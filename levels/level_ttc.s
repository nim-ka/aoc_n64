.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/ttc_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1080, -840, 1573, /*angle*/ 0, 0, 0, /*behArg*/ 0x00560000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x58, /*pos*/ 1919, 6191, 1919, /*angle*/ 0, 225, 0, /*behArg*/ 0x00000000, /*beh*/ beh_thwomp_2
    return

script_func_local_2:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -1450, -1130, -1050, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -1850, 300, -950, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -1300, -2250, -1300, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 2200, 7300, 2210, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -1050, 2400, -790, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 1815, -3200, 800, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_ttc_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_ttc_segment_7SegmentRomStart, /*romEnd*/ _level_ttc_segment_7SegmentRomEnd
    cmd1A /*seg*/ 0x09, /*romStart*/ ttc_textures, /*romEnd*/ ttc_textures_end
    load_mio0 /*seg*/ 0x05, /*romStart*/ yoshiegg_owl_thwomp, /*romEnd*/ yoshiegg_owl_thwomp_end
    load_raw /*seg*/ 0x0C, /*romStart*/ owl_thwomp_bullet_heave, /*romEnd*/ owl_thwomp_bullet_heave_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_2
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000240
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000258
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000270
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E000288
    cmd22 /*unk2*/ 0x003A, /*unk4*/ 0x0E0002A8
    cmd22 /*unk2*/ 0x003B, /*unk4*/ 0x0E0002C8
    cmd22 /*unk2*/ 0x003C, /*unk4*/ 0x0E0002E0
    cmd22 /*unk2*/ 0x003D, /*unk4*/ 0x0E0002F8
    cmd22 /*unk2*/ 0x003E, /*unk4*/ 0x0E000310
    cmd22 /*unk2*/ 0x003F, /*unk4*/ 0x0E000328
    cmd22 /*unk2*/ 0x0040, /*unk4*/ 0x0E000340
    cmd22 /*unk2*/ 0x0041, /*unk4*/ 0x0E000358
    cmd22 /*unk2*/ 0x0042, /*unk4*/ 0x0E000370
    cmd22 /*unk2*/ 0x0043, /*unk4*/ 0x0E000388
    cmd22 /*unk2*/ 0x0044, /*unk4*/ 0x0E0003A0

    area /*index*/ 1, /*geo*/ 0x0E0003B8
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1417, -3822, -548, /*angle*/ 0, 316, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0E, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x35, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x67, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        terrain /*terrainData*/ 0x07012330
        cmd39 /*unk4*/ 0x07015B24
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 316, /*pos*/ 1417, -4822, -548
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_ttc.geo.s"
.align 4