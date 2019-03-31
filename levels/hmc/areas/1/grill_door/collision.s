glabel hmc_seg7_collision_0702B65C # 0x0702B65C - 0x0702B6E0
# collision vertices
.ifdef VERSION_JP
.hword 0x0040, 0x0008
.hword   410,     0,    51
.hword   410,   819,   -50
.hword   410,   819,    51
.hword     0,   819,    51
.hword     0,     0,    51
.hword     0,   819,   -50
.hword   410,     0,   -50
.hword     0,     0,   -50
# collision 0x00 normal
.hword 0x0000,   12
.hword    0,    1,    2
.hword    2,    3,    4
.hword    2,    4,    0
.hword    2,    1,    5
.hword    2,    5,    3
.hword    6,    5,    1
.hword    0,    6,    1
.hword    6,    7,    5
.hword    3,    5,    7
.hword    3,    7,    4
.hword    4,    7,    6
.hword    4,    6,    0
.hword 0x0041
.hword 0x0042
.else
.hword 0x0040, 0x0008
.hword   410,     0,    51
.hword   410,   719,   -50 # 819 changed to 719 in non-JP builds
.hword   410,   719,    51
.hword     0,   719,    51
.hword     0,     0,    51
.hword     0,   719,   -50
.hword   410,     0,   -50
.hword     0,     0,   -50
# collision 0x00 normal
.hword 0x0000,   12
.hword    0,    1,    2
.hword    2,    3,    4
.hword    2,    4,    0
.hword    2,    1,    5
.hword    2,    5,    3
.hword    6,    5,    1
.hword    0,    6,    1
.hword    6,    7,    5
.hword    3,    5,    7
.hword    3,    7,    4
.hword    4,    7,    6
.hword    4,    6,    0
.hword 0x0041
.hword 0x0042
.endif
