// 0x0700BC88 - 0x0700BCC8
static const Vtx ssl_seg7_vertex_0700BC88[] = {
    {{{ -6143,      0,  -4697}, 0, {   990,      0}, {0xff, 0xff, 0xff, 0xc8}}},
    {{{ -5836,      0,  -4697}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xc8}}},
    {{{ -5836,      0,  -5004}, 0, {     0,    990}, {0xff, 0xff, 0xff, 0xc8}}},
    {{{ -6143,      0,  -5004}, 0, {   990,    990}, {0xff, 0xff, 0xff, 0xc8}}},
};

// 0x0700BCC8 - 0x0700BD00
static const Gfx ssl_seg7_dl_0700BCC8[] = {
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, ssl_seg7_texture_07000800),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsSPVertex(ssl_seg7_vertex_0700BC88, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700BD00 - 0x0700BD70
const Gfx ssl_seg7_dl_0700BD00[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(ssl_seg7_dl_0700BCC8),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

