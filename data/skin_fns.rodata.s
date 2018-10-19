.include "macros.inc"

.section .rodata


unref_801B85A0:
	.asciiz "reset_net %d\n"
	.balign 4, 0

glabel D_801B85B0
	.incbin "bin/sm64.j.255EC0.bin", 0x10EC0, 0xC

glabel D_801B85BC
	.incbin "bin/sm64.j.255EC0.bin", 0x10ECC, 0xC

glabel D_801B85C8
	.incbin "bin/sm64.j.255EC0.bin", 0x10ED8, 0xC

glabel D_801B85D4
	.incbin "bin/sm64.j.255EC0.bin", 0x10EE4, 0xC

glabel D_801B85E0
	.incbin "bin/sm64.j.255EC0.bin", 0x10EF0, 0x10

glabel D_801B85F0
	.incbin "bin/sm64.j.255EC0.bin", 0x10F00, 0xC

glabel D_801B85FC
	.incbin "bin/sm64.j.255EC0.bin", 0x10F0C, 0xC

glabel D_801B8608
	.incbin "bin/sm64.j.255EC0.bin", 0x10F18, 0xC

glabel D_801B8614
	.incbin "bin/sm64.j.255EC0.bin", 0x10F24, 0xC

glabel D_801B8620
	.incbin "bin/sm64.j.255EC0.bin", 0x10F30, 0x28

glabel D_801B8648
	.incbin "bin/sm64.j.255EC0.bin", 0x10F58, 0xC

glabel D_801B8654
	.incbin "bin/sm64.j.255EC0.bin", 0x10F64, 0xC

glabel D_801B8660
	.incbin "bin/sm64.j.255EC0.bin", 0x10F70, 0xC

glabel D_801B866C
	.incbin "bin/sm64.j.255EC0.bin", 0x10F7C, 0xC

glabel D_801B8678
	.incbin "bin/sm64.j.255EC0.bin", 0x10F88, 0x8

glabel D_801B8680
	.incbin "bin/sm64.j.255EC0.bin", 0x10F90, 0x8

glabel D_801B8688
	.incbin "bin/sm64.j.255EC0.bin", 0x10F98, 0x8

glabel D_801B8690
	.incbin "bin/sm64.j.255EC0.bin", 0x10FA0, 0x8

glabel D_801B8698
	.incbin "bin/sm64.j.255EC0.bin", 0x10FA8, 0xC

glabel D_801B86A4
	.incbin "bin/sm64.j.255EC0.bin", 0x10FB4, 0xC

glabel D_801B86B0
	.incbin "bin/sm64.j.255EC0.bin", 0x10FC0, 0x10

glabel D_801B86C0
	.incbin "bin/sm64.j.255EC0.bin", 0x10FD0, 0x10

glabel D_801B86D0
	.incbin "bin/sm64.j.255EC0.bin", 0x10FE0, 0x8

glabel D_801B86D8
	.incbin "bin/sm64.j.255EC0.bin", 0x10FE8, 0x8

glabel D_801B86E0
	.incbin "bin/sm64.j.255EC0.bin", 0x10FF0, 0xC

glabel D_801B86EC
	.incbin "bin/sm64.j.255EC0.bin", 0x10FFC, 0x10

glabel D_801B86FC
	.incbin "bin/sm64.j.255EC0.bin", 0x1100C, 0x10

glabel D_801B870C
	.incbin "bin/sm64.j.255EC0.bin", 0x1101C, 0x10

glabel D_801B871C
	.incbin "bin/sm64.j.255EC0.bin", 0x1102C, 0x8

glabel D_801B8724
	.incbin "bin/sm64.j.255EC0.bin", 0x11034, 0x14

glabel D_801B8738
	.incbin "bin/sm64.j.255EC0.bin", 0x11048, 0x10

glabel D_801B8748
	.incbin "bin/sm64.j.255EC0.bin", 0x11058, 0x8

glabel D_801B8750
	.incbin "bin/sm64.j.255EC0.bin", 0x11060, 0xC

glabel D_801B875C
	.incbin "bin/sm64.j.255EC0.bin", 0x1106C, 0x10

glabel D_801B876C
	.incbin "bin/sm64.j.255EC0.bin", 0x1107C, 0x10

glabel D_801B877C
	.incbin "bin/sm64.j.255EC0.bin", 0x1108C, 0x10

glabel D_801B878C
	.incbin "bin/sm64.j.255EC0.bin", 0x1109C, 0x14

glabel D_801B87A0
	.incbin "bin/sm64.j.255EC0.bin", 0x110B0, 0x8

glabel D_801B87A8
	.incbin "bin/sm64.j.255EC0.bin", 0x110B8, 0x8

glabel D_801B87B0
	.incbin "bin/sm64.j.255EC0.bin", 0x110C0, 0x8

glabel jtbl_801B87B8
	.word .L801935F0
	.word .L80193638
	.word .L80193664
	.word .L8019360C
	.word .L80193678
	.word .L8019368C
	.word .L801935F8

	.word 0, 0, 0
