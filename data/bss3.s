.include "macros.inc"


.section .bss

glabel sTargetWeightID
    .space 0x4
glabel D_801BA964
    .space 0x4
glabel D_801BA968
    .space 0x4
glabel D_801BA96C
    .space 0x4
glabel D_801BA970
    .space 0x4
glabel D_801BA974
    .space 0x4
glabel D_801BA978
    .space 0x4
glabel D_801BA97C
    .space 0x4
glabel D_801BA980
    .space 0x8
glabel D_801BA988
    .space 0x28
glabel D_801BA9B0
    .space 0x4
glabel D_801BA9B4
    .space 0x4
glabel D_801BA9B8
    .space 0x70
glabel D_801BAA28
    .space 0x8
glabel D_801BAA30
    .space 0x28
glabel D_801BAA58
    .space 0x4
glabel D_801BAA5C
    .space 0x4
glabel D_801BAA60
    .space 0x70
glabel D_801BAAD0
    .space 0x4
glabel D_801BAAD4
    .space 0x4
glabel D_801BAAD8
    .space 0x8
glabel D_801BAAE0
    .space 0x4
glabel D_801BAAE4
    .space 0x4
glabel D_801BAAE8
    .space 0x8
glabel gGdSkinNet
    .space 0x4
glabel D_801BAAF4
    .space 0x4
glabel D_801BAAF8
    .space 0x34
glabel sCubeShapeGroup
    .space 0x10
glabel sCubeShape
    .space 0xC
glabel sGdLineBuf # D_801BAB48; char[0xFF + 1]
    .space 0x100
glabel sGdLineBufCsr # D_801BAC48
    .space 0x4
glabel sGdShapeFile # D_801BAC4C
    .space 0x4
glabel sGdShapeListHead
    .space 0x4
glabel sGdShapeCount
    .space 0xC
glabel D_801BAC60 #MyVec3f
    .space 0x4
glabel D_801BAC64
    .space 0x4
glabel D_801BAC68
    .space 0xC
glabel D_801BAC74
    .space 0x4
glabel D_801BAC78
    .space 0x24
glabel D_801BAC9C
    .space 0x4
glabel D_801BACA0
    .space 0x18
glabel D_801BACB8
    .space 0x4
glabel D_801BACBC
    .space 0x4
glabel D_801BACC0
    .space 0x8
glabel D_801BACC8
    .space 0x4
glabel D_801BACCC
    .space 0x4
glabel D_801BACD0
    .space 0x38
glabel D_801BAD08
    .space 0x28
glabel D_801BAD30
    .space 0x4
glabel D_801BAD34
    .space 0x4
glabel D_801BAD38
    .space 0x128
glabel D_801BAE60
    .space 0x10
glabel D_801BAE70
    .space 0x18
glabel D_801BAE88
    .space 0x18
glabel D_801BAEA0
    .space 0x8
glabel D_801BAEA8
    .space 0x80
glabel D_801BAF28
    .space 0x8
glabel D_801BAF30
    .space 0xDC
glabel D_801BB00C
    .space 0x4
glabel D_801BB010
    .space 0x8
glabel D_801BB018
    .space 0x4
glabel D_801BB01C
    .space 0x4
glabel D_801BB020
    .space 0x40
glabel D_801BB060
    .space 0x40
glabel D_801BB0A0
    .space 0x4
glabel D_801BB0A4
    .space 0x4
glabel D_801BB0A8
    .space 0x4
glabel D_801BB0AC
    .space 0x4
glabel D_801BB0B0
    .space 0x4
glabel D_801BB0B4
    .space 0x4
glabel D_801BB0B8
    .space 0x4
glabel D_801BB0BC
    .space 0x4
glabel D_801BB0C0
    .space 0x4
glabel D_801BB0C4
    .space 0x4
glabel D_801BB0C8
    .space 0x4
glabel D_801BB0CC
    .space 0x4
glabel D_801BB0D0
    .space 0x4
glabel D_801BB0D4
    .space 0x4
glabel D_801BB0D8
    .space 0x8
glabel D_801BB0E0
    .space 0x8
glabel D_801BB0E8
    .space 0x4
glabel D_801BB0EC
    .space 0x4
glabel D_801BB0F0
    .space 0x10
glabel D_801BB100
    .space 0x40
glabel D_801BB140
    .space 0x40
glabel D_801BB180
    .space 0x4
glabel D_801BB184
    .space 0x4
glabel D_801BB188
    .space 0x8
glabel D_801BB190
    .space 0x4
glabel D_801BB194
    .space 0x4
glabel D_801BB198
    .space 0x8
glabel D_801BB1A0
    .space 0x4
glabel D_801BB1A4
    .space 0x4
glabel D_801BB1A8
    .space 0x10
glabel D_801BB1B8
    .space 0x3
glabel D_801BB1BB
    .space 0x1
glabel D_801BB1BC
    .space 0x3
glabel D_801BB1BF
    .space 0x1
glabel D_801BB1C0
    .space 0x3
glabel D_801BB1C3
    .space 0xD
glabel D_801BB1D0
    .space 0x8
glabel D_801BB1D8
    .space 0x2580
glabel D_801BD758
    .space 0x4
glabel D_801BD75C
    .space 0x4
glabel D_801BD760
    .space 0x8
glabel D_801BD768
    .space 0x4
glabel D_801BD76C
    .space 0x4
glabel D_801BD770
    .space 0x4
glabel D_801BD774
    .space 0x4
glabel D_801BD778
    .space 0x24
glabel D_801BD79C
    .space 0x4
glabel D_801BD7A0
    .space 0x8
glabel D_801BD7A8
    .space 0x8
glabel D_801BD7B0
    .space 0x8
glabel D_801BD7B8
    .space 0x8
glabel D_801BD7C0
    .space 0x8
glabel D_801BD7C8
    .space 0x4
glabel D_801BD7CC
    .space 0x14
glabel D_801BD7E0
    .space 0xFA0
glabel D_801BE780
    .space 0x4
glabel D_801BE784
    .space 0x4
glabel D_801BE788
    .space 0x8
glabel D_801BE790
    .space 0x40
glabel D_801BE7D0
    .space 0x60
glabel D_801BE830
    .space 0x18
glabel D_801BE848
    .space 0x68
glabel D_801BE8B0
    .space 0x8
glabel D_801BE8B8
    .space 0x8
glabel D_801BE8C0
    .space 0x8
glabel D_801BE8C8
    .space 0x7C
glabel D_801BE944
    .space 0x38
glabel D_801BE97C
    .space 0x4
glabel D_801BE980
    .space 0x14
glabel D_801BE994
    .space 0x4
