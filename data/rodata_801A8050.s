.include "macros.inc"

.section .rodata

#not game over 2

glabel D_801A8050
	.incbin "bin/sm64.j.255EC0.bin", 0x960, 0x8

glabel D_801A8058
	.incbin "bin/sm64.j.255EC0.bin", 0x968, 0x4

glabel D_801A805C
	.incbin "bin/sm64.j.255EC0.bin", 0x96C, 0x14

glabel D_801A8070
	.incbin "bin/sm64.j.255EC0.bin", 0x980, 0xC

glabel D_801A807C
	.incbin "bin/sm64.j.255EC0.bin", 0x98C, 0xC

glabel D_801A8088
	.incbin "bin/sm64.j.255EC0.bin", 0x998, 0xC

glabel D_801A8094
	.incbin "bin/sm64.j.255EC0.bin", 0x9A4, 0xC

glabel D_801A80A0
	.incbin "bin/sm64.j.255EC0.bin", 0x9B0, 0xC

glabel D_801A80AC
	.incbin "bin/sm64.j.255EC0.bin", 0x9BC, 0xC

glabel D_801A80B8
	.incbin "bin/sm64.j.255EC0.bin", 0x9C8, 0xC

glabel D_801A80C4
	.incbin "bin/sm64.j.255EC0.bin", 0x9D4, 0xC

glabel D_801A80D0
	.incbin "bin/sm64.j.255EC0.bin", 0x9E0, 0xC

glabel D_801A80DC
	.incbin "bin/sm64.j.255EC0.bin", 0x9EC, 0xC

glabel D_801A80E8
	.incbin "bin/sm64.j.255EC0.bin", 0x9F8, 0xC

glabel D_801A80F4
	.word D_801A807C

glabel D_801A80F8
	.word 0
	.word 0

glabel D_801A8100
	.word 0

glabel D_801A8104
	.word D_801A8070
	.word D_801A80DC
	.word D_801A807C
	.word D_801A80B8
	.word D_801A80B8

glabel D_801A8118
	.word D_801A8070
	.word D_801A80B8
	.incbin "bin/sm64.j.255EC0.bin", 0xA30, 0x80

glabel D_801A81A0
	.incbin "bin/sm64.j.255EC0.bin", 0xAB0, 0x20

#press start head 1
glabel D_801A81C0
	.word 0

glabel D_801A81C4
	.word 0
	.word 0
	.word 0
	.word 0

glabel D_801A81D4
	.incbin "bin/sm64.j.255EC0.bin", 0xAE4, 0x4
glabel D_801A81D8
	.incbin "bin/sm64.j.255EC0.bin", 0xAE8, 0x4
glabel D_801A81DC
	.incbin "bin/sm64.j.255EC0.bin", 0xAEC, 0x4
glabel D_801A81E0
	.incbin "bin/sm64.j.255EC0.bin", 0xAF0, 0x58

glabel D_801A8238
	.incbin "bin/sm64.j.255EC0.bin", 0xB48, 0x4
glabel D_801A823C
	.incbin "bin/sm64.j.255EC0.bin", 0xB4C, 0x4
glabel D_801A8240
	.incbin "bin/sm64.j.255EC0.bin", 0xB50, 0x4
glabel D_801A8244
	.incbin "bin/sm64.j.255EC0.bin", 0xB54, 0xC

glabel D_801A8250
	.word 0

glabel D_801A8254
	.word 0

glabel D_801A8258
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0

glabel D_801A8270
	.word 0
	.word 0
	.word 0
	.word 0

glabel D_801A8280
	.word 0

glabel D_801A8284
	.incbin "bin/sm64.j.255EC0.bin", 0xB94, 0x1C

glabel D_801A82A0
	.word 0

glabel D_801A82A4
	.incbin "bin/sm64.j.255EC0.bin", 0xBB4, 0x4

glabel D_801A82A8
	.incbin "bin/sm64.j.255EC0.bin", 0xBB8, 0x4

glabel D_801A82AC
	.incbin "bin/sm64.j.255EC0.bin", 0xBBC, 0x14

glabel D_801A82C0
	.word 0
	.word 0
	.word 0
	.word 0

glabel D_801A82D0
	.word 0

glabel D_801A82D4
	.word 0
	.word 0
	.word 0

glabel D_801A82E0
	.word 0

glabel D_801A82E4
	.word 0

glabel D_801A82E8
	.word 0

glabel D_801A82EC
	.word 0

glabel D_801A82F0
	.word 0

glabel D_801A82F4
	.word 0

glabel D_801A82F8
	.word 0

glabel D_801A82FC
	.incbin "bin/sm64.j.255EC0.bin", 0xC0C, 0x2C
	.word D_801A82FC
glabel D_801A832C
	.incbin "bin/sm64.j.255EC0.bin", 0xC3C, 0x2C
	.word D_801A832C
glabel D_801A835C
	.incbin "bin/sm64.j.255EC0.bin", 0xC6C, 0x2C
	.word D_801A835C

	.incbin "bin/sm64.j.255EC0.bin", 0xC9C, 0x18
glabel D_801A83A4
	.incbin "bin/sm64.j.255EC0.bin", 0xCB4, 0x9C
	.word D_801B88D0
	.incbin "bin/sm64.j.255EC0.bin", 0xD54, 0x14
	.word D_801B88D8
	.incbin "bin/sm64.j.255EC0.bin", 0xD6C, 0x2C
	.word D_801A83A4
	.incbin "bin/sm64.j.255EC0.bin", 0xD9C, 0x14
	.word D_801B88E0
	.incbin "bin/sm64.j.255EC0.bin", 0xDB4, 0x14
	.word D_801B88E8
	.incbin "bin/sm64.j.255EC0.bin", 0xDCC, 0x28
glabel D_801A84E4
	.incbin "bin/sm64.j.255EC0.bin", 0xDF4, 0x64
	.word D_801A84E4
	.incbin "bin/sm64.j.255EC0.bin", 0xE5C, 0x74
	.word D_801A84E4
	.incbin "bin/sm64.j.255EC0.bin", 0xED4, 0x5C
	.word D_801A84E4
	.incbin "bin/sm64.j.255EC0.bin", 0xF34, 0x44

glabel D_801A8668
	.word 0
	.word 0
	.word 0

glabel D_801A8674
	.word 0
	.word 0

glabel D_801A867C
	.word 0

glabel D_801A8680
	.word 0

glabel D_801A8684
	.word 0

glabel D_801A8688
	.word 0

glabel D_801A868C
	.word 0

glabel D_801A8690
	.word 0

glabel D_801A8694
	.incbin "bin/sm64.j.255EC0.bin", 0xFA4, 0x4

glabel D_801A8698
	.incbin "bin/sm64.j.255EC0.bin", 0xFA8, 0x4

glabel D_801A869C
	.word 0

glabel D_801A86A0
	.word 0

glabel D_801A86A4
	.word 0

glabel D_801A86A8
	.word 0

glabel D_801A86AC
	.word 0

glabel D_801A86B0
	.word 0
	.word 0

glabel D_801A86B8
	.word 0

glabel D_801A86BC
	.incbin "bin/sm64.j.255EC0.bin", 0xFCC, 0x4

glabel D_801A86C0
	.incbin "bin/sm64.j.255EC0.bin", 0xFD0, 0x8

glabel D_801A86C8
	.incbin "bin/sm64.j.255EC0.bin", 0xFD8, 0x4

glabel D_801A86CC
	.incbin "bin/sm64.j.255EC0.bin", 0xFDC, 0x4

glabel D_801A86D0
	.incbin "bin/sm64.j.255EC0.bin", 0xFE0, 0x4

glabel D_801A86D4
	.incbin "bin/sm64.j.255EC0.bin", 0xFE4, 0x4

glabel D_801A86D8
	.word 0

glabel D_801A86DC
	.word 0

glabel D_801A86E0
	.word 0

glabel D_801A86E4
	.word 0

glabel D_801A86E8
	.word 0

glabel D_801A86EC
	.word 0

glabel D_801A86F0
	.word 0

glabel D_801A86F4
	.word 0
	.word 0

glabel D_801A86FC
	.word 0

glabel D_801A8700
	.word 0

glabel D_801A8704
	.incbin "bin/sm64.j.255EC0.bin", 0x1014, 0x4

glabel D_801A8708
	.incbin "bin/sm64.j.255EC0.bin", 0x1018, 0x28

glabel D_801A8730
	.incbin "bin/sm64.j.255EC0.bin", 0x1040, 0x808

glabel D_801A8F38
	.incbin "bin/sm64.j.255EC0.bin", 0x1848, 0x800
glabel D_801A9738
	.incbin "bin/sm64.j.255EC0.bin", 0x2048, 0x800
glabel D_801A9F38
	.incbin "bin/sm64.j.255EC0.bin", 0x2848, 0x800
glabel D_801AA738
	.incbin "bin/sm64.j.255EC0.bin", 0x3048, 0x800
glabel D_801AAF38
	.incbin "bin/sm64.j.255EC0.bin", 0x3848, 0x800
glabel D_801AB738
	.incbin "bin/sm64.j.255EC0.bin", 0x4048, 0x800
glabel D_801ABF38
	.incbin "bin/sm64.j.255EC0.bin", 0x4848, 0x800
glabel D_801AC738
	.incbin "bin/sm64.j.255EC0.bin", 0x5048, 0x800
glabel D_801ACF38
	.incbin "bin/sm64.j.255EC0.bin", 0x5848, 0x800
glabel D_801AD738
	.incbin "bin/sm64.j.255EC0.bin", 0x6048, 0x800
glabel D_801ADF38
	.incbin "bin/sm64.j.255EC0.bin", 0x6848, 0x800
glabel D_801AE738
	.incbin "bin/sm64.j.255EC0.bin", 0x7048, 0x800
glabel D_801AEF38
	.incbin "bin/sm64.j.255EC0.bin", 0x7848, 0x800
glabel D_801AF738
	.incbin "bin/sm64.j.255EC0.bin", 0x8048, 0x800
glabel D_801AFF38
	.incbin "bin/sm64.j.255EC0.bin", 0x8848, 0x800
glabel D_801B0738
	.incbin "bin/sm64.j.255EC0.bin", 0x9048, 0x800
glabel D_801B0F38
	.incbin "bin/sm64.j.255EC0.bin", 0x9848, 0x800
glabel D_801B1738
	.incbin "bin/sm64.j.255EC0.bin", 0xA048, 0x80
glabel D_801B17B8
	.incbin "bin/sm64.j.255EC0.bin", 0xA0C8, 0x4C
	.word D_801B1738
	.incbin "bin/sm64.j.255EC0.bin", 0xA118, 0x30

glabel D_801B1838
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801A9738
    .word 0x06010000, D_801B17B8
glabel D_801B1850
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801A9F38
    .word 0x06010000, D_801B17B8
glabel D_801B1868
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AA738
    .word 0x06010000, D_801B17B8
glabel D_801B1880
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AAF38
    .word 0x06010000, D_801B17B8
glabel D_801B1898
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AB738
    .word 0x06010000, D_801B17B8
glabel D_801B18B0
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801ABF38
    .word 0x06010000, D_801B17B8
glabel D_801B18C8
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AC738
    .word 0x06010000, D_801B17B8
glabel D_801B18E0
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801ACF38
    .word 0x06010000, D_801B17B8
glabel D_801B18F8
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AD738
    .word 0x06010000, D_801B17B8
glabel D_801B1910
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801ADF38
    .word 0x06010000, D_801B17B8
glabel D_801B1928
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AE738
    .word 0x06010000, D_801B17B8
glabel D_801B1940
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AEF38
    .word 0x06010000, D_801B17B8
glabel D_801B1958
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AF738
    .word 0x06010000, D_801B17B8
glabel D_801B1970
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801AFF38
    .word 0x06010000, D_801B17B8
glabel D_801B1988
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801B0738
    .word 0x06010000, D_801B17B8
glabel D_801B19A0
    .word 0xE7000000, 0x00000000
    .word 0xFD100000, D_801B0F38
    .word 0x06010000, D_801B17B8

glabel D_801B19B8
	.word D_801B1838
	.word D_801B1838
	.word D_801B1850
	.word D_801B1850
	.word D_801B1868
	.word D_801B1868
	.word D_801B1880
	.word D_801B1880
	.word D_801B1898
	.word D_801B1898
	.word D_801B18B0
	.word D_801B18B0
	.word D_801B18C8
	.word D_801B18C8
	.word D_801B18E0
	.word D_801B18E0

glabel D_801B19F8
	.word D_801B18F8
	.word D_801B18F8
	.word D_801B1910
	.word D_801B1910
	.word D_801B1928
	.word D_801B1928
	.word D_801B1940
	.word D_801B1940
	.word D_801B1958
	.word D_801B1958
	.word D_801B1970
	.word D_801B1970
	.word D_801B1988
	.word D_801B1988
	.word D_801B19A0
	.word D_801B19A0
glabel D_801B1A38
	.incbin "bin/sm64.j.255EC0.bin", 0xA348, 0x800
glabel D_801B2238
	.incbin "bin/sm64.j.255EC0.bin", 0xAB48, 0x800
glabel D_801B2A38
	.incbin "bin/sm64.j.255EC0.bin", 0xB348, 0x800
glabel D_801B3238
	.incbin "bin/sm64.j.255EC0.bin", 0xBB48, 0x800
glabel D_801B3A38
	.incbin "bin/sm64.j.255EC0.bin", 0xC348, 0x1000
glabel D_801B4A38
	.incbin "bin/sm64.j.255EC0.bin", 0xD348, 0x40
glabel D_801B4A78
    .word 0xFC119623, 0xFF2FFFFF
    .word 0xB6000000, 0x000C0000
    .word 0xB900031D, 0x00443078
    .word 0xBB000001, 0x80008000
    .word 0xF5100000, 0x07000000
    .word 0xE6000000, 0x00000000
    .word 0xF3000000, 0x073FF100
    .word 0xF5101000, 0x00000000
    .word 0xF2000000, 0x0007C07C
    .word 0x04300040, D_801B4A38
    .word 0xBF000000, 0x00000A14
    .word 0xBF000000, 0x0000141E
    .word 0xBB000000, 0x00010001
    .word 0xFCFFFFFF, 0xFFFE793C
    .word 0xB900031D, 0x00442478
    .word 0xB8000000, 0x00000000
glabel D_801B4AF8
	.incbin "bin/sm64.j.255EC0.bin", 0xD408, 0x10
glabel D_801B4B08
	.incbin "bin/sm64.j.255EC0.bin", 0xD418, 0x10

	# probably display lists. maybe.
glabel D_801B4B18
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4AF8
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B1A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4B38
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4AF8
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B2238
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4B58
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4AF8
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B2A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4B78
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4AF8
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B3238
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4B98
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4AF8
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B3A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4BB8
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4AF8
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B3A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4BD8
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4B08
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B1A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4BF8
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4B08
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B2238
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4C18
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4B08
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B2A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4C38
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4B08
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B3238
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4C58
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4B08
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B3A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78
glabel D_801B4C78
	.byte 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.word D_801B4B08
	.byte 0xfd, 0x10, 0x00, 0x00
	.word D_801B3A38
	.byte 0x06, 0x01, 0x00, 0x00
	.word D_801B4A78

glabel D_801B4C98
	.word D_801B4B98
	.word D_801B4B98
	.word D_801B4B78
	.word D_801B4B78
	.word D_801B4B58
	.word D_801B4B58
	.word D_801B4B38
	.word D_801B4B38
	.word D_801B4B18
	.word D_801B4B18
	.word D_801B4BB8
	.word D_801B4BB8

glabel D_801B4CC8
	.word D_801B4C58
	.word D_801B4C58
	.word D_801B4C38
	.word D_801B4C38
	.word D_801B4C18
	.word D_801B4C18
	.word D_801B4BF8
	.word D_801B4BF8
	.word D_801B4BD8
	.word D_801B4BD8
	.word D_801B4C78
	.word D_801B4C78

	.word 0xB8000000, 0

glabel D_801B4D00
	.incbin "bin/sm64.j.255EC0.bin", 0xD610, 0x400

glabel D_801B5100
	.incbin "bin/sm64.j.255EC0.bin", 0xDA10, 0x2C
	.word D_801B4D00
	.incbin "bin/sm64.j.255EC0.bin", 0xDA40, 0x40

glabel D_801B5170
	.incbin "bin/sm64.j.255EC0.bin", 0xDA80, 0x18

glabel D_801B5188
	.incbin "bin/sm64.j.255EC0.bin", 0xDA98, 0x84

glabel D_801B520C
	.incbin "bin/sm64.j.255EC0.bin", 0xDB1C, 0x1C
glabel D_801B5228
	.incbin "bin/sm64.j.255EC0.bin", 0xDB38, 0x30
glabel D_801B5258
	.incbin "bin/sm64.j.255EC0.bin", 0xDB68, 0x5C
	.word D_801B5228
	.incbin "bin/sm64.j.255EC0.bin", 0xDBC8, 0xC
	.word D_801B5258
	.incbin "bin/sm64.j.255EC0.bin", 0xDBD8, 0x10

glabel D_801B52D8
	.incbin "bin/sm64.j.255EC0.bin", 0xDBE8, 0x58

glabel D_801B5330
	.incbin "bin/sm64.j.255EC0.bin", 0xDC40, 0x8

glabel D_801B5338
	.incbin "bin/sm64.j.255EC0.bin", 0xDC48, 0x8

glabel D_801B5340
	.incbin "bin/sm64.j.255EC0.bin", 0xDC50, 0x14

glabel D_801B5354
	.incbin "bin/sm64.j.255EC0.bin", 0xDC64, 0x8

glabel D_801B535C
	.incbin "bin/sm64.j.255EC0.bin", 0xDC6C, 0x8

glabel D_801B5364
	.incbin "bin/sm64.j.255EC0.bin", 0xDC74, 0xC

glabel D_801B5370
	.incbin "bin/sm64.j.255EC0.bin", 0xDC80, 0x24

glabel D_801B5394
	.incbin "bin/sm64.j.255EC0.bin", 0xDCA4, 0x18

glabel D_801B53AC
	.incbin "bin/sm64.j.255EC0.bin", 0xDCBC, 0x20

glabel D_801B53CC
	.incbin "bin/sm64.j.255EC0.bin", 0xDCDC, 0x18

glabel D_801B53E4
	.incbin "bin/sm64.j.255EC0.bin", 0xDCF4, 0x28

glabel D_801B540C
	.incbin "bin/sm64.j.255EC0.bin", 0xDD1C, 0x14

glabel D_801B5420
	.incbin "bin/sm64.j.255EC0.bin", 0xDD30, 0x4

glabel D_801B5424
	.incbin "bin/sm64.j.255EC0.bin", 0xDD34, 0x14

glabel D_801B5438
	.incbin "bin/sm64.j.255EC0.bin", 0xDD48, 0x4

glabel D_801B543C
	.incbin "bin/sm64.j.255EC0.bin", 0xDD4C, 0x14

glabel D_801B5450
	.incbin "bin/sm64.j.255EC0.bin", 0xDD60, 0x4

glabel D_801B5454
	.incbin "bin/sm64.j.255EC0.bin", 0xDD64, 0x14

glabel D_801B5468
	.incbin "bin/sm64.j.255EC0.bin", 0xDD78, 0x4

glabel D_801B546C
	.incbin "bin/sm64.j.255EC0.bin", 0xDD7C, 0x14
