# White Particle Small

white_particle_small_vertex: # 0x04032700
vertex     -4,      0,      0,      0,    960,  0xFF, 0xFF, 0xFF, 0xFF
vertex      4,      0,      0,    960,    960,  0xFF, 0xFF, 0xFF, 0xFF
vertex      4,      8,      0,    960,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex     -4,      8,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

white_particle_small_unused_vertex: # 0x04032740
vertex     -4,      0,      0,      0,    960,  0xFF, 0x00, 0x00, 0xFF
vertex      4,      0,      0,    960,    960,  0xFF, 0x00, 0x00, 0xFF
vertex      4,      8,      0,    960,      0,  0xFF, 0x00, 0x00, 0xFF
vertex     -4,      8,      0,      0,      0,  0xFF, 0x00, 0x00, 0xFF

white_particle_small_texture: # 0x04032780
.incbin "actors/white_particle_small/small_snow_particle.rgba16"

glabel white_particle_small_dl_begin # 0x04032980 - 0x040329E0
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsDPSetCombineModeLERP1Cycle G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_SHADE, G_ACMUX_0
gsSPTexture 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON
gsDPLoadTextureBlock white_particle_small_texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD
gsSPEndDisplayList

glabel white_particle_small_dl_end # 0x040329E0 - 0x04032A18
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsDPPipeSync
gsSPTexture 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList

glabel white_particle_small_dl # 0x04032A18 - 0x04032A30
gsSPDisplayList white_particle_small_dl_begin
gsSPVertex white_particle_small_vertex, 4, 0
gsSPBranchList white_particle_small_dl_end

glabel white_particle_small_unused_dl # 0x04032A30 - 0x04032A48 # Unused, has different vertex color
gsSPDisplayList white_particle_small_dl_begin
gsSPVertex white_particle_small_unused_vertex, 4, 0
gsSPBranchList white_particle_small_dl_end
