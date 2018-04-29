.include "macros.inc"
.include "globals.inc"

.section .data

# mapinfo
glabel D_8032FEE0
	.word D_80336C80
	.word D_80336C88
	.word D_80336C90
	.word D_80336C98
	.word D_80336CA0
	.word D_80336CA8
	.word D_80336CB0
	.word D_80336CB8
	.word D_80336CC0

glabel D_8032FF04
	.word D_80336CC4
	.word D_80336CCC
	.word D_80336CD4
	.word D_80336CDC
	.word D_80336CE4
	.word D_80336CEC
	.word D_80336CF4
	.word D_80336CFC
	.word D_80336D04

glabel D_8032FF28
	.word 0

glabel D_8032FF2C
	.word 0

glabel D_8032FF30
	.word 0

glabel D_8032FF34
	.word 0

glabel D_8032FF38
	.word 0

glabel D_8032FF3C
	.word 0

glabel D_8032FF40
	.word 0

glabel D_8032FF44
	.word 0

glabel D_8032FF48
	.incbin "bin/sm64.j.0EADAC.bin", 0x19C, 0x18
