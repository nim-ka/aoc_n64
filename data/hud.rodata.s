.include "macros.inc"
.include "globals.inc"

.section .rodata

#hud
glabel jtbl_80337130
	.word L802E1848
	.word L802E187C
	.word L802E18B0
	.word L802E18E4
	.word L802E1918
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E19B4
	.word L802E194C
	.word L802E1980

glabel jtbl_80337188
	.word L802E1B9C
	.word L802E1BC8
	.word L802E1C20
	.word L802E1CA0
	.word L802E1D4C

	# padding
	.word 0

glabel D_803371A0
	.incbin "bin/rodata.bin", 0x2730, 0x4

glabel D_803371A4
	.incbin "bin/rodata.bin", 0x2734, 0x4

glabel D_803371A8
	.incbin "bin/rodata.bin", 0x2738, 0x4

glabel D_803371AC
	.incbin "bin/rodata.bin", 0x273C, 0x4

glabel D_803371B0
	.incbin "bin/rodata.bin", 0x2740, 0x4

glabel D_803371B4
	.incbin "bin/rodata.bin", 0x2744, 0x4

glabel D_803371B8
	.incbin "bin/rodata.bin", 0x2748, 0x4

glabel D_803371BC
	.incbin "bin/rodata.bin", 0x274C, 0x4

glabel D_803371C0
	.incbin "bin/rodata.bin", 0x2750, 0x4

glabel D_803371C4
	.incbin "bin/rodata.bin", 0x2754, 0x4

glabel D_803371C8
	.incbin "bin/rodata.bin", 0x2758, 0x8

glabel D_803371D0
	.incbin "bin/rodata.bin", 0x2760, 0x4

glabel D_803371D4
	.incbin "bin/rodata.bin", 0x2764, 0x8

glabel D_803371DC
	.incbin "bin/rodata.bin", 0x276C, 0x4






