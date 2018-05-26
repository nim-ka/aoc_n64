.include "macros.inc"

.section .data

#ingame menu 2

glabel D_80330640
	.word 0
	.word 0

glabel D_80330648
	.incbin "bin/sm64.j.0EADAC.bin", 0x89C, 0x30

glabel D_80330678
	.incbin "bin/sm64.j.0EADAC.bin", 0x8CC, 0x8

glabel D_80330680
	.incbin "bin/sm64.j.0EADAC.bin", 0x8D4, 0x8

glabel D_80330688
	.incbin "bin/sm64.j.0EADAC.bin", 0x8DC, 0x10

glabel D_80330698
	.incbin "bin/sm64.j.0EADAC.bin", 0x8EC, 0x38
