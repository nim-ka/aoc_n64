.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/pss_seg7.mio0"
.align 4

.section .level, "a"

glabel level_pss_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_pss_segment_7SegmentRomStart, /*romEnd*/ _level_pss_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _ttm_textures_mio0SegmentRomStart, /*romEnd*/ _ttm_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _group8_mio0SegmentRomStart, /*romEnd*/ _group8_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _group8_geoSegmentRomStart,  /*romEnd*/ _group8_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _common0_mio0SegmentRomStart, /*romEnd*/ _common0_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _common0_geoSegmentRomStart,  /*romEnd*/ _common0_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behParam*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_9

    area /*index*/ 1, /*geo*/ pss_geo_000100
        object /*model*/ MODEL_NONE, /*pos*/ 5632, 6751, -5631, /*angle*/ 0, 270, 0, /*behParam*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel*/ 0x1B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF3, /*destLevel*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x20, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF0, /*destLevel*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x26, /*unk6*/ 0x0000
        warp_node /*id*/ 0xF1, /*destLevel*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x23, /*unk6*/ 0x0000
        terrain /*terrainData*/ pss_seg7_collision
        macro_objects /*objList*/ pss_seg7_macro_objs
        terrain_type /*terrainType*/ 0x0006
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0009
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 270, /*pos*/ 5632, 6451, -5631
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_pss.s"
.align 4
