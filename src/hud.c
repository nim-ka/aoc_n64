#include <ultra64.h>

#include "sm64.h"
#include "object_helpers.h"
#include "hud.h"

#include "behavior_data.h"

/* First half of old "hud.s" file; 
 * It might not have anything to do with the HUD anymore, though
**/

static struct Struct803306D0 D_803306D0[] = 
{
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_one_coin,                    0x0074, 0x0000 }, 
    { &beh_moving_blue_coin,             0x0076, 0x0000 }, { &beh_blue_coin_sliding,           0x0076, 0x0000 }, 
    { &beh_red_coin,                     0x00D7, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_coin_formation,               0x0000, 0x0000 }, { &beh_coin_formation,              0x0000, 0x0002 }, 
    { &beh_coin_formation,               0x0000, 0x0004 }, { &beh_coin_formation,              0x0000, 0x0010 }, 
    { &beh_coin_formation,               0x0000, 0x0011 }, { &beh_coin_formation,              0x0000, 0x0012 }, 
    { &beh_coin_formation,               0x0000, 0x0013 }, { &beh_coin_formation,              0x0000, 0x0014 }, 
    { &beh_checkpoint,                   0x0000, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_star,                         0x007A, 0x0000 }, { &beh_message_panel,               0x007C, 0x0000 }, 
    { &beh_cannon_trap_door,             0x00C9, 0x0000 }, { &beh_bobomb_buddy_cannon_role,    0x00C3, 0x0000 }, 
    { &beh_butterfly,                    0x00BB, 0x0000 }, { &beh_bouncing_fireball,           0x0000, 0x0000 }, 
    { &beh_large_fish_group,             0x0000, 0x0000 }, { &beh_large_fish_group,            0x0000, 0x0001 }, 
    { &beh_multiple_coins,               0x0000, 0x0000 }, { &beh_1up_hidden_in_tree,          0x0000, 0x0000 }, 
    { &beh_goomba_walk,                  0x00C0, 0x0001 }, { &beh_goomba_walk,                 0x00C0, 0x0002 }, 
    { &beh_goombas_group,                0x0000, 0x0000 }, { &beh_goombas_group,               0x0000, 0x0008 }, 
    { &beh_sign_on_wall,                 0x0000, 0x0000 }, { &beh_chuckya,                     0x00DF, 0x0000 }, 
    { &beh_cannon_base,                  0x0080, 0x0000 }, { &beh_goomba_walk,                 0x00C0, 0x0000 }, 
    { &beh_amp_homing,                   0x00C2, 0x0000 }, { &beh_amp,                         0x00C2, 0x0000 }, 
    { &beh_carry_something1,             0x007D, 0x0000 }, { &beh_beta_trampoline,             0x00B5, 0x0000 }, 
    { &beh_rolling_metal_ball,           0x00B4, 0x0000 }, { &beh_snufit,                      0x00CE, 0x0000 }, 
    { &beh_recover_life,                 0x0078, 0x0000 }, { &beh_1up_sliding,                 0x00D4, 0x0000 }, 
    { &beh_1up,                          0x00D4, 0x0000 }, { &beh_1up_jump_on_approach,        0x00D4, 0x0000 }, 
    { &beh_1up_hidden,                   0x00D4, 0x0000 }, { &beh_1up_hidden_trigger,          0x0000, 0x0000 }, 
    { &beh_1up,                          0x00D4, 0x0001 }, { &beh_1up,                         0x00D4, 0x0002 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_blue_coin_switch,            0x008C, 0x0000 }, 
    { &beh_hidden_blue_coin,             0x0076, 0x0000 }, { &beh_activate_cap_switch,         0x0055, 0x0000 }, 
    { &beh_activate_cap_switch,          0x0055, 0x0001 }, { &beh_activate_cap_switch,         0x0055, 0x0002 }, 
    { &beh_activate_cap_switch,          0x0055, 0x0003 }, { &beh_water_level_trigger,         0x0081, 0x0000 }, 
    { &beh_exclamation_box,              0x0089, 0x0000 }, { &beh_exclamation_box,             0x0089, 0x0001 }, 
    { &beh_exclamation_box,              0x0089, 0x0002 }, { &beh_exclamation_box,             0x0089, 0x0003 }, 
    { &beh_exclamation_box,              0x0089, 0x0004 }, { &beh_exclamation_box,             0x0089, 0x0005 }, 
    { &beh_exclamation_box,              0x0089, 0x0006 }, { &beh_exclamation_box,             0x0089, 0x0007 }, 
    { &beh_exclamation_box,              0x0089, 0x0008 }, { &beh_breakable_box,               0x0081, 0x0000 }, 
    { &beh_breakable_box,                0x0081, 0x0001 }, { &beh_pushable,                    0x00D9, 0x0000 }, 
    { &beh_breakable_box2,               0x0082, 0x0000 }, { &beh_floor_switch_hidden_objects, 0x00CF, 0x0000 }, 
    { &beh_hidden_object,                0x0081, 0x0000 }, { &beh_hidden_object,               0x0081, 0x0001 }, 
    { &beh_hidden_object,                0x0081, 0x0002 }, { &beh_breakable_box,               0x0081, 0x0003 }, 
    { &beh_koopa_shell_underwater,       0x00BE, 0x0000 }, { &beh_exclamation_box,             0x0089, 0x0009 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_bullet_bill,                 0x0054, 0x0000 }, 
    { &beh_heave_ho,                     0x0059, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_thwomp_2,                     0x0058, 0x0000 }, { &beh_fire_spewer,                 0x00B4, 0x0000 }, 
    { &beh_fly_guy,                      0x00DC, 0x0001 }, { &beh_jumping_box,                 0x0081, 0x0000 }, 
    { &beh_three_butterflies,            0x00BB, 0x0000 }, { &beh_three_butterflies,           0x00BB, 0x0004 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_small_bully,                 0x0056, 0x0000 }, 
    { &beh_small_bully,                  0x0057, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_stub_1D0C,                    0x0058, 0x0000 }, { &beh_bouncing_fireball,           0x0000, 0x0000 }, 
    { &beh_flamethrower,                 0x0000, 0x0004 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_poundable,                    0x006B, 0x0000 }, { &beh_water_bubble_drop,           0x0000, 0x0000 }, 
    { &beh_evil_lakitu,                  0x0054, 0x0000 }, { &beh_koopa,                       0x0068, 0x0002 }, 
    { &beh_waving_koopa_flag,            0x0000, 0x0000 }, { &beh_bobomb,                      0x00BC, 0x0000 }, 
    { &beh_cannon,                       0x0080, 0x0000 }, { &beh_bobomb_buddy_cannon_role,  0x00C3, 0x0000 }, 
    { &beh_cannon,                       0x0080, 0x0000 }, { &beh_bobomb,                      0x00BC, 0x0001 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_star,                        0x0054, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_unagi,                       0x0055, 0x0000 }, 
    { &beh_sushi_shark,                  0x0056, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_static_object,               0x0057, 0x0000 }, 
    { &beh_tweester,                     0x0056, 0x0000 }, { &beh_pokey,                       0x0000, 0x0000 }, 
    { &beh_pokey,                        0x0000, 0x0000 }, { &beh_tox_box,                     0x00C7, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_monty_mole,                  0x0055, 0x0000 }, 
    { &beh_monty_mole,                   0x0055, 0x0001 }, { &beh_monty_mole_in_hole,          0x0054, 0x0000 }, 
    { &beh_fly_guy,                      0x00DC, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_wiggler,                      0x0057, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_spindrift,                   0x0054, 0x0000 }, 
    { &beh_mr_blizzard,                  0x0055, 0x0000 }, { &beh_mr_blizzard,                 0x0055, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_small_penguin,               0x0057, 0x0000 }, 
    { &beh_tuxies_mother,                0x0057, 0x0000 }, { &beh_tuxies_mother,               0x0057, 0x0000 }, 
    { &beh_mr_blizzard,                  0x0055, 0x0001 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_haunted_chair,               0x0056, 0x0000 }, 
    { &beh_haunted_chair,                0x0056, 0x0000 }, { &beh_haunted_chair,               0x0056, 0x0000 }, 
    { &beh_boo_2,                        0x0054, 0x0000 }, { &beh_boo_2,                       0x0054, 0x0000 }, 
    { &beh_boo_group,                    0x0054, 0x0000 }, { &beh_boo_with_cage,               0x0054, 0x0000 }, 
    { &beh_beta_boo_key_outside,         0x0055, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_chirp_chirp,                  0x0000, 0x0000 }, { &beh_seaweed_bundle,              0x0000, 0x0000 }, 
    { &beh_beta_chest,                   0x0065, 0x0000 }, { &beh_bowser_bomb,                 0x00B3, 0x0000 }, 
    { &beh_large_fish_group,             0x0000, 0x0002 }, { &beh_large_fish_group,            0x0000, 0x0003 }, 
    { &beh_manta_rings_generator,        0x0068, 0x0000 }, { &beh_manta_rings_generator,       0x0068, 0x0000 }, 
    { &beh_skeeter,                      0x0069, 0x0000 }, { &beh_clam_shell,                  0x0058, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_ukiki_open_cage,             0x0056, 0x0000 }, 
    { &beh_ukiki_open_cage,              0x0056, 0x0001 }, { &beh_piranha_plant_2,             0x0064, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_small_whomp,                 0x0067, 0x0000 }, 
    { &beh_chain_chomp,                  0x0066, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_koopa,                        0x0068, 0x0001 }, { &beh_koopa,                       0x00BF, 0x0000 }, 
    { &beh_poundable,                    0x006B, 0x0000 }, { &beh_piranha_plant,               0x0064, 0x0000 }, 
    { &beh_piranha_plant,                0x0064, 0x0001 }, { &beh_koopa,                       0x0068, 0x0004 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_moneybag,                    0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_bat,                         0x0064, 0x0000 }, 
    { &beh_bat,                          0x0064, 0x0001 }, { &beh_mr_i,                        0x0000, 0x0000 }, 
    { &beh_scuttlebug_spawn,             0x0000, 0x0000 }, { &beh_scuttlebug,                  0x0065, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0054, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_rotating_clock_platform,     0x0036, 0x0000 }, 
    { &beh_rotating_clock_platform,      0x0037, 0x0001 }, { &beh_clock_pendulum,              0x0038, 0x0000 }, 
    { &beh_clock_metal_platform,         0x0039, 0x0000 }, { &beh_clock_metal_platform,        0x003A, 0x0001 }, 
    { &beh_sliding_platform,             0x003B, 0x0000 }, { &beh_rotating_gear_platform,      0x003C, 0x0000 }, 
    { &beh_rotating_gear_platform,       0x003D, 0x0002 }, { &beh_pushable_clock_box,          0x003E, 0x0000 }, 
    { &beh_pushable_clock_box,           0x003F, 0x0001 }, { &beh_clock_platform,              0x0040, 0x0000 }, 
    { &beh_clock_main_rotation,          0x0041, 0x0000 }, { &beh_rotating_clock_platform2,    0x0042, 0x0000 }, 
    { &beh_clock_main_rotation,          0x0043, 0x0001 }, { &beh_clock_main_rotation,         0x0044, 0x0001 }, 
    { &beh_clock_metal_platform,         0x0039, 0x0002 }, { &beh_clock_metal_platform,        0x003A, 0x0003 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_exclamation_box,             0x0089, 0x000A }, 
    { &beh_exclamation_box,              0x0089, 0x000B }, { &beh_exclamation_box,             0x0089, 0x000C }, 
    { &beh_exclamation_box,              0x0089, 0x000D }, { &beh_exclamation_box,             0x0089, 0x000E }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_sliding_platform2,            0x0036, 0x0000 }, { &beh_sliding_platform2,           0x0037, 0x0000 }, 
    { &beh_another_tilting_platform,     0x0038, 0x0000 }, { &beh_octagonal_platform_rotating, 0x0039, 0x0000 }, 
    { &beh_floor_switch_press_animation, 0x0041, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_four_rotating_platforms,     0x003D, 0x0000 }, 
    { &beh_climbable_cage,               0x003E, 0x0000 }, { &beh_solid_moving,                0x003F, 0x0000 }, 
    { &beh_solid_moving,                 0x0040, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }, 
    { &beh_collectable_coin,             0x0074, 0x0000 }, { &beh_collectable_coin,            0x0074, 0x0000 }
};

static struct Struct802E19DC D_80331240[] = 
{
    {0x00, 0x01, 0x00, 0x00, NULL},                            {0x01, 0x00, 0x00, 0x74, &beh_collectable_coin},
    {0x02, 0x00, 0x00, 0x74, &beh_collectable_coin},           {0x03, 0x00, 0x00, 0xB8, &beh_static_object},
    {0x04, 0x00, 0x00, 0x54, &beh_boo_group},                  {0x05, 0x00, 0x00, 0xAC, &beh_castle_floor_trap},
    {0x06, 0x00, 0x00, 0x36, &beh_horizontal_movement},        {0x07, 0x00, 0x00, 0x37, &beh_snow_ball},
    {0x08, 0x01, 0x00, 0x38, &beh_bascule_bridge},             {0x09, 0x00, 0x00, 0x00, &beh_static_object},
    {0x0A, 0x00, 0x00, 0x3A, &beh_rotating_cw_with_fire_bars}, {0x0B, 0x00, 0x00, 0x00, &beh_floating_wood_bridge},
    {0x0C, 0x00, 0x00, 0x00, &beh_tumbling_platform},          {0x0D, 0x00, 0x00, 0x3E, &beh_lll_rotating_platform},
    {0x0E, 0x01, 0x00, 0x3F, &beh_lll_slow_tilting_movement},  {0x0F, 0x00, 0x00, 0x40, &beh_lll_slow_up_down_movement},
    {0x10, 0x00, 0x00, 0x41, &beh_tilting_inverted_pyramid2},  {0x11, 0x00, 0x00, 0x00, &beh_bowser_puzzle},
    {0x12, 0x00, 0x00, 0x00, &beh_mr_i},                       {0x13, 0x00, 0x00, 0x56, &beh_small_bully},
    {0x14, 0x00, 0x00, 0x57, &beh_big_bully_boss},             {0x15, 0x00, 0x00, 0x00, &beh_static_object},
    {0x16, 0x00, 0x00, 0x00, &beh_static_object},              {0x17, 0x00, 0x00, 0x00, &beh_static_object},
    {0x18, 0x00, 0x00, 0x00, &beh_static_object},              {0x19, 0x00, 0x00, 0x00, &beh_static_object},
    {0x1A, 0x00, 0x00, 0x74, &beh_moving_blue_coin},           {0x1B, 0x00, 0x00, 0x65, &beh_beta_chest},
    {0x1C, 0x00, 0x00, 0x68, &beh_manta_rings_generator},      {0x1D, 0x00, 0x00, 0xB3, &beh_bowser_bomb},
    {0x1E, 0x03, 0x00, 0x00, &beh_static_object},              {0x1F, 0x00, 0x00, 0x00, &beh_static_object},
    {0x20, 0x00, 0x00, 0xBB, &beh_butterfly},                  {0x21, 0x00, 0x00, 0x64, &beh_bowser},
    {0x22, 0x00, 0x00, 0xAF, &beh_clocklike_rotation},         {0x23, 0x01, 0x00, 0xAE, &beh_rock_formation_eyes},
    {0x24, 0x01, 0x00, 0xAD, &beh_sliding_brick_platform_2},   {0x25, 0x00, 0x00, 0x00, &beh_tower_platform_group},
    {0x26, 0x00, 0x00, 0x00, &beh_rotating_counter_clockwise}, {0x27, 0x00, 0x00, 0xB2, &beh_wf_tumbling_bridge},
    {0x28, 0x00, 0x00, 0xB1, &beh_large_rock_eyes},            {0x65, 0x01, 0x00, 0x03, &beh_static_object},
    {0x66, 0x01, 0x00, 0x04, &beh_static_object},              {0x67, 0x01, 0x00, 0x05, &beh_static_object},
    {0x68, 0x01, 0x00, 0x06, &beh_static_object},              {0x69, 0x01, 0x00, 0x07, &beh_static_object},
    {0x6A, 0x01, 0x00, 0x08, &beh_static_object},              {0x6B, 0x01, 0x00, 0x09, &beh_static_object},
    {0x6C, 0x01, 0x00, 0x0A, &beh_static_object},              {0x6D, 0x01, 0x00, 0x0B, &beh_static_object},
    {0x6E, 0x01, 0x00, 0x0C, &beh_static_object},              {0x6F, 0x01, 0x00, 0x0D, &beh_static_object},
    {0x70, 0x01, 0x00, 0x0E, &beh_static_object},              {0x71, 0x01, 0x00, 0x0F, &beh_static_object},
    {0x72, 0x01, 0x00, 0x10, &beh_static_object},              {0x73, 0x01, 0x00, 0x11, &beh_static_object},
    {0x74, 0x01, 0x00, 0x12, &beh_static_object},              {0x75, 0x01, 0x00, 0x13, &beh_static_object},
    {0x76, 0x01, 0x00, 0x14, &beh_static_object},              {0x77, 0x01, 0x00, 0x15, &beh_static_object},
    {0x78, 0x01, 0x00, 0x16, &beh_static_object},              {0x79, 0x00, 0x00, 0x17, &beh_tree},
    {0x7A, 0x00, 0x00, 0x18, &beh_tree},                       {0x7B, 0x00, 0x00, 0x19, &beh_tree},
    {0x7C, 0x00, 0x00, 0x1A, &beh_tree},                       {0x7D, 0x00, 0x00, 0x1B, &beh_tree},
    {0x89, 0x01, 0x00, 0x1C, &beh_door},                       {0x7E, 0x01, 0x00, 0x1D, &beh_door},
    {0x7F, 0x01, 0x00, 0x1E, &beh_door},                       {0x80, 0x01, 0x00, 0x1F, &beh_door},
    {0x81, 0x01, 0x00, 0x20, &beh_door},                       {0x82, 0x01, 0x00, 0x21, &beh_door},
    {0x8A, 0x04, 0x00, 0x22, &beh_door},                       {0x8B, 0x04, 0x01, 0x23, &beh_door},
    {0x8C, 0x04, 0x03, 0x24, &beh_door},                       {0x8D, 0x04, 0x00, 0x25, &beh_door},
    {0x88, 0x02, 0x00, 0x26, &beh_door_warp},                  {0x83, 0x02, 0x00, 0x27, &beh_door_warp},
    {0x84, 0x02, 0x00, 0x28, &beh_door_warp},                  {0x85, 0x02, 0x00, 0x29, &beh_door_warp},
    {0x86, 0x02, 0x00, 0x2A, &beh_door_warp},                  {0x87, 0x02, 0x00, 0x2B, &beh_door_warp},
    {0xFF, 0x00, 0x00, 0x00, NULL}
};

s16 func_802E1190(s16 a0)
{
    u16 sp06 = ((u16) (a0 & 0xFF));
    sp06 <<= 8;

    if (sp06 == 0x3F00)
        sp06 = 0x4000;
    
    if (sp06 == 0x7F00)
        sp06 = 0x8000;
    
    if (sp06 == 0xBF00)
        sp06 = 0xC000;
    
    if (sp06 == 0xFF00)
        sp06 = 0x0000;
    
    return (s16) sp06;
}

void func_802E1224(u32 a0, u32 (*a1)[], s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    if (a1 != NULL)
    {
        struct Object *sp3C = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, func_802E1190(a5), 0);
        sp3C->oUnk188 = ((u32) a6) << 16;        
    }
}

void func_802E12CC(u32 a0, u8 (*a1)[], s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    if (a1 != NULL)
    {
        struct Object *sp3C = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, func_802E1190(a5), 0);
        sp3C->oUnk188 = ((u32) a6) << 24;        
    }
}

void func_802E1374(u32 a0, u8 (*a1)[], s16 a2, s16 a3, s16 a4, s16 a5, s16 a6, s16 a7)
{
    struct Object *sp34 = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, 0, 0);


    sp34->oUnknownUnk108_F32 = (f32) a5;
    sp34->oUnknownUnk10C_F32 = (f32) a6;
    sp34->oUnknownUnk110_F32 = (f32) a7;
}

void Unknown802E142C(u32 (*a0)[], s16 a1[])
{    
    struct Object *sp3C;
    s16 sp3A;
        
    sp3A = &beh_collectable_coin == a0 ? 116 : 0;
    
    sp3C = func_8029E230(&D_8035FB18, 0, sp3A, a0, a1[1], a1[2], a1[3], 0, func_802E1190(a1[0]), 0);

    sp3C->oUnk1A8 = a1[4];
    sp3C->oUnk188 = (a1[4] & 0xFF) >> 16;    // good C
}

void func_802E1504(s16 a0, s16* a1)
{
    UNUSED u32 pad5C;
    s32 offset;
    s16 sp4C[5];
    struct Object * sp48;
    struct Struct803306D0 sp40;

    D_8035FB18.header.gfx.unk18 = a0;
    D_8035FB18.header.gfx.unk19 = a0;

    while (TRUE)
    {
        if (*a1 == -1)
            break;

        offset = (*a1 & 0x1FF) - 0x1F;

        if (offset < 0)
            break;

        sp4C[0] = ((*a1++ >> 9) & 0x7F) << 1;
        sp4C[1] = *a1++;
        sp4C[2] = *a1++;
        sp4C[3] = *a1++;
        sp4C[4] = *a1++;

        sp40.unk6 = D_803306D0[offset].unk4; 
        sp40.beh  = D_803306D0[offset].beh;
        sp40.unk4 = D_803306D0[offset].unk6;

        if (sp40.unk4 != 0)
            sp4C[4] = (sp4C[4] & 0xFF00) + (sp40.unk4 & 0x00FF); 

        if (((sp4C[4] >> 8) & 0x00FF) != 0xFF)
        {
            sp48 = func_8029E230(&D_8035FB18, 0, sp40.unk6, sp40.beh, sp4C[1], sp4C[2], sp4C[3], 0, func_802E1190(sp4C[0]), 0);

            sp48->oUnk1A8   = sp4C[4];
            sp48->oUnk188   = ((sp4C[4] & 0x00FF) << 16) + (sp4C[4] & 0xFF00);
            sp48->oBehParam = sp4C[4] & 0x00FF;
            sp48->unk1F6   = 2;
            sp48->unk25C   = a1 - 1;
            sp48->nextObj    = sp48;
        }
    }
}

void func_802E1780(s16 a0, s16* a1)
{
    UNUSED u8 pad[8];
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp36;
    UNUSED u8 pad2[10];

    D_8035FB18.header.gfx.unk18 = a0;
    D_8035FB18.header.gfx.unk19 = a0;

    while (TRUE)
    {
        sp38 = *a1++;

        if (sp38 < 0)
            break;
        
        sp3E = *a1++;
        sp3C = *a1++;
        sp3A = *a1++;
        sp36 = *a1++;

        switch (sp38)
        {
            case 0x00:
                func_802E1224(0, &beh_boo_boss_spawned_bridge, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x01:
                func_802E1224(54, &beh_bbh_tilt_floor_platforms, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x02:
                func_802E1224(55, &beh_bbh_tumbling_platform_group, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x03:
                func_802E1224(57, &beh_tumbling_bookshelf, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x04:
                func_802E1224(58, &beh_mesh_elevator, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x14:
                func_802E1224(116, &beh_collectable_coin, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x15:
                func_802E1224(116, &beh_collectable_coin, sp3E, sp3C, sp3A, sp36, 0);
                break;
            default:
                break;
        }
    }   
}

void func_802E19DC(s16 a0, s16** a1)
{
    s32 sp4C;
    int i;          //sp48
    u32 offset;     //sp44
    s16 sp42;
    s16 sp40;
    s16 sp3E;
    s16 sp34[5];
    u8  sp33;
    u8  sp32;
    s8  sp31;
    u8  sp30;
    void* sp2C;

    sp4C = **a1;
    (*a1)++;

    D_8035FB18.header.gfx.unk18 = a0;
    D_8035FB18.header.gfx.unk19 = a0;

    for (i = 0; i < sp4C; i++)
    {
        sp31 = (s8) **a1;
        (*a1)++;
        sp42 = **a1;
        (*a1)++;
        sp40 = **a1;
        (*a1)++;
        sp3E = **a1;
        (*a1)++;

        offset = 0;
        while (TRUE)
        {
            if (D_80331240[offset].unk00 == (u8) sp31)
                break;

            if (D_80331240[offset].unk00 == 0xFF) { }

            offset++;
        }

        sp33 = D_80331240[offset].unk03;
        sp2C = D_80331240[offset].beh;
        sp32 = D_80331240[offset].unk01;
        sp30 = D_80331240[offset].unk02;

        switch (sp32)
        {
            case 0:
                func_802E1224(sp33, sp2C, sp42, sp40, sp3E, 0, 0);
                break;
            case 1:
                sp34[0] = **a1;
                (*a1)++;
                func_802E1224(sp33, sp2C, sp42, sp40, sp3E, sp34[0], 0);
                break;
            case 2:
                sp34[0] = **a1;
                (*a1)++;
                sp34[1] = **a1;
                (*a1)++;
                func_802E1224(sp33, sp2C, sp42, sp40, sp3E, sp34[0], sp34[1]);
                break;
            case 3:
                sp34[0] = **a1;
                (*a1)++;
                sp34[1] = **a1;
                (*a1)++;
                sp34[2] = **a1;
                (*a1)++;
                func_802E1374(sp33, sp2C, sp42, sp40, sp3E, sp34[0], sp34[1], sp34[2]);
                break;
            case 4:
                sp34[0] = **a1;
                (*a1)++;
                func_802E12CC(sp33, sp2C, sp42, sp40, sp3E, sp34[0], sp30);
                break;
            default:
                break;
        }

    }
}
