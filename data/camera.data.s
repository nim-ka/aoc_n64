.include "macros.inc"


.section .data


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
.word 0x01000000, CameraBBH020C, 0x00DE0000, 0x05B200C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x00DE0000, 0x027F00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x01B30000, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x064D0000, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x07230000, 0x05B300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0xFE110333, 0x057F00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0xFE110333, 0x028000FA, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x00B30333, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x064D0333, 0x00DE00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x07230333, 0x01E600C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH020C, 0x07230333, 0x071A00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH0D0F, 0x09410000, 0x05B300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH0D0F, 0x0D1A0000, 0x054300C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH0D0F, 0x0B330202, 0x07330200, 0x00660199, 0x00000000
.word 0x01000000, CameraBBH1011, 0x0D1A0000, 0x032400C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH1011, 0x064D0000, 0xFEC000C8, 0x00C800C8, 0x00000000
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
.word 0x01000000, CameraBBH020C, 0x07230333, 0x071A00C8, 0x00C800C8, 0x00000000
.word 0x01000000, CameraBBH2E2F, 0x0933FBA8, 0xFF3F04CC, 0x01F4053F, 0x00000000
.word 0x01000000, CameraBBH2E2F, 0x0933F941, 0x058204CC, 0x01F402C1, 0x00000000
.word 0x01000000, CameraBBH3033, 0x0000F667, 0x072300FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH3033, 0x0000F667, 0x094100FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH3033, 0x0000F667, 0x134100FA, 0x00C800FA, 0x00000000
.word 0x01000000, CameraBBH3033, 0x0000F667, 0x112300FA, 0x00C800FA, 0x00000000
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

glabel TableCutscenePeachEnd
.word CutscenePeachEnd0, 0x00AA0000
.word CutscenePeachEnd1, 0x00460000
.word CutscenePeachEnd2, 0x004B0000
.word CutscenePeachEnd3, 0x01820000
.word CutscenePeachEnd4, 0x008B0000
.word CutscenePeachEnd5, 0x024E0000
.word CutscenePeachEnd6, 0x005F0000
.word CutscenePeachEnd7, 0x01A90000
.word CutscenePeachEnd8, 0x00EC0000
.word CutscenePeachEnd9, 0x00F50000
.word CutscenePeachEndA, 0x7FFF0000
.word CutscenePeachEndB, 0x00000000

glabel TableCutsceneGrandStar
.word CutsceneGrandStar0, 0x01680000
.word CutsceneGrandStar1, 0x7FFF0000

glabel TableCutscene0FTodo
.word Cutscene0FTodo0, 0x00010000
.word Cutscene0FTodo1, 0x7FFF0000

glabel TableCutsceneDoorWarp
.word CutsceneDoor0, 0x00010000
.word CutsceneDoorWarp1, 0x7FFF0000

glabel TableCutsceneEndWaving
.word CutsceneEndWaving0, 0x7FFF0000

glabel TableCutsceneCredits
.word CutsceneCredits0, 0x7FFF0000

glabel TableCutsceneDoor00
.word CutsceneDoor0, 0x00010000
.word CutsceneDoor1, 0x001E0000
.word CutsceneDoor2, 0x00010000
.word CutsceneDoor3, 0x00320000
.word CutsceneDoor4, 0x00000000

glabel TableCutsceneDoor01
.word CutsceneDoor0, 0x00010000
.word CutsceneDoor1, 0x00140000
.word CutsceneDoor2, 0x00010000
.word CutsceneDoor3, 0x00320000
.word CutsceneDoor4, 0x00000000

glabel TableCutsceneDoor0A
.word CutsceneDoor0, 0x00010000
.word CutsceneDoor1, 0x001E0000
.word CutsceneDoorAB_2, 0x7FFF0000

glabel TableCutsceneDoor0B
.word CutsceneDoor0, 0x00010000
.word CutsceneDoor1, 0x00140000
.word CutsceneDoorAB_2, 0x7FFF0000

glabel TableCutsceneEnterCannon
.word CutsceneEnterCannon0, 0x00010000
.word CutsceneEnterCannon1, 0x00790000
.word CutsceneEnterCannon2, 0x00000000

glabel TableCutsceneStarSpawn
.word CutsceneStarSpawn0, 0x7FFF0000
.word CutsceneStarSpawn1, 0x000F0000
.word CutsceneStarSpawn2, 0x00000000

glabel TableCutsceneSpecialStarSpawn
.word CutsceneSpecialStarSpawn0, 0x7FFF0000
.word CutsceneSpecialStarSpawn1, 0x00000000

glabel TableCutsceneEnterPainting
.word CutsceneEnterPainting0, 0x7FFF0000

glabel TableCutsceneExitPaintingDeath
.word CutsceneExitPainting0, 0x00760000
.word CutsceneExitPainting1, 0x00000000

glabel TableCutsceneExitPaintingSuccess
.word CutsceneExitPainting0, 0x00B40000
.word CutsceneExitPainting1, 0x00000000

glabel TableCutscene11Todo
.word Cutscene11Todo_0, 0x00010000
.word Cutscene11Todo_1, 0x003C0000
.word CutsceneExitPainting1, 0x00000000

glabel TableCutsceneIntroPeach
.word CutsceneIntroPeach0, 0x7FFF0000
.word CutsceneIntroPeach1, 0x00230000
.word CutsceneIntroPeach2, 0x03340000
.word CutsceneIntroPeach3, 0x010E0000
.word CutsceneIntroPeach4, 0x7FFF0000

glabel TableCutscenePrepareCannon
.word CutscenePrepareCannon0, 0x00AA0000
.word CutscenePrepareCannon1, 0x00000000

glabel TableCutsceneExitWaterfall
.word CutsceneExitWaterfall0, 0x00340000
.word CutsceneFallCommon1, 0x00000000

glabel TableCutsceneFallToCastleGrounds
.word CutsceneFallToCastleGrounds0, 0x00490000
.word CutsceneFallCommon1, 0x00000000

glabel TableCutsceneEnterPyramidTop
.word CutsceneEnterPyramidTop0, 0x005A0000
.word CutsceneFallCommon1, 0x00000000

glabel TableCutscene26Todo
.word Cutscene26Todo0, 0x7FFF0000
.word Cutscene26Todo1, 0x00960000
.word Cutscene26Todo2, 0x00000000

glabel TableCutsceneDeath1
.word CutsceneDeath1, 0x7FFF0000

glabel TableCutsceneEnterPool
.word CutsceneEnterPool0, 0x00640000
.word CutsceneFallCommon1, 0x00000000

glabel TableCutsceneDeath2
.word CutsceneDeath2, 0x7FFF0000

glabel TableCutsceneBBHDeath
.word CutsceneBBHDeath0, 0x7FFF0000

glabel TableCutsceneQuicksandDeath
.word CutsceneQuicksandDeath0, 0x7FFF0000
.word CutsceneQuicksandDeath0, 0x7FFF0000

glabel TableCutscene1ATodo
.word Cutscene1ATodo0, 0x7FFF0000

glabel TableCutsceneEnterBowserPlatform
.word CutsceneEnterBowserPlatform0, 0x00B40000
.word CutsceneEnterBowserPlatform1, 0x7FFF0000
.word CutsceneEnterBowserPlatform2, 0x00000000

glabel TableCutsceneStarDance1
.word CutsceneStarDance1, 0x7FFF0000

glabel TableCutsceneStarDance2
.word CutsceneStarDance2, 0x7FFF0000

glabel TableCutsceneStarDance3
.word CutsceneStarDance3, 0x7FFF0000

glabel TableCutsceneKeyDance
.word CutsceneKeyDance0, 0x7FFF0000

glabel TableCutsceneCapSwitchPress
.word CutsceneCapSwitchPress0, 0x7FFF0000

glabel TableCutsceneSlidingDoorsOpen
.word CutsceneSlidingDoorsOpen0, 0x00320000
.word CutsceneDoubleDoorsOpen1, 0x00000000

glabel TableCutsceneUnlockKeyDoor
.word CutsceneUnlockKeyDoor0, 0x00C80000
.word CutsceneDoubleDoorsOpen1, 0x00000000

glabel TableCutsceneExitBowserSuccess
.word CutsceneExitBowserSuccess0, 0x00BE0000
.word CutsceneExitNonPainting1, 0x00000000

glabel TableCutscene1CTodo
.word Cutscene1CTodo_0, 0x00780000
.word CutsceneExitNonPainting1, 0x00000000

glabel TableCutsceneBBHExitSuccess
.word CutsceneBBHExitSuccess0, 0x00A30000
.word CutsceneExitNonPainting1, 0x00000000

glabel TableCutsceneNonPaintingDeath
.word CutsceneNonPaintingDeath0, 0x00780000
.word CutsceneExitNonPainting1, 0x00000000

glabel TableCutsceneDialog
.word CutsceneDialog0, 0x7FFF0000
.word CutsceneDialog1, 0x000C0000
.word CutsceneDialog2, 0x00000000

glabel TableCutsceneReadMessage
.word CutsceneReadMessage0, 0x7FFF0000
.word CutsceneReadMessage1, 0x000F0000
.word CutsceneReadMessage2, 0x00000000

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
