.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/ddd_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -3071, -270, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sushi_shark
    object /*unk2*/ 0x1F, /*unk3*/ 0x56, /*pos*/ -3071, -4270, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_sushi_shark
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3071, -130, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_fish_3
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3071, -4270, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_fish_2
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3071, -2000, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_chirp_chirp
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3071, -3000, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_chirp_chirp
    object /*unk2*/ 0x1F, /*unk3*/ 0x57, /*pos*/ -3174, -4915, 102, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_whirlpool
    return

script_func_local_2:
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -2400, -4607, 125, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_treasure_chests
    object /*unk2*/ 0x3E, /*unk3*/ 0x54, /*pos*/ -4640, -1380, 40, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_manta_ray
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_sub_door
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowsers_sub
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 5120, 1005, 3584, /*angle*/ 0, 180, 0, /*behArg*/ 0x001E0000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 5605, 1005, 3380, /*angle*/ 0, 270, 0, /*behArg*/ 0x00150000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1800, 1005, 1275, /*angle*/ 0, 0, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 4000, 1005, 1075, /*angle*/ 0, 180, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1830, 1005, 520, /*angle*/ 0, 270, 0, /*behArg*/ 0x00140000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 4000, 1005, 1275, /*angle*/ 0, 0, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 5760, 1005, 360, /*angle*/ 0, 270, 0, /*behArg*/ 0x00170000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 3310, 1005, -1945, /*angle*/ 0, 0, 0, /*behArg*/ 0x00170000, /*beh*/ beh_ddd_yellow_poles
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 3550, 1005, -2250, /*angle*/ 0, 0, 0, /*behArg*/ 0x000D0000, /*beh*/ beh_ddd_yellow_poles
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3404, -3319, -489, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_jet_stream
    return

script_func_local_5:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 3900, 850, -600, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 5513, 1200, 900, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 3404, -3319, -489, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_manta_rings_generator
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 2030, -3700, -2780, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_ddd_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_ddd_segment_7SegmentRomStart, /*romEnd*/ _level_ddd_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _jrb_textures_mio0SegmentRomStart, /*romEnd*/ _jrb_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_textures_mio0SegmentRomStart, /*romEnd*/ _flower_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _water_skybox_mio0SegmentRomStart, /*romEnd*/ _water_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _sea_creatures_mio0SegmentRomStart, /*romEnd*/ _sea_creatures_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _sea_creatures_geoSegmentRomStart,  /*romEnd*/ _sea_creatures_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _skeeter_fish_treasurechest_mio0SegmentRomStart, /*romEnd*/ _skeeter_fish_treasurechest_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _skeeter_fish_treasurechest_geoSegmentRomStart,  /*romEnd*/ _skeeter_fish_treasurechest_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_5
    jump_link /*target*/ script_func_global_14
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000478
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E0004A0
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000450

    area /*index*/ 1, /*geo*/ 0x0E0004C0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3071, 3000, 0, /*angle*/ 0, 7, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x17, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x35, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x67, /*destLevel2*/ 0x00
        whirlpool /*unk2*/ 0, /*unk3*/ 0, /*pos*/ -3174, -4915, 102, /*strength*/ 20
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        instant_warp /*index*/ 3, /*destArea*/ 2, /*displace*/ -8192, 0, 0
        terrain /*terrainData*/ 0x0700D310
        cmd39 /*unk4*/ 0x0700EEF4
        set_music /*unk2*/ 0x0003, /*seq*/ 0x0005
        terrain_type /*terrainType*/ 0x0005
    end_area

    area /*index*/ 2, /*geo*/ 0x0E000570
        whirlpool /*unk2*/ 0, /*unk3*/ 0, /*pos*/ 3355, -3575, -515, /*strength*/ -30
        whirlpool /*unk2*/ 1, /*unk3*/ 2, /*pos*/ 3917, -2040, -6041, /*strength*/ 50
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x35, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x67, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF3, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x1E, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        jump_link /*target*/ script_func_local_5
        instant_warp /*index*/ 2, /*destArea*/ 1, /*displace*/ 8192, 0, 0
        terrain /*terrainData*/ 0x0700DE70
        cmd39 /*unk4*/ 0x0700EFAC
        set_music /*unk2*/ 0x0003, /*seq*/ 0x0005
        terrain_type /*terrainType*/ 0x0005
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ -3071, 3000, 500
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_ddd.s"
.align 4
