// 0x07007F90 - 0x07007F98
static const Ambient vcutm_seg7_light_07007F90 = {
    {{0x3f, 0x3f, 0x3f}, 0, {0x3f, 0x3f, 0x3f}, 0}
};

// 0x07007F98 - 0x07007FA8
static const Light vcutm_seg7_light_07007F98 = {
    {{0xff, 0xff, 0xff}, 0, {0xff, 0xff, 0xff}, 0, {0x28, 0x28, 0x28}, 0}
};

// 0x07007FA8 - 0x07008068
static const Vtx vcutm_seg7_vertex_07007FA8[] = {
    {{{  4915,      0,  -5099}, 0, { -3096,   4054}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  4116,    819,  -5099}, 0, {  5078,  -4120}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  4915,    819,  -5099}, 0, { -3096,  -4120}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  4116,      0,  -5099}, 0, {  5078,   4054}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  4915,    819,  -4320}, 0, {  5078,  -2076}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  4116,      0,  -4320}, 0, { -3096,   6098}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  4915,      0,  -4320}, 0, {  5078,   6098}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  4116,    819,  -4320}, 0, { -3096,  -2076}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  4116,    819,  -4320}, 0, {  4056,  -4120}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  4116,      0,  -5099}, 0, { -4118,   4054}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  4116,      0,  -4320}, 0, {  4056,   4054}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  4116,    819,  -5099}, 0, { -4118,  -4120}, {0x81, 0x00, 0x00, 0xff}}},
};

// 0x07008068 - 0x070080D0
static const Gfx vcutm_seg7_dl_07008068[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, vcutm_seg7_texture_07000000),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsSPLight(&vcutm_seg7_light_07007F98, 1),
    gsSPLight(&vcutm_seg7_light_07007F90, 2),
    gsSPVertex(vcutm_seg7_vertex_07007FA8, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  7,  5, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  8, 11,  9, 0x0),
    gsSPEndDisplayList(),
};

// 0x070080D0 - 0x07008140
const Gfx vcutm_seg7_dl_070080D0[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(vcutm_seg7_dl_07008068),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

