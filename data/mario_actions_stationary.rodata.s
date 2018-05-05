.include "macros.inc"


.section .rodata

#mario actions stationary
glabel D_803357D0
	.incbin "bin/rodata.bin", 0xD60, 0x4

glabel D_803357D4
	.incbin "bin/rodata.bin", 0xD64, 0x4

glabel jtbl_803357D8
	.word L8026372C
	.word L80263740
	.word L802639FC
	.word L802639FC
	.word L8026377C
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802637E0
	.word L802637F4
	.word L80263808

glabel jtbl_80335804
	.word L8026381C
	.word L80263830
	.word L80263844
	.word L80263858
	.word L8026386C

glabel jtbl_80335818
	.word L802638A8
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802638BC
	.word L802638D0
	.word L802638E4
	.word L802638F8
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639C0
	.word L802639D4

glabel jtbl_80335878
	.word L80263880
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L80263984
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L8026390C
	.word L80263920
	.word L802639FC
	.word L802639FC
	.word L802639FC
	.word L80263948
	.word L80263970
	.word L80263998

	.word 0, 0, 0

