# level script bifs_platform_level from 4CC990-4CCBA0



.global bifs_platform_level
.align 4, 0
bifs_platform_level:
.word 0x24181F36, 0x00000000, 0x00000000, 0x005A0000, 0x00000000, beh_tilting_bowser_lava_platform
.word 0x24181FB3, 0x00040531, 0x0E0E0000, 0x005A0000, 0x00000000, beh_bowser_bomb
.word 0x24181FB3, 0x0E000531, 0x00000000, 0x005A0000, 0x00000000, beh_bowser_bomb
.word 0x24181FB3, 0x00000531, 0xF2010000, 0x005A0000, 0x00000000, beh_bowser_bomb
.word 0x24181FB3, 0xF2010531, 0x00000000, 0x005A0000, 0x00000000, beh_bowser_bomb
.word 0x07040000
.word 0x1B040000
.word 0x180C000A, bifs_skybox, bifs_skybox_end
.word 0x1A0C0009, lll_textures, lll_textures_end
.word 0x180C000B, flower_textures, flower_textures_end
.word 0x180C0007, bifs_platform_segment7, bifs_platform_segment7_end
.word 0x180C0006, bowser, bowser_end
.word 0x170C000D, bowser_flames_bomb, bowser_flames_bomb_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x150008D8
.word 0x22080036, 0x0E000170
.word 0x1F080100, 0x0E000188
.word 0x24181F00, 0x000008B5, 0x00000000, 0x00B40000, 0x000A0000, beh_warps_6C
.word 0x26080A21, 0x010A0000
.word 0x2608F006, 0x03360000
.word 0x2608F113, 0x010C0000
.word 0x06080000, 0x0E000000
.word 0x2E080000, 0x070019F0
.word 0x36080002, 0x00070000
.word 0x31040001
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x00B40000, 0x04CD0000
.word 0x11080000, LevelProc_8024BCD8 # 8024BB38
.word 0x12080001, LevelProc_8024BCD8 # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin bifs_platform_level alignment 0x4CCAFC
.byte 0x00, 0x00, 0x00, 0x00
# begin bifs_platform_level geo 0x4CCB00
# 0170
.word 0x20001388
.word 0x04000000
.word   0x15010000, 0x07000FE0
.word 0x05000000
.word 0x01000000
.word 0x0800000A, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x19000001, Geo19_802763D4
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A01002D, 0x00644E20, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F00000B, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x07001930
.word         0x17000000
.word         0x1800000C, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
bifs_platform_level_end:
