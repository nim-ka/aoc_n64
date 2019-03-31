# This file only has a collision entry and no model. It may have been some sort of
# collision hitbox for an object that didn't have a model.

.balign 4 # 0x0700D1DA - 0x0700D1DC

# TODO: this appears to be a lid for an unused box
glabel jrb_seg7_collision_0700D1DC # 0x0700D1DC - 0x0700D20C
# collision vertices
.hword 0x0040, 0x0004
.hword   123,     0,  -122
.hword  -122,     0,  -122
.hword  -122,     0,   123
.hword   123,     0,   123
# collision 0x00 normal
.hword 0x0000,    2
.hword    0,    1,    2
.hword    0,    2,    3
.hword 0x0041
.hword 0x0042
