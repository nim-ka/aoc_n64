.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/sl_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 700, 4500, 690, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 4350, 1350, 4350, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 5000, 1200, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_hidden_red_coin_star
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 977, 1024, 2075, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_snow_mound_spawn
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ 1715, 3328, 518, /*angle*/ 0, -51, 0, /*behArg*/ 0x00000000, /*beh*/ beh_walking_penguin
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 700, 3428, 700, /*angle*/ 0, 30, 0, /*behArg*/ 0x00000000, /*beh*/ beh_snowman_wind_blowing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 480, 2300, 1370, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_igloo
    object /*unk2*/ 0x1F, /*unk3*/ 0x65, /*pos*/ 315, 1331, -4852, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_chill_bully_boss
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 2954, 970, 750, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_mr_blizzard
    return

script_func_local_4:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 0, 500, 1000, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_sl_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_sl_segment_7SegmentRomStart, /*romEnd*/ _level_sl_segment_7SegmentRomEnd
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
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000390
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000360
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000378
    cmd22 /*unk2*/ 0x0019, /*unk4*/ 0x16001018

    area /*index*/ 1, /*geo*/ 0x0E0003A8
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5541, 2024, 443, /*angle*/ 0, 270, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 257, 2150, 1399, /*angle*/ 0, 290, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_warps_60
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 569, 2150, 1336, /*angle*/ 0, 0, 0, /*behArg*/ 0x060C0000, /*beh*/ beh_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5468, 1056, -5400, /*angle*/ 0, -20, 0, /*behArg*/ 0x000D0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3698, 1024, -1237, /*angle*/ 0, 6, 0, /*behArg*/ 0x000E0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x0A, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0D, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0E, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0E, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0D, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x36, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x68, /*destLevel2*/ 0x00
        terrain /*terrainData*/ 0x0700CBD8
        cmd39 /*unk4*/ 0x0700ED94
        set_menu_music /*unk2*/ 0x0000, /*seq*/ 0x0008
        terrain_type /*terrainType*/ 0x0002
    end_area

    area /*index*/ 2, /*geo*/ 0x0E000484
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 2867, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_60
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 3277, /*angle*/ 0, 0, 0, /*behArg*/ 0x140B0000, /*beh*/ beh_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0A, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_4
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x36, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x68, /*destLevel2*/ 0x00
        terrain /*terrainData*/ 0x0700EFFC
        cmd39 /*unk4*/ 0x0700F978
        set_menu_music /*unk2*/ 0x0004, /*seq*/ 0x000C
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
.include "geo/level_sl.geo.s"
.align 4
