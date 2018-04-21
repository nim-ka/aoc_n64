.include "macros.inc"
.include "globals.inc"

.section .rodata

#interaction
glabel jtbl_80335010
	.incbin "bin/rodata.bin", 0x5A0, 0x80

glabel jtbl_80335090
	.incbin "bin/rodata.bin", 0x620, 0xC8

glabel jtbl_80335158
	.incbin "bin/rodata.bin", 0x6E8, 0x118

glabel D_80335270
	.incbin "bin/rodata.bin", 0x800, 0x4

glabel D_80335274
	.incbin "bin/rodata.bin", 0x804, 0x4

glabel D_80335278
	.incbin "bin/rodata.bin", 0x808, 0x8
