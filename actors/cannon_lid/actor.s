# Cannon Lid

cannon_lid_seg8_light_08004040: # 0x08004040
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

cannon_lid_seg8_light_08004048: # 0x08004048
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

cannon_lid_seg8_texture_08004058: # 0x08004058
.incbin "actors/cannon_lid/0.rgba16"

cannon_lid_seg8_vertex_08004858: # 0x08004858
vertex    102,      0,   -101,    990,      0,  0x00, 0x7F, 0x00, 0xFF
vertex   -101,      0,   -101,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex   -101,      0,    102,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex    102,      0,    102,    990,    990,  0x00, 0x7F, 0x00, 0xFF

glabel cannon_lid_seg8_dl_08004898 # 0x08004898 - 0x080048E0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, cannon_lid_seg8_texture_08004058
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight cannon_lid_seg8_light_08004048, 1
gsSPLight cannon_lid_seg8_light_08004040, 2
gsSPVertex cannon_lid_seg8_vertex_08004858, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel cannon_lid_seg8_dl_080048E0 # 0x080048E0 - 0x08004950
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList cannon_lid_seg8_dl_08004898
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList

glabel cannon_lid_seg8_collision_08004950 # 0x08004950 - 0x08004980
# collision vertices
.hword 0x0040, 0x0004
.hword   112,     0,  -111
.hword  -111,     0,  -111
.hword  -111,     0,   112
.hword   112,     0,   112
# collision 0x00 normal
.hword 0x0000,    2
.hword    0,    1,    2
.hword    0,    2,    3
.hword 0x0041
.hword 0x0042

binid