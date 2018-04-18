#ifndef _ULTRA64_GBI_H_
#define _ULTRA64_GBI_H_

/* Types */

typedef struct
{
    unsigned int w0;
    unsigned int w1;
} Gwords;

/* TODO: fill in the rest of the members */
typedef union
{
    Gwords words;
    long long int force_structure_alignment;
} Gfx;


#define _SHIFTL(value, shift, size) \
    ((unsigned int) (((unsigned int) (value) & ((1 << size) - 1)) << shift))


#define GPACK_RGBA5551(r, g, b, a) \
    ((((r) << 8) & 0xF800) | \
    (((g) << 3) & 0x07C0) | \
    (((b) >> 2) & 0x003E) | \
    ((a) & 0x0001))
#define GPACK_ZDZ(z, dz) ((z) << 2 | (dz))


#define G_ZBUFFER            0x00000001
#define G_TEXTURE_ENABLE     0x00000002
#define G_SHADE              0x00000004
#define G_SHADING_SMOOTH     0x00000200
#define G_CULL_FRONT         0x00001000
#define G_CULL_BACK          0x00002000
#define G_CULL_BOTH          0x00003000
#define G_FOG                0x00010000
#define G_LIGHTING           0x00020000
#define G_TEXTURE_GEN        0x00040000
#define G_TEXTURE_GEN_LINEAR 0x00080000
#define G_LOD                0x00100000
#define G_CLIPPING           0x00800000

#define G_IM_FMT_RGBA   0
#define G_IM_FMT_YUV    1
#define G_IM_FMT_CI     2
#define G_IM_FMT_IA     3
#define G_IM_FMT_I      4


#define G_AC_NONE      (0 << 0)
#define G_AC_THRESHOLD (1 << 0)
#define G_AC_DITHER    (3 << 0)

#define G_ZS_PIXEL (0 << 2)
#define G_ZS_PRIM  (1 << 2)

#define G_CD_MAGICSQ (0 << 6)
#define G_CD_BAYER   (1 << 6)
#define G_CD_NOISE   (2 << 6)

#define G_CK_NONE (0 << 8)
#define G_CK_KEY  (1 << 8)

#define G_TC_CONV     (0 << 9)
#define G_TC_FILTCONV (5 << 9)
#define G_TC_FILT     (6 << 9)

#define G_TF_POINT   (0 << 12)
#define G_TF_BILERP  (2 << 12)
#define G_TF_AVERAGE (3 << 12)

#define G_TT_NONE   (0 << 14)
#define G_TT_RGBA16 (2 << 14)
#define G_TT_IA16   (3 << 14)

#define G_TL_TILE (0 << 16)
#define G_TL_LOD  (1 << 16)

#define G_TD_CLAMP   (0 << 17)
#define G_TD_SHARPEN (1 << 17)
#define G_TD_DETAIL  (2 << 17)

#define G_TP_NONE   (0 << 19)
#define G_TP_PERSP  (1 << 19)

#define G_CYC_1CYCLE (0 << 20)
#define G_CYC_2CYCLE (1 << 20)
#define G_CYC_COPY   (2 << 20)
#define G_CYC_FILL   (3 << 20)

#define G_PM_NPRIMITIVE (0 << 23)
#define G_PM_1PRIMITIVE (1 << 23)

#define G_SC_NON_INTERLACE  0
#define G_SC_ODD_INTERLACE  3
#define G_SC_EVEN_INTERLACE 2


#define gDPPipeSync(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xE7000000; \
    _g->words.w1 = 0x00000000; \
}

#define gDPFullSync(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xE9000000; \
    _g->words.w1 = 0x00000000; \
}

#define gSPEndDisplayList(pkt) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB8000000; \
    _g->words.w1 = 0x00000000; \
}

#define gDPSetCycleType(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001402; \
    _g->words.w1 = type; \
}

#define gDPPipelineMode(pkt, mode) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001701; \
    _g->words.w1 = mode; \
}

#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = _SHIFTL(0xED, 24, 8) | \
        _SHIFTL((int) ((float) ulx * 4.0f), 12, 12) | \
        _SHIFTL((int) ((float) uly * 4.0f), 0, 12); \
    _g->words.w1 = _SHIFTL(mode, 24, 8) | \
        _SHIFTL((int) ((float) lrx * 4.0f), 12, 12) | \
        _SHIFTL((int) ((float) lry * 4.0f), 0, 12); \
}

#define gDPSetCombine(pkt, muxs0, muxs1) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = _SHIFTL(0xFC, 24, 8) | _SHIFTL(muxs0, 0, 24); \
    _g->words.w1 = muxs1; \
}

#define gDPSetTextureLOD(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001001; \
    _g->words.w1 = type; \
}

#define gDPSetTextureLUT(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000E02; \
    _g->words.w1 = type; \
}

#define gDPSetTextureDetail(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001102; \
    _g->words.w1 = type; \
}

#define gDPSetTexturePersp(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA001301; \
    _g->words.w1 = type; \
}

#define gDPSetTextureFilter(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000C02; \
    _g->words.w1 = type; \
}

#define gDPSetTextureConvert(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000903; \
    _g->words.w1 = type; \
}

#define gDPSetCombineKey(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000801; \
    _g->words.w1 = type; \
}

#define gDPSetColorDither(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBA000602; \
    _g->words.w1 = type; \
}

#define gDPSetFillColor(pkt, color) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xF7000000; \
    _g->words.w1 = color; \
}

#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = _SHIFTL(0xF6, 24, 8) | _SHIFTL(lrx, 14, 10) | _SHIFTL(lry, 2, 10); \
    _g->words.w1 = _SHIFTL(0, 24, 8) | _SHIFTL(ulx, 14, 10) | _SHIFTL(uly, 2, 10); \
}

#define gDPSetAlphaCompare(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB9000002; \
    _g->words.w1 = type; \
}

#define gDPSetDepthSource(pkt, type) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB9000201; \
    _g->words.w1 = type; \
}

#define gDPSetRenderMode(pkt, mode1, mode2) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB900031D; \
    _g->words.w1 = mode1 | mode2; \
}

#define gSPClearGeometryMode(pkt, mode) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB6000000; \
    _g->words.w1 = mode; \
}

#define gSPSetGeometryMode(pkt, word) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xB7000000; \
    _g->words.w1 = word; \
}

#define gSPNumLights(pkt, n) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xBC000002; \
    _g->words.w1 = (0x80000000 + ((n) + 1) * 0x20); \
}

#define gSPTexture(pkt, sc, tc, level, tile, on) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = _SHIFTL(0xBB, 24, 8) | _SHIFTL(0, 16, 8)| \
        _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 0, 8); \
    _g->words.w1 = _SHIFTL(sc, 16, 16) | _SHIFTL(tc, 0, 16); \
}

#define gDPSetColorImage(pkt, fmt, size, width, image) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = _SHIFTL(0xFF, 24, 8) | _SHIFTL(fmt, 21, 3)| \
        _SHIFTL(size, 19, 2) | _SHIFTL((width) - 1, 0, 12); \
    _g->words.w1 = image; \
}

#define gDPSetDepthImage(pkt, image) \
{ \
    Gfx *_g = (Gfx *) (pkt); \
    _g->words.w0 = 0xFE000000; \
    _g->words.w1 = image; \
}


#endif
