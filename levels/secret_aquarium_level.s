# level script secret_aquarium_level from 46A0E0-46A2E0



.global secret_aquarium_level
.align 4, 0
secret_aquarium_level:
.word 0x24181F00, 0x0000FC18, 0x00000000, 0x00000000, 0x00000000, beh_large_fish_group
.word 0x24181F00, 0x0000FC18, 0x00000000, 0x00000000, 0x00020000, beh_large_fish_group
.word 0x07040000
.word 0x24181F00, 0x0000EF66, 0x00000000, 0x00000000, 0x00000000, beh_hidden_red_coin_star
.word 0x07040000
.word 0x1B040000
.word 0x180C0007, secret_aquarium_segment7, secret_aquarium_segment7_end
.word 0x1A0C0009, inside_castle_textures, inside_castle_textures_end
.word 0x180C000A, cloud_floor_skybox, cloud_floor_skybox_end
.word 0x180C000B, flower_textures, flower_textures_end
.word 0x180C0005, sea_creatures_texture, sea_creatures_texture_end
.word 0x170C000C, sea_creatures, sea_creatures_end
.word 0x180C0006, treasure_chest_fish, treasure_chest_fish_end
.word 0x170C000D, skeeter_fish_manta_chest, skeeter_fish_manta_chest_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x15000788
.word 0x06080000, 0x15000914
.word 0x1F080100, 0x0E000170
.word 0x24181F00, 0x0000FA01, 0x00000000, 0x005A0000, 0x000A0000, beh_warps_94
.word 0x26080A14, 0x010A0000
.word 0x2608F006, 0x01270000
.word 0x2608F106, 0x01280000
.word 0x06080000, 0x0E000000
.word 0x06080000, 0x0E000034
.word 0x2E080000, 0x07003000
.word 0x39080000, 0x07003284
.word 0x36080003, 0x00850000
.word 0x31040005
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x005A0000, 0xFA010000
.word 0x11080000, LevelProc_8024BCD8 # 8024BB38
.word 0x12080001, LevelProc_8024BCD8 # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin secret_aquarium_level alignment 0x46A248
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
# begin secret_aquarium_level geo 0x46A250
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
.word     0x0A01002D, 0x00643200, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F000001, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word       0x04000000
.word         0x15010000, 0x07002DE8
.word         0x15050000, 0x07002FD0
.word         0x17000000
.word         0x18000002, Geo18_802761D0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
secret_aquarium_level_end:
