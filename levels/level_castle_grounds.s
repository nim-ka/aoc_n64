.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/castle_grounds_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    warp_node /*id*/ 0x00, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x00, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x01, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x01, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x02, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x02, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 900, -1710, /*angle*/ 0, 180, 0, /*behArg*/ 0x00030000, /*beh*/ beh_warps_70
    warp_node /*id*/ 0x03, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1328, 260, 4664, /*angle*/ 0, 180, 0, /*behArg*/ 0x00040000, /*beh*/ beh_warps_6C
    warp_node /*id*/ 0x04, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x04, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3379, -815, -2025, /*angle*/ 0, 0, 0, /*behArg*/ 0x3C050000, /*beh*/ beh_warp
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3379, -500, -2025, /*angle*/ 0, 180, 0, /*behArg*/ 0x00060000, /*beh*/ beh_warps_90
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3799, -1199, -5816, /*angle*/ 0, 0, 0, /*behArg*/ 0x00070000, /*beh*/ beh_warps_94
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3379, -500, -2025, /*angle*/ 0, 180, 0, /*behArg*/ 0x00080000, /*beh*/ beh_warps_8C
    warp_node /*id*/ 0x05, /*destLevel1*/ 0x12, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x06, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x06, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x07, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x07, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x08, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x08, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5408, 4500, 3637, /*angle*/ 0, 225, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
    warp_node /*id*/ 0x0A, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6901, 2376, -6509, /*angle*/ 0, 230, 0, /*behArg*/ 0x00140000, /*beh*/ beh_warps_64
    warp_node /*id*/ 0x14, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x14, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4997, -1250, 2258, /*angle*/ 0, 210, 0, /*behArg*/ 0x001E0000, /*beh*/ beh_warps_94
    warp_node /*id*/ 0x1E, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x1E, /*destLevel2*/ 0x00
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5812, 100, -5937, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7430, 1500, 873, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_birds_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -80, 1500, 5004, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_birds_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 7131, 1500, -2989, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_birds_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7430, 1500, -5937, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ambiant_sounds
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_moat_grills
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_invisible_objects_under_bridge
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -4878, -787, -5690, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -4996, -787, -5548, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5114, -787, -5406, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5212, -787, -5219, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5311, -787, -5033, /*angle*/ 0, 0, 0, /*behArg*/ 0x00040000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5419, -787, -4895, /*angle*/ 0, 0, 0, /*behArg*/ 0x00050000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5527, -787, -4757, /*angle*/ 0, 0, 0, /*behArg*/ 0x00060000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5686, -787, -4733, /*angle*/ 0, 0, 0, /*behArg*/ 0x00070000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x8E, /*pos*/ -5845, -787, -4710, /*angle*/ 0, 0, 0, /*behArg*/ 0x00080000, /*beh*/ beh_water_mist2
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5223, -975, 1667, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_fish_2
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -5069, 850, 3221, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_multiple_birds_flying
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -4711, 742, 433, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_multiple_birds_flying
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ 5774, 913, -1114, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_multiple_birds_flying
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1328, 260, 4664, /*angle*/ 0, 180, 0, /*behArg*/ 0x00280000, /*beh*/ beh_intro_scene
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_at_120_stars
    object /*unk2*/ 0x1F, /*unk3*/ 0x66, /*pos*/ 11, 803, -3015, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_lakitu
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -3213, 3348, -3011, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_castle_flag_waving
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 3213, 3348, -3011, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_castle_flag_waving
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -3835, 3348, -6647, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_castle_flag_waving
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 3835, 3348, -6647, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_castle_flag_waving
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -4508, 406, 4400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -4408, 406, 4500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -4708, 406, 4100, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -6003, 473, -2621, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -6003, 473, -2321, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 6543, 461, -617, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 6143, 461, -617, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 5773, 775, -5722, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 5873, 775, -5622, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 5473, 775, -5322, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -1504, 326, 3196, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ -1204, 326, 3296, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 0, 3174, -5625, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_yoshi
    return

glabel level_castle_grounds_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_castle_grounds_segment_7SegmentRomStart, /*romEnd*/ _level_castle_grounds_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _water_skybox_mio0SegmentRomStart, /*romEnd*/ _water_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _castle_grounds_textures_mio0SegmentRomStart, /*romEnd*/ _castle_grounds_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _peach_toadstool_yoshi_birds_mio0SegmentRomStart, /*romEnd*/ _peach_toadstool_yoshi_birds_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _peach_toadstool_yoshi_birds_geoSegmentRomStart,  /*romEnd*/ _peach_toadstool_yoshi_birds_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _lakitu_toad_mips_boo_mio0SegmentRomStart, /*romEnd*/ _lakitu_toad_mips_boo_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _lakitu_toad_mips_boo_geoSegmentRomStart,  /*romEnd*/ _lakitu_toad_mips_boo_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_11
    jump_link /*target*/ script_func_global_16
    cmd22 /*unk2*/ 0x0003, /*unk4*/ castle_grounds_geo_0006F4
    cmd22 /*unk2*/ 0x0017, /*unk4*/ coin_X_geo_000FE8
    cmd22 /*unk2*/ 0x0016, /*unk4*/ common_seg16_geo_pipe
    cmd22 /*unk2*/ 0x0026, /*unk4*/ coin_X_geo_0003A8
    cmd22 /*unk2*/ 0x0029, /*unk4*/ coin_X_geo_0005F8
    cmd22 /*unk2*/ 0x0036, /*unk4*/ castle_grounds_geo_00070C
    cmd22 /*unk2*/ 0x0037, /*unk4*/ castle_grounds_geo_000660
    cmd22 /*unk2*/ 0x0038, /*unk4*/ castle_grounds_geo_000724

    area /*index*/ 1, /*geo*/ castle_grounds_geo_00073C
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        terrain /*terrainData*/ castle_grounds_collision
        cmd39 /*unk4*/ castle_grounds_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0000
        terrain_type /*terrainType*/ 0x0000
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ -1328, 260, 4664
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_castle_grounds.s"
.align 4
