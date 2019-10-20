# Assembly Macros

.set NULL, 0
.set FALSE, 0
.set TRUE, 1

.set K0BASE, 0x80000000
.set K1BASE, 0xA0000000
.set K2BASE, 0xC0000000
.set SCREEN_WIDTH, 320
.set SCREEN_HEIGHT, 240
.set PTR_WIDTH, 4

.macro glabel label
    .global \label
    .balign 4
    \label:
.endm

.macro .word32 x
    .word \x
.endm
