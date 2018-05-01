.include "macros.inc"
.include "globals.inc"

.section .rodata

#rotate
glabel D_80336EC0
	.incbin "bin/rodata.bin", 0x2450, 0x8

glabel D_80336EC8
	.incbin "bin/rodata.bin", 0x2458, 0x8

glabel D_80336ED0
	.incbin "bin/rodata.bin", 0x2460, 0x8

glabel D_80336ED8
	.incbin "bin/rodata.bin", 0x2468, 0x8

glabel D_80336EE0
	.incbin "bin/rodata.bin", 0x2470, 0x8

glabel D_80336EE8
	.incbin "bin/rodata.bin", 0x2478, 0x8
glabel D_80336EF0
	.incbin "bin/rodata.bin", 0x2480, 0x8
glabel D_80336EF8
	.incbin "bin/rodata.bin", 0x2488, 0x8
glabel D_80336F00
	.incbin "bin/rodata.bin", 0x2490, 0x8

glabel D_80336F08
	.incbin "bin/rodata.bin", 0x2498, 0x8
glabel D_80336F10
	.incbin "bin/rodata.bin", 0x24A0, 0x8
glabel D_80336F18
	.incbin "bin/rodata.bin", 0x24A8, 0x8
glabel D_80336F20
	.incbin "bin/rodata.bin", 0x24B0, 0x8
glabel D_80336F28
	.incbin "bin/rodata.bin", 0x24B8, 0x8

glabel D_80336F30
	.incbin "bin/rodata.bin", 0x24C0, 0x8

glabel D_80336F38
	.incbin "bin/rodata.bin", 0x24C8, 0x8

glabel D_80336F40
	.incbin "bin/rodata.bin", 0x24D0, 0x8

glabel D_80336F48
	.incbin "bin/rodata.bin", 0x24D8, 0x8

glabel D_80336F50
	.incbin "bin/rodata.bin", 0x24E0, 0x8

glabel D_80336F58
	.incbin "bin/rodata.bin", 0x24E8, 0x8

glabel D_80336F60
	.incbin "bin/rodata.bin", 0x24F0, 0x8

glabel jtbl_80336F68
	.word L802CE93C
	.word L802CE964
	.word L802CE98C
	.word L802CEA70
	.word L802CEA70
	.word L802CEA70
	.word L802CEA70
	.word L802CEA70
	.word L802CEA70
	.word L802CEA70
	.word L802CE9B4
	.word L802CE9E4
	.word L802CEA14

	.word 0

