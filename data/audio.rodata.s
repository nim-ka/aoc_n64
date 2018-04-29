.include "macros.inc"
.include "globals.inc"

.section .rodata

#audio data
glabel jtbl_80337BE0
	.word L80316BD0
	.word L80316BDC
	.word L80316C1C
	.word L80316BEC
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316BFC
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C0C

glabel D_80337C20
	.incbin "bin/rodata.bin", 0x31B0, 0x40

glabel jtbl_80337C60
	.word L8031A5B0
	.word L8031A5B8
	.word L8031A5DC
	.word L8031A5F4
	.word L8031A6D8
	.word L8031A70C
	.word L8031A714
	.word L8031A714
	.word L8031A794

	.word 0, 0, 0 # padding, file boundry?

glabel jtbl_80337C90
	.word L8031B2C0
	.word L8031B27C
	.word L8031B690
	.word L8031B690
	.word L8031B30C
	.word L8031B220
	.word L8031B690
	.word L8031B690
	.word L8031B1E4

glabel jtbl_80337CB4
	.word L8031B350
	.word L8031B3A8
	.word L8031B444
	.word L8031B3D4
	.word L8031B3D4
	.word L8031B494
	.word L8031B5B8
	.word L8031B688
	.word L8031B3A8
	.word L8031B350
	.word L8031BBE8
	.word L8031BBF4
	.word L8031BBE8
	.word L8031BBF4
	.word L8031BBE8

	# more missed literals?
	.incbin "bin/rodata.bin", 0x3280, 0x18

glabel jtbl_80337D08
	.word L8031C430
	.word L8031C3DC
	.word L8031C44C
	.word L8031C45C
	.word L8031C3F8
	.word L8031C6C8
	.word L8031C724
	.word L8031C75C
	.word L8031C75C
	.word L8031C7A8
	.word L8031C7B8
	.word L8031C75C
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C7D8
	.word L8031C7FC
	.word L8031C80C
	.word L8031C508
	.word L8031C6B8
	.word L8031C1CC
	.word L8031C698
	.word L8031C600
	.word L8031C5E4
	.word L8031C5D4
	.word L8031C5B8
	.word L8031C5A0
	.word L8031C568
	.word L8031C530
	.word L8031C4C0
	.word L8031C46C
	.word L8031C488
	.word L8031C650
	.word L8031C61C
	.word L8031C684
	.word L8031C820
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C3CC
	.word L8031C3A4
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C34C
	.word L8031C33C
	.word L8031C2F4
	.word L8031C2BC
	.word L8031C34C
	.word L8031C34C
	.word L8031C34C
	.word L8031C280
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC

glabel jtbl_80337E04
	.word L8031C89C
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C9E4
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA14
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA30
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA58
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8F8
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C9DC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8DC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C914
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C960
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C97C

	# even more missed literals
	.incbin "bin/rodata.bin", 0x3658, 0x4

	.word 0 # padding?

glabel jtbl_803380D0
	.word L8031D204
	.word L8031D1F4
	.word L8031CD54
	.word L8031CD54
	.word L8031D1E4
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D1D4
	.word L8031D1A0
	.word L8031D1A0
	.word L8031D190
	.word L8031D180
	.word L8031D150
	.word L8031D134
	.word L8031D118
	.word L8031CD54
	.word L8031CD54
	.word L8031D0E0
	.word L8031CFE4
	.word L8031CF74
	.word L8031CF74
	.word L8031CF54
	.word L8031CF50
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CF40
	.word L8031CF18
	.word L8031CD54
	.word L8031CD54
	.word L8031CEB8
	.word L8031CD54
	.word L8031CE70
	.word L8031CE38
	.word L8031CEB8
	.word L8031CEB8
	.word L8031CEB8
	.word L8031CDFC
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54

glabel jtbl_803381B0
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2D8
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2E4
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2EC
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2F4
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54

	# padding
	.word 0, 0, 0

	# unknown area
	.incbin "bin/rodata.bin", 0x38D0, 0x74

glabel jtbl_803383B4
	.word L8031F244
	.word L8031F0B4
	.word L8031F244
	.word L8031F2A8
	.word L8031F2A8
	.word L8031F2A8
	.word L8031F2A8
	.word L8031F220
	.word L8031F2A8
	.word L8031F2A8

glabel jtbl_803383DC
	.word L8031F52C
	.word L8031F3A4
	.word L8031F52C
	.word L8031F590
	.word L8031F590
	.word L8031F590
	.word L8031F590
	.word L8031F50C
	.word L8031F590
	.word L8031F590

	.word 0 #align?

	# 2 more
	.incbin "bin/rodata.bin", 0x3998, 0x8

	# missed literals
	.incbin "bin/rodata.bin", 0x39A0, 0x8

glabel jtbl_80338418
	.word L8031FBAC
	.word L8031FBEC
	.word L8031FC2C
	.word L8031FC6C
	.word L8031FCAC
	.word L8031FCEC
	.word L8031FD2C
	.word L8031FD54

	.incbin "bin/rodata.bin", 0x39C8, 0x18

glabel D_80338450
	.incbin "bin/rodata.bin", 0x39E0, 0x8

glabel D_80338458
	.incbin "bin/rodata.bin", 0x39E8, 0x8

glabel D_80338460
	.incbin "bin/rodata.bin", 0x39F0, 0x50

glabel D_803384B0
	.incbin "bin/rodata.bin", 0x3A40, 0x50

glabel D_80338500
	.incbin "bin/rodata.bin", 0x3A90, 0x10

glabel D_80338510
	.incbin "bin/rodata.bin", 0x3AA0, 0x4

glabel D_80338514
	.incbin "bin/rodata.bin", 0x3AA4, 0x8

glabel D_8033851C
	.incbin "bin/rodata.bin", 0x3AAC, 0x18

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

glabel D_80338630
	.incbin "bin/rodata.bin", 0x3BC0, 0x30

glabel D_80338660
	.incbin "bin/rodata.bin", 0x3BF0, 0x58

glabel D_803386B8
	.incbin "bin/rodata.bin", 0x3C48, 0x4

glabel D_803386BC
	.incbin "bin/rodata.bin", 0x3C4C, 0x4

glabel D_803386C0
	.incbin "bin/rodata.bin", 0x3C50, 0x10

glabel D_803386D0
	.incbin "bin/rodata.bin", 0x3C60, 0x80

glabel D_80338750
	.incbin "bin/rodata.bin", 0x3CE0, 0x800
	
glabel D_80338F50
	.incbin "bin/rodata.bin", 0x44E0, 0x2C0
