.balign 4 # 0x070125F2 - 0x070125F4

glabel ssl_seg7_collision_pyramid_top # 0x070125F4 - 0x07012642
# collision vertices
.hword 0x0040, 0x0005
.hword  -511,  -255,   512
.hword   512,  -255,  -511
.hword   512,  -255,   512
.hword     0,   256,     0
.hword  -511,  -255,  -511
# collision 0x35 35
.hword 0x0035,    6
.hword    0,    1,    2
.hword    0,    2,    3
.hword    2,    1,    3
.hword    0,    4,    1
.hword    1,    4,    3
.hword    4,    0,    3
.hword 0x0041
.hword 0x0042
