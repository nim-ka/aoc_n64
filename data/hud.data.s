.include "macros.inc"
.include "model_ids.inc"

.section .data

.set PRESET_ID, 0 # useless until I figure out how to include this file in level mio0 files.

.macro macro_obj_preset name, beh, model, bparam=0
	.set \name, PRESET_ID
	.set PRESET_ID, PRESET_ID + 1
	
	.word \beh
	.hword \model, \bparam
.endm

# There are many presets which are just a singular yellow coin which are unused. It's possible that these presets were generated
# by a tool and these unused presets were deleted, which made the tool replace them with a default preset.
.macro blank_preset name
	macro_obj_preset \name, beh_yellow_coin, MODEL_YELLOW_COIN
.endm

# TODO: Experiment with some of the unused presets to come up with better names.

glabel MacroObjectPresets
macro_obj_preset macro_yellow_coin,                 /*beh*/ beh_yellow_coin,         /*modelID*/ MODEL_YELLOW_COIN
macro_obj_preset macro_yellow_coin_2,               /*beh*/ beh_one_coin,            /*modelID*/ MODEL_YELLOW_COIN
macro_obj_preset macro_moving_blue_coin,            /*beh*/ beh_moving_blue_coin,    /*modelID*/ MODEL_BLUE_COIN
macro_obj_preset macro_sliding_blue_coin,           /*beh*/ beh_blue_coin_sliding,   /*modelID*/ MODEL_BLUE_COIN # unused
macro_obj_preset macro_red_coin,                    /*beh*/ beh_red_coin,            /*modelID*/ MODEL_RED_COIN
blank_preset macro_empty_5
macro_obj_preset macro_coin_line_horizontal,        /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE
macro_obj_preset macro_coin_ring_horizontal,        /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_RING
macro_obj_preset macro_coin_arrow,                  /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_ARROW
macro_obj_preset macro_coin_line_horizontal_flying, /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_FLYING
macro_obj_preset macro_coin_line_vertical,          /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL
macro_obj_preset macro_coin_ring_horizontal_flying, /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING
macro_obj_preset macro_coin_ring_vertical,          /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING | COIN_FORMATION_FLAG_VERTICAL
macro_obj_preset macro_coin_arrow_flying,           /*beh*/ beh_coin_formation,      /*modelID*/ MODEL_NONE,     /*behParam*/ COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_ARROW # unused
macro_obj_preset macro_hidden_star_trigger,         /*beh*/ beh_hidden_star_trigger, /*modelID*/ MODEL_NONE
blank_preset macro_empty_15
blank_preset macro_empty_16
blank_preset macro_empty_17
blank_preset macro_empty_18
blank_preset macro_empty_19
macro_obj_preset macro_fake_star,                   /*beh*/ beh_unused_fake_star,            /*modelID*/ MODEL_STAR             # unused
macro_obj_preset macro_wooden_signpost,             /*beh*/ beh_message_panel,               /*modelID*/ MODEL_WOODEN_SIGNPOST
macro_obj_preset macro_cannon_closed,               /*beh*/ beh_cannon_closed,               /*modelID*/ MODEL_DL_CANNON_LID
macro_obj_preset macro_bobomb_buddy_opens_cannon,   /*beh*/ beh_bobomb_buddy_opens_cannon,   /*modelID*/ MODEL_BOBOMB_BUDDY
macro_obj_preset macro_butterfly,                   /*beh*/ beh_butterfly,                   /*modelID*/ MODEL_BUTTERFLY        # unused
macro_obj_preset macro_bouncing_fireball_copy,      /*beh*/ beh_bouncing_fireball,           /*modelID*/ MODEL_NONE             # unused
macro_obj_preset macro_fish_group_3,                /*beh*/ beh_large_fish_group,            /*modelID*/ MODEL_NONE,            /*behParam*/ 0 # unused
macro_obj_preset macro_fish_group,                  /*beh*/ beh_large_fish_group,            /*modelID*/ MODEL_NONE,            /*behParam*/ 1
macro_obj_preset macro_unknown_28,                  /*beh*/ beh_multiple_coins,              /*modelID*/ MODEL_NONE             # unused
macro_obj_preset macro_hidden_1up_in_pole,          /*beh*/ beh_hidden_1up_in_pole_spawner,  /*modelID*/ MODEL_NONE
macro_obj_preset macro_huge_goomba,                 /*beh*/ bGoomba,                         /*modelID*/ MODEL_GOOMBA,          /*behParam*/ 1
macro_obj_preset macro_tiny_goomba,                 /*beh*/ bGoomba,                         /*modelID*/ MODEL_GOOMBA,          /*behParam*/ 2
macro_obj_preset macro_goomba_triplet_spawner,      /*beh*/ bGoombaTripletSpawner,           /*modelID*/ MODEL_NONE,            /*behParam*/ 0
macro_obj_preset macro_goomba_quintuplet_spawner,   /*beh*/ bGoombaTripletSpawner,           /*modelID*/ MODEL_NONE,            /*behParam*/ 8 # unused
macro_obj_preset macro_sign_on_wall,                /*beh*/ beh_sign_on_wall,                /*modelID*/ MODEL_NONE
macro_obj_preset macro_chuckya,                     /*beh*/ beh_chuckya,                     /*modelID*/ MODEL_CHUCKYA
macro_obj_preset macro_cannon_opened,               /*beh*/ beh_cannon,                      /*modelID*/ MODEL_CANNON_BASE
macro_obj_preset macro_goomba,                      /*beh*/ bGoomba,                         /*modelID*/ MODEL_GOOMBA
macro_obj_preset macro_amp_homing,                  /*beh*/ beh_amp_homing,                  /*modelID*/ MODEL_AMP
macro_obj_preset macro_amp_circling,                /*beh*/ beh_amp_circling,                /*modelID*/ MODEL_AMP
macro_obj_preset macro_unknown_40,                  /*beh*/ beh_carry_something1,            /*modelID*/ 0x007D # unknown model # unused
macro_obj_preset macro_unknown_41,                  /*beh*/ beh_beta_trampoline,             /*modelID*/ 0x00B5 # unknown model # unused
macro_obj_preset macro_free_bowling_ball,           /*beh*/ beh_free_bowling_ball,           /*modelID*/ MODEL_BOWLING_BALL     # unused
macro_obj_preset macro_snufit,                      /*beh*/ beh_snufit,                      /*modelID*/ MODEL_SNUFIT
macro_obj_preset macro_recovery_heart,              /*beh*/ beh_recovery_heart,              /*modelID*/ MODEL_HEART
macro_obj_preset macro_1up_sliding,                 /*beh*/ beh_1up_sliding,                 /*modelID*/ MODEL_1UP
macro_obj_preset macro_1up,                         /*beh*/ beh_1up,                         /*modelID*/ MODEL_1UP,             /*behParam*/ 0
macro_obj_preset macro_1up_jump_on_approach,        /*beh*/ beh_1up_jump_on_approach,        /*modelID*/ MODEL_1UP              # unused
macro_obj_preset macro_hidden_1up,                  /*beh*/ beh_hidden_1up,                  /*modelID*/ MODEL_1UP
macro_obj_preset macro_hidden_1up_trigger,          /*beh*/ beh_hidden_1up_trigger,          /*modelID*/ MODEL_NONE
macro_obj_preset macro_1up_2,                       /*beh*/ beh_1up,                         /*modelID*/ MODEL_1UP,             /*behParam*/ 1
macro_obj_preset macro_1up_3,                       /*beh*/ beh_1up,                         /*modelID*/ MODEL_1UP,             /*behParam*/ 2
blank_preset macro_empty_52
macro_obj_preset macro_blue_coin_switch,            /*beh*/ beh_blue_coin_switch,            /*modelID*/ MODEL_BLUE_COIN_SWITCH
macro_obj_preset macro_hidden_blue_coin,            /*beh*/ beh_hidden_blue_coin,            /*modelID*/ MODEL_BLUE_COIN
macro_obj_preset macro_wing_cap_switch,             /*beh*/ beh_cap_switch,                  /*modelID*/ MODEL_CAP_SWITCH,      /*behParam*/ 0 # unused
macro_obj_preset macro_metal_cap_switch,            /*beh*/ beh_cap_switch,                  /*modelID*/ MODEL_CAP_SWITCH,      /*behParam*/ 1 # unused
macro_obj_preset macro_vanish_cap_switch,           /*beh*/ beh_cap_switch,                  /*modelID*/ MODEL_CAP_SWITCH,      /*behParam*/ 2 # unused
macro_obj_preset macro_yellow_cap_switch,           /*beh*/ beh_cap_switch,                  /*modelID*/ MODEL_CAP_SWITCH,      /*behParam*/ 3 # unused
macro_obj_preset macro_unknown_59,                  /*beh*/ beh_water_level_diamond,         /*modelID*/ MODEL_BREAKABLE_BOX    # unused
macro_obj_preset macro_box_wing_cap,                /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 0
macro_obj_preset macro_box_metal_cap,               /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 1
macro_obj_preset macro_box_vanish_cap,              /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 2
macro_obj_preset macro_box_koopa_shell,             /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 3
macro_obj_preset macro_box_one_coin,                /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 4 # unused
macro_obj_preset macro_box_three_coins,             /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 5
macro_obj_preset macro_box_ten_coins,               /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 6
macro_obj_preset macro_box_1up,                     /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 7
macro_obj_preset macro_box_star_1,                  /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 8
macro_obj_preset macro_breakable_box_no_coins,      /*beh*/ beh_breakable_box,               /*modelID*/ MODEL_BREAKABLE_BOX,   /*behParam*/ 0
macro_obj_preset macro_breakable_box_three_coins,   /*beh*/ beh_breakable_box,               /*modelID*/ MODEL_BREAKABLE_BOX,   /*behParam*/ 1
macro_obj_preset macro_pushable_metal_box,          /*beh*/ beh_pushable_metal_box,          /*modelID*/ MODEL_METAL_BOX
macro_obj_preset macro_breakable_box_small,         /*beh*/ beh_breakable_box_small,         /*modelID*/ MODEL_BREAKABLE_BOX_SMALL
macro_obj_preset macro_floor_switch_hidden_objects, /*beh*/ beh_floor_switch_hidden_objects, /*modelID*/ MODEL_PURPLE_SWITCH
macro_obj_preset macro_hidden_box,                  /*beh*/ beh_hidden_object,               /*modelID*/ MODEL_BREAKABLE_BOX,   /*behParam*/ 0
macro_obj_preset macro_hidden_object_2,             /*beh*/ beh_hidden_object,               /*modelID*/ MODEL_BREAKABLE_BOX,   /*behParam*/ 1 # unused
macro_obj_preset macro_hidden_object_3,             /*beh*/ beh_hidden_object,               /*modelID*/ MODEL_BREAKABLE_BOX,   /*behParam*/ 2 # unused
macro_obj_preset macro_breakable_box_giant,         /*beh*/ beh_breakable_box,               /*modelID*/ MODEL_BREAKABLE_BOX,   /*behParam*/ 3
macro_obj_preset macro_koopa_shell_underwater,      /*beh*/ beh_koopa_shell_underwater,      /*modelID*/ MODEL_KOOPA_SHELL
macro_obj_preset macro_box_1up_running_away,        /*beh*/ beh_exclamation_box,             /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 9
blank_preset macro_empty_80
macro_obj_preset macro_bullet_bill_cannon,          /*beh*/ beh_bullet_bill,                 /*modelID*/ MODEL_BULLET_BILL      # unused
macro_obj_preset macro_heave_ho,                    /*beh*/ beh_heave_ho,                    /*modelID*/ MODEL_HEAVE_HO
blank_preset macro_empty_83
macro_obj_preset macro_thwomp,                      /*beh*/ beh_thwomp_2,                    /*modelID*/ MODEL_THWOMP           # unused
macro_obj_preset macro_fire_spitter,                /*beh*/ bFireSpitter,                    /*modelID*/ MODEL_BOWLING_BALL
macro_obj_preset macro_fire_fly_guy,                /*beh*/ bFlyGuy,                         /*modelID*/ MODEL_FLYGUY,          /*behParam*/ 1
macro_obj_preset macro_jumping_box,                 /*beh*/ beh_jumping_box,                 /*modelID*/ MODEL_BREAKABLE_BOX
macro_obj_preset macro_butterfly_triplet,           /*beh*/ bTripletButterfly,               /*modelID*/ MODEL_BUTTERFLY,       /*behParam*/ 0
macro_obj_preset macro_butterfly_triplet_2,         /*beh*/ bTripletButterfly,               /*modelID*/ MODEL_BUTTERFLY,       /*behParam*/ 4
blank_preset macro_empty_90
blank_preset macro_empty_91
blank_preset macro_empty_92
macro_obj_preset macro_bully,             /*beh*/ beh_small_bully,       /*modelID*/ MODEL_BULLY
macro_obj_preset macro_bully_2,           /*beh*/ beh_small_bully,       /*modelID*/ MODEL_BULLY_BOSS       # unused
blank_preset macro_empty_95
macro_obj_preset macro_unknown_96,        /*beh*/ beh_stub_1D0C,         /*modelID*/ 0x0058 # unknown model # unused
macro_obj_preset macro_bouncing_fireball, /*beh*/ beh_bouncing_fireball, /*modelID*/ MODEL_NONE
macro_obj_preset macro_flamethrower,      /*beh*/ beh_flamethrower,      /*modelID*/ MODEL_NONE,            /*behParam*/ 4
blank_preset macro_empty_99
blank_preset macro_empty_100
blank_preset macro_empty_101
blank_preset macro_empty_102
blank_preset macro_empty_103
blank_preset macro_empty_104
blank_preset macro_empty_105
macro_obj_preset macro_wooden_post,                    /*beh*/ bWoodenPost,                   /*modelID*/ MODEL_WOODEN_POST
macro_obj_preset macro_water_bomb_spawner,             /*beh*/ bWaterBombSpawner,             /*modelID*/ MODEL_NONE
macro_obj_preset macro_enemy_lakitu,                   /*beh*/ bEnemyLakitu,                  /*modelID*/ MODEL_ENEMY_LAKITU
macro_obj_preset macro_bob_koopa_the_quick,            /*beh*/ bKoopa,                        /*modelID*/ MODEL_KOOPA_WITH_SHELL, /*behParam*/ 2 # unused
macro_obj_preset macro_koopa_race_endpoint,            /*beh*/ bKoopaRaceEndpoint,            /*modelID*/ MODEL_NONE              # unused
macro_obj_preset macro_bobomb,                         /*beh*/ beh_bobomb,                    /*modelID*/ MODEL_BLACK_BOBOMB,     /*behParam*/ 0
macro_obj_preset macro_water_bomb_cannon_copy,         /*beh*/ beh_water_bomb_cannon,         /*modelID*/ MODEL_CANNON_BASE       # unused
macro_obj_preset macro_bobomb_buddy_opens_cannon_copy, /*beh*/ beh_bobomb_buddy_opens_cannon, /*modelID*/ MODEL_BOBOMB_BUDDY      # unused
macro_obj_preset macro_water_bomb_cannon,              /*beh*/ beh_water_bomb_cannon,         /*modelID*/ MODEL_CANNON_BASE
macro_obj_preset macro_bobomb_still,                   /*beh*/ beh_bobomb,                    /*modelID*/ MODEL_BLACK_BOBOMB,     /*behParam*/ 1
blank_preset macro_empty_116
blank_preset macro_empty_117
blank_preset macro_empty_118
blank_preset macro_empty_119
blank_preset macro_empty_120
blank_preset macro_empty_121
blank_preset macro_empty_122
macro_obj_preset macro_unknown_123, /*beh*/ beh_unused_fake_star, /*modelID*/ 0x0054 # unknown model # unused
blank_preset macro_empty_124
macro_obj_preset macro_unagi,       /*beh*/ beh_unagi,            /*modelID*/ MODEL_UNAGI            # unused
macro_obj_preset macro_sushi,       /*beh*/ beh_sushi_shark,      /*modelID*/ MODEL_SUSHI            # unused
blank_preset macro_empty_127
blank_preset macro_empty_128
blank_preset macro_empty_129
blank_preset macro_empty_130
blank_preset macro_empty_131
blank_preset macro_empty_132
blank_preset macro_empty_133
blank_preset macro_empty_134
blank_preset macro_empty_135
blank_preset macro_empty_136
macro_obj_preset macro_unknown_137, /*beh*/ beh_static_object, /*modelID*/ MODEL_KLEPTO      # unused
macro_obj_preset macro_tornado,     /*beh*/ beh_tornado,       /*modelID*/ MODEL_TORNADO     # unused
macro_obj_preset macro_pokey,       /*beh*/ bPokey,            /*modelID*/ MODEL_NONE
macro_obj_preset macro_pokey_copy,  /*beh*/ bPokey,            /*modelID*/ MODEL_NONE        # unused
macro_obj_preset macro_tox_box,     /*beh*/ beh_tox_box,       /*modelID*/ MODEL_SSL_TOX_BOX # unused
blank_preset macro_empty_142
blank_preset macro_empty_143
blank_preset macro_empty_144
blank_preset macro_empty_145
blank_preset macro_empty_146
blank_preset macro_empty_147
blank_preset macro_empty_148
blank_preset macro_empty_149
blank_preset macro_empty_150
macro_obj_preset macro_monty_mole_2,    /*beh*/ bMontyMole,     /*modelID*/ MODEL_MONTY_MOLE, /*behParam*/ 0 # unused
macro_obj_preset macro_monty_mole,      /*beh*/ bMontyMole,     /*modelID*/ MODEL_MONTY_MOLE, /*behParam*/ 1
macro_obj_preset macro_monty_mole_hole, /*beh*/ bMontyMoleHole, /*modelID*/ MODEL_DL_MONTY_MOLE_HOLE
macro_obj_preset macro_fly_guy,         /*beh*/ bFlyGuy,        /*modelID*/ MODEL_FLYGUY,     /*behParam*/ 0
blank_preset macro_empty_155
macro_obj_preset macro_wiggler,         /*beh*/ bWiggler,       /*modelID*/ MODEL_WIGGLER     # unused
blank_preset macro_empty_157
blank_preset macro_empty_158
blank_preset macro_empty_159
blank_preset macro_empty_160
blank_preset macro_empty_161
blank_preset macro_empty_162
blank_preset macro_empty_163
blank_preset macro_empty_164
macro_obj_preset macro_spindrift,          /*beh*/ beh_spindrift,     /*modelID*/ MODEL_SPINDRIFT
macro_obj_preset macro_mr_blizzard,        /*beh*/ bMrBlizzard,       /*modelID*/ MODEL_MR_BLIZZARD_HIDDEN, /*behParam*/ 0
macro_obj_preset macro_mr_blizzard_copy,   /*beh*/ bMrBlizzard,       /*modelID*/ MODEL_MR_BLIZZARD_HIDDEN, /*behParam*/ 0 # unused
blank_preset macro_empty_168
macro_obj_preset macro_small_penguin,      /*beh*/ beh_small_penguin, /*modelID*/ MODEL_PENGUIN             # unused
macro_obj_preset macro_tuxies_mother,      /*beh*/ beh_tuxies_mother, /*modelID*/ MODEL_PENGUIN             # unused
macro_obj_preset macro_tuxies_mother_copy, /*beh*/ beh_tuxies_mother, /*modelID*/ MODEL_PENGUIN             # unused
macro_obj_preset macro_mr_blizzard_2,      /*beh*/ bMrBlizzard,       /*modelID*/ MODEL_MR_BLIZZARD_HIDDEN, /*behParam*/ 1 # unused
blank_preset macro_empty_173
blank_preset macro_empty_174
blank_preset macro_empty_175
blank_preset macro_empty_176
blank_preset macro_empty_177
blank_preset macro_empty_178
blank_preset macro_empty_179
blank_preset macro_empty_180
blank_preset macro_empty_181
blank_preset macro_empty_182
blank_preset macro_empty_183
blank_preset macro_empty_184
blank_preset macro_empty_185
blank_preset macro_empty_186
blank_preset macro_empty_187
blank_preset macro_empty_188
macro_obj_preset macro_haunted_chair_copy,  /*beh*/ beh_haunted_chair,        /*modelID*/ MODEL_HAUNTED_CHAIR # unused
macro_obj_preset macro_haunted_chair,       /*beh*/ beh_haunted_chair,        /*modelID*/ MODEL_HAUNTED_CHAIR
macro_obj_preset macro_haunted_chair_copy2, /*beh*/ beh_haunted_chair,        /*modelID*/ MODEL_HAUNTED_CHAIR # unused
macro_obj_preset macro_boo,                 /*beh*/ beh_boo_2,                /*modelID*/ MODEL_BOO           # unused
macro_obj_preset macro_boo_copy,            /*beh*/ beh_boo_2,                /*modelID*/ MODEL_BOO           # unused
macro_obj_preset macro_boo_group,           /*beh*/ beh_boo_group,            /*modelID*/ MODEL_BOO           # unused
macro_obj_preset macro_boo_with_cage,       /*beh*/ beh_boo_with_cage,        /*modelID*/ MODEL_BOO           # unused
macro_obj_preset macro_beta_key,            /*beh*/ beh_beta_boo_key_outside, /*modelID*/ MODEL_SMALL_KEY     # unused
blank_preset macro_empty_197
blank_preset macro_empty_198
blank_preset macro_empty_199
blank_preset macro_empty_200
blank_preset macro_empty_201
blank_preset macro_empty_202
blank_preset macro_empty_203
blank_preset macro_empty_204
blank_preset macro_empty_205
blank_preset macro_empty_206
blank_preset macro_empty_207
blank_preset macro_empty_208
blank_preset macro_empty_209
blank_preset macro_empty_210
blank_preset macro_empty_211
blank_preset macro_empty_212
blank_preset macro_empty_213
blank_preset macro_empty_214
blank_preset macro_empty_215
blank_preset macro_empty_216
blank_preset macro_empty_217
blank_preset macro_empty_218
blank_preset macro_empty_219
blank_preset macro_empty_220
blank_preset macro_empty_221
blank_preset macro_empty_222
blank_preset macro_empty_223
blank_preset macro_empty_224
blank_preset macro_empty_225
blank_preset macro_empty_226
blank_preset macro_empty_227
blank_preset macro_empty_228
blank_preset macro_empty_229
blank_preset macro_empty_230
blank_preset macro_empty_231
blank_preset macro_empty_232
blank_preset macro_empty_233
macro_obj_preset macro_chirp_chirp,                  /*beh*/ beh_chirp_chirp,             /*modelID*/ MODEL_NONE                 # unknown
macro_obj_preset macro_seaweed_bundle,               /*beh*/ beh_seaweed_bundle,          /*modelID*/ MODEL_NONE
macro_obj_preset macro_beta_chest,                   /*beh*/ beh_beta_chest,              /*modelID*/ MODEL_TREASURE_CHEST_BASE  # unused
macro_obj_preset macro_water_mine,                   /*beh*/ beh_bowser_bomb,             /*modelID*/ MODEL_WATER_MINE           # unused
macro_obj_preset macro_fish_group_4,                 /*beh*/ beh_large_fish_group,        /*modelID*/ MODEL_NONE, /*behParam*/ 2 # unused
macro_obj_preset macro_fish_group_2,                 /*beh*/ beh_large_fish_group,        /*modelID*/ MODEL_NONE, /*behParam*/ 3
macro_obj_preset macro_jet_stream_ring_spawner,      /*beh*/ beh_jet_stream_ring_spawner, /*modelID*/ MODEL_WATER_RING           # unused
macro_obj_preset macro_jet_stream_ring_spawner_copy, /*beh*/ beh_jet_stream_ring_spawner, /*modelID*/ MODEL_WATER_RING           # unused
macro_obj_preset macro_skeeter,                      /*beh*/ bSkeeter,                    /*modelID*/ MODEL_SKEETER
macro_obj_preset macro_clam_shell,                   /*beh*/ beh_clam_shell,              /*modelID*/ MODEL_CLAM_SHELL
blank_preset macro_empty_244
blank_preset macro_empty_245
blank_preset macro_empty_246
blank_preset macro_empty_247
blank_preset macro_empty_248
blank_preset macro_empty_249
blank_preset macro_empty_250
macro_obj_preset macro_ukiki,                /*beh*/ beh_ukiki_open_cage, /*modelID*/ MODEL_UKIKI, /*behParam*/ 0 # unused
macro_obj_preset macro_ukiki_2,              /*beh*/ beh_ukiki_open_cage, /*modelID*/ MODEL_UKIKI, /*behParam*/ 1 # unused
macro_obj_preset macro_piranha_plant,        /*beh*/ beh_piranha_plant_2, /*modelID*/ MODEL_PIRANHA_PLANT         # unused
blank_preset macro_empty_254
macro_obj_preset macro_whomp,                /*beh*/ beh_small_whomp,     /*modelID*/ MODEL_WHOMP
macro_obj_preset macro_chain_chomp,          /*beh*/ bChainChomp,         /*modelID*/ MODEL_CHAIN_CHOMP
blank_preset macro_empty_257
macro_obj_preset macro_koopa,                /*beh*/ bKoopa,              /*modelID*/ MODEL_KOOPA_WITH_SHELL,     /*behParam*/ 1
macro_obj_preset macro_koopa_shellless,      /*beh*/ bKoopa,              /*modelID*/ MODEL_KOOPA_WITHOUT_SHELL,  /*behParam*/ 0 # unused
macro_obj_preset macro_wooden_post_copy,     /*beh*/ bWoodenPost,         /*modelID*/ MODEL_WOODEN_POST           # unused
macro_obj_preset macro_fire_piranha_plant,   /*beh*/ bFirePiranhaPlant,   /*modelID*/ MODEL_PIRANHA_PLANT,        /*behParam*/ 0
macro_obj_preset macro_fire_piranha_plant_2, /*beh*/ bFirePiranhaPlant,   /*modelID*/ MODEL_PIRANHA_PLANT,        /*behParam*/ 1 # unused
macro_obj_preset macro_thi_koopa_the_quick,  /*beh*/ bKoopa,              /*modelID*/ MODEL_KOOPA_WITH_SHELL,     /*behParam*/ 4
blank_preset macro_empty_264
blank_preset macro_empty_265
blank_preset macro_empty_266
blank_preset macro_empty_267
blank_preset macro_empty_268
blank_preset macro_empty_269
blank_preset macro_empty_270
blank_preset macro_empty_271
blank_preset macro_empty_272
blank_preset macro_empty_273
blank_preset macro_empty_274
blank_preset macro_empty_275
blank_preset macro_empty_276
blank_preset macro_empty_277
blank_preset macro_empty_278
blank_preset macro_empty_279
blank_preset macro_empty_280
macro_obj_preset macro_moneybag, /*beh*/ beh_moneybag_hidden, /*modelID*/ MODEL_YELLOW_COIN
blank_preset macro_empty_282
blank_preset macro_empty_283
blank_preset macro_empty_284
blank_preset macro_empty_285
blank_preset macro_empty_286
blank_preset macro_empty_287
blank_preset macro_empty_288
macro_obj_preset macro_swoop,              /*beh*/ bSwoop,               /*modelID*/ MODEL_SWOOP, /*behParam*/ 0
macro_obj_preset macro_swoop_2,            /*beh*/ bSwoop,               /*modelID*/ MODEL_SWOOP, /*behParam*/ 1
macro_obj_preset macro_mr_i,               /*beh*/ beh_mr_i,             /*modelID*/ MODEL_NONE
macro_obj_preset macro_scuttlebug_spawner, /*beh*/ beh_scuttlebug_spawn, /*modelID*/ MODEL_NONE
macro_obj_preset macro_scuttlebug,         /*beh*/ beh_scuttlebug,       /*modelID*/ MODEL_SCUTTLEBUG
blank_preset macro_empty_294
blank_preset macro_empty_295
blank_preset macro_empty_296
blank_preset macro_empty_297
blank_preset macro_empty_298
blank_preset macro_empty_299
blank_preset macro_empty_300
blank_preset macro_empty_301
blank_preset macro_empty_302
macro_obj_preset macro_unknown_303, /*beh*/ beh_yellow_coin, /*modelID*/ 0x0054 # unknown model # unused
blank_preset macro_empty_304
blank_preset macro_empty_305
blank_preset macro_empty_306
blank_preset macro_empty_307
blank_preset macro_empty_308
blank_preset macro_empty_309
blank_preset macro_empty_310
blank_preset macro_empty_311
blank_preset macro_empty_312
macro_obj_preset macro_ttc_rotating_cube,     /*beh*/ bTTCRotatingSolid, /*modelID*/ MODEL_TTC_ROTATING_CUBE,     /*behParam*/ 0
macro_obj_preset macro_ttc_rotating_prism,    /*beh*/ bTTCRotatingSolid, /*modelID*/ MODEL_TTC_ROTATING_PRISM,    /*behParam*/ 1
macro_obj_preset macro_ttc_pendulum,          /*beh*/ bTTCPendulum,      /*modelID*/ MODEL_TTC_PENDULUM
macro_obj_preset macro_ttc_large_treadmill,   /*beh*/ bTTCTreadmill,     /*modelID*/ MODEL_TTC_LARGE_TREADMILL,   /*behParam*/ 0
macro_obj_preset macro_ttc_small_treadmill,   /*beh*/ bTTCTreadmill,     /*modelID*/ MODEL_TTC_SMALL_TREADMILL,   /*behParam*/ 1
macro_obj_preset macro_ttc_push_block,        /*beh*/ bTTCMovingBar,     /*modelID*/ MODEL_TTC_PUSH_BLOCK
macro_obj_preset macro_ttc_rotating_hexagon,  /*beh*/ bTTCCog,           /*modelID*/ MODEL_TTC_ROTATING_HEXAGON,  /*behParam*/ 0
macro_obj_preset macro_ttc_rotating_triangle, /*beh*/ bTTCCog,           /*modelID*/ MODEL_TTC_ROTATING_TRIANGLE, /*behParam*/ 2
macro_obj_preset macro_ttc_pit_block,         /*beh*/ bTTCPitBlock,      /*modelID*/ MODEL_TTC_PIT_BLOCK,         /*behParam*/ 0
macro_obj_preset macro_ttc_pit_block_2,       /*beh*/ bTTCPitBlock,      /*modelID*/ MODEL_TTC_PIT_BLOCK_2,       /*behParam*/ 1 # unused
macro_obj_preset macro_ttc_elevator_platform, /*beh*/ bTTCElevator,      /*modelID*/ MODEL_TTC_ELEVATOR_PLATFORM
macro_obj_preset macro_ttc_clock_hand,        /*beh*/ bTTC2DRotator,     /*modelID*/ MODEL_TTC_CLOCK_HAND,        /*behParam*/ 0
macro_obj_preset macro_ttc_spinner,           /*beh*/ bTTCSpinner,       /*modelID*/ MODEL_TTC_SPINNER
macro_obj_preset macro_ttc_small_gear,        /*beh*/ bTTC2DRotator,     /*modelID*/ MODEL_TTC_SMALL_GEAR,        /*behParam*/ 1
macro_obj_preset macro_ttc_large_gear,        /*beh*/ bTTC2DRotator,     /*modelID*/ MODEL_TTC_LARGE_GEAR,        /*behParam*/ 1
macro_obj_preset macro_ttc_large_treadmill_2, /*beh*/ bTTCTreadmill,     /*modelID*/ MODEL_TTC_LARGE_TREADMILL,   /*behParam*/ 2
macro_obj_preset macro_ttc_small_treadmill_2, /*beh*/ bTTCTreadmill,     /*modelID*/ MODEL_TTC_SMALL_TREADMILL,   /*behParam*/ 3
blank_preset macro_empty_330
blank_preset macro_empty_331
blank_preset macro_empty_332
blank_preset macro_empty_333
blank_preset macro_empty_334
blank_preset macro_empty_335
blank_preset macro_empty_336
blank_preset macro_empty_337
blank_preset macro_empty_338
macro_obj_preset macro_box_star_2, /*beh*/ beh_exclamation_box, /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 10
macro_obj_preset macro_box_star_3, /*beh*/ beh_exclamation_box, /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 11
macro_obj_preset macro_box_star_4, /*beh*/ beh_exclamation_box, /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 12
macro_obj_preset macro_box_star_5, /*beh*/ beh_exclamation_box, /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 13 # unused
macro_obj_preset macro_box_star_6, /*beh*/ beh_exclamation_box, /*modelID*/ MODEL_EXCLAMATION_BOX, /*behParam*/ 14
blank_preset macro_empty_344
blank_preset macro_empty_345
blank_preset macro_empty_346
blank_preset macro_empty_347
blank_preset macro_empty_348
blank_preset macro_empty_349
macro_obj_preset macro_bits_sliding_platform,       /*beh*/ beh_sliding_platform2,              /*modelID*/ MODEL_BITS_SLIDING_PLATFORM       # unused
macro_obj_preset macro_bits_twin_sliding_platforms, /*beh*/ beh_sliding_platform2,              /*modelID*/ MODEL_BITS_TWIN_SLIDING_PLATFORMS # unused
macro_obj_preset macro_bits_unknown_352,            /*beh*/ beh_another_tilting_platform,       /*modelID*/ 0x0038 # unknown model            # unused
macro_obj_preset macro_bits_octagonal_platform,     /*beh*/ beh_octagonal_platform_rotating,    /*modelID*/ MODEL_BITS_OCTAGONAL_PLATFORM     # unused
macro_obj_preset macro_bits_staircase,              /*beh*/ beh_animates_on_floor_switch_press, /*modelID*/ MODEL_BITS_STAIRCASE              # unused
blank_preset macro_empty_355
blank_preset macro_empty_356
macro_obj_preset macro_bits_ferris_wheel_axle,      /*beh*/ bFerrisWheelAxle,                   /*modelID*/ MODEL_BITS_FERRIS_WHEEL_AXLE      # unused
macro_obj_preset macro_bits_arrow_platform,         /*beh*/ bActivatedBackAndForthPlatform,     /*modelID*/ MODEL_BITS_ARROW_PLATFORM         # unused
macro_obj_preset macro_bits_seesaw_platform,        /*beh*/ bSeesawPlatform,                    /*modelID*/ MODEL_BITS_SEESAW_PLATFORM        # unused
macro_obj_preset macro_bits_tilting_w_platform,     /*beh*/ bSeesawPlatform,                    /*modelID*/ MODEL_BITS_TILTING_W_PLATFORM     # unused
blank_preset macro_empty_361
blank_preset macro_empty_362
blank_preset macro_empty_363
blank_preset macro_empty_364
blank_preset macro_empty_365
