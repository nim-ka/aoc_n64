.include "macros.inc"


.section .rodata

#level functions
glabel D_80336610
	.incbin "bin/rodata.bin", 0x1BA0, 0xC

glabel D_8033661C
	.incbin "bin/rodata.bin", 0x1BAC, 0x4

glabel D_80336620
	.incbin "bin/rodata.bin", 0x1BB0, 0x4

glabel D_80336624
	.incbin "bin/rodata.bin", 0x1BB4, 0x4

glabel D_80336628
	.incbin "bin/rodata.bin", 0x1BB8, 0x4

glabel D_8033662C
	.incbin "bin/rodata.bin", 0x1BBC, 0x4

glabel D_80336630
	.incbin "bin/rodata.bin", 0x1BC0, 0x8

glabel D_80336638
	.incbin "bin/rodata.bin", 0x1BC8, 0x8

glabel D_80336640
	.incbin "bin/rodata.bin", 0x1BD0, 0x8

glabel D_80336648
	.incbin "bin/rodata.bin", 0x1BD8, 0x8

glabel D_80336650
	.incbin "bin/rodata.bin", 0x1BE0, 0x4

glabel D_80336654
	.incbin "bin/rodata.bin", 0x1BE4, 0x4

glabel D_80336658
	.incbin "bin/rodata.bin", 0x1BE8, 0x8

glabel D_80336660
	.incbin "bin/rodata.bin", 0x1BF0, 0x8

glabel D_80336668
	.incbin "bin/rodata.bin", 0x1BF8, 0x8

glabel D_80336670
	.incbin "bin/rodata.bin", 0x1C00, 0x4

glabel D_80336674
	.incbin "bin/rodata.bin", 0x1C04, 0x4

glabel D_80336678
	.incbin "bin/rodata.bin", 0x1C08, 0x4

glabel D_8033667C
	.incbin "bin/rodata.bin", 0x1C0C, 0x4

glabel D_80336680
	.incbin "bin/rodata.bin", 0x1C10, 0x4

glabel D_80336684
	.incbin "bin/rodata.bin", 0x1C14, 0x4

glabel D_80336688
	.incbin "bin/rodata.bin", 0x1C18, 0x4

glabel D_8033668C
	.incbin "bin/rodata.bin", 0x1C1C, 0x4

glabel D_80336690
	.incbin "bin/rodata.bin", 0x1C20, 0x4

glabel jtbl_80336694
	.word L802A420C
	.word L802A4268
	.word L802A4298
	.word L802A42EC
	.word L802A4370

	# padding
	.word 0, 0

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
	.word L802A4E94
	.word L802A4EF8
	.word L802A4F80
	.word L802A4FB4
	.word L802A5034

glabel D_80336728
	.incbin "bin/rodata.bin", 0x1CB8, 0x8

glabel D_80336730
	.incbin "bin/rodata.bin", 0x1CC0, 0x8

glabel D_80336738
	.incbin "bin/rodata.bin", 0x1CC8, 0x8

glabel D_80336740
	.incbin "bin/rodata.bin", 0x1CD0, 0x8

glabel D_80336748
	.incbin "bin/rodata.bin", 0x1CD8, 0x8

glabel D_80336750
	.incbin "bin/rodata.bin", 0x1CE0, 0x4

glabel D_80336754
	.incbin "bin/rodata.bin", 0x1CE4, 0x4

glabel D_80336758
	.incbin "bin/rodata.bin", 0x1CE8, 0x4

glabel D_8033675C
	.incbin "bin/rodata.bin", 0x1CEC, 0x4

glabel D_80336760
	.incbin "bin/rodata.bin", 0x1CF0, 0x4

glabel jtbl_80336764
	.word L802A74D8
	.word L802A7594
	.word L802A7668
	.word L802A7694
	.word L802A76FC

glabel D_80336778
	.incbin "bin/rodata.bin", 0x1D08, 0x8

glabel D_80336780
	.incbin "bin/rodata.bin", 0x1D10, 0x8
glabel D_80336788
	.incbin "bin/rodata.bin", 0x1D18, 0x8
glabel D_80336790
	.incbin "bin/rodata.bin", 0x1D20, 0x8
glabel D_80336798
	.incbin "bin/rodata.bin", 0x1D28, 0x8

glabel D_803367A0
	.incbin "bin/rodata.bin", 0x1D30, 0x4

glabel D_803367A4
	.incbin "bin/rodata.bin", 0x1D34, 0x4
glabel D_803367A8
	.incbin "bin/rodata.bin", 0x1D38, 0x4
glabel D_803367AC
	.incbin "bin/rodata.bin", 0x1D3C, 0x4

glabel D_803367B0
	.incbin "bin/rodata.bin", 0x1D40, 0x8
glabel D_803367B8
	.incbin "bin/rodata.bin", 0x1D48, 0x8

glabel D_803367C0
	.incbin "bin/rodata.bin", 0x1D50, 0x8

glabel D_803367C8
	.incbin "bin/rodata.bin", 0x1D58, 0x8

glabel D_803367D0
	.incbin "bin/rodata.bin", 0x1D60, 0x4

glabel jtbl_803367D4
	.word L802AB3D0
	.word L802AB408
	.word L802AB458
	.word L802AB4E8
	.word L802AB580

glabel D_803367E8
	.incbin "bin/rodata.bin", 0x1D78, 0x8

glabel D_803367F0
	.incbin "bin/rodata.bin", 0x1D80, 0x4

glabel D_803367F4
	.incbin "bin/rodata.bin", 0x1D84, 0x4

glabel D_803367F8
	.incbin "bin/rodata.bin", 0x1D88, 0x4

glabel D_803367FC
	.incbin "bin/rodata.bin", 0x1D8C, 0x4

glabel D_80336800
	.incbin "bin/rodata.bin", 0x1D90, 0x4

glabel D_80336804
	.incbin "bin/rodata.bin", 0x1D94, 0x4

glabel D_80336808
	.incbin "bin/rodata.bin", 0x1D98, 0x4

glabel D_8033680C
	.incbin "bin/rodata.bin", 0x1D9C, 0x4

glabel D_80336810
	.incbin "bin/rodata.bin", 0x1DA0, 0x4

glabel jtbl_80336814
	.word L802AC2F0
	.word L802AC300
	.word L802AC318
	.word L802AC330
	.word L802AC348

glabel D_80336828
	.incbin "bin/rodata.bin", 0x1DB8, 0x8

glabel D_80336830
	.incbin "bin/rodata.bin", 0x1DC0, 0x8

glabel D_80336838
	.incbin "bin/rodata.bin", 0x1DC8, 0x8

glabel D_80336840
	.incbin "bin/rodata.bin", 0x1DD0, 0x8
glabel D_80336848
	.incbin "bin/rodata.bin", 0x1DD8, 0x8
glabel D_80336850
	.incbin "bin/rodata.bin", 0x1DE0, 0x8

glabel jtbl_80336858
	.word L802AE594
	.word L802AE594
	.word L802AE594
	.word L802AE594
	.word L802AE594
	.word L802AE594
	.word L802AE594
	.word L802AE594
	.word L802AE5C8
	.word L802AE5D0

glabel D_80336880
	.incbin "bin/rodata.bin", 0x1E10, 0x8

glabel D_80336888
	.incbin "bin/rodata.bin", 0x1E18, 0x8

glabel D_80336890
	.incbin "bin/rodata.bin", 0x1E20, 0x8

glabel D_80336898
	.incbin "bin/rodata.bin", 0x1E28, 0x8

glabel jtbl_803368A0
	.word L802B039C
	.word L802B03BC
	.word L802B03EC
	.word L802B041C
	.word L802B044C

glabel jtbl_803368B4
	.word L802B0A10
	.word L802B0AA4
	.word L802B0B00
	.word L802B0BD0
	.word L802B0C14

glabel D_803368C8
	.incbin "bin/rodata.bin", 0x1E58, 0x8

glabel D_803368D0
	.incbin "bin/rodata.bin", 0x1E60, 0x8

glabel D_803368D8
	.incbin "bin/rodata.bin", 0x1E68, 0x4

glabel D_803368DC
	.incbin "bin/rodata.bin", 0x1E6C, 0x4

glabel D_803368E0
	.incbin "bin/rodata.bin", 0x1E70, 0x4

glabel D_803368E4
	.incbin "bin/rodata.bin", 0x1E74, 0x4

glabel D_803368E8
	.incbin "bin/rodata.bin", 0x1E78, 0x4

glabel D_803368EC
	.incbin "bin/rodata.bin", 0x1E7C, 0x4

glabel D_803368F0
	.incbin "bin/rodata.bin", 0x1E80, 0x8

glabel jtbl_803368F8
	.word L802B2164
	.word L802B21EC
	.word L802B2284
	.word L802B22D4
	.word L802B2308

glabel D_8033690C
	.incbin "bin/rodata.bin", 0x1E9C, 0x4

glabel D_80336910
	.incbin "bin/rodata.bin", 0x1EA0, 0x8

glabel D_80336918
	.incbin "bin/rodata.bin", 0x1EA8, 0x8
glabel D_80336920	
	.incbin "bin/rodata.bin", 0x1EB0, 0x4
glabel D_80336924
	.incbin "bin/rodata.bin", 0x1EB4, 0x4
glabel D_80336928
	.incbin "bin/rodata.bin", 0x1EB8, 0x8
glabel D_80336930
	.incbin "bin/rodata.bin", 0x1EC0, 0x8

glabel D_80336938
	.incbin "bin/rodata.bin", 0x1EC8, 0x4

glabel D_8033693C
	.incbin "bin/rodata.bin", 0x1ECC, 0x4

glabel D_80336940
	.incbin "bin/rodata.bin", 0x1ED0, 0x8
glabel D_80336948
	.incbin "bin/rodata.bin", 0x1ED8, 0x8
glabel D_80336950
	.incbin "bin/rodata.bin", 0x1EE0, 0x8
glabel D_80336958
	.incbin "bin/rodata.bin", 0x1EE8, 0x8
glabel D_80336960
	.incbin "bin/rodata.bin", 0x1EF0, 0x8

glabel jtbl_80336968
	.word L802B63D0
	.word L802B63E0
	.word L802B63F0
	.word L802B6468
	.word L802B6494
	.word L802B64D0
	.word L802B64D0
	.word L802B64D0
	.word L802B64D0
	.word L802B64D0
	.word L802B649C
	.word L802B64C8

glabel D_80336998
	.incbin "bin/rodata.bin", 0x1F28, 0x8

glabel D_803369A0
	.incbin "bin/rodata.bin", 0x1F30, 0x8

glabel D_803369A8
	.incbin "bin/rodata.bin", 0x1F38, 0x4

glabel jtbl_803369AC
	.word L802B7120
	.word L802B7190
	.word L802B71B8
	.word L802B7268
	.word L802B72A8
	.word L802B7204
	.word L802B7244
	.word L802B72CC
	.word L802B72CC
	.word L802B71E0

glabel D_803369D4
	.incbin "bin/rodata.bin", 0x1F64, 0x4

glabel D_803369D8
	.incbin "bin/rodata.bin", 0x1F68, 0x8
glabel D_803369E0
	.incbin "bin/rodata.bin", 0x1F70, 0x8
glabel D_803369E8
	.incbin "bin/rodata.bin", 0x1F78, 0x8

glabel jtbl_803369F0
	.word L802B9308
	.word L802B9348
	.word L802B9368
	.word L802B937C
	.word L802B939C

glabel jtbl_80336A04
	.word L802B95DC
	.word L802B9610
	.word L802B9664
	.word L802B96B0
	.word L802B970C
	.word L802B97C4

glabel D_80336A1C
	.incbin "bin/rodata.bin", 0x1FAC, 0x4
glabel D_80336A20
	.incbin "bin/rodata.bin", 0x1FB0, 0x4

glabel D_80336A24
	.incbin "bin/rodata.bin", 0x1FB4, 0x4

glabel D_80336A28
	.incbin "bin/rodata.bin", 0x1FB8, 0x8

glabel D_80336A30
	.incbin "bin/rodata.bin", 0x1FC0, 0x8

glabel D_80336A38
	.incbin "bin/rodata.bin", 0x1FC8, 0x4

glabel D_80336A3C
	.incbin "bin/rodata.bin", 0x1FCC, 0x4

glabel D_80336A40
	.incbin "bin/rodata.bin", 0x1FD0, 0x4

glabel D_80336A44
	.incbin "bin/rodata.bin", 0x1FD4, 0x4

glabel D_80336A48
	.incbin "bin/rodata.bin", 0x1FD8, 0x8

glabel D_80336A50
	.incbin "bin/rodata.bin", 0x1FE0, 0x4

glabel D_80336A54
	.incbin "bin/rodata.bin", 0x1FE4, 0x4

glabel D_80336A58
	.incbin "bin/rodata.bin", 0x1FE8, 0x8

glabel D_80336A60
	.incbin "bin/rodata.bin", 0x1FF0, 0x4

glabel D_80336A64
	.incbin "bin/rodata.bin", 0x1FF4, 0x4

glabel D_80336A68
	.incbin "bin/rodata.bin", 0x1FF8, 0x4

glabel D_80336A6C
	.incbin "bin/rodata.bin", 0x1FFC, 0x4

glabel jtbl_80336A70
	.word L802BAB10
	.word L802BABB0
	.word L802BAC0C
	.word L802BAC4C
	.word L802BAC9C
	.word L802BACE0
	.word L802BAD88
	.word L802BADF0

glabel D_80336A90
	.incbin "bin/rodata.bin", 0x2020, 0x4

glabel jtbl_80336A94
	.word L802BB11C
	.word L802BB228
	.word L802BB228
	.word L802BB1A4
	.word L802BB1AC
	.word L802BB208
	.word L802BB228
	.word L802BB15C

glabel D_80336AB4
	.incbin "bin/rodata.bin", 0x2044, 0x4

glabel D_80336AB8
	.incbin "bin/rodata.bin", 0x2048, 0x4

glabel D_80336ABC
	.incbin "bin/rodata.bin", 0x204C, 0x4

glabel D_80336AC0
	.incbin "bin/rodata.bin", 0x2050, 0x4
glabel D_80336AC4
	.incbin "bin/rodata.bin", 0x2054, 0x4

glabel D_80336AC8
	.incbin "bin/rodata.bin", 0x2058, 0x8

glabel jtbl_80336AD0
	.word L802BC184
	.word L802BC1CC
	.word L802BC24C
	.word L802BC2C4
	.word L802BC338

glabel D_80336AE4
	.incbin "bin/rodata.bin", 0x2074, 0x4

glabel D_80336AE8
	.incbin "bin/rodata.bin", 0x2078, 0x8

glabel D_80336AF0
	.incbin "bin/rodata.bin", 0x2080, 0x8

glabel D_80336AF8
	.incbin "bin/rodata.bin", 0x2088, 0x8

glabel D_80336B00
	.incbin "bin/rodata.bin", 0x2090, 0x8

glabel D_80336B08
	.incbin "bin/rodata.bin", 0x2098, 0x8

glabel D_80336B10
	.incbin "bin/rodata.bin", 0x20A0, 0x8

glabel D_80336B18
	.incbin "bin/rodata.bin", 0x20A8, 0x4

glabel D_80336B1C
	.incbin "bin/rodata.bin", 0x20AC, 0x4

glabel D_80336B20
	.incbin "bin/rodata.bin", 0x20B0, 0x4

glabel D_80336B24
	.incbin "bin/rodata.bin", 0x20B4, 0x4

glabel D_80336B28
	.incbin "bin/rodata.bin", 0x20B8, 0x4

glabel D_80336B2C
	.incbin "bin/rodata.bin", 0x20BC, 0x4

glabel D_80336B30
	.incbin "bin/rodata.bin", 0x20C0, 0x4

glabel D_80336B34
	.incbin "bin/rodata.bin", 0x20C4, 0x4

glabel D_80336B38
	.incbin "bin/rodata.bin", 0x20C8, 0x8

glabel D_80336B40
	.incbin "bin/rodata.bin", 0x20D0, 0x8

glabel D_80336B48
	.incbin "bin/rodata.bin", 0x20D8, 0x8

glabel D_80336B50
	.incbin "bin/rodata.bin", 0x20E0, 0x4

glabel D_80336B54
	.incbin "bin/rodata.bin", 0x20E4, 0x4

glabel D_80336B58
	.incbin "bin/rodata.bin", 0x20E8, 0x8

glabel D_80336B60
	.incbin "bin/rodata.bin", 0x20F0, 0x4

glabel D_80336B64
	.incbin "bin/rodata.bin", 0x20F4, 0x4

glabel D_80336B68
	.incbin "bin/rodata.bin", 0x20F8, 0x8

glabel D_80336B70
	.incbin "bin/rodata.bin", 0x2100, 0x8

glabel D_80336B78
	.incbin "bin/rodata.bin", 0x2108, 0x8

glabel D_80336B80
	.incbin "bin/rodata.bin", 0x2110, 0x8

glabel D_80336B88
	.incbin "bin/rodata.bin", 0x2118, 0x8

glabel D_80336B90
	.incbin "bin/rodata.bin", 0x2120, 0x8

glabel D_80336B98
	.incbin "bin/rodata.bin", 0x2128, 0x4

glabel D_80336B9C
	.incbin "bin/rodata.bin", 0x212C, 0x4

glabel D_80336BA0
	.incbin "bin/rodata.bin", 0x2130, 0x4

glabel D_80336BA4
	.incbin "bin/rodata.bin", 0x2134, 0x4

glabel D_80336BA8
	.incbin "bin/rodata.bin", 0x2138, 0x8

glabel D_80336BB0
	.incbin "bin/rodata.bin", 0x2140, 0x8

glabel D_80336BB8
	.incbin "bin/rodata.bin", 0x2148, 0x8

glabel D_80336BC0
	.incbin "bin/rodata.bin", 0x2150, 0x8

glabel D_80336BC8
	.incbin "bin/rodata.bin", 0x2158, 0x8

glabel D_80336BD0
	.incbin "bin/rodata.bin", 0x2160, 0x4

glabel D_80336BD4
	.incbin "bin/rodata.bin", 0x2164, 0x4

glabel D_80336BD8
	.incbin "bin/rodata.bin", 0x2168, 0x4

glabel D_80336BDC
	.incbin "bin/rodata.bin", 0x216C, 0x4

glabel D_80336BE0
	.incbin "bin/rodata.bin", 0x2170, 0x4

glabel D_80336BE4
	.incbin "bin/rodata.bin", 0x2174, 0x4

glabel D_80336BE8
	.incbin "bin/rodata.bin", 0x2178, 0x4

glabel D_80336BEC
	.incbin "bin/rodata.bin", 0x217C, 0x4

glabel D_80336BF0
	.incbin "bin/rodata.bin", 0x2180, 0x4

glabel D_80336BF4
	.incbin "bin/rodata.bin", 0x2184, 0x4

glabel jtbl_80336BF8
	.word L802C58AC
	.word L802C58BC
	.word L802C58CC
	.word L802C58DC
	.word L802C58EC

glabel jtbl_80336C0C
	.word L802C5B94
	.word L802C5C1C
	.word L802C5DB8
	.word L802C5E4C
	.word L802C5EBC
	.word L802C5F48

glabel D_80336C24
	.incbin "bin/rodata.bin", 0x21B4, 0x4

glabel D_80336C28
	.incbin "bin/rodata.bin", 0x21B8, 0x4

glabel D_80336C2C
	.incbin "bin/rodata.bin", 0x21BC, 0x4

glabel D_80336C30
	.incbin "bin/rodata.bin", 0x21C0, 0x4

glabel D_80336C34
	.incbin "bin/rodata.bin", 0x21C4, 0x4

glabel D_80336C38
	.incbin "bin/rodata.bin", 0x21C8, 0x8

glabel D_80336C40
	.incbin "bin/rodata.bin", 0x21D0, 0x8

glabel D_80336C48
	.incbin "bin/rodata.bin", 0x21D8, 0x4

glabel D_80336C4C
	.incbin "bin/rodata.bin", 0x21DC, 0x4

