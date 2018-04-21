.include "macros.inc"
.include "globals.inc"

.section .data

#transparent texture
glabel D_80330390
	.incbin "bin/sm64.j.0EADAC.bin", 0x5E4, 0x4

glabel D_80330394
	.incbin "bin/sm64.j.0EADAC.bin", 0x5E8, 0x4

glabel D_80330398
	.incbin "bin/sm64.j.0EADAC.bin", 0x5EC, 0x8
