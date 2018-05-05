.include "macros.inc"


.section .data

#moving texture
glabel D_8032FFD0
	.incbin "bin/sm64.j.0EADAC.bin", 0x224, 0x4

glabel D_8032FFD4
	.word 0

glabel D_8032FFD8
	.word 0

glabel D_8032FFDC
	.word 0

glabel D_8032FFE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x234, 0x4

glabel D_8032FFE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x238, 0x20

glabel D_80330004
	.incbin "bin/sm64.j.0EADAC.bin", 0x258, 0xC

glabel D_80330010
	.incbin "bin/sm64.j.0EADAC.bin", 0x264, 0x14

glabel D_80330024
	.incbin "bin/sm64.j.0EADAC.bin", 0x278, 0x220

glabel D_80330244
	.incbin "bin/sm64.j.0EADAC.bin", 0x498, 0xC

glabel D_80330250
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A4, 0x14

glabel D_80330264
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B8, 0xB8

glabel D_8033031C
	.incbin "bin/sm64.j.0EADAC.bin", 0x570, 0xC

glabel D_80330328
	.incbin "bin/sm64.j.0EADAC.bin", 0x57C, 0x14

glabel D_8033033C
	.incbin "bin/sm64.j.0EADAC.bin", 0x590, 0x4C

glabel D_80330388
	.incbin "bin/sm64.j.0EADAC.bin", 0x5DC, 0x8
