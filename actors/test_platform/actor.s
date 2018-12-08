# Test Platform (small tiny platform 1/4th the size of a box. Probably used in early modeling tests?)

unknown_seg8_light_08026008: # 0x08026008
.byte 0x32, 0x32, 0x07, 0x00, 0x32, 0x32, 0x07, 0x00

unknown_seg8_light_08026010: # 0x08026010
.byte 0xC8, 0xC8, 0x1E, 0x00, 0xC8, 0xC8, 0x1E, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

unknown_seg8_vertex_08026020: # 0x08026020
vertex    200,   -100,    200,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    200,   -100,   -200,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    200,      0,   -200,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    200,      0,    200,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    200,   -100,    200,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    200,      0,   -200,      0,      0,  0x7F, 0x00, 0x00, 0x00
vertex    200,   -100,   -200,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex    200,   -100,    200,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex   -200,   -100,   -200,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex    200,   -100,    200,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex   -200,   -100,    200,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex   -200,   -100,   -200,      0,      0,  0x00, 0x81, 0x00, 0x00
vertex    200,      0,   -200,      0,      0,  0x00, 0x00, 0x81, 0x00
vertex    200,   -100,   -200,      0,      0,  0x00, 0x00, 0x81, 0x00
vertex   -200,   -100,   -200,      0,      0,  0x00, 0x00, 0x81, 0x00

unknown_seg8_vertex_08026110: # 0x08026110
vertex   -200,      0,   -200,      0,      0,  0x00, 0x00, 0x81, 0x00
vertex    200,      0,   -200,      0,      0,  0x00, 0x00, 0x81, 0x00
vertex   -200,   -100,   -200,      0,      0,  0x00, 0x00, 0x81, 0x00
vertex   -200,   -100,   -200,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex   -200,   -100,    200,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex   -200,      0,   -200,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex   -200,   -100,    200,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex   -200,      0,    200,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex   -200,      0,   -200,      0,      0,  0x81, 0x00, 0x00, 0x00
vertex    200,      0,    200,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    200,      0,   -200,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex   -200,      0,   -200,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex   -200,      0,    200,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex    200,      0,    200,      0,      0,  0x00, 0x7F, 0x00, 0x00
vertex   -200,      0,   -200,      0,      0,  0x00, 0x7F, 0x00, 0x00

unknown_seg8_vertex_08026200: # 0x08026200
vertex    200,   -100,    200,      0,      0,  0x00, 0x00, 0x7F, 0x00
vertex    200,      0,    200,      0,      0,  0x00, 0x00, 0x7F, 0x00
vertex   -200,   -100,    200,      0,      0,  0x00, 0x00, 0x7F, 0x00
vertex    200,      0,    200,      0,      0,  0x00, 0x00, 0x7F, 0x00
vertex   -200,      0,    200,      0,      0,  0x00, 0x00, 0x7F, 0x00
vertex   -200,   -100,    200,      0,      0,  0x00, 0x00, 0x7F, 0x00

glabel unknown_seg8_dl_08026260 # 0x08026260 - 0x080262F8
gsMoveWd 0, 2, 0x80000040
gsSPLight unknown_seg8_light_08026010, 1
gsSPLight unknown_seg8_light_08026008, 2
gsSPVertex unknown_seg8_vertex_08026020, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPVertex unknown_seg8_vertex_08026110, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPVertex unknown_seg8_vertex_08026200, 6, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSPEndDisplayList

glabel unknown_seg8_collision_080262F8 # 0x080262F8 - 0x0802637C
# collision vertices
.hword 0x0040, 0x0008
.hword   200,     0,  -200
.hword   200,  -100,  -200
.hword   200,  -100,   200
.hword   200,     0,   200
.hword  -200,  -100,  -200
.hword  -200,  -100,   200
.hword  -200,     0,  -200
.hword  -200,     0,   200
# collision 0x00 normal
.hword 0x0000,   12
.hword    2,    1,    0
.hword    3,    2,    0
.hword    1,    2,    4
.hword    2,    5,    4
.hword    0,    1,    4
.hword    6,    0,    4
.hword    4,    5,    6
.hword    5,    7,    6
.hword    3,    0,    6
.hword    7,    3,    6
.hword    2,    3,    5
.hword    3,    7,    5
.hword 0x0041
.hword 0x0042
.word 0

binid
