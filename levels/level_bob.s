.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bob_segment7.mio0"
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
    object /*unk2*/ 0x03, /*unk3*/ 0x00, /*pos*/ 1535, 3840, -5561, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_metal_ball_generator
    object /*unk2*/ 0x3C, /*unk3*/ 0x00, /*pos*/ 1535, 3840, -5561, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_metal_ball_generator_2
    object /*unk2*/ 0x03, /*unk3*/ 0x00, /*pos*/ 524, 2825, -5400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_metal_ball_generator
    object /*unk2*/ 0x3C, /*unk3*/ 0x00, /*pos*/ 524, 2825, -5400, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_metal_ball_generator_2
    object /*unk2*/ 0x1F, /*unk3*/ 0xB4, /*pos*/ -993, 886, -3565, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rolling_ball
    object /*unk2*/ 0x1F, /*unk3*/ 0xB4, /*pos*/ -785, 886, -4301, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rolling_ball
    object /*unk2*/ 0x3E, /*unk3*/ 0xB4, /*pos*/ -93, 886, -3414, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rolling_ball
    object /*unk2*/ 0x01, /*unk3*/ 0xC3, /*pos*/ -5723, 140, 6017, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_pink_bobomb_with_message
    object /*unk2*/ 0x01, /*unk3*/ 0xC3, /*pos*/ -6250, 0, 6680, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_pink_bobomb_with_message
    object /*unk2*/ 0x3E, /*unk3*/ 0xC3, /*pos*/ -5723, 140, 6017, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pink_bobomb_opening_cannon
    object /*unk2*/ 0x3E, /*unk3*/ 0xC3, /*pos*/ -6250, 0, 6680, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_pink_bobomb_with_message
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
    cmd1A /*seg*/ 0x09, /*romStart*/ bob_textures, /*romEnd*/ bob_textures_end
    load_mio0 /*seg*/ 0x0A, /*romStart*/ water_skybox, /*romEnd*/ water_skybox_end
    load_mio0 /*seg*/ 0x05, /*romStart*/ bobombs, /*romEnd*/ bobombs_end
    load_raw /*seg*/ 0x0C, /*romStart*/ kingbobomb_bubble, /*romEnd*/ kingbobomb_bubble_end
    load_mio0 /*seg*/ 0x06, /*romStart*/ koopa_whomp, /*romEnd*/ koopa_whomp_end
    load_raw /*seg*/ 0x0D, /*romStart*/ koopa_log_piranha_whomp_chomp, /*romEnd*/ koopa_log_piranha_whomp_chomp_end
    load_mio0 /*seg*/ 0x08, /*romStart*/ chuckya_shyguy_goomba, /*romEnd*/ chuckya_shyguy_goomba_end
    load_raw /*seg*/ 0x0F, /*romStart*/ cannon_box_switch_enemies, /*romEnd*/ cannon_box_switch_enemies_end
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_4
    jump_link /*target*/ script_func_global_15
    cmd22 /*unk2*/ 0x0017, /*unk4*/ 0x16000FE8
    cmd22 /*unk2*/ 0x0036, /*unk4*/ 0x0E000440
    cmd22 /*unk2*/ 0x0037, /*unk4*/ 0x0E000458
    cmd22 /*unk2*/ 0x0038, /*unk4*/ 0x0E000470

    area /*index*/ 1, /*geo*/ 0x0E000488
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
        terrain /*terrainData*/ 0x0700E958
        cmd39 /*unk4*/ 0x0701104C
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
.include "geo/level_bob.geo.s"
.align 4
