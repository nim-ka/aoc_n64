.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/cotmc_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*model*/ MODEL_CAP_SWITCH, /*pos*/ 0,  363, -6144, /*angle*/ 0, 0, 0, /*behParam*/ 0x00010000, /*beh*/ beh_cap_switch
    object /*model*/ MODEL_NONE,       /*pos*/ 0,  500, -7373, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    object /*model*/ MODEL_NONE,       /*pos*/ 0,  500,  3584, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    return

script_func_local_2:
    object /*model*/ MODEL_NONE,       /*pos*/ 0, -200, -7000, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_cotmc_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_cotmc_segment_7SegmentRomStart, /*romEnd*/ _level_cotmc_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _hmc_textures_mio0SegmentRomStart, /*romEnd*/ _hmc_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _capswitch_springboard_mio0SegmentRomStart, /*romEnd*/ _capswitch_springboard_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _capswitch_springboard_geoSegmentRomStart,  /*romEnd*/ _capswitch_springboard_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _mr_i_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomStart, /*romEnd*/ _mr_i_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _mr_i_swoop_snufit_dorrie_scuttlebug_geoSegmentRomStart,  /*romEnd*/ _mr_i_swoop_snufit_dorrie_scuttlebug_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behParam*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_9
    jump_link /*target*/ script_func_global_18
    jump_link /*target*/ script_func_global_1

    area /*index*/ 1, /*geo*/ cotmc_geo_0001A0
        object /*model*/ MODEL_NONE, /*pos*/ -4185, 1020, -47, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x1C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x34, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x66, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF3, /*destLevel*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x14, /*unk6*/ 0x0000
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_1
        terrain /*terrainData*/ cotmc_seg7_collision_level
        macro_objects /*objList*/ cotmc_seg7_macro_objs
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x82
        set_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -4185, 20, -47
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_cotmc.s"
.align 4
