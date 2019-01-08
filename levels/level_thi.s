.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/thi_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    return

script_func_local_2:
    object /*model*/ MODEL_NONE,    /*pos*/     0, -700, -4500, /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ beh_hidden_star,          /*acts*/ ALL_ACTS
    return

script_func_local_3:
    object /*model*/ MODEL_NONE,    /*pos*/ -1800,  800, -1500, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ beh_hidden_red_coin_star, /*acts*/ ALL_ACTS
    object /*model*/ MODEL_WIGGLER, /*pos*/    17, 1843,   -62, /*angle*/ 0, 0, 0, /*behParam*/ 0x05000000, /*beh*/ bWiggler
    return

script_func_local_4:
    object /*model*/ MODEL_KOOPA_WITH_SHELL, /*pos*/ -1900,  -511,  2400, /*angle*/ 0, -30, 0, /*behParam*/ 0x02030000, /*beh*/ bKoopa,             /*acts*/ ACT_3
    object /*model*/ MODEL_NONE,             /*pos*/  7400, -1537, -6300, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bKoopaRaceEndpoint, /*acts*/ ACT_3
    object /*model*/ MODEL_NONE,             /*pos*/ -6556, -2969,  6565, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bGoombaTripletSpawner
    object /*model*/ MODEL_GOOMBA,           /*pos*/  6517, -2559,  4327, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bGoomba
    object /*model*/ MODEL_PIRANHA_PLANT,    /*pos*/ -6336, -2047, -3861, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bFirePiranhaPlant
    object /*model*/ MODEL_PIRANHA_PLANT,    /*pos*/ -5740, -2047, -6578, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bFirePiranhaPlant
    object /*model*/ MODEL_PIRANHA_PLANT,    /*pos*/ -6481, -2047, -5998, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bFirePiranhaPlant
    object /*model*/ MODEL_PIRANHA_PLANT,    /*pos*/ -5577, -2047, -4961, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bFirePiranhaPlant
    object /*model*/ MODEL_PIRANHA_PLANT,    /*pos*/ -6865, -2047, -4568, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bFirePiranhaPlant
    object /*model*/ MODEL_NONE,             /*pos*/ -4413,   204, -2140, /*angle*/ 0,   0, 0, /*behParam*/ 0x00030000, /*beh*/ beh_thi_bowling_ball_spawner
    object /*model*/ MODEL_BUBBA,            /*pos*/ -6241, -3300,  -716, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bubba
    object /*model*/ MODEL_BUBBA,            /*pos*/  1624, -3300,  8142, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_bubba
    return

script_func_local_5:
    object /*model*/ MODEL_THI_HUGE_ISLAND_TOP, /*pos*/     0, 3891, -1533, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_thi_huge_island_top
    return

script_func_local_6:
    object /*model*/ MODEL_THI_TINY_ISLAND_TOP, /*pos*/     0, 1167,  -460, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_thi_tiny_island_top
    object /*model*/ MODEL_NONE,                /*pos*/ -1382,   80,  -649, /*angle*/ 0, 0, 0, /*behParam*/ 0x00040000, /*beh*/ beh_thi_bowling_ball_spawner
    return

script_func_local_7:
    object /*model*/ MODEL_THI_WARP_PIPE, /*pos*/  6656, -1536, -5632, /*angle*/ 0, 0, 0, /*behParam*/ 0x00320000, /*beh*/ beh_warp_pipe
    object /*model*/ MODEL_THI_WARP_PIPE, /*pos*/ -5888, -2048, -5888, /*angle*/ 0, 0, 0, /*behParam*/ 0x00330000, /*beh*/ beh_warp_pipe
    object /*model*/ MODEL_THI_WARP_PIPE, /*pos*/ -3072,   512, -3840, /*angle*/ 0, 0, 0, /*behParam*/ 0x00340000, /*beh*/ beh_warp_pipe
    warp_node /*id*/ 0x32, /*destLevel*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x32, /*unk6*/ 0x0000
    warp_node /*id*/ 0x33, /*destLevel*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x33, /*unk6*/ 0x0000
    warp_node /*id*/ 0x34, /*destLevel*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x34, /*unk6*/ 0x0000
    return

script_func_local_8:
    object /*model*/ MODEL_THI_WARP_PIPE, /*pos*/  1997, -461, -1690, /*angle*/ 0, 0, 0, /*behParam*/ 0x00320000, /*beh*/ beh_warp_pipe
    object /*model*/ MODEL_THI_WARP_PIPE, /*pos*/ -1766, -614, -1766, /*angle*/ 0, 0, 0, /*behParam*/ 0x00330000, /*beh*/ beh_warp_pipe
    object /*model*/ MODEL_THI_WARP_PIPE, /*pos*/  -922,  154, -1152, /*angle*/ 0, 0, 0, /*behParam*/ 0x00340000, /*beh*/ beh_warp_pipe
    warp_node /*id*/ 0x32, /*destLevel*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x32, /*unk6*/ 0x0000
    warp_node /*id*/ 0x33, /*destLevel*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x33, /*unk6*/ 0x0000
    warp_node /*id*/ 0x34, /*destLevel*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x34, /*unk6*/ 0x0000
    return

glabel level_thi_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_thi_segment_7SegmentRomStart, /*romEnd*/ _level_thi_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _wf_textures_mio0SegmentRomStart, /*romEnd*/ _wf_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _water_skybox_mio0SegmentRomStart, /*romEnd*/ _water_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _bubba_wiggler_lakitu_mio0SegmentRomStart, /*romEnd*/ _bubba_wiggler_lakitu_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _bubba_wiggler_lakitu_geoSegmentRomStart,  /*romEnd*/ _bubba_wiggler_lakitu_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _koopa_log_piranha_whomp_chomp_mio0SegmentRomStart, /*romEnd*/ _koopa_log_piranha_whomp_chomp_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _koopa_log_piranha_whomp_chomp_geoSegmentRomStart,  /*romEnd*/ _koopa_log_piranha_whomp_chomp_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behParam*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_12
    jump_link /*target*/ script_func_global_15
    load_model_from_geo /*model*/ MODEL_THI_BUBBLY_TREE, /*geo*/ bubbly_tree_geo
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_03, /*geo*/ thi_geo_0005F0
    load_model_from_geo /*model*/ MODEL_THI_WARP_PIPE, /*geo*/ warp_pipe_geo
    load_model_from_geo /*model*/ MODEL_THI_HUGE_ISLAND_TOP, /*geo*/ thi_geo_0005B0
    load_model_from_geo /*model*/ MODEL_THI_TINY_ISLAND_TOP, /*geo*/ thi_geo_0005C8

    area /*index*/ 1, /*geo*/ thi_geo_000608
        object /*model*/ MODEL_NONE, /*pos*/ -7372, -1969,  7373, /*angle*/ 0, 149, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*model*/ MODEL_NONE, /*pos*/   410,  -512,   922, /*angle*/ 0,   0, 0, /*behParam*/ 0x000B0000, /*beh*/ beh_warps_60
        object /*model*/ MODEL_NONE, /*pos*/   410,  -512,   717, /*angle*/ 0,   0, 0, /*behParam*/ 0x050C0000, /*beh*/ beh_warp
        object /*model*/ MODEL_NONE, /*pos*/     0,  3170, -1570, /*angle*/ 0,   0, 0, /*behParam*/ 0x0A0D0000, /*beh*/ beh_warp
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0B, /*destLevel*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0C, /*destLevel*/ 0x0D, /*destArea*/ 0x03, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0D, /*destLevel*/ 0x0D, /*destArea*/ 0x03, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x37, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x69, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_7
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_5
        jump_link /*target*/ script_func_local_4
        terrain /*terrainData*/ thi_seg7_area_1_collision
        macro_objects /*objList*/ thi_seg7_area_1_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0003
        terrain_type /*terrainType*/ 0x0000
    end_area

    area /*index*/ 2, /*geo*/ thi_geo_0006D4
        object /*model*/ MODEL_NONE, /*pos*/ -2211,  110,  2212, /*angle*/ 0,  149, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*model*/ MODEL_NONE, /*pos*/   280, -767, -4180, /*angle*/ 0,    0, 0, /*behParam*/ 0x000B0000, /*beh*/ beh_fading_warp
        object /*model*/ MODEL_NONE, /*pos*/ -1638,    0, -1988, /*angle*/ 0, -126, 0, /*behParam*/ 0x000C0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0B, /*destLevel*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x0C, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0C, /*destLevel*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x33, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x65, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_8
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_6
        terrain /*terrainData*/ thi_seg7_area_2_collision
        macro_objects /*objList*/ thi_seg7_area_2_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0003
        terrain_type /*terrainType*/ 0x0000
    end_area

    area /*index*/ 3, /*geo*/ thi_geo_00079C
        object /*model*/ MODEL_NONE, /*pos*/ 512, 1024, 2150, /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_60
        object /*model*/ MODEL_NONE, /*pos*/   0, 3277,    0, /*angle*/ 0,   0, 0, /*behParam*/ 0x000B0000, /*beh*/ beh_warps_64
        object /*model*/ MODEL_NONE, /*pos*/ 512, 1024, 2355, /*angle*/ 0,   0, 0, /*behParam*/ 0x050C0000, /*beh*/ beh_warp
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x0D, /*destArea*/ 0x03, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0B, /*destLevel*/ 0x0D, /*destArea*/ 0x03, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0C, /*destLevel*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x37, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x69, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ thi_seg7_area_3_collision
        macro_objects /*objList*/ thi_seg7_area_3_macro_objs
        set_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0000
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 149, /*pos*/ -7372, -2969, 7373
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_thi.s"
.align 4
