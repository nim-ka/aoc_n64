.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bifs_platform_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 0, 0, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_bowser_lava_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 4, 1329, 3598, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_mine
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 3584, 1329, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_mine
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 0, 1329, -3583, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_mine
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ -3583, 1329, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_mine
    return

glabel level_bowser_2_entry
    init_level
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bifs_skybox_mio0SegmentRomStart, /*romEnd*/ _bifs_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _lll_textures_mio0SegmentRomStart, /*romEnd*/ _lll_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_textures_mio0SegmentRomStart, /*romEnd*/ _flower_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bowser_2_segment_7SegmentRomStart, /*romEnd*/ _level_bowser_2_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _bowser_flames_bomb_mio0SegmentRomStart, /*romEnd*/ _bowser_flames_bomb_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _bowser_flames_bomb_geoSegmentRomStart, /*romEnd*/ _bowser_flames_bomb_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_13
    cmd22 /*unk2*/ 0x0036, /*unk4*/ bowser_2_geo_000170

    area /*index*/ 1, /*geo*/ bowser_2_geo_000188
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 2229, 0, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_6C
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x21, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x36, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x13, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        terrain /*terrainData*/ bowser_2_seg7_collision
        set_music /*unk2*/ 0x0002, /*seq*/ 0x0007
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ 0, 1229, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_bowser_2.s"
.align 4
