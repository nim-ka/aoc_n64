.include "macros.inc"
.include "globals.inc"

.section .rodata

#level functions
glabel D_80336610
	.incbin "bin/rodata.bin", 0x1BA0, 0x10

glabel D_80336620
	.incbin "bin/rodata.bin", 0x1BB0, 0x4

glabel D_80336624
	.incbin "bin/rodata.bin", 0x1BB4, 0x4

glabel D_80336628
	.incbin "bin/rodata.bin", 0x1BB8, 0x4

glabel D_8033662C
	.incbin "bin/rodata.bin", 0x1BBC, 0x4

glabel D_80336630
	.incbin "bin/rodata.bin", 0x1BC0, 0x20

glabel D_80336650
	.incbin "bin/rodata.bin", 0x1BE0, 0x4

glabel D_80336654
	.incbin "bin/rodata.bin", 0x1BE4, 0xC

glabel D_80336660
	.incbin "bin/rodata.bin", 0x1BF0, 0x10

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
	.incbin "bin/rodata.bin", 0x1CA4, 0x2C

glabel D_80336740
	.incbin "bin/rodata.bin", 0x1CD0, 0x10

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
	.incbin "bin/rodata.bin", 0x1CF4, 0x14

glabel D_80336778
	.incbin "bin/rodata.bin", 0x1D08, 0x28

glabel D_803367A0
	.incbin "bin/rodata.bin", 0x1D30, 0x4

glabel D_803367A4
	.incbin "bin/rodata.bin", 0x1D34, 0x1C

glabel D_803367C0
	.incbin "bin/rodata.bin", 0x1D50, 0x10

glabel D_803367D0
	.incbin "bin/rodata.bin", 0x1D60, 0x4

glabel jtbl_803367D4
	.incbin "bin/rodata.bin", 0x1D64, 0x1C

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
	.incbin "bin/rodata.bin", 0x1DA4, 0x14

glabel D_80336828
	.incbin "bin/rodata.bin", 0x1DB8, 0x10

glabel D_80336838
	.incbin "bin/rodata.bin", 0x1DC8, 0x20

glabel jtbl_80336858
	.incbin "bin/rodata.bin", 0x1DE8, 0x30

glabel D_80336888
	.incbin "bin/rodata.bin", 0x1E18, 0x18

glabel jtbl_803368A0
	.incbin "bin/rodata.bin", 0x1E30, 0x14

glabel jtbl_803368B4
	.incbin "bin/rodata.bin", 0x1E44, 0x24

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
	.incbin "bin/rodata.bin", 0x1E7C, 0xC

glabel jtbl_803368F8
	.incbin "bin/rodata.bin", 0x1E88, 0x14

glabel D_8033690C
	.incbin "bin/rodata.bin", 0x1E9C, 0x4

glabel D_80336910
	.incbin "bin/rodata.bin", 0x1EA0, 0x28

glabel D_80336938
	.incbin "bin/rodata.bin", 0x1EC8, 0x4

glabel D_8033693C
	.incbin "bin/rodata.bin", 0x1ECC, 0x2C

glabel jtbl_80336968
	.incbin "bin/rodata.bin", 0x1EF8, 0x40

glabel D_803369A8
	.incbin "bin/rodata.bin", 0x1F38, 0x4

glabel jtbl_803369AC
	.incbin "bin/rodata.bin", 0x1F3C, 0x28

glabel D_803369D4
	.incbin "bin/rodata.bin", 0x1F64, 0x1C

glabel jtbl_803369F0
	.incbin "bin/rodata.bin", 0x1F80, 0x14

glabel jtbl_80336A04
	.incbin "bin/rodata.bin", 0x1F94, 0x20

glabel D_80336A24
	.incbin "bin/rodata.bin", 0x1FB4, 0x4

glabel D_80336A28
	.incbin "bin/rodata.bin", 0x1FB8, 0x10

glabel D_80336A38
	.incbin "bin/rodata.bin", 0x1FC8, 0x4

glabel D_80336A3C
	.incbin "bin/rodata.bin", 0x1FCC, 0x4

glabel D_80336A40
	.incbin "bin/rodata.bin", 0x1FD0, 0x4

glabel D_80336A44
	.incbin "bin/rodata.bin", 0x1FD4, 0xC

glabel D_80336A50
	.incbin "bin/rodata.bin", 0x1FE0, 0x4

glabel D_80336A54
	.incbin "bin/rodata.bin", 0x1FE4, 0xC

glabel D_80336A60
	.incbin "bin/rodata.bin", 0x1FF0, 0x4

glabel D_80336A64
	.incbin "bin/rodata.bin", 0x1FF4, 0x4

glabel D_80336A68
	.incbin "bin/rodata.bin", 0x1FF8, 0x4

glabel D_80336A6C
	.incbin "bin/rodata.bin", 0x1FFC, 0x4

glabel jtbl_80336A70
	.incbin "bin/rodata.bin", 0x2000, 0x20

glabel D_80336A90
	.incbin "bin/rodata.bin", 0x2020, 0x4

glabel jtbl_80336A94
	.incbin "bin/rodata.bin", 0x2024, 0x20

glabel D_80336AB4
	.incbin "bin/rodata.bin", 0x2044, 0x4

glabel D_80336AB8
	.incbin "bin/rodata.bin", 0x2048, 0x4

glabel D_80336ABC
	.incbin "bin/rodata.bin", 0x204C, 0x4

glabel D_80336AC0
	.incbin "bin/rodata.bin", 0x2050, 0x10

glabel jtbl_80336AD0
	.incbin "bin/rodata.bin", 0x2060, 0x14

glabel D_80336AE4
	.incbin "bin/rodata.bin", 0x2074, 0xC

glabel D_80336AF0
	.incbin "bin/rodata.bin", 0x2080, 0x18

glabel D_80336B08
	.incbin "bin/rodata.bin", 0x2098, 0x10

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
	.incbin "bin/rodata.bin", 0x20C4, 0x1C

glabel D_80336B50
	.incbin "bin/rodata.bin", 0x20E0, 0x4

glabel D_80336B54
	.incbin "bin/rodata.bin", 0x20E4, 0xC

glabel D_80336B60
	.incbin "bin/rodata.bin", 0x20F0, 0x4

glabel D_80336B64
	.incbin "bin/rodata.bin", 0x20F4, 0x4

glabel D_80336B68
	.incbin "bin/rodata.bin", 0x20F8, 0x10

glabel D_80336B78
	.incbin "bin/rodata.bin", 0x2108, 0x20

glabel D_80336B98
	.incbin "bin/rodata.bin", 0x2128, 0x4

glabel D_80336B9C
	.incbin "bin/rodata.bin", 0x212C, 0x4

glabel D_80336BA0
	.incbin "bin/rodata.bin", 0x2130, 0x4

glabel D_80336BA4
	.incbin "bin/rodata.bin", 0x2134, 0x4

glabel D_80336BA8
	.incbin "bin/rodata.bin", 0x2138, 0x28

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
	.incbin "bin/rodata.bin", 0x2188, 0x14

glabel jtbl_80336C0C
	.incbin "bin/rodata.bin", 0x219C, 0x18

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
	.incbin "bin/rodata.bin", 0x21C8, 0x10

glabel D_80336C48
	.incbin "bin/rodata.bin", 0x21D8, 0x4

glabel D_80336C4C
	.incbin "bin/rodata.bin", 0x21DC, 0x4
