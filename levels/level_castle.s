.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "mio0/inside_castle_seg7.mio0"
.align 4

.section .level, "a"

script_func_local_1:
    warp_node /*id*/ 0x00, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x00, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x01, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x01, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x02, /*destLevel1*/ 0x1A, /*destArea*/ 0x01, /*destNode*/ 0x01, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0xD5, /*pos*/ -2706, 512, -1409, /*angle*/ 0, 45, 0, /*behArg*/ 0x08000000, /*beh*/ beh_star_door
    object /*unk2*/ 0x1F, /*unk3*/ 0xD5, /*pos*/ -2598, 512, -1517, /*angle*/ 0, 225, 0, /*behArg*/ 0x08000000, /*beh*/ beh_star_door
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -1100, 512, -1074, /*angle*/ 0, 0, 0, /*behArg*/ 0x01030000, /*beh*/ beh_door_warp
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -946, 512, -1074, /*angle*/ 0, 180, 0, /*behArg*/ 0x01040000, /*beh*/ beh_door_warp
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -1100, -1074, 922, /*angle*/ 0, 0, 0, /*behArg*/ 0x02050000, /*beh*/ beh_door_warp
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -946, -1074, 922, /*angle*/ 0, 180, 0, /*behArg*/ 0x02060000, /*beh*/ beh_door_warp
    warp_node /*id*/ 0x03, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x00, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x04, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x01, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x05, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x00, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x06, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x01, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x00, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x01, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x02, /*destLevel1*/ 0x09, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x03, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x04, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x05, /*destLevel1*/ 0x05, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x06, /*destLevel1*/ 0x18, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x07, /*destLevel1*/ 0x18, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x08, /*destLevel1*/ 0x18, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x09, /*destLevel1*/ 0x0C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x0A, /*destLevel1*/ 0x0C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x0B, /*destLevel1*/ 0x0C, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2013, 768, -2014, /*angle*/ 0, 0, 0, /*behArg*/ 0x000A0000, /*beh*/ beh_warp
    warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5513, 512, -4324, /*angle*/ 0, 0, 0, /*behArg*/ 0x300B0000, /*beh*/ beh_warp
    warp_node /*id*/ 0x0B, /*destLevel1*/ 0x11, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 1963, 819, 1280, /*angle*/ 0, 0, 0, /*behArg*/ 0x050C0000, /*beh*/ beh_warp
    warp_node /*id*/ 0x0C, /*destLevel1*/ 0x14, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    warp_node /*id*/ 0xF2, /*destLevel1*/ 0x1D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, 512, -650, /*angle*/ 0, 0, 0, /*behArg*/ 0x001E0000, /*beh*/ beh_warps_60
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, -50, 717, /*angle*/ 0, 180, 0, /*behArg*/ 0x001F0000, /*beh*/ beh_warps_60
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, 900, 717, /*angle*/ 0, 180, 0, /*behArg*/ 0x00200000, /*beh*/ beh_warps_64
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, 900, 717, /*angle*/ 0, 180, 0, /*behArg*/ 0x00210000, /*beh*/ beh_warps_84
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, 900, 717, /*angle*/ 0, 180, 0, /*behArg*/ 0x00220000, /*beh*/ beh_warps_68
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, 900, 717, /*angle*/ 0, 180, 0, /*behArg*/ 0x00230000, /*beh*/ beh_warps_70
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5513, 512, -4324, /*angle*/ 0, -135, 0, /*behArg*/ 0x00240000, /*beh*/ beh_warps_8C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5513, 512, -4324, /*angle*/ 0, -135, 0, /*behArg*/ 0x00250000, /*beh*/ beh_warps_90
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1024, 900, 717, /*angle*/ 0, 0, 0, /*behArg*/ 0x00260000, /*beh*/ beh_warps_88
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2816, 1200, -256, /*angle*/ 0, 90, 0, /*behArg*/ 0x00270000, /*beh*/ beh_warps_88
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2816, 1200, -256, /*angle*/ 0, 270, 0, /*behArg*/ 0x00280000, /*beh*/ beh_warps_70
    warp_node /*id*/ 0x1E, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x1E, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x1F, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x1F, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x20, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x20, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x21, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x21, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x22, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x22, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x23, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x23, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x24, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x24, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x25, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x25, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x26, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x26, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x27, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x27, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x28, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x28, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5422, 717, -461, /*angle*/ 0, 270, 0, /*behArg*/ 0x00320000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2304, 0, -4552, /*angle*/ 0, 180, 0, /*behArg*/ 0x00330000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 256, 102, -4706, /*angle*/ 0, 180, 0, /*behArg*/ 0x00340000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4501, 717, -230, /*angle*/ 0, 90, 0, /*behArg*/ 0x00350000, /*beh*/ beh_warps_7C
    warp_node /*id*/ 0x32, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x32, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x33, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x33, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x34, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x34, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x35, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x35, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5422, 717, -461, /*angle*/ 0, 270, 0, /*behArg*/ 0x00640000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2304, 0, -4552, /*angle*/ 0, 180, 0, /*behArg*/ 0x00650000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 256, 102, -4706, /*angle*/ 0, 180, 0, /*behArg*/ 0x00660000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4501, 717, -230, /*angle*/ 0, 90, 0, /*behArg*/ 0x00670000, /*beh*/ beh_warps_80
    warp_node /*id*/ 0x64, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x64, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x65, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x65, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x66, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x66, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x67, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x67, /*destLevel2*/ 0x00
    return

script_func_local_2:
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -1100, 512, 3021, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_door_warp
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -946, 512, 3021, /*angle*/ 0, 180, 0, /*behArg*/ 0x00010000, /*beh*/ beh_door_warp
    warp_node /*id*/ 0x00, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x01, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x04, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0xD1, /*pos*/ -281, 2253, 4762, /*angle*/ 0, 0, 0, /*behArg*/ 0x32000000, /*beh*/ beh_star_door
    object /*unk2*/ 0x1F, /*unk3*/ 0xD1, /*pos*/ -127, 2253, 4762, /*angle*/ 0, 180, 0, /*behArg*/ 0x32000000, /*beh*/ beh_star_door
    object /*unk2*/ 0x1F, /*unk3*/ 0xD6, /*pos*/ -281, 3174, 3772, /*angle*/ 0, 0, 0, /*behArg*/ 0x46000000, /*beh*/ beh_star_door
    object /*unk2*/ 0x1F, /*unk3*/ 0xD6, /*pos*/ -127, 3174, 3772, /*angle*/ 0, 180, 0, /*behArg*/ 0x46000000, /*beh*/ beh_star_door
    painting_warp_node /*id*/ 0x18, /*destLevel1*/ 0x0B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x19, /*destLevel1*/ 0x0B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x1A, /*destLevel1*/ 0x0B, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x1B, /*destLevel1*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x1C, /*destLevel1*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x1D, /*destLevel1*/ 0x0D, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x1E, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x1F, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x20, /*destLevel1*/ 0x24, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x21, /*destLevel1*/ 0x0E, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x22, /*destLevel1*/ 0x0E, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x23, /*destLevel1*/ 0x0E, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x24, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x25, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x26, /*destLevel1*/ 0x0A, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x27, /*destLevel1*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x28, /*destLevel1*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x29, /*destLevel1*/ 0x0D, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x2A, /*destLevel1*/ 0x0F, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3002, 2816, 5886, /*angle*/ 0, 0, 0, /*behArg*/ 0x0F0A0000, /*beh*/ beh_warp
    warp_node /*id*/ 0x0A, /*destLevel1*/ 0x1F, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -230, 4813, -3352, /*angle*/ 0, 0, 0, /*behArg*/ 0x0F0B0000, /*beh*/ beh_warp
    warp_node /*id*/ 0x0B, /*destLevel1*/ 0x15, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -659, 1613, -350, /*angle*/ 0, 180, 0, /*behArg*/ 0x00320000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4693, 2157, 1828, /*angle*/ 0, 270, 0, /*behArg*/ 0x00330000, /*beh*/ beh_warps_88
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -675, 1400, 3870, /*angle*/ 0, 0, 0, /*behArg*/ 0x00340000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -205, 2918, 7300, /*angle*/ 0, 0, 0, /*behArg*/ 0x00350000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3538, 1766, -400, /*angle*/ 0, 180, 0, /*behArg*/ 0x00360000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4693, 2157, 1828, /*angle*/ 0, 270, 0, /*behArg*/ 0x00370000, /*beh*/ beh_warps_88
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3002, 2816, 5886, /*angle*/ 0, 90, 0, /*behArg*/ 0x00380000, /*beh*/ beh_warps_8C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3412, 2816, 5886, /*angle*/ 0, 270, 0, /*behArg*/ 0x003A0000, /*beh*/ beh_warps_8C
    warp_node /*id*/ 0x32, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x32, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x33, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x33, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x34, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x34, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x35, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x35, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x36, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x36, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x37, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x37, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x38, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x38, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x3A, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x3A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -659, 1613, -350, /*angle*/ 0, 180, 0, /*behArg*/ 0x00640000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4693, 2157, 1828, /*angle*/ 0, 270, 0, /*behArg*/ 0x00650000, /*beh*/ beh_warps_70
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -675, 1400, 3870, /*angle*/ 0, 0, 0, /*behArg*/ 0x00660000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -205, 2918, 7300, /*angle*/ 0, 0, 0, /*behArg*/ 0x00670000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3538, 1766, -400, /*angle*/ 0, 180, 0, /*behArg*/ 0x00680000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -4693, 2157, 1828, /*angle*/ 0, 270, 0, /*behArg*/ 0x00690000, /*beh*/ beh_warps_70
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -230, 4813, -3352, /*angle*/ 0, 180, 0, /*behArg*/ 0x006B0000, /*beh*/ beh_warps_90
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -3412, 2816, 5886, /*angle*/ 0, 270, 0, /*behArg*/ 0x006C0000, /*beh*/ beh_warps_90
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3002, 2816, 5886, /*angle*/ 0, 90, 0, /*behArg*/ 0x006D0000, /*beh*/ beh_warps_90
    warp_node /*id*/ 0x64, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x64, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x65, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x65, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x66, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x66, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x67, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x67, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x68, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x68, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x69, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x69, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x6B, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x6B, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x6C, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x6C, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x6D, /*destLevel1*/ 0x06, /*destArea*/ 0x02, /*destNode*/ 0x6D, /*destLevel2*/ 0x00
    return

script_func_local_3:
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -1100, -1074, 922, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_door_warp
    object /*unk2*/ 0x1F, /*unk3*/ 0x25, /*pos*/ -946, -1074, 922, /*angle*/ 0, 180, 0, /*behArg*/ 0x00010000, /*beh*/ beh_door_warp
    warp_node /*id*/ 0x00, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x05, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x01, /*destLevel1*/ 0x06, /*destArea*/ 0x01, /*destNode*/ 0x06, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x02, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x02, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0xD0, /*pos*/ 307, -1074, 2074, /*angle*/ 0, 90, 0, /*behArg*/ 0x1E000000, /*beh*/ beh_star_door
    object /*unk2*/ 0x1F, /*unk3*/ 0xD0, /*pos*/ 307, -1074, 1920, /*angle*/ 0, 270, 0, /*behArg*/ 0x1E000000, /*beh*/ beh_star_door
    painting_warp_node /*id*/ 0x0C, /*destLevel1*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x0D, /*destLevel1*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x0E, /*destLevel1*/ 0x16, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x0F, /*destLevel1*/ 0x08, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x10, /*destLevel1*/ 0x08, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x11, /*destLevel1*/ 0x08, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x2A, /*destLevel1*/ 0x07, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x15, /*destLevel1*/ 0x17, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x16, /*destLevel1*/ 0x17, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    painting_warp_node /*id*/ 0x17, /*destLevel1*/ 0x17, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4147, -1280, 1997, /*angle*/ 0, 0, 0, /*behArg*/ 0x0F180000, /*beh*/ beh_warp
    warp_node /*id*/ 0x18, /*destLevel1*/ 0x13, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1382, -819, -4150, /*angle*/ 0, 180, 0, /*behArg*/ 0x00320000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2918, -870, -875, /*angle*/ 0, 0, 0, /*behArg*/ 0x00330000, /*beh*/ beh_warps_7C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2483, -1688, -2662, /*angle*/ 0, 270, 0, /*behArg*/ 0x00340000, /*beh*/ beh_warps_8C
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2381, -500, 2011, /*angle*/ 0, 90, 0, /*behArg*/ 0x00350000, /*beh*/ beh_warps_88
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4147, -1100, 1997, /*angle*/ 0, 90, 0, /*behArg*/ 0x00360000, /*beh*/ beh_warps_8C
    warp_node /*id*/ 0x32, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x32, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x33, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x33, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x34, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x34, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x35, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x35, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x36, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x36, /*destLevel2*/ 0x00
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -1382, -819, -4150, /*angle*/ 0, 180, 0, /*behArg*/ 0x00640000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -2918, -870, -875, /*angle*/ 0, 0, 0, /*behArg*/ 0x00650000, /*beh*/ beh_warps_80
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2483, -1688, -2662, /*angle*/ 0, 270, 0, /*behArg*/ 0x00660000, /*beh*/ beh_warps_90
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2381, -500, 2011, /*angle*/ 0, 90, 0, /*behArg*/ 0x00670000, /*beh*/ beh_warps_70
    object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 4147, -1100, 1997, /*angle*/ 0, 90, 0, /*behArg*/ 0x00680000, /*beh*/ beh_warps_90
    warp_node /*id*/ 0x64, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x64, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x65, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x65, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x66, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x66, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x67, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x67, /*destLevel2*/ 0x00
    warp_node /*id*/ 0x68, /*destLevel1*/ 0x06, /*destArea*/ 0x03, /*destNode*/ 0x68, /*destLevel2*/ 0x00
    return

script_func_local_4:
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -2037, -818, -716, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -1648, -818, -716, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -1648, -818, -101, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -1648, -818, 512, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -2037, -818, -101, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -2969, -921, 420, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -2037, -818, -1330, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -3839, -1023, -1422, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -1929, -818, -3615, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x90, /*pos*/ -834, -818, -3615, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x91, /*pos*/ -3317, -921, 1229, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x91, /*pos*/ -204, -921, -624, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    object /*unk2*/ 0x1F, /*unk3*/ 0x91, /*pos*/ -2876, -921, 1229, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_burning
    return

glabel level_castle_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_castle_segment_7SegmentRomStart, /*romEnd*/ _level_castle_segment_7SegmentRomEnd
    cmd1A     /*seg*/ 0x09, /*romStart*/ _inside_castle_textures_mio0SegmentRomStart, /*romEnd*/ _inside_castle_textures_mio0SegmentRomEnd
    load_mio0 /*seg*/ 0x06, /*romStart*/ _lakitu_toad_mips_boo_mio0SegmentRomStart, /*romEnd*/ _lakitu_toad_mips_boo_mio0SegmentRomEnd
    load_raw  /*seg*/ 0x0D, /*romStart*/ _lakitu_toad_mips_boo_geoSegmentRomStart,  /*romEnd*/ _lakitu_toad_mips_boo_geoSegmentRomEnd
    alloc_level_pool
    mario /*unk3*/ 0x01, /*behArg*/ 0x00000001, /*beh*/ beh_mario
    jump_link /*target*/ script_func_global_16
    cmd22 /*unk2*/ 0x0035, /*unk4*/ castle_geo_000F18
    cmd22 /*unk2*/ 0x0036, /*unk4*/ castle_geo_001940
    cmd22 /*unk2*/ 0x0037, /*unk4*/ castle_geo_001530
    cmd22 /*unk2*/ 0x0038, /*unk4*/ castle_geo_001548
    cmd22 /*unk2*/ 0x0039, /*unk4*/ castle_geo_001518
    cmd22 /*unk2*/ 0x0026, /*unk4*/ castle_door_geo
    cmd22 /*unk2*/ 0x0027, /*unk4*/ wooden_door_geo
    cmd22 /*unk2*/ 0x0029, /*unk4*/ metal_door_geo
    cmd22 /*unk2*/ 0x001C, /*unk4*/ castle_door_geo
    cmd22 /*unk2*/ 0x001D, /*unk4*/ wooden_door_geo
    cmd22 /*unk2*/ 0x0022, /*unk4*/ castle_door_0_star_geo
    cmd22 /*unk2*/ 0x0023, /*unk4*/ castle_door_1_star_geo
    cmd22 /*unk2*/ 0x0024, /*unk4*/ castle_door_3_stars_geo
    cmd22 /*unk2*/ 0x0025, /*unk4*/ locked_castle_door_geo
    cmd22 /*unk2*/ 0x00D0, /*unk4*/ castle_geo_000F00
    cmd22 /*unk2*/ 0x00D5, /*unk4*/ castle_geo_000F00
    cmd22 /*unk2*/ 0x00D1, /*unk4*/ castle_geo_000F00
    cmd22 /*unk2*/ 0x00D6, /*unk4*/ castle_geo_000F00

    area /*index*/ 1, /*geo*/ castle_geo_001400
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ -5513, 717, -4324, /*angle*/ 0, 45, 0, /*behArg*/ 0x00140000, /*beh*/ beh_castle_floor_trap
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2477, 307, -2000, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_fish_group
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2774, 507, -1716, /*angle*/ 0, 90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tank_fish_groups
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3672, 507, -1307, /*angle*/ 0, 45, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tank_fish_groups
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 3748, 507, 773, /*angle*/ 0, -45, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tank_fish_groups
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 2778, 507, 1255, /*angle*/ 0, -90, 0, /*behArg*/ 0x00000000, /*beh*/ beh_tank_fish_groups
        object /*unk2*/ 0x1F, /*unk3*/ 0x65, /*pos*/ -1000, 50, -3500, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_boo_in_castle
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ -1671, 0, 1313, /*angle*/ 0, 83, 0, /*behArg*/ 0x85000000, /*beh*/ beh_toad_message
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ 1524, 307, 458, /*angle*/ 0, 110, 0, /*behArg*/ 0x86000000, /*beh*/ beh_toad_message
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ 596, -306, -2637, /*angle*/ 0, 152, 0, /*behArg*/ 0x87000000, /*beh*/ beh_toad_message
        jump_link /*target*/ script_func_local_1
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
        terrain /*terrainData*/ inside_castle_seg7_area_1_collision
        rooms /*surfaceRooms*/ inside_castle_seg7_area_1_rooms
        cmd39 /*unk4*/ inside_castle_seg7_area_1_macro_objs
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0004
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 2, /*geo*/ castle_geo_001858
        object /*unk2*/ 0x1F, /*unk3*/ 0x37, /*pos*/ -205, 2918, 7222, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_clock_big_arm
        object /*unk2*/ 0x1F, /*unk3*/ 0x38, /*pos*/ -205, 2918, 7222, /*angle*/ 0, 180, 0, /*behArg*/ 0x00000000, /*beh*/ beh_rotating_small_clock_arm
        object /*unk2*/ 0x1F, /*unk3*/ 0x39, /*pos*/ -205, 2611, 7140, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_oscillating_pendulum
        object /*unk2*/ 0x1F, /*unk3*/ 0x66, /*pos*/ 4231, 1408, 1601, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_lakitu
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ -977, 1203, 2569, /*angle*/ 0, 0, 0, /*behArg*/ 0x4C000000, /*beh*/ beh_toad_message
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ -1584, 2253, 7157, /*angle*/ 0, 136, 0, /*behArg*/ 0x53000000, /*beh*/ beh_toad_message
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ 837, 1203, 3020, /*angle*/ 0, 180, 0, /*behArg*/ 0x89000000, /*beh*/ beh_toad_message
        jump_link /*target*/ script_func_local_2
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
        terrain /*terrainData*/ inside_castle_seg7_area_2_collision
        rooms /*surfaceRooms*/ inside_castle_seg7_area_2_rooms
        cmd39 /*unk4*/ inside_castle_seg7_area_2_macro_objs
        instant_warp /*index*/ 0, /*destArea*/ 2, /*displace*/ 0, -205, 410
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0004
        terrain_type /*terrainType*/ 0x0001
    end_area

    area /*index*/ 3, /*geo*/ castle_geo_001C10
        object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 7066, -1178, -819, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_pillar
        object /*unk2*/ 0x1F, /*unk3*/ 0x36, /*pos*/ 7066, -1178, -205, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_water_level_pillar
        object /*unk2*/ 0x1F, /*unk3*/ 0x00, /*pos*/ 0, 0, 0, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_ddd_warp
        object /*unk2*/ 0x1F, /*unk3*/ 0x64, /*pos*/ -1509, -1177, -1564, /*angle*/ 0, 0, 0, /*behArg*/ 0x00000000, /*beh*/ beh_mips
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ 1787, -1381, -1957, /*angle*/ 0, 126, 0, /*behArg*/ 0x52000000, /*beh*/ beh_toad_message
        object /*unk2*/ 0x1F, /*unk3*/ 0xDD, /*pos*/ -4048, -1381, -1334, /*angle*/ 0, 30, 0, /*behArg*/ 0x88000000, /*beh*/ beh_toad_message
        jump_link /*target*/ script_func_local_3
        jump_link /*target*/ script_func_local_4
        warp_node /*id*/ 0xF1, /*destLevel1*/ 0x10, /*destArea*/ 0x01, /*destNode*/ 0x03, /*destLevel2*/ 0x00
        terrain /*terrainData*/ inside_castle_seg7_area_3_collision
        rooms /*surfaceRooms*/ inside_castle_seg7_area_3_rooms
        cmd39 /*unk4*/ inside_castle_seg7_area_3_macro_objs
        set_music /*unk2*/ 0x0001, /*seq*/ 0x0004
        terrain_type /*terrainType*/ 0x0001
    end_area

    free_level_pool
    mario_pos /*area*/ 1, /*yaw*/ 180, /*pos*/ -1023, 0, 1152
    call /*arg*/ 0, /*func*/ lvl_init_or_update
    call_loop /*arg*/ 1, /*func*/ lvl_init_or_update
    clear_level
    sleep_before_exit /*frames*/ 1
    exit

.align 4
.include "levels/geo/level_castle.s"
.align 4
