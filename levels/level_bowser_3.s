.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bits_platform_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00040000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00050000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00060000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3C, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00070000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00080000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00090000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_falling_bowser_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ -2122, 512, -2912, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ -3362, 512, 1121, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 0, 512, 3584, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 3363, 512, 1121, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    object /*unk2*/ 0x1F, /*unk3*/ 0xB3, /*pos*/ 2123, 512, -2912, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_bomb
    return

glabel level_bowser_3_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bowser_3_segment_7SegmentRomStart, /*romEnd*/ _level_bowser_3_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ bowser, /*romEnd*/ bowser_end
    load_raw /*seg*/ 0x0D, /*romStart*/ bowser_flames_bomb, /*romEnd*/ bowser_flames_bomb_end
    load_mio0 /*seg*/ 0x0A, /*romStart*/ bits_skybox, /*romEnd*/ bits_skybox_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_13
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000290
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E0002A8
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E0002C0
    cmd22 /*unk2*/ 0x0039, /*unk4*/ 0x0E0002D8
    cmd22 /*unk2*/ 0x003A, /*unk4*/ 0x0E0002F0
    cmd22 /*unk2*/ 0x003B, /*unk4*/ 0x0E000308
    cmd22 /*unk2*/ 0x003C, /*unk4*/ 0x0E000320
    cmd22 /*unk2*/ 0x003D, /*unk4*/ 0x0E000338
    cmd22 /*unk2*/ 0x003E, /*unk4*/ 0x0E000350
    cmd22 /*unk2*/ 0x003F, /*unk4*/ 0x0E000368
    cmd22 /*unk2*/ 0x0003, /*unk4*/ 0x0E000380

    area /*index*/ 1, /*geo*/ 0x0E000398
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 1307, 0, /*angle*/ 0, 183, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_6C
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x22, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x15, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        terrain /*terrainData*/ 0x070049C8
        set_music /*unk2*/ 0x0002, /*seq*/ 0x0019
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 183, /*pos*/ 0, 307, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "geo/level_bowser_3.geo.s"
.align 4
