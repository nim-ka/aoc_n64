.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/lll_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x03, /*pos*/ 3840, 0, -5631, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x04, /*pos*/ 4992, 0, -639, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x05, /*pos*/ 7168, 0, 1408, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x06, /*pos*/ 0, 0, 3712, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x07, /*pos*/ -3199, 0, 3456, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x08, /*pos*/ -5119, 0, -2047, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0A, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0B, /*pos*/ 0, 0, 6272, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0C, /*pos*/ 5632, 0, 1408, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0C, /*pos*/ 2048, 0, 3456, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0C, /*pos*/ -4607, 0, 3456, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0C, /*pos*/ -5119, 0, -511, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0D, /*pos*/ 0, 0, -2047, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0E, /*pos*/ -5115, 300, -3200, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_hexagonal_mesh
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -1919, 307, 3648, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bascule_bridge
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ -5119, 307, -4095, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rotating_cw_with_fire_bars
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_rotating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ 3968, 0, 1408, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_slow_tilting_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ -5759, 0, 3072, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_slow_tilting_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ 2816, 0, 512, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_slow_tilting_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ -1791, 0, -4095, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_slow_tilting_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x40, /*pos*/ 3840, 0, -3199, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_slow_up_down_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 922, -153, 2150, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_inverted_pyramid2
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 1741, -153, 1741, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_inverted_pyramid2
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 1741, -153, 2560, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_inverted_pyramid2
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 2099, -153, -306, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_inverted_pyramid2
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5119, 102, 1024, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_puzzle
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 1124, 0, -4607, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_horizontal_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 7168, 0, 2432, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_horizontal_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 7168, 0, 7296, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sinks_when_stepped_on
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 6144, 307, 6016, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pitoune
    object /*unk2*/ 0x1F, /*unk3*/ 0x09, /*pos*/ -5119, 0, -4095, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_rotating_ccw
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3583, 0, -4095, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_floating_wood_bridge
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3199, 307, 3456, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_mr_i
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ 0, 307, -4385, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_big_bully_boss
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ 4046, 2234, -5521, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -5119, 307, -2482, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ 0, 307, 3712, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ 6813, 307, 1613, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ 7168, 307, 998, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -5130, 285, -1663, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 200, -2048, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 500, 2, 5000, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -700, 2, 4500, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6300, 2, 2625, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3280, 2, -4854, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5996, 2, -390, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5423, 2, -1991, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4921, 2, -1504, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*unk2*/ 0x30, /*unk3*/ 0x89, /*pos*/ 1050, 550, 6200, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_exclamation_box
    return

script_func_local_5:
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -4400, 350, 250, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 3100, 400, 7900, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_collect_star
    return

script_func_local_6:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 728, 2606, -2754, /*angle*/ 0, 0, 0, /*behArg*/ 0x00380000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1043, 2972, -2679, /*angle*/ 0, 0, 0, /*behArg*/ 0x004E0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1078, 3078, -2269, /*angle*/ 0, 0, 0, /*behArg*/ 0x00660000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1413, 3222, -2190, /*angle*/ 0, 0, 0, /*behArg*/ 0x00520000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 783, 1126, -47, /*angle*/ 0, 0, 0, /*behArg*/ 0x00660000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 662, 2150, 708, /*angle*/ 0, 0, 0, /*behArg*/ 0x00660000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2943, 476, 10, /*angle*/ 0, 270, 0, /*behArg*/ 0x00020000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2759, 2350, -1108, /*angle*/ 0, 60, 0, /*behArg*/ 0x00020000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2472, 2350, -1605, /*angle*/ 0, 60, 0, /*behArg*/ 0x00020000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x53, /*pos*/ -485, 1203, 2933, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_when_mario_is_near
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 417, 2150, 583, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rotating_cw_with_fire_bars
    object /*unk2*/ 0x1F, /*unk3*/ 0xCA, /*pos*/ -764, 0, 1664, /*angle*/ 0, 180, 0, /*behArg*/ 0x08A50000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0xCA, /*pos*/ 184, 980, -1366, /*angle*/ 0, 180, 0, /*behArg*/ 0x08A60000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -26, 103, -2649, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_volcano_sound_loop
    return

script_func_local_7:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 2523, 3850, -901, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 1800, 3400, 1450, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_lll_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x004763C0, /*romEnd*/ 0x0048A950
    cmd1A /*seg*/ 0x09, /*romStart*/ 0x0031C770, /*romEnd*/ 0x003253E0
    load_mio0 /*seg*/ 0x0A, /*romStart*/ 0x002CE5E0, /*romEnd*/ 0x002D4A90
    load_mio0 /*seg*/ 0x0B, /*romStart*/ 0x0036DAD0, /*romEnd*/ 0x003701E0
    load_mio0 /*seg*/ 0x05, /*romStart*/ big_bully, /*romEnd*/ big_bully_end
    load_raw /*seg*/ 0x0C, /*romStart*/ bully_blargg, /*romEnd*/ bully_blargg_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ mri_swoop, /*romEnd*/ mri_swoop_end
    load_raw /*seg*/ 0x0D, /*romStart*/ mri_swoop_snufit_dorrie_scuttlebug, /*romEnd*/ mri_swoop_snufit_dorrie_scuttlebug_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_3
    jump_link /*target*/ script_func_global_18
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E0009E0
    cmd22 /*unk2*/ 0x0004, /*unk4*/ 0x0E0009F8
    cmd22 /*unk2*/ 0x0005, /*unk4*/ 0x0E000A10
    cmd22 /*unk2*/ 0x0006, /*unk4*/ 0x0E000A28
    cmd22 /*unk2*/ 0x0007, /*unk4*/ 0x0E000A40
    cmd22 /*unk2*/ 0x0008, /*unk4*/ 0x0E000A60
    cmd22 /*unk2*/ 0x000A, /*unk4*/ 0x0E000A90
    cmd22 /*unk2*/ 0x000B, /*unk4*/ 0x0E000AA8
    cmd22 /*unk2*/ 0x000C, /*unk4*/ 0x0E000AC0
    cmd22 /*unk2*/ 0x000D, /*unk4*/ 0x0E000AD8
    cmd22 /*unk2*/ 0x000E, /*unk4*/ 0x0E000AF0
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000B20
    cmd22 /*unk2*/ 0x003A, /*unk4*/ 0x0E000B38
    cmd22 /*unk2*/ 0x003E, /*unk4*/ 0x0E000BB0
    cmd22 /*unk2*/ 0x003F, /*unk4*/ 0x0E000BC8
    cmd22 /*unk2*/ 0x0040, /*unk4*/ 0x0E000BE0
    cmd22 /*unk2*/ 0x0041, /*unk4*/ 0x0E000BF8
    cmd22 /*unk2*/ 0x0043, /*unk4*/ 0x0E000C10
    cmd22 /*unk2*/ 0x0044, /*unk4*/ 0x0E000C30
    cmd22 /*unk2*/ 0x0045, /*unk4*/ 0x0E000C50
    cmd22 /*unk2*/ 0x0046, /*unk4*/ 0x0E000C70
    cmd22 /*unk2*/ 0x0047, /*unk4*/ 0x0E000C90
    cmd22 /*unk2*/ 0x0048, /*unk4*/ 0x0E000CB0
    cmd22 /*unk2*/ 0x0049, /*unk4*/ 0x0E000CD0
    cmd22 /*unk2*/ 0x004A, /*unk4*/ 0x0E000CF0
    cmd22 /*unk2*/ 0x004B, /*unk4*/ 0x0E000D10
    cmd22 /*unk2*/ 0x004C, /*unk4*/ 0x0E000D30
    cmd22 /*unk2*/ 0x004D, /*unk4*/ 0x0E000D50
    cmd22 /*unk2*/ 0x004E, /*unk4*/ 0x0E000D70
    cmd22 /*unk2*/ 0x004F, /*unk4*/ 0x0E000D90
    cmd22 /*unk2*/ 0x0050, /*unk4*/ 0x0E000DB0
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000B08
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000DD0
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E000DE8
    cmd22 /*unk2*/ 0x0009, /*unk4*/ 0x0E000A78
    cmd22 /*unk2*/ 0x0035, /*unk4*/ 0x0E000B50
    cmd22 /*unk2*/ 0x003B, /*unk4*/ 0x0E000B68
    cmd22 /*unk2*/ 0x003C, /*unk4*/ 0x0E000B80
    cmd22 /*unk2*/ 0x003D, /*unk4*/ 0x0E000B98
    cmd22 /*unk2*/ 0x0053, /*unk4*/ 0x0E000EA8

    area /*index*/ 1, /*geo*/ 0x0E000E00
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3839, 1154, 6272, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 105, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x190B0000, /*beh*/ beh_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3200, 11, 3456, /*angle*/ 0, -100, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5888, 154, 6656, /*angle*/ 0, 100, 0, /*behArg*/ 0x000D0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x16, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x80
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0D, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0D, /*destLevel1*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x32, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x64, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        jump_link /*target*/ script_func_local_5
        terrain /*terrainData*/ 0x0701ADE8
        cmd39 /*unk4*/ 0x0701CE18
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x61
        set_menu_music /*unk2*/ 0x0000, /*seq*/ 0x0006
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 2, /*geo*/ 0x0E000EC0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -955, 1103, -1029, /*angle*/ 0, 118, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x16, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x32, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x64, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_6
        jump_link /*target*/ script_func_local_7
        terrain /*terrainData*/ 0x07025F80
        cmd39 /*unk4*/ 0x070283D4
        set_menu_music /*unk2*/ 0x0004, /*seq*/ 0x0006
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -3839, 154, 6272
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_lll.geo.s"
.align 4
