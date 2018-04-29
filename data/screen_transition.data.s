.include "macros.inc"
.include "globals.inc"

.section .data

#screen_transition
glabel D_8032FF60
	.word 0

glabel D_8032FF64
	.word 0

glabel D_8032FF68
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC, 0x18
