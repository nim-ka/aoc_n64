.include "macros.inc"


.section .rodata

glabel D_80336E60
	.incbin "bin/rodata.bin", 0x23F0, 0x8

glabel D_80336E68
	.incbin "bin/rodata.bin", 0x23F8, 0x8

#screen transition
glabel jtbl_80336E70
	.word L802CC148
	.word L802CC168
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC188
	.word L802CC1B0
	.word L802CC1D8
	.word L802CC200
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC2D0
	.word L802CC228
	.word L802CC254
	.word L802CC280
	.word L802CC2A8

