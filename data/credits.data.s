
.include "macros.inc"
.include "globals.inc"

.section .data

#credits
glabel D_8032C790 # undumped pointer list
	.incbin "bin/sm64.j.0E7000.bin", 0x790, 0xD8

glabel D_8032C868
	.incbin "bin/sm64.j.0E7000.bin", 0x868, 0x170

glabel D_8032C9D8
	.incbin "bin/sm64.j.0E7000.bin", 0x9D8, 0x8

glabel D_8032C9E0
	.incbin "bin/sm64.j.0E7000.bin", 0x9E0, 0x10
