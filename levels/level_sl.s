.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/sl_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*model*/ MODEL_STAR, /*pos*/  700, 4500,  690, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_star,                 /*acts*/ ALL_ACTS
    object /*model*/ MODEL_STAR, /*pos*/ 4350, 1350, 4350, /*angle*/ 0, 0, 0, /*behParam*/ 0x02000000, /*beh*/ beh_star,                 /*acts*/ ALL_ACTS
    object /*model*/ MODEL_NONE, /*pos*/ 5000, 1200,    0, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ beh_hidden_red_coin_star, /*acts*/ ALL_ACTS
    return

script_func_local_2:
    object /*model*/ MODEL_NONE, /*pos*/  977, 1024, 2075, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_snow_mound_spawn
    return

script_func_local_3:
    object /*model*/ MODEL_PENGUIN,            /*pos*/ 1715, 3328,   518, /*angle*/ 0, -51, 0, /*behParam*/ 0x00000000, /*beh*/ beh_walking_penguin
    object /*model*/ MODEL_NONE,               /*pos*/  700, 3428,   700, /*angle*/ 0,  30, 0, /*behParam*/ 0x00000000, /*beh*/ beh_snowman_wind_blowing
    object /*model*/ MODEL_NONE,               /*pos*/  480, 2300,  1370, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_igloo
    object /*model*/ MODEL_BIG_CHILL_BULLY,    /*pos*/  315, 1331, -4852, /*angle*/ 0,   0, 0, /*behParam*/ 0x01000000, /*beh*/ beh_big_chill_bully
    object /*model*/ MODEL_MR_BLIZZARD_HIDDEN, /*pos*/ 2954,  970,   750, /*angle*/ 0,   0, 0, /*behParam*/ 0x00020000, /*beh*/ bMrBlizzard
    return

script_func_local_4:
    object /*model*/ MODEL_STAR, /*pos*/ 0, 500, 1000, /*angle*/ 0, 0, 0, /*behParam*/ 0x05000000, /*beh*/ beh_star, /*acts*/ ALL_ACTS
    return

glabel level_sl_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_sl_segment_7SegmentRomStart, /*romEnd*/ _level_sl_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _ccm_textures_mio0SegmentRomStart, /*romEnd*/ _ccm_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_bubbles_textures_mio0SegmentRomStart, /*romEnd*/ _flower_bubbles_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _ccm_skybox_mio0SegmentRomStart, /*romEnd*/ _ccm_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _group7_mio0SegmentRomStart, /*romEnd*/ _group7_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _group7_geoSegmentRomStart,  /*romEnd*/ _group7_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _group16_mio0SegmentRomStart, /*romEnd*/ _group16_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _group16_geoSegmentRomStart,  /*romEnd*/ _group16_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _common0_mio0SegmentRomStart, /*romEnd*/ _common0_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _common0_geoSegmentRomStart,  /*romEnd*/ _common0_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behParam*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_8
    jump_link /*target*/ script_func_global_17
    load_model_from_geo /*model*/ MODEL_SL_36, /*geo*/ sl_geo_000390
    load_model_from_geo /*model*/ MODEL_SL_37, /*geo*/ sl_geo_000360
    load_model_from_geo /*model*/ MODEL_SL_38, /*geo*/ sl_geo_000378
    load_model_from_geo /*model*/ MODEL_SL_SNOW_TREE, /*geo*/ snow_tree_geo

    area /*index*/ 1, /*geo*/ sl_geo_0003A8
        object /*model*/ MODEL_NONE, /*pos*/  5541, 2024,   443, /*angle*/ 0, 270, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*model*/ MODEL_NONE, /*pos*/   257, 2150,  1399, /*angle*/ 0, 290, 0, /*behParam*/ 0x000B0000, /*beh*/ beh_warps_60
        object /*model*/ MODEL_NONE, /*pos*/   569, 2150,  1336, /*angle*/ 0,   0, 0, /*behParam*/ 0x060C0000, /*beh*/ beh_warp
        object /*model*/ MODEL_NONE, /*pos*/  5468, 1056, -5400, /*angle*/ 0, -20, 0, /*behParam*/ 0x000D0000, /*beh*/ beh_fading_warp
        object /*model*/ MODEL_NONE, /*pos*/ -3698, 1024, -1237, /*angle*/ 0,   6, 0, /*behParam*/ 0x000E0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0B, /*destLevel*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0C, /*destLevel*/ 0x0A, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0D, /*destLevel*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0E, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0E, /*destLevel*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0D, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x36, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x68, /*unk6*/ 0x0000
        terrain /*terrainData*/ sl_seg7_area_1_collision
        macro_objects /*objList*/ sl_seg7_area_1_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0008
        terrain_type /*terrainType*/ 0x0002
    end_area

    area /*index*/ 2, /*geo*/ sl_geo_000484
        object /*model*/ MODEL_NONE, /*pos*/ 0, 0, 2867, /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_60
        object /*model*/ MODEL_NONE, /*pos*/ 0, 0, 3277, /*angle*/ 0,   0, 0, /*behParam*/ 0x140B0000, /*beh*/ beh_warp
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x0A, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0x0B, /*destLevel*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_4
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x36, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x68, /*unk6*/ 0x0000
        terrain /*terrainData*/ sl_seg7_area_2_collision
        macro_objects /*objList*/ sl_seg7_area_2_macro_objs
        set_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0002
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 270, /*pos*/ 5541, 1024, 443
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_sl.s"
.align 4
