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
	.word L8025160C
	.word L8025160C
	.word L8025160C
	.word L8025161C
	.word L8025161C
	.word L8025160C
	.word L802515FC
	.word L802515EC

glabel jtbl_803352B8
	.word L8025160C
	.word L802515FC
	.word L802515EC
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L802515FC
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025160C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L8025161C
	.word L802515FC
	.word L8025160C
	.word L802515EC

glabel jtbl_8033534C
	.word L802517A8
	.word L802517A8
	.word L802517A8
	.word L8025177C
	.word L8025177C
	.word L802517A8
	.word L80251798
	.word L80251788

glabel jtbl_8033536C
	.word L802517A8
	.word L80251798
	.word L80251788
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L802517B8
	.word L802517C8
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L802517A8
	.word L8025177C
	.word L80251788
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L8025177C
	.word L80251798
	.word L802517A8
	.word L80251788

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
	.word L802524F4
	.word L802523E0
	.word L80252778
	.word L80252778
	.word L80252778
	.word L802525B8
	.word L80252534
	.word L80252778
	.word L8025266C
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252534
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252478
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L80252778
	.word L802524F4

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

