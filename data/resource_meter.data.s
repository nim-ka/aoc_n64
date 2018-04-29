
.include "macros.inc"
.include "globals.inc"

.section .data

# resource_meter
glabel D_8032CFB0
	.word 0

glabel D_8032CFB4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4CC, 0x4

glabel D_8032CFB8
	.word 0
	.word 0
