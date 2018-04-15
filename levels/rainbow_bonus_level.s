# level script rainbow_bonus_level from 4CB8D0-4CBB70



.global rainbow_bonus_level
.align 4, 0x01
rainbow_bonus_level:
.word 0x24181F00, 0x0F9CF54D, 0x15650000, 0x00000000, 0x00520000, beh_pole_grabbing
.word 0x24181F00, 0xF4A10DEC, 0xF0810000, 0x00000000, 0x00540000, beh_pole_grabbing
.word 0x24181F00, 0xF3460D1F, 0xF0960000, 0x00000000, 0x00690000, beh_pole_grabbing
.word 0x24181F00, 0xF5B10C52, 0xEEEF0000, 0x00000000, 0x007D0000, beh_pole_grabbing
.word 0x24181F00, 0xF45C0FD0, 0xEF680000, 0x00000000, 0x00240000, beh_pole_grabbing
.word 0x24181F00, 0xF3260E34, 0xEE830000, 0x00000000, 0x004D0000, beh_pole_grabbing
.word 0x07040000
.word 0x24181F00, 0xFF60079E, 0xFE2A0000, 0x00000000, 0x00000000, beh_hidden_red_coin_star
.word 0x07040000
.word 0x1B040000
.word 0x180C0007, rainbow_bonus_segment7, rainbow_bonus_segment7_end
.word 0x180C000A, cloud_floor_skybox, cloud_floor_skybox_end
.word 0x1A0C0009, rr_textures, rr_textures_end
.word 0x180C0005, big_bully, big_bully_end
.word 0x170C000C, bully_blargg, bully_blargg_end
.word 0x180C0006, mri_swoop, mri_swoop_end
.word 0x170C000D, mri_swoop_snufit_dorrie_scuttlebug, mri_swoop_snufit_dorrie_scuttlebug_end
.word 0x180C0008, chuckya_shyguy_goomba, chuckya_shyguy_goomba_end
.word 0x170C000F, cannon_box_switch_enemies, cannon_box_switch_enemies_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x15000660
.word 0x06080000, 0x15000750
.word 0x06080000, 0x150009DC
.word 0x1F080100, 0x0E0001F0
.word 0x24181F00, 0xFFBD0A6D, 0xFFF00000, 0x010E0000, 0x000A0000, beh_warps_64
.word 0x26080A1F, 0x010A0000
.word 0x2608F006, 0x02380000
.word 0x2608F106, 0x026D0000
.word 0x2608F310, 0x010A0000
.word 0x06080000, 0x0E000000
.word 0x06080000, 0x0E000094
.word 0x2E080000, 0x07010688
.word 0x39080000, 0x070136A8
.word 0x36080000, 0x00090000
.word 0x31040002
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x010EFFBD, 0x0685FFF0
.word 0x11080000, LevelProc_8024BCD8 # 8024BB38
.word 0x12080001, LevelProc_8024BCD8 # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin rainbow_bonus_level alignment 0x4CBAB4
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
# begin rainbow_bonus_level geo 0x4CBAC0
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
.word     0x0A01002D, 0x00644E20, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F000010, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x0700C1F8
.word         0x15050000, 0x0700EFD8
.word         0x15050000, 0x07010608
.word         0x17000000
.word         0x18000000, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word   0x0C000000
.word   0x04000000
.word     0x18000000, Geo18_802CD1E8
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x00000000
rainbow_bonus_level_end:
