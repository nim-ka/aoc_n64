.include "macros.inc"
.include "globals.inc"

.section .rodata

#castle message behaviors
glabel jtbl_80335DA0
	.incbin "bin/rodata.bin", 0x1330, 0x14

glabel D_80335DB4
	.incbin "bin/rodata.bin", 0x1344, 0x4

glabel D_80335DB8
	.incbin "bin/rodata.bin", 0x1348, 0x18
