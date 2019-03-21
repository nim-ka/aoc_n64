# Warp Collision (seems strange to put these collision in another file. Only instance of this seperation thus far. Not sure what this is doing as a file.)

glabel door_seg3_collision_0301CE78 # 0x0301CE78 - 0x0301CECC
# collision vertices
.hword 0x0040, 0x0008
.hword   -80,   240,    30
.hword    80,   240,    30
.hword    80,     0,    30
.hword   -80,     0,    30
.hword   -80,   240,   -30
.hword    80,     0,   -30
.hword    80,   240,   -30
.hword   -80,     0,   -30
# collision 0x00 normal
.hword 0x0000,    4
.hword    2,    1,    0
.hword    3,    2,    0
.hword    6,    5,    4
.hword    5,    7,    4
.hword 0x0041
.hword 0x0042

glabel lll_hexagonal_mesh_seg3_collision_0301CECC # 0x0301CECC - 0x0301CEFC
# collision vertices
.hword 0x0040, 0x0004
.hword  -200,     0,  -200
.hword   200,     0,  -200
.hword   200,     0,   200
.hword  -200,     0,   200
# collision 0x00 normal
.hword 0x0000,    2
.hword    2,    1,    0
.hword    3,    2,    0
.hword 0x0041
.hword 0x0042
.word 0
