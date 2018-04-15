# level script metal_cap_level from 4BC980-4BCBD0



.global metal_cap_level
.align 4, 0x01
metal_cap_level:
.word 0x24181F55, 0x0000016B, 0xE8000000, 0x00000000, 0x00010000, beh_activate_cap_switch
.word 0x24181F00, 0x000001F4, 0xE3330000, 0x00000000, 0x00000000, beh_waterfall_sound_loop
.word 0x24181F00, 0x000001F4, 0x0E000000, 0x00000000, 0x00000000, beh_waterfall_sound_loop
.word 0x07040000
.word 0x24181F00, 0x0000FF38, 0xE4A80000, 0x00000000, 0x00000000, beh_hidden_red_coin_star
.word 0x07040000
.word 0x1B040000
.word 0x180C0007, metal_cap_segment7, metal_cap_segment7_end
.word 0x1A0C0009, hmc_textures, hmc_textures_end
.word 0x180C0005, checkerboard_question, checkerboard_question_end
.word 0x170C000C, cap_switch, cap_switch_end
.word 0x180C0006, mri_swoop, mri_swoop_end
.word 0x170C000D, mri_swoop_snufit_dorrie_scuttlebug, mri_swoop_snufit_dorrie_scuttlebug_end
.word 0x180C0008, chuckya_shyguy_goomba, chuckya_shyguy_goomba_end
.word 0x170C000F, cannon_box_switch_enemies, cannon_box_switch_enemies_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x15000830
.word 0x06080000, 0x150009DC
.word 0x06080000, 0x15000660
.word 0x1F080100, 0x0E0001A0
.word 0x24181F00, 0xEFA703FC, 0xFFD10000, 0x005A0000, 0x000A0000, beh_warps_64
.word 0x26080A1C, 0x010A0000
.word 0x2608F006, 0x03340000
.word 0x2608F106, 0x03660000
.word 0x2608F310, 0x01140000
.word 0x06080000, 0x0E00004C
.word 0x06080000, 0x0E000000
.word 0x2E080000, 0x0700A508
.word 0x39080000, 0x0700BD38
.word 0x30040082
.word 0x36080004, 0x000C0000
.word 0x31040001
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x005AEFA7, 0x0014FFD1
.word 0x11080000, LevelProc_8024BCD8 # 8024BB38
.word 0x12080001, LevelProc_8024BCD8 # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin metal_cap_level alignment 0x4BCB14
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
# begin metal_cap_level geo 0x4BCB20
.word 0x0800000A, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x19000001, 0x00000000
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A01002D, 0x00643200, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F000010, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x07007D48
.word         0x15010000, 0x0700A160
.word         0x18000000, Geo18_802D01E0
.word         0x18002801, Geo18_802D1B70
.word         0x15050000, 0x0700A4B8
.word         0x17000000
.word         0x18000000, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x00000000
.word 0x00000000
metal_cap_level_end:
