.include "macros.inc"


.section .data

#screen_transition
glabel D_8032FF60
	.word 0

glabel D_8032FF64
	.word 0

glabel D_8032FF68
	.word seg2_texture_0200F458
	.word seg2_texture_0200FC58
	.word seg2_texture_02010458
	.word seg2_texture_02011458
