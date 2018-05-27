.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/vanish_cap_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 154, -1919, -6256, /*angle*/ 0, 270, 0, /*behArg*/ 0x00070000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -2047, -3378, -2047, /*angle*/ 0, 0, 0, /*behArg*/ 0x00070000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 3251, -1082, -6256, /*angle*/ 0, 270, 0, /*behArg*/ 0x014B0000, /*beh*/ beh_checkerboard_elevator_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 2355, -1901, -6256, /*angle*/ 0, 270, 0, /*behArg*/ 0x014B0000, /*beh*/ beh_checkerboard_elevator_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 1459, -1594, -6256, /*angle*/ 0, 90, 0, /*behArg*/ 0x014B0000, /*beh*/ beh_checkerboard_elevator_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -1151, -2413, -6256, /*angle*/ 0, 270, 0, /*behArg*/ 0x014B0000, /*beh*/ beh_checkerboard_elevator_group
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 4506, 26, -6246, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_activate_cap_switch
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4600, 250, -4500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_vcutm_entry
    init_level
    cmd1A /*seg*/ 0x09, /*romStart*/ 0x0035D2B0, /*romEnd*/ 0x00363F20
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x0045A540, /*romEnd*/ 0x0045F160
    load_mio0 /*seg*/ 0x05, /*romStart*/ checkerboard_question, /*romEnd*/ checkerboard_question_end
    load_raw /*seg*/ 0x0C, /*romStart*/ cap_switch, /*romEnd*/ cap_switch_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_9
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E0001F0
    cmd22 /*unk2*/ 0x0016, /*unk4*/ 0x16000388

    area /*index*/ 1, /*geo*/ 0x0E000208
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6143, 6734, -6143, /*angle*/ 0, 0, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x12, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x07, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x08, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x06, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        terrain /*terrainData*/ 0x07009750
        cmd39 /*unk4*/ 0x0700AB0C
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x81
        set_menu_music /*unk2*/ 0x0000, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 0, /*pos*/ -6143, 5734, -6143
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_vcutm.geo.s"
.align 4
