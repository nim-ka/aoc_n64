# White Particle

white_particle_vertex: # 0x0302C660
vertex    -15,    -15,      0,      0,    480,  0xFF, 0xFF, 0xFF, 0xFF
vertex     15,    -15,      0,    480,    480,  0xFF, 0xFF, 0xFF, 0xFF
vertex     15,     15,      0,    480,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -15,     15,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

white_particle_texture: # 0x0302C6A0
.incbin "actors/white_particle/snow_particle.rgba16"

glabel white_particle_dl # 0x0302C8A0 - 0x0302C938
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsDPLoadTextureBlock white_particle_texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON
gsSPVertex white_particle_vertex, 4, 0
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsSPTexture 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF
gsDPPipeSync
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList
