.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/wf_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x03, /*pos*/ 2305, 2432, -255, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x04, /*pos*/ 3405, 1664, -1791, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x05, /*pos*/ 3840, 0, -2303, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x05, /*pos*/ 3840, 0, -1279, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x06, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x07, /*pos*/ 1757, 3519, -3151, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0A, /*pos*/ 3840, 794, 2688, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0C, /*pos*/ 1408, 2522, 2431, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_static_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x0D, /*pos*/ -2560, 2560, -256, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_giant_pole
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0xAE, /*pos*/ 3300, 1070, 1, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_formation_eyes
    object /*unk2*/ 0x1F, /*unk3*/ 0xAE, /*pos*/ 3300, 1070, 1281, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rock_formation_eyes
    object /*unk2*/ 0x1F, /*unk3*/ 0xB1, /*pos*/ 3300, 1070, 641, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_large_rock_eyes
    object /*unk2*/ 0x1F, /*unk3*/ 0xAF, /*pos*/ -255, 2560, 2304, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_clocklike_rotation
    object /*unk2*/ 0x1F, /*unk3*/ 0xAD, /*pos*/ 3328, 1075, -1791, /*angle*/ 0, 90, 0, /*behArg*/ 0x00020000, /*beh*/ beh_sliding_brick_platform_2
    object /*unk2*/ 0x1F, /*unk3*/ 0xAD, /*pos*/ 3328, 1075, -767, /*angle*/ 0, 90, 0, /*behArg*/ 0x00010000, /*beh*/ beh_sliding_brick_platform_2
    object /*unk2*/ 0x1F, /*unk3*/ 0xAD, /*pos*/ 3328, 1075, -2815, /*angle*/ 0, 90, 0, /*behArg*/ 0x00030000, /*beh*/ beh_sliding_brick_platform_2
    object /*unk2*/ 0x1F, /*unk3*/ 0xB2, /*pos*/ 1792, 2496, 1600, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_wf_tumbling_bridge
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 512, 2176, 2944, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_breakable_wall
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -1023, 2176, 2944, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_breakable_wall_2
    object /*unk2*/ 0x3E, /*unk3*/ 0x38, /*pos*/ 13, 3584, -1407, /*angle*/ 0, 315, 0, /*behArg*/ 0x00000000, /*beh*/ beh_kickable_board
    object /*unk2*/ 0x3E, /*unk3*/ 0xD4, /*pos*/ -384, 3584, 6, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_1up
    object /*unk2*/ 0x1F, /*unk3*/ 0x10, /*pos*/ 2304, 3584, -2303, /*angle*/ 0, 0, 0, /*behArg*/ 0x08000000, /*beh*/ beh_rotating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x10, /*pos*/ 3200, 3328, -1791, /*angle*/ 0, 0, 0, /*behArg*/ 0x08000000, /*beh*/ beh_rotating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x10, /*pos*/ 2688, 3584, -895, /*angle*/ 0, 0, 0, /*behArg*/ 0x08000000, /*beh*/ beh_rotating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2495, 1331, -256, /*angle*/ 0, 0, 0, /*behArg*/ 0x003D0000, /*beh*/ beh_pole_grabbing
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x58, /*pos*/ 3462, 1939, -1545, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_thwomp
    object /*unk2*/ 0x1F, /*unk3*/ 0x58, /*pos*/ 3462, 1075, -3314, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_thwomp_2
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -856, 922, 3819, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_multiple_coins
    object /*unk2*/ 0x1F, /*unk3*/ 0x64, /*pos*/ 1822, 2560, -101, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_piranha_plant_2
    object /*unk2*/ 0x1F, /*unk3*/ 0x64, /*pos*/ 4625, 256, 5017, /*angle*/ 0, -90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_piranha_plant_2
    object /*unk2*/ 0x1F, /*unk3*/ 0x64, /*pos*/ 689, 2560, 1845, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_piranha_plant_2
    object /*unk2*/ 0x1F, /*unk3*/ 0x67, /*pos*/ -1545, 2560, -286, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_whomp
    object /*unk2*/ 0x1F, /*unk3*/ 0x67, /*pos*/ 189, 2560, -1857, /*angle*/ 0, -135, 0, /*behArg*/ 0x00000000, /*beh*/ beh_small_whomp
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4736, 256, 4992, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4608, 256, 5120, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4608, 256, 4992, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4608, 256, 4864, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4480, 256, 4992, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4608, 256, 256, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4736, 256, 128, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4480, 256, 128, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4608, 256, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0xBB, /*pos*/ 4608, 256, 128, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_butterfly
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1035, 2880, -900, /*angle*/ 0, 45, 0, /*behArg*/ 0x00000000, /*beh*/ beh_checkerboard_elevator_group
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ 1280, 3712, 968, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bullet_bill
    object /*unk2*/ 0x3E, /*unk3*/ 0x08, /*pos*/ 0, 3584, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tower
    object /*unk2*/ 0x3E, /*unk3*/ 0x09, /*pos*/ 1280, 3584, 896, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bullet_bill_cannon
    object /*unk2*/ 0x3E, /*unk3*/ 0x00, /*pos*/ 0, 3483, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tower_platform_group
    object /*unk2*/ 0x3E, /*unk3*/ 0x39, /*pos*/ -511, 3584, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tower_door
    object /*unk2*/ 0x3C, /*unk3*/ 0xC3, /*pos*/ -1700, 1140, 3500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bobomb_buddy_cannon_role
    object /*unk2*/ 0x3C, /*unk3*/ 0x56, /*pos*/ 2560, 700, 4608, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hoot
    return

script_func_local_4:
    object /*unk2*/ 0x01, /*unk3*/ 0x67, /*pos*/ 0, 3584, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_whomp_king_boss
    object /*unk2*/ 0x3E, /*unk3*/ 0x7A, /*pos*/ 300, 5550, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -2500, 1500, -750, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 4600, 550, 2500, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 2880, 4300, 190, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 590, 2450, 2650, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_wf_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_wf_segment_7SegmentRomStart, /*romEnd*/ _level_wf_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ cloud_floor_skybox, /*romEnd*/ cloud_floor_skybox_end
    cmd1A /*seg*/ 0x09, /*romStart*/ wf_textures, /*romEnd*/ wf_textures_end
    load_mio0 /*seg*/ 0x05, /*romStart*/ yoshiegg_owl_thwomp, /*romEnd*/ yoshiegg_owl_thwomp_end
    load_raw /*seg*/ 0x0C, /*romStart*/ owl_thwomp_bullet_heave, /*romEnd*/ owl_thwomp_bullet_heave_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ koopa_whomp, /*romEnd*/ koopa_whomp_end
    load_raw /*seg*/ 0x0D, /*romStart*/ koopa_log_piranha_whomp_chomp, /*romEnd*/ koopa_log_piranha_whomp_chomp_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_2
    jump_link /*target*/ script_func_global_15
    cmd22 /*unk2*/ 0x0017, /*unk4*/ 0x16000FE8
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E0007E0
    cmd22 /*unk2*/ 0x0004, /*unk4*/ 0x0E000820
    cmd22 /*unk2*/ 0x0005, /*unk4*/ 0x0E000860
    cmd22 /*unk2*/ 0x0006, /*unk4*/ 0x0E000878
    cmd22 /*unk2*/ 0x0007, /*unk4*/ 0x0E000890
    cmd22 /*unk2*/ 0x0008, /*unk4*/ 0x0E0008A8
    cmd22 /*unk2*/ 0x0009, /*unk4*/ 0x0E0008E8
    cmd22 /*unk2*/ 0x000A, /*unk4*/ 0x0E000900
    cmd22 /*unk2*/ 0x000C, /*unk4*/ 0x0E000940
    cmd22 /*unk2*/ 0x000D, /*unk4*/ 0x0E000AE0
    cmd22 /*unk2*/ 0x000E, /*unk4*/ 0x0E000958
    cmd22 /*unk2*/ 0x000F, /*unk4*/ 0x0E0009A0
    cmd22 /*unk2*/ 0x0010, /*unk4*/ 0x0E0009B8
    cmd22 /*unk2*/ 0x0011, /*unk4*/ 0x0E0009D0
    cmd22 /*unk2*/ 0x0012, /*unk4*/ 0x0E0009E8
    cmd22 /*unk2*/ 0x00AE, /*unk4*/ 0x0E000A00
    cmd22 /*unk2*/ 0x00B1, /*unk4*/ 0x0E000A40
    cmd22 /*unk2*/ 0x00AF, /*unk4*/ 0x0E000A58
    cmd22 /*unk2*/ 0x00AD, /*unk4*/ 0x0E000A98
    cmd22 /*unk2*/ 0x00B0, /*unk4*/ 0x0E000AB0
    cmd22 /*unk2*/ 0x00B2, /*unk4*/ 0x0E000AC8
    cmd22 /*unk2*/ 0x002C, /*unk4*/ 0x0E000AF8
    cmd22 /*unk2*/ 0x002D, /*unk4*/ 0x0E000B10
    cmd22 /*unk2*/ 0x002E, /*unk4*/ 0x0E000B38
    cmd22 /*unk2*/ 0x002F, /*unk4*/ 0x0E000B60
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000B78
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000B90
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000BA8
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E000BE0
    cmd22 /*unk2*/ 0x003A, /*unk4*/ 0x0E000BC8

    area /*index*/ 1, /*geo*/ 0x0E000BF8
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2600, 1256, 5120, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2925, 2560, -947, /*angle*/ 0, 19, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2548, 1075, -3962, /*angle*/ 0, 51, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x18, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x18, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x18, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        terrain /*terrainData*/ 0x070102D8
        cmd39 /*unk4*/ 0x07011C38
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x1E
        set_music /*unk2*/ 0x0005, /*seq*/ 0x0003
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ 2600, 256, 5120
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_wf.geo.s"
.align 4
