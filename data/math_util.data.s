.include "macros.inc"


.section .data

#math util
glabel gSineTable
	.incbin "bin/sm64.j.101998.bin", 0x70, 0x1000

glabel gCosineTable
	.incbin "bin/sm64.j.101998.bin", 0x1070, 0x1000

glabel D_80388000
	.incbin "bin/sm64.j.101998.bin", 0x2070, 0x3000

glabel D_8038B000
	.incbin "bin/sm64.j.101998.bin", 0x5070, 0x810
