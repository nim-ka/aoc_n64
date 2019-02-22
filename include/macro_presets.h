#ifndef _GUARD_MACRO_PRESETS_H
#define _GUARD_MACRO_PRESETS_H

#include "macro_preset_names.h"
#include "behavior_data.h"
#include "model_ids.h"

#define MACRO_OBJ_PRESET(name, beh, model, bparam) \
    {\name, beh, model, bparam}

struct MacroPreset
{
    /*0x00*/ u32 *beh;
    /*0x04*/ s16 model;
    /*0x06*/ s16 param;
};

struct MacroPreset MacroObjectPresets[] = {
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_one_coin, MODEL_YELLOW_COIN, 0},
    {beh_moving_blue_coin, MODEL_BLUE_COIN, 0},
    {beh_blue_coin_sliding, MODEL_BLUE_COIN, 0}, // unused
    {beh_red_coin, MODEL_RED_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_coin_formation, MODEL_NONE, 0},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_RING},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_ARROW},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_FLYING},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING | COIN_FORMATION_FLAG_VERTICAL},
    {beh_coin_formation, MODEL_NONE, COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_ARROW}, // unused
    {beh_hidden_star_trigger, MODEL_NONE, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_unused_fake_star, MODEL_STAR, 0}, // unused
    {beh_message_panel, MODEL_WOODEN_SIGNPOST, 0},
    {beh_cannon_closed, MODEL_DL_CANNON_LID, 0},
    {beh_bobomb_buddy_opens_cannon, MODEL_BOBOMB_BUDDY, 0},
    {beh_butterfly, MODEL_BUTTERFLY, 0}, // unused
    {beh_bouncing_fireball, MODEL_NONE, 0}, // unused
    {beh_large_fish_group, MODEL_NONE, 0}, // unused
    {beh_large_fish_group, MODEL_NONE, 1},
    {beh_multiple_coins, MODEL_NONE, 0}, // unused
    {beh_hidden_1up_in_pole_spawner, MODEL_NONE, 0},
    {bGoomba, MODEL_GOOMBA, 1},
    {bGoomba, MODEL_GOOMBA, 2},
    {bGoombaTripletSpawner, MODEL_NONE, 0},
    {bGoombaTripletSpawner, MODEL_NONE, 8}, // unused
    {beh_sign_on_wall, MODEL_NONE, 0},
    {beh_chuckya, MODEL_CHUCKYA, 0},
    {beh_cannon, MODEL_CANNON_BASE, 0},
    {bGoomba, MODEL_GOOMBA, 0},
    {beh_amp_homing, MODEL_AMP, 0},
    {beh_amp_circling, MODEL_AMP, 0},
    {beh_carry_something1, 0x007D, 0}, // unused
    {beh_beta_trampoline, 0x00B5, 0}, // unused
    {beh_free_bowling_ball, MODEL_BOWLING_BALL, 0}, // unused
    {beh_snufit, MODEL_SNUFIT, 0},
    {beh_recovery_heart, MODEL_HEART, 0},
    {beh_1up_sliding, MODEL_1UP, 0},
    {beh_1up, MODEL_1UP, 0},
    {beh_1up_jump_on_approach, MODEL_1UP, 0}, // unused
    {beh_hidden_1up, MODEL_1UP, 0},
    {beh_hidden_1up_trigger, MODEL_NONE, 0},
    {beh_1up, MODEL_1UP, 1},
    {beh_1up, MODEL_1UP, 2},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_blue_coin_switch, MODEL_BLUE_COIN_SWITCH, 0},
    {beh_hidden_blue_coin, MODEL_BLUE_COIN, 0},
    {beh_cap_switch, MODEL_CAP_SWITCH, 0}, // unused
    {beh_cap_switch, MODEL_CAP_SWITCH, 1}, // unused
    {beh_cap_switch, MODEL_CAP_SWITCH, 2}, // unused
    {beh_cap_switch, MODEL_CAP_SWITCH, 3}, // unused
    {beh_water_level_diamond, MODEL_BREAKABLE_BOX, 0}, // unused
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 0},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 1},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 2},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 3},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 4}, // unused
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 5},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 6},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 7},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 8},
    {beh_breakable_box, MODEL_BREAKABLE_BOX, 0},
    {beh_breakable_box, MODEL_BREAKABLE_BOX, 1},
    {beh_pushable_metal_box, MODEL_METAL_BOX, 0},
    {beh_breakable_box_small, MODEL_BREAKABLE_BOX_SMALL, 0},
    {beh_floor_switch_hidden_objects, MODEL_PURPLE_SWITCH, 0},
    {beh_hidden_object, MODEL_BREAKABLE_BOX, 0},
    {beh_hidden_object, MODEL_BREAKABLE_BOX, 1}, // unused
    {beh_hidden_object, MODEL_BREAKABLE_BOX, 2}, // unused
    {beh_breakable_box, MODEL_BREAKABLE_BOX, 3},
    {beh_koopa_shell_underwater, MODEL_KOOPA_SHELL, 0},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 9},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_bullet_bill, MODEL_BULLET_BILL, 0}, // unused
    {beh_heave_ho, MODEL_HEAVE_HO, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_thwomp_2, MODEL_THWOMP, 0}, // unused
    {bFireSpitter, MODEL_BOWLING_BALL, 0},
    {bFlyGuy, MODEL_FLYGUY, 1},
    {beh_jumping_box, MODEL_BREAKABLE_BOX, 0},
    {bTripletButterfly, MODEL_BUTTERFLY, 0},
    {bTripletButterfly, MODEL_BUTTERFLY, 4},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_small_bully, MODEL_BULLY, 0},
    {beh_small_bully, MODEL_BULLY_BOSS, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_stub_1D0C, 0x0058, 0}, // unused
    {beh_bouncing_fireball, MODEL_NONE, 0},
    {beh_flamethrower, MODEL_NONE, 4},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bWoodenPost, MODEL_WOODEN_POST, 0},
    {bWaterBombSpawner, MODEL_NONE, 0},
    {bEnemyLakitu, MODEL_ENEMY_LAKITU, 0},
    {bKoopa, MODEL_KOOPA_WITH_SHELL, 2}, // unused
    {bKoopaRaceEndpoint, MODEL_NONE, 0}, // unused
    {beh_bobomb, MODEL_BLACK_BOBOMB, 0},
    {beh_water_bomb_cannon, MODEL_CANNON_BASE, 0}, // unused
    {beh_bobomb_buddy_opens_cannon, MODEL_BOBOMB_BUDDY, 0}, // unused
    {beh_water_bomb_cannon, MODEL_CANNON_BASE, 0},
    {beh_bobomb, MODEL_BLACK_BOBOMB, 1},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_unused_fake_star, 0x0054, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_unagi, MODEL_UNAGI, 0}, // unused
    {beh_sushi_shark, MODEL_SUSHI, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_static_object, MODEL_KLEPTO, 0}, // unused
    {beh_tornado, MODEL_TORNADO, 0}, // unused
    {bPokey, MODEL_NONE, 0},
    {bPokey, MODEL_NONE, 0}, // unused
    {beh_tox_box, MODEL_SSL_TOX_BOX, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bMontyMole, MODEL_MONTY_MOLE, 0}, // unused
    {bMontyMole, MODEL_MONTY_MOLE, 1},
    {bMontyMoleHole, MODEL_DL_MONTY_MOLE_HOLE, 0},
    {bFlyGuy, MODEL_FLYGUY, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bWiggler, MODEL_WIGGLER, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_spindrift, MODEL_SPINDRIFT, 0},
    {bMrBlizzard, MODEL_MR_BLIZZARD_HIDDEN, 0},
    {bMrBlizzard, MODEL_MR_BLIZZARD_HIDDEN, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_small_penguin, MODEL_PENGUIN, 0}, // unused
    {beh_tuxies_mother, MODEL_PENGUIN, 0}, // unused
    {beh_tuxies_mother, MODEL_PENGUIN, 0}, // unused
    {bMrBlizzard, MODEL_MR_BLIZZARD_HIDDEN, 1}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_haunted_chair, MODEL_HAUNTED_CHAIR, 0}, // unused
    {beh_haunted_chair, MODEL_HAUNTED_CHAIR, 0},
    {beh_haunted_chair, MODEL_HAUNTED_CHAIR, 0}, // unused
    {beh_boo_2, MODEL_BOO, 0}, // unused
    {beh_boo_2, MODEL_BOO, 0}, // unused
    {beh_boo_group, MODEL_BOO, 0}, // unused
    {beh_boo_with_cage, MODEL_BOO, 0}, // unused
    {beh_beta_boo_key_outside, MODEL_SMALL_KEY, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_chirp_chirp, MODEL_NONE, 0},
    {beh_seaweed_bundle, MODEL_NONE, 0},
    {beh_beta_chest, MODEL_TREASURE_CHEST_BASE, 0}, // unused
    {beh_bowser_bomb, MODEL_WATER_MINE, 0}, // unused
    {beh_large_fish_group, MODEL_NONE, 2}, // unused
    {beh_large_fish_group, MODEL_NONE, 3},
    {beh_jet_stream_ring_spawner, MODEL_WATER_RING, 0}, // unused
    {beh_jet_stream_ring_spawner, MODEL_WATER_RING, 0}, // unused
    {bSkeeter, MODEL_SKEETER, 0},
    {beh_clam_shell, MODEL_CLAM_SHELL, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_ukiki_open_cage, MODEL_UKIKI, 0}, // unused
    {beh_ukiki_open_cage, MODEL_UKIKI, 1}, // unused
    {beh_piranha_plant_2, MODEL_PIRANHA_PLANT, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_small_whomp, MODEL_WHOMP, 0},
    {bChainChomp, MODEL_CHAIN_CHOMP, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bKoopa, MODEL_KOOPA_WITH_SHELL, 1},
    {bKoopa, MODEL_KOOPA_WITHOUT_SHELL, 0}, // unused
    {bWoodenPost, MODEL_WOODEN_POST, 0}, // unused
    {bFirePiranhaPlant, MODEL_PIRANHA_PLANT, 0},
    {bFirePiranhaPlant, MODEL_PIRANHA_PLANT, 1}, // unused
    {bKoopa, MODEL_KOOPA_WITH_SHELL, 4},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_moneybag_hidden, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bSwoop, MODEL_SWOOP, 0},
    {bSwoop, MODEL_SWOOP, 1},
    {beh_mr_i, MODEL_NONE, 0},
    {beh_scuttlebug_spawn, MODEL_NONE, 0},
    {beh_scuttlebug, MODEL_SCUTTLEBUG, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, 0x0054, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bTTCRotatingSolid, MODEL_TTC_ROTATING_CUBE, 0},
    {bTTCRotatingSolid, MODEL_TTC_ROTATING_PRISM, 1},
    {bTTCPendulum, MODEL_TTC_PENDULUM, 0},
    {bTTCTreadmill, MODEL_TTC_LARGE_TREADMILL, 0},
    {bTTCTreadmill, MODEL_TTC_SMALL_TREADMILL, 1},
    {bTTCMovingBar, MODEL_TTC_PUSH_BLOCK, 0},
    {bTTCCog, MODEL_TTC_ROTATING_HEXAGON, 0},
    {bTTCCog, MODEL_TTC_ROTATING_TRIANGLE, 2},
    {bTTCPitBlock, MODEL_TTC_PIT_BLOCK, 0},
    {bTTCPitBlock, MODEL_TTC_PIT_BLOCK_2, 1}, // unused
    {bTTCElevator, MODEL_TTC_ELEVATOR_PLATFORM, 0},
    {bTTC2DRotator, MODEL_TTC_CLOCK_HAND, 0},
    {bTTCSpinner, MODEL_TTC_SPINNER, 0},
    {bTTC2DRotator, MODEL_TTC_SMALL_GEAR, 1},
    {bTTC2DRotator, MODEL_TTC_LARGE_GEAR, 1},
    {bTTCTreadmill, MODEL_TTC_LARGE_TREADMILL, 2},
    {bTTCTreadmill, MODEL_TTC_SMALL_TREADMILL, 3},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 10},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 11},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 12},
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 13}, // unused
    {beh_exclamation_box, MODEL_EXCLAMATION_BOX, 14},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_sliding_platform2, MODEL_BITS_SLIDING_PLATFORM, 0}, // unused
    {beh_sliding_platform2, MODEL_BITS_TWIN_SLIDING_PLATFORMS, 0}, // unused
    {beh_another_tilting_platform, 0x0038, 0}, // unused
    {beh_octagonal_platform_rotating, MODEL_BITS_OCTAGONAL_PLATFORM, 0}, // unused
    {beh_animates_on_floor_switch_press, MODEL_BITS_STAIRCASE, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {bFerrisWheelAxle, MODEL_BITS_FERRIS_WHEEL_AXLE, 0}, // unused
    {bActivatedBackAndForthPlatform, MODEL_BITS_ARROW_PLATFORM, 0}, // unused
    {bSeesawPlatform, MODEL_BITS_SEESAW_PLATFORM, 0}, // unused
    {bSeesawPlatform, MODEL_BITS_TILTING_W_PLATFORM, 0}, // unused
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0},
    {beh_yellow_coin, MODEL_YELLOW_COIN, 0}
};

#endif // _GUARD_MACRO_PRESETS_H
