.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/wdw_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 3390, 0, 384, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_square_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -767, 384, 3584, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_square_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -767, 384, 1536, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_square_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -767, 2304, -1279, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_square_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -578, 2177, 3009, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_arrow_lift
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -1474, 2177, 3393, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_arrow_lift
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -1602, 2177, 3009, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_arrow_lift
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -1090, 2177, 3521, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_arrow_lift
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -962, 2177, 3137, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_arrow_lift
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_initialize_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1920, 2560, -3583, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 3328, 256, 2918, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 2048, 1792, 2176, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 640, 1024, 3712, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1810, 40, -3118, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0xCF, /*pos*/ 3360, 1280, 3420, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_floor_switch_hidden_objects
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 2239, 1126, 3391, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_hidden_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 1215, 1357, 2751, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_hidden_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 1215, 1229, 3391, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_hidden_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 1599, 1101, 3391, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_hidden_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 2879, 1152, 3391, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_hidden_object
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 1024, 3277, -2112, /*angle*/ 0, 0, 0, /*behArg*/ 0x00320000, /*beh*/ beh_wdw_express_elevator_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 1024, 3277, -1663, /*angle*/ 0, 0, 0, /*behArg*/ 0x00320000, /*beh*/ beh_wdw_express_elevator
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -767, 1152, 128, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rect_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ -767, 2304, -2687, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rect_floating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3C, /*pos*/ 734, 3840, 84, /*angle*/ 0, 0, 0, /*behArg*/ 0x46010000, /*beh*/ beh_rotating_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x69, /*pos*/ 2956, 288, -468, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_skeeter
    object /*unk2*/ 0x1F, /*unk3*/ 0x69, /*pos*/ 184, 384, 621, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_skeeter
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_initialize_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -3583, -2508, -2047, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -767, -127, 1792, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_trigger
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -768, -665, 3584, /*angle*/ 0, 0, 0, /*behArg*/ 0x005C0000, /*beh*/ beh_pole_grabbing
    return

script_func_local_3:
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 3360, 1580, 2660, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_hidden_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 890, 3400, -2040, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_collect_star
    return

script_func_local_4:
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -770, -1600, 3600, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 2180, -840, 3720, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_wdw_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_wdw_segment_7SegmentRomStart, /*romEnd*/ _level_wdw_segment_7SegmentRomEnd
    cmd1A /*seg*/ 0x09, /*romStart*/ wf_textures, /*romEnd*/ wf_textures_end
    load_mio0 /*seg*/ 0x0A, /*romStart*/ wdw_skybox, /*romEnd*/ wdw_skybox_end
    load_mio0 /*seg*/ 0x05, /*romStart*/ yoshiegg_owl_thwomp, /*romEnd*/ yoshiegg_owl_thwomp_end
    load_raw /*seg*/ 0x0C, /*romStart*/ owl_thwomp_bullet_heave, /*romEnd*/ owl_thwomp_bullet_heave_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ treasure_chest_fish, /*romEnd*/ treasure_chest_fish_end
    load_raw /*seg*/ 0x0D, /*romStart*/ skeeter_fish_manta_chest, /*romEnd*/ skeeter_fish_manta_chest_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_2
    jump_link /*target*/ script_func_global_14
    cmd22 /*unk2*/ 0x0017, /*unk4*/ 0x16000FE8
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000580
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000598
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E0005C0
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E0005E8
    cmd22 /*unk2*/ 0x003A, /*unk4*/ 0x0E000610
    cmd22 /*unk2*/ 0x003B, /*unk4*/ 0x0E000628
    cmd22 /*unk2*/ 0x003C, /*unk4*/ 0x0E000640

    area /*index*/ 1, /*geo*/ 0x0E000658
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3395, 3580, 384, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 818, 0, 3634, /*angle*/ 0, 45, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2865, 3328, 3065, /*angle*/ 0, 0, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x0B, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x0B, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_1
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x32, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x64, /*destLevel2*/ 0x00
        instant_warp /*index*/ 1, /*destArea*/ 2, /*displace*/ 0, 0, 0
        terrain /*terrainData*/ 0x07014150
        cmd39 /*unk4*/ 0x070160D8
        set_menu_music /*unk2*/ 0x0003, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 2, /*geo*/ 0x0E000724
        jump_link /*target*/ script_func_local_4
        jump_link /*target*/ script_func_local_2
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x32, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x64, /*destLevel2*/ 0x00
        instant_warp /*index*/ 0, /*destArea*/ 1, /*displace*/ 0, 0, 0
        terrain /*terrainData*/ 0x0701633C
        cmd39 /*unk4*/ 0x07018224
        set_menu_music /*unk2*/ 0x0003, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0005
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ 3395, 2580, 384
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_wdw.geo.s"
.align 4
