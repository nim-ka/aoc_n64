.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/main_menu_seg7.mio0"
.align 4

.section .level, "a"

glabel level_main_menu_entry_1
    init_level
    fixed_load /*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_main_menu_segment_7SegmentRomStart, /*romEnd*/ _level_main_menu_segment_7SegmentRomEnd
    load_raw /*seg*/ 0x13, /*romStart*/ _behaviorSegmentRomStart, /*romEnd*/ _behaviorSegmentRomEnd
    alloc_level_pool
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_03, /*geo*/ main_menu_geo_0001D0
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_04, /*geo*/ main_menu_geo_000290
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_05, /*geo*/ main_menu_geo_0002B8
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_06, /*geo*/ main_menu_geo_0002E0
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_07, /*geo*/ main_menu_geo_000308
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_08, /*geo*/ main_menu_geo_000200
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_09, /*geo*/ main_menu_geo_000230
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_0A, /*geo*/ main_menu_geo_000260
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_0B, /*geo*/ main_menu_geo_000330
    load_model_from_geo /*model*/ MODEL_MAIN_MENU_0C, /*geo*/ main_menu_geo_000358

    area /*index*/ 1, /*geo*/ main_menu_geo_000380
        object /*model*/ MODEL_NONE,         /*pos*/ 0, 0, -19000, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ beh_menu_button_manager
        object /*model*/ MODEL_MAIN_MENU_06, /*pos*/ 0, 0, -19000, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ beh_yellow_background_in_menu
        terrain /*terrainData*/ main_menu_seg7_collision
    end_area

    free_level_pool
    load_area /*area*/ 1
    set_menu_music /*seq*/ 0x0021
    transition /*unk2*/ 0, /*unk3*/ 16, /*color*/ -1, -1, -1
    call /*arg*/ 0, /*func*/ LevelProc_801766DC
    call_loop /*arg*/ 0, /*func*/ LevelProc_801768A0
    get_or_set /*op*/ OP_SET, /*var*/ VAR_CURR_SAVE_FILE_NUM
    cmd38 /*unk2*/ 0x00BE
    transition /*unk2*/ 1, /*unk3*/ 16, /*color*/ -1, -1, -1
    sleep /*frames*/ 16
    clear_level
    sleep_before_exit /*frames*/ 1
    set_reg /*value*/ 16
    exit_and_execute /*seg*/ 0x15, /*script*/ _level_main_scriptsSegmentRomStart, /*scriptEnd*/ _level_main_scriptsSegmentRomEnd, /*entry*/ level_main_scripts_entry

glabel level_main_menu_entry_2
    call /*arg*/ 0, /*func*/ lvl_set_current_level
    jump_if /*op*/ OP_EQ, /*arg*/ 0, /*target*/ L1
    init_level
    fixed_load /*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_main_menu_segment_7SegmentRomStart, /*romEnd*/ _level_main_menu_segment_7SegmentRomEnd
    alloc_level_pool

    area /*index*/ 2, /*geo*/ main_menu_geo_000408
        object /*model*/ MODEL_NONE, /*pos*/ 0, -100, 0, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ beh_act_selector
        terrain /*terrainData*/ main_menu_seg7_collision
    end_area

    free_level_pool
    load_area /*area*/ 2
    transition /*unk2*/ 0, /*unk3*/ 16, /*color*/ -1, -1, -1
    sleep /*frames*/ 16
    set_menu_music /*seq*/ 0x000D
    call /*arg*/ 0, /*func*/ LevelProc_80177560
    call_loop /*arg*/ 0, /*func*/ LevelProc_80177610
    get_or_set /*op*/ OP_SET, /*var*/ VAR_D_8033A758
    cmd38 /*unk2*/ 0x00BE
    transition /*unk2*/ 1, /*unk3*/ 16, /*color*/ -1, -1, -1
    sleep /*frames*/ 16
    clear_level
    sleep_before_exit /*frames*/ 1
L1:
    exit

.align 4
.include "levels/geo/level_main_menu.s"
.align 4
