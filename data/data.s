
.include "macros.inc"
.include "globals.inc"

.section .data

# Unknown region 0E63F0-0E6800 [410]
.incbin "bin/sm64.j.0E63F0.bin"

glabel D_8032B800
	.incbin "bin/sm64.j.0E6800.rsp.audio.bin"

# Unknown region 0E7000-0E79F0 [9F0]
	.incbin "bin/sm64.j.0E7000.bin", 0x0, 0x620

glabel D_8032C620
	.incbin "bin/sm64.j.0E7000.bin", 0x620, 0x4

glabel D_8032C624
	.incbin "bin/sm64.j.0E7000.bin", 0x624, 0x4

glabel D_8032C628
	.incbin "bin/sm64.j.0E7000.bin", 0x628, 0x4

glabel D_8032C62C
	.incbin "bin/sm64.j.0E7000.bin", 0x62C, 0x4

glabel D_8032C630
	.incbin "bin/sm64.j.0E7000.bin", 0x630, 0x4

glabel D_8032C634
	.incbin "bin/sm64.j.0E7000.bin", 0x634, 0x4

glabel D_8032C638
	.incbin "bin/sm64.j.0E7000.bin", 0x638, 0x4

glabel D_8032C63C
	.incbin "bin/sm64.j.0E7000.bin", 0x63C, 0x4

glabel D_8032C640
	.incbin "bin/sm64.j.0E7000.bin", 0x640, 0x4

glabel gResetTimer
	.incbin "bin/sm64.j.0E7000.bin", 0x644, 0x4

glabel D_8032C648
	.incbin "bin/sm64.j.0E7000.bin", 0x648, 0x4

glabel D_8032C64C
	.incbin "bin/sm64.j.0E7000.bin", 0x64C, 0x4

glabel D_8032C650
	.incbin "bin/sm64.j.0E7000.bin", 0x650, 0x4

glabel D_8032C654
	.incbin "bin/sm64.j.0E7000.bin", 0x654, 0x4

glabel gPrintDebugInfo
	.incbin "bin/sm64.j.0E7000.bin", 0x658, 0x4

glabel D_8032C65C
	.incbin "bin/sm64.j.0E7000.bin", 0x65C, 0x10

glabel D_8032C66C
	.incbin "bin/sm64.j.0E7000.bin", 0x66C, 0x10

glabel D_8032C67C
	.incbin "bin/sm64.j.0E7000.bin", 0x67C, 0x4

glabel D_8032C680
	.incbin "bin/sm64.j.0E7000.bin", 0x680, 0x14

glabel D_8032C694
	.incbin "bin/sm64.j.0E7000.bin", 0x694, 0x4

glabel D_8032C698
	.incbin "bin/sm64.j.0E7000.bin", 0x698, 0x4

glabel D_8032C69C
	.incbin "bin/sm64.j.0E7000.bin", 0x69C, 0x4

glabel D_8032C6A0
	.incbin "bin/sm64.j.0E7000.bin", 0x6A0, 0x4

glabel gPlayer1Controller
	.incbin "bin/sm64.j.0E7000.bin", 0x6A4, 0x4

glabel D_8032C6A8
	.incbin "bin/sm64.j.0E7000.bin", 0x6A8, 0x4

glabel gPlayer2Controller
	.incbin "bin/sm64.j.0E7000.bin", 0x6AC, 0x4

glabel gDemoInputs
	.incbin "bin/sm64.j.0E7000.bin", 0x6B0, 0x4

glabel gDemoInputListID
	.incbin "bin/sm64.j.0E7000.bin", 0x6B4, 0x4

glabel gRecordedDemoTimer
	.incbin "bin/sm64.j.0E7000.bin", 0x6B8, 0x1

glabel gRecordedDemoStickX
	.incbin "bin/sm64.j.0E7000.bin", 0x6B9, 0x1

glabel gRecordedDemoStickY
	.incbin "bin/sm64.j.0E7000.bin", 0x6BA, 0x1

glabel gRecordedDemoButton
	.incbin "bin/sm64.j.0E7000.bin", 0x6BB, 0x5

glabel D_8032C6C0
	.incbin "bin/sm64.j.0E7000.bin", 0x6C0, 0x4

glabel D_8032C6C4
	.incbin "bin/sm64.j.0E7000.bin", 0x6C4, 0x4

glabel D_8032C6C8
	.incbin "bin/sm64.j.0E7000.bin", 0x6C8, 0x4

glabel D_8032C6CC
	.incbin "bin/sm64.j.0E7000.bin", 0x6CC, 0x4

glabel D_8032C6D0
	.incbin "bin/sm64.j.0E7000.bin", 0x6D0, 0x4

glabel D_8032C6D4
	.incbin "bin/sm64.j.0E7000.bin", 0x6D4, 0x14

glabel D_8032C6E8
	.incbin "bin/sm64.j.0E7000.bin", 0x6E8, 0x8

glabel D_8032C6F0
	.incbin "bin/sm64.j.0E7000.bin", 0x6F0, 0x90

glabel D_8032C780
	.incbin "bin/sm64.j.0E7000.bin", 0x780, 0xE8

glabel D_8032C868
	.incbin "bin/sm64.j.0E7000.bin", 0x868, 0x170

glabel D_8032C9D8
	.incbin "bin/sm64.j.0E7000.bin", 0x9D8, 0x8

glabel D_8032C9E0
	.incbin "bin/sm64.j.0E7000.bin", 0x9E0, 0x10

glabel TableInteractions
.word 0x00000010, InteractionCoin
.word 0x00010000, InteractionHealth
.word 0x00001000, InteractionStar
.word 0x08000000, InteractionWarpShrink
.word 0x00002000, InteractionWarpHole
.word 0x00000800, InteractionWarpDoor
.word 0x00000004, InteractionDoor
.word 0x00004000, InteractionCannon
.word 0x40000000, InteractionNormal
.word 0x01000000, InteractionSpin
.word 0x02000000, InteractionFall
.word 0x00000400, InteractionBlowsAway
.word 0x00040000, InteractionFlame
.word 0x10000000, InteractionDamage10000000
.word 0x04000000, InteractionDamage04000000
.word 0x00020000, InteractionBully
.word 0x20000000, InteractionElectrocute
.word 0x00100000, InteractionDamage
.word 0x00200000, InteractionDamage00200000
.word 0x00400000, InteractionDamage00400000
.word 0x00008000, InteractionDamage
.word 0x00000008, InteractionDamageNormal
.word 0x00000040, InteractionPole
.word 0x00000001, InteractionCanHang
.word 0x00000200, InteractionCanBePunched
.word 0x00000080, InteractionDamage
.word 0x00080000, InteractionKoopaShell
.word 0x00000100, InteractionDamage00000100
.word 0x00000020, InteractionNothing
.word 0x00000002, InteractionCanBePickedUp
.word 0x00800000, InteractionMessage

# Unknown region 0E7AE8-0E8048 [560]
glabel D_8032CAE8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x0, 0x24

glabel D_8032CB0C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x24, 0x24

glabel D_8032CB30
	.incbin "bin/sm64.j.0E7AE8.bin", 0x48, 0x4

glabel D_8032CB34
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4C, 0x4

glabel D_8032CB38
	.incbin "bin/sm64.j.0E7AE8.bin", 0x50, 0x8

glabel D_8032CB40
	.incbin "bin/sm64.j.0E7AE8.bin", 0x58, 0x3B

glabel D_8032CB7B
	.incbin "bin/sm64.j.0E7AE8.bin", 0x93, 0x5

glabel D_8032CB80
	.incbin "bin/sm64.j.0E7AE8.bin", 0x98, 0x4

glabel D_8032CB84
	.incbin "bin/sm64.j.0E7AE8.bin", 0x9C, 0xC

glabel D_8032CB90
	.incbin "bin/sm64.j.0E7AE8.bin", 0xA8, 0x8

glabel D_8032CB98
	.incbin "bin/sm64.j.0E7AE8.bin", 0xB0, 0x38

glabel D_8032CBD0
	.incbin "bin/sm64.j.0E7AE8.bin", 0xE8, 0x10

glabel D_8032CBE0
	.incbin "bin/sm64.j.0E7AE8.bin", 0xF8, 0x4

glabel D_8032CBE4
	.incbin "bin/sm64.j.0E7AE8.bin", 0xFC, 0x4

glabel D_8032CBE8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x100, 0x4

glabel D_8032CBEC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x104, 0x8

glabel D_8032CBF4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x10C, 0x8

glabel D_8032CBFC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x114, 0x86

glabel D_8032CC82
	.incbin "bin/sm64.j.0E7AE8.bin", 0x19A, 0x52

glabel D_8032CCD4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1EC, 0x2

glabel D_8032CCD6
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1EE, 0x2

glabel D_8032CCD8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1F0, 0x2

glabel D_8032CCDA
	.incbin "bin/sm64.j.0E7AE8.bin", 0x1F2, 0x16

glabel D_8032CCF0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x208, 0x18

glabel D_8032CD08
	.incbin "bin/sm64.j.0E7AE8.bin", 0x220, 0x18

glabel D_8032CD20
	.incbin "bin/sm64.j.0E7AE8.bin", 0x238, 0x18

glabel D_8032CD38
	.incbin "bin/sm64.j.0E7AE8.bin", 0x250, 0x18

glabel D_8032CD50
	.incbin "bin/sm64.j.0E7AE8.bin", 0x268, 0x18

glabel D_8032CD68
	.incbin "bin/sm64.j.0E7AE8.bin", 0x280, 0x18

glabel D_8032CD80
	.incbin "bin/sm64.j.0E7AE8.bin", 0x298, 0x18

glabel D_8032CD98
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2B0, 0x18

glabel D_8032CDB0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2C8, 0x20

glabel D_8032CDD0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2E8, 0x4

glabel D_8032CDD4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2EC, 0x4

glabel D_8032CDD8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2F0, 0x8

glabel D_8032CDE0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2F8, 0x10

glabel D_8032CDF0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x308, 0x8

glabel D_8032CDF8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x310, 0x14

glabel D_8032CE0C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x324, 0x4

glabel D_8032CE10
	.incbin "bin/sm64.j.0E7AE8.bin", 0x328, 0x10

glabel D_8032CE20
	.incbin "bin/sm64.j.0E7AE8.bin", 0x338, 0x4

glabel D_8032CE24
	.incbin "bin/sm64.j.0E7AE8.bin", 0x33C, 0x4

glabel D_8032CE28
	.incbin "bin/sm64.j.0E7AE8.bin", 0x340, 0x4

glabel D_8032CE2C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x344, 0x4

glabel D_8032CE30
	.incbin "bin/sm64.j.0E7AE8.bin", 0x348, 0x4

glabel D_8032CE34
	.incbin "bin/sm64.j.0E7AE8.bin", 0x34C, 0x3

glabel D_8032CE37
	.incbin "bin/sm64.j.0E7AE8.bin", 0x34F, 0x29

glabel D_8032CE60
	.incbin "bin/sm64.j.0E7AE8.bin", 0x378, 0x4

glabel D_8032CE64
	.incbin "bin/sm64.j.0E7AE8.bin", 0x37C, 0x4

glabel D_8032CE68
	.incbin "bin/sm64.j.0E7AE8.bin", 0x380, 0x4

glabel D_8032CE6C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x384, 0x4

glabel D_8032CE70
	.incbin "bin/sm64.j.0E7AE8.bin", 0x388, 0x4

glabel D_8032CE74
	.incbin "bin/sm64.j.0E7AE8.bin", 0x38C, 0x4

glabel D_8032CE78
	.incbin "bin/sm64.j.0E7AE8.bin", 0x390, 0x4

glabel D_8032CE7C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x394, 0x4

glabel D_8032CE80
	.incbin "bin/sm64.j.0E7AE8.bin", 0x398, 0x4

glabel D_8032CE84
	.incbin "bin/sm64.j.0E7AE8.bin", 0x39C, 0x4

glabel D_8032CE88
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3A0, 0x4

glabel D_8032CE8C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3A4, 0x4

glabel D_8032CE90
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3A8, 0x4

glabel gCurrSaveFileNum
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3AC, 0x4

glabel gCurrLevelNum
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3B0, 0x4

glabel D_8032CE9C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x3B4, 0x64

glabel D_8032CF00
	.incbin "bin/sm64.j.0E7AE8.bin", 0x418, 0x10

glabel D_8032CF10
	.incbin "bin/sm64.j.0E7AE8.bin", 0x428, 0x40

glabel D_8032CF50
	.incbin "bin/sm64.j.0E7AE8.bin", 0x468, 0x40

glabel D_8032CF90
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4A8, 0x4

glabel D_8032CF94
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4AC, 0x4

glabel D_8032CF98
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4B0, 0x4

glabel D_8032CF9C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4B4, 0x4

glabel D_8032CFA0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4B8, 0x4

glabel D_8032CFA4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4BC, 0x4

glabel D_8032CFA8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4C0, 0x8

glabel D_8032CFB0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4C8, 0x4

glabel D_8032CFB4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4CC, 0x4

glabel D_8032CFB8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4D0, 0xC

glabel D_8032CFC4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4DC, 0x4

glabel D_8032CFC8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4E0, 0x4

glabel D_8032CFCC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4E4, 0x4

glabel D_8032CFD0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4E8, 0x4

glabel D_8032CFD4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4EC, 0x4

glabel D_8032CFD8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4F0, 0x4

glabel D_8032CFDC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4F4, 0x10

glabel D_8032CFEC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x504, 0x4

glabel D_8032CFF0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x508, 0x4

glabel D_8032CFF4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x50C, 0x4

glabel D_8032CFF8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x510, 0x4

glabel D_8032CFFC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x514, 0x4

# TODO: This is part of camera

glabel D_8032D000
	.incbin "bin/sm64.j.0E7AE8.bin", 0x518, 0x4

glabel D_8032D004
	.incbin "bin/sm64.j.0E7AE8.bin", 0x51C, 0x8

glabel D_8032D00C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x524, 0x3C

glabel TableCameraTransitions
.word NULL
.word CameraChange01
.word CameraChange02
.word CameraChange03
.word CameraChange040710
.word CameraChange05
.word CameraChange06
.word CameraChange040710
.word CameraChange08
.word CameraChange090F
.word CameraChange0A
.word CameraChange0B
.word CameraChange0C
.word CameraChange0D
.word CameraChange0E
.word CameraChange090F
.word CameraChange040710
.word CameraChange11
