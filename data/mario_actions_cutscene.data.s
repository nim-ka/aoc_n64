
.include "macros.inc"
.include "globals.inc"

.section .data

#mario_actions_cutscene
glabel D_8032CBD0
	.incbin "bin/sm64.j.0E7AE8.bin", 0xE8, 0x10

glabel D_8032CBE0
	.word 0

glabel D_8032CBE4
	.word 0

glabel D_8032CBE8
	.word 0

glabel D_8032CBEC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x104, 0x8

glabel D_8032CBF4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x10C, 0x8

glabel D_8032CBFC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x114, 0x86

glabel D_8032CC82
	.incbin "bin/sm64.j.0E7AE8.bin", 0x19A, 0x52

glabel D_8032CCD4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1EC, 0x2

glabel D_8032CCD6
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1EE, 0x2

glabel D_8032CCD8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1F0, 0x2

glabel D_8032CCDA
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1F2, 0x16

