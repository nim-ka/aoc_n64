sa_vertex_07002E80: # 0x07002E80 - 0x07002F80
vertex  -3276,   -972,   1075,      0,      0,  0x00, 0x00, 0xFF, 0x40
vertex  -3276,  -3122,  -1074,      0,      0,  0x00, 0x00, 0xFF, 0x40
vertex  -3276,   -972,  -1074,      0,      0,  0x00, 0x00, 0xFF, 0x40
vertex  -3276,  -3122,   1075,      0,      0,  0x00, 0x00, 0xFF, 0x40
vertex  -1074,  -3122,  -3276,      0,      0,  0x00, 0xFF, 0x00, 0x40
vertex   1075,   -972,  -3276,      0,      0,  0x00, 0xFF, 0x00, 0x40
vertex  -1074,   -972,  -3276,      0,      0,  0x00, 0xFF, 0x00, 0x40
vertex   1075,  -3122,  -3276,      0,      0,  0x00, 0xFF, 0x00, 0x40
vertex   3277,   -972,  -1074,      0,      0,  0xFF, 0x00, 0x00, 0x40
vertex   3277,  -3122,  -1074,      0,      0,  0xFF, 0x00, 0x00, 0x40
vertex   3277,  -3122,   1075,      0,      0,  0xFF, 0x00, 0x00, 0x40
vertex   3277,   -972,   1075,      0,      0,  0xFF, 0x00, 0x00, 0x40
vertex  -1074,   -972,   3277,      0,      0,  0x00, 0xFF, 0xFF, 0x40
vertex   1075,  -3122,   3277,      0,      0,  0x00, 0xFF, 0xFF, 0x40
vertex  -1074,  -3122,   3277,      0,      0,  0x00, 0xFF, 0xFF, 0x40
vertex   1075,   -972,   3277,      0,      0,  0x00, 0xFF, 0xFF, 0x40

sa_dl_07002F80: # 0x07002F80 - 0x07002FD0
gsSPVertex sa_vertex_07002E80, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  7,  5, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 15, 13, 0x0
gsSPEndDisplayList

glabel sa_seg7_dl_07002FD0 # 0x07002FD0 - 0x07003000
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsSPDisplayList sa_dl_07002F80
gsDPPipeSync
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList
