.include "macros.inc"
.include "level_commands.inc"

.section .level, "a"

glabel level_main_scripts_entry
    load_mio0 /*seg*/ 0x04, /*romStart*/ mario, /*romEnd*/ mario_end
    load_mio0 /*seg*/ 0x03, /*romStart*/ doors_trees_coins, /*romEnd*/ doors_trees_coins_end
    load_raw /*seg*/ 0x17, /*romStart*/ water_sparkles_mario, /*romEnd*/ water_sparkles_mario_end
    load_raw /*seg*/ 0x16, /*romStart*/ coins_pipe_doors_maps_trees, /*romEnd*/ coins_pipe_doors_maps_trees_end
    load_raw /*seg*/ 0x13, /*romStart*/ _behaviorSegmentRomStart, /*romEnd*/ _behaviorSegmentRomEnd
    alloc_level_pool
    cmd22 /*unk2*/ 0x0001, /*unk4*/ 0x17002DD4
    cmd22 /*unk2*/ 0x0096, /*unk4*/ 0x17000038
    cmd22 /*unk2*/ 0x0095, /*unk4*/ 0x170001BC
    cmd22 /*unk2*/ 0x00A8, /*unk4*/ 0x17000000
    cmd22 /*unk2*/ 0x00A5, /*unk4*/ 0x1700009C
    cmd22 /*unk2*/ 0x00A6, /*unk4*/ 0x17000124
    cmd22 /*unk2*/ 0x00A7, /*unk4*/ 0x17000230
    cmd22 /*unk2*/ 0x00A3, /*unk4*/ 0x17000168
    cmd22 /*unk2*/ 0x0074, /*unk4*/ 0x1600013C
    cmd22 /*unk2*/ 0x007A, /*unk4*/ 0x16000EA0
    cmd22 /*unk2*/ 0x0079, /*unk4*/ 0x16000F6C
    cmd22 /*unk2*/ 0x007C, /*unk4*/ 0x16000FB4
    cmd21 /*unk2*/ 0x40A4, /*unk4*/ 0x04032A18
    cmd22 /*unk2*/ 0x0090, /*unk4*/ 0x16000B2C
    cmd22 /*unk2*/ 0x0091, /*unk4*/ 0x16000B8C
    cmd22 /*unk2*/ 0x0094, /*unk4*/ 0x17000084
    cmd22 /*unk2*/ 0x00A2, /*unk4*/ 0x16000C8C
    cmd22 /*unk2*/ 0x00AA, /*unk4*/ 0x1700001C
    cmd22 /*unk2*/ 0x00B9, /*unk4*/ 0x16000C44
    cmd22 /*unk2*/ 0x00BA, /*unk4*/ 0x16000BEC
    cmd22 /*unk2*/ 0x008F, /*unk4*/ 0x17000284
    cmd21 /*unk2*/ 0x409F, /*unk4*/ 0x0302BCD0
    cmd22 /*unk2*/ 0x00BB, /*unk4*/ 0x160000A8
    cmd22 /*unk2*/ 0x009C, /*unk4*/ 0x17000084
    cmd21 /*unk2*/ 0x40A1, /*unk4*/ 0x0301CB00
    cmd22 /*unk2*/ 0x008E, /*unk4*/ 0x16000000
    cmd22 /*unk2*/ 0x00E0, /*unk4*/ 0x16000020
    cmd21 /*unk2*/ 0x409E, /*unk4*/ 0x0302C8A0
    cmd22 /*unk2*/ 0x00A0, /*unk4*/ 0x16000F98
    cmd22 /*unk2*/ 0x0075, /*unk4*/ 0x160001A0
    cmd22 /*unk2*/ 0x0076, /*unk4*/ 0x16000200
    cmd22 /*unk2*/ 0x0077, /*unk4*/ 0x16000264
    cmd22 /*unk2*/ 0x0085, /*unk4*/ 0x16000DA8
    cmd22 /*unk2*/ 0x0086, /*unk4*/ 0x16000CF0
    cmd22 /*unk2*/ 0x0087, /*unk4*/ 0x16000D3C
    cmd22 /*unk2*/ 0x0088, /*unk4*/ 0x16000CA4
    cmd22 /*unk2*/ 0x0088, /*unk4*/ 0x16000CA4
    cmd22 /*unk2*/ 0x00C8, /*unk4*/ 0x16000AB0
    cmd22 /*unk2*/ 0x00CC, /*unk4*/ 0x16000A84
    cmd22 /*unk2*/ 0x00CB, /*unk4*/ 0x16000B10
    cmd22 /*unk2*/ 0x00D4, /*unk4*/ 0x16000E84
    cmd22 /*unk2*/ 0x00D7, /*unk4*/ 0x160002C4
    cmd22 /*unk2*/ 0x00D8, /*unk4*/ 0x16000328
    cmd22 /*unk2*/ 0x00DB, /*unk4*/ 0x16000E14
    cmd22 /*unk2*/ 0x00CD, /*unk4*/ 0x16000040
    cmd22 /*unk2*/ 0x008A, /*unk4*/ 0x16000ED4
    cmd22 /*unk2*/ 0x008B, /*unk4*/ 0x16000F24
    free_level_pool
    call /*arg*/ 0, /*func*/ lvl_init_from_save_file
    link_push_zero
    execute /*seg*/ 0x14, /*script*/ _level_main_menuSegmentRomStart, /*scriptEnd*/ _level_main_menuSegmentRomEnd, /*entry*/ level_main_menu_entry_2
    jump_link /*target*/ script_func_local_1
    sleep /*frames*/ 1
    pop_twice_if /*op*/ OP_LT, /*arg*/ 0
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
    cmd22 /*unk2*/ 0x008C, /*unk4*/ 0x0F000000
    cmd22 /*unk2*/ 0x00C2, /*unk4*/ 0x0F000028
    cmd22 /*unk2*/ 0x00CF, /*unk4*/ 0x0F0004CC
    cmd22 /*unk2*/ 0x00CA, /*unk4*/ 0x0F0004E4
    cmd22 /*unk2*/ 0x0081, /*unk4*/ 0x0F0005D0
    cmd22 /*unk2*/ 0x0082, /*unk4*/ 0x0F000610
    cmd22 /*unk2*/ 0x0083, /*unk4*/ 0x0F000A58
    cmd22 /*unk2*/ 0x0089, /*unk4*/ 0x0F000694
    cmd22 /*unk2*/ 0x00C0, /*unk4*/ 0x0F0006E4
    cmd21 /*unk2*/ 0x4084, /*unk4*/ 0x08025F08
    cmd22 /*unk2*/ 0x00BE, /*unk4*/ 0x0F000AB0
    cmd22 /*unk2*/ 0x00D9, /*unk4*/ 0x0F000A30
    cmd21 /*unk2*/ 0x10DA, /*unk4*/ 0x08024BB8
    cmd22 /*unk2*/ 0x00BC, /*unk4*/ 0x0F0007B8
    cmd22 /*unk2*/ 0x00C3, /*unk4*/ 0x0F0008F4
    cmd21 /*unk2*/ 0x10C9, /*unk4*/ 0x080048E0
    cmd22 /*unk2*/ 0x00B4, /*unk4*/ 0x0F000640
    cmd22 /*unk2*/ 0x007F, /*unk4*/ 0x0F0001C0
    cmd22 /*unk2*/ 0x0080, /*unk4*/ 0x0F0001A8
    cmd22 /*unk2*/ 0x0078, /*unk4*/ 0x0F0004FC
    cmd22 /*unk2*/ 0x00DC, /*unk4*/ 0x0F000518
    cmd22 /*unk2*/ 0x00DF, /*unk4*/ 0x0F0001D8
    cmd22 /*unk2*/ 0x00E1, /*unk4*/ 0x0F00066C
    return

glabel script_func_global_2
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000264
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000018
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C0001E4
    cmd22 /*unk2*/ 0x0058, /*unk4*/ 0x0C000248
    cmd22 /*unk2*/ 0x0059, /*unk4*/ 0x0C00028C
    return

glabel script_func_global_3
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000240
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C000120
    return

glabel script_func_global_4
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000308
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000328
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000000
    return

glabel script_func_global_5
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x05008D14
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C00010C
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000068
    cmd21 /*unk2*/ 0x5057, /*unk4*/ 0x05013CB8
    cmd22 /*unk2*/ 0x0058, /*unk4*/ 0x0C000000
    return

glabel script_func_global_6
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000610
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000644
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x05014630
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x0058, /*unk4*/ 0x0C0005A8
    cmd22 /*unk2*/ 0x0059, /*unk4*/ 0x0C0005E4
    return

glabel script_func_global_7
    cmd21 /*unk2*/ 0x6054, /*unk4*/ 0x05000840
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000110
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C00036C
    return

glabel script_func_global_8
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C00021C
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000348
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C000104
    return

glabel script_func_global_9
    cmd21 /*unk2*/ 0x4054, /*unk4*/ 0x05002E00
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000048
    cmd21 /*unk2*/ 0x1056, /*unk4*/ 0x05003120
    return

glabel script_func_global_10
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000224
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000188
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C0000D8
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C0001B4
    cmd22 /*unk2*/ 0x0058, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x0059, /*unk4*/ 0x0C0000C0
    cmd22 /*unk2*/ 0x005A, /*unk4*/ 0x0C000274
    return

glabel script_func_global_11
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C000000
    cmd22 /*unk2*/ 0x00DE, /*unk4*/ 0x0C000410
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000468
    return

glabel script_func_global_12
    cmd22 /*unk2*/ 0x0054, /*unk4*/ 0x0C0001BC
    cmd22 /*unk2*/ 0x0055, /*unk4*/ 0x0C000290
    cmd22 /*unk2*/ 0x0056, /*unk4*/ 0x0C000328
    cmd22 /*unk2*/ 0x0057, /*unk4*/ 0x0C000030
    cmd22 /*unk2*/ 0x0058, /*unk4*/ 0x0500C778
    cmd22 /*unk2*/ 0x0059, /*unk4*/ 0x0C000000
    return

glabel script_func_global_13
    cmd22 /*unk2*/ 0x0064, /*unk4*/ 0x0D000AB8
    cmd22 /*unk2*/ 0x0065, /*unk4*/ 0x0D000B78
    cmd22 /*unk2*/ 0x00B3, /*unk4*/ 0x0D000B78
    cmd22 /*unk2*/ 0x0066, /*unk4*/ 0x0D000BB8
    cmd22 /*unk2*/ 0x0067, /*unk4*/ 0x0D000000
    cmd22 /*unk2*/ 0x0068, /*unk4*/ 0x0D000090
    cmd22 /*unk2*/ 0x0069, /*unk4*/ 0x0D000B18
    return

glabel script_func_global_14
    cmd22 /*unk2*/ 0x0064, /*unk4*/ 0x0D00038C
    cmd22 /*unk2*/ 0x0065, /*unk4*/ 0x0D000450
    cmd22 /*unk2*/ 0x0066, /*unk4*/ 0x0D000468
    cmd22 /*unk2*/ 0x0067, /*unk4*/ 0x0D000324
    cmd22 /*unk2*/ 0x0068, /*unk4*/ 0x0D000414
    cmd22 /*unk2*/ 0x00B3, /*unk4*/ 0x0D0002F4
    cmd22 /*unk2*/ 0x00C1, /*unk4*/ 0x0D000284
    cmd22 /*unk2*/ 0x0069, /*unk4*/ 0x0D000000
    return

glabel script_func_global_15
    cmd22 /*unk2*/ 0x0064, /*unk4*/ 0x0D000358
    cmd22 /*unk2*/ 0x0067, /*unk4*/ 0x0D000480
    cmd22 /*unk2*/ 0x0068, /*unk4*/ 0x0D000214
    cmd22 /*unk2*/ 0x00BF, /*unk4*/ 0x0D0000D0
    cmd22 /*unk2*/ 0x0065, /*unk4*/ 0x0D0005D0
    cmd22 /*unk2*/ 0x0066, /*unk4*/ 0x0D0005EC
    cmd22 /*unk2*/ 0x006A, /*unk4*/ 0x0D000000
    cmd22 /*unk2*/ 0x006B, /*unk4*/ 0x0D0000B8
    return

glabel script_func_global_16
    cmd22 /*unk2*/ 0x0064, /*unk4*/ 0x0D000448
    cmd22 /*unk2*/ 0x0065, /*unk4*/ 0x0D0005B0
    cmd22 /*unk2*/ 0x0066, /*unk4*/ 0x0D000000
    cmd22 /*unk2*/ 0x00DD, /*unk4*/ 0x0D0003E4
    return

glabel script_func_global_17
    cmd22 /*unk2*/ 0x0064, /*unk4*/ 0x06003754
    cmd22 /*unk2*/ 0x0065, /*unk4*/ 0x06003874
    cmd22 /*unk2*/ 0x0066, /*unk4*/ 0x0D0000F0
    return

glabel script_func_global_18
    cmd22 /*unk2*/ 0x0064, /*unk4*/ 0x0D0000DC
    cmd22 /*unk2*/ 0x0065, /*unk4*/ 0x0D000394
    cmd22 /*unk2*/ 0x0066, /*unk4*/ 0x0D00001C
    cmd22 /*unk2*/ 0x0067, /*unk4*/ 0x0D000000
    cmd22 /*unk2*/ 0x0068, /*unk4*/ 0x0D000230
    cmd22 /*unk2*/ 0x00CE, /*unk4*/ 0x0D0001A0
    return

.align 4
