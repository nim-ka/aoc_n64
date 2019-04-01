glabel bowser_2_seg7_collision_lava # 0x070019F0 - 0x07001A66
# collision vertices
.hword 0x0040, 0x0008
.hword -2776, -1023, -6479
.hword -6545, -1023, -2617
.hword -6479, -1023,  2777
.hword  6480, -1023, -2776
.hword  2618, -1023, -6545
.hword -2617, -1023,  6546
.hword  6546, -1023,  2618
.hword  2777, -1023,  6480
# collision 0x01 lethal_lava
.hword 0x0001,    6
.hword    0,    1,    2
.hword    0,    3,    4
.hword    0,    2,    5
.hword    0,    6,    3
.hword    0,    7,    6
.hword    0,    5,    7
.hword 0x0041
# special objects  0x43
.hword 0x0043,    2 # add 2 special objects
special_object /*preset*/ special_null_start, /*pos*/  0, 1229,     0, /*yaw*/ 128 # unused, probably an early way to set intial position
special_object /*preset*/ special_bowser,     /*pos*/ -8, 1229, -1418
.hword 0x0042
