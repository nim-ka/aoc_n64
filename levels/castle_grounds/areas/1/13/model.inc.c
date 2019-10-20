ALIGNED8 static const u8 castle_grounds_seg7_us_texture_0700EAE8[] = {
#include "levels/castle_grounds/5.ia8.inc.c"
};

// 0x0700F2E8
const Gfx castle_grounds_seg7_us_dl_0700F2E8[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP1Cycle(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 6, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 1, castle_grounds_seg7_us_texture_0700EAE8),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x7FF, 0x100),
    gsSPTextureRectangle(116 << 2, 166 << 2, (116 + 64) << 2, (166 + 32) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10),
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

