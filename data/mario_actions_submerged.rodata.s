.include "macros.inc"
.include "globals.inc"

.section .rodata

#mario actions submerged
glabel D_80335C70
	.incbin "bin/rodata.bin", 0x1200, 0x4

glabel jtbl_80335C74
	.word L80272A78
	.word L80272A94
	.word L80272AB0
	.word L80272ACC
	.word L80272AE8
	.word L80272B00

glabel jtbl_80335C8C
	.word L80272B48
	.word L80272B5C
	.word L80272B70
	.word L80272B84
	.word L80272B98
	.word L80272BAC

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
	.word L8027474C
	.word L80274760
	.word L80274774
	.word L80274788
	.word L8027479C
	.word L802747B0
	.word L802747C4
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L802747D8
	.word L802747EC

glabel jtbl_80335D04
	.word L8027483C
	.word L802748B4
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274918
	.word L80274878
	.word L802748F0
	.word L8027488C
	.word L80274904

	.word 0
