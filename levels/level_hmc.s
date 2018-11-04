.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/hmc_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 4936, -357, -4146, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 5018, -460, -5559, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1997, 666, -235, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1762, -460, -2610, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 4178, -255, -3737, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 2233, -460, 256, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 5510, -255, -3429, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 4690, -357, -767, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 3462, -255, -1125, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1762, 666, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1762, -460, 256, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 6482, 461, 3226, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 1075, 461, 6543, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 6912, 461, 6543, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 6912, 461, 3697, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 6482, 461, 7014, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ 3817, 717, 1034, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 799, 1024, 4434, /*angle*/ 0, 0, 0, /*behArg*/ 0x00B80000, /*beh*/ beh_pole_grabbing
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 889, 1024, 3277, /*angle*/ 0, 0, 0, /*behArg*/ 0x00B80000, /*beh*/ beh_pole_grabbing
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 1100, 950, 6350, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_controllable_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -3243, 1434, 1392, /*angle*/ 0, 27, 0, /*behArg*/ 0x00000000, /*beh*/ beh_hmc_elevator_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -2816, 2253, -2509, /*angle*/ 0, 0, 0, /*behArg*/ 0x00010000, /*beh*/ beh_hmc_elevator_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -973, 1741, -7347, /*angle*/ 0, 0, 0, /*behArg*/ 0x00020000, /*beh*/ beh_hmc_elevator_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -3533, 1741, -7040, /*angle*/ 0, 0, 0, /*behArg*/ 0x00030000, /*beh*/ beh_hmc_elevator_platform
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 614, -4690, 2330, /*angle*/ 0, 270, 0, /*behArg*/ 0x00010000, /*beh*/ beh_openable_grill
    object /*unk2*/ 0x1F, /*unk3*/ 0xCF, /*pos*/ -307, -4997, 2483, /*angle*/ 0, 270, 0, /*behArg*/ 0x00000000, /*beh*/ beh_floor_switch_grills
    object /*unk2*/ 0x1F, /*unk3*/ 0xCA, /*pos*/ 1270, 2000, 4000, /*angle*/ 0, 270, 0, /*behArg*/ 0x09A40000, /*beh*/ beh_platform_on_tracks
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x68, /*pos*/ -3533, -4969, 3558, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_dorrie
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -6093, 3075, -7807, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_big_boulder_generator
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -500, 1600, 3500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00040000, /*beh*/ beh_flamethrower
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -500, 1600, 3800, /*angle*/ 0, 0, 0, /*behArg*/ 0x00040000, /*beh*/ beh_flamethrower
    return

script_func_local_4:
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -3600, -4000, 3600, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x00, /*pos*/ 4000, 300, 5000, /*angle*/ 0, 0, 0, /*behArg*/ 0x01000000, /*beh*/ beh_hidden_red_coin_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ 6200, -4400, 2300, /*angle*/ 0, 0, 0, /*behArg*/ 0x02000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -2100, 2100, -7550, /*angle*/ 0, 0, 0, /*behArg*/ 0x03000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -6500, 2700, -1600, /*angle*/ 0, 0, 0, /*behArg*/ 0x04000000, /*beh*/ beh_collect_star
    object /*unk2*/ 0x3F, /*unk3*/ 0x7A, /*pos*/ -5000, 3050, -6700, /*angle*/ 0, 0, 0, /*behArg*/ 0x05000000, /*beh*/ beh_collect_star
    return

glabel level_hmc_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_hmc_segment_7SegmentRomStart, /*romEnd*/ _level_hmc_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _hmc_textures_mio0SegmentRomStart, /*romEnd*/ _hmc_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x05, /*romStart*/ _mole_monkey_fwoosh_mio0SegmentRomStart, /*romEnd*/ _mole_monkey_fwoosh_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0C, /*romStart*/ _mole_monkey_fwoosh_geoSegmentRomStart, /*romEnd*/ _mole_monkey_fwoosh_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _mri_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomStart, /*romEnd*/ _mri_swoop_snufit_dorrie_scuttlebug_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _mri_swoop_snufit_dorrie_scuttlebug_geoSegmentRomStart, /*romEnd*/ _mri_swoop_snufit_dorrie_scuttlebug_geoSegmentRomEnd
    load_mio0 /*seg*/ 0x08, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomStart, /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0F, /*romStart*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomStart,  /*romEnd*/ _amp_chuckya_shyguy_goomba_boxes_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_1
    jump_link /*target*/ script_func_global_7
    jump_link /*target*/ script_func_global_18
    cmd22 /*unk2*/ 0x001D, /*unk4*/ wooden_door_geo
    cmd22 /*unk2*/ 0x001F, /*unk4*/ metal_door_geo
    cmd22 /*unk2*/ 0x0020, /*unk4*/ hazy_maze_door_geo
    cmd22 /*unk2*/ 0x0036, /*unk4*/ hmc_geo_0005A0
    cmd22 /*unk2*/ 0x0037, /*unk4*/ hmc_geo_0005B8
    cmd22 /*unk2*/ 0x0038, /*unk4*/ hmc_geo_0005D0
    cmd22 /*unk2*/ 0x0039, /*unk4*/ hmc_geo_000548
    cmd22 /*unk2*/ 0x003A, /*unk4*/ hmc_geo_000570
    cmd22 /*unk2*/ 0x003B, /*unk4*/ hmc_geo_000588
    cmd22 /*unk2*/ 0x003C, /*unk4*/ hmc_geo_000530

    area /*index*/ 1, /*geo*/ hmc_geo_000B90
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -7152, 3161, 7181, /*angle*/ 0, 135, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warps_74
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3351, -4690, 4773, /*angle*/ 0, 0, 0, /*behArg*/ 0x340B0000, /*beh*/ beh_warp
        warp_node /*id*/ 0x0A, /*destLevel1*/ 0x07, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0x0B, /*destLevel1*/ 0x1C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF0, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x34, /*destLevel2*/ 0x00
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x66, /*destLevel2*/ 0x00
        jump_link /*target*/ script_func_local_1
        jump_link /*target*/ script_func_local_2
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        terrain /*terrainData*/ hmc_seg7_collision_level
        cmd39 /*unk4*/ hmc_seg7_macro_objs
        rooms /*surfaceRooms*/ hmc_seg7_rooms
        set_music /*unk2*/ 0x0004, /*seq*/ 0x000C
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 135, /*pos*/ -7152, 2161, 7181
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_hmc.s"
.align 4
