.include "macros.inc"
.include "globals.inc"

.section .data

#graph node
	.incbin "bin/sm64.j.101998.bin", 0x0, 0x40

glabel D_80385FD0
	.incbin "bin/sm64.j.101998.bin", 0x40, 0xC

glabel D_80385FDC
	.incbin "bin/sm64.j.101998.bin", 0x4C, 0x8

glabel D_80385FE4
	.incbin "bin/sm64.j.101998.bin", 0x54, 0x1C
