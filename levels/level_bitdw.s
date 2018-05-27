.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bidw_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -1966, -3154, 3586, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_squarish_path_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -1352, -3154, 4200, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_squarish_path_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -2963, 1017, -2464, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_squarish_path_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -2349, 1017, -1849, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_squarish_path_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -2349, 1017, -1235, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_squarish_path_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -1735, 1017, -621, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_squarish_path_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 1491, 1273, 512, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -147, 894, 512, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -5728, 819, -2151, /*angle*/ 0, 0, 0, /*behArg*/ 0x03CE0000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -204, -1924, 3381, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_four_rotating_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ 5279, 1740, -6, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_floor_switch_press_animation
    object /*unk2*/ 0x1F, /*unk3*/ 0xCF, /*pos*/ 3922, 1740, -7, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_purple_switch_staircase
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3092, -2795, 2842, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2463, -2386, 2844, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 7180, 3000, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_course_red_coin_star
    return

glabel level_bitdw_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x00452D40, /*romEnd*/ 0x00459EA0
    load_mio0 /*seg*/ 0x0A, /*romStart*/ 0x00300270, /*romEnd*/ 0x0030B460
    cmd1A /*seg*/ 0x09, /*romStart*/ 0x0033BCB0, /*romEnd*/ 0x0033F6E0
    load_mio0 /*seg*/ 0x05, /*romStart*/ enemy, /*romEnd*/ enemy_end
    load_raw /*seg*/ 0x0C, /*romStart*/ bubba_wiggler_lakitu, /*romEnd*/ bubba_wiggler_lakitu_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ mri_swoop, /*romEnd*/ mri_swoop_end
    load_raw /*seg*/ 0x0D, /*romStart*/ mri_swoop_snufit_dorrie_scuttlebug, /*romEnd*/ mri_swoop_snufit_dorrie_scuttlebug_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_12
    jump_link /*target*/ script_func_global_18
    jump_link /*target*/ script_func_global_1
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E0003C0
    cmd22 /*unk2*/ 0x0004, /*unk4*/ 0x0E0003D8
    cmd22 /*unk2*/ 0x0005, /*unk4*/ 0x0E0003F0
    cmd22 /*unk2*/ 0x0006, /*unk4*/ 0x0E000408
    cmd22 /*unk2*/ 0x0007, /*unk4*/ 0x0E000420
    cmd22 /*unk2*/ 0x0008, /*unk4*/ 0x0E000438
    cmd22 /*unk2*/ 0x0009, /*unk4*/ 0x0E000450
    cmd22 /*unk2*/ 0x000A, /*unk4*/ 0x0E000468
    cmd22 /*unk2*/ 0x000B, /*unk4*/ 0x0E000480
    cmd22 /*unk2*/ 0x000C, /*unk4*/ 0x0E000498
    cmd22 /*unk2*/ 0x000D, /*unk4*/ 0x0E0004B0
    cmd22 /*unk2*/ 0x000E, /*unk4*/ 0x0E0004C8
    cmd22 /*unk2*/ 0x000F, /*unk4*/ 0x0E0004E0
    cmd22 /*unk2*/ 0x0010, /*unk4*/ 0x0E0004F8
    cmd22 /*unk2*/ 0x0011, /*unk4*/ 0x0E000510
    cmd22 /*unk2*/ 0x0012, /*unk4*/ 0x16000388
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000558
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000540
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000528
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E000570
    cmd22 /*unk2*/ 0x003A, /*unk4*/ 0x0E000588
    cmd22 /*unk2*/ 0x003B, /*unk4*/ 0x0E0005A0
    cmd22 /*unk2*/ 0x003C, /*unk4*/ 0x0E0005B8
    cmd22 /*unk2*/ 0x003D, /*unk4*/ 0x0E0005D0
    cmd22 /*unk2*/ 0x003E, /*unk4*/ 0x0E0005E8
    cmd22 /*unk2*/ 0x003F, /*unk4*/ 0x0E000600

    area /*index*/ 1, /*geo*/ 0x0E000618
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7443, -2153, 3886, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        object /*unk2*/ 0x1F, /*unk3*/ 0x12, /*pos*/ 6816, 2860, -7, /*angle*/ 0, 0, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_warp_pipe
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5910, 3500, -7, /*angle*/ 0, 90, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_warps_70
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x11, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x1E, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x11, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x25, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ 0x0700D460
        cmd39 /*unk4*/ 0x0700F438
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x5A
        set_menu_music /*unk2*/ 0x0000, /*seq*/ 0x0011
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -7443, -3153, 3886
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_bitdw.geo.s"
.align 4
