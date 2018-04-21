.include "macros.inc"
.include "globals.inc"

.section .data

#audio data (for all the audio files)
glabel D_80331D40
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F94, 0x4

glabel D_80331D44
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F98, 0x4

glabel D_80331D48
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F9C, 0xE8

glabel D_80331E30
	.incbin "bin/sm64.j.0EADAC.bin", 0x2084, 0x4

glabel D_80331E34
	.incbin "bin/sm64.j.0EADAC.bin", 0x2088, 0x78

glabel D_80331EAC
	.incbin "bin/sm64.j.0EADAC.bin", 0x2100, 0x4

glabel D_80331EB0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2104, 0x4

glabel D_80331EB4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2108, 0x9C

glabel D_80331F50
	.incbin "bin/sm64.j.0EADAC.bin", 0x21A4, 0x14C

glabel D_8033209C
	.incbin "bin/sm64.j.0EADAC.bin", 0x22F0, 0x4

glabel D_803320A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x22F4, 0x4

glabel D_803320A4
	.incbin "bin/sm64.j.0EADAC.bin", 0x22F8, 0xC

glabel D_803320B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2304, 0xC

glabel D_803320BC
	.incbin "bin/sm64.j.0EADAC.bin", 0x2310, 0xC

glabel D_803320C8
	.incbin "bin/sm64.j.0EADAC.bin", 0x231C, 0xC

glabel D_803320D4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2328, 0xC

glabel D_803320E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2334, 0x18

glabel D_803320F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x234C, 0x10

glabel D_80332108
	.incbin "bin/sm64.j.0EADAC.bin", 0x235C, 0x4

glabel D_8033210C
	.incbin "bin/sm64.j.0EADAC.bin", 0x2360, 0x4

glabel D_80332110
	.incbin "bin/sm64.j.0EADAC.bin", 0x2364, 0x4

glabel D_80332114
	.incbin "bin/sm64.j.0EADAC.bin", 0x2368, 0x4

glabel D_80332118
	.incbin "bin/sm64.j.0EADAC.bin", 0x236C, 0x4

glabel D_8033211C
	.incbin "bin/sm64.j.0EADAC.bin", 0x2370, 0x4

glabel D_80332120
	.incbin "bin/sm64.j.0EADAC.bin", 0x2374, 0x4

glabel D_80332124
	.incbin "bin/sm64.j.0EADAC.bin", 0x2378, 0x4

glabel D_80332128
	.incbin "bin/sm64.j.0EADAC.bin", 0x237C, 0x4

glabel D_8033212C
	.incbin "bin/sm64.j.0EADAC.bin", 0x2380, 0x40

glabel D_8033216C
	.incbin "bin/sm64.j.0EADAC.bin", 0x23C0, 0x10

glabel D_8033217C
	.incbin "bin/sm64.j.0EADAC.bin", 0x23D0, 0x14

glabel D_80332190
	.incbin "bin/sm64.j.0EADAC.bin", 0x23E4, 0x4F4

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
	.incbin "bin/sm64.j.0EADAC.bin", 0x2D08, 0x20C

glabel D_80332CC0
	.incbin "bin/sm64.j.0EADAC.bin", 0x2F14, 0x24

glabel D_80332CE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x2F38, 0x200

glabel D_80332EE4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3138, 0x78

glabel D_80332F5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x31B0, 0x184

glabel D_803330E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x3334, 0x4

glabel D_803330E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x3338, 0x200

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
