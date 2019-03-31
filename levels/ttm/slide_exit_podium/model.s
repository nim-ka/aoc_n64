ttm_seg7_light_0702ACE8: # 0x0702ACE8 - 0x0702ACF0
.byte 0x0C, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0x00

ttm_seg7_light_0702ACF0: # 0x0702ACF0 - 0x0702AD00
.byte 0x33, 0x33, 0x33, 0x00, 0x33, 0x33, 0x33, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

ttm_seg7_light_0702AD00: # 0x0702AD00 - 0x0702AD08
.byte 0x1D, 0x1D, 0x1D, 0x00, 0x1D, 0x1D, 0x1D, 0x00

ttm_seg7_light_0702AD08: # 0x0702AD08 - 0x0702AD18
.byte 0x77, 0x77, 0x77, 0x00, 0x77, 0x77, 0x77, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

ttm_seg7_light_0702AD18: # 0x0702AD18 - 0x0702AD20
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

ttm_seg7_light_0702AD20: # 0x0702AD20 - 0x0702AD30
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

ttm_seg7_texture_0702AD30: # 0x0702AD30 - 0x0702B530
.incbin "levels/ttm/8.rgba16"

ttm_seg7_vertex_0702B530: # 0x0702B530 - 0x0702B570
vertex    102,     10,    102,   4568,  -7698,  0x00, 0x7F, 0x00, 0xFF
vertex   -101,     10,   -101,   5590,  -8720,  0x00, 0x7F, 0x00, 0xFF
vertex   -101,     10,    102,   4568,  -8720,  0x00, 0x7F, 0x00, 0xFF
vertex    102,     10,   -101,   5590,  -7698,  0x00, 0x7F, 0x00, 0xFF

ttm_seg7_vertex_0702B570: # 0x0702B570 - 0x0702B670
vertex   -101,      0,   -101,   5590,  -8720,  0x00, 0x00, 0x7F, 0xFF
vertex    102,    205,   -101,   5590,  -7698,  0x00, 0x00, 0x7F, 0xFF
vertex   -101,    205,   -101,   5590,  -8720,  0x00, 0x00, 0x7F, 0xFF
vertex    102,      0,   -101,   5590,  -7698,  0x00, 0x00, 0x7F, 0xFF
vertex   -101,      0,   -101,   5590,  -8720,  0x7F, 0x00, 0x00, 0xFF
vertex   -101,    205,    102,   4568,  -8720,  0x7F, 0x00, 0x00, 0xFF
vertex   -101,      0,    102,   4568,  -8720,  0x7F, 0x00, 0x00, 0xFF
vertex   -101,    205,   -101,   5590,  -8720,  0x7F, 0x00, 0x00, 0xFF
vertex   -101,    205,    102,   4568,  -8720,  0x00, 0x00, 0x81, 0xFF
vertex    102,      0,    102,   4568,  -7698,  0x00, 0x00, 0x81, 0xFF
vertex   -101,      0,    102,   4568,  -8720,  0x00, 0x00, 0x81, 0xFF
vertex    102,    205,    102,   4568,  -7698,  0x00, 0x00, 0x81, 0xFF
vertex    102,      0,    102,   4568,  -7698,  0x81, 0x00, 0x00, 0xFF
vertex    102,    205,    102,   4568,  -7698,  0x81, 0x00, 0x00, 0xFF
vertex    102,    205,   -101,   5590,  -7698,  0x81, 0x00, 0x00, 0xFF
vertex    102,      0,   -101,   5590,  -7698,  0x81, 0x00, 0x00, 0xFF

ttm_seg7_vertex_0702B670: # 0x0702B670 - 0x0702B770
vertex   -204,      0,   -204,   6100,  -9230,  0x00, 0x00, 0x81, 0xFF
vertex   -204,    307,   -204,   6100,  -9230,  0x00, 0x00, 0x81, 0xFF
vertex   1024,      0,   -204,   6100,  -3098,  0x00, 0x00, 0x81, 0xFF
vertex   -204,    307,    205,   4056,  -9230,  0x00, 0x00, 0x7F, 0xFF
vertex   -204,      0,    205,   4056,  -9230,  0x00, 0x00, 0x7F, 0xFF
vertex   1024,      0,    205,   4056,  -3098,  0x00, 0x00, 0x7F, 0xFF
vertex   -204,    307,   -204,   6100,  -9230,  0x59, 0x5A, 0x00, 0xFF
vertex   -204,    307,    205,   4056,  -9230,  0x59, 0x5A, 0x00, 0xFF
vertex   -101,    205,    102,   4568,  -8720,  0x59, 0x5A, 0x00, 0xFF
vertex   -101,    205,   -101,   5590,  -8720,  0x59, 0x5A, 0x00, 0xFF
vertex   -204,    307,   -204,   6100,  -9230,  0x18, 0x64, 0x4A, 0xFF
vertex   -101,    205,   -101,   5590,  -8720,  0x18, 0x64, 0x4A, 0xFF
vertex    205,    205,   -204,   6100,  -7186,  0x18, 0x64, 0x4A, 0xFF
vertex    205,    205,   -204,   6100,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex   -101,    205,   -101,   5590,  -8720,  0x00, 0x7F, 0x00, 0xFF
vertex    102,    205,   -101,   5590,  -7698,  0x00, 0x7F, 0x00, 0xFF

ttm_seg7_vertex_0702B770: # 0x0702B770 - 0x0702B870
vertex   -204,    102,    614,   2012,  -9230,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    102,    614,   2012,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    102,    205,   4056,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex   -204,    102,    205,   4056,  -9230,  0x00, 0x7F, 0x00, 0xFF
vertex    205,      0,    205,   4056,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex    205,    102,    205,   4056,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex    205,    102,    614,   2012,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex    205,      0,    614,   2012,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex   -204,      0,    614,   2012,  -9230,  0x00, 0x00, 0x7F, 0xFF
vertex    205,    102,    614,   2012,  -7186,  0x00, 0x00, 0x7F, 0xFF
vertex   -204,    102,    614,   2012,  -9230,  0x00, 0x00, 0x7F, 0xFF
vertex    205,      0,    614,   2012,  -7186,  0x00, 0x00, 0x7F, 0xFF
vertex   -204,    102,   -613,   8144,  -9230,  0x00, 0x00, 0x81, 0xFF
vertex    205,    102,   -613,   8144,  -7186,  0x00, 0x00, 0x81, 0xFF
vertex    205,      0,   -613,   8144,  -7186,  0x00, 0x00, 0x81, 0xFF
vertex   -204,      0,   -613,   8144,  -9230,  0x00, 0x00, 0x81, 0xFF

ttm_seg7_vertex_0702B870: # 0x0702B870 - 0x0702B970
vertex    102,    205,   -101,   5590,  -7698,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    205,    205,   4056,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    205,   -204,   6100,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex    205,      0,   -613,   8144,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex    205,    102,   -613,   8144,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex    205,    102,   -204,   6100,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex    205,      0,   -204,   6100,  -7186,  0x7F, 0x00, 0x00, 0xFF
vertex   -204,    102,   -204,   6100,  -9230,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    102,   -204,   6100,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    102,   -613,   8144,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex   -204,    102,   -613,   8144,  -9230,  0x00, 0x7F, 0x00, 0xFF
vertex   1024,      0,   -204,   6100,  -3098,  0x1E, 0x7B, 0x00, 0xFF
vertex    205,    205,   -204,   6100,  -7186,  0x1E, 0x7B, 0x00, 0xFF
vertex    205,    205,    205,   4056,  -7186,  0x1E, 0x7B, 0x00, 0xFF
vertex   1024,      0,    205,   4056,  -3098,  0x1E, 0x7B, 0x00, 0xFF
vertex    102,    205,    102,   4568,  -7698,  0x00, 0x7F, 0x00, 0xFF

ttm_seg7_vertex_0702B970: # 0x0702B970 - 0x0702B9D0
vertex    205,    205,    205,   4056,  -7186,  0x00, 0x7F, 0x00, 0xFF
vertex    102,    205,    102,   4568,  -7698,  0x00, 0x7F, 0x00, 0xFF
vertex   -101,    205,    102,   4568,  -8720,  0x00, 0x7F, 0x00, 0xFF
vertex    205,    205,    205,   4056,  -7186,  0x18, 0x64, 0xB6, 0xFF
vertex   -101,    205,    102,   4568,  -8720,  0x18, 0x64, 0xB6, 0xFF
vertex   -204,    307,    205,   4056,  -9230,  0x18, 0x64, 0xB6, 0xFF

ttm_seg7_dl_0702B9D0: # 0x0702B9D0 - 0x0702BB60
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, ttm_seg7_texture_0702AD30
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight ttm_seg7_light_0702ACF0, 1
gsSPLight ttm_seg7_light_0702ACE8, 2
gsSPVertex ttm_seg7_vertex_0702B530, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSPLight ttm_seg7_light_0702AD08, 1
gsSPLight ttm_seg7_light_0702AD00, 2
gsSPVertex ttm_seg7_vertex_0702B570, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  7,  5, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 11,  9, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPLight ttm_seg7_light_0702AD20, 1
gsSPLight ttm_seg7_light_0702AD18, 2
gsSPVertex ttm_seg7_vertex_0702B670, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 13, 14, 15, 0x0
gsSPVertex ttm_seg7_vertex_0702B770, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 11,  9, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex ttm_seg7_vertex_0702B870, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  5,  6, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7,  9, 10, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 13, 14, 0x0
gsSP1Triangle  0, 15,  1, 0x0
gsSPVertex ttm_seg7_vertex_0702B970, 6, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSPEndDisplayList

glabel ttm_seg7_dl_0702BB60 # 0x0702BB60 - 0x0702BBD0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList ttm_seg7_dl_0702B9D0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList