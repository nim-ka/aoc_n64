.balign 4

glabel wf_seg7_collision_kickable_board # 0x0700FC7C - 0x0700FD00
# terrain vertices
.hword 0x0040, 0x0008
.hword   -96,     0,     0
.hword   -96,  1178,    77
.hword   -96,  1178,     0
.hword    95,  1178,    77
.hword    95,  1178,     0
.hword    95,     0,     0
.hword    95,     0,    77
.hword   -96,     0,    77
# terrain 0x28 wall
.hword 0x0028,   12
.hword    0,    1,    2
.hword    2,    1,    3
.hword    2,    3,    4
.hword    2,    4,    5
.hword    2,    5,    0
.hword    4,    3,    6
.hword    4,    6,    5
.hword    0,    7,    1
.hword    3,    1,    7
.hword    3,    7,    6
.hword    5,    6,    7
.hword    5,    7,    0
.hword 0x0041
.hword 0x0042
