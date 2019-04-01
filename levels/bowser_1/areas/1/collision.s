glabel bowser_1_seg7_collision_level # 0x07002838 - 0x07002AC8
# collision vertices
.hword 0x0040, 0x001D
.hword  2172,   307, -2171
.hword     0,   307, -3071
.hword  1086,   307, -1085
.hword -2171,   307, -2171
.hword     0,   307, -1535
.hword -2171,   307,  2172
.hword     0, -2047,  3072
.hword     0,   307,  3072
.hword -3071, -2047,     0
.hword -3071,   307,     0
.hword -2171, -2047,  2172
.hword -1535,   307,     0
.hword -1085,   307, -1085
.hword -1085,   307,  1086
.hword -2171, -2047, -2171
.hword     0,   307,  1536
.hword  3072,   307,     0
.hword     0, -2047, -3071
.hword  2172, -2047,  2172
.hword  3072, -2047,     0
.hword  2172,   307,  2172
.hword  2172, -2047, -2171
.hword  1536,   307,     0
.hword  1086,   307,  1086
.hword     0,   307,     0
.hword  7168, -6143, -7167
.hword -7167, -6143, -7167
.hword -7167, -6143,  7168
.hword  7168, -6143,  7168
# collision 0x00 normal
.hword 0x0000,   40
.hword    5,    6,    7
.hword    0,    1,    2
.hword    1,    3,    4
.hword    5,    7,   15
.hword    8,    9,    3
.hword   10,    9,    8
.hword   10,    5,    9
.hword    9,   11,   12
.hword    9,   13,   11
.hword    9,    5,   13
.hword    9,   12,    3
.hword    4,    3,   12
.hword    8,    3,   14
.hword   14,    3,    1
.hword    6,    5,   10
.hword    5,   15,   13
.hword    7,   20,   23
.hword    2,    1,    4
.hword   16,    0,    2
.hword   16,    2,   22
.hword   14,    1,   17
.hword   17,    1,    0
.hword   18,   20,    7
.hword   18,    7,    6
.hword    7,   23,   15
.hword   17,    0,   21
.hword   19,   20,   18
.hword   19,   16,   20
.hword   20,   22,   23
.hword   20,   16,   22
.hword   21,   16,   19
.hword   21,    0,   16
.hword   11,   24,   12
.hword   13,   24,   11
.hword    2,   24,   22
.hword   24,    2,    4
.hword   23,   24,   15
.hword   24,    4,   12
.hword   15,   24,   13
.hword   22,   24,   23
# collision 0x0A deathfloor
.hword 0x000A,    2
.hword   25,   26,   27
.hword   25,   27,   28
.hword 0x0041
# special objects 0x43
.hword 0x0043,   22 # add 22 special objects
special_object /*preset*/ special_null_start,   /*pos*/     0, 1843,     0, /*yaw*/ 1423 # unused, probably an early way to set intial position
special_object /*preset*/ special_mine,         /*pos*/  2949,  589,     0
special_object /*preset*/ special_mine,         /*pos*/     0,  589, -2949
special_object /*preset*/ special_mine,         /*pos*/     0,  589,  2949
special_object /*preset*/ special_mine,         /*pos*/ -2949,  589,     0
special_object /*preset*/ special_bowser,       /*pos*/     0,  300, -1000
special_object /*preset*/ special_level_geo_03, /*pos*/     0,  384,  3072, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -2171,  384, -2171, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/     0,  384, -3071, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -3071,  384,     0, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -2171,  384,  2172, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -2621,  384,  1086, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  2172,  384,  2172, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  3072,  384,     0, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  2172,  384, -2171, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -1085,  384,  2622, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  2622,  384,  1086, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -2621,  384, -1085, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -1085,  384, -2621, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  1086,  384, -2621, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  2622,  384, -1085, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  1086,  384,  2622, /*yaw*/    0
.hword 0x0042
