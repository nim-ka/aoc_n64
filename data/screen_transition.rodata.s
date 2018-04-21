.include "macros.inc"
.include "globals.inc"

.section .rodata

#screen transition
glabel jtbl_80336E70
	.incbin "bin/rodata.bin", 0x2400, 0x50
