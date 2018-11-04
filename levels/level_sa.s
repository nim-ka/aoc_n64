.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/sa_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, -1000, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_large_fish_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, -1000, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_large_fish_group
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, -4250, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hidden_red_coin_star
    return

glabel level_sa_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_sa_segment_7SegmentRomStart, /*romEnd*/ _level_sa_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _inside_castle_textures_mio0SegmentRomStart, /*romEnd*/ _inside_castle_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _cloud_floor_skybox_mio0SegmentRomStart, /*romEnd*/ _cloud_floor_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_textures_mio0SegmentRomStart, /*romEnd*/ _flower_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _sea_creatures_mio0SegmentRomStart, /*romEnd*/ _sea_creatures_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _sea_creatures_geoSegmentRomStart,  /*romEnd*/ _sea_creatures_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _skeeter_fish_treasurechest_mio0SegmentRomStart, /*romEnd*/ _skeeter_fish_treasurechest_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _skeeter_fish_treasurechest_geoSegmentRomStart,  /*romEnd*/ _skeeter_fish_treasurechest_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_5
    jump_link /*target*/ script_func_global_14

    area /*index*/ 1, /*geo*/ sa_geo_000170
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, -1535, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_94
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x14, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x27, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x28, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        terrain /*terrainData*/ sa_seg7_collision
        cmd39 /*unk4*/ sa_seg7_macro_objs
        set_music /*unk2*/ 0x0003, /*seq*/ 0x0085
        terrain_type /*terrainType*/ 0x0005
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ 0, -1535, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_sa.s"
.align 4
