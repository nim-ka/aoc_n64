.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario actions cutscene
glabel D_80335530
	.incbin "bin/rodata.bin", 0xAC0, 0x1C

glabel jtbl_8033554C
	.incbin "bin/rodata.bin", 0xADC, 0x1C

glabel D_80335568
	.incbin "bin/rodata.bin", 0xAF8, 0x4

glabel D_8033556C
	.incbin "bin/rodata.bin", 0xAFC, 0x4

glabel D_80335570
	.incbin "bin/rodata.bin", 0xB00, 0x4

glabel D_80335574
	.incbin "bin/rodata.bin", 0xB04, 0x4

glabel D_80335578
	.incbin "bin/rodata.bin", 0xB08, 0x4

glabel D_8033557C
	.incbin "bin/rodata.bin", 0xB0C, 0x4

glabel jtbl_80335580
	.incbin "bin/rodata.bin", 0xB10, 0x34

glabel jtbl_803355B4
	.incbin "bin/rodata.bin", 0xB44, 0x1C

glabel jtbl_803355D0
	.incbin "bin/rodata.bin", 0xB60, 0x14

glabel jtbl_803355E4
	.incbin "bin/rodata.bin", 0xB74, 0xC4

glabel jtbl_803356A8
	.incbin "bin/rodata.bin", 0xC38, 0xF8
