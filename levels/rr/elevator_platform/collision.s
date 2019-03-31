.balign 4 # 0x070296CA - 0x070296CC

glabel rr_seg7_collision_elevator_platform # 0x070296CC - 0x07029750
# collision vertices
.hword 0x0040, 0x0008
.hword   205,   102,   307
.hword   205,     0,   307
.hword   205,     0,  -306
.hword  -204,     0,   307
.hword  -204,     0,  -306
.hword  -204,   102,   307
.hword  -204,   102,  -306
.hword   205,   102,  -306
# collision 0x00 normal
.hword 0x0000,   12
.hword    0,    1,    2
.hword    1,    3,    4
.hword    1,    4,    2
.hword    5,    3,    1
.hword    5,    1,    0
.hword    6,    4,    3
.hword    6,    3,    5
.hword    7,    4,    6
.hword    7,    2,    4
.hword    0,    2,    7
.hword    7,    6,    5
.hword    7,    5,    0
.hword 0x0041
.hword 0x0042
