# Chain Ball

.balign 8

chain_ball_seg6_vertex_06020AA0: # 0x06020AA0
vertex    -26,    -26,      0,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     26,    -26,      0,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     26,     26,      0,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -26,     26,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

.dword 0 # align? binid?

chain_ball_seg6_texture_06020AE8: # 0x06020AE8
.incbin "actors/chain_ball/chain_ball.rgba16"

glabel chain_ball_seg6_dl_060212E8 # 0x060212E8 - 0x06021380
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsDPLoadTextureBlock chain_ball_seg6_texture_06020AE8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON
gsSPVertex chain_ball_seg6_vertex_06020AA0, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF
gsDPPipeSync
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList
