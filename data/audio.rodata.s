.include "macros.inc"


.section .rodata

# playback_2
glabel jtbl_80337C60
.ifdef VERSION_JP
	.word L8031A5B0
	.word L8031A5B8
	.word L8031A5DC
	.word L8031A5F4
	.word L8031A6D8
	.word L8031A70C
	.word L8031A714
	.word L8031A714
	.word L8031A794
.else
	.word L_U_8031B5D8
	.word L_U_8031B5E0
	.word L_U_8031B604
	.word L_U_8031B61C
	.word L_U_8031B700
	.word L_U_8031B734
	.word L_U_8031B73C
	.word L_U_8031B73C
	.word L_U_8031B7BC
.endif

	.word 0
	.word 0
	.word 0
