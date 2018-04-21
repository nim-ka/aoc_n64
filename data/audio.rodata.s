.include "macros.inc"
.include "globals.inc"

.section .rodata

#audio data
glabel jtbl_80337BE0
	.incbin "bin/rodata.bin", 0x3170, 0x40

glabel D_80337C20
	.incbin "bin/rodata.bin", 0x31B0, 0x40

glabel jtbl_80337C60
	.incbin "bin/rodata.bin", 0x31F0, 0x30

glabel jtbl_80337C90
	.incbin "bin/rodata.bin", 0x3220, 0x24

glabel jtbl_80337CB4
	.incbin "bin/rodata.bin", 0x3244, 0x150

glabel jtbl_80337E04
	.incbin "bin/rodata.bin", 0x3394, 0x2CC

glabel jtbl_803380D0
	.incbin "bin/rodata.bin", 0x3660, 0xE0

glabel jtbl_803381B0
	.incbin "bin/rodata.bin", 0x3740, 0x204

glabel jtbl_803383B4
	.incbin "bin/rodata.bin", 0x3944, 0x28

glabel jtbl_803383DC
	.incbin "bin/rodata.bin", 0x396C, 0x3C

glabel jtbl_80338418
	.incbin "bin/rodata.bin", 0x39A8, 0x38

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
	.incbin "bin/rodata.bin", 0x3AC4, 0xDC

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
