# level script wing_cap_level from 4C06A0-4C08C0



.global wing_cap_level
.align 4, 0
wing_cap_level:
.word 0x24181F55, 0x0000F801, 0x000A0000, 0x00000000, 0x00000000, beh_activate_cap_switch
.word 0x07040000
.word 0x24181F00, 0x0320F95C, 0x00000000, 0x00000000, 0x00000000, beh_hidden_red_coin_star
.word 0x07040000
.word 0x1B040000
.word 0x180C0007, wing_cap_segment7, wing_cap_segment7_end
.word 0x180C000A, cloud_floor_skybox, cloud_floor_skybox_end
.word 0x1A0C0009, rr_textures, rr_textures_end
.word 0x180C0005, checkerboard_question, checkerboard_question_end
.word 0x170C000C, cap_switch, cap_switch_end
.word 0x180C0008, chuckya_shyguy_goomba, chuckya_shyguy_goomba_end
.word 0x170C000F, cannon_box_switch_enemies, cannon_box_switch_enemies_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x15000660
.word 0x06080000, 0x15000830
.word 0x22080003, 0x0E000160
.word 0x1F080100, 0x0E000188
.word 0x24181F00, 0xF0010B77, 0x00000000, 0x005A0000, 0x000A0000, beh_warps_78
.word 0x26080A1D, 0x010A0000
.word 0x2608F306, 0x01200000
.word 0x2608F006, 0x01260000
.word 0x2608F106, 0x01230000
.word 0x06080000, 0x0E00001C
.word 0x06080000, 0x0E000000
.word 0x2E080000, 0x07007A18
.word 0x39080000, 0x070088AC
.word 0x30040083
.word 0x36080000, 0x00090000
.word 0x31040001
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x005AF001, 0x0B770000
.word 0x11080000, LevelProc_8024BCD8 # 8024BB38
.word 0x12080001, LevelProc_8024BCD8 # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin wing_cap_level alignment 0x4C07F8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
# begin wing_cap_level geo 0x4C0800
# 0160
.word 0x200007D0
.word 0x04000000
.word   0x14000000, 0x00000000
.word   0x04000000
.word     0x15050000, 0x070079A8
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x0800000A, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x19000003, Geo19_802763D4
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A01002D, 0x006461A8, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F000010, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x07005D28
.word         0x15050000, 0x07007048
.word         0x15050000, 0x070078B8
.word         0x17000000
.word         0x18000000, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
wing_cap_level_end:
