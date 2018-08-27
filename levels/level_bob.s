.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bob_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 1456, 768, 446, /*angle*/ 0, 326, 0, /*behArg*/ 0x00000000, /*beh*/ beh_chain_chomp_freed_explosion
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -2303, 717, 1024, /*angle*/ 0, 45, 0, /*behArg*/ 0x00030000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2050, 0, -3069, /*angle*/ 0, 25, 0, /*behArg*/ 0x00000000, /*beh*/ beh_openable_grill
    object /*unk2*/ 0x1F, /*unk3*/ 0xCF, /*pos*/ -2283, 0, -3682, /*angle*/ 0, 27, 0, /*behArg*/ 0x00000000, /*beh*/ beh_floor_switch_grills
    object /*unk2*/ 0x1F, /*unk3*/ 0xCA, /*pos*/ 1612, 300, 4611, /*angle*/ 0, 0, 0, /*behArg*/ 0x00280000, /*beh*/ beh_checkerboard_elevator_group
    return

script_func_local_2:
    object /*unk2*/ 0x03, /*unk3*/ 0x00, /*pos*/ 1535, 3840, -5561, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bob_bowling_ball_spawner
    object /*unk2*/ 0x3C, /*unk3*/ 0x00, /*pos*/ 1535, 3840, -5561, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ttm_bowling_ball_spawner
    object /*unk2*/ 0x03, /*unk3*/ 0x00, /*pos*/ 524, 2825, -5400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_bob_bowling_ball_spawner
    object /*unk2*/ 0x3C, /*unk3*/ 0x00, /*pos*/ 524, 2825, -5400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_ttm_bowling_ball_spawner
    object /*unk2*/ 0x1F, /*unk3*/ 0xB4, /*pos*/ -993, 886, -3565, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bob_pit_bowling_ball
    object /*unk2*/ 0x1F, /*unk3*/ 0xB4, /*pos*/ -785, 886, -4301, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bob_pit_bowling_ball
    object /*unk2*/ 0x3E, /*unk3*/ 0xB4, /*pos*/ -93, 886, -3414, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bob_pit_bowling_ball
    object /*unk2*/ 0x01, /*unk3*/ 0xC3, /*pos*/ -5723, 140, 6017, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_bobomb_buddy_advice_role
    object /*unk2*/ 0x01, /*unk3*/ 0xC3, /*pos*/ -6250, 0, 6680, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_bobomb_buddy_advice_role
    object /*unk2*/ 0x3E, /*unk3*/ 0xC3, /*pos*/ -5723, 140, 6017, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bobomb_buddy_cannon_role
    object /*unk2*/ 0x3E, /*unk3*/ 0xC3, /*pos*/ -6250, 0, 6680, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_bobomb_buddy_advice_role
    object /*unk2*/ 0x01, /*unk3*/ 0x80, /*pos*/ -5694, 128, 5600, /*angle*/ 0, 135, 0, /*behArg*/ 0x00010000, /*beh*/ beh_cannon
    object /*unk2*/ 0x3E, /*unk3*/ 0xC9, /*pos*/ -5694, 128, 5600, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_cannon_trap_door
    object /*unk2*/ 0x02, /*unk3*/ 0x00, /*pos*/ 3304, 4242, -4603, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_waving_koopa_flag
    object /*unk2*/ 0x3C, /*unk3*/ 0x68, /*pos*/ 3400, 770, 6500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_koopa
    return

script_func_local_3:
    object /*unk2*/ 0x01, /*unk3*/ 0x56, /*pos*/ 1636, 4242, -5567, /*angle*/ 0, -147, 0, /*behArg*/ 0x00000000, /*beh*/ beh_king_bobomb
    object /*unk2*/ 0x02, /*unk3*/ 0x68, /*pos*/ -4004, 0, 5221, /*angle*/ 0, 0, 0, /*behArg*/ 0x01020000, /*beh*/ beh_koopa
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -6000, 1000, 2400, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -6600, 1000, 1250, /*angle*/ 0, 0, 0, /*behArg*/ 0x04040000, /*beh*/ beh_hidden_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 1550, 1200, 300, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_bob_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bob_segment_7SegmentRomStart, /*romEnd*/ _level_bob_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _bob_textures_mio0SegmentRomStart, /*romEnd*/ _bob_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _water_skybox_mio0SegmentRomStart, /*romEnd*/ _water_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _bobombs_bubble_mio0SegmentRomStart, /*romEnd*/ _bobombs_bubble_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _bobombs_bubble_geoSegmentRomStart,  /*romEnd*/ _bobombs_bubble_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _koopa_log_piranha_whomp_chomp_mio0SegmentRomStart, /*romEnd*/ _koopa_log_piranha_whomp_chomp_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _koopa_log_piranha_whomp_chomp_geoSegmentRomStart,  /*romEnd*/ _koopa_log_piranha_whomp_chomp_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_4
    jump_link /*target*/ script_func_global_15
    cmd22 /*unk2*/ 0x0017, /*unk4*/ bubbly_tree_geo
    cmd22 /*unk2*/ 0x0036, /*unk4*/ bob_geo_000440
    cmd22 /*unk2*/ 0x0037, /*unk4*/ bob_geo_000458
    cmd22 /*unk2*/ 0x0038, /*unk4*/ bob_geo_000470

    area /*index*/ 1, /*geo*/ bob_geo_000488
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6558, 1000, 6464, /*angle*/ 0, 135, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 583, 2683, -5387, /*angle*/ 0, -154, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1680, 3835, -5523, /*angle*/ 0, -153, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6612, 1024, -3351, /*angle*/ 0, 107, 0, /*behArg*/ 0x000D0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1980, 768, 6618, /*angle*/ 0, -151, 0, /*behArg*/ 0x000E0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0D, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0E, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0E, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0D, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x32, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x64, /*destLevel2*/ 0x00
        terrain /*terrainData*/ bob_seg7_collision_level
        cmd39 /*unk4*/ bob_seg7_macro_objs
        cmd30 /*unk2*/ 0x00, /*unk3*/ 0x00
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0003
        terrain_type /*terrainType*/ 0x0000
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 135, /*pos*/ -6558, 0, 6464
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_bob.s"
.align 4
