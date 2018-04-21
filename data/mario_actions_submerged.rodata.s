.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario actions submerged
glabel D_80335C70
	.incbin "bin/rodata.bin", 0x1200, 0x4

glabel jtbl_80335C74
	.incbin "bin/rodata.bin", 0x1204, 0x18

glabel jtbl_80335C8C
	.incbin "bin/rodata.bin", 0x121C, 0x18

glabel D_80335CA4
	.incbin "bin/rodata.bin", 0x1234, 0x4

glabel D_80335CA8
	.incbin "bin/rodata.bin", 0x1238, 0x4

glabel D_80335CAC
	.incbin "bin/rodata.bin", 0x123C, 0x4

glabel D_80335CB0
	.incbin "bin/rodata.bin", 0x1240, 0x4

glabel D_80335CB4
	.incbin "bin/rodata.bin", 0x1244, 0x8

glabel jtbl_80335CBC
	.incbin "bin/rodata.bin", 0x124C, 0x48

glabel jtbl_80335D04
	.incbin "bin/rodata.bin", 0x1294, 0x2C
