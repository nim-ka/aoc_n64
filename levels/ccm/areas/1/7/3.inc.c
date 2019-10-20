// 0x0700F6E0 - 0x0700F6E8
static const Ambient ccm_seg7_light_0700F6E0 = {
    {{0x7f, 0x7f, 0x7f}, 0, {0x7f, 0x7f, 0x7f}, 0}
};

// 0x0700F6E8 - 0x0700F6F8
static const Light ccm_seg7_light_0700F6E8 = {
    {{0xff, 0xff, 0xff}, 0, {0xff, 0xff, 0xff}, 0, {0x28, 0x28, 0x28}, 0}
};

// 0x0700F6F8 - 0x0700F738
static const Vtx ccm_seg7_vertex_0700F6F8[] = {
    {{{   219,   -378,     76}, 0, {     0,    990}, {0x56, 0x00, 0x5c, 0xff}}},
    {{{   294,   -378,      6}, 0, {   990,    990}, {0x56, 0x00, 0x5c, 0xff}}},
    {{{   294,   -275,      6}, 0, {   990,      0}, {0x56, 0x00, 0x5c, 0xff}}},
    {{{   219,   -275,     76}, 0, {     0,      0}, {0x56, 0x00, 0x5c, 0xff}}},
};

// 0x0700F738 - 0x0700F780
static const Gfx ccm_seg7_dl_0700F738[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, snow_09000800),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsSPLight(&ccm_seg7_light_0700F6E8, 1),
    gsSPLight(&ccm_seg7_light_0700F6E0, 2),
    gsSPVertex(ccm_seg7_vertex_0700F6F8, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700F780 - 0x0700F800
const Gfx ccm_seg7_dl_0700F780[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(255, 255, 255, 90),
    gsDPSetCombineLERP1Cycle(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(ccm_seg7_dl_0700F738),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPEndDisplayList(),
};

