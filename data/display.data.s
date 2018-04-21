
.include "macros.inc"
.include "globals.inc"

.section .data

	.incbin "bin/sm64.j.0E7000.bin", 0x690, 0x4

glabel D_8032C694
	.incbin "bin/sm64.j.0E7000.bin", 0x694, 0x4

glabel D_8032C698
	.incbin "bin/sm64.j.0E7000.bin", 0x698, 0x4

glabel D_8032C69C
	.incbin "bin/sm64.j.0E7000.bin", 0x69C, 0x4
