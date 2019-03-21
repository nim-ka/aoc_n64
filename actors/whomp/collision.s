# Whomp

glabel whomp_seg6_collision_06020A0C # 0x06020A0C - 0x06020A90
.ifdef VERSION_JP
# collision vertices
.hword 0x0040, 0x0008
.hword  -200,    50,  -100
.hword   150,    50,  -100
.hword   150,   430,  -100
.hword  -200,   430,  -100
.hword  -200,    50,    -3
.hword   150,   430,    -3
.hword   150,    50,    -3
.hword  -200,   430,    -3
# collision 0x76 fence
.hword 0x0076,   12
.hword    2,    1,    0
.hword    3,    2,    0
.hword    6,    5,    4
.hword    5,    7,    4
.hword    7,    5,    3
.hword    5,    2,    3
.hword    6,    4,    0
.hword    1,    6,    0
.hword    5,    1,    2
.hword    6,    1,    5
.hword    0,    7,    3
.hword    0,    4,    7
.hword 0x0041
.hword 0x0042
.word 0
.else
# collision vertices
.hword 0x0040, 0x0008
.hword  -150,    50,  -100
.hword   150,    50,  -100
.hword   150,   430,  -100
.hword  -150,   430,  -100
.hword  -150,    50,    -3
.hword   150,   430,    -3
.hword   150,    50,    -3
.hword  -150,   430,    -3
# collision 0x76 fence
.hword 0x0076,   12
.hword    2,    1,    0
.hword    3,    2,    0
.hword    6,    5,    4
.hword    5,    7,    4
.hword    7,    5,    3
.hword    5,    2,    3
.hword    6,    4,    0
.hword    1,    6,    0
.hword    5,    1,    2
.hword    6,    1,    5
.hword    0,    7,    3
.hword    0,    4,    7
.hword 0x0041
.hword 0x0042
.word 0
.endif
