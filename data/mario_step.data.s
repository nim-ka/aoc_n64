
.include "macros.inc"
.include "globals.inc"

.section .data

#mario step
glabel D_8032CB90
	.incbin "bin/sm64.j.0E7AE8.bin", 0xA8, 0x8

glabel D_8032CB98
	.incbin "bin/sm64.j.0E7AE8.bin", 0xB0, 0x38
