.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/ccm_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 531, -4430, 6426, /*angle*/ 0, 0, 0, /*behArg*/ 0x07120000, /*beh*/ beh_platform_on_tracks
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ 2650, -3735, 3970, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_small_penguin
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ -555, 3470, -1000, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_penguin
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -2376, -1589, 4256, /*angle*/ 0, 252, 0, /*behArg*/ 0x00010000, /*beh*/ beh_mr_blizzard
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -394, -1589, 4878, /*angle*/ 0, 74, 0, /*behArg*/ 0x00010000, /*beh*/ beh_mr_blizzard
    object /*unk2*/ 0x10, /*unk3*/ 0xD2, /*pos*/ 2560, 2662, -1122, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_snowmans_bottom
    return

script_func_local_3:
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 2665, -4607, 4525, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ccm_touched_star_spawn
    object /*unk2*/ 0x3F, /*unk3*/ 0x57, /*pos*/ 3450, -4700, 4550, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_tuxies_mother
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 4200, -927, 400, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x37, /*pos*/ -4230, -1169, 1813, /*angle*/ 0, 270, 0, /*behArg*/ 0x04000000, /*beh*/ beh_snowmans_head
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -2000, -2200, -3000, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

script_func_local_4:
    object /*unk2*/ 0x3E, /*unk3*/ 0x57, /*pos*/ -4952, 6656, -6075, /*angle*/ 0, 270, 0, /*behArg*/ 0x02000000, /*beh*/ beh_racing_penguin
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6500, -5836, -6400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_finish_line_check
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6393, -716, 7503, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_shortcut_check
    return

glabel level_ccm_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_ccm_segment_7SegmentRomStart, /*romEnd*/ _level_ccm_segment_7SegmentRomEnd
    cmd1A /*seg*/ 0x09, /*romStart*/ ccm_textures, /*romEnd*/ ccm_textures_end
    load_mio0 /*seg*/ 0x0B, /*romStart*/ flower_textures, /*romEnd*/ flower_textures_end
    load_mio0 /*seg*/ 0x0A, /*romStart*/ ccm_skybox, /*romEnd*/ ccm_skybox_end
    load_mio0 /*seg*/ 0x05, /*romStart*/ spindrift_penguin_snowman, /*romEnd*/ spindrift_penguin_snowman_end
    load_raw /*seg*/ 0x0C, /*romStart*/ spindrift_penguin_blizzard, /*romEnd*/ spindrift_penguin_blizzard_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ chillychief_moneybag, /*romEnd*/ chillychief_moneybag_end
    load_raw /*seg*/ 0x0D, /*romStart*/ moneybag, /*romEnd*/ moneybag_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_8
    jump_link /*target*/ script_func_global_17
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E00042C
    cmd22 /*unk2*/ 0x0004, /*unk4*/ 0x0E00045C
    cmd22 /*unk2*/ 0x0005, /*unk4*/ 0x0E000494
    cmd22 /*unk2*/ 0x0006, /*unk4*/ 0x0E0004BC
    cmd22 /*unk2*/ 0x0007, /*unk4*/ 0x0E0004E4
    cmd22 /*unk2*/ 0x0027, /*unk4*/ 0x1600043C
    cmd22 /*unk2*/ 0x0019, /*unk4*/ 0x16001018
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E0003D0
    cmd22 /*unk2*/ 0x00D2, /*unk4*/ 0x0E0003F0
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E00040C

    area /*index*/ 1, /*geo*/ 0x0E00051C
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1512, 3560, -2305, /*angle*/ 0, 140, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -181, 2918, -1486, /*angle*/ 0, 0, 0, /*behArg*/ 0x0F1E0000, /*beh*/ beh_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1847, 2815, -321, /*angle*/ 0, -158, 0, /*behArg*/ 0x001F0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3349, -4694, -183, /*angle*/ 0, -34, 0, /*behArg*/ 0x00200000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x14, /*destLevel1*/ 0x05, /*destArea*/ 0x02, /*destNode*/ 0x14, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x1E, /*destLevel1*/ 0x05, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x1F, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x20, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x20, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x1F, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x33, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x65, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ 0x070138E8
        cmd39 /*unk4*/ 0x07016284
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x30
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0008
        terrain_type /*terrainType*/ 0x0002
    end_area

    area /*index*/ 2, /*geo*/ 0x0E0005E8
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5836, 7465, -6143, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x14, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x14, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x05, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x33, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x65, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_4
        terrain /*terrainData*/ 0x07020880
        cmd39 /*unk4*/ 0x07023468
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0006
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 140, /*pos*/ -1512, 2560, -2305
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_ccm.geo.s"
.align 4
