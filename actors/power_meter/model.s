# Power Meter HUD

.word 0, 0

texture_power_meter_left_side: # 0x030233E0
.incbin "actors/power_meter/power_meter_left_side.rgba16"

texture_power_meter_right_side: # 0x030243E0
.incbin "actors/power_meter/power_meter_right_side.rgba16"

texture_power_meter_full: # 0x030253E0
.incbin "actors/power_meter/power_meter_full.rgba16"

texture_power_meter_seven_segments: # 0x03025BE0
.incbin "actors/power_meter/power_meter_seven_segments.rgba16"

texture_power_meter_six_segments: # 0x030263E0
.incbin "actors/power_meter/power_meter_six_segments.rgba16"

texture_power_meter_five_segments: # 0x03026BE0
.incbin "actors/power_meter/power_meter_five_segments.rgba16"

texture_power_meter_four_segments: # 0x030273E0
.incbin "actors/power_meter/power_meter_four_segments.rgba16"

texture_power_meter_three_segments: # 0x03027BE0
.incbin "actors/power_meter/power_meter_three_segments.rgba16"

texture_power_meter_two_segments: # 0x030283E0
.incbin "actors/power_meter/power_meter_two_segments.rgba16"

texture_power_meter_one_segments: # 0x03028BE0
.incbin "actors/power_meter/power_meter_one_segment.rgba16"

glabel power_meter_health_segments_lut # 0x030293E0
.word texture_power_meter_one_segments
.word texture_power_meter_two_segments
.word texture_power_meter_three_segments
.word texture_power_meter_four_segments
.word texture_power_meter_five_segments
.word texture_power_meter_six_segments
.word texture_power_meter_seven_segments
.word texture_power_meter_full

vertex_power_meter_base: # 0x03029400
vertex    -32,    -32,      0,      0,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,    -32,      0,    992,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,     32,      0,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -32,     32,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,    -32,      0,      1,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex     32,    -32,      0,   1024,   2016,  0xFF, 0xFF, 0xFF, 0xFF
vertex     32,     32,      0,   1024,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex      0,     32,      0,      1,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel dl_power_meter_base # 0x03029480 - 0x03029530
gsDPPipeSync
gsSPClearGeometryMode G_LIGHTING
gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0

# There were multiple matching pairs, so I don't know if this is correct or not.
gsDPSetRenderMode G_RM_TEX_EDGE, G_RM_TEX_EDGE2
# It could also be one of these:
# G_RM_OPA_SURF, G_RM_TEX_EDGE2; G_RM_TEX_EDGE, G_RM_OPA_SURF2; G_RM_RA_ZB_OPA_SURF, G_RM_TEX_EDGE, G_RM_OPA_CI2;
# G_RM_OPA_CI, G_RM_TEX_EDGE2; G_G_RM_PASS, G_RM_TEX_EDGE2;

gsDPSetTextureFilter G_TF_POINT
gsSPTexture -1, -1, 0, 0, 1
gsSPVertex vertex_power_meter_base, 8, 0
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 252
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_power_meter_left_side
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSP2Triangles  0,  1,  2, 0x0,  0,  2,  3, 0x0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_power_meter_right_side
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSP2Triangles  4,  5,  6, 0x0,  4,  6,  7, 0x0
gsSPEndDisplayList

vertex_power_meter_health_segments: # 0x03029530
vertex    -16,    -16,      0,      0,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     15,    -16,      0,    992,    992,  0xFF, 0xFF, 0xFF, 0xFF
vertex     15,     16,      0,    992,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -16,     16,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel dl_power_meter_health_segments_begin # 0x03029570 - 0x030295A0
gsDPPipeSync
gsSPVertex vertex_power_meter_health_segments, 4, 0
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPEndDisplayList

glabel dl_power_meter_health_segments_end # 0x030295A0 - 0x030295D8
gsDPPipeSync
gsSPTexture -1, -1, 0, 0, 0
gsSPSetGeometryMode G_LIGHTING

# There were multiple matching pairs, so I don't know if this is correct or not.
gsDPSetRenderMode G_RM_OPA_SURF, G_RM_OPA_SURF2
# It could also be one of these:
# G_RM_OPA_SURF, G_RM_OPA_CI2; G_RM_OPA_CI, G_RM_OPA_SURF2; G_RM_PASS, G_RM_OPA_SURF2;

gsDPSetCombineModeLERP1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTextureFilter G_TF_BILERP
gsSPEndDisplayList
