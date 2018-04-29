.include "macros.inc"
.include "globals.inc"

.section .rodata

#rotate
glabel D_80336EC0
	.incbin "bin/rodata.bin", 0x2450, 0x78

glabel D_80336F38
	.incbin "bin/rodata.bin", 0x24C8, 0x10

glabel D_80336F48
	.incbin "bin/rodata.bin", 0x24D8, 0x20

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
