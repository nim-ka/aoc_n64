.include "macros.inc"

.section .rodata

glabel D_801A8050
   .word 1
   .word 1

glabel D_801A8058
   .float -600.0

glabel D_801A805C
   .word 1
   .word 320, 240
   .word 0, 0

glabel D_801A8070
   .float 1.0, 1.0, 1.0

glabel D_801A807C
   .float 1.0, 0.0, 0.0

glabel D_801A8088
   .float 0.0, 1.0, 0.0

glabel D_801A8094
   .float 0.0, 0.0, 1.0

glabel D_801A80A0
   .float 0.0, 0.0, 6.0

glabel D_801A80AC
   .float 1.0, 0.0, 1.0

glabel D_801A80B8
   .float 0.0, 0.0, 0.0

glabel D_801A80C4
   .float 0.6, 0.6, 0.6

glabel D_801A80D0
   .float 0.4, 0.4, 0.4

glabel D_801A80DC
   .float 1.0, 1.0, 0.0

glabel D_801A80E8
   .float 1.0, 1.0, 0.0

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

# Unreferenced 4x4 Matrix? @ 801A8120
    .float 1.0, 0.0, 0.0, 0.0
    .float 0.0, 0.0, 0.0, 0.0
    .float 0.0, 0.0, 1.0, 0.0
    .float 0.0, 0.0, 0.0, 1.0

# Another Unreferenced 4x4 Matrix? @ 801A8160
    .float 1.0, 0.0, 0.0, 0.0
    .float 0.0, 1.0, 0.0, 0.0
    .float 0.0, 0.0, 1.0, 0.0
    .float 0.0, 0.0, 0.0, 1.0

glabel D_801A81A0
   .word 1, 0, 0, 0
   .word 0, 0, 0, 0 

#press start head 1
glabel D_801A81C0
   .word 0

glabel D_801A81C4
   .word 0
   .word 0
   .word 0
   .word 0

glabel D_801A81D4
   .word   9,   3,  12, -14
   .word  25,   5,  16, -25
   .word  42,   4,  15, -39
   .word  55,  -6,  20, -23
   .word  70,  -2,  20, -23
   .word 135,   0,  16, 0
   .word   0

glabel D_801A8238
   .word  15,  0,  22,  0
   .word  0, 0

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
   .word 2, 1, 3, 4, 5, 8, 9

glabel D_801A82A0
   .word 0

glabel D_801A82A4
   .word 0x12345678

glabel D_801A82A8
   .word 0x58374895

glabel D_801A82AC
   .ascii "0123456789ABCDEF"
   .balign 0x10

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
   .float 1.0

glabel D_801A8698
   .word 1

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
   .word 1

glabel D_801A86C0
   .word 0
   .word 10

glabel D_801A86C8
   .word 1

glabel D_801A86CC
   .float 1.0

glabel D_801A86D0
   .float 1.0

glabel D_801A86D4
   .float 1.0

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
   .word 3

glabel D_801A8708
   .incbin "bin/sm64.j.255EC0.bin", 0x1018, 0x20

# TODO: end of display list. does anything reference this?
.word 0xB8000000, 0x00000000

glabel D_801A8730
   .incbin "build/bin/intro_raw/hand_open.rgba16"

# TODO: end of display list. does anything reference this?
.word 0xB8000000, 0x00000000

glabel D_801A8F38
   .incbin "build/bin/intro_raw/hand_closed.rgba16"
glabel D_801A9738
   .incbin "build/bin/intro_raw/red_star_0.rgba16"
glabel D_801A9F38
   .incbin "build/bin/intro_raw/red_star_1.rgba16"
glabel D_801AA738
   .incbin "build/bin/intro_raw/red_star_2.rgba16"
glabel D_801AAF38
   .incbin "build/bin/intro_raw/red_star_3.rgba16"
glabel D_801AB738
   .incbin "build/bin/intro_raw/red_star_4.rgba16"
glabel D_801ABF38
   .incbin "build/bin/intro_raw/red_star_5.rgba16"
glabel D_801AC738
   .incbin "build/bin/intro_raw/red_star_6.rgba16"
glabel D_801ACF38
   .incbin "build/bin/intro_raw/red_star_7.rgba16"
glabel D_801AD738
   .incbin "build/bin/intro_raw/white_star_0.rgba16"
glabel D_801ADF38
   .incbin "build/bin/intro_raw/white_star_1.rgba16"
glabel D_801AE738
   .incbin "build/bin/intro_raw/white_star_2.rgba16"
glabel D_801AEF38
   .incbin "build/bin/intro_raw/white_star_3.rgba16"
glabel D_801AF738
   .incbin "build/bin/intro_raw/white_star_4.rgba16"
glabel D_801AFF38
   .incbin "build/bin/intro_raw/white_star_5.rgba16"
glabel D_801B0738
   .incbin "build/bin/intro_raw/white_star_6.rgba16"
glabel D_801B0F38
   .incbin "build/bin/intro_raw/white_star_7.rgba16"

glabel D_801B1738
   vertex    -64,      0,      0,      0,    992,  0x00, 0x00, 0x7F, 0x00
   vertex     64,      0,      0,    992,    992,  0x00, 0x00, 0x7F, 0x00
   vertex     64,    128,      0,    992,      0,  0x00, 0x00, 0x7F, 0x00
   vertex    -64,    128,      0,      0,      0,  0x00, 0x00, 0x7F, 0x00

D_801B1778: # TODO: references?
   vertex  16384,      0,      0,      0,  16384,  0x00, 0x00, 0x00, 0x00
   vertex      0,      0,  16384,      0,      0,  0x00, 0x00, 0x40, 0x00
   vertex      0,      0,      0,      0,      0,  0x00, 0x00, 0x00, 0x00
   vertex      0,      0,      0,      0,      0,  0x00, 0x00, 0x00, 0x00

glabel D_801B17B8
   .word 0xFCFFFFFF, 0xFFFCF279
   .word 0xB6000000, 0x000C0000
   .word 0xB900031D, 0x00443078
   .word 0xBB000001, 0xFFFFFFFF
   .word 0xF5100000, 0x07094250
   .word 0xE6000000, 0x00000000
   .word 0xF3000000, 0x073FF100
   .word 0xF5101000, 0x00094250
   .word 0xF2000000, 0x0007C07C
   .word 0x04300040, D_801B1738
   .word 0xBF000000, 0x00000A14
   .word 0xBF000000, 0x0000141E
   .word 0xBB000000, 0xFFFFFFFF
   .word 0xFCFFFFFF, 0xFFFE793C
   .word 0xB900031D, 0x00442478
   .word 0xB8000000, 0x00000000

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
   .incbin "build/bin/intro_raw/sparkle_0.rgba16"
glabel D_801B2238
   .incbin "build/bin/intro_raw/sparkle_1.rgba16"
glabel D_801B2A38
   .incbin "build/bin/intro_raw/sparkle_2.rgba16"
glabel D_801B3238
   .incbin "build/bin/intro_raw/sparkle_3.rgba16"
glabel D_801B3A38
   .incbin "build/bin/intro_raw/sparkle_4.rgba16"
D_801B4238: # TODO: references?
   .incbin "build/bin/intro_raw/sparkle_5.rgba16"

glabel D_801B4A38
   vertex    -32,      0,      0,      0,   1984,  0x00, 0x00, 0x7F, 0x00
   vertex     32,      0,      0,   1984,   1984,  0x00, 0x00, 0x7F, 0x00
   vertex     32,     64,      0,   1984,      0,  0x00, 0x00, 0x7F, 0x00
   vertex    -32,     64,      0,      0,      0,  0x00, 0x00, 0x7F, 0x00

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
   .word 0xFA000000, 0xFF0000FF
   .word 0xB8000000, 0x00000000

glabel D_801B4B08
   .word 0xFA000000, 0xFFFFFFFF
   .word 0xB8000000, 0x00000000

glabel D_801B4B18
   .word 0xE7000000, 0x00000000
   .word 0x06000000, D_801B4AF8
   .word 0xFD100000, D_801B1A38
   .word 0x06010000, D_801B4A78
glabel D_801B4B38
   .word 0xE7000000, 0x00000000
   .word 0x06000000, D_801B4AF8
   .word 0xFD100000, D_801B2238
   .word 0x06010000, D_801B4A78
glabel D_801B4B58
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4AF8
   .word 0xFD100000, D_801B2A38
   .word 0x06010000, D_801B4A78
glabel D_801B4B78
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4AF8
   .word 0xFD100000, D_801B3238
   .word 0x06010000, D_801B4A78
glabel D_801B4B98
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4AF8
   .word 0xFD100000, D_801B3A38
   .word 0x06010000, D_801B4A78
glabel D_801B4BB8
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4AF8
   .word 0xFD100000, D_801B3A38
   .word 0x06010000, D_801B4A78
glabel D_801B4BD8
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4B08
   .word 0xFD100000, D_801B1A38
   .word 0x06010000, D_801B4A78
glabel D_801B4BF8
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4B08
   .word 0xFD100000, D_801B2238
   .word 0x06010000, D_801B4A78
glabel D_801B4C18
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4B08
   .word 0xFD100000, D_801B2A38
   .word 0x06010000, D_801B4A78
glabel D_801B4C38
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4B08
   .word 0xFD100000, D_801B3238
   .word 0x06010000, D_801B4A78
glabel D_801B4C58
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4B08
   .word 0xFD100000, D_801B3A38
   .word 0x06010000, D_801B4A78
glabel D_801B4C78
   .word 0xE7000000, 0x0000000
   .word 0x06000000, D_801B4B08
   .word 0xFD100000, D_801B3A38
   .word 0x06010000, D_801B4A78

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
   .incbin "build/bin/intro_raw/mario_face_shine.ia8"

glabel D_801B5100
   .word 0xB7000000, 0x00040000
   .word 0xBB000001, 0x07C007C0
   .word 0xBA001301, 0x00080000
   .word 0xBA000C02, 0x00002000
   .word 0xFC30B261, 0x44664924
   .word 0xFD700000, D_801B4D00
   .word 0xF5700000, 0x07014050
   .word 0xE6000000, 0x00000000
   .word 0xF3000000, 0x071FF200
   .word 0xE7000000, 0x00000000
   .word 0xF5680800, 0x00014050
   .word 0xF2000000, 0x0007C07C
   .word 0xE7000000, 0x00000000
   .word 0xB8000000, 0x00000000

glabel D_801B5170
   .word 0xB6000000, 0xFFFFFFFF
   .word 0xB7000000, 0x00000204
   .word 0xB8000000, 0x00000000

glabel D_801B5188
   .word 0xE7000000, 0x00000000
   .word 0xFCFFFFFF, 0xFFFE793C
   .word 0xBA001402, 0x00000000
   .word 0xBA001001, 0x00000000
   .word 0xBA000E02, 0x00000000
   .word 0xBA001102, 0x00000000
   .word 0xBA001301, 0x00080000
   .word 0xBA000C02, 0x00002000
   .word 0xBA000903, 0x00000C00
   .word 0xBA000801, 0x00000000
   .word 0xB9000002, 0x00000000
   .word 0xB900031D, 0x0F0A4000
   .word 0xC0000000, 0x00000000
   .word 0xBA000602, 0x00000000
   .word 0xE7000000, 0x00000000
   .word 0xB8000000, 0x00000000

   .word 0

glabel D_801B520C
   .float 1.0

   .word 0
   .word 0

# TODO: end of display list. does anything reference this?
   .word 0xE7000000, 0x00000000
   .word 0xB8000000, 0x00000000

glabel D_801B5228
   vertex -8,  8,  0,  0,  0,  0x00, 0x00, 0x00, 0xFF
   vertex  8, -2,  0,  0,  0,  0x00, 0x00, 0x00, 0xFF
   vertex  2, -8,  0,  0,  0,  0x00, 0x00, 0x00, 0xFF

glabel D_801B5258
   vertex -6,  6,  0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF
   vertex  7, -3,  0,  0,  0,  0xFF, 0x00, 0x00, 0xFF
   vertex  3, -7,  0,  0,  0,  0xFF, 0x00, 0x00, 0xFF

D_801B5288: # TODO: references?
   .word 0xE7000000, 0x00000000
   .word 0xB900031D, 0x0F0A4000
   .word 0xB6000000, 0xFFFFFFFF
   .word 0xB7000000, 0x00000204
   .word 0xE7000000, 0x00000000
   .word 0x04200030, D_801B5228
   .word 0xBF000000, 0x00000A14
   .word 0x04200030, D_801B5258
   .word 0xBF000000, 0x00000A14
   .word 0xB8000000, 0x00000000

glabel D_801B52D8
   .word 0xE7000000, 0x00000000
   .word 0xBA001402, 0x00000000
   .word 0xBB000001, 0x80008000
   .word 0xB9000002, 0x00000001
   .word 0xF9000000, 0x00000001
   .word 0xB900031D, 0x00443078
   .word 0xFCFFFFFF, 0xFFFCF279
   .word 0xBA000C02, 0x00002000
   .word 0xBA001301, 0x00000000
   .word 0xB8000000, 0x00000000
