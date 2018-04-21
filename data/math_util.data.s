.include "macros.inc"
.include "globals.inc"

.section .data

#math util
glabel D_80386000
	.incbin "bin/sm64.j.101998.bin", 0x70, 0x1000

glabel D_80387000
	.incbin "bin/sm64.j.101998.bin", 0x1070, 0x4000

glabel D_8038B000
	.incbin "bin/sm64.j.101998.bin", 0x5070, 0x810
