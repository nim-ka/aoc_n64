.include "macros.inc"

.section .data

.macro adsrtable name
.word (\name - gSoundDataADSR), (\name\()_end - \name)
.endm

.macro adsr name
\name:
.ifdef VERSION_JP
.incbin "sound/adsr/jp/\name\().bin"
.endif
.ifdef VERSION_US
.incbin "sound/adsr/us/\name\().bin"
.endif
\name\()_end:
.endm

glabel gSoundDataADSR # US: 57B720
.hword 1 # current sequence
.hword (adsr_entry_end - adsr_entry_start) / 8 # number of entries

adsr_entry_start:
adsrtable adsr_00
adsrtable adsr_01
adsrtable adsr_02
adsrtable adsr_03
adsrtable adsr_04
adsrtable adsr_05
adsrtable adsr_06
adsrtable adsr_07
adsrtable adsr_08
adsrtable adsr_09
adsrtable adsr_0A
adsrtable adsr_0B
adsrtable adsr_0C
adsrtable adsr_0D
adsrtable adsr_0E
adsrtable adsr_0F
adsrtable adsr_10
adsrtable adsr_11
adsrtable adsr_12
adsrtable adsr_13
adsrtable adsr_14
adsrtable adsr_15
adsrtable adsr_16
adsrtable adsr_17
adsrtable adsr_18
adsrtable adsr_19
adsrtable adsr_1A
adsrtable adsr_1B
adsrtable adsr_1C
adsrtable adsr_1D
adsrtable adsr_1E
adsrtable adsr_1F
adsrtable adsr_20
adsrtable adsr_21
adsrtable adsr_22
adsrtable adsr_23
adsrtable adsr_24
adsrtable adsr_25
adsr_entry_end:

.word 0, 0, 0 # you cant use an align 4, 0x00 here or else the table calculation above will not work.

adsr adsr_00
adsr adsr_01
adsr adsr_02
adsr adsr_03
adsr adsr_04
adsr adsr_05
adsr adsr_06
adsr adsr_07
adsr adsr_08
adsr adsr_09
adsr adsr_0A
adsr adsr_0B
adsr adsr_0C
adsr adsr_0D
adsr adsr_0E
adsr adsr_0F
adsr adsr_10
adsr adsr_11
adsr adsr_12
adsr adsr_13
adsr adsr_14
adsr adsr_15
adsr adsr_16
adsr adsr_17
adsr adsr_18
adsr adsr_19
adsr adsr_1A
adsr adsr_1B
adsr adsr_1C
adsr adsr_1D
adsr adsr_1E
adsr adsr_1F
adsr adsr_20
adsr adsr_21
adsr adsr_22
adsr adsr_23
adsr adsr_24
adsr adsr_25

.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.macro soundtable name
.word (\name - gSoundDataRaw), (\name\()_end - \name)
.endm

# US: 593560 - 7B0860
# raw sound data area
raw_sound_begin:
glabel gSoundDataRaw # the nlist entries below are part of this area.
.hword 2 # current segment
.hword (sound_table_end - sound_table) / 8 # number of entries (pair of words as described below)

# Each pair of words represents the following:
# 1: Relative offset of the nlist
# 2: Size of the nlist

sound_table:
soundtable nlist_00
soundtable nlist_01
soundtable nlist_02
soundtable nlist_03
soundtable nlist_04_05
soundtable nlist_04_05 
soundtable nlist_06
soundtable nlist_07
soundtable nlist_08
soundtable nlist_09
soundtable nlist_0A
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_extra_1
soundtable nlist_0B_rest
soundtable nlist_extra_2
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_extra_3
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
soundtable nlist_0B_rest
sound_table_end:

.word 0, 0, 0

nlist_00: # US: 5936A0
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xA63A0, 0x6F0 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xA6A90, 0x28D0 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xA9360, 0x330 # sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xA9690, 0x11D0 # sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAA860, 0x1190 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAB9F0, 0x1B50 # sample 05
nlist_00_end:

nlist_01: # US: 59A840
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAD540, 0x60 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAD5A0, 0x2B0 # sample 01

# no sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAD850, 0x240 # sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xADA90, 0x690 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAE120, 0x680 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAE7A0, 0x160 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xAE900, 0x19E0 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xB02E0, 0xC30 # sample 08
nlist_01_end:

nlist_02: # US: 59E210
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xB0F10, 0x3790 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xB46A0, 0x14F0 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xB5B90, 0x1B90 # sample 02
nlist_02_end:

nlist_03: # US: 5A4A20
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xB7720, 0x1C90 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xB93B0, 0x11D0 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBA580, 0x10C0 # sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBB640, 0x14D0 # sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBCB10, 0xAB0 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBD5C0, 0xB10 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBE0D0, 0xA50 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBEB20, 0xE60 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xBF980, 0x2880 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xC2200, 0x7D0 # sample 09
nlist_03_end:

nlist_04_05: # US: 5AFCD0
# nlist 04
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xC29D0, 0x15E0 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xC3FB0, 0x1030 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xC4FE0, 0x2C80 # sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xC7C60, 0x17C0 # sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xC9420, 0x1200 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xCA620, 0x37A0 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xCDDC0, 0x7B0 # sample 06

# no sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xCE570, 0x2370 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xD08E0, 0xA80 # sample 09

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xD1360, 0x710 # sample 0A

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xD1A70, 0x5D0 # sample 0B

# no sample 0C

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xD2040, 0x2C10 # sample 0D

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xD4C50, 0x5910 # sample 0E

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xDA560, 0x7E50 # sample 0F

# nlist 05
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xE23B0, 0x1070 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xE3420, 0x24B0 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xE58D0, 0x440 # sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xE5D10, 0x36F0 # sample 03

# a 0x28D0 sample (04) is listed here in the nlist, but doesnt actually exist
# in the bank. probably cross-bank.

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xE9400, 0xC90 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xEA090, 0x38D0 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xED960, 0x2910 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF0270, 0x7D0 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF0A40, 0x9B0 # sample 09

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF13F0, 0xF60 # sample 0A

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF2350, 0x820 # sample 0B

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF2B70, 0x330 # sample 0C

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF2EA0, 0x2830 # sample 0D

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF56D0, 0x19B0 # sample 0E

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF7080, 0x1080 # sample 0F
nlist_04_05_end:

nlist_06: # US: 5E5400
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF8100, 0x890 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF8990, 0xCC0 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xF9650, 0x2310 # sample 02

# no sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xFB960, 0x3DB0 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0xFF710, 0xAF0 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x100200, 0x19C0 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x101BC0, 0x6C0 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x102280, 0x530 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1027B0, 0x1C90 # sample 09

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x104440, 0x920 # sample 0A

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x104D60, 0x980 # sample 0B

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1056E0, 0x890 # sample 0C

# no sample 0D

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x105F70, 0x14B0 # sample 0E

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x107420, 0x2880 # sample 0F
nlist_06_end:

nlist_07: # US: 5F6FA0
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x109CA0, 0x4C0 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x10A160, 0xE50 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x10AFB0, 0x4C0 # sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x10B470, 0x2960 # sample 03

# no sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x10DDD0, 0x2A40 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x110810, 0x1010 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x111820, 0x12D0 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x112AF0, 0x13E0 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x113ED0, 0x570 # sample 09

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x114440, 0xF50 # sample 0A

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x115390, 0x1850 # sample 0B

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x116BE0, 0x15A0 # sample 0C

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x118180, 0x22EA # sample 0D
.ifdef VERSION_US
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.endif
.ifdef VERSION_JP
.byte 0x17, 0x1C, 0xF2, 0x41, 0x14, 0xA1
.endif

.ifdef VERSION_US # new US sample: 607770-607E90 (0x720) (chain chomp)
.incbin "sound/nlist07/0E.raw" # sample 0E
.endif
nlist_07_end:

nlist_08: # US: 607770
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x11A470, 0x760 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x11ABD0, 0x810 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x11B3E0, 0xA90 # sample 02

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x11BE70, 0x1B00 # sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x11D970, 0x2150 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x11FAC0, 0xB00 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1205C0, 0x1180 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x121740, 0xA90 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1221D0, 0x2090 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x124260, 0x1930 # sample 09

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x125B90, 0x1610 # sample 0A

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1271A0, 0x15B0 # sample 0B

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x128750, 0x3210 # sample 0C

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x12B960, 0x3900 # sample 0D

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x12F260, 0x20E0 # sample 0E

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x131340, 0xBBE # sample 0F
.ifdef VERSION_US
.byte 0x00, 0x00
.endif
.ifdef VERSION_JP
.byte 0x2F, 0x40
.endif

.ifdef VERSION_US
.align 4, 0x00
.incbin "sound/nlist08/10.raw" # doh

.align 4, 0x00
.incbin "sound/nlist08/11.raw" # game over

.align 4, 0x00
.incbin "sound/nlist08/12.raw" # hello

.align 4, 0x00
.incbin "sound/nlist08/13.raw" # press start to play

.align 4, 0x00
.incbin "sound/nlist08/14.raw" # boing

.align 4, 0x00
.incbin "sound/nlist08/15.raw" # nighty nighty zzz ah spaghetti zzz ah ravioli zzz ah mamamia

.align 4, 0x00
.incbin "sound/nlist08/16.raw" # so long ye' bowser

.align 4, 0x00
.incbin "sound/nlist08/17.raw" # imma tired

.align 4, 0x00
.incbin "sound/nlist08/18.raw" # wah hah

.align 4, 0x00
.incbin "sound/nlist08/19.raw" # yippee

.align 4, 0x00
.incbin "sound/nlist08/1A.raw" # lets-a-go
.endif
nlist_08_end:

nlist_09: # US: 64D350
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x131F00, 0x1780 # sample 00 primary (also sample 02)

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x133680, 0xBC0 # sample 00 secondary

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x134240, 0x2B30 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x136D70, 0x2110 # sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x138E80, 0xE80 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x139D00, 0x690 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x13A390, 0x26B6 # sample 06
.ifdef VERSION_US
.byte 0x11, 0x02, 0xB1, 0x01, 0x1D, 0xCF, 0x42, 0xDD, 0x24, 0xFE
.endif
.ifdef VERSION_JP
.byte 0xFB, 0xBD, 0x0E, 0xCF, 0x00, 0x01, 0x71, 0xD2, 0x74, 0xCC
.endif
nlist_09_end:

nlist_0A: # US: 657EA0
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x13CA50, 0x60C0 # sample 00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x142B10, 0x15E0 # sample 01

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1440F0, 0x1480 # sample 02

# no sample 03

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x145570, 0x3DB0 # sample 04

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x149320, 0x46E0 # sample 05

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x14DA00, 0x8F0 # sample 06

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x14E2F0, 0xA00 # sample 07

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x14ECF0, 0x4280 # sample 08

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x152F70, 0x8A0 # sample 09

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x153810, 0x1660 # sample 0A

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x154E70, 0x2040 # sample 0B

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x156EB0, 0x2030 # sample 0C

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x158EE0, 0x2F30 # sample 0D

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x15BE10, 0x546A # sample 0E
.ifdef VERSION_US
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.endif
.ifdef VERSION_JP
.byte 0x05, 0x63, 0x91, 0xDE, 0x01, 0xEE
.endif

# peach US sounds
.ifdef VERSION_US
.align 4, 0x00
.incbin "sound/nlist09/0F.raw" # dear mario

.align 4, 0x00
.incbin "sound/nlist09/10.raw" # mario

.align 4, 0x00
.incbin "sound/nlist09/11.raw" # power of the stars

.align 4, 0x00
.incbin "sound/nlist09/12.raw" # and its all thanks to you

.align 4, 0x00
.incbin "sound/nlist09/13.raw" # thank you mario

.align 4, 0x00
.incbin "sound/nlist09/14.raw" # we have to do something special

.align 4, 0x00
.incbin "sound/nlist09/15.raw" # lets bake a delicious cake

.align 4, 0x00
.incbin "sound/nlist09/16.raw" # for mario

.align 4, 0x00
.incbin "sound/nlist09/17.raw" # mario
.endif
nlist_0A_end:

nlist_0B_rest: # US: 6B5B00
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x161280, 0x2E40 # 0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1640C0, 0x28A0 # 2E40

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x166960, 0x43D0 # 56E0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x16AD30, 0x42F0 # 9AB0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x16F020, 0x1E10 # DDA0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x170E30, 0x3790 # FBB0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1745C0, 0x7C0 # 13340

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x174D80, 0xB90 # 13B00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x175910, 0x1480 # 14690

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x176D90, 0x1AC0 # 15B10

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x178850, 0x25E0 # 175D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x17AE30, 0x1C20 # 19BB0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x17CA50, 0x11A0 # 1B7D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x17DBF0, 0x1200 # 1C970

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x17EDF0, 0x850 # 1DB70

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x17F640, 0x2FA0 # 1E3C0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1825E0, 0x3180 # 21360

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x185760, 0x4710 # 244E0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x189E70, 0x1BD0 # 28BF0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x18BA40, 0x2670 # 2A7C0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x18E0B0, 0x4F50 # 2CE30

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x193000, 0x4B50 # 31D80

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x197B50, 0x3950 # 368D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x19B4A0, 0x37E0 # 3A220

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x19EC80, 0x4DA0 # 3DA00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1A3A20, 0x46D0 # 427A0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1A80F0, 0x2360 # 46E70

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1AA450, 0x3D90 # 491D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1AE1E0, 0x19D0 # 4CF60

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1AFBB0, 0x5C30 # 4E930

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1B57E0, 0x400 # 54560

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1B5BE0, 0x1880 # 54960

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1B7460, 0x1090 # 561E0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1B84F0, 0x1CF0 # 57270

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1BA1E0, 0x3710 # 58F60

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1BD8F0, 0x3E10 # 5C670

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1C1700, 0x46F0 # 60480

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1C5DF0, 0x4460 # 64B70

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1CA250, 0x70F0 # 68FD0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1D1340, 0x6650 # 700C0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1D7990, 0x3E00 # 76710

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1DB790, 0x3180 # 7A510

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1DE910, 0x36E0 # 7D690

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1E1FF0, 0x1DF0 # 80D70

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1E3DE0, 0x4640 # 82B60

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1E8420, 0x3C10 # 871A0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1EC030, 0x4740 # 8ADB0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1F0770, 0x5170 # 8F4F0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1F58E0, 0x4630 # 94660

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1F9F10, 0x3C40 # 98C90

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x1FDB50, 0x4190 # 9C8D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x201CE0, 0x11D0 # A0A60

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x202EB0, 0x24A0 # A1C30

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x205350, 0x2A10 # A40D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x207D60, 0x2090 # A6AE0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x209DF0, 0x1D20 # A8B70

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x20BB10, 0x9C0 # AA890

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x20C4D0, 0x5270 # AB250

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x211740, 0x3A80 # B04C0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x2151C0, 0x5A70 # B3F40

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x21AC30, 0x4B30 # B99B0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x21F760, 0x3090 # BE4E0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x2227F0, 0x2CE0 # C1570

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x2254D0, 0x4DA0 # C4250

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x22A270, 0x3C60 # C8FF0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x22DED0, 0x4640 # CCC50

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x232510, 0xBB0 # D1290

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x2330C0, 0x31B0 # D1E40

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x236270, 0x3B90 # D4FF0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x239E00, 0x1CD0 # D8B80

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x23BAD0, 0x2C80 # DA850

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x23E750, 0x3430 # DD4D0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x241B80, 0x39D0 # E0900
nlist_0B_rest_end:

nlist_extra_1: # US: 799DD0
.incbin "bin/sm64.j.4E9FA0.bin", 0x245550, 0x3A80
nlist_extra_1_end:

nlist_extra_2: # US: 79D850
.incbin "bin/sm64.j.4E9FA0.bin", 0x248FD0, 0x1950
nlist_extra_2_end:

nlist_extra_3: # US: 79F1A0
.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x24A920, 0x9E00

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x254720, 0x41A0

.align 4, 0x00
.incbin "bin/sm64.j.4E9FA0.bin", 0x2588C0, 0x3710
nlist_extra_3_end:

.word 0, 0, 0, 0
