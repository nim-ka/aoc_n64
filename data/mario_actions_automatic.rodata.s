.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario actions automatic
glabel D_803357A0
	.incbin "bin/rodata.bin", 0xD30, 0x4

glabel D_803357A4
	.incbin "bin/rodata.bin", 0xD34, 0xC

glabel jtbl_803357B0
	.incbin "bin/rodata.bin", 0xD40, 0x20
