.include "macros.inc"
.include "globals.inc"

.section .rodata

# 0x80334A70

# Unknown region 0EFA50-0F4210 [47C0]

glabel D_80334A70
	.incbin "bin/rodata.bin", 0x0, 0x10

glabel D_80334A80
	.incbin "bin/rodata.bin", 0x10, 0x3CC

glabel jtbl_80334E4C
	.incbin "bin/rodata.bin", 0x3DC, 0x94

glabel jtbl_80334EE0
	.incbin "bin/rodata.bin", 0x470, 0x9C

glabel jtbl_80334F7C
	.incbin "bin/rodata.bin", 0x50C, 0x64

glabel jtbl_80334FE0
	.incbin "bin/rodata.bin", 0x570, 0x14

glabel jtbl_80334FF4
	.incbin "bin/rodata.bin", 0x584, 0x1C

glabel jtbl_80335010
	.incbin "bin/rodata.bin", 0x5A0, 0x80

glabel jtbl_80335090
	.incbin "bin/rodata.bin", 0x620, 0xC8

glabel jtbl_80335158
	.incbin "bin/rodata.bin", 0x6E8, 0x128

glabel D_80335280
	.incbin "bin/rodata.bin", 0x810, 0x8

glabel D_80335288
	.incbin "bin/rodata.bin", 0x818, 0x8

glabel D_80335290
	.incbin "bin/rodata.bin", 0x820, 0x8

glabel jtbl_80335298
	.incbin "bin/rodata.bin", 0x828, 0x20

glabel jtbl_803352B8
	.incbin "bin/rodata.bin", 0x848, 0x94

glabel jtbl_8033534C
	.incbin "bin/rodata.bin", 0x8DC, 0x20

glabel jtbl_8033536C
	.incbin "bin/rodata.bin", 0x8FC, 0xC8

glabel jtbl_80335434
	.incbin "bin/rodata.bin", 0x9C4, 0xA4

glabel jtbl_803354D8
	.incbin "bin/rodata.bin", 0xA68, 0x74

glabel jtbl_8033554C
	.incbin "bin/rodata.bin", 0xADC, 0x34

glabel jtbl_80335580
	.incbin "bin/rodata.bin", 0xB10, 0x34

glabel jtbl_803355B4
	.incbin "bin/rodata.bin", 0xB44, 0x1C

glabel jtbl_803355D0
	.incbin "bin/rodata.bin", 0xB60, 0x14

glabel jtbl_803355E4
	.incbin "bin/rodata.bin", 0xB74, 0xC4

glabel jtbl_803356A8
	.incbin "bin/rodata.bin", 0xC38, 0x108

glabel jtbl_803357B0
	.incbin "bin/rodata.bin", 0xD40, 0x28

glabel jtbl_803357D8
	.incbin "bin/rodata.bin", 0xD68, 0x2C

glabel jtbl_80335804
	.incbin "bin/rodata.bin", 0xD94, 0x14

glabel jtbl_80335818
	.incbin "bin/rodata.bin", 0xDA8, 0x60

glabel jtbl_80335878
	.incbin "bin/rodata.bin", 0xE08, 0xF4

glabel jtbl_8033596C
	.incbin "bin/rodata.bin", 0xEFC, 0x2C

glabel jtbl_80335998
	.incbin "bin/rodata.bin", 0xF28, 0x7C

glabel jtbl_80335A14
	.incbin "bin/rodata.bin", 0xFA4, 0x18

glabel jtbl_80335A2C
	.incbin "bin/rodata.bin", 0xFBC, 0x94

glabel jtbl_80335AC0
	.incbin "bin/rodata.bin", 0x1050, 0xC0

glabel jtbl_80335B80
	.incbin "bin/rodata.bin", 0x1110, 0x3C

glabel jtbl_80335BBC
	.incbin "bin/rodata.bin", 0x114C, 0xB8

glabel jtbl_80335C74
	.incbin "bin/rodata.bin", 0x1204, 0x18

glabel jtbl_80335C8C
	.incbin "bin/rodata.bin", 0x121C, 0x30

glabel jtbl_80335CBC
	.incbin "bin/rodata.bin", 0x124C, 0x48

glabel jtbl_80335D04
	.incbin "bin/rodata.bin", 0x1294, 0x2C

glabel jtbl_80335D30
	.incbin "bin/rodata.bin", 0x12C0, 0x28

glabel jtbl_80335D58
	.incbin "bin/rodata.bin", 0x12E8, 0x48

glabel jtbl_80335DA0
	.incbin "bin/rodata.bin", 0x1330, 0x30

glabel D_80335DD0
	.incbin "bin/rodata.bin", 0x1360, 0x10

glabel D_80335DE0
	.incbin "bin/rodata.bin", 0x1370, 0x8

glabel D_80335DE8
	.incbin "bin/rodata.bin", 0x1378, 0x8

glabel D_80335DF0
	.incbin "bin/rodata.bin", 0x1380, 0xC

glabel jtbl_80335DFC
	.incbin "bin/rodata.bin", 0x138C, 0xB0

glabel jtbl_80335EAC
	.incbin "bin/rodata.bin", 0x143C, 0xD4

glabel jtbl_80335F80
	.incbin "bin/rodata.bin", 0x1510, 0xF8

glabel jtbl_80336078
	.incbin "bin/rodata.bin", 0x1608, 0x54

glabel jtbl_803360CC
	.incbin "bin/rodata.bin", 0x165C, 0x98

glabel jtbl_80336164
	.incbin "bin/rodata.bin", 0x16F4, 0x38

glabel jtbl_8033619C
	.incbin "bin/rodata.bin", 0x172C, 0x18

glabel jtbl_803361B4
	.incbin "bin/rodata.bin", 0x1744, 0xEC

glabel jtbl_803362A0
	.incbin "bin/rodata.bin", 0x1830, 0x228

glabel jtbl_803364C8
	.incbin "bin/rodata.bin", 0x1A58, 0xD0

glabel jtbl_80336598
	.incbin "bin/rodata.bin", 0x1B28, 0x48

glabel jtbl_803365E0
	.incbin "bin/rodata.bin", 0x1B70, 0x30

glabel D_80336610
	.incbin "bin/rodata.bin", 0x1BA0, 0x84

glabel jtbl_80336694
	.incbin "bin/rodata.bin", 0x1C24, 0x1C

glabel D_803366B0
	.incbin "bin/rodata.bin", 0x1C40, 0x4

glabel D_803366B4
	.incbin "bin/rodata.bin", 0x1C44, 0x8

glabel D_803366BC
	.incbin "bin/rodata.bin", 0x1C4C, 0x8

glabel D_803366C4
	.incbin "bin/rodata.bin", 0x1C54, 0x4

glabel D_803366C8
	.incbin "bin/rodata.bin", 0x1C58, 0x8

glabel D_803366D0
	.incbin "bin/rodata.bin", 0x1C60, 0x8

glabel D_803366D8
	.incbin "bin/rodata.bin", 0x1C68, 0xC

glabel D_803366E4
	.incbin "bin/rodata.bin", 0x1C74, 0xC

glabel D_803366F0
	.incbin "bin/rodata.bin", 0x1C80, 0xC

glabel D_803366FC
	.incbin "bin/rodata.bin", 0x1C8C, 0x8

glabel D_80336704
	.incbin "bin/rodata.bin", 0x1C94, 0x8

glabel D_8033670C
	.incbin "bin/rodata.bin", 0x1C9C, 0x8

glabel jtbl_80336714
	.incbin "bin/rodata.bin", 0x1CA4, 0x50

glabel jtbl_80336764
	.incbin "bin/rodata.bin", 0x1CF4, 0x70

glabel jtbl_803367D4
	.incbin "bin/rodata.bin", 0x1D64, 0x40

glabel jtbl_80336814
	.incbin "bin/rodata.bin", 0x1DA4, 0x44

glabel jtbl_80336858
	.incbin "bin/rodata.bin", 0x1DE8, 0x48

glabel jtbl_803368A0
	.incbin "bin/rodata.bin", 0x1E30, 0x14

glabel jtbl_803368B4
	.incbin "bin/rodata.bin", 0x1E44, 0x44

glabel jtbl_803368F8
	.incbin "bin/rodata.bin", 0x1E88, 0x70

glabel jtbl_80336968
	.incbin "bin/rodata.bin", 0x1EF8, 0x44

glabel jtbl_803369AC
	.incbin "bin/rodata.bin", 0x1F3C, 0x44

glabel jtbl_803369F0
	.incbin "bin/rodata.bin", 0x1F80, 0x14

glabel jtbl_80336A04
	.incbin "bin/rodata.bin", 0x1F94, 0x6C

glabel jtbl_80336A70
	.incbin "bin/rodata.bin", 0x2000, 0x24

glabel jtbl_80336A94
	.incbin "bin/rodata.bin", 0x2024, 0x3C

glabel jtbl_80336AD0
	.incbin "bin/rodata.bin", 0x2060, 0x128

glabel jtbl_80336BF8
	.incbin "bin/rodata.bin", 0x2188, 0x14

glabel jtbl_80336C0C
	.incbin "bin/rodata.bin", 0x219C, 0x44

glabel D_80336C50
	.incbin "bin/rodata.bin", 0x21E0, 0xB8

glabel D_80336D08
	.incbin "bin/rodata.bin", 0x2298, 0xC

glabel D_80336D14
	.incbin "bin/rodata.bin", 0x22A4, 0x8

glabel D_80336D1C
	.incbin "bin/rodata.bin", 0x22AC, 0x8

glabel D_80336D24
	.incbin "bin/rodata.bin", 0x22B4, 0x8

glabel D_80336D2C
	.incbin "bin/rodata.bin", 0x22BC, 0x8

glabel D_80336D34
	.incbin "bin/rodata.bin", 0x22C4, 0x8

glabel D_80336D3C
	.incbin "bin/rodata.bin", 0x22CC, 0x8

glabel D_80336D44
	.incbin "bin/rodata.bin", 0x22D4, 0x8

glabel D_80336D4C
	.incbin "bin/rodata.bin", 0x22DC, 0xC

glabel D_80336D58
	.incbin "bin/rodata.bin", 0x22E8, 0xC

glabel D_80336D64
	.incbin "bin/rodata.bin", 0x22F4, 0xC

glabel D_80336D70
	.incbin "bin/rodata.bin", 0x2300, 0xC

glabel D_80336D7C
	.incbin "bin/rodata.bin", 0x230C, 0xC

glabel D_80336D88
	.incbin "bin/rodata.bin", 0x2318, 0xC

glabel D_80336D94
	.incbin "bin/rodata.bin", 0x2324, 0x10

glabel D_80336DA4
	.incbin "bin/rodata.bin", 0x2334, 0xC

glabel D_80336DB0
	.incbin "bin/rodata.bin", 0x2340, 0xC

glabel D_80336DBC
	.incbin "bin/rodata.bin", 0x234C, 0x8

glabel D_80336DC4
	.incbin "bin/rodata.bin", 0x2354, 0xC

glabel D_80336DD0
	.incbin "bin/rodata.bin", 0x2360, 0xC

glabel D_80336DDC
	.incbin "bin/rodata.bin", 0x236C, 0xC

glabel D_80336DE8
	.incbin "bin/rodata.bin", 0x2378, 0xC

glabel D_80336DF4
	.incbin "bin/rodata.bin", 0x2384, 0xC

glabel D_80336E00
	.incbin "bin/rodata.bin", 0x2390, 0xC

glabel D_80336E0C
	.incbin "bin/rodata.bin", 0x239C, 0xC

glabel D_80336E18
	.incbin "bin/rodata.bin", 0x23A8, 0xC

glabel D_80336E24
	.incbin "bin/rodata.bin", 0x23B4, 0xC

glabel D_80336E30
	.incbin "bin/rodata.bin", 0x23C0, 0xC

glabel D_80336E3C
	.incbin "bin/rodata.bin", 0x23CC, 0x34

glabel jtbl_80336E70
	.incbin "bin/rodata.bin", 0x2400, 0xF8

glabel jtbl_80336F68
	.incbin "bin/rodata.bin", 0x24F8, 0xB0

glabel jtbl_80337018
	.incbin "bin/rodata.bin", 0x25A8, 0xDC

glabel jtbl_803370F4
	.incbin "bin/rodata.bin", 0x2684, 0x3C

glabel jtbl_80337130
	.incbin "bin/rodata.bin", 0x26C0, 0x58

glabel jtbl_80337188
	.incbin "bin/rodata.bin", 0x2718, 0x18

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
	.incbin "bin/rodata.bin", 0x276C, 0xD8

glabel jtbl_803372B4
	.incbin "bin/rodata.bin", 0x2844, 0x14

glabel jtbl_803372C8
	.incbin "bin/rodata.bin", 0x2858, 0x70

glabel jtbl_80337338
	.incbin "bin/rodata.bin", 0x28C8, 0x84

glabel jtbl_803373BC
	.incbin "bin/rodata.bin", 0x294C, 0x9C

glabel jtbl_80337458
	.incbin "bin/rodata.bin", 0x29E8, 0x14

glabel jtbl_8033746C
	.incbin "bin/rodata.bin", 0x29FC, 0x18

glabel jtbl_80337484
	.incbin "bin/rodata.bin", 0x2A14, 0x1C

glabel jtbl_803374A0
	.incbin "bin/rodata.bin", 0x2A30, 0x68

glabel jtbl_80337508
	.incbin "bin/rodata.bin", 0x2A98, 0x2C

glabel jtbl_80337534
	.incbin "bin/rodata.bin", 0x2AC4, 0x2C

glabel jtbl_80337560
	.incbin "bin/rodata.bin", 0x2AF0, 0xF8

glabel jtbl_80337658
	.incbin "bin/rodata.bin", 0x2BE8, 0x100

glabel jtbl_80337758
	.incbin "bin/rodata.bin", 0x2CE8, 0x38

glabel jtbl_80337790
	.incbin "bin/rodata.bin", 0x2D20, 0x38

glabel jtbl_803377C8
	.incbin "bin/rodata.bin", 0x2D58, 0x78

glabel jtbl_80337840
	.incbin "bin/rodata.bin", 0x2DD0, 0x74

glabel jtbl_803378B4
	.incbin "bin/rodata.bin", 0x2E44, 0x28

glabel jtbl_803378DC
	.incbin "bin/rodata.bin", 0x2E6C, 0x70

glabel jtbl_8033794C
	.incbin "bin/rodata.bin", 0x2EDC, 0x30

glabel jtbl_8033797C
	.incbin "bin/rodata.bin", 0x2F0C, 0x5C

glabel jtbl_803379D8
	.incbin "bin/rodata.bin", 0x2F68, 0x40

glabel jtbl_80337A18
	.incbin "bin/rodata.bin", 0x2FA8, 0x34

glabel jtbl_80337A4C
	.incbin "bin/rodata.bin", 0x2FDC, 0x44

glabel jtbl_80337A90
	.incbin "bin/rodata.bin", 0x3020, 0x24

glabel jtbl_80337AB4
	.incbin "bin/rodata.bin", 0x3044, 0x54

glabel jtbl_80337B08
	.incbin "bin/rodata.bin", 0x3098, 0x40

glabel jtbl_80337B48
	.incbin "bin/rodata.bin", 0x30D8, 0x98

glabel jtbl_80337BE0
	.incbin "bin/rodata.bin", 0x3170, 0x80

glabel jtbl_80337C60
	.incbin "bin/rodata.bin", 0x31F0, 0x30

glabel jtbl_80337C90
	.incbin "bin/rodata.bin", 0x3220, 0x24

glabel jtbl_80337CB4
	.incbin "bin/rodata.bin", 0x3244, 0x150

glabel jtbl_80337E04
	.incbin "bin/rodata.bin", 0x3394, 0x2CC

glabel jtbl_803380D0
	.incbin "bin/rodata.bin", 0x3660, 0xE0

glabel jtbl_803381B0
	.incbin "bin/rodata.bin", 0x3740, 0x204

glabel jtbl_803383B4
	.incbin "bin/rodata.bin", 0x3944, 0x28

glabel jtbl_803383DC
	.incbin "bin/rodata.bin", 0x396C, 0x3C

glabel jtbl_80338418
	.incbin "bin/rodata.bin", 0x39A8, 0x38

glabel D_80338450
	.incbin "bin/rodata.bin", 0x39E0, 0x8

glabel D_80338458
	.incbin "bin/rodata.bin", 0x39E8, 0x8

glabel D_80338460
	.incbin "bin/rodata.bin", 0x39F0, 0x50

glabel D_803384B0
	.incbin "bin/rodata.bin", 0x3A40, 0x60

glabel D_80338510
	.incbin "bin/rodata.bin", 0x3AA0, 0x4

glabel D_80338514
	.incbin "bin/rodata.bin", 0x3AA4, 0x20

glabel jtbl_80338534
	.incbin "bin/rodata.bin", 0x3AC4, 0x184

glabel D_803386B8
	.incbin "bin/rodata.bin", 0x3C48, 0x4

glabel D_803386BC
	.incbin "bin/rodata.bin", 0x3C4C, 0x4

glabel D_803386C0
	.incbin "bin/rodata.bin", 0x3C50, 0x10

glabel D_803386D0
	.incbin "bin/rodata.bin", 0x3C60, 0x80

glabel D_80338750
	.incbin "bin/rodata.bin", 0x3CE0, 0x800

glabel D_80338F50
	.incbin "bin/rodata.bin", 0x44E0, 0x2C0

# 0x80339210
