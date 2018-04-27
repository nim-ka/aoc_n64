#include <ultra64.h>
#include "sm64.h"

#include "geo_layout.h"

void GeoLayout00(void)
{
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (u32) &gGeoLayoutCommand[8];
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (D_8038BD78 << 16) + D_8038BD7E;
    D_8038BD7E = gGeoLayoutStackIndex;
    gGeoLayoutCommand = (u8 *) segmented_to_virtual((void *) cur_geo_cmd_s32(0x04));
}

void GeoLayout01(void)
{
    gGeoLayoutStackIndex = D_8038BD7E;
    D_8038BD7E = gGeoLayoutStack[--gGeoLayoutStackIndex] & 0xFFFF;
    D_8038BD78 = gGeoLayoutStack[gGeoLayoutStackIndex] >> 16;
    gGeoLayoutCommand = (u8 *) gGeoLayoutStack[--gGeoLayoutStackIndex];
}

void GeoLayout02(void)
{
    if(cur_geo_cmd_u8(0x01) == 1)
    {
        gGeoLayoutStack[gGeoLayoutStackIndex++] = (u32) &gGeoLayoutCommand[8];
    }

    gGeoLayoutCommand = (u8 *) segmented_to_virtual((void *) cur_geo_cmd_s32(0x04));
}

void GeoLayout03(void)
{
    gGeoLayoutCommand = (u8 *) gGeoLayoutStack[--gGeoLayoutStackIndex];
}

// open node
void GeoLayout04(void)
{
    D_8038BCF8[D_8038BD78 + 1] = D_8038BCF8[D_8038BD78];
    D_8038BD78++;
    gGeoLayoutCommand += 0x04;
}

// close node
void GeoLayout05(void)
{
    D_8038BD78--;
    gGeoLayoutCommand += 0x04;
}

void GeoLayout06(void)
{
    u16 sp6 = cur_geo_cmd_s16(0x02);

    if(sp6 < D_8038BCB0)
    {
        D_8038BCAC[sp6] = D_8038BCF8[D_8038BD78];
    }

    gGeoLayoutCommand += 0x04;
}

// unused
void GeoLayout07(void)
{
    u16 sp6 = cur_geo_cmd_u8(0x01);
    u16 sp4 = cur_geo_cmd_s16(0x02);

    switch(sp6)
    {
        case 0:
            D_8038BCF8[D_8038BD78]->unk02 = sp4;
            break;
        case 1:
            D_8038BCF8[D_8038BD78]->unk02 |= sp4;
            break;
        case 2:
            D_8038BCF8[D_8038BD78]->unk02 &= ~sp4;
            break;
    }

    gGeoLayoutCommand += 0x04;
}

// set screen area
void GeoLayout08(void)
{
    s32 sp34;
    struct SceneGraphScreenAreaNode *screenAreaNode;

    s16 x = cur_geo_cmd_s16(0x04); // x
    s16 y = cur_geo_cmd_s16(0x06); // y
    s16 width = cur_geo_cmd_s16(0x08); // width
    s16 height = cur_geo_cmd_s16(0x0A); // height
    
    // number of entries to allocate for D_8038BCAC array
    D_8038BCB0 = cur_geo_cmd_s16(0x02) + 2; // 0x00 = mario face, 0x0A = all other levels

    screenAreaNode = func_8037B24C(D_8038BCA0, 0, 0, x, y, width, height);

    // TODO: check type
    D_8038BCAC = (struct SceneGraphNode **) SimpleAllocate(D_8038BCA0, D_8038BCB0 * sizeof(s32));

    screenAreaNode->unk20 = D_8038BCAC;
    screenAreaNode->unk1E = D_8038BCB0;
    
    // clear D_8038BCAC array
    for(sp34 = 0; sp34 < D_8038BCB0; sp34++)
    {
        D_8038BCAC[sp34] = NULL;
    }

    RegisterSceneGraphNode((struct SceneGraphNode *) screenAreaNode);

    gGeoLayoutCommand += 0x0C;
}

void GeoLayout09(void)
{
    struct SceneGraphNode *sceneGraphNode;
    f32 sp18 = (f32) cur_geo_cmd_s16(0x02) / 100.0f;
    
    sceneGraphNode = func_8037B30C(D_8038BCA0, 0, sp18);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x04;
}

// set camera frustum
void GeoLayout0A(void)
{
    struct SceneGraphNode *sceneGraphNode;
    s32 frustumProc = 0; // TODO: function type
    s16 fov = cur_geo_cmd_s16(0x02);
    s16 near = cur_geo_cmd_s16(0x04);
    s16 far = cur_geo_cmd_s16(0x06);

    if(cur_geo_cmd_u8(0x01))
    {
        // optional asm function
        frustumProc = cur_geo_cmd_s32(0x08);
        gGeoLayoutCommand += 0x04;
    }

    sceneGraphNode = func_8037B380(D_8038BCA0, 0, (float)fov, near, far, frustumProc, 0);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x08;
}

// start geo layout
void GeoLayout0B(void)
{
    struct SceneGraphNode *sceneGraphNode;
    
    sceneGraphNode = func_8037B448(D_8038BCA0, 0);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x04;
}

void GeoLayout1F(void)
{
    /* no operation */
    gGeoLayoutCommand += 0x10;
}

// toggle zbuffer
void GeoLayout0C(void)
{
    struct SceneGraphNode *sceneGraphNode;
    
    sceneGraphNode = func_8037B4AC(D_8038BCA0, 0, cur_geo_cmd_u8(0x01));

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x04;
}

// set render range
void GeoLayout0D(void)
{
    struct SceneGraphNode *sceneGraphNode;
    s16 minDistance = cur_geo_cmd_s16(0x04);
    s16 maxDistance = cur_geo_cmd_s16(0x06);

    sceneGraphNode = func_8037B530(D_8038BCA0, 0, minDistance, maxDistance);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x08;
}

// switch case
// 0x02 = numCases, 0x04 = asm function
void GeoLayout0E(void)
{
    struct SceneGraphNode *sceneGraphNode;
    
    sceneGraphNode = func_8037B5B4(D_8038BCA0, 0,
        cur_geo_cmd_s16(0x02), // num cases
        0,
        cur_geo_cmd_s32(0x04), // asm routine
        0);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x08;
}

void GeoLayout0F(void)
{
    struct SceneGraphNode *sceneGraphNode;
    u8 *sp38 = &gGeoLayoutCommand[4];

    Vec3i sp2c, sp20;

    sp38 = func_8037CB60(sp2c, sp38);
    sp38 = func_8037CB60(sp20, sp38);

    sceneGraphNode = func_8037B670(D_8038BCA0, 0, sp2c, sp20,
        cur_geo_cmd_s32(0x10),
        cur_geo_cmd_s16(0x02));

    RegisterSceneGraphNode(sceneGraphNode);

    D_8038BCAC[0] = sceneGraphNode;

    gGeoLayoutCommand += 0x14;
}

// translate and rotate
void GeoLayout10(void)
{
    struct SceneGraphNode *sceneGraphNode;

    Vec3s sp44, sp3c;

    s32 sp38 = 0;
    s16 sp36 = 0;

    s16 sp34 = cur_geo_cmd_u8(0x01);
    s16 *sp30 = (s16 *) gGeoLayoutCommand;

    switch((sp34 & 0x70) >> 4)
    {
        case 0:
            sp30 = Copy16BitTriple(sp44, &sp30[2]);
            sp30 = func_8037CBFC(sp3c, sp30);
            break;
        case 1:
            sp30 = Copy16BitTriple(sp44, &sp30[1]);
            vec3s_copy(sp3c, D_80385FDC);
            break;
        case 2:
            sp30 = func_8037CBFC(sp3c, &sp30[1]);
            vec3s_copy(sp44, D_80385FDC);
            break;
        case 3:
            vec3s_copy(sp44, D_80385FDC);
            vec3s_set(sp3c, 0, (sp30[1] << 15) / 180, 0);
            sp30 += 2;
            break;
    }

    if(sp34 & 0x80)
    {
        sp38 = *(s32 *)&sp30[0];
        sp36 = sp34 & 0x0F;
        sp30 += 2;
    }

    sceneGraphNode = func_8037B744(D_8038BCA0, 0, sp36, sp38, sp44, sp3c);
    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand = (u8 *) sp30;
}

void GeoLayout11(void)
{
    struct SceneGraphNode *sceneGraphNode;

    Vec3s sp2c;

    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    s16* sp24 = (s16 *) gGeoLayoutCommand;
    s32 sp20 = 0;

    sp24 = Copy16BitTriple(sp2c, &sp24[1]);

    if(sp28 & 0x80)
    {
        sp20 = *(u32*)&sp24[0];
        sp2a = sp28 & 0x0F;
        sp24 += 2;
    }

    sceneGraphNode = func_8037B7F8(D_8038BCA0, 0, sp2a, sp20, sp2c);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand = (u8 *) sp24;
}

void GeoLayout12(void)
{
    struct SceneGraphNode *sceneGraphNode;

    Vec3s sp2c;

    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    s16* sp24 = (s16 *) gGeoLayoutCommand;
    s32 sp20 = 0;

    // rotation related?
    sp24 = func_8037CBFC(sp2c, &sp24[1]);

    if(sp28 & 0x80)
    {
        sp20 = *(u32*)&sp24[0];
        sp2a = sp28 & 0x0F;
        sp24 += 2;
    }

    sceneGraphNode = func_8037B89C(D_8038BCA0, 0, sp2a, sp20, sp2c);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand = (u8 *) sp24;
}

// scale model
void GeoLayout1D(void)
{
    struct SceneGraphNode *sceneGraphNode;

    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    f32 scale = cur_geo_cmd_u32(0x04) / 65536.0f;
    s32 sp20 = 0;

    if(sp28 & 0x80)
    {
        sp20 = cur_geo_cmd_s32(0x08);
        sp2a = sp28 & 0x0F;
        gGeoLayoutCommand += 0x04;
    }

    sceneGraphNode = func_8037B940(D_8038BCA0, 0, sp2a, sp20, scale);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x08;
}

void GeoLayout1E(void)
{
    /* no operation */
    gGeoLayoutCommand += 0x08;
}

// load display list
void GeoLayout13(void)
{
    struct SceneGraphNode *sceneGraphNode;
    Vec3s relativePos;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *gfx = (void *) cur_geo_cmd_s32(0x08); // dlist segptr
    s16* sp20 = (s16 *) gGeoLayoutCommand;

    Copy16BitTriple(relativePos, &sp20[1]);

    sceneGraphNode = func_8037BB48(D_8038BCA0, 0, drawingLayer, gfx, relativePos);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x0C;
}

void GeoLayout14(void)
{
    struct SceneGraphNode *sceneGraphNode;
    Vec3s sp2c;
    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    s16 *sp24 = (s16 *) gGeoLayoutCommand;
    s32 sp20 = 0;

    sp24 = Copy16BitTriple(sp2c, &sp24[1]);

    if(sp28 & 0x80)
    {
        sp20 = *(s32*)&sp24[0];
        sp2a = sp28 & 0x0F;
        sp24 += 2;
    }

    sceneGraphNode = func_8037BBEC(D_8038BCA0, 0, sp2a, sp20, sp2c);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand = (u8 *) sp24;
}

// load display list
void GeoLayout15(void)
{
    struct SceneGraphDListNode *sceneGraphDListNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *gfx = (void *) cur_geo_cmd_s32(0x04);

    sceneGraphDListNode = func_8037BC90(D_8038BCA0, 0, drawingLayer, gfx);

    RegisterSceneGraphNode((struct SceneGraphNode *) sceneGraphDListNode);

    gGeoLayoutCommand += 0x08;
}

// start geo layout with shadow
void GeoLayout16(void)
{
    struct SceneGraphNode *sceneGraphNode;
    u8 shadowType = cur_geo_cmd_s16(0x02); // shadow type
    u8 shadowSolidity = cur_geo_cmd_s16(0x04); // shadow solidity
    s16 shadowScale = cur_geo_cmd_s16(0x06); // shadow scale

    sceneGraphNode = func_8037BD24(D_8038BCA0, 0, shadowScale, shadowSolidity, shadowType);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x08;
}

void GeoLayout17(void)
{
    struct SceneGraphNode *sceneGraphNode;

    sceneGraphNode = func_8037BDB4(D_8038BCA0, 0, D_8038BD88);

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x04;
}

// load polygons asm
void GeoLayout18(void)
{
    struct SceneGraphNode *sceneGraphNode;

    sceneGraphNode = func_8037BE28(D_8038BCA0, 0,
        cur_geo_cmd_s32(0x04), // asm function
        cur_geo_cmd_s16(0x02)); // parameter

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x08;
}

// set background
void GeoLayout19(void)
{
    struct SceneGraphNode *sceneGraphNode;

    sceneGraphNode = func_8037BECC(D_8038BCA0, 0,
        cur_geo_cmd_s16(0x02), // background ID, or RGBA5551 color if asm function is null
        cur_geo_cmd_s32(0x04), // asm function
        0);
    
    RegisterSceneGraphNode(sceneGraphNode);
    
    gGeoLayoutCommand += 0x08;
}

void GeoLayout1A(void)
{
    /* no operation */
    gGeoLayoutCommand += 0x08;
}

void GeoLayout1B(void)
{
    struct SceneGraphNode *sp24;
    struct SceneGraphNode *sp20 = NULL;
    s16 sp1e = cur_geo_cmd_s16(0x02);

    if(sp1e >= 0)
    {
        sp20 = D_8038BCAC[sp1e];

        if(sp20->type == 0x29)
        {
            sp20 = ((struct SceneGraphNode_x29 *)sp20)->unk14;
        }
        else
        {
            sp20 = NULL;
        }
    }

    sp24 = func_8037BDB4(D_8038BCA0, 0, (u8 *)sp20);

    RegisterSceneGraphNode(sp24);

    gGeoLayoutCommand += 0x04;
}

void GeoLayout1C(void)
{
    struct SceneGraphNode *sceneGraphNode;
    Vec3s sp24;

    Copy16BitTriple(sp24, (s16 *) &gGeoLayoutCommand[0x02]);

    sceneGraphNode = func_8037BF84(D_8038BCA0, 0, 0, sp24, cur_geo_cmd_s32(0x08), cur_geo_cmd_u8(0x01));

    RegisterSceneGraphNode(sceneGraphNode);

    gGeoLayoutCommand += 0x0C;
}

void GeoLayout20(void)
{
    struct SceneGraphNode *sceneGraphNode;
    sceneGraphNode = func_8037BAD4(D_8038BCA0, 0, cur_geo_cmd_s16(0x02));
    RegisterSceneGraphNode(sceneGraphNode);
    gGeoLayoutCommand += 0x04;
}

struct SceneGraphNode *ProcessGeoLayout(struct Struct80278464 *a0, void *segptr)
{
    D_8038BCA4 = NULL;
    D_8038BCB0 = 0; // number of entries in D_8038BCAC

    D_8038BCF8[0] = 0;
    D_8038BD78 = 0; // index of D_8038BCF8

    gGeoLayoutStackIndex = 2;
    D_8038BD7E = 2; // stack index is often copied here

    gGeoLayoutCommand = (u8*) segmented_to_virtual(segptr);

    D_8038BCA0 = a0; 

    gGeoLayoutStack[0] = 0;
    gGeoLayoutStack[1] = 0;

    while(gGeoLayoutCommand != NULL)
    {
        GeoLayoutJumpTable[gGeoLayoutCommand[0x00]]();
    }

    return D_8038BCA4;
}
