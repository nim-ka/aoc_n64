.include "macros.inc"

.section .rodata

glabel D_80337BB0
.ifdef VERSION_JP
	.incbin "bin/rodata.bin", 0x3140, 0x8
.else
	.word 0x3FFFFEB0, 0x3FFFFEB0
.endif

glabel D_80337BB8
.ifdef VERSION_JP
	.incbin "bin/rodata.bin", 0x3148, 0x8
.else
	.word 0x407FFEDA, 0x407FFEDA
.endif

glabel D_80337BC0
.ifdef VERSION_JP
	.incbin "bin/rodata.bin", 0x3150, 0x8
.else
	.word 0x3F34FDF4, 0x00000000
.endif

.ifdef VERSION_US
	.word 0, 0 # this needs to be an align but w/e.
.endif
	
.ifdef VERSION_JP
glabel D_80337BC8
	.incbin "bin/rodata.bin", 0x3158, 0x8
.endif

.ifdef VERSION_JP
glabel D_80337BD0
	.incbin "bin/rodata.bin", 0x3160, 0x8
.endif

.ifdef VERSION_JP
glabel D_80337BD8
	.incbin "bin/rodata.bin", 0x3168, 0x8
.endif
