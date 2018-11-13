.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/ssl_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ -2047, 1536, -1023, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pyramid_top
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0xC7, /*pos*/ -1284, 0, -5895, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tox_box
    object /*unk2*/ 0x1F, /*unk3*/ 0xC7, /*pos*/ 1283, 0, -4865, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_tox_box
    object /*unk2*/ 0x1F, /*unk3*/ 0xC7, /*pos*/ 4873, 0, -3335, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_tox_box
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -3600, -200, 2940, /*angle*/ 0, 0, 0, /*behArg*/ 0x00120000, /*beh*/ beh_tornado
    object /*unk2*/ 0x38, /*unk3*/ 0x56, /*pos*/ 1017, -200, 3832, /*angle*/ 0, 0, 0, /*behArg*/ 0x00190000, /*beh*/ beh_tornado
    object /*unk2*/ 0x38, /*unk3*/ 0x56, /*pos*/ 3066, -200, 400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00190000, /*beh*/ beh_tornado
    object /*unk2*/ 0x01, /*unk3*/ 0x57, /*pos*/ 2200, 1174, -2820, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_klepto
    object /*unk2*/ 0x3E, /*unk3*/ 0x57, /*pos*/ -5963, 573, -4784, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_klepto
    return

script_func_local_3:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -2050, 1200, -580, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 6000, 800, 3500, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_hidden_red_coin_star
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2867, 640, 2867, /*angle*/ 0, 0, 0, /*behArg*/ 0x004D0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 3200, 1331, /*angle*/ 0, 0, 0, /*behArg*/ 0x005C0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 3297, 0, 95, /*angle*/ 0, 0, 0, /*behArg*/ 0x001C0000, /*beh*/ beh_grindel
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -870, 3840, 105, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_grindel2
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -3362, 0, -1385, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_grindel2
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -2458, 2109, -1430, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_spindel
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 858, 1927, -2307, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_moving_up_and_down
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 730, 1927, -2307, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_moving_up_and_down
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1473, 2567, -2307, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_moving_up_and_down
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1345, 2567, -2307, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_moving_up_and_down
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 0, 4966, 256, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pyramid_elevator
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1198, -133, 2396, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sand_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 7, 1229, -708, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sand_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 7, 4317, -708, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sand_sound_loop
    return

script_func_local_5:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 500, 5050, -500, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 900, 1400, 2350, /*angle*/ 0, 0, 0, /*behArg*/ 0x05040000, /*beh*/ beh_hidden_star
    return

script_func_local_6:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, -1534, -3693, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_eyerok_boss
    return

glabel level_ssl_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_ssl_segment_7SegmentRomStart, /*romEnd*/ _level_ssl_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _ssl_skybox_mio0SegmentRomStart, /*romEnd*/ _ssl_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _bob_textures_mio0SegmentRomStart, /*romEnd*/ _bob_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _klepto_eyerok_pokey_mio0SegmentRomStart, /*romEnd*/ _klepto_eyerok_pokey_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _klepto_eyerok_pokey_geoSegmentRomStart,  /*romEnd*/ _klepto_eyerok_pokey_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_6
    cmd22 /*unk2*/ 0x001B, /*unk4*/ palm_tree_geo
    cmd22 /*unk2*/ 0x0003, /*unk4*/ ssl_geo_0005C0
    cmd22 /*unk2*/ 0x0004, /*unk4*/ ssl_geo_0005D8
    cmd22 /*unk2*/ 0x003A, /*unk4*/ ssl_geo_000618
    cmd22 /*unk2*/ 0x0036, /*unk4*/ ssl_geo_000734
    cmd22 /*unk2*/ 0x0037, /*unk4*/ ssl_geo_000764
    cmd22 /*unk2*/ 0x0038, /*unk4*/ ssl_geo_000794
    cmd22 /*unk2*/ 0x0039, /*unk4*/ ssl_geo_0007AC
    cmd22 /*unk2*/ 0x00C7, /*unk4*/ ssl_geo_000630

    area /*index*/ 1, /*geo*/ ssl_geo_000648
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 653, 1038, 6566, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2048, 0, 56, /*angle*/ 0, 0, 0, /*behArg*/ 0x00140000, /*beh*/ beh_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2048, 768, -1024, /*angle*/ 0, 0, 0, /*behArg*/ 0x0F1E0000, /*beh*/ beh_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 6930, 0, -4871, /*angle*/ 0, 159, 0, /*behArg*/ 0x001F0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5943, 0, -4903, /*angle*/ 0, 49, 0, /*behArg*/ 0x00200000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x08, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x14, /*destLevel1*/ 0x08, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x80
        warp_node /*id*/ 0x1E, /*destLevel1*/ 0x08, /*destArea*/ 0x02, /*destNode*/ 0x14, /*destLevel2*/ 0x80
        warp_node /*id*/ 0x1F, /*destLevel1*/ 0x08, /*destArea*/ 0x01, /*destNode*/ 0x20, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x20, /*destLevel1*/ 0x08, /*destArea*/ 0x01, /*destNode*/ 0x1F, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x33, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x65, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ ssl_seg7_area_1_collision
        cmd39 /*unk4*/ ssl_seg7_area_1_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0006
        terrain_type /*terrainType*/ 0x0003
    end_area

    area /*index*/ 2, /*geo*/ ssl_geo_0007CC
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 300, 6451, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 5500, 256, /*angle*/ 0, 180, 0, /*behArg*/ 0x00140000, /*beh*/ beh_warps_64
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3070, 1280, 2900, /*angle*/ 0, 180, 0, /*behArg*/ 0x00150000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2546, 1150, -2647, /*angle*/ 0, 78, 0, /*behArg*/ 0x00160000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x08, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x14, /*destLevel1*/ 0x08, /*destArea*/ 0x02, /*destNode*/ 0x14, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x15, /*destLevel1*/ 0x08, /*destArea*/ 0x02, /*destNode*/ 0x16, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x16, /*destLevel1*/ 0x08, /*destArea*/ 0x02, /*destNode*/ 0x15, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x33, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x65, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_4
        jump_link /*target*/ script_func_local_5
        instant_warp /*index*/ 3, /*destArea*/ 3, /*displace*/ 0, 0, 0
        terrain /*terrainData*/ ssl_seg7_area_2_collision
        cmd39 /*unk4*/ ssl_seg7_area_2_macro_objs
        set_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 3, /*geo*/ ssl_geo_00088C
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x33, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x65, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_6
        terrain /*terrainData*/ ssl_seg7_area_3_collision
        cmd39 /*unk4*/ ssl_seg7_area_3_macro_objs
        instant_warp /*index*/ 2, /*destArea*/ 2, /*displace*/ 0, 0, 0
        set_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 88, /*pos*/ 653, 38, 6566
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_ssl.s"
.align 4
