#include <ultra64.h>
#include "sm64.h"

#define const

// 0x801A8730
ALIGNED8 const u8 textureHandOpen[] = {
#include "textures/intro_raw/hand_open.rgba16.inc.c"
};

//! stray EndDisplayList
static const Gfx dl_unused_1[] = {
    gsSPEndDisplayList(),
};

// 0x801A8F38
ALIGNED8 const u8 textureHandClosed[] = {
#include "textures/intro_raw/hand_closed.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_0[] = {
#include "textures/intro_raw/red_star_0.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_1[] = {
#include "textures/intro_raw/red_star_1.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_2[] = {
#include "textures/intro_raw/red_star_2.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_3[] = {
#include "textures/intro_raw/red_star_3.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_4[] = {
#include "textures/intro_raw/red_star_4.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_5[] = {
#include "textures/intro_raw/red_star_5.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_6[] = {
#include "textures/intro_raw/red_star_6.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_red_star_7[] = {
#include "textures/intro_raw/red_star_7.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_0[] = {
#include "textures/intro_raw/white_star_0.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_1[] = {
#include "textures/intro_raw/white_star_1.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_2[] = {
#include "textures/intro_raw/white_star_2.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_3[] = {
#include "textures/intro_raw/white_star_3.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_4[] = {
#include "textures/intro_raw/white_star_4.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_5[] = {
#include "textures/intro_raw/white_star_5.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_6[] = {
#include "textures/intro_raw/white_star_6.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_white_star_7[] = {
#include "textures/intro_raw/white_star_7.rgba16.inc.c"
};

static const Vtx star_vertex_801B1738[] = {
    {{{   -64,      0,      0}, 0, {     0,    992}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    64,      0,      0}, 0, {   992,    992}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    64,    128,      0}, 0, {   992,      0}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{   -64,    128,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0x00}}},
};

//! no references to these vertices
static const Vtx D_vertex_801B1778[] = {
    {{{ 16384,      0,      0}, 0, {     0,  16384}, {0x00, 0x00, 0x00, 0x00}}},
    {{{     0,      0,  16384}, 0, {     0,      0}, {0x00, 0x00, 0x40, 0x00}}},
    {{{     0,      0,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
    {{{     0,      0,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
};

static const Gfx star_dl_common[] = {
    gsDPSetCombineLERP1Cycle(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(star_vertex_801B1738, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_NOOP2),
    gsSPEndDisplayList(),
};

static const Gfx red_star_dl_801B1838[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_0),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B1850[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_1),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B1868[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_2),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B1880[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_3),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B1898[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_4),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B18B0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_5),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B18C8[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_6),
    gsSPBranchList(star_dl_common),
};

static const Gfx red_star_dl_801B18E0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_red_star_7),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B18F8[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_0),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B1910[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_1),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B1928[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_2),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B1940[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_3),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B1958[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_4),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B1970[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_5),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B1988[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_6),
    gsSPBranchList(star_dl_common),
};

static const Gfx white_star_dl_801B19A0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_white_star_7),
    gsSPBranchList(star_dl_common),
};

// 0x801B19B8
const Gfx *const redStarDlArray[] = {
    red_star_dl_801B1838,
    red_star_dl_801B1838,
    red_star_dl_801B1850,
    red_star_dl_801B1850,
    red_star_dl_801B1868,
    red_star_dl_801B1868,
    red_star_dl_801B1880,
    red_star_dl_801B1880,
    red_star_dl_801B1898,
    red_star_dl_801B1898,
    red_star_dl_801B18B0,
    red_star_dl_801B18B0,
    red_star_dl_801B18C8,
    red_star_dl_801B18C8,
    red_star_dl_801B18E0,
    red_star_dl_801B18E0,
};

// 0x801B19F8
const Gfx *const silverStarDlArray[] = {
    white_star_dl_801B18F8,
    white_star_dl_801B18F8,
    white_star_dl_801B1910,
    white_star_dl_801B1910,
    white_star_dl_801B1928,
    white_star_dl_801B1928,
    white_star_dl_801B1940,
    white_star_dl_801B1940,
    white_star_dl_801B1958,
    white_star_dl_801B1958,
    white_star_dl_801B1970,
    white_star_dl_801B1970,
    white_star_dl_801B1988,
    white_star_dl_801B1988,
    white_star_dl_801B19A0,
    white_star_dl_801B19A0,
};

ALIGNED8 static const u8 texture_sparkle_0[] = {
#include "textures/intro_raw/sparkle_0.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_sparkle_1[] = {
#include "textures/intro_raw/sparkle_1.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_sparkle_2[] = {
#include "textures/intro_raw/sparkle_2.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_sparkle_3[] = {
#include "textures/intro_raw/sparkle_3.rgba16.inc.c"
};

ALIGNED8 static const u8 texture_sparkle_4[] = {
#include "textures/intro_raw/sparkle_4.rgba16.inc.c"
};

//! no references to this texture 0x801B4238
ALIGNED8 static const u8 texture_sparkle_5[] = {
#include "textures/intro_raw/sparkle_5.rgba16.inc.c"
};

static const Vtx sparkle_vertex_801B4A38[] = {
    {{{   -32,      0,      0}, 0, {     0,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,      0,      0}, 0, {  1984,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,     64,      0}, 0, {  1984,      0}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{   -32,     64,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0x00}}},
};

// 0x801B4A78
static const Gfx sparkle_dl_common[] = {
    gsDPSetCombineLERP1Cycle(TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x3FF, 0x100),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(sparkle_vertex_801B4A38, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_NOOP2),
    gsSPEndDisplayList(),
};

static const Gfx red_dl_801B4AF8[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPEndDisplayList(),
};

static const Gfx white_dl_801B4B08[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

static const Gfx sparkle_dl_801B4B18[] = {
    gsDPPipeSync(),
    gsSPDisplayList(red_dl_801B4AF8),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_0),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4B38[] = {
    gsDPPipeSync(),
    gsSPDisplayList(red_dl_801B4AF8),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_1),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4B58[] = {
    gsDPPipeSync(),
    gsSPDisplayList(red_dl_801B4AF8),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_2),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4B78[] = {
    gsDPPipeSync(),
    gsSPDisplayList(red_dl_801B4AF8),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_3),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4B98[] = {
    gsDPPipeSync(),
    gsSPDisplayList(red_dl_801B4AF8),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4BB8[] = {
    gsDPPipeSync(),
    gsSPDisplayList(red_dl_801B4AF8),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4BD8[] = {
    gsDPPipeSync(),
    gsSPDisplayList(white_dl_801B4B08),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_0),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4BF8[] = {
    gsDPPipeSync(),
    gsSPDisplayList(white_dl_801B4B08),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_1),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4C18[] = {
    gsDPPipeSync(),
    gsSPDisplayList(white_dl_801B4B08),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_2),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4C38[] = {
    gsDPPipeSync(),
    gsSPDisplayList(white_dl_801B4B08),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_3),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4C58[] = {
    gsDPPipeSync(),
    gsSPDisplayList(white_dl_801B4B08),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4),
    gsSPBranchList(sparkle_dl_common),
};

static const Gfx sparkle_dl_801B4C78[] = {
    gsDPPipeSync(),
    gsSPDisplayList(white_dl_801B4B08),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_sparkle_4),
    gsSPBranchList(sparkle_dl_common),
};

// 0x801B4C98
const Gfx *const redSparkleDlArray[] = {
    sparkle_dl_801B4B98,
    sparkle_dl_801B4B98,
    sparkle_dl_801B4B78,
    sparkle_dl_801B4B78,
    sparkle_dl_801B4B58,
    sparkle_dl_801B4B58,
    sparkle_dl_801B4B38,
    sparkle_dl_801B4B38,
    sparkle_dl_801B4B18,
    sparkle_dl_801B4B18,
    sparkle_dl_801B4BB8,
    sparkle_dl_801B4BB8,
};

// 0x801B4CC8
const Gfx *const silverSparkleDlArray[] = {
    sparkle_dl_801B4C58,
    sparkle_dl_801B4C58,
    sparkle_dl_801B4C38,
    sparkle_dl_801B4C38,
    sparkle_dl_801B4C18,
    sparkle_dl_801B4C18,
    sparkle_dl_801B4BF8,
    sparkle_dl_801B4BF8,
    sparkle_dl_801B4BD8,
    sparkle_dl_801B4BD8,
    sparkle_dl_801B4C78,
    sparkle_dl_801B4C78,
};

//! stray EndDisplayList
static const Gfx dl_unused_2[] = {
    gsSPEndDisplayList(),
};

// 0x801B4D00
ALIGNED8 static const u8 texture_mario_face_shine[] = {
#include "textures/intro_raw/mario_face_shine.ia8.inc.c"
};

const Gfx marioHeadDl801B5100[] = {
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsSPTexture(0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetCombineLERP1Cycle(PRIMITIVE, SHADE, TEXEL0, SHADE, PRIMITIVE, SHADE, TEXEL0, SHADE),
    gsDPLoadTextureBlock(texture_mario_face_shine, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

const Gfx marioHeadDl801B5170[] = {
    gsSPGeometryMode(0xFFFFFFFF, G_SHADING_SMOOTH | G_SHADE),
    gsSPEndDisplayList(),
};

const Gfx marioHeadDl801B5188[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP1Cycle(0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

UNUSED static const u32 goddard_tex_dl_unused_0 = 0;

float D_801B520C = 1.0f;

UNUSED static const u64 goddard_tex_dl_unused_1 = 0;

//! no references to display list
static const Gfx dl_unused_3[] = {
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

static const Vtx vertex_801B5228[] = {
    {{{    -8,      8,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
    {{{     8,     -2,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
    {{{     2,     -8,      0}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0xff}}},
};

static const Vtx vertex_801B5258[] = {
    {{{    -6,      6,      0}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{     7,     -3,      0}, 0, {     0,      0}, {0xff, 0x00, 0x00, 0xff}}},
    {{{     3,     -7,      0}, 0, {     0,      0}, {0xff, 0x00, 0x00, 0xff}}},
};

//! no references to display list
static const Gfx dl_801B5288[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsSPGeometryMode(0xFFFFFFFF, G_SHADING_SMOOTH | G_SHADE),
    gsDPPipeSync(),
    gsSPVertex(vertex_801B5228, 3, 0),
    gsSP1Triangle( 0,  1,  2, 0x0),
    gsSPVertex(vertex_801B5258, 3, 0),
    gsSP1Triangle( 0,  1,  2, 0x0),
    gsSPEndDisplayList(),
};

const Gfx marioHeadDl801B52D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0, 0, 0, 1),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsDPSetCombineLERP1Cycle(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPEndDisplayList(),
};

