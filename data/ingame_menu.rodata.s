.include "macros.inc"
.include "globals.inc"

.section .rodata

#ingame menu
glabel D_80336FC0
	.incbin "bin/rodata.bin", 0x2550, 0x10

glabel D_80336FD0
	.incbin "bin/rodata.bin", 0x2560, 0x8
glabel D_80336FD8
	.incbin "bin/rodata.bin", 0x2568, 0x8
glabel D_80336FE0
	.incbin "bin/rodata.bin", 0x2570, 0x8
glabel D_80336FE8
	.incbin "bin/rodata.bin", 0x2578, 0x8
glabel D_80336FF0
	.incbin "bin/rodata.bin", 0x2580, 0x10

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

glabel D_803370A0
	.incbin "bin/rodata.bin", 0x2630, 0x8

glabel D_803370A8
	.incbin "bin/rodata.bin", 0x2638, 0x8
glabel D_803370B0
	.incbin "bin/rodata.bin", 0x2640, 0x8
glabel D_803370B8
	.incbin "bin/rodata.bin", 0x2648, 0x8
glabel D_803370C0
	.incbin "bin/rodata.bin", 0x2650, 0x8
glabel D_803370C8
	.incbin "bin/rodata.bin", 0x2658, 0x8
glabel D_803370D0
	.incbin "bin/rodata.bin", 0x2660, 0x8

	.word 0, 0

glabel D_803370E0
	.incbin "bin/rodata.bin", 0x2670, 0x4

glabel D_803370E4
	.incbin "bin/rodata.bin", 0x2674, 0x4
glabel D_803370E8
	.incbin "bin/rodata.bin", 0x2678, 0x4

glabel D_803370EC
	.incbin "bin/rodata.bin", 0x267C, 0x4
glabel D_803370F0
	.incbin "bin/rodata.bin", 0x2680, 0x4

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
