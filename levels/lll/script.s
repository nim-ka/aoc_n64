# Unlike most levels, level geometry objects in LLL are defined as regular objects instead of terrain objects.
script_func_local_1:
    object /*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  3840,   0, -5631, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/  4992,   0,  -639, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_05, /*pos*/  7168,   0,  1408, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_06, /*pos*/     0,   0,  3712, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_07, /*pos*/ -3199,   0,  3456, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_08, /*pos*/ -5119,   0, -2047, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0A, /*pos*/     0,   0,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0B, /*pos*/     0,   0,  6272, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/  5632,   0,  1408, /*angle*/ 0, 270, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/  2048,   0,  3456, /*angle*/ 0, 180, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/ -4607,   0,  3456, /*angle*/ 0, 270, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/ -5119,   0,  -511, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
    object /*model*/ MODEL_LEVEL_GEOMETRY_0D, /*pos*/     0,   0, -2047, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_static_object
	# This behavior differs from the rest in that it actually has collision rather than being purely visual.
	# A likely explanation is that this object was added in after the collision model was made, and they didn't want
	# to redo the collision so they just added a new behavior for it.
    object /*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -5115, 300, -3200, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_hexagonal_mesh
    return

script_func_local_2:
    object /*model*/ MODEL_LLL_DRAWBRIDGE_PART,              /*pos*/ -1919,  307,  3648, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_drawbridge_spawner
    object /*model*/ MODEL_LLL_ROTATING_BLOCK_FIRE_BARS,     /*pos*/ -5119,  307, -4095, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_rotating_block_with_fire_bars
    object /*model*/ MODEL_LLL_ROTATING_HEXAGONAL_RING,      /*pos*/     0,    0,     0, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_rotating_hexagonal_ring
    object /*model*/ MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, /*pos*/  3968,    0,  1408, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_sinking_rectangular_platform
    object /*model*/ MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, /*pos*/ -5759,    0,  3072, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_sinking_rectangular_platform
    object /*model*/ MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, /*pos*/  2816,    0,   512, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_sinking_rectangular_platform
    object /*model*/ MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, /*pos*/ -1791,    0, -4095, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_sinking_rectangular_platform
    object /*model*/ MODEL_LLL_SINKING_SQUARE_PLATFORMS,     /*pos*/  3840,    0, -3199, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_sinking_square_platforms
    object /*model*/ MODEL_LLL_TILTING_SQUARE_PLATFORM,      /*pos*/   922, -153,  2150, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_tilting_square_platform
    object /*model*/ MODEL_LLL_TILTING_SQUARE_PLATFORM,      /*pos*/  1741, -153,  1741, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_tilting_square_platform
    object /*model*/ MODEL_LLL_TILTING_SQUARE_PLATFORM,      /*pos*/  1741, -153,  2560, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_tilting_square_platform
    object /*model*/ MODEL_LLL_TILTING_SQUARE_PLATFORM,      /*pos*/  2099, -153,  -306, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_tilting_square_platform
    object /*model*/ MODEL_NONE,                             /*pos*/ -5119,  102,  1024, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_bowser_puzzle
    return

script_func_local_3:
    object /*model*/ MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, /*pos*/  1124,   0, -4607, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_moving_octagonal_mesh_platform
    object /*model*/ MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, /*pos*/  7168,   0,  2432, /*angle*/ 0,  0, 0, /*behParam*/ 0x00010000, /*beh*/ beh_lll_moving_octagonal_mesh_platform
    object /*model*/ MODEL_LLL_SINKING_ROCK_BLOCK,             /*pos*/  7168,   0,  7296, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_sinking_rock_block
    object /*model*/ MODEL_LLL_ROLLING_LOG,                    /*pos*/  6144, 307,  6016, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_rolling_log
    object /*model*/ MODEL_LLL_ROTATING_HEXAGONAL_PLATFORM,    /*pos*/ -5119,   0, -4095, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_rotating_hexagonal_platform
    object /*model*/ MODEL_NONE,                               /*pos*/ -3583,   0, -4095, /*angle*/ 0,  0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_floating_wood_bridge
    return

script_func_local_4:
    object /*model*/ MODEL_NONE,            /*pos*/ -3199,  307,  3456, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_mr_i
    object /*model*/ MODEL_BULLY_BOSS,      /*pos*/     0,  307, -4385, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_big_bully
    object /*model*/ MODEL_BULLY_BOSS,      /*pos*/  4046, 2234, -5521, /*angle*/ 0,   0, 0, /*behParam*/ 0x01000000, /*beh*/ beh_big_bully_with_minions
    object /*model*/ MODEL_BULLY,           /*pos*/ -5119,  307, -2482, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_small_bully
    object /*model*/ MODEL_BULLY,           /*pos*/     0,  307,  3712, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_small_bully
    object /*model*/ MODEL_BULLY,           /*pos*/  6813,  307,  1613, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_small_bully
    object /*model*/ MODEL_BULLY,           /*pos*/  7168,  307,   998, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_small_bully
    object /*model*/ MODEL_BULLY,           /*pos*/ -5130,  285, -1663, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_small_bully
    object /*model*/ MODEL_NONE,            /*pos*/     0,  200, -2048, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*model*/ MODEL_NONE,            /*pos*/   500,    2,  5000, /*angle*/ 0, 270, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_NONE,            /*pos*/  -700,    2,  4500, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_NONE,            /*pos*/ -6300,    2,  2625, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_NONE,            /*pos*/ -3280,    2, -4854, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_NONE,            /*pos*/  5996,    2,  -390, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_NONE,            /*pos*/  5423,    2, -1991, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_NONE,            /*pos*/  4921,    2, -1504, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bouncing_fireball
    object /*model*/ MODEL_EXCLAMATION_BOX, /*pos*/  1050,  550,  6200, /*angle*/ 0,   0, 0, /*behParam*/ 0x00030000, /*beh*/ beh_exclamation_box, /*acts*/ ACT_5 | ACT_6
    return

script_func_local_5:
    object /*model*/ MODEL_NONE, /*pos*/ -4400, 350,  250, /*angle*/ 0, 0, 0, /*behParam*/ 0x02000000, /*beh*/ beh_hidden_red_coin_star, /*acts*/ ALL_ACTS
    object /*model*/ MODEL_STAR, /*pos*/  3100, 400, 7900, /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ beh_star,                 /*acts*/ ALL_ACTS
    return

script_func_local_6:
    object /*model*/ MODEL_NONE,                         /*pos*/   728, 2606, -2754, /*angle*/ 0,   0, 0, /*behParam*/ 0x00380000, /*beh*/ beh_pole_grabbing
    object /*model*/ MODEL_NONE,                         /*pos*/  1043, 2972, -2679, /*angle*/ 0,   0, 0, /*behParam*/ 0x004E0000, /*beh*/ beh_pole_grabbing
    object /*model*/ MODEL_NONE,                         /*pos*/  1078, 3078, -2269, /*angle*/ 0,   0, 0, /*behParam*/ 0x00660000, /*beh*/ beh_pole_grabbing
    object /*model*/ MODEL_NONE,                         /*pos*/  1413, 3222, -2190, /*angle*/ 0,   0, 0, /*behParam*/ 0x00520000, /*beh*/ beh_pole_grabbing
    object /*model*/ MODEL_NONE,                         /*pos*/   783, 1126,   -47, /*angle*/ 0,   0, 0, /*behParam*/ 0x00660000, /*beh*/ beh_pole_grabbing
    object /*model*/ MODEL_NONE,                         /*pos*/   662, 2150,   708, /*angle*/ 0,   0, 0, /*behParam*/ 0x00660000, /*beh*/ beh_pole_grabbing
    object /*model*/ MODEL_NONE,                         /*pos*/  2943,  476,    10, /*angle*/ 0, 270, 0, /*behParam*/ 0x00020000, /*beh*/ beh_flamethrower
    object /*model*/ MODEL_NONE,                         /*pos*/ -2759, 2350, -1108, /*angle*/ 0,  60, 0, /*behParam*/ 0x00020000, /*beh*/ beh_flamethrower
    object /*model*/ MODEL_NONE,                         /*pos*/ -2472, 2350, -1605, /*angle*/ 0,  60, 0, /*behParam*/ 0x00020000, /*beh*/ beh_flamethrower
    object /*model*/ MODEL_LLL_VOLCANO_FALLING_TRAP,     /*pos*/  -485, 1203,  2933, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_volcano_falling_trap
    object /*model*/ MODEL_LLL_ROTATING_BLOCK_FIRE_BARS, /*pos*/   417, 2150,   583, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_lll_rotating_block_with_fire_bars
    object /*model*/ MODEL_CHECKERBOARD_PLATFORM,        /*pos*/  -764,    0,  1664, /*angle*/ 0, 180, 0, /*behParam*/ 0x08A50000, /*beh*/ bPlatformOnTrack
    object /*model*/ MODEL_CHECKERBOARD_PLATFORM,        /*pos*/   184,  980, -1366, /*angle*/ 0, 180, 0, /*behParam*/ 0x08A60000, /*beh*/ bPlatformOnTrack
    object /*model*/ MODEL_NONE,                         /*pos*/   -26,  103, -2649, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_volcano_sound_loop
    return

script_func_local_7:
    object /*model*/ MODEL_STAR, /*pos*/ 2523, 3850, -901, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ beh_star, /*acts*/ ALL_ACTS
    object /*model*/ MODEL_STAR, /*pos*/ 1800, 3400, 1450, /*angle*/ 0, 0, 0, /*behParam*/ 0x05000000, /*beh*/ beh_star, /*acts*/ ALL_ACTS
    return

glabel level_lll_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _lll_segment_7SegmentRomStart, /*romEnd*/ _lll_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _fire_mio0SegmentRomStart, /*romEnd*/ _fire_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bitfs_skybox_mio0SegmentRomStart, /*romEnd*/ _bitfs_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _effect_mio0SegmentRomStart, /*romEnd*/ _effect_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _group2_mio0SegmentRomStart, /*romEnd*/ _group2_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _group2_geoSegmentRomStart,  /*romEnd*/ _group2_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _group17_mio0SegmentRomStart, /*romEnd*/ _group17_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _group17_geoSegmentRomStart,  /*romEnd*/ _group17_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _common0_mio0SegmentRomStart, /*romEnd*/ _common0_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _common0_geoSegmentRomStart,  /*romEnd*/ _common0_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behParam*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_3
    jump_link /*target*/ script_func_global_18
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_03, /*geo*/ lll_geo_0009E0
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_04, /*geo*/ lll_geo_0009F8
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_05, /*geo*/ lll_geo_000A10
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_06, /*geo*/ lll_geo_000A28
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_07, /*geo*/ lll_geo_000A40
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_08, /*geo*/ lll_geo_000A60
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_0A, /*geo*/ lll_geo_000A90
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_0B, /*geo*/ lll_geo_000AA8
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_0C, /*geo*/ lll_geo_000AC0
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_0D, /*geo*/ lll_geo_000AD8
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_0E, /*geo*/ lll_geo_000AF0
    load_model_from_geo /*model*/ MODEL_LLL_DRAWBRIDGE_PART,                /*geo*/ lll_geo_000B20
    load_model_from_geo /*model*/ MODEL_LLL_ROTATING_BLOCK_FIRE_BARS,       /*geo*/ lll_geo_000B38
    load_model_from_geo /*model*/ MODEL_LLL_ROTATING_HEXAGONAL_RING,        /*geo*/ lll_geo_000BB0
    load_model_from_geo /*model*/ MODEL_LLL_SINKING_RECTANGULAR_PLATFORM,   /*geo*/ lll_geo_000BC8
    load_model_from_geo /*model*/ MODEL_LLL_SINKING_SQUARE_PLATFORMS,       /*geo*/ lll_geo_000BE0
    load_model_from_geo /*model*/ MODEL_LLL_TILTING_SQUARE_PLATFORM,        /*geo*/ lll_geo_000BF8
    load_model_from_geo /*model*/ MODEL_LLL_43,                             /*geo*/ lll_geo_000C10
    load_model_from_geo /*model*/ MODEL_LLL_44,                             /*geo*/ lll_geo_000C30
    load_model_from_geo /*model*/ MODEL_LLL_45,                             /*geo*/ lll_geo_000C50
    load_model_from_geo /*model*/ MODEL_LLL_46,                             /*geo*/ lll_geo_000C70
    load_model_from_geo /*model*/ MODEL_LLL_47,                             /*geo*/ lll_geo_000C90
    load_model_from_geo /*model*/ MODEL_LLL_48,                             /*geo*/ lll_geo_000CB0
    load_model_from_geo /*model*/ MODEL_LLL_49,                             /*geo*/ lll_geo_000CD0
    load_model_from_geo /*model*/ MODEL_LLL_4A,                             /*geo*/ lll_geo_000CF0
    load_model_from_geo /*model*/ MODEL_LLL_4B,                             /*geo*/ lll_geo_000D10
    load_model_from_geo /*model*/ MODEL_LLL_4C,                             /*geo*/ lll_geo_000D30
    load_model_from_geo /*model*/ MODEL_LLL_4D,                             /*geo*/ lll_geo_000D50
    load_model_from_geo /*model*/ MODEL_LLL_4E,                             /*geo*/ lll_geo_000D70
    load_model_from_geo /*model*/ MODEL_LLL_4F,                             /*geo*/ lll_geo_000D90
    load_model_from_geo /*model*/ MODEL_LLL_50,                             /*geo*/ lll_geo_000DB0
    load_model_from_geo /*model*/ MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, /*geo*/ lll_geo_000B08
    load_model_from_geo /*model*/ MODEL_LLL_SINKING_ROCK_BLOCK,             /*geo*/ lll_geo_000DD0
    load_model_from_geo /*model*/ MODEL_LLL_ROLLING_LOG,                    /*geo*/ lll_geo_000DE8
    load_model_from_geo /*model*/ MODEL_LLL_ROTATING_HEXAGONAL_PLATFORM,    /*geo*/ lll_geo_000A78
    load_model_from_geo /*model*/ MODEL_LLL_35,                             /*geo*/ lll_geo_000B50
    load_model_from_geo /*model*/ MODEL_LLL_3B,                             /*geo*/ lll_geo_000B68
    load_model_from_geo /*model*/ MODEL_LLL_3C,                             /*geo*/ lll_geo_000B80
    load_model_from_geo /*model*/ MODEL_LLL_3D,                             /*geo*/ lll_geo_000B98
    load_model_from_geo /*model*/ MODEL_LLL_VOLCANO_FALLING_TRAP,           /*geo*/ lll_geo_000EA8

    area /*index*/ 1, /*geo*/ lll_geo_000E00
        object /*model*/ MODEL_NONE, /*pos*/ -3839, 1154, 6272, /*angle*/ 0,   90, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*model*/ MODEL_NONE, /*pos*/     0,  105,    0, /*angle*/ 0,    0, 0, /*behParam*/ 0x190B0000, /*beh*/ beh_warp
        object /*model*/ MODEL_NONE, /*pos*/ -3200,   11, 3456, /*angle*/ 0, -100, 0, /*behParam*/ 0x000C0000, /*beh*/ beh_fading_warp
        object /*model*/ MODEL_NONE, /*pos*/ -5888,  154, 6656, /*angle*/ 0,  100, 0, /*behParam*/ 0x000D0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0B, /*destLevel*/ 0x16, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*unk6*/ 0x8000
        warp_node /*id*/ 0x0C, /*destLevel*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0D, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0D, /*destLevel*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x32, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x64, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        jump_link /*target*/ script_func_local_5
        terrain /*terrainData*/ lll_seg7_area_1_collision
        macro_objects /*objList*/ lll_seg7_area_1_macro_objs
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x61
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0006
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 2, /*geo*/ lll_geo_000EC0
        object /*model*/ MODEL_NONE, /*pos*/ -955, 1103, -1029, /*angle*/ 0, 118, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x16, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x32, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x64, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_6
        jump_link /*target*/ script_func_local_7
        terrain /*terrainData*/ lll_seg7_area_2_collision
        macro_objects /*objList*/ lll_seg7_area_2_macro_objs
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
