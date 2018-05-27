
.include "macros.inc"


.section .data

glabel D_8032CF10
	.incbin "bin/sm64.j.0E7AE8.bin", 0x428, 0x40

glabel D_8032CF50
	.incbin "bin/sm64.j.0E7AE8.bin", 0x468, 0x40

glabel D_8032CF90
	.word 0

glabel D_8032CF94
	.word 0

glabel D_8032CF98
	.word 0

glabel D_8032CF9C
	.word 0

glabel D_8032CFA0
	.word 0

glabel D_8032CFA4
	.word 0

glabel gAreaUpdateCounter
	.word 0
	.word 0
