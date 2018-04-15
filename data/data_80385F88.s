.include "macros.inc"
.include "globals.inc"

.section .text, "ax"

# 0x80385F90

	.incbin "bin/sm64.j.101998.bin", 0x0, 0x40

glabel D_80385FD0
	.incbin "bin/sm64.j.101998.bin", 0x40, 0xC

glabel D_80385FDC
	.incbin "bin/sm64.j.101998.bin", 0x4C, 0x8

glabel D_80385FE4
	.incbin "bin/sm64.j.101998.bin", 0x54, 0x1C

glabel D_80386000
	.incbin "bin/sm64.j.101998.bin", 0x70, 0x1000

glabel D_80387000
	.incbin "bin/sm64.j.101998.bin", 0x1070, 0x4000

glabel D_8038B000
	.incbin "bin/sm64.j.101998.bin", 0x5070, 0x810

# 0x8038B810

glabel GeoLayoutJumpTable
.word GeoLayout00
.word GeoLayout01
.word GeoLayout02
.word GeoLayout03
.word GeoLayout04
.word GeoLayout05
.word GeoLayout06
.word GeoLayout07
.word GeoLayout08
.word GeoLayout09
.word GeoLayout0A
.word GeoLayout0B
.word GeoLayout0C
.word GeoLayout0D
.word GeoLayout0E
.word GeoLayout0F
.word GeoLayout10
.word GeoLayout11
.word GeoLayout12
.word GeoLayout13
.word GeoLayout14
.word GeoLayout15
.word GeoLayout16
.word GeoLayout17
.word GeoLayout18
.word GeoLayout19
.word GeoLayout1A
.word GeoLayout1B
.word GeoLayout1C
.word GeoLayout1D
.word GeoLayout1E
.word GeoLayout1F
.word GeoLayout20

# Unknown region 1072A4-1072C8 [24]
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0x38, 0xBD, 0xA0
.byte 0x00, 0x00, 0x00, 0x00

glabel LevelScriptJumpTable
.word LevelScript00
.word LevelScript01
.word LevelScript02
.word LevelScript03
.word LevelScript04
.word LevelScript05
.word LevelScript06
.word LevelScript07
.word LevelScript08
.word LevelScript09
.word LevelScript0A
.word LevelScript0B
.word LevelScript0C
.word LevelScript0D
.word LevelScript0E
.word LevelScript0F
.word LevelScript10
.word LevelScript11
.word LevelScript12
.word LevelScript13
.word LevelScript14
.word LevelScript15
.word LevelScript16
.word LevelScript17
.word LevelScript18
.word LevelScript19
.word LevelScript1A
.word LevelScript1B
.word LevelScript1C
.word LevelScript1D
.word LevelScript1E
.word LevelScript1F
.word LevelScript20
.word LevelScript21
.word LevelScript22
.word LevelScript23
.word LevelScript24
.word LevelScript25
.word LevelScript26
.word LevelScript27
.word LevelScript28
.word LevelScript29
.word LevelScript2A
.word LevelScript2B
.word LevelScript2C
.word LevelScript2D
.word LevelScript2E
.word LevelScript2F
.word LevelScript30
.word LevelScript31
.word LevelScript32
.word LevelScript33
.word LevelScript34
.word LevelScript35
.word LevelScript36
.word LevelScript37
.word LevelScript38
.word LevelScript39
.word LevelScript3A
.word LevelScript3B
.word LevelScript3C

# Unknown region 1073BC-1073C0 [4]
.byte 0x00, 0x00, 0x00, 0x00

glabel BehaviorJumpTable
.word Behavior00
.word Behavior01
.word Behavior02
.word Behavior03
.word Behavior04
.word Behavior05
.word Behavior06
.word Behavior07
.word Behavior08
.word Behavior09
.word Behavior0A
.word Behavior0B
.word Behavior0C
.word Behavior0D
.word Behavior0E
.word Behavior0F
.word Behavior10
.word Behavior11
.word Behavior12
.word Behavior13
.word Behavior14
.word Behavior15
.word Behavior16
.word Behavior17
.word Behavior18
.word Behavior19
.word Behavior1A
.word Behavior1B
.word Behavior1C
.word Behavior1D
.word Behavior1E
.word Behavior1F
.word Behavior20
.word Behavior21
.word Behavior22
.word Behavior23
.word Behavior24
.word Behavior25
.word Behavior26
.word Behavior27
.word Behavior28
.word Behavior29
.word Behavior2A
.word Behavior2B
.word Behavior2C
.word Behavior2D
.word Behavior2E
.word Behavior2F
.word Behavior30
.word Behavior31
.word Behavior32
.word Behavior33
.word Behavior34
.word Behavior35
.word Behavior36
.word Behavior37

# 0x8038BA90

glabel D_8038BA90
	.incbin "bin/sm64.j.1074A0.bin", 0x0, 0x8

glabel jtbl_8038BA98
	.incbin "bin/sm64.j.1074A0.bin", 0x8, 0x58

glabel jtbl_8038BAF0
	.incbin "bin/sm64.j.1074A0.bin", 0x60, 0x20

glabel jtbl_8038BB10
	.incbin "bin/sm64.j.1074A0.bin", 0x80, 0x14

glabel jtbl_8038BB24
	.incbin "bin/sm64.j.1074A0.bin", 0x94, 0x1C

glabel D_8038BB40
	.incbin "bin/sm64.j.1074A0.bin", 0xB0, 0xC

glabel D_8038BB4C
	.incbin "bin/sm64.j.1074A0.bin", 0xBC, 0x8

glabel D_8038BB54
	.incbin "bin/sm64.j.1074A0.bin", 0xC4, 0x8

glabel D_8038BB5C
	.incbin "bin/sm64.j.1074A0.bin", 0xCC, 0x8

glabel D_8038BB64
	.incbin "bin/sm64.j.1074A0.bin", 0xD4, 0x4

glabel D_8038BB68
	.incbin "bin/sm64.j.1074A0.bin", 0xD8, 0x4

glabel D_8038BB6C
	.incbin "bin/sm64.j.1074A0.bin", 0xDC, 0x4

glabel D_8038BB70
	.incbin "bin/sm64.j.1074A0.bin", 0xE0, 0xC

glabel D_8038BB7C
	.incbin "bin/sm64.j.1074A0.bin", 0xEC, 0xC

glabel D_8038BB88
	.incbin "bin/sm64.j.1074A0.bin", 0xF8, 0x50

glabel jtbl_8038BBD8
	.incbin "bin/sm64.j.1074A0.bin", 0x148, 0xB8

# 0x8038BC90
