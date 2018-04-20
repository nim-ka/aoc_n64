
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

# Unknown region 0E8090-0E8138 [A8]
glabel D_8032D090
	.incbin "bin/sm64.j.0E8090.bin", 0x0, 0xC

glabel D_8032D09C
	.incbin "bin/sm64.j.0E8090.bin", 0xC, 0x1C

glabel D_8032D0B8
	.incbin "bin/sm64.j.0E8090.bin", 0x28, 0x38

glabel D_8032D0F0
	.incbin "bin/sm64.j.0E8090.bin", 0x60, 0x48

glabel TableCameraSL
.word 0x01000000, CameraSL00, 0x045F0E00, 0x04650499, 0x01660166, 0xE2D90000
.word 0x01000000, CameraSL01, 0x045F0E00, 0x04651000, 0x10001000, 0xE2D90000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraTHI
.word 0x01000000, CameraTHI00, 0xEDFFF467, 0x19300064, 0x012C012C, 0x00000000
.word 0x01000000, CameraTHI01, 0xED37F467, 0x19300064, 0x012C012C, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraHMC
.word 0x01000000, CameraHMC00, 0x07CC0066, 0x000000CD, 0x006400CD, 0x00000000
.word 0x01000000, CameraHMC01, 0x0D16EDAF, 0x12C00258, 0x00320258, 0x00000000
.word 0x01000000, CameraHMC02, 0xF33204D4, 0x05630166, 0x00C80166, 0x00000000
.word 0x01000000, CameraHMC03, 0xF5000807, 0xF6000166, 0x00C80166, 0x00000000
.word 0x01000000, CameraHMC04, 0xF2340607, 0xE4800166, 0x00C80166, 0x00000000
.word 0x01000000, CameraHMC05, 0xFC340607, 0xE34D0166, 0x00C80166, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraSSL
.word 0x01000000, CameraSSL00, 0xF8000438, 0xFC000096, 0x00960096, 0x00000000
.word 0x02000000, CameraSSL0102, 0x0000FF98, 0xFF9804E0, 0x06000B86, 0x00000000
.word 0x02000000, CameraSSL0102, 0x000009C4, 0x01000203, 0x13880203, 0x00000000
.word 0x03000000, CameraSSL03, 0x0000FA02, 0xF80803E8, 0x032003E8, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraRR
.word 0x01000000, CameraRR00, 0xEF9B0EEB, 0xF3F106E9, 0x05D20156, 0x00000000
.word 0x01000000, CameraRR01, 0xEF9B0EEB, 0xF1450301, 0x01EA0156, 0x00000000
.word 0x01000000, CameraRR02, 0xEA1D12E2, 0xEBA7012C, 0x0258024F, 0x00000000
.word 0x01000000, CameraRR0305, 0xF5CF0E92, 0xEAA9012C, 0x028A0241, 0x00000000
.word 0x01000000, CameraRR04, 0xEF9C1CAF, 0xEBDD1194, 0x03E81194, 0x00000000
.word 0x01000000, CameraRR0305, 0xEF9C179B, 0xEBDD01F4, 0x012C01F4, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000
.word 0x01000000, CameraRR07, 0x09A40AA0, 0xEE000CBF, 0x06A00C00, 0x00000000
.word 0xFF000000, CameraRR08, 0x00000000, 0x00000000, 0x00000000, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraMetal
.word 0x01000000, CameraMetal00, 0x000005DC, 0x0DAC0226, 0x271005DC, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraCCM
.word 0x02000000, CameraCCM00, 0xED12080D, 0x001B04CD, 0x053E018C, 0x00000000
.word 0x02000000, CameraCCM01, 0xE6F4F0B3, 0xE79A0133, 0x00B90084, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraInside
.word 0x01000000, CameraInside00, 0xFBB40291, 0xFABE012C, 0x0096012C, 0x00000000
.word 0x01000000, CameraInside01, 0xFBB50291, 0xFCDD012C, 0x0096012C, 0x00000000
.word 0x01000000, CameraInside00, 0xF700FEF8, 0xF018008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0xF7000091, 0xFAC0008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside01, 0xF7000091, 0xFCDE008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0x0B0004B0, 0xFF000064, 0x00640064, 0x00000000
.word 0x01000000, CameraInside00, 0x0100FF5F, 0xEF7E008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0x01000091, 0xFAC0008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside01, 0x01000091, 0xFCDE008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0xFC01002C, 0xECFA008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0xFE350091, 0xFC04008C, 0x0096008C, 0x60000000
.word 0x01000000, CameraInside01, 0xFFAB0091, 0xFD8D008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0xF9CB0091, 0xFC04008C, 0x0096008C, 0xA0000000
.word 0x01000000, CameraInside01, 0xF8550091, 0xFD8D008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside0E, 0xF4EA0291, 0xF98500C8, 0x00960096, 0x20000000
.word 0x01000000, CameraInside0F, 0xF6F10200, 0xFB0E012C, 0x0096012C, 0x20000000
.word 0x01000000, CameraInside00, 0x034C02F7, 0xF9870028, 0x00960028, 0xE0000000
.word 0x01000000, CameraInside01, 0x01BA02F7, 0xFAF4008C, 0x0096008C, 0xE0000000
.word 0x02000000, CameraInside1213, 0xFC180291, 0x06CC00C8, 0x012C00C8, 0x00000000
.word 0x02000000, CameraInside1213, 0xFC1C0544, 0x071600C8, 0x012C00C8, 0x00000000
.word 0x02000000, CameraInside00, 0xFC4E0291, 0x0AA10032, 0x00960032, 0x00000000
.word 0x02000000, CameraInside00, 0xFC1C0544, 0x038B0032, 0x00960032, 0x00000000
.word 0x02000000, CameraInside00, 0xFC1B0544, 0x05AA008C, 0x0096008C, 0x00000000
.word 0x01000000, CameraInside00, 0xECB201C4, 0xFE33008C, 0x0096008C, 0x40000000
.word 0x01000000, CameraInside00, 0xF2BF015E, 0xFCE7008C, 0x0096008C, 0x40000000
.word 0x01000000, CameraInside01, 0xF4DD015E, 0xFCE8008C, 0x0096008C, 0x40000000
.word 0x01000000, CameraInside01, 0x0323015E, 0xFF1C008C, 0x0096008C, 0xC0000000
.word 0x01000000, CameraInside01, 0x0323015E, 0xFF1C008C, 0x0096008C, 0xC0000000
.word 0x01000000, CameraInside00, 0x0541015E, 0xFF1B008C, 0x0096008C, 0x40000000
.word 0x01000000, CameraInside00, 0xFC4EFC5F, 0x026E012C, 0x0096012C, 0x00000000
.word 0x02000000, CameraInside1E, 0xFF3305B0, 0x09CC00D2, 0x03A002CE, 0x00000000
.word 0x01000000, CameraInside1F, 0xFBFDFDB5, 0xFD32013E, 0x01E60241, 0x00000000
.word 0x01000000, CameraInside20, 0xFC010178, 0x0726012C, 0x0190012C, 0x00000000
.word 0x03000000, CameraHMC01, 0x09B5F967, 0xF59D0258, 0x00320258, 0x00000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableCameraBBH
.word 0x01000000, CameraBBH00, 0x02E60000, 0x094100C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH01, 0x02E50000, 0x072300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x00DE0000, 0x05B200C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x00DE0000, 0x027F00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x01B30000, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x064D0000, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x07230000, 0x05B300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0xFE110333, 0x057F00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0xFE110333, 0x028000FA, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x00B30333, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x064D0333, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x07230333, 0x01E600C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x07230333, 0x071A00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH0D_OF, 0x09410000, 0x05B300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH0D_OF, 0x0D1A0000, 0x054300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH0D_OF, 0x0B330202, 0x07330200, 0x00660199, 0x00000000
.word 0x01000000, CameraBBH10_11, 0x0D1A0000, 0x032400C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH10_11, 0x064D0000, 0xFEC000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH12, 0x01B30000, 0xFEC000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1314, 0xF81B0000, 0x032300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1314, 0xFEC00000, 0x028000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH15, 0xFA000166, 0xFF0202CC, 0x016B0066, 0x00000000
.word 0x01000000, CameraBBH16, 0xFA000166, 0xFE3502CC, 0x016B0066, 0x00000000
.word 0x01000000, CameraBBH17, 0xF9E80000, 0xFADE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH18, 0xFEC00000, 0x05B300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH18, 0xF81B0000, 0x054100C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1A1B, 0x09410333, 0x01E600C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1A1B, 0x094106CD, 0x01E600C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1C, 0x0B3304CC, 0x049602CC, 0x019E0066, 0x00000000
.word 0x01000000, CameraBBH1D, 0x0B3304CC, 0x056202CC, 0x019E0066, 0x00000000
.word 0x01000000, CameraBBH1E, 0x09410333, 0x071A00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1F20, 0x072506CD, 0x01E600C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1F20, 0x02E506CD, 0x063300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH21, 0x00660800, 0xFF410064, 0x01360133, 0x00000000
.word 0x01000000, CameraBBH22, 0x01990800, 0xFF410064, 0x01360133, 0x00000000
.word 0x01000000, CameraBBH23, 0x02E60782, 0x087400C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH24, 0x024B052A, 0x0A7503E8, 0x01900258, 0x00000000
.word 0x01000000, CameraBBH18, 0xFBF30333, 0x058000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH18, 0xF84E0400, 0x054100C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH12, 0x00B30333, 0xFEC000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH28, 0x064D0333, 0xFEC000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH29, 0x083304CC, 0xFCCD0066, 0x019E02CC, 0x00000000
.word 0x01000000, CameraBBH2A, 0x090004CC, 0xFCCD0066, 0x019E02CC, 0x00000000
.word 0x01000000, CameraBBH2B2C, 0xFBF30333, 0x028000C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH2B2C, 0xF84E0400, 0x032300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH02_0C, 0x07230333, 0x071A00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH2E2F, 0x0933FBA8, 0xFF3F04CC, 0x01F4053F, 0x00000000
.word 0x01000000, CameraBBH2E2F, 0x0933F941, 0x058204CC, 0x01F402C1, 0x00000000
.word 0x01000000, CameraBBH30_33, 0x0000F667, 0x072300FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH30_33, 0x0000F667, 0x094100FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH30_33, 0x0000F667, 0x134100FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH30_33, 0x0000F667, 0x112300FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH34, 0x075FF667, 0x00CC00FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH3536, 0x04F8F667, 0x00CC00FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH3536, 0xF96FF667, 0x00CC00FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH34, 0xF708F667, 0x00CC00FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH38, 0xF485FDA3, 0x14F70320, 0x00640320, 0x00000000
.word 0x01000000, CameraBBH393A, 0xF485FF33, 0x14F7012C, 0x0064012C, 0x00000000
.word 0x01000000, CameraBBH393A, 0xF6E4FF34, 0x126A00FA, 0x00C800FA, 0x60000000
.word 0x01000000, CameraBBH34, 0xF86DFF34, 0x10F400FA, 0x00C800FA, 0x60000000
.word 0x00000000, NULL, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel TableLevelCinematicCamera
.word NULL
.word NULL
.word NULL
.word NULL
.word TableCameraBBH
.word TableCameraCCM
.word TableCameraInside
.word TableCameraHMC
.word TableCameraSSL
.word NULL
.word TableCameraSL
.word NULL
.word NULL
.word TableCameraTHI
.word NULL
.word TableCameraRR
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word TableCameraMetal
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL
.word NULL

# Unknown region 0E8DF0-0E9574 [784]
glabel D_8032DDF0
	.incbin "bin/sm64.j.0E8DF0.bin", 0x0, 0xB8

glabel D_8032DEA8
	.incbin "bin/sm64.j.0E8DF0.bin", 0xB8, 0xB8

glabel D_8032DF60
	.incbin "bin/sm64.j.0E8DF0.bin", 0x170, 0x70

glabel D_8032DFD0
	.incbin "bin/sm64.j.0E8DF0.bin", 0x1E0, 0x70

glabel D_8032E040
	.incbin "bin/sm64.j.0E8DF0.bin", 0x250, 0x50

glabel D_8032E090
	.incbin "bin/sm64.j.0E8DF0.bin", 0x2A0, 0x58

glabel D_8032E0E8
	.incbin "bin/sm64.j.0E8DF0.bin", 0x2F8, 0xA0

glabel D_8032E188
	.incbin "bin/sm64.j.0E8DF0.bin", 0x398, 0x48

glabel D_8032E1D0
	.incbin "bin/sm64.j.0E8DF0.bin", 0x3E0, 0x48

glabel D_8032E218
	.incbin "bin/sm64.j.0E8DF0.bin", 0x428, 0x40

glabel D_8032E258
	.incbin "bin/sm64.j.0E8DF0.bin", 0x468, 0x38

glabel D_8032E290
	.incbin "bin/sm64.j.0E8DF0.bin", 0x4A0, 0xC

glabel D_8032E29C
	.incbin "bin/sm64.j.0E8DF0.bin", 0x4AC, 0xC

glabel D_8032E2A8
	.incbin "bin/sm64.j.0E8DF0.bin", 0x4B8, 0xC

glabel D_8032E2B4
	.incbin "bin/sm64.j.0E8DF0.bin", 0x4C4, 0x118

glabel D_8032E3CC
	.incbin "bin/sm64.j.0E8DF0.bin", 0x5DC, 0x118

glabel D_8032E4E4
	.incbin "bin/sm64.j.0E8DF0.bin", 0x6F4, 0x48

glabel D_8032E52C
	.incbin "bin/sm64.j.0E8DF0.bin", 0x73C, 0x48

glabel TableCutScenePeachEnd
.word CutScenePeachEnd0, 0x00AA0000
.word CutScenePeachEnd1, 0x00460000
.word CutScenePeachEnd2, 0x004B0000
.word CutScenePeachEnd3, 0x01820000
.word CutScenePeachEnd4, 0x008B0000
.word CutScenePeachEnd5, 0x024E0000
.word CutScenePeachEnd6, 0x005F0000
.word CutScenePeachEnd7, 0x01A90000
.word CutScenePeachEnd8, 0x00EC0000
.word CutScenePeachEnd9, 0x00F50000
.word CutScenePeachEndA, 0x7FFF0000
.word CutScenePeachEndB, 0x00000000

glabel TableCutSceneGrandStar
.word CutSceneGrandStar0, 0x01680000
.word CutSceneGrandStar1, 0x7FFF0000

glabel TableCutScene0FTodo
.word CutScene0FTodo_0, 0x00010000
.word CutScene0FTodo_1, 0x7FFF0000

glabel TableCutSceneDoorWarp
.word CutSceneDoor0, 0x00010000
.word CutSceneDoorWarp1, 0x7FFF0000

glabel TableCutSceneEndWaving
.word CutSceneEndWaving, 0x7FFF0000

glabel TableCutSceneEndCredits
.word CutSceneCredits, 0x7FFF0000

glabel TableCutSceneDoor00
.word CutSceneDoor0, 0x00010000
.word CutSceneDoor1, 0x001E0000
.word CutSceneDoor2, 0x00010000
.word CutSceneDoor3, 0x00320000
.word CutSceneDoor4, 0x00000000

glabel TableCutSceneDoor01
.word CutSceneDoor0, 0x00010000
.word CutSceneDoor1, 0x00140000
.word CutSceneDoor2, 0x00010000
.word CutSceneDoor3, 0x00320000
.word CutSceneDoor4, 0x00000000

glabel TableCutSceneDoor0A
.word CutSceneDoor0, 0x00010000
.word CutSceneDoor1, 0x001E0000
.word CutSceneDoorAB_2, 0x7FFF0000

glabel TableCutSceneDoor0B
.word CutSceneDoor0, 0x00010000
.word CutSceneDoor1, 0x00140000
.word CutSceneDoorAB_2, 0x7FFF0000

glabel TableCutSceneEnterCannon
.word CutSceneEnterCannon0, 0x00010000
.word CutSceneEnterCannon1, 0x00790000
.word CutSceneEnterCannon2, 0x00000000

glabel TableCutSceneStarSpawn
.word CutSceneStarSpawn0, 0x7FFF0000
.word CutSceneStarSpawn1, 0x000F0000
.word CutSceneStarSpawn2, 0x00000000

glabel TableCutSceneSpecialStarSpawn
.word CutSceneSpecialStarSpawn0, 0x7FFF0000
.word CutSceneSpecialStarSpawn1, 0x00000000

glabel TableCutSceneEnterPainting
.word CutSceneEnterPainting, 0x7FFF0000

glabel TableCutSceneExitPaintingDeath
.word CutSceneExitPainting0, 0x00760000
.word CutSceneExitPainting1, 0x00000000

glabel TableCutSceneExitPaintingSuccess
.word CutSceneExitPainting0, 0x00B40000
.word CutSceneExitPainting1, 0x00000000

glabel TableCutScene11Todo
.word CutScene11Todo_0, 0x00010000
.word CutScene11Todo_1, 0x003C0000
.word CutSceneExitPainting1, 0x00000000

glabel TableCutSceneIntroPeach
.word CutSceneIntroPeach0, 0x7FFF0000
.word CutSceneIntroPeach1, 0x00230000
.word CutSceneIntroPeach2, 0x03340000
.word CutSceneIntroPeach3, 0x010E0000
.word CutSceneIntroPeach4, 0x7FFF0000

glabel TableCutScenePrepareCannon
.word CutScenePrepareCannon0, 0x00AA0000
.word CutScenePrepareCannon1, 0x00000000

glabel TableCutSceneExitWaterfall
.word CutSceneExitWaterfall0, 0x00340000
.word CutSceneFallCommon, 0x00000000

glabel TableCutSceneFallToCastleGrounds
.word CutSceneFallToCastleGrounds0, 0x00490000
.word CutSceneFallCommon, 0x00000000

glabel TableCutSceneEnterPyramidTop
.word CutSceneEnterPyramidTop0, 0x005A0000
.word CutSceneFallCommon, 0x00000000

glabel TableCutScene26Todo
.word CutScene26Todo_0, 0x7FFF0000
.word CutScene26Todo_1, 0x00960000
.word CutScene26Todo_2, 0x00000000

glabel TableCutSceneDeath1
.word CutSceneDeath1, 0x7FFF0000

glabel TableCutSceneEnterPool
.word CutSceneEnterPool0, 0x00640000
.word CutSceneFallCommon, 0x00000000

glabel TableCutSceneDeath2
.word CutSceneDeath2, 0x7FFF0000

glabel TableCutSceneBBHDeath
.word CutSceneBBHDeath, 0x7FFF0000

glabel TableCutSceneQuicksandDeath
.word CutSceneQuicksandDeath0, 0x7FFF0000
.word CutSceneQuicksandDeath0, 0x7FFF0000

glabel TableCutScene1ATodo
.word CutScene1ATodo, 0x7FFF0000

glabel TableCutSceneEnterBowserPlatform
.word CutSceneEnterBowserPlatform0, 0x00B40000
.word CutSceneEnterBowserPlatform1, 0x7FFF0000
.word CutSceneEnterBowserPlatform2, 0x00000000

glabel TableCutSceneStarDance1
.word CutSceneStarDance1, 0x7FFF0000

glabel TableCutSceneStarDance2
.word CutSceneStarDance2, 0x7FFF0000

glabel TableCutSceneStarDance3
.word CutSceneStarDance3, 0x7FFF0000

glabel TableCutSceneKeyDance
.word CutSceneKeyDance, 0x7FFF0000

glabel TableCutSceneCapSwitchPress
.word CutSceneCapSwitchPress, 0x7FFF0000

glabel TableCutSceneSlidingDoorOpen
.word CutSceneSlidingDoorsOpen0, 0x00320000
.word CutSceneSlidingDoubleDoorsOpen1, 0x00000000

glabel TableCutSceneUnlockKeyDoor
.word CutSceneUnlockKeyDoor0, 0x00C80000
.word CutSceneSlidingDoubleDoorsOpen1, 0x00000000

glabel TableCutSceneExitBowserSuccess
.word CutSceneExitBowserSuccess0, 0x00BE0000
.word CutSceneExitNonPainting1, 0x00000000

glabel TableCutScene1CTodo
.word CutScene1CTodo_0, 0x00780000
.word CutSceneExitNonPainting1, 0x00000000

glabel TableCutSceneBBHExitSuccess
.word CutSceneBBHExitSuccess0, 0x00A30000
.word CutSceneExitNonPainting1, 0x00000000

glabel TableCutSceneNonPaintingDeath
.word CutSceneNonPaintingDeath0, 0x00780000
.word CutSceneExitNonPainting1, 0x00000000

glabel TableCutSceneDialog
.word CutSceneDialog0, 0x7FFF0000
.word CutSceneDialog1, 0x000C0000
.word CutSceneDialog2, 0x00000000

glabel TableCutSceneReadMessage
.word CutSceneReadMessage0, 0x7FFF0000
.word CutSceneReadMessage1, 0x000F0000
.word CutSceneReadMessage2, 0x00000000

# Unknown region 0E98A4-0EA10C [868]
glabel D_8032E8A4
	.incbin "bin/sm64.j.0E98A4.bin", 0x0, 0x6C

glabel D_8032E910
	.incbin "bin/sm64.j.0E98A4.bin", 0x6C, 0x14

glabel D_8032E924
	.incbin "bin/sm64.j.0E98A4.bin", 0x80, 0x28

glabel D_8032E94C
	.incbin "bin/sm64.j.0E98A4.bin", 0xA8, 0x28

glabel D_8032E974
	.incbin "bin/sm64.j.0E98A4.bin", 0xD0, 0x28

glabel D_8032E99C
	.incbin "bin/sm64.j.0E98A4.bin", 0xF8, 0x28

glabel D_8032E9C4
	.incbin "bin/sm64.j.0E98A4.bin", 0x120, 0x28

glabel D_8032E9EC
	.incbin "bin/sm64.j.0E98A4.bin", 0x148, 0x28

glabel D_8032EA14
	.incbin "bin/sm64.j.0E98A4.bin", 0x170, 0x28

glabel D_8032EA3C
	.incbin "bin/sm64.j.0E98A4.bin", 0x198, 0x28

glabel D_8032EA64
	.incbin "bin/sm64.j.0E98A4.bin", 0x1C0, 0x20

glabel D_8032EA84
	.incbin "bin/sm64.j.0E98A4.bin", 0x1E0, 0x20

glabel D_8032EAA4
	.incbin "bin/sm64.j.0E98A4.bin", 0x200, 0x28

glabel D_8032EACC
	.incbin "bin/sm64.j.0E98A4.bin", 0x228, 0x28

glabel D_8032EAF4
	.incbin "bin/sm64.j.0E98A4.bin", 0x250, 0x18

glabel D_8032EB0C
	.incbin "bin/sm64.j.0E98A4.bin", 0x268, 0x18

glabel D_8032EB24
	.incbin "bin/sm64.j.0E98A4.bin", 0x280, 0x30

glabel D_8032EB54
	.incbin "bin/sm64.j.0E98A4.bin", 0x2B0, 0x30

glabel D_8032EB84
	.incbin "bin/sm64.j.0E98A4.bin", 0x2E0, 0x30

glabel D_8032EBB4
	.incbin "bin/sm64.j.0E98A4.bin", 0x310, 0x30

glabel D_8032EBE4
	.incbin "bin/sm64.j.0E98A4.bin", 0x340, 0x38

glabel D_8032EC1C
	.incbin "bin/sm64.j.0E98A4.bin", 0x378, 0x38

glabel D_8032EC54
	.incbin "bin/sm64.j.0E98A4.bin", 0x3B0, 0x20

glabel D_8032EC74
	.incbin "bin/sm64.j.0E98A4.bin", 0x3D0, 0x20

glabel D_8032EC94
	.incbin "bin/sm64.j.0E98A4.bin", 0x3F0, 0x20

glabel D_8032ECB4
	.incbin "bin/sm64.j.0E98A4.bin", 0x410, 0x20

glabel D_8032ECD4
	.incbin "bin/sm64.j.0E98A4.bin", 0x430, 0x30

glabel D_8032ED04
	.incbin "bin/sm64.j.0E98A4.bin", 0x460, 0x30

glabel D_8032ED34
	.incbin "bin/sm64.j.0E98A4.bin", 0x490, 0x38

glabel D_8032ED6C
	.incbin "bin/sm64.j.0E98A4.bin", 0x4C8, 0x38

glabel D_8032EDA4
	.incbin "bin/sm64.j.0E98A4.bin", 0x500, 0x20

glabel D_8032EDC4
	.incbin "bin/sm64.j.0E98A4.bin", 0x520, 0x20

glabel D_8032EDE4
	.incbin "bin/sm64.j.0E98A4.bin", 0x540, 0x20

glabel D_8032EE04
	.incbin "bin/sm64.j.0E98A4.bin", 0x560, 0x20

glabel D_8032EE24
	.incbin "bin/sm64.j.0E98A4.bin", 0x580, 0x28

glabel D_8032EE4C
	.incbin "bin/sm64.j.0E98A4.bin", 0x5A8, 0x28

glabel D_8032EE74
	.incbin "bin/sm64.j.0E98A4.bin", 0x5D0, 0x28

glabel D_8032EE9C
	.incbin "bin/sm64.j.0E98A4.bin", 0x5F8, 0x28

glabel D_8032EEC4
	.incbin "bin/sm64.j.0E98A4.bin", 0x620, 0x28

glabel D_8032EEEC
	.incbin "bin/sm64.j.0E98A4.bin", 0x648, 0x28

glabel D_8032EF14
	.incbin "bin/sm64.j.0E98A4.bin", 0x670, 0x20

glabel D_8032EF34
	.incbin "bin/sm64.j.0E98A4.bin", 0x690, 0x2C

glabel D_8032EF60
	.incbin "bin/sm64.j.0E98A4.bin", 0x6BC, 0xC

glabel D_8032EF6C
	.incbin "bin/sm64.j.0E98A4.bin", 0x6C8, 0x148

glabel D_8032F0B4
	.incbin "bin/sm64.j.0E98A4.bin", 0x810, 0x58

glabel TableMrIParticleActions
.word ActionMrIParticle0
.word ActionMrIParticle1

glabel TableMrIActions
.word ActionMrI0
.word ActionMrI1
.word ActionMrI2
.word ActionMrI3

glabel D_8032F124
# Unknown region 0EA124-0EA14C [28]
.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x02, 0x05, 0x00, 0x50, 0x00, 0x96, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x1E, 0xA4, 0x00, 0x28, 0x00, 0x14, 0x28, 0xFC, 0x1E, 0x00, 0x00, 0x41, 0xA0, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0B, 0x0C, 0x00

glabel TableCapSwitchActions
.word ActionActivateCapSwitch0
.word ActionActivateCapSwitch1
.word ActionActivateCapSwitch2
.word ActionActivateCapSwitch3

glabel TableKingBobombActions
.word ActionKingBobomb0
.word ActionKingBobomb1
.word ActionKingBobomb2
.word ActionKingBobomb3
.word ActionKingBobomb4
.word ActionKingBobomb5
.word ActionKingBobomb6
.word ActionKingBobomb7
.word ActionKingBobomb8

glabel D_8032F180
# Unknown region 0EA180-0EA1E0 [60]
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x14, 0x50, 0x15, 0x80, 0x81
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x01, 0x0F, 0xFF, 0x50, 0x15, 0x80, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x21, 0xFF, 0x50, 0x15, 0x80, 0x81
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0F, 0x50, 0x15, 0x80, 0x81

glabel TableOpenedCannonActions
.word ActionOpenedCannon0
.word ActionOpenedCannon1
.word ActionOpenedCannon2
.word ActionOpenedCannon3
.word ActionOpenedCannon4
.word ActionOpenedCannon5
.word ActionOpenedCannon6

# Unknown region 0EA1FC-0EA238 [3C]
.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x41, 0x20, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x41, 0xA0, 0x00, 0x00
.byte 0x3F, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x41, 0xA0, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00
.byte 0x08, 0x00, 0x00, 0x00, 0x41, 0x20, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00

glabel TableChuckyaActions
.word ActionChuckya0
.word ActionChuckya1
.word ActionChuckya2
.word ActionChuckya3

# Unknown region 0EA248-0EA2C4 [7C]
.byte 0x00, 0x00, 0x00, 0x64, 0x07, 0x00, 0xFD, 0x30, 0x07, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96
.byte 0x07, 0x01, 0x86, 0xB4, 0x03, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00
.byte 0x00, 0x50, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x02, 0x14, 0x8E, 0x00, 0x28, 0x05, 0x1E, 0x14
.byte 0xFC, 0x1E, 0x00, 0x00, 0x43, 0xA5, 0x00, 0x00, 0x41, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10
.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x6A
.byte 0x00, 0x00, 0xFF, 0xCE, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x96, 0xFF, 0xCE, 0x00, 0x64
.byte 0xFF, 0x9C, 0x00, 0x32, 0x00, 0x32, 0x00, 0x64, 0x00, 0x64, 0x00, 0x32

glabel TableCoinInsideBooActions
.word ActionCoinInsideBoo0
.word ActionCoinInsideBoo1

# Unknown region 0EA2CC-0EA338 [6C]
.byte 0xD0, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xDE, 0x67, 0x21, 0x99, 0x21, 0x99, 0x21, 0x99
.byte 0xDE, 0x67, 0xDE, 0x67, 0x21, 0x99, 0xDE, 0x67, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x20, 0x00, 0x00, 0x00, 0xE9, 0x9A, 0x16, 0x66, 0x16, 0x66, 0x16, 0x66, 0xE9, 0x9A, 0xE9, 0x9A
.byte 0x16, 0x66, 0xE9, 0x9A, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x08, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x30, 0x04, 0xC0, 0x81
.byte 0x30, 0x06, 0xC0, 0x81, 0x30, 0x05, 0xC0, 0x81, 0x30, 0x07, 0xC0, 0x81

glabel TableGrindelThwompActions
.word ActionGrindelThwomp0
.word ActionGrindelThwomp1
.word ActionGrindelThwomp2
.word ActionGrindelThwomp3
.word ActionGrindelThwomp4

glabel D_8032F34C
# Unknown region 0EA34C-0EA37C [30]
.byte 0x00, 0x09, 0xFE, 0x00, 0x00, 0x80, 0x00, 0xB0, 0x07, 0x00, 0xFA, 0xEC, 0x00, 0x09, 0xFE, 0x64
.byte 0x00, 0x67, 0x00, 0x38, 0x07, 0x02, 0x6B, 0x1C, 0x00, 0x09, 0xFE, 0x00, 0x00, 0x80, 0x00, 0x3C
.byte 0x07, 0x01, 0xD2, 0x1C, 0x00, 0x09, 0xFE, 0x00, 0x00, 0x80, 0x00, 0x40, 0x07, 0x01, 0x52, 0x88

glabel TableTumblingBridgeActions
.word ActionTumblingBridge0
.word ActionTumblingBridge1
.word ActionTumblingBridge2
.word ActionTumblingBridge3

# Unknown region 0EA38C-0EA3B8 [2C]
.byte 0xFF, 0xCD, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x33, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0xF5, 0xCD, 0x00, 0x00, 0x00, 0x00, 0xF6, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD6
.byte 0x00, 0x00, 0x00, 0x00, 0xFF, 0xCE, 0x07, 0x99, 0x00, 0x01, 0x00, 0x00

glabel TableElevatorActions
.word ActionElevator0
.word ActionElevator1
.word ActionElevator2
.word ActionElevator3
.word ActionElevator4

glabel D_8032F3CC
# Unknown region 0EA3CC-0EA410 [44]
.byte 0x03, 0x14, 0x8E, 0x14, 0x0A, 0x05, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00
.byte 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x05, 0x9F, 0x00, 0x00, 0x14, 0x14, 0x00, 0xFC, 0x1E, 0x00, 0x00
.byte 0x40, 0xA0, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFF, 0xF8, 0x00, 0x01, 0x00, 0x04
.byte 0x00, 0x05, 0x9E, 0x00, 0x00, 0x14, 0x14, 0x00, 0xFC, 0x1E, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
.byte 0x40, 0x00, 0x00, 0x00

glabel TableLittleCageActions
.word ActionLittleCage0
.word ActionLittleCage1
.word ActionLittleCage2
.word ActionLittleCage3

glabel D_8032F420
# Unknown region 0EA420-0EA488 [68]
.byte 0x3F, 0xF3, 0x33, 0x33, 0x40, 0x19, 0x99, 0x9A, 0x40, 0x80, 0x00, 0x00, 0x40, 0x99, 0x99, 0x9A
.byte 0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x01, 0x03, 0x00, 0x5A, 0x00, 0x50, 0x00, 0x50, 0x00, 0x46
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xDC, 0x01, 0x2C, 0x00, 0xDC, 0x01, 0x2C
.byte 0x00, 0x00, 0x02, 0x00, 0x14, 0x00, 0x01, 0x00, 0x00, 0x96, 0x00, 0xC8, 0x00, 0x96, 0x00, 0xC8
.byte 0x00, 0x1E, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x01, 0x00, 0x34, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01
.byte 0x00, 0x4A, 0x00, 0x00, 0x00, 0x56, 0x00, 0x01, 0x00, 0x60, 0x00, 0x00, 0x00, 0x6C, 0x00, 0x01
.byte 0x00, 0x76, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00

glabel TableHeaveHoActions
.word ActionHeaveHo0
.word ActionHeaveHo1
.word ActionHeaveHo2
.word ActionHeaveHo3

glabel D_8032F498
# Unknown region 0EA498-0EA4A8 [10]
.byte 0x00, 0x00, 0x00, 0x02, 0x14, 0x00, 0x01, 0x05, 0x00, 0x96, 0x00, 0xFA, 0x00, 0x96, 0x00, 0xFA

glabel TableJumpingBoxActions
.word ActionJumpingBox0
.word ActionJumpingBox1

glabel D_8032F4B0
# Unknown region 0EA4B0-0EA4C0 [10]
.byte 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x01, 0x2C, 0x00, 0x00, 0x00, 0x00

glabel TableBetaBooKeyInsideActions
.word ActionBetaBooKeyInside0
.word ActionBetaBooKeyInside1
.word ActionBetaBooKeyInside2

glabel D_8032F4CC
# Unknown region 0EA4CC-0EA4DC [10]
.byte 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x64, 0x00, 0xA0, 0x00, 0x64

glabel TableBulletBillActions
.word ActionBulletBill0
.word ActionBulletBill1
.word ActionBulletBill2
.word ActionBulletBill3
.word ActionBulletBill4

glabel TableBowserTailAnchorActions
.word ActionBowserTailAnchor0
.word ActionBowserTailAnchor1
.word ActionBowserTailAnchor2

# Unknown region 0EA4FC-0EA568 [6C]
.byte 0x07, 0x08, 0x09, 0x0C, 0x0D, 0x0E, 0x0F, 0x04, 0x03, 0x10, 0x11, 0x13, 0x03, 0x03, 0x03, 0x03
.byte 0x00, 0x3C, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x18, 0x2A, 0x3C, 0xFF, 0x00, 0x77, 0x00, 0x78
.byte 0x00, 0x79, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0A, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A
.byte 0xFF, 0xFF, 0xFF, 0xF6, 0x00, 0x72, 0x00, 0x01, 0xFF, 0xEC, 0x00, 0x86, 0xFF, 0xFF, 0x00, 0x14
.byte 0x00, 0x9A, 0x00, 0x01, 0x00, 0x28, 0x00, 0xA4, 0xFF, 0xFF, 0xFF, 0xD8, 0x00, 0xAE, 0x00, 0x01
.byte 0xFF, 0xB0, 0x00, 0xB3, 0xFF, 0xFF, 0x00, 0x50, 0x00, 0xB8, 0x00, 0x01, 0x00, 0xA0, 0x00, 0xBA
.byte 0xFF, 0xFF, 0xFF, 0x60, 0x00, 0xBA, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00

glabel TableBowserActions
.word ActionBowser0
.word ActionBowser1
.word ActionBowser2
.word ActionBowser3
.word ActionBowser4
.word ActionBowser5
.word ActionBowser6
.word ActionBowser7
.word ActionBowser8
.word ActionBowser9
.word ActionBowser10
.word ActionBowser11
.word ActionBowser12
.word ActionBowser13
.word ActionBowser14
.word ActionBowser15
.word ActionBowser16
.word ActionBowser17
.word ActionBowser18
.word ActionBowser19

# Unknown region 0EA5B8-0EA71C [164]
glabel D_8032F5B8
    .incbin "bin/sm64.j.0EA5B8.bin"

glabel TableFallingBowserPlatformActions
.word ActionFallingBowserPlatform0
.word ActionFallingBowserPlatform1
.word ActionFallingBowserPlatform2

# Unknown region 0EA728-0EA840 [118]
glabel D_8032F728
	.incbin "bin/sm64.j.0EA728.bin", 0x0, 0x10

glabel D_8032F738
	.incbin "bin/sm64.j.0EA728.bin", 0x10, 0x1C

glabel D_8032F754
	.incbin "bin/sm64.j.0EA728.bin", 0x2C, 0x28

glabel D_8032F77C
	.incbin "bin/sm64.j.0EA728.bin", 0x54, 0x5C

glabel D_8032F7D8
	.incbin "bin/sm64.j.0EA728.bin", 0xB0, 0x68

glabel TableUkikiOpenCageActions
.word ActionUkikiOpenCage0
.word ActionUkikiOpenCage1
.word ActionUkikiOpenCage2
.word ActionUkikiOpenCage3
.word ActionUkikiOpenCage4
.word ActionUkikiOpenCage5
.word ActionUkikiOpenCage6
.word ActionUkikiOpenCage7

# Unknown region 0EA860-0EA8D0 [70]
.byte 0x00, 0x02, 0x00, 0x1E, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xDC, 0x03, 0x84, 0x00, 0x1E
.byte 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0xFF, 0xE2, 0x00, 0x02, 0x00, 0x1E, 0xC0, 0x00, 0x00, 0x00
.byte 0x00, 0x01, 0x00, 0xDC, 0x03, 0x84, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0xFF, 0xE2
.byte 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xDB
.byte 0x03, 0x84, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0xFF, 0xE2, 0x00, 0x02, 0x00, 0x1E
.byte 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xDB, 0x03, 0x84, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x1E
.byte 0x00, 0x00, 0xFF, 0xE2, 0x00, 0x03, 0x00, 0x00, 0x80, 0x32, 0xF8, 0x60, 0x80, 0x32, 0xF8, 0x94

glabel TableRotatingCwFireBarsActions
.word ActionRotatingCwFireBars0
.word ActionRotatingCwFireBars1
.word ActionRotatingCwFireBars2
.word ActionRotatingCwFireBars3

# Unknown region 0EA8E0-0EA978 [98]
glabel D_8032F8E0
    .incbin "bin/sm64.j.0EA8E0.bin"

glabel TableToxBoxActions
.word ActionToxBox0
.word ActionToxBox1
.word ActionToxBox2
.word ActionToxBox3
.word ActionToxBox4
.word ActionToxBox5
.word ActionToxBox6
.word ActionToxBox7

glabel D_8032F998
# Unknown region 0EA998-0EA9A0 [8]
.byte 0x0C, 0x1C, 0x32, 0x40, 0xFF, 0x00, 0x00, 0x00

glabel TablePiranhaPlantActions
.word ActionPiranhaPlant20
.word ActionPiranhaPlant21
.word ActionPiranhaPlant22
.word ActionPiranhaPlant23
.word ActionPiranhaPlant24
.word ActionPiranhaPlant25
.word ActionPiranhaPlant26
.word ActionPiranhaPlant27
.word ActionPiranhaPlant28

# Unknown region 0EA9C4-0EABBC [1F8]
	.incbin "bin/sm64.j.0EA9C4.bin", 0x0, 0x188

glabel D_8032FB4C
	.incbin "bin/sm64.j.0EA9C4.bin", 0x188, 0x70

glabel TableBowserPuzzlePieceActions
.word ActionBowserPuzzlePiece0
.word ActionBowserPuzzlePiece1
.word ActionBowserPuzzlePiece2
.word ActionBowserPuzzlePiece3
.word ActionBowserPuzzlePiece4
.word ActionBowserPuzzlePiece5
.word ActionBowserPuzzlePiece6

glabel TableTuxiesMotherActions
.word ActionTuxiesMother0
.word ActionTuxiesMother1
.word ActionTuxiesMother2

glabel TableSmallPenguinActions
.word ActionSmallPenguin0
.word ActionSmallPenguin1
.word ActionSmallPenguin2
.word ActionSmallPenguin3
.word ActionSmallPenguin4
.word ActionSmallPenguin5

glabel TableFishActions
.word ActionFish0
.word ActionFish1
.word ActionFish2

glabel TableFishGroupActions
.word ActionFishGroup0
.word ActionFishGroup1
.word ActionFishGroup2

glabel TableBirdChirpChirpActions
.word ActionBirdChirpChirp0
.word ActionBirdChirpChirp1
.word ActionBirdChirpChirp2
.word ActionBirdChirpChirp3

glabel TableCheepCheepActions
.word ActionCheepCheep0
.word ActionCheepCheep1
.word ActionCheepCheep2

# Unknown region 0EAC30-0EACC0 [90]
glabel D_8032FC30
	.incbin "bin/sm64.j.0EAC30.bin", 0x0, 0x10

glabel D_8032FC40
	.incbin "bin/sm64.j.0EAC30.bin", 0x10, 0x80

glabel TableExclamationBoxActions
.word ActionExclamationBox0
.word ActionExclamationBox1
.word ActionExclamationBox2
.word ActionExclamationBox3
.word ActionExclamationBox4
.word ActionExclamationBox5

glabel D_8032FCD8
# Unknown region 0EACD8-0EAD08 [30]
.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00, 0x82, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00
.byte 0x01, 0x40, 0x00, 0x38, 0x07, 0x01, 0x14, 0x74, 0x01, 0x9A, 0x00, 0x3C, 0x07, 0x02, 0xB6, 0x5C
.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xDC, 0x0F, 0xA0, 0x00, 0x00, 0x00, 0x00

glabel TableTweesterActions
.word ActionTweester0
.word ActionTweester1
.word ActionTweester2

glabel D_8032FD14
# Unknown region 0EAD14-0EAD38 [24]
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x8C, 0x00, 0x50, 0x00, 0x28, 0x00, 0x3C
.byte 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0xD2, 0x00, 0x6E, 0x00, 0xD2, 0xFF, 0x2E, 0x00, 0x46
.byte 0xFF, 0x2E, 0x00, 0x00

glabel TableBooActions
.word ActionBoo0
.word ActionBoo1
.word ActionBoo2
.word ActionBoo3
.word ActionBoo4
.word ActionBoo5

glabel TableBooGivingStarActions
.word ActionBooGivingStar0
.word ActionBooGivingStar1
.word ActionBooGivingStar2
.word ActionBooGivingStar3
.word ActionBooGivingStar4

glabel TableBooWithCageActions
.word ActionBooWithCage0
.word ActionBooWithCage1
.word ActionBooWithCage2
.word ActionBooWithCage3

glabel D_8032FD74
# Unknown region 0EAD74-0EAD84 [10]
.byte 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x01, 0x03, 0x00, 0x82, 0x00, 0x46, 0x00, 0x5A, 0x00, 0x3C

glabel TableWhompActions
.word ActionWhomp0
.word ActionWhomp1
.word ActionWhomp2
.word ActionWhomp3
.word ActionWhomp4
.word ActionWhomp5
.word ActionWhomp6
.word ActionWhomp7
.word ActionWhomp8
.word ActionWhomp9

# Unknown region 0EADAC-0EFA50 [4CA4]
glabel D_8032FDAC
	.incbin "bin/sm64.j.0EADAC.bin", 0x0, 0x48

glabel D_8032FDF4
	.incbin "bin/sm64.j.0EADAC.bin", 0x48, 0x48

glabel D_8032FE3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x90, 0x10

glabel D_8032FE4C
	.incbin "bin/sm64.j.0EADAC.bin", 0xA0, 0x74

glabel D_8032FEC0
	.incbin "bin/sm64.j.0EADAC.bin", 0x114, 0x14

glabel gMarioPlatform
	.incbin "bin/sm64.j.0EADAC.bin", 0x128, 0xC

glabel D_8032FEE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x134, 0x24

glabel D_8032FF04
	.incbin "bin/sm64.j.0EADAC.bin", 0x158, 0x24

glabel D_8032FF28
	.incbin "bin/sm64.j.0EADAC.bin", 0x17C, 0x4

glabel D_8032FF2C
	.incbin "bin/sm64.j.0EADAC.bin", 0x180, 0x4

glabel D_8032FF30
	.incbin "bin/sm64.j.0EADAC.bin", 0x184, 0x4

glabel D_8032FF34
	.incbin "bin/sm64.j.0EADAC.bin", 0x188, 0x4

glabel D_8032FF38
	.incbin "bin/sm64.j.0EADAC.bin", 0x18C, 0x4

glabel D_8032FF3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x190, 0x4

glabel D_8032FF40
	.incbin "bin/sm64.j.0EADAC.bin", 0x194, 0x4

glabel D_8032FF44
	.incbin "bin/sm64.j.0EADAC.bin", 0x198, 0x4

glabel D_8032FF48
	.incbin "bin/sm64.j.0EADAC.bin", 0x19C, 0x18

glabel D_8032FF60
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B4, 0x4

glabel D_8032FF64
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B8, 0x4

glabel D_8032FF68
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC, 0x60

glabel D_8032FFC8
	.incbin "bin/sm64.j.0EADAC.bin", 0x21C, 0x8

glabel D_8032FFD0
	.incbin "bin/sm64.j.0EADAC.bin", 0x224, 0x4

glabel D_8032FFD4
	.incbin "bin/sm64.j.0EADAC.bin", 0x228, 0x4

glabel D_8032FFD8
	.incbin "bin/sm64.j.0EADAC.bin", 0x22C, 0x8

glabel D_8032FFE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x234, 0x1B

glabel D_8032FFFB
	.incbin "bin/sm64.j.0EADAC.bin", 0x24F, 0x4

glabel D_8032FFFF
	.incbin "bin/sm64.j.0EADAC.bin", 0x253, 0x5

glabel D_80330004
	.incbin "bin/sm64.j.0EADAC.bin", 0x258, 0x240

glabel D_80330244
	.incbin "bin/sm64.j.0EADAC.bin", 0x498, 0xD8

glabel D_8033031C
	.incbin "bin/sm64.j.0EADAC.bin", 0x570, 0x6C

glabel D_80330388
	.incbin "bin/sm64.j.0EADAC.bin", 0x5DC, 0x8

glabel D_80330390
	.incbin "bin/sm64.j.0EADAC.bin", 0x5E4, 0x4

glabel D_80330394
	.incbin "bin/sm64.j.0EADAC.bin", 0x5E8, 0x4

glabel D_80330398
	.incbin "bin/sm64.j.0EADAC.bin", 0x5EC, 0x60

glabel D_803303F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x64C, 0x4

glabel D_803303FC
	.incbin "bin/sm64.j.0EADAC.bin", 0x650, 0x4

glabel D_80330400
	.incbin "bin/sm64.j.0EADAC.bin", 0x654, 0x10

glabel D_80330410
	.incbin "bin/sm64.j.0EADAC.bin", 0x664, 0xC

glabel D_8033041C
	.incbin "bin/sm64.j.0EADAC.bin", 0x670, 0x4

glabel D_80330420
	.incbin "bin/sm64.j.0EADAC.bin", 0x674, 0x4

glabel D_80330424
	.incbin "bin/sm64.j.0EADAC.bin", 0x678, 0x4

glabel D_80330428
	.incbin "bin/sm64.j.0EADAC.bin", 0x67C, 0x4

glabel D_8033042C
	.incbin "bin/sm64.j.0EADAC.bin", 0x680, 0x4

glabel D_80330430
	.incbin "bin/sm64.j.0EADAC.bin", 0x684, 0x4

glabel D_80330434
	.incbin "bin/sm64.j.0EADAC.bin", 0x688, 0x4

glabel D_80330438
	.incbin "bin/sm64.j.0EADAC.bin", 0x68C, 0x4

glabel D_8033043C
	.incbin "bin/sm64.j.0EADAC.bin", 0x690, 0x4

glabel D_80330440
	.incbin "bin/sm64.j.0EADAC.bin", 0x694, 0x4

glabel D_80330444
	.incbin "bin/sm64.j.0EADAC.bin", 0x698, 0x4

glabel D_80330448
	.incbin "bin/sm64.j.0EADAC.bin", 0x69C, 0x4

glabel D_8033044C
	.incbin "bin/sm64.j.0EADAC.bin", 0x6A0, 0x4

glabel D_80330450
	.incbin "bin/sm64.j.0EADAC.bin", 0x6A4, 0x4

glabel D_80330454
	.incbin "bin/sm64.j.0EADAC.bin", 0x6A8, 0xC

glabel D_80330460
	.incbin "bin/sm64.j.0EADAC.bin", 0x6B4, 0x8

glabel D_80330468
	.incbin "bin/sm64.j.0EADAC.bin", 0x6BC, 0xC

glabel D_80330474
	.incbin "bin/sm64.j.0EADAC.bin", 0x6C8, 0x8

glabel D_8033047C
	.incbin "bin/sm64.j.0EADAC.bin", 0x6D0, 0xA4

glabel D_80330520
	.incbin "bin/sm64.j.0EADAC.bin", 0x774, 0x4

glabel D_80330524
	.incbin "bin/sm64.j.0EADAC.bin", 0x778, 0x4

glabel D_80330528
	.incbin "bin/sm64.j.0EADAC.bin", 0x77C, 0x4

glabel D_8033052C
	.incbin "bin/sm64.j.0EADAC.bin", 0x780, 0x4

glabel D_80330530
	.incbin "bin/sm64.j.0EADAC.bin", 0x784, 0x4

glabel D_80330534
	.incbin "bin/sm64.j.0EADAC.bin", 0x788, 0x4

glabel D_80330538
	.incbin "bin/sm64.j.0EADAC.bin", 0x78C, 0x4

glabel D_8033053C
	.incbin "bin/sm64.j.0EADAC.bin", 0x790, 0x8

glabel D_80330544
	.incbin "bin/sm64.j.0EADAC.bin", 0x798, 0x4

glabel D_80330548
	.incbin "bin/sm64.j.0EADAC.bin", 0x79C, 0x4

glabel D_8033054C
	.incbin "bin/sm64.j.0EADAC.bin", 0x7A0, 0xC

glabel D_80330558
	.incbin "bin/sm64.j.0EADAC.bin", 0x7AC, 0x10

glabel D_80330568
	.incbin "bin/sm64.j.0EADAC.bin", 0x7BC, 0xC

glabel D_80330574
	.incbin "bin/sm64.j.0EADAC.bin", 0x7C8, 0xC

glabel D_80330580
	.incbin "bin/sm64.j.0EADAC.bin", 0x7D4, 0x10

glabel D_80330590
	.incbin "bin/sm64.j.0EADAC.bin", 0x7E4, 0xC

glabel D_8033059C
	.incbin "bin/sm64.j.0EADAC.bin", 0x7F0, 0x10

glabel D_803305AC
	.incbin "bin/sm64.j.0EADAC.bin", 0x800, 0x8

glabel D_803305B4
	.incbin "bin/sm64.j.0EADAC.bin", 0x808, 0x4

glabel D_803305B8
	.incbin "bin/sm64.j.0EADAC.bin", 0x80C, 0x4

glabel D_803305BC
	.incbin "bin/sm64.j.0EADAC.bin", 0x810, 0x4

glabel D_803305C0
	.incbin "bin/sm64.j.0EADAC.bin", 0x814, 0x4

glabel D_803305C4
	.incbin "bin/sm64.j.0EADAC.bin", 0x818, 0x4

glabel D_803305C8
	.incbin "bin/sm64.j.0EADAC.bin", 0x81C, 0x4

glabel D_803305CC
	.incbin "bin/sm64.j.0EADAC.bin", 0x820, 0x4

glabel D_803305D0
	.incbin "bin/sm64.j.0EADAC.bin", 0x824, 0x8

glabel D_803305D8
	.incbin "bin/sm64.j.0EADAC.bin", 0x82C, 0x10

glabel D_803305E8
	.incbin "bin/sm64.j.0EADAC.bin", 0x83C, 0x4

glabel D_803305EC
	.incbin "bin/sm64.j.0EADAC.bin", 0x840, 0x4

glabel D_803305F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x844, 0x4

glabel D_803305F4
	.incbin "bin/sm64.j.0EADAC.bin", 0x848, 0x4

glabel D_803305F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x84C, 0x8

glabel D_80330600
	.incbin "bin/sm64.j.0EADAC.bin", 0x854, 0x8

glabel D_80330608
	.incbin "bin/sm64.j.0EADAC.bin", 0x85C, 0x10

glabel D_80330618
	.incbin "bin/sm64.j.0EADAC.bin", 0x86C, 0xC

glabel D_80330624
	.incbin "bin/sm64.j.0EADAC.bin", 0x878, 0x1C

glabel D_80330640
	.incbin "bin/sm64.j.0EADAC.bin", 0x894, 0x8

glabel D_80330648
	.incbin "bin/sm64.j.0EADAC.bin", 0x89C, 0x30

glabel D_80330678
	.incbin "bin/sm64.j.0EADAC.bin", 0x8CC, 0x8

glabel D_80330680
	.incbin "bin/sm64.j.0EADAC.bin", 0x8D4, 0x8

glabel D_80330688
	.incbin "bin/sm64.j.0EADAC.bin", 0x8DC, 0x10

glabel D_80330698
	.incbin "bin/sm64.j.0EADAC.bin", 0x8EC, 0xBA8

glabel D_80331240
	.incbin "bin/sm64.j.0EADAC.bin", 0x1494, 0x1

glabel D_80331241
	.incbin "bin/sm64.j.0EADAC.bin", 0x1495, 0x1

glabel D_80331242
	.incbin "bin/sm64.j.0EADAC.bin", 0x1496, 0x1

glabel D_80331243
	.incbin "bin/sm64.j.0EADAC.bin", 0x1497, 0x1

glabel D_80331244
	.incbin "bin/sm64.j.0EADAC.bin", 0x1498, 0x29C

glabel D_803314E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1734, 0x2

glabel D_803314E2
	.incbin "bin/sm64.j.0EADAC.bin", 0x1736, 0x2

glabel D_803314E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1738, 0x8

glabel D_803314EC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1740, 0xC

glabel D_803314F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x174C, 0x8

glabel D_80331500
	.incbin "bin/sm64.j.0EADAC.bin", 0x1754, 0x4

glabel D_80331504
	.incbin "bin/sm64.j.0EADAC.bin", 0x1758, 0x4

glabel D_80331508
	.incbin "bin/sm64.j.0EADAC.bin", 0x175C, 0x4

glabel D_8033150C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1760, 0x4

glabel D_80331510
	.incbin "bin/sm64.j.0EADAC.bin", 0x1764, 0x4

glabel D_80331514
	.incbin "bin/sm64.j.0EADAC.bin", 0x1768, 0x10

glabel D_80331524
	.incbin "bin/sm64.j.0EADAC.bin", 0x1778, 0x10

glabel D_80331534
	.incbin "bin/sm64.j.0EADAC.bin", 0x1788, 0x10

glabel D_80331544
	.incbin "bin/sm64.j.0EADAC.bin", 0x1798, 0x10

glabel D_80331554
	.incbin "bin/sm64.j.0EADAC.bin", 0x17A8, 0x10

glabel D_80331564
	.incbin "bin/sm64.j.0EADAC.bin", 0x17B8, 0x10

glabel D_80331574
	.incbin "bin/sm64.j.0EADAC.bin", 0x17C8, 0x10

glabel D_80331584
	.incbin "bin/sm64.j.0EADAC.bin", 0x17D8, 0x10

glabel D_80331594
	.incbin "bin/sm64.j.0EADAC.bin", 0x17E8, 0x10

glabel D_803315A4
	.incbin "bin/sm64.j.0EADAC.bin", 0x17F8, 0x10

glabel D_803315B4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1808, 0x54

glabel D_80331608
	.incbin "bin/sm64.j.0EADAC.bin", 0x185C, 0x4C

glabel D_80331654
	.incbin "bin/sm64.j.0EADAC.bin", 0x18A8, 0x10

glabel D_80331664
	.incbin "bin/sm64.j.0EADAC.bin", 0x18B8, 0x10

glabel D_80331674
	.incbin "bin/sm64.j.0EADAC.bin", 0x18C8, 0x10

glabel D_80331684
	.incbin "bin/sm64.j.0EADAC.bin", 0x18D8, 0x10

glabel D_80331694
	.incbin "bin/sm64.j.0EADAC.bin", 0x18E8, 0x4

glabel D_80331698
	.incbin "bin/sm64.j.0EADAC.bin", 0x18EC, 0x10

glabel D_803316A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x18FC, 0x44

glabel D_803316EC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1940, 0x10

glabel D_803316FC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1950, 0x10

glabel D_8033170C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1960, 0x10

glabel D_8033171C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1970, 0x2

glabel D_8033171E
	.incbin "bin/sm64.j.0EADAC.bin", 0x1972, 0x12

glabel D_80331730
	.incbin "bin/sm64.j.0EADAC.bin", 0x1984, 0x10

glabel D_80331740
	.incbin "bin/sm64.j.0EADAC.bin", 0x1994, 0x8

glabel D_80331748
	.incbin "bin/sm64.j.0EADAC.bin", 0x199C, 0x8

glabel D_80331750
	.incbin "bin/sm64.j.0EADAC.bin", 0x19A4, 0x2

glabel D_80331752
	.incbin "bin/sm64.j.0EADAC.bin", 0x19A6, 0x2

glabel D_80331754
	.incbin "bin/sm64.j.0EADAC.bin", 0x19A8, 0x1C

glabel D_80331770
	.incbin "bin/sm64.j.0EADAC.bin", 0x19C4, 0x10

glabel D_80331780
	.incbin "bin/sm64.j.0EADAC.bin", 0x19D4, 0x8

glabel D_80331788
	.incbin "bin/sm64.j.0EADAC.bin", 0x19DC, 0x10

glabel D_80331798
	.incbin "bin/sm64.j.0EADAC.bin", 0x19EC, 0x10

glabel D_803317A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x19FC, 0x8

glabel D_803317B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A04, 0x10

glabel D_803317C0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A14, 0x4

glabel D_803317C4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A18, 0x4

glabel D_803317C8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A1C, 0x2

glabel D_803317CA
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A1E, 0x1A

glabel D_803317E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A38, 0xC

glabel D_803317F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A44, 0x10

glabel D_80331800
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A54, 0x10

glabel D_80331810
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A64, 0x10

glabel D_80331820
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A74, 0x4

glabel D_80331824
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A78, 0x14

glabel D_80331838
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A8C, 0xC

glabel D_80331844
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A98, 0x10

glabel D_80331854
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AA8, 0x8

glabel D_8033185C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AB0, 0x10

glabel D_8033186C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AC0, 0x8

glabel D_80331874
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AC8, 0x3

glabel D_80331877
	.incbin "bin/sm64.j.0EADAC.bin", 0x1ACB, 0x3

glabel D_8033187A
	.incbin "bin/sm64.j.0EADAC.bin", 0x1ACE, 0xE

glabel D_80331888
	.incbin "bin/sm64.j.0EADAC.bin", 0x1ADC, 0x10

glabel D_80331898
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AEC, 0x10

glabel D_803318A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AFC, 0x14

glabel D_803318BC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B10, 0x10

glabel D_803318CC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B20, 0x24

glabel D_803318F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B44, 0x20

glabel D_80331910
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B64, 0x4

glabel D_80331914
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B68, 0x4

glabel D_80331918
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B6C, 0x10

glabel D_80331928
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B7C, 0x10

glabel D_80331938
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B8C, 0x3

glabel D_8033193B
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B8F, 0x2

glabel D_8033193D
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B91, 0x1

glabel D_8033193E
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B92, 0xE

glabel D_8033194C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BA0, 0x14

glabel D_80331960
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BB4, 0x8

glabel D_80331968
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BBC, 0x4

glabel D_8033196C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC0, 0x10

glabel D_8033197C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BD0, 0x8

glabel D_80331984
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BD8, 0x8

glabel D_8033198C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BE0, 0x8

glabel D_80331994
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BE8, 0x4

glabel D_80331998
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BEC, 0x8

glabel D_803319A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BF4, 0x4

glabel D_803319A4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BF8, 0x4

glabel D_803319A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BFC, 0x8

glabel D_803319B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C04, 0x2

glabel D_803319B2
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C06, 0x1E

glabel D_803319D0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C24, 0x4

glabel D_803319D4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C28, 0x4

glabel D_803319D8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C2C, 0x10

glabel D_803319E8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C3C, 0x8

glabel D_803319F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C44, 0x10

glabel D_80331A00
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C54, 0x1

glabel D_80331A01
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C55, 0x2

glabel D_80331A03
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C57, 0x1

glabel D_80331A04
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C58, 0x2

glabel D_80331A06
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C5A, 0xE

glabel D_80331A14
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C68, 0x10

glabel D_80331A24
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C78, 0x20

glabel D_80331A44
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C98, 0x8

glabel D_80331A4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CA0, 0x80

glabel D_80331ACC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D20, 0x8

glabel D_80331AD4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D28, 0xC

glabel D_80331AE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D34, 0x10

glabel D_80331AF0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D44, 0x10

glabel D_80331B00
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D54, 0x10

glabel D_80331B10
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D64, 0x10

glabel D_80331B20
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D74, 0x10

glabel D_80331B30
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D84, 0xC

glabel D_80331B3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D90, 0x10

glabel D_80331B4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DA0, 0x10

glabel D_80331B5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DB0, 0x8

glabel D_80331B64
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DB8, 0x10

glabel D_80331B74
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DC8, 0x10

glabel D_80331B84
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DD8, 0x10

glabel D_80331B94
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DE8, 0x10

glabel D_80331BA4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DF8, 0x8

glabel D_80331BAC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E00, 0x10

glabel D_80331BBC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E10, 0x4

glabel D_80331BC0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E14, 0x4

glabel D_80331BC4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E18, 0x1C

glabel D_80331BE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E34, 0x8

glabel D_80331BE8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E3C, 0x18

glabel D_80331C00
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E54, 0x2

glabel D_80331C02
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E56, 0x16

glabel D_80331C18
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E6C, 0x10

glabel D_80331C28
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E7C, 0x10

glabel D_80331C38
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E8C, 0x10

glabel D_80331C48
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E9C, 0x2

glabel D_80331C4A
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E9E, 0x2

glabel D_80331C4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1EA0, 0xB8

glabel D_80331D04
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F58, 0x10

glabel D_80331D14
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F68, 0x4

glabel D_80331D18
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F6C, 0x4

glabel D_80331D1C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F70, 0x10

glabel D_80331D2C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F80, 0x14

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

glabel D_803347C0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A14, 0x4

glabel D_803347C4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A18, 0x4

glabel D_803347C8
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A1C, 0x4

glabel D_803347CC
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A20, 0x4

glabel D_803347D0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A24, 0x4

glabel D_803347D4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A28, 0xC

glabel D_803347E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A34, 0x4

glabel D_803347E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A38, 0x4

glabel D_803347E8
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A3C, 0x4

glabel D_803347EC
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A40, 0x4

glabel D_803347F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A44, 0x4

glabel D_803347F4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A48, 0xC

glabel D_80334800
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A54, 0x4

glabel D_80334804
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A58, 0x4

glabel D_80334808
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A5C, 0x8

glabel D_80334810
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A64, 0x10

glabel D_80334820
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A74, 0x10

glabel D_80334830
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A84, 0x10

glabel D_80334840
	.incbin "bin/sm64.j.0EADAC.bin", 0x4A94, 0x24

glabel D_80334864
	.incbin "bin/sm64.j.0EADAC.bin", 0x4AB8, 0x2C

glabel D_80334890
	.incbin "bin/sm64.j.0EADAC.bin", 0x4AE4, 0x8

glabel D_80334898
	.incbin "bin/sm64.j.0EADAC.bin", 0x4AEC, 0x4

glabel D_8033489C
	.incbin "bin/sm64.j.0EADAC.bin", 0x4AF0, 0x4

glabel D_803348A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4AF4, 0x4

glabel D_803348A4
	.incbin "bin/sm64.j.0EADAC.bin", 0x4AF8, 0xC

glabel D_803348B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B04, 0x60

glabel D_80334910
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B64, 0x4

glabel D_80334914
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B68, 0x4

glabel D_80334918
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B6C, 0x4

glabel D_8033491C
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B70, 0x4

glabel D_80334920
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B74, 0x14

glabel D_80334934
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B88, 0x4

glabel D_80334938
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B8C, 0x8

glabel D_80334940
	.incbin "bin/sm64.j.0EADAC.bin", 0x4B94, 0x10

glabel D_80334950
	.incbin "bin/sm64.j.0EADAC.bin", 0x4BA4, 0x10

glabel D_80334960
	.incbin "bin/sm64.j.0EADAC.bin", 0x4BB4, 0x14

glabel D_80334974
	.incbin "bin/sm64.j.0EADAC.bin", 0x4BC8, 0x1C

glabel D_80334990
	.incbin "bin/sm64.j.0EADAC.bin", 0x4BE4, 0x50

glabel D_803349E0
	.incbin "bin/sm64.j.0EADAC.bin", 0x4C34, 0x50

glabel D_80334A30
	.incbin "bin/sm64.j.0EADAC.bin", 0x4C84, 0x4

glabel D_80334A34
	.incbin "bin/sm64.j.0EADAC.bin", 0x4C88, 0x4

glabel D_80334A38
	.incbin "bin/sm64.j.0EADAC.bin", 0x4C8C, 0x8

glabel D_80334A40
	.incbin "bin/sm64.j.0EADAC.bin", 0x4C94, 0x4

glabel D_80334A44
	.incbin "bin/sm64.j.0EADAC.bin", 0x4C98, 0xC

