// 0x07008FD0 - 0x07009010
static const Vtx ddd_seg7_vertex_07008FD0[] = {
    {{{  4941,  -1015,  -4095}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
    {{{  2893,  -1015,  -4095}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
    {{{  2893,  -3063,  -5631}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
    {{{  4941,  -3063,  -5631}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
};

// 0x07009010 - 0x07009030
static const Gfx ddd_seg7_dl_07009010[] = {
    gsSPVertex(ddd_seg7_vertex_07008FD0, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x07009030 - 0x07009080
const Gfx ddd_seg7_dl_07009030[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(255, 255, 255, 80),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
    gsSPClearGeometryMode(G_LIGHTING | G_CULL_BACK),
    gsSPDisplayList(ddd_seg7_dl_07009010),
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsSPSetGeometryMode(G_LIGHTING | G_CULL_BACK),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPEndDisplayList(),
};

