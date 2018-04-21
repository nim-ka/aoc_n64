.include "macros.inc"
.include "globals.inc"

.section .rodata

#level script
glabel jtbl_8038BAF0
	.incbin "bin/sm64.j.1074A0.bin", 0x60, 0x20

glabel jtbl_8038BB10
	.incbin "bin/sm64.j.1074A0.bin", 0x80, 0x14

glabel jtbl_8038BB24
	.incbin "bin/sm64.j.1074A0.bin", 0x94, 0x1C
