# level script cake_end_level from 4AA450-4AA510



.global cake_end_level
.align 4, 0
cake_end_level:
.word 0x1B040000
.word 0x180C0007, cake_end, cake_end_end
.word 0x1D040000
.word 0x1F080100, 0x0E000050
.word 0x20040000
.word 0x1E040000
.word 0x0304003C
.word 0x34040000
.word 0x29040100
.word 0x3308004B, 0x00000000
.word 0x03040078
.word 0x11080000, LevelProc_8024BFA0 # 8024BE00
.word 0x03040001
.word 0x05080000, 0x0E000044
# begin cake_end_level geo 0x4AA4A0
.word 0x0800000A, 0x00A00078, 0x00A00078
.word 0x04000000
.word   0x0C000000
.word   0x04000000
.word     0x09000064
.word     0x04000000
.word       0x18000000, Geo18_802D28CC
.word     0x05000000
.word   0x05000000
.word   0x0C010000
.word   0x04000000
.word     0x0A01002D, 0x00643200, Geo0A_8029AA3C
.word     0x04000000
.word       0x0F000001, 0x000007D0, 0x17700000, 0x00000000, Geo0F_80287D30
.word     0x05000000
.word   0x05000000
.word 0x05000000
.word 0x01000000
.word 0x00000000
cake_end_level_end:
