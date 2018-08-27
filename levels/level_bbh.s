.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bbh_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 2089, 1331, -1125, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1331, 1075, -1330, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 2089, 1331, -511, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -511, 358, -1330, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1126, 358, 2212, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 205, 358, 2212, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 2866, 820, 1897, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bbh_tilt_floor_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 2961, 0, -768, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bbh_tumbling_platform_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -1994, 819, 213, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tumbling_bookshelf
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ -2985, -205, 5400, /*angle*/ 0, -45, 0, /*behArg*/ 0x00000000, /*beh*/ beh_mesh_elevator
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -205, -2560, 205, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rotating_merry_go_round
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2200, 819, -800, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_haunted_room_check
    return

script_func_local_3:
    object /*unk2*/ 0x01, /*unk3*/ 0x54, /*pos*/ 1000, 50, 1000, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_giving_star
    object /*unk2*/ 0x01, /*unk3*/ 0x54, /*pos*/ 20, 100, -908, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_2
    object /*unk2*/ 0x01, /*unk3*/ 0x54, /*pos*/ 3150, 100, 398, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_2
    object /*unk2*/ 0x01, /*unk3*/ 0x54, /*pos*/ -2000, 150, -800, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_2
    object /*unk2*/ 0x01, /*unk3*/ 0x54, /*pos*/ 2851, 100, 2289, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_2
    object /*unk2*/ 0x01, /*unk3*/ 0x54, /*pos*/ -1551, 100, -1018, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_2
    object /*unk2*/ 0x3E, /*unk3*/ 0x35, /*pos*/ 973, 0, 517, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_staircase_step
    object /*unk2*/ 0x3E, /*unk3*/ 0x35, /*pos*/ 973, -206, 717, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_staircase_step
    object /*unk2*/ 0x3E, /*unk3*/ 0x35, /*pos*/ 973, -412, 917, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_staircase_step
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ 20, 100, -908, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ 3150, 100, 398, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ -2000, 150, -800, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ 2851, 100, 2289, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ -1551, 100, -1018, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x00, /*pos*/ 990, -2146, -908, /*angle*/ 0, -45, 0, /*behArg*/ 0x00030000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x3E, /*unk3*/ 0x00, /*pos*/ -1100, -2372, 1100, /*angle*/ 0, 135, 0, /*behArg*/ 0x01000000, /*beh*/ beh_spawn_big_boo
    object /*unk2*/ 0x3F, /*unk3*/ 0x54, /*pos*/ 1030, 1922, 2546, /*angle*/ 0, -90, 0, /*behArg*/ 0x04000000, /*beh*/ beh_patrolling_boo
    object /*unk2*/ 0x3F, /*unk3*/ 0x54, /*pos*/ 581, 1850, -206, /*angle*/ 0, -90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_3
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ -1300, 0, 2310, /*angle*/ 0, 243, 0, /*behArg*/ 0x00000000, /*beh*/ beh_mad_piano
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -1530, 0, 2200, /*angle*/ 0, 66, 0, /*behArg*/ 0x00000000, /*beh*/ beh_haunted_chair
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1330, 890, 200, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bookend_spawn
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -818, 890, -200, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bookend_spawn
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1330, 890, -622, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bookend_spawn
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -818, 890, -686, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bookend_spawn
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1950, 880, 8, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bookshelf_thing
    object /*unk2*/ 0x1F, /*unk3*/ 0x59, /*pos*/ 2680, 1045, 876, /*angle*/ 0, 166, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flying_bookend
    object /*unk2*/ 0x1F, /*unk3*/ 0x59, /*pos*/ 3075, 1045, 995, /*angle*/ 0, 166, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flying_bookend
    object /*unk2*/ 0x1F, /*unk3*/ 0x59, /*pos*/ -1411, 218, 922, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flying_bookend
    return

script_func_local_4:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -2030, 1350, 1940, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -204, 1100, 1576, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 923, 1741, -332, /*angle*/ 0, 18, 0, /*behArg*/ 0x05010000, /*beh*/ beh_mr_i
    return

glabel level_bbh_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bbh_segment_7SegmentRomStart, /*romEnd*/ _level_bbh_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bbh_skybox_mio0SegmentRomStart, /*romEnd*/ _bbh_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _bbh_textures_mio0SegmentRomStart, /*romEnd*/ _bbh_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _boo_bookend_chair_piano_mio0SegmentRomStart, /*romEnd*/ _boo_bookend_chair_piano_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _boo_bookend_chair_piano_geoSegmentRomStart,  /*romEnd*/ _boo_bookend_chair_piano_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _mri_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomStart, /*romEnd*/ _mri_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _mri_swoop_snufit_dorrie_scuttlebug_geoSegmentRomStart, /*romEnd*/ _mri_swoop_snufit_dorrie_scuttlebug_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_10
    jump_link /*target*/ script_func_global_18
    cmd22 /*unk2*/ 0x001D, /*unk4*/ haunted_door_geo
    cmd22 /*unk2*/ 0x0035, /*unk4*/ geo_bbh_0005B0
    cmd22 /*unk2*/ 0x0036, /*unk4*/ geo_bbh_0005C8
    cmd22 /*unk2*/ 0x0037, /*unk4*/ geo_bbh_0005E0
    cmd22 /*unk2*/ 0x0038, /*unk4*/ geo_bbh_0005F8
    cmd22 /*unk2*/ 0x0039, /*unk4*/ geo_bbh_000610
    cmd22 /*unk2*/ 0x003A, /*unk4*/ geo_bbh_000628
    cmd22 /*unk2*/ 0x003B, /*unk4*/ geo_bbh_000640
    cmd22 /*unk2*/ 0x003C, /*unk4*/ geo_bbh_000658

    area /*index*/ 1, /*geo*/ geo_bbh_000F00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 666, 796, 5350, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x04, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x1A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x1A, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        terrain /*terrainData*/ bbh_seg7_collision
        cmd39 /*unk4*/ bbh_seg7_macro_objs
        rooms /*surfaceRooms*/ bbh_seg7_rooms
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x62
        set_music /*unk2*/ 0x0006, /*seq*/ 0x000A
        terrain_type /*terrainType*/ 0x0004
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ 666, -204, 5350
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_bbh.s"
.align 4
