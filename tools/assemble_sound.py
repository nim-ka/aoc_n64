#!/usr/bin/env python3
from collections import namedtuple
import json
import os
import re
import struct
import subprocess
import sys

TYPE_CTL = 1
TYPE_TBL = 2

STACK_TRACES = False
DUMP_INDIVIDUAL_BINS = False


class Aifc:
    def __init__(self, name, fname, data, book, loop):
        self.name = name
        self.fname = fname
        self.data = data
        self.book = book
        self.loop = loop
        self.used = False
        self.offset = None


class SampleBank:
    def __init__(self, name, entries):
        self.name = name
        self.uses = 0
        self.entries = entries
        self.name_to_entry = {}
        for e in entries:
            self.name_to_entry[e.name] = e


Book = namedtuple("Book", ["order", "npredictors", "table"])
Loop = namedtuple("Loop", ["start", "end", "count", "state"])
Bank = namedtuple("Bank", ["name", "sample_bank", "json"])


def align(val, al):
    return (val + (al - 1)) & -al


def fail(msg):
    print(msg, file=sys.stderr)
    if STACK_TRACES:
        raise Exception("re-raising exception")
    sys.exit(1)


def validate(cond, msg, forstr=""):
    if not cond:
        if forstr:
            msg += " for " + msg
        raise Exception(msg)


def strip_comments(string):
    string = re.sub(re.compile("/\*.*?\*/", re.DOTALL), "", string)
    return re.sub(re.compile("//.*?\n"), "", string)


def to_bcd(num):
    assert num >= 0
    shift = 0
    ret = 0
    while num:
        ret |= (num % 10) << shift
        shift += 4
        num //= 10
    return ret


def parse_aifc_loop(data):
    validate(len(data) == 48, "loop chunk size should be 48")
    a, b, start, end, count = struct.unpack(">HHIIi", data[:16])
    validate(a == 1, "at most one loop supported")
    validate(b == 1, "at most one loop supported")
    state = []
    for i in range(16, len(data), 2):
        state.append(struct.unpack(">h", data[i : i + 2])[0])
    return Loop(start, end, count, state)


def parse_aifc_book(data):
    count, order, npredictors = struct.unpack(">hhh", data[:6])
    validate(count == 1, "at most one predictor supported")
    validate(
        len(data) == 6 + 16 * order * npredictors,
        "predictor book chunk size doesn't match",
    )
    table = []
    for i in range(6, len(data), 2):
        table.append(struct.unpack(">h", data[i : i + 2])[0])
    return Book(order, npredictors, table)


def parse_aifc(data, name, fname):
    validate(data[:4] == b"FORM", "must start with FORM")
    validate(data[8:12] == b"AIFC", "format must be AIFC")
    i = 12
    sections = []
    while i < len(data):
        tp = data[i : i + 4]
        le, = struct.unpack(">I", data[i + 4 : i + 8])
        i += 8
        sections.append((tp, data[i : i + le]))
        i = align(i + le, 2)

    audio_data = None
    vadpcm_codes = None
    vadpcm_loops = None

    for (tp, data) in sections:
        if tp == b"APPL" and data[:4] == b"stoc":
            plen = data[4]
            tp = data[5 : 5 + plen]
            data = data[align(5 + plen, 2) :]
            if tp == b"VADPCMCODES":
                vadpcm_codes = data
            elif tp == b"VADPCMLOOPS":
                vadpcm_loops = data
        elif tp == b"SSND":
            audio_data = data[8:]

    validate(audio_data is not None, "no SSND section")
    validate(vadpcm_codes is not None, "no VADPCM table")

    book = parse_aifc_book(vadpcm_codes)
    loop = parse_aifc_loop(vadpcm_loops) if vadpcm_loops is not None else None
    return Aifc(name, fname, audio_data, book, loop)


class ReserveSerializer:
    def __init__(self):
        self.parts = []
        self.sizes = []
        self.size = 0

    def add(self, part):
        assert isinstance(part, (bytes, list))
        self.parts.append(part)
        self.sizes.append(len(part))
        self.size += len(part)

    def reserve(self, space):
        li = []
        self.parts.append(li)
        self.sizes.append(space)
        self.size += space
        return li

    def align(self, alignment):
        new_size = (self.size + alignment - 1) & -alignment
        self.add((new_size - self.size) * b"\0")

    def finish(self):
        flat_parts = []
        for (li, si) in zip(self.parts, self.sizes):
            if isinstance(li, list):
                li = b"".join(li)
            assert (
                len(li) == si
            ), "unfulfilled reservation of size {}, only got {}".format(si, len(li))
            flat_parts.append(li)
        return b"".join(flat_parts)


class GarbageSerializer:
    def __init__(self):
        self.garbage_bufs = [[]]
        self.parts = []
        self.size = 0
        self.garbage_pos = 0

    def reset_garbage_pos(self):
        self.garbage_bufs.append([])
        self.garbage_pos = 0

    def add(self, part):
        assert isinstance(part, bytes)
        self.parts.append(part)
        self.garbage_bufs[-1].append((self.garbage_pos, part))
        self.size += len(part)
        self.garbage_pos += len(part)

    def align(self, alignment):
        new_size = (self.size + alignment - 1) & -alignment
        self.add((new_size - self.size) * b"\0")

    def garbage_at(self, pos):
        # Find the last write to position pos & 0xffff, assuming a cyclic
        # buffer of size 0x10000 where the write position is reset to 0 on
        # each call to reset_garbage_pos.
        pos &= 0xFFFF
        for bufs in self.garbage_bufs[::-1]:
            for (bpos, buf) in bufs[::-1]:
                q = ((bpos + len(buf) - 1 - pos) & ~0xFFFF) + pos
                if q >= bpos:
                    return buf[q - bpos]
        return 0

    def align_garbage(self, alignment):
        while self.size % alignment != 0:
            self.add(bytes([self.garbage_at(self.garbage_pos)]))

    def finish(self):
        return b"".join(self.parts)


def validate_json_format(json, fmt, forstr=""):
    constructor_to_name = {
        str: "a string",
        dict: "an object",
        int: "an integer",
        float: "a floating point number",
        list: "an array",
    }
    for key, tp in fmt.items():
        validate(key in json, 'missing key "' + key + '"', forstr)
        if isinstance(tp, list):
            validate_int_in_range(json[key], tp[0], tp[1], '"' + key + '"', forstr)
        else:
            validate(
                isinstance(json[key], tp)
                or (tp == float and isinstance(json[key], int)),
                '"{}" must be {}'.format(key, constructor_to_name[tp]),
                forstr,
            )


def validate_int_in_range(val, lo, hi, msg, forstr=""):
    validate(isinstance(val, int), "{} must be an integer".format(msg), forstr)
    validate(
        lo <= val <= hi, "{} must be in range {} to {}".format(msg, lo, hi), forstr
    )


def validate_sound(json, sample_bank, forstr=""):
    validate_json_format(json, {"sample": str, "tuning": float})
    validate(
        json["sample"] in sample_bank.name_to_entry,
        "reference to sound {} which isn't found in sample bank {}".format(
            json["sample"], sample_bank.name
        ),
        forstr,
    )


def validate_bank(json, sample_bank):
    validate_json_format(
        json, {"envelopes": dict, "instruments": dict, "instrument_list": list}
    )

    if "date" in json:
        validate(
            isinstance(json["date"], str)
            and re.match(r"[0-9]{4}-[0-9]{2}-[0-9]{2}\Z", json["date"]),
            "date must have format yyyy-mm-dd",
        )

    for key, env in json["envelopes"].items():
        validate(isinstance(env, list), 'envelope "' + key + '" must be an array')
        last_fine = False
        for entry in env:
            if entry in ["stop", "hang", "restart"]:
                last_fine = True
            else:
                validate(
                    isinstance(entry, list) and len(entry) == 2,
                    'envelope entry in "'
                    + key
                    + '" must be a list of length 2, or one of stop/hang/restart',
                )
                if entry[0] == "goto":
                    validate_int_in_range(
                        entry[1], 0, len(env) - 2, "envelope goto target out of range:"
                    )
                    last_fine = True
                else:
                    validate_int_in_range(
                        entry[0], 1, 2 ** 16 - 4, "envelope entry's first part"
                    )
                    validate_int_in_range(
                        entry[1], 0, 2 ** 16 - 1, "envelope entry's second part"
                    )
                    last_fine = False
        validate(
            last_fine, 'envelope "{}" must end with stop/hang/restart/goto'.format(key)
        )

    drums = []
    instruments = []
    instrument_names = set()
    for name, inst in json["instruments"].items():
        if name == "percussion":
            validate(isinstance(inst, list), "drums entry must be a list")
            drums = inst
        else:
            validate(isinstance(inst, dict), "instrument entry must be an object")
            instruments.append((name, inst))
            instrument_names.add(name)

    for drum in drums:
        validate(isinstance(drum, dict), "drum entry must be an object")
        validate_json_format(
            drum,
            {"release_rate": [0, 255], "pan": [0, 128], "envelope": str, "sound": dict},
        )
        validate_sound(drum["sound"], sample_bank)
        validate(
            drum["envelope"] in json["envelopes"],
            "reference to non-existent envelope " + drum["envelope"],
            "drum",
        )

    no_sound = {}

    for name, inst in instruments:
        forstr = "instrument " + name
        for lohi in ["lo", "hi"]:
            nr = "normal_range_" + lohi
            so = "sound_" + lohi
            if nr in inst:
                validate(so in inst, nr + " is specified, but not " + so, forstr)
            if so in inst:
                validate(nr in inst, so + " is specified, but not " + nr, forstr)
            else:
                inst[so] = no_sound
        if "normal_range_lo" not in inst:
            inst["normal_range_lo"] = 0
        if "normal_range_hi" not in inst:
            inst["normal_range_hi"] = 127

        validate_json_format(
            inst,
            {
                "release_rate": [0, 255],
                "envelope": str,
                "normal_range_lo": [0, 127],
                "normal_range_hi": [0, 127],
                "sound_lo": dict,
                "sound": dict,
                "sound_hi": dict,
            },
            forstr,
        )

        if "ifdef" in inst:
            validate(
                isinstance(inst["ifdef"], list)
                and all(isinstance(x, str) for x in inst["ifdef"]),
                '"ifdef" must be an array of strings',
            )

        validate(
            inst["normal_range_lo"] <= inst["normal_range_hi"],
            "normal_range_lo > normal_range_hi",
            forstr,
        )
        validate(
            inst["envelope"] in json["envelopes"],
            "reference to non-existent envelope " + inst["envelope"],
            forstr,
        )
        for key in ["sound_lo", "sound", "sound_hi"]:
            if inst[key] is no_sound:
                del inst[key]
            else:
                validate_sound(inst[key], sample_bank, forstr)

    seen_instruments = set()
    for inst in json["instrument_list"]:
        if inst is None:
            continue
        validate(
            isinstance(inst, str),
            "instrument list should contain only strings and nulls",
        )
        validate(
            inst in instrument_names, "reference to non-existent instrument " + inst
        )
        validate(
            inst not in seen_instruments, inst + " occurs twice in the instrument list"
        )
        seen_instruments.add(inst)

    for inst in instrument_names:
        validate(inst in seen_instruments, "unreferenced instrument " + inst)


def apply_ifdefs(bank, defines):
    if "VERSION_EU" in defines and "date" in bank.json:
        bank.json["date"] = bank.json["date"].replace("1996-03-19", "1996-06-24")

    ifdef_removed = set()
    for key, inst in bank.json["instruments"].items():
        if (
            isinstance(inst, dict)
            and "ifdef" in inst
            and all(d not in defines for d in inst["ifdef"])
        ):
            ifdef_removed.add(key)
    for key in ifdef_removed:
        del bank.json["instruments"][key]
        bank.json["instrument_list"].remove(key)


def mark_sample_bank_uses(bank):
    bank.sample_bank.uses += 1

    def mark_used(name):
        bank.sample_bank.name_to_entry[name].used = True

    for inst in bank.json["instruments"].values():
        if isinstance(inst, list):
            for drum in inst:
                mark_used(drum["sound"]["sample"])
        else:
            if "sound_lo" in inst:
                mark_used(inst["sound_lo"]["sample"])
            mark_used(inst["sound"]["sample"])
            if "sound_hi" in inst:
                mark_used(inst["sound_hi"]["sample"])


def serialize_ctl(bank, base_ser):
    json = bank.json

    drums = []
    instruments = []
    for inst in json["instruments"].values():
        if isinstance(inst, list):
            drums = inst
        else:
            instruments.append(inst)

    y, m, d = map(int, json.get("date", "0000-00-00").split("-"))
    date = y * 10000 + m * 100 + d
    base_ser.add(
        struct.pack(
            ">IIII",
            len(json["instrument_list"]),
            len(drums),
            1 if bank.sample_bank.uses > 1 else 0,
            to_bcd(date),
        )
    )

    ser = ReserveSerializer()
    if drums:
        drum_pos_buf = ser.reserve(4)
    else:
        ser.add(b"\0" * 4)
        drum_pos_buf = None

    inst_pos_buf = ser.reserve(4 * len(json["instrument_list"]))
    ser.align(16)

    used_samples = []
    for inst in json["instruments"].values():
        if isinstance(inst, list):
            for drum in inst:
                used_samples.append(drum["sound"]["sample"])
        else:
            if "sound_lo" in inst:
                used_samples.append(inst["sound_lo"]["sample"])
            used_samples.append(inst["sound"]["sample"])
            if "sound_hi" in inst:
                used_samples.append(inst["sound_hi"]["sample"])

    sample_name_to_addr = {}
    for name in used_samples:
        if name in sample_name_to_addr:
            continue
        sample_name_to_addr[name] = ser.size
        aifc = bank.sample_bank.name_to_entry[name]
        sample_len = len(aifc.data)

        # Sample
        ser.add(struct.pack(">II", 0, aifc.offset))
        loop_addr_buf = ser.reserve(4)
        book_addr_buf = ser.reserve(4)
        ser.add(struct.pack(">I", align(sample_len, 2)))
        ser.align(16)

        # Book
        book_addr_buf.append(struct.pack(">I", ser.size))
        ser.add(struct.pack(">ii", aifc.book.order, aifc.book.npredictors))
        for x in aifc.book.table:
            ser.add(struct.pack(">h", x))
        ser.align(16)

        # Loop
        loop_addr_buf.append(struct.pack(">I", ser.size))
        if aifc.loop is None:
            assert sample_len % 9 in [0, 1]
            end = sample_len // 9 * 16 + (sample_len % 2)
            ser.add(struct.pack(">IIiI", 0, end, 0, 0))
        else:
            ser.add(
                struct.pack(">IIiI", aifc.loop.start, aifc.loop.end, aifc.loop.count, 0)
            )
            assert aifc.loop.count != 0
            for x in aifc.loop.state:
                ser.add(struct.pack(">h", x))
        ser.align(16)

    env_name_to_addr = {}
    for name, env in json["envelopes"].items():
        env_name_to_addr[name] = ser.size
        for entry in env:
            if entry == "stop":
                entry = [0, 0]
            elif entry == "hang":
                entry = [2 ** 16 - 1, 0]
            elif entry == "restart":
                entry = [2 ** 16 - 3, 0]
            elif entry[0] == "goto":
                entry[0] = 2 ** 16 - 2
            ser.add(struct.pack(">HH", *entry))
        ser.align(16)

    def ser_sound(sound):
        sample_addr = (
            0 if sound["sample"] is None else sample_name_to_addr[sound["sample"]]
        )
        ser.add(struct.pack(">If", sample_addr, sound["tuning"]))

    no_sound = {"sample": None, "tuning": 0.0}

    inst_name_to_pos = {}
    for name, inst in json["instruments"].items():
        if isinstance(inst, list):
            continue
        inst_name_to_pos[name] = ser.size
        env_addr = env_name_to_addr[inst["envelope"]]
        ser.add(
            struct.pack(
                ">BBBBI",
                0,
                inst.get("normal_range_lo", 0),
                inst.get("normal_range_hi", 127),
                inst["release_rate"],
                env_addr,
            )
        )
        ser_sound(inst.get("sound_lo", no_sound))
        ser_sound(inst["sound"])
        ser_sound(inst.get("sound_hi", no_sound))
    ser.align(16)

    for name in json["instrument_list"]:
        if name is None:
            inst_pos_buf.append(struct.pack(">I", 0))
            continue
        inst_pos_buf.append(struct.pack(">I", inst_name_to_pos[name]))

    if drums:
        drum_poses = []
        for drum in drums:
            drum_poses.append(ser.size)
            ser.add(struct.pack(">BBBB", drum["release_rate"], drum["pan"], 0, 0))
            ser_sound(drum["sound"])
            env_addr = env_name_to_addr[drum["envelope"]]
            ser.add(struct.pack(">I", env_addr))
        ser.align(16)

        drum_pos_buf.append(struct.pack(">I", ser.size))
        for pos in drum_poses:
            ser.add(struct.pack(">I", pos))
        ser.align(16)

    base_ser.add(ser.finish())


def serialize_tbl(sample_bank, ser):
    ser.reset_garbage_pos()
    base_addr = ser.size
    for aifc in sample_bank.entries:
        if not aifc.used:
            continue
        ser.align(16)
        aifc.offset = ser.size - base_addr
        ser.add(aifc.data)
    ser.align(2)
    ser.align_garbage(16)


def serialize_seqfile(entries, serialize_entry, entry_list, magic):
    ser = ReserveSerializer()
    ser.add(struct.pack(">HH", magic, len(entry_list)))
    table = ser.reserve(len(entry_list) * 8)
    ser.align(16)
    data_start = ser.size

    ser2 = GarbageSerializer()
    entry_offsets = []
    entry_lens = []
    for entry in entries:
        entry_offsets.append(ser2.size)
        serialize_entry(entry, ser2)
        entry_lens.append(ser2.size - entry_offsets[-1])
    ser.add(ser2.finish())
    ser.add(b"\0")
    ser.align(64)

    for ent in entry_list:
        table.append(struct.pack(">I", entry_offsets[ent] + data_start))
        table.append(struct.pack(">I", entry_lens[ent]))
    return ser.finish()


def main():
    global STACK_TRACES
    need_help = False
    skip_next = False
    cpp_command = None
    print_samples = False
    defines = []
    args = []
    for i, a in enumerate(sys.argv[1:], 1):
        if skip_next:
            skip_next = False
            continue
        if a == "--help" or a == "-h":
            need_help = True
        elif a == "--cpp":
            cpp_command = sys.argv[i + 1]
            skip_next = True
        elif a == "-D":
            defines.append(sys.argv[i + 1])
            skip_next = True
        elif a.startswith("-D"):
            defines.append(a[2:])
        elif a == "--stack-trace":
            STACK_TRACES = True
        elif a == "--print-samples":
            print_samples = True
        elif a.startswith("-"):
            print("Unrecognized option " + a)
            sys.exit(1)
        else:
            args.append(a)

    if need_help or len(args) != 4:
        print(
            "Usage: {} <samples dir> <sound bank dir>"
            " <out .ctl file> <out .tbl file>"
            " [--cpp <preprocessor>]"
            " [-D <symbol>]"
            " [--stack-trace]".format(sys.argv[0])
        )
        sys.exit(0 if need_help else 1)

    sample_bank_dir = args[0]
    sound_bank_dir = args[1]
    ctl_data_out = args[2]
    tbl_data_out = args[3]

    defines_set = {d.split("=")[0] for d in defines}

    banks = []
    sample_banks = []
    name_to_sample_bank = {}

    sample_bank_names = sorted(os.listdir(sample_bank_dir))
    for name in sample_bank_names:
        dir = os.path.join(sample_bank_dir, name)
        if not os.path.isdir(dir):
            continue
        entries = []
        for f in sorted(os.listdir(dir)):
            fname = os.path.join(dir, f)
            if not f.endswith(".aifc"):
                continue
            try:
                with open(fname, "rb") as inf:
                    data = inf.read()
                    entries.append(parse_aifc(data, f[:-5], fname))
            except Exception as e:
                fail("malformed AIFC file " + fname + ": " + str(e))
        if entries:
            sample_bank = SampleBank(name, entries)
            sample_banks.append(sample_bank)
            name_to_sample_bank[name] = sample_bank

    bank_names = sorted(os.listdir(sound_bank_dir))
    for f in bank_names:
        fname = os.path.join(sound_bank_dir, f)
        if not f.endswith(".json"):
            continue

        try:
            if cpp_command:
                data = subprocess.run(
                    [cpp_command, fname] + ["-D" + x for x in defines],
                    stdout=subprocess.PIPE,
                    check=True,
                ).stdout.decode()
            else:
                with open(fname, "r") as inf:
                    data = inf.read()
                data = strip_comments(data)
            bank_json = json.loads(data)

            validate(isinstance(bank_json, dict), "must have a top-level object")
            validate_json_format(bank_json, {"sample_bank": str})
            sample_bank_name = bank_json["sample_bank"]
            validate(
                sample_bank_name in name_to_sample_bank,
                "sample bank " + sample_bank_name + " not found",
            )
            sample_bank = name_to_sample_bank[sample_bank_name]

            validate_bank(bank_json, sample_bank)

            bank = Bank(f[:-5], sample_bank, bank_json)
            apply_ifdefs(bank, defines_set)
            mark_sample_bank_uses(bank)
            banks.append(bank)

        except Exception as e:
            fail("failed to parse bank " + fname + ": " + str(e))

    sample_banks = [b for b in sample_banks if b.uses > 0]
    sample_bank_index = {}
    for sample_bank in sample_banks:
        sample_bank_index[sample_bank] = len(sample_bank_index)

    with open(tbl_data_out, "wb") as out:
        out.write(
            serialize_seqfile(
                sample_banks,
                serialize_tbl,
                [sample_bank_index[x.sample_bank] for x in banks],
                TYPE_TBL,
            )
        )

    with open(ctl_data_out, "wb") as out:
        if DUMP_INDIVIDUAL_BINS:
            # Debug logic, may simplify diffing
            os.makedirs("ctl/", exist_ok=True)
            for b in banks:
                with open("ctl/" + b.name + ".bin", "wb") as f:
                    ser = GarbageSerializer()
                    serialize_ctl(b, ser)
                    f.write(ser.finish())
            print("wrote to ctl/")

        out.write(
            serialize_seqfile(banks, serialize_ctl, list(range(len(banks))), TYPE_CTL)
        )

    if print_samples:
        for sample_bank in sample_banks:
            for entry in sample_bank.entries:
                if entry.used:
                    print(entry.fname)


if __name__ == "__main__":
    main()