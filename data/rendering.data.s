
.include "macros.inc"
.include "globals.inc"

.section .data

#rendering
glabel D_8032CE60
	.word D_8033A140

glabel gLoadedGeoLayouts
	.word D_8033A160

glabel D_8032CE68
	.word D_8033A560

glabel D_8032CE6C
	.word 0

glabel gCurrCreditsEntry
	.word 0

glabel D_8032CE74
	.word 0

glabel D_8032CE78
	.word 0

glabel D_8032CE7C
	.word 0

glabel D_8032CE80
	.word 0

glabel D_8032CE84
	.word 0

glabel D_8032CE88
	.word 0

glabel D_8032CE8C
	.word 0

glabel D_8032CE90
	.word 0

glabel gCurrSaveFileNum
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3AC, 0x4

glabel gCurrLevelNum
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3B0, 0x4

glabel D_8032CE9C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3B4, 0x50

glabel D_8032CEEC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x404, 0x14

glabel D_8032CF00
	.incbin "bin/sm64.j.0E7AE8.bin", 0x418, 0x10

glabel D_8032CF10
	.incbin "bin/sm64.j.0E7AE8.bin", 0x428, 0x40

glabel D_8032CF50
	.incbin "bin/sm64.j.0E7AE8.bin", 0x468, 0x40

glabel D_8032CF90
	.word 0

glabel D_8032CF94
	.word 0

glabel D_8032CF98
	.word 0

glabel D_8032CF9C
	.word 0

glabel D_8032CFA0
	.word 0

glabel D_8032CFA4
	.word 0

glabel D_8032CFA8
	.word 0
	.word 0
