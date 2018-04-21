.include "macros.inc"

.section .mio0_b, "ax"

.include "levels/main_menu_level.s"

.align 4, 0
.global main_menu_segment7
main_menu_segment7:
.incbin "build/mio0/main_menu_segment7.mio0"
glabel main_menu_segment7_end

.include "levels/main_level_scripts.s"

.align 4, 0
.global water_skybox
water_skybox:
.incbin "build/mio0/water_skybox.mio0"
glabel water_skybox_end

.align 4, 0
.global ccm_skybox
ccm_skybox:
.incbin "build/mio0/ccm_skybox.mio0"
glabel ccm_skybox_end

.align 4, 0
.global clouds_skybox
clouds_skybox:
.incbin "build/mio0/clouds_skybox.mio0"
glabel clouds_skybox_end

.align 4, 0
.global bifs_skybox
bifs_skybox:
.incbin "build/mio0/bifs_skybox.mio0"
glabel bifs_skybox_end

.align 4, 0
.global wdw_skybox
wdw_skybox:
.incbin "build/mio0/wdw_skybox.mio0"
glabel wdw_skybox_end

.align 4, 0
.global cloud_floor_skybox
cloud_floor_skybox:
.incbin "build/mio0/cloud_floor_skybox.mio0"
glabel cloud_floor_skybox_end

.align 4, 0
.global ssl_skybox
ssl_skybox:
.incbin "build/mio0/ssl_skybox.mio0"
glabel ssl_skybox_end

.align 4, 0
.global bbh_skybox
bbh_skybox:
.incbin "build/mio0/bbh_skybox.mio0"
glabel bbh_skybox_end

.align 4, 0
.global bidw_skybox
bidw_skybox:
.incbin "build/mio0/bidw_skybox.mio0"
glabel bidw_skybox_end

.align 4, 0
.global bits_skybox
bits_skybox:
.incbin "build/mio0/bits_skybox.mio0"
glabel bits_skybox_end

.align 4, 0
.global lll_textures
lll_textures:
.incbin "build/mio0/lll_textures.mio0"
glabel lll_textures_end

.align 4, 0
.global bbh_textures
bbh_textures:
.incbin "build/mio0/bbh_textures.mio0"
glabel bbh_textures_end

.align 4, 0
.global bob_textures
bob_textures:
.incbin "build/mio0/bob_textures.mio0"
glabel bob_textures_end

.align 4, 0
.global jrb_textures
jrb_textures:
.incbin "build/mio0/jrb_textures.mio0"
glabel jrb_textures_end

.align 4, 0
.global rr_textures
rr_textures:
.incbin "build/mio0/rr_textures.mio0"
glabel rr_textures_end

.align 4, 0
.global ccm_textures
ccm_textures:
.incbin "build/mio0/ccm_textures.mio0"
glabel ccm_textures_end

.align 4, 0
.global hmc_textures
hmc_textures:
.incbin "build/mio0/hmc_textures.mio0"
glabel hmc_textures_end

.align 4, 0
.global ttc_textures
ttc_textures:
.incbin "build/mio0/ttc_textures.mio0"
glabel ttc_textures_end

.align 4, 0
.global ttm_textures
ttm_textures:
.incbin "build/mio0/ttm_textures.mio0"
glabel ttm_textures_end

.align 4, 0
.global wf_textures
wf_textures:
.incbin "build/mio0/wf_textures.mio0"
glabel wf_textures_end

.align 4, 0
.global castle_grounds_textures
castle_grounds_textures:
.incbin "build/mio0/castle_grounds_textures.mio0"
glabel castle_grounds_textures_end

.align 4, 0
.global inside_castle_textures
inside_castle_textures:
.incbin "build/mio0/inside_castle_textures.mio0"
glabel inside_castle_textures_end

.align 4, 0
.global flower_textures
flower_textures:
.incbin "build/mio0/flower_textures.mio0"
glabel flower_textures_end

.align 4, 0
.global bbh_segment7
bbh_segment7:
.incbin "build/mio0/bbh_segment7.mio0"
glabel bbh_segment7_end

.include "levels/bbh_level.s"

.align 4, 0
.global ccm_segment7
ccm_segment7:
.incbin "build/mio0/ccm_segment7.mio0"
glabel ccm_segment7_end

.include "levels/ccm_level.s"

.align 4, 0
.global inside_castle_segment7
inside_castle_segment7:
.incbin "build/mio0/inside_castle_segment7.mio0"
glabel inside_castle_segment7_end

.include "levels/inside_castle_level.s"

.align 4, 0
.global hmc_segment7
hmc_segment7:
.incbin "build/mio0/hmc_segment7.mio0"
glabel hmc_segment7_end

.include "levels/hmc_level.s"

.align 4, 0
.global ssl_segment7
ssl_segment7:
.incbin "build/mio0/ssl_segment7.mio0"
glabel ssl_segment7_end

.include "levels/ssl_level.s"

.align 4, 0
.global bob_segment7
bob_segment7:
.incbin "build/mio0/bob_segment7.mio0"
glabel bob_segment7_end

.include "levels/bob_level.s"

.align 4, 0
.global sl_segment7
sl_segment7:
.incbin "build/mio0/sl_segment7.mio0"
glabel sl_segment7_end

.include "levels/sl_level.s"

.align 4, 0
.global wdw_segment7
wdw_segment7:
.incbin "build/mio0/wdw_segment7.mio0"
glabel wdw_segment7_end

.include "levels/wdw_level.s"

.align 4, 0
.global jrb_segment7
jrb_segment7:
.incbin "build/mio0/jrb_segment7.mio0"
glabel jrb_segment7_end

.include "levels/jrb_level.s"

.align 4, 0
.global thi_segment7
thi_segment7:
.incbin "build/mio0/thi_segment7.mio0"
glabel thi_segment7_end

.include "levels/thi_level.s"

.align 4, 0
.global ttc_segment7
ttc_segment7:
.incbin "build/mio0/ttc_segment7.mio0"
glabel ttc_segment7_end

.include "levels/ttc_level.s"

.align 4, 0
.global rr_segment7
rr_segment7:
.incbin "build/mio0/rr_segment7.mio0"
glabel rr_segment7_end

.include "levels/rr_level.s"

.align 4, 0
.global castle_grounds_segment7
castle_grounds_segment7:
.incbin "build/mio0/castle_grounds_segment7.mio0"
glabel castle_grounds_segment7_end

.include "levels/castle_grounds_level.s"

.align 4, 0
.global bidw_segment7
bidw_segment7:
.incbin "build/mio0/bidw_segment7.mio0"
glabel bidw_segment7_end

.include "levels/bidw_level.s"

.align 4, 0
.global vanish_cap_segment7
vanish_cap_segment7:
.incbin "build/mio0/vanish_cap_segment7.mio0"
glabel vanish_cap_segment7_end

.include "levels/vanish_cap_level.s"

.align 4, 0
.global bifs_segment7
bifs_segment7:
.incbin "build/mio0/bifs_segment7.mio0"
glabel bifs_segment7_end

.include "levels/bifs_level.s"

.align 4, 0
.global secret_aquarium_segment7
secret_aquarium_segment7:
.incbin "build/mio0/secret_aquarium_segment7.mio0"
glabel secret_aquarium_segment7_end

.include "levels/secret_aquarium_level.s"

.align 4, 0
.global bits_segment7
bits_segment7:
.incbin "build/mio0/bits_segment7.mio0"
glabel bits_segment7_end

.include "levels/bits_level.s"

.align 4, 0
.global lll_segment7
lll_segment7:
.incbin "build/mio0/lll_segment7.mio0"
glabel lll_segment7_end

.include "levels/lll_level.s"

.align 4, 0
.global ddd_segment7
ddd_segment7:
.incbin "build/mio0/ddd_segment7.mio0"
glabel ddd_segment7_end

.include "levels/ddd_level.s"

.align 4, 0
.global wf_segment7
wf_segment7:
.incbin "build/mio0/wf_segment7.mio0"
glabel wf_segment7_end

.include "levels/wf_level.s"

.align 4, 0
.global cake_end
cake_end:
.incbin "build/mio0/cake_end.mio0"
.global cake_end_end
cake_end_end:

.include "levels/cake_end_level.s"

.align 4, 0
.global castle_courtyard_segment7
castle_courtyard_segment7:
.incbin "build/mio0/castle_courtyard_segment7.mio0"
glabel castle_courtyard_segment7_end

.include "levels/castle_courtyard_level.s"

.align 4, 0
.global secret_slide_segment7
secret_slide_segment7:
.incbin "build/mio0/secret_slide_segment7.mio0"
glabel secret_slide_segment7_end

.include "levels/secret_slide_level.s"

.align 4, 0
.global metal_cap_segment7
metal_cap_segment7:
.incbin "build/mio0/metal_cap_segment7.mio0"
glabel metal_cap_segment7_end

.include "levels/metal_cap_level.s"

.align 4, 0
.global wing_cap_segment7
wing_cap_segment7:
.incbin "build/mio0/wing_cap_segment7.mio0"
glabel wing_cap_segment7_end

.include "levels/wing_cap_level.s"

.align 4, 0
.global bidw_platform_segment7
bidw_platform_segment7:
.incbin "build/mio0/bidw_platform_segment7.mio0"
glabel bidw_platform_segment7_end

.include "levels/bidw_platform_level.s"

.align 4, 0
.global rainbow_bonus_segment7
rainbow_bonus_segment7:
.incbin "build/mio0/rainbow_bonus_segment7.mio0"
glabel rainbow_bonus_segment7_end

.include "levels/rainbow_bonus_level.s"

.align 4, 0
.global bifs_platform_segment7
bifs_platform_segment7:
.incbin "build/mio0/bifs_platform_segment7.mio0"
glabel bifs_platform_segment7_end

.include "levels/bifs_platform_level.s"

.align 4, 0
.global bits_platform_segment7
bits_platform_segment7:
.incbin "build/mio0/bits_platform_segment7.mio0"
glabel bits_platform_segment7_end

.include "levels/bits_platform_level.s"

.align 4, 0
.global ttm_segment7
ttm_segment7:
.incbin "build/mio0/ttm_segment7.mio0"
glabel ttm_segment7_end

.include "levels/ttm_level.s"
