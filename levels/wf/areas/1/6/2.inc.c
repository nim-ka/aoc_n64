// 0x07006558 - 0x07006560
static const Ambient wf_seg7_light_07006558 = {
    {{0x66, 0x66, 0x66}, 0, {0x66, 0x66, 0x66}, 0}
};

// 0x07006560 - 0x07006570
static const Light wf_seg7_light_07006560 = {
    {{0xff, 0xff, 0xff}, 0, {0xff, 0xff, 0xff}, 0, {0x28, 0x28, 0x28}, 0}
};

// 0x07006570 - 0x070065B0
static const Vtx wf_seg7_vertex_07006570[] = {
    {{{  -178,    640,   1280}, 0, {     0,   -440}, {0x00, 0x72, 0xca, 0xff}}},
    {{{   179,    640,   1280}, 0, {     0,    990}, {0x00, 0x72, 0xca, 0xff}}},
    {{{   179,   -600,  -1304}, 0, { 11414,    990}, {0x00, 0x72, 0xca, 0xff}}},
    {{{  -178,   -600,  -1304}, 0, { 11414,   -440}, {0x00, 0x72, 0xca, 0xff}}},
};

// 0x070065B0 - 0x070065F8
static const Gfx wf_seg7_dl_070065B0[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, grass_09008000),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsSPLight(&wf_seg7_light_07006560, 1),
    gsSPLight(&wf_seg7_light_07006558, 2),
    gsSPVertex(wf_seg7_vertex_07006570, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x070065F8 - 0x07006668
const Gfx wf_seg7_dl_070065F8[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(wf_seg7_dl_070065B0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

