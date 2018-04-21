.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario actions stationary
glabel D_803357D0
	.incbin "bin/rodata.bin", 0xD60, 0x4

glabel D_803357D4
	.incbin "bin/rodata.bin", 0xD64, 0x4

glabel jtbl_803357D8
	.incbin "bin/rodata.bin", 0xD68, 0x2C

glabel jtbl_80335804
	.incbin "bin/rodata.bin", 0xD94, 0x14

glabel jtbl_80335818
	.incbin "bin/rodata.bin", 0xDA8, 0x60

glabel jtbl_80335878
	.incbin "bin/rodata.bin", 0xE08, 0x68
