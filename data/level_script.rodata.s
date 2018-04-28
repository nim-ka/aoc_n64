.include "macros.inc"
.include "globals.inc"

.section .rodata

#level script
glabel jtbl_8038BAF0
	.word .L8037E1D4
	.word .L8037E1EC
	.word .L8037E20C
	.word .L8037E228
	.word .L8037E244
	.word .L8037E25C
	.word .L8037E278
	.word .L8037E290

glabel jtbl_8038BB10
	.word .L80380478
	.word .L80380490
	.word .L803804A8
	.word .L803804C0
	.word .L803804D8

glabel jtbl_8038BB24
	.word .L80380528
	.word .L80380540
	.word .L80380558
	.word .L80380570
	.word .L80380588

	.word 0, 0 #hmm. why doesnt this file pad to 0x10?



