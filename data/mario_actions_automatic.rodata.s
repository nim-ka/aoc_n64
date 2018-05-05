.include "macros.inc"


.section .rodata

#mario actions automatic
glabel D_803357A0
	.incbin "bin/rodata.bin", 0xD30, 0x4

glabel D_803357A4
	.incbin "bin/rodata.bin", 0xD34, 0x4
glabel D_803357A8
	.incbin "bin/rodata.bin", 0xD38, 0x4
glabel D_803357AC
	.incbin "bin/rodata.bin", 0xD3C, 0x4

glabel jtbl_803357B0
	.word L80260370
	.word L80260384
	.word L80260398
	.word L802603AC
	.word L802603C0

	.word 0, 0, 0

