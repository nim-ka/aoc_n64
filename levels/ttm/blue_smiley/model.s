ttm_seg7_vertex_0702A948: # 0x0702A948 - 0x0702A988
vertex   1024,   2048,      0,    990,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -1023,   2048,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -1023,      0,      0,      0,    990,  0xFF, 0xFF, 0xFF, 0xFF
vertex   1024,      0,      0,    990,    990,  0xFF, 0xFF, 0xFF, 0xFF

ttm_seg7_dl_0702A988: # 0x0702A988 - 0x0702A9C0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mountain_09002800
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex ttm_seg7_vertex_0702A948, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSPEndDisplayList

glabel ttm_seg7_dl_0702A9C0 # 0x0702A9C0 - 0x0702AA30
gsDPPipeSync
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPClearGeometryMode G_LIGHTING
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC
gsSPDisplayList ttm_seg7_dl_0702A988
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF
gsDPPipeSync
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList
