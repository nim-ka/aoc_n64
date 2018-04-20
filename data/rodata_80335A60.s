.include "macros.inc"
.include "globals.inc"

.section .rodata

# 0x80335A60

glabel D_80335C70
    .incbin "bin/rodata.bin", 0x1200, 0x4

glabel jtbl_80335C74
    .incbin "bin/rodata.bin", 0x1204, 0x18
glabel jtbl_80335C8C
    .incbin "bin/rodata.bin", 0x121C, 0x18

glabel D_80335CA4
    .incbin "bin/rodata.bin", 0x1234, 0x4

glabel D_80335CA8
    .incbin "bin/rodata.bin", 0x1238, 0x4

glabel D_80335CAC
    .incbin "bin/rodata.bin", 0x123C, 0x4

glabel D_80335CB0
    .incbin "bin/rodata.bin", 0x1240, 0x4

glabel D_80335CB4
    .incbin "bin/rodata.bin", 0x1244, 0x8

glabel jtbl_80335CBC
    .incbin "bin/rodata.bin", 0x124C, 0x48

glabel jtbl_80335D04
    .incbin "bin/rodata.bin", 0x1294, 0x2C

glabel jtbl_80335D30
    .incbin "bin/rodata.bin", 0x12C0, 0x28

glabel jtbl_80335D58
    .incbin "bin/rodata.bin", 0x12E8, 0x48

glabel jtbl_80335DA0
    .incbin "bin/rodata.bin", 0x1330, 0x14

glabel D_80335DB4
    .incbin "bin/rodata.bin", 0x1344, 0x4

glabel D_80335DB8
    .incbin "bin/rodata.bin", 0x1348, 0x18

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
    .incbin "bin/rodata.bin", 0x143C, 0xCC

glabel D_80335F78
    .incbin "bin/rodata.bin", 0x1508, 0x4

glabel D_80335F7C
    .incbin "bin/rodata.bin", 0x150C, 0x4

glabel jtbl_80335F80
    .incbin "bin/rodata.bin", 0x1510, 0x28

glabel D_80335FA8
    .incbin "bin/rodata.bin", 0x1538, 0x4

glabel D_80335FAC
    .incbin "bin/rodata.bin", 0x153C, 0x4

glabel D_80335FB0
    .incbin "bin/rodata.bin", 0x1540, 0x4

glabel D_80335FB4
    .incbin "bin/rodata.bin", 0x1544, 0x4

glabel D_80335FB8
    .incbin "bin/rodata.bin", 0x1548, 0x4

glabel D_80335FBC
    .incbin "bin/rodata.bin", 0x154C, 0x4

glabel D_80335FC0
    .incbin "bin/rodata.bin", 0x1550, 0x4

glabel D_80335FC4
    .incbin "bin/rodata.bin", 0x1554, 0x4

glabel D_80335FC8
    .incbin "bin/rodata.bin", 0x1558, 0x4

glabel D_80335FCC
    .incbin "bin/rodata.bin", 0x155C, 0x4

glabel D_80335FD0
    .incbin "bin/rodata.bin", 0x1560, 0x4

glabel D_80335FD4
    .incbin "bin/rodata.bin", 0x1564, 0x4

glabel D_80335FD8
    .incbin "bin/rodata.bin", 0x1568, 0x4

glabel D_80335FDC
    .incbin "bin/rodata.bin", 0x156C, 0x4

glabel D_80335FE0
    .incbin "bin/rodata.bin", 0x1570, 0x4

glabel D_80335FE4
    .incbin "bin/rodata.bin", 0x1574, 0x4

glabel D_80335FE8
    .incbin "bin/rodata.bin", 0x1578, 0x8

glabel D_80335FF0
    .incbin "bin/rodata.bin", 0x1580, 0x4

glabel D_80335FF4
    .incbin "bin/rodata.bin", 0x1584, 0x4

glabel D_80335FF8
    .incbin "bin/rodata.bin", 0x1588, 0x4

glabel D_80335FFC
    .incbin "bin/rodata.bin", 0x158C, 0x4

glabel D_80336000
    .incbin "bin/rodata.bin", 0x1590, 0x4

glabel D_80336004
    .incbin "bin/rodata.bin", 0x1594, 0x4

glabel D_80336008
    .incbin "bin/rodata.bin", 0x1598, 0x4

glabel D_8033600C
    .incbin "bin/rodata.bin", 0x159C, 0x4

glabel D_80336010
    .incbin "bin/rodata.bin", 0x15A0, 0x4

glabel D_80336014
    .incbin "bin/rodata.bin", 0x15A4, 0x4

glabel D_80336018
    .incbin "bin/rodata.bin", 0x15A8, 0x4

glabel D_8033601C
    .incbin "bin/rodata.bin", 0x15AC, 0x4

glabel D_80336020
    .incbin "bin/rodata.bin", 0x15B0, 0x4

glabel D_80336024
    .incbin "bin/rodata.bin", 0x15B4, 0x4

glabel D_80336028
    .incbin "bin/rodata.bin", 0x15B8, 0x4

glabel D_8033602C
    .incbin "bin/rodata.bin", 0x15BC, 0x4

glabel D_80336030
    .incbin "bin/rodata.bin", 0x15C0, 0x4

glabel D_80336034
    .incbin "bin/rodata.bin", 0x15C4, 0x4

glabel D_80336038
    .incbin "bin/rodata.bin", 0x15C8, 0x4

glabel D_8033603C
    .incbin "bin/rodata.bin", 0x15CC, 0x4

glabel D_80336040
    .incbin "bin/rodata.bin", 0x15D0, 0x4

glabel D_80336044
    .incbin "bin/rodata.bin", 0x15D4, 0x4

glabel D_80336048
    .incbin "bin/rodata.bin", 0x15D8, 0x4

glabel D_8033604C
    .incbin "bin/rodata.bin", 0x15DC, 0x4

glabel D_80336050
    .incbin "bin/rodata.bin", 0x15E0, 0x4

glabel D_80336054
    .incbin "bin/rodata.bin", 0x15E4, 0x4

glabel D_80336058
    .incbin "bin/rodata.bin", 0x15E8, 0x4

glabel D_8033605C
    .incbin "bin/rodata.bin", 0x15EC, 0x4

glabel D_80336060
    .incbin "bin/rodata.bin", 0x15F0, 0x4

glabel D_80336064
    .incbin "bin/rodata.bin", 0x15F4, 0x4

glabel D_80336068
    .incbin "bin/rodata.bin", 0x15F8, 0x4

glabel D_8033606C
    .incbin "bin/rodata.bin", 0x15FC, 0x4

glabel D_80336070
    .incbin "bin/rodata.bin", 0x1600, 0x4

glabel D_80336074
    .incbin "bin/rodata.bin", 0x1604, 0x4

glabel jtbl_80336078
    .incbin "bin/rodata.bin", 0x1608, 0x44

glabel D_803360BC
    .incbin "bin/rodata.bin", 0x164C, 0x4

glabel D_803360C0
    .incbin "bin/rodata.bin", 0x1650, 0x4

glabel D_803360C4
    .incbin "bin/rodata.bin", 0x1654, 0x4

glabel D_803360C8
    .incbin "bin/rodata.bin", 0x1658, 0x4

glabel jtbl_803360CC
    .incbin "bin/rodata.bin", 0x165C, 0x74

glabel D_80336140
    .incbin "bin/rodata.bin", 0x16D0, 0x4

glabel D_80336144
    .incbin "bin/rodata.bin", 0x16D4, 0x4

glabel D_80336148
    .incbin "bin/rodata.bin", 0x16D8, 0x4

glabel D_8033614C
    .incbin "bin/rodata.bin", 0x16DC, 0x4

glabel D_80336150
    .incbin "bin/rodata.bin", 0x16E0, 0x8

glabel D_80336158
    .incbin "bin/rodata.bin", 0x16E8, 0x4

glabel D_8033615C
    .incbin "bin/rodata.bin", 0x16EC, 0x4

glabel D_80336160
    .incbin "bin/rodata.bin", 0x16F0, 0x4

glabel jtbl_80336164
    .incbin "bin/rodata.bin", 0x16F4, 0x18

glabel D_8033617C
    .incbin "bin/rodata.bin", 0x170C, 0x4

glabel D_80336180
    .incbin "bin/rodata.bin", 0x1710, 0x4

glabel D_80336184
    .incbin "bin/rodata.bin", 0x1714, 0x4

glabel D_80336188
    .incbin "bin/rodata.bin", 0x1718, 0x4

glabel D_8033618C
    .incbin "bin/rodata.bin", 0x171C, 0x4

glabel D_80336190
    .incbin "bin/rodata.bin", 0x1720, 0x4

glabel D_80336194
    .incbin "bin/rodata.bin", 0x1724, 0x4

glabel D_80336198
    .incbin "bin/rodata.bin", 0x1728, 0x4

glabel jtbl_8033619C
    .incbin "bin/rodata.bin", 0x172C, 0x18

glabel jtbl_803361B4
    .incbin "bin/rodata.bin", 0x1744, 0x14

glabel D_803361C8
    .incbin "bin/rodata.bin", 0x1758, 0x4

glabel D_803361CC
    .incbin "bin/rodata.bin", 0x175C, 0x4

glabel D_803361D0
    .incbin "bin/rodata.bin", 0x1760, 0x4

glabel D_803361D4
    .incbin "bin/rodata.bin", 0x1764, 0x4

glabel D_803361D8
    .incbin "bin/rodata.bin", 0x1768, 0x4

glabel D_803361DC
    .incbin "bin/rodata.bin", 0x176C, 0x4

glabel D_803361E0
    .incbin "bin/rodata.bin", 0x1770, 0x4

glabel D_803361E4
    .incbin "bin/rodata.bin", 0x1774, 0x4

glabel D_803361E8
    .incbin "bin/rodata.bin", 0x1778, 0x4

glabel D_803361EC
    .incbin "bin/rodata.bin", 0x177C, 0x4

glabel D_803361F0
    .incbin "bin/rodata.bin", 0x1780, 0x4

glabel D_803361F4
    .incbin "bin/rodata.bin", 0x1784, 0x4

glabel D_803361F8
    .incbin "bin/rodata.bin", 0x1788, 0x4

glabel D_803361FC
    .incbin "bin/rodata.bin", 0x178C, 0x4

glabel D_80336200
    .incbin "bin/rodata.bin", 0x1790, 0x4

glabel D_80336204
    .incbin "bin/rodata.bin", 0x1794, 0x4

glabel D_80336208
    .incbin "bin/rodata.bin", 0x1798, 0x4

glabel D_8033620C
    .incbin "bin/rodata.bin", 0x179C, 0x4

glabel D_80336210
    .incbin "bin/rodata.bin", 0x17A0, 0x4

glabel D_80336214
    .incbin "bin/rodata.bin", 0x17A4, 0x4

glabel D_80336218
    .incbin "bin/rodata.bin", 0x17A8, 0x4

glabel D_8033621C
    .incbin "bin/rodata.bin", 0x17AC, 0x4

glabel D_80336220
    .incbin "bin/rodata.bin", 0x17B0, 0x4

glabel D_80336224
    .incbin "bin/rodata.bin", 0x17B4, 0x4

glabel D_80336228
    .incbin "bin/rodata.bin", 0x17B8, 0x4

glabel D_8033622C
    .incbin "bin/rodata.bin", 0x17BC, 0x4

glabel D_80336230
    .incbin "bin/rodata.bin", 0x17C0, 0x4

glabel D_80336234
    .incbin "bin/rodata.bin", 0x17C4, 0x4

glabel D_80336238
    .incbin "bin/rodata.bin", 0x17C8, 0x4

glabel D_8033623C
    .incbin "bin/rodata.bin", 0x17CC, 0x4

glabel D_80336240
    .incbin "bin/rodata.bin", 0x17D0, 0x4

glabel D_80336244
    .incbin "bin/rodata.bin", 0x17D4, 0x4

glabel D_80336248
    .incbin "bin/rodata.bin", 0x17D8, 0x4

glabel D_8033624C
    .incbin "bin/rodata.bin", 0x17DC, 0x4

glabel D_80336250
    .incbin "bin/rodata.bin", 0x17E0, 0x4

glabel D_80336254
    .incbin "bin/rodata.bin", 0x17E4, 0x4

glabel D_80336258
    .incbin "bin/rodata.bin", 0x17E8, 0x4

glabel D_8033625C
    .incbin "bin/rodata.bin", 0x17EC, 0x4

glabel D_80336260
    .incbin "bin/rodata.bin", 0x17F0, 0x4

glabel D_80336264
    .incbin "bin/rodata.bin", 0x17F4, 0x4

glabel D_80336268
    .incbin "bin/rodata.bin", 0x17F8, 0x4

glabel D_8033626C
    .incbin "bin/rodata.bin", 0x17FC, 0x4

glabel D_80336270
    .incbin "bin/rodata.bin", 0x1800, 0x4

glabel D_80336274
    .incbin "bin/rodata.bin", 0x1804, 0x4

glabel D_80336278
    .incbin "bin/rodata.bin", 0x1808, 0x4

glabel D_8033627C
    .incbin "bin/rodata.bin", 0x180C, 0x4

glabel D_80336280
    .incbin "bin/rodata.bin", 0x1810, 0x4

glabel D_80336284
    .incbin "bin/rodata.bin", 0x1814, 0x4

glabel D_80336288
    .incbin "bin/rodata.bin", 0x1818, 0x4

glabel D_8033628C
    .incbin "bin/rodata.bin", 0x181C, 0x4

glabel D_80336290
    .incbin "bin/rodata.bin", 0x1820, 0x4

glabel D_80336294
    .incbin "bin/rodata.bin", 0x1824, 0x4

glabel D_80336298
    .incbin "bin/rodata.bin", 0x1828, 0x4

glabel D_8033629C
    .incbin "bin/rodata.bin", 0x182C, 0x4

glabel jtbl_803362A0
    .incbin "bin/rodata.bin", 0x1830, 0x204

glabel D_803364A4
    .incbin "bin/rodata.bin", 0x1A34, 0x4

glabel D_803364A8
    .incbin "bin/rodata.bin", 0x1A38, 0x4

glabel D_803364AC
    .incbin "bin/rodata.bin", 0x1A3C, 0x4

glabel D_803364B0
    .incbin "bin/rodata.bin", 0x1A40, 0x4

glabel D_803364B4
    .incbin "bin/rodata.bin", 0x1A44, 0x4

glabel D_803364B8
    .incbin "bin/rodata.bin", 0x1A48, 0x4

glabel D_803364BC
    .incbin "bin/rodata.bin", 0x1A4C, 0x4

glabel D_803364C0
    .incbin "bin/rodata.bin", 0x1A50, 0x4

glabel D_803364C4
    .incbin "bin/rodata.bin", 0x1A54, 0x4

glabel jtbl_803364C8
    .incbin "bin/rodata.bin", 0x1A58, 0xD0

glabel jtbl_80336598
    .incbin "bin/rodata.bin", 0x1B28, 0x34

glabel D_803365CC
    .incbin "bin/rodata.bin", 0x1B5C, 0x4

glabel D_803365D0
    .incbin "bin/rodata.bin", 0x1B60, 0x4

glabel D_803365D4
    .incbin "bin/rodata.bin", 0x1B64, 0x4

glabel D_803365D8
    .incbin "bin/rodata.bin", 0x1B68, 0x4

glabel D_803365DC
    .incbin "bin/rodata.bin", 0x1B6C, 0x4

glabel jtbl_803365E0
    .incbin "bin/rodata.bin", 0x1B70, 0x30

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

glabel D_80336C50
    .incbin "bin/rodata.bin", 0x21E0, 0x10

glabel D_80336C60
    .incbin "bin/rodata.bin", 0x21F0, 0x4

glabel D_80336C64
    .incbin "bin/rodata.bin", 0x21F4, 0x4

glabel D_80336C68
    .incbin "bin/rodata.bin", 0x21F8, 0x4

glabel D_80336C6C
    .incbin "bin/rodata.bin", 0x21FC, 0x4

glabel D_80336C70
    .incbin "bin/rodata.bin", 0x2200, 0x4

glabel D_80336C74
    .incbin "bin/rodata.bin", 0x2204, 0x94

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
    .incbin "bin/rodata.bin", 0x2400, 0xC8

glabel D_80336F38
    .incbin "bin/rodata.bin", 0x24C8, 0x10

glabel D_80336F48
    .incbin "bin/rodata.bin", 0x24D8, 0x20

glabel jtbl_80336F68
    .incbin "bin/rodata.bin", 0x24F8, 0xB0

glabel jtbl_80337018
    .incbin "bin/rodata.bin", 0x25A8, 0xCC

glabel D_803370E4
    .incbin "bin/rodata.bin", 0x2674, 0x8

glabel D_803370EC
    .incbin "bin/rodata.bin", 0x267C, 0x8

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
    .incbin "bin/rodata.bin", 0x276C, 0xBC

glabel D_80337298
    .incbin "bin/rodata.bin", 0x2828, 0x18

glabel D_803372B0
    .incbin "bin/rodata.bin", 0x2840, 0x4

glabel jtbl_803372B4
    .incbin "bin/rodata.bin", 0x2844, 0x14

glabel jtbl_803372C8
    .incbin "bin/rodata.bin", 0x2858, 0x14

glabel D_803372DC
    .incbin "bin/rodata.bin", 0x286C, 0x4

glabel D_803372E0
    .incbin "bin/rodata.bin", 0x2870, 0x4

glabel D_803372E4
    .incbin "bin/rodata.bin", 0x2874, 0x4

glabel D_803372E8
    .incbin "bin/rodata.bin", 0x2878, 0x4

glabel D_803372EC
    .incbin "bin/rodata.bin", 0x287C, 0x4

glabel D_803372F0
    .incbin "bin/rodata.bin", 0x2880, 0x4

glabel D_803372F4
    .incbin "bin/rodata.bin", 0x2884, 0x4

glabel D_803372F8
    .incbin "bin/rodata.bin", 0x2888, 0x4

glabel D_803372FC
    .incbin "bin/rodata.bin", 0x288C, 0x4

glabel D_80337300
    .incbin "bin/rodata.bin", 0x2890, 0x4

glabel D_80337304
    .incbin "bin/rodata.bin", 0x2894, 0x4

glabel D_80337308
    .incbin "bin/rodata.bin", 0x2898, 0x4

glabel D_8033730C
    .incbin "bin/rodata.bin", 0x289C, 0x4

glabel D_80337310
    .incbin "bin/rodata.bin", 0x28A0, 0x4

glabel D_80337314
    .incbin "bin/rodata.bin", 0x28A4, 0x4

glabel D_80337318
    .incbin "bin/rodata.bin", 0x28A8, 0x4

glabel D_8033731C
    .incbin "bin/rodata.bin", 0x28AC, 0x4

glabel D_80337320
    .incbin "bin/rodata.bin", 0x28B0, 0x18

glabel jtbl_80337338
    .incbin "bin/rodata.bin", 0x28C8, 0x20

glabel D_80337358
    .incbin "bin/rodata.bin", 0x28E8, 0x38

glabel D_80337390
    .incbin "bin/rodata.bin", 0x2920, 0x4

glabel D_80337394
    .incbin "bin/rodata.bin", 0x2924, 0x4

glabel D_80337398
    .incbin "bin/rodata.bin", 0x2928, 0x4

glabel D_8033739C
    .incbin "bin/rodata.bin", 0x292C, 0x4

glabel D_803373A0
    .incbin "bin/rodata.bin", 0x2930, 0x4

glabel D_803373A4
    .incbin "bin/rodata.bin", 0x2934, 0x4

glabel D_803373A8
    .incbin "bin/rodata.bin", 0x2938, 0x4

glabel D_803373AC
    .incbin "bin/rodata.bin", 0x293C, 0x4

glabel D_803373B0
    .incbin "bin/rodata.bin", 0x2940, 0x4

glabel D_803373B4
    .incbin "bin/rodata.bin", 0x2944, 0x4

glabel D_803373B8
    .incbin "bin/rodata.bin", 0x2948, 0x4

glabel jtbl_803373BC
    .incbin "bin/rodata.bin", 0x294C, 0x44

glabel D_80337400
    .incbin "bin/rodata.bin", 0x2990, 0x20

glabel D_80337420
    .incbin "bin/rodata.bin", 0x29B0, 0x4

glabel D_80337424
    .incbin "bin/rodata.bin", 0x29B4, 0x4

glabel D_80337428
    .incbin "bin/rodata.bin", 0x29B8, 0x4

glabel D_8033742C
    .incbin "bin/rodata.bin", 0x29BC, 0x4

glabel D_80337430
    .incbin "bin/rodata.bin", 0x29C0, 0x4

glabel D_80337434
    .incbin "bin/rodata.bin", 0x29C4, 0x4

glabel D_80337438
    .incbin "bin/rodata.bin", 0x29C8, 0x4

glabel D_8033743C
    .incbin "bin/rodata.bin", 0x29CC, 0x4

glabel D_80337440
    .incbin "bin/rodata.bin", 0x29D0, 0x4

glabel D_80337444
    .incbin "bin/rodata.bin", 0x29D4, 0x4

glabel D_80337448
    .incbin "bin/rodata.bin", 0x29D8, 0x4

glabel D_8033744C
    .incbin "bin/rodata.bin", 0x29DC, 0x4

glabel D_80337450
    .incbin "bin/rodata.bin", 0x29E0, 0x4

glabel D_80337454
    .incbin "bin/rodata.bin", 0x29E4, 0x4

glabel jtbl_80337458
    .incbin "bin/rodata.bin", 0x29E8, 0x14

glabel jtbl_8033746C
    .incbin "bin/rodata.bin", 0x29FC, 0x18

glabel jtbl_80337484
    .incbin "bin/rodata.bin", 0x2A14, 0x1C

glabel jtbl_803374A0
    .incbin "bin/rodata.bin", 0x2A30, 0x14

glabel D_803374B4
    .incbin "bin/rodata.bin", 0x2A44, 0x4

glabel D_803374B8
    .incbin "bin/rodata.bin", 0x2A48, 0x4

glabel D_803374BC
    .incbin "bin/rodata.bin", 0x2A4C, 0x4

glabel D_803374C0
    .incbin "bin/rodata.bin", 0x2A50, 0x4

glabel D_803374C4
    .incbin "bin/rodata.bin", 0x2A54, 0x4

glabel D_803374C8
    .incbin "bin/rodata.bin", 0x2A58, 0x4

glabel D_803374CC
    .incbin "bin/rodata.bin", 0x2A5C, 0x4

glabel D_803374D0
    .incbin "bin/rodata.bin", 0x2A60, 0x4

glabel D_803374D4
    .incbin "bin/rodata.bin", 0x2A64, 0x4

glabel D_803374D8
    .incbin "bin/rodata.bin", 0x2A68, 0x20

glabel D_803374F8
    .incbin "bin/rodata.bin", 0x2A88, 0x4

glabel D_803374FC
    .incbin "bin/rodata.bin", 0x2A8C, 0x4

glabel D_80337500
    .incbin "bin/rodata.bin", 0x2A90, 0x4

glabel D_80337504
    .incbin "bin/rodata.bin", 0x2A94, 0x4

glabel jtbl_80337508
    .incbin "bin/rodata.bin", 0x2A98, 0x14

glabel D_8033751C
    .incbin "bin/rodata.bin", 0x2AAC, 0x4

glabel D_80337520
    .incbin "bin/rodata.bin", 0x2AB0, 0x4

glabel D_80337524
    .incbin "bin/rodata.bin", 0x2AB4, 0x4

glabel D_80337528
    .incbin "bin/rodata.bin", 0x2AB8, 0x4

glabel D_8033752C
    .incbin "bin/rodata.bin", 0x2ABC, 0x4

glabel D_80337530
    .incbin "bin/rodata.bin", 0x2AC0, 0x4

glabel jtbl_80337534
    .incbin "bin/rodata.bin", 0x2AC4, 0x14

glabel D_80337548
    .incbin "bin/rodata.bin", 0x2AD8, 0x4

glabel D_8033754C
    .incbin "bin/rodata.bin", 0x2ADC, 0x4

glabel D_80337550
    .incbin "bin/rodata.bin", 0x2AE0, 0x4

glabel D_80337554
    .incbin "bin/rodata.bin", 0x2AE4, 0xC

glabel jtbl_80337560
    .incbin "bin/rodata.bin", 0x2AF0, 0x90

glabel D_803375F0
    .incbin "bin/rodata.bin", 0x2B80, 0x4

glabel D_803375F4
    .incbin "bin/rodata.bin", 0x2B84, 0x4

glabel D_803375F8
    .incbin "bin/rodata.bin", 0x2B88, 0x18

glabel D_80337610
    .incbin "bin/rodata.bin", 0x2BA0, 0x4

glabel D_80337614
    .incbin "bin/rodata.bin", 0x2BA4, 0x4

glabel D_80337618
    .incbin "bin/rodata.bin", 0x2BA8, 0x4

glabel D_8033761C
    .incbin "bin/rodata.bin", 0x2BAC, 0x4

glabel D_80337620
    .incbin "bin/rodata.bin", 0x2BB0, 0x4

glabel D_80337624
    .incbin "bin/rodata.bin", 0x2BB4, 0x4

glabel D_80337628
    .incbin "bin/rodata.bin", 0x2BB8, 0x4

glabel D_8033762C
    .incbin "bin/rodata.bin", 0x2BBC, 0x4

glabel D_80337630
    .incbin "bin/rodata.bin", 0x2BC0, 0x4

glabel D_80337634
    .incbin "bin/rodata.bin", 0x2BC4, 0x4

glabel D_80337638
    .incbin "bin/rodata.bin", 0x2BC8, 0x20

glabel jtbl_80337658
    .incbin "bin/rodata.bin", 0x2BE8, 0xC0

glabel D_80337718
    .incbin "bin/rodata.bin", 0x2CA8, 0x4

glabel D_8033771C
    .incbin "bin/rodata.bin", 0x2CAC, 0x4

glabel D_80337720
    .incbin "bin/rodata.bin", 0x2CB0, 0x18

glabel D_80337738
    .incbin "bin/rodata.bin", 0x2CC8, 0x4

glabel D_8033773C
    .incbin "bin/rodata.bin", 0x2CCC, 0x4

glabel D_80337740
    .incbin "bin/rodata.bin", 0x2CD0, 0x4

glabel D_80337744
    .incbin "bin/rodata.bin", 0x2CD4, 0x4

glabel D_80337748
    .incbin "bin/rodata.bin", 0x2CD8, 0x4

glabel D_8033774C
    .incbin "bin/rodata.bin", 0x2CDC, 0x4

glabel D_80337750
    .incbin "bin/rodata.bin", 0x2CE0, 0x4

glabel D_80337754
    .incbin "bin/rodata.bin", 0x2CE4, 0x4

glabel jtbl_80337758
    .incbin "bin/rodata.bin", 0x2CE8, 0x14

glabel D_8033776C
    .incbin "bin/rodata.bin", 0x2CFC, 0x4

glabel D_80337770
    .incbin "bin/rodata.bin", 0x2D00, 0x4

glabel D_80337774
    .incbin "bin/rodata.bin", 0x2D04, 0xC

glabel D_80337780
    .incbin "bin/rodata.bin", 0x2D10, 0x4

glabel D_80337784
    .incbin "bin/rodata.bin", 0x2D14, 0x4

glabel D_80337788
    .incbin "bin/rodata.bin", 0x2D18, 0x4

glabel D_8033778C
    .incbin "bin/rodata.bin", 0x2D1C, 0x4

glabel jtbl_80337790
    .incbin "bin/rodata.bin", 0x2D20, 0x30

glabel D_803377C0
    .incbin "bin/rodata.bin", 0x2D50, 0x4

glabel D_803377C4
    .incbin "bin/rodata.bin", 0x2D54, 0x4

glabel jtbl_803377C8
    .incbin "bin/rodata.bin", 0x2D58, 0x24

glabel D_803377EC
    .incbin "bin/rodata.bin", 0x2D7C, 0x4

glabel D_803377F0
    .incbin "bin/rodata.bin", 0x2D80, 0x4

glabel D_803377F4
    .incbin "bin/rodata.bin", 0x2D84, 0x4

glabel D_803377F8
    .incbin "bin/rodata.bin", 0x2D88, 0x4

glabel D_803377FC
    .incbin "bin/rodata.bin", 0x2D8C, 0x4

glabel D_80337800
    .incbin "bin/rodata.bin", 0x2D90, 0x4

glabel D_80337804
    .incbin "bin/rodata.bin", 0x2D94, 0x4

glabel D_80337808
    .incbin "bin/rodata.bin", 0x2D98, 0x4

glabel D_8033780C
    .incbin "bin/rodata.bin", 0x2D9C, 0x4

glabel D_80337810
    .incbin "bin/rodata.bin", 0x2DA0, 0x4

glabel D_80337814
    .incbin "bin/rodata.bin", 0x2DA4, 0x4

glabel D_80337818
    .incbin "bin/rodata.bin", 0x2DA8, 0x4

glabel D_8033781C
    .incbin "bin/rodata.bin", 0x2DAC, 0x4

glabel D_80337820
    .incbin "bin/rodata.bin", 0x2DB0, 0x4

glabel D_80337824
    .incbin "bin/rodata.bin", 0x2DB4, 0x4

glabel D_80337828
    .incbin "bin/rodata.bin", 0x2DB8, 0x4

glabel D_8033782C
    .incbin "bin/rodata.bin", 0x2DBC, 0x4

glabel D_80337830
    .incbin "bin/rodata.bin", 0x2DC0, 0x4

glabel D_80337834
    .incbin "bin/rodata.bin", 0x2DC4, 0x4

glabel D_80337838
    .incbin "bin/rodata.bin", 0x2DC8, 0x4

glabel D_8033783C
    .incbin "bin/rodata.bin", 0x2DCC, 0x4

glabel jtbl_80337840
    .incbin "bin/rodata.bin", 0x2DD0, 0x1C

glabel D_8033785C
    .incbin "bin/rodata.bin", 0x2DEC, 0x4

glabel D_80337860
    .incbin "bin/rodata.bin", 0x2DF0, 0x4

glabel D_80337864
    .incbin "bin/rodata.bin", 0x2DF4, 0x4

glabel D_80337868
    .incbin "bin/rodata.bin", 0x2DF8, 0x4

glabel D_8033786C
    .incbin "bin/rodata.bin", 0x2DFC, 0x4

glabel D_80337870
    .incbin "bin/rodata.bin", 0x2E00, 0x4

glabel D_80337874
    .incbin "bin/rodata.bin", 0x2E04, 0x4

glabel D_80337878
    .incbin "bin/rodata.bin", 0x2E08, 0x4

glabel D_8033787C
    .incbin "bin/rodata.bin", 0x2E0C, 0x4

glabel D_80337880
    .incbin "bin/rodata.bin", 0x2E10, 0x4

glabel D_80337884
    .incbin "bin/rodata.bin", 0x2E14, 0x4

glabel D_80337888
    .incbin "bin/rodata.bin", 0x2E18, 0x4

glabel D_8033788C
    .incbin "bin/rodata.bin", 0x2E1C, 0x4

glabel D_80337890
    .incbin "bin/rodata.bin", 0x2E20, 0x4

glabel D_80337894
    .incbin "bin/rodata.bin", 0x2E24, 0x4

glabel D_80337898
    .incbin "bin/rodata.bin", 0x2E28, 0x4

glabel D_8033789C
    .incbin "bin/rodata.bin", 0x2E2C, 0x4

glabel D_803378A0
    .incbin "bin/rodata.bin", 0x2E30, 0x4

glabel D_803378A4
    .incbin "bin/rodata.bin", 0x2E34, 0x4

glabel D_803378A8
    .incbin "bin/rodata.bin", 0x2E38, 0x4

glabel D_803378AC
    .incbin "bin/rodata.bin", 0x2E3C, 0x4

glabel D_803378B0
    .incbin "bin/rodata.bin", 0x2E40, 0x4

glabel jtbl_803378B4
    .incbin "bin/rodata.bin", 0x2E44, 0x18

glabel D_803378CC
    .incbin "bin/rodata.bin", 0x2E5C, 0x4

glabel D_803378D0
    .incbin "bin/rodata.bin", 0x2E60, 0x4

glabel D_803378D4
    .incbin "bin/rodata.bin", 0x2E64, 0x4

glabel D_803378D8
    .incbin "bin/rodata.bin", 0x2E68, 0x4

glabel jtbl_803378DC
    .incbin "bin/rodata.bin", 0x2E6C, 0x14

glabel D_803378F0
    .incbin "bin/rodata.bin", 0x2E80, 0x4

glabel D_803378F4
    .incbin "bin/rodata.bin", 0x2E84, 0x4

glabel D_803378F8
    .incbin "bin/rodata.bin", 0x2E88, 0x4

glabel D_803378FC
    .incbin "bin/rodata.bin", 0x2E8C, 0x4

glabel D_80337900
    .incbin "bin/rodata.bin", 0x2E90, 0x4

glabel D_80337904
    .incbin "bin/rodata.bin", 0x2E94, 0x4

glabel D_80337908
    .incbin "bin/rodata.bin", 0x2E98, 0x4

glabel D_8033790C
    .incbin "bin/rodata.bin", 0x2E9C, 0x4

glabel D_80337910
    .incbin "bin/rodata.bin", 0x2EA0, 0x4

glabel D_80337914
    .incbin "bin/rodata.bin", 0x2EA4, 0x4

glabel D_80337918
    .incbin "bin/rodata.bin", 0x2EA8, 0x4

glabel D_8033791C
    .incbin "bin/rodata.bin", 0x2EAC, 0x4

glabel D_80337920
    .incbin "bin/rodata.bin", 0x2EB0, 0x4

glabel D_80337924
    .incbin "bin/rodata.bin", 0x2EB4, 0x4

glabel D_80337928
    .incbin "bin/rodata.bin", 0x2EB8, 0x4

glabel D_8033792C
    .incbin "bin/rodata.bin", 0x2EBC, 0x4

glabel D_80337930
    .incbin "bin/rodata.bin", 0x2EC0, 0x4

glabel D_80337934
    .incbin "bin/rodata.bin", 0x2EC4, 0x4

glabel D_80337938
    .incbin "bin/rodata.bin", 0x2EC8, 0x8

glabel D_80337940
    .incbin "bin/rodata.bin", 0x2ED0, 0x4

glabel D_80337944
    .incbin "bin/rodata.bin", 0x2ED4, 0x4

glabel D_80337948
    .incbin "bin/rodata.bin", 0x2ED8, 0x4

glabel jtbl_8033794C
    .incbin "bin/rodata.bin", 0x2EDC, 0x20

glabel D_8033796C
    .incbin "bin/rodata.bin", 0x2EFC, 0x4

glabel D_80337970
    .incbin "bin/rodata.bin", 0x2F00, 0x4

glabel D_80337974
    .incbin "bin/rodata.bin", 0x2F04, 0x4

glabel D_80337978
    .incbin "bin/rodata.bin", 0x2F08, 0x4

glabel jtbl_8033797C
    .incbin "bin/rodata.bin", 0x2F0C, 0x14

glabel D_80337990
    .incbin "bin/rodata.bin", 0x2F20, 0x4

glabel D_80337994
    .incbin "bin/rodata.bin", 0x2F24, 0x4

glabel D_80337998
    .incbin "bin/rodata.bin", 0x2F28, 0x4

glabel D_8033799C
    .incbin "bin/rodata.bin", 0x2F2C, 0x4

glabel D_803379A0
    .incbin "bin/rodata.bin", 0x2F30, 0x4

glabel D_803379A4
    .incbin "bin/rodata.bin", 0x2F34, 0x4

glabel D_803379A8
    .incbin "bin/rodata.bin", 0x2F38, 0x4

glabel D_803379AC
    .incbin "bin/rodata.bin", 0x2F3C, 0x4

glabel D_803379B0
    .incbin "bin/rodata.bin", 0x2F40, 0x4

glabel D_803379B4
    .incbin "bin/rodata.bin", 0x2F44, 0x4

glabel D_803379B8
    .incbin "bin/rodata.bin", 0x2F48, 0x4

glabel D_803379BC
    .incbin "bin/rodata.bin", 0x2F4C, 0x4

glabel D_803379C0
    .incbin "bin/rodata.bin", 0x2F50, 0x4

glabel D_803379C4
    .incbin "bin/rodata.bin", 0x2F54, 0x4

glabel D_803379C8
    .incbin "bin/rodata.bin", 0x2F58, 0x4

glabel D_803379CC
    .incbin "bin/rodata.bin", 0x2F5C, 0x4

glabel D_803379D0
    .incbin "bin/rodata.bin", 0x2F60, 0x4

glabel D_803379D4
    .incbin "bin/rodata.bin", 0x2F64, 0x4

glabel jtbl_803379D8
    .incbin "bin/rodata.bin", 0x2F68, 0x20

glabel D_803379F8
    .incbin "bin/rodata.bin", 0x2F88, 0x4

glabel D_803379FC
    .incbin "bin/rodata.bin", 0x2F8C, 0x4

glabel D_80337A00
    .incbin "bin/rodata.bin", 0x2F90, 0x4

glabel D_80337A04
    .incbin "bin/rodata.bin", 0x2F94, 0x4

glabel D_80337A08
    .incbin "bin/rodata.bin", 0x2F98, 0x4

glabel D_80337A0C
    .incbin "bin/rodata.bin", 0x2F9C, 0x4

glabel D_80337A10
    .incbin "bin/rodata.bin", 0x2FA0, 0x4

glabel D_80337A14
    .incbin "bin/rodata.bin", 0x2FA4, 0x4

glabel jtbl_80337A18
    .incbin "bin/rodata.bin", 0x2FA8, 0x14

glabel D_80337A2C
    .incbin "bin/rodata.bin", 0x2FBC, 0x4

glabel D_80337A30
    .incbin "bin/rodata.bin", 0x2FC0, 0x4

glabel D_80337A34
    .incbin "bin/rodata.bin", 0x2FC4, 0x4

glabel D_80337A38
    .incbin "bin/rodata.bin", 0x2FC8, 0x4

glabel D_80337A3C
    .incbin "bin/rodata.bin", 0x2FCC, 0x4

glabel D_80337A40
    .incbin "bin/rodata.bin", 0x2FD0, 0x4

glabel D_80337A44
    .incbin "bin/rodata.bin", 0x2FD4, 0x4

glabel D_80337A48
    .incbin "bin/rodata.bin", 0x2FD8, 0x4

glabel jtbl_80337A4C
    .incbin "bin/rodata.bin", 0x2FDC, 0x14

glabel D_80337A60
    .incbin "bin/rodata.bin", 0x2FF0, 0x4

glabel D_80337A64
    .incbin "bin/rodata.bin", 0x2FF4, 0x4

glabel D_80337A68
    .incbin "bin/rodata.bin", 0x2FF8, 0x4

glabel D_80337A6C
    .incbin "bin/rodata.bin", 0x2FFC, 0x4

glabel D_80337A70
    .incbin "bin/rodata.bin", 0x3000, 0x4

glabel D_80337A74
    .incbin "bin/rodata.bin", 0x3004, 0x4

glabel D_80337A78
    .incbin "bin/rodata.bin", 0x3008, 0x4

glabel D_80337A7C
    .incbin "bin/rodata.bin", 0x300C, 0x4

glabel D_80337A80
    .incbin "bin/rodata.bin", 0x3010, 0x4

glabel D_80337A84
    .incbin "bin/rodata.bin", 0x3014, 0x4

glabel D_80337A88
    .incbin "bin/rodata.bin", 0x3018, 0x4

glabel D_80337A8C
    .incbin "bin/rodata.bin", 0x301C, 0x4

glabel jtbl_80337A90
    .incbin "bin/rodata.bin", 0x3020, 0x14

glabel D_80337AA4
    .incbin "bin/rodata.bin", 0x3034, 0x4

glabel D_80337AA8
    .incbin "bin/rodata.bin", 0x3038, 0x4

glabel D_80337AAC
    .incbin "bin/rodata.bin", 0x303C, 0x4

glabel D_80337AB0
    .incbin "bin/rodata.bin", 0x3040, 0x4

glabel jtbl_80337AB4
    .incbin "bin/rodata.bin", 0x3044, 0x3C

glabel D_80337AF0
    .incbin "bin/rodata.bin", 0x3080, 0x4

glabel D_80337AF4
    .incbin "bin/rodata.bin", 0x3084, 0x8

glabel D_80337AFC
    .incbin "bin/rodata.bin", 0x308C, 0x4

glabel D_80337B00
    .incbin "bin/rodata.bin", 0x3090, 0x4

glabel D_80337B04
    .incbin "bin/rodata.bin", 0x3094, 0x4

glabel jtbl_80337B08
    .incbin "bin/rodata.bin", 0x3098, 0x20

glabel D_80337B28
    .incbin "bin/rodata.bin", 0x30B8, 0x4

glabel D_80337B2C
    .incbin "bin/rodata.bin", 0x30BC, 0x4

glabel D_80337B30
    .incbin "bin/rodata.bin", 0x30C0, 0x4

glabel D_80337B34
    .incbin "bin/rodata.bin", 0x30C4, 0x4

glabel D_80337B38
    .incbin "bin/rodata.bin", 0x30C8, 0x4

glabel D_80337B3C
    .incbin "bin/rodata.bin", 0x30CC, 0x4

glabel D_80337B40
    .incbin "bin/rodata.bin", 0x30D0, 0x4

glabel D_80337B44
    .incbin "bin/rodata.bin", 0x30D4, 0x4

glabel jtbl_80337B48
    .incbin "bin/rodata.bin", 0x30D8, 0x18

glabel D_80337B60
    .incbin "bin/rodata.bin", 0x30F0, 0x4

glabel D_80337B64
    .incbin "bin/rodata.bin", 0x30F4, 0x4

glabel D_80337B68
    .incbin "bin/rodata.bin", 0x30F8, 0x4

glabel D_80337B6C
    .incbin "bin/rodata.bin", 0x30FC, 0x4

glabel D_80337B70
    .incbin "bin/rodata.bin", 0x3100, 0x4

glabel D_80337B74
    .incbin "bin/rodata.bin", 0x3104, 0x4

glabel D_80337B78
    .incbin "bin/rodata.bin", 0x3108, 0x4

glabel D_80337B7C
    .incbin "bin/rodata.bin", 0x310C, 0x4

glabel D_80337B80
    .incbin "bin/rodata.bin", 0x3110, 0x4

glabel D_80337B84
    .incbin "bin/rodata.bin", 0x3114, 0x4

glabel D_80337B88
    .incbin "bin/rodata.bin", 0x3118, 0x4

glabel D_80337B8C
    .incbin "bin/rodata.bin", 0x311C, 0x4

glabel D_80337B90
    .incbin "bin/rodata.bin", 0x3120, 0x4

glabel D_80337B94
    .incbin "bin/rodata.bin", 0x3124, 0x8

glabel D_80337B9C
    .incbin "bin/rodata.bin", 0x312C, 0x4

glabel D_80337BA0
    .incbin "bin/rodata.bin", 0x3130, 0x4

glabel D_80337BA4
    .incbin "bin/rodata.bin", 0x3134, 0x34

glabel D_80337BD8
    .incbin "bin/rodata.bin", 0x3168, 0x8

glabel jtbl_80337BE0
    .incbin "bin/rodata.bin", 0x3170, 0x40

glabel D_80337C20
    .incbin "bin/rodata.bin", 0x31B0, 0x40

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
    .incbin "bin/rodata.bin", 0x3A40, 0x50

glabel D_80338500
    .incbin "bin/rodata.bin", 0x3A90, 0x10

glabel D_80338510
    .incbin "bin/rodata.bin", 0x3AA0, 0x4

glabel D_80338514
    .incbin "bin/rodata.bin", 0x3AA4, 0x8

glabel D_8033851C
    .incbin "bin/rodata.bin", 0x3AAC, 0x18

glabel jtbl_80338534
    .incbin "bin/rodata.bin", 0x3AC4, 0xDC

glabel D_80338610
    .incbin "bin/rodata.bin", 0x3BA0, 0x20

glabel D_80338630
    .incbin "bin/rodata.bin", 0x3BC0, 0x30

glabel D_80338660
    .incbin "bin/rodata.bin", 0x3BF0, 0x58

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
