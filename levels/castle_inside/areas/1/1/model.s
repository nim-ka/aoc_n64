inside_castle_seg7_vertex_07023CB0: # 0x07023CB0 - 0x07023DB0
vertex  -7395,   1126,  -5772,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,   1126,  -5989,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,   1434,  -5989,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7395,   1434,  -5772,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,   1126,  -5989,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -6961,   1126,  -6206,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -6961,   1434,  -6206,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,   1434,  -5989,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7395,    819,  -5772,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,    819,  -5989,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,   1126,  -5989,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7395,   1126,  -5772,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,    819,  -5989,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -6961,    819,  -6206,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -6961,   1126,  -6206,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  -7178,   1126,  -5989,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel inside_castle_seg7_dl_07023DB0 # 0x07023DB0 - 0x07023FE0
gsDPPipeSync
gsDPSetCycleType G_CYC_2CYCLE
gsDPSetCombineMode G_CCMUX_TEXEL1, G_CCMUX_TEXEL0, G_CCMUX_LOD_FRACTION, G_CCMUX_TEXEL0, G_ACMUX_TEXEL1, G_ACMUX_TEXEL0, G_ACMUX_LOD_FRACTION, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_COMBINED, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetRenderMode G_RM_PASS, G_RM_AA_ZB_OPA_SURF2
gsDPSetTextureLOD G_TL_LOD
gsSPClearGeometryMode G_LIGHTING | G_SHADING_SMOOTH
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 256, 1, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 1, 0, 0, 124, 124
gsSPTexture -1, -1, 1, 0, 1
gsSPVertex inside_castle_seg7_vertex_07023CB0, 16, 0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07008000
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07006000
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07008800
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07006800
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07009000
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07007000
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07009800
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, inside_castle_seg7_texture_07007800
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPTexture -1, -1, 1, 0, 0
gsDPPipeSync
gsDPSetCycleType G_CYC_1CYCLE
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetRenderMode G_RM_AA_ZB_OPA_SURF, G_RM_NOOP2
gsDPSetTextureLOD G_TL_TILE
gsSPSetGeometryMode G_LIGHTING | G_SHADING_SMOOTH
gsSPEndDisplayList