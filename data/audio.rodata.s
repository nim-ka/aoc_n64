.include "macros.inc"


.section .rodata

#audio data
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

.ifdef VERSION_JP
glabel D_80337C20
	.incbin "bin/rodata.bin", 0x31B0, 0x8

glabel D_80337C28
	.incbin "bin/rodata.bin", 0x31B8, 0x8

glabel D_80337C30
	.incbin "bin/rodata.bin", 0x31C0, 0x8

glabel D_80337C38
	.incbin "bin/rodata.bin", 0x31C8, 0x8

glabel D_80337C40
	.incbin "bin/rodata.bin", 0x31D0, 0x8

glabel D_80337C48
	.incbin "bin/rodata.bin", 0x31D8, 0x8

glabel D_80337C50
	.incbin "bin/rodata.bin", 0x31E0, 0x10
.else
	# TODO: Identify these.
glabel D_U_80338E00
	.word 0x4A2FC800

glabel D_U_80338E04
	.word 0x4185B439
	.word 0x00000000
	.word 0x00000000

glabel D_U_80338E10
	.word 0x407FFEB0

glabel D_U_80338E14
	.word 0x3836719F

glabel D_U_80338E18
	.word 0x3F85F3B6

glabel D_U_80338E1C
	.word 0x3F05F3B6

glabel D_U_80338E20
	.word 0x3E867770

glabel D_U_80338E24
	.word 0x3E05F30E
	.word 0x00000000
	.word 0x00000000
.endif	

glabel jtbl_80337C60
.ifdef VERSION_JP
	.word L8031A5B0
	.word L8031A5B8
	.word L8031A5DC
	.word L8031A5F4
	.word L8031A6D8
	.word L8031A70C
	.word L8031A714
	.word L8031A714
	.word L8031A794
.else
	.word L_U_8031B5D8
	.word L_U_8031B5E0
	.word L_U_8031B604
	.word L_U_8031B61C
	.word L_U_8031B700
	.word L_U_8031B734
	.word L_U_8031B73C
	.word L_U_8031B73C
	.word L_U_8031B7BC
.endif

	.word 0
	.word 0
	.word 0

glabel jtbl_80337C90
.ifdef VERSION_JP
	.word L8031B2C0
	.word L8031B27C
	.word L8031B690
	.word L8031B690
	.word L8031B30C
	.word L8031B220
	.word L8031B690
	.word L8031B690
	.word L8031B1E4
.else
	.word L_U_8031C2DC
	.word L_U_8031C298
	.word L_U_8031C6A0
	.word L_U_8031C6A0
	.word L_U_8031C328
	.word L_U_8031C23C
	.word L_U_8031C6A0
	.word L_U_8031C6A0
	.word L_U_8031C200
.endif

glabel jtbl_80337CB4
.ifdef VERSION_JP
	.word L8031B350
	.word L8031B3A8
	.word L8031B444
	.word L8031B3D4
	.word L8031B3D4
	.word L8031B494
	.word L8031B5B8
	.word L8031B688
	.word L8031B3A8
	.word L8031B350
.else
	.word L_U_8031C36C
	.word L_U_8031C3BC
	.word L_U_8031C454
	.word L_U_8031C3E8
	.word L_U_8031C3E8
	.word L_U_8031C4A4
	.word L_U_8031C5C8
	.word L_U_8031C698
	.word L_U_8031C3BC
	.word L_U_8031C36C
.endif

glabel jtbl_80337CDC
.ifdef VERSION_JP
	.word L8031BBE8
	.word L8031BBF4
	.word L8031BBE8
	.word L8031BBF4
	.word L8031BBE8
.else
	.word L_U_8031CBE0
	.word L_U_8031CBEC
	.word L_U_8031CBE0
	.word L_U_8031CBEC
	.word L_U_8031CBE0
.endif

.ifdef VERSION_JP
glabel D_80337CF0
	.incbin "bin/rodata.bin", 0x3280, 0x8
.endif

.ifdef VERSION_JP
glabel D_80337CF8
	.incbin "bin/rodata.bin", 0x3288, 0x8
.endif

.ifdef VERSION_JP
glabel D_80337D00
	.incbin "bin/rodata.bin", 0x3290, 0x8
.endif

glabel jtbl_80337D08 # US: 80338EC0
.ifdef VERSION_JP
	.word L8031C430
	.word L8031C3DC
	.word L8031C44C
	.word L8031C45C
	.word L8031C3F8
	.word L8031C6C8
	.word L8031C724
	.word L8031C75C
	.word L8031C75C
	.word L8031C7A8
	.word L8031C7B8
	.word L8031C75C
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C7D8
	.word L8031C7FC
	.word L8031C80C
	.word L8031C508
	.word L8031C6B8
	.word L8031C1CC
	.word L8031C698
	.word L8031C600
	.word L8031C5E4
	.word L8031C5D4
	.word L8031C5B8
	.word L8031C5A0
	.word L8031C568
	.word L8031C530
	.word L8031C4C0
	.word L8031C46C
	.word L8031C488
	.word L8031C650
	.word L8031C61C
	.word L8031C684
	.word L8031C820
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C3CC
	.word L8031C3A4
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C34C
	.word L8031C33C
	.word L8031C2F4
	.word L8031C2BC
	.word L8031C34C
	.word L8031C34C
	.word L8031C34C
	.word L8031C280
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
.else
	.word L_U_8031D3A8
	.word L_U_8031D354
	.word L_U_8031D3C4
	.word L_U_8031D3D4
	.word L_U_8031D370
	.word L_U_8031D5E4
	.word L_U_8031D640
	.word L_U_8031D678
	.word L_U_8031D678
	.word L_U_8031D6C4
	.word L_U_8031D6D4
	.word L_U_8031D678
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D6F4
	.word L_U_8031D718
	.word L_U_8031D728
	.word L_U_8031D44C
	.word L_U_8031D5D4
	.word L_U_8031D144
	.word L_U_8031D5B4
	.word L_U_8031D51C
	.word L_U_8031D500
	.word L_U_8031D4F0
	.word L_U_8031D4D4
	.word L_U_8031D4BC
	.word L_U_8031D498
	.word L_U_8031D474
	.word L_U_8031D424
	.word L_U_8031D3E4
	.word L_U_8031D400
	.word L_U_8031D56C
	.word L_U_8031D538
	.word L_U_8031D5A0
	.word L_U_8031D73C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D344
	.word L_U_8031D31C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D2C4
	.word L_U_8031D2B4
	.word L_U_8031D26C
	.word L_U_8031D234
	.word L_U_8031D2C4
	.word L_U_8031D2C4
	.word L_U_8031D2C4
	.word L_U_8031D1F8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
.endif

glabel jtbl_80337E04 # US: 80338FBC
.ifdef VERSION_JP
	.word L8031C89C
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C9E4
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA14
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA30
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA58
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8F8
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C9DC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8DC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C914
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C960
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C97C
.else
	.word L_U_8031D7B8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D900
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D930
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D94C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D974
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D814
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D8F8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D7E8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D7F8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D830
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D87C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D898
.endif

.ifdef VERSION_JP
glabel D_803380C8
	.incbin "bin/rodata.bin", 0x3658, 0x8
.endif

glabel jtbl_803380D0 # US: 80339280
.ifdef VERSION_JP
	.word L8031D204
	.word L8031D1F4
	.word L8031CD54
	.word L8031CD54
	.word L8031D1E4
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D1D4
	.word L8031D1A0
	.word L8031D1A0
	.word L8031D190
	.word L8031D180
	.word L8031D150
	.word L8031D134
	.word L8031D118
	.word L8031CD54
	.word L8031CD54
	.word L8031D0E0
	.word L8031CFE4
	.word L8031CF74
	.word L8031CF74
	.word L8031CF54
	.word L8031CF50
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CF40
	.word L8031CF18
	.word L8031CD54
	.word L8031CD54
	.word L8031CEB8
	.word L8031CD54
	.word L8031CE70
	.word L8031CE38
	.word L8031CEB8
	.word L8031CEB8
	.word L8031CEB8
	.word L8031CDFC
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
.else
	.word L_U_8031E0C0
	.word L_U_8031E0B0
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031E0A0
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031E090
	.word L_U_8031E05C
	.word L_U_8031E05C
	.word L_U_8031E04C
	.word L_U_8031E03C
	.word L_U_8031E014
	.word L_U_8031DFF8
	.word L_U_8031DFDC
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DFB0
	.word L_U_8031DF14
	.word L_U_8031DE8C
	.word L_U_8031DE8C
	.word L_U_8031DE6C
	.word L_U_8031DE68
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DE58
	.word L_U_8031DE30
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DDD0
	.word L_U_8031DC6C
	.word L_U_8031DD88
	.word L_U_8031DD50
	.word L_U_8031DDD0
	.word L_U_8031DDD0
	.word L_U_8031DDD0
	.word L_U_8031DD14
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
.endif

glabel jtbl_803381B0 # US: 80339360
.ifdef VERSION_JP
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2D8
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2E4
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2EC
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031D2F4
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
	.word L8031CD54
.else
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031E194
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031E1A0
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031E1A8
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031E1B0
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
	.word L_U_8031DC6C
.endif

	# padding
	.word 0, 0, 0

# audio interface 2

.ifdef VERSION_US
glabel D_U_803394F0
	.incbin "bin/rodata_audio_us.bin", 0x0, 0x1E8
.endif

glabel D_80338370 # "DAC: Lost 1 frame"
	.incbin "bin/rodata.bin", 0x38D0, 0x38

glabel D_80338378
	.incbin "bin/rodata.bin", 0x3908, 0x8

glabel D_80338380
	.incbin "bin/rodata.bin", 0x3910, 0x8

.ifdef VERSION_JP
glabel D_80338388
	.incbin "bin/rodata.bin", 0x3918, 0x8

glabel D_80338390
	.incbin "bin/rodata.bin", 0x3920, 0x4

glabel D_80338394
	.incbin "bin/rodata.bin", 0x3924, 0x4

glabel D_80338398
	.incbin "bin/rodata.bin", 0x3928, 0x8

glabel D_803383A0
	.incbin "bin/rodata.bin", 0x3930, 0x8

glabel D_803383A8
	.incbin "bin/rodata.bin", 0x3938, 0x8

glabel D_803383B0
	.incbin "bin/rodata.bin", 0x3940, 0x4
.else
# TODO: Remove these symbols once the ifdef code uses the above symbols below.

glabel D_U_80339720
glabel D_80338388 
	.word 0x46ABE000

glabel D_U_80339724
glabel D_80338390
	.word 0x472BE000

glabel D_U_80339728
glabel D_80338394
	.word 0x472BE000

glabel D_U_8033972C
glabel D_80338398
	.word 0x46ABE000

glabel D_U_80339730
glabel D_803383A0
	.word 0x3DA3D70A

glabel D_U_80339734
glabel D_803383A8
	.word 0x46ABE000

glabel D_U_80339738
glabel D_803383B0
	.word 0x3F666666
.endif

glabel jtbl_803383B4
.ifdef VERSION_JP
	.word L8031F244
	.word L8031F0B4
	.word L8031F244
	.word L8031F2A8
	.word L8031F2A8
	.word L8031F2A8
	.word L8031F2A8
	.word L8031F220
	.word L8031F2A8
	.word L8031F2A8
.else
	.word L_U_803200D4
	.word L_U_8031FF5C
	.word L_U_803200D4
	.word L_U_80320138
	.word L_U_80320138
	.word L_U_80320138
	.word L_U_80320138
	.word L_U_803200B0
	.word L_U_80320138
	.word L_U_80320138
.endif

glabel jtbl_803383DC
.ifdef VERSION_JP
	.word L8031F52C
	.word L8031F3A4
	.word L8031F52C
	.word L8031F590
	.word L8031F590
	.word L8031F590
	.word L8031F590
	.word L8031F50C
	.word L8031F590
	.word L8031F590
.else
	.word L_U_803203DC
	.word L_U_8032026C
	.word L_U_803203DC
	.word L_U_80320440
	.word L_U_80320440
	.word L_U_80320440
	.word L_U_80320440
	.word L_U_803203BC
	.word L_U_80320440
	.word L_U_80320440
.endif

.ifdef VERSION_US
glabel jtbl_U_8033978C
	.word L_U_80320A4C
	.word L_U_80320A8C
	.word L_U_80320ACC
	.word L_U_80320B0C
	.word L_U_80320B4C
	.word L_U_80320B8C
	.word L_U_80320BCC
	.word L_U_80320BF4
.endif

	.word 0 #align?

.ifdef VERSION_JP
glabel D_80338408
	.incbin "bin/rodata.bin", 0x3998, 0x8

glabel D_80338410
	.incbin "bin/rodata.bin", 0x39A0, 0x8
.else
# TODO: Remove these symbols once the ifdef code uses the above symbols below.
glabel D_U_803397B0
glabel D_80338408
	.word 0x3F91DF46

glabel D_U_803397B4
glabel D_80338410
	.word 0x9D353918, 0x00000000

	.word 0 # align?

glabel D_U_803397C0
	.word 0x80000000, 0x00000000

glabel D_U_803397C8
	.word 0x80000000, 0x00000000
	
glabel D_U_803397D0
	.word 0x3FF00000, 0x00000000

	# TODO: Place labels here
	.word 0xBFC55554
	.word 0xBC83656D
	.word 0x3F8110ED
	.word 0x3804C2A0
	.word 0xBF29F6FF
	.word 0xEEA56814
	.word 0x3EC5DBDF
	.word 0x0E314BFE

glabel D_U_803397F8
	.word 0x3FD45F30
	.word 0x6DC9C883

glabel D_U_80339800
	.word 0x400921FB
	.word 0x50000000

glabel D_U_80339808
	.word 0x3E6110B4
	.word 0x611A6263

glabel D_U_80339810
	.word 0x00000000
	.word 0x00000000

	.word 0x00000000
	.word 0x00000000

glabel D_803384B0
	.word 0x3FF00000
	.word 0x00000000
	.word 0xBFC55554
	.word 0xBC83656D

	.word 0x3F8110ED
	.word 0x3804C2A0
	.word 0xBF29F6FF
	.word 0xEEA56814

	.word 0x3EC5DBDF
	.word 0x0E314BFE

glabel D_803384D8
	.word 0x3FD45F30
	.word 0x6DC9C883

glabel D_803384E0
	.word 0x400921FB
	.word 0x50000000

glabel D_803384E8
	.word 0x3E6110B4
	.word 0x611A6263

glabel D_803384F0
	.word 0x00000000
	.word 0x00000000
	.word 0x00000000
	.word 0x00000000

glabel D_80338500
	.word 0x3C8EFA35
	.word 0x00000000
	.word 0x00000000
	.word 0x00000000

glabel D_80338510
	.word 0x686C4C00

glabel D_80338514
	.word 0x202B2D23
	.word 0x30000000

glabel D_8033851C
	.word 0x00000001
	.word 0x00000002
	.word 0x00000004
	.word 0x00000008
	.word 0x00000010
	.word 0x00000000

glabel D_U_AUDROEND
.endif

.ifdef VERSION_JP
glabel jtbl_80338418
	.word L8031FBAC
	.word L8031FBEC
	.word L8031FC2C
	.word L8031FC6C
	.word L8031FCAC
	.word L8031FCEC
	.word L8031FD2C
	.word L8031FD54

glabel D_80338438
	.incbin "bin/rodata.bin", 0x39C8, 0x8

glabel D_80338440
	.incbin "bin/rodata.bin", 0x39D0, 0x10

glabel D_80338450
	.word 0x80000000
	.word 0

glabel D_80338458
	.word 0x80000000
	.word 0

glabel D_80338460
	.incbin "bin/rodata.bin", 0x39F0, 0x28

glabel D_80338488
	.incbin "bin/rodata.bin", 0x3A18, 0x8

glabel D_80338490
	.incbin "bin/rodata.bin", 0x3A20, 0x8

glabel D_80338498
	.incbin "bin/rodata.bin", 0x3A28, 0x8

glabel D_803384A0
	.incbin "bin/rodata.bin", 0x3A30, 0x10

glabel D_803384B0
	.incbin "bin/rodata.bin", 0x3A40, 0x28

glabel D_803384D8
	.incbin "bin/rodata.bin", 0x3A68, 0x8

glabel D_803384E0
	.incbin "bin/rodata.bin", 0x3A70, 0x8

glabel D_803384E8
	.incbin "bin/rodata.bin", 0x3A78, 0x8

glabel D_803384F0
	.incbin "bin/rodata.bin", 0x3A80, 0x10

glabel D_80338500
	.incbin "bin/rodata.bin", 0x3A90, 0x10

glabel D_80338510
	.incbin "bin/rodata.bin", 0x3AA0, 0x4

glabel D_80338514
	.incbin "bin/rodata.bin", 0x3AA4, 0x8

glabel D_8033851C
	.incbin "bin/rodata.bin", 0x3AAC, 0x18
.else

# TODO: Resolve these.
glabel D_80338438
glabel D_80338450
glabel D_80338458
glabel D_80338460
glabel D_80338488
glabel D_80338490
glabel D_80338498
glabel D_803384A0

.endif

glabel jtbl_80338534
	.word L80326044
	.word L80326470
	.word L80326044
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80325E60
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80325C10
	.word L80325C60
	.word L80326044
	.word L80326044
	.word L80326044
	.word L80326470
	.word L80325C60
	.word L80326470
	.word L80326470
	.word L80326470
	.word L80326470
	.word L8032624C
	.word L80325E60
	.word L80326374
	.word L80326470
	.word L80326470
	.word L803263D8
	.word L80326470
	.word L80325E60
	.word L80326470
	.word L80326470
	.word L80325E60

	# padding
	.word 0, 0, 0

glabel D_80338610
	.incbin "bin/rodata.bin", 0x3BA0, 0x20

glabel jtbl_80338630
	.word L80326B9C
	.word L80326B64
	.word L80326B44
	.word L803269B8
	.word L80326984
	.word L80326AE8
	.word L80326BE8
	.word L80326BE8
	.word L80326964
	.word 0
	.word 0
	.word 0

glabel D_80338660
	.incbin "bin/rodata.bin", 0x3BF0, 0x10

glabel D_80338670
	.incbin "bin/rodata.bin", 0x3C00, 0x48

glabel D_803386B8
	.incbin "bin/rodata.bin", 0x3C48, 0x4

glabel D_803386BC
	.incbin "bin/rodata.bin", 0x3C4C, 0x4

glabel D_803386C0
	.incbin "bin/rodata.bin", 0x3C50, 0x8

glabel D_803386C8
	.incbin "bin/rodata.bin", 0x3C58, 0x8

glabel D_803386D0
	.incbin "bin/rodata.bin", 0x3C60, 0x80

glabel D_80338750
	.incbin "bin/rodata.bin", 0x3CE0, 0x800

glabel D_80338F50
	.incbin "bin/rodata.bin", 0x44E0, 0x2C0
glabel audio_data_end
