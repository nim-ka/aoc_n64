.include "macros.inc"
.include "globals.inc"

.section .rodata

# 0x80334A70

# Unknown region 0EFA50-0F4210 [47C0]

glabel CreditsList
	.incbin "bin/rodata.bin", 0x20, 0x3BC

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
	.incbin "bin/rodata.bin", 0x6E8, 0x118

glabel D_80335270
	.incbin "bin/rodata.bin", 0x800, 0x4

glabel D_80335274
	.incbin "bin/rodata.bin", 0x804, 0x4

glabel D_80335278
	.incbin "bin/rodata.bin", 0x808, 0x8

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
	.incbin "bin/rodata.bin", 0x8FC, 0x94

glabel D_80335400
	.incbin "bin/rodata.bin", 0x990, 0x4

glabel D_80335404
	.incbin "bin/rodata.bin", 0x994, 0x4

glabel D_80335408
	.incbin "bin/rodata.bin", 0x998, 0x8

glabel D_80335410
	.incbin "bin/rodata.bin", 0x9A0, 0x4

glabel D_80335414
	.incbin "bin/rodata.bin", 0x9A4, 0x4

glabel D_80335418
	.incbin "bin/rodata.bin", 0x9A8, 0x4

glabel D_8033541C
	.incbin "bin/rodata.bin", 0x9AC, 0x4

glabel D_80335420
	.incbin "bin/rodata.bin", 0x9B0, 0x4

glabel D_80335424
	.incbin "bin/rodata.bin", 0x9B4, 0x4

glabel D_80335428
	.incbin "bin/rodata.bin", 0x9B8, 0x4

glabel D_8033542C
	.incbin "bin/rodata.bin", 0x9BC, 0x4

glabel D_80335430
	.incbin "bin/rodata.bin", 0x9C0, 0x4

glabel jtbl_80335434
	.incbin "bin/rodata.bin", 0x9C4, 0x84

glabel D_803354B8
	.incbin "bin/rodata.bin", 0xA48, 0x4

glabel D_803354BC
	.incbin "bin/rodata.bin", 0xA4C, 0x4

glabel D_803354C0
	.incbin "bin/rodata.bin", 0xA50, 0x4

glabel D_803354C4
	.incbin "bin/rodata.bin", 0xA54, 0x4

glabel D_803354C8
	.incbin "bin/rodata.bin", 0xA58, 0x8

glabel D_803354D0
	.incbin "bin/rodata.bin", 0xA60, 0x4

glabel D_803354D4
	.incbin "bin/rodata.bin", 0xA64, 0x4

glabel jtbl_803354D8
	.incbin "bin/rodata.bin", 0xA68, 0x34

glabel D_8033550C
	.incbin "bin/rodata.bin", 0xA9C, 0x4

glabel D_80335510
	.incbin "bin/rodata.bin", 0xAA0, 0x8

glabel D_80335518
	.incbin "bin/rodata.bin", 0xAA8, 0x8

glabel D_80335520
	.incbin "bin/rodata.bin", 0xAB0, 0x10

glabel D_80335530
	.incbin "bin/rodata.bin", 0xAC0, 0x1C

glabel jtbl_8033554C
	.incbin "bin/rodata.bin", 0xADC, 0x1C

glabel D_80335568
	.incbin "bin/rodata.bin", 0xAF8, 0x4

glabel D_8033556C
	.incbin "bin/rodata.bin", 0xAFC, 0x4

glabel D_80335570
	.incbin "bin/rodata.bin", 0xB00, 0x4

glabel D_80335574
	.incbin "bin/rodata.bin", 0xB04, 0x4

glabel D_80335578
	.incbin "bin/rodata.bin", 0xB08, 0x4

glabel D_8033557C
	.incbin "bin/rodata.bin", 0xB0C, 0x4

glabel jtbl_80335580
	.incbin "bin/rodata.bin", 0xB10, 0x34

glabel jtbl_803355B4
	.incbin "bin/rodata.bin", 0xB44, 0x1C

glabel jtbl_803355D0
	.incbin "bin/rodata.bin", 0xB60, 0x14

glabel jtbl_803355E4
	.incbin "bin/rodata.bin", 0xB74, 0xC4

glabel jtbl_803356A8
	.incbin "bin/rodata.bin", 0xC38, 0xF8

glabel D_803357A0
	.incbin "bin/rodata.bin", 0xD30, 0x4

glabel D_803357A4
	.incbin "bin/rodata.bin", 0xD34, 0xC

glabel jtbl_803357B0
	.incbin "bin/rodata.bin", 0xD40, 0x20

glabel D_803357D0
	.incbin "bin/rodata.bin", 0xD60, 0x4

glabel D_803357D4
	.incbin "bin/rodata.bin", 0xD64, 0x4

glabel jtbl_803357D8
	.incbin "bin/rodata.bin", 0xD68, 0x2C

glabel jtbl_80335804
	.incbin "bin/rodata.bin", 0xD94, 0x14

glabel jtbl_80335818
	.incbin "bin/rodata.bin", 0xDA8, 0x60

glabel jtbl_80335878
	.incbin "bin/rodata.bin", 0xE08, 0x68

glabel D_803358E0
	.incbin "bin/rodata.bin", 0xE70, 0x4

glabel D_803358E4
	.incbin "bin/rodata.bin", 0xE74, 0x4

glabel D_803358E8
	.incbin "bin/rodata.bin", 0xE78, 0x4

glabel D_803358EC
	.incbin "bin/rodata.bin", 0xE7C, 0x4

glabel D_803358F0
	.incbin "bin/rodata.bin", 0xE80, 0x4

glabel D_803358F4
	.incbin "bin/rodata.bin", 0xE84, 0x4

glabel D_803358F8
	.incbin "bin/rodata.bin", 0xE88, 0x4

glabel D_803358FC
	.incbin "bin/rodata.bin", 0xE8C, 0xC

glabel D_80335908
	.incbin "bin/rodata.bin", 0xE98, 0x4

glabel D_8033590C
	.incbin "bin/rodata.bin", 0xE9C, 0x8

glabel D_80335914
	.incbin "bin/rodata.bin", 0xEA4, 0x4

glabel D_80335918
	.incbin "bin/rodata.bin", 0xEA8, 0x4

glabel D_8033591C
	.incbin "bin/rodata.bin", 0xEAC, 0xC

glabel D_80335928
	.incbin "bin/rodata.bin", 0xEB8, 0x4

glabel D_8033592C
	.incbin "bin/rodata.bin", 0xEBC, 0x4

glabel D_80335930
	.incbin "bin/rodata.bin", 0xEC0, 0x4

glabel D_80335934
	.incbin "bin/rodata.bin", 0xEC4, 0x4

glabel D_80335938
	.incbin "bin/rodata.bin", 0xEC8, 0x4

glabel D_8033593C
	.incbin "bin/rodata.bin", 0xECC, 0x4

glabel D_80335940
	.incbin "bin/rodata.bin", 0xED0, 0x4

glabel D_80335944
	.incbin "bin/rodata.bin", 0xED4, 0x4

glabel D_80335948
	.incbin "bin/rodata.bin", 0xED8, 0x4

glabel D_8033594C
	.incbin "bin/rodata.bin", 0xEDC, 0x4

glabel D_80335950
	.incbin "bin/rodata.bin", 0xEE0, 0x10

glabel D_80335960
	.incbin "bin/rodata.bin", 0xEF0, 0x4

glabel D_80335964
	.incbin "bin/rodata.bin", 0xEF4, 0x4

glabel D_80335968
	.incbin "bin/rodata.bin", 0xEF8, 0x4

glabel jtbl_8033596C
	.incbin "bin/rodata.bin", 0xEFC, 0x2C

glabel jtbl_80335998
	.incbin "bin/rodata.bin", 0xF28, 0x7C

glabel jtbl_80335A14
	.incbin "bin/rodata.bin", 0xFA4, 0x18

glabel jtbl_80335A2C
	.incbin "bin/rodata.bin", 0xFBC, 0x34
