.include "macros.inc"

.section .rodata

glabel D_80337000
	.incbin "bin/rodata.bin", 0x2590, 0x8

glabel D_80337008
	.incbin "bin/rodata.bin", 0x2598, 0x8

glabel D_80337010
	.incbin "bin/rodata.bin", 0x25A0, 0x8

glabel jtbl_80337018
	.word L802D8C04
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8BA4
	.word L802D8BB4
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8C18
	.word L802D8B74
	.word L802D8B38

	.word 0, 0
