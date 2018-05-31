.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/secret_slide_segment7.mio0"
.align 4

.section .level, "a"

glabel level_pss_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_pss_segment_7SegmentRomStart, /*romEnd*/ _level_pss_segment_7SegmentRomEnd
    cmd1A /*seg*/ 0x09, /*romStart*/ ttm_textures, /*romEnd*/ ttm_textures_end
    load_mio0 /*seg*/ 0x05, /*romStart*/ checkerboard_question, /*romEnd*/ checkerboard_question_end
    load_raw /*seg*/ 0x0C, /*romStart*/ cap_switch, /*romEnd*/ cap_switch_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_9

    area /*index*/ 1, /*geo*/ 0x0E000100
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5632, 6751, -5631, /*angle*/ 0, 270, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x20, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x26, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x23, /*destLevel2*/ 0x00
        terrain /*terrainData*/ 0x0700E490
        cmd39 /*unk4*/ 0x07010F00
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
.include "geo/level_pss.geo.s"
.align 4
