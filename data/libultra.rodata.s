.include "macros.inc"


.section .rodata

.ifdef VERSION_JP
glabel D_80338440
	.incbin "bin/rodata.bin", 0x39D0, 0x10

glabel D_80338450
	.word 0x80000000
	.word 0

glabel D_80338458
	.word 0x80000000
	.word 0

glabel D_80338460
	.incbin "bin/rodata.bin", 0x39F0, 0x28

glabel D_80338488
	.incbin "bin/rodata.bin", 0x3A18, 0x8

glabel D_80338490
	.incbin "bin/rodata.bin", 0x3A20, 0x8

glabel D_80338498
	.incbin "bin/rodata.bin", 0x3A28, 0x8

glabel D_803384A0
	.incbin "bin/rodata.bin", 0x3A30, 0x10

glabel D_803384B0
	.incbin "bin/rodata.bin", 0x3A40, 0x28

glabel D_803384D8
	.incbin "bin/rodata.bin", 0x3A68, 0x8

glabel D_803384E0
	.incbin "bin/rodata.bin", 0x3A70, 0x8

glabel D_803384E8
	.incbin "bin/rodata.bin", 0x3A78, 0x8

glabel D_803384F0
	.incbin "bin/rodata.bin", 0x3A80, 0x10

glabel D_80338500
	.incbin "bin/rodata.bin", 0x3A90, 0x10

glabel D_80338510
	.incbin "bin/rodata.bin", 0x3AA0, 0x4

glabel D_80338514
	.incbin "bin/rodata.bin", 0x3AA4, 0x8

glabel D_8033851C
	.incbin "bin/rodata.bin", 0x3AAC, 0x18

.else

# Unused labels for US. TODO: Resolve these.
glabel D_80338450
glabel D_80338458
glabel D_80338460
glabel D_80338488
glabel D_80338490
glabel D_80338498
glabel D_803384A0

glabel D_U_803397B0
	.word 0x3F91DF46

glabel D_U_803397B4
glabel D_80338410
	.word 0x9D353918, 0x00000000

	.word 0 # align?

glabel D_U_803397C0
	.word 0x80000000, 0x00000000

glabel D_U_803397C8
	.word 0x80000000, 0x00000000

glabel D_U_803397D0
	.word 0x3FF00000, 0x00000000

	# TODO: Place labels here
	.word 0xBFC55554
	.word 0xBC83656D
	.word 0x3F8110ED
	.word 0x3804C2A0
	.word 0xBF29F6FF
	.word 0xEEA56814
	.word 0x3EC5DBDF
	.word 0x0E314BFE

glabel D_U_803397F8
	.word 0x3FD45F30
	.word 0x6DC9C883

glabel D_U_80339800
	.word 0x400921FB
	.word 0x50000000

glabel D_U_80339808
	.word 0x3E6110B4
	.word 0x611A6263

glabel D_U_80339810
	.word 0x00000000
	.word 0x00000000

	.word 0x00000000
	.word 0x00000000

glabel D_803384B0
	.word 0x3FF00000
	.word 0x00000000
	.word 0xBFC55554
	.word 0xBC83656D

	.word 0x3F8110ED
	.word 0x3804C2A0
	.word 0xBF29F6FF
	.word 0xEEA56814

	.word 0x3EC5DBDF
	.word 0x0E314BFE

glabel D_803384D8
	.word 0x3FD45F30
	.word 0x6DC9C883

glabel D_803384E0
	.word 0x400921FB
	.word 0x50000000

glabel D_803384E8
	.word 0x3E6110B4
	.word 0x611A6263

glabel D_803384F0
	.word 0x00000000
	.word 0x00000000
	.word 0x00000000
	.word 0x00000000

glabel D_80338500
	.word 0x3C8EFA35
	.word 0x00000000
	.word 0x00000000
	.word 0x00000000

glabel D_80338510
	.word 0x686C4C00

glabel D_80338514
	.word 0x202B2D23
	.word 0x30000000

glabel D_8033851C
	.word 0x00000001
	.word 0x00000002
	.word 0x00000004
	.word 0x00000008
	.word 0x00000010
	.word 0x00000000

.endif

glabel jtbl_80338534
	.word L80326044
	.word L80326470
	.word L80326044
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80325E60
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80325C10
	.word L80325C60
	.word L80326044
	.word L80326044
	.word L80326044
	.word L80326470
	.word L80325C60
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L8032624C
	.word L80325E60
	.word L80326374
	.word L80326470
	.word L80326470
	.word L803263D8
	.word L80326470
	.word L80325E60
	.word L80326470
	.word L80326470
	.word L80325E60

	# padding
	.word 0, 0, 0

glabel D_80338610
	.incbin "bin/rodata.bin", 0x3BA0, 0x20

glabel jtbl_80338630
	.word L80326B9C
	.word L80326B64
	.word L80326B44
	.word L803269B8
	.word L80326984
	.word L80326AE8
	.word L80326BE8
	.word L80326BE8
	.word L80326964
	.word 0
	.word 0
	.word 0

glabel D_80338660
	.incbin "bin/rodata.bin", 0x3BF0, 0x10

glabel D_80338670
	.incbin "bin/rodata.bin", 0x3C00, 0x48

glabel D_803386B8
	.incbin "bin/rodata.bin", 0x3C48, 0x4

glabel D_803386BC
	.incbin "bin/rodata.bin", 0x3C4C, 0x4

glabel D_803386C0
	.incbin "bin/rodata.bin", 0x3C50, 0x8

glabel D_803386C8
	.incbin "bin/rodata.bin", 0x3C58, 0x8

glabel D_803386D0
	.incbin "bin/rodata.bin", 0x3C60, 0x80

glabel D_80338750
	.incbin "bin/rodata.bin", 0x3CE0, 0x800

glabel D_80338F50
	.incbin "bin/rodata.bin", 0x44E0, 0x2C0

# TODO: fix naming
glabel audio_data_end
