.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/wmotr_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3996, -2739, 5477, /*angle*/ 0, 0, 0, /*behArg*/ 0x00520000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2911, 3564, -3967, /*angle*/ 0, 0, 0, /*behArg*/ 0x00540000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3258, 3359, -3946, /*angle*/ 0, 0, 0, /*behArg*/ 0x00690000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2639, 3154, -4369, /*angle*/ 0, 0, 0, /*behArg*/ 0x007D0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2980, 4048, -4248, /*angle*/ 0, 0, 0, /*behArg*/ 0x00240000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3290, 3636, -4477, /*angle*/ 0, 0, 0, /*behArg*/ 0x004D0000, /*beh*/ beh_pole_grabbing
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -160, 1950, -470, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_wmotr_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_wmotr_segment_7SegmentRomStart, /*romEnd*/ _level_wmotr_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _cloud_floor_skybox_mio0SegmentRomStart, /*romEnd*/ _cloud_floor_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _rr_textures_mio0SegmentRomStart, /*romEnd*/ _rr_textures_mio0SegmentRomEnd
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

    area /*index*/ 1, /*geo*/ wmotr_geo_0001F0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -67, 2669, -16, /*angle*/ 0, 270, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1F, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x38, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x6D, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        terrain /*terrainData*/ wmotr_seg7_collision 
        cmd39 /*unk4*/ wmotr_seg7_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0002
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 270, /*pos*/ -67, 1669, -16
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_wmotr.s"
.align 4
