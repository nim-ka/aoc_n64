
.include "macros.inc"
.include "globals.inc"

.section .data

#mario
glabel D_8032CB40
	.incbin "bin/sm64.j.0E7AE8.bin", 0x58, 0x3B

glabel D_8032CB7B
	.incbin "bin/sm64.j.0E7AE8.bin", 0x93, 0x5

glabel D_8032CB80
	.incbin "bin/sm64.j.0E7AE8.bin", 0x98, 0x4

glabel D_8032CB84
	.incbin "bin/sm64.j.0E7AE8.bin", 0x9C, 0xC
