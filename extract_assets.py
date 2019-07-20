#!/usr/bin/env python3
import sys
import os
import json


def read_asset_map():
    with open("assets.json") as f:
        ret = json.load(f)
    del ret["comment"]
    return ret


def read_local_asset_list():
    try:
        ret = []
        with open(".assets-local.txt") as f:
            f.readline()
            version = int(f.readline().strip())
            for line in f:
                ret.append(line.strip())
        return version, ret
    except FileNotFoundError:
        return -1, []


def clean_assets():
    assets = set(read_asset_map().keys())
    assets.update(read_local_asset_list()[1])
    for fname in list(assets) + [".assets-local.txt"]:
        try:
            os.remove(fname)
        except FileNotFoundError:
            pass


def main():
    args = sys.argv[1:]
    if args == ["--clean"]:
        clean_assets()
        sys.exit(0)

    langs = ["jp", "us", "eu"]
    if not args or not all(a in langs for a in args):
        langs_str = " ".join("[" + lang + "]" for lang in langs)
        print("Usage: " + sys.argv[0] + " " + langs_str)
        print("For each version, baserom.<version>.z64 must exist")
        sys.exit(1)

    asset_map = read_asset_map()
    all_assets = []
    any_missing_assets = False
    for asset, data in asset_map.items():
        if os.path.isfile(asset):
            all_assets.append((asset, data, True))
        else:
            all_assets.append((asset, data, False))
            if not any_missing_assets and any(lang in data[-1] for lang in args):
                any_missing_assets = True

    if not any_missing_assets:
        # Nothing to do, no need to read a ROM. For efficiency we don't check
        # the list of old assets either.
        return

    # Late imports (to optimize startup perf)
    import subprocess
    import hashlib
    from collections import defaultdict

    # In case we ever need to change formats of generated files, we keep a
    # revision ID in the local asset file.
    new_version = 0
    new_assets = {a[0] for a in all_assets}

    previous_version, previous_assets = read_local_asset_list()
    if previous_version is None:
        # If we have no local asset file, we assume that files are version
        # controlled and thus up to date.
        previous_version = new_version

    # Create work list
    todo = defaultdict(lambda: [])
    for (asset, data, exists) in all_assets:
        if exists and previous_version == new_version:
            # Leave existing assets alone.
            continue

        meta = data[:-2]
        size, positions = data[-2:]
        for lang, pos in positions.items():
            mio0 = None if len(pos) == 1 else pos[0]
            pos = pos[-1]
            if lang in args:
                todo[(lang, mio0)].append((asset, pos, size, meta))
                break

    # Load ROMs
    roms = {}
    for lang in args:
        fname = "baserom." + lang + ".z64"
        try:
            with open(fname, "rb") as f:
                roms[lang] = f.read()
        except:
            print("Failed to open " + fname + ". Please ensure it exists!")
            sys.exit(1)
        sha1 = hashlib.sha1(roms[lang]).hexdigest()
        with open("sm64." + lang + ".sha1", "r") as f:
            expected_sha1 = f.read().split()[0]
        if sha1 != expected_sha1:
            print(
                fname
                + " has the wrong hash! Found "
                + sha1
                + ", expected "
                + expected_sha1
            )

    # Make sure tools exist
    subprocess.check_call(["make", "-s", "-C", "tools/", "n64graphics", "mio0"])

    # Go through the assets in roughly alphabetical order (but assets in the same
    # mio0 file still go together).
    keys = sorted(list(todo.keys()), key=lambda k: todo[k][0][0])

    # Import new assets
    for key in keys:
        assets = todo[key]
        lang, mio0 = key
        if mio0 is not None:
            image = subprocess.run(
                [
                    "./tools/mio0",
                    "-d",
                    "-o",
                    str(mio0),
                    "baserom." + lang + ".z64",
                    "/dev/stdout",
                ],
                check=True,
                stdout=subprocess.PIPE,
            ).stdout
        else:
            image = roms[lang]

        for (asset, pos, size, meta) in assets:
            print("extracting", asset)
            input = image[pos : pos + size]
            os.makedirs(os.path.dirname(asset), exist_ok=True)
            if asset.endswith(".png"):
                w, h = meta
                fmt = asset.split(".")[-2]
                subprocess.run(
                    [
                        "./tools/n64graphics",
                        "-e",
                        "/dev/stdin",
                        "-g",
                        asset,
                        "-f",
                        fmt,
                        "-w",
                        str(w),
                        "-h",
                        str(h),
                    ],
                    input=input,
                    check=True,
                )
            else:
                with open(asset, "wb") as f:
                    f.write(input)

    # Remove old assets
    for asset in previous_assets:
        if asset not in new_assets:
            try:
                print("deleting", asset)
                os.remove(asset)
            except FileNotFoundError:
                pass

    # Replace the asset list
    output = "\n".join(
        [
            "# This file tracks the assets currently extracted by extract_assets.py.",
            str(new_version),
            *sorted(list(new_assets)),
            "",
        ]
    )
    with open(".assets-local.txt", "w") as f:
        f.write(output)


main()