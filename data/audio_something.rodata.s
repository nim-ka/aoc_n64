.include "macros.inc"

.section .rodata

# audio

glabel D_80337BB0
	.incbin "bin/rodata.bin", 0x3140, 0x8
glabel D_80337BB8
	.incbin "bin/rodata.bin", 0x3148, 0x8
glabel D_80337BC0
	.incbin "bin/rodata.bin", 0x3150, 0x8
glabel D_80337BC8
	.incbin "bin/rodata.bin", 0x3158, 0x8
glabel D_80337BD0
	.incbin "bin/rodata.bin", 0x3160, 0x8

glabel D_80337BD8
	.incbin "bin/rodata.bin", 0x3168, 0x8

