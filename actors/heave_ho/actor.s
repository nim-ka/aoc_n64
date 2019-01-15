# Heave Ho

# Unreferenced light
.byte 0x2C, 0x2C, 0x2C, 0x00, 0x2C, 0x2C, 0x2C, 0x00

.byte 0xB2, 0xB2, 0xB2, 0x00, 0xB2, 0xB2, 0xB2, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x3F, 0x38, 0x00, 0x00, 0x3F, 0x38, 0x00, 0x00

.byte 0xFF, 0xE3, 0x00, 0x00, 0xFF, 0xE3, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00

.byte 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_light_0500E968: # 0x0500E968
.byte 0x14, 0x14, 0x15, 0x00, 0x14, 0x14, 0x15, 0x00

heave_ho_seg5_light_0500E970: # 0x0500E970
.byte 0x50, 0x50, 0x54, 0x00, 0x50, 0x50, 0x54, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_light_0500E980: # 0x0500E980
.byte 0x73, 0x3F, 0x32, 0x00, 0x73, 0x3F, 0x32, 0x00

heave_ho_seg5_light_0500E988: # 0x0500E988
.byte 0xFF, 0xE0, 0x85, 0x00, 0xFF, 0xE0, 0x85, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x3B, 0x38, 0x21, 0x00, 0x3B, 0x38, 0x21, 0x00

.byte 0xEC, 0xE3, 0x84, 0x00, 0xEC, 0xE3, 0x84, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x32, 0x32, 0x32, 0x00, 0x32, 0x32, 0x32, 0x00

.byte 0xC8, 0xC8, 0xC8, 0x00, 0xC8, 0xC8, 0xC8, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_texture_0500E9C8: # 0x0500E9C8
.incbin "actors/heave_ho/0.rgba16"

heave_ho_seg5_texture_0500F1C8: # 0x0500F1C8
.incbin "actors/heave_ho/1.rgba16"

heave_ho_seg5_texture_0500F9C8: # 0x0500F9C8
.incbin "actors/heave_ho/2.rgba16"

heave_ho_seg5_texture_050109C8: # 0x050109C8
.incbin "actors/heave_ho/3.rgba16"

heave_ho_seg5_texture_050111C8: # 0x050111C8
.incbin "actors/heave_ho/4.rgba16"

heave_ho_seg5_texture_050113C8: # 0x050113C8
.incbin "actors/heave_ho/5.rgba16"

heave_ho_seg5_light_05011BC8: # 0x05011BC8
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

heave_ho_seg5_light_05011BD0: # 0x05011BD0
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_light_05011BE0: # 0x05011BE0
.byte 0x40, 0x00, 0x0D, 0x00, 0x40, 0x00, 0x0D, 0x00

heave_ho_seg5_light_05011BE8: # 0x05011BE8
.byte 0x81, 0x01, 0x1A, 0x00, 0x81, 0x01, 0x1A, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_vertex_05011BF8: # 0x05011BF8
vertex    -23,    108,    -47,     96,   -150,  0xD4, 0x70, 0xDA, 0xFF
vertex   -107,    -11,    -95,   -286,   1018,  0xA6, 0xBD, 0xC6, 0xFF
vertex   -107,    -11,     96,   1246,   1018,  0x90, 0x28, 0x2B, 0xFF
vertex    -23,    108,     48,    862,   -150,  0xD9, 0x6A, 0x39, 0xFF

heave_ho_seg5_vertex_05011C38: # 0x05011C38
vertex    -23,    108,    -47,    862,   -822,  0xD4, 0x70, 0xDA, 0xFF
vertex    -23,    108,     48,     96,   -822,  0xD9, 0x6A, 0x39, 0xFF
vertex    132,     86,     72,    -94,    236,  0x30, 0x6E, 0x27, 0xFF
vertex    132,     86,    -71,   1054,    236,  0x2B, 0x67, 0xC4, 0xFF
vertex    233,     -9,     72,    -94,   1170,  0x51, 0xBA, 0x43, 0xFF
vertex    233,     -9,    -71,   1054,   1170,  0x68, 0x31, 0xCC, 0xFF

heave_ho_seg5_vertex_05011C98: # 0x05011C98
vertex    132,     86,    -71,   1736,   -108,  0x2B, 0x67, 0xC4, 0xFF
vertex     24,    -11,   -155,     36,   1382,  0x00, 0xBF, 0x93, 0xFF
vertex    -23,    108,    -47,   -452,   -292,  0xD4, 0x70, 0xDA, 0xFF
vertex    233,     -9,    -71,   3024,   1182,  0x68, 0x31, 0xCC, 0xFF
vertex   -107,    -11,    -95,  -1844,   1486,  0xA6, 0xBD, 0xC6, 0xFF
vertex    -23,    108,     48,   -452,   -292,  0xD9, 0x6A, 0x39, 0xFF
vertex     24,    -11,    156,     36,   1382,  0x00, 0xBF, 0x6D, 0xFF
vertex    132,     86,     72,   1736,   -108,  0x30, 0x6E, 0x27, 0xFF
vertex   -107,    -11,     96,  -1844,   1486,  0x90, 0x28, 0x2B, 0xFF
vertex    233,     -9,     72,   3024,   1182,  0x51, 0xBA, 0x43, 0xFF

heave_ho_seg5_vertex_05011D38: # 0x05011D38
vertex   -107,    -11,    -95,      0,      0,  0xA6, 0xBD, 0xC6, 0xFF
vertex     24,    -11,    156,      0,      0,  0x00, 0xBF, 0x6D, 0xFF
vertex   -107,    -11,     96,      0,      0,  0x90, 0x28, 0x2B, 0xFF
vertex     24,    -11,   -155,      0,      0,  0x00, 0xBF, 0x93, 0xFF
vertex    233,     -9,    -71,      0,      0,  0x68, 0x31, 0xCC, 0xFF
vertex    233,     -9,     72,      0,      0,  0x51, 0xBA, 0x43, 0xFF

glabel heave_ho_seg5_dl_05011D98 # 0x05011D98 - 0x05011DE0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_0500E9C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight heave_ho_seg5_light_05011BD0, 1
gsSPLight heave_ho_seg5_light_05011BC8, 2
gsSPVertex heave_ho_seg5_vertex_05011BF8, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05011DE0 # 0x05011DE0 - 0x05011E28
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_050109C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex heave_ho_seg5_vertex_05011C38, 6, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  2,  4,  5, 0x0
gsSP1Triangle  2,  5,  3, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05011E28 # 0x05011E28 - 0x05011E80
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_0500F9C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x080
gsSPVertex heave_ho_seg5_vertex_05011C98, 10, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  2,  1,  4, 0x0
gsSP1Triangle  5,  6,  7, 0x0
gsSP1Triangle  8,  6,  5, 0x0
gsSP1Triangle  6,  9,  7, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05011E80 # 0x05011E80 - 0x05011EC0
gsSPLight heave_ho_seg5_light_05011BE8, 1
gsSPLight heave_ho_seg5_light_05011BE0, 2
gsSPVertex heave_ho_seg5_vertex_05011D38, 6, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  5,  1, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05011EC0 # 0x05011EC0 - 0x05011F50
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList heave_ho_seg5_dl_05011D98
gsSPDisplayList heave_ho_seg5_dl_05011DE0
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 252, 124
gsSPDisplayList heave_ho_seg5_dl_05011E28
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPDisplayList heave_ho_seg5_dl_05011E80
gsSPEndDisplayList

heave_ho_seg5_light_05011F50: # 0x05011F50
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

heave_ho_seg5_light_05011F58: # 0x05011F58
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_light_05011F68: # 0x05011F68
.byte 0x4C, 0x00, 0x16, 0x00, 0x4C, 0x00, 0x16, 0x00

heave_ho_seg5_light_05011F70: # 0x05011F70
.byte 0x99, 0x00, 0x2D, 0x00, 0x99, 0x00, 0x2D, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_vertex_05011F80: # 0x05011F80
vertex     -1,     -2,    245,   -604,    434,  0xD6, 0xF8, 0x77, 0xFF
vertex    -37,     20,    206,    990,   1372,  0xB4, 0x5F, 0xDF, 0xFF
vertex    -28,    -33,    206,    990,   -368,  0xDB, 0x8C, 0x21, 0xFF
vertex    -37,     20,    206,    198,    552,  0xB4, 0x5F, 0xDF, 0xFF
vertex    218,     73,    204,    774,    552,  0x30, 0x75, 0xFC, 0xFF
vertex    228,      3,    206,    764,    338,  0x6F, 0xC5, 0xF2, 0xFF
vertex    -28,    -33,    206,    194,    386,  0xDB, 0x8C, 0x21, 0xFF
vertex    166,     53,    250,   1112,    914,  0x19, 0x3D, 0x6C, 0xFF
vertex    174,      9,    250,   1060,     34,  0x1E, 0xC0, 0x69, 0xFF
vertex    228,      3,    206,    -98,   -190,  0x6F, 0xC5, 0xF2, 0xFF
vertex    218,     73,    204,    -98,   1190,  0x30, 0x75, 0xFC, 0xFF

heave_ho_seg5_vertex_05012030: # 0x05012030
vertex    166,     53,    250,      0,      0,  0x19, 0x3D, 0x6C, 0xFF
vertex    218,     73,    204,      0,      0,  0x30, 0x75, 0xFC, 0xFF
vertex    -37,     20,    206,      0,      0,  0xB4, 0x5F, 0xDF, 0xFF
vertex     -1,     -2,    245,      0,      0,  0xD6, 0xF8, 0x77, 0xFF
vertex    174,      9,    250,      0,      0,  0x1E, 0xC0, 0x69, 0xFF
vertex    -28,    -33,    206,      0,      0,  0xDB, 0x8C, 0x21, 0xFF
vertex    228,      3,    206,      0,      0,  0x6F, 0xC5, 0xF2, 0xFF

glabel heave_ho_seg5_dl_050120A0 # 0x050120A0 - 0x05012100
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_050109C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight heave_ho_seg5_light_05011F58, 1
gsSPLight heave_ho_seg5_light_05011F50, 2
gsSPVertex heave_ho_seg5_vertex_05011F80, 11, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  5,  6,  3, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  9, 10,  7, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05012100 # 0x05012100 - 0x05012148
gsSPLight heave_ho_seg5_light_05011F70, 1
gsSPLight heave_ho_seg5_light_05011F68, 2
gsSPVertex heave_ho_seg5_vertex_05012030, 7, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  2,  3,  0, 0x0
gsSP1Triangle  4,  0,  3, 0x0
gsSP1Triangle  3,  5,  4, 0x0
gsSP1Triangle  6,  4,  5, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05012148 # 0x05012148 - 0x050121B0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList heave_ho_seg5_dl_050120A0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPDisplayList heave_ho_seg5_dl_05012100
gsSPEndDisplayList

heave_ho_seg5_light_050121B0: # 0x050121B0
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

heave_ho_seg5_light_050121B8: # 0x050121B8
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_light_050121C8: # 0x050121C8
.byte 0x4C, 0x00, 0x16, 0x00, 0x4C, 0x00, 0x16, 0x00

heave_ho_seg5_light_050121D0: # 0x050121D0
.byte 0x99, 0x00, 0x2D, 0x00, 0x99, 0x00, 0x2D, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_vertex_050121E0: # 0x050121E0
vertex    -28,    -33,   -205,    990,   -368,  0xDB, 0x8C, 0xDF, 0xFF
vertex    -37,     20,   -205,    990,   1372,  0xB4, 0x5F, 0x21, 0xFF
vertex     -1,     -2,   -244,   -604,    434,  0xD6, 0xF8, 0x89, 0xFF
vertex    228,      3,   -205,    764,    338,  0x6F, 0xC5, 0x0E, 0xFF
vertex    218,     73,   -203,    774,    552,  0x30, 0x75, 0x04, 0xFF
vertex    -37,     20,   -205,    198,    552,  0xB4, 0x5F, 0x21, 0xFF
vertex    -28,    -33,   -205,    194,    386,  0xDB, 0x8C, 0xDF, 0xFF
vertex    228,      3,   -205,    -98,   -190,  0x6F, 0xC5, 0x0E, 0xFF
vertex    174,      9,   -249,   1060,     34,  0x1E, 0xC0, 0x97, 0xFF
vertex    166,     53,   -249,   1112,    914,  0x19, 0x3D, 0x94, 0xFF
vertex    218,     73,   -203,    -98,   1190,  0x30, 0x75, 0x04, 0xFF

heave_ho_seg5_vertex_05012290: # 0x05012290
vertex    -37,     20,   -205,      0,      0,  0xB4, 0x5F, 0x21, 0xFF
vertex    218,     73,   -203,      0,      0,  0x30, 0x75, 0x04, 0xFF
vertex    166,     53,   -249,      0,      0,  0x19, 0x3D, 0x94, 0xFF
vertex    -28,    -33,   -205,      0,      0,  0xDB, 0x8C, 0xDF, 0xFF
vertex    174,      9,   -249,      0,      0,  0x1E, 0xC0, 0x97, 0xFF
vertex    228,      3,   -205,      0,      0,  0x6F, 0xC5, 0x0E, 0xFF
vertex     -1,     -2,   -244,      0,      0,  0xD6, 0xF8, 0x89, 0xFF

glabel heave_ho_seg5_dl_05012300 # 0x05012300 - 0x05012360
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_050109C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight heave_ho_seg5_light_050121B8, 1
gsSPLight heave_ho_seg5_light_050121B0, 2
gsSPVertex heave_ho_seg5_vertex_050121E0, 11, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  5,  6,  3, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  9, 10,  7, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05012360 # 0x05012360 - 0x050123A8
gsSPLight heave_ho_seg5_light_050121D0, 1
gsSPLight heave_ho_seg5_light_050121C8, 2
gsSPVertex heave_ho_seg5_vertex_05012290, 7, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  2,  4, 0x0
gsSP1Triangle  4,  3,  6, 0x0
gsSP1Triangle  2,  6,  0, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050123A8 # 0x050123A8 - 0x05012410
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList heave_ho_seg5_dl_05012300
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPDisplayList heave_ho_seg5_dl_05012360
gsSPEndDisplayList

heave_ho_seg5_light_05012410: # 0x05012410
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

heave_ho_seg5_light_05012418: # 0x05012418
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_light_05012428: # 0x05012428
.byte 0x5D, 0x6D, 0x65, 0x00, 0x5D, 0x6D, 0x65, 0x00

heave_ho_seg5_light_05012430: # 0x05012430
.byte 0xBB, 0xDA, 0xCB, 0x00, 0xBB, 0xDA, 0xCB, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_vertex_05012440: # 0x05012440
vertex    438,     63,   -205,      0,    990,  0x10, 0x83, 0x00, 0xFF
vertex    438,     63,    206,    990,    990,  0x10, 0x83, 0x00, 0xFF
vertex    146,     25,    206,    990,      0,  0x10, 0x83, 0x00, 0xFF
vertex    146,     25,   -205,      0,      0,  0x10, 0x83, 0x00, 0xFF

heave_ho_seg5_vertex_05012480: # 0x05012480
vertex    188,     61,    206,      0,      0,  0xAE, 0x60, 0x00, 0xFF
vertex    188,     61,   -205,      0,      0,  0xAE, 0x60, 0x00, 0xFF
vertex    146,     25,   -205,      0,      0,  0xAE, 0x60, 0x00, 0xFF
vertex    188,     61,   -205,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    438,     63,   -205,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    146,     25,   -205,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    188,     61,    206,      0,      0,  0xFF, 0x7E, 0x00, 0xFF
vertex    438,     63,   -205,      0,      0,  0xFF, 0x7E, 0x00, 0xFF
vertex    188,     61,   -205,      0,      0,  0xFF, 0x7E, 0x00, 0xFF
vertex    438,     63,    206,      0,      0,  0xFF, 0x7E, 0x00, 0xFF
vertex    146,     25,    206,      0,      0,  0xAE, 0x60, 0x00, 0xFF
vertex    438,     63,    206,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    188,     61,    206,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    146,     25,    206,      0,      0,  0x00, 0x00, 0x7F, 0xFF

glabel heave_ho_seg5_dl_05012560 # 0x05012560 - 0x050125A8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_0500F1C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight heave_ho_seg5_light_05012418, 1
gsSPLight heave_ho_seg5_light_05012410, 2
gsSPVertex heave_ho_seg5_vertex_05012440, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050125A8 # 0x050125A8 - 0x050125F8
gsSPLight heave_ho_seg5_light_05012430, 1
gsSPLight heave_ho_seg5_light_05012428, 2
gsSPVertex heave_ho_seg5_vertex_05012480, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  9,  7, 0x0
gsSP1Triangle  0,  2, 10, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050125F8 # 0x050125F8 - 0x05012670
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList heave_ho_seg5_dl_05012560
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPDisplayList heave_ho_seg5_dl_050125A8
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList

heave_ho_seg5_vertex_05012670: # 0x05012670
vertex    -11,     12,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex     12,    -11,      0,    479,    479,  0xFF, 0xFF, 0xFF, 0xFF
vertex     12,     12,      0,    479,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -11,    -11,      0,      0,    479,  0xFF, 0xFF, 0xFF, 0xFF

glabel heave_ho_seg5_dl_050126B0 # 0x050126B0 - 0x050126E8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_050111C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x0FF, 0x200
gsSPVertex heave_ho_seg5_vertex_05012670, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050126E8 # 0x050126E8 - 0x05012758
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPClearGeometryMode G_LIGHTING
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 4, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 60, 60
gsSPDisplayList heave_ho_seg5_dl_050126B0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList

heave_ho_seg5_light_05012758: # 0x05012758
.byte 0x93, 0x73, 0x7C, 0x00, 0x93, 0x73, 0x7C, 0x00

heave_ho_seg5_light_05012760: # 0x05012760
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

heave_ho_seg5_vertex_05012770: # 0x05012770
vertex     30,    155,      0,      0,    990,  0x00, 0x00, 0x7F, 0xFF
vertex     30,   -153,      0,    990,    990,  0x00, 0x00, 0x7F, 0xFF
vertex    214,    155,      0,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    214,   -153,      0,    990,      0,  0x00, 0x00, 0x7F, 0xFF

glabel heave_ho_seg5_dl_050127B0 # 0x050127B0 - 0x050127F8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heave_ho_seg5_texture_050113C8
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight heave_ho_seg5_light_05012760, 1
gsSPLight heave_ho_seg5_light_05012758, 2
gsSPVertex heave_ho_seg5_vertex_05012770, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  2,  1,  3, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050127F8 # 0x050127F8 - 0x05012868
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_SHADE, G_ACMUX_0, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_SHADE, G_ACMUX_0
gsSPClearGeometryMode G_CULL_BACK | G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList heave_ho_seg5_dl_050127B0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_CULL_BACK | G_SHADING_SMOOTH
gsSPEndDisplayList

heave_ho_seg5_vertex_05012868: # 0x05012868
vertex    -13,     44,     13,      0,      0,  0xDE, 0x75, 0x22, 0x00
vertex      0,     44,     18,      0,      0,  0x00, 0x75, 0x30, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -24,     33,     24,      0,      0,  0xC1, 0x5A, 0x3F, 0xFF
vertex      0,     33,     33,      0,      0,  0x00, 0x5A, 0x59, 0xFF
vertex    -31,     18,     31,      0,      0,  0xAE, 0x30, 0x52, 0xFF
vertex      0,     18,     44,      0,      0,  0x00, 0x30, 0x75, 0xFF
vertex    -33,      0,     33,      0,      0,  0xA7, 0x00, 0x59, 0xFF
vertex      0,      0,     48,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    -31,    -18,     31,      0,      0,  0xAE, 0xD0, 0x52, 0xFF
vertex      0,    -18,     44,      0,      0,  0x00, 0xD0, 0x75, 0xFF
vertex    -24,    -33,     24,      0,      0,  0xC1, 0xA6, 0x3F, 0xFF
vertex      0,    -33,     33,      0,      0,  0x00, 0xA6, 0x59, 0xFF
vertex    -13,    -44,     13,      0,      0,  0xDE, 0x8B, 0x22, 0xFF
vertex      0,    -44,     18,      0,      0,  0x00, 0x8B, 0x30, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012968: # 0x05012968
vertex    -18,     44,      0,      0,      0,  0xD0, 0x75, 0x00, 0xFF
vertex    -13,     44,     13,      0,      0,  0xDE, 0x75, 0x22, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -33,     33,      0,      0,      0,  0xA7, 0x5A, 0x00, 0xFF
vertex    -24,     33,     24,      0,      0,  0xC1, 0x5A, 0x3F, 0xFF
vertex    -44,     18,      0,      0,      0,  0x8B, 0x30, 0x00, 0xFF
vertex    -31,     18,     31,      0,      0,  0xAE, 0x30, 0x52, 0xFF
vertex    -48,      0,      0,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    -33,      0,     33,      0,      0,  0xA7, 0x00, 0x59, 0xFF
vertex    -44,    -18,      0,      0,      0,  0x8B, 0xD0, 0x00, 0xFF
vertex    -31,    -18,     31,      0,      0,  0xAE, 0xD0, 0x52, 0xFF
vertex    -33,    -33,      0,      0,      0,  0xA7, 0xA6, 0x00, 0xFF
vertex    -24,    -33,     24,      0,      0,  0xC1, 0xA6, 0x3F, 0xFF
vertex    -18,    -44,      0,      0,      0,  0xD0, 0x8B, 0x00, 0xFF
vertex    -13,    -44,     13,      0,      0,  0xDE, 0x8B, 0x22, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012A68: # 0x05012A68
vertex    -13,     44,    -13,      0,      0,  0xDE, 0x75, 0xDE, 0xFF
vertex    -18,     44,      0,      0,      0,  0xD0, 0x75, 0x00, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -24,     33,    -24,      0,      0,  0xC1, 0x5A, 0xC1, 0xFF
vertex    -33,     33,      0,      0,      0,  0xA7, 0x5A, 0x00, 0xFF
vertex    -31,     18,    -31,      0,      0,  0xAE, 0x30, 0xAE, 0xFF
vertex    -44,     18,      0,      0,      0,  0x8B, 0x30, 0x00, 0xFF
vertex    -33,      0,    -33,      0,      0,  0xA7, 0x00, 0xA7, 0xFF
vertex    -48,      0,      0,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    -31,    -18,    -31,      0,      0,  0xAE, 0xD0, 0xAE, 0xFF
vertex    -44,    -18,      0,      0,      0,  0x8B, 0xD0, 0x00, 0xFF
vertex    -24,    -33,    -24,      0,      0,  0xC1, 0xA6, 0xC1, 0xFF
vertex    -33,    -33,      0,      0,      0,  0xA7, 0xA6, 0x00, 0xFF
vertex    -13,    -44,    -13,      0,      0,  0xDE, 0x8B, 0xDE, 0xFF
vertex    -18,    -44,      0,      0,      0,  0xD0, 0x8B, 0x00, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012B68: # 0x05012B68
vertex      0,     44,    -18,      0,      0,  0x00, 0x75, 0xD0, 0xFF
vertex    -13,     44,    -13,      0,      0,  0xDE, 0x75, 0xDE, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,     33,    -33,      0,      0,  0x00, 0x5A, 0xA7, 0xFF
vertex    -24,     33,    -24,      0,      0,  0xC1, 0x5A, 0xC1, 0xFF
vertex      0,     18,    -44,      0,      0,  0x00, 0x30, 0x8B, 0xFF
vertex    -31,     18,    -31,      0,      0,  0xAE, 0x30, 0xAE, 0xFF
vertex      0,      0,    -48,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    -33,      0,    -33,      0,      0,  0xA7, 0x00, 0xA7, 0xFF
vertex      0,    -18,    -44,      0,      0,  0x00, 0xD0, 0x8B, 0xFF
vertex    -31,    -18,    -31,      0,      0,  0xAE, 0xD0, 0xAE, 0xFF
vertex      0,    -33,    -33,      0,      0,  0x00, 0xA6, 0xA7, 0xFF
vertex    -24,    -33,    -24,      0,      0,  0xC1, 0xA6, 0xC1, 0xFF
vertex      0,    -44,    -18,      0,      0,  0x00, 0x8B, 0xD0, 0xFF
vertex    -13,    -44,    -13,      0,      0,  0xDE, 0x8B, 0xDE, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012C68: # 0x05012C68
vertex     13,     44,    -13,      0,      0,  0x22, 0x75, 0xDE, 0xFF
vertex      0,     44,    -18,      0,      0,  0x00, 0x75, 0xD0, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     24,     33,    -24,      0,      0,  0x3F, 0x5A, 0xC1, 0xFF
vertex      0,     33,    -33,      0,      0,  0x00, 0x5A, 0xA7, 0xFF
vertex     31,     18,    -31,      0,      0,  0x52, 0x30, 0xAE, 0xFF
vertex      0,     18,    -44,      0,      0,  0x00, 0x30, 0x8B, 0xFF
vertex     33,      0,    -33,      0,      0,  0x59, 0x00, 0xA7, 0xFF
vertex      0,      0,    -48,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex     31,    -18,    -31,      0,      0,  0x52, 0xD0, 0xAE, 0xFF
vertex      0,    -18,    -44,      0,      0,  0x00, 0xD0, 0x8B, 0xFF
vertex     24,    -33,    -24,      0,      0,  0x3F, 0xA6, 0xC1, 0xFF
vertex      0,    -33,    -33,      0,      0,  0x00, 0xA6, 0xA7, 0xFF
vertex     13,    -44,    -13,      0,      0,  0x22, 0x8B, 0xDE, 0xFF
vertex      0,    -44,    -18,      0,      0,  0x00, 0x8B, 0xD0, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012D68: # 0x05012D68
vertex     18,     44,      0,      0,      0,  0x30, 0x75, 0x00, 0xFF
vertex     13,     44,    -13,      0,      0,  0x22, 0x75, 0xDE, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     33,     33,      0,      0,      0,  0x59, 0x5A, 0x00, 0xFF
vertex     24,     33,    -24,      0,      0,  0x3F, 0x5A, 0xC1, 0xFF
vertex     44,     18,      0,      0,      0,  0x75, 0x30, 0x00, 0xFF
vertex     31,     18,    -31,      0,      0,  0x52, 0x30, 0xAE, 0xFF
vertex     48,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex     33,      0,    -33,      0,      0,  0x59, 0x00, 0xA7, 0xFF
vertex     44,    -18,      0,      0,      0,  0x75, 0xD0, 0x00, 0xFF
vertex     31,    -18,    -31,      0,      0,  0x52, 0xD0, 0xAE, 0xFF
vertex     33,    -33,      0,      0,      0,  0x59, 0xA6, 0x00, 0xFF
vertex     24,    -33,    -24,      0,      0,  0x3F, 0xA6, 0xC1, 0xFF
vertex     18,    -44,      0,      0,      0,  0x30, 0x8B, 0x00, 0xFF
vertex     13,    -44,    -13,      0,      0,  0x22, 0x8B, 0xDE, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012E68: # 0x05012E68
vertex     13,     44,     13,      0,      0,  0x22, 0x75, 0x22, 0xFF
vertex     18,     44,      0,      0,      0,  0x30, 0x75, 0x00, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     24,     33,     24,      0,      0,  0x3F, 0x5A, 0x3F, 0xFF
vertex     33,     33,      0,      0,      0,  0x59, 0x5A, 0x00, 0xFF
vertex     31,     18,     31,      0,      0,  0x52, 0x30, 0x52, 0xFF
vertex     44,     18,      0,      0,      0,  0x75, 0x30, 0x00, 0xFF
vertex     33,      0,     33,      0,      0,  0x59, 0x00, 0x59, 0xFF
vertex     48,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex     31,    -18,     31,      0,      0,  0x52, 0xD0, 0x52, 0xFF
vertex     44,    -18,      0,      0,      0,  0x75, 0xD0, 0x00, 0xFF
vertex     24,    -33,     24,      0,      0,  0x3F, 0xA6, 0x3F, 0xFF
vertex     33,    -33,      0,      0,      0,  0x59, 0xA6, 0x00, 0xFF
vertex     13,    -44,     13,      0,      0,  0x22, 0x8B, 0x22, 0xFF
vertex     18,    -44,      0,      0,      0,  0x30, 0x8B, 0x00, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05012F68: # 0x05012F68
vertex      0,     44,     18,      0,      0,  0x00, 0x75, 0x30, 0xFF
vertex     13,     44,     13,      0,      0,  0x22, 0x75, 0x22, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,     33,     33,      0,      0,  0x00, 0x5A, 0x59, 0xFF
vertex     24,     33,     24,      0,      0,  0x3F, 0x5A, 0x3F, 0xFF
vertex      0,     18,     44,      0,      0,  0x00, 0x30, 0x75, 0xFF
vertex     31,     18,     31,      0,      0,  0x52, 0x30, 0x52, 0xFF
vertex      0,      0,     48,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex     33,      0,     33,      0,      0,  0x59, 0x00, 0x59, 0xFF
vertex      0,    -18,     44,      0,      0,  0x00, 0xD0, 0x75, 0xFF
vertex     31,    -18,     31,      0,      0,  0x52, 0xD0, 0x52, 0xFF
vertex      0,    -33,     33,      0,      0,  0x00, 0xA6, 0x59, 0xFF
vertex     24,    -33,     24,      0,      0,  0x3F, 0xA6, 0x3F, 0xFF
vertex      0,    -44,     18,      0,      0,  0x00, 0x8B, 0x30, 0xFF
vertex     13,    -44,     13,      0,      0,  0x22, 0x8B, 0x22, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013068: # 0x05013068
vertex    223,    -25,      0,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    223,      0,    -25,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    223,     25,      0,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    223,     25,      0,      0,      0,  0x01, 0x7F, 0x00, 0xFF
vertex      0,     18,    -18,      0,      0,  0xFF, 0x59, 0xA7, 0xFF
vertex      0,     18,     18,      0,      0,  0xFF, 0x59, 0x59, 0xFF
vertex    223,      0,    -25,      0,      0,  0x01, 0x00, 0x81, 0xFF
vertex    223,      0,     25,      0,      0,  0x01, 0x00, 0x7F, 0xFF
vertex      0,    -18,     18,      0,      0,  0xFF, 0xA7, 0x59, 0xFF
vertex    223,    -25,      0,      0,      0,  0x01, 0x81, 0x00, 0xFF
vertex      0,    -18,    -18,      0,      0,  0xFF, 0xA7, 0xA7, 0xFF
vertex    223,      0,     25,      0,      0,  0x7F, 0x00, 0x00, 0xFF

heave_ho_seg5_vertex_05013128: # 0x05013128
vertex    -13,     44,     13,      0,      0,  0xDE, 0x75, 0x22, 0x00
vertex      0,     44,     18,      0,      0,  0x00, 0x75, 0x30, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -24,     33,     24,      0,      0,  0xC1, 0x5A, 0x3F, 0xFF
vertex      0,     33,     33,      0,      0,  0x00, 0x5A, 0x59, 0xFF
vertex    -31,     18,     31,      0,      0,  0xAE, 0x30, 0x52, 0xFF
vertex      0,     18,     44,      0,      0,  0x00, 0x30, 0x75, 0xFF
vertex    -33,      0,     33,      0,      0,  0xA7, 0x00, 0x59, 0xFF
vertex      0,      0,     48,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    -31,    -18,     31,      0,      0,  0xAE, 0xD0, 0x52, 0xFF
vertex      0,    -18,     44,      0,      0,  0x00, 0xD0, 0x75, 0xFF
vertex    -24,    -33,     24,      0,      0,  0xC1, 0xA6, 0x3F, 0xFF
vertex      0,    -33,     33,      0,      0,  0x00, 0xA6, 0x59, 0xFF
vertex    -13,    -44,     13,      0,      0,  0xDE, 0x8B, 0x22, 0xFF
vertex      0,    -44,     18,      0,      0,  0x00, 0x8B, 0x30, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013228: # 0x05013228
vertex    -18,     44,      0,      0,      0,  0xD0, 0x75, 0x00, 0xFF
vertex    -13,     44,     13,      0,      0,  0xDE, 0x75, 0x22, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -33,     33,      0,      0,      0,  0xA7, 0x5A, 0x00, 0xFF
vertex    -24,     33,     24,      0,      0,  0xC1, 0x5A, 0x3F, 0xFF
vertex    -44,     18,      0,      0,      0,  0x8B, 0x30, 0x00, 0xFF
vertex    -31,     18,     31,      0,      0,  0xAE, 0x30, 0x52, 0xFF
vertex    -48,      0,      0,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    -33,      0,     33,      0,      0,  0xA7, 0x00, 0x59, 0xFF
vertex    -44,    -18,      0,      0,      0,  0x8B, 0xD0, 0x00, 0xFF
vertex    -31,    -18,     31,      0,      0,  0xAE, 0xD0, 0x52, 0xFF
vertex    -33,    -33,      0,      0,      0,  0xA7, 0xA6, 0x00, 0xFF
vertex    -24,    -33,     24,      0,      0,  0xC1, 0xA6, 0x3F, 0xFF
vertex    -18,    -44,      0,      0,      0,  0xD0, 0x8B, 0x00, 0xFF
vertex    -13,    -44,     13,      0,      0,  0xDE, 0x8B, 0x22, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013328: # 0x05013328
vertex    -13,     44,    -13,      0,      0,  0xDE, 0x75, 0xDE, 0xFF
vertex    -18,     44,      0,      0,      0,  0xD0, 0x75, 0x00, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -24,     33,    -24,      0,      0,  0xC1, 0x5A, 0xC1, 0xFF
vertex    -33,     33,      0,      0,      0,  0xA7, 0x5A, 0x00, 0xFF
vertex    -31,     18,    -31,      0,      0,  0xAE, 0x30, 0xAE, 0xFF
vertex    -44,     18,      0,      0,      0,  0x8B, 0x30, 0x00, 0xFF
vertex    -33,      0,    -33,      0,      0,  0xA7, 0x00, 0xA7, 0xFF
vertex    -48,      0,      0,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    -31,    -18,    -31,      0,      0,  0xAE, 0xD0, 0xAE, 0xFF
vertex    -44,    -18,      0,      0,      0,  0x8B, 0xD0, 0x00, 0xFF
vertex    -24,    -33,    -24,      0,      0,  0xC1, 0xA6, 0xC1, 0xFF
vertex    -33,    -33,      0,      0,      0,  0xA7, 0xA6, 0x00, 0xFF
vertex    -13,    -44,    -13,      0,      0,  0xDE, 0x8B, 0xDE, 0xFF
vertex    -18,    -44,      0,      0,      0,  0xD0, 0x8B, 0x00, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013428: # 0x05013428
vertex      0,     44,    -18,      0,      0,  0x00, 0x75, 0xD0, 0xFF
vertex    -13,     44,    -13,      0,      0,  0xDE, 0x75, 0xDE, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,     33,    -33,      0,      0,  0x00, 0x5A, 0xA7, 0xFF
vertex    -24,     33,    -24,      0,      0,  0xC1, 0x5A, 0xC1, 0xFF
vertex      0,     18,    -44,      0,      0,  0x00, 0x30, 0x8B, 0xFF
vertex    -31,     18,    -31,      0,      0,  0xAE, 0x30, 0xAE, 0xFF
vertex      0,      0,    -48,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    -33,      0,    -33,      0,      0,  0xA7, 0x00, 0xA7, 0xFF
vertex      0,    -18,    -44,      0,      0,  0x00, 0xD0, 0x8B, 0xFF
vertex    -31,    -18,    -31,      0,      0,  0xAE, 0xD0, 0xAE, 0xFF
vertex      0,    -33,    -33,      0,      0,  0x00, 0xA6, 0xA7, 0xFF
vertex    -24,    -33,    -24,      0,      0,  0xC1, 0xA6, 0xC1, 0xFF
vertex      0,    -44,    -18,      0,      0,  0x00, 0x8B, 0xD0, 0xFF
vertex    -13,    -44,    -13,      0,      0,  0xDE, 0x8B, 0xDE, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013528: # 0x05013528
vertex     13,     44,    -13,      0,      0,  0x22, 0x75, 0xDE, 0xFF
vertex      0,     44,    -18,      0,      0,  0x00, 0x75, 0xD0, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     24,     33,    -24,      0,      0,  0x3F, 0x5A, 0xC1, 0xFF
vertex      0,     33,    -33,      0,      0,  0x00, 0x5A, 0xA7, 0xFF
vertex     31,     18,    -31,      0,      0,  0x52, 0x30, 0xAE, 0xFF
vertex      0,     18,    -44,      0,      0,  0x00, 0x30, 0x8B, 0xFF
vertex     33,      0,    -33,      0,      0,  0x59, 0x00, 0xA7, 0xFF
vertex      0,      0,    -48,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex     31,    -18,    -31,      0,      0,  0x52, 0xD0, 0xAE, 0xFF
vertex      0,    -18,    -44,      0,      0,  0x00, 0xD0, 0x8B, 0xFF
vertex     24,    -33,    -24,      0,      0,  0x3F, 0xA6, 0xC1, 0xFF
vertex      0,    -33,    -33,      0,      0,  0x00, 0xA6, 0xA7, 0xFF
vertex     13,    -44,    -13,      0,      0,  0x22, 0x8B, 0xDE, 0xFF
vertex      0,    -44,    -18,      0,      0,  0x00, 0x8B, 0xD0, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013628: # 0x05013628
vertex     18,     44,      0,      0,      0,  0x30, 0x75, 0x00, 0xFF
vertex     13,     44,    -13,      0,      0,  0x22, 0x75, 0xDE, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     33,     33,      0,      0,      0,  0x59, 0x5A, 0x00, 0xFF
vertex     24,     33,    -24,      0,      0,  0x3F, 0x5A, 0xC1, 0xFF
vertex     44,     18,      0,      0,      0,  0x75, 0x30, 0x00, 0xFF
vertex     31,     18,    -31,      0,      0,  0x52, 0x30, 0xAE, 0xFF
vertex     48,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex     33,      0,    -33,      0,      0,  0x59, 0x00, 0xA7, 0xFF
vertex     44,    -18,      0,      0,      0,  0x75, 0xD0, 0x00, 0xFF
vertex     31,    -18,    -31,      0,      0,  0x52, 0xD0, 0xAE, 0xFF
vertex     33,    -33,      0,      0,      0,  0x59, 0xA6, 0x00, 0xFF
vertex     24,    -33,    -24,      0,      0,  0x3F, 0xA6, 0xC1, 0xFF
vertex     18,    -44,      0,      0,      0,  0x30, 0x8B, 0x00, 0xFF
vertex     13,    -44,    -13,      0,      0,  0x22, 0x8B, 0xDE, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013728: # 0x05013728
vertex     13,     44,     13,      0,      0,  0x22, 0x75, 0x22, 0xFF
vertex     18,     44,      0,      0,      0,  0x30, 0x75, 0x00, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     24,     33,     24,      0,      0,  0x3F, 0x5A, 0x3F, 0xFF
vertex     33,     33,      0,      0,      0,  0x59, 0x5A, 0x00, 0xFF
vertex     31,     18,     31,      0,      0,  0x52, 0x30, 0x52, 0xFF
vertex     44,     18,      0,      0,      0,  0x75, 0x30, 0x00, 0xFF
vertex     33,      0,     33,      0,      0,  0x59, 0x00, 0x59, 0xFF
vertex     48,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex     31,    -18,     31,      0,      0,  0x52, 0xD0, 0x52, 0xFF
vertex     44,    -18,      0,      0,      0,  0x75, 0xD0, 0x00, 0xFF
vertex     24,    -33,     24,      0,      0,  0x3F, 0xA6, 0x3F, 0xFF
vertex     33,    -33,      0,      0,      0,  0x59, 0xA6, 0x00, 0xFF
vertex     13,    -44,     13,      0,      0,  0x22, 0x8B, 0x22, 0xFF
vertex     18,    -44,      0,      0,      0,  0x30, 0x8B, 0x00, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013828: # 0x05013828
vertex      0,     44,     18,      0,      0,  0x00, 0x75, 0x30, 0xFF
vertex     13,     44,     13,      0,      0,  0x22, 0x75, 0x22, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,     33,     33,      0,      0,  0x00, 0x5A, 0x59, 0xFF
vertex     24,     33,     24,      0,      0,  0x3F, 0x5A, 0x3F, 0xFF
vertex      0,     18,     44,      0,      0,  0x00, 0x30, 0x75, 0xFF
vertex     31,     18,     31,      0,      0,  0x52, 0x30, 0x52, 0xFF
vertex      0,      0,     48,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex     33,      0,     33,      0,      0,  0x59, 0x00, 0x59, 0xFF
vertex      0,    -18,     44,      0,      0,  0x00, 0xD0, 0x75, 0xFF
vertex     31,    -18,     31,      0,      0,  0x52, 0xD0, 0x52, 0xFF
vertex      0,    -33,     33,      0,      0,  0x00, 0xA6, 0x59, 0xFF
vertex     24,    -33,     24,      0,      0,  0x3F, 0xA6, 0x3F, 0xFF
vertex      0,    -44,     18,      0,      0,  0x00, 0x8B, 0x30, 0xFF
vertex     13,    -44,     13,      0,      0,  0x22, 0x8B, 0x22, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013928: # 0x05013928
vertex    -13,     44,     13,      0,      0,  0xDE, 0x75, 0x22, 0x00
vertex      0,     44,     18,      0,      0,  0x00, 0x75, 0x30, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -24,     33,     24,      0,      0,  0xC1, 0x5A, 0x3F, 0xFF
vertex      0,     33,     33,      0,      0,  0x00, 0x5A, 0x59, 0xFF
vertex    -31,     18,     31,      0,      0,  0xAE, 0x30, 0x52, 0xFF
vertex      0,     18,     44,      0,      0,  0x00, 0x30, 0x75, 0xFF
vertex    -33,      0,     33,      0,      0,  0xA7, 0x00, 0x59, 0xFF
vertex      0,      0,     48,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    -31,    -18,     31,      0,      0,  0xAE, 0xD0, 0x52, 0xFF
vertex      0,    -18,     44,      0,      0,  0x00, 0xD0, 0x75, 0xFF
vertex    -24,    -33,     24,      0,      0,  0xC1, 0xA6, 0x3F, 0xFF
vertex      0,    -33,     33,      0,      0,  0x00, 0xA6, 0x59, 0xFF
vertex    -13,    -44,     13,      0,      0,  0xDE, 0x8B, 0x22, 0xFF
vertex      0,    -44,     18,      0,      0,  0x00, 0x8B, 0x30, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013A28: # 0x05013A28
vertex    -18,     44,      0,      0,      0,  0xD0, 0x75, 0x00, 0xFF
vertex    -13,     44,     13,      0,      0,  0xDE, 0x75, 0x22, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -33,     33,      0,      0,      0,  0xA7, 0x5A, 0x00, 0xFF
vertex    -24,     33,     24,      0,      0,  0xC1, 0x5A, 0x3F, 0xFF
vertex    -44,     18,      0,      0,      0,  0x8B, 0x30, 0x00, 0xFF
vertex    -31,     18,     31,      0,      0,  0xAE, 0x30, 0x52, 0xFF
vertex    -48,      0,      0,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    -33,      0,     33,      0,      0,  0xA7, 0x00, 0x59, 0xFF
vertex    -44,    -18,      0,      0,      0,  0x8B, 0xD0, 0x00, 0xFF
vertex    -31,    -18,     31,      0,      0,  0xAE, 0xD0, 0x52, 0xFF
vertex    -33,    -33,      0,      0,      0,  0xA7, 0xA6, 0x00, 0xFF
vertex    -24,    -33,     24,      0,      0,  0xC1, 0xA6, 0x3F, 0xFF
vertex    -18,    -44,      0,      0,      0,  0xD0, 0x8B, 0x00, 0xFF
vertex    -13,    -44,     13,      0,      0,  0xDE, 0x8B, 0x22, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013B28: # 0x05013B28
vertex    -13,     44,    -13,      0,      0,  0xDE, 0x75, 0xDE, 0xFF
vertex    -18,     44,      0,      0,      0,  0xD0, 0x75, 0x00, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    -24,     33,    -24,      0,      0,  0xC1, 0x5A, 0xC1, 0xFF
vertex    -33,     33,      0,      0,      0,  0xA7, 0x5A, 0x00, 0xFF
vertex    -31,     18,    -31,      0,      0,  0xAE, 0x30, 0xAE, 0xFF
vertex    -44,     18,      0,      0,      0,  0x8B, 0x30, 0x00, 0xFF
vertex    -33,      0,    -33,      0,      0,  0xA7, 0x00, 0xA7, 0xFF
vertex    -48,      0,      0,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    -31,    -18,    -31,      0,      0,  0xAE, 0xD0, 0xAE, 0xFF
vertex    -44,    -18,      0,      0,      0,  0x8B, 0xD0, 0x00, 0xFF
vertex    -24,    -33,    -24,      0,      0,  0xC1, 0xA6, 0xC1, 0xFF
vertex    -33,    -33,      0,      0,      0,  0xA7, 0xA6, 0x00, 0xFF
vertex    -13,    -44,    -13,      0,      0,  0xDE, 0x8B, 0xDE, 0xFF
vertex    -18,    -44,      0,      0,      0,  0xD0, 0x8B, 0x00, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013C28: # 0x05013C28
vertex      0,     44,    -18,      0,      0,  0x00, 0x75, 0xD0, 0xFF
vertex    -13,     44,    -13,      0,      0,  0xDE, 0x75, 0xDE, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,     33,    -33,      0,      0,  0x00, 0x5A, 0xA7, 0xFF
vertex    -24,     33,    -24,      0,      0,  0xC1, 0x5A, 0xC1, 0xFF
vertex      0,     18,    -44,      0,      0,  0x00, 0x30, 0x8B, 0xFF
vertex    -31,     18,    -31,      0,      0,  0xAE, 0x30, 0xAE, 0xFF
vertex      0,      0,    -48,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    -33,      0,    -33,      0,      0,  0xA7, 0x00, 0xA7, 0xFF
vertex      0,    -18,    -44,      0,      0,  0x00, 0xD0, 0x8B, 0xFF
vertex    -31,    -18,    -31,      0,      0,  0xAE, 0xD0, 0xAE, 0xFF
vertex      0,    -33,    -33,      0,      0,  0x00, 0xA6, 0xA7, 0xFF
vertex    -24,    -33,    -24,      0,      0,  0xC1, 0xA6, 0xC1, 0xFF
vertex      0,    -44,    -18,      0,      0,  0x00, 0x8B, 0xD0, 0xFF
vertex    -13,    -44,    -13,      0,      0,  0xDE, 0x8B, 0xDE, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013D28: # 0x05013D28
vertex     13,     44,    -13,      0,      0,  0x22, 0x75, 0xDE, 0xFF
vertex      0,     44,    -18,      0,      0,  0x00, 0x75, 0xD0, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     24,     33,    -24,      0,      0,  0x3F, 0x5A, 0xC1, 0xFF
vertex      0,     33,    -33,      0,      0,  0x00, 0x5A, 0xA7, 0xFF
vertex     31,     18,    -31,      0,      0,  0x52, 0x30, 0xAE, 0xFF
vertex      0,     18,    -44,      0,      0,  0x00, 0x30, 0x8B, 0xFF
vertex     33,      0,    -33,      0,      0,  0x59, 0x00, 0xA7, 0xFF
vertex      0,      0,    -48,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex     31,    -18,    -31,      0,      0,  0x52, 0xD0, 0xAE, 0xFF
vertex      0,    -18,    -44,      0,      0,  0x00, 0xD0, 0x8B, 0xFF
vertex     24,    -33,    -24,      0,      0,  0x3F, 0xA6, 0xC1, 0xFF
vertex      0,    -33,    -33,      0,      0,  0x00, 0xA6, 0xA7, 0xFF
vertex     13,    -44,    -13,      0,      0,  0x22, 0x8B, 0xDE, 0xFF
vertex      0,    -44,    -18,      0,      0,  0x00, 0x8B, 0xD0, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013E28: # 0x05013E28
vertex     18,     44,      0,      0,      0,  0x30, 0x75, 0x00, 0xFF
vertex     13,     44,    -13,      0,      0,  0x22, 0x75, 0xDE, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     33,     33,      0,      0,      0,  0x59, 0x5A, 0x00, 0xFF
vertex     24,     33,    -24,      0,      0,  0x3F, 0x5A, 0xC1, 0xFF
vertex     44,     18,      0,      0,      0,  0x75, 0x30, 0x00, 0xFF
vertex     31,     18,    -31,      0,      0,  0x52, 0x30, 0xAE, 0xFF
vertex     48,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex     33,      0,    -33,      0,      0,  0x59, 0x00, 0xA7, 0xFF
vertex     44,    -18,      0,      0,      0,  0x75, 0xD0, 0x00, 0xFF
vertex     31,    -18,    -31,      0,      0,  0x52, 0xD0, 0xAE, 0xFF
vertex     33,    -33,      0,      0,      0,  0x59, 0xA6, 0x00, 0xFF
vertex     24,    -33,    -24,      0,      0,  0x3F, 0xA6, 0xC1, 0xFF
vertex     18,    -44,      0,      0,      0,  0x30, 0x8B, 0x00, 0xFF
vertex     13,    -44,    -13,      0,      0,  0x22, 0x8B, 0xDE, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05013F28: # 0x05013F28
vertex     13,     44,     13,      0,      0,  0x22, 0x75, 0x22, 0xFF
vertex     18,     44,      0,      0,      0,  0x30, 0x75, 0x00, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex     24,     33,     24,      0,      0,  0x3F, 0x5A, 0x3F, 0xFF
vertex     33,     33,      0,      0,      0,  0x59, 0x5A, 0x00, 0xFF
vertex     31,     18,     31,      0,      0,  0x52, 0x30, 0x52, 0xFF
vertex     44,     18,      0,      0,      0,  0x75, 0x30, 0x00, 0xFF
vertex     33,      0,     33,      0,      0,  0x59, 0x00, 0x59, 0xFF
vertex     48,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex     31,    -18,     31,      0,      0,  0x52, 0xD0, 0x52, 0xFF
vertex     44,    -18,      0,      0,      0,  0x75, 0xD0, 0x00, 0xFF
vertex     24,    -33,     24,      0,      0,  0x3F, 0xA6, 0x3F, 0xFF
vertex     33,    -33,      0,      0,      0,  0x59, 0xA6, 0x00, 0xFF
vertex     13,    -44,     13,      0,      0,  0x22, 0x8B, 0x22, 0xFF
vertex     18,    -44,      0,      0,      0,  0x30, 0x8B, 0x00, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05014028: # 0x05014028
vertex      0,     44,     18,      0,      0,  0x00, 0x75, 0x30, 0xFF
vertex     13,     44,     13,      0,      0,  0x22, 0x75, 0x22, 0x00
vertex      0,     48,      0,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex      0,     33,     33,      0,      0,  0x00, 0x5A, 0x59, 0xFF
vertex     24,     33,     24,      0,      0,  0x3F, 0x5A, 0x3F, 0xFF
vertex      0,     18,     44,      0,      0,  0x00, 0x30, 0x75, 0xFF
vertex     31,     18,     31,      0,      0,  0x52, 0x30, 0x52, 0xFF
vertex      0,      0,     48,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex     33,      0,     33,      0,      0,  0x59, 0x00, 0x59, 0xFF
vertex      0,    -18,     44,      0,      0,  0x00, 0xD0, 0x75, 0xFF
vertex     31,    -18,     31,      0,      0,  0x52, 0xD0, 0x52, 0xFF
vertex      0,    -33,     33,      0,      0,  0x00, 0xA6, 0x59, 0xFF
vertex     24,    -33,     24,      0,      0,  0x3F, 0xA6, 0x3F, 0xFF
vertex      0,    -44,     18,      0,      0,  0x00, 0x8B, 0x30, 0xFF
vertex     13,    -44,     13,      0,      0,  0x22, 0x8B, 0x22, 0xFF
vertex      0,    -48,      0,      0,      0,  0x00, 0x81, 0x00, 0xFF

heave_ho_seg5_vertex_05014128: # 0x05014128
vertex    204,    -17,    220,      0,      0,  0x3E, 0x6E, 0x00, 0x00
vertex    204,    -29,   -219,      0,      0,  0x7F, 0x00, 0xFD, 0x00
vertex    180,    -17,   -219,      0,      0,  0xC2, 0x6E, 0x00, 0x00
vertex    204,    -41,    220,      0,      0,  0x3E, 0x92, 0x00, 0xFF
vertex    180,    -41,   -219,      0,      0,  0xC2, 0x92, 0x00, 0xFF
vertex    180,    -29,    220,      0,      0,  0x81, 0x00, 0x03, 0xFF

glabel heave_ho_seg5_dl_05014188 # 0x05014188 - 0x05014560
gsSPLight heave_ho_seg5_light_0500E970, 1
gsSPLight heave_ho_seg5_light_0500E968, 2
gsSPVertex heave_ho_seg5_vertex_05012868, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012968, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012A68, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012B68, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012C68, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012D68, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012E68, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05012F68, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05014560 # 0x05014560 - 0x050145D0
gsSPLight heave_ho_seg5_light_0500E988, 1
gsSPLight heave_ho_seg5_light_0500E980, 2
gsSPVertex heave_ho_seg5_vertex_05013068, 12, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  4,  3,  6, 0x0
gsSP1Triangle  5,  7,  3, 0x0
gsSP1Triangle  8,  9,  7, 0x0
gsSP1Triangle 10,  6,  9, 0x0
gsSP1Triangle  2, 11,  0, 0x0
gsSP1Triangle  7,  5,  8, 0x0
gsSP1Triangle  9,  8, 10, 0x0
gsSP1Triangle  6, 10,  4, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050145D0 # 0x050145D0 - 0x050149A8
gsSPLight heave_ho_seg5_light_0500E970, 1
gsSPLight heave_ho_seg5_light_0500E968, 2
gsSPVertex heave_ho_seg5_vertex_05013128, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013228, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013328, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013428, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013528, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013628, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013728, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013828, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_050149A8 # 0x050149A8 - 0x05014D80
gsSPLight heave_ho_seg5_light_0500E970, 1
gsSPLight heave_ho_seg5_light_0500E968, 2
gsSPVertex heave_ho_seg5_vertex_05013928, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013A28, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013B28, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013C28, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013D28, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013E28, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05013F28, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPVertex heave_ho_seg5_vertex_05014028, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  0,  3, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  5,  7, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  8,  7,  9, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 12, 11, 13, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 14, 13, 15, 0x0
gsSPEndDisplayList

glabel heave_ho_seg5_dl_05014D80 # 0x05014D80 - 0x05014DD0
gsSPLight heave_ho_seg5_light_0500E988, 1
gsSPLight heave_ho_seg5_light_0500E980, 2
gsSPVertex heave_ho_seg5_vertex_05014128, 6, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3,  5, 0x0
gsSP1Triangle  0,  2,  5, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  2,  4,  5, 0x0
gsSPEndDisplayList

heave_ho_seg5_animvalue_05014DD0: # 0x05014DD0
.hword 0x0000, 0x0030, 0xFF92, 0xC001, 0x3FFF, 0xC001, 0x0000, 0xF5C3
.hword 0xEB86, 0xE148, 0xD70B, 0xCCCE, 0xC290, 0xB853, 0xAE16, 0xA3D8
.hword 0x999B, 0x8F5E, 0x8520, 0x7AE0, 0x70A2, 0x6665, 0x5C28, 0x51EA
.hword 0x47AD, 0x3D70, 0x3332, 0x28F5, 0x1EB8, 0x147A, 0x0A3D, 0x2170
.hword 0x8001, 0x8001, 0x0000, 0xF5C3, 0xEB86, 0xE148, 0xD70B, 0xCCCE
.hword 0xC290, 0xB853, 0xAE16, 0xA3D8, 0x999B, 0x8F5E, 0x8520, 0x7AE0
.hword 0x70A2, 0x6665, 0x5C28, 0x51EA, 0x47AD, 0x3D70, 0x3332, 0x28F5
.hword 0x1EB8, 0x147A, 0x0A3D, 0x2170, 0x8001, 0x8001, 0x8001, 0x8001
.hword 0x3FFF, 0xC001, 0x3FFF, 0x8001, 0x8001, 0x8001

heave_ho_seg5_animindex_05014E5C: # 0x05014E5C
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003
.hword 0x0001, 0x0004, 0x0001, 0x0005, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0045, 0x0001, 0x0043, 0x0001, 0x0044, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0019, 0x0022, 0x0001, 0x0000
.hword 0x0001, 0x003B, 0x0019, 0x0006, 0x0001, 0x0000, 0x0001, 0x001F
.hword 0x0001, 0x0040, 0x0001, 0x0041, 0x0001, 0x0042, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x003E, 0x0001, 0x003F, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x003D, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x003C, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0020
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0021

heave_ho_seg5_anim_05014F28: # 0x05014F28
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x18
.hword 0x10
.word heave_ho_seg5_animvalue_05014DD0
.word heave_ho_seg5_animindex_05014E5C
.word 0

heave_ho_seg5_animvalue_05014F40: # 0x05014F40
.hword 0x0000, 0x0030, 0xFF92, 0xC001, 0x3FFF, 0xC001, 0x0000, 0x06BC
.hword 0x0D79, 0x1435, 0x1AF2, 0x21AE, 0x286B, 0x2F28, 0x35E4, 0x3CA1
.hword 0x435D, 0x4A1A, 0x50D6, 0x5793, 0x5E50, 0x650C, 0x6BC9, 0x7285
.hword 0x7942, 0x8001, 0x86BE, 0x8D7B, 0x9437, 0x9AF4, 0xA1B0, 0xA86D
.hword 0xAF2A, 0xB5E6, 0xBCA3, 0xC35F, 0xCA1C, 0xD0D8, 0xD795, 0xDE52
.hword 0xE50E, 0xEBCB, 0xF287, 0xF944, 0x2170, 0x8001, 0x8001, 0x0000
.hword 0x06BC, 0x0D79, 0x1435, 0x1AF2, 0x21AE, 0x286B, 0x2F28, 0x35E4
.hword 0x3CA1, 0x435D, 0x4A1A, 0x50D6, 0x5793, 0x5E50, 0x650C, 0x6BC9
.hword 0x7285, 0x7942, 0x8001, 0x86BE, 0x8D7B, 0x9437, 0x9AF4, 0xA1B0
.hword 0xA86D, 0xAF2A, 0xB5E6, 0xBCA3, 0xC35F, 0xCA1C, 0xD0D8, 0xD795
.hword 0xDE52, 0xE50E, 0xEBCB, 0xF287, 0xF944, 0x2170, 0x8001, 0x8001
.hword 0x0000, 0x0069, 0x0152, 0x023B, 0x02A4, 0x025E, 0x01B6, 0x00EE
.hword 0x0046, 0x0000, 0x0046, 0x00EE, 0x01B6, 0x025E, 0x02A4, 0x025F
.hword 0x01B9, 0x00F3, 0x004A, 0x0000, 0x0066, 0x014F, 0x0239, 0x02A4
.hword 0x025E, 0x01B6, 0x00EE, 0x0046, 0x0000, 0x0046, 0x00EE, 0x01B6
.hword 0x025E, 0x02A4, 0x025F, 0x01B9, 0x00F3, 0x004A, 0x8001, 0x8001
.hword 0x3FFF, 0xC001, 0x3FFF, 0x8001, 0x8001, 0x8001

heave_ho_seg5_animindex_0501504C: # 0x0501504C
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003
.hword 0x0001, 0x0004, 0x0001, 0x0005, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0085, 0x0001, 0x0083, 0x0001, 0x0084, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0026, 0x0058, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0026, 0x002F, 0x0001, 0x0000
.hword 0x0001, 0x0055, 0x0026, 0x0006, 0x0001, 0x0000, 0x0001, 0x002C
.hword 0x0001, 0x0080, 0x0001, 0x0081, 0x0001, 0x0082, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x007E, 0x0001, 0x007F, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0057, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0056, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x002D
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x002E

heave_ho_seg5_anim_05015118: # 0x05015118
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x26
.hword 0x10
.word heave_ho_seg5_animvalue_05014F40
.word heave_ho_seg5_animindex_0501504C
.word 0

heave_ho_seg5_animvalue_05015130: # 0x05015130
.hword 0x0000, 0x0030, 0xFF92, 0xC001, 0x3FFF, 0xC001, 0x672F, 0xB545
.hword 0xEEB0, 0x17E3, 0x3554, 0x4D42, 0x6308, 0x76C7, 0x889F, 0x98A9
.hword 0xA706, 0xB3D6, 0xBF37, 0xC948, 0xD227, 0xD9F3, 0xE0CA, 0xE6CC
.hword 0xEC16, 0xF0C8, 0xF501, 0xF8DE, 0xFC7E, 0x2170, 0x59B4, 0x30F4
.hword 0x2BC7, 0x2990, 0x29C2, 0x2BD0, 0x2F2C, 0x3348, 0x3798, 0x3B8C
.hword 0x3FA4, 0x449E, 0x4A48, 0x5073, 0x56ED, 0x5D87, 0x640F, 0x6A55
.hword 0x702A, 0x755B, 0x79BA, 0x7D15, 0x7F3C, 0x8001, 0x672F, 0xB545
.hword 0xEEB0, 0x17E3, 0x3554, 0x4D42, 0x6308, 0x76C7, 0x889F, 0x98A9
.hword 0xA706, 0xB3D6, 0xBF37, 0xC948, 0xD227, 0xD9F3, 0xE0CA, 0xE6CC
.hword 0xEC16, 0xF0C8, 0xF501, 0xF8DE, 0xFC7E, 0x2170, 0x59B4, 0x30F4
.hword 0x2BC7, 0x2990, 0x29C2, 0x2BD0, 0x2F2C, 0x3348, 0x3798, 0x3B8C
.hword 0x3FA4, 0x449E, 0x4A48, 0x5073, 0x56ED, 0x5D87, 0x640F, 0x6A55
.hword 0x702A, 0x755B, 0x79BA, 0x7D15, 0x7F3C, 0x59B4, 0x30F4, 0x2BC7
.hword 0x2990, 0x29C2, 0x2BD0, 0x2F2C, 0x3348, 0x3798, 0x3B8C, 0x3FA4
.hword 0x449E, 0x4A48, 0x5073, 0x56ED, 0x5D87, 0x640F, 0x6A55, 0x702A
.hword 0x755B, 0x79BA, 0x7D15, 0x7F3C, 0xFEB0, 0xFD12, 0xFBB2, 0xFB1D
.hword 0xFB31, 0xFB6B, 0xFBC3, 0xFC33, 0xFCB4, 0xFD3F, 0xFDCE, 0xFE59
.hword 0xFEDA, 0xFF4B, 0xFFA3, 0xFFDD, 0xFFF2, 0xFFF2, 0xFFF2, 0xFFF2
.hword 0xFFF2, 0xFFF2, 0xFFF2, 0x8001, 0x8001, 0x3FFF, 0xC001, 0x3FFF
.hword 0x8001, 0x8001, 0x8001, 0x0000

heave_ho_seg5_animindex_05015268: # 0x05015268
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003
.hword 0x0001, 0x0004, 0x0001, 0x0005, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x009A, 0x0001, 0x0098, 0x0001, 0x0099, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0017, 0x007C, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0017, 0x0036, 0x0001, 0x0000
.hword 0x0001, 0x004D, 0x0017, 0x0006, 0x0001, 0x0000, 0x0001, 0x001D
.hword 0x0001, 0x0095, 0x0001, 0x0096, 0x0001, 0x0097, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0093, 0x0001, 0x0094, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0017, 0x0065, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0017, 0x004E, 0x0001, 0x0000, 0x0001, 0x0000, 0x0017, 0x001E
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0035

heave_ho_seg5_anim_05015334: # 0x05015334
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x17
.hword 0x10
.word heave_ho_seg5_animvalue_05015130
.word heave_ho_seg5_animindex_05015268
.word 0

glabel heave_ho_seg5_anims_0501534C # 0x0501534C
.word heave_ho_seg5_anim_05015118
.word heave_ho_seg5_anim_05015334
.word heave_ho_seg5_anim_05014F28

binid
