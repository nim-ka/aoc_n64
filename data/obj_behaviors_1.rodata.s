.include "macros.inc"


.section .rodata

#obj behaviors

.ifdef VERSION_US # these arent actually US exclusive, but it's part of a hack to keep the US ROM OK while it was being differed via scripts, otherwise, this object is in the wrong spot.
glabel D_803374B8
    .incbin "bin/rodata.bin", 0x2A48, 0x4 # 45 DA C0 00 (7000.0f)

glabel D_803374BC
    .incbin "bin/rodata.bin", 0x2A4C, 0x4 # 45 BB 80 00 (6000.0f)
.endif
glabel D_803374C0
    .incbin "bin/rodata.bin", 0x2A50, 0x4 # C0 A3 D7 0A

glabel D_803374C4
    .incbin "bin/rodata.bin", 0x2A54, 0x4

glabel D_803374C8
    .incbin "bin/rodata.bin", 0x2A58, 0x4

glabel D_803374CC
    .incbin "bin/rodata.bin", 0x2A5C, 0x4

glabel D_803374D0
    .incbin "bin/rodata.bin", 0x2A60, 0x4

glabel D_803374D4
    .incbin "bin/rodata.bin", 0x2A64, 0x4

glabel D_803374D8
    .incbin "bin/rodata.bin", 0x2A68, 0x8

glabel D_803374E0
    .incbin "bin/rodata.bin", 0x2A70, 0x8

glabel D_803374E8
    .incbin "bin/rodata.bin", 0x2A78, 0x8

glabel D_803374F0
    .incbin "bin/rodata.bin", 0x2A80, 0x8

glabel D_803374F8
    .incbin "bin/rodata.bin", 0x2A88, 0x4

glabel D_803374FC
    .incbin "bin/rodata.bin", 0x2A8C, 0x4

glabel D_80337500
    .incbin "bin/rodata.bin", 0x2A90, 0x4

glabel D_80337504
    .incbin "bin/rodata.bin", 0x2A94, 0x4

glabel jtbl_80337508
    .word L802F0044
    .word L802F00DC
    .word L802F0108
    .word L802F0134
    .word L802F0144

glabel D_8033751C
    .incbin "bin/rodata.bin", 0x2AAC, 0x4

glabel D_80337520
    .incbin "bin/rodata.bin", 0x2AB0, 0x4

glabel D_80337524
    .incbin "bin/rodata.bin", 0x2AB4, 0x4

glabel D_80337528
    .incbin "bin/rodata.bin", 0x2AB8, 0x4

glabel D_8033752C
    .incbin "bin/rodata.bin", 0x2ABC, 0x4

glabel D_80337530
    .incbin "bin/rodata.bin", 0x2AC0, 0x4

glabel jtbl_80337534
    .word L802F0358
    .word L802F0394
    .word L802F039C
    .word L802F03D0
    .word L802F043C

glabel D_80337548
    .incbin "bin/rodata.bin", 0x2AD8, 0x4

glabel D_8033754C
    .incbin "bin/rodata.bin", 0x2ADC, 0x4

glabel D_80337550
    .incbin "bin/rodata.bin", 0x2AE0, 0x4

glabel D_80337554
    .incbin "bin/rodata.bin", 0x2AE4, 0x4

glabel D_80337558
    .incbin "bin/rodata.bin", 0x2AE8, 0x8

glabel jtbl_80337560
    .word L802F0A0C
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0A20
    .word L802F0A20
    .word L802F0ABC
    .word L802F0A4C
    .word L802F0A4C
    .word L802F0A20
    .word L802F0A4C
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0B58
    .word L802F0AE8

glabel D_803375F0
    .incbin "bin/rodata.bin", 0x2B80, 0x4

glabel D_803375F4
    .incbin "bin/rodata.bin", 0x2B84, 0x4

glabel D_803375F8
    .incbin "bin/rodata.bin", 0x2B88, 0x8

glabel D_80337600
    .incbin "bin/rodata.bin", 0x2B90, 0x8

glabel D_80337608
    .incbin "bin/rodata.bin", 0x2B98, 0x8

glabel D_80337610
    .incbin "bin/rodata.bin", 0x2BA0, 0x4

glabel D_80337614
    .incbin "bin/rodata.bin", 0x2BA4, 0x4

glabel D_80337618
    .incbin "bin/rodata.bin", 0x2BA8, 0x4

glabel D_8033761C
    .incbin "bin/rodata.bin", 0x2BAC, 0x4

glabel D_80337620
    .incbin "bin/rodata.bin", 0x2BB0, 0x4

glabel D_80337624
    .incbin "bin/rodata.bin", 0x2BB4, 0x4

glabel D_80337628
    .incbin "bin/rodata.bin", 0x2BB8, 0x4

glabel D_8033762C
    .incbin "bin/rodata.bin", 0x2BBC, 0x4

glabel D_80337630
    .incbin "bin/rodata.bin", 0x2BC0, 0x4

glabel D_80337634
    .incbin "bin/rodata.bin", 0x2BC4, 0x4

glabel D_80337638
    .incbin "bin/rodata.bin", 0x2BC8, 0x8

glabel D_80337640
    .incbin "bin/rodata.bin", 0x2BD0, 0x8

glabel D_80337648
    .incbin "bin/rodata.bin", 0x2BD8, 0x8

glabel D_80337650
    .incbin "bin/rodata.bin", 0x2BE0, 0x8

glabel jtbl_80337658
    .word L802F4588
    .word L802F4610
    .word L802F4758
    .word L802F48A0
    .word L802F49E8
    .word L802F4B30
    .word L802F4B48
    .word 0

glabel D_80337678
    .incbin "bin/rodata.bin", 0x2C08, 0x8

glabel D_80337680
    .incbin "bin/rodata.bin", 0x2C10, 0x8

glabel D_80337688
    .incbin "bin/rodata.bin", 0x2C18, 0x8

glabel D_80337690
    .incbin "bin/rodata.bin", 0x2C20, 0x8

glabel D_80337698
    .incbin "bin/rodata.bin", 0x2C28, 0x8

glabel D_803376A0
    .incbin "bin/rodata.bin", 0x2C30, 0x8

glabel D_803376A8
    .incbin "bin/rodata.bin", 0x2C38, 0x8

glabel D_803376B0
    .incbin "bin/rodata.bin", 0x2C40, 0x8

glabel D_803376B8
    .incbin "bin/rodata.bin", 0x2C48, 0x8

glabel D_803376C0
    .incbin "bin/rodata.bin", 0x2C50, 0x8

glabel D_803376C8
    .incbin "bin/rodata.bin", 0x2C58, 0x8

glabel D_803376D0
    .incbin "bin/rodata.bin", 0x2C60, 0x8

glabel D_803376D8
    .incbin "bin/rodata.bin", 0x2C68, 0x8

glabel D_803376E0
    .incbin "bin/rodata.bin", 0x2C70, 0x8

glabel D_803376E8
    .incbin "bin/rodata.bin", 0x2C78, 0x8

glabel D_803376F0
    .incbin "bin/rodata.bin", 0x2C80, 0x8

glabel D_803376F8
    .incbin "bin/rodata.bin", 0x2C88, 0x8

glabel D_80337700
    .incbin "bin/rodata.bin", 0x2C90, 0x8

glabel D_80337708
    .incbin "bin/rodata.bin", 0x2C98, 0x8

glabel D_80337710
    .incbin "bin/rodata.bin", 0x2CA0, 0x8

glabel D_80337718
    .incbin "bin/rodata.bin", 0x2CA8, 0x4

glabel D_8033771C
    .incbin "bin/rodata.bin", 0x2CAC, 0x4

glabel D_80337720
    .incbin "bin/rodata.bin", 0x2CB0, 0x8

glabel D_80337728
    .incbin "bin/rodata.bin", 0x2CB8, 0x8

glabel D_80337730
    .incbin "bin/rodata.bin", 0x2CC0, 0x8

glabel D_80337738
    .incbin "bin/rodata.bin", 0x2CC8, 0x4

glabel D_8033773C
    .incbin "bin/rodata.bin", 0x2CCC, 0x4

glabel D_80337740
    .incbin "bin/rodata.bin", 0x2CD0, 0x4

glabel D_80337744
    .incbin "bin/rodata.bin", 0x2CD4, 0x4

glabel D_80337748
    .incbin "bin/rodata.bin", 0x2CD8, 0x4

glabel D_8033774C
    .incbin "bin/rodata.bin", 0x2CDC, 0x4

glabel D_80337750
    .incbin "bin/rodata.bin", 0x2CE0, 0x4

glabel D_80337754
    .incbin "bin/rodata.bin", 0x2CE4, 0x4

glabel jtbl_80337758
    .word L802F7A3C
    .word L802F7A4C
    .word L802F7A5C
    .word L802F7A6C
    .word L802F7A7C

glabel D_8033776C
    .incbin "bin/rodata.bin", 0x2CFC, 0x4

glabel D_80337770
    .incbin "bin/rodata.bin", 0x2D00, 0x4

glabel D_80337774
    .incbin "bin/rodata.bin", 0x2D04, 0x4

glabel D_80337778
    .incbin "bin/rodata.bin", 0x2D08, 0x8

glabel D_80337780
    .incbin "bin/rodata.bin", 0x2D10, 0x4

glabel D_80337784
    .incbin "bin/rodata.bin", 0x2D14, 0x4

glabel D_80337788
    .incbin "bin/rodata.bin", 0x2D18, 0x4

glabel D_8033778C
    .incbin "bin/rodata.bin", 0x2D1C, 0x4

glabel jtbl_80337790
    .word L802F85E4
    .word L802F85F4
    .word L802F8604
    .word L802F8614
    .word L802F8624
    .word L802F8634
    .word L802F8654
    .word L802F8654
    .word L802F8654
    .word L802F8654
    .word L802F8644

	.word 0
	.ifdef VERSION_US
	.word 0, 0
	.endif
