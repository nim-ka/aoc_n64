.include "macros.inc"
.include "globals.inc"

.section .data

#moving texture
glabel D_8032FFD0
	.incbin "bin/sm64.j.0EADAC.bin", 0x224, 0x4

glabel D_8032FFD4
	.incbin "bin/sm64.j.0EADAC.bin", 0x228, 0x4

glabel D_8032FFD8
	.incbin "bin/sm64.j.0EADAC.bin", 0x22C, 0x8

glabel D_8032FFE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x234, 0x1B

glabel D_8032FFFB
	.incbin "bin/sm64.j.0EADAC.bin", 0x24F, 0x4

glabel D_8032FFFF
	.incbin "bin/sm64.j.0EADAC.bin", 0x253, 0x5

glabel D_80330004
	.incbin "bin/sm64.j.0EADAC.bin", 0x258, 0x240

glabel D_80330244
	.incbin "bin/sm64.j.0EADAC.bin", 0x498, 0xD8

glabel D_8033031C
	.incbin "bin/sm64.j.0EADAC.bin", 0x570, 0x6C

glabel D_80330388
	.incbin "bin/sm64.j.0EADAC.bin", 0x5DC, 0x8
