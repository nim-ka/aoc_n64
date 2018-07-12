.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bits_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -2370, -4525, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00100000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -2611, 3544, -904, /*angle*/ 0, 0, 0, /*behArg*/ 0x00CF0000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -4700, 3544, -904, /*angle*/ 0, 180, 0, /*behArg*/ 0x008F0000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 4139, -1740, -1831, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -6459, 1732, -904, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -4770, 1732, -904, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ -1748, -1330, -1094, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_four_rotating_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 2275, 5628, -1315, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_four_rotating_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 3114, 4701, -1320, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_four_rotating_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 2793, 2325, -904, /*angle*/ 0, 0, 0, /*behArg*/ 0x00610000, /*beh*/ beh_climbable_cage
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ 27, -1555, -713, /*angle*/ 0, 90, 0, /*behArg*/ 0x00010000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x40, /*pos*/ -306, -4300, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 1769, -234, -899, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_floor_switch_press_animation
    object /*unk2*/ 0x1F, /*unk3*/ 0xCF, /*pos*/ -279, -234, -900, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_purple_switch_staircase
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6460, 2039, -905, /*angle*/ 0, 0, 0, /*behArg*/ 0x00CF0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3326, 3227, -905, /*angle*/ 0, 0, 0, /*behArg*/ 0x004D0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5518, 3184, -4019, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 6465, 3731, -1915, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5915, 3718, -4019, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 350, 6800, -6800, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_course_red_coin_star
    return

glabel level_bits_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bits_segment_7SegmentRomStart, /*romEnd*/ _level_bits_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bits_skybox_mio0SegmentRomStart, /*romEnd*/ _bits_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _rr_textures_mio0SegmentRomStart, /*romEnd*/ _rr_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _koopa_log_piranha_whomp_chomp_mio0SegmentRomStart, /*romEnd*/ _koopa_log_piranha_whomp_chomp_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _koopa_log_piranha_whomp_chomp_geoSegmentRomStart,  /*romEnd*/ _koopa_log_piranha_whomp_chomp_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_15
    jump_link /*target*/ script_func_global_1
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E000430
    cmd22 /*unk2*/ 0x0004, /*unk4*/ 0x0E000448
    cmd22 /*unk2*/ 0x0005, /*unk4*/ 0x0E000460
    cmd22 /*unk2*/ 0x0006, /*unk4*/ 0x0E000478
    cmd22 /*unk2*/ 0x0007, /*unk4*/ 0x0E000490
    cmd22 /*unk2*/ 0x0008, /*unk4*/ 0x0E0004A8
    cmd22 /*unk2*/ 0x0009, /*unk4*/ 0x0E0004C0
    cmd22 /*unk2*/ 0x000A, /*unk4*/ 0x0E0004D8
    cmd22 /*unk2*/ 0x000B, /*unk4*/ 0x0E0004F0
    cmd22 /*unk2*/ 0x000C, /*unk4*/ 0x0E000508
    cmd22 /*unk2*/ 0x000D, /*unk4*/ 0x0E000520
    cmd22 /*unk2*/ 0x000E, /*unk4*/ 0x0E000538
    cmd22 /*unk2*/ 0x000F, /*unk4*/ 0x0E000550
    cmd22 /*unk2*/ 0x0010, /*unk4*/ 0x0E000568
    cmd22 /*unk2*/ 0x0011, /*unk4*/ 0x0E000580
    cmd22 /*unk2*/ 0x0012, /*unk4*/ 0x0E000598
    cmd22 /*unk2*/ 0x0013, /*unk4*/ 0x0E0005B0
    cmd22 /*unk2*/ 0x0014, /*unk4*/ 0x0E0005C8
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E0005E0
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E0005F8
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E000610
    cmd22 /*unk2*/ 0x003C, /*unk4*/ 0x0E000628
    cmd22 /*unk2*/ 0x003D, /*unk4*/ 0x0E000640
    cmd22 /*unk2*/ 0x003E, /*unk4*/ 0x0E000658
    cmd22 /*unk2*/ 0x003F, /*unk4*/ 0x0E000670
    cmd22 /*unk2*/ 0x0040, /*unk4*/ 0x0E000688
    cmd22 /*unk2*/ 0x0041, /*unk4*/ 0x0E0006A0
    cmd22 /*unk2*/ 0x0042, /*unk4*/ 0x0E0006B8
    cmd22 /*unk2*/ 0x0043, /*unk4*/ 0x0E0006D0
    cmd22 /*unk2*/ 0x0044, /*unk4*/ 0x0E0006E8
    cmd22 /*unk2*/ 0x0045, /*unk4*/ 0x0E000700
    cmd22 /*unk2*/ 0x0049, /*unk4*/ 0x16000388

    area /*index*/ 1, /*geo*/ 0x0E000718
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7039, -3812, 4, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        object /*unk2*/ 0x1F, /*unk3*/ 0x49, /*pos*/ 351, 6652, -6030, /*angle*/ 0, 0, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_warp_pipe
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 351, 6800, -3900, /*angle*/ 0, 180, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_warps_70
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x15, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x22, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x15, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x6B, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        terrain /*terrainData*/ 0x07016E18
        cmd39 /*unk4*/ 0x0701A76C
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0011
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -7039, -4812, 4
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_bits.s"
.align 4
