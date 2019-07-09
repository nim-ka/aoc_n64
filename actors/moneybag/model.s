# Moneybag

moneybag_seg6_texture_060039B0: # 0x060039B0
.incbin "actors/moneybag/moneybag_mouth.rgba16"

moneybag_seg6_texture_060049B0: # 0x060049B0
.incbin "actors/moneybag/moneybag_eyes.rgba16"

moneybag_seg6_light_060051B0: # 0x060051B0
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

moneybag_seg6_light_060051B8: # 0x060051B8
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

moneybag_seg6_light_060051C8: # 0x060051C8
.byte 0x00, 0x3F, 0x23, 0x00, 0x00, 0x3F, 0x23, 0x00

moneybag_seg6_light_060051D0: # 0x060051D0
.byte 0x00, 0x7F, 0x47, 0x00, 0x00, 0x7F, 0x47, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

moneybag_seg6_vertex_060051E0: # 0x060051E0
vertex    226,      1,    300,   1988,      0,  0xCD, 0xF8, 0x73, 0xFF
vertex      0,      0,    200,   2656,    358,  0xAC, 0xFB, 0x5E, 0xFF
vertex    278,   -190,    140,    988,    390,  0xD2, 0x96, 0x33, 0xFF
vertex    261,    194,   -174,    824,    392,  0xCC, 0x64, 0xC8, 0xFF
vertex    226,      1,   -299,     -8,      0,  0xCD, 0xF8, 0x8D, 0xFF
vertex      0,      0,   -199,   -672,    312,  0xAC, 0xFB, 0xA2, 0xFF
vertex    261,    194,    175,   1156,    392,  0xCC, 0x64, 0x38, 0xFF
vertex      0,      0,    200,   2656,    312,  0xAC, 0xFB, 0x5E, 0xFF
vertex      0,      0,   -199,   -672,    358,  0xAC, 0xFB, 0xA2, 0xFF
vertex    278,   -190,   -139,    992,    390,  0xD2, 0x96, 0xCD, 0xFF

moneybag_seg6_vertex_06005280: # 0x06005280
vertex      0,      0,    200,      0,      0,  0xAC, 0xFB, 0x5E, 0xFF
vertex    -88,    -68,      0,      0,      0,  0x9F, 0xAF, 0x00, 0xFF
vertex    278,   -190,    140,      0,      0,  0xD2, 0x96, 0x33, 0xFF
vertex    -88,     71,      0,      0,      0,  0x9B, 0x4C, 0x00, 0xFF
vertex    261,    194,    175,      0,      0,  0xCC, 0x64, 0x38, 0xFF
vertex      0,      0,   -199,      0,      0,  0xAC, 0xFB, 0xA2, 0xFF
vertex    278,   -190,   -139,      0,      0,  0xD2, 0x96, 0xCD, 0xFF
vertex    261,    194,   -174,      0,      0,  0xCC, 0x64, 0xC8, 0xFF

glabel moneybag_seg6_dl_06005300 # 0x06005300 - 0x06005358
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, moneybag_seg6_texture_060039B0
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x080
gsSPLight moneybag_seg6_light_060051B8, 1
gsSPLight moneybag_seg6_light_060051B0, 2
gsSPVertex moneybag_seg6_vertex_060051E0, 10, 0
gsSP2Triangles  0,  1,  2, 0x0,  3,  4,  5, 0x0
gsSP2Triangles  6,  7,  0, 0x0,  8,  4,  9, 0x0
gsSPEndDisplayList

glabel moneybag_seg6_dl_06005358 # 0x06005358 - 0x060053B8
gsSPLight moneybag_seg6_light_060051D0, 1
gsSPLight moneybag_seg6_light_060051C8, 2
gsSPVertex moneybag_seg6_vertex_06005280, 8, 0
gsSP2Triangles  0,  1,  2, 0x0,  1,  0,  3, 0x0
gsSP2Triangles  3,  0,  4, 0x0,  3,  5,  1, 0x0
gsSP2Triangles  6,  2,  1, 0x0,  1,  5,  6, 0x0
gsSP2Triangles  5,  3,  7, 0x0,  4,  7,  3, 0x0
gsSPEndDisplayList

glabel moneybag_seg6_dl_060053B8 # 0x060053B8 - 0x06005428
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 252, 124
gsSPDisplayList moneybag_seg6_dl_06005300
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsSPDisplayList moneybag_seg6_dl_06005358
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

moneybag_seg6_light_06005428: # 0x06005428
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

moneybag_seg6_light_06005430: # 0x06005430
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

moneybag_seg6_vertex_06005440: # 0x06005440
vertex    418,     89,   -157,    388,      0,  0x46, 0x62, 0xDB, 0xFF
vertex    261,    194,    175,   1604,    408,  0x46, 0x62, 0x25, 0xFF
vertex    418,     89,    157,   1540,      0,  0x43, 0x5B, 0x39, 0xFF
vertex    418,     89,    157,    684,      0,  0x43, 0x5B, 0x39, 0xFF
vertex    261,    194,    175,   1156,    392,  0x46, 0x62, 0x25, 0xFF
vertex    226,      1,    300,   1988,      0,  0x34, 0xF9, 0x73, 0xFF
vertex    418,     89,   -157,   1296,      0,  0x46, 0x62, 0xDB, 0xFF
vertex    226,      1,   -299,     -8,      0,  0x33, 0xF9, 0x8D, 0xFF
vertex    261,    194,   -174,    824,    392,  0x43, 0x5B, 0xC7, 0xFF
vertex    418,    -85,   -157,   1296,      0,  0x28, 0xBA, 0x9F, 0xFF
vertex    278,   -190,   -139,    992,    390,  0x46, 0x9D, 0xDD, 0xFF
vertex    278,   -190,    140,    988,    390,  0x40, 0xA1, 0x35, 0xFF
vertex    418,    -85,    157,    684,      0,  0x28, 0xBA, 0x61, 0xFF
vertex    261,    194,   -174,    324,    408,  0x43, 0x5B, 0xC7, 0xFF

moneybag_seg6_vertex_06005520: # 0x06005520
vertex    278,   -190,   -139,   1512,    416,  0x46, 0x9D, 0xDD, 0xFF
vertex    418,    -85,   -156,   1588,      0,  0x4C, 0x9B, 0x00, 0xFF
vertex    418,    -85,    158,    248,      0,  0x4C, 0x9B, 0x00, 0xFF
vertex    278,   -190,    140,    320,    416,  0x40, 0xA1, 0x35, 0xFF
vertex    238,    -15,    286,   2336,    754,  0x3E, 0xCE, 0x62, 0xFF
vertex    272,     77,    312,    124,   1062,  0x3E, 0xCE, 0x62, 0xFF
vertex    229,     73,    337,    124,    436,  0x3E, 0xCE, 0x62, 0xFF

glabel moneybag_seg6_dl_06005590 # 0x06005590 - 0x06005618
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, moneybag_seg6_texture_060039B0
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x080
gsSPLight moneybag_seg6_light_06005430, 1
gsSPLight moneybag_seg6_light_06005428, 2
gsSPVertex moneybag_seg6_vertex_06005440, 14, 0
gsSP2Triangles  0,  1,  2, 0x0,  3,  4,  5, 0x0
gsSP2Triangles  6,  7,  8, 0x0,  9, 10,  7, 0x0
gsSP2Triangles  5, 11, 12, 0x0,  0, 13,  1, 0x0
gsSPVertex moneybag_seg6_vertex_06005520, 7, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSPEndDisplayList

glabel moneybag_seg6_dl_06005618 # 0x06005618 - 0x06005688
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsSPClearGeometryMode G_CULL_BACK
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 252, 124
gsSPDisplayList moneybag_seg6_dl_06005590
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_CULL_BACK
gsSPEndDisplayList

glabel moneybag_seg6_dl_06005688 # 0x06005688 - 0x060056A8
gsSPDisplayList moneybag_seg6_dl_060053B8
gsSPDisplayList moneybag_seg6_dl_06005618
gsDPSetEnvColor 255, 255, 255, 255
gsSPEndDisplayList

moneybag_seg6_vertex_060056A8: # 0x060056A8
vertex    356,    121,   -159,    960,      4,  0xFF, 0xFF, 0xFF, 0xFF
vertex    356,   -128,    150,     28,    918,  0xFF, 0xFF, 0xFF, 0xFF
vertex    356,   -128,   -149,    930,    918,  0xFF, 0xFF, 0xFF, 0xFF
vertex    356,    121,    160,     -2,      4,  0xFF, 0xFF, 0xFF, 0xFF
vertex    226,      1,    298,   -414,    442,  0xFF, 0xFF, 0xFF, 0xFF
vertex    226,      1,   -297,   1374,    442,  0xFF, 0xFF, 0xFF, 0xFF

glabel moneybag_seg6_dl_06005708 # 0x06005708 - 0x06005750
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, moneybag_seg6_texture_060049B0
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex moneybag_seg6_vertex_060056A8, 6, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  3,  1, 0x0
gsSP2Triangles  1,  3,  4, 0x0,  5,  0,  2, 0x0
gsSPEndDisplayList

glabel moneybag_seg6_dl_06005750 # 0x06005750 - 0x060057C0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsSPClearGeometryMode G_LIGHTING
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList moneybag_seg6_dl_06005708
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList

# Unreferenced light
.byte 0x0C, 0x20, 0x06, 0x00, 0x0C, 0x20, 0x06, 0x00

.byte 0x30, 0x83, 0x1A, 0x00, 0x30, 0x83, 0x1A, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

moneybag_seg6_light_060057F0: # 0x060057F0
.byte 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00

moneybag_seg6_light_060057F8: # 0x060057F8
.byte 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

moneybag_seg6_vertex_06005820: # 0x06005820
vertex      0,      0,      0,      0,      0,  0x83, 0x11, 0x00, 0x00
vertex    180,     90,      0,      0,      0,  0xC8, 0x71, 0x00, 0x00
vertex    180,     40,    -80,      0,      0,  0xC8, 0x2A, 0x97, 0x00
vertex    180,   -120,    -40,      0,      0,  0xBB, 0xB0, 0xBB, 0xFF
vertex    180,   -120,     40,      0,      0,  0xBB, 0xB0, 0x45, 0xFF
vertex    180,     90,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     40,     80,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,   -120,     40,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,   -120,    -40,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     40,    -80,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     40,     80,      0,      0,  0xC8, 0x2A, 0x69, 0xFF

moneybag_seg6_vertex_060058D0: # 0x060058D0
vertex    180,     40,     80,      0,      0,  0xC8, 0x2A, 0x69, 0x00
vertex    180,     90,      0,      0,      0,  0xC8, 0x71, 0x00, 0x00
vertex      0,      0,      0,      0,      0,  0x83, 0x11, 0x00, 0x00
vertex    180,   -120,    -40,      0,      0,  0xBB, 0xB0, 0xBB, 0xFF
vertex    180,   -120,     40,      0,      0,  0xBB, 0xB0, 0x45, 0xFF
vertex    180,   -120,    -40,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     40,    -80,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     90,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,   -120,     40,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     40,     80,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    180,     40,    -80,      0,      0,  0xC8, 0x2A, 0x97, 0xFF

glabel moneybag_seg6_dl_06005980 # 0x06005980 - 0x060059F0
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsSPLight moneybag_seg6_light_060057F8, 1
gsSPLight moneybag_seg6_light_060057F0, 2
gsSPVertex moneybag_seg6_vertex_06005820, 11, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  3,  4, 0x0
gsSP2Triangles  5,  6,  7, 0x0,  5,  7,  8, 0x0
gsSP2Triangles  5,  8,  9, 0x0, 10,  1,  0, 0x0
gsSP2Triangles  0,  4, 10, 0x0,  2,  3,  0, 0x0
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

glabel moneybag_seg6_dl_060059F0 # 0x060059F0 - 0x06005A60
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsSPLight moneybag_seg6_light_060057F8, 1
gsSPLight moneybag_seg6_light_060057F0, 2
gsSPVertex moneybag_seg6_vertex_060058D0, 11, 0
gsSP2Triangles  0,  1,  2, 0x0,  3,  4,  2, 0x0
gsSP2Triangles  5,  6,  7, 0x0,  8,  5,  7, 0x0
gsSP2Triangles  9,  8,  7, 0x0,  2,  1, 10, 0x0
gsSP2Triangles 10,  3,  2, 0x0,  2,  4,  0, 0x0
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

moneybag_seg6_animvalue_06005A60: # 0x06005A60
.hword 0x0000, 0x00B4, 0xFF1A, 0x1FFF, 0x3FFF, 0x1FFF, 0x8001, 0xC001
.hword 0xC001, 0x8001, 0x8001, 0x8001

moneybag_seg6_animindex_06005A78: # 0x06005A78
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003
.hword 0x0001, 0x0004, 0x0001, 0x0005, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x000B, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x000A
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0007, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0009, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0008, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0006

moneybag_seg6_anim_06005AD8: # 0x06005AD8
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x1E
.hword 0x07
.word moneybag_seg6_animvalue_06005A60
.word moneybag_seg6_animindex_06005A78
.word 0

moneybag_seg6_animvalue_06005AF0: # 0x06005AF0
.hword 0x0000, 0x00B4, 0x00B4, 0x00B4, 0x00B4, 0x00B4, 0x00B4, 0x00D3
.hword 0x00F0, 0x00F0, 0x00F0, 0xFF1A, 0x3FFF, 0x3B84, 0x3FFF, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFED, 0xFFCD, 0xFFC6
.hword 0x0000, 0x5FCF, 0x629C, 0x6931, 0x70D4, 0x76C7, 0x7851, 0x72FB
.hword 0x68D5, 0x5DA7, 0x5537, 0xDBB5, 0xD928, 0xD276, 0xCAAE, 0xC4D8
.hword 0xC343, 0xD86B, 0xF157, 0x0A0A, 0x1E86, 0xDBB5, 0xD8F4, 0xD287
.hword 0xCAAE, 0xC507, 0xC343, 0xDB90, 0xF887, 0x1452, 0x291E, 0x8001
.hword 0x8001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFED
.hword 0xFFCD, 0xFFC6, 0x0000, 0x5FCF, 0x629C, 0x6931, 0x70D4, 0x76C7
.hword 0x7851, 0x72FB, 0x68D5, 0x5DA7, 0x5537, 0x0000

moneybag_seg6_animindex_06005B8C: # 0x06005B8C
.hword 0x0001, 0x0000, 0x000A, 0x0001, 0x0001, 0x000B, 0x0001, 0x000C
.hword 0x0001, 0x000D, 0x0001, 0x000E, 0x0001, 0x0000, 0x000A, 0x0039
.hword 0x000A, 0x0043, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0038
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x000A, 0x0023, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0037, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x000A, 0x002D, 0x0001, 0x0000, 0x000A, 0x000F, 0x000A, 0x0019

moneybag_seg6_anim_06005BEC: # 0x06005BEC
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x0A
.hword 0x07
.word moneybag_seg6_animvalue_06005AF0
.word moneybag_seg6_animindex_06005B8C
.word 0

moneybag_seg6_animvalue_06005C04: # 0x06005C04
.hword 0x0000, 0x00F0, 0xFF1A, 0x3FFF, 0x3B84, 0x3FFF, 0xFF99, 0x026A
.hword 0xFF99, 0xFCC7, 0x5537, 0x2406, 0x2986, 0x2406, 0x1E86, 0x243A
.hword 0x1F56, 0x243A, 0x291E, 0x8001, 0x8001, 0xFF99, 0x026A, 0xFF99
.hword 0xFCC7, 0x5537

moneybag_seg6_animindex_06005C38: # 0x06005C38
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003
.hword 0x0001, 0x0004, 0x0001, 0x0005, 0x0001, 0x0000, 0x0004, 0x0015
.hword 0x0001, 0x0019, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0014
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0004, 0x000B, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0013, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0004, 0x000F, 0x0001, 0x0000, 0x0004, 0x0006, 0x0001, 0x000A

moneybag_seg6_anim_06005C98: # 0x06005C98
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x04
.hword 0x07
.word moneybag_seg6_animvalue_06005C04
.word moneybag_seg6_animindex_06005C38
.word 0

moneybag_seg6_animvalue_06005CB0: # 0x06005CB0
.hword 0x0000, 0x00E9, 0x00DE, 0x00D0, 0xFF1A, 0x3FFF, 0x3B84, 0x3FFF
.hword 0x56CC, 0x58BF, 0x5AD8, 0x0F8B, 0xFC25, 0xE93B, 0x0E14, 0xFA02
.hword 0xE77D, 0x8001, 0x8001, 0x56CC, 0x58BF, 0x5AD8

moneybag_seg6_animindex_06005CDC: # 0x06005CDC
.hword 0x0001, 0x0000, 0x0003, 0x0001, 0x0001, 0x0004, 0x0001, 0x0005
.hword 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0003, 0x0013, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0012
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0003, 0x000B, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0011, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0003, 0x000E, 0x0001, 0x0000, 0x0001, 0x0000, 0x0003, 0x0008

moneybag_seg6_anim_06005D3C: # 0x06005D3C
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x03
.hword 0x07
.word moneybag_seg6_animvalue_06005CB0
.word moneybag_seg6_animindex_06005CDC
.word 0

moneybag_seg6_animvalue_06005D54: # 0x06005D54
.hword 0x0000, 0x00B4, 0xFF1A, 0x3FFF, 0x3B84, 0x3FFF, 0x5FCF, 0x62B8
.hword 0x6758, 0x6BA0, 0x6D82, 0x6B5E, 0x66A8, 0x61F3, 0xF6B5, 0xFD63
.hword 0x0000, 0xFBB1, 0xF323, 0xEAC2, 0xE6FC, 0xEAE5, 0x10B8, 0x0568
.hword 0x0000, 0x0456, 0x0E78, 0x18B6, 0x1D63, 0x18CC, 0xCB51, 0xD1A7
.hword 0xD3F8, 0xCF36, 0xC62D, 0xBDA4, 0xBA61, 0xC022, 0x0B33, 0x1144
.hword 0x13E9, 0x10FC, 0x0A72, 0x03AA, 0x0000, 0x0154, 0xEDCE, 0xE3F3
.hword 0xDFA7, 0xE4C7, 0xF004, 0xFB28, 0x0000, 0xFA46, 0xCBE1, 0xC320
.hword 0xBECD, 0xC17F, 0xC8B2, 0xD070, 0xD4C8, 0xD3C1, 0x8001, 0x8001
.hword 0x5FCF, 0x62B8, 0x6758, 0x6BA0, 0x6D82, 0x6B5E, 0x66A8, 0x61F3

moneybag_seg6_animindex_06005DE4: # 0x06005DE4
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003
.hword 0x0001, 0x0004, 0x0001, 0x0005, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0008, 0x0040, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x003F
.hword 0x0008, 0x000E, 0x0008, 0x0016, 0x0008, 0x001E, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x003E, 0x0008, 0x0026, 0x0008, 0x002E
.hword 0x0008, 0x0036, 0x0001, 0x0000, 0x0001, 0x0000, 0x0008, 0x0006

moneybag_seg6_anim_06005E44: # 0x06005E44
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x08
.hword 0x07
.word moneybag_seg6_animvalue_06005D54
.word moneybag_seg6_animindex_06005DE4
.word 0

glabel moneybag_seg6_anims_06005E5C # 0x06005E5C
.word moneybag_seg6_anim_06005AD8
.word moneybag_seg6_anim_06005BEC
.word moneybag_seg6_anim_06005C98
.word moneybag_seg6_anim_06005D3C
.word moneybag_seg6_anim_06005E44
