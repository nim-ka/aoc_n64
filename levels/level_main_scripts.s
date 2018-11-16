.include "macros.inc"
.include "level_commands.inc"

.section .level, "a"

glabel level_main_scripts_entry
    load_mio0 /*seg*/ 0x04, /*romStart*/ _mario_water_sparkles_mio0SegmentRomStart, /*romEnd*/ _mario_water_sparkles_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x03, /*romStart*/ _coins_pipe_doors_maps_trees_mio0SegmentRomStart, /*romEnd*/ _coins_pipe_doors_maps_trees_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x17, /*romStart*/ _mario_water_sparkles_geoSegmentRomStart, /*romEnd*/ _mario_water_sparkles_geoSegmentRomEnd
    load_raw  /*seg*/ 0x16, /*romStart*/ _coins_pipe_doors_maps_trees_geoSegmentRomStart, /*romEnd*/ _coins_pipe_doors_maps_trees_geoSegmentRomEnd
    load_raw  /*seg*/ 0x13, /*romStart*/ _behaviorSegmentRomStart, /*romEnd*/ _behaviorSegmentRomEnd
    alloc_level_pool
    cmd22 /*unk2*/ 0x0001, /*unk4*/ mario_geo
    cmd22 /*unk2*/ 0x0096, /*unk4*/ smoke_geo
    cmd22 /*unk2*/ 0x0095, /*unk4*/ sparkles_geo
    cmd22 /*unk2*/ 0x00A8, /*unk4*/ bubble_geo
    cmd22 /*unk2*/ 0x00A5, /*unk4*/ spot_on_ground_geo
    cmd22 /*unk2*/ 0x00A6, /*unk4*/ water_waves2_geo
    cmd22 /*unk2*/ 0x00A7, /*unk4*/ water_splash_geo
    cmd22 /*unk2*/ 0x00A3, /*unk4*/ water_waves_geo
    cmd22 /*unk2*/ 0x0074, /*unk4*/ yellow_coin_geo
    cmd22 /*unk2*/ 0x007A, /*unk4*/ star_geo
    cmd22 /*unk2*/ 0x0079, /*unk4*/ transparent_star_geo
    cmd22 /*unk2*/ 0x007C, /*unk4*/ wooden_signpost_geo
    cmd21 /*unk2*/ 0x40A4, /*unk4*/ snowball_seg4_dl_04032A18
    cmd22 /*unk2*/ 0x0090, /*unk4*/ red_flame_geo
    cmd22 /*unk2*/ 0x0091, /*unk4*/ blue_flame_geo
    cmd22 /*unk2*/ 0x0094, /*unk4*/ dirt2_geo
    cmd22 /*unk2*/ 0x00A2, /*unk4*/ leaves_geo
    cmd22 /*unk2*/ 0x00AA, /*unk4*/ purple_marble_geo
    cmd22 /*unk2*/ 0x00B9, /*unk4*/ fish_geo
    cmd22 /*unk2*/ 0x00BA, /*unk4*/ fish2_geo
    cmd22 /*unk2*/ 0x008F, /*unk4*/ sparkles_animation_geo
    cmd21 /*unk2*/ 0x409F, /*unk4*/ coins_TODO_seg3_dl_0302BCD0 
    cmd22 /*unk2*/ 0x00BB, /*unk4*/ butterfly_geo
    cmd22 /*unk2*/ 0x009C, /*unk4*/ dirt2_geo
    cmd21 /*unk2*/ 0x40A1, /*unk4*/ coins_TODO_seg3_dl_0301CB00
    cmd22 /*unk2*/ 0x008E, /*unk4*/ mist_geo
    cmd22 /*unk2*/ 0x00E0, /*unk4*/ white_puff_geo
    cmd21 /*unk2*/ 0x409E, /*unk4*/ snow_ball_seg3_dl_0302C8A0
    cmd22 /*unk2*/ 0x00A0, /*unk4*/ snowman_snow_ball_geo
    cmd22 /*unk2*/ 0x0075, /*unk4*/ yellow_coin_no_shadow_geo
    cmd22 /*unk2*/ 0x0076, /*unk4*/ blue_coin_geo
    cmd22 /*unk2*/ 0x0077, /*unk4*/ blue_coin_no_shadow_geo
    cmd22 /*unk2*/ 0x0085, /*unk4*/ marios_winged_metal_cap_geo
    cmd22 /*unk2*/ 0x0086, /*unk4*/ marios_metal_cap_geo
    cmd22 /*unk2*/ 0x0087, /*unk4*/ marios_wing_cap_geo
    cmd22 /*unk2*/ 0x0088, /*unk4*/ marios_cap_geo
    cmd22 /*unk2*/ 0x0088, /*unk4*/ marios_cap_geo
    cmd22 /*unk2*/ 0x00C8, /*unk4*/ bowser_key_geo
    cmd22 /*unk2*/ 0x00CC, /*unk4*/ bowser_key2_geo
    cmd22 /*unk2*/ 0x00CB, /*unk4*/ red_flame_shadow_geo
    cmd22 /*unk2*/ 0x00D4, /*unk4*/ mushroom_1up_geo
    cmd22 /*unk2*/ 0x00D7, /*unk4*/ red_coin_geo
    cmd22 /*unk2*/ 0x00D8, /*unk4*/ red_coin_no_shadow_geo
    cmd22 /*unk2*/ 0x00DB, /*unk4*/ number_geo
    cmd22 /*unk2*/ 0x00CD, /*unk4*/ explosion_geo
    cmd22 /*unk2*/ 0x008A, /*unk4*/ dirt_animation_geo
    cmd22 /*unk2*/ 0x008B, /*unk4*/ cartoon_star_geo
    free_level_pool
    call /*arg*/ 0, /*func*/ lvl_init_from_save_file
    loop_begin
        execute /*seg*/ 0x14, /*script*/ _level_main_menuSegmentRomStart, /*scriptEnd*/ _level_main_menuSegmentRomEnd, /*entry*/ level_main_menu_entry_2
        jump_link /*target*/ script_func_local_1
        sleep /*frames*/ 1
    loop_until /*op*/ OP_LT, /*arg*/ 0
    jump_if /*op*/ OP_EQ, /*arg*/ -1, /*target*/ L2
    jump_if /*op*/ OP_EQ, /*arg*/ -2, /*target*/ L3
    jump_if /*op*/ OP_EQ, /*arg*/ -3, /*target*/ L4
    jump_if /*op*/ OP_EQ, /*arg*/ -8, /*target*/ L1
    jump_if /*op*/ OP_EQ, /*arg*/ -9, /*target*/ L5
L1:
    exit_and_execute /*seg*/ 0x14, /*script*/ _level_introSegmentRomStart, /*scriptEnd*/ _level_introSegmentRomEnd, /*entry*/ level_intro_entry_1

L2:
    exit_and_execute /*seg*/ 0x0E, /*script*/ _level_endingSegmentRomStart, /*scriptEnd*/ _level_endingSegmentRomEnd, /*entry*/ level_ending_entry

L3:
    exit_and_execute /*seg*/ 0x14, /*script*/ _level_introSegmentRomStart, /*scriptEnd*/ _level_introSegmentRomEnd, /*entry*/ level_intro_entry_2

L4:
    exit_and_execute /*seg*/ 0x14, /*script*/ _level_introSegmentRomStart, /*scriptEnd*/ _level_introSegmentRomEnd, /*entry*/ level_intro_entry_3

L5:
    exit_and_execute /*seg*/ 0x14, /*script*/ _level_introSegmentRomStart, /*scriptEnd*/ _level_introSegmentRomEnd, /*entry*/ level_intro_entry_4

script_func_local_1:
    get_or_set /*op*/ OP_GET, /*var*/ VAR_CURR_LEVEL_NUM
    jump_if /*op*/ OP_EQ, /*arg*/ 4, /*target*/ L6
    jump_if /*op*/ OP_EQ, /*arg*/ 5, /*target*/ L7
    jump_if /*op*/ OP_EQ, /*arg*/ 6, /*target*/ L8
    jump_if /*op*/ OP_EQ, /*arg*/ 7, /*target*/ L9
    jump_if /*op*/ OP_EQ, /*arg*/ 8, /*target*/ L10
    jump_if /*op*/ OP_EQ, /*arg*/ 9, /*target*/ L11
    jump_if /*op*/ OP_EQ, /*arg*/ 10, /*target*/ L12
    jump_if /*op*/ OP_EQ, /*arg*/ 11, /*target*/ L13
    jump_if /*op*/ OP_EQ, /*arg*/ 12, /*target*/ L14
    jump_if /*op*/ OP_EQ, /*arg*/ 13, /*target*/ L15
    jump_if /*op*/ OP_EQ, /*arg*/ 14, /*target*/ L16
    jump_if /*op*/ OP_EQ, /*arg*/ 15, /*target*/ L17
    jump_if /*op*/ OP_EQ, /*arg*/ 16, /*target*/ L18
    jump_if /*op*/ OP_EQ, /*arg*/ 17, /*target*/ L19
    jump_if /*op*/ OP_EQ, /*arg*/ 18, /*target*/ L20
    jump_if /*op*/ OP_EQ, /*arg*/ 19, /*target*/ L21
    jump_if /*op*/ OP_EQ, /*arg*/ 20, /*target*/ L22
    jump_if /*op*/ OP_EQ, /*arg*/ 21, /*target*/ L23
    jump_if /*op*/ OP_EQ, /*arg*/ 22, /*target*/ L24
    jump_if /*op*/ OP_EQ, /*arg*/ 23, /*target*/ L25
    jump_if /*op*/ OP_EQ, /*arg*/ 24, /*target*/ L26
    jump_if /*op*/ OP_EQ, /*arg*/ 25, /*target*/ L27
    jump_if /*op*/ OP_EQ, /*arg*/ 26, /*target*/ L28
    jump_if /*op*/ OP_EQ, /*arg*/ 27, /*target*/ L29
    jump_if /*op*/ OP_EQ, /*arg*/ 28, /*target*/ L30
    jump_if /*op*/ OP_EQ, /*arg*/ 29, /*target*/ L31
    jump_if /*op*/ OP_EQ, /*arg*/ 30, /*target*/ L32
    jump_if /*op*/ OP_EQ, /*arg*/ 31, /*target*/ L33
    jump_if /*op*/ OP_EQ, /*arg*/ 33, /*target*/ L34
    jump_if /*op*/ OP_EQ, /*arg*/ 34, /*target*/ L35
    jump_if /*op*/ OP_EQ, /*arg*/ 36, /*target*/ L36
    exit

L6:
    execute /*seg*/ 0x0E, /*script*/ _level_bbhSegmentRomStart, /*scriptEnd*/ _level_bbhSegmentRomEnd, /*entry*/ level_bbh_entry
    return

L7:
    execute /*seg*/ 0x0E, /*script*/ _level_ccmSegmentRomStart, /*scriptEnd*/ _level_ccmSegmentRomEnd, /*entry*/ level_ccm_entry
    return

L8:
    execute /*seg*/ 0x0E, /*script*/ _level_castleSegmentRomStart, /*scriptEnd*/ _level_castleSegmentRomEnd, /*entry*/ level_castle_entry
    return

L9:
    execute /*seg*/ 0x0E, /*script*/ _level_hmcSegmentRomStart, /*scriptEnd*/ _level_hmcSegmentRomEnd, /*entry*/ level_hmc_entry
    return

L10:
    execute /*seg*/ 0x0E, /*script*/ _level_sslSegmentRomStart, /*scriptEnd*/ _level_sslSegmentRomEnd, /*entry*/ level_ssl_entry
    return

L11:
    execute /*seg*/ 0x0E, /*script*/ _level_bobSegmentRomStart, /*scriptEnd*/ _level_bobSegmentRomEnd, /*entry*/ level_bob_entry
    return

L12:
    execute /*seg*/ 0x0E, /*script*/ _level_slSegmentRomStart, /*scriptEnd*/ _level_slSegmentRomEnd, /*entry*/ level_sl_entry
    return

L13:
    execute /*seg*/ 0x0E, /*script*/ _level_wdwSegmentRomStart, /*scriptEnd*/ _level_wdwSegmentRomEnd, /*entry*/ level_wdw_entry
    return

L14:
    execute /*seg*/ 0x0E, /*script*/ _level_jrbSegmentRomStart, /*scriptEnd*/ _level_jrbSegmentRomEnd, /*entry*/ level_jrb_entry
    return

L15:
    execute /*seg*/ 0x0E, /*script*/ _level_thiSegmentRomStart, /*scriptEnd*/ _level_thiSegmentRomEnd, /*entry*/ level_thi_entry
    return

L16:
    execute /*seg*/ 0x0E, /*script*/ _level_ttcSegmentRomStart, /*scriptEnd*/ _level_ttcSegmentRomEnd, /*entry*/ level_ttc_entry
    return

L17:
    execute /*seg*/ 0x0E, /*script*/ _level_rrSegmentRomStart, /*scriptEnd*/ _level_rrSegmentRomEnd, /*entry*/ level_rr_entry
    return

L18:
    execute /*seg*/ 0x0E, /*script*/ _level_castle_groundsSegmentRomStart, /*scriptEnd*/ _level_castle_groundsSegmentRomEnd, /*entry*/ level_castle_grounds_entry
    return

L19:
    execute /*seg*/ 0x0E, /*script*/ _level_bitdwSegmentRomStart, /*scriptEnd*/ _level_bitdwSegmentRomEnd, /*entry*/ level_bitdw_entry
    return

L20:
    execute /*seg*/ 0x0E, /*script*/ _level_vcutmSegmentRomStart, /*scriptEnd*/ _level_vcutmSegmentRomEnd, /*entry*/ level_vcutm_entry
    return

L21:
    execute /*seg*/ 0x0E, /*script*/ _level_bitfsSegmentRomStart, /*scriptEnd*/ _level_bitfsSegmentRomEnd, /*entry*/ level_bitfs_entry
    return

L22:
    execute /*seg*/ 0x0E, /*script*/ _level_saSegmentRomStart, /*scriptEnd*/ _level_saSegmentRomEnd, /*entry*/ level_sa_entry
    return

L23:
    execute /*seg*/ 0x0E, /*script*/ _level_bitsSegmentRomStart, /*scriptEnd*/ _level_bitsSegmentRomEnd, /*entry*/ level_bits_entry
    return

L24:
    execute /*seg*/ 0x0E, /*script*/ _level_lllSegmentRomStart, /*scriptEnd*/ _level_lllSegmentRomEnd, /*entry*/ level_lll_entry
    return

L25:
    execute /*seg*/ 0x0E, /*script*/ _level_dddSegmentRomStart, /*scriptEnd*/ _level_dddSegmentRomEnd, /*entry*/ level_ddd_entry
    return

L26:
    execute /*seg*/ 0x0E, /*script*/ _level_wfSegmentRomStart, /*scriptEnd*/ _level_wfSegmentRomEnd, /*entry*/ level_wf_entry
    return

L27:
    execute /*seg*/ 0x0E, /*script*/ _level_endingSegmentRomStart, /*scriptEnd*/ _level_endingSegmentRomEnd, /*entry*/ level_ending_entry
    return

L28:
    execute /*seg*/ 0x0E, /*script*/ _level_castle_courtyardSegmentRomStart, /*scriptEnd*/ _level_castle_courtyardSegmentRomEnd, /*entry*/ level_castle_courtyard_entry
    return

L29:
    execute /*seg*/ 0x0E, /*script*/ _level_pssSegmentRomStart, /*scriptEnd*/ _level_pssSegmentRomEnd, /*entry*/ level_pss_entry
    return

L30:
    execute /*seg*/ 0x0E, /*script*/ _level_cotmcSegmentRomStart, /*scriptEnd*/ _level_cotmcSegmentRomEnd, /*entry*/ level_cotmc_entry
    return

L31:
    execute /*seg*/ 0x0E, /*script*/ _level_totwcSegmentRomStart, /*scriptEnd*/ _level_totwcSegmentRomEnd, /*entry*/ level_totwc_entry
    return

L32:
    execute /*seg*/ 0x0E, /*script*/ _level_bowser_1SegmentRomStart, /*scriptEnd*/ _level_bowser_1SegmentRomEnd, /*entry*/ level_bowser_1_entry
    return

L33:
    execute /*seg*/ 0x0E, /*script*/ _level_wmotrSegmentRomStart, /*scriptEnd*/ _level_wmotrSegmentRomEnd, /*entry*/ level_wmotr_entry
    return

L34:
    execute /*seg*/ 0x0E, /*script*/ _level_bowser_2SegmentRomStart, /*scriptEnd*/ _level_bowser_2SegmentRomEnd, /*entry*/ level_bowser_2_entry
    return

L35:
    execute /*seg*/ 0x0E, /*script*/ _level_bowser_3SegmentRomStart, /*scriptEnd*/ _level_bowser_3SegmentRomEnd, /*entry*/ level_bowser_3_entry
    return

L36:
    execute /*seg*/ 0x0E, /*script*/ _level_ttmSegmentRomStart, /*scriptEnd*/ _level_ttmSegmentRomEnd, /*entry*/ level_ttm_entry
    return

glabel script_func_global_1
    cmd22 /*unk2*/ 0x008C, /*unk4*/ blue_coin_switch_geo
    cmd22 /*unk2*/ 0x00C2, /*unk4*/ amp_geo
    cmd22 /*unk2*/ 0x00CF, /*unk4*/ purple_switch_geo
    cmd22 /*unk2*/ 0x00CA, /*unk4*/ checkerboard_platform_geo
    cmd22 /*unk2*/ 0x0081, /*unk4*/ breakable_box_geo
    cmd22 /*unk2*/ 0x0082, /*unk4*/ breakable_box2_geo
    cmd22 /*unk2*/ 0x0083, /*unk4*/ exclamation_box_outline_geo
    cmd22 /*unk2*/ 0x0089, /*unk4*/ exclamation_box_geo
    cmd22 /*unk2*/ 0x00C0, /*unk4*/ goomba_geo
    cmd21 /*unk2*/ 0x4084, /*unk4*/ exclamation_point_seg8_dl_08025F08
    cmd22 /*unk2*/ 0x00BE, /*unk4*/ koopa_shell_geo
    cmd22 /*unk2*/ 0x00D9, /*unk4*/ metal_box_geo
    cmd21 /*unk2*/ 0x10DA, /*unk4*/ metal_box_seg8_dl_08024BB8
    cmd22 /*unk2*/ 0x00BC, /*unk4*/ black_bobomb_geo
    cmd22 /*unk2*/ 0x00C3, /*unk4*/ pink_bobomb_geo
    cmd21 /*unk2*/ 0x10C9, /*unk4*/ cannon_closed_seg8_dl_080048E0
    cmd22 /*unk2*/ 0x00B4, /*unk4*/ bowling_ball_geo
    cmd22 /*unk2*/ 0x007F, /*unk4*/ cannon_barrel_geo
    cmd22 /*unk2*/ 0x0080, /*unk4*/ cannon_base_geo
    cmd22 /*unk2*/ 0x0078, /*unk4*/ heart_geo
    cmd22 /*unk2*/ 0x00DC, /*unk4*/ shyguy_geo
    cmd22 /*unk2*/ 0x00DF, /*unk4*/ chuckya_geo
    cmd22 /*unk2*/ 0x00E1, /*unk4*/ bowling_ball2_geo
    return

glabel script_func_global_2
    cmd22 /*unk2*/ 0x0054, /*unk4*/ bullet_bill_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ yellow_sphere_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ hoot_geo
    cmd22 /*unk2*/ 0x0057, /*unk4*/ yoshi_egg_geo
    cmd22 /*unk2*/ 0x0058, /*unk4*/ thwomp_geo
    cmd22 /*unk2*/ 0x0059, /*unk4*/ heave_ho_geo
    return

glabel script_func_global_3
    cmd22 /*unk2*/ 0x0054, /*unk4*/ blargg_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ bully_geo
    cmd22 /*unk2*/ 0x0057, /*unk4*/ bully_boss_geo
    return

glabel script_func_global_4
    cmd22 /*unk2*/ 0x0054, /*unk4*/ water_bubble_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ water_bubble_shadow_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ king_bobomb_geo
    return

glabel script_func_global_5
    cmd22 /*unk2*/ 0x0054, /*unk4*/ manta_seg5_geo_05008D14
    cmd22 /*unk2*/ 0x0055, /*unk4*/ unagi_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ sushi_geo
    cmd21 /*unk2*/ 0x5057, /*unk4*/ whirlpool_seg5_dl_05013CB8
    cmd22 /*unk2*/ 0x0058, /*unk4*/ clam_shell_geo
    return

glabel script_func_global_6
    cmd22 /*unk2*/ 0x0054, /*unk4*/ pokey_head_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ pokey_body_part_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ tornado_seg5_geo_05014630
    cmd22 /*unk2*/ 0x0057, /*unk4*/ klepto_geo
    cmd22 /*unk2*/ 0x0058, /*unk4*/ eyerok_geo
    cmd22 /*unk2*/ 0x0059, /*unk4*/ eyerok2_geo
    return

glabel script_func_global_7
    cmd21 /*unk2*/ 0x6054, /*unk4*/ monty_mole_hole_seg5_dl_05000840
    cmd22 /*unk2*/ 0x0055, /*unk4*/ monty_mole_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ ukiki_geo
    cmd22 /*unk2*/ 0x0057, /*unk4*/ fwoosh_geo
    return

glabel script_func_global_8
    cmd22 /*unk2*/ 0x0054, /*unk4*/ spindrift_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ mr_blizzard_hidden_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ mr_blizzard_geo
    cmd22 /*unk2*/ 0x0057, /*unk4*/ penguin_geo
    return

glabel script_func_global_9
    cmd21 /*unk2*/ 0x4054, /*unk4*/ capswitch_seg5_dl_05002E00
    cmd22 /*unk2*/ 0x0055, /*unk4*/ cap_switch_geo
    cmd21 /*unk2*/ 0x1056, /*unk4*/ cap_switch_base_seg5_dl_05003120
    return

glabel script_func_global_10
    cmd22 /*unk2*/ 0x0054, /*unk4*/ boo_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ small_key_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ haunted_chair_geo
    cmd22 /*unk2*/ 0x0057, /*unk4*/ mad_piano_geo
    cmd22 /*unk2*/ 0x0058, /*unk4*/ bookend_part_geo
    cmd22 /*unk2*/ 0x0059, /*unk4*/ book_enemy_geo
    cmd22 /*unk2*/ 0x005A, /*unk4*/ haunted_cage_geo
    return

glabel script_func_global_11
    cmd22 /*unk2*/ 0x0054, /*unk4*/ birds_geo
    cmd22 /*unk2*/ 0x00DE, /*unk4*/ peach_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ yoshi_geo
    return

glabel script_func_global_12
    cmd22 /*unk2*/ 0x0054, /*unk4*/ lakitu_enemy_geo
    cmd22 /*unk2*/ 0x0055, /*unk4*/ spiny_egg_geo
    cmd22 /*unk2*/ 0x0056, /*unk4*/ spiny_geo
    cmd22 /*unk2*/ 0x0057, /*unk4*/ wiggler_geo
    cmd22 /*unk2*/ 0x0058, /*unk4*/ wiggler2_geo
    cmd22 /*unk2*/ 0x0059, /*unk4*/ bubba_geo
    return

glabel script_func_global_13
    cmd22 /*unk2*/ 0x0064, /*unk4*/ bowser_geo
    cmd22 /*unk2*/ 0x0065, /*unk4*/ bowser_bomb_geo
    cmd22 /*unk2*/ 0x00B3, /*unk4*/ bowser_bomb_geo
    cmd22 /*unk2*/ 0x0066, /*unk4*/ bowser_clouds_geo
    cmd22 /*unk2*/ 0x0067, /*unk4*/ bowser_flames_geo
    cmd22 /*unk2*/ 0x0068, /*unk4*/ invisible_bowser_accessory_geo
    cmd22 /*unk2*/ 0x0069, /*unk4*/ bowser2_geo
    return

glabel script_func_global_14
    cmd22 /*unk2*/ 0x0064, /*unk4*/ chirp_chirp_geo
    cmd22 /*unk2*/ 0x0065, /*unk4*/ treasure_chest_bottom_geo
    cmd22 /*unk2*/ 0x0066, /*unk4*/ treasure_chest_lid_geo
    cmd22 /*unk2*/ 0x0067, /*unk4*/ fish3_geo
    cmd22 /*unk2*/ 0x0068, /*unk4*/ manta_ring_geo
    cmd22 /*unk2*/ 0x00B3, /*unk4*/ water_mine_geo
    cmd22 /*unk2*/ 0x00C1, /*unk4*/ seaweed_geo
    cmd22 /*unk2*/ 0x0069, /*unk4*/ skeeter_geo
    return

glabel script_func_global_15
    cmd22 /*unk2*/ 0x0064, /*unk4*/ piranha_plant_geo
    cmd22 /*unk2*/ 0x0067, /*unk4*/ whomp_geo
    cmd22 /*unk2*/ 0x0068, /*unk4*/ koopa2_geo
    cmd22 /*unk2*/ 0x00BF, /*unk4*/ koopa_geo
    cmd22 /*unk2*/ 0x0065, /*unk4*/ metallic_ball_geo
    cmd22 /*unk2*/ 0x0066, /*unk4*/ chain_chomp
    cmd22 /*unk2*/ 0x006A, /*unk4*/ koopa_flag_geo
    cmd22 /*unk2*/ 0x006B, /*unk4*/ poundable_wooden_log
    return

glabel script_func_global_16
    cmd22 /*unk2*/ 0x0064, /*unk4*/ mips_geo
    cmd22 /*unk2*/ 0x0065, /*unk4*/ boo_castle_geo
    cmd22 /*unk2*/ 0x0066, /*unk4*/ lakitu_geo
    cmd22 /*unk2*/ 0x00DD, /*unk4*/ toad_geo
    return

glabel script_func_global_17
    cmd22 /*unk2*/ 0x0064, /*unk4*/ chilly_chief_seg6_geo
    cmd22 /*unk2*/ 0x0065, /*unk4*/ chilly_chief_seg6_geo2
    cmd22 /*unk2*/ 0x0066, /*unk4*/ moneybag_geo
    return

glabel script_func_global_18
    cmd22 /*unk2*/ 0x0064, /*unk4*/ swoop_geo
    cmd22 /*unk2*/ 0x0065, /*unk4*/ scuttlebug_geo
    cmd22 /*unk2*/ 0x0066, /*unk4*/ mr_i_iris_geo
    cmd22 /*unk2*/ 0x0067, /*unk4*/ mr_i_geo
    cmd22 /*unk2*/ 0x0068, /*unk4*/ dorrie_geo
    cmd22 /*unk2*/ 0x00CE, /*unk4*/ snufit_geo
    return

.align 4
