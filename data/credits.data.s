
.include "macros.inc"
.include "globals.inc"

.section .data

#credits
glabel D_8032C790
	.word D_80334A90
	.word D_80334AA0
	.word D_80334AB4
	.word D_80334ACC
	.word D_80334AE0
	.word D_80334AF0
	.word D_80334B04
	.word D_80334B18
	.word D_80334B2C
	.word D_80334B3C
	.word D_80334B4C
	.word D_80334B5C
	.word D_80334B6C
	.word D_80334B80
	.word D_80334B90
	.word D_80334BA8
	.word D_80334BB8
	.word D_80334BCC
	.word D_80334BDC
	.word D_80334BF0
	.word D_80334C04
	.word D_80334C10
	.word D_80334C1C
	.word D_80334C30
	.word D_80334C44
	.word D_80334C54
	.word D_80334C64
	.word D_80334C74
	.word D_80334C80
	.word D_80334C90
	.word D_80334CA0
	.word D_80334CB4
	.word D_80334CC4
	.word D_80334CD4
	.word D_80334CE8
	.word D_80334CF8
	.word D_80334D08
	.word D_80334D18
	.word D_80334D2C
	.word D_80334D3C
	.word D_80334D50
	.word D_80334D5C
	.word D_80334D70
	.word D_80334D88
	.word D_80334DA0
	.word D_80334DB0
	.word D_80334DBC
	.word D_80334DD0
	.word D_80334DE0
	.word D_80334DF0
	.word D_80334E04
	.word D_80334E10
	.word D_80334E24
	.word D_80334E38

glabel D_8032C868
	.incbin "bin/sm64.j.0E7000.bin", 0x868, 0x170

glabel gMarioState
	.incbin "bin/sm64.j.0E7000.bin", 0x9D8, 0x8

glabel D_8032C9E0
	.incbin "bin/sm64.j.0E7000.bin", 0x9E0, 0x10
