.include "macros.inc"
.include "globals.inc"

.section .rodata

#rotate
glabel D_80336EC0
	.incbin "bin/rodata.bin", 0x2450, 0x78

glabel D_80336F38
	.incbin "bin/rodata.bin", 0x24C8, 0x10

glabel D_80336F48
	.incbin "bin/rodata.bin", 0x24D8, 0x20

glabel jtbl_80336F68
	.incbin "bin/rodata.bin", 0x24F8, 0x38
