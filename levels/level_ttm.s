.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/ttm_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x35, /*pos*/ 4360, -1722, 4001, /*angle*/ 0, 48, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pitoune_2
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1639, 1146, -1742, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_ttm_bowling_ball_spawner
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3295, -3692, 2928, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2004, -1580, 1283, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2077, -1023, -1969, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2500, -1023, -2157, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2048, -1023, -2307, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2351, -1023, -2416, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2400, -2559, -2185, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -1435, -2559, -3118, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -1677, -2559, -3507, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -1869, -2559, -2704, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2525, -2559, -2626, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole_in_hole
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_monty_mole
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_monty_mole
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3625, 560, 165, /*angle*/ 0, 330, 0, /*behArg*/ 0x00000000, /*beh*/ beh_fwoosh_blowing_wind
    object /*unk2*/ 0x02, /*unk3*/ 0x56, /*pos*/ 729, 2307, 335, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ukiki
    object /*unk2*/ 0x3F, /*unk3*/ 0x56, /*pos*/ 1992, -1548, 2944, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_ukiki
    return

script_func_local_3:
    object /*unk2*/ 0x01, /*unk3*/ 0x7A, /*pos*/ 1200, 2600, 150, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x02, /*unk3*/ 0x36, /*pos*/ 2496, 1670, 1492, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_little_cage
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -3250, -2500, -3700, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -2900, -2700, 3650, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 1800, 1200, 1050, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 7300, -3100, 1300, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 4389, 3620, 624, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -1251, 2493, 2224, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -2547, 1365, -520, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ -324, 989, -4090, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    return

script_func_local_5:
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 7867, -959, -6085, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -5241, 5329, 9466, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -1869, -5311, 7358, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -9095, 4262, 5348, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ -8477, 730, -7122, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 6160, -6076, 7861, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    return

script_func_local_6:
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 5157, 1974, -8292, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 11106, 2588, 381, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 37, 1974, -1124, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    return

script_func_local_7:
    return

glabel level_ttm_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_ttm_segment_7SegmentRomStart, /*romEnd*/ _level_ttm_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _ttm_textures_mio0SegmentRomStart, /*romEnd*/ _ttm_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _water_skybox_mio0SegmentRomStart, /*romEnd*/ _water_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _mole_ukiki_fwoosh_mio0SegmentRomStart, /*romEnd*/ _mole_ukiki_fwoosh_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _mole_ukiki_fwoosh_geoSegmentRomStart,  /*romEnd*/ _mole_ukiki_fwoosh_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_flyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_7
    cmd22 /*unk2*/ 0x007B, /*unk4*/ ttm_geo_000DF4
    cmd22 /*unk2*/ 0x0035, /*unk4*/ ttm_geo_000730
    cmd22 /*unk2*/ 0x0036, /*unk4*/ ttm_geo_000710
    cmd22 /*unk2*/ 0x0037, /*unk4*/ ttm_geo_000D14
    cmd22 /*unk2*/ 0x0038, /*unk4*/ ttm_geo_000D4C
    cmd22 /*unk2*/ 0x0039, /*unk4*/ ttm_geo_000D84
    cmd22 /*unk2*/ 0x003A, /*unk4*/ ttm_geo_000DBC
    cmd22 /*unk2*/ 0x0003, /*unk4*/ ttm_geo_000748
    cmd22 /*unk2*/ 0x0004, /*unk4*/ ttm_geo_000778
    cmd22 /*unk2*/ 0x0005, /*unk4*/ ttm_geo_0007A8
    cmd22 /*unk2*/ 0x0006, /*unk4*/ ttm_geo_0007D8
    cmd22 /*unk2*/ 0x0007, /*unk4*/ ttm_geo_000808
    cmd22 /*unk2*/ 0x0008, /*unk4*/ ttm_geo_000830
    cmd22 /*unk2*/ 0x0009, /*unk4*/ ttm_geo_000858
    cmd22 /*unk2*/ 0x000A, /*unk4*/ ttm_geo_000880
    cmd22 /*unk2*/ 0x000B, /*unk4*/ ttm_geo_0008A8
    cmd22 /*unk2*/ 0x000C, /*unk4*/ ttm_geo_0008D0
    cmd22 /*unk2*/ 0x000D, /*unk4*/ ttm_geo_0008F8
    cmd22 /*unk2*/ 0x000F, /*unk4*/ ttm_geo_000920
    cmd22 /*unk2*/ 0x0010, /*unk4*/ ttm_geo_000948
    cmd22 /*unk2*/ 0x0011, /*unk4*/ ttm_geo_000970
    cmd22 /*unk2*/ 0x0012, /*unk4*/ ttm_geo_000990
    cmd22 /*unk2*/ 0x0013, /*unk4*/ ttm_geo_0009C0
    cmd22 /*unk2*/ 0x0014, /*unk4*/ ttm_geo_0009F0
    cmd22 /*unk2*/ 0x0015, /*unk4*/ ttm_geo_000A18
    cmd22 /*unk2*/ 0x0016, /*unk4*/ ttm_geo_000A40

    area /*index*/ 1, /*geo*/ ttm_geo_000A70
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 102, -3332, 5734, /*angle*/ 0, 45, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2447, -2457, 3952, /*angle*/ 0, -105, 0, /*behArg*/ 0x00140000, /*beh*/ beh_warps_64
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2267, -3006, -3788, /*angle*/ 0, 148, 0, /*behArg*/ 0x00150000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -557, -3448, -4146, /*angle*/ 0, -168, 0, /*behArg*/ 0x00160000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x14, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x14, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x15, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x16, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x16, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x15, /*destLevel2*/ 0x00
        painting_warp_node /*id*/ 0x00, /*destLevel1*/ 0x24, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x80
        painting_warp_node /*id*/ 0x01, /*destLevel1*/ 0x24, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x80
        painting_warp_node /*id*/ 0x02, /*destLevel1*/ 0x24, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x80
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ ttm_seg7_area_1_collision
        cmd39 /*unk4*/ ttm_seg7_area_1_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0003
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 2, /*geo*/ ttm_geo_000B5C
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 7000, 5381, 6750, /*angle*/ 0, 225, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x24, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_4
        terrain /*terrainData*/ ttm_seg7_area_2_collision
        cmd39 /*unk4*/ ttm_seg7_area_2_macro_objs
        instant_warp /*index*/ 2, /*destArea*/ 3, /*displace*/ 10240, 7168, 10240
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0006
    end_area

    area /*index*/ 3, /*geo*/ ttm_geo_000BEC
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_5
        terrain /*terrainData*/ ttm_seg7_area_3_collision
        cmd39 /*unk4*/ ttm_seg7_area_3_macro_objs
        instant_warp /*index*/ 3, /*destArea*/ 4, /*displace*/ -11264, 13312, 3072
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0006
    end_area

    area /*index*/ 4, /*geo*/ ttm_geo_000C84
        object /*unk2*/ 0x1F, /*unk3*/ 0x7B, /*pos*/ -7285, -1866, -4812, /*angle*/ 0, 0, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_exit_podium_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x14, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_6
        jump_link /*target*/ script_func_local_7
        terrain /*terrainData*/ ttm_seg7_area_4_collision
        cmd39 /*unk4*/ ttm_seg7_area_4_macro_objs
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0006
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 45, /*pos*/ 102, -4332, 5734
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_ttm.s"
.align 4
