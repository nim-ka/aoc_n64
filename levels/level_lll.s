.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/lll_seg7.mio0"
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
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -1919, 307, 3648, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lll_drawbridge_spawner
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
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ 0, 307, -4385, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_big_bully
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ 4046, 2234, -5521, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_big_bully_with_minions
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
    object /*unk2*/ 0x1F, /*unk3*/ 0xCA, /*pos*/ -764, 0, 1664, /*angle*/ 0, 180, 0, /*behArg*/ 0x08A50000, /*beh*/ bPlatformOnTrack
    object /*unk2*/ 0x1F, /*unk3*/ 0xCA, /*pos*/ 184, 980, -1366, /*angle*/ 0, 180, 0, /*behArg*/ 0x08A60000, /*beh*/ bPlatformOnTrack
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -26, 103, -2649, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_volcano_sound_loop
    return

script_func_local_7:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 2523, 3850, -901, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 1800, 3400, 1450, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_lll_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_lll_segment_7SegmentRomStart, /*romEnd*/ _level_lll_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _lll_textures_mio0SegmentRomStart, /*romEnd*/ _lll_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bitfs_skybox_mio0SegmentRomStart, /*romEnd*/ _bitfs_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_textures_mio0SegmentRomStart, /*romEnd*/ _flower_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _bully_blargg_mio0SegmentRomStart, /*romEnd*/ _bully_blargg_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _bully_blargg_geoSegmentRomStart,  /*romEnd*/ _bully_blargg_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _mr_i_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomStart, /*romEnd*/ _mr_i_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _mr_i_swoop_snufit_dorrie_scuttlebug_geoSegmentRomStart,  /*romEnd*/ _mr_i_swoop_snufit_dorrie_scuttlebug_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_3
    jump_link /*target*/ script_func_global_18
    cmd22 /*unk2*/ 0x0003, /*unk4*/ lll_geo_0009E0
    cmd22 /*unk2*/ 0x0004, /*unk4*/ lll_geo_0009F8
    cmd22 /*unk2*/ 0x0005, /*unk4*/ lll_geo_000A10
    cmd22 /*unk2*/ 0x0006, /*unk4*/ lll_geo_000A28
    cmd22 /*unk2*/ 0x0007, /*unk4*/ lll_geo_000A40
    cmd22 /*unk2*/ 0x0008, /*unk4*/ lll_geo_000A60
    cmd22 /*unk2*/ 0x000A, /*unk4*/ lll_geo_000A90
    cmd22 /*unk2*/ 0x000B, /*unk4*/ lll_geo_000AA8
    cmd22 /*unk2*/ 0x000C, /*unk4*/ lll_geo_000AC0
    cmd22 /*unk2*/ 0x000D, /*unk4*/ lll_geo_000AD8
    cmd22 /*unk2*/ 0x000E, /*unk4*/ lll_geo_000AF0
    cmd22 /*unk2*/ 0x0038, /*unk4*/ lll_geo_000B20
    cmd22 /*unk2*/ 0x003A, /*unk4*/ lll_geo_000B38
    cmd22 /*unk2*/ 0x003E, /*unk4*/ lll_geo_000BB0
    cmd22 /*unk2*/ 0x003F, /*unk4*/ lll_geo_000BC8
    cmd22 /*unk2*/ 0x0040, /*unk4*/ lll_geo_000BE0
    cmd22 /*unk2*/ 0x0041, /*unk4*/ lll_geo_000BF8
    cmd22 /*unk2*/ 0x0043, /*unk4*/ lll_geo_000C10
    cmd22 /*unk2*/ 0x0044, /*unk4*/ lll_geo_000C30
    cmd22 /*unk2*/ 0x0045, /*unk4*/ lll_geo_000C50
    cmd22 /*unk2*/ 0x0046, /*unk4*/ lll_geo_000C70
    cmd22 /*unk2*/ 0x0047, /*unk4*/ lll_geo_000C90
    cmd22 /*unk2*/ 0x0048, /*unk4*/ lll_geo_000CB0
    cmd22 /*unk2*/ 0x0049, /*unk4*/ lll_geo_000CD0
    cmd22 /*unk2*/ 0x004A, /*unk4*/ lll_geo_000CF0
    cmd22 /*unk2*/ 0x004B, /*unk4*/ lll_geo_000D10
    cmd22 /*unk2*/ 0x004C, /*unk4*/ lll_geo_000D30
    cmd22 /*unk2*/ 0x004D, /*unk4*/ lll_geo_000D50
    cmd22 /*unk2*/ 0x004E, /*unk4*/ lll_geo_000D70
    cmd22 /*unk2*/ 0x004F, /*unk4*/ lll_geo_000D90
    cmd22 /*unk2*/ 0x0050, /*unk4*/ lll_geo_000DB0
    cmd22 /*unk2*/ 0x0036, /*unk4*/ lll_geo_000B08
    cmd22 /*unk2*/ 0x0037, /*unk4*/ lll_geo_000DD0
    cmd22 /*unk2*/ 0x0039, /*unk4*/ lll_geo_000DE8
    cmd22 /*unk2*/ 0x0009, /*unk4*/ lll_geo_000A78
    cmd22 /*unk2*/ 0x0035, /*unk4*/ lll_geo_000B50
    cmd22 /*unk2*/ 0x003B, /*unk4*/ lll_geo_000B68
    cmd22 /*unk2*/ 0x003C, /*unk4*/ lll_geo_000B80
    cmd22 /*unk2*/ 0x003D, /*unk4*/ lll_geo_000B98
    cmd22 /*unk2*/ 0x0053, /*unk4*/ lll_geo_000EA8

    area /*index*/ 1, /*geo*/ lll_geo_000E00
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
        terrain /*terrainData*/ lll_seg7_area_1_collision
        cmd39 /*unk4*/ lll_seg7_area_1_macro_objs
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x61
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0006
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 2, /*geo*/ lll_geo_000EC0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -955, 1103, -1029, /*angle*/ 0, 118, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x16, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x32, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x64, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_6
        jump_link /*target*/ script_func_local_7
        terrain /*terrainData*/ lll_seg7_area_2_collision
        cmd39 /*unk4*/ lll_seg7_area_2_macro_objs
        set_music /*unk2*/ 0x0004, /*seq*/ 0x0006
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
.include "levels/geo/level_lll.s"
.align 4
