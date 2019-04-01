glabel bowser_3_seg7_collision_level # 0x070049C8 - 0x07004B94
# collision vertices
.hword 0x0040, 0x0018
.hword -8191, -6143,  8192
.hword  8192, -6143,  8192
.hword  8192, -6143, -8191
.hword -8191, -6143, -8191
.hword -1182, -2364,   394
.hword -1182,   307,   394
.hword -2364,   307,  -787
.hword -2364, -1852,  -787
.hword  -787,   307, -1024
.hword  -787, -2364, -1024
.hword -1497, -1852,  2050
.hword -1497,   307,  2050
.hword     0,   307,  1262
.hword   788,   307, -1024
.hword     0,   307, -2522
.hword  1183,   307,   394
.hword  1498, -1852,  2050
.hword  1498,   307,  2050
.hword     0, -2364,  1262
.hword  2365,   307,  -787
.hword  2365, -1852,  -787
.hword  1183, -2364,   394
.hword   788, -2364, -1024
.hword     0, -1852, -2522
# collision 0x00 normal
.hword 0x0000,   36
.hword    4,   18,   10
.hword    4,    5,    6
.hword    4,    6,    7
.hword    6,    5,    8
.hword    6,    8,    9
.hword    7,    6,    9
.hword   10,    5,    4
.hword   10,   11,    5
.hword    5,   11,   12
.hword    8,    5,   12
.hword   13,   14,    8
.hword    8,   12,   15
.hword    8,   15,   13
.hword    9,    8,   14
.hword   16,   17,   12
.hword   16,   12,   18
.hword   18,   12,   11
.hword   12,   17,   15
.hword   18,   11,   10
.hword   18,    4,    9
.hword    4,    7,    9
.hword    9,   23,   22
.hword   15,   19,   13
.hword   20,   19,   15
.hword   20,   15,   21
.hword   21,   15,   17
.hword   22,   13,   19
.hword   14,   13,   22
.hword   23,   14,   22
.hword    9,   14,   23
.hword   22,   19,   20
.hword   21,   17,   16
.hword   21,   22,   20
.hword   18,   22,   21
.hword   16,   18,   21
.hword   18,    9,   22
# collision 0x0A deathfloor
.hword 0x000A,    2
.hword    0,    1,    2
.hword    0,    2,    3
.hword 0x0041
# special objects 0x43
.hword 0x0043,    7 # add 7 special objects
special_object /*preset*/ special_null_start,   /*pos*/     0,   307,     0, /*yaw*/  128 # unused, probably an early way to set intial position
special_object /*preset*/ special_bowser,       /*pos*/    13,   307, -1024
special_object /*preset*/ special_level_geo_03, /*pos*/ -3362,  -204,  1121, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/     0,  -204,  3584, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  3362,  -204,  1126, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/  2123,  -204, -2912, /*yaw*/    0
special_object /*preset*/ special_level_geo_03, /*pos*/ -2122,  -204, -2912, /*yaw*/    0
.hword 0x0042
