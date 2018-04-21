.include "macros.inc"
.include "globals.inc"

.section .rodata

#rendering
glabel D_80335DD0
	.incbin "bin/rodata.bin", 0x1360, 0x10

glabel D_80335DE0
	.incbin "bin/rodata.bin", 0x1370, 0x8

glabel D_80335DE8
	.incbin "bin/rodata.bin", 0x1378, 0x8

glabel D_80335DF0
	.incbin "bin/rodata.bin", 0x1380, 0xC

glabel jtbl_80335DFC
	.incbin "bin/rodata.bin", 0x138C, 0xB0

glabel jtbl_80335EAC
	.incbin "bin/rodata.bin", 0x143C, 0xA4
