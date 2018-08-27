.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/castle_courtyard_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 200, -1652, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ambiant_sounds
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2700, 0, -1652, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_birds_sound_loop
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2700, 0, -1652, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_birds_sound_loop
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -3217, 100, -101, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ 3317, 100, -1701, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -71, 1, -1387, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_group
    return

glabel level_castle_courtyard_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_castle_courtyard_segment_7SegmentRomStart, /*romEnd*/ _level_castle_courtyard_segment_7SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _water_skybox_mio0SegmentRomStart, /*romEnd*/ _water_skybox_mio0SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _castle_grounds_textures_mio0SegmentRomStart, /*romEnd*/ _castle_grounds_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _boo_bookend_chair_piano_mio0SegmentRomStart, /*romEnd*/ _boo_bookend_chair_piano_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _boo_bookend_chair_piano_geoSegmentRomStart,  /*romEnd*/ _boo_bookend_chair_piano_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_10
    cmd22 /*unk2*/ 0x0018, /*unk4*/ spiky_tree_geo
    cmd22 /*unk2*/ 0x0027, /*unk4*/ wooden_door_geo
    cmd22 /*unk2*/ 0x0003, /*unk4*/ castle_courtyard_geo_000200

    area /*index*/ 1, /*geo*/ castle_courtyard_geo_000218
        object /*unk2*/ 0x1F, /*unk3*/ 0x54, /*pos*/ -2360, -100, -2712, /*angle*/ 0, 0, 0, /*behArg*/ 0x01050000, /*beh*/ beh_boo_with_cage
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 51, -1000, /*angle*/ 0, 180, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_8C
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 51, -1000, /*angle*/ 0, 180, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_warps_90
        warp_node /*id*/ 0x05, /*destLevel1*/ 0x04, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x1A, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x01, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x02, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        terrain /*terrainData*/ castle_courtyard_seg7_collision
        cmd39 /*unk4*/ castle_courtyard_seg7_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0000
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 0, /*pos*/ -14, 0, -201
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_castle_courtyard.s"
.align 4
