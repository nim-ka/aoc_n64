# Power Meter HUD

power_meter_seg3_texture_030233E0: # 0x030233E0
.incbin "actors/power_meter/0.rgba16"

power_meter_seg3_texture_030243E0: # 0x030243E0
.incbin "actors/power_meter/1.rgba16"

power_meter_seg3_texture_030253E0: # 0x030253E0
.incbin "actors/power_meter/2.rgba16"

power_meter_seg3_texture_03025BE0: # 0x03025BE0
.incbin "actors/power_meter/3.rgba16"

power_meter_seg3_texture_030263E0: # 0x030263E0
.incbin "actors/power_meter/4.rgba16"

power_meter_seg3_texture_03026BE0: # 0x03026BE0
.incbin "actors/power_meter/5.rgba16"

power_meter_seg3_texture_030273E0: # 0x030273E0
.incbin "actors/power_meter/6.rgba16"

power_meter_seg3_texture_03027BE0: # 0x03027BE0
.incbin "actors/power_meter/7.rgba16"

power_meter_seg3_texture_030283E0: # 0x030283E0
.incbin "actors/power_meter/8.rgba16"

power_meter_seg3_texture_03028BE0: # 0x03028BE0
.incbin "actors/power_meter/9.rgba16"

glabel power_meter_seg3_health_icons_030293E0 # 0x030293E0
.word power_meter_seg3_texture_03028BE0
.word power_meter_seg3_texture_030283E0
.word power_meter_seg3_texture_03027BE0
.word power_meter_seg3_texture_030273E0
.word power_meter_seg3_texture_03026BE0
.word power_meter_seg3_texture_030263E0
.word power_meter_seg3_texture_03025BE0
.word power_meter_seg3_texture_030253E0

power_meter_seg3_vertex_03029400: # 0x03029400
vertex    -32,    -32,      0,      0,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,    -32,      0,    992,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,     32,      0,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -32,     32,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,    -32,      0,      1,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex     32,    -32,      0,   1024,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex     32,     32,      0,   1024,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,     32,      0,      1,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel power_meter_seg3_dl_03029480 # 0x03029480 - 0x03029530
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x0F0A7008
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, 0x00000000
gsSPTexture -1, -1, 0, 0, 1
gsSPVertex power_meter_seg3_vertex_03029400, 8, 0
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 252
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, power_meter_seg3_texture_030233E0
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, power_meter_seg3_texture_030243E0
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSPEndDisplayList

power_meter_seg3_vertex_03029530: # 0x03029530
vertex    -16,    -16,      0,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     15,    -16,      0,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     15,     16,      0,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -16,     16,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel power_meter_seg3_dl_03029570 # 0x03029570 - 0x030295A0
gsDPPipeSync
gsSPVertex power_meter_seg3_vertex_03029530, 4, 0
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPEndDisplayList

glabel power_meter_seg3_dl_030295A0 # 0x030295A0 - 0x030295D8
gsDPPipeSync
gsSPTexture -1, -1, 0, 0, 0
gsSPSetGeometryMode G_LIGHTING
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x0F0A4000
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, 0x00002000
gsSPEndDisplayList

binid
