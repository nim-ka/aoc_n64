
.include "macros.inc"
.include "globals.inc"

.section .data

#save file

glabel D_8032CE30
	.word 0

glabel D_8032CE34
	.incbin "bin/sm64.j.0E7AE8.bin", 0x34C, 0x3

glabel D_8032CE37
	.incbin "bin/sm64.j.0E7AE8.bin", 0x34F, 0x29
