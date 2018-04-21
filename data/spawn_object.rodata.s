.include "macros.inc"
.include "globals.inc"

.section .rodata

#spawn object
glabel D_80336C60
	.incbin "bin/rodata.bin", 0x21F0, 0x4

glabel D_80336C64
	.incbin "bin/rodata.bin", 0x21F4, 0x4

glabel D_80336C68
	.incbin "bin/rodata.bin", 0x21F8, 0x4

glabel D_80336C6C
	.incbin "bin/rodata.bin", 0x21FC, 0x4
