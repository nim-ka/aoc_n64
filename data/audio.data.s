.include "macros.inc"


.section .data

# interface_2 is the last source file in link order... but its data doesn't
# seem to be last. Maybe its data should be moved to some other file and
# this data into that file, or the remaining data moved into interface_2
# (but then D_80332190 would require large alignment).

# audio_interface_1?
glabel D_80332190
.ifdef VERSION_JP
	.incbin "bin/sm64.j.0EADAC.bin", 0x23E4, 0x2F8
.else
	.incbin "bin/sm64.u.0EE2A0.bin", 0x0, 0x2F8
.endif

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

# audio_something?
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
