.include "macros.inc"
.include "globals.inc"

.section .rodata

#ingame menu
	.incbin "bin/rodata.bin", 0x2550, 0x58

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

	.incbin "bin/rodata.bin", 0x2630, 0x38

	.word 0, 0

	.incbin "bin/rodata.bin", 0x2670, 0x4

glabel D_803370E4
	.incbin "bin/rodata.bin", 0x2674, 0x8

glabel D_803370EC
	.incbin "bin/rodata.bin", 0x267C, 0x8

glabel jtbl_803370F4
	.word L802E035C
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E03CC
	.word L802E0364
	.word L802E0384
	.word L802E03A4
	.word L802E03B8






