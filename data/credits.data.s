
.include "macros.inc"
.include "globals.inc"

.section .data

#credits
glabel D_8032C790
	.word D_80334A90
	.word D_80334AA0
glabel D_8032C798
	.word D_80334AB4
	.word D_80334ACC
	.word D_80334AE0
glabel D_8032C7A4
	.word D_80334AF0
	.word D_80334B04
	.word D_80334B18
glabel D_8032C7B0
	.word D_80334B2C
	.word D_80334B3C
	.word D_80334B4C
	.word D_80334B5C
glabel D_8032C7C0
	.word D_80334B6C
	.word D_80334B80
glabel D_8032C7C8
	.word D_80334B90
	.word D_80334BA8
glabel D_8032C7D0
	.word D_80334BB8
	.word D_80334BCC
	.word D_80334BDC
glabel D_8032C7DC
	.word D_80334BF0
	.word D_80334C04
	.word D_80334C10
glabel D_8032C7E8
	.word D_80334C1C
	.word D_80334C30
	.word D_80334C44
	.word D_80334C54
glabel D_8032C7F8
	.word D_80334C64
	.word D_80334C74
glabel D_8032C800
	.word D_80334C80
	.word D_80334C90
glabel D_8032C808
	.word D_80334CA0
	.word D_80334CB4
glabel D_8032C810
	.word D_80334CC4
	.word D_80334CD4
	.word D_80334CE8
glabel D_8032C81C
	.word D_80334CF8
	.word D_80334D08
glabel D_8032C824
	.word D_80334D18
	.word D_80334D2C
	.word D_80334D3C
	.word D_80334D50
glabel D_8032C834
	.word D_80334D5C
	.word D_80334D70
glabel D_8032C83C
	.word D_80334D88
	.word D_80334DA0
	.word D_80334DB0
glabel D_8032C848
	.word D_80334DBC
	.word D_80334DD0
	.word D_80334DE0
	.word D_80334DF0
glabel D_8032C858
	.word D_80334E04
	.word D_80334E10
glabel D_8032C860
	.word D_80334E24
	.word D_80334E38

glabel D_8032C868
	.incbin "bin/sm64.j.0E7000.bin", 0x868, 0xC
	.word NULL
	.incbin "bin/sm64.j.0E7000.bin", 0x878, 0xC
	.word D_8032C790
	.incbin "bin/sm64.j.0E7000.bin", 0x888, 0xC
	.word D_8032C798
	.incbin "bin/sm64.j.0E7000.bin", 0x898, 0xC
	.word D_8032C7A4
	.incbin "bin/sm64.j.0E7000.bin", 0x8A8, 0xC
	.word D_8032C7B0
	.incbin "bin/sm64.j.0E7000.bin", 0x8B8, 0xC
	.word D_8032C7C0
	.incbin "bin/sm64.j.0E7000.bin", 0x8C8, 0xC
	.word D_8032C7C8
	.incbin "bin/sm64.j.0E7000.bin", 0x8D8, 0xC
	.word D_8032C7D0
	.incbin "bin/sm64.j.0E7000.bin", 0x8E8, 0xC
	.word D_8032C7DC
	.incbin "bin/sm64.j.0E7000.bin", 0x8F8, 0xC
	.word D_8032C7E8
	.incbin "bin/sm64.j.0E7000.bin", 0x908, 0xC
	.word D_8032C7F8
	.incbin "bin/sm64.j.0E7000.bin", 0x918, 0xC
	.word D_8032C800
	.incbin "bin/sm64.j.0E7000.bin", 0x928, 0xC
	.word D_8032C808
	.incbin "bin/sm64.j.0E7000.bin", 0x938, 0xC
	.word D_8032C810
	.incbin "bin/sm64.j.0E7000.bin", 0x948, 0xC
	.word D_8032C81C
	.incbin "bin/sm64.j.0E7000.bin", 0x958, 0xC
	.word D_8032C824
	.incbin "bin/sm64.j.0E7000.bin", 0x968, 0xC
	.word D_8032C834
	.incbin "bin/sm64.j.0E7000.bin", 0x978, 0xC
	.word D_8032C83C
	.incbin "bin/sm64.j.0E7000.bin", 0x988, 0xC
	.word D_8032C848
	.incbin "bin/sm64.j.0E7000.bin", 0x998, 0xC
	.word D_8032C858
	.incbin "bin/sm64.j.0E7000.bin", 0x9A8, 0xC
	.word D_8032C860
	.incbin "bin/sm64.j.0E7000.bin", 0x9B8, 0xC
	.word 0
	.incbin "bin/sm64.j.0E7000.bin", 0x9C8, 0xC
	.word 0

glabel gMarioState
	.word gMarioStates
	.word 0

glabel D_8032C9E0
	.word 0
	.word 0
	.word 0
	.word 0
