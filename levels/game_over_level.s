# level script game_over_level from 268020-268520
.include "macros.inc"
.global game_over_level
.align 4, 0
game_over_level:
.word 0x1B040000
.word 0x16100000, __segCodeSection, __text8016F000pos, __text8016F000end
.word 0x170C0013, __load_behavior_data, __load_behavior_data_end
.word 0x180C0007, wood_trademark, wood_trademark_end
.word 0x1D040000
.word 0x1F080100, 0x140002D0
.word 0x20040000
.word 0x1E040000
.word 0x29040100
.word 0x11080000, LevelProc_8016F508 # 8016F508
.word 0x0304004B
.word 0x33080110, 0x00000000
.word 0x03040010
.word 0x2A040100
.word 0x1C040000
.word 0x03040002
.word 0x01100014, game_over_level, game_over_level_end, 0x14000078
.word 0x1B040000
.word 0x34040100
.word 0x16100000, run_press_start_demo_timer, __text8016F000pos, game_over_level
.word 0x19040002
.word 0x170C0013, __load_behavior_data, __load_behavior_data_end
.word 0x1A0C000A, mario_bg, mario_bg_end
.word 0x1D040000
.word 0x1F080100, 0x1400035C
.word 0x20040000
.word 0x1E040000
.word 0x03040002
.word 0x34040000
.word 0x29040100
.word 0x37040002
.word 0x33080814, 0x00000000
.word 0x03040014
.word 0x12080001, LevelProc_8016F508 # 8016F508
.word 0x0C0C0200, 0x00000064, 0x1400020C
.word 0x0C0C0200, 0x00000065, 0x14000238
.word 0x05080000, 0x14000284
.word 0x1B040000
.word 0x34040100
.word 0x16100000, run_press_start_demo_timer, __text8016F000pos, game_over_level
.word 0x19040003
.word 0x170C0013, __load_behavior_data, __load_behavior_data_end
.word 0x1A0C000A, mario_bg, mario_bg_end
.word 0x1D040000
.word 0x1F080100, 0x140003B8
.word 0x20040000
.word 0x1E040000
.word 0x03040002
.word 0x34040000
.word 0x29040100
.word 0x37040082
.word 0x33080814, 0x00000000
.word 0x03040014
.word 0x12080002, LevelProc_8016F508 # 8016F508
.word 0x0C0C0200, 0x00000064, 0x1400020C
.word 0x0C0C0200, 0x00000065, 0x14000238
.word 0x05080000, 0x14000284
.word 0x1B040000
.word 0x170C0013, __load_behavior_data, __load_behavior_data_end
.word 0x1A0C000A, mario_bg, mario_bg_end
.word 0x180C0007, debug_level_select, debug_level_select_end
.word 0x16100000, run_press_start_demo_timer, __text8016F000pos, game_over_level
.word 0x1D040000
.word 0x1F080100, 0x14000414
.word 0x20040000
.word 0x1E040000
.word 0x29040100
.word 0x37040002
.word 0x33080010, 0xFFFFFF00
.word 0x03040010
.word 0x12080003, LevelProc_8016F508 # 8016F508
.word 0x0C0C0200, 0xFFFFFFFF, 0x140002A8
.word 0x05080000, 0x1400025C
.word 0x380400BE
.word 0x33080110, 0xFFFFFF00
.word 0x03040010
.word 0x1C040000
.word 0x03040002
.word 0x13040010
.word 0x01100014, main_menu_level, main_menu_level_end, 0x14000000
.word 0x33080110, 0xFFFFFF00
.word 0x03040010
.word 0x1C040000
.word 0x03040002
.word 0x01100014, game_over_level, game_over_level_end, 0x14000190
.word 0x380400BE
.word 0x33080110, 0xFFFFFF00
.word 0x03040010
.word 0x1C040000
.word 0x03040002
.word 0x01100015, main_level_scripts, main_level_scripts_end, 0x15000000
.word 0x33080110, 0xFFFFFF00
.word 0x03040010
.word 0x1C040000
.word 0x03040002
.word 0x01100015, main_level_scripts, main_level_scripts_end, 0x15000000
.word 0x380400BE
.word 0x33080110, 0x00000000
.word 0x03040010
.word 0x1C040000
.word 0x03040002
.word 0x01100014, game_over_level, game_over_level_end, 0x14000000
# begin game_over_level geo 0x2682F0
.word 0x08000000, 0x00A00078, 0x00A00078
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
.word     0x0A00002D, 0x00804000
.word     0x04000000
.word       0x0F000000, 0x00000000, 0x0C800000, 0x00000000, 0x00000000
.word       0x04000000
.word         0x18000000, Geo18_8016F670
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word   0x0C000000
.word   0x04000000
.word     0x18000000, Geo18_8016F984
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x08000000, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x18000000, Geo18_8016FE70
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A00002D, 0x00804000
.word     0x04000000
.word       0x18000002, Geo18_802764B0
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x08000000, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x18000000, Geo18_8016FFFC
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A00002D, 0x00804000
.word     0x04000000
.word       0x18000003, Geo18_802764B0
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x08000000, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x18000000, Geo18_8016FE70
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A00002D, 0x00804000
.word     0x04000000
.word       0x0F000000, 0x00000000, 0x04B00000, 0x00000000, 0x00000000
.word       0x04000000
.word         0x1181FF1A, 0x012C0000, 0x07000858
.word         0x1181FF88, 0x012C0000, 0x07001100
.word         0x1181FFEC, 0x012C0000, 0x07001BA0
.word         0x11810064, 0x012C0000, 0x070025F0
.word         0x118100FA, 0x012C0000, 0x07003258
.word         0x1181FECA, 0x00640000, 0x07003DB8
.word         0x1181FFA6, 0x00640000, 0x070048C8
.word         0x1181003C, 0x00640000, 0x07005558
.word         0x118100B4, 0x00640000, 0x070059F8
.word         0x1181012C, 0x00640000, 0x070063B0
.word       0x05000000
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x00000000
glabel game_over_level_end
