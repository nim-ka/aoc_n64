
.section .mio0, "ax"

.include "levels/main_entry.s"

.align 4, 0x01
.global font_graphics
font_graphics:
.incbin "bin/font_graphics.mio0"
font_graphics_end:

.align 4, 0x01
.global mario
mario:
.incbin "bin/mario.mio0"
mario_end:

# Unknown region 125DB0-128BE0 [2E30]
.incbin "bin/sm64.j.125DB0.bin"

.align 4, 0x01
.global yoshiegg_owl_thwomp
yoshiegg_owl_thwomp:
.incbin "bin/yoshiegg_owl_thwomp.mio0"
yoshiegg_owl_thwomp_end:

.align 4, 0x01
.global owl_thwomp_bullet_heave
owl_thwomp_bullet_heave:
.include "geo/owl_thwomp_bullet_heave.geo.s"
owl_thwomp_bullet_heave_end:

.align 4, 0x01
.global big_bully
big_bully:
.incbin "bin/big_bully.mio0"
big_bully_end:

.align 4, 0x01
.global bully_blargg
bully_blargg:
.include "geo/bully_blargg.geo.s"
bully_blargg_end:

.align 4, 0x01
.global bobombs
bobombs:
.incbin "bin/bobombs.mio0"
bobombs_end:

.align 4, 0x01
.global kingbobomb_bubble
kingbobomb_bubble:
.include "geo/kingbobomb_bubble.geo.s"
kingbobomb_bubble_end:

.align 4, 0x01
.global sea_creatures_texture
sea_creatures_texture:
.incbin "bin/sea_creatures_texture.mio0"
sea_creatures_texture_end:

.align 4, 0x01
.global sea_creatures
sea_creatures:
.include "geo/sea_creatures.geo.s"
sea_creatures_end:

.align 4, 0x01
.global vulture_pokey
vulture_pokey:
.incbin "bin/vulture_pokey.mio0"
vulture_pokey_end:

.align 4, 0x01
.global klepto_eyerock_pokey
klepto_eyerock_pokey:
.include "geo/klepto_eyerock_pokey.geo.s"
klepto_eyerock_pokey_end:

.align 4, 0x01
.global monkey
monkey:
.incbin "bin/monkey.mio0"
monkey_end:

.align 4, 0x01
.global mole_monkey_fwoosh
mole_monkey_fwoosh:
.include "geo/mole_monkey_fwoosh.geo.s"
mole_monkey_fwoosh_end:

.align 4, 0x01
.global spindrift_penguin_snowman
spindrift_penguin_snowman:
.incbin "bin/spindrift_penguin_snowman.mio0"
spindrift_penguin_snowman_end:

.align 4, 0x01
.global spindrift_penguin_blizzard
spindrift_penguin_blizzard:
.include "geo/spindrift_penguin_blizzard.geo.s"
spindrift_penguin_blizzard_end:

.align 4, 0x01
.global checkerboard_question
checkerboard_question:
.incbin "bin/checkerboard_question.mio0"
checkerboard_question_end:

.align 4, 0x01
.global cap_switch
cap_switch:
.include "geo/cap_switch.geo.s"
cap_switch_end:

.align 4, 0x01
.global piano_books
piano_books:
.incbin "bin/piano_books.mio0"
piano_books_end:

.align 4, 0x01
.global bookend_chair_piano_boo
bookend_chair_piano_boo:
.include "geo/bookend_chair_piano_boo.geo.s"
bookend_chair_piano_boo_end:

.align 4, 0x01
.global peach_toadstool
peach_toadstool:
.incbin "bin/peach_toadstool.mio0"
peach_toadstool_end:

.align 4, 0x01
.global birds_peach_yoshi
birds_peach_yoshi:
.include "geo/birds_peach_yoshi.geo.s"
birds_peach_yoshi_end:

.align 4, 0x01
.global enemy
enemy:
.incbin "bin/enemy.mio0"
enemy_end:

.align 4, 0x01
.global bubba_wiggler_lakitu
bubba_wiggler_lakitu:
.include "geo/bubba_wiggler_lakitu.geo.s"
bubba_wiggler_lakitu_end:

.align 4, 0x01
.global bowser
bowser:
.incbin "bin/bowser.mio0"
bowser_end:

.align 4, 0x01
.global bowser_flames_bomb
bowser_flames_bomb:
.include "geo/bowser_flames_bomb.geo.s"
bowser_flames_bomb_end:

.align 4, 0x01
.global treasure_chest_fish
treasure_chest_fish:
.incbin "bin/treasure_chest_fish.mio0"
treasure_chest_fish_end:

.align 4, 0x01
.global skeeter_fish_manta_chest
skeeter_fish_manta_chest:
.include "geo/skeeter_fish_manta_chest.geo.s"
skeeter_fish_manta_chest_end:

.align 4, 0x01
.global koopa_whomp
koopa_whomp:
.incbin "bin/koopa_whomp.mio0"
koopa_whomp_end:

.align 4, 0x01
.global koopa_log_piranha_whomp_chomp
koopa_log_piranha_whomp_chomp:
.include "geo/koopa_log_piranha_whomp_chomp.geo.s"
koopa_log_piranha_whomp_chomp_end:

.align 4, 0x01
.global lakitu_toad
lakitu_toad:
.incbin "bin/lakitu_toad.mio0"
lakitu_toad_end:

.align 4, 0x01
.global lakitu_toad_mips_boo
lakitu_toad_mips_boo:
.include "geo/lakitu_toad_mips_boo.geo.s"
lakitu_toad_mips_boo_end:

.align 4, 0x01
.global chillychief_moneybag
chillychief_moneybag:
.incbin "bin/chillychief_moneybag.mio0"
chillychief_moneybag_end:

.align 4, 0x01
.global moneybag
moneybag:
.include "geo/moneybag.geo.s"
moneybag_end:

.align 4, 0x01
.global mri_swoop
mri_swoop:
.incbin "bin/mri_swoop.mio0"
mri_swoop_end:

.align 4, 0x01
.global mri_swoop_snufit_dorrie_scuttlebug
mri_swoop_snufit_dorrie_scuttlebug:
.include "geo/mri_swoop_snufit_dorrie_scuttlebug.geo.s"
mri_swoop_snufit_dorrie_scuttlebug_end:

.align 4, 0x01
.global chuckya_shyguy_goomba
chuckya_shyguy_goomba:
.incbin "bin/chuckya_shyguy_goomba.mio0"
chuckya_shyguy_goomba_end:

.align 4, 0x01
.global cannon_box_switch_enemies
cannon_box_switch_enemies:
.include "geo/cannon_box_switch_enemies.geo.s"
cannon_box_switch_enemies_end:

.align 4, 0x01
.global doors_trees_coins
doors_trees_coins:
.incbin "bin/doors_trees_coins.mio0"
doors_trees_coins_end:

.align 4, 0x01
.global coins_pipe_doors_maps_trees
coins_pipe_doors_maps_trees:
.include "geo/coins_pipe_doors_maps_trees.geo.s"
coins_pipe_doors_maps_trees_end:

.section .behavior, "a"

.global behavior_data
.global behavior_data_end
behavior_data:
.include "./behavior_data.s"
behavior_data_end:


.section .mio0_c, "ax"

.include "levels/game_over_level.s"

.align 4, 0x01
.global wood_trademark
wood_trademark:
.incbin "bin/wood_trademark.mio0"
wood_trademark_end:

.align 4, 0x01
.global debug_level_select
debug_level_select:
.incbin "bin/debug_level_select.mio0"
debug_level_select_end:

.align 4, 0x01
.global mario_bg
mario_bg:
.incbin "bin/mario_bg.mio0"
mario_bg_end:

.section .mio0_b, "ax"

.include "levels/main_menu_level.s"

.align 4, 0x01
.global main_menu_segment7
main_menu_segment7:
.incbin "bin/main_menu_segment7.mio0"
main_menu_segment7_end:

.include "levels/main_level_scripts.s"

.align 4, 0x01
.global water_skybox
water_skybox:
.incbin "bin/water_skybox.mio0"
water_skybox_end:

.align 4, 0x01
.global ccm_skybox
ccm_skybox:
.incbin "bin/ccm_skybox.mio0"
ccm_skybox_end:

.align 4, 0x01
.global clouds_skybox
clouds_skybox:
.incbin "bin/clouds_skybox.mio0"
clouds_skybox_end:

.align 4, 0x01
.global bifs_skybox
bifs_skybox:
.incbin "bin/bifs_skybox.mio0"
bifs_skybox_end:

.align 4, 0x01
.global wdw_skybox
wdw_skybox:
.incbin "bin/wdw_skybox.mio0"
wdw_skybox_end:

.align 4, 0x01
.global cloud_floor_skybox
cloud_floor_skybox:
.incbin "bin/cloud_floor_skybox.mio0"
cloud_floor_skybox_end:

.align 4, 0x01
.global ssl_skybox
ssl_skybox:
.incbin "bin/ssl_skybox.mio0"
ssl_skybox_end:

.align 4, 0x01
.global bbh_skybox
bbh_skybox:
.incbin "bin/bbh_skybox.mio0"
bbh_skybox_end:

.align 4, 0x01
.global bidw_skybox
bidw_skybox:
.incbin "bin/bidw_skybox.mio0"
bidw_skybox_end:

.align 4, 0x01
.global bits_skybox
bits_skybox:
.incbin "bin/bits_skybox.mio0"
bits_skybox_end:

.align 4, 0x01
.global lll_textures
lll_textures:
.incbin "bin/lll_textures.mio0"
lll_textures_end:

.align 4, 0x01
.global bbh_textures
bbh_textures:
.incbin "bin/bbh_textures.mio0"
bbh_textures_end:

.align 4, 0x01
.global bob_textures
bob_textures:
.incbin "bin/bob_textures.mio0"
bob_textures_end:

.align 4, 0x01
.global jrb_textures
jrb_textures:
.incbin "bin/jrb_textures.mio0"
jrb_textures_end:

.align 4, 0x01
.global rr_textures
rr_textures:
.incbin "bin/rr_textures.mio0"
rr_textures_end:

.align 4, 0x01
.global ccm_textures
ccm_textures:
.incbin "bin/ccm_textures.mio0"
ccm_textures_end:

.align 4, 0x01
.global hmc_textures
hmc_textures:
.incbin "bin/hmc_textures.mio0"
hmc_textures_end:

.align 4, 0x01
.global ttc_textures
ttc_textures:
.incbin "bin/ttc_textures.mio0"
ttc_textures_end:

.align 4, 0x01
.global ttm_textures
ttm_textures:
.incbin "bin/ttm_textures.mio0"
ttm_textures_end:

.align 4, 0x01
.global wf_textures
wf_textures:
.incbin "bin/wf_textures.mio0"
wf_textures_end:

.align 4, 0x01
.global castle_grounds_textures
castle_grounds_textures:
.incbin "bin/castle_grounds_textures.mio0"
castle_grounds_textures_end:

.align 4, 0x01
.global inside_castle_textures
inside_castle_textures:
.incbin "bin/inside_castle_textures.mio0"
inside_castle_textures_end:

.align 4, 0x01
.global flower_textures
flower_textures:
.incbin "bin/flower_textures.mio0"
flower_textures_end:

.align 4, 0x01
.global bbh_segment7
bbh_segment7:
.incbin "bin/bbh_segment7.mio0"
bbh_segment7_end:

.include "levels/bbh_level.s"

.align 4, 0x01
.global ccm_segment7
ccm_segment7:
.incbin "bin/ccm_segment7.mio0"
ccm_segment7_end:

.include "levels/ccm_level.s"

.align 4, 0x01
.global inside_castle_segment7
inside_castle_segment7:
.incbin "bin/inside_castle_segment7.mio0"
inside_castle_segment7_end:

.include "levels/inside_castle_level.s"

.align 4, 0x01
.global hmc_segment7
hmc_segment7:
.incbin "bin/hmc_segment7.mio0"
hmc_segment7_end:

.include "levels/hmc_level.s"

.align 4, 0x01
.global ssl_segment7
ssl_segment7:
.incbin "bin/ssl_segment7.mio0"
ssl_segment7_end:

.include "levels/ssl_level.s"

.align 4, 0x01
.global bob_segment7
bob_segment7:
.incbin "bin/bob_segment7.mio0"
bob_segment7_end:

.include "levels/bob_level.s"

.align 4, 0x01
.global sl_segment7
sl_segment7:
.incbin "bin/sl_segment7.mio0"
sl_segment7_end:

.include "levels/sl_level.s"

.align 4, 0x01
.global wdw_segment7
wdw_segment7:
.incbin "bin/wdw_segment7.mio0"
wdw_segment7_end:

.include "levels/wdw_level.s"

.align 4, 0x01
.global jrb_segment7
jrb_segment7:
.incbin "bin/jrb_segment7.mio0"
jrb_segment7_end:

.include "levels/jrb_level.s"

.align 4, 0x01
.global thi_segment7
thi_segment7:
.incbin "bin/thi_segment7.mio0"
thi_segment7_end:

.include "levels/thi_level.s"

.align 4, 0x01
.global ttc_segment7
ttc_segment7:
.incbin "bin/ttc_segment7.mio0"
ttc_segment7_end:

.include "levels/ttc_level.s"

.align 4, 0x01
.global rr_segment7
rr_segment7:
.incbin "bin/rr_segment7.mio0"
rr_segment7_end:

.include "levels/rr_level.s"

.align 4, 0x01
.global castle_grounds_segment7
castle_grounds_segment7:
.incbin "bin/castle_grounds_segment7.mio0"
castle_grounds_segment7_end:

.include "levels/castle_grounds_level.s"

.align 4, 0x01
.global bidw_segment7
bidw_segment7:
.incbin "bin/bidw_segment7.mio0"
bidw_segment7_end:

.include "levels/bidw_level.s"

.align 4, 0x01
.global vanish_cap_segment7
vanish_cap_segment7:
.incbin "bin/vanish_cap_segment7.mio0"
vanish_cap_segment7_end:

.include "levels/vanish_cap_level.s"

.align 4, 0x01
.global bifs_segment7
bifs_segment7:
.incbin "bin/bifs_segment7.mio0"
bifs_segment7_end:

.include "levels/bifs_level.s"

.align 4, 0x01
.global secret_aquarium_segment7
secret_aquarium_segment7:
.incbin "bin/secret_aquarium_segment7.mio0"
secret_aquarium_segment7_end:

.include "levels/secret_aquarium_level.s"

.align 4, 0x01
.global bits_segment7
bits_segment7:
.incbin "bin/bits_segment7.mio0"
bits_segment7_end:

.include "levels/bits_level.s"

.align 4, 0x01
.global lll_segment7
lll_segment7:
.incbin "bin/lll_segment7.mio0"
lll_segment7_end:

.include "levels/lll_level.s"

.align 4, 0x01
.global ddd_segment7
ddd_segment7:
.incbin "bin/ddd_segment7.mio0"
ddd_segment7_end:

.include "levels/ddd_level.s"

.align 4, 0x01
.global wf_segment7
wf_segment7:
.incbin "bin/wf_segment7.mio0"
wf_segment7_end:

.include "levels/wf_level.s"

.align 4, 0x01
.global cake_end
cake_end:
.incbin "bin/cake_end.mio0"
cake_end_end:

.include "levels/cake_end_level.s"

.align 4, 0x01
.global castle_courtyard_segment7
castle_courtyard_segment7:
.incbin "bin/castle_courtyard_segment7.mio0"
castle_courtyard_segment7_end:

.include "levels/castle_courtyard_level.s"

.align 4, 0x01
.global secret_slide_segment7
secret_slide_segment7:
.incbin "bin/secret_slide_segment7.mio0"
secret_slide_segment7_end:

.include "levels/secret_slide_level.s"

.align 4, 0x01
.global metal_cap_segment7
metal_cap_segment7:
.incbin "bin/metal_cap_segment7.mio0"
metal_cap_segment7_end:

.include "levels/metal_cap_level.s"

.align 4, 0x01
.global wing_cap_segment7
wing_cap_segment7:
.incbin "bin/wing_cap_segment7.mio0"
wing_cap_segment7_end:

.include "levels/wing_cap_level.s"

.align 4, 0x01
.global bidw_platform_segment7
bidw_platform_segment7:
.incbin "bin/bidw_platform_segment7.mio0"
bidw_platform_segment7_end:

.include "levels/bidw_platform_level.s"

.align 4, 0x01
.global rainbow_bonus_segment7
rainbow_bonus_segment7:
.incbin "bin/rainbow_bonus_segment7.mio0"
rainbow_bonus_segment7_end:

.include "levels/rainbow_bonus_level.s"

.align 4, 0x01
.global bifs_platform_segment7
bifs_platform_segment7:
.incbin "bin/bifs_platform_segment7.mio0"
bifs_platform_segment7_end:

.include "levels/bifs_platform_level.s"

.align 4, 0x01
.global bits_platform_segment7
bits_platform_segment7:
.incbin "bin/bits_platform_segment7.mio0"
bits_platform_segment7_end:

.include "levels/bits_platform_level.s"

.align 4, 0x01
.global ttm_segment7
ttm_segment7:
.incbin "bin/ttm_segment7.mio0"
ttm_segment7_end:

.include "levels/ttm_level.s"
