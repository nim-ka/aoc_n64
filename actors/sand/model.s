# Sand

sand_seg3_vertex_0302BA90: # 0x0302BA90
vertex     -8,     -8,      0,      0,    480,  0xFF, 0xFF, 0xFF, 0xFF
vertex      8,     -8,      0,    480,    480,  0xFF, 0xFF, 0xFF, 0xFF
vertex      8,      8,      0,    480,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex     -8,      8,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

sand_seg3_texture_0302BAD0: # 0x0302BAD0
.incbin "actors/sand/sand_particle.rgba16"

glabel sand_seg3_dl_0302BCD0 # 0x0302BCD0 - 0x0302BD60
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsDPLoadTextureBlock sand_seg3_texture_0302BAD0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON
gsSPVertex sand_seg3_vertex_0302BA90, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList
