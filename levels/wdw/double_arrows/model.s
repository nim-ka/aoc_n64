wdw_seg7_vertex_070127C8: # 0x070127C8 - 0x070128A8
vertex   -895,  -1496,  -3387,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -895,  -1496,  -3515,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex  -1151,  -1496,  -3323,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1536,  -1496,  -3131,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1536,  -1496,  -3259,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1280,  -1496,  -3323,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1536,  -1496,  -3387,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1920,  -1496,  -3259,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1536,  -1496,  -3515,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1920,  -1496,  -3387,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -895,  -1496,  -3259,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -511,  -1496,  -3259,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -895,  -1496,  -3131,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -511,  -1496,  -3387,      0,      0,  0xFF, 0xFF, 0x00, 0x80

wdw_seg7_dl_070128A8: # 0x070128A8 - 0x07012908
gsSPVertex wdw_seg7_vertex_070127C8, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  4,  6,  5, 0x0
gsSP1Triangle  4,  7,  6, 0x0
gsSP1Triangle  6,  8,  5, 0x0
gsSP1Triangle  7,  9,  6, 0x0
gsSP1Triangle 10,  0,  2, 0x0
gsSP1Triangle 10, 11,  0, 0x0
gsSP1Triangle 10,  2, 12, 0x0
gsSP1Triangle 11, 13,  0, 0x0
gsSPEndDisplayList

glabel wdw_seg7_dl_07012908 # 0x07012908 - 0x07012938
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsSPDisplayList wdw_seg7_dl_070128A8
gsDPPipeSync
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList