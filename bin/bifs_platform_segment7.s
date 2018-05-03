.section .rodata

# TODO: cross-link between segments
.equ lll_texture_09003000, 0x09003000
.equ lll_texture_09005000, 0x09005000
.equ lll_texture_09005800, 0x09005800
.equ lll_texture_09009800, 0x09009800

.include "macros.inc"

bifs_platform_texture_07000000: # 0x07000000
.incbin "bin/bifs_platform_segment7/bifs_platform_segment7.00000.rgba16"

bifs_platform_vertices_07000800: # 0x07000800
.hword   1176,    784,  -2837,      0,   6612,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,   1229,  -1175,      0,   7634,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,    784,  -1175,      0,   7634,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   1176,    784,   2838,      0,   1502,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   1176,   1229,   2838,      0,   1502,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,   1229,   2838,      0,   2524,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,    784,   1176,      0,    480,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,    784,   2838,      0,   2524,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,   1229,   1176,      0,    480,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,   1229,   1176,      0,   3546,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,    784,   1176,      0,   3546,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,   1229,   1176,      0,   8656,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,    784,   1176,      0,   8656,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,   1502,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,    784,   2838,      0,   1246,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,    784,   1176,      0,   1756,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF

bifs_platform_vertices_07000900: # 0x07000900
.hword   1176,    784,  -2837,      0,   6612,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   1176,   1229,  -2837,      0,   6612,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,   1229,  -1175,      0,   7634,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,    784,  -2837,      0,   5590,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,   1229,  -2837,      0,   5590,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,    784,  -1175,      0,   4568,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,   1229,  -1175,      0,   4568,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,    784,   1176,      0,   3546,    678 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,   1229,   1176,      0,   3546,    990 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,    784,   1176,      0,   1756,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2837,    784,  -1175,      0,   2268,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,   2012,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,    784,  -2837,      0,   2778,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,   2524,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   1176,    784,  -2837,      0,   3290,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,   3034,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF

bifs_platform_vertices_07000A00: # 0x07000A00
.hword   1176,    784,  -2837,      0,   3290,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,    784,  -1175,      0,   3800,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,   3546,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,    784,   1176,      0,   4312,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,   4056,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2838,    784,   1176,      0,    224,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   1176,    784,   2838,      0,    734,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,    480,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -1175,    784,   2838,      0,   1246,    812 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword      0,   -306,      0,      0,    990,    552 ; .byte 0xFF, 0xFF, 0xFF, 0xFF

bifs_platform_vertices_07000AA0: # 0x07000AA0
.hword   2838,   1229,  -1175,      0,   5298,  -4574 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   1703,   1229,    705,      0,   3210,  -1892 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   2838,   1229,   1176,      0,   4460,  -1222 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword  -2837,   1229,  -1175,      0,  -1782,  -4574 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   -704,   1229,  -1702,      0,   1064,  -5326 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword  -1175,   1229,  -2837,      0,    882,  -6944 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword  -2837,   1229,   1176,      0,  -2620,  -1222 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword  -1702,   1229,   -704,      0,   -534,  -3904 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword  -1702,   1229,    705,      0,  -1036,  -1892 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword    705,   1229,  -1702,      0,   2824,  -5326 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   1176,   1229,  -2837,      0,   3816,  -6944 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword  -1175,   1229,   2838,      0,  -1138,   1146 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   -704,   1229,   1703,      0,   -148,   -470 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   1176,   1229,   2838,      0,   1792,   1146 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword    705,   1229,   1703,      0,   1610,   -470 ; .byte 0xAD, 0x10, 0x16, 0xFF
.hword   1703,   1229,   -704,      0,   3714,  -3904 ; .byte 0xAD, 0x10, 0x16, 0xFF

bifs_platform_vertices_07000BA0: # 0x07000BA0
.hword  -1418,   1229,    588,      0,   3034,  -2076 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -587,   1229,   1419,      0,   5202,  -1178 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword      0,   1229,      0,      0,   3034,    990 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    588,   1229,   1419,      0,   6100,    990 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1419,   1229,    588,      0,   5202,   3156 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -1418,   1229,   -587,      0,    866,  -1178 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1419,   1229,   -587,      0,   3034,   4054 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    588,   1229,  -1418,      0,    866,   3156 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -587,   1229,  -1418,      0,      0,    990 ; .byte 0xFD, 0x42, 0x34, 0xFF

bifs_platform_vertices_07000C30: # 0x07000C30
.hword   -704,   1229,   1703,      0,      0,    850 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    705,   1229,   1703,      0,   4568,  -1054 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    588,   1229,   1419,      0,   3800,  -1820 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -1702,   1229,    705,      0,  -4630,  -1054 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -1418,   1229,   -587,      0,  -5450,  -5654 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -1702,   1229,   -704,      0,  -6534,  -5654 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -587,   1229,  -1418,      0,  -3862,  -9486 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -704,   1229,  -1702,      0,  -4628, -10252 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -1418,   1229,    588,      0,  -3862,  -1820 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    588,   1229,  -1418,      0,      0, -11072 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    705,   1229,  -1702,      0,      0, -12156 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -587,   1229,   1419,      0,      0,   -234 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1703,   1229,    705,      0,   6472,  -5652 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1419,   1229,    588,      0,   5388,  -5652 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1703,   1229,   -704,      0,   4568, -10252 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1419,   1229,   -587,      0,   3800,  -9486 ; .byte 0xFD, 0x42, 0x34, 0xFF

glabel bifs_platform_f3d_07000D30 # 0x07000D30
.word 0xFD100000, lll_texture_09009800
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x04F00100, bifs_platform_vertices_07000800
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x003C281E
.word 0xBF000000, 0x001E3246
.word 0xBF000000, 0x003C5028
.word 0xBF000000, 0x0046325A
.word 0xBF000000, 0x00465A64
.word 0xBF000000, 0x00146E78
.word 0xBF000000, 0x00140A6E
.word 0xBF000000, 0x00828C96
.word 0x04F00100, bifs_platform_vertices_07000900
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E0A00
.word 0xBF000000, 0x001E280A
.word 0xBF000000, 0x0032281E
.word 0xBF000000, 0x00323C28
.word 0xBF000000, 0x00463C32
.word 0xBF000000, 0x0046503C
.word 0xBF000000, 0x005A646E
.word 0xBF000000, 0x00647882
.word 0xBF000000, 0x00788C96
.word 0x049000A0, bifs_platform_vertices_07000A00
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E28
.word 0xBF000000, 0x00323C46
.word 0xBF000000, 0x003C505A
.word 0xB8000000, 0x00000000

bifs_platform_f3d_07000E28: # 0x07000E28
.word 0xFD100000, lll_texture_09003000
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x04F00100, bifs_platform_vertices_07000AA0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x003C461E
.word 0xBF000000, 0x001E4628
.word 0xBF000000, 0x003C5046
.word 0xBF000000, 0x0032285A
.word 0xBF000000, 0x00325A64
.word 0xBF000000, 0x006E503C
.word 0xBF000000, 0x006E7850
.word 0xBF000000, 0x006E828C
.word 0xBF000000, 0x006E8C78
.word 0xBF000000, 0x00645A96
.word 0xBF000000, 0x00140A8C
.word 0xBF000000, 0x0000960A
.word 0xBF000000, 0x00148C82
.word 0xBF000000, 0x00649600
.word 0xB8000000, 0x00000000

bifs_platform_f3d_07000ED0: # 0x07000ED0
.word 0xFD100000, lll_texture_09005800
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x04800090, bifs_platform_vertices_07000BA0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xBF000000, 0x001E2814
.word 0xBF000000, 0x00320014
.word 0xBF000000, 0x003C4614
.word 0xBF000000, 0x00283C14
.word 0xBF000000, 0x00503214
.word 0xBF000000, 0x00465014
.word 0xB8000000, 0x00000000

bifs_platform_f3d_07000F38: # 0x07000F38
.word 0xFD100000, lll_texture_09005000
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x04F00100, bifs_platform_vertices_07000C30
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x0032283C
.word 0xBF000000, 0x00323C46
.word 0xBF000000, 0x001E5028
.word 0xBF000000, 0x00463C5A
.word 0xBF000000, 0x00465A64
.word 0xBF000000, 0x0000501E
.word 0xBF000000, 0x00006E50
.word 0xBF000000, 0x00788214
.word 0xBF000000, 0x008C8278
.word 0xBF000000, 0x0078140A
.word 0xBF000000, 0x0000146E
.word 0xBF000000, 0x00645A96
.word 0xBF000000, 0x008C9682
.word 0xBF000000, 0x0064968C
.word 0xB8000000, 0x00000000

glabel bifs_platform_f3d_07000FE0 # 0x07000FE0
.word 0xE7000000, 0x00000000
.word 0xBA001402, 0x00100000
.word 0xB900031D, 0xC8112078
.word 0xB9000201, 0x00000000
.word 0xF8000000, 0xC83200FF
.word 0xBC000008, 0x0C80F480
.word 0xB7000000, 0x00010000
.word 0xFC127FFF, 0xFFFFF838
.word 0xB6000000, 0x00020000
.word 0xF5100000, 0x07000000
.word 0xBB000001, 0xFFFFFFFF
.word 0xE8000000, 0x00000000
.word 0xF5101000, 0x00014050
.word 0xF2000000, 0x0007C07C
.word 0x06000000, bifs_platform_f3d_07000D30
.word 0x06000000, bifs_platform_f3d_07000E28
.word 0x06000000, bifs_platform_f3d_07000ED0
.word 0x06000000, bifs_platform_f3d_07000F38
.word 0xBB000000, 0xFFFFFFFF
.word 0xE7000000, 0x00000000
.word 0xBA001402, 0x00000000
.word 0xB900031D, 0x00442078
.word 0xB6000000, 0x00010000
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xB7000000, 0x00020000
.word 0xB8000000, 0x00000000

bifs_platform_vertices_070010B0: # 0x070010B0
.hword   6546,   -511,   2618,      0,   4910,    248 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6480,  -3071,  -2776,      0,   8112,    772 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6480,   -511,  -2776,      0,   8100,    232 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -6545,   -511,  -2617,      0,  17484,    232 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -6545,  -3071,  -2617,      0,  17472,    772 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -6479,  -3071,   2777,      0,  20664,    790 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -6479,   -511,   2777,      0,  20676,    248 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2776,   -511,  -6479,      0,  14348,    220 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2617,  -3071,   6546,      0,  23924,    800 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2617,   -511,   6546,      0,  23930,    260 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2776,  -3071,  -6479,      0,  14342,    762 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2618,   -511,  -6545,      0,  11236,    220 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2618,  -3071,  -6545,      0,  11240,    762 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2776,   -511,  -6479,      0,    782,   1298 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2777,   -511,   6480,      0,  -1526,  -4090 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6546,   -511,   2618,      0,  -3092,  -2484 ; .byte 0xFF, 0xFF, 0xFF, 0xFF

bifs_platform_vertices_070011B0: # 0x070011B0
.hword   6546,   -511,   2618,      0,   4910,    248 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6546,  -3071,   2618,      0,   4924,    788 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6480,  -3071,  -2776,      0,   8112,    772 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2777,   -511,   6480,      0,   1658,    260 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2777,  -3071,   6480,      0,   1664,    800 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2617,   -511,   6546,      0,  23930,    260 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2617,  -3071,   6546,      0,  23924,    800 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2777,  -3071,   6480,      0,  27214,    800 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2777,   -511,   6480,      0,  27208,    260 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2776,   -511,  -6479,      0,    782,   1298 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -6545,   -511,  -2617,      0,   2350,   -306 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -6479,   -511,   2777,      0,   2322,  -2550 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword  -2617,   -511,   6546,      0,    716,  -4116 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2777,   -511,   6480,      0,  -1526,  -4090 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6546,   -511,   2618,      0,  -3092,  -2484 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6480,   -511,  -2776,      0,  -3066,   -240 ; .byte 0xFF, 0xFF, 0xFF, 0xFF

bifs_platform_vertices_070012B0: # 0x070012B0
.hword  -2776,   -511,  -6479,      0,    782,   1298 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   6480,   -511,  -2776,      0,  -3066,   -240 ; .byte 0xFF, 0xFF, 0xFF, 0xFF
.hword   2618,   -511,  -6545,      0,  -1460,   1326 ; .byte 0xFF, 0xFF, 0xFF, 0xFF

bifs_platform_vertices_070012E0: # 0x070012E0
.hword  -3512,   -511,   -889,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3159,   -511,   -886,      0,   -360,    440 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3323,    399,  -1105,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1240,   -511,  -5279,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1593,   -511,  -5276,      0,   -360,    440 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1429,    399,  -5496,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1152,   -511,  -5616,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1732,   -511,  -5615,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   1344,   -511,  -5811,      0,    458,    824 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3407,   -511,   3474,      0,    458,    824 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3600,   -511,   3669,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3322,    399,   3790,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3511,   -511,   4006,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3158,   -511,   4009,      0,   -360,    440 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3019,   -511,   3670,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3021,   -511,  -1224,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF

bifs_platform_vertices_070013E0: # 0x070013E0
.hword  -3021,   -511,  -1224,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3408,   -511,  -1420,      0,    458,    824 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3323,    399,  -1105,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3601,   -511,  -1226,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3512,   -511,   -889,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4200,   -511,   -835,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4288,   -511,   -498,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4478,    399,   -715,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4392,   -511,  -1030,      0,    458,    824 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4642,   -511,   -495,      0,   -360,    440 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4780,   -511,   -834,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   2820,   -511,   2679,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   2909,   -511,   3016,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3098,    399,   2799,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3262,   -511,   3019,      0,   -360,    440 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3400,   -511,   2680,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF

bifs_platform_vertices_070014E0: # 0x070014E0
.hword   3013,   -511,   2484,      0,    458,    824 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   2820,   -511,   2679,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3098,    399,   2799,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3400,   -511,   2680,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -130,   -511,  -4068,      0,    762,    860 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -426,   -511,  -3769,      0,    464,    564 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword      0,   1229,  -3583,      0,    278,    990 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -290,   -511,  -3250,      0,    -52,    700 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    253,   -511,  -3245,      0,    -56,   1242 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    465,   -511,  -3767,      0,    462,   1454 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -126,   -511,   3113,      0,    324,    450 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -422,   -511,   3412,      0,    326,    748 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword      4,   1229,   3598,      0,    632,    628 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   -286,   -511,   3931,      0,    652,    938 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    256,   -511,   3936,      0,    926,    670 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword    469,   -511,   3415,      0,    772,    304 ; .byte 0xFD, 0x42, 0x34, 0xFF

bifs_platform_vertices_070015E0: # 0x070015E0
.hword   3453,   -511,   -484,      0,    458,    824 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3157,   -511,   -185,      0,    160,   1116 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3584,   1229,      0,      0,    -26,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3293,   -511,    333,      0,   -356,    984 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   3837,   -511,    338,      0,   -360,    440 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword   4049,   -511,   -183,      0,    158,    228 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3714,   -511,   -484,      0,   -516,    396 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -4010,   -511,   -185,      0,   -218,    692 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3583,   1229,      0,      0,      0,    266 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3874,   -511,    333,      0,    298,    556 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3118,   -511,   -183,      0,   -216,   -198 ; .byte 0xFD, 0x42, 0x34, 0xFF
.hword  -3330,   -511,    338,      0,    302,     14 ; .byte 0xFD, 0x42, 0x34, 0xFF

bifs_platform_f3d_070016A0: # 0x070016A0
.word 0xFD100000, bifs_platform_texture_07000000
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x04F00100, bifs_platform_vertices_070010B0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x001E323C
.word 0xBF000000, 0x0046281E
.word 0xBF000000, 0x003C3250
.word 0xBF000000, 0x003C505A
.word 0xBF000000, 0x00466428
.word 0xBF000000, 0x006E6446
.word 0xBF000000, 0x006E7864
.word 0xBF000000, 0x0014786E
.word 0xBF000000, 0x00140A78
.word 0xBF000000, 0x00828C96
.word 0x04F00100, bifs_platform_vertices_070011B0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E0A00
.word 0xBF000000, 0x001E280A
.word 0xBF000000, 0x00323C46
.word 0xBF000000, 0x00324650
.word 0xBF000000, 0x005A646E
.word 0xBF000000, 0x005A6E78
.word 0xBF000000, 0x005A7882
.word 0xBF000000, 0x005A8C96
.word 0x04200030, bifs_platform_vertices_070012B0
.word 0xBF000000, 0x00000A14
.word 0xB8000000, 0x00000000

bifs_platform_f3d_07001788: # 0x07001788
.word 0xFD100000, lll_texture_09005800
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x04F00100, bifs_platform_vertices_070012E0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x003C1E32
.word 0xBF000000, 0x00284632
.word 0xBF000000, 0x00465032
.word 0xBF000000, 0x00503C32
.word 0xBF000000, 0x005A646E
.word 0xBF000000, 0x0064786E
.word 0xBF000000, 0x0078826E
.word 0xBF000000, 0x008C5A6E
.word 0xBF000000, 0x00828C6E
.word 0xBF000000, 0x000A9614
.word 0x04F00100, bifs_platform_vertices_070013E0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xBF000000, 0x001E2814
.word 0xBF000000, 0x00323C46
.word 0xBF000000, 0x00503246
.word 0xBF000000, 0x003C5A46
.word 0xBF000000, 0x005A6446
.word 0xBF000000, 0x00645046
.word 0xBF000000, 0x006E7882
.word 0xBF000000, 0x00788C82
.word 0xBF000000, 0x008C9682
.word 0x04F00100, bifs_platform_vertices_070014E0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E0014
.word 0xBF000000, 0x0028323C
.word 0xBF000000, 0x0032463C
.word 0xBF000000, 0x0046503C
.word 0xBF000000, 0x00505A3C
.word 0xBF000000, 0x005A283C
.word 0xBF000000, 0x00646E78
.word 0xBF000000, 0x006E8278
.word 0xBF000000, 0x00828C78
.word 0xBF000000, 0x00966478
.word 0xBF000000, 0x008C9678
.word 0x04B000C0, bifs_platform_vertices_070015E0
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xBF000000, 0x001E2814
.word 0xBF000000, 0x00283214
.word 0xBF000000, 0x00320014
.word 0xBF000000, 0x003C4650
.word 0xBF000000, 0x00465A50
.word 0xBF000000, 0x00643C50
.word 0xBF000000, 0x006E6450
.word 0xBF000000, 0x005A6E50
.word 0xB8000000, 0x00000000

glabel bifs_platform_f3d_07001930 # 0x07001930
.word 0xE7000000, 0x00000000
.word 0xBA001402, 0x00100000
.word 0xB900031D, 0xC8112078
.word 0xB9000201, 0x00000000
.word 0xF8000000, 0xC83200FF
.word 0xBC000008, 0x0C80F480
.word 0xB7000000, 0x00010000
.word 0xFC127FFF, 0xFFFFF838
.word 0xB6000000, 0x00020000
.word 0xF5100000, 0x07000000
.word 0xBB000001, 0xFFFFFFFF
.word 0xE8000000, 0x00000000
.word 0xF5101000, 0x00014050
.word 0xF2000000, 0x0007C07C
.word 0x06000000, bifs_platform_f3d_070016A0
.word 0x06000000, bifs_platform_f3d_07001788
.word 0xBB000000, 0xFFFFFFFF
.word 0xE7000000, 0x00000000
.word 0xBA001402, 0x00000000
.word 0xB900031D, 0x00442078
.word 0xB6000000, 0x00010000
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xB7000000, 0x00020000
.word 0xB8000000, 0x00000000

glabel bifs_platform_collision # 0x070019F0
.incbin "bin/bifs_platform_segment7/bifs_platform_segment7.019F0.collision"
