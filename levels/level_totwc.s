.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/totwc_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*model*/ MODEL_CAP_SWITCH, /*pos*/   0, -2047, 10, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_cap_switch
    return

script_func_local_2:
    object /*model*/ MODEL_NONE,       /*pos*/ 800, -1700,  0, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_totwc_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_totwc_segment_7SegmentRomStart, /*romEnd*/ _level_totwc_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _cloud_floor_skybox_mio0SegmentRomStart, /*romEnd*/ _cloud_floor_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _rr_textures_mio0SegmentRomStart, /*romEnd*/ _rr_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _capswitch_springboard_mio0SegmentRomStart, /*romEnd*/ _capswitch_springboard_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _capswitch_springboard_geoSegmentRomStart,  /*romEnd*/ _capswitch_springboard_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behParam*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_9
    load_model_from_geo /*model*/ MODEL_LEVEL_GEOMETRY_03, /*geo*/ totwc_geo_000160

    area /*index*/ 1, /*geo*/ totwc_geo_000188
        object /*model*/ MODEL_NONE, /*pos*/ -4095, 2935, 0, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_78
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x1D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF3, /*destLevel*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x20, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x26, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x23, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_1
        terrain /*terrainData*/ totwc_seg7_collision
        macro_objects /*objList*/ totwc_seg7_macro_objs
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x83
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -4095, 2935, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_totwc.s"
.align 4
