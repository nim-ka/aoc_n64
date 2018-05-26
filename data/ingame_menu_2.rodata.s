.include "macros.inc"

.section .rodata

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

