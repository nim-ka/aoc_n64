// 0x0702AC00 - 0x0702AC40
static const Vtx ttm_seg7_vertex_0702AC00[] = {
    {{{  1024,   2048,      0}, 0, {   990,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{ -1023,   2048,      0}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{ -1023,      0,      0}, 0, {     0,    990}, {0xff, 0xff, 0xff, 0xff}}},
    {{{  1024,      0,      0}, 0, {   990,    990}, {0xff, 0xff, 0xff, 0xff}}},
};

// 0x0702AC40 - 0x0702AC78
static const Gfx ttm_seg7_dl_0702AC40[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mountain_0900B000),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsSPVertex(ttm_seg7_vertex_0702AC00, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x0702AC78 - 0x0702ACE8
const Gfx ttm_seg7_dl_0702AC78[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(ttm_seg7_dl_0702AC40),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

