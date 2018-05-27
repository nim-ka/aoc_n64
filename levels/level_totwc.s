.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/wing_cap_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 0, -2047, 10, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_activate_cap_switch
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 800, -1700, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_totwc_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x004BCBD0, /*romEnd*/ 0x004C06A0
    load_mio0 /*seg*/ 0x0A, /*romStart*/ 0x002E5E20, /*romEnd*/ 0x002EFA80
    cmd1A /*seg*/ 0x09, /*romStart*/ 0x0033BCB0, /*romEnd*/ 0x0033F6E0
    load_mio0 /*seg*/ 0x05, /*romStart*/ checkerboard_question, /*romEnd*/ checkerboard_question_end
    load_raw /*seg*/ 0x0C, /*romStart*/ cap_switch, /*romEnd*/ cap_switch_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_9
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E000160

    area /*index*/ 1, /*geo*/ 0x0E000188
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4095, 2935, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_78
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x20, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x26, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x23, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_1
        terrain /*terrainData*/ 0x07007A18
        cmd39 /*unk4*/ 0x070088AC
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x83
        set_menu_music /*unk2*/ 0x0000, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -4095, 2935, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_totwc.geo.s"
.align 4
