#include <ultra64.h>

#include "sm64.h"
#include "moving_texture.h"
#include "area.h"
#include "camera.h"
#include "rendering_graph_node.h"
#include "engine/math_util.h"
#include "memory.h"
#include "save_file.h"
#include "segment2.h"
#include "engine/surface_collision.h"
#include "geo_misc.h"
#include "rendering_graph_node.h"
#include "room.h"

#define MOVTEXT_VTX_COLOR_DEFAULT 0
#define MOVTEXT_VTX_COLOR_YELLOW  1
#define MOVTEXT_VTX_COLOR_RED     2

struct MovingTextureGeoList
{
    u32 geo_id;
    s32 texture_num;
    s32 vtx_count;
    s16 *tris;
    Gfx *begin_dl;
    Gfx *end_dl;
    Gfx *tri_dl;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 layer;
};

s16 D_8032FFD0 = 1;
s16 D_8032FFD4 = 0;
s8 gMovTextVtxColor = MOVTEXT_VTX_COLOR_DEFAULT;
float D_8032FFDC = 0.0f;
s32 D_8032FFE0 = 0;

extern u8 ssl_quicksand[];
extern u8 ssl_pyramid_sand[];
extern u8 ttc_yellow_triangle[];

u8 *gMovingTextureIdList[] =
{
    texture_waterbox_water,
    texture_waterbox_mist,
    texture_waterbox_jrb_water,
    texture_waterbox_unknown_water,
    texture_waterbox_lava,
    ssl_quicksand,
    ssl_pyramid_sand,
    ttc_yellow_triangle
};

extern Gfx castle_grounds_dl_waterfall[];
extern s16 castle_grounds_movtex_tris_waterfall[];
extern s16 ssl_movtex_tris_pyramid_sand_pathway_front[];
extern Gfx ssl_dl_pyramid_sand_pathway_begin[];
extern Gfx ssl_dl_pyramid_sand_pathway_end[];
extern Gfx ssl_dl_pyramid_sand_pathway_front_end[];
extern s16 ssl_movtex_tris_pyramid_sand_pathway_floor[];
extern Gfx ssl_dl_pyramid_sand_pathway_floor_begin[];
extern Gfx ssl_dl_pyramid_sand_pathway_floor_end[];
extern s16 ssl_movtex_tris_pyramid_sand_pathway_side[];
extern Gfx ssl_dl_pyramid_sand_pathway_side_end[];
extern s16 bitfs_movtex_tris_lava_first_section[];
extern Gfx bitfs_dl_lava_sections[];
extern s16 bitfs_movtex_tris_lava_second_section[];
extern s16 bitfs_movtex_tris_lava_floor[];
extern Gfx bitfs_dl_lava_floor[];
extern s16 lll_movtex_tris_lava_floor[];
extern Gfx lll_dl_lava_floor[];
extern s16 lll_movtex_tris_lavafall_volcano[];
extern Gfx lll_dl_lavafall_volcano[];
extern s16 cotmc_movtex_tris_water[];
extern Gfx cotmc_dl_water_begin[];
extern Gfx cotmc_dl_water_end[];
extern Gfx cotmc_dl_water[];
extern s16 ttm_movtex_tris_begin_waterfall[];
extern Gfx ttm_dl_waterfall[];
extern s16 ttm_movtex_tris_end_waterfall[];
extern s16 ttm_movtex_tris_begin_puddle_waterfall[];
extern Gfx ttm_dl_bottom_waterfall[];
extern s16 ttm_movtex_tris_end_puddle_waterfall[];
extern s16 ttm_movtex_tris_puddle_waterfall[];
extern Gfx ttm_dl_puddle_waterfall[];
extern s16 ssl_movtex_tris_pyramid_quicksand[];
extern Gfx ssl_dl_quicksand_begin[];
extern Gfx ssl_dl_quicksand_end[];
extern Gfx ssl_dl_pyramid_quicksand[];
extern s16 ssl_movtex_tris_pyramid_corners_quicksand[];
extern Gfx ssl_dl_pyramid_corners_quicksand[];
extern s16 ssl_movtex_tris_sides_quicksand[];
extern Gfx ssl_dl_sides_quicksand[];
extern s16 ttc_movtex_tris_big_surface_treadmill[];
extern Gfx ttc_dl_surface_treadmill_begin[];
extern Gfx ttc_dl_surface_treadmill_end[];
extern Gfx ttc_dl_surface_treadmill[];
extern s16 ttc_movtex_tris_small_surface_treadmill[];
extern s16 ssl_movtex_tris_quicksand_pit[];
extern Gfx ssl_dl_quicksand_pit_begin[];
extern Gfx ssl_dl_quicksand_pit_end[];
extern Gfx ssl_dl_quicksand_pit[];
extern s16 ssl_movtex_tris_pyramid_quicksand_pit[];
extern Gfx ssl_dl_pyramid_quicksand_pit_begin[];
extern Gfx ssl_dl_pyramid_quicksand_pit_end[];

struct MovingTextureGeoList gMovingTextureTris[] =
{
    {0x0801, TEX_PYRAMID_SAND_SSL, 8, ssl_movtex_tris_pyramid_sand_pathway_front, ssl_dl_pyramid_sand_pathway_begin, ssl_dl_pyramid_sand_pathway_end, ssl_dl_pyramid_sand_pathway_front_end, 0xff, 0xff, 0xff, 0xff, LAYER_TRANSPARENT_INTER},
    {0x0802, TEX_PYRAMID_SAND_SSL, 8, ssl_movtex_tris_pyramid_sand_pathway_floor, ssl_dl_pyramid_sand_pathway_floor_begin, ssl_dl_pyramid_sand_pathway_floor_end, ssl_dl_pyramid_sand_pathway_front_end, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE_INTER},
    {0x0803, TEX_PYRAMID_SAND_SSL, 6, ssl_movtex_tris_pyramid_sand_pathway_side, ssl_dl_pyramid_sand_pathway_begin, ssl_dl_pyramid_sand_pathway_end, ssl_dl_pyramid_sand_pathway_side_end, 0xff, 0xff, 0xff, 0xff, LAYER_TRANSPARENT_INTER},
    {0x1601, TEXTURE_WATER, 15, castle_grounds_movtex_tris_waterfall, dl_waterbox_rgba16_begin, dl_waterbox_end, castle_grounds_dl_waterfall, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT_INTER},
    {0x1901, TEXTURE_LAVA, 4, bitfs_movtex_tris_lava_first_section, dl_waterbox_rgba16_begin, dl_waterbox_end, bitfs_dl_lava_sections, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x1902, TEXTURE_LAVA, 4, bitfs_movtex_tris_lava_second_section, dl_waterbox_rgba16_begin, dl_waterbox_end, bitfs_dl_lava_sections, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT},
    {0x1903, TEXTURE_LAVA, 9, bitfs_movtex_tris_lava_floor, dl_waterbox_rgba16_begin, dl_waterbox_end, bitfs_dl_lava_floor, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT},
    {0x2201, TEXTURE_LAVA, 9, lll_movtex_tris_lava_floor, dl_waterbox_rgba16_begin, dl_waterbox_end, lll_dl_lava_floor, 0xff, 0xff, 0xff, 0xc8, LAYER_TRANSPARENT},
    {0x2202, TEXTURE_LAVA, 16, lll_movtex_tris_lavafall_volcano, dl_waterbox_rgba16_begin, dl_waterbox_end, lll_dl_lavafall_volcano, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT_INTER},
    {0x2801, TEXTURE_WATER, 14, cotmc_movtex_tris_water, cotmc_dl_water_begin, cotmc_dl_water_end, cotmc_dl_water, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT_INTER},
    {0x3601, TEXTURE_WATER, 6, ttm_movtex_tris_begin_waterfall, dl_waterbox_rgba16_begin, dl_waterbox_end, ttm_dl_waterfall, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT},
    {0x3602, TEXTURE_WATER, 6, ttm_movtex_tris_end_waterfall, dl_waterbox_rgba16_begin, dl_waterbox_end, ttm_dl_waterfall, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT},
    {0x3603, TEXTURE_WATER, 4, ttm_movtex_tris_begin_puddle_waterfall, dl_waterbox_rgba16_begin, dl_waterbox_end, ttm_dl_bottom_waterfall, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT_INTER},
    {0x3604, TEXTURE_WATER, 4, ttm_movtex_tris_end_puddle_waterfall, dl_waterbox_rgba16_begin, dl_waterbox_end, ttm_dl_bottom_waterfall, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT_INTER},
    {0x3605, TEXTURE_WATER, 8, ttm_movtex_tris_puddle_waterfall, dl_waterbox_rgba16_begin, dl_waterbox_end, ttm_dl_puddle_waterfall, 0xff, 0xff, 0xff, 0xb4, LAYER_TRANSPARENT_INTER},
    {0x00000000, 0x00000000,                  0, NULL,       NULL,             NULL,             NULL,       0x00, 0x00, 0x00, 0x00, 0x00000000},
};

struct MovingTextureGeoList gMovingTextureTrisWithRot[] =
{
    {0x0801, TEX_QUICKSAND_SSL,  12, ssl_movtex_tris_pyramid_quicksand, ssl_dl_quicksand_begin, ssl_dl_quicksand_end, ssl_dl_pyramid_quicksand, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x0802, TEX_QUICKSAND_SSL,  16, ssl_movtex_tris_pyramid_corners_quicksand, ssl_dl_quicksand_begin, ssl_dl_quicksand_end, ssl_dl_pyramid_corners_quicksand, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x0803, TEX_QUICKSAND_SSL,  15, ssl_movtex_tris_sides_quicksand, ssl_dl_quicksand_begin, ssl_dl_quicksand_end, ssl_dl_sides_quicksand, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x1400, TEX_YELLOW_TRI_TTC, 12, ttc_movtex_tris_big_surface_treadmill, ttc_dl_surface_treadmill_begin, ttc_dl_surface_treadmill_end, ttc_dl_surface_treadmill, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x1401, TEX_YELLOW_TRI_TTC, 12, ttc_movtex_tris_small_surface_treadmill, ttc_dl_surface_treadmill_begin, ttc_dl_surface_treadmill_end, ttc_dl_surface_treadmill, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x00000000, 0x00000000,                        0, NULL,       NULL,       NULL,       NULL,       0x00, 0x00, 0x00, 0x00, 0x00000000},
};

struct MovingTextureGeoList gMovingTextureTrisWithLight[] =
{
    {0x0801, TEX_QUICKSAND_SSL,    8, ssl_movtex_tris_quicksand_pit, ssl_dl_quicksand_pit_begin, ssl_dl_quicksand_pit_end, ssl_dl_quicksand_pit, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x0802, TEX_PYRAMID_SAND_SSL, 8, ssl_movtex_tris_pyramid_quicksand_pit, ssl_dl_pyramid_quicksand_pit_begin, ssl_dl_pyramid_quicksand_pit_end, ssl_dl_quicksand_pit, 0xff, 0xff, 0xff, 0xff, LAYER_OPAQUE},
    {0x00000000, 0x00000000,                         0, NULL,       NULL,       NULL,       NULL,       0x00, 0x00, 0x00, 0x00, 0x00000000},
};

Gfx *Geo18_802D0080(s32 run, UNUSED struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    s32 spC;
    UNUSED u8 unused[] = {1, 0, 4, 0, 7, 0, 10, 0};
    s16 sp2;

    if (run != TRUE)
    {
        D_8032FFE0 = 0;
    }
    else if (run == TRUE && gWaterRegions != NULL && D_8032FFE0 == 0)
    {
        if (D_8032FFDC <= 1382.4)
            sp2 = 31;
        else if (D_8032FFDC >= 1600.0)
            sp2 = 2816;
        else
            sp2 = 1024;
        for (spC = 0; spC < *gWaterRegions; spC++)
        {
            gWaterRegions[spC * 6 + 6] = sp2;
        }
        D_8032FFE0 = 1;
    }
    return NULL;
}

Gfx *Geo18_802D01E0(s32 run, UNUSED struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    if (run != TRUE)
    {
        D_8032FFD4 = gAreaUpdateCounter - 1;
        D_8032FFD0 = gAreaUpdateCounter;
    }
    else
    {
        D_8032FFD4 = D_8032FFD0;
        D_8032FFD0 = gAreaUpdateCounter;
    }
    return NULL;
}

void vertex_control_movtext(Vtx *verts, s32 n, s16 x, s16 y, s16 z, s16 f, s16 g,
    f32 h, u8 alpha)
{
    s16 s = 32.0 * (32.0 * h - 1.0) * sins(f + g);
    s16 t = 32.0 * (32.0 * h - 1.0) * coss(f + g);

    if (gMovTextVtxColor == MOVTEXT_VTX_COLOR_YELLOW)
        make_vertex(verts, n, x, y, z, s, t, 255, 255, 0, alpha);
    else if (gMovTextVtxColor == MOVTEXT_VTX_COLOR_RED)
        make_vertex(verts, n, x, y, z, s, t, 255, 0, 0, alpha);
    else
        make_vertex(verts, n, x, y, z, s, t, 255, 255, 255, alpha);
}

struct MovingTexureQuadBox
{
    s16 visibility;
    s16 rotspeed;
    s16 rotscale;
    s16 x1;
    s16 z1;
    s16 x2;
    s16 z2;
    s16 x3;
    s16 z3;
    s16 x4;
    s16 z4;
    s16 rot;
    s16 alpha;
    s16 text_id;
};

struct MovingTextureBox
{
    s16 id;
    s16 filler;
    void *addr_data;
};

s16 D_8035FF70;

Gfx *func_802CF9A4(s16 y, struct MovingTexureQuadBox *b)
{
    s16 visibility;
    s16 rotspeed = b->rotspeed;
    s16 rotscale = b->rotscale;
    s16 x1 = b->x1;
    s16 z1 = b->z1;
    s16 x2 = b->x2;
    s16 z2 = b->z2;
    s16 x3 = b->x3;
    s16 z3 = b->z3;
    s16 x4 = b->x4;
    s16 z4 = b->z4;
    s16 rot = b->rot;
    s16 alpha = b->alpha;
    s16 text_id = b->text_id;
    Vtx *verts = alloc_display_list(4 * sizeof(*verts));
    Gfx *sp6C;
    Gfx *sp68;

    if (text_id == D_8035FF70)
        sp6C = alloc_display_list(3 * sizeof(*sp6C));
    else
        sp6C = alloc_display_list(8 * sizeof(*sp6C));
    if (sp6C == NULL || verts == NULL)
        return NULL;
    sp68 = sp6C;
    if (D_8032FFD0 != D_8032FFD4)
        b->visibility += rotspeed;
    visibility = b->visibility;
    if (rot == ROTATE_CLOCKWISE)
    {
        vertex_control_movtext(verts, 0, x1, y, z1, visibility,      0, rotscale, alpha);
        vertex_control_movtext(verts, 1, x2, y, z2, visibility,  16384, rotscale, alpha);
        vertex_control_movtext(verts, 2, x3, y, z3, visibility, -32768, rotscale, alpha);
        vertex_control_movtext(verts, 3, x4, y, z4, visibility, -16384, rotscale, alpha);
    }
    else // ROTATE_COUNTER_CLOCKWISE
    {
        vertex_control_movtext(verts, 0, x1, y, z1, visibility,      0, rotscale, alpha);
        vertex_control_movtext(verts, 1, x2, y, z2, visibility, -16384, rotscale, alpha);
        vertex_control_movtext(verts, 2, x3, y, z3, visibility, -32768, rotscale, alpha);
        vertex_control_movtext(verts, 3, x4, y, z4, visibility,  16384, rotscale, alpha);
    }
    if (text_id != D_8035FF70)
    {
        if (text_id == TEXTURE_MIST)
        {
            if (0)
            {
            }
            gDPSetTextureImage(sp68++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, gMovingTextureIdList[text_id])
            gDPTileSync(sp68++)
            gDPSetTile(sp68++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, 7, 0,
                G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD)
            gDPLoadSync(sp68++)
            gDPLoadBlock(sp68++, 7, 0, 0, 1023, 256)
        }
        else // any rgba16 texture
        {
            gDPSetTextureImage(sp68++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gMovingTextureIdList[text_id])
            gDPTileSync(sp68++)
            gDPSetTile(sp68++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0,
                G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD)
            gDPLoadSync(sp68++)
            gDPLoadBlock(sp68++, 7, 0, 0, 1023, 256)
            if (0)
            {
            }
        }
        D_8035FF70 = text_id;
    }
    gSPVertex(sp68++, 0x80000000 + (u32)verts, 4, 0)
    gSPDisplayList(sp68++, dl_draw_quad_verts_0123)
    gSPEndDisplayList(sp68)
    return sp6C;
}

Gfx *func_802CFFA4(s16 a, void *b)
{
    s16 *sp34 = segmented_to_virtual(b);
    s16 sp32 = sp34[0];
    Gfx *sp2C = alloc_display_list((sp32 + 1) * sizeof(*sp2C));
    Gfx *sp28 = sp2C;
    Gfx *sp24;
    s32 sp20;

    if (sp2C == NULL)
        return NULL;
    for (sp20 = 0; sp20 < sp32; sp20++)
    {
        sp24 = func_802CF9A4(a, (struct MovingTexureQuadBox *)(&sp34[sp20 * 14 + 1]));
        if (sp24 != NULL)
            gSPDisplayList(sp28++, VIRTUAL_TO_PHYSICAL(sp24))
    }
    gSPEndDisplayList(sp28);
    return sp2C;
}

 // search_moving_texture_id?, seems to be related to movTexJump
Gfx *func_802D00D0(s16 id, s16 b, void *addr_data)
{
    struct MovingTextureBox *sp1C = segmented_to_virtual(addr_data);
    s32 sp18 = 0;

    while (sp1C[sp18].id != -1)
    {
        if (sp1C[sp18].id == id)
            return func_802CFFA4(b, sp1C[sp18].addr_data);
        sp18++;
    }
    return NULL;
}

extern u8 bbh_movtex_merry_go_round_water_entrance[];
extern u8 bbh_movtex_merry_go_round_water_side[];
extern u8 ccm_movtex_penguin_puddle_water[];
extern u8 inside_castle_movtex_green_room_water[];
extern u8 inside_castle_movtex_moat_water[];
extern u8 hmc_movtex_dorrie_pool_water[];
extern u8 hmc_movtex_toxic_maze_mist[];
extern u8 ssl_movtex_puddle_water[];
extern u8 ssl_movtex_toxbox_quicksand_mist[];
extern u8 sl_movtex_water[];
extern u8 wdw_movtex_area1_water[];
extern u8 wdw_movtex_area2_water[];
extern u8 jrb_movtex_water[];
extern u8 jrb_movtex_intial_mist[];
extern u8 jrb_movtex_sinked_boat_water[];
extern u8 thi_movtex_area1_water[];
extern u8 thi_movtex_area2_water[];
extern u8 castle_grounds_movtex_water[];
extern u8 lll_movtex_volcano_floor_lava[];
extern u8 ddd_movtex_area1_water[];
extern u8 ddd_movtex_area2_water[];
extern u8 wf_movtex_water[];
extern u8 castle_courtyard_movtex_star_statue_water[];
extern u8 ttm_movtex_puddle[];

void *load_moving_texture_box(u32 a)
{
    switch (a)
    {
    case 0x0400: return bbh_movtex_merry_go_round_water_entrance;
    case 0x0401: return bbh_movtex_merry_go_round_water_side;
    case 0x0501: return ccm_movtex_penguin_puddle_water;
    case 0x0600: return inside_castle_movtex_green_room_water;
    case 0x0612: return inside_castle_movtex_moat_water;
    case 0x0701: return hmc_movtex_dorrie_pool_water;
    case 0x0702: return hmc_movtex_toxic_maze_mist;
    case 0x0801: return ssl_movtex_puddle_water;
    case 0x0851: return ssl_movtex_toxbox_quicksand_mist;
    case 0x1001: return sl_movtex_water;
    case 0x1101: return wdw_movtex_area1_water;
    case 0x1102: return wdw_movtex_area2_water;
    case 0x1201: return jrb_movtex_water;
    case 0x1205: return jrb_movtex_intial_mist;
    case 0x1202: return jrb_movtex_sinked_boat_water;
    case 0x1301: return thi_movtex_area1_water;
    case 0x1302: return thi_movtex_area2_water;
    case 0x1601: return castle_grounds_movtex_water;
    case 0x2202: return lll_movtex_volcano_floor_lava;
    case 0x2301: return ddd_movtex_area1_water;
    case 0x2302: return ddd_movtex_area2_water;
    case 0x2401: return wf_movtex_water;
    case 0x2601: return castle_courtyard_movtex_star_statue_water;
    case 0x3601: return ttm_movtex_puddle;
    default:     return NULL;
    }
}

void change_movtex_texture_format(u32 a, Gfx **b)
{
    switch (a)
    {
    case 0x0702: // hmc_movtex_toxic_maze_mist
        gSPDisplayList((*b)++, dl_waterbox_ia16_begin)
        break;
    case 0x0851: // ssl_movtex_toxbox_quicksand_mist
        gSPDisplayList((*b)++, dl_waterbox_ia16_begin)
        break;
    case 0x1205: // jrb_movtex_intial_mist
        gSPDisplayList((*b)++, dl_waterbox_ia16_begin)
        break;
    default:
        gSPDisplayList((*b)++, dl_waterbox_rgba16_begin)
        break;
    }
}

struct Struct802D104C
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0x18-0x4];
    u32 unk18;
};

Gfx *geo_exec_movtex_box(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    Gfx *sp44 = NULL;
    Gfx *sp40 = NULL;
    Gfx *sp3C;
    void *sp38;
    struct GraphNode12A *sp34;
    s16 sp32;
    s16 sp30;
    s16 sp2E;
    s32 sp28;

    if (run == TRUE)
    {
        gMovTextVtxColor = MOVTEXT_VTX_COLOR_DEFAULT;
        if (gWaterRegions == NULL)
            return NULL;
        sp32 = gWaterRegions[0];
        sp44 = alloc_display_list((sp32 + 3) * sizeof(*sp44));
        if (sp44 == NULL)
            return NULL;
        else
            sp40 = sp44;
        sp34 = (struct GraphNode12A *)node;
        if (sp34->unk18 == 0x1205) //  jrb_movtex_intial_mist
        {
            if (gCameraStatus.camFocAndPosCurrAndGoal[3][1] < 1024.0)
                return NULL;
            if (save_file_get_star_flags(gCurrSaveFileNum - 1, 2) & 1)
                return NULL;
        }
        else if (sp34->unk18 == 0x0702) // hmc_movtex_toxic_maze_mist
        {
            gMovTextVtxColor = MOVTEXT_VTX_COLOR_YELLOW;
        }
        else if (sp34->unk18 == 0x0851) // ssl_movtex_toxbox_quicksand_mist
        {
            gMovTextVtxColor = MOVTEXT_VTX_COLOR_RED;
        }
        sp38 = load_moving_texture_box(sp34->unk18);
        if (sp38 == NULL)
            return NULL;
        sp34->fnNode.node.flags = (sp34->fnNode.node.flags & 0xFF) | 0x700;
        change_movtex_texture_format(sp34->unk18, &sp40);
        D_8035FF70 = -1;
        for (sp28 = 0; sp28 < sp32; sp28++)
        {
            sp30 = gWaterRegions[sp28 * 6 + 1];
            sp2E = gWaterRegions[sp28 * 6 + 6];
            sp3C = func_802D00D0(sp30, sp2E, sp38);
            if (sp3C != NULL)
                gSPDisplayList(sp40++, VIRTUAL_TO_PHYSICAL(sp3C));
        }
        gSPDisplayList(sp40++, dl_waterbox_end);
        gSPEndDisplayList(sp40);
    }
    return sp44;
}

void func_802D0850(s16 *a, s32 b)
{
    s16 sp6 = a[0];
    s16 *sp0 = a + b;

    if (D_8032FFD0 != D_8032FFD4)
    {
        *sp0 += sp6;
        if (*sp0 >= 0x400)
            *sp0 -= 0x400;
        if (*sp0 <= -0x400)
            *sp0 += 0x400;
    }
}

void func_802D08EC(Vtx *vtx, s16 *b, struct MovingTextureGeoList *c, s8 d)
{
    s16 x = b[1];
    s16 y = b[2];
    s16 z = b[3];
    u8 alpha = c->a;
    u8 r1;
    u8 g1;
    u8 b1;
    s8 r2;
    s8 g2;
    s8 b2;
    s16 s;
    s16 t;

    switch (d)
    {
    case 0:
        r1 = c->r;
        g1 = c->g;
        b1 = c->b;
        s = b[4];
        t = b[5];
        make_vertex(vtx, 0, x, y, z, s, t, r1, g1, b1, alpha);
        break;
    case 1:
        r2 = b[4];
        g2 = b[5];
        b2 = b[6];
        s = b[7];
        t = b[8];
        make_vertex(vtx, 0, x, y, z, s, t, r2, g2, b2, alpha);
        break;
    }
}

void func_802D0A94(Vtx *verts, s32 n, s16 *c, struct MovingTextureGeoList *d, s8 e)
{
    u8 alpha = d->a;
    s16 x;
    s16 y;
    s16 z;
    s16 sp56;
    s16 sp54;
    s16 s;
    s16 t;
    s16 sp4E;
    s16 sp4C;
    u8 r1;
    u8 g1;
    u8 b1;
    s8 r2;
    s8 g2;
    s8 b2;

    switch (e)
    {
    case 0:
        x = c[n * 5 + 1];
        y = c[n * 5 + 2];
        z = c[n * 5 + 3];
        sp56 = c[4];
        sp54 = c[5];
        sp4E = c[n * 5 + 4];
        sp4C = c[n * 5 + 5];
        s = sp56 + ((sp4E * 32) * 32U);
        t = sp54 + ((sp4C * 32) * 32U);
        r1 = d->r;
        g1 = d->g;
        b1 = d->b;
        make_vertex(verts, n, x, y, z, s, t, r1, g1, b1, alpha);
        break;
    case 1:
        x = c[n * 8 + 1];
        y = c[n * 8 + 2];
        z = c[n * 8 + 3];
        sp56 = c[7];
        sp54 = c[8];
        sp4E = c[n * 8 + 7];
        sp4C = c[n * 8 + 8];
        s = sp56 + ((sp4E * 32) * 32U);
        t = sp54 + ((sp4C * 32) * 32U);
        r2 = c[n * 8 + 4];
        g2 = c[n * 8 + 5];
        b2 = c[n * 8 + 6];
        make_vertex(verts, n, x, y, z, s, t, r2, g2, b2, alpha);
        break;
    }
}

Gfx *func_802D0DD4(s16 *a, struct MovingTextureGeoList *b, s8 c)
{
    Vtx *verts = alloc_display_list(b->vtx_count * sizeof(*verts));
    Gfx *sp50 = alloc_display_list(11 * sizeof(*sp50));
    Gfx *sp4C = sp50;
    s32 sp48;

    if (verts == NULL || sp50 == NULL)
        return NULL;
    func_802D08EC(verts, a, b, c);
    for (sp48 = 1; sp48 < b->vtx_count; sp48++)
        func_802D0A94(verts, sp48, a, b, c);
    gSPDisplayList(sp4C++, b->begin_dl)
    gDPSetTextureImage(sp4C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gMovingTextureIdList[b->texture_num])
    gDPTileSync(sp4C++)
    gDPSetTile(sp4C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0,
                G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD)
    gDPLoadSync(sp4C++)
    gDPLoadBlock(sp4C++, 7, 0, 0, 1023, 256)
    gSPVertex(sp4C++, 0x80000000 + (u32)verts, b->vtx_count, 0)
    gSPDisplayList(sp4C++, b->tri_dl)
    gSPDisplayList(sp4C++, b->end_dl)
    gSPEndDisplayList(sp4C)
    return sp50;
}

Gfx *Geo18_802D1B70(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    s32 sp24;
    s16 *sp20;
    struct GraphNode12A *sp1C;
    Gfx *sp18 = NULL;

    if (run == TRUE)
    {
        sp24 = 0;
        sp1C = (struct GraphNode12A *)node;
        while (gMovingTextureTris[sp24].tris != 0)
        {
            if (gMovingTextureTris[sp24].geo_id == sp1C->unk18)
            {
                sp1C->fnNode.node.flags = (sp1C->fnNode.node.flags & 0xFF) | (gMovingTextureTris[sp24].layer << 8);
                sp20 = segmented_to_virtual(gMovingTextureTris[sp24].tris);
                func_802D0850(sp20, 4);
                sp18 = func_802D0DD4(sp20, &gMovingTextureTris[sp24], 0);
                break;
            }
            sp24++;
        }
    }
    return sp18;
}

Gfx *Geo18_802D1CDC(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    s32 sp24;
    s16 *sp20;
    struct GraphNode12A *sp1C;
    Gfx *sp18 = NULL;

    if (run == TRUE)
    {
        sp24 = 0;
        sp1C = (struct GraphNode12A *)node;
        while (gMovingTextureTrisWithRot[sp24].tris != 0)
        {
            if (gMovingTextureTrisWithRot[sp24].geo_id == sp1C->unk18)
            {
                sp1C->fnNode.node.flags = (sp1C->fnNode.node.flags & 0xFF) | (gMovingTextureTrisWithRot[sp24].layer << 8);
                sp20 = segmented_to_virtual(gMovingTextureTrisWithRot[sp24].tris);
                func_802D0850(sp20, 7);
                sp18 = func_802D0DD4(sp20, &gMovingTextureTrisWithRot[sp24], 1);
                break;
            }
            sp24++;
        }
    }
    return sp18;
}

Gfx *Geo18_802D1E48(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    s32 sp24;
    s16 *sp20;
    struct GraphNode12A *sp1C;
    Gfx *sp18 = NULL;

    if (run == TRUE)
    {
        sp24 = 0;
        sp1C = (struct GraphNode12A *)node;
        while (gMovingTextureTrisWithRot[sp24].tris != 0)
        {
            if (gMovingTextureTrisWithRot[sp24].geo_id == sp1C->unk18)
            {
                sp1C->fnNode.node.flags = (sp1C->fnNode.node.flags & 0xFF) | (gMovingTextureTrisWithRot[sp24].layer << 8);
                sp20 = segmented_to_virtual(gMovingTextureTrisWithRot[sp24].tris);
                sp18 = func_802D0DD4(sp20, &gMovingTextureTrisWithRot[sp24], 1);
                break;
            }
            sp24++;
        }
    }
    return sp18;
}

Gfx *Geo18_802D1FA8(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    s32 sp24;
    s16 *sp20;
    struct GraphNode12A *sp1C;
    Gfx *sp18 = NULL;

    if (run == TRUE)
    {
        sp24 = 0;
        sp1C = (struct GraphNode12A *)node;
        while (gMovingTextureTrisWithLight[sp24].tris != 0)
        {
            if (gMovingTextureTrisWithLight[sp24].geo_id == sp1C->unk18)
            {
                sp1C->fnNode.node.flags = (sp1C->fnNode.node.flags & 0xFF) | (gMovingTextureTrisWithLight[sp24].layer << 8);
                sp20 = segmented_to_virtual(gMovingTextureTrisWithLight[sp24].tris);
                sp18 = func_802D0DD4(sp20, &gMovingTextureTrisWithLight[sp24], 1);
                break;
            }
            sp24++;
        }
    }
    return sp18;
}

Gfx *Geo18_802D2108(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    void *sp2C;

    if (run == TRUE)
    {
        struct GraphNode12A *sp28 = (struct GraphNode12A *)node;

        switch (sp28->unk18)
        {
        case 0x0801: sp2C = segmented_to_virtual(ssl_movtex_tris_quicksand_pit);           break;
        case 0x0802: sp2C = segmented_to_virtual(ssl_movtex_tris_pyramid_quicksand_pit);   break;
        case 0x1400: sp2C = segmented_to_virtual(ttc_movtex_tris_big_surface_treadmill);   break;
        case 0x1401: sp2C = segmented_to_virtual(ttc_movtex_tris_small_surface_treadmill); break;
        }
        func_802D0850(sp2C, 7);
    }
    return NULL;
}
