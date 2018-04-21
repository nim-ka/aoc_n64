.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario
glabel D_80335280
	.incbin "bin/rodata.bin", 0x810, 0x8

glabel D_80335288
	.incbin "bin/rodata.bin", 0x818, 0x8

glabel D_80335290
	.incbin "bin/rodata.bin", 0x820, 0x8

glabel jtbl_80335298
	.incbin "bin/rodata.bin", 0x828, 0x20

glabel jtbl_803352B8
	.incbin "bin/rodata.bin", 0x848, 0x94

glabel jtbl_8033534C
	.incbin "bin/rodata.bin", 0x8DC, 0x20

glabel jtbl_8033536C
	.incbin "bin/rodata.bin", 0x8FC, 0x94

glabel D_80335400
	.incbin "bin/rodata.bin", 0x990, 0x4

glabel D_80335404
	.incbin "bin/rodata.bin", 0x994, 0x4

glabel D_80335408
	.incbin "bin/rodata.bin", 0x998, 0x8

glabel D_80335410
	.incbin "bin/rodata.bin", 0x9A0, 0x4

glabel D_80335414
	.incbin "bin/rodata.bin", 0x9A4, 0x4

glabel D_80335418
	.incbin "bin/rodata.bin", 0x9A8, 0x4

glabel D_8033541C
	.incbin "bin/rodata.bin", 0x9AC, 0x4

glabel D_80335420
	.incbin "bin/rodata.bin", 0x9B0, 0x4

glabel D_80335424
	.incbin "bin/rodata.bin", 0x9B4, 0x4

glabel D_80335428
	.incbin "bin/rodata.bin", 0x9B8, 0x4

glabel D_8033542C
	.incbin "bin/rodata.bin", 0x9BC, 0x4

glabel D_80335430
	.incbin "bin/rodata.bin", 0x9C0, 0x4

glabel jtbl_80335434
	.incbin "bin/rodata.bin", 0x9C4, 0x84

glabel D_803354B8
	.incbin "bin/rodata.bin", 0xA48, 0x4

glabel D_803354BC
	.incbin "bin/rodata.bin", 0xA4C, 0x4

glabel D_803354C0
	.incbin "bin/rodata.bin", 0xA50, 0x4

glabel D_803354C4
	.incbin "bin/rodata.bin", 0xA54, 0x4

glabel D_803354C8
	.incbin "bin/rodata.bin", 0xA58, 0x8
