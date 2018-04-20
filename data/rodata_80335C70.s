.include "macros.inc"
.include "globals.inc"

.section .rodata

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

glabel jtbl_80335D30
	.incbin "bin/rodata.bin", 0x12C0, 0x28

glabel jtbl_80335D58
	.incbin "bin/rodata.bin", 0x12E8, 0x48

glabel jtbl_80335DA0
	.incbin "bin/rodata.bin", 0x1330, 0x14

glabel D_80335DB4
	.incbin "bin/rodata.bin", 0x1344, 0x4

glabel D_80335DB8
	.incbin "bin/rodata.bin", 0x1348, 0x18

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
