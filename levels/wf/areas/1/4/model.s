wf_seg7_vertex_07005568: # 0x07005568 - 0x07005658
vertex   1270,   2944,   -772,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1343,   2739,   -844,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   1198,   2739,   -699,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   3594,   1459,    870,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   3594,   1587,   1126,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   3594,   1331,   1126,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   3594,   1459,   -511,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   3594,   1587,   -255,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   3594,   1331,   -255,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex  -1033,   2944,    512,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex  -1033,   2816,    256,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex  -1033,   2688,    512,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -824,   2944,  -1017,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -727,   2816,  -1254,      0,      0,  0xFF, 0xFF, 0x00, 0x80
vertex   -824,   2688,  -1017,      0,      0,  0xFF, 0xFF, 0x00, 0x80

wf_seg7_dl_07005658: # 0x07005658 - 0x07005690
gsSPVertex wf_seg7_vertex_07005568, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPEndDisplayList

glabel wf_seg7_dl_07005690 # 0x07005690 - 0x070056C0
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsSPDisplayList wf_seg7_dl_07005658
gsDPPipeSync
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList