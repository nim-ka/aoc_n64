.include "macros.inc"

.section .data

# 0x801A76F0

#intro geo (all data)
glabel D_801A7B30
   .word title_f3d_0A000130, title_f3d_0A000148, title_f3d_0A000160, title_f3d_0A000178 

glabel D_801A7B40
   .float   0.0,  80.0, 160.0, 240.0
   .float   0.0,  80.0, 160.0, 240.0
   .float   0.0,  80.0, 160.0, 240.0

glabel D_801A7B70
   .float 160.0, 160.0, 160.0, 160.0
   .float  80.0,  80.0,  80.0,  80.0
   .float   0.0,   0.0,   0.0,   0.0

glabel D_801A7BA0
   .word mario_title_texture_table, game_over_texture_table

glabel D_801A7BA8
   .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

glabel D_801A7BB4
   .word D_801A7BA8

glabel D_801A7BB8
   .byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01

glabel D_801A7BC4
   .byte 0x00, 0x01, 0x02, 0x03, 0x07, 0x0b, 0x0a, 0x09, 0x08, 0x04, 0x05, 0x06
