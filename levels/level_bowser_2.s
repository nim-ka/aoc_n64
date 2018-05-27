.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bifs_platform_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 0, 0, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_bowser_lava_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 4, 1329, 3598, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 3584, 1329, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 0, 1329, -3583, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ -3583, 1329, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    return

glabel level_bowser_2_entry
    init_level
    load_mio0 /*seg*/ 0x0A, /*romStart*/ 0x002CE5E0, /*romEnd*/ 0x002D4A90
    cmd1A /*seg*/ 0x09, /*romStart*/ 0x0031C770, /*romEnd*/ 0x003253E0
    load_mio0 /*seg*/ 0x0B, /*romStart*/ 0x0036DAD0, /*romEnd*/ 0x003701E0
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x004CBB70, /*romEnd*/ 0x004CC990
    load_mio0 /*seg*/ 0x06, /*romStart*/ bowser, /*romEnd*/ bowser_end
    load_raw /*seg*/ 0x0D, /*romStart*/ bowser_flames_bomb, /*romEnd*/ bowser_flames_bomb_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_13
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000170

    area /*index*/ 1, /*geo*/ 0x0E000188
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 2229, 0, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_6C
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x21, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x36, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x13, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        terrain /*terrainData*/ 0x070019F0
        set_menu_music /*unk2*/ 0x0002, /*seq*/ 0x0007
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ 0, 1229, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_bowser_2.geo.s"
.align 4
