.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bidw_platform_segment7.mio0"
.align 4

.section .level, "a"

glabel level_bowser_1_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bowser_1_segment_7SegmentRomStart, /*romEnd*/ _level_bowser_1_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bidw_skybox_mio0SegmentRomStart, /*romEnd*/ _bidw_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _bowser_flames_bomb_mio0SegmentRomStart, /*romEnd*/ _bowser_flames_bomb_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _bowser_flames_bomb_geoSegmentRomStart, /*romEnd*/ _bowser_flames_bomb_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_13
    cmd22 /*unk2*/ 0x0003, /*unk4*/ bowser_1_yellow_sphere_geo

    area /*index*/ 1, /*geo*/ bowser_1_geo_0000D0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 1307, 0, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_6C
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1E, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x24, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x11, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        terrain /*terrainData*/ bowser_1_seg7_collision
        set_music /*unk2*/ 0x0002, /*seq*/ 0x0007
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ 0, 307, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_bowser_1.s"
.align 4
