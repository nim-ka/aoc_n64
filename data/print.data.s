.include "macros.inc"
.include "globals.inc"

.section .data

#print
glabel D_803303A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x5F4, 0x58

glabel D_803303F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x64C, 0x4

glabel D_803303FC
	.incbin "bin/sm64.j.0EADAC.bin", 0x650, 0x4

glabel D_80330400
	.incbin "bin/sm64.j.0EADAC.bin", 0x654, 0x10
