#include <ultra64.h>

#include "sm64.h"
#include "obj_behaviors.h"
#include "rendering_graph_node.h"
#include "memory.h"
#include "behavior_script.h"
#include "surface_collision.h"
#include "math_util.h"
#include "display.h"
#include "object_helpers.h"
#include "behavior_data.h"
#include "mario.h"
#include "game.h"
#include "camera.h"
#include "mario_actions_cutscene.h"
#include "object_list_processor.h"
#include "save_file.h"
#include "area.h"
#include "castle_message_behaviors.h"
#include "level_update.h"
#include "audio/interface_2.h"
#include "behavior_actions.h"
#include "spawn_object.h"
#include "spawn_sound.h"
#include "room.h"
#include "ingame_menu_3.h"
#include "ingame_menu.h"

#define o gCurrentObject

#define OBJ_COL_FLAG_GROUNDED (1 << 0)
#define OBJ_COL_FLAG_HIT_WALL (1 << 1)
#define OBJ_COL_FLAG_UNDERWATER (1 << 2)
#define OBJ_COL_FLAG_NO_Y_VEL (1 << 3)
#define OBJ_COL_FLAGS_LANDED (OBJ_COL_FLAG_GROUNDED | OBJ_COL_FLAG_NO_Y_VEL)

struct Surface *D_803600E0;

/* DATA */
s8 D_80331500 = 1;
s16 D_80331504 = 0;
s8 D_80331508 = 0;
s8 D_8033150C = 0;
s8 D_80331510 = 0;

struct ObjectHitbox D_80331514 = {
    0x00000010, 
    0, 1, 0, 0,
    100, 64,
    0, 0
};
struct ObjectHitbox D_80331524 = {
    0x00000010, 
    0, 5, 0, 0,
    100, 64,
    0, 0
};
struct ObjectHitbox D_80331534 = {
    0x00000002, 
    0, 0, 0, 0,
    65, 113,
    0, 0
};
struct ObjectHitbox D_80331544 = {
    0x02000000, 
    0, 0, 0, 0,
    200, 500,
    0, 0
};
struct ObjectHitbox D_80331554 = {
    0x20000000, 
    40, 1, 0, 0,
    40, 50,
    50, 60
};
struct ObjectHitbox D_80331564 = {
    0x00020000, 
    0, 1, 0, 0,
    73, 123,
    63, 0x71,
};
struct ObjectHitbox D_80331574 = {
    0x00020000, 
    0, 1, 0, 0,
    115, 235,
    105, 225,
};
struct ObjectHitbox D_80331584 = {
    0x00008000, 
    0, 2, 1, 0,
    120, 60,
    100, 50,
};
struct ObjectHitbox D_80331594 = {
    0x00000008, 
    0, 2, 1, 0,
    120, 60,
    100, 50,
};
struct ObjectHitbox D_803315A4 = {
    0x00000008, 
    0, 2, 0, 0,
    100, 150,
    0, 0,
};

// TODO: these are likely Waypoint structs
s16 D_803315B4[] = { 
    0x0000, 0xED4E, 0x0065, 0xF78A, 
    0x0001, 0xEC78, 0x0051, 0xF53F, 
    0x0002, 0xEC50, 0x0021, 0xF0FA, 
    0x0003, 0xEC9A, 0x0026, 0xEC9A, 
    0x0004, 0xF053, 0xFEFD, 0xECE3, 
    0x0005, 0xF5F3, 0xFC05, 0xED54, 
    0x0006, 0xFBE3, 0xFA89, 0xED3A, 
    0x0007, 0x02F8, 0xF99B, 0xED1F, 
    0x0008, 0x0B32, 0xF801, 0xECEA, 
    0x0009, 0x0D3A, 0xE66E, 0xED1F, 
    0xFFFF, 0x0000
};
// TODO: these are likely Waypoint structs
s16 D_80331608[] = {
    0x0000, 0xFA3C, 0x001D, 0xFD58, 
    0x0001, 0xFA2C, 0x000E, 0xFBD0, 
    0x0002, 0xFA24, 0x0003, 0xFACD, 
    0x0003, 0xFAA2, 0xFFEF, 0xFA09, 
    0x0004, 0xFB66, 0xFFAD, 0xFA28, 
    0x0005, 0xFEDC, 0xFE58, 0xFA6F, 
    0x0006, 0x00FA, 0xFE15, 0xFA67, 
    0x0007, 0x035E, 0xFD9B, 0xFA57, 
    0x0008, 0x0422, 0xF858, 0xFA57, 
    0xFFFF, 0x0000
};

struct ObjectHitbox D_80331654 = {
    0x00000008, 
    0, 3, 0, 0,
    210, 350,
    0, 0,
};
struct ObjectHitbox D_80331664 = {
    0x00000020, 
    0, 0, 0, 0,
    80, 80,
    90, 90,
};
struct ObjectHitbox D_80331674 = {
    0x00001000, 
    0, 0, 0, 0,
    80, 50,
    0, 0,
};
struct ObjectHitbox D_80331684 = {
    0x00000010, 
    0, 2, 0, 0,
    100, 64,
    0, 0,
};

s8 D_80331694 = 0;

struct ObjectHitbox D_80331698 = {
    0x00000002, 
    20, 0, 1, 0,
    150, 250,
    150, 250,
};

// TODO: these are likely Waypoint structs
s16 D_803316A8[] = {
    0x0000, 0xEE6C, 0xFA9C, 0xFFD8, 
    0x0001, 0xEFE8, 0xF740, 0x02E4, 
    0x0002, 0xF330, 0xF3F8, 0x0410, 
    0x0003, 0xF740, 0xF308, 0x02D0, 
    0x0004, 0xF8D0, 0xF3BC, 0xFEE8, 
    0x0005, 0xF6F0, 0xF650, 0xFBB4, 
    0x0006, 0xF36C, 0xF9C0, 0xFAB0, 
    0x0007, 0xEFAC, 0xFC04, 0xFBF0, 
    0xFFFF, 0x0000
};

struct ObjectHitbox D_803316EC = {
    0x00000008, 
    0, 0, 3, 0,
    210, 60,
    200, 50,
};
struct ObjectHitbox D_803316FC = {
    0x00000008, 
    150, 3, 0, 0,
    150, 300,
    0, 0,
};
struct ObjectHitbox D_8033170C = {
    0x20000000, 
    0, 1, 0, 0,
    300, 300,
    310, 310,
};


s16 D_8033171C[] = {
    0x0000, 0xEA07, 0xFAAC, 0xE8E8, 
    0xFA85, 0xEDFF, 0xFC14, 0xEB44
};

s32 count_objects_with_behavior(void *);

extern void *ccm_seg7_trajectory_snowman;
extern void *inside_castle_seg7_trajectory_mips;

void func_802E2F40(void)
{
    D_80331508 = 0;
}

struct Struct802E2F58 *func_802E2F58(s32 arg0, struct Object *arg1, UNUSED s32 arg2)
{
    struct Struct802E2F58 *sp34;
    s32 (*sp30)[2];
    struct Object *sp2c;
    struct Object *sp28;
    UNUSED struct Object *sp24;
    UNUSED s32 sp20;
    s32 (*sp1c)[2];
    s32 (*sp18)[2];
    
    sp34 = NULL;

    if (arg0 == 1)
    {
        sp2c = (struct Object*)D_8032CFA0;
        sp28 = arg1;
        sp24 = arg1;
        if (D_8032CFA4 != NULL) sp2c = (struct Object*)D_8032CFA4->unk1C;
        
        sp34 = (struct Struct802E2F58 *)alloc_display_list(0x18);
        sp30 = (s32 (*)[2])sp34;
        sp28->header.gfx.node.flags = (sp28->header.gfx.node.flags & 0xFF) | 0x500; //sets bits 8, 10 and zeros upper byte
        sp1c = sp30++;
        (*sp1c)[0] = 0xFB000000;
        (*sp1c)[1] = (s32)(sp2c->oOpacity & 0xFF) | 0xFFFFFF00;
        sp18 = sp30;
        (*sp18)[0] = 0xB8000000;
        (*sp18)[1] = 0;    
    }
    
    return sp34;
}

f32 absf_2(f32 f)
{
    if (f < 0) f *= -1.0f;
    return f;
}

//f12 = objVelX
//f14 = objVelZ
//sp8 = nX
//spc = nY
//sp10 = nZ
//sp14 = objYawX

void TurnObjAwayFromSurface(f32 objVelX, f32 objVelZ, f32 nX, UNUSED f32 nY, f32 nZ, f32 *objYawX, f32 *objYawZ)
{
    *objYawX = (nZ * nZ - nX * nX) * objVelX / (nX * nX + nZ * nZ)
          - 2.0f * objVelZ * (nX * nZ) / (nX * nX + nZ * nZ);

    *objYawZ = (nX * nX - nZ * nZ) * objVelZ / (nX * nX + nZ * nZ)
          - 2.0f * objVelX * (nX * nZ) / (nX * nX + nZ * nZ);
}

//sp78 = objVelX
//sp7c = objVelZ
//sp70, f12 = objNewX
//sp74, f14 = objY
//sp80 = objNewZ
//sp38 = objVelXCopy
//sp34 = objVelZCopy

s32 ObjFindWall(f32 objNewX, f32 objY, f32 objNewZ, f32 objVelX, f32 objVelZ)
{
    struct WallCollisionData hitbox;
    f32 wall_nX, wall_nY, wall_nZ, objVelXCopy, objVelZCopy, objYawX, objYawZ;

    hitbox.x = objNewX;
    hitbox.y = objY;
    hitbox.z = objNewZ;
    hitbox.offsetY = o->hitboxHeight / 2.0f;
    hitbox.radius = o->hitboxRadius;

    if (find_wall_collisions(&hitbox) != 0)
    {
        o->oPosX = hitbox.x;
        o->oPosY = hitbox.y;
        o->oPosZ = hitbox.z;
        wall_nX = hitbox.walls[0]->normal.x;
        wall_nY = hitbox.walls[0]->normal.y;
        wall_nZ = hitbox.walls[0]->normal.z;
        objVelXCopy = objVelX;
        objVelZCopy = objVelZ;
        TurnObjAwayFromSurface(objVelXCopy, objVelZCopy, wall_nX, wall_nY, wall_nZ, &objYawX, &objYawZ);
        o->oMoveAngleYaw = atan2s(objYawZ, objYawX);
        return 0;
    }

    return 1;
}

//sp48 = objFloor
//sp4c = floorY
//sp50 = objVelX
//sp54 = objVelZ
//sp38 = objVelXCopy
//sp34 = objVelZCopy

s32 TurnObjAwayFromAwkwardFloor(struct Surface* objFloor, f32 floorY, f32 objVelX, f32 objVelZ)
{
    float floor_nX, floor_nY, floor_nZ, objVelXCopy, objVelZCopy, objYawX, objYawZ;
    
    if (objFloor == NULL)
    {
        //! TRUNC overflow exception after 36 minutes
        o->oMoveAngleYaw += 32767.999200000002; /* ¯\_(ツ)_/¯ */
        return 0;
    }

    floor_nX = objFloor->normal.x;
    floor_nY = objFloor->normal.y;
    floor_nZ = objFloor->normal.z;

    if (floor_nY < 0.5 && floorY > o->oPosY)
    {
        objVelXCopy = objVelX;
        objVelZCopy = objVelZ;
        TurnObjAwayFromSurface(objVelXCopy, objVelZCopy, floor_nX, floor_nY, floor_nZ, &objYawX, &objYawZ);
        o->oMoveAngleYaw = atan2s(objYawZ, objYawX);
        return 0;
    }

    return 1;
}

//sp38 = obj
//sp3c = normalX
//sp40 = normalY
//sp44 = normalZ

void ObjOrientGraph(struct Object *obj, f32 normalX, f32 normalY, f32 normalZ)
{
    Vec3f sp2c, sp20;

    f32 (*throwMatrix)[4][4]; // TODO: use Mtx type

    if (D_80331500 == 0) return;
    if ((obj->header.gfx.node.flags & 0x4) != 0) return; //bit 2
    throwMatrix = (f32 (*)[4][4])alloc_display_list(0x40);
    if (throwMatrix == NULL) return;

    sp2c[0] = obj->oPosX;
    sp2c[1] = obj->oPosY + obj->oGraphYOffset;
    sp2c[2] = obj->oPosZ;

    sp20[0] = normalX;
    sp20[1] = normalY;
    sp20[2] = normalZ;

    mtxf_from_up_direction(*throwMatrix, sp20, sp2c, obj->oFaceAngleYaw);
    obj->header.gfx.throwMatrix = (void *)throwMatrix;
}

//sp4 = floor_nY

void CalcObjFriction(f32 *objFriction, f32 floor_nY) 
{
    if (floor_nY < 0.2 && o->oFriction < 0.9999) *objFriction = 0;
    else *objFriction = o->oFriction;
}

//sp28 = objFloor
//sp2c = objFloorY
//sp30 = objVelX
//sp34 = objVelZ
//sp24 = floor_nX
//sp20 = floor_nY
//sp1c = floor_nZ

void CalcNewObjVelAndPosY(struct Surface* objFloor, f32 objFloorY, f32 objVelX, f32 objVelZ)
{
    f32 floor_nX = objFloor->normal.x;
    f32 floor_nY = objFloor->normal.y;
    f32 floor_nZ = objFloor->normal.z;
    f32 objFriction;
    
    o->oVelY -= o->oGravity;
    if ((f64)o->oVelY > 75.0) o->oVelY = 75.0;
    if ((f64)o->oVelY < -75.0) o->oVelY = -75.0;
    
    o->oPosY += o->oVelY;
    if (o->oPosY < objFloorY) {
        o->oPosY = objFloorY;
        if ((f64)o->oVelY < -17.5)
            o->oVelY = -(o->oVelY / 2.0f);
        else o->oVelY = 0;
    }

    //! potential TRUNC crash
    if ((s32)o->oPosY >= (s32)objFloorY && (s32)o->oPosY < (s32)objFloorY + 37)
    {
        ObjOrientGraph(o, floor_nX, floor_nY, floor_nZ);
        objVelX += floor_nX * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * o->oGravity * 2.0f;
        objVelZ += floor_nZ * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * o->oGravity * 2.0f;
        
        if (objVelX < 0.000001 && objVelX > -0.000001) objVelX = 0;
        if (objVelZ < 0.000001 && objVelZ > -0.000001) objVelZ = 0;
        
        if (objVelX != 0 || objVelZ != 0) o->oMoveAngleYaw = atan2s(objVelZ, objVelX);
        
        CalcObjFriction(&objFriction, floor_nY);
        o->oForwardVel = sqrtf(objVelX * objVelX + objVelZ * objVelZ) * objFriction;
    }
}

//sp28 = objFloor
//sp2c = floorY
//sp30 = objVelX
//sp34 = objVelZ
//sp38 = waterY
//sp24 = floor_nX
//sp20 = floor_nY
//sp1c = floor_nZ
//sp18 = netYAccel

void CalcNewObjVelAndPosYUnderwater(struct Surface* objFloor, f32 floorY, f32 objVelX, f32 objVelZ, f32 waterY)
{
    f32 floor_nX = objFloor->normal.x;
    f32 floor_nY = objFloor->normal.y;
    f32 floor_nZ = objFloor->normal.z;

    f32 netYAccel = (1.0f - o->oBuoyancy) * (-1.0f * o->oGravity);
    o->oVelY -= netYAccel;
    if (o->oVelY > 75.0) o->oVelY = 75.0;
    if (o->oVelY < -75.0) o->oVelY = -75.0;

    o->oPosY += o->oVelY;
    if (o->oPosY < floorY)
    {
        o->oPosY = floorY;
        if ((f64)o->oVelY < -17.5)
            o->oVelY = -(o->oVelY / 2.0f);
        else o->oVelY = 0;
    }
    
    if ((f64)o->oForwardVel > 12.5 && (waterY + 30.0f) > o->oPosY && waterY - 30.0f < o->oPosY)
        o->oVelY = -o->oVelY;
    
    if ((s32)o->oPosY >= (s32)floorY && (s32)o->oPosY < (s32)floorY + 37)
    {
        ObjOrientGraph(o, floor_nX, floor_nY, floor_nZ);
        objVelX += floor_nX * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * netYAccel * 2.0f;
        objVelZ += floor_nZ * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * netYAccel * 2.0f;
    }
    
    if (objVelX < 0.000001 && objVelX > -0.000001) objVelX = 0;
    if (objVelZ < 0.000001 && objVelZ > -0.000001) objVelZ = 0;
    
    if ((f64)o->oVelY < 0.000001 && (f64)o->oVelY > -0.000001) o->oVelY = 0;
    
    if (objVelX != 0 || objVelZ != 0) o->oMoveAngleYaw = atan2s(objVelZ, objVelX);
    o->oForwardVel = sqrtf(objVelX * objVelX + objVelZ * objVelZ) * 0.8;
    o->oVelY *= 0.8;
}

//sp4 = xVel
//sp0 = zVel

void ObjUpdatePosVelXZ(void)
{
    f32 xVel = o->oForwardVel * sins(o->oMoveAngleYaw);
    f32 zVel = o->oForwardVel * coss(o->oMoveAngleYaw);

    o->oPosX += xVel;
    o->oPosZ += zVel;
}

//sp20 = waterY
//sp24 = objY
//sp1c = globalTimer

void ObjSplash(s32 waterY, s32 objY)
{
    u32 globalTimer = gGlobalTimer;
    if ((f32)(waterY + 30) > o->oPosY && o->oPosY > (f32)(waterY - 30))
    {
        spawn_object(o, 0xA6, beh_object_water_wave);
        if (o->oVelY < -20.0f) PlaySound2(0x50324081);
    }
    
    if ((objY + 50) < waterY && (globalTimer & 0x1F) == 0) spawn_object(o, 0xA4, beh_object_bubble); /* 0x1F is bits 4-0 */
}

//sp3c = objX
//sp38 = objY
//sp34 = objZ
//sp28 = objVelX
//sp24 = objVelZ
//sp30 = floorY
//sp2c = waterY
//sp22 = collisionFlags

s16 ObjectStep(void)
{
    f32 objX = o->oPosX;
    f32 objY = o->oPosY;
    f32 objZ = o->oPosZ;
    f32 floorY;
    f32 waterY = -10000.0;
    f32 objVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
    f32 objVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);
    s16 collisionFlags = 0;
    
    if (ObjFindWall(objX + objVelX, objY, objZ + objVelZ, objVelX, objVelZ) == 0) collisionFlags += OBJ_COL_FLAG_HIT_WALL;
    
    floorY = find_floor(objX + objVelX, objY, objZ + objVelZ, &D_803600E0);
    
    if (TurnObjAwayFromAwkwardFloor(D_803600E0, floorY, objVelX, objVelZ) == 1)
    {
        waterY = find_water_level(objX + objVelX, objZ + objVelZ);
        if (waterY > objY)
        {
            CalcNewObjVelAndPosYUnderwater(D_803600E0, floorY, objVelX, objVelZ, waterY);
            collisionFlags += OBJ_COL_FLAG_UNDERWATER;
        }
        else CalcNewObjVelAndPosY(D_803600E0, floorY, objVelX, objVelZ);
    }
    else collisionFlags += ((collisionFlags & OBJ_COL_FLAG_HIT_WALL) ^ OBJ_COL_FLAG_HIT_WALL); /* bit 1 = 1 */
    
    ObjUpdatePosVelXZ();
    if ((s32)o->oPosY == (s32)floorY) collisionFlags += OBJ_COL_FLAG_GROUNDED;
    if ((s32)o->oVelY == 0) collisionFlags += OBJ_COL_FLAG_NO_Y_VEL;
    
    ObjSplash((s32)waterY, (s32)o->oPosY);
    
    return collisionFlags;
}

//sp1e = collisionFlags

s16 func_802E4204(void)
{
    s16 collisionFlags = 0;
    D_80331500 = 0;
    collisionFlags = ObjectStep();
    D_80331500 = 1;

    return collisionFlags;
}

void func_802E4250(struct Object* obj)
{
    o->oVelX = obj->oForwardVel * sins(obj->oMoveAngleYaw);
    o->oVelZ = obj->oForwardVel * coss(obj->oMoveAngleYaw);

    obj->oPosX += o->oVelX;
    obj->oPosY += obj->oVelY;
    obj->oPosZ += o->oVelZ;
}

//sp18 = arg2

s32 IsPointCloseToMario(f32 x, f32 y, f32 z, s32 dist)
{
    f32 mGfxX = gMarioObject->header.gfx.pos[0];
    f32 mGfxY = gMarioObject->header.gfx.pos[1];
    f32 mGfxZ = gMarioObject->header.gfx.pos[2];

    if ((x - mGfxX) * (x - mGfxX) + (y - mGfxY) * (y - mGfxY) + (z - mGfxZ) * (z - mGfxZ) < (f32)(dist * dist))
        return 1;

    return 0;
}

//sp14 = x
//sp18 = y
//sp1c = z
//spc = objX
//sp8 = objY
//sp4 = objZ

s32 IsPointCloseToObject(struct Object* obj, f32 x, f32 y, f32 z, s32 dist)
{
    f32 objX = obj->oPosX;
    f32 objY = obj->oPosY;
    f32 objZ = obj->oPosZ;
    
    if ((x - objX) * (x - objX) + (y - objY) * (y - objY) + (z - objZ) * (z - objZ) < (f32)(dist * dist))
        return 1;
    
    return 0;
}

//sp28 = obj
//sp2c = arg1
//sp24 = objX
//sp20 = objY
//sp1c = objZ

void SetObjectVisibility(struct Object* obj, s32 arg1)
{
    f32 objX = obj->oPosX;
    f32 objY = obj->oPosY;
    f32 objZ = obj->oPosZ;

    if (IsPointCloseToMario(objX, objY, objZ, arg1) == 1) obj->header.gfx.node.flags &= ~0x10; /* bit 4 = 0 */
    else obj->header.gfx.node.flags |= 0x10; /* bit 4 = 1 */
}

//sp28 = obj
//sp2c = homeX
//sp30 = y
//sp34 = homeZ


s32 ObjLeaveIfMarioIsNearHome(struct Object* obj, f32 homeX, f32 y, f32 homeZ, s32 dist)
{
    f32 homeDistX = homeX - obj->oPosX;
    f32 homeDistZ = homeZ - obj->oPosZ;
    s16 angleAwayFromHome = atan2s(homeDistZ, homeDistX);

    if (IsPointCloseToMario(homeX, y, homeZ, dist) == 1) return 1;
    else
    {
        obj->oMoveAngleYaw = approach_s16_symmetric(obj->oMoveAngleYaw, angleAwayFromHome, 320);
    }

    return 0;
}

//sp28 = obj
//sp2c = homeX
//sp30 = homeY
//sp34 = homeZ

void ObjDisplaceHome(struct Object* obj, f32 homeX, UNUSED f32 homeY, f32 homeZ, s32 baseDisp)
{
    s16 angleToNewHome;
    f32 homeDistX, homeDistZ;

    if ((s32)(RandomFloat() * 50.0f) == 0)
    {
        obj->oHomeX = (f32)(baseDisp * 2) * RandomFloat() - (f32)baseDisp + homeX;
        obj->oHomeZ = (f32)(baseDisp * 2) * RandomFloat() - (f32)baseDisp + homeZ;
    }

    homeDistX = obj->oHomeX - obj->oPosX;
    homeDistZ = obj->oHomeZ - obj->oPosZ;
    angleToNewHome = atan2s(homeDistZ, homeDistX);
    obj->oMoveAngleYaw = approach_s16_symmetric(obj->oMoveAngleYaw, angleToNewHome, 320);
}

s32 func_802E46C0(u32 arg0, u32 arg1, s16 arg2)
{
    s16 sp6 = (u16)arg1 - (u16)arg0;
    
    if (((f32)sins(-arg2) < (f32)sins(sp6))
    &&  ((f32)sins(sp6) < (f32)sins(arg2))
    &&  (coss(sp6) > 0))
        return 1;
    
    return 0;
}

//sp60= arg0
//sp64 = x
//sp68 = y
//sp6c = z
//sp38 = hitbox

s32 func_802E478C(Vec3f dist, f32 x, f32 y, f32 z, f32 arg4)
{
    struct WallCollisionData hitbox;
    UNUSED u8 filler[0x20];

    hitbox.x = x;
    hitbox.y = y;
    hitbox.z = z;
    hitbox.offsetY = 10.0f;
    hitbox.radius = arg4;
    if (find_wall_collisions(&hitbox) != 0)
    {
        dist[0] = hitbox.x - x;
        dist[1] = hitbox.y - y;
        dist[2] = hitbox.z - z;
        return 1;
    }
    else return 0;
}

//sp20 = obj
//sp24 = nCoins

void ObjSpawnYellowCoins(struct Object *obj, s32 nCoins)
{
    struct Object *coin;
    s8 count;

    for(count = 0; count < (s8)nCoins; count++)
    {
        coin = spawn_object(obj, 0x74, beh_moving_yellow_coin);
        coin->oForwardVel = RandomFloat() * 20.0f;
        coin->oVelY = RandomFloat() * 40.0f + 20.0f;
        coin->oMoveAngleYaw = RandomU16();
    }
}

s32 ObjFlickerAndDisappear(struct Object *obj, s16 arg1)
{
    if (obj->oTimer < arg1) return 0;
    if (obj->oTimer < arg1 + 40)
    {
        if (obj->oTimer % 2 != 0) obj->header.gfx.node.flags |= 0x10; /* bit 4 = 1 */
        else obj->header.gfx.node.flags &= ~0x10; /* bit 4 = 0 */
    }
    else
    {
        obj->activeFlags = 0;
        return 1;
    }

    return 0;
}

s8 func_802E49A4(s16 arg0)
{
    s16 sp6;

    if (gMarioCurrentRoom == 0)
    {
        if (arg0 == D_80331504) return 1;
        else return 0;
    }
    else
    {
        if (arg0 == gMarioCurrentRoom) sp6 = 1;
        else sp6 = 0;
        
        D_80331504 = gMarioCurrentRoom;
    }
    
    return sp6;
}

//sp20 = arg0
//sp24 = arg1
//sp28 = arg2
//sp2c = arg3

s16 func_802E4A38(s32 *arg0, s16 arg1, f32 arg2, s32 arg3)
{
    s16 sp1e;

    if
    (
           (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, (s32)arg2) == 1
        &&  func_802E46C0(o->oFaceAngleYaw, gMarioObject->header.gfx.angle[1] + 0x8000, 0x1000) == 1
        &&  func_802E46C0(o->oMoveAngleYaw, o->oAngleToMario, 0x1000) == 1)
    ||
           (*arg0 == 1)
    )
    {
        *arg0 = 1;
        if (set_mario_npc_dialogue(arg3) == 2)
        {
            sp1e = func_8028F8E0(162, o, arg1);
            if (sp1e != 0)
            {
                set_mario_npc_dialogue(0);
                *arg0 = 0;
                return sp1e;
            }
            return 0;
        }
    }

    return 0;
}

void ObjCheckFloorDeath(s16 collisionFlags, struct Surface *floor)
{
    if (floor == NULL) return;

    if ((collisionFlags & 0x1) == 1) /* bit 0 */
    {
        switch (floor->type)
        {
            case SURFACE_LAVA: o->oAction = OBJ_ACT_LAVA_DEATH; break;
            case SURFACE_DEATH_PLANE: o->oAction = OBJ_ACT_DEATH_PLANE_DEATH; break;
            default: break;
        }
    }
}

//sp10 = arg0

s32 ObjLavaDeath(void)
{
    struct Object* deathSmoke;
    
    if (o->oTimer >= 31) 
    {
        o->activeFlags = 0;
        return 1;
    }
    else o->oPosY -= 10.0f;
    
    if ((o->oTimer % 8) == 0)
    {
        PlaySound2(0x5118A081);
        deathSmoke = spawn_object(o, 0x96, beh_bobomb_bully_death_smoke);
        deathSmoke->oPosX += RandomFloat() * 20.0f;
        deathSmoke->oPosY += RandomFloat() * 20.0f;
        deathSmoke->oPosZ += RandomFloat() * 20.0f;
        deathSmoke->oForwardVel = RandomFloat() * 10.0f;
    }
    
    return 0;
}

//sp30 = arg0
//sp34 = arg1
//sp38 = arg2
//sp3c = arg3

void SpawnOrangeNumber(s8 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    struct Object* orangeNumber;
    
    if (arg0 >= 10) return;

    orangeNumber = spawn_object_relative(arg0, arg1, arg2, arg3, o, 219, beh_orange_number);
    orangeNumber->oPosY += 25.0f;
}

s32 Unknown802E4DF4(s16 *arg0)
{
    if (*(arg0 + D_8033150C) == 0)
    {
        D_8033150C = 0;
        return 1;
    }

    if ((*(arg0 + D_8033150C) & gPlayer3Controller->buttonPressed) != 0)
    {
        D_8033150C++;
        D_80331510 = 0;
    }
    else if (D_80331510 == 10 || gPlayer3Controller->buttonPressed != 0)
    {
        D_8033150C = 0;
        D_80331510 = 0;
        return 0;
    }  
    D_80331510++;
    
    return 0;
}

#include "behaviors/moving_coin.c.inc"
#include "behaviors/seaweed.c.inc"
#include "behaviors/bobomb.c.inc"
#include "behaviors/cannon_door.c.inc"
#include "behaviors/whirlpool.c.inc"
#include "behaviors/amp.c.inc"
#include "behaviors/butterfly.c.inc"
#include "behaviors/hoot.c.inc"
#include "behaviors/beta_green_shell.c.inc"
#include "behaviors/bubble.c.inc"
#include "behaviors/water_wave.c.inc"
#include "behaviors/explosion.c.inc"
#include "behaviors/corkbox.c.inc"
#include "behaviors/bully.c.inc"
#include "behaviors/water_ring.c.inc"
#include "behaviors/bowser_bomb.c.inc"
#include "behaviors/celebration_star.c.inc"
#include "behaviors/drawbridge.c.inc"
#include "behaviors/bomp.c.inc"
#include "behaviors/sliding_platform.c.inc"
#include "behaviors/moneybag.c.inc"
#include "behaviors/bowling_ball.c.inc"
#include "behaviors/cruiser.c.inc"
#include "behaviors/spindel.c.inc"
#include "behaviors/pyramid_wall.c.inc"
#include "behaviors/pyramid_elevator.c.inc"
#include "behaviors/pyramid_top.c.inc"

// not part of behavior files
// or are they? TODO: misc.c.inc?

void BehWaterfallSoundLoop(void) {
    PlaySound(0x40010001);
}

void BehVolcanoSoundLoop(void) {
    PlaySound(0x41030001);
}

void BehCastleFlagWavingInit(void) {
    o->header.gfx.unk38.animFrame = RandomFloat() * 28.0f;
}

void BehBirdsSoundLoop(void) {
    if (D_8033B860->unk0 == 3)
        return;

    switch(o->oBehParams2ndByte) {
        case 0:
            PlaySound(0x90524001);
            break;

        case 1:
            PlaySound(0x80504001);
            break;

        case 2:
            PlaySound(0x50514001);
            break;
    }
}

void BehAmbiantSoundsInit(void) {
    if (D_8033B860->unk0 == 3)
        return;

    SetSound(0x60104001, D_803320E0);
}

void BehSandSoundLoop(void) {
    if (D_8033B860->unk0 == 3)
        return;

    PlaySound(0x400E0001);
}

void BehHiddenAt120StarsInit(void) {
    if (save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24) >= 120) 
        o->activeFlags = 0;
}

#include "behaviors/snowman.c.inc"
#include "behaviors/boulder.c.inc"
#include "behaviors/cap.c.inc"
#include "behaviors/spawn_star.c.inc"
#include "behaviors/red_coin.c.inc"
#include "behaviors/hidden_star.c.inc"
#include "behaviors/rolling_log.c.inc"
#include "behaviors/mushroom_1up.c.inc"
#include "behaviors/controllable_platform.c.inc"
#include "behaviors/breakable_box_small.c.inc"
#include "behaviors/snow_mound.c.inc"
#include "behaviors/floating_platform.c.inc"
#include "behaviors/arrow_lift.c.inc"
#include "behaviors/orange_number.c.inc"
#include "behaviors/manta_ray.c.inc"
#include "behaviors/falling_pillar.c.inc"
#include "behaviors/floating_box.c.inc"
#include "behaviors/pendulum.c.inc"
#include "behaviors/treasure_chest.c.inc"
#include "behaviors/mips.c.inc"
#include "behaviors/yoshi.c.inc"
