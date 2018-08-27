.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/rr_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -3400, -2038, 6564, /*angle*/ 0, 0, 0, /*behArg*/ 0x02560000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -2684, -1423, -36, /*angle*/ 0, 0, 0, /*behArg*/ 0x02590000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 4571, -1782, 2036, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 580, -963, -3659, /*angle*/ 0, 180, 0, /*behArg*/ 0x00010000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 1567, 880, -184, /*angle*/ 0, 180, 0, /*behArg*/ 0x00070000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ 646, 880, -184, /*angle*/ 0, 0, 0, /*behArg*/ 0x00080000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 644, -1321, -1301, /*angle*/ 0, 180, 0, /*behArg*/ 0x03010000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1797, -1321, -56, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 663, -1321, 1179, /*angle*/ 0, 180, 0, /*behArg*/ 0x03010000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -502, -1321, -51, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_octagonal_platform_rotating
    object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ 5043, 1342, 300, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_rr_rotating_platform_with_fire
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 3473, 2422, -1821, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rr_cruiser_wing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 4084, 2431, -2883, /*angle*/ 45, 180, 180, /*behArg*/ 0x00010000, /*beh*/ beh_rr_cruiser_wing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 3470, 2420, -2869, /*angle*/ 45, 180, 180, /*behArg*/ 0x00010000, /*beh*/ beh_rr_cruiser_wing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 2856, 2410, -2855, /*angle*/ 45, 180, 180, /*behArg*/ 0x00010000, /*beh*/ beh_rr_cruiser_wing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 4101, 2435, -1813, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rr_cruiser_wing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 2859, 2411, -1834, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rr_cruiser_wing
    object /*unk2*/ 0x1F, /*unk3*/ 0x3C, /*pos*/ -6013, -2857, 6564, /*angle*/ 0, 270, 0, /*behArg*/ 0x00050000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x3C, /*pos*/ 614, -3574, 6564, /*angle*/ 0, 270, 0, /*behArg*/ 0x00050000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ -3557, -809, 4619, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pendulum_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ -2213, -2582, 6257, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_pendulum_movement
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_donut_platform_group
    object /*unk2*/ 0x1F, /*unk3*/ 0x40, /*pos*/ -2684, 1546, -36, /*angle*/ 0, 0, 0, /*behArg*/ 0x00050000, /*beh*/ beh_rr_elevator_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 5862, -1347, 6564, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_floor_switch_press_animation
    object /*unk2*/ 0x1F, /*unk3*/ 0xCF, /*pos*/ 4428, -1936, 6564, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_purple_switch_staircase
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 614, -2857, 3671, /*angle*/ 0, 0, 0, /*behArg*/ 0x00CC0000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 621, -4598, 7362, /*angle*/ 0, 0, 0, /*behArg*/ 0x00750000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5119, 3819, 3325, /*angle*/ 0, 0, 0, /*behArg*/ 0x00610000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3554, 2891, -2327, /*angle*/ 0, 0, 0, /*behArg*/ 0x00C10000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2680, 214, 295, /*angle*/ 0, 0, 0, /*behArg*/ 0x00620000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3811, 1033, 295, /*angle*/ 0, 0, 0, /*behArg*/ 0x00620000, /*beh*/ beh_pole_grabbing
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5809, -1834, 5719, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4838, -1015, 4081, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3301, -1834, 5617, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 6772, -757, -606, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4187, 3213, -6630, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    return

script_func_local_3:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 1450, 3400, -2352, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -4200, 6700, -4450, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ -5150, -1400, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -5850, -700, 4950, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 3700, -400, 6600, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    return

glabel level_rr_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_rr_segment_7SegmentRomStart, /*romEnd*/ _level_rr_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _rr_textures_mio0SegmentRomStart, /*romEnd*/ _rr_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _cloud_floor_skybox_mio0SegmentRomStart, /*romEnd*/ _cloud_floor_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _bubba_wiggler_lakitu_mio0SegmentRomStart, /*romEnd*/ _bubba_wiggler_lakitu_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _bubba_wiggler_lakitu_geoSegmentRomStart,  /*romEnd*/ _bubba_wiggler_lakitu_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_12
    jump_link /*target*/ script_func_global_1
    cmd22 /*unk2*/ 0x0003, /*unk4*/ rr_geo_000660
    cmd22 /*unk2*/ 0x0004, /*unk4*/ rr_geo_000678
    cmd22 /*unk2*/ 0x0005, /*unk4*/ rr_geo_000690
    cmd22 /*unk2*/ 0x0006, /*unk4*/ rr_geo_0006A8
    cmd22 /*unk2*/ 0x0007, /*unk4*/ rr_geo_0006C0
    cmd22 /*unk2*/ 0x0008, /*unk4*/ rr_geo_0006D8
    cmd22 /*unk2*/ 0x0009, /*unk4*/ rr_geo_0006F0
    cmd22 /*unk2*/ 0x000A, /*unk4*/ rr_geo_000708
    cmd22 /*unk2*/ 0x000B, /*unk4*/ rr_geo_000720
    cmd22 /*unk2*/ 0x000C, /*unk4*/ rr_geo_000738
    cmd22 /*unk2*/ 0x000D, /*unk4*/ rr_geo_000758
    cmd22 /*unk2*/ 0x000E, /*unk4*/ rr_geo_000770
    cmd22 /*unk2*/ 0x000F, /*unk4*/ rr_geo_000788
    cmd22 /*unk2*/ 0x0010, /*unk4*/ rr_geo_0007A0
    cmd22 /*unk2*/ 0x0011, /*unk4*/ rr_geo_0007B8
    cmd22 /*unk2*/ 0x0012, /*unk4*/ rr_geo_0007D0
    cmd22 /*unk2*/ 0x0013, /*unk4*/ rr_geo_0007E8
    cmd22 /*unk2*/ 0x0014, /*unk4*/ rr_geo_000800
    cmd22 /*unk2*/ 0x0015, /*unk4*/ rr_geo_000818
    cmd22 /*unk2*/ 0x0016, /*unk4*/ rr_geo_000830
    cmd22 /*unk2*/ 0x0036, /*unk4*/ rr_geo_0008C0
    cmd22 /*unk2*/ 0x0037, /*unk4*/ rr_geo_000848
    cmd22 /*unk2*/ 0x0038, /*unk4*/ rr_geo_0008A8
    cmd22 /*unk2*/ 0x0039, /*unk4*/ rr_geo_000878
    cmd22 /*unk2*/ 0x003A, /*unk4*/ rr_geo_0008D8
    cmd22 /*unk2*/ 0x003B, /*unk4*/ rr_geo_000890
    cmd22 /*unk2*/ 0x003C, /*unk4*/ rr_geo_000908
    cmd22 /*unk2*/ 0x003D, /*unk4*/ rr_geo_000940
    cmd22 /*unk2*/ 0x003E, /*unk4*/ rr_geo_000860
    cmd22 /*unk2*/ 0x003F, /*unk4*/ rr_geo_000920
    cmd22 /*unk2*/ 0x0040, /*unk4*/ rr_geo_0008F0
    cmd22 /*unk2*/ 0x0041, /*unk4*/ rr_geo_000958
    cmd22 /*unk2*/ 0x0042, /*unk4*/ rr_geo_000970
    cmd22 /*unk2*/ 0x0043, /*unk4*/ rr_geo_000988
    cmd22 /*unk2*/ 0x0044, /*unk4*/ rr_geo_0009A0
    cmd22 /*unk2*/ 0x0045, /*unk4*/ rr_geo_0009B8

    area /*index*/ 1, /*geo*/ rr_geo_0009D0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2599, -833, 2071, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7092, 2364, -63, /*angle*/ 0, 90, 0, /*behArg*/ 0x000B0000, /*beh*/ beh_fading_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4213, 3379, -2815, /*angle*/ 0, 180, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_fading_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0F, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x0F, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x0F, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x3A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x6C, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ rr_seg7_collision
        cmd39 /*unk4*/ rr_seg7_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0009
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ 2599, -1833, 2071
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_rr.s"
.align 4
