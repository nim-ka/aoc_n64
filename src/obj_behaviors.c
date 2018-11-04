#include <ultra64.h>

#include "sm64.h"
#include "obj_behaviors.h"
#include "graph_node.h"
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
#include "audio_interface_2.h"
#include "behavior_actions.h"
#include "spawn_object.h"
#include "spawn_sound.h"

#define o gCurrentObject

#define OBJ_COL_FLAG_GROUNDED (1 << 0)
#define OBJ_COL_FLAG_HIT_WALL (1 << 1)
#define OBJ_COL_FLAG_UNDERWATER (1 << 2)
#define OBJ_COL_FLAG_NO_Y_VEL (1 << 3)
#define OBJ_COL_FLAGS_LANDED (OBJ_COL_FLAG_GROUNDED | OBJ_COL_FLAG_NO_Y_VEL)

//FIXME: Unclear what files these functions belong to so I declared them here
extern void PlaySound(u32);

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

f32 absf(f32 f)
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
        wall_nX = hitbox.walls[0]->normal[0];
        wall_nY = hitbox.walls[0]->normal[1];
        wall_nZ = hitbox.walls[0]->normal[2];
        objVelXCopy = objVelX;
        objVelZCopy = objVelZ;
        TurnObjAwayFromSurface(objVelXCopy, objVelZCopy, wall_nX, wall_nY, wall_nZ, &objYawX, &objYawZ);
        o->oAngleYaw = atan2s(objYawZ, objYawX);
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
        o->oAngleYaw += 32767.999200000002; /* ¯\_(ツ)_/¯ */
        return 0;
    }

    floor_nX = objFloor->normal[0];
    floor_nY = objFloor->normal[1];
    floor_nZ = objFloor->normal[2];

    if (floor_nY < 0.5 && floorY > o->oPosY)
    {
        objVelXCopy = objVelX;
        objVelZCopy = objVelZ;
        TurnObjAwayFromSurface(objVelXCopy, objVelZCopy, floor_nX, floor_nY, floor_nZ, &objYawX, &objYawZ);
        o->oAngleYaw = atan2s(objYawZ, objYawX);
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
    f32 floor_nX = objFloor->normal[0];
    f32 floor_nY = objFloor->normal[1];
    f32 floor_nZ = objFloor->normal[2];
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
        
        if (objVelX != 0 || objVelZ != 0) o->oAngleYaw = atan2s(objVelZ, objVelX);
        
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
    f32 floor_nX = objFloor->normal[0];
    f32 floor_nY = objFloor->normal[1];
    f32 floor_nZ = objFloor->normal[2];

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
    
    if (objVelX != 0 || objVelZ != 0) o->oAngleYaw = atan2s(objVelZ, objVelX);
    o->oForwardVel = sqrtf(objVelX * objVelX + objVelZ * objVelZ) * 0.8;
    o->oVelY *= 0.8;
}

//sp4 = xVel
//sp0 = zVel

void ObjUpdatePosVelXZ(void)
{
    f32 xVel = o->oForwardVel * sins(o->oAngleYaw);
    f32 zVel = o->oForwardVel * coss(o->oAngleYaw);

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
        SpawnObj(o, 0xA6, beh_object_water_wave);
        if (o->oVelY < -20.0f) PlaySound2(0x50324081);
    }
    
    if ((objY + 50) < waterY && (globalTimer & 0x1F) == 0) SpawnObj(o, 0xA4, beh_object_bubble); /* 0x1F is bits 4-0 */
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
    f32 objVelX = o->oForwardVel * sins(o->oAngleYaw);
    f32 objVelZ = o->oForwardVel * coss(o->oAngleYaw);
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
    o->oVelX = obj->oForwardVel * sins(obj->oAngleYaw);
    o->oVelZ = obj->oForwardVel * coss(obj->oAngleYaw);

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
        obj->oAngleYaw = approach_target_angle(obj->oAngleYaw, angleAwayFromHome, 320);
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
    obj->oAngleYaw = approach_target_angle(obj->oAngleYaw, angleToNewHome, 320);
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
        coin = SpawnObj(obj, 0x74, beh_moving_yellow_coin);
        coin->oForwardVel = RandomFloat() * 20.0f;
        coin->oVelY = RandomFloat() * 40.0f + 20.0f;
        coin->oAngleYaw = RandomU16();
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
        obj->active = 0;
        return 1;
    }

    return 0;
}

s8 func_802E49A4(s16 arg0)
{
    s16 sp6;

    if (D_8035FEE0 == 0)
    {
        if (arg0 == D_80331504) return 1;
        else return 0;
    }
    else
    {
        if (arg0 == D_8035FEE0) sp6 = 1;
        else sp6 = 0;
        
        D_80331504 = D_8035FEE0;
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
        &&  func_802E46C0(o->oAngleYaw, o->oAngleToMario, 0x1000) == 1)
    ||
           (*arg0 == 1)
    )
    {
        *arg0 = 1;
        if (func_802573C8(arg3) == 2)
        {
            sp1e = func_8028F8E0(162, o, arg1);
            if (sp1e != 0)
            {
                func_802573C8(0);
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
            case 1: o->oAction = OBJ_ACT_LAVA_DEATH; break;
            case 10: o->oAction = OBJ_ACT_DEATH_PLANE_DEATH; break;
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
        o->active = 0;
        return 1;
    }
    else o->oPosY -= 10.0f;
    
    if ((o->oTimer % 8) == 0)
    {
        PlaySound2(0x5118A081);
        deathSmoke = SpawnObj(o, 0x96, beh_bobomb_bully_death_smoke);
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

    orangeNumber = spawn_obj_adv(arg0, arg1, arg2, arg3, o, 219, beh_orange_number);
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

//sp18 = collisionFlagsPtr

s32 CoinStep(s16 *collisionFlagsPtr)
{
    *collisionFlagsPtr = ObjectStep();
    
    ObjCheckFloorDeath(*collisionFlagsPtr, D_803600E0);
    
    if ((*collisionFlagsPtr & 0x1) != 0 && (*collisionFlagsPtr & 0x8) == 0) /* bit 0, bit 3 */
    {
        PlaySound2(0x30364081);
        return 1;
    }
    
    return 0;
}

void MovingCoinFlickerLoop(void)
{
    s16 collisionFlags;
    
    CoinStep(&collisionFlags);
    ObjFlickerAndDisappear(o, 0);
}

void CoinCollected(void)
{
    SpawnObj(o, 149, beh_golden_coin_sparkles);
    o->active = 0;
}

void BehMovingYellowCoinInit(void)
{
    o->oGravity = 3.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 1.5f;
    
    func_802A2CFC(o, &D_80331514);
}

void BehMovingYellowCoinLoop(void)
{
    s16 collisionFlags;
    switch (o->oAction)
    {
        case MOV_YCOIN_ACT_IDLE:
            CoinStep(&collisionFlags);
            
            if (o->oTimer < 10) func_8029FE38();
            else func_8029FE58();
            
            if (o->oTimer >= 301) o->oAction = 1;
            break;
            
        case MOV_YCOIN_ACT_BLINKING:
            MovingCoinFlickerLoop();
            break;
            
        case MOV_YCOIN_ACT_LAVA_DEATH:
            o->active = 0;
            break;
            
        case MOV_YCOIN_ACT_DEATH_PLANE_DEATH:
            o->active = 0;
            break;
    }

    if ((o->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        o->oInteractStatus = 0;
    }
}

void BehMovingBlueCoinInit(void)
{
    o->oGravity = 5.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 1.5f;
    
    func_802A2CFC(o, &D_80331524);
}

void BehMovingBlueCoinLoop(void)
{
    s16 collisionFlags;

    switch (o->oAction)
    {
        case MOV_BCOIN_ACT_STILL:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1500) != 0)
                o->oAction = 1;
            break;

        case MOV_BCOIN_ACT_MOVING:
            collisionFlags = ObjectStep();
            if ((collisionFlags & 0x1) != 0) /* bit 0 */
            {
                o->oForwardVel += 25.0f;
                if ((collisionFlags & 0x8) == 0) PlaySound2(0x30364081); /* bit 3 */
            }
            else o->oForwardVel *= 0.98;
            
            if ((f64)o->oForwardVel > 75.0) o->oForwardVel = 75.0f;
            
            ObjFlickerAndDisappear(o, 600);
            break;
    }
    
    if ((o->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        o->oInteractStatus = 0;
    }
}

void BehBlueCoinSlidingJumpingInit(void)
{
    o->oGravity = 3.0;
    o->oFriction = 0.98;
    o->oBuoyancy = 1.5;
    
    func_802A2CFC(o, &D_80331524);
}

void func_802E540C(void)
{
    s16 collisionFlags;
    
    o->oForwardVel = 15.0;
    o->oAngleYaw = o->oAngleToMario + 0x8000;
    
    if (CoinStep(&collisionFlags) != 0) o->oVelY += 18.0f;
    if ((collisionFlags & 0x2) != 0) o->oAction = 3; /* bit 1 */
    
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1000) == 0)
        o->oAction = 2;
}

void func_802E54DC(void)
{
    s16 collisionFlags;
    
    CoinStep(&collisionFlags);
    
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 500) == 1)
        o->oAction = 1;
    
    if (o->oTimer >= 151)
        o->oAction = 3;
}

void BehBlueCoinSlidingLoop(void)
{
    s16 collisionFlags;

    switch (o->oAction)
    {
        case 0:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 500) == 1)
                o->oAction = 1;
            
            SetObjectVisibility(o, 3000);
            break;
    
        case 1:
            func_802E540C();
            break;
            
        case 2:
            func_802E54DC();
            SetObjectVisibility(o, 3000);
            break;

        case 3:
            CoinStep(&collisionFlags);
            if (o->oTimer >= 61)
                o->oAction = 4;
            break;
            
        case 4:
            MovingCoinFlickerLoop();
            break;
            
        case 100:
            o->active = 0;
            break;
            
        case 101:
            o->active = 0;
            break;
    }

    if ((o->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        o->oInteractStatus = 0;
    }
}

void BehBlueCoinJumpingLoop(void)
{
    s16 collisionFlags;

    switch (o->oAction)
    {
        case 0:
            if (o->oTimer == 0)
            {
                func_8029FE38();
                o->oVelY = 50.0;
            }
            
            ObjectStep();
            
            if (o->oTimer == 15)
            {
                func_8029FE58();
                o->oAction = 1;
            }
            break;
            
        case 1:
            func_802E540C();
            break;
            
        case 2:
            func_802E54DC();
            SetObjectVisibility(o, 3000);
            break;

        case 3:
            CoinStep(&collisionFlags);
            if (o->oTimer >= 61) o->oAction = 4;
            break;
            
        case 4:
            MovingCoinFlickerLoop();
            break;
    }
    
    if ((o->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        o->oInteractStatus = 0;
    }
}

void BehSeaweedInit(void)
{
    o->header.gfx.unk38.animFrame = RandomFloat() * 80.0f;
}

void BehSeaweedBundleInit(void)
{
    struct Object *seaweed;

    seaweed = SpawnObj(o, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 14523;
    seaweed->oFaceAnglePitch = 5500;
    seaweed->oFaceAngleRoll = 9600;
    seaweed->header.gfx.scale[0] = 1.0;
    seaweed->header.gfx.scale[1] = 1.0;
    seaweed->header.gfx.scale[2] = 1.0;
    //!gfx.animFrame uninitialized

    seaweed = SpawnObj(o, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 41800;
    seaweed->oFaceAnglePitch = 6102;
    seaweed->oFaceAngleRoll = 0;
    seaweed->header.gfx.scale[0] = 0.8;
    seaweed->header.gfx.scale[1] = 0.9;
    seaweed->header.gfx.scale[2] = 0.8;
    seaweed->header.gfx.unk38.animFrame = RandomFloat() * 80.0f;

    seaweed = SpawnObj(o, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 40500;
    seaweed->oFaceAnglePitch = 8700;
    seaweed->oFaceAngleRoll = 4100;
    seaweed->header.gfx.scale[0] = 0.8;
    seaweed->header.gfx.scale[1] = 0.8;
    seaweed->header.gfx.scale[2] = 0.8;
    seaweed->header.gfx.unk38.animFrame = RandomFloat() * 80.0f;

    seaweed = SpawnObj(o, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 57236;
    seaweed->oFaceAnglePitch = 9500;
    seaweed->oFaceAngleRoll = 0;
    seaweed->header.gfx.scale[0] = 1.2;
    seaweed->header.gfx.scale[1] = 1.2;
    seaweed->header.gfx.scale[2] = 1.2;
    seaweed->header.gfx.unk38.animFrame = RandomFloat() * 80.0f;
}

void BehBobombInit(void)
{
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    o->oUnk190 = 0x100;
}

void func_802E5B7C(void)
{
    if (((o->oUnk188 >> 8) & 0x1) == 0)
    {
        ObjSpawnYellowCoins(o, 1);
        o->oUnk188 = 0x100;
        func_8029C6D8(o, 1);
    }
}

void BobombExplodeLoop(void)
{
    struct Object *explosion;
    if (o->oTimer < 5) ScaleObject(1.0 + (f32)o->oTimer / 5.0);
    else
    {
        explosion = SpawnObj(o, 205, beh_explosion);
        explosion->oGraphYOffset += 100.0f;
        
        func_802E5B7C();
        RespawnBobombOrCorkbox(0xBC, beh_bobomb, 3000);
        o->active = 0;
    }
}

void CheckBobombInteractions(void)
{
    func_802A2CFC(o, &D_80331534);
    if ((o->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        if ((o->oInteractStatus & 0x2) != 0) /* bit 1 */
        {
            o->oAngleYaw = gMarioObject->header.gfx.angle[1];
            o->oForwardVel = 25.0;
            o->oVelY = 30.0;
            o->oAction = BOBOMB_ACT_LAUNCHED;
        }

        if ((o->oInteractStatus & 0x800000) != 0) /* bit 23 */
            o->oAction = BOBOMB_ACT_EXPLODE;

        o->oInteractStatus = 0;
    }

    if (func_802A4964(o) == 1) o->oAction = BOBOMB_ACT_EXPLODE;
}

void BobombPatrolLoop(void)
{
    UNUSED s8 filler[4];
    UNUSED s16 sp22;
    s16 collisionFlags;

    sp22 = o->header.gfx.unk38.animFrame;
    o->oForwardVel = 5.0;

    collisionFlags = ObjectStep();
    if ((ObjLeaveIfMarioIsNearHome(o, o->oHomeX, o->oHomeY, o->oHomeZ, 400) == 1)
    &&  (func_802E46C0(o->oAngleYaw, o->oAngleToMario, 0x2000) == 1))
    {
        o->oBobombFuseLit = 1;
        o->oAction = BOBOMB_ACT_CHASE_MARIO;
    }
    ObjCheckFloorDeath(collisionFlags, D_803600E0);
}

void BobombChaseMarioLoop(void)
{
    UNUSED u8 filler[4];
    s16 sp1a, collisionFlags;

    sp1a = ++o->header.gfx.unk38.animFrame;
    o->oForwardVel = 20.0;

    collisionFlags = ObjectStep();

    if (sp1a == 5 || sp1a == 16) PlaySound2(0x50270081);

    UnknownMove(o, gMarioObject, 16, 0x800);
    ObjCheckFloorDeath(collisionFlags, D_803600E0);
}

void BobombLaunchedLoop(void)
{
    s16 collisionFlags = 0;
    collisionFlags = ObjectStep();
    if ((collisionFlags & 0x1) == 1) o->oAction = BOBOMB_ACT_EXPLODE; /* bit 0 */
}

void GenericBobombFreeLoop(void)
{
    switch (o->oAction)
    {
        case BOBOMB_ACT_PATROL:
            BobombPatrolLoop();
            break;
            
        case BOBOMB_ACT_LAUNCHED:
            BobombLaunchedLoop();
            break;
            
        case BOBOMB_ACT_CHASE_MARIO:
            BobombChaseMarioLoop();
            break;
            
        case BOBOMB_ACT_EXPLODE:
            BobombExplodeLoop();
            break;
            
        case BOBOMB_ACT_LAVA_DEATH:
            if (ObjLavaDeath() == 1) RespawnBobombOrCorkbox(188, beh_bobomb, 3000);
            break;
            
        case BOBOMB_ACT_DEATH_PLANE_DEATH:
            o->active = 0;
            RespawnBobombOrCorkbox(188, beh_bobomb, 3000);
            break;
    }
    
    CheckBobombInteractions();
    
    if (o->oBobombFuseTimer >= 151) o->oAction = 3;
}

void StationaryBobombFreeLoop(void)
{
    switch (o->oAction)
    {
        case BOBOMB_ACT_LAUNCHED:
            BobombLaunchedLoop();
            break;
            
        case BOBOMB_ACT_EXPLODE:
            BobombExplodeLoop();
            break;
            
        case BOBOMB_ACT_LAVA_DEATH:
            if (ObjLavaDeath() == 1) RespawnBobombOrCorkbox(188, beh_bobomb, 3000);
            break;
            
        case BOBOMB_ACT_DEATH_PLANE_DEATH:
            o->active = 0;
            RespawnBobombOrCorkbox(188, beh_bobomb, 3000);
            break;
    }
    
    CheckBobombInteractions();
    
    if (o->oBobombFuseTimer >= 151) o->oAction = 3;
}

void BobombFreeLoop(void)
{
    if (o->oBehParam == BOBOMB_BP_STYPE_GENERIC) GenericBobombFreeLoop();
    else StationaryBobombFreeLoop();
}

void BobombHeldLoop(void)
{
    o->header.gfx.node.flags |= 0x10; /* bit 4 */
    SetObjAnimation(1);
    func_8029EF64(gMarioObject, 0, 60.0f, 100.0);

    o->oBobombFuseLit = 1;
    if (o->oBobombFuseTimer >= 151)
    {
        //! Although the Bob-omb's action is set to explode when the fuse timer expires,
        //  BobombExplodeLoop() will not execute until the bob-omb's held state changes. 
        //  This allows the Bob-omb to be regrabbed indefinitely.                        
            
        gMarioObject->oInteractStatus |= 0x8; /* bit 3 */
        o->oAction = BOBOMB_ACT_EXPLODE;
    }
}

void BobombDroppedLoop(void)
{
    func_8029FCF8();

    o->header.gfx.node.flags &= ~0x10; /* bit 4 = 0 */
    SetObjAnimation(0);

    o->oHeldState = 0;
    o->oAction = BOBOMB_ACT_PATROL;
}

void BobombThrownLoop(void)
{
    func_8029F0A4();

    o->header.gfx.node.flags &= ~0x10; /* bit 4 = 0 */
    o->oHeldState = 0;
    o->oFlags &= ~0x8; /* bit 3 */
    o->oForwardVel = 25.0;
    o->oVelY = 20.0;
    o->oAction = BOBOMB_ACT_LAUNCHED;
}

//sp18 = blinkTimer

void ObjRandomBlink(s32 *blinkTimer)
{
    if (*blinkTimer == 0)
    {
        if ((s16)(RandomFloat() * 100.0f) == 0)
        {
            o->oAnimState = 1;
            *blinkTimer = 1;
        }
    }
    else
    {
        (*blinkTimer)++;
        if (*blinkTimer >= 6) o->oAnimState = 0;
        if (*blinkTimer >= 11) o->oAnimState = 1;
        if (*blinkTimer >= 16) 
        {
            o->oAnimState = 0;
            *blinkTimer = 0;
        }
    }
}

void BehBobombLoop(void)
{
    s8 dustPeriodMinus1;
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 4000) != 0)
    {
        switch (o->oHeldState)
        {
            case HELD_FREE:
                BobombFreeLoop();
                break;
                
            case HELD_HELD:
                BobombHeldLoop();
                break;
                
            case HELD_THROWN:
                BobombThrownLoop();
                break;
                
            case HELD_DROPPED:
                BobombDroppedLoop();
                break;
        }
    
        ObjRandomBlink(&o->oBobombBlinkTimer);
        
        if (o->oBobombFuseLit == 1)
        {
            if (o->oBobombFuseTimer >= 121) dustPeriodMinus1 = 1;
            else dustPeriodMinus1 = 7;
        
            if ((dustPeriodMinus1 & o->oBobombFuseTimer) == 0) /* oBobombFuseTimer % 2 or oBobombFuseTimer % 8 */
                SpawnObj(o, 150, beh_bobomb_fuse_smoke);
                
            PlaySound(0x60086001);
            
            o->oBobombFuseTimer++;
        }
    }
}

void BehBobombFuseSmokeInit(void)
{
    o->oPosX += (s32)(RandomFloat() * 80.0f) - 40;
    o->oPosY += (s32)(RandomFloat() * 80.0f) + 60;
    o->oPosZ += (s32)(RandomFloat() * 80.0f) - 40;
    ScaleObject(1.2f);
}

void BehBobombBuddyInit(void)
{
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    o->oUnk190 = 0x4000;
}

void BobombBuddyIdleLoop(void)
{
    UNUSED u8 filler[4];
    s16 sp1a = o->header.gfx.unk38.animFrame;
    UNUSED s16 collisionFlags = 0;

    o->oBobombBuddyPosXCopy = o->oPosX;
    o->oBobombBuddyPosYCopy = o->oPosY;
    o->oBobombBuddyPosZCopy = o->oPosZ;

    collisionFlags = ObjectStep();

    if ((sp1a == 5) || (sp1a == 16)) PlaySound2(0x50270081);

    if (o->oDistanceToMario < 1000.0f)
        o->oAngleYaw = approach_target_angle(o->oAngleYaw, o->oAngleToMario, 0x140);

    if (o->oInteractStatus == 0x8000) o->oAction = BOBOMB_BUDDY_ACT_TURN_TO_TALK;
}

//sp30 = arg0
//sp34 = arg1

void BobombBuddyCannonLoop(s16 arg0, s16 arg1)
{
    struct Object* sp2c;
    s16 sp2a, sp28;
    
    switch (o->oBobombBuddyCannonStatus)
    {
        case BOBOMB_BUDDY_CANNON_UNOPENED:
            sp2a = func_8028F8E0(162, o, arg0);
            if (sp2a != 0)
            {
                save_file_set_cannon_unlocked();
                sp2c = func_8029F1E0(beh_cannon_trap_door);
                if (sp2c != 0) o->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_OPENING;
                else o->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_STOP_TALKING;
            }
            break;
            
        case BOBOMB_BUDDY_CANNON_OPENING:
            sp2c = func_8029F1E0(beh_cannon_trap_door);
            sp28 = func_8028F9E8(150, sp2c);
            if (sp28 == -1) o->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_OPENED;
            break;
            
        case BOBOMB_BUDDY_CANNON_OPENED:
            sp2a = func_8028F8E0(162, o, arg1);
            if (sp2a != 0) o->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_STOP_TALKING;
            break;
            
        case BOBOMB_BUDDY_CANNON_STOP_TALKING:
            func_802573C8(0);
            
            o->active &= ~0x20; /* bit 5 */
            o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
            o->oInteractStatus = 0;
            o->oAction = BOBOMB_BUDDY_ACT_IDLE;
            o->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_OPENED;
            break;
    }
}

void BobombBuddyTalkLoop(void)
{
    if (func_802573C8(1) == 2)
    {
        o->active |= 0x20; /* bit 5 */

        switch (o->oBobombBuddyRole)
        {
            case BOBOMB_BUDDY_ROLE_ADVICE:
                if (func_8028F8E0(162, o, o->oBehParam) != BOBOMB_BUDDY_BP_STYPE_GENERIC)
                {
                    func_802573C8(0);

                    o->active &= ~0x20; /* bit 5 */
                    o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
                    o->oInteractStatus = 0;
                    o->oAction = BOBOMB_BUDDY_ACT_IDLE;
                }
                break;

            case BOBOMB_BUDDY_ROLE_CANNON:
                if (gCurrCourseNum == COURSE_BOB) BobombBuddyCannonLoop(4, 105);
                else BobombBuddyCannonLoop(47, 106);
                break;
        }
    }
}

void BobombBuddyTurnToTalkLoop(void)
{
    s16 sp1e = o->header.gfx.unk38.animFrame;
    if ((sp1e == 5) || (sp1e == 16)) PlaySound2(0x50270081);
    
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, o->oAngleToMario, 0x1000);
    if ((s16)o->oAngleYaw == (s16)o->oAngleToMario)
        o->oAction = BOBOMB_BUDDY_ACT_TALK;
    
    PlaySound2(0x045BFF81);
}

void BobombBuddyActionLoop(void)
{
    switch (o->oAction)
    {
        case BOBOMB_BUDDY_ACT_IDLE:
            BobombBuddyIdleLoop();
            break;
            
        case BOBOMB_BUDDY_ACT_TURN_TO_TALK:
            BobombBuddyTurnToTalkLoop();
            break;
            
        case BOBOMB_BUDDY_ACT_TALK:
            BobombBuddyTalkLoop();
            break;
    }

    SetObjectVisibility(o, 3000);
}

void BehBobombBuddyLoop(void)
{
    BobombBuddyActionLoop();
    
    ObjRandomBlink(&o->oBobombBuddyBlinkTimer);
    
    o->oInteractStatus = 0;
}

void BehCannonTrapDoorInit(void)
{
    struct Object *cannonTrapDoor;

    if (save_file_is_cannon_unlocked() == 1)
    {
        cannonTrapDoor = SpawnObj(o, 128, beh_cannon_base);
        cannonTrapDoor->oBehParam = o->oBehParam;
        cannonTrapDoor->oPosX = o->oHomeX;
        cannonTrapDoor->oPosY = o->oHomeY;
        cannonTrapDoor->oPosZ = o->oHomeZ;

        o->oAction = CANNON_TRAP_DOOR_ACT_OPEN;
        o->active = 0;
    }
}

void CannonTrapDoorOpeningLoop(void)
{
    if (o->oTimer == 0) PlaySound2(0x30478081);

    if (o->oTimer < 30)
    {
        o->oVelY = -0.5f;
        o->oPosY += o->oVelY;
        o->oVelX = 0;
    }
    else
    {
        if (o->oTimer == 80)
        {
            BehCannonTrapDoorInit();
            return;
        }

        o->oVelX = 4.0f;
        o->oVelY = 0;
        o->oPosX += o->oVelX;
    }
}

void BehCannonTrapDoorLoop(void)
{
    switch (o->oAction)
    {
        case CANNON_TRAP_DOOR_ACT_CLOSED:
            o->oVelX = 0;
            o->oVelY = 0;
            o->oDrawingDistance = 4000.0f;
            
            if (save_file_is_cannon_unlocked() == 1)
                o->oAction = CANNON_TRAP_DOOR_ACT_CAM_ZOOM;
            break;
            
        case CANNON_TRAP_DOOR_ACT_CAM_ZOOM:
            if (o->oTimer == 60) o->oAction = CANNON_TRAP_DOOR_ACT_OPENING;
            
            o->oDrawingDistance = 20000.0f;
            break;
            
        case CANNON_TRAP_DOOR_ACT_OPENING:
            CannonTrapDoorOpeningLoop();
            break;
    }
}

void BehWhirlpoolInit(void)
{
    o->oWhirlpoolInitFacePitch = o->oFaceAnglePitch;
    o->oWhirlpoolInitFaceRoll = o->oFaceAngleRoll;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
}

void func_802E70A8(void)
{
    func_802A2CFC(o, &D_80331544);
}

void func_802E70DC(void)
{
    f32 cosPitch = coss(o->oFaceAnglePitch);
    f32 sinPitch = sins(o->oFaceAnglePitch);
    f32 cosRoll = coss(o->oFaceAngleRoll);
    f32 sinRoll = sins(o->oFaceAngleRoll);
    f32 normalX = sinRoll * cosPitch;
    f32 normalY = cosPitch * cosRoll;
    f32 normalZ = sinPitch;
    ObjOrientGraph(o, normalX, normalY, normalZ);
}

void BehWhirlpoolLoop(void)
{
    if (o->oDistanceToMario < 5000.0f)
    {
        o->header.gfx.node.flags &= ~0x10; /* bit 4 */

        //not sure if actually an array
        D_803600B0[7] = 60;
        D_803600B0[1] = o->oPosX;
        D_803600B0[3] = o->oPosZ;
        D_803600B0[4] = o->oPosX;
        D_803600B0[5] = o->oPosY;
        D_803600B0[6] = o->oPosZ;
        D_803600B0[2] = o->oPosY + 800.0f;
        D_803600B0[8] = o->oWhirlpoolInitFacePitch;
        D_803600B0[9] = o->oWhirlpoolInitFaceRoll;
        
        func_802E70DC();
        
        o->oFaceAngleYaw += 0x1F40;
    }
    else
    {
        o->header.gfx.node.flags |= 0x10; /* bit 4 */
        D_803600B0[7] = 0;
    }

    PlaySound(0x40090001);

    func_802E70A8();
}

void BehJetStreamLoop(void)
{
    if (o->oDistanceToMario < 5000.0f)
    {
        D_803600B0[7] = 60;
        D_803600B0[1] = o->oPosX;
        D_803600B0[2] = o->oPosY;
        D_803600B0[3] = o->oPosZ;
    }
    else D_803600B0[7] = 0;

    PlaySound(0x40090001);
}

void BehAmpHomingInit(void)
{
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oGravity = 0;
    o->oFriction = 1.0;
    o->oBuoyancy = 1.0;
    o->oAmpHomingAvgY = o->oHomeY;

    ScaleObject(0.1f);
    o->header.gfx.node.flags |= 0x10; /* bit 4 */
}

void CheckAmpAttack(void)
{
    func_802A2CFC(o, &D_80331554);
    if (o->oInteractStatus & 0x8000) /* bit 15 */
    {
        if (o->oInteractStatus & 0x8000) /* bit 15 */
            o->oAction = AMP_HOMING_ACT_ATTACK_COOLDOWN;
            
        o->oInteractStatus = 0;
    }
}

void AmpHomingAppearLoop(void)
{
    f32 sp24 = D_8033B328.unk0[3][0] - o->oPosX;
    f32 sp20 = D_8033B328.unk0[3][2] - o->oPosZ;
    s16 targetYaw = atan2s(sp20, sp24);
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, targetYaw, 0x1000);
    
    if (o->oTimer < 30)
        ScaleObject(0.1 + 0.9 * (f32)(o->oTimer / 30.0f));
    else o->oAnimState = 1;
    
    if (o->oTimer >= 91)
    {
        ScaleObject(1.0f);
        o->oAction = AMP_HOMING_ACT_CHASE;
        o->oAmpHomingYPhase = 0;
    }
}

void AmpHomingChaseLoop(void)
{
    if ((o->oAngleToMario - 0x400 < o->oAngleYaw)
    &&  (o->oAngleYaw < o->oAngleToMario + 0x400))
    {
        o->oAmpHomingLockedOn = 1;
        o->oTimer = 0;
    }

    if (o->oAmpHomingLockedOn == 1)
    {
        o->oForwardVel = 15.0f;

        if (o->oAmpHomingAvgY > gMarioObject->header.gfx.pos[1] + 150.0f)
            o->oAmpHomingAvgY -= 10.0f;
        else o->oAmpHomingAvgY = gMarioObject->header.gfx.pos[1] + 150.0f;

        if (o->oTimer >= 31) o->oAmpHomingLockedOn = 0;
    }
    else
    {
        o->oForwardVel = 10.0f;

        UnknownMove(o, gMarioObject, 16, 0x400);

        if (o->oAmpHomingAvgY < gMarioObject->header.gfx.pos[1] + 250.0f)
            o->oAmpHomingAvgY += 10.0f;
    }

    o->oPosY = o->oAmpHomingAvgY + sins(o->oAmpHomingYPhase * 0x400) * 20.0f;

    CheckAmpAttack();

    if (IsPointCloseToMario(o->oHomeX, o->oHomeY, o->oHomeZ, 1500) == 0)
        o->oAction = AMP_HOMING_ACT_GIVE_UP;
}

void AmpHomingGiveUpLoop(void)
{
    UNUSED u8 filler[8];
    
    o->oForwardVel = 15.0f;
    
    if (o->oTimer >= 151)
    {
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        o->header.gfx.node.flags |= 0x10; /* bit 4 */
        o->oAction = AMP_HOMING_ACT_INACTIVE;
        o->oAnimState = 0;
        o->oForwardVel = 0;
        o->oAmpHomingAvgY = o->oHomeY;
    }
}

void AmpAttackCooldownLoop(void)
{
    o->header.gfx.unk38.animFrame += 2;
    o->oForwardVel = 0;

    func_8029FE38();

    if (o->oTimer >= 31) o->oAnimState = 0;
    if (o->oTimer >= 91)
    {
        o->oAnimState = 1;
        func_8029FE58();
        o->oAction = AMP_HOMING_ACT_CHASE;
    }
}

void BehAmpHomingLoop(void)
{
    switch (o->oAction)
    {
        case AMP_HOMING_ACT_INACTIVE:
            if (IsPointCloseToMario(o->oHomeX, o->oHomeY, o->oHomeZ, 800) == 1)
            {
                o->oAction = AMP_HOMING_ACT_APPEAR;
                o->header.gfx.node.flags &= ~0x10; /* bit 4 */
            }
            break;

        case AMP_HOMING_ACT_APPEAR:
            AmpHomingAppearLoop();
            break;

        case AMP_HOMING_ACT_CHASE:
            AmpHomingChaseLoop();
            PlaySound(0x60034001);
            break;
            
        case AMP_HOMING_ACT_GIVE_UP:
            AmpHomingGiveUpLoop();
            break;
            
        case AMP_HOMING_ACT_ATTACK_COOLDOWN:
            AmpAttackCooldownLoop();
            break;
    }
    
    ObjectStep();
    
    o->oAmpHomingYPhase++;
}

void BehAmpInit(void)
{
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oAnimState = 1;
    
    switch (o->oBehParam)
    {
        case AMP_BP_ROT_RADIUS_200:
            o->oAmpRadiusOfRotation = 200.0f;
            break;
            
        case AMP_BP_ROT_RADIUS_300:
            o->oAmpRadiusOfRotation = 300.0f;
            break;
            
        case AMP_BP_ROT_RADIUS_400:
            o->oAmpRadiusOfRotation = 400.0f;
            break;
            
        case AMP_BP_ROT_RADIUS_0:
            break;
    }
    
    o->oAngleYaw = RandomU16();
    o->oAction = 2;
}

void FixedAmpIdleLoop(void)
{
    f32 xToMario = gMarioObject->header.gfx.pos[0] - o->oPosX;
    f32 yToMario = gMarioObject->header.gfx.pos[1] + 120.0f - o->oPosY;
    f32 zToMario = gMarioObject->header.gfx.pos[2] - o->oPosZ;
    s16 vAngleToMario = atan2s(sqrtf(xToMario * xToMario + zToMario * zToMario), -yToMario);

    UnknownMove(o, gMarioObject, 19, 0x1000);
    o->oFaceAnglePitch = approach_target_angle(o->oFaceAnglePitch, vAngleToMario, 0x1000);

    o->oPosY = o->oHomeY + coss(o->oAmpYPhase * 0x458) * 20.0f;

    CheckAmpAttack();

    o->oAmpYPhase++;
}

void AmpIdleLoop(void)
{
    o->oPosX = o->oHomeX + sins(o->oAngleYaw) * o->oAmpRadiusOfRotation;
    o->oPosZ = o->oHomeZ + coss(o->oAngleYaw) * o->oAmpRadiusOfRotation;
    o->oPosY = o->oHomeY + coss(o->oAmpYPhase * 0x8B0) * 30.0f;
    o->oAngleYaw += 0x400;
    o->oFaceAngleYaw = o->oAngleYaw + 0x4000;
    
    CheckAmpAttack();
    
    o->oAmpYPhase++;
    
    PlaySound(0x60034001);
}

void BehAmpLoop(void)
{
    switch (o->oAction)
    {
        case AMP_ACT_IDLE:
            if (o->oBehParam == AMP_BP_ROT_RADIUS_0) FixedAmpIdleLoop();
            else AmpIdleLoop();
            break;

        case AMP_ATTACK_COOLDOWN:
            AmpAttackCooldownLoop();
            break;
    }
}

void BehButterflyInit(void)
{
    SetObjAnimation(1);

    o->oButterflyYPhase = RandomFloat() * 100.0f;
    o->header.gfx.unk38.animFrame = RandomFloat() * 7.0f;
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
}

//sp28 = speed

void ButterflyStep(s32 speed)
{
    f32 *sp24;
    s16 yaw = o->oAngleYaw;
    s16 pitch = o->oAnglePitch;
    s16 yPhase = o->oButterflyYPhase;
    f32 floorY;
    
    o->oVelX = sins(yaw) * (f32)speed;
    o->oVelY = sins(pitch) * (f32)speed;
    o->oVelZ = coss(yaw) * (f32)speed;
    
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    
    if (o->oAction == BUTTERFLY_ACT_FOLLOW_MARIO)
        o->oPosY -= o->oVelY + coss((s32)(yPhase * 655.36)) * 20.0f / 4.0f;
    else o->oPosY -= o->oVelY;
    
    floorY = func_803814B8(o->oPosX, o->oPosY, o->oPosZ, &sp24);
    
    if (o->oPosY < floorY + 2.0f) o->oPosY = floorY + 2.0f;
    
    o->oButterflyYPhase++;
    if (o->oButterflyYPhase >= 101) o->oButterflyYPhase = 0;
}

void CalculateButterflyAngle(void)
{
    gMarioObject->oPosX += 5 * o->oButterflyYPhase / 4;
    gMarioObject->oPosZ += 5 * o->oButterflyYPhase / 4;
    UnknownMove(o, gMarioObject, 16, 0x300);
    gMarioObject->oPosX -= 5 * o->oButterflyYPhase / 4;
    gMarioObject->oPosZ -= 5 * o->oButterflyYPhase / 4;

    gMarioObject->oPosY += (5 * o->oButterflyYPhase + 0x100) / 4;
    UnknownMove(o, gMarioObject, 15, 0x500);
    gMarioObject->oPosY -= (5 * o->oButterflyYPhase + 0x100) / 4;
}

void ButterflyRestingLoop(void)
{
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1000))
    {
        SetObjAnimation(0);

        o->oAction = BUTTERFLY_ACT_FOLLOW_MARIO;
        o->oAngleYaw = gMarioObject->header.gfx.angle[1];
    }
}

void ButterflyFollowMarioLoop(void)
{
    CalculateButterflyAngle();
    
    ButterflyStep(7);
    
    if (!IsPointCloseToMario(o->oHomeX, o->oHomeY, o->oHomeZ, 1200))
        o->oAction = BUTTERFLY_ACT_RETURN_HOME;
}

void ButterflyReturnHomeLoop(void)
{
    f32 homeDistX = o->oHomeX - o->oPosX;
    f32 homeDistY = o->oHomeY - o->oPosY;
    f32 homeDistZ = o->oHomeZ - o->oPosZ;
    s16 hAngleToHome = atan2s(homeDistZ, homeDistX);
    s16 vAngleToHome = atan2s(sqrtf(homeDistX * homeDistX + homeDistZ * homeDistZ), -homeDistY);
    
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, hAngleToHome, 0x800);
    o->oAnglePitch = approach_target_angle(o->oAnglePitch, vAngleToHome, 0x50);
    
    ButterflyStep(7);
    
    if (homeDistX * homeDistX + homeDistY * homeDistY + homeDistZ * homeDistZ < 144.0f)
    {
        SetObjAnimation(1);
        
        o->oAction = BUTTERFLY_ACT_RESTING;
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
    }
}

void BehButterflyLoop(void)
{
    switch (o->oAction)
    {
        case BUTTERFLY_ACT_RESTING:
            ButterflyRestingLoop();
            break;
            
        case BUTTERFLY_ACT_FOLLOW_MARIO:
            ButterflyFollowMarioLoop();
            break;
            
        case BUTTERFLY_ACT_RETURN_HOME:
            ButterflyReturnHomeLoop();
            break;
    }

    SetObjectVisibility(o, 3000);
}

void BehHootInit(void)
{
    SetObjAnimation(0);

    o->oHomeX = o->oPosX + 800.0f;
    o->oHomeY = o->oPosY - 150.0f;
    o->oHomeZ = o->oPosZ + 300.0f;
    o->header.gfx.node.flags |= 0x10; /* bit 4 */

    func_8029FE38();
}

//sp28 = arg0
//sp2c = arg1

f32 HootFindNextFloor(f32 **arg0, f32 arg1)
{
    f32 sp24 = arg1 * sins(o->oAngleYaw) + o->oPosX;
    UNUSED f32 sp20 = o->oPosY;
    f32 sp1c = arg1 * coss(o->oAngleYaw) + o->oPosZ;
    f32 floorY = func_803814B8(sp24, 10000.0f, sp1c, arg0);
    
    return floorY;
}

void HootFloorBounce(void)
{
    f32 *sp1c;
    f32 floorY;
    
    floorY = HootFindNextFloor(&sp1c, 375.0f);
    if (floorY + 75.0f > o->oPosY) o->oAnglePitch -= 3640.8888;
    
    floorY = HootFindNextFloor(&sp1c, 200.0f);
    if (floorY + 125.0f > o->oPosY) o->oAnglePitch -= 7281.7776;
    
    floorY = HootFindNextFloor(&sp1c, 0);
    if (floorY + 125.0f > o->oPosY) o->oPosY = floorY + 125.0f;
    if ((f64)o->oAnglePitch < -21845.3328) o->oAnglePitch = -21845;
}

//sp30 = fastOscY
//sp34 = speed

void HootFreeStep(s16 fastOscY, s32 speed)
{
    f32 *sp2c;
    s16 yaw = o->oAngleYaw;
    s16 pitch = o->oAnglePitch;
    s16 sp26 = o->header.gfx.unk38.animFrame;
    f32 xPrev = o->oPosX;
    f32 zPrev = o->oPosZ;
    f32 hSpeed;
    
    o->oVelY = sins(pitch) * speed;
    hSpeed = coss(pitch) * speed;
    o->oVelX = sins(yaw) * hSpeed;
    o->oVelZ = coss(yaw) * hSpeed;
    
    o->oPosX += o->oVelX;
    if (fastOscY == 0)
        o->oPosY -= o->oVelY + coss((s32)(sp26 * 3276.8)) * 50.0f / 4.0f;
    else
        o->oPosY -= o->oVelY + coss((s32)(sp26 * 6553.6)) * 50.0f / 4.0f;
    o->oPosZ += o->oVelZ;
    
    func_803814B8(o->oPosX, o->oPosY, o->oPosZ, &sp2c);
    if (sp2c == NULL)
    {
        o->oPosX = xPrev;
        o->oPosZ = zPrev;
    }
    
    if (sp26 == 0) PlaySound2(0x300A0081);
}

void PlayerSetHootYaw(void)
{
    s16 stickX = gPlayer3Controller->rawStickX;
    s16 stickY = gPlayer3Controller->rawStickY;
    UNUSED s16 pitch = o->oAnglePitch;
    if (stickX < 10 && stickX >= -9) stickX = 0;
    if (stickY < 10 && stickY >= -9) stickY = 0;
    
    o->oAngleYaw -= 5 * stickX;
}

//sp28 = speed
//sp2c = xPrev
//sp30 = zPrev

void HootCarryStep(s32 speed, UNUSED f32 xPrev, UNUSED f32 zPrev)
{
    s16 yaw = o->oAngleYaw;
    s16 pitch = o->oAnglePitch;
    s16 sp22 = o->header.gfx.unk38.animFrame;
    f32 hSpeed;
    
    o->oVelY = sins(pitch) * speed;
    hSpeed = coss(pitch) * speed;
    o->oVelX = sins(yaw) * hSpeed;
    o->oVelZ = coss(yaw) * hSpeed;
    
    o->oPosX += o->oVelX;
    o->oPosY -= o->oVelY + coss((s32)(sp22 * 6553.6)) * 50.0f / 4.0f;
    o->oPosZ += o->oVelZ;
    
    if (sp22 == 0) PlaySound2(0x300A0081);
}

//sp48 = xPrev
//sp4c = yPrev
//sp50 = zPrev

void HootSurfaceCollision(f32 xPrev, UNUSED f32 yPrev, f32 zPrev)
{
    f32 *sp44;
    struct WallCollisionData hitbox;
    f32 floorY;
    
    hitbox.x = o->oPosX;
    hitbox.y = o->oPosY;
    hitbox.z = o->oPosZ;
    hitbox.offsetY = 10.0;
    hitbox.radius = 50.0;
    
    if (find_wall_collisions(&hitbox) != 0)
    {
        o->oPosX = hitbox.x;
        o->oPosY = hitbox.y;
        o->oPosZ = hitbox.z;
        gMarioObject->oInteractStatus |= 0x80; /* bit 7 */
    }
    
    floorY = func_803814B8(o->oPosX, o->oPosY, o->oPosZ, &sp44);
    if (sp44 == NULL)
    {
        o->oPosX = xPrev;
        o->oPosZ = zPrev;
        return;
    }
    
    
    if (absf(o->oPosX) > 8000.0f) o->oPosX = xPrev;
    if (absf(o->oPosZ) > 8000.0f) o->oPosZ = zPrev;
    if (floorY + 125.0f > o->oPosY) o->oPosY = floorY + 125.0f;
}

//sp28 = xPrev
//sp2c = zPrev

void HootAscentLoop(f32 xPrev, f32 zPrev)
{
    f32 negX = 0 - o->oPosX;
    f32 negZ = 0 - o->oPosZ;
    s16 angleToOrigin = atan2s(negZ, negX);
    
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, angleToOrigin, 0x500);
    o->oAnglePitch = 0xCE38;
    
    if (o->oTimer >= 29)
    {
        PlaySound(0x40108001);
        o->header.gfx.unk38.animFrame = 1;
    }
    
    if (o->oPosY > 6500.0f) o->oAction = HOOT_ACT_CARRY;
    
    HootCarryStep(60, xPrev, zPrev);
}

void HootActionLoop(void)
{
    f32 xPrev = o->oPosX;
    f32 yPrev = o->oPosY;
    f32 zPrev = o->oPosZ;
    
    switch (o->oAction)
    {
        case HOOT_ACT_ASCENT:
            HootAscentLoop(xPrev, zPrev);
            break;
            
        case HOOT_ACT_CARRY:
            PlayerSetHootYaw();
            
            o->oAnglePitch = 0x71C;
            
            if (o->oPosY < 2700.0f)
            {
                func_802A3FA8(10);
                
                if (func_8028F8E0(162, o, 45))
                {
                    func_802A3FCC(10);
                    
                    o->oAction = HOOT_ACT_TIRED;
                }
            }
            
            HootCarryStep(20, xPrev, zPrev);
            break;
            
        case HOOT_ACT_TIRED:
            PlayerSetHootYaw();
            
            o->oAnglePitch = 0;
            
            HootCarryStep(20, xPrev, zPrev);
            
            if (o->oTimer >= 61) gMarioObject->oInteractStatus |= 0x80; /* bit 7 */
            break;
    }
    
    HootSurfaceCollision(xPrev, yPrev, zPrev);
}

void HootTurnToHome(void)
{
    f32 homeDistX = o->oHomeX - o->oPosX;
    f32 homeDistY = o->oHomeY - o->oPosY;
    f32 homeDistZ = o->oHomeZ - o->oPosZ;
    s16 hAngleToHome = atan2s(homeDistZ, homeDistX);
    s16 vAngleToHome = atan2s(sqrtf(homeDistX * homeDistX + homeDistZ * homeDistZ), -homeDistY);
    
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, hAngleToHome, 0x140);
    o->oAnglePitch = approach_target_angle(o->oAnglePitch, vAngleToHome, 0x140);
}

void HootAwakeLoop(void)
{
    if (o->oInteractStatus == 0x1)
    {
        HootActionLoop();
        
        SetObjAnimation(1);
    }
    else
    {
        SetObjAnimation(0);
        
        HootTurnToHome();
        HootFloorBounce();
        HootFreeStep(0, 10);
        
        o->oAction = 0;
        o->oTimer = 0;
    }
    
    SetObjectVisibility(o, 2000);
}

void BehHootLoop(void)
{
    switch (o->oHootAvailability)
    {
        case HOOT_AVAIL_ASLEEP_IN_TREE:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 50))
            {
                o->header.gfx.node.flags &= ~0x10; /* bit 4 */
                o->oHootAvailability = HOOT_AVAIL_WANTS_TO_TALK;
            }
            break;
            
        case HOOT_AVAIL_WANTS_TO_TALK:
            HootAwakeLoop();
            
            if (func_802573C8(2) == 2 && func_8028F8E0(162, o, 44))
            {
                func_802573C8(0);
                
                func_8029FE58();
                
                o->oHootAvailability = HOOT_AVAIL_READY_TO_FLY;
            }
            break;
            
        case HOOT_AVAIL_READY_TO_FLY:
            HootAwakeLoop();
            break;
    }
}

void BehBetaGreenShellInit(void)
{
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
}

void BetaGreenShellDropped(void)
{
    HideObject();
    
    func_8029FCF8();
    
    o->oHeldState = HELD_FREE;
    o->oForwardVel = 0;
    o->oVelY = 0;
}

void BetaGreenShellThrown(void)
{
    func_8029F0A4();
    
    HideObject();
    
    o->oHeldState = HELD_FREE;
    o->oFlags &= ~0x8; /* bit 3 */
    o->oForwardVel = 40.0;
    o->oVelY = 20.0;
}

void BehBetaGreenShellLoop(void)
{
    switch (o->oHeldState)
    {
        case HELD_FREE:
            ObjectStep();
            break;
            
        case HELD_HELD:
            func_8029EEF0();
            break;
            
        case HELD_THROWN:
            BetaGreenShellThrown();
            break;
            
        case HELD_DROPPED:
            BetaGreenShellDropped();
            break;
    }
}

void BehObjectBubbleInit(void)
{
    o->oPosX += RandomFloat() * 30.0f;
    o->oPosY += RandomFloat() * 30.0f;
    o->oPosZ += RandomFloat() * 30.0f;
}

void BehObjectBubbleLoop(void)
{
    struct Object *bubbleRipples;
    f32 waterY = find_water_level(o->oPosX, o->oPosZ);
    f32 bubbleY = o->oPosY;
    
    if (bubbleY > waterY)
    {
        if (D_8035FD80.next)
        {
            bubbleRipples = func_8029E5A4(o, 0, 165, beh_object_bubble_ripples);
            bubbleRipples->oPosX = o->oPosX;
            bubbleRipples->oPosY = bubbleY + 5.0f;
            bubbleRipples->oPosZ = o->oPosZ;
        }
        
        o->active = 0;
    }
}

void BehObjectWaterWaveInit(void)
{
    o->oPosY = find_water_level(o->oPosX, o->oPosZ);
}

void BehObjectWaterWaveLoop(void)
{
    s32 globalTimer = gGlobalTimer;
    if ((globalTimer % 16) == 0) o->active = 0;
}

void BehExplosionInit(void)
{
    create_sound_spawner(0x802E2081);
    func_8027F308(1);
    
    o->oOpacity = 255;
}

void BehExplosionLoop(void)
{
    s32 i;
    
    if (o->oTimer == 9)
    {
        if (find_water_level(o->oPosX, o->oPosZ) > o->oPosY)
        {
            for (i = 0; i < 40; i++)
                SpawnObj(o, 164, beh_bobomb_explosion_bubble);
        }
        else SpawnObj(o, 150, beh_bobomb_bully_death_smoke);
        
        o->active = 0;
    }
    
    o->oOpacity -= 14;
    
    ScaleObject((f32)o->oTimer / 9.0f + 1.0);
}

void BehBobombBullyDeathSmokeInit(void)
{
    o->oPosY -= 300.0f;
    
    ScaleObject(10.0f);
}

void BehBobombExplosionBubbleInit(void)
{
    ScaleXYZ(o, 2.0f, 2.0f, 1.0f);
    
    o->oBobombExpBubGfxExpRateX = (s32)(RandomFloat() * 2048.0f) + 0x800;
    o->oBobombExpBubGfxExpRateY = (s32)(RandomFloat() * 2048.0f) + 0x800;
    o->oTimer = RandomFloat() * 10.0f;
    o->oVelY = (s32)(RandomFloat() * 4.0f) + 4;
}

void BehBobombExplosionBubbleLoop(void)
{
    f32 waterY = gMarioStates[0].waterLevel;
    
    o->header.gfx.scale[0] = sins(o->oBobombExpBubGfxScaleFacX) * 0.5 + 2.0;
    o->oBobombExpBubGfxScaleFacX += o->oBobombExpBubGfxExpRateX;
    
    o->header.gfx.scale[1] = sins(o->oBobombExpBubGfxScaleFacY) * 0.5 + 2.0;
    o->oBobombExpBubGfxScaleFacY += o->oBobombExpBubGfxExpRateY;
    
    if (o->oPosY > waterY)
    {
        o->active = 0;
        o->oPosY += 5.0f;
        SpawnObj(o, 165, beh_water_surface_white_wave_2);
    }
    
    if (o->oTimer >= 61) o->active = 0;
    
    o->oPosY += o->oVelY;
    o->oTimer++;
}

void BehBobombCorkBoxRespawnerLoop(void)
{
    struct Object *sp1c;
    
    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, o->oBBCBRespawnerMinSpawnDist))
    {
        sp1c = SpawnObj(o, o->oBreakableBoxBackupUnkF4, o->oBBCBRespawnerBehaviorToSpawn);
        sp1c->oUnk188 = o->oUnk188;
        o->active = 0;
    }
}

//sp38 = arg0
//sp3c = behToSpawn
//sp40 = minSpawnDist

void RespawnBobombOrCorkbox(s32 arg0, void *behToSpawn, s32 minSpawnDist)
{
    struct Object *respawner = func_8029E230(o, 0, 0, beh_bobomb_cork_box_respawner, o->oHomeX, o->oHomeY, o->oHomeZ, 0, 0, 0);
    respawner->oUnk188 = o->oUnk188;
    respawner->oBreakableBoxBackupUnkF4 = arg0;
    respawner->oBBCBRespawnerMinSpawnDist = minSpawnDist;
    respawner->oBBCBRespawnerBehaviorToSpawn = behToSpawn;
}

void BehSmallBullyInit(void)
{
    SetObjAnimation(0);
    
    o->oHomeX = o->oPosX;
    o->oHomeZ = o->oPosZ;
    o->oBehParam = BULLY_BP_SIZE_SMALL;
    o->oGravity = 4.0;
    o->oFriction = 0.91;
    o->oBuoyancy = 1.3;
    
    func_802A2CFC(o, &D_80331564);
}

void BehBigBullyInit(void)
{
    SetObjAnimation(0);
    
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oBehParam = BULLY_BP_SIZE_BIG;
    o->oGravity = 5.0;
    o->oFriction = 0.93;
    o->oBuoyancy = 1.3;
    
    func_802A2CFC(o, &D_80331574);
}

void BullyCheckMarioCollision(void)
{
    if (o->oInteractStatus & 0x8000) /* bit 15 */
    {
        if (o->oBehParam == BULLY_BP_SIZE_SMALL) PlaySound2(0x901C0081);
        else PlaySound2(0x90570081);
        
        o->oInteractStatus &= ~0x8000; /* bit 15 */
        o->oAction = BULLY_ACT_KNOCKBACK;
        o->oFlags &= ~0x8; /* bit 3 */
        SetObjAnimation(3);
        o->oBullyMarioCollisionAngle = o->oAngleYaw;
    }
}

void BullyChaseMarioLoop(void)
{
    f32 homeX = o->oHomeX;
    f32 posY = o->oPosY;
    f32 homeZ = o->oHomeZ;
    
    if (o->oTimer < 10)
    {
        o->oForwardVel = 3.0;
        UnknownMove(o, gMarioObject, 16, 4096);
    }
    else if (o->oBehParam == BULLY_BP_SIZE_SMALL)
    {
        o->oForwardVel = 20.0;
        if (o->oTimer >= 31) o->oTimer = 0;
    }
    else
    {
        o->oForwardVel = 30.0;
        if (o->oTimer >= 36) o->oTimer = 0;
    }
    
    if (!IsPointCloseToMario(homeX, posY, homeZ, 1000))
    {
        o->oAction = BULLY_ACT_PATROL;
        SetObjAnimation(0);
    }
}

void BullyKnockbackLoop(void)
{
    if (o->oForwardVel < 10.0 && (s32)o->oVelY == 0)
    {
        o->oForwardVel = 1.0;
        o->oBullyKBTimerAndMinionKOCounter++;
        o->oFlags |= 0x8; /* bit 3 */
        o->oAngleYaw = o->oFaceAngleYaw;
        UnknownMove(o, gMarioObject, 16, 1280);
    }
    else o->header.gfx.unk38.animFrame = 0;
    
    if (o->oBullyKBTimerAndMinionKOCounter == 18)
    {
        o->oAction = BULLY_ACT_CHASE_MARIO;
        o->oBullyKBTimerAndMinionKOCounter = 0;
        SetObjAnimation(1);
    }
}

void BullyBackUpLoop(void)
{
    if (o->oTimer == 0)
    {
        o->oFlags &= ~0x8; /* bit 3 */
        o->oAngleYaw += 0x8000;
    }
    
    o->oForwardVel = 5.0;
    
    //! BullyBackUpCheck() happens after this function, and has the potential to reset
    //  the bully's action to BULLY_ACT_BACK_UP. Because the back up action is only
    //  set to end when the timer EQUALS 15, if this happens on that frame, the bully
    //  will be stuck in BULLY_ACT_BACK_UP forever until Mario hits it or its death
    //  conditions are activated. However because its angle is set to its facing angle,
    //  it will walk forward instead of backing up.
    
    if (o->oTimer == 15)
    {
        o->oAngleYaw = o->oFaceAngleYaw;
        o->oFlags |= 0x8; /* bit 3 */
        o->oAction = BULLY_ACT_PATROL;
    }
}

void BullyBackUpCheck(s16 collisionFlags)
{
    if (!(collisionFlags & 0x8) && o->oAction != BULLY_ACT_KNOCKBACK) /* bit 3 */
    {
        o->oPosX = o->oBullyPrevX;
        o->oPosZ = o->oBullyPrevZ;
        o->oAction = BULLY_ACT_BACK_UP;
    }
}

void PlayBullyStompingSound(void)
{
    s16 sp26 = o->header.gfx.unk38.animFrame;
    switch (o->oAction)
    {
        case BULLY_ACT_PATROL:
            if (sp26 == 0 || sp26 == 12)
            {
                if (o->oBehParam == BULLY_BP_SIZE_SMALL) PlaySound2(0x501B3081);
                else PlaySound2(0x50366081);
            }
            break;
            
        case BULLY_ACT_CHASE_MARIO:
        case BULLY_ACT_BACK_UP:
            if (sp26 == 0 || sp26 == 5)
            {
                if (o->oBehParam == BULLY_BP_SIZE_SMALL) PlaySound2(0x501B3081);
                else PlaySound2(0x50366081);
            }
            break;
    }
}

void BullyStep(void)
{
    s16 collisionFlags = 0;
    collisionFlags = ObjectStep();
    BullyBackUpCheck(collisionFlags);
    PlayBullyStompingSound();
    ObjCheckFloorDeath(collisionFlags, D_803600E0);
    
    if (o->oBullySubtype & BULLY_STYPE_CHILL)
    {
        if (o->oPosY < 1030.0f) o->oAction = BULLY_ACT_LAVA_DEATH;
    }
}

void BullySpawnCoin(void)
{
    struct Object *coin = SpawnObj(o, 116, beh_moving_yellow_coin);
#ifdef VERSION_JP
    PlaySound2(0x30300081);
#else
    PlaySound2(0x38300081);
#endif
    coin->oForwardVel = 10.0f;
    coin->oVelY = 100.0f;
    coin->oPosY = o->oPosY + 310.0f;
    coin->oAngleYaw = (f32)(o->oBullyMarioCollisionAngle + 0x8000) + RandomFloat() * 1024.0f;
}

void BullyLavaDeath(void)
{
    if (ObjLavaDeath() == 1)
    {
        if (o->oBehParam == BULLY_BP_SIZE_SMALL)
        {
            if (o->oBullySubtype == BULLY_STYPE_MINION)
                o->parentObj->oBullyKBTimerAndMinionKOCounter++;
            BullySpawnCoin();
        }
        else
        {
            func_802A3004();
            
            if (o->oBullySubtype == BULLY_STYPE_CHILL) CreateStar(130.0f, 1600.0f, -4335.0f);
            else
            {
                CreateStar(0, 950.0f, -6800.0f);
                func_8029E230(o, 0, 0, beh_tumbling_platform, 0, 154, -5631, 0, 0, 0);
            }
        }
    }
}

void BehBullyLoop(void)
{
    o->oBullyPrevX = o->oPosX;
    o->oBullyPrevY = o->oPosY;
    o->oBullyPrevZ = o->oPosZ;
    
    //! Because this function runs no matter what, Mario is able to interrupt the bully's
    //  death action by colliding with it. Since the bully hitbox is tall enough to collide
    //  with Mario even when it is under a lava floor, this can get the bully stuck OOB
    //  if there is nothing under the lava floor.
    BullyCheckMarioCollision();
    
    switch (o->oAction)
    {
        case BULLY_ACT_PATROL:
            o->oForwardVel = 5.0;
            
            if (ObjLeaveIfMarioIsNearHome(o, o->oHomeX, o->oPosY, o->oHomeZ, 800) == 1)
            {
                o->oAction = BULLY_ACT_CHASE_MARIO;
                SetObjAnimation(1);
            }
            
            BullyStep();
            break;
            
        case BULLY_ACT_CHASE_MARIO:
            BullyChaseMarioLoop();
            BullyStep();
            break;
            
        case BULLY_ACT_KNOCKBACK:
            BullyKnockbackLoop();
            BullyStep();
            break;
            
        case BULLY_ACT_BACK_UP:
            BullyBackUpLoop();
            BullyStep();
            break;
            
        case BULLY_ACT_LAVA_DEATH:
            BullyLavaDeath();
            break;
            
        case BULLY_ACT_DEATH_PLANE_DEATH:
            o->active = 0;
            break;
    }
    
    SetObjectVisibility(o, 3000);
}

//sp38 = arg0
//sp3c = arg1
//sp40 = arg2
//sp44 = arg3

void BigBullySpawnMinion(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    struct Object *bully = func_8029E230(o, 0, 86, beh_small_bully, arg0, arg1, arg2, 0, arg3, 00);
    bully->oBullySubtype = BULLY_STYPE_MINION;
    bully->oBehParam = BULLY_BP_SIZE_SMALL;
}

void BehBigBullyWithMinionsInit(void)
{
    BigBullySpawnMinion(4454, 307, -5426, 0);
    BigBullySpawnMinion(3840, 307, -6041, 0);
    BigBullySpawnMinion(3226, 307, -5426, 0);
    
    o->header.gfx.node.flags |= 0x10; /* bit 4 */
    
    func_8029FE38();
    
    o->oAction = BULLY_ACT_INACTIVE;
}

void BigBullyWithMinionsLavaDeath(void)
{
    if (ObjLavaDeath() == 1)
    {
        func_802A3004();
        CreateStar(3700.0f, 600.0f, -5500.0f);
    }
}

void BehBigBullyWithMinionsLoop(void)
{
    s16 collisionFlags;
    
    o->oBullyPrevX = o->oPosX;
    o->oBullyPrevY = o->oPosY;
    o->oBullyPrevZ = o->oPosZ;
    
    BullyCheckMarioCollision();
    
    switch (o->oAction)
    {
        case BULLY_ACT_PATROL:
            o->oForwardVel = 5.0;
            
            if (ObjLeaveIfMarioIsNearHome(o, o->oHomeX, o->oPosY, o->oHomeZ, 1000) == 1)
            {
                o->oAction = BULLY_ACT_CHASE_MARIO;
                SetObjAnimation(1);
            }
            
            BullyStep();
            break;
            
        case BULLY_ACT_CHASE_MARIO:
            BullyChaseMarioLoop();
            BullyStep();
            break;
            
        case BULLY_ACT_KNOCKBACK:
            BullyKnockbackLoop();
            BullyStep();
            break;
            
        case BULLY_ACT_BACK_UP:
            BullyBackUpLoop();
            BullyStep();
            break;
            
        case BULLY_ACT_INACTIVE:
            //! The Big Bully that spawns from killing its 3 minions uses the knockback timer
            //  for counting the number of dead minions. This means that when it activates,
            //  the knockback timer is at 3 instead of 0. So the bully knockback time will
            //  be reduced by 3 frames (16.67%) on the first hit.
            if (o->oBullyKBTimerAndMinionKOCounter == 3)
            {
                func_80321228();
                
                if (o->oTimer >= 91)
                    o->oAction = BULLY_ACT_ACTIVATE_AND_FALL;
            }
            break;
            
        case BULLY_ACT_ACTIVATE_AND_FALL:
            collisionFlags = ObjectStep();
            if ((collisionFlags & 0x9) == 0x9) /* bits 0 and 3 */
                o->oAction = BULLY_ACT_PATROL;
                
            if (collisionFlags == 1)
            {
                PlaySound2(0x500CA081);
                func_8027F440(1, o->oPosX, o->oPosY, o->oPosZ);
                func_802A3004();
            }
            
            o->header.gfx.node.flags &= ~0x10; /* bit 4 */
            func_8029FE58();
            break;
            
        case BULLY_ACT_LAVA_DEATH:
            BigBullyWithMinionsLavaDeath();
            break;
            
        case BULLY_ACT_DEATH_PLANE_DEATH:
            o->active = 0;
            break;
    }
}

f32 WaterRingCalcMarioDistInFront(void)
{
    f32 marioDistX = o->oPosX - gMarioObject->header.gfx.pos[0];
    f32 marioDistY = o->oPosY - (gMarioObject->header.gfx.pos[1] + 80.0f);
    f32 marioDistZ = o->oPosZ - gMarioObject->header.gfx.pos[2];
    f32 marioDistInFront = marioDistX * o->oWaterRingNormalX + marioDistY * o->oWaterRingNormalY + marioDistZ * o->oWaterRingNormalZ;
    
    return marioDistInFront;
}

void WaterRingInit(void)
{
    SetObjAnimation(0);
    o->oWaterRingScalePhaseX = (s32)(RandomFloat() * 4096.0f) + 0x1000;
    o->oWaterRingScalePhaseY = (s32)(RandomFloat() * 4096.0f) + 0x1000;
    o->oWaterRingScalePhaseZ = (s32)(RandomFloat() * 4096.0f) + 0x1000;
    
    //! This normal calculation assumes a facing yaw of 0, which is not the case
    //  for the manta ray rings. It also errs by multiplying the normal X by -1.
    //  This cause the ring's orientation for the purposes of collision to be 
    //  different than the graphical orientation, which means that Mario won't
    //  necessarily collect a ring even if he appears to swim through it.
    o->oWaterRingNormalX = coss(o->oFaceAnglePitch) * sins(o->oFaceAngleRoll) * -1.0f;
    o->oWaterRingNormalY = coss(o->oFaceAnglePitch) * coss(o->oFaceAngleRoll);
    o->oWaterRingNormalZ = sins(o->oFaceAnglePitch);
    
    o->oWaterRingMarioDistInFront = WaterRingCalcMarioDistInFront();
    
    // Adding this code will alter the ring's graphical orientation to align with the faulty
    // collision orientation:
    //
    // o->oFaceAngleYaw = 0;
    // o->oFaceAngleRoll *= -1;
}

void BehJetStreamWaterRingInit(void)
{
    WaterRingInit();
    o->oOpacity = 70;
    SetObjAnimation(0);
    o->oFaceAnglePitch = 0x8000;
}

//sp28 = arg0
//sp2c = ringManager

void CheckWaterRingCollection(f32 avgScale, struct Object* ringManager)
{
    f32 marioDistInFront = WaterRingCalcMarioDistInFront();
    struct Object *ringSpawner;
    
    if (!IsPointCloseToObject(o, gMarioObject->header.gfx.pos[0], gMarioObject->header.gfx.pos[1] + 80.0f, gMarioObject->header.gfx.pos[2], (avgScale + 0.2) * 120.0))
    {
        o->oWaterRingMarioDistInFront = marioDistInFront;
        return;
    }

    if (o->oWaterRingMarioDistInFront * marioDistInFront < 0)
    {
        ringSpawner = o->parentObj;
        if (ringSpawner)
        {
            if ((o->oWaterRingIndex == ringManager->oWaterRingMgrLastRingCollected + 1)
            ||  (ringSpawner->oWaterRingSpawnerRingsCollected == 0))
            {
                ringSpawner->oWaterRingSpawnerRingsCollected++;
                if (ringSpawner->oWaterRingSpawnerRingsCollected < 6)
                {
                    SpawnOrangeNumber(ringSpawner->oWaterRingSpawnerRingsCollected, 0, -40, 0);
#ifdef VERSION_JP
                    SetSound(0x701EFF81, D_803320E0);
#else
                    SetSound(0x70302081 + ((ringSpawner->oUnk1AF - 1) << 16), D_803320E0);
#endif
                }
                
                ringManager->oWaterRingMgrLastRingCollected = o->oWaterRingIndex;
            }
            else ringSpawner->oWaterRingSpawnerRingsCollected = 0;
        }
        
        o->oAction = WATER_RING_ACT_COLLECTED;
    }
    
    o->oWaterRingMarioDistInFront = marioDistInFront;
}

void SetWaterRingScale(f32 avgScale)
{
    o->header.gfx.scale[0] = sins(o->oWaterRingScalePhaseX) * 0.1 + avgScale;
    o->header.gfx.scale[1] = sins(o->oWaterRingScalePhaseY) * 0.5 + avgScale;
    o->header.gfx.scale[2] = sins(o->oWaterRingScalePhaseZ) * 0.1 + avgScale;
    o->oWaterRingScalePhaseX += 0x1700;
    o->oWaterRingScalePhaseY += 0x1700;
    o->oWaterRingScalePhaseZ += 0x1700;
}

void WaterRingCollectedLoop(void)
{
    f32 avgScale = (f32)o->oTimer * 0.2 + o->oWaterRingAvgScale;
    
    if (o->oTimer >= 21) o->active = 0;
    
    o->oOpacity -= 10;
    if (o->oOpacity < 0) o->oOpacity = 0;
    
    SetWaterRingScale(avgScale);
}

void JetStreamWaterRingNotCollectedLoop(void)
{
    f32 avgScale = (f32)o->oTimer / 225.0 * 3.0 + 0.5;
    
    //! In this case ringSpawner and ringManager are the same object,
    //  because the Jet Stream Ring Spawner is its own parent object.
    struct Object *ringSpawner = o->parentObj;
    struct Object *ringManager = ringSpawner->parentObj;
    
    if (o->oTimer >= 226)
    {
        o->oOpacity -= 2;
        if (o->oOpacity < 3) o->active = 0;
    }
    
    CheckWaterRingCollection(avgScale, ringManager);
    SetWaterRingScale(avgScale);
    
    o->oPosY += 10.0f;
    o->oFaceAngleYaw += 0x100;
    SetObjectVisibility(o, 5000);
    
    if (ringSpawner->oWaterRingSpawnerRingsCollected == 4 && o->oWaterRingIndex == ringManager->oWaterRingMgrLastRingCollected + 1)
        o->oOpacity = sins(o->oTimer * 0x1000) * 200.0f + 50.0f;
    
    o->oWaterRingAvgScale = avgScale;
}

void BehJetStreamWaterRingLoop(void)
{
    switch (o->oAction)
    {
        case WATER_RING_ACT_NOT_COLLECTED:
            JetStreamWaterRingNotCollectedLoop();
            break;
            
        case WATER_RING_ACT_COLLECTED:
            WaterRingCollectedLoop();
            break;
    }
}

void Unknown802EB8A4(void)
{
    struct Object *ringManager = SpawnObj(o, 0, beh_manta_ray_ring_manager);
    o->parentObj = ringManager;
}

void JetStreamRingSpawnerActiveLoop(void)
{
    //! The Jet Stream Ring Spawner is its own parent object. The code may have been copied
    //  from the Manta Ray, which spawns rings but also has a Ring Manager object as its
    //  parent. The Jet Stream Ring Spawner functions as both a spawner and a Ring Manager.
    struct Object *currentObj = o->parentObj;
    struct Object *waterRing;
    
    //! Because the index counter overflows at 10000, it's possible to wait
    //  for about 4 hours and 38 minutes if you miss a ring, and the index will
    //  come around again.
    if (o->oTimer == 300) o->oTimer = 0;
    if ((o->oTimer == 0)
    ||  (o->oTimer == 50)
    ||  (o->oTimer == 150)
    ||  (o->oTimer == 200)
    ||  (o->oTimer == 250))
    {
        waterRing = SpawnObj(o, 104, beh_jet_stream_water_ring);
        waterRing->oWaterRingIndex = currentObj->oWaterRingMgrNextRingIndex;
        currentObj->oWaterRingMgrNextRingIndex++;
        if (currentObj->oWaterRingMgrNextRingIndex >= 10001) currentObj->oWaterRingMgrNextRingIndex = 0;
    }
}

void BehJetStreamRingSpawnerLoop(void)
{
    switch (o->oAction)
    {
        case JS_RING_SPAWNER_ACT_ACTIVE:
            JetStreamRingSpawnerActiveLoop();
            
            if (o->oWaterRingSpawnerRingsCollected == 5)
            {
                func_802A3004();
                
                CreateStar(3400.0f, -3200.0f, -500.0f);
                
                o->oAction = JS_RING_SPAWNER_ACT_INACTIVE;
            }
            break;
            
        case JS_RING_SPAWNER_ACT_INACTIVE:
            break;
    }
}

void BehMantaRayWaterRingInit(void)
{
    WaterRingInit();
    o->oOpacity = 150;
}

void MantaRayWaterRingNotCollectedLoop(void)
{
    f32 avgScale = (f32)o->oTimer / 50.0f * 1.3 + 0.1;
    struct Object *ringSpawner = o->parentObj;
    struct Object *ringManager = ringSpawner->parentObj;
    
    if (avgScale > 1.3) avgScale = 1.3;
    
    if (o->oTimer >= 151)
    {
        o->oOpacity -= 2;
        if (o->oOpacity < 3) o->active = 0;
    }
    
    CheckWaterRingCollection(avgScale, ringManager);
    SetWaterRingScale(avgScale);
    SetObjectVisibility(o, 5000);
    
    if (ringSpawner->oWaterRingSpawnerRingsCollected == 4 && o->oWaterRingIndex == ringManager->oWaterRingMgrLastRingCollected + 1)
        o->oOpacity = sins(o->oTimer * 0x1000) * 200.0f + 50.0f;
    
    o->oWaterRingAvgScale = avgScale;
}

void BehMantaRayWaterRingLoop(void)
{
    switch (o->oAction)
    {
        case WATER_RING_ACT_NOT_COLLECTED:
            MantaRayWaterRingNotCollectedLoop();
            break;
            
        case WATER_RING_ACT_COLLECTED:
            WaterRingCollectedLoop();
            break;
    }
}

void BehBowserMineLoop(void)
{
    if (func_802A0CA8(o, gMarioObject) == 1)
    {
        o->oInteractStatus &= ~0x8000; /* bit 15 */
        SpawnObj(o, 205, beh_explosion);
        o->active = 0;
    }
    
    if (o->oInteractStatus & 0x200000) /* bit 21 */
    {
        SpawnObj(o, 103, beh_bowser_mine_explosion);
        create_sound_spawner(0x312F0081);
        func_8027F440(3, o->oPosX, o->oPosY, o->oPosZ);
        o->active = 0;
    }
    
    SetObjectVisibility(o, 7000);
}

void BehBowserMineExplosionLoop(void)
{
    struct Object *mineSmoke;
    
    ScaleObject((f32)o->oTimer / 14.0f * 9.0 + 1.0);
    if ((o->oTimer % 4 == 0) && (o->oTimer < 20))
    {
        mineSmoke = SpawnObj(o, 102, beh_bowser_mine_smoke);
        mineSmoke->oPosX += RandomFloat() * 600.0f - 400.0f;
        mineSmoke->oPosZ += RandomFloat() * 600.0f - 400.0f;
        mineSmoke->oVelY += RandomFloat() * 10.0f;
    }
    
    if (o->oTimer % 2 == 0) o->oAnimState++;
    if (o->oTimer == 28) o->active = 0;
}

void BehBowserMineSmokeLoop(void)
{
    ScaleObject((f32)o->oTimer / 14.0f * 9.0 + 1.0);
    if (o->oTimer % 2 == 0) o->oAnimState++;
    
    o->oOpacity -= 10;
    if (o->oOpacity < 10) o->oOpacity = 0;
    
    o->oPosY += o->oVelY;
    
    if (o->oTimer == 28) o->active = 0;
}

void BehCelebrationStarInit(void)
{
    o->oHomeX = gMarioObject->header.gfx.pos[0];
    o->oPosY = gMarioObject->header.gfx.pos[1] + 30.0f;
    o->oHomeZ = gMarioObject->header.gfx.pos[2];
    o->oAngleYaw = gMarioObject->header.gfx.angle[1] + 0x8000;
    o->oCelebStarDiameterOfRotation = 100;
#ifdef VERSION_JP
	o->header.gfx.asGraphNode = gLoadedGraphNodes[122];
    ScaleObject(0.4f);
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
#else
    if (gCurrLevelNum == LEVEL_BOWSER_1 || gCurrLevelNum == LEVEL_BOWSER_2)
    {
        o->header.gfx.asGraphNode = gLoadedGraphNodes[204];
        o->oFaceAnglePitch = 0;
        o->oFaceAngleRoll = 49152;
        ScaleObject(0.1f);
        o->oUnknownUnkF4_S32 = 1;
    }
    else
    {
        o->header.gfx.asGraphNode = gLoadedGraphNodes[122];
        o->oFaceAnglePitch = 0;
        o->oFaceAngleRoll = 0;
        ScaleObject(0.4f);
        o->oUnknownUnkF4_S32 = 0;
    }
#endif
}

void CelebrationStarSpinAroundMarioLoop(void)
{
    o->oPosX = o->oHomeX + sins(o->oAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosZ = o->oHomeZ + coss(o->oAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosY += 5.0f;
    o->oFaceAngleYaw += 0x1000;
    o->oAngleYaw += 0x2000;
    
    if (o-> oTimer == 40) o->oAction = CELEB_STAR_ACT_FACE_CAMERA;
    if (o-> oTimer < 35)
    {
        SpawnObj(o, 149, beh_celebration_star_sparkle);
        o->oCelebStarDiameterOfRotation++;
    }
    else o->oCelebStarDiameterOfRotation -= 20;
}

void CelebrationStarFaceCameraLoop(void)
{

    if (o->oTimer < 10)
    {
#ifdef VERSION_JP
        ScaleObject((f32)o->oTimer / 10.0);
#else // mario dab fix
        if(o->oUnknownUnkF4_S32 == 0)
        {
            ScaleObject((f32)o->oTimer / 10.0);
        }
        else
        {
            ScaleObject((f32)o->oTimer / 30.0);
        }
#endif
        o->oFaceAngleYaw += 0x1000;
    }
    else
    {
        o->oFaceAngleYaw = gMarioObject->header.gfx.angle[1];
    }
    
    if (o->oTimer == 59) o->active = 0;
}

void BehCelebrationStarLoop(void)
{
    switch (o->oAction)
    {
        case CELEB_STAR_ACT_SPIN_AROUND_MARIO:
            CelebrationStarSpinAroundMarioLoop();
            break;
            
        case CELEB_STAR_ACT_FACE_CAMERA:
            CelebrationStarFaceCameraLoop();
            break;
    }
}

void BehCelebrationStarSparkleLoop(void)
{
    o->oPosY -= 15.0f;
    
    if (o->oTimer == 12) o->active = 0;
}

void BehStarKeyCollectionPuffSpawnerLoop(void)
{
    func_802AA618(0, 10, 30.0f);
    o->active = 0;
}

void BehLLLDrawbridgeSpawnerLoop(void)
{
    struct Object *drawbridge1, *drawbridge2;
    
    drawbridge1 = SpawnObj(o, 56, beh_lll_drawbridge);
    drawbridge1->oAngleYaw = o->oAngleYaw;
    drawbridge1->oPosX += coss(o->oAngleYaw) * 640.0f;
    drawbridge1->oPosZ += sins(o->oAngleYaw) * 640.0f;
    
    drawbridge2 = SpawnObj(o, 56, beh_lll_drawbridge);
    drawbridge2->oAngleYaw = o->oAngleYaw + 0x8000;
    drawbridge2->oPosX += coss(o->oAngleYaw) * -640.0f;
    drawbridge2->oPosZ += sins(o->oAngleYaw) * -640.0f;
    
    o->active = 0;
}

void BehLLLDrawbridgeLoop(void)
{
    s32 globalTimer = gGlobalTimer;
    
    switch (o->oAction)
    {
        case LLL_DRAWBRIDGE_ACT_LOWER:
            o->oFaceAngleRoll += 0x100;
            break;
            
        case LLL_DRAWBRIDGE_ACT_RAISE:
            o->oFaceAngleRoll -= 0x100;
            break;
    }
    
    if ((s16)o->oFaceAngleRoll < -0x1FFD)
    {
        o->oFaceAngleRoll = 0xDFFF;
        
        //! Because the global timer increments when the game is paused, pausing and unpausing
        //  the game at regular intervals can leave the drawbridge raised indefinitely.
        if (o->oTimer >= 51 && (globalTimer % 8) == 0)
        {
            o->oAction = LLL_DRAWBRIDGE_ACT_LOWER;
            PlaySound2(0x30344081);
        }    
    }
    
    if ((s16)o->oFaceAngleRoll >= 0)
    {
        o->oFaceAngleRoll = 0;
        
        //! Because the global timer increments when the game is paused, pausing and unpausing
        //  the game at regular intervals can leave the drawbridge lowered indefinitely.
        if (o->oTimer >= 51 && (globalTimer % 8) == 0)
        {
            o->oAction = LLL_DRAWBRIDGE_ACT_RAISE;
            PlaySound2(0x30354081);
        }
    }
}

void BehSmallBompInit(void)
{
    o->oFaceAngleYaw -= 0x4000;
    o->oSmallBompInitX = o->oPosX;
    o->oTimer = RandomFloat() * 100.0f;
}

void BehSmallBompLoop(void)
{
    switch (o->oAction)
    {
        case BOMP_ACT_WAIT:
            if (o->oTimer >= 101)
            {
                o->oAction = BOMP_ACT_POKE_OUT;
                o->oForwardVel = 30.0f;
            }
            break;
            
        case BOMP_ACT_POKE_OUT:
            if (o->oPosX > 3450.0f)
            {
                o->oPosX = 3450.0f;
                o->oForwardVel = 0;
            }
            
            if (o->oTimer == 15.0)
            {
                o->oAction = BOMP_ACT_EXTEND;
                o->oForwardVel = 40.0f;
                PlaySound2(0x50130081);
            }
            break;
            
        case BOMP_ACT_EXTEND:
            if (o->oPosX > 3830.0f)
            {
                o->oPosX = 3830.0f;
                o->oForwardVel = 0;
            }
            
            if (o->oTimer == 60)
            {
                o->oAction = BOMP_ACT_RETRACT;
                o->oForwardVel = 10.0f;
                o->oAngleYaw -= 0x8000;
                PlaySound2(0x50130081);
            }
            break;
            
        case BOMP_ACT_RETRACT:
            if (o->oPosX < 3330.0f)
            {
                o->oPosX = 3330.0f;
                o->oForwardVel = 0;
            }
            
            if (o->oTimer == 90)
            {
                o->oAction = BOMP_ACT_POKE_OUT;
                o->oForwardVel = 25.0f;
                o->oAngleYaw -= 0x8000;
            }
            break;
    }
}

void BehLargeBompInit(void)
{
    o->oAngleYaw += 0x4000;
    o->oTimer = RandomFloat() * 100.0f;
}

void BehLargeBompLoop(void)
{
    switch (o->oAction)
    {
        case BOMP_ACT_WAIT:
            if (o->oTimer >= 101)
            {
                o->oAction = BOMP_ACT_POKE_OUT;
                o->oForwardVel = 30.0f;
            }
            break;
            
        case BOMP_ACT_POKE_OUT:
            if (o->oPosX > 3450.0f)
            {
                o->oPosX = 3450.0f;
                o->oForwardVel = 0;
            }
            
            if (o->oTimer == 15.0)
            {
                o->oAction = BOMP_ACT_EXTEND;
                o->oForwardVel = 10.0f;
                PlaySound2(0x50130081);
            }
            break;
            
        case BOMP_ACT_EXTEND:
            if (o->oPosX > 3830.0f)
            {
                o->oPosX = 3830.0f;
                o->oForwardVel = 0;
            }
            
            if (o->oTimer == 60)
            {
                o->oAction = BOMP_ACT_RETRACT;
                o->oForwardVel = 10.0f;
                o->oAngleYaw -= 0x8000;
                PlaySound2(0x50130081);
            }
            break;
            
        case BOMP_ACT_RETRACT:
            if (o->oPosX < 3330.0f)
            {
                o->oPosX = 3330.0f;
                o->oForwardVel = 0;
            }
            
            if (o->oTimer == 90)
            {
                o->oAction = BOMP_ACT_POKE_OUT;
                o->oForwardVel = 25.0f;
                o->oAngleYaw -= 0x8000;
            }
            break;
    }
}

void BehWFSlidingBrickPlatformInit(void)
{
    o->oFaceAngleYaw -= 0x4000;
    o->oPosX += 2.0f;
    o->oHomeX = o->oPosX;
    
    switch (o->oBehParam)
    {
        case WF_SLID_BRICK_PTFM_BP_MOV_VEL_10:
            o->oWFSlidBrickPtfmMovVel = 10.0f;
            break;
            
        case WF_SLID_BRICK_PTFM_BP_MOV_VEL_15:
            o->oWFSlidBrickPtfmMovVel = 15.0f;
            break;
            
        case WF_SLID_BRICK_PTFM_BP_MOV_VEL_20:
            o->oWFSlidBrickPtfmMovVel = 20.0f;
            break;
    }
    
    o->oTimer = RandomFloat() * 100.0f;
}

void BehWFSlidingBrickPlatformLoop(void)
{
    switch (o->oAction)
    {
        case WF_SLID_BRICK_PTFM_ACT_WAIT:
            if (o->oTimer >= 101)
            {
                o->oAction = WF_SLID_BRICK_PTFM_ACT_EXTEND;
                o->oForwardVel = o->oWFSlidBrickPtfmMovVel;
            }
            break;
            
        case WF_SLID_BRICK_PTFM_ACT_EXTEND:
            if (o->oTimer >= 500.0f / o->oWFSlidBrickPtfmMovVel)
            {
                o->oForwardVel = 0;
                o->oPosX = o->oHomeX + 510.0f;
            }
            
            if (o->oTimer == 60)
            {
                o->oAction = WF_SLID_BRICK_PTFM_ACT_RETRACT;
                o->oForwardVel = o->oWFSlidBrickPtfmMovVel;
                o->oAngleYaw -= 0x8000;
            }
            break;
            
        case WF_SLID_BRICK_PTFM_ACT_RETRACT:
            if (o->oTimer >= 500.0f / o->oWFSlidBrickPtfmMovVel)
            {
                o->oForwardVel = 0;
                o->oPosX = o->oHomeX;
            }
            
            if (o->oTimer == 90)
            {
                o->oAction = WF_SLID_BRICK_PTFM_ACT_EXTEND;
                o->oForwardVel = o->oWFSlidBrickPtfmMovVel;
                o->oAngleYaw -= 0x8000;
            }
            break;
    }
}

void BehMoneybagInit(void)
{
    o->oGravity = 3.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
    SetObjAnimation(0);
    o->oOpacity = 0;
}

void MoneybagCheckMarioCollision(void)
{
    func_802A2CFC(o, &D_80331584);
    
    if (o->oInteractStatus & 0x8000) /* bit 15 */
    {
        if (o->oInteractStatus & 0x2000) /* bit 13 */
        {
            o->oAngleYaw = o->oAngleToMario + 0x8000;
            o->oVelY = 30.0f;
        }
        
        if (o->oInteractStatus & 0x4000) /* bit 14 */
        {
            o->oAction = MONEYBAG_ACT_DEATH;
        }
        
        o->oInteractStatus = 0;
    }
}

//sp20 = collisionFlags

void MoneybagJump(s8 collisionFlags)
{
    s16 animFrame = o->header.gfx.unk38.animFrame;
    
    switch (o->oMoneybagJumpState)
    {
        case MONEYBAG_JUMP_PREPARE:
            SetObjAnimation(1);
            if (animFrame == 5)
            {
                o->oForwardVel = 20.0f;
                o->oVelY = 40.0f;
            }
            
            if (func_8029F788() == 1)
            {
                o->oMoneybagJumpState = MONEYBAG_JUMP_JUMP;
                PlaySound2(0x306D2081);
            }
            break;
            
        case MONEYBAG_JUMP_JUMP:
            SetObjAnimation(2);
            
            if ((collisionFlags & 1) == 1) /* bit 0 */
            {
                o->oForwardVel = 0;
                o->oVelY = 0;
                o->oMoneybagJumpState = MONEYBAG_JUMP_LANDING;
            }
            break;
            
        case MONEYBAG_JUMP_JUMP_AND_BOUNCE:
            SetObjAnimation(3);
            
            if (func_8029F788() == 1) o->oMoneybagJumpState = MONEYBAG_JUMP_LANDING;
            break;
            
        case MONEYBAG_JUMP_WALK_AROUND:
            SetObjAnimation(4);
            o->oForwardVel = 10.0f;
            
            if (o->oTimer >= 61)
            {
                o->oMoneybagJumpState = MONEYBAG_JUMP_LANDING;
                o->oForwardVel = 0;
                o->header.gfx.unk38.animFrame = 0;
            }
            break;
            
        case MONEYBAG_JUMP_WALK_HOME:
            SetObjAnimation(4);
            o->oForwardVel = 5.0f;
            break;
    }
}

void MoneybagMoveAroundLoop(void)
{
    s16 collisionFlags;
    
    ObjDisplaceHome(o, o->oHomeX, o->oHomeY, o->oHomeZ, 200);
    
    collisionFlags = ObjectStep();
    
    if (((collisionFlags & OBJ_COL_FLAGS_LANDED) == OBJ_COL_FLAGS_LANDED)
    &&  (o->oMoneybagJumpState == MONEYBAG_JUMP_LANDING))
    {
        if ((s32)(RandomFloat() * 6.0f) == 1)
        {
            o->oMoneybagJumpState = MONEYBAG_JUMP_WALK_AROUND;
            o->oTimer = 0;
        }
        else o->oMoneybagJumpState = MONEYBAG_JUMP_PREPARE;
    }
    
    MoneybagJump(collisionFlags);
    MoneybagCheckMarioCollision();
    
    if (!IsPointCloseToMario(o->oHomeX, o->oHomeY, o->oHomeZ, 800)
    && ((collisionFlags & 0x9) == 9))
        o->oAction = MONEYBAG_ACT_RETURN_HOME;
}

void MoneybagReturnHomeLoop(void)
{
    s16 collisionFlags;
    f32 sp28 = o->oHomeX - o->oPosX;
    f32 sp24 = o->oHomeZ - o->oPosZ;
    s16 sp22 = atan2s(sp24, sp28);
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, sp22, 0x800);
    
    collisionFlags = ObjectStep();
    if (((collisionFlags & OBJ_COL_FLAGS_LANDED) == OBJ_COL_FLAGS_LANDED)
    &&  (o->oMoneybagJumpState == MONEYBAG_JUMP_LANDING))
        o->oMoneybagJumpState = MONEYBAG_JUMP_WALK_HOME;
    
    MoneybagJump(collisionFlags);
    MoneybagCheckMarioCollision();
    
    if (IsPointCloseToObject(o, o->oHomeX, o->oHomeY, o->oHomeZ, 100))
    {
        SpawnObj(o, 116, beh_fake_moneybag_coin);
#ifdef VERSION_US
        PlaySound2(0x30762081);
#endif
        SetObjAnimation(0);
        o->oAction = MONEYBAG_ACT_DISAPPEAR;
        o->oMoneybagJumpState = MONEYBAG_JUMP_LANDING;
    }
    
    if (IsPointCloseToMario(o->oHomeX, o->oHomeY, o->oHomeZ, 800) == 1)
    {
        o->oAction = MONEYBAG_ACT_MOVE_AROUND;
        o->oMoneybagJumpState = MONEYBAG_JUMP_LANDING;
    }
}

void MoneybagDisappearLoop(void)
{
    o->oOpacity -= 6;
    if (o->oOpacity < 0)
    {
        o->oOpacity = 0;
        o->active = 0;
    }
}

void MoneybagDeathLoop(void)
{
    if (o->oTimer == 1)
    {
        ObjSpawnYellowCoins(o, 5);
        create_sound_spawner(0x30713081);
        func_802A3004();
        o->active = 0;
    }
}

void BehMoneybagLoop(void)
{
    switch (o->oAction)
    {
        case MONEYBAG_ACT_APPEAR:
        case MONEYBAG_ACT_UNUSED_APPEAR:
            o->oOpacity += 12;
            if (o->oOpacity >= 256)
            {
                o->oOpacity = 255;
                o->parentObj->active = 0;
                o->oAction = MONEYBAG_ACT_MOVE_AROUND;
            }
            break;
            
        case MONEYBAG_ACT_MOVE_AROUND:
            MoneybagMoveAroundLoop();
            if (o->oTimer >= 31) func_8029FE58();
            break;
            
        case MONEYBAG_ACT_RETURN_HOME:
            MoneybagReturnHomeLoop();
            break;
            
        case MONEYBAG_ACT_DISAPPEAR:
            MoneybagDisappearLoop();
            break;
            
        case MONEYBAG_ACT_DEATH:
            MoneybagDeathLoop();
            break;
    }
}

void BehFakeMoneybagCoinLoop(void)
{
    func_802A2CFC(o, &D_80331594);
    
    switch (o->oAction)
    {
        case FAKE_MONEYBAG_COIN_ACT_IDLE:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 400))
            {
                SpawnObj(o, 102, beh_moneybag);
#ifdef VERSION_US
                PlaySound2(0x30762081);
#endif
                o->oAction = FAKE_MONEYBAG_COIN_ACT_TRANSFORM;
            }
            break;
            
        case FAKE_MONEYBAG_COIN_ACT_TRANSFORM:
            break;
    }
    
    o->oInteractStatus = 0;
}

void BehBowlingBallInit(void)
{
    o->oGravity = 5.5f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
}

void func_802EDA14(void)
{
    func_802A2CFC(o, &D_803315A4);
    
    if (o->oInteractStatus & 0x8000) o->oInteractStatus = 0;
}

void func_802EDA6C(void)
{
    switch (o->oBehParam)
    {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oBowlingBallUnkFC = segmented_to_virtual(bob_seg7_metal_ball_path0);
            break;
            
        case BBALL_BP_STYPE_TTM:
            o->oBowlingBallUnkFC = segmented_to_virtual(ttm_seg7_trajectory_070170A0);
            break;
            
        case BBALL_BP_STYPE_BOB_LOWER:
            o->oBowlingBallUnkFC = segmented_to_virtual(bob_seg7_metal_ball_path1);
            break;
            
        case BBALL_BP_STYPE_THI_LARGE:
            o->oBowlingBallUnkFC = D_803315B4;
            break;
            
        case BBALL_BP_STYPE_THI_SMALL:
            o->oBowlingBallUnkFC = D_80331608;
            break;
    }
}

void BehBowlingBallRollLoop(void)
{
    s16 collisionFlags;
    s32 sp18;
    
    func_802EDA6C();
    collisionFlags = ObjectStep();
    
    //! Uninitialzed parameter, but the parameter is unused in the called function
    sp18 = func_802A24B4(sp18);
    
    //! oBowlingBallInitYaw is never explicitly initialized, so it is 0.
    o->oBowlingBallTargetYaw = o->oBowlingBallInitYaw;
    o->oAngleYaw = approach_target_angle(o->oAngleYaw, o->oBowlingBallTargetYaw, 0x400);
    if (o->oForwardVel > 70.0)
    {
        o->oForwardVel = 70.0;
    }
    
    func_802EDA14();
    
    if (sp18 == -1)
    {
        if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 7000))
        {
            func_802A3004();
            func_802AA618(0, 0, 92.0f);
        }
        
        o->active = 0;
    }
    
    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) && (o->oVelY > 5.0f))
        PlaySound2(0x30400081);
}

void BehBowlingBallInitializeLoop(void)
{
    s32 sp1c;
    
    func_802EDA6C();
    
    //! Uninitialzed parameter, but the parameter is unused in the called function
    sp1c = func_802A24B4(sp1c);
    
    //! oBowlingBallInitYaw is never explicitly initialized, so it is 0.
    o->oAngleYaw = o->oBowlingBallInitYaw;
    
    switch (o->oBehParam)
    {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oForwardVel = 20.0f;
            break;
            
        case BBALL_BP_STYPE_TTM:
            o->oForwardVel = 10.0f;
            break;
            
        case BBALL_BP_STYPE_BOB_LOWER:
            o->oForwardVel = 20.0f;
            break;
            
        case BBALL_BP_STYPE_THI_LARGE:
            o->oForwardVel = 25.0f;
            break;
            
        case BBALL_BP_STYPE_THI_SMALL:
            o->oForwardVel = 10.0f;
            ScaleObject(0.3f);
            o->oGraphYOffset = 39.0f;
            break;
    }
}

void BehBowlingBallLoop(void)
{
    switch (o->oAction)
    {
        case BBALL_ACT_INITIALIZE:
            o->oAction = BBALL_ACT_ROLL;
            BehBowlingBallInitializeLoop();
            break;
            
        case BBALL_ACT_ROLL:
            BehBowlingBallRollLoop();
            break;
    }
    
    if (o->oBehParam != 4)
        func_8027F440(4, o->oPosX, o->oPosY, o->oPosZ);
    
    SetObjectVisibility(o, 4000);
}

#ifdef VERSION_US // hack to keep the ROM OK, not an actual diff
extern float D_803374B8;
extern float D_803374BC;
#endif

void BehGenericBowlingBallSpawnerInit(void)
{
    switch (o->oBehParam)
    {
        case BBALL_BP_STYPE_BOB_UPPER:
#ifdef VERSION_JP
            o->oBBallSpwnrMaxSpawnDist = 7000.0f;
#else
			o->oBBallSpwnrMaxSpawnDist = D_803374B8;
#endif
            o->oBBallSpwnrSpawnOdds = 2.0f;
            break;
            
        case BBALL_BP_STYPE_TTM:
            o->oBBallSpwnrMaxSpawnDist = 8000.0f;
            o->oBBallSpwnrSpawnOdds = 1.0f;
            break;
            
        case BBALL_BP_STYPE_BOB_LOWER:
#ifdef VERSION_JP
            o->oBBallSpwnrMaxSpawnDist = 6000.0f;
#else
			o->oBBallSpwnrMaxSpawnDist = D_803374BC;
#endif
            o->oBBallSpwnrSpawnOdds = 2.0f;
            break;
    }
}

void BehGenericBowlingBallSpawnerLoop(void)
{
    struct Object *bowlingBall;
    
    if (o->oTimer == 256)
        o->oTimer = 0;
    
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1000)
    ||  (o->oPosY < gMarioObject->header.gfx.pos[1]))
        return;
    
    if ((o->oTimer & o->oBBallSpwnrPeriodMinus1) == 0) /* Modulus */
    {
        if  (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, o->oBBallSpwnrMaxSpawnDist))
        {
            if  ((s32)(RandomFloat() * o->oBBallSpwnrSpawnOdds) == 0)
            {
                bowlingBall = SpawnObj(o, 180, beh_bowling_ball);
                bowlingBall->oBehParam = o->oBehParam;
            }
        }
    }
}

void BehTHIBowlingBallSpawnerLoop(void)
{
    struct Object *bowlingBall;
    
    if (o->oTimer == 256)
        o->oTimer = 0;
    
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 800)
    ||  (o->oPosY < gMarioObject->header.gfx.pos[1]))
        return;
        
    if ((o->oTimer % 64) == 0)
    {
        if  (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 12000))
        {
            if  ((s32)(RandomFloat() * 1.5) == 0)
            {
                bowlingBall = SpawnObj(o, 180, beh_bowling_ball);
                bowlingBall->oBehParam = o->oBehParam;
            }
        }
    }
}

void BehBOBPitBowlingBallInit(void)
{
    o->oGravity = 12.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
}

void BehBOBPitBowlingBallLoop(void)
{
    f32 *sp1c;
    UNUSED s16 collisionFlags = ObjectStep();
    
    func_803814B8(o->oPosX, o->oPosY, o->oPosZ, &sp1c);
    if ((sp1c[4] == 0) && (sp1c[6] == 0))
        o->oForwardVel = 28.0f;
    
    func_802EDA14();
    func_8027F440(4, o->oPosX, o->oPosY, o->oPosZ);
    PlaySound(0x400A0001);
    SetObjectVisibility(o, 3000);
}

void BehFreeBowlingBallInit(void)
{
    o->oGravity = 5.5f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oForwardVel = 0;
    o->oAngleYaw = 0;
}

void BehFreeBowlingBallRollLoop(void)
{
    s16 collisionFlags = ObjectStep();
    func_802EDA14();
    
    if (o->oForwardVel > 10.0f)
    {
        func_8027F440(4, o->oPosX, o->oPosY, o->oPosZ);
        PlaySound(0x400A0001);
    }
    
    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED)
    &&  !(collisionFlags & OBJ_COL_FLAGS_LANDED))
        PlaySound2(0x30400081);
        
    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 6000))
    {
        o->header.gfx.node.flags |= 0x10; /* bit 4 */
        func_8029FE38();
        
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        BehFreeBowlingBallInit();
        o->oAction = FREE_BBALL_ACT_RESET;
    }
}

void BehFreeBowlingBallLoop(void)
{
    o->oGravity = 5.5f;
    
    switch (o->oAction)
    {
        case FREE_BBALL_ACT_IDLE:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 3000))
            {
                o->oAction = FREE_BBALL_ACT_ROLL;
                o->header.gfx.node.flags &= ~0x10; /* bit 4 */
                func_8029FE58();
            }
            break;
            
        case FREE_BBALL_ACT_ROLL:
            BehFreeBowlingBallRollLoop();
            break;
            
        case FREE_BBALL_ACT_RESET:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 5000))
                o->oAction = FREE_BBALL_ACT_IDLE;
            break;
    }
}

void BehRRCruiserWingInit(void)
{
    o->oRRCruiserWingUnkF4 = o->oFaceAngleYaw;
    o->oRRCruiserWingUnkF8 = o->oFaceAnglePitch;
}

void BehRRCruiserWingLoop(void)
{
    if (o->oBehParam == 0)
    {
        o->oFaceAngleYaw = o->oRRCruiserWingUnkF4 + sins(o->oTimer * 0x400) * 8192.0f;
        o->oFaceAnglePitch = o->oRRCruiserWingUnkF8 + coss(o->oTimer * 0x400) * 2048.0f;
    }
    else
    {
        o->oFaceAngleYaw = o->oRRCruiserWingUnkF4 - sins(o->oTimer * 0x400) * 8192.0f;
        o->oFaceAnglePitch = o->oRRCruiserWingUnkF8 + coss(o->oTimer * 0x400) * 2048.0f;
    }
#ifndef VERSION_JP
    if (o->oTimer == 64)
    {
        PlaySound2(0x30750081);
        o->oTimer = 0;
    }
#endif
}

/*
glabel D_803374C0
    .incbin "bin/rodata.bin", 0x2A50, 0x4

glabel D_803374C4
    .incbin "bin/rodata.bin", 0x2A54, 0x4
	*/
