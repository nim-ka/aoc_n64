.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/jrb_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x01, /*unk3*/ 0x39, /*pos*/ 2385, 3589, 3727, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sunken_ship_part
    object /*unk2*/ 0x01, /*unk3*/ 0x3A, /*pos*/ 2385, 3589, 3727, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sunken_ship_part
    object /*unk2*/ 0x01, /*unk3*/ 0x35, /*pos*/ 5385, -5520, 2428, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sunken_ship_part_2
    object /*unk2*/ 0x01, /*unk3*/ 0x37, /*pos*/ 5385, -5520, 2428, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sunken_ship_part_2
    object /*unk2*/ 0x01, /*unk3*/ 0x00, /*pos*/ 5385, -5520, 2428, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_in_sunken_ship
    object /*unk2*/ 0x01, /*unk3*/ 0x00, /*pos*/ 5385, -5520, 2428, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_in_sunken_ship_2
    object /*unk2*/ 0x3E, /*unk3*/ 0x35, /*pos*/ 4880, 820, 2375, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ship_part_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x36, /*pos*/ 4880, 820, 2375, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ship_part_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x37, /*pos*/ 4880, 820, 2375, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ship_part_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x38, /*pos*/ 4880, 820, 2375, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ship_part_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x00, /*pos*/ 4880, 820, 2375, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_in_sunken_ship_3
    object /*unk2*/ 0x3E, /*unk3*/ 0x3C, /*pos*/ 4668, 1434, 2916, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_jrb_sliding_box
    object /*unk2*/ 0x01, /*unk3*/ 0x55, /*pos*/ 6048, -5381, 1154, /*angle*/ 0, 340, 0, /*behArg*/ 0x00000000, /*beh*/ beh_unagi
    object /*unk2*/ 0x02, /*unk3*/ 0x55, /*pos*/ 8270, -3130, 1846, /*angle*/ 0, 285, 0, /*behArg*/ 0x01010000, /*beh*/ beh_unagi
    object /*unk2*/ 0x3C, /*unk3*/ 0x55, /*pos*/ 6048, -5381, 1154, /*angle*/ 0, 340, 0, /*behArg*/ 0x02020000, /*beh*/ beh_unagi
    object /*unk2*/ 0x3E, /*unk3*/ 0x00, /*pos*/ 4988, -5221, 2473, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_jet_stream
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1800, -2812, -2100, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_treasure_chests_jrb
    object /*unk2*/ 0x3E, /*unk3*/ 0xC3, /*pos*/ -1956, 1331, 6500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bobomb_buddy_cannon_role
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 1834, -2556, -7090, /*angle*/ 0, 194, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -2005, -2556, -3506, /*angle*/ 0, 135, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 1578, -2556, -5554, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 42, -2556, -6578, /*angle*/ 0, 135, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -981, -2556, -5298, /*angle*/ 0, 255, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -6549, 1536, 4343, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 1322, -2556, -3506, /*angle*/ 0, 165, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 6442, -2556, -6322, /*angle*/ 0, 135, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 3882, -2556, -5042, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 1497, 1741, 7810, /*angle*/ 0, 14, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -3978, 1536, -85, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -5228, 1230, 2106, /*angle*/ 0, 323, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -7481, 1536, 185, /*angle*/ 0, 149, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -5749, 1536, -1113, /*angle*/ 0, 255, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -5332, 1434, 1023, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -815, -613, 3556, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -3429, 819, 4948, /*angle*/ 0, 284, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -1940, 410, 2377, /*angle*/ 0, 194, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -1798, -716, 4330, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -845, 922, 7668, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 6741, -2886, 3556, /*angle*/ 0, 135, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 255, -101, 4719, /*angle*/ 0, 45, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 1787, -306, 5133, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 1079, -613, 2299, /*angle*/ 0, 75, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 2931, -1697, 980, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 3036, -4709, 4027, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 4222, -1125, 7083, /*angle*/ 0, 104, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 6650, -613, 4941, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 5764, -4709, 4427, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 3693, -4709, 856, /*angle*/ 0, 135, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 7981, 410, 2704, /*angle*/ 0, 165, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 2917, -3046, 4818, /*angle*/ 0, 241, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 5896, -393, -123, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_solid
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 53, 2355, 2724, /*angle*/ 0, 0, 0, /*behArg*/ 0x00290000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 659, 2560, 3314, /*angle*/ 0, 0, 0, /*behArg*/ 0x00290000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1087, 2150, 3798, /*angle*/ 0, 0, 0, /*behArg*/ 0x00290000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2535, 1075, 6113, /*angle*/ 0, 0, 0, /*behArg*/ 0x00610000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 2078, -2863, -4696, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_pillar
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ -1403, -2863, -4696, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_pillar
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ -1096, -2863, -3262, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_pillar
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 337, -2863, -5106, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_pillar
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 2078, -2863, -6232, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_pillar
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 4330, -2863, -5618, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_falling_pillar
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 2078, -2966, -4696, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pillar_base
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ -1403, -2966, -4696, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pillar_base
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ -1096, -2966, -3262, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pillar_base
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 337, -2966, -5106, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pillar_base
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 2078, -2966, -6232, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pillar_base
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 4330, -2966, -5618, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pillar_base
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ -1059, 1025, 7072, /*angle*/ 0, 247, 0, /*behArg*/ 0x00000000, /*beh*/ beh_jrb_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4236, 1044, 2136, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_inside_cannon
    return

script_func_local_3:
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 4900, 2400, 800, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_hidden_red_coin_star
.ifdef VERSION_JP
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 1540, 2160, 2130, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
.endif
.ifdef VERSION_US
    object /*unk2*/ 0x3F, /*unk3*/ 0x89, /*pos*/ 1540, 2160, 2130, /*angle*/ 0, 0, 0, /*behArg*/ 0x04080000, /*beh*/ beh_exclamation_box
.endif
    object /*unk2*/ 0x3E, /*unk3*/ 0x7A, /*pos*/ 5000, -4800, 2500, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 400, -350, -2700, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_treasure_chests_ship
    return

script_func_local_5:
    return

glabel level_jrb_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_jrb_segment_7SegmentRomStart, /*romEnd*/ _level_jrb_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_textures_mio0SegmentRomStart, /*romEnd*/ _flower_textures_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _jrb_textures_mio0SegmentRomStart, /*romEnd*/ _jrb_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _clouds_skybox_mio0SegmentRomStart, /*romEnd*/ _clouds_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _sea_creatures_mio0SegmentRomStart, /*romEnd*/ _sea_creatures_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _sea_creatures_geoSegmentRomStart, /*romEnd*/ _sea_creatures_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _skeeter_fish_treasurechest_mio0SegmentRomStart, /*romEnd*/ _skeeter_fish_treasurechest_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _skeeter_fish_treasurechest_geoSegmentRomStart,  /*romEnd*/ _skeeter_fish_treasurechest_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_5
    jump_link /*target*/ script_func_global_14
    cmd22 /*unk2*/ 0x0035, /*unk4*/ jrb_geo_000978
    cmd22 /*unk2*/ 0x0036, /*unk4*/ jrb_geo_0009B0
    cmd22 /*unk2*/ 0x0037, /*unk4*/ jrb_geo_0009E8
    cmd22 /*unk2*/ 0x0038, /*unk4*/ jrb_geo_000A00
    cmd22 /*unk2*/ 0x0039, /*unk4*/ jrb_geo_000990
    cmd22 /*unk2*/ 0x003A, /*unk4*/ jrb_geo_0009C8
    cmd22 /*unk2*/ 0x003B, /*unk4*/ jrb_geo_000930
    cmd22 /*unk2*/ 0x003C, /*unk4*/ jrb_geo_000960
    cmd22 /*unk2*/ 0x003D, /*unk4*/ jrb_geo_000900
    cmd22 /*unk2*/ 0x003E, /*unk4*/ jrb_geo_000918
    cmd22 /*unk2*/ 0x003F, /*unk4*/ jrb_geo_000948

    area /*index*/ 1, /*geo*/ jrb_geo_000A18
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6750, 2126, 1482, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x0C, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x35, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x67, /*destLevel2*/ 0x00
        whirlpool /*unk2*/ 0, /*unk3*/ 3, /*pos*/ 4979, -5222, 2482, /*strength*/ -30
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ jrb_seg7_area_1_collision
        cmd39 /*unk4*/ jrb_seg7_area_1_macro_objs 
        set_music /*unk2*/ 0x0003, /*seq*/ 0x0005
        terrain_type /*terrainType*/ 0x0005
    end_area

    area /*index*/ 2, /*geo*/ jrb_geo_000AFC
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 928, 1050, -1248, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_94
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0C, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x35, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x67, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_4
        jump_link /*target*/ script_func_local_5
        terrain /*terrainData*/ jrb_seg7_area_2_collision
        cmd39 /*unk4*/ jrb_seg7_area_2_macro_objs 
        set_music /*unk2*/ 0x0003, /*seq*/ 0x0005
        terrain_type /*terrainType*/ 0x0005
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -6750, 1126, 1482
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_jrb.s"
.align 4
