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
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B10, 0x4
	.word ccm_seg7_collision_070163F8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B18, 0x8

glabel D_803318CC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B20, 0x8
	.word ccm_seg7_trajectory_0701669C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B2C, 0x18

glabel D_803318F0
	.word bitdw_seg7_collision_0700F70C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B48, 0x8
	.word bob_seg7_collision_bridge
   .word bitfs_seg7_collision_07015928
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B58, 0xC

glabel D_80331910
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B64, 0x4

glabel D_80331914
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B68, 0x4

glabel D_80331918
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B6C, 0x4
	.word bitdw_seg7_collision_0700F7F0
	.word bitdw_seg7_collision_0700F898
	.incbin "bin/sm64.j.0EADAC.bin", 0x1B78, 0x4

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
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BB4, 0x8

glabel D_80331968
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BBC, 0x4

glabel D_8033196C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BC0, 0x10

glabel D_8033197C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BD0, 0x8

glabel D_80331984
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BD8, 0x8

glabel D_8033198C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BE0, 0x8

glabel D_80331994
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BE8, 0x4

glabel D_80331998
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BEC, 0x8

glabel D_803319A0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BF4, 0x4

glabel D_803319A4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BF8, 0x4

glabel D_803319A8
	.incbin "bin/sm64.j.0EADAC.bin", 0x1BFC, 0x8

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
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C78, 0x8
   .word bitfs_seg7_collision_07015714
   .word bitfs_seg7_collision_07015768
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C88, 0xC
	.word bitdw_seg7_collision_0700F688

glabel D_80331A44
	.incbin "bin/sm64.j.0EADAC.bin", 0x1C98, 0x8

glabel D_80331A4C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CA0, 0x8

glabel D_80331A54
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CA8, 0x4
glabel D_80331A58
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CAC, 0x24
	.word bitdw_seg7_collision_0700FD9C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CD4, 0x4
	.word bitdw_seg7_collision_0700FC7C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CDC, 0x4
	.word bitdw_seg7_collision_0700FB5C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CE4, 0x4
	.word bitdw_seg7_collision_0700FA3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CEC, 0x4
	.word bitdw_seg7_collision_0700F91C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1CF4, 0x2C

glabel D_80331ACC
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D20, 0x8

glabel D_80331AD4
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D28, 0x4
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
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F70, 0x10

glabel D_80331D2C
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F80, 0x14

