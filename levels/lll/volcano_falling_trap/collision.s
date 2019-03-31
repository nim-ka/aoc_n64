.balign 4 # 0x070284DA - 0x070284DC

glabel lll_seg7_collision_falling_wall # 0x070284DC - 0x0702856C
# collision vertices
.hword 0x0040, 0x000A
.hword   307,  -101,   105
.hword   307,   614,   105
.hword   307,  -101,   703
.hword  -306,   614,   105
.hword  -306,  -101,   703
.hword  -306,  -101,   105
.hword  -306,  -101,     3
.hword  -306,   614,     3
.hword   307,   614,     3
.hword   307,  -101,     3
# collision 0x00 normal
.hword 0x0000,   12
.hword    0,    1,    2
.hword    2,    1,    3
.hword    2,    3,    4
.hword    3,    5,    4
.hword    6,    7,    8
.hword    6,    8,    9
.hword    7,    1,    8
.hword    7,    3,    1
.hword    7,    6,    5
.hword    7,    5,    3
.hword    9,    8,    1
.hword    9,    1,    0
.hword 0x0041
.hword 0x0042
