glabel sa_seg7_collision # 0x07003000 - 0x07003282
# terrain vertices
.hword 0x0040, 0x0030
.hword -2661,     0,  3072
.hword  2662,     0,  3072
.hword  2662, -4607,  3072
.hword -2661, -4607,  3072
.hword  2662,     0, -3071
.hword -2661,     0, -3071
.hword -2661, -4607, -3071
.hword  2662, -4607, -3071
.hword -3071,     0, -2661
.hword -3071,     0,  2662
.hword -3071, -4607,  2662
.hword -3071, -4607, -2661
.hword  3072,     0,  2662
.hword  3072, -4607, -2661
.hword  3072, -4607,  2662
.hword  3072,     0, -2661
.hword  3072,     0,  3072
.hword -3071, -4607,  3072
.hword   512, -4607,  -511
.hword  -511, -4607,  -511
.hword   307, -4402,  -306
.hword  -511, -4607,   512
.hword   512, -4607,   512
.hword -2866, -4607,  2662
.hword -2661, -4607,  2867
.hword -2661, -4607, -2866
.hword -2866, -4607, -2661
.hword  2867, -4607, -2661
.hword  2662, -4607, -2866
.hword  2662, -4607,  2867
.hword  2867, -4607,  2662
.hword -3071,     0, -3071
.hword  3072,     0, -3071
.hword -3071,     0,  3072
.hword  3072, -4607,  3072
.hword -3071, -4607, -3071
.hword  3072, -4607, -3071
.hword  -306, -4402,   307
.hword   307, -4402,   307
.hword  -306, -4402,  -306
.hword -2866,     0,  2662
.hword -2661,     0,  2867
.hword -2661,     0, -2866
.hword -2866,     0, -2661
.hword  2867,     0, -2661
.hword  2662,     0, -2866
.hword  2662,     0,  2867
.hword  2867,     0,  2662
# terrain 0x00 normal
.hword 0x0000,   52
.hword   12,   13,   14
.hword    0,    1,    2
.hword    0,    2,    3
.hword    4,    5,    6
.hword    4,    6,    7
.hword    8,    9,   10
.hword    8,   10,   11
.hword   17,   19,   35
.hword   12,   15,   13
.hword   16,   31,   32
.hword   16,   33,   31
.hword   17,   34,   22
.hword   17,   22,   21
.hword   17,   21,   19
.hword   21,   39,   19
.hword   18,   22,   34
.hword   18,   34,   36
.hword   19,   18,   36
.hword   19,   36,   35
.hword   20,   37,   38
.hword   19,   39,   20
.hword   19,   20,   18
.hword   18,   20,   38
.hword   20,   39,   37
.hword   21,   37,   39
.hword   24,    0,    3
.hword   22,   38,   37
.hword   22,   37,   21
.hword   18,   38,   22
.hword   10,    9,   40
.hword   10,   40,   23
.hword   23,   40,   41
.hword   23,   41,   24
.hword   24,   41,    0
.hword   27,   44,   45
.hword    6,    5,   42
.hword    6,   42,   25
.hword   25,   42,   43
.hword   25,   43,   26
.hword   26,   43,    8
.hword   26,    8,   11
.hword   13,   15,   44
.hword   13,   44,   27
.hword   30,   12,   14
.hword   27,   45,   28
.hword   28,   45,    4
.hword   28,    4,    7
.hword    2,    1,   46
.hword    2,   46,   29
.hword   29,   46,   47
.hword   29,   47,   30
.hword   30,   47,   12
.hword 0x0041
# special object 0x43
.hword 0x0043,    1 # add 1 special object
special_object /*preset*/ special_null_start, /*pos*/ 0, -1535, 0, /*yaw*/ 64 # unused, probably an early way to set intial position
# water boxes (val, loX, hiX, loZ, hiZ, height)
.hword 0x0044,    1
.hword     0, -3173, -3173,  3174,  3174,   102
.hword 0x0042
