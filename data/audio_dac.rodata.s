.include "macros.inc"

.section .rodata

glabel jtbl_80337BE0
.ifdef VERSION_JP
	.word L80316BD0
	.word L80316BDC
	.word L80316C1C
	.word L80316BEC
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316BFC
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C1C
	.word L80316C0C
.else
	.word L80317BF0
	.word L80317BFC
	.word L80317C3C
	.word L80317C0C
	.word L80317C3C
	.word L80317C3C
	.word L80317C3C
	.word L80317C1C
	.word L80317C3C
	.word L80317C3C
	.word L80317C3C
	.word L80317C3C
	.word L80317C3C
	.word L80317C3C
	.word L80317C3C
	.word L80317C2C
.endif

.ifdef VERSION_US
glabel D_U_80338E00
	.word 0x4A2FC800

glabel D_U_80338E04
	.word 0x4185B439
.endif
