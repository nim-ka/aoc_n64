.include "macros.inc"


.section .data

#screen_transition
glabel D_8032FF60
	.word 0

glabel D_8032FF64
	.word 0

glabel D_8032FF68
.ifdef VERSION_JP
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC, 0x18
.else
	.word 0x020122B8, 0x02012AB8, 0x020132B8, 0x020142B8, 0, 0
.endif
