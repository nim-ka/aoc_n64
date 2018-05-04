# level script bidw_platform_level from 4C2160-4C22C0



.global bidw_platform_level
.align 4, 0
bidw_platform_level:
.word 0x1B040000
.word 0x180C0007, bidw_platform_segment7, bidw_platform_segment7_end
.word 0x180C000A, bidw_skybox, bidw_skybox_end
.word 0x180C0006, bowser, bowser_end
.word 0x170C000D, bowser_flames_bomb, bowser_flames_bomb_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x150008D8
.word 0x22080003, 0x0D0000B0
.word 0x1F080100, 0x0E0000D0
.word 0x24181F00, 0x0000051B, 0x00000000, 0x00B40000, 0x000A0000, beh_warps_6C
.word 0x26080A1E, 0x010A0000
.word 0x2608F006, 0x01240000
.word 0x2608F111, 0x010C0000
.word 0x2E080000, 0x07002838
.word 0x36080002, 0x00070000
.word 0x31040001
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x00B40000, 0x01330000
.word 0x11080000, lvl_init_or_update # 8024BB38
.word 0x12080001, lvl_init_or_update # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin bidw_platform_level geo 0x4C2230
.word 0x0800000A, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x19000007, Geo19_802763D4
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A01002D, 0x00643200, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F00000B, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x07002768
.word         0x17000000
.word         0x18000000, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x00000000
.word 0x00000000
bidw_platform_level_end:
