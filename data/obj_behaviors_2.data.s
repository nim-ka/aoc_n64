.include "macros.inc"


.section .data

#obj behaviors 2
glabel D_80331730
	.incbin "bin/sm64.j.0EADAC.bin", 0x1984, 0x10

glabel D_80331740
	.incbin "bin/sm64.j.0EADAC.bin", 0x1994, 0x8

glabel D_80331748
	.incbin "bin/sm64.j.0EADAC.bin", 0x199C, 0x8

glabel D_80331750
	.incbin "bin/sm64.j.0EADAC.bin", 0x19A4, 0x2

glabel D_80331752
	.incbin "bin/sm64.j.0EADAC.bin", 0x19A6, 0x2

glabel D_80331754
   .word bob_seg7_trajectory_koopa

glabel D_80331758
	.incbin "bin/sm64.j.0EADAC.bin", 0x19AC, 0xC
   .word thi_seg7_trajectory_koopa
	.incbin "bin/sm64.j.0EADAC.bin", 0x19BC, 0x8

glabel D_80331770
	.incbin "bin/sm64.j.0EADAC.bin", 0x19C4, 0x10

glabel D_80331780
	.incbin "bin/sm64.j.0EADAC.bin", 0x19D4, 0x8

glabel D_80331788
	.incbin "bin/sm64.j.0EADAC.bin", 0x19DC, 0x10

glabel D_80331798
	.incbin "bin/sm64.j.0EADAC.bin", 0x19EC, 0x10

glabel D_803317A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x19FC, 0x8

glabel D_803317B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A04, 0x10

glabel D_803317C0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A14, 0x4

glabel D_803317C4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A18, 0x4

glabel D_803317C8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A1C, 0x2

glabel D_803317CA
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A1E, 0x1A

glabel D_803317E4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A38, 0xC

glabel D_803317F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A44, 0x10

glabel D_80331800
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A54, 0x10

glabel D_80331810
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A64, 0x10

glabel D_80331820
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A74, 0x4

glabel D_80331824
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A78, 0x14

glabel D_80331838
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A8C, 0xC

glabel D_80331844
	.incbin "bin/sm64.j.0EADAC.bin", 0x1A98, 0x10

glabel D_80331854
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AA8, 0x8

glabel D_8033185C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AB0, 0x10

glabel D_8033186C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AC0, 0x8

glabel D_80331874
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AC8, 0x3

glabel D_80331877
	.incbin "bin/sm64.j.0EADAC.bin", 0x1ACB, 0x3

glabel D_8033187A
	.incbin "bin/sm64.j.0EADAC.bin", 0x1ACE, 0xE

glabel D_80331888
	.incbin "bin/sm64.j.0EADAC.bin", 0x1ADC, 0x10

glabel D_80331898
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AEC, 0x10

glabel D_803318A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1AFC, 0x14

glabel D_803318BC
   .word rr_seg7_collision_07029038
   .word ccm_seg7_collision_070163F8
   .word 0x0800D710
   .word bitfs_seg7_collision_070157E0

glabel D_803318CC
   .word rr_seg7_trajectory_0702EC3C
   .word rr_seg7_trajectory_0702ECC0
   .word ccm_seg7_trajectory_0701669C
   .word bitfs_seg7_trajectory_070159AC
   .word hmc_seg7_arr_702B86C
   .word lll_seg7_trajectory_0702856C
   .word lll_seg7_trajectory_07028660
   .word rr_seg7_trajectory_0702ED9C
   .word rr_seg7_trajectory_0702EEE0

glabel D_803318F0
   .word bitdw_seg7_collision_0700F70C
   .word bits_seg7_collision_0701ADD8
   .word bits_seg7_collision_0701AE5C
   .word bob_seg7_collision_bridge
   .word bitfs_seg7_collision_07015928
   .word rr_seg7_collision_07029750
   .word rr_seg7_collision_07029858
   .word vcutm_seg7_collision_0700AC44

glabel D_80331910
	.word bits_seg7_collision_0701ACAC

glabel D_80331914
	.word bits_seg7_collision_0701AC28

glabel D_80331918
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B6C, 0x4
	.word bitdw_seg7_collision_0700F7F0
	.word bitdw_seg7_collision_0700F898
	.word 0x003A0000

glabel D_80331928
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B7C, 0x10

glabel D_80331938
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B8C, 0x3

glabel D_8033193B
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B8F, 0x2

glabel D_8033193D
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B91, 0x1

glabel D_8033193E
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B92, 0xE

glabel D_8033194C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BA0, 0x14

glabel D_80331960
   .word ttc_seg7_collision_07014F70
   .word ttc_seg7_collision_07015008

glabel D_80331968
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BBC, 0x4

glabel D_8033196C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC0, 0x10

glabel D_8033197C
   .word ttc_seg7_collision_070152B4
   .word ttc_seg7_collision_070153E0

glabel D_80331984
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BD8, 0x8

glabel D_8033198C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BE0, 0x8

glabel D_80331994
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BE8, 0x4

glabel D_80331998
   .word ttc_seg7_collision_07015584
   .word ttc_seg7_collision_07015650

glabel D_803319A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BF4, 0x4

glabel D_803319A4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BF8, 0x4

glabel D_803319A8
   .word ttc_seg7_collision_07015754
   .word ttc_seg7_collision_070157D8

glabel D_803319B0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C04, 0x2

glabel D_803319B2
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C06, 0x1E

glabel D_803319D0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C24, 0x4

glabel D_803319D4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C28, 0x4

glabel D_803319D8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C2C, 0x10

glabel D_803319E8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C3C, 0x8

glabel D_803319F0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C44, 0x10

glabel D_80331A00
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C54, 0x1

glabel D_80331A01
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C55, 0x2

glabel D_80331A03
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C57, 0x1

glabel D_80331A04
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C58, 0x2

glabel D_80331A06
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C5A, 0x6
glabel D_80331A0C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C60, 0x8

glabel D_80331A14
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C68, 0x10

glabel D_80331A24
   .word bits_seg7_collision_0701A9A0
   .word bits_seg7_collision_0701AA0C
   .word bitfs_seg7_collision_07015714
   .word bitfs_seg7_collision_07015768
   .word rr_seg7_collision_070295F8
   .word rr_seg7_collision_0702967C
   .word 0x0
	.word bitdw_seg7_collision_0700F688

glabel D_80331A44
   .word bits_seg7_collision_0701AA84
   .word rr_seg7_collision_07029508

glabel D_80331A4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CA0, 0x8

glabel D_80331A54
   .word bits_seg7_collision_0701B734
glabel D_80331A58
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CAC, 0x4
   .word bits_seg7_collision_0701B59C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CB4, 0x4
   .word bits_seg7_collision_0701B404
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CBC, 0x4
   .word bits_seg7_collision_0701B26C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CC4, 0x4
   .word bits_seg7_collision_0701B0D4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CCC, 0x4
	.word bitdw_seg7_collision_0700FD9C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CD4, 0x4
	.word bitdw_seg7_collision_0700FC7C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CDC, 0x4
	.word bitdw_seg7_collision_0700FB5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CE4, 0x4
	.word bitdw_seg7_collision_0700FA3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CEC, 0x4
	.word bitdw_seg7_collision_0700F91C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CF4, 0x4
   .word rr_seg7_collision_0702A6B4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CFC, 0x4
   .word rr_seg7_collision_0702A32C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D04, 0x4
   .word rr_seg7_collision_07029FA4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D0C, 0x4
   .word rr_seg7_collision_07029C1C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D14, 0x4
   .word rr_seg7_collision_07029924
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D1C, 0x4

glabel D_80331ACC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D20, 0x8

glabel D_80331AD4
   .word bits_seg7_collision_0701AD54
   .word bitfs_seg7_collision_070157E0 
   .word bitfs_seg7_collision_07015124

glabel D_80331AE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D34, 0x10

glabel D_80331AF0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D44, 0x10

glabel D_80331B00
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D54, 0x10

glabel D_80331B10
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D64, 0x10

glabel D_80331B20
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D74, 0x10

glabel D_80331B30
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D84, 0xC

glabel D_80331B3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D90, 0x10

glabel D_80331B4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DA0, 0x10

glabel D_80331B5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DB0, 0x8

glabel D_80331B64
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DB8, 0x10

glabel D_80331B74
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DC8, 0x10

glabel D_80331B84
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DD8, 0x10

glabel D_80331B94
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DE8, 0x10

glabel D_80331BA4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DF8, 0x8

glabel D_80331BAC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E00, 0x10

glabel D_80331BBC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E10, 0x4

glabel D_80331BC0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E14, 0x4

glabel D_80331BC4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E18, 0x1C

glabel D_80331BE0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E34, 0x8

glabel D_80331BE8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E3C, 0x18

glabel D_80331C00
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E54, 0x2

glabel D_80331C02
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E56, 0x16

glabel D_80331C18
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E6C, 0x10

glabel D_80331C28
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E7C, 0x10

glabel D_80331C38
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E8C, 0x10

glabel D_80331C48
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E9C, 0x2

glabel D_80331C4A
	.incbin "bin/sm64.j.0EADAC.bin", 0x1E9E, 0x2

glabel D_80331C4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1EA0, 0xB8

glabel D_80331D04
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F58, 0x10

glabel D_80331D14
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F68, 0x4

glabel D_80331D18
	.word 0

glabel D_80331D1C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F70, 0xB
.ifdef VERSION_JP
	.byte 0xBC
.else
	.byte 0xDC
.endif
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F7C, 0x4

glabel D_80331D2C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F80, 0x10
