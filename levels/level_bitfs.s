.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/bifs_segment7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ -5733, -3071, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x07330000, /*beh*/ beh_platform_on_tracks
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -1945, -3225, -715, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_inverted_pyramid
    object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -2866, -3225, -715, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tilting_inverted_pyramid
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -1381, 3487, 96, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bifs_sinking_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ 1126, -3065, 307, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bifs_sinking_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -3225, 3487, 96, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bifs_sinking_platforms
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 6605, -3071, 266, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bifs_sinking_cage_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 1843, 3584, 96, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_bifs_sinking_cage_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 614, 3584, 96, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_bifs_sinking_cage_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3A, /*pos*/ 3072, 3584, 96, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_bifs_sinking_cage_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3B, /*pos*/ 2867, -1279, 307, /*angle*/ 0, 0, 0, /*behArg*/ 0x029F0000, /*beh*/ beh_climbable_cage
    object /*unk2*/ 0x1F, /*unk3*/ 0x3C, /*pos*/ -5836, 410, 300, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_squishable_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 4454, -2226, 266, /*angle*/ 0, 0, 0, /*behArg*/ 0x00040000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x3D, /*pos*/ 5786, -2380, 266, /*angle*/ 0, 0, 0, /*behArg*/ 0x00040000, /*beh*/ beh_solid_moving
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ -3890, 102, 617, /*angle*/ 0, 90, 0, /*behArg*/ 0x010C0000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x3E, /*pos*/ -3276, 102, 2, /*angle*/ 0, 270, 0, /*behArg*/ 0x010C0000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x3F, /*pos*/ 2103, 198, 312, /*angle*/ 0, 0, 0, /*behArg*/ 0x019F0000, /*beh*/ beh_sliding_platform2
    object /*unk2*/ 0x1F, /*unk3*/ 0x41, /*pos*/ 4979, 4250, 96, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_wf_tumbling_bridge
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3890, -2043, 266, /*angle*/ 0, 0, 0, /*behArg*/ 0x00520000, /*beh*/ beh_pole_grabbing
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3226, 3584, -822, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1382, 3584, -822, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1229, 307, -412, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_flamethrower
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1200, 5700, 160, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_bowser_course_red_coin_star
    return

glabel level_bitfs_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_bitfs_segment_7SegmentRomStart, /*romEnd*/ _level_bitfs_segment_7SegmentRomEnd
    cmd1A /*seg*/ 0x09, /*romStart*/ _rr_textures_mio0SegmentRomStart, /*romEnd*/ _rr_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0A, /*romStart*/ _bifs_skybox_mio0SegmentRomStart, /*romEnd*/ _bifs_skybox_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x0B, /*romStart*/ _flower_textures_mio0SegmentRomStart, /*romEnd*/ _flower_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _bully_blargg_mio0SegmentRomStart, /*romEnd*/ _bully_blargg_mio0SegmentRomEnd
    load_raw /*seg*/ 0x0C, /*romStart*/ _bully_blargg_geoSegmentRomStart, /*romEnd*/ _bully_blargg_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _mri_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomStart, /*romEnd*/ _mri_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomEnd
    load_raw /*seg*/ 0x0D, /*romStart*/ _mri_swoop_snufit_dorrie_scuttlebug_geoSegmentRomStart, /*romEnd*/ _mri_swoop_snufit_dorrie_scuttlebug_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_3
    jump_link /*target*/ script_func_global_18
    jump_link /*target*/ script_func_global_1
    cmd22 /*unk2*/ 0x0003, /*unk4*/ bitfs_geo_0004B0
    cmd22 /*unk2*/ 0x0004, /*unk4*/ bitfs_geo_0004C8
    cmd22 /*unk2*/ 0x0005, /*unk4*/ bitfs_geo_0004E0
    cmd22 /*unk2*/ 0x0006, /*unk4*/ bitfs_geo_0004F8
    cmd22 /*unk2*/ 0x0007, /*unk4*/ bitfs_geo_000510
    cmd22 /*unk2*/ 0x0008, /*unk4*/ bitfs_geo_000528
    cmd22 /*unk2*/ 0x0009, /*unk4*/ bitfs_geo_000540
    cmd22 /*unk2*/ 0x000A, /*unk4*/ bitfs_geo_000558
    cmd22 /*unk2*/ 0x000B, /*unk4*/ bitfs_geo_000570
    cmd22 /*unk2*/ 0x000C, /*unk4*/ bitfs_geo_000588
    cmd22 /*unk2*/ 0x000D, /*unk4*/ bitfs_geo_0005A0
    cmd22 /*unk2*/ 0x000E, /*unk4*/ bitfs_geo_0005B8
    cmd22 /*unk2*/ 0x000F, /*unk4*/ bitfs_geo_0005D0
    cmd22 /*unk2*/ 0x0010, /*unk4*/ bitfs_geo_0005E8
    cmd22 /*unk2*/ 0x0011, /*unk4*/ bitfs_geo_000600
    cmd22 /*unk2*/ 0x0012, /*unk4*/ bitfs_geo_000618
    cmd22 /*unk2*/ 0x0013, /*unk4*/ bitfs_geo_000630
    cmd22 /*unk2*/ 0x0014, /*unk4*/ bitfs_geo_000648
    cmd22 /*unk2*/ 0x0015, /*unk4*/ bitfs_geo_000660
    cmd22 /*unk2*/ 0x0036, /*unk4*/ bitfs_geo_000758
    cmd22 /*unk2*/ 0x0037, /*unk4*/ bitfs_geo_0006C0
    cmd22 /*unk2*/ 0x0038, /*unk4*/ bitfs_geo_000770
    cmd22 /*unk2*/ 0x0039, /*unk4*/ bitfs_geo_0006A8
    cmd22 /*unk2*/ 0x003A, /*unk4*/ bitfs_geo_000690
    cmd22 /*unk2*/ 0x003B, /*unk4*/ bitfs_geo_000678
    cmd22 /*unk2*/ 0x003C, /*unk4*/ bitfs_geo_000708
    cmd22 /*unk2*/ 0x003D, /*unk4*/ bitfs_geo_000788
    cmd22 /*unk2*/ 0x003E, /*unk4*/ bitfs_geo_000728
    cmd22 /*unk2*/ 0x003F, /*unk4*/ bitfs_geo_000740
    cmd22 /*unk2*/ 0x0040, /*unk4*/ bitfs_geo_0006D8
    cmd22 /*unk2*/ 0x0041, /*unk4*/ bitfs_geo_0006F0

    area /*index*/ 1, /*geo*/ bitfs_geo_0007A0
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7577, -1764, 0, /*angle*/ 0, 90, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_64
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 6735, 3681, 99, /*angle*/ 0, 0, 0, /*behArg*/ 0x140B0000, /*beh*/ beh_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 5886, 5000, 99, /*angle*/ 0, 90, 0, /*behArg*/ 0x000C0000, /*beh*/ beh_warps_70
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x13, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x21, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0C, /*destLevel1*/ 0x13, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x68, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        terrain /*terrainData*/ bitfs_seg7_collision
        cmd39 /*unk4*/ bitfs_seg7_macro_objs
        set_music /*unk2*/ 0x0000, /*seq*/ 0x0011
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 90, /*pos*/ -7577, -2764, 0
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_bitfs.s"
.align 4
