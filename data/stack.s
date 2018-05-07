.include "macros.inc"

.section .stack

glabel D_801C1000
    .space 0xD000
glabel D_801CE000
    .space 0x31200
glabel D_801FF200
.ifdef VERSION_US
    .space 0x1400
.else
    .space 0x1800
.endif
glabel D_80200A00
    .space 0x800
glabel D_80201200
    .space 0x2000
glabel D_80203200
    .space 0x2000
glabel D_80205200
    .space 0x2000
glabel D_80207200
    .space 0x890
glabel D_80207A90
    .space 0x8
glabel D_80207A98
    .space 0x4
glabel D_80207A9C
    .space 0x64
glabel gSaveBuffer
    .space 0x8
glabel D_80207B08
    .space 0x4
glabel D_80207B0C
    .space 0x19
glabel D_80207B25
    .space 0x19B
glabel D_80207CC0
    .space 0x40
glabel D_80207D00
    .space 0x400
glabel D_80208100
    .space 0x19098
glabel D_80221198
    .space 0x8
glabel D_802211A0
    .space 0x10
glabel D_802211B0
    .space 0x1
glabel D_802211B1
    .space 0xEF
glabel D_802212A0
    .space 0x2
glabel D_802212A2
    .space 0x1
glabel D_802212A3
    .space 0x5
glabel D_802212A8
    .space 0x8
glabel D_802212B0
    .space 0x8
glabel D_802212B8
    .space 0x10
glabel D_802212C8
    .space 0x30
glabel D_802212F8
    .space 0x10
glabel D_80221308
    .space 0x10
glabel D_80221318
    .space 0x10
glabel D_80221328
    .space 0x4
glabel D_8022132C
    .space 0x190
glabel D_802214BC
    .space 0x4
glabel D_802214C0
    .space 0x38
glabel D_802214F8
    .space 0x4
glabel D_802214FC
    .space 0x190
glabel D_8022168C
    .space 0x4
glabel D_80221690
    .space 0x38
glabel D_802216C8
    .space 0x4
glabel D_802216CC
    .space 0x190
glabel D_8022185C
    .space 0x4
glabel D_80221860
    .space 0x38
glabel D_80221898
    .space 0x10
glabel D_802218A8
    .space 0x8
glabel D_802218B0
    .space 0x10
glabel D_802218C0
    .space 0x10
glabel D_802218D0
    .space 0x40
glabel D_80221910
    .space 0x100
glabel D_80221A10
    .space 0x1000
glabel D_80222A10
    .space 0x8
glabel D_80222A18
    .space 0x1
glabel D_80222A19
    .space 0x1
glabel D_80222A1A
    .space 0x16
glabel D_80222A30
    .space 0x14
glabel D_80222A44
    .space 0x64
glabel D_80222AA8
    .space 0x21C
glabel D_80222CC4
    .space 0x114
glabel D_80222DD8
    .space 0x1800
glabel D_802245D8
    .space 0x70
glabel D_80224648
    .space 0x1790
glabel D_80225DD8
    .space 0xC0
glabel D_80225E98
    .space 0x10
glabel D_80225EA8
    .space 0x4
glabel D_80225EAC
    .space 0xC
glabel D_80225EB8
    .space 0x10
glabel D_80225EC8
    .space 0x10
glabel D_80225ED8
    .space 0x10
glabel D_80225EE8
    .space 0x18
glabel D_80225F00
    .space 0x100
glabel D_80226000
    .space 0x500
glabel D_80226500
    .space 0x18
glabel D_80226518
    .space 0x8
glabel D_80226520
    .space 0x18
glabel D_80226538
    .space 0x600
glabel D_80226B38
    .space 0x4
glabel D_80226B3C
    .space 0x4
glabel D_80226B40
    .space 0x8
glabel D_80226B48
    .space 0x100
glabel D_80226C48
    .space 0x100
glabel D_80226D48
    .space 0x1
glabel D_80226D49
    .space 0x1
glabel D_80226D4A
    .space 0x1
glabel D_80226D4B
    .space 0x1
glabel D_80226D4C
    .space 0x4
glabel D_80226D50
    .space 0x4
glabel D_80226D54
    .space 0x4
glabel D_80226D58
    .space 0x4
glabel D_80226D5C
    .space 0x4
glabel D_80226D60
    .space 0x4
glabel D_80226D64
    .space 0x4
glabel D_80226D68
    .space 0x4
glabel D_80226D6C
    .space 0x4
glabel D_80226D70
    .space 0x4
glabel D_80226D74
    .space 0x4
glabel D_80226D78
    .space 0x4
glabel D_80226D7C
    .space 0x2
glabel D_80226D7E
    .space 0x1
glabel D_80226D7F
    .space 0x1
glabel D_80226D80
    .space 0x4
glabel D_80226D84
    .space 0x4
glabel D_80226D88
    .space 0x4
glabel D_80226D8C
    .space 0x4
glabel D_80226D90
    .space 0x8
glabel D_80226D98
    .space 0x4
glabel D_80226D9C
    .space 0x4
glabel D_80226DA0
    .space 0xA0
glabel D_80226E40
    .space 0xC
glabel D_80226E4C
    .space 0x6
glabel D_80226E52
    .space 0x6
glabel D_80226E58
    .space 0x40
glabel D_80226E98
    .space 0x20
glabel D_80226EB8
    .space 0x8
glabel D_80226EC0
    .space 0x140
glabel D_80227000
    .space 0x1F000
