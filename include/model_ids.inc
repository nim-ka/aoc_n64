
# TODO: find a way to include this file in .c files.


.set ACT_1, (1 << 0)
.set ACT_2, (1 << 1)
.set ACT_3, (1 << 2)
.set ACT_4, (1 << 3)
.set ACT_5, (1 << 4)
.set ACT_6, (1 << 5)

# If an object is set as active for the first 5 acts only, it is treated as always active.
# It's possible that there were only planned to be 5 acts per level early in development.
# Hence, they added a macro so they wouldn't have to change the acts for every object.
.set ALL_ACTS_MACRO, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5
.set ALL_ACTS,       ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6


.set COIN_FORMATION_FLAG_VERTICAL, (1 << 0)
.set COIN_FORMATION_FLAG_RING,     (1 << 1)
.set COIN_FORMATION_FLAG_ARROW,    (1 << 2)
.set COIN_FORMATION_FLAG_FLYING,   (1 << 4)


# SAME CONTENT AS model_ids.h

# TODO: Name more of these.

.set MODEL_NONE,                        0x00

# Global models that are loaded for every level

.set MODEL_MARIO,                       0x01        # mario_geo
.set MODEL_SMOKE,                       0x96        # smoke_geo
.set MODEL_SPARKLES,                    0x95        # sparkles_geo
.set MODEL_BUBBLE,                      0xA8        # bubble_geo
.set MODEL_SPOT_ON_GROUND,              0xA5        # spot_on_ground_geo
.set MODEL_WATER_WAVES_2,               0xA6        # water_waves2_geo
.set MODEL_WATER_SPLASH,                0xA7        # water_splash_geo
.set MODEL_WATER_WAVES,                 0xA3        # water_waves_geo
.set MODEL_YELLOW_COIN,                 0x74        # yellow_coin_geo
.set MODEL_STAR,                        0x7A        # star_geo
.set MODEL_TRANSPARENT_STAR,            0x79        # transparent_star_geo
.set MODEL_WOODEN_SIGNPOST,             0x7C        # wooden_signpost_geo
.set MODEL_DL_GLOBAL_A4,                0xA4        # snowball_seg4_dl_04032A18
.set MODEL_RED_FLAME,                   0x90        # red_flame_geo
.set MODEL_BLUE_FLAME,                  0x91        # blue_flame_geo
.set MODEL_BURN_SMOKE,                  0x94        # burn_smoke_geo
.set MODEL_LEAVES,                      0xA2        # leaves_geo
.set MODEL_PURPLE_MARBLE,               0xAA        # purple_marble_geo
.set MODEL_FISH,                        0xB9        # fish_geo
.set MODEL_FISH_2,                      0xBA        # fish2_geo
.set MODEL_SPARKLES_ANIMATION,          0x8F        # sparkles_animation_geo
.set MODEL_DL_GLOBAL_9F,                0x9F        # coins_TODO_seg3_dl_0302BCD0
.set MODEL_BUTTERFLY,                   0xBB        # butterfly_geo
.set MODEL_BURN_SMOKE_COPY,             0x9C        # burn_smoke_geo
.set MODEL_DL_GLOBAL_A1,                0xA1        # coins_TODO_seg3_dl_0301CB00
.set MODEL_MIST,                        0x8E        # mist_geo
.set MODEL_WHITE_PUFF,                  0xE0        # white_puff_geo
.set MODEL_DL_GLOBAL_9E,                0x9E        # snow_ball_seg3_dl_0302C8A0
.set MODEL_SNOWMAN_SNOW_BALL,           0xA0        # snowman_snow_ball_geo
.set MODEL_YELLOW_COIN_NO_SHADOW,       0x75        # yellow_coin_no_shadow_geo
.set MODEL_BLUE_COIN,                   0x76        # blue_coin_geo
.set MODEL_BLUE_COIN_NO_SHADOW,         0x77        # blue_coin_no_shadow_geo
.set MODEL_MARIOS_WINGED_METAL_CAP,     0x85        # marios_winged_metal_cap_geo
.set MODEL_MARIOS_METAL_CAP,            0x86        # marios_metal_cap_geo
.set MODEL_MARIOS_WING_CAP,             0x87        # marios_wing_cap_geo
.set MODEL_MARIOS_CAP,                  0x88        # marios_cap_geo
.set MODEL_BOWSER_KEY,                  0xC8        # bowser_key_geo
.set MODEL_BOWSER_KEY_2,                0xCC        # bowser_key2_geo
.set MODEL_RED_FLAME_SHADOW,            0xCB        # red_flame_shadow_geo
.set MODEL_1UP,                         0xD4        # mushroom_1up_geo
.set MODEL_RED_COIN,                    0xD7        # red_coin_geo
.set MODEL_RED_COIN_NO_SHADOW,          0xD8        # red_coin_no_shadow_geo
.set MODEL_NUMBER,                      0xDB        # number_geo
.set MODEL_EXPLOSION,                   0xCD        # explosion_geo
.set MODEL_DIRT_ANIMATION,              0x8A        # dirt_animation_geo
.set MODEL_CARTOON_STAR,                0x8B        # cartoon_star_geo

# Common model sets that can be loaded by multiple levels

# every level except castle, ending, intro, main menu, sa
.set MODEL_BLUE_COIN_SWITCH,            0x8C        # blue_coin_switch_geo
.set MODEL_AMP,                         0xC2        # amp_geo
.set MODEL_PURPLE_SWITCH,               0xCF        # purple_switch_geo
.set MODEL_CHECKERBOARD_PLATFORM,       0xCA        # checkerboard_platform_geo
.set MODEL_BREAKABLE_BOX,               0x81        # breakable_box_geo
.set MODEL_BREAKABLE_BOX_SMALL,         0x82        # breakable_box_small_geo
.set MODEL_EXCLAMATION_BOX_OUTLINE,     0x83        # exclamation_box_outline_geo
.set MODEL_EXCLAMATION_BOX,             0x89        # exclamation_box_geo
.set MODEL_GOOMBA,                      0xC0        # goomba_geo
.set MODEL_DL_COMMON1_84,               0x84        # exclamation_point_seg8_dl_08025F08
.set MODEL_KOOPA_SHELL,                 0xBE        # koopa_shell_geo
.set MODEL_METAL_BOX,                   0xD9        # metal_box_geo
.set MODEL_DL_COMMON1_DA,               0xDA        # metal_box_seg8_dl_08024BB8
.set MODEL_BLACK_BOBOMB,                0xBC        # black_bobomb_geo
.set MODEL_BOBOMB_BUDDY,                0xC3        # bobomb_buddy_geo
.set MODEL_DL_CANNON_LID,               0xC9        # cannon_closed_seg8_dl_080048E0
.set MODEL_BOWLING_BALL,                0xB4        # bowling_ball_geo
.set MODEL_CANNON_BARREL,               0x7F        # cannon_barrel_geo
.set MODEL_CANNON_BASE,                 0x80        # cannon_base_geo
.set MODEL_HEART,                       0x78        # heart_geo
.set MODEL_FLYGUY,                      0xDC        # shyguy_geo
.set MODEL_CHUCKYA,                     0xDF        # chuckya_geo
.set MODEL_BOWLING_BALL_2,              0xE1        # bowling_ball2_geo

# ttc, wdw, wf
.set MODEL_BULLET_BILL,                 0x54        # bullet_bill_geo
.set MODEL_YELLOW_SPHERE,               0x55        # yellow_sphere_geo
.set MODEL_HOOT,                        0x56        # hoot_geo
.set MODEL_YOSHI_EGG,                   0x57        # yoshi_egg_geo
.set MODEL_THWOMP,                      0x58        # thwomp_geo
.set MODEL_HEAVE_HO,                    0x59        # heave_ho_geo

# bitfs, lll, wmotr
.set MODEL_BLARGG,                      0x54        # blargg_geo
.set MODEL_BULLY,                       0x56        # bully_geo
.set MODEL_BULLY_BOSS,                  0x57        # bully_boss_geo

# bob
.set MODEL_WATER_BOMB,                  0x54        # water_bomb_geo
.set MODEL_WATER_BOMB_SHADOW,           0x55        # water_bomb_shadow_geo
.set MODEL_KING_BOBOMB,                 0x56        # king_bobomb_geo

# ddd, jrb, sa
.set MODEL_MANTA_RAY,                   0x54        # manta_seg5_geo_05008D14
.set MODEL_UNAGI,                       0x55        # unagi_geo
.set MODEL_SUSHI,                       0x56        # sushi_geo
.set MODEL_DL_WHIRLPOOL,                0x57        # whirlpool_seg5_dl_05013CB8
.set MODEL_CLAM_SHELL,                  0x58        # clam_shell_geo

# ssl
.set MODEL_POKEY_HEAD,                  0x54        # pokey_head_geo
.set MODEL_POKEY_BODY_PART,             0x55        # pokey_body_part_geo
.set MODEL_TORNADO,                     0x56        # tornado_seg5_geo_05014630
.set MODEL_KLEPTO,                      0x57        # klepto_geo
.set MODEL_EYEROK,                      0x58        # eyerok_geo
.set MODEL_EYEROK_2,                    0x59        # eyerok2_geo

# hmc, ttm
.set MODEL_DL_MONTY_MOLE_HOLE,          0x54        # monty_mole_hole_seg5_dl_05000840
.set MODEL_MONTY_MOLE,                  0x55        # monty_mole_geo
.set MODEL_UKIKI,                       0x56        # ukiki_geo
.set MODEL_FWOOSH,                      0x57        # fwoosh_geo

# ccm, sl
.set MODEL_SPINDRIFT,                   0x54        # spindrift_geo
.set MODEL_MR_BLIZZARD_HIDDEN,          0x55        # mr_blizzard_hidden_geo
.set MODEL_MR_BLIZZARD,                 0x56        # mr_blizzard_geo
.set MODEL_PENGUIN,                     0x57        # penguin_geo

# cotmc, pss, totwc, vcutm
.set MODEL_DL_COMMON9_54,               0x54        # capswitch_seg5_dl_05002E00
.set MODEL_CAP_SWITCH,                  0x55        # cap_switch_geo
.set MODEL_DL_COMMON9_56,               0x56        # cap_switch_base_seg5_dl_05003120

# bbh, castle courtyard
.set MODEL_BOO,                         0x54        # boo_geo
.set MODEL_SMALL_KEY,                   0x55        # small_key_geo
.set MODEL_HAUNTED_CHAIR,               0x56        # haunted_chair_geo
.set MODEL_MAD_PIANO,                   0x57        # mad_piano_geo
.set MODEL_BOOKEND_PART,                0x58        # bookend_part_geo
.set MODEL_BOOKEND,                     0x59        # bookend_geo
.set MODEL_HAUNTED_CAGE,                0x5A        # haunted_cage_geo

# castle grounds
.set MODEL_BIRDS,                       0x54        # birds_geo
.set MODEL_PEACH,                       0xDE        # peach_geo
.set MODEL_YOSHI,                       0x55        # yoshi_geo

# bitdw, rr, thi
.set MODEL_ENEMY_LAKITU,                0x54        # enemy_lakitu_geo
.set MODEL_SPINY_BALL,                  0x55        # spiny_ball_geo
.set MODEL_SPINY,                       0x56        # spiny_geo
.set MODEL_WIGGLER,                     0x57        # wiggler_geo
.set MODEL_WIGGLER_BODY_PART,           0x58        # wiggler2_geo
.set MODEL_BUBBA,                       0x59        # bubba_geo

# bowser 1, bowser 2, bowser 3
.set MODEL_COMMON13_64,                 0x64        # bowser_geo
.set MODEL_COMMON13_65,                 0x65        # bowser_bomb_geo
.set MODEL_BOWSER_BOMB,                 0xB3        # bowser_bomb_geo
.set MODEL_COMMON13_66,                 0x66        # bowser_clouds_geo
.set MODEL_COMMON13_67,                 0x67        # bowser_flames_geo
.set MODEL_COMMON13_68,                 0x68        # invisible_bowser_accessory_geo
.set MODEL_COMMON13_69,                 0x69        # bowser2_geo

# ddd, jrb, sa, wdw
.set MODEL_BUB,                         0x64        # bub_geo
.set MODEL_TREASURE_CHEST_BASE,         0x65        # treasure_chest_base_geo
.set MODEL_TREASURE_CHEST_LID,          0x66        # treasure_chest_lid_geo
.set MODEL_CYAN_FISH,                   0x67        # cyan_fish_geo
.set MODEL_WATER_RING,                  0x68        # water_ring_geo
.set MODEL_WATER_MINE,                  0xB3        # water_mine_geo
.set MODEL_SEAWEED,                     0xC1        # seaweed_geo
.set MODEL_SKEETER,                     0x69        # skeeter_geo

# bits, bob, thi, wf
.set MODEL_PIRANHA_PLANT,               0x64        # piranha_plant_geo
.set MODEL_WHOMP,                       0x67        # whomp_geo
.set MODEL_KOOPA_WITH_SHELL,            0x68        # koopa_with_shell_geo
.set MODEL_KOOPA_WITHOUT_SHELL,         0xBF        # koopa_without_shell_geo
.set MODEL_METALLIC_BALL,               0x65        # metallic_ball_geo
.set MODEL_CHAIN_CHOMP,                 0x66        # chain_chomp
.set MODEL_KOOPA_FLAG,                  0x6A        # koopa_flag_geo
.set MODEL_WOODEN_POST,                 0x6B        # wooden_post_geo

# castle, castle grounds
.set MODEL_MIPS,                        0x64        # mips_geo
.set MODEL_BOO_CASTLE,                  0x65        # boo_castle_geo
.set MODEL_LAKITU,                      0x66        # lakitu_geo
.set MODEL_TOAD,                        0xDD        # toad_geo

# ccm, sl
.set MODEL_COMMON17_64,                 0x64        # chilly_chief_seg6_geo
.set MODEL_BIG_CHILL_BULLY,             0x65        # chilly_chief_seg6_geo2
.set MODEL_MONEYBAG,                    0x66        # moneybag_geo

# bbh, bitdw, bitfs, cotmc, hmc, lll, wmotr
.set MODEL_SWOOP,                       0x64        # swoop_geo
.set MODEL_SCUTTLEBUG,                  0x65        # scuttlebug_geo
.set MODEL_MR_I_IRIS,                   0x66        # mr_i_iris_geo
.set MODEL_MR_I,                        0x67        # mr_i_geo
.set MODEL_DORRIE,                      0x68        # dorrie_geo
.set MODEL_SNUFIT,                      0xCE        # snufit_geo

# Various static level geometry, the geo layout differs but terrain object presets treat them the same.

.set MODEL_LEVEL_GEOMETRY_03,                0x03
.set MODEL_LEVEL_GEOMETRY_04,                0x04
.set MODEL_LEVEL_GEOMETRY_05,                0x05
.set MODEL_LEVEL_GEOMETRY_06,                0x06
.set MODEL_LEVEL_GEOMETRY_07,                0x07
.set MODEL_LEVEL_GEOMETRY_08,                0x08
.set MODEL_LEVEL_GEOMETRY_09,                0x09
.set MODEL_LEVEL_GEOMETRY_0A,                0x0A
.set MODEL_LEVEL_GEOMETRY_0B,                0x0B
.set MODEL_LEVEL_GEOMETRY_0C,                0x0C
.set MODEL_LEVEL_GEOMETRY_0D,                0x0D
.set MODEL_LEVEL_GEOMETRY_0E,                0x0E
.set MODEL_LEVEL_GEOMETRY_0F,                0x0F
.set MODEL_LEVEL_GEOMETRY_10,                0x10
.set MODEL_LEVEL_GEOMETRY_11,                0x11
.set MODEL_LEVEL_GEOMETRY_12,                0x12
.set MODEL_LEVEL_GEOMETRY_13,                0x13
.set MODEL_LEVEL_GEOMETRY_14,                0x14
.set MODEL_LEVEL_GEOMETRY_15,                0x15
.set MODEL_LEVEL_GEOMETRY_16,                0x16

# Level-specific models

# bbh
.set MODEL_BBH_HAUNTED_DOOR,            0x1D        # haunted_door_geo
.set MODEL_BBH_STAIRCASE_STEP,          0x35        # geo_bbh_0005B0
.set MODEL_BBH_TILTING_FLOOR_PLATFORM,  0x36        # geo_bbh_0005C8
.set MODEL_BBH_TUMBLING_PLATFORM,       0x37        # geo_bbh_0005E0
.set MODEL_BBH_38,                      0x38        # geo_bbh_0005F8
.set MODEL_BBH_MOVING_BOOKSHELF,        0x39        # geo_bbh_000610
.set MODEL_BBH_MESH_ELEVATOR,           0x3A        # geo_bbh_000628
.set MODEL_BBH_MERRY_GO_ROUND,          0x3B        # geo_bbh_000640
.set MODEL_BBH_3C,                      0x3C        # geo_bbh_000658

# ccm
.set MODEL_CCM_CABIN_DOOR,              0x27        # cabin_door_geo
.set MODEL_CCM_SNOW_TREE,               0x19        # snow_tree_geo
.set MODEL_CCM_ROPEWAY_LIFT,            0x36        # ccm_geo_0003D0
.set MODEL_CCM_SNOWMAN_BASE,            0xD2        # ccm_geo_0003F0
.set MODEL_CCM_SNOWMAN_HEAD,            0x37        # ccm_geo_00040C

# castle
.set MODEL_CASTLE_35,                   0x35        # castle_geo_000F18
.set MODEL_CASTLE_WATER_LEVEL_PILLAR,   0x36        # castle_geo_001940
.set MODEL_CASTLE_CLOCK_MINUTE_HAND,    0x37        # castle_geo_001530
.set MODEL_CASTLE_CLOCK_HOUR_HAND,      0x38        # castle_geo_001548
.set MODEL_CASTLE_CLOCK_PENDULUM,       0x39        # castle_geo_001518
.set MODEL_CASTLE_26,                   0x26        # castle_door_geo # unused?
.set MODEL_CASTLE_27,                   0x27        # wooden_door_geo # unused?
.set MODEL_CASTLE_METAL_DOOR,           0x29        # metal_door_geo
.set MODEL_CASTLE_CASTLE_DOOR,          0x1C        # castle_door_geo
.set MODEL_CASTLE_WOODEN_DOOR,          0x1D        # wooden_door_geo
.set MODEL_CASTLE_DOOR_0_STARS,         0x22        # castle_door_0_star_geo
.set MODEL_CASTLE_DOOR_1_STAR,          0x23        # castle_door_1_star_geo
.set MODEL_CASTLE_DOOR_3_STARS,         0x24        # castle_door_3_stars_geo
.set MODEL_CASTLE_KEY_DOOR,             0x25        # key_door_geo
.set MODEL_CASTLE_STAR_DOOR_30_STARS,   0xD0        # castle_geo_000F00
.set MODEL_CASTLE_STAR_DOOR_8_STARS,    0xD5        # castle_geo_000F00
.set MODEL_CASTLE_STAR_DOOR_50_STARS,   0xD1        # castle_geo_000F00
.set MODEL_CASTLE_STAR_DOOR_70_STARS,   0xD6        # castle_geo_000F00

# hmc
.set MODEL_HMC_WOODEN_DOOR,             0x1D        # wooden_door_geo
.set MODEL_HMC_METAL_DOOR,              0x1F        # metal_door_geo
.set MODEL_HMC_HAZY_MAZE_DOOR,          0x20        # hazy_maze_door_geo
.set MODEL_HMC_ARROW_PLATFORM,          0x36        # hmc_geo_0005A0
.set MODEL_HMC_37,                      0x37        # hmc_geo_0005B8
.set MODEL_HMC_ELEVATOR_PLATFORM,       0x38        # hmc_geo_0005D0
.set MODEL_HMC_39,                      0x39        # hmc_geo_000548
.set MODEL_HMC_3A,                      0x3A        # hmc_geo_000570
.set MODEL_HMC_3B,                      0x3B        # hmc_geo_000588
.set MODEL_HMC_3C,                      0x3C        # hmc_geo_000530

# ssl
.set MODEL_SSL_PALM_TREE,               0x1B        # palm_tree_geo
.set MODEL_SSL_PYRAMID_TOP,             0x3A        # ssl_geo_000618
.set MODEL_SSL_GRINDEL,                 0x36        # ssl_geo_000734
.set MODEL_SSL_SPINDEL,                 0x37        # ssl_geo_000764
.set MODEL_SSL_MOVING_PYRAMID_WALL,     0x38        # ssl_geo_000794
.set MODEL_SSL_PYRAMID_ELEVATOR,        0x39        # ssl_geo_0007AC
.set MODEL_SSL_TOX_BOX,                 0xC7        # ssl_geo_000630

# bob
.set MODEL_BOB_BUBBLY_TREE,             0x17        # bubbly_tree_geo
.set MODEL_BOB_CHAIN_CHOMP_GATE,        0x36        # bob_geo_000440
.set MODEL_BOB_SEESAW_PLATFORM,         0x37        # bob_geo_000458
.set MODEL_BOB_38,                      0x38        # bob_geo_000470

# sl
.set MODEL_SL_36,                       0x36        # sl_geo_000390
.set MODEL_SL_37,                       0x37        # sl_geo_000360
.set MODEL_SL_38,                       0x38        # sl_geo_000378
.set MODEL_SL_SNOW_TREE,                0x19        # snow_tree_geo

# wdw
.set MODEL_WDW_BUBBLY_TREE,                   0x17        # bubbly_tree_geo
.set MODEL_WDW_SQUARE_FLOATING_PLATFORM,      0x36        # wdw_geo_000580
.set MODEL_WDW_ARROW_LIFT,                    0x37        # wdw_geo_000598
.set MODEL_WDW_WATER_LEVEL_DIAMOND,           0x38        # wdw_geo_0005C0
.set MODEL_WDW_HIDDEN_PLATFORM,               0x39        # wdw_geo_0005E8
.set MODEL_WDW_EXPRESS_ELEVATOR,              0x3A        # wdw_geo_000610
.set MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, 0x3B        # wdw_geo_000628
.set MODEL_WDW_ROTATING_PLATFORM,             0x3C        # wdw_geo_000640

# jrb
.set MODEL_JRB_35,                      0x35        # jrb_geo_000978
.set MODEL_JRB_36,                      0x36        # jrb_geo_0009B0
.set MODEL_JRB_37,                      0x37        # jrb_geo_0009E8
.set MODEL_JRB_38,                      0x38        # jrb_geo_000A00
.set MODEL_JRB_39,                      0x39        # jrb_geo_000990
.set MODEL_JRB_3A,                      0x3A        # jrb_geo_0009C8
.set MODEL_JRB_ROCK,                    0x3B        # jrb_geo_000930
.set MODEL_JRB_SLIDING_BOX,             0x3C        # jrb_geo_000960
.set MODEL_JRB_FALLING_PILLAR,          0x3D        # jrb_geo_000900
.set MODEL_JRB_FALLING_PILLAR_BASE,     0x3E        # jrb_geo_000918
.set MODEL_JRB_FLOATING_PLATFORM,       0x3F        # jrb_geo_000948

# thi
.set MODEL_THI_BUBBLY_TREE,             0x17        # bubbly_tree_geo
.set MODEL_THI_WARP_PIPE,               0x16        # warp_pipe_geo
.set MODEL_THI_HUGE_ISLAND_TOP,         0x36        # thi_geo_0005B0
.set MODEL_THI_TINY_ISLAND_TOP,         0x37        # thi_geo_0005C8

# ttc
.set MODEL_TTC_ROTATING_CUBE,           0x36        # ttc_geo_000240
.set MODEL_TTC_ROTATING_PRISM,          0x37        # ttc_geo_000258
.set MODEL_TTC_PENDULUM,                0x38        # ttc_geo_000270
.set MODEL_TTC_LARGE_TREADMILL,         0x39        # ttc_geo_000288
.set MODEL_TTC_SMALL_TREADMILL,         0x3A        # ttc_geo_0002A8
.set MODEL_TTC_PUSH_BLOCK,              0x3B        # ttc_geo_0002C8
.set MODEL_TTC_ROTATING_HEXAGON,        0x3C        # ttc_geo_0002E0
.set MODEL_TTC_ROTATING_TRIANGLE,       0x3D        # ttc_geo_0002F8
.set MODEL_TTC_PIT_BLOCK,               0x3E        # ttc_geo_000310
.set MODEL_TTC_PIT_BLOCK_2,             0x3F        # ttc_geo_000328
.set MODEL_TTC_ELEVATOR_PLATFORM,       0x40        # ttc_geo_000340
.set MODEL_TTC_CLOCK_HAND,              0x41        # ttc_geo_000358
.set MODEL_TTC_SPINNER,                 0x42        # ttc_geo_000370
.set MODEL_TTC_SMALL_GEAR,              0x43        # ttc_geo_000388
.set MODEL_TTC_LARGE_GEAR,              0x44        # ttc_geo_0003A0

# rr
.set MODEL_RR_SLIDING_PLATFORM,         0x36        # rr_geo_0008C0
.set MODEL_RR_FLYING_CARPET,            0x37        # rr_geo_000848
.set MODEL_RR_OCTAGONAL_PLATFORM,       0x38        # rr_geo_0008A8
.set MODEL_RR_ROTATING_BRIDGE_PLATFORM, 0x39        # rr_geo_000878
.set MODEL_RR_3A,                       0x3A        # rr_geo_0008D8
.set MODEL_RR_CRUISER_WING,             0x3B        # rr_geo_000890
.set MODEL_RR_SEESAW_PLATFORM,          0x3C        # rr_geo_000908
.set MODEL_RR_3D,                       0x3D        # rr_geo_000940
.set MODEL_RR_SWINGING_PLATFORM,        0x3E        # rr_geo_000860
.set MODEL_RR_3F,                       0x3F        # rr_geo_000920
.set MODEL_RR_ELEVATOR_PLATFORM,        0x40        # rr_geo_0008F0
.set MODEL_RR_TRICKY_TRIANGLES,         0x41        # rr_geo_000958
.set MODEL_RR_42,                       0x42        # rr_geo_000970
.set MODEL_RR_43,                       0x43        # rr_geo_000988
.set MODEL_RR_44,                       0x44        # rr_geo_0009A0
.set MODEL_RR_45,                       0x45        # rr_geo_0009B8

# bitdw
.set MODEL_BITDW_WARP_PIPE,             0x12        # warp_pipe_geo
.set MODEL_BITDW_SQUARE_PLATFORM,       0x36        # geo_bitdw_000558
.set MODEL_BITDW_SEESAW_PLATFORM,       0x37        # geo_bitdw_000540
.set MODEL_BITDW_SLIDING_PLATFORM,      0x38        # geo_bitdw_000528
.set MODEL_BITDW_FERRIS_WHEEL_AXLE,     0x39        # geo_bitdw_000570
.set MODEL_BITDW_3A,                    0x3A        # geo_bitdw_000588
.set MODEL_BITDW_3B,                    0x3B        # geo_bitdw_0005A0
.set MODEL_BITDW_3C,                    0x3C        # geo_bitdw_0005B8
.set MODEL_BITDW_3D,                    0x3D        # geo_bitdw_0005D0
.set MODEL_BITDW_3E,                    0x3E        # geo_bitdw_0005E8
.set MODEL_BITDW_STAIRCASE,             0x3F        # geo_bitdw_000600

# vcutm
.set MODEL_VCUTM_36,                    0x36        # vcutm_geo_0001F0
.set MODEL_VCUTM_WARP_PIPE,             0x16        # warp_pipe_geo

# bitfs
.set MODEL_BITFS_PLATFORM_ON_TRACK,       0x36        # bitfs_geo_000758
.set MODEL_BITFS_TILTING_SQUARE_PLATFORM, 0x37        # bitfs_geo_0006C0
.set MODEL_BITFS_SINKING_PLATFORMS,       0x38        # bitfs_geo_000770
.set MODEL_BITFS_39,                      0x39        # bitfs_geo_0006A8
.set MODEL_BITFS_SINKING_CAGE_PLATFORM,   0x3A        # bitfs_geo_000690
.set MODEL_BITFS_ELEVATOR,                0x3B        # bitfs_geo_000678
.set MODEL_BITFS_STRETCHING_PLATFORMS,    0x3C        # bitfs_geo_000708
.set MODEL_BITFS_SEESAW_PLATFORM,         0x3D        # bitfs_geo_000788
.set MODEL_BITFS_MOVING_SQUARE_PLATFORM,  0x3E        # bitfs_geo_000728
.set MODEL_BITFS_SLIDING_PLATFORM,        0x3F        # bitfs_geo_000740
.set MODEL_BITFS_40,                      0x40        # bitfs_geo_0006D8
.set MODEL_BITFS_TUMBLING_PLATFORM,       0x41        # bitfs_geo_0006F0

# bits
.set MODEL_BITS_SLIDING_PLATFORM,         0x36        # bits_geo_0005E0
.set MODEL_BITS_TWIN_SLIDING_PLATFORMS,   0x37        # bits_geo_0005F8
.set MODEL_BITS_OCTAGONAL_PLATFORM,       0x39        # bits_geo_000610
.set MODEL_BITS_3C,                       0x3C        # bits_geo_000628
.set MODEL_BITS_FERRIS_WHEEL_AXLE,        0x3D        # bits_geo_000640
.set MODEL_BITS_ARROW_PLATFORM,           0x3E        # bits_geo_000658
.set MODEL_BITS_SEESAW_PLATFORM,          0x3F        # bits_geo_000670
.set MODEL_BITS_TILTING_W_PLATFORM,       0x40        # bits_geo_000688
.set MODEL_BITS_STAIRCASE,                0x41        # bits_geo_0006A0
.set MODEL_BITS_42,                       0x42        # bits_geo_0006B8
.set MODEL_BITS_43,                       0x43        # bits_geo_0006D0
.set MODEL_BITS_44,                       0x44        # bits_geo_0006E8
.set MODEL_BITS_45,                       0x45        # bits_geo_000700
.set MODEL_BITS_WARP_PIPE,                0x49        # warp_pipe_geo

# lll
.set MODEL_LLL_DRAWBRIDGE_PART,                0x38        # lll_geo_000B20
.set MODEL_LLL_ROTATING_BLOCK_FIRE_BARS,       0x3A        # lll_geo_000B38
.set MODEL_LLL_ROTATING_HEXAGONAL_RING,        0x3E        # lll_geo_000BB0
.set MODEL_LLL_SINKING_RECTANGULAR_PLATFORM,   0x3F        # lll_geo_000BC8
.set MODEL_LLL_SINKING_SQUARE_PLATFORMS,       0x40        # lll_geo_000BE0
.set MODEL_LLL_TILTING_SQUARE_PLATFORM,        0x41        # lll_geo_000BF8
.set MODEL_LLL_43,                             0x43        # lll_geo_000C10
.set MODEL_LLL_44,                             0x44        # lll_geo_000C30
.set MODEL_LLL_45,                             0x45        # lll_geo_000C50
.set MODEL_LLL_46,                             0x46        # lll_geo_000C70
.set MODEL_LLL_47,                             0x47        # lll_geo_000C90
.set MODEL_LLL_48,                             0x48        # lll_geo_000CB0
.set MODEL_LLL_49,                             0x49        # lll_geo_000CD0
.set MODEL_LLL_4A,                             0x4A        # lll_geo_000CF0
.set MODEL_LLL_4B,                             0x4B        # lll_geo_000D10
.set MODEL_LLL_4C,                             0x4C        # lll_geo_000D30
.set MODEL_LLL_4D,                             0x4D        # lll_geo_000D50
.set MODEL_LLL_4E,                             0x4E        # lll_geo_000D70
.set MODEL_LLL_4F,                             0x4F        # lll_geo_000D90
.set MODEL_LLL_50,                             0x50        # lll_geo_000DB0
.set MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, 0x36        # lll_geo_000B08
.set MODEL_LLL_SINKING_ROCK_BLOCK,             0x37        # lll_geo_000DD0
.set MODEL_LLL_ROLLING_LOG,                    0x39        # lll_geo_000DE8
.set MODEL_LLL_ROTATING_HEXAGONAL_PLATFORM,    0x09        # lll_geo_000A78
.set MODEL_LLL_35,                             0x35        # lll_geo_000B50
.set MODEL_LLL_3B,                             0x3B        # lll_geo_000B68
.set MODEL_LLL_3C,                             0x3C        # lll_geo_000B80
.set MODEL_LLL_3D,                             0x3D        # lll_geo_000B98
.set MODEL_LLL_VOLCANO_FALLING_TRAP,           0x53        # lll_geo_000EA8

# ddd
.set MODEL_DDD_BOWSER_SUB_DOOR,         0x36        # ddd_geo_000478
.set MODEL_DDD_BOWSER_SUB,              0x37        # ddd_geo_0004A0
.set MODEL_DDD_POLE,                    0x38        # ddd_geo_000450

# wf
.set MODEL_WF_BUBBLY_TREE,              0x17        # bubbly_tree_geo
.set MODEL_WF_GIANT_POLE,               0x0D        # wf_geo_000AE0
.set MODEL_WF_ROTATING_PLATFORM,        0x10        # wf_geo_0009B8
.set MODEL_WF_SMALL_BOMP,               0xAE        # wf_geo_000A00
.set MODEL_WF_LARGE_BOMP,               0xB1        # wf_geo_000A40
.set MODEL_WF_ROTATING_WOODEN_PLATFORM, 0xAF        # wf_geo_000A58
.set MODEL_WF_SLIDING_PLATFORM,         0xAD        # wf_geo_000A98
.set MODEL_WF_B0,                       0xB0        # wf_geo_000AB0
.set MODEL_WF_TUMBLING_BRIDGE_PART,     0xB2        # wf_geo_000AC8
.set MODEL_WF_2C,                       0x2C        # wf_geo_000AF8
.set MODEL_WF_2D,                       0x2D        # wf_geo_000B10
.set MODEL_WF_2E,                       0x2E        # wf_geo_000B38
.set MODEL_WF_2F,                       0x2F        # wf_geo_000B60
.set MODEL_WF_BREAKABLE_WALL_RIGHT,     0x36        # wf_geo_000B78
.set MODEL_WF_BREAKABLE_WALL_LEFT,      0x37        # wf_geo_000B90
.set MODEL_WF_KICKABLE_BOARD,           0x38        # wf_geo_000BA8
.set MODEL_WF_TOWER_DOOR,               0x39        # wf_geo_000BE0
.set MODEL_WF_3A,                       0x3A        # wf_geo_000BC8

# castle courtyard
.set MODEL_COURTYARD_SPIKY_TREE,        0x18        # spiky_tree_geo
.set MODEL_COURTYARD_WOODEN_DOOR,       0x27        # wooden_door_geo

# castle grounds
.set MODEL_CASTLE_GROUNDS_BUBBLY_TREE,  0x17        # bubbly_tree_geo
.set MODEL_CASTLE_GROUNDS_WARP_PIPE,    0x16        # warp_pipe_geo
.set MODEL_CASTLE_GROUNDS_CASTLE_DOOR,  0x26        # castle_door_geo
.set MODEL_CASTLE_GROUNDS_METAL_DOOR,   0x29        # metal_door_geo
.set MODEL_CASTLE_GROUNDS_VCUTM_GRILL,  0x36        # castle_grounds_geo_00070C
.set MODEL_CASTLE_GROUNDS_FLAG,         0x37        # castle_grounds_geo_000660
.set MODEL_CASTLE_GROUNDS_CANNON_GRILL, 0x38        # castle_grounds_geo_000724

# bowser 2
.set MODEL_BOWSER_2_TILTING_ARENA,       0x36        # bowser_2_geo_000170

# bowser 3
.set MODEL_BOWSER_3_FALLING_PLATFORM_1,  0x36        # bowser_3_geo_000290
.set MODEL_BOWSER_3_FALLING_PLATFORM_2,  0x37        # bowser_3_geo_0002A8
.set MODEL_BOWSER_3_FALLING_PLATFORM_3,  0x38        # bowser_3_geo_0002C0
.set MODEL_BOWSER_3_FALLING_PLATFORM_4,  0x39        # bowser_3_geo_0002D8
.set MODEL_BOWSER_3_FALLING_PLATFORM_5,  0x3A        # bowser_3_geo_0002F0
.set MODEL_BOWSER_3_FALLING_PLATFORM_6,  0x3B        # bowser_3_geo_000308
.set MODEL_BOWSER_3_FALLING_PLATFORM_7,  0x3C        # bowser_3_geo_000320
.set MODEL_BOWSER_3_FALLING_PLATFORM_8,  0x3D        # bowser_3_geo_000338
.set MODEL_BOWSER_3_FALLING_PLATFORM_9,  0x3E        # bowser_3_geo_000350
.set MODEL_BOWSER_3_FALLING_PLATFORM_10, 0x3F        # bowser_3_geo_000368

# ttm
.set MODEL_TTM_SLIDE_EXIT_PODIUM,       0x7B        # ttm_geo_000DF4
.set MODEL_TTM_ROLLING_LOG,             0x35        # ttm_geo_000730
.set MODEL_TTM_STAR_CAGE,               0x36        # ttm_geo_000710
.set MODEL_TTM_BLUE_SMILEY,             0x37        # ttm_geo_000D14
.set MODEL_TTM_YELLOW_SMILEY,           0x38        # ttm_geo_000D4C
.set MODEL_TTM_STAR_SMILEY,             0x39        # ttm_geo_000D84
.set MODEL_TTM_MOON_SMILEY,             0x3A        # ttm_geo_000DBC

# main menu
.set MODEL_MAIN_MENU_03,                0x03        # main_menu_geo_0001D0
.set MODEL_MAIN_MENU_04,                0x04        # main_menu_geo_000290
.set MODEL_MAIN_MENU_05,                0x05        # main_menu_geo_0002B8
.set MODEL_MAIN_MENU_06,                0x06        # main_menu_geo_0002E0
.set MODEL_MAIN_MENU_07,                0x07        # main_menu_geo_000308
.set MODEL_MAIN_MENU_08,                0x08        # main_menu_geo_000200
.set MODEL_MAIN_MENU_09,                0x09        # main_menu_geo_000230
.set MODEL_MAIN_MENU_0A,                0x0A        # main_menu_geo_000260
.set MODEL_MAIN_MENU_0B,                0x0B        # main_menu_geo_000330
.set MODEL_MAIN_MENU_0C,                0x0C        # main_menu_geo_000358
