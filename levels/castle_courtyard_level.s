# level script castle_courtyard_level from 4AD610-4AD8D0



.global castle_courtyard_level
.align 4, 0
castle_courtyard_level:
.word 0x24181F00, 0x000000C8, 0xF98C0000, 0x00000000, 0x00000000, beh_ambiant_sounds
.word 0x24181F00, 0xF5740000, 0xF98C0000, 0x00000000, 0x00000000, beh_birds_sound_loop
.word 0x24181F00, 0x0A8C0000, 0xF98C0000, 0x00000000, 0x00010000, beh_birds_sound_loop
.word 0x07040000
.word 0x24181F54, 0xF36F0064, 0xFF9B0000, 0x00000000, 0x00000000, beh_boo_group
.word 0x24181F54, 0x0CF50064, 0xF95B0000, 0x00000000, 0x00000000, beh_boo_group
.word 0x24181F54, 0xFFB90001, 0xFA950000, 0x00000000, 0x00000000, beh_boo_group
.word 0x07040000
.word 0x1B040000
.word 0x180C0007, castle_courtyard_segment7, castle_courtyard_segment7_end
.word 0x180C000A, water_skybox, water_skybox_end
.word 0x1A0C0009, castle_grounds_textures, castle_grounds_textures_end
.word 0x180C0005, piano_books, piano_books_end
.word 0x170C000C, bookend_chair_piano_boo, bookend_chair_piano_boo_end
.word 0x180C0008, chuckya_shyguy_goomba, chuckya_shyguy_goomba_end
.word 0x170C000F, cannon_box_switch_enemies, cannon_box_switch_enemies_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x15000660
.word 0x06080000, 0x1500084C
.word 0x22080018, 0x16001000
.word 0x22080027, 0x160004D0
.word 0x22080003, 0x0E000200
.word 0x1F080100, 0x0E000218
.word 0x24181F54, 0xF6C8FF9C, 0xF5680000, 0x00000000, 0x01050000, beh_boo_with_cage
.word 0x24181F00, 0x00000033, 0xFC180000, 0x00B40000, 0x000A0000, beh_warps_8C
.word 0x24181F00, 0x00000033, 0xFC180000, 0x00B40000, 0x000B0000, beh_warps_90
.word 0x26080504, 0x010A0000
.word 0x26080A1A, 0x010A0000
.word 0x26080B1A, 0x010B0000
.word 0x26080106, 0x01020000
.word 0x2608F110, 0x01030000
.word 0x06080000, 0x0E000000
.word 0x06080000, 0x0E00004C
.word 0x2E080000, 0x070059A8
.word 0x39080000, 0x07006E20
.word 0x36080000, 0x00000000
.word 0x31040001
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x0000FFF2, 0x0000FF37
.word 0x11080000, lvl_init_or_update # 8024BB38
.word 0x12080001, lvl_init_or_update # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin castle_courtyard_level alignment 0x4AD80C
.byte 0x00, 0x00, 0x00, 0x00
# begin castle_courtyard_level geo 0x4AD810
# 0200
.word 0x20000A28
.word 0x04000000
.word   0x15010000, 0x07005078
.word 0x05000000
.word 0x01000000
.word 0x0800000A, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x19000000, Geo19_802763D4
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A01002D, 0x00643200, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F000010, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x070048B8
.word         0x15060000, 0x07005698
.word         0x15040000, 0x07005938
.word         0x18000000, Geo18_802D01E0
.word         0x18002601, Geo18_802D104C
.word         0x17000000
.word         0x18000000, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
castle_courtyard_level_end:
