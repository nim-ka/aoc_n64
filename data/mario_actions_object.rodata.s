.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario actions object
glabel jtbl_80335D30
	.incbin "bin/rodata.bin", 0x12C0, 0x28

glabel jtbl_80335D58
	.incbin "bin/rodata.bin", 0x12E8, 0x48
