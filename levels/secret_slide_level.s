# level script secret_slide_level from 4B5EB0-4B6070



.global secret_slide_level
.align 4, 0x01
secret_slide_level:
.word 0x1B040000
.word 0x180C0007, secret_slide_segment7, secret_slide_segment7_end
.word 0x1A0C0009, ttm_textures, ttm_textures_end
.word 0x180C0005, checkerboard_question, checkerboard_question_end
.word 0x170C000C, cap_switch, cap_switch_end
.word 0x180C0008, chuckya_shyguy_goomba, chuckya_shyguy_goomba_end
.word 0x170C000F, cannon_box_switch_enemies, cannon_box_switch_enemies_end
.word 0x1D040000
.word 0x250C0001, 0x00000001, beh_mario
.word 0x06080000, 0x15000660
.word 0x06080000, 0x15000830
.word 0x1F080100, 0x0E000100
.word 0x24181F00, 0x16001A5F, 0xEA010000, 0x010E0000, 0x000A0000, beh_warps_64
.word 0x26080A1B, 0x010A0000
.word 0x2608F306, 0x01200000
.word 0x2608F006, 0x01260000
.word 0x2608F106, 0x01230000
.word 0x2E080000, 0x0700E490
.word 0x39080000, 0x07010F00
.word 0x31040006
.word 0x36080001, 0x00090000
.word 0x20040000
.word 0x1E040000
.word 0x2B0C0100, 0x010E1600, 0x1933EA01
.word 0x11080000, 0x8024BB38 # 8024BB38
.word 0x12080001, 0x8024BB38 # 8024BB38
.word 0x1C040000
.word 0x04040001
.word 0x02040000
# begin secret_slide_level alignment 0x4B5FA8
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
# begin secret_slide_level geo 0x4B5FB0
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
.word     0x0A01002D, 0x00643200, 0x8029A320
.word     0x04000000
.word       0x0F000009, 0x000007D0, 0x17700000, 0x00000000, 0x80287748
.word       0x04000000
.word         0x15010000, 0x0700A7C0
.word         0x15010000, 0x0700AFA8
.word         0x15010000, 0x0700B3F0
.word         0x15010000, 0x0700D338
.word         0x15050000, 0x0700DAD8
.word         0x15010000, 0x0700E2B0
.word         0x15020000, 0x0700E3E8
.word         0x17000000
.word         0x18000000, 0x80275C20
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x00000000
.word 0x00000000
secret_slide_level_end:
