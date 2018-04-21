.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario step
glabel D_803354D0
	.incbin "bin/rodata.bin", 0xA60, 0x4

glabel D_803354D4
	.incbin "bin/rodata.bin", 0xA64, 0x4

glabel jtbl_803354D8
	.incbin "bin/rodata.bin", 0xA68, 0x34

glabel D_8033550C
	.incbin "bin/rodata.bin", 0xA9C, 0x4

glabel D_80335510
	.incbin "bin/rodata.bin", 0xAA0, 0x8

glabel D_80335518
	.incbin "bin/rodata.bin", 0xAA8, 0x8

glabel D_80335520
	.incbin "bin/rodata.bin", 0xAB0, 0x10
