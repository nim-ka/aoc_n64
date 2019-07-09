# Water Ring

water_ring_seg6_light_06012368: # 0x06012368
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

water_ring_seg6_light_06012370: # 0x06012370
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

water_ring_seg6_texture_06012380: # 0x06012380
.incbin "actors/water_ring/water_ring.rgba16"

water_ring_seg6_vertex_06013380: # 0x06013380
vertex      0,    264,      0,      0,      0,  0x00, 0x2A, 0x77, 0x00
vertex   -131,    228,      0,      0,      0,  0xEB, 0x25, 0x77, 0x00
vertex    -98,    171,     23,      0,      0,  0xEB, 0x25, 0x77, 0x00
vertex      0,    198,     23,      0,      0,  0x00, 0x2A, 0x77, 0x00
vertex      0,    198,     23,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex    -98,    171,     23,      0,      0,  0x3F, 0x93, 0x00, 0x00
vertex    -98,    171,    -23,      0,      0,  0x3F, 0x93, 0x00, 0x00
vertex      0,    198,    -23,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex      0,    198,    -23,      0,      0,  0x00, 0x2A, 0x89, 0x00
vertex    -98,    171,    -23,      0,      0,  0xEB, 0x25, 0x89, 0x00
vertex   -131,    228,      0,      0,      0,  0xEB, 0x25, 0x89, 0x00
vertex      0,    264,      0,      0,      0,  0x00, 0x2A, 0x89, 0x00
vertex   -227,    132,      0,      0,      0,  0xDB, 0x15, 0x77, 0x00
vertex   -170,     99,     23,      0,      0,  0xDB, 0x15, 0x77, 0x00
vertex   -170,     99,     23,      0,      0,  0x6D, 0xC1, 0x00, 0x00
vertex   -170,     99,    -23,      0,      0,  0x6D, 0xC1, 0x00, 0x00

water_ring_seg6_vertex_06013480: # 0x06013480
vertex    -98,    171,    -23,      0,      0,  0xEB, 0x25, 0x89, 0x00
vertex   -170,     99,    -23,      0,      0,  0xDB, 0x15, 0x89, 0x00
vertex   -227,    132,      0,      0,      0,  0xDB, 0x15, 0x89, 0x00
vertex   -131,    228,      0,      0,      0,  0xEB, 0x25, 0x89, 0x00
vertex   -227,    132,      0,      0,      0,  0xDB, 0x15, 0x77, 0x00
vertex   -263,      0,      0,      0,      0,  0xD6, 0x00, 0x77, 0x00
vertex   -197,      0,     23,      0,      0,  0xD6, 0x00, 0x77, 0x00
vertex   -170,     99,     23,      0,      0,  0xDB, 0x15, 0x77, 0x00
vertex   -170,     99,     23,      0,      0,  0x6D, 0xC1, 0x00, 0x00
vertex   -197,      0,     23,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex   -197,      0,    -23,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex   -170,     99,    -23,      0,      0,  0x6D, 0xC1, 0x00, 0x00
vertex   -197,      0,    -23,      0,      0,  0xD6, 0x00, 0x89, 0x00
vertex   -263,      0,      0,      0,      0,  0xD6, 0x00, 0x89, 0x00
vertex   -227,   -132,      0,      0,      0,  0xDB, 0xEB, 0x77, 0x00
vertex   -170,    -99,     23,      0,      0,  0xDB, 0xEB, 0x77, 0x00

water_ring_seg6_vertex_06013580: # 0x06013580
vertex   -197,      0,     23,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex   -170,    -99,     23,      0,      0,  0x6D, 0x3F, 0x00, 0x00
vertex   -170,    -99,    -23,      0,      0,  0x6D, 0x3F, 0x00, 0x00
vertex   -197,      0,    -23,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex   -197,      0,    -23,      0,      0,  0xD6, 0x00, 0x89, 0x00
vertex   -170,    -99,    -23,      0,      0,  0xDB, 0xEB, 0x89, 0x00
vertex   -227,   -132,      0,      0,      0,  0xDB, 0xEB, 0x89, 0x00
vertex   -263,      0,      0,      0,      0,  0xD6, 0x00, 0x89, 0x00
vertex   -227,   -132,      0,      0,      0,  0xDB, 0xEB, 0x77, 0x00
vertex   -131,   -228,      0,      0,      0,  0xEB, 0xDB, 0x77, 0x00
vertex    -98,   -171,     23,      0,      0,  0xEB, 0xDB, 0x77, 0x00
vertex   -170,    -99,     23,      0,      0,  0xDB, 0xEB, 0x77, 0x00
vertex    -98,   -171,     23,      0,      0,  0x3F, 0x6D, 0x00, 0x00
vertex    -98,   -171,    -23,      0,      0,  0x3F, 0x6D, 0x00, 0x00
vertex    -98,   -171,    -23,      0,      0,  0xEB, 0xDB, 0x89, 0x00
vertex   -131,   -228,      0,      0,      0,  0xEB, 0xDB, 0x89, 0x00

water_ring_seg6_vertex_06013680: # 0x06013680
vertex   -131,   -228,      0,      0,      0,  0xEB, 0xDB, 0x77, 0x00
vertex      0,   -264,      0,      0,      0,  0x00, 0xD6, 0x77, 0x00
vertex      0,   -198,     23,      0,      0,  0x00, 0xD6, 0x77, 0x00
vertex    -98,   -171,     23,      0,      0,  0xEB, 0xDB, 0x77, 0x00
vertex    -98,   -171,     23,      0,      0,  0x3F, 0x6D, 0x00, 0x00
vertex      0,   -198,     23,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,   -198,    -23,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -98,   -171,    -23,      0,      0,  0x3F, 0x6D, 0x00, 0x00
vertex    -98,   -171,    -23,      0,      0,  0xEB, 0xDB, 0x89, 0x00
vertex      0,   -198,    -23,      0,      0,  0x00, 0xD6, 0x89, 0x00
vertex      0,   -264,      0,      0,      0,  0x00, 0xD6, 0x89, 0x00
vertex   -131,   -228,      0,      0,      0,  0xEB, 0xDB, 0x89, 0x00
vertex    132,   -228,      0,      0,      0,  0x15, 0xDB, 0x77, 0x00
vertex     99,   -171,     23,      0,      0,  0x15, 0xDB, 0x77, 0x00
vertex     99,   -171,     23,      0,      0,  0xC1, 0x6D, 0x00, 0x00
vertex     99,   -171,    -23,      0,      0,  0xC1, 0x6D, 0x00, 0x00

water_ring_seg6_vertex_06013780: # 0x06013780
vertex      0,   -198,    -23,      0,      0,  0x00, 0xD6, 0x89, 0x00
vertex     99,   -171,    -23,      0,      0,  0x15, 0xDB, 0x89, 0x00
vertex    132,   -228,      0,      0,      0,  0x15, 0xDB, 0x89, 0x00
vertex      0,   -264,      0,      0,      0,  0x00, 0xD6, 0x89, 0x00
vertex    132,   -228,      0,      0,      0,  0x15, 0xDB, 0x77, 0x00
vertex    229,   -132,      0,      0,      0,  0x25, 0xEB, 0x77, 0x00
vertex    172,    -99,     23,      0,      0,  0x25, 0xEB, 0x77, 0x00
vertex     99,   -171,     23,      0,      0,  0x15, 0xDB, 0x77, 0x00
vertex     99,   -171,     23,      0,      0,  0xC1, 0x6D, 0x00, 0x00
vertex    172,    -99,     23,      0,      0,  0x93, 0x3F, 0x00, 0x00
vertex    172,    -99,    -23,      0,      0,  0x93, 0x3F, 0x00, 0x00
vertex     99,   -171,    -23,      0,      0,  0xC1, 0x6D, 0x00, 0x00
vertex    172,    -99,    -23,      0,      0,  0x25, 0xEB, 0x89, 0x00
vertex    229,   -132,      0,      0,      0,  0x25, 0xEB, 0x89, 0x00
vertex    264,      0,      0,      0,      0,  0x2A, 0x00, 0x77, 0x00
vertex    198,      0,     23,      0,      0,  0x2A, 0x00, 0x77, 0x00

water_ring_seg6_vertex_06013880: # 0x06013880
vertex    172,    -99,     23,      0,      0,  0x93, 0x3F, 0x00, 0x00
vertex    198,      0,     23,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex    198,      0,    -23,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex    172,    -99,    -23,      0,      0,  0x93, 0x3F, 0x00, 0x00
vertex    172,    -99,    -23,      0,      0,  0x25, 0xEB, 0x89, 0x00
vertex    198,      0,    -23,      0,      0,  0x2A, 0x00, 0x89, 0x00
vertex    264,      0,      0,      0,      0,  0x2A, 0x00, 0x89, 0x00
vertex    229,   -132,      0,      0,      0,  0x25, 0xEB, 0x89, 0x00
vertex    264,      0,      0,      0,      0,  0x2A, 0x00, 0x77, 0x00
vertex    229,    132,      0,      0,      0,  0x25, 0x15, 0x77, 0x00
vertex    172,     99,     23,      0,      0,  0x25, 0x15, 0x77, 0x00
vertex    198,      0,     23,      0,      0,  0x2A, 0x00, 0x77, 0x00
vertex    172,     99,     23,      0,      0,  0x93, 0xC1, 0x00, 0x00
vertex    172,     99,    -23,      0,      0,  0x93, 0xC1, 0x00, 0x00
vertex    172,     99,    -23,      0,      0,  0x25, 0x15, 0x89, 0x00
vertex    229,    132,      0,      0,      0,  0x25, 0x15, 0x89, 0x00

water_ring_seg6_vertex_06013980: # 0x06013980
vertex    229,    132,      0,      0,      0,  0x25, 0x15, 0x77, 0x00
vertex    132,    228,      0,      0,      0,  0x15, 0x25, 0x77, 0x00
vertex     99,    171,     23,      0,      0,  0x15, 0x25, 0x77, 0x00
vertex    172,     99,     23,      0,      0,  0x25, 0x15, 0x77, 0x00
vertex    172,     99,     23,      0,      0,  0x93, 0xC1, 0x00, 0x00
vertex     99,    171,     23,      0,      0,  0xC1, 0x93, 0x00, 0x00
vertex     99,    171,    -23,      0,      0,  0xC1, 0x93, 0x00, 0x00
vertex    172,     99,    -23,      0,      0,  0x93, 0xC1, 0x00, 0x00
vertex    172,     99,    -23,      0,      0,  0x25, 0x15, 0x89, 0x00
vertex     99,    171,    -23,      0,      0,  0x15, 0x25, 0x89, 0x00
vertex    132,    228,      0,      0,      0,  0x15, 0x25, 0x89, 0x00
vertex    229,    132,      0,      0,      0,  0x25, 0x15, 0x89, 0x00
vertex      0,    264,      0,      0,      0,  0x00, 0x2A, 0x77, 0x00
vertex      0,    198,     23,      0,      0,  0x00, 0x2A, 0x77, 0x00
vertex      0,    198,     23,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex      0,    198,    -23,      0,      0,  0x00, 0x81, 0x00, 0x00

water_ring_seg6_vertex_06013A80: # 0x06013A80
vertex     99,    171,    -23,      0,      0,  0x15, 0x25, 0x89, 0x00
vertex      0,    198,    -23,      0,      0,  0x00, 0x2A, 0x89, 0x00
vertex      0,    264,      0,      0,      0,  0x00, 0x2A, 0x89, 0x00
vertex    132,    228,      0,      0,      0,  0x15, 0x25, 0x89, 0x00

glabel water_ring_seg6_dl_06013AC0 # 0x06013AC0 - 0x06013DD8
gsDPPipeSync
gsSPSetGeometryMode G_TEXTURE_GEN
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_ENVIRONMENT
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, water_ring_seg6_texture_06012380
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x080
gsDPPipeSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 252, 124
gsSPTexture 6144, 1984, 0, 0, 1
gsSPLight water_ring_seg6_light_06012370, 1
gsSPLight water_ring_seg6_light_06012368, 2
gsSPVertex water_ring_seg6_vertex_06013380, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013480, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013580, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013680, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013780, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013880, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013980, 16, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSP2Triangles  8,  9, 10, 0x0,  8, 10, 11, 0x0
gsSP2Triangles  1, 12, 13, 0x0,  1, 13,  2, 0x0
gsSP2Triangles  5, 14, 15, 0x0,  5, 15,  6, 0x0
gsSPVertex water_ring_seg6_vertex_06013A80, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsDPPipeSync
gsSPClearGeometryMode G_TEXTURE_GEN
gsDPSetEnvColor 255, 255, 255, 255
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPTexture 3968, 1984, 0, 0, 0
gsSPEndDisplayList

water_ring_seg6_animvalue_06013DD8: # 0x06013DD8
.hword 0x0000, 0xC001, 0x000B, 0xFFF5, 0xFFB5, 0xFF53, 0xFED6, 0xFE44
.hword 0xFDA4, 0xFCFE, 0xFC57, 0xFBB7, 0xFB25, 0xFAA8, 0xFA46, 0xFA06
.hword 0xF9EF, 0xF9FC, 0xFA22, 0xFA5D, 0xFAAC, 0xFB0B, 0xFB79, 0xFBF1
.hword 0xFC72, 0xFCF9, 0xFD83, 0xFE0E, 0xFE97, 0xFF1B, 0xFF98, 0x000A
.hword 0x0080, 0x0103, 0x0191, 0x0226, 0x02BE, 0x0355, 0x03E9, 0x0474
.hword 0x04F4, 0x0565, 0x05C4, 0x060B, 0x0639, 0x0649, 0x063D, 0x061B
.hword 0x05E4, 0x059C, 0x0544, 0x04DF, 0x046F, 0x03F6, 0x0377, 0x02F4
.hword 0x026F, 0x01EA, 0x0168, 0x00EC, 0x0077, 0xF9E4, 0xF9F2, 0xFA1C
.hword 0xFA5D, 0xFAB2, 0xFB19, 0xFB8D, 0xFC0D, 0xFC94, 0xFD20, 0xFDAD
.hword 0xFE39, 0xFEBF, 0xFF3D, 0xFFB0, 0x0021, 0x00A0, 0x0127, 0x01B4
.hword 0x0245, 0x02D6, 0x0364, 0x03EC, 0x046C, 0x04E1, 0x0548, 0x059E
.hword 0x05E0, 0x060B, 0x061C, 0x0610, 0x05E6, 0x05A2, 0x0547, 0x04DA
.hword 0x045E, 0x03D7, 0x0348, 0x02B5, 0x0221, 0x0191, 0x0108, 0x0089
.hword 0x0018, 0xFFAC, 0xFF36, 0xFEBA, 0xFE39, 0xFDB6, 0xFD33, 0xFCB2
.hword 0xFC35, 0xFBBE, 0xFB50, 0xFAED, 0xFA96, 0xFA4E, 0xFA17, 0xF9F3
.hword 0xC000, 0xC000, 0xC000, 0xC001, 0xC001, 0xC001, 0xC001, 0xC001
.hword 0xC001, 0xC001, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002
.hword 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002
.hword 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002
.hword 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002
.hword 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002, 0xC002
.hword 0xC002, 0xC001, 0xC001, 0xC001, 0xC001, 0xC001, 0xC001, 0xC001
.hword 0xC000, 0xC000, 0xC000, 0x0000

water_ring_seg6_animindex_06013F40: # 0x06013F40
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0001
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x003B, 0x0002, 0x003B, 0x003D
.hword 0x003B, 0x0078

water_ring_seg6_anim_06013F64: # 0x06013F64
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x3B
.hword 0x02
.word water_ring_seg6_animvalue_06013DD8
.word water_ring_seg6_animindex_06013F40
.word 0

glabel water_ring_seg6_anims_06013F7C # 0x06013F7C
.word water_ring_seg6_anim_06013F64
.word 0
.word 0
