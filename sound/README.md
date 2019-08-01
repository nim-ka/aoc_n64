Sound in SM64 consists of three parts: samples, sound banks, and sequences.

Samples represent raw sound data, given as AIFC files with a custom compression
format. The N64 SDK provides two command line programs for converting AIFF
files into AIFC: `tabledesign` and `vadpcm_enc`. The tools come in both MIPS
and x86 versions. Usage is:
```
tabledesign -s 1 input.aiff > input.table
vadpcm_enc -c input.table input.aiff output.aifc
```

Additionally, the SDK has a tool `vadpcm_dec` for converting AIFC files to RAW
format. Combined with `sox` for converting RAW to AIFF, you can do:
```
vadpcm_dec input.aifc > output.raw
sox -B -t raw -r 16k -e signed -b 16 -c 1 output.raw output.aiff
```
You may need to adjust the sample rate from 16k to something else. Note that
this process is not lossless (though nearly so), and that `vadpcm_dec` drops
loops.

Samples are collected into banks, given by directories. The order in which
banks and samples end up in the final binary is determined by their file and
directory names. Thus, to keep the ROM OK, sample files/bank directories should
be prefixed by a number to maintain sort order.

Samples cannot be referred to directly from sequence files. Instead, there is
an indirect step in the form of sound banks. Each sound bank refers to a single
sample bank, and amends it with extra information in the form of a JSON file.
This JSON file contains a set of "instruments", which describe how note values
(pitches) map to samples, which pitch corrections to perform, and what ADSR
envelopes to use. The `instrument_list` key maps indices to instruments; these
indices are what sequence files can refer to. A special instrument `percussion`
is also supported, as an array with (usually) 64 different entries, covering
note values 0..63. It is referred to as instrument ID 0x7f.

C-style comments are supported in the JSON. Similar to samples, the sound banks
come in alphabetical order in the ROM, so they should be prefixed to maintain
sort order.

Sequence files are what actually controls the audio. The are in .m64 format,
which is similar to MIDI, but Turing complete. An .m64 file has a sequence
script which can spawn channels, which have channel scripts that can spawn
layers, which have layer scripts that can play notes. Each note is performed
using an instrument from a sound bank. A sequence file can use multiple banks;
`bank_sets.s` describes the mapping from sequences to sound banks. Channels
can switch between banks using a command. However, in practice most sequences
limit themselves to a single sound bank. The main exception is sequence 0,
which is responsible for sound effects.
