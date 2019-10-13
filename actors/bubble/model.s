# Bubble

bubble_seg4_vertex_0401CD20: # 0x0401CD20
vertex    -16,      0,      0,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     16,      0,      0,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     16,     32,      0,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -16,     32,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

bubble_seg4_texture_0401CD60: # 0x0401CD60
.incbin "actors/bubble/bubble.rgba16"

bubble_seg4_texture_0401D560: # 0x0401D560
.incbin "actors/bubble/mr_i_bubble.rgba16"

glabel bubble_seg4_dl_0401DD60 # 0x0401DD60 - 0x0401DDE0
gsDPPipeSync
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON
gsDPLoadTextureBlock bubble_seg4_texture_0401CD60, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD
gsSPVertex bubble_seg4_vertex_0401CD20, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

glabel bubble_seg4_dl_0401DDE0 # 0x0401DDE0 - 0x0401DE60
gsDPPipeSync
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON
gsDPLoadTextureBlock bubble_seg4_texture_0401D560, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD
gsSPVertex bubble_seg4_vertex_0401CD20, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList
