// White Particle

// 0x0302C660
static const Vtx white_particle_vertex[] = {
    {{{   -15,    -15,      0}, 0, {     0,    480}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    15,    -15,      0}, 0, {   480,    480}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    15,     15,      0}, 0, {   480,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -15,     15,      0}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
};

// 0x0302C6A0
static const u8 white_particle_texture[] = {
#include "actors/white_particle/snow_particle.rgba16.inc.c"
};

// 0x0302C8A0 - 0x0302C938
const Gfx white_particle_dl[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP1Cycle(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
    gsDPLoadTextureBlock(white_particle_texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(white_particle_vertex, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

