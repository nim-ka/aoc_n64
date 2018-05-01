.include "macros.inc"
.include "globals.inc"

.section .data

#audio data (for all the audio files)
glabel D_80331D40
	.word 0

glabel D_80331D44
	.word 0

glabel D_80331D48
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F9C, 0xAC

glabel D_80331DF4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2048, 0x3C

glabel D_80331E30
	.word 0

glabel D_80331E34
	.word 0

glabel D_80331E38
	.incbin "bin/sm64.j.0EADAC.bin", 0x208C, 0xC

glabel D_80331E44
	.incbin "bin/sm64.j.0EADAC.bin", 0x2098, 0x18

glabel D_80331E5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x20B0, 0x1C

glabel D_80331E78
	.incbin "bin/sm64.j.0EADAC.bin", 0x20CC, 0x10

glabel D_80331E88
	.incbin "bin/sm64.j.0EADAC.bin", 0x20DC, 0x10

glabel D_80331E98
	.incbin "bin/sm64.j.0EADAC.bin", 0x20EC, 0x10

glabel D_80331EA8
	.word 0

glabel D_80331EAC
	.incbin "bin/sm64.j.0EADAC.bin", 0x2100, 0x4

glabel D_80331EB0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2104, 0x4

glabel D_80331EB4
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331E38
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331E88
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331E78
	.word D_80331E5C
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331E44
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331EA8
	.word D_80331E98

glabel D_80331F50
	.incbin "bin/sm64.j.0EADAC.bin", 0x21A4, 0x60

glabel D_80331FB0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2204, 0x78

glabel D_80332028
	.incbin "bin/sm64.j.0EADAC.bin", 0x227C, 0x50

glabel D_80332078
	.incbin "bin/sm64.j.0EADAC.bin", 0x22CC, 0x24

glabel D_8033209C
	.incbin "bin/sm64.j.0EADAC.bin", 0x22F0, 0x4

glabel D_803320A0
	.word 0

glabel D_803320A4
	.word 0
	.word 0
	.word 0

glabel D_803320B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2304, 0xC

glabel D_803320BC
	.word 0
	.word 0
	.word 0

glabel D_803320C8
	.incbin "bin/sm64.j.0EADAC.bin", 0x231C, 0xC

glabel D_803320D4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2328, 0xC

glabel D_803320E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2334, 0x18

glabel D_803320F8
	.word 0
	.word 0
	.word 0
	.word 0

glabel D_80332108
	.word 0

glabel D_8033210C
	.word 0

glabel D_80332110
	.word 0

glabel D_80332114
	.word 0

glabel D_80332118
	.word 0

glabel D_8033211C
	.word 0

glabel D_80332120
	.word 0

glabel D_80332124
	.word 0

glabel D_80332128
	.word 0

glabel D_8033212C
	.incbin "bin/sm64.j.0EADAC.bin", 0x2380, 0x40

glabel D_8033216C
	.incbin "bin/sm64.j.0EADAC.bin", 0x23C0, 0x10

glabel D_8033217C
	.incbin "bin/sm64.j.0EADAC.bin", 0x23D0, 0x14

glabel D_80332190
	.incbin "bin/sm64.j.0EADAC.bin", 0x23E4, 0x2F8

glabel D_80332488
	.incbin "bin/sm64.j.0EADAC.bin", 0x26DC, 0x1FC

glabel D_80332684
	.incbin "bin/sm64.j.0EADAC.bin", 0x28D8, 0x200

glabel D_80332884
	.incbin "bin/sm64.j.0EADAC.bin", 0x2AD8, 0x200

glabel D_80332A84
	.incbin "bin/sm64.j.0EADAC.bin", 0x2CD8, 0x10

glabel D_80332A94
	.incbin "bin/sm64.j.0EADAC.bin", 0x2CE8, 0x10

glabel D_80332AA4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2CF8, 0x10

glabel D_80332AB4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2D08, 0xC

glabel D_80332AC0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2D14, 0x80

glabel D_80332B40
	.incbin "bin/sm64.j.0EADAC.bin", 0x2D94, 0x80

glabel D_80332BC0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2E14, 0x80

glabel D_80332C40
	.incbin "bin/sm64.j.0EADAC.bin", 0x2E94, 0x80

glabel D_80332CC0
	.word D_80332C40
	.word D_80332BC0
	.word D_80332AC0
	.word D_80332B40

glabel D_80332CD0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2F24, 0x12

glabel D_80332CE2
	.incbin "bin/sm64.j.0EADAC.bin", 0x2F36, 0x2

glabel D_80332CE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2F38, 0x1FC

glabel D_80332EE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x3134, 0x4

glabel D_80332EE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3138, 0x78

glabel D_80332F5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x31B0, 0x184

glabel D_803330E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x3334, 0x4

glabel D_803330E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3338, 0x1FC

glabel D_803332E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x3534, 0x4

glabel D_803332E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3538, 0x200

glabel D_803334E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3738, 0x200

glabel D_803336E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3938, 0x200

glabel D_803338E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3B38, 0x200

glabel D_80333AE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3D38, 0x200

glabel D_80333CE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3F38, 0x200

glabel D_80333EE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4138, 0x4

glabel D_80333EE8
	.incbin "bin/sm64.j.0EADAC.bin", 0x413C, 0x4

glabel D_80333EEC
	.incbin "bin/sm64.j.0EADAC.bin", 0x4140, 0x4

glabel D_80333EF0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4144, 0x4

glabel D_80333EF4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4148, 0xC

glabel D_80333F00
	.incbin "bin/sm64.j.0EADAC.bin", 0x4154, 0x8C0
