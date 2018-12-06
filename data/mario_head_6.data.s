.include "macros.inc"
.include "ultra64/gbi.inc"

.section .data

# head_6 start? 
   .word 0

glabel D_801A8674
   .word 0
   .word 0

glabel D_801A867C
   .word 0

glabel D_801A8680
   .word 0

glabel D_801A8684
   .word 0

glabel D_801A8688
   .word 0

glabel D_801A868C
   .word 0

glabel D_801A8690
   .word 0

glabel D_801A8694
   .float 1.0

glabel D_801A8698
   .word 1

glabel D_801A869C
   .word 0

glabel D_801A86A0
   .word 0

glabel D_801A86A4
   .word 0

glabel D_801A86A8
   .word 0

glabel D_801A86AC
   .word 0

glabel D_801A86B0
   .word 0
   .word 0

glabel D_801A86B8
   .word 0

glabel D_801A86BC
   .word 1

glabel D_801A86C0
   .word 0
   .word 10

glabel D_801A86C8
   .word 1

glabel D_801A86CC
   .float 1.0

glabel D_801A86D0
   .float 1.0

glabel D_801A86D4
   .float 1.0

glabel D_801A86D8
   .word 0

glabel D_801A86DC
   .word 0

glabel D_801A86E0
   .word 0

glabel D_801A86E4
   .word 0

glabel D_801A86E8
   .word 0

glabel D_801A86EC
   .word 0

glabel D_801A86F0
   .word 0

glabel D_801A86F4
   .word 0
   .word 0

glabel D_801A86FC
   .word 0

glabel D_801A8700
   .word 0

glabel D_801A8704
   .word  3, dynlist_04000000
   .word  3, dynlist_04000650
   .word  3, dynlist_04004F90
   .word -1, 0x00000000

.balign 8
# It doesn't really make sense for this DL command to be here,
# unless all of goddard's texture data were also in C... 
#! stray EndDisplayList @ 801A8728
gsSPEndDisplayList
