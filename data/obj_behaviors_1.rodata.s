.include "macros.inc"


.section .rodata

#obj behaviors
glabel D_80337360
    .incbin "bin/rodata.bin", 0x28F0, 0x8

glabel D_80337368
    .incbin "bin/rodata.bin", 0x28F8, 0x8

glabel D_80337370
    .incbin "bin/rodata.bin", 0x2900, 0x8
glabel D_80337378
    .incbin "bin/rodata.bin", 0x2908, 0x8
glabel D_80337380
    .incbin "bin/rodata.bin", 0x2910, 0x8
glabel D_80337388
    .incbin "bin/rodata.bin", 0x2918, 0x8

glabel D_80337390
    .incbin "bin/rodata.bin", 0x2920, 0x4

glabel D_80337394
    .incbin "bin/rodata.bin", 0x2924, 0x4

glabel D_80337398
    .incbin "bin/rodata.bin", 0x2928, 0x4

glabel D_8033739C
    .incbin "bin/rodata.bin", 0x292C, 0x4

glabel D_803373A0
    .incbin "bin/rodata.bin", 0x2930, 0x4

glabel D_803373A4
    .incbin "bin/rodata.bin", 0x2934, 0x4

glabel D_803373A8
    .incbin "bin/rodata.bin", 0x2938, 0x4

glabel D_803373AC
    .incbin "bin/rodata.bin", 0x293C, 0x4

glabel D_803373B0
    .incbin "bin/rodata.bin", 0x2940, 0x4

glabel D_803373B4
    .incbin "bin/rodata.bin", 0x2944, 0x4

glabel D_803373B8
    .incbin "bin/rodata.bin", 0x2948, 0x4

glabel jtbl_803373BC
    .word L802EAE84
    .word L802EAEF4
    .word L802EAF0C
    .word L802EAF24
    .word L802EAF3C
    .word L802EAF8C

    .word 0

glabel D_803373D8
    .incbin "bin/rodata.bin", 0x2968, 0x8

glabel D_803373E0
    .incbin "bin/rodata.bin", 0x2970, 0x8

glabel D_803373E8
    .incbin "bin/rodata.bin", 0x2978, 0x8

glabel D_803373F0
    .incbin "bin/rodata.bin", 0x2980, 0x8

glabel D_803373F8
    .incbin "bin/rodata.bin", 0x2988, 0x8

glabel D_80337400
    .incbin "bin/rodata.bin", 0x2990, 0x8
glabel D_80337408
    .incbin "bin/rodata.bin", 0x2998, 0x8

glabel D_80337410
    .incbin "bin/rodata.bin", 0x29A0, 0x8

glabel D_80337418
    .incbin "bin/rodata.bin", 0x29A8, 0x8

glabel D_80337420
    .incbin "bin/rodata.bin", 0x29B0, 0x4

glabel D_80337424
    .incbin "bin/rodata.bin", 0x29B4, 0x4

glabel D_80337428
    .incbin "bin/rodata.bin", 0x29B8, 0x4

glabel D_8033742C
    .incbin "bin/rodata.bin", 0x29BC, 0x4

glabel D_80337430
    .incbin "bin/rodata.bin", 0x29C0, 0x4

glabel D_80337434
    .incbin "bin/rodata.bin", 0x29C4, 0x4

glabel D_80337438
    .incbin "bin/rodata.bin", 0x29C8, 0x4

glabel D_8033743C
    .incbin "bin/rodata.bin", 0x29CC, 0x4

glabel D_80337440
    .incbin "bin/rodata.bin", 0x29D0, 0x4

glabel D_80337444
    .incbin "bin/rodata.bin", 0x29D4, 0x4

glabel D_80337448
    .incbin "bin/rodata.bin", 0x29D8, 0x4

glabel D_8033744C
    .incbin "bin/rodata.bin", 0x29DC, 0x4

glabel D_80337450
    .incbin "bin/rodata.bin", 0x29E0, 0x4

glabel D_80337454
    .incbin "bin/rodata.bin", 0x29E4, 0x4

glabel jtbl_80337458
    .word L802ED2C0
    .word L802ED340
    .word L802ED398
    .word L802ED3C8
    .word L802ED434

glabel jtbl_8033746C
    .word L802ED814
    .word L802ED814
    .word L802ED878
    .word L802ED8A8
    .word L802ED8B8
    .word L802ED8C8

glabel jtbl_80337484
    .word L802EDAA4
    .word L802EDAC4
    .word L802EDAE4
    .word L802EDB04
    .word L802EDB20

glabel D_80337498
    .incbin "bin/rodata.bin", 0x2A28, 0x8

glabel jtbl_803374A0
    .word L802EDD04
    .word L802EDD24
    .word L802EDD44
    .word L802EDD64
    .word L802EDD84

glabel D_803374B4
    .incbin "bin/rodata.bin", 0x2A44, 0x4

glabel D_803374B8
    .incbin "bin/rodata.bin", 0x2A48, 0x4

glabel D_803374BC
    .incbin "bin/rodata.bin", 0x2A4C, 0x4

glabel D_803374C0
    .incbin "bin/rodata.bin", 0x2A50, 0x4

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

    .incbin "bin/rodata.bin", 0x2BFC, 0xC

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

