.balign 4 # 0x07012642 - 0x07012644

glabel ssl_seg7_collision_tox_box # 0x07012644 - 0x07012758
# collision vertices
.hword 0x0040, 0x0010
.hword  -255,   256,   256
.hword   256,   256,  -255
.hword  -255,   256,  -255
.hword   256,   256,   256
.hword  -255,  -255,   256
.hword   256,  -255,   256
.hword   256,  -255,  -255
.hword  -255,  -255,  -255
.hword   154,  -255,   154
.hword   154,  -255,  -153
.hword  -153,  -255,  -153
.hword  -153,  -255,   154
.hword  -153,   154,   154
.hword  -153,   154,  -153
.hword   154,   154,  -153
.hword   154,   154,   154
# collision 0x28 wall
.hword 0x0028,   28
.hword   12,   13,   14
.hword    0,    1,    2
.hword    0,    3,    1
.hword    4,    0,    2
.hword    5,    0,    4
.hword    5,    3,    0
.hword    6,    3,    5
.hword    6,    1,    3
.hword    7,    1,    6
.hword    7,    2,    1
.hword    4,    2,    7
.hword    8,    6,    5
.hword    8,    9,    6
.hword    7,    6,    9
.hword    4,    8,    5
.hword    7,    9,   10
.hword    7,   11,    4
.hword    7,   10,   11
.hword    4,   11,    8
.hword   12,   11,   10
.hword   12,   10,   13
.hword   10,   14,   13
.hword   10,    9,   14
.hword    8,   11,   12
.hword   14,    9,    8
.hword   12,   14,   15
.hword    8,   12,   15
.hword   14,    8,   15
.hword 0x0041
.hword 0x0042
