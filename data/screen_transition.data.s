.include "macros.inc"
.include "globals.inc"

.section .data

#screen_transition
glabel D_8032FF60
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B4, 0x4

glabel D_8032FF64
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B8, 0x4

glabel D_8032FF68
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC, 0x18
