# generated by n64split
.section .rodata
.include "macros.inc"
.include "ultra64/gbi.inc"

.word 0
.word 0 # Hmm...

# Flower (Unused)

flower_bubbles_textures_texture_0B000008: # 0x0B000008
.incbin "bin/flower_bubbles_textures/flower.00008.rgba16"

flower_bubbles_textures_texture_0B000808: # 0x0B000808
.incbin "bin/flower_bubbles_textures/flower.00808.rgba16"

flower_bubbles_textures_texture_0B001008: # 0x0B001008
.incbin "bin/flower_bubbles_textures/flower.01008.rgba16"

flower_bubbles_textures_texture_0B001808: # 0x0B001808
.incbin "bin/flower_bubbles_textures/flower.01808.rgba16"

glabel flower_bubbles_textures_ptr_0B002008 # 0x0B002008
.word flower_bubbles_textures_texture_0B000008
.word flower_bubbles_textures_texture_0B000808
.word flower_bubbles_textures_texture_0B001008
.word flower_bubbles_textures_texture_0B001808
.word flower_bubbles_textures_texture_0B001008
.word flower_bubbles_textures_texture_0B000808

# Lava Bubble

lava_bubble_texture_0B002020: # 0x0B002020
.incbin "bin/flower_bubbles_textures/lava_bubble.02020.rgba16"

lava_bubble_texture_0B002820: # 0x0B002820
.incbin "bin/flower_bubbles_textures/lava_bubble.02820.rgba16"

lava_bubble_texture_0B003020: # 0x0B003020
.incbin "bin/flower_bubbles_textures/lava_bubble.03020.rgba16"

lava_bubble_texture_0B003820: # 0x0B003820
.incbin "bin/flower_bubbles_textures/lava_bubble.03820.rgba16"

lava_bubble_texture_0B004020: # 0x0B004020
.incbin "bin/flower_bubbles_textures/lava_bubble.04020.rgba16"

lava_bubble_texture_0B004820: # 0x0B004820
.incbin "bin/flower_bubbles_textures/lava_bubble.04820.rgba16"

lava_bubble_texture_0B005020: # 0x0B005020
.incbin "bin/flower_bubbles_textures/lava_bubble.05020.rgba16"

lava_bubble_texture_0B005820: # 0x0B005820
.incbin "bin/flower_bubbles_textures/lava_bubble.05820.rgba16"

glabel lava_bubble_ptr_0B006020 # 0x0B006020
.word lava_bubble_texture_0B002020
.word lava_bubble_texture_0B002820
.word lava_bubble_texture_0B003020
.word lava_bubble_texture_0B003020
.word lava_bubble_texture_0B003020
.word lava_bubble_texture_0B003820
.word lava_bubble_texture_0B004020
.word lava_bubble_texture_0B004820
.word lava_bubble_texture_0B005020
.word lava_bubble_texture_0B005820

# Bubble

bubble_texture_0B006048: # 0x0B006048
.incbin "bin/flower_bubbles_textures/bubble.06048.rgba16"

glabel bubble_ptr_0B006848 # 0x0B006848
.word bubble_texture_0B006048

# Tiny Bubble

tiny_bubble_texture_0B00684C: # 0x0B00684C
.incbin "bin/flower_bubbles_textures/tiny_bubble.0684C.rgba16"

.word 0 # align?
glabel tiny_bubble_dl_0B006A50 # 0x0B006A50 - 0x0B006AB0
gsDPPipeSync
gsSPClearGeometryMode 0x00022200
gsSPTexture -32768, -32768, 0, 0, 1
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00553078
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, tiny_bubble_texture_0B00684C
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 4, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x0FF, 0x200
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 4, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 60, 60
gsSPEndDisplayList

glabel tiny_bubble_dl_0B006AB0 # 0x0B006AB0 - 0x0B006AD8
gsSPTexture 1, 1, 0, 0, 0
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00552078
gsSPSetGeometryMode 0x00022200
gsSPEndDisplayList

tiny_bubble_texture_0B006AD8: # 0x0B006AD8
.incbin "bin/flower_bubbles_textures/tiny_bubble.06AD8.rgba16"

glabel tiny_bubble_dl_0B006CD8 # 0x0B006CD8 - 0x0B006D38
gsDPPipeSync
gsSPClearGeometryMode 0x00020200
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, tiny_bubble_texture_0B006AD8
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00553078
gsSPTexture -32768, -32768, 0, 0, 1
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x0FF, 0x200
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 60, 60
gsSPEndDisplayList

glabel tiny_bubble_dl_0B006D38 # 0x0B006D38 - 0x0B006D68
gsDPPipeSync
gsSPClearGeometryMode 0x00020200
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00553078
gsSPTexture -1, -1, 0, 0, 1
gsSPEndDisplayList

glabel tiny_bubble_dl_0B006D68 # 0x0B006D68 - 0x0B006D98
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPEndDisplayList