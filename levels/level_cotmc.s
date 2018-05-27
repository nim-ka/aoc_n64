.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/metal_cap_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x55, /*pos*/ 0, 363, -6144, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_activate_cap_switch
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 500, -7373, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 500, 3584, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_waterfall_sound_loop
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, -200, -7000, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_cotmc_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x004B6070, /*romEnd*/ 0x004BC980
    cmd1A /*seg*/ 0x09, /*romStart*/ 0x00345FF0, /*romEnd*/ 0x0034CD00
    load_mio0 /*seg*/ 0x05, /*romStart*/ checkerboard_question, /*romEnd*/ checkerboard_question_end
    load_raw /*seg*/ 0x0C, /*romStart*/ cap_switch, /*romEnd*/ cap_switch_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ mri_swoop, /*romEnd*/ mri_swoop_end
    load_raw /*seg*/ 0x0D, /*romStart*/ mri_swoop_snufit_dorrie_scuttlebug, /*romEnd*/ mri_swoop_snufit_dorrie_scuttlebug_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_9
    jump_link /*target*/ script_func_global_18
    jump_link /*target*/ script_func_global_1

    area /*index*/ 1, /*geo*/ 0x0E0001A0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4185, 1020, -47, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x14, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_1
        terrain /*terrainData*/ 0x0700A508
        cmd39 /*unk4*/ 0x0700BD38
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x82
        set_menu_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -4185, 20, -47
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_cotmc.geo.s"
.align 4
