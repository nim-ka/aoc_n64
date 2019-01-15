.include "macros.inc"
.include "ultra64/gbi.inc"

.section .rodata

.balign 8
glabel textureHandOpen # 0x801A8730
   .incbin "bin/intro_raw/hand_open.rgba16"

#! stray EndDisplayList
gsSPEndDisplayList

.balign 8
glabel textureHandClosed # 0x801A8F38
   .incbin "bin/intro_raw/hand_closed.rgba16"
texture_red_star_0:
   .incbin "bin/intro_raw/red_star_0.rgba16"
texture_red_star_1:
   .incbin "bin/intro_raw/red_star_1.rgba16"
texture_red_star_2:
   .incbin "bin/intro_raw/red_star_2.rgba16"
texture_red_star_3:
   .incbin "bin/intro_raw/red_star_3.rgba16"
texture_red_star_4:
   .incbin "bin/intro_raw/red_star_4.rgba16"
texture_red_star_5:
   .incbin "bin/intro_raw/red_star_5.rgba16"
texture_red_star_6:
   .incbin "bin/intro_raw/red_star_6.rgba16"
texture_red_star_7:
   .incbin "bin/intro_raw/red_star_7.rgba16"
texture_white_star_0:
   .incbin "bin/intro_raw/white_star_0.rgba16"
texture_white_star_1:
   .incbin "bin/intro_raw/white_star_1.rgba16"
texture_white_star_2:
   .incbin "bin/intro_raw/white_star_2.rgba16"
texture_white_star_3:
   .incbin "bin/intro_raw/white_star_3.rgba16"
texture_white_star_4:
   .incbin "bin/intro_raw/white_star_4.rgba16"
texture_white_star_5:
   .incbin "bin/intro_raw/white_star_5.rgba16"
texture_white_star_6:
   .incbin "bin/intro_raw/white_star_6.rgba16"
texture_white_star_7:
   .incbin "bin/intro_raw/white_star_7.rgba16"

star_vertex_801B1738:
   vertex    -64,      0,      0,      0,    992,  0x00, 0x00, 0x7F, 0x00
   vertex     64,      0,      0,    992,    992,  0x00, 0x00, 0x7F, 0x00
   vertex     64,    128,      0,    992,      0,  0x00, 0x00, 0x7F, 0x00
   vertex    -64,    128,      0,      0,      0,  0x00, 0x00, 0x7F, 0x00

D_vertex_801B1778: #! no references to these vertices
   vertex  16384,      0,      0,      0,  16384,  0x00, 0x00, 0x00, 0x00
   vertex      0,      0,  16384,      0,      0,  0x00, 0x00, 0x40, 0x00
   vertex      0,      0,      0,      0,      0,  0x00, 0x00, 0x00, 0x00
   vertex      0,      0,      0,      0,      0,  0x00, 0x00, 0x00, 0x00

star_dl_common:
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPClearGeometryMode 0x000C0000
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00443078
gsSPTexture -1, -1, 0, 0, 1
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPVertex star_vertex_801B1738, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPTexture -1, -1, 0, 0, 0
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00442478
gsSPEndDisplayList

red_star_dl_801B1838:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_0
gsSPBranchList star_dl_common

red_star_dl_801B1850:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_1
gsSPBranchList star_dl_common

red_star_dl_801B1868:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_2
gsSPBranchList star_dl_common

red_star_dl_801B1880:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_3
gsSPBranchList star_dl_common

red_star_dl_801B1898:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_4
gsSPBranchList star_dl_common

red_star_dl_801B18B0:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_5
gsSPBranchList star_dl_common

red_star_dl_801B18C8:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_6
gsSPBranchList star_dl_common

red_star_dl_801B18E0:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_7
gsSPBranchList star_dl_common

white_star_dl_801B18F8:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_0
gsSPBranchList star_dl_common

white_star_dl_801B1910:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_1
gsSPBranchList star_dl_common

white_star_dl_801B1928:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_2
gsSPBranchList star_dl_common

white_star_dl_801B1940:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_3
gsSPBranchList star_dl_common

white_star_dl_801B1958:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_4
gsSPBranchList star_dl_common

white_star_dl_801B1970:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_5
gsSPBranchList star_dl_common

white_star_dl_801B1988:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_6
gsSPBranchList star_dl_common

white_star_dl_801B19A0:
gsDPPipeSync
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_7
gsSPBranchList star_dl_common

glabel redStarDlArray # 0x801B19B8
   .word red_star_dl_801B1838
   .word red_star_dl_801B1838
   .word red_star_dl_801B1850
   .word red_star_dl_801B1850
   .word red_star_dl_801B1868
   .word red_star_dl_801B1868
   .word red_star_dl_801B1880
   .word red_star_dl_801B1880
   .word red_star_dl_801B1898
   .word red_star_dl_801B1898
   .word red_star_dl_801B18B0
   .word red_star_dl_801B18B0
   .word red_star_dl_801B18C8
   .word red_star_dl_801B18C8
   .word red_star_dl_801B18E0
   .word red_star_dl_801B18E0

glabel whiteStarDlArray # 0x801B19F8
   .word white_star_dl_801B18F8
   .word white_star_dl_801B18F8
   .word white_star_dl_801B1910
   .word white_star_dl_801B1910
   .word white_star_dl_801B1928
   .word white_star_dl_801B1928
   .word white_star_dl_801B1940
   .word white_star_dl_801B1940
   .word white_star_dl_801B1958
   .word white_star_dl_801B1958
   .word white_star_dl_801B1970
   .word white_star_dl_801B1970
   .word white_star_dl_801B1988
   .word white_star_dl_801B1988
   .word white_star_dl_801B19A0
   .word white_star_dl_801B19A0

texture_sparkle_0:
   .incbin "bin/intro_raw/sparkle_0.rgba16"
texture_sparkle_1:
   .incbin "bin/intro_raw/sparkle_1.rgba16"
texture_sparkle_2:
   .incbin "bin/intro_raw/sparkle_2.rgba16"
texture_sparkle_3:
   .incbin "bin/intro_raw/sparkle_3.rgba16"
texture_sparkle_4:
   .incbin "bin/intro_raw/sparkle_4.rgba16"
texture_sparkle_5: #! no references to this texture 0x801B4238
   .incbin "bin/intro_raw/sparkle_5.rgba16"

sparkle_vertex_801B4A38:
   vertex    -32,      0,      0,      0,   1984,  0x00, 0x00, 0x7F, 0x00
   vertex     32,      0,      0,   1984,   1984,  0x00, 0x00, 0x7F, 0x00
   vertex     32,     64,      0,   1984,      0,  0x00, 0x00, 0x7F, 0x00
   vertex    -32,     64,      0,      0,      0,  0x00, 0x00, 0x7F, 0x00

sparkle_dl_common: # 0x801B4A78
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_PRIMITIVE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_PRIMITIVE, G_ACMUX_0, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_PRIMITIVE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_PRIMITIVE, G_ACMUX_0
gsSPClearGeometryMode 0x000C0000
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00443078
gsSPTexture -32768, -32768, 0, 0, 1
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPVertex sparkle_vertex_801B4A38, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPTexture 1, 1, 0, 0, 0
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00442478
gsSPEndDisplayList

red_dl_801B4AF8:
gsDPSetPrimColor 0, 0, 0xFF, 0x00, 0x00, 0xFF
gsSPEndDisplayList

white_dl_801B4B08:
gsDPSetPrimColor 0, 0, 0xFF, 0xFF, 0xFF, 0xFF
gsSPEndDisplayList

sparkle_dl_801B4B18:
gsDPPipeSync
gsSPDisplayList red_dl_801B4AF8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_0
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4B38:
gsDPPipeSync
gsSPDisplayList red_dl_801B4AF8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_1
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4B58:
gsDPPipeSync
gsSPDisplayList red_dl_801B4AF8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_2
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4B78:
gsDPPipeSync
gsSPDisplayList red_dl_801B4AF8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_3
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4B98:
gsDPPipeSync
gsSPDisplayList red_dl_801B4AF8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4BB8:
gsDPPipeSync
gsSPDisplayList red_dl_801B4AF8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4BD8:
gsDPPipeSync
gsSPDisplayList white_dl_801B4B08
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_0
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4BF8:
gsDPPipeSync
gsSPDisplayList white_dl_801B4B08
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_1
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4C18:
gsDPPipeSync
gsSPDisplayList white_dl_801B4B08
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_2
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4C38:
gsDPPipeSync
gsSPDisplayList white_dl_801B4B08
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_3
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4C58:
gsDPPipeSync
gsSPDisplayList white_dl_801B4B08
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4
gsSPBranchList sparkle_dl_common

sparkle_dl_801B4C78:
gsDPPipeSync
gsSPDisplayList white_dl_801B4B08
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4
gsSPBranchList sparkle_dl_common

glabel redSparkleDlArray # 0x801B4C98
   .word sparkle_dl_801B4B98
   .word sparkle_dl_801B4B98
   .word sparkle_dl_801B4B78
   .word sparkle_dl_801B4B78
   .word sparkle_dl_801B4B58
   .word sparkle_dl_801B4B58
   .word sparkle_dl_801B4B38
   .word sparkle_dl_801B4B38
   .word sparkle_dl_801B4B18
   .word sparkle_dl_801B4B18
   .word sparkle_dl_801B4BB8
   .word sparkle_dl_801B4BB8

glabel whiteSparkleDlArray # 0x801B4CC8
   .word sparkle_dl_801B4C58
   .word sparkle_dl_801B4C58
   .word sparkle_dl_801B4C38
   .word sparkle_dl_801B4C38
   .word sparkle_dl_801B4C18
   .word sparkle_dl_801B4C18
   .word sparkle_dl_801B4BF8
   .word sparkle_dl_801B4BF8
   .word sparkle_dl_801B4BD8
   .word sparkle_dl_801B4BD8
   .word sparkle_dl_801B4C78
   .word sparkle_dl_801B4C78

#! stray EndDisplayList
gsSPEndDisplayList

texture_mario_face_shine: # 0x801B4D00
   .incbin "bin/intro_raw/mario_face_shine.ia8"

glabel marioHeadDl801B5100
gsSPSetGeometryMode G_TEXTURE_GEN
gsSPTexture 1984, 1984, 0, 0, 1
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, 0x00080000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, 0x00002000
gsDPSetCombineMode G_CCMUX_PRIMITIVE, G_CCMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_SHADE, G_ACMUX_PRIMITIVE, G_ACMUX_SHADE, G_ACMUX_TEXEL0, G_ACMUX_SHADE, G_CCMUX_PRIMITIVE, G_CCMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_SHADE, G_ACMUX_PRIMITIVE, G_ACMUX_SHADE, G_ACMUX_TEXEL0, G_ACMUX_SHADE
gsDPSetTextureImage G_IM_FMT_IA, G_IM_SIZ_16b, 1, texture_mario_face_shine
gsDPSetTile G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x1FF, 0x200
gsDPPipeSync
gsDPSetTile G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsDPPipeSync
gsSPEndDisplayList

glabel marioHeadDl801B5170
gsSPClearGeometryMode 0xFFFFFFFF
gsSPSetGeometryMode G_SHADING_SMOOTH | G_SHADE
gsSPEndDisplayList

glabel marioHeadDl801B5188
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, 0x00080000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, 0x00002000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, 0x00000C00
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x0F0A4000
gsDPNoOp
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, 0x00000000
gsDPPipeSync
gsSPEndDisplayList

   .word 0

glabel D_801B520C
   .float 1.0

   .word 0
   .word 0

#! no references to display list
gsDPPipeSync
gsSPEndDisplayList

vertex_801B5228:
vertex -8,  8,  0,  0,  0,  0x00, 0x00, 0x00, 0xFF
vertex  8, -2,  0,  0,  0,  0x00, 0x00, 0x00, 0xFF
vertex  2, -8,  0,  0,  0,  0x00, 0x00, 0x00, 0xFF

vertex_801B5258:
vertex -6,  6,  0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF
vertex  7, -3,  0,  0,  0,  0xFF, 0x00, 0x00, 0xFF
vertex  3, -7,  0,  0,  0,  0xFF, 0x00, 0x00, 0xFF

glabel dl_801B5288 #! no references to display list
gsDPPipeSync
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x0F0A4000
gsSPClearGeometryMode 0xFFFFFFFF
gsSPSetGeometryMode G_SHADING_SMOOTH | G_SHADE
gsDPPipeSync
gsSPVertex vertex_801B5228, 3, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSPVertex vertex_801B5258, 3, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSPEndDisplayList

glabel marioHeadDl801B52D8
gsDPPipeSync
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, 0x00000000
gsSPTexture -32768, -32768, 0, 0, 1
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, 0x00000001
gsDPSetBlendColor 0, 0, 0, 1
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00443078
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, 0x00002000
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, 0x00000000
gsSPEndDisplayList
