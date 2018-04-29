.include "macros.inc"
.include "globals.inc"

.section .rodata

# 0x80334A70

# Unknown region 0EFA50-0F4210 [47C0]

#credits

glabel D_80334A90
	.ascii "1GAME DIRECTOR"
	.byte 0x00, 0x00

glabel D_80334AA0
	.incbin "bin/rodata.bin", 0x30, 0x14

glabel D_80334AB4
	.incbin "bin/rodata.bin", 0x44, 0x18

glabel D_80334ACC
	.incbin "bin/rodata.bin", 0x5C, 0x14

glabel D_80334AE0
	.incbin "bin/rodata.bin", 0x70, 0x10

glabel D_80334AF0
	.incbin "bin/rodata.bin", 0x80, 0x14

glabel D_80334B04
	.incbin "bin/rodata.bin", 0x94, 0x14

glabel D_80334B18
	.incbin "bin/rodata.bin", 0xA8, 0x14

glabel D_80334B2C
	.incbin "bin/rodata.bin", 0xBC, 0x10

glabel D_80334B3C
	.incbin "bin/rodata.bin", 0xCC, 0x10
glabel D_80334B4C
	.incbin "bin/rodata.bin", 0xDC, 0x10
glabel D_80334B5C
	.incbin "bin/rodata.bin", 0xEC, 0x10
glabel D_80334B6C
	.incbin "bin/rodata.bin", 0xFC, 0x14
glabel D_80334B80
	.incbin "bin/rodata.bin", 0x110, 0x10
glabel D_80334B90
	.incbin "bin/rodata.bin", 0x120, 0x18
glabel D_80334BA8
	.incbin "bin/rodata.bin", 0x138, 0x10
glabel D_80334BB8
	.incbin "bin/rodata.bin", 0x148, 0x14
glabel D_80334BCC
	.incbin "bin/rodata.bin", 0x15C, 0x10
glabel D_80334BDC
	.incbin "bin/rodata.bin", 0x16C, 0x14

glabel D_80334BF0
	.incbin "bin/rodata.bin", 0x180, 0x14
glabel D_80334C04
	.incbin "bin/rodata.bin", 0x194, 0xC
glabel D_80334C10
	.incbin "bin/rodata.bin", 0x1A0, 0xC
glabel D_80334C1C
	.incbin "bin/rodata.bin", 0x1AC, 0x14
glabel D_80334C30
	.incbin "bin/rodata.bin", 0x1C0, 0x14
glabel D_80334C44
	.incbin "bin/rodata.bin", 0x1D4, 0x10
glabel D_80334C54
	.incbin "bin/rodata.bin", 0x1E4, 0x10
glabel D_80334C64
	.incbin "bin/rodata.bin", 0x1F4, 0x10
glabel D_80334C74
	.incbin "bin/rodata.bin", 0x204, 0xC
glabel D_80334C80
	.incbin "bin/rodata.bin", 0x210, 0x10

glabel D_80334C90
	.incbin "bin/rodata.bin", 0x220, 0x10
glabel D_80334CA0
	.incbin "bin/rodata.bin", 0x230, 0x14
glabel D_80334CB4
	.incbin "bin/rodata.bin", 0x244, 0x10
glabel D_80334CC4
	.incbin "bin/rodata.bin", 0x254, 0x10
glabel D_80334CD4
	.incbin "bin/rodata.bin", 0x264, 0x14
glabel D_80334CE8
	.incbin "bin/rodata.bin", 0x278, 0x10
glabel D_80334CF8
	.incbin "bin/rodata.bin", 0x288, 0x10
glabel D_80334D08
	.incbin "bin/rodata.bin", 0x298, 0x10
glabel D_80334D18
	.incbin "bin/rodata.bin", 0x2A8, 0x14
glabel D_80334D2C
	.incbin "bin/rodata.bin", 0x2BC, 0x10

glabel D_80334D3C
	.incbin "bin/rodata.bin", 0x2CC, 0x14
glabel D_80334D50
	.incbin "bin/rodata.bin", 0x2E0, 0xC
glabel D_80334D5C
	.incbin "bin/rodata.bin", 0x2EC, 0x14
glabel D_80334D70
	.incbin "bin/rodata.bin", 0x300, 0x18
glabel D_80334D88
	.incbin "bin/rodata.bin", 0x318, 0x18
glabel D_80334DA0
	.incbin "bin/rodata.bin", 0x330, 0x10
glabel D_80334DB0
	.incbin "bin/rodata.bin", 0x340, 0xC
glabel D_80334DBC
	.incbin "bin/rodata.bin", 0x34C, 0x14
glabel D_80334DD0
	.incbin "bin/rodata.bin", 0x360, 0x10
glabel D_80334DE0
	.incbin "bin/rodata.bin", 0x370, 0x10

glabel D_80334DF0
	.incbin "bin/rodata.bin", 0x380, 0x14
glabel D_80334E04
	.incbin "bin/rodata.bin", 0x394, 0xC
glabel D_80334E10
	.incbin "bin/rodata.bin", 0x3A0, 0x14
glabel D_80334E24
	.incbin "bin/rodata.bin", 0x3B4, 0x14
glabel D_80334E38
	.incbin "bin/rodata.bin", 0x3C8, 0x14

glabel jtbl_80334E4C
	.word .L80249AC4
	.word .L80249ADC
	.word .L80249AF8
	.word .L80249B10
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249B28
	.word .L80249BDC
	.word .L80249B44
	.word .L80249B5C
	.word .L80249B78
	.word .L80249B90
	.word .L80249BA8
	.word .L80249BC0
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249C88
	.word .L80249BF8
	.word .L80249C10
	.word .L80249C28
	.word .L80249C40
	.word .L80249C58
	.word .L80249C70

glabel jtbl_80334EE0
	.word .L80249E94
	.word .L80249F3C
	.word .L80249E74
	.word .L80249EB4
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249EFC
	.word .L80249F3C
	.word .L80249ED8
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F3C
	.word .L80249F1C

glabel jtbl_80334F7C
	.word .L8024AA80
	.word .L8024AABC
	.word .L8024AB70
	.word .L8024ABE0
	.word .L8024AB0C
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024ACE0
	.word .L8024A960
	.word .L8024A9A0
	.word .L8024AA08
	.word .L8024ACE0
	.word .L8024A91C
	.word .L8024A8D8
	.word .L8024AC40
	.word .L8024AC6C
	.word .L8024A8D8

glabel jtbl_80334FE0
	.word L8024AE44
	.word L8024AE5C
	.word L8024AE78
	.word L8024AE88
	.word L8024AEBC

glabel jtbl_80334FF4
	.word .L8024B84C
	.word .L8024B8B0
	.word .L8024B860
	.word .L8024B874
	.word .L8024B888
	.word .L8024B89C

