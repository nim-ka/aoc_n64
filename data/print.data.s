.include "macros.inc"
.include "globals.inc"

.section .data

#print
glabel D_803303A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x5F4, 0x8
glabel D_803303A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x5FC, 0x3C
glabel D_803303E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x638, 0x8

glabel D_803303EC
	.word D_803303A0
	.word D_803303A8
	.word D_803303E4

glabel D_803303F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x64C, 0x4

glabel D_803303FC
	.word 0

glabel D_80330400
	.word 0
	.word 0
	.word 0
	.word 0
