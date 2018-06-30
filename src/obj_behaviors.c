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

#define COLLISION_FLAG_0 (1 << 0)
#define COLLISION_FLAG_1 (1 << 1)
#define COLLISION_FLAG_2 (1 << 2)
#define COLLISION_FLAG_3 (1 << 3)

extern void PlaySound(u32 arg0);
extern void PlaySound2(u32 arg0);

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
        sp28->gfx.graphFlags = (sp28->gfx.graphFlags & 0xFF) | 0x500; //sets bits 8, 10 and zeros upper byte
        sp1c = sp30++;
        (*sp1c)[0] = 0xFB000000;
        (*sp1c)[1] = (s32)(sp2c->oUnk17C & 0xFF) | 0xFFFFFF00;
        sp18 = sp30;
        (*sp18)[0] = 0xB8000000;
        (*sp18)[1] = 0;
    }

    return sp34;
}

float func_802E3058(f32 f)
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
    hitbox.offsetY = gCurrentObject->hitboxHeight / 2.0f;
    hitbox.radius = gCurrentObject->hitboxRadius;

    if (find_wall_collisions(&hitbox) != 0)
    {
        gCurrentObject->oPosX = hitbox.x;
        gCurrentObject->oPosY = hitbox.y;
        gCurrentObject->oPosZ = hitbox.z;
        wall_nX = hitbox.walls[0]->normal[0];
        wall_nY = hitbox.walls[0]->normal[1];
        wall_nZ = hitbox.walls[0]->normal[2];
        objVelXCopy = objVelX;
        objVelZCopy = objVelZ;
        TurnObjAwayFromSurface(objVelXCopy, objVelZCopy, wall_nX, wall_nY, wall_nZ, &objYawX, &objYawZ);
        gCurrentObject->oAngleYaw = atan2s(objYawZ, objYawX);
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
        //!Possible TRUNC overflow exception
        gCurrentObject->oAngleYaw += 32767.999200000002; /* ¯\_(ツ)_/¯ */
        return 0;
    }

    floor_nX = objFloor->normal[0];
    floor_nY = objFloor->normal[1];
    floor_nZ = objFloor->normal[2];

    if (floor_nY < 0.5 && floorY > gCurrentObject->oPosY)
    {
        objVelXCopy = objVelX;
        objVelZCopy = objVelZ;
        TurnObjAwayFromSurface(objVelXCopy, objVelZCopy, floor_nX, floor_nY, floor_nZ, &objYawX, &objYawZ);
        gCurrentObject->oAngleYaw = atan2s(objYawZ, objYawX);
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
    f32 (*sp1c)[4][4];

    if (D_80331500 == 0) return;
    if ((obj->gfx.graphFlags & 0x4) != 0) return; //bit 2
    sp1c = (f32 (*)[4][4])alloc_display_list(0x40);
    if (sp1c == NULL) return;

    sp2c[0] = obj->oPosX;
    sp2c[1] = obj->oPosY + obj->oGraphYOffset;
    sp2c[2] = obj->oPosZ;

    sp20[0] = normalX;
    sp20[1] = normalY;
    sp20[2] = normalZ;

    mtxf_from_up_direction(*sp1c, sp20, sp2c, obj->oFaceAngleYaw);
    obj->gfx.unk50 = (void *)sp1c;
}

//sp4 = floor_nY

void CalcObjGroundFVelMultiplier(f32 *objGroundFVelMultPtr, f32 floor_nY)
{
    if (floor_nY < 0.2 && gCurrentObject->oGroundFVelMultiplier < 0.9999) *objGroundFVelMultPtr = 0;
    else *objGroundFVelMultPtr = gCurrentObject->oGroundFVelMultiplier;
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
    f32 objGroundFVelMult;

    gCurrentObject->oVelY -= gCurrentObject->oGravity;
    if ((f64)gCurrentObject->oVelY > 75.0) gCurrentObject->oVelY = 75.0;
    if ((f64)gCurrentObject->oVelY < -75.0) gCurrentObject->oVelY = -75.0;

    gCurrentObject->oPosY += gCurrentObject->oVelY;
    if (gCurrentObject->oPosY < objFloorY) {
        gCurrentObject->oPosY = objFloorY;
        if ((f64)gCurrentObject->oVelY < -17.5)
            gCurrentObject->oVelY = -(gCurrentObject->oVelY/(f32)2.0);
        else gCurrentObject->oVelY = 0;
    }

    //! potential TRUNC crash
    if ((s32)gCurrentObject->oPosY >= (s32)objFloorY && (s32)gCurrentObject->oPosY < (s32)objFloorY + 37)
    {
        ObjOrientGraph(gCurrentObject, floor_nX, floor_nY, floor_nZ);
        objVelX += floor_nX * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * gCurrentObject->oGravity * 2.0f;
        objVelZ += floor_nZ * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * gCurrentObject->oGravity * 2.0f;

        if (objVelX < 0.000001 && objVelX > -0.000001) objVelX = 0;
        if (objVelZ < 0.000001 && objVelZ > -0.000001) objVelZ = 0;

        if (objVelX != 0 || objVelZ != 0) gCurrentObject->oAngleYaw = atan2s(objVelZ, objVelX);

        CalcObjGroundFVelMultiplier(&objGroundFVelMult, floor_nY);
        gCurrentObject->oForwardVel = sqrtf(objVelX * objVelX + objVelZ * objVelZ) * objGroundFVelMult;
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

    f32 netYAccel = (1.0f - gCurrentObject->oBuoyancy) * (-1.0f * gCurrentObject->oGravity);
    gCurrentObject->oVelY -= netYAccel;
    if (gCurrentObject->oVelY > 75.0) gCurrentObject->oVelY = 75.0;
    if (gCurrentObject->oVelY < -75.0) gCurrentObject->oVelY = -75.0;

    gCurrentObject->oPosY += gCurrentObject->oVelY;
    if (gCurrentObject->oPosY < floorY)
    {
        gCurrentObject->oPosY = floorY;
        if ((f64)gCurrentObject->oVelY < -17.5)
            gCurrentObject->oVelY = -(gCurrentObject->oVelY/2.0f);
        else gCurrentObject->oVelY = 0;
    }

    if ((f64)gCurrentObject->oForwardVel > 12.5 && (waterY + 30.0f) > gCurrentObject->oPosY && waterY - 30.0f < gCurrentObject->oPosY)
        gCurrentObject->oVelY = -gCurrentObject->oVelY;

    if ((s32)gCurrentObject->oPosY >= (s32)floorY && (s32)gCurrentObject->oPosY < (s32)floorY + 37)
    {
        ObjOrientGraph(gCurrentObject, floor_nX, floor_nY, floor_nZ);
        objVelX += floor_nX * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * netYAccel * 2.0f;
        objVelZ += floor_nZ * (floor_nX * floor_nX + floor_nZ * floor_nZ) / (floor_nX * floor_nX + floor_nY * floor_nY + floor_nZ * floor_nZ) * netYAccel * 2.0f;
    }

    if (objVelX < 0.000001 && objVelX > -0.000001) objVelX = 0;
    if (objVelZ < 0.000001 && objVelZ > -0.000001) objVelZ = 0;

    if ((f64)gCurrentObject->oVelY < 0.000001 && (f64)gCurrentObject->oVelY > -0.000001) gCurrentObject->oVelY = 0;

    if (objVelX != 0 || objVelZ != 0) gCurrentObject->oAngleYaw = atan2s(objVelZ, objVelX);
    gCurrentObject->oForwardVel = sqrtf(objVelX * objVelX + objVelZ * objVelZ) * 0.8;
    gCurrentObject->oVelY *= 0.8;
}

//sp4 = xVel
//sp0 = zVel

void ObjUpdatePosVelXZ(void)
{
    f32 xVel = gCurrentObject->oForwardVel * sins(gCurrentObject->oAngleYaw);
    f32 zVel = gCurrentObject->oForwardVel * coss(gCurrentObject->oAngleYaw);

    gCurrentObject->oPosX += xVel;
    gCurrentObject->oPosZ += zVel;
}

//sp20 = waterY
//sp24 = objY
//sp1c = globalTimer

void ObjSplash(s32 waterY, s32 objY)
{
    u32 globalTimer = gGlobalTimer;
    if ((f32)(waterY + 30) > gCurrentObject->oPosY && gCurrentObject->oPosY > (f32)(waterY - 30))
    {
        SpawnObj(gCurrentObject, 0xA6, beh_water_wave);
        if (gCurrentObject->oVelY < -20.0f) PlaySound2(0x50324081);
    }

    if ((objY + 50) < waterY && (globalTimer & 0x1F) == 0) SpawnObj(gCurrentObject, 0xA4, beh_dirt); /* 0x1F is bits 4-0 */
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
    f32 objX = gCurrentObject->oPosX;
    f32 objY = gCurrentObject->oPosY;
    f32 objZ = gCurrentObject->oPosZ;
    f32 floorY;
    f32 waterY = -10000.0;
    f32 objVelX = gCurrentObject->oForwardVel * sins(gCurrentObject->oAngleYaw);
    f32 objVelZ = gCurrentObject->oForwardVel * coss(gCurrentObject->oAngleYaw);
    s16 collisionFlags = 0;

    if (ObjFindWall(objX + objVelX, objY, objZ + objVelZ, objVelX, objVelZ) == 0) collisionFlags += COLLISION_FLAG_1;

    floorY = find_floor(objX + objVelX, objY, objZ + objVelZ, &D_803600E0);

    if (TurnObjAwayFromAwkwardFloor(D_803600E0, floorY, objVelX, objVelZ) == 1)
    {
        waterY = find_water_level(objX + objVelX, objZ + objVelZ);
        if (waterY > objY)
        {
            CalcNewObjVelAndPosYUnderwater(D_803600E0, floorY, objVelX, objVelZ, waterY);
            collisionFlags += COLLISION_FLAG_2;
        }
        else CalcNewObjVelAndPosY(D_803600E0, floorY, objVelX, objVelZ);
    }
    else collisionFlags += ((collisionFlags & COLLISION_FLAG_1) ^ COLLISION_FLAG_1); /* bit 1 = 1 */

    ObjUpdatePosVelXZ();
    if ((s32)gCurrentObject->oPosY == (s32)floorY) collisionFlags += COLLISION_FLAG_0;
    if ((s32)gCurrentObject->oVelY == 0) collisionFlags += COLLISION_FLAG_3;

    ObjSplash((s32)waterY, (s32)gCurrentObject->oPosY);

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
    gCurrentObject->oVelX = obj->oForwardVel * sins(obj->oAngleYaw);
    gCurrentObject->oVelZ = obj->oForwardVel * coss(obj->oAngleYaw);

    obj->oPosX += gCurrentObject->oVelX;
    obj->oPosY += obj->oVelY;
    obj->oPosZ += gCurrentObject->oVelZ;
}

//sp18 = arg2

s32 IsPointCloseToMario(f32 x, f32 y, f32 z, s32 dist)
{
    f32 mGfxX = gMarioObject->gfx.unk20[0];
    f32 mGfxY = gMarioObject->gfx.unk20[1];
    f32 mGfxZ = gMarioObject->gfx.unk20[2];

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

    if (IsPointCloseToMario(objX, objY, objZ, arg1) == 1) obj->gfx.graphFlags &= ~0x10; /* bit 4 = 0 */
    else obj->gfx.graphFlags |= 0x10; /* bit 4 = 1 */
}

//sp28 = obj
//sp2c = homeX
//sp30 = y
//sp34 = homeZ

s32 ObjLeaveIfMarioIsHome(struct Object* obj, f32 homeX, f32 y, f32 homeZ, s32 dist)
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
//sp2c = arg1
//sp30 = arg2
//sp34 = arg3

void func_802E45A0(struct Object* obj, f32 arg1, UNUSED f32 arg2, f32 arg3, s32 arg4)
{
    s16 angleToHome;
    f32 homeDistX, homeDistZ;

    if ((s32)(RandomFloat() * 50.0f) == 0)
    {
        obj->oHomeX = (f32)(arg4 * 2) * RandomFloat() - (f32)arg4 + arg1;
        obj->oHomeZ = (f32)(arg4 * 2) * RandomFloat() - (f32)arg4 + arg3;
    }

    homeDistX = obj->oHomeX - obj->oPosX;
    homeDistZ = obj->oHomeZ - obj->oPosZ;
    angleToHome = atan2s(homeDistZ, homeDistX);
    obj->oAngleYaw = approach_target_angle(obj->oAngleYaw, angleToHome, 320);
}

s32 func_802E46C0(u32 arg0, u32 arg1, s16 arg2)
{
    s16 sp6 = (u16)arg1 - (u16)arg0;
    if ((f32)sins(-arg2) < (f32)sins(sp6) && (f32)sins(sp6) < (f32)sins(arg2) && coss(sp6) > 0)
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

//sp20 = arg0
//sp24 = arg1

void func_802E4850(struct Object *obj, s32 arg1)
{
    struct Object *coin;
    s8 count;

    for(count = 0; count < (s8)arg1; count++)
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
        if (obj->oTimer % 2 != 0) obj->gfx.graphFlags |= 0x10; /* bit 4 = 1 */
        else obj->gfx.graphFlags &= ~0x10; /* bit 4 = 0 */
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
           (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, (s32)arg2) == 1
        &&  func_802E46C0(gCurrentObject->oFaceAngleYaw, gMarioObject->gfx.unk1A[1] + 0x8000, 0x1000) == 1
        &&  func_802E46C0(gCurrentObject->oAngleYaw, gCurrentObject->oAngleToMario, 0x1000) == 1)
    ||
           (*arg0 == 1)
    )
    {
        *arg0 = 1;
        if (func_802573C8(arg3) == 2)
        {
            sp1e = func_8028F8E0(162, gCurrentObject, arg1);
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
            case 1: gCurrentObject->oAction = OBJ_ACT_LAVA_DEATH; break;
            case 10: gCurrentObject->oAction = OBJ_ACT_DEATH_PLANE_DEATH; break;
            default: break;
        }
    }
}

//sp10 = arg0

s32 func_802E4C08(void)
{
    struct Object* bigSmoke;

    if (gCurrentObject->oTimer >= 31)
    {
        gCurrentObject->active = 0;
        return 1;
    }
    else gCurrentObject->oPosY -= 10.0f;

    if ((gCurrentObject->oTimer % 8) == 0)
    {
        PlaySound2(0x5118A081);
        bigSmoke = SpawnObj(gCurrentObject, 0x96, beh_large_white_smoke_cloud);
        bigSmoke->oPosX += RandomFloat() * 20.0f;
        bigSmoke->oPosY += RandomFloat() * 20.0f;
        bigSmoke->oPosZ += RandomFloat() * 20.0f;
        bigSmoke->oForwardVel = RandomFloat() * 10.0f;
    }

    return 0;
}

//sp30 = arg0
//sp34 = arg1
//sp38 = arg2
//sp3c = arg3

void func_802E4D5C(s8 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    struct Object* orangeNumber;

    if (arg0 >= 10) return;

    orangeNumber = SpawnObjAdv(arg0, arg1, arg2, arg3, gCurrentObject, 219, beh_orange_number);
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

void MovingCoinBlinkingLoop(void)
{
    s16 collisionFlags;

    CoinStep(&collisionFlags);
    ObjFlickerAndDisappear(gCurrentObject, 0);
}

void CoinCollected(void)
{
    SpawnObj(gCurrentObject, 149, beh_golden_coin_sparkles);
    gCurrentObject->active = 0;
}

void BehMovingYellowCoinInit(void)
{
    gCurrentObject->oGravity = 3.0f;
    gCurrentObject->oGroundFVelMultiplier = 1.0f;
    gCurrentObject->oBuoyancy = 1.5f;

    func_802A2CFC(gCurrentObject, &D_80331514);
}

void BehMovingYellowCoinLoop(void)
{
    s16 collisionFlags;

    switch (gCurrentObject->oAction)
    {
        case MOV_YCOIN_ACT_IDLE:
            CoinStep(&collisionFlags);

            if (gCurrentObject->oTimer < 10) func_8029FE38();
            else func_8029FE58();

            if (gCurrentObject->oTimer >= 301) gCurrentObject->oAction = 1;
            break;

        case MOV_YCOIN_ACT_BLINKING:
            MovingCoinBlinkingLoop();
            break;

        case MOV_YCOIN_ACT_LAVA_DEATH:
            gCurrentObject->active = 0;
            break;

        case MOV_YCOIN_ACT_DEATH_PLANE_DEATH:
            gCurrentObject->active = 0;
            break;
    }

    if ((gCurrentObject->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        gCurrentObject->oInteractStatus = 0;
    }
}

void BehMovingBlueCoinInit(void)
{
    gCurrentObject->oGravity = 5.0f;
    gCurrentObject->oGroundFVelMultiplier = 1.0f;
    gCurrentObject->oBuoyancy = 1.5f;

    func_802A2CFC(gCurrentObject, &D_80331524);
}

void BehMovingBlueCoinLoop(void)
{
    s16 collisionFlags;

    switch (gCurrentObject->oAction)
    {
        case MOV_BCOIN_ACT_STILL:
            if (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, 1500) != 0)
                gCurrentObject->oAction = 1;
            break;

        case MOV_BCOIN_ACT_MOVING:
            collisionFlags = ObjectStep();
            if ((collisionFlags & 0x1) != 0) /* bit 0 */
            {
                gCurrentObject->oForwardVel += 25.0f;
                if ((collisionFlags & 0x8) == 0) PlaySound2(0x30364081); /* bit 3 */
            }
            else gCurrentObject->oForwardVel *= 0.98;

            if ((f64)gCurrentObject->oForwardVel > 75.0) gCurrentObject->oForwardVel = 75.0f;

            ObjFlickerAndDisappear(gCurrentObject, 600);
            break;
    }

    if ((gCurrentObject->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        gCurrentObject->oInteractStatus = 0;
    }
}

void BehBlueCoinSlidingJumpingInit(void)
{
    gCurrentObject->oGravity = 3.0;
    gCurrentObject->oGroundFVelMultiplier = 0.98;
    gCurrentObject->oBuoyancy = 1.5;

    func_802A2CFC(gCurrentObject, &D_80331524);
}

void func_802E540C(void)
{
    s16 collisionFlags;

    gCurrentObject->oForwardVel = 15.0;
    gCurrentObject->oAngleYaw = gCurrentObject->oAngleToMario + 0x8000;

    if (CoinStep(&collisionFlags) != 0) gCurrentObject->oVelY += 18.0f;
    if ((collisionFlags & 0x2) != 0) gCurrentObject->oAction = 3; /* bit 1 */

    if (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, 1000) == 0)
        gCurrentObject->oAction = 2;
}

void func_802E54DC(void)
{
    s16 collisionFlags;

    CoinStep(&collisionFlags);

    if (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, 500) == 1)
        gCurrentObject->oAction = 1;

    if (gCurrentObject->oTimer >= 151)
        gCurrentObject->oAction = 3;
}

void BehBlueCoinSlidingLoop(void)
{
    s16 collisionFlags;

    switch (gCurrentObject->oAction)
    {
        case 0:
            if (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, 500) == 1)
                gCurrentObject->oAction = 1;

            SetObjectVisibility(gCurrentObject, 3000);
            break;

        case 1:
            func_802E540C();
            break;

        case 2:
            func_802E54DC();
            SetObjectVisibility(gCurrentObject, 3000);
            break;

        case 3:
            CoinStep(&collisionFlags);
            if (gCurrentObject->oTimer >= 61)
                gCurrentObject->oAction = 4;
            break;

        case 4:
            MovingCoinBlinkingLoop();
            break;

        case 100:
            gCurrentObject->active = 0;
            break;

        case 101:
            gCurrentObject->active = 0;
            break;
    }

    if ((gCurrentObject->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        gCurrentObject->oInteractStatus = 0;
    }
}

void BehBlueCoinJumpingLoop(void)
{
    s16 collisionFlags;

    switch (gCurrentObject->oAction)
    {
        case 0:
            if (gCurrentObject->oTimer == 0)
            {
                func_8029FE38();
                gCurrentObject->oVelY = 50.0;
            }

            ObjectStep();

            if (gCurrentObject->oTimer == 15)
            {
                func_8029FE58();
                gCurrentObject->oAction = 1;
            }
            break;

        case 1:
            func_802E540C();
            break;

        case 2:
            func_802E54DC();
            SetObjectVisibility(gCurrentObject, 3000);
            break;

        case 3:
            CoinStep(&collisionFlags);
            if (gCurrentObject->oTimer >= 61) gCurrentObject->oAction = 4;
            break;

        case 4:
            MovingCoinBlinkingLoop();
            break;
    }

    if ((gCurrentObject->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        CoinCollected();
        gCurrentObject->oInteractStatus = 0;
    }
}

void BehSeaweedInit(void)
{
    gCurrentObject->gfx.unk40 = RandomFloat() * 80.0f;
}

void BehSeaweedBundleInit(void)
{
    struct Object *seaweed;

    seaweed = SpawnObj(gCurrentObject, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 14523;
    seaweed->oFaceAnglePitch = 5500;
    seaweed->oFaceAngleRoll = 9600;
    seaweed->gfx.scale[0] = 1.0;
    seaweed->gfx.scale[1] = 1.0;
    seaweed->gfx.scale[2] = 1.0;
    //!gfx.unk40 uninitialized

    seaweed = SpawnObj(gCurrentObject, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 41800;
    seaweed->oFaceAnglePitch = 6102;
    seaweed->oFaceAngleRoll = 0;
    seaweed->gfx.scale[0] = 0.8;
    seaweed->gfx.scale[1] = 0.9;
    seaweed->gfx.scale[2] = 0.8;
    seaweed->gfx.unk40 = RandomFloat() * 80.0f;

    seaweed = SpawnObj(gCurrentObject, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 40500;
    seaweed->oFaceAnglePitch = 8700;
    seaweed->oFaceAngleRoll = 4100;
    seaweed->gfx.scale[0] = 0.8;
    seaweed->gfx.scale[1] = 0.8;
    seaweed->gfx.scale[2] = 0.8;
    seaweed->gfx.unk40 = RandomFloat() * 80.0f;

    seaweed = SpawnObj(gCurrentObject, 193, beh_seaweed);
    seaweed->oFaceAngleYaw = 57236;
    seaweed->oFaceAnglePitch = 9500;
    seaweed->oFaceAngleRoll = 0;
    seaweed->gfx.scale[0] = 1.2;
    seaweed->gfx.scale[1] = 1.2;
    seaweed->gfx.scale[2] = 1.2;
    seaweed->gfx.unk40 = RandomFloat() * 80.0f;
}

void BehBobombInit(void)
{
    gCurrentObject->oGravity = 2.5;
    gCurrentObject->oGroundFVelMultiplier = 0.8;
    gCurrentObject->oBuoyancy = 1.3;
    gCurrentObject->oUnk190 = 0x100;
}

void func_802E5B7C(void)
{
    if (((gCurrentObject->oUnk188 >> 8) & 0x1) == 0)
    {
        func_802E4850(gCurrentObject, 1);
        gCurrentObject->oUnk188 = 0x100;
        func_8029C6D8(gCurrentObject, 1);
    }
}

void BobombExplodeLoop(void)
{
    struct Object *explosion;

    if (gCurrentObject->oTimer < 5) ScaleObject(1.0 + (f32)gCurrentObject->oTimer / 5.0);
    else
    {
        explosion = SpawnObj(gCurrentObject, 205, beh_explosion);
        explosion->oGraphYOffset += 100.0f;

        func_802E5B7C();
        func_802EA074(0xBC, beh_bobomb, 3000);
        gCurrentObject->active = 0;
    }
}

void CheckBobombInteractions(void)
{
    func_802A2CFC(gCurrentObject, &D_80331534);

    if ((gCurrentObject->oInteractStatus & 0x8000) != 0) /* bit 15 */
    {
        if ((gCurrentObject->oInteractStatus & 0x2) != 0) /* bit 1 */
        {
            gCurrentObject->oAngleYaw = gMarioObject->gfx.unk1A[1];
            gCurrentObject->oForwardVel = 25.0;
            gCurrentObject->oVelY = 30.0;
            gCurrentObject->oAction = BOBOMB_ACT_THROWN;
        }

        if ((gCurrentObject->oInteractStatus & 0x800000) != 0) /* bit 23 */
            gCurrentObject->oAction = BOBOMB_ACT_EXPLODE;

        gCurrentObject->oInteractStatus = 0;
    }

    if (func_802A4964(gCurrentObject) == 1) gCurrentObject->oAction = BOBOMB_ACT_EXPLODE;
}

void BobombPatrolLoop(void)
{
    UNUSED s8 filler[4];
    UNUSED s16 sp22;
    s16 collisionFlags;

    sp22 = gCurrentObject->gfx.unk40;
    gCurrentObject->oForwardVel = 5.0;

    collisionFlags = ObjectStep();
    if ((ObjLeaveIfMarioIsHome(gCurrentObject, gCurrentObject->oHomeX, gCurrentObject->oHomeY, gCurrentObject->oHomeZ, 400) == 1)
    &&  (func_802E46C0(gCurrentObject->oAngleYaw, gCurrentObject->oAngleToMario, 0x2000) == 1))
    {
        gCurrentObject->oBobombFuseLit = 1;
        gCurrentObject->oAction = BOBOMB_ACT_CHASE_MARIO;
    }

    ObjCheckFloorDeath(collisionFlags, D_803600E0);
}

void BobombChaseMarioLoop(void)
{
    UNUSED u8 filler[4];
    s16 sp1a, collisionFlags;

    sp1a = ++gCurrentObject->gfx.unk40;
    gCurrentObject->oForwardVel = 20.0;

    collisionFlags = ObjectStep();

    if (sp1a == 5 || sp1a == 16) PlaySound2(0x50270081);

    UnknownMove(gCurrentObject, gMarioObject, 16, 0x800);
    ObjCheckFloorDeath(collisionFlags, D_803600E0);
}

void BobombActThrownLoop(void)
{
    s16 collisionFlags = 0;
    collisionFlags = ObjectStep();
    if ((collisionFlags & 0x1) == 1) gCurrentObject->oAction = BOBOMB_ACT_EXPLODE; /* bit 0 */
}

void GenericBobombFreeLoop(void)
{
    switch (gCurrentObject->oAction)
    {
        case BOBOMB_ACT_PATROL:
            BobombPatrolLoop();
            break;

        case BOBOMB_ACT_THROWN:
            BobombActThrownLoop();
            break;

        case BOBOMB_ACT_CHASE_MARIO:
            BobombChaseMarioLoop();
            break;

        case BOBOMB_ACT_EXPLODE:
            BobombExplodeLoop();
            break;

        case BOBOMB_ACT_LAVA_DEATH:
            if (func_802E4C08() == 1) func_802EA074(188, beh_bobomb, 3000);
            break;

        case BOBOMB_ACT_DEATH_PLANE_DEATH:
            gCurrentObject->active = 0;
            func_802EA074(188, beh_bobomb, 3000);
            break;
    }

    CheckBobombInteractions();

    if (gCurrentObject->oBobombFuseTimer >= 151) gCurrentObject->oAction = 3;
}

void StationaryBobombFreeLoop(void)
{
    switch (gCurrentObject->oAction)
    {
        case BOBOMB_ACT_THROWN:
            BobombActThrownLoop();
            break;

        case BOBOMB_ACT_EXPLODE:
            BobombExplodeLoop();
            break;

        case BOBOMB_ACT_LAVA_DEATH:
            if (func_802E4C08() == 1) func_802EA074(188, beh_bobomb, 3000);
            break;

        case BOBOMB_ACT_DEATH_PLANE_DEATH:
            gCurrentObject->active = 0;
            func_802EA074(188, beh_bobomb, 3000);
            break;
    }

    CheckBobombInteractions();

    if (gCurrentObject->oBobombFuseTimer >= 151) gCurrentObject->oAction = 3;
}

void BobombFreeLoop(void)
{
    if (gCurrentObject->oBehParam == BOBOMB_BP_STYPE_GENERIC) GenericBobombFreeLoop();
    else StationaryBobombFreeLoop();
}

void BobombHeldLoop(void)
{
    gCurrentObject->gfx.graphFlags |= 0x10; /* bit 4 */
    SetObjAnimation(1);
    func_8029EF64(gMarioObject, 0, 60.0f, 100.0);

    gCurrentObject->oBobombFuseLit = 1;
    if (gCurrentObject->oBobombFuseTimer >= 151)
    {
        //! Although the Bob-omb's action is set to explode when the fuse timer expires,
        //  BobombExplodeLoop() will not execute until the bob-omb's held state changes.
        //    This allows the Bob-omb to be regrabbed indefinitely.

        gMarioObject->oInteractStatus |= 0x8; /* bit 3 */
        gCurrentObject->oAction = BOBOMB_ACT_EXPLODE;
    }
}

void BobombDroppedLoop(void)
{
    func_8029FCF8();

    gCurrentObject->gfx.graphFlags &= ~0x10; /* bit 4 = 0 */
    SetObjAnimation(0);

    gCurrentObject->oHeldState = 0;
    gCurrentObject->oAction = BOBOMB_ACT_PATROL;
}

void BobombHeldThrownLoop(void)
{
    func_8029F0A4();

    gCurrentObject->gfx.graphFlags &= ~0x10; /* bit 4 = 0 */
    gCurrentObject->oHeldState = 0;
    gCurrentObject->oFlags &= ~0x8; /* bit 3 */
    gCurrentObject->oForwardVel = 25.0;
    gCurrentObject->oVelY = 20.0;
    gCurrentObject->oAction = BOBOMB_ACT_THROWN;
}

//sp18 = blinkTimer

void ObjRandomBlink(s32 *blinkTimer)
{
    if (*blinkTimer == 0)
    {
        if ((s16)(RandomFloat() * 100.0f) == 0)
        {
            gCurrentObject->oEyesClosed = 1;
            *blinkTimer = 1;
        }
    }
    else
    {
        (*blinkTimer)++;
        if (*blinkTimer >= 6) gCurrentObject->oEyesClosed = 0;
        if (*blinkTimer >= 11) gCurrentObject->oEyesClosed = 1;
        if (*blinkTimer >= 16)
        {
            gCurrentObject->oEyesClosed = 0;
            *blinkTimer = 0;
        }
    }
}

void BehBobombLoop(void)
{
    s8 dustPeriodMinus1;

    if (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, 4000) != 0)
    {
        switch (gCurrentObject->oHeldState)
        {
            case HELD_FREE:
                BobombFreeLoop();
                break;

            case HELD_HELD:
                BobombHeldLoop();
                break;

            case HELD_THROWN:
                BobombHeldThrownLoop();
                break;

            case HELD_DROPPED:
                BobombDroppedLoop();
                break;
        }


        ObjRandomBlink(&gCurrentObject->oBobombBlinkTimer);

        if (gCurrentObject->oBobombFuseLit == 1)
        {
            if (gCurrentObject->oBobombFuseTimer >= 121) dustPeriodMinus1 = 1;
            else dustPeriodMinus1 = 7;

            if ((dustPeriodMinus1 & gCurrentObject->oBobombFuseTimer) == 0) /* oBobombFuseTimer % 2 or oBobombFuseTimer % 8 */
                SpawnObj(gCurrentObject, 150, beh_bobomb_fuse_smoke);

            PlaySound(0x60086001);

            gCurrentObject->oBobombFuseTimer++;
        }
    }
}

void BehBobombFuseSmokeInit(void)
{
    gCurrentObject->oPosX += (s32)(RandomFloat() * 80.0f) - 40;
    gCurrentObject->oPosY += (s32)(RandomFloat() * 80.0f) + 60;
    gCurrentObject->oPosZ += (s32)(RandomFloat() * 80.0f) - 40;

    ScaleObject(1.2f);
}

void BehBobombBuddyInit(void)
{
    gCurrentObject->oGravity = 2.5;
    gCurrentObject->oGroundFVelMultiplier = 0.8;
    gCurrentObject->oBuoyancy = 1.3;
    gCurrentObject->oUnk190 = 0x4000;
}

void BobombBuddyIdleLoop(void)
{
    UNUSED u8 filler[4];
    s16 sp1a = gCurrentObject->gfx.unk40;
    UNUSED s16 collisionFlags = 0;

    gCurrentObject->oBobombBuddyPosXCopy = gCurrentObject->oPosX;
    gCurrentObject->oBobombBuddyPosYCopy = gCurrentObject->oPosY;
    gCurrentObject->oBobombBuddyPosZCopy = gCurrentObject->oPosZ;

    collisionFlags = ObjectStep();

    if ((sp1a == 5) || (sp1a == 16)) PlaySound2(0x50270081);

    if (gCurrentObject->oDistanceToMario < 1000.0f)
        gCurrentObject->oAngleYaw = approach_target_angle(gCurrentObject->oAngleYaw, gCurrentObject->oAngleToMario, 0x140);

    if (gCurrentObject->oInteractStatus == 0x8000) gCurrentObject->oAction = BOBOMB_BUDDY_ACT_TURN_TO_TALK;
}

//sp30 = arg0
//sp34 = arg1

void BobombBuddyCannonLoop(s16 arg0, s16 arg1)
{
    s32 sp2c;
    s16 sp2a, sp28;

    switch (gCurrentObject->oBobombBuddyCannonStatus)
    {
        case BOBOMB_BUDDY_CANNON_UNOPENED:
            sp2a = func_8028F8E0(162, gCurrentObject, arg0);
            if (sp2a != 0)
            {
                save_file_set_cannon_unlocked();

                sp2c = func_8029F1E0(beh_cannon_trap_door);
                if (sp2c != 0) gCurrentObject->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_OPENING;
                else gCurrentObject->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_STOP_TALKING;
            }
            break;

        case BOBOMB_BUDDY_CANNON_OPENING:
            sp2c = func_8029F1E0(beh_cannon_trap_door);
            sp28 = func_8028F9E8(150, sp2c);
            if (sp28 == -1) gCurrentObject->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_OPENED;
            break;

        case BOBOMB_BUDDY_CANNON_OPENED:
            sp2a = func_8028F8E0(162, gCurrentObject, arg1);
            if (sp2a != 0) gCurrentObject->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_STOP_TALKING;
            break;

        case BOBOMB_BUDDY_CANNON_STOP_TALKING:
            func_802573C8(0);

            gCurrentObject->active &= ~0x20; /* bit 5 */
            gCurrentObject->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
            gCurrentObject->oInteractStatus = 0;
            gCurrentObject->oAction = BOBOMB_BUDDY_ACT_IDLE;
            gCurrentObject->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_OPENED;
            break;
    }
}

void BobombBuddyTalkLoop(void)
{
    if (func_802573C8(1) == 2)
    {
        gCurrentObject->active |= 0x20; /* bit 5 */

        switch (gCurrentObject->oBobombBuddyRole)
        {
            case BOBOMB_BUDDY_ROLE_ADVICE:
                if (func_8028F8E0(162, gCurrentObject, gCurrentObject->oBehParam) != BOBOMB_BUDDY_BP_STYPE_GENERIC)
                {
                    func_802573C8(0);

                    gCurrentObject->active &= ~0x20; /* bit 5 */
                    gCurrentObject->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
                    gCurrentObject->oInteractStatus = 0;
                    gCurrentObject->oAction = BOBOMB_BUDDY_ACT_IDLE;
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
    s16 sp1e = gCurrentObject->gfx.unk40;
    if ((sp1e == 5) || (sp1e == 16)) PlaySound2(0x50270081);

    gCurrentObject->oAngleYaw = approach_target_angle(gCurrentObject->oAngleYaw, gCurrentObject->oAngleToMario, 0x1000);
    if ((s16)gCurrentObject->oAngleYaw == (s16)gCurrentObject->oAngleToMario)
        gCurrentObject->oAction = BOBOMB_BUDDY_ACT_TALK;

    PlaySound2(0x045BFF81);
}

void BobombBuddyActionLoop(void)
{
    switch (gCurrentObject->oAction)
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

    SetObjectVisibility(gCurrentObject, 3000);
}

void BehBobombBuddyLoop(void)
{
    BobombBuddyActionLoop();

    ObjRandomBlink(&gCurrentObject->oBobombBuddyBlinkTimer);

    gCurrentObject->oInteractStatus = 0;
}

void BehCannonTrapDoorInit(void)
{
    struct Object *cannonTrapDoor;

    if (save_file_is_cannon_unlocked() == 1)
    {
        cannonTrapDoor = SpawnObj(gCurrentObject, 128, beh_cannon_base);
        cannonTrapDoor->oBehParam = gCurrentObject->oBehParam;
        cannonTrapDoor->oPosX = gCurrentObject->oHomeX;
        cannonTrapDoor->oPosY = gCurrentObject->oHomeY;
        cannonTrapDoor->oPosZ = gCurrentObject->oHomeZ;

        gCurrentObject->oAction = CANNON_TRAP_DOOR_ACT_OPEN;
        gCurrentObject->active = 0;
    }
}

void CannonTrapDoorOpeningLoop(void)
{
    if (gCurrentObject->oTimer == 0) PlaySound2(0x30478081);

    if (gCurrentObject->oTimer < 30)
    {
        gCurrentObject->oVelY = -0.5f;
        gCurrentObject->oPosY += gCurrentObject->oVelY;
        gCurrentObject->oVelX = 0;
    }
    else
    {
        if (gCurrentObject->oTimer == 80)
        {
            BehCannonTrapDoorInit();
            return;
        }

        gCurrentObject->oVelX = 4.0f;
        gCurrentObject->oVelY = 0;
        gCurrentObject->oPosX += gCurrentObject->oVelX;
    }
}

void BehCannonTrapDoorLoop(void)
{
    switch (gCurrentObject->oAction)
    {
        case CANNON_TRAP_DOOR_ACT_CLOSED:
            gCurrentObject->oVelX = 0;
            gCurrentObject->oVelY = 0;
            gCurrentObject->oDrawingDistance = 4000.0f;

            if (save_file_is_cannon_unlocked() == 1)
                gCurrentObject->oAction = CANNON_TRAP_DOOR_ACT_CAM_ZOOM;
            break;

        case CANNON_TRAP_DOOR_ACT_CAM_ZOOM:
            if (gCurrentObject->oTimer == 60) gCurrentObject->oAction = CANNON_TRAP_DOOR_ACT_OPENING;

            gCurrentObject->oDrawingDistance = 20000.0f;
            break;

        case CANNON_TRAP_DOOR_ACT_OPENING:
            CannonTrapDoorOpeningLoop();
            break;
    }
}

void BehWhirlpoolInit(void)
{
    gCurrentObject->oWhirlpoolInitFacePitch = gCurrentObject->oFaceAnglePitch;
    gCurrentObject->oWhirlpoolInitFaceRoll = gCurrentObject->oFaceAngleRoll;
    gCurrentObject->oFaceAnglePitch = 0;
    gCurrentObject->oFaceAngleRoll = 0;
}

void func_802E70A8(void)
{
    func_802A2CFC(gCurrentObject, &D_80331544);
}

void func_802E70DC(void)
{
    f32 cosPitch = coss(gCurrentObject->oFaceAnglePitch);
    f32 sinPitch = sins(gCurrentObject->oFaceAnglePitch);
    f32 cosRoll = coss(gCurrentObject->oFaceAngleRoll);
    f32 sinRoll = sins(gCurrentObject->oFaceAngleRoll);
    f32 normalX = sinRoll * cosPitch;
    f32 normalY = cosPitch * cosRoll;
    f32 normalZ = sinPitch;
    ObjOrientGraph(gCurrentObject, normalX, normalY, normalZ);
}

void BehWhirlpoolLoop(void)
{
    if (gCurrentObject->oDistanceToMario < 5000.0f)
    {
        gCurrentObject->gfx.graphFlags &= ~0x10; /* bit 4 */

        //not sure if actually an array
        D_803600B0[7] = 60;
        D_803600B0[1] = gCurrentObject->oPosX;
        D_803600B0[3] = gCurrentObject->oPosZ;
        D_803600B0[4] = gCurrentObject->oPosX;
        D_803600B0[5] = gCurrentObject->oPosY;
        D_803600B0[6] = gCurrentObject->oPosZ;
        D_803600B0[2] = gCurrentObject->oPosY + 800.0f;
        D_803600B0[8] = gCurrentObject->oWhirlpoolInitFacePitch;
        D_803600B0[9] = gCurrentObject->oWhirlpoolInitFaceRoll;

        func_802E70DC();

        gCurrentObject->oFaceAngleYaw += 0x1F40;
    }
    else
    {
        gCurrentObject->gfx.graphFlags |= 0x10; /* bit 4 */
        D_803600B0[7] = 0;
    }

    PlaySound(0x40090001);

    func_802E70A8();
}

void BehJetStreamLoop(void)
{
    if (gCurrentObject->oDistanceToMario < 5000.0f)
    {
        D_803600B0[7] = 60;
        D_803600B0[1] = gCurrentObject->oPosX;
        D_803600B0[2] = gCurrentObject->oPosY;
        D_803600B0[3] = gCurrentObject->oPosZ;
    }
    else D_803600B0[7] = 0;

    PlaySound(0x40090001);
}

void BehAmpHomingInit(void)
{
    gCurrentObject->oHomeX = gCurrentObject->oPosX;
    gCurrentObject->oHomeY = gCurrentObject->oPosY;
    gCurrentObject->oHomeZ = gCurrentObject->oPosZ;
    gCurrentObject->oGravity = 0;
    gCurrentObject->oGroundFVelMultiplier = 1.0;
    gCurrentObject->oBuoyancy = 1.0;
    gCurrentObject->oAmpHomingAvgY = gCurrentObject->oHomeY;

    ScaleObject(0.1f);
    gCurrentObject->gfx.graphFlags |= 0x10; /* bit 4 */
}

void CheckAmpAttack(void)
{
    func_802A2CFC(gCurrentObject, &D_80331554);

    if (gCurrentObject->oInteractStatus & 0x8000) /* bit 15 */
    {
        if (gCurrentObject->oInteractStatus & 0x8000) /* bit 15 */
            gCurrentObject->oAction = AMP_HOMING_ACT_ATTACK_COOLDOWN;

        gCurrentObject->oInteractStatus = 0;
    }
}

void AmpHomingAppearLoop(void)
{
    f32 sp24 = D_8033B328.unk0[3][0] - gCurrentObject->oPosX;
    f32 sp20 = D_8033B328.unk0[3][2] - gCurrentObject->oPosZ;
    s16 targetYaw = atan2s(sp20, sp24);
    gCurrentObject->oAngleYaw = approach_target_angle(gCurrentObject->oAngleYaw, targetYaw, 0x1000);

    if (gCurrentObject->oTimer < 30)
        ScaleObject(0.1 + 0.9 * (f32)(gCurrentObject->oTimer / 30.0f));
    else gCurrentObject->oAmpHomingChargeAnim = 1;

    if (gCurrentObject->oTimer >= 91)
    {
        ScaleObject(1.0f);
        gCurrentObject->oAction = AMP_HOMING_ACT_CHASE;
        gCurrentObject->oAmpHomingYOscTimer = 0;
    }
}

void AmpHomingChaseLoop(void)
{
    if ((gCurrentObject->oAngleToMario - 0x400 < gCurrentObject->oAngleYaw)
    &&  (gCurrentObject->oAngleYaw < gCurrentObject->oAngleToMario + 0x400))
    {
        gCurrentObject->oAmpHomingLockedOn = 1;
        gCurrentObject->oTimer = 0;
    }

    if (gCurrentObject->oAmpHomingLockedOn == 1)
    {
        gCurrentObject->oForwardVel = 15.0f;

        if (gCurrentObject->oAmpHomingAvgY > gMarioObject->gfx.unk20[1] + 150.0f)
            gCurrentObject->oAmpHomingAvgY -= 10.0f;
        else gCurrentObject->oAmpHomingAvgY = gMarioObject->gfx.unk20[1] + 150.0f;

        if (gCurrentObject->oTimer >= 31) gCurrentObject->oAmpHomingLockedOn = 0;
    }
    else
    {
        gCurrentObject->oForwardVel = 10.0f;

        UnknownMove(gCurrentObject, gMarioObject, 16, 0x400);

        if (gCurrentObject->oAmpHomingAvgY < gMarioObject->gfx.unk20[1] + 250.0f)
            gCurrentObject->oAmpHomingAvgY += 10.0f;
    }

    gCurrentObject->oPosY = gCurrentObject->oAmpHomingAvgY + sins(gCurrentObject->oAmpHomingYOscTimer * 0x400) * 20.0f;

    CheckAmpAttack();

    if (IsPointCloseToMario(gCurrentObject->oHomeX, gCurrentObject->oHomeY, gCurrentObject->oHomeZ, 1500) == 0)
        gCurrentObject->oAction = AMP_HOMING_ACT_GIVE_UP;
}

void AmpHomingGiveUpLoop(void)
{
    UNUSED u8 filler[8];

    gCurrentObject->oForwardVel = 15.0f;

    if (gCurrentObject->oTimer >= 151)
    {
        gCurrentObject->oPosX = gCurrentObject->oHomeX;
        gCurrentObject->oPosY = gCurrentObject->oHomeY;
        gCurrentObject->oPosZ = gCurrentObject->oHomeZ;
        gCurrentObject->gfx.graphFlags |= 0x10; /* bit 4 */
        gCurrentObject->oAction = AMP_HOMING_ACT_INACTIVE;
        gCurrentObject->oAmpHomingChargeAnim = 0;
        gCurrentObject->oForwardVel = 0;
        gCurrentObject->oAmpHomingAvgY = gCurrentObject->oHomeY;
    }
}

void AmpAttackCooldownLoop(void)
{
    gCurrentObject->gfx.unk40 += 2;
    gCurrentObject->oForwardVel = 0;

    func_8029FE38();

    if (gCurrentObject->oTimer >= 31) gCurrentObject->oAmpHomingChargeAnim = 0;
    if (gCurrentObject->oTimer >= 91)
    {
        gCurrentObject->oAmpHomingChargeAnim = 1;
        func_8029FE58();
        gCurrentObject->oAction = AMP_HOMING_ACT_CHASE;
    }
}

void BehAmpHomingLoop(void)
{
    switch (gCurrentObject->oAction)
    {
        case AMP_HOMING_ACT_INACTIVE:
            if (IsPointCloseToMario(gCurrentObject->oHomeX, gCurrentObject->oHomeY, gCurrentObject->oHomeZ, 800) == 1)
            {
                gCurrentObject->oAction = AMP_HOMING_ACT_APPEAR;
                gCurrentObject->gfx.graphFlags &= ~0x10; /* bit 4 */
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

    gCurrentObject->oAmpHomingYOscTimer++;
}

void BehAmpInit(void)
{
    gCurrentObject->oHomeX = gCurrentObject->oPosX;
    gCurrentObject->oHomeY = gCurrentObject->oPosY;
    gCurrentObject->oHomeZ = gCurrentObject->oPosZ;
    gCurrentObject->oAmpChargeAnim = 1;

    switch (gCurrentObject->oBehParam)
    {
        case AMP_BP_ROT_RADIUS_200:
            gCurrentObject->oAmpRadiusOfRotation = 200.0f;
            break;

        case AMP_BP_ROT_RADIUS_300:
            gCurrentObject->oAmpRadiusOfRotation = 300.0f;
            break;

        case AMP_BP_ROT_RADIUS_400:
            gCurrentObject->oAmpRadiusOfRotation = 400.0f;
            break;

        case AMP_BP_ROT_RADIUS_0:
            break;
    }

    gCurrentObject->oAngleYaw = RandomU16();
    gCurrentObject->oAction = 2;
}

void FixedAmpIdleLoop(void)
{
    f32 xToMario = gMarioObject->gfx.unk20[0] - gCurrentObject->oPosX;
    f32 yToMario = gMarioObject->gfx.unk20[1] + 120.0f - gCurrentObject->oPosY;
    f32 zToMario = gMarioObject->gfx.unk20[2] - gCurrentObject->oPosZ;
    s16 vAngleToMario = atan2s(sqrtf(xToMario * xToMario + zToMario * zToMario), -yToMario);

    UnknownMove(gCurrentObject, gMarioObject, 19, 0x1000);
    gCurrentObject->oFaceAnglePitch = approach_target_angle(gCurrentObject->oFaceAnglePitch, vAngleToMario, 0x1000);

    gCurrentObject->oPosY = gCurrentObject->oHomeY + coss(gCurrentObject->oAmpYOscTimer * 0x458) * 20.0f;

    CheckAmpAttack();

    gCurrentObject->oAmpYOscTimer++;
}

void AmpIdleLoop(void)
{
    gCurrentObject->oPosX = gCurrentObject->oHomeX + sins(gCurrentObject->oAngleYaw) * gCurrentObject->oAmpRadiusOfRotation;
    gCurrentObject->oPosZ = gCurrentObject->oHomeZ + coss(gCurrentObject->oAngleYaw) * gCurrentObject->oAmpRadiusOfRotation;
    gCurrentObject->oPosY = gCurrentObject->oHomeY + coss(gCurrentObject->oAmpYOscTimer * 0x8B0) * 30.0f;
    gCurrentObject->oAngleYaw += 0x400;
    gCurrentObject->oFaceAngleYaw = gCurrentObject->oAngleYaw + 0x4000;

    CheckAmpAttack();

    gCurrentObject->oAmpYOscTimer++;

    PlaySound(0x60034001);
}

void BehAmpLoop(void)
{
    switch (gCurrentObject->oAction)
    {
        case AMP_ACT_IDLE:
            if (gCurrentObject->oBehParam == AMP_BP_ROT_RADIUS_0) FixedAmpIdleLoop();
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

    gCurrentObject->oButterflyYOscTimer = RandomFloat() * 100.0f;
    gCurrentObject->gfx.unk40 = RandomFloat() * 7.0f;
    gCurrentObject->oHomeX = gCurrentObject->oPosX;
    gCurrentObject->oHomeY = gCurrentObject->oPosY;
    gCurrentObject->oHomeZ = gCurrentObject->oPosZ;
}

//sp28 = speed

void ButterflyStep(s32 speed)
{
    f32 *sp24;
    s16 yaw = gCurrentObject->oAngleYaw;
    s16 pitch = gCurrentObject->oAnglePitch;
    s16 yOscTimer = gCurrentObject->oButterflyYOscTimer;
    f32 floorY;

    gCurrentObject->oVelX = sins(yaw) * (f32)speed;
    gCurrentObject->oVelY = sins(pitch) * (f32)speed;
    gCurrentObject->oVelZ = coss(yaw) * (f32)speed;

    gCurrentObject->oPosX += gCurrentObject->oVelX;
    gCurrentObject->oPosZ += gCurrentObject->oVelZ;

    if (gCurrentObject->oAction == BUTTERFLY_ACT_FOLLOW_MARIO)
        gCurrentObject->oPosY -= gCurrentObject->oVelY + coss((s32)(yOscTimer * 655.36)) * 20.0f / 4.0f;
    else gCurrentObject->oPosY -= gCurrentObject->oVelY;

    floorY = func_803814B8(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, &sp24);

    if (gCurrentObject->oPosY < floorY + 2.0f) gCurrentObject->oPosY = floorY + 2.0f;

    gCurrentObject->oButterflyYOscTimer++;
    if (gCurrentObject->oButterflyYOscTimer >= 101) gCurrentObject->oButterflyYOscTimer = 0;
}

void CalculateButterflyAngle(void)
{
    gMarioObject->oPosX += 5 * gCurrentObject->oButterflyYOscTimer / 4;
    gMarioObject->oPosZ += 5 * gCurrentObject->oButterflyYOscTimer / 4;
    UnknownMove(gCurrentObject, gMarioObject, 16, 0x300);
    gMarioObject->oPosX -= 5 * gCurrentObject->oButterflyYOscTimer / 4;
    gMarioObject->oPosZ -= 5 * gCurrentObject->oButterflyYOscTimer / 4;

    gMarioObject->oPosY += (5 * gCurrentObject->oButterflyYOscTimer + 0x100) / 4;
    UnknownMove(gCurrentObject, gMarioObject, 15, 0x500);
    gMarioObject->oPosY -= (5 * gCurrentObject->oButterflyYOscTimer + 0x100) / 4;
}

void ButterflyRestingLoop(void)
{
    if (IsPointCloseToMario(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, 1000))
    {
        SetObjAnimation(0);

        gCurrentObject->oAction = BUTTERFLY_ACT_FOLLOW_MARIO;
        gCurrentObject->oAngleYaw = gMarioObject->gfx.unk1A[1];
    }
}

void ButterflyFollowMarioLoop(void)
{
    CalculateButterflyAngle();

    ButterflyStep(7);

    if (!IsPointCloseToMario(gCurrentObject->oHomeX, gCurrentObject->oHomeY, gCurrentObject->oHomeZ, 1200))
        gCurrentObject->oAction = BUTTERFLY_ACT_RETURN_HOME;
}

void ButterflyReturnHomeLoop(void)
{
    f32 homeDistX = gCurrentObject->oHomeX - gCurrentObject->oPosX;
    f32 homeDistY = gCurrentObject->oHomeY - gCurrentObject->oPosY;
    f32 homeDistZ = gCurrentObject->oHomeZ - gCurrentObject->oPosZ;
    s16 hAngleToHome = atan2s(homeDistZ, homeDistX);
    s16 vAngleToHome = atan2s(sqrtf(homeDistX * homeDistX + homeDistZ * homeDistZ), -homeDistY);

    gCurrentObject->oAngleYaw = approach_target_angle(gCurrentObject->oAngleYaw, hAngleToHome, 0x800);
    gCurrentObject->oAnglePitch = approach_target_angle(gCurrentObject->oAnglePitch, vAngleToHome, 0x50);

    ButterflyStep(7);

    if (homeDistX * homeDistX + homeDistY * homeDistY + homeDistZ * homeDistZ < 144.0f)
    {
        SetObjAnimation(1);

        gCurrentObject->oAction = BUTTERFLY_ACT_RESTING;
        gCurrentObject->oPosX = gCurrentObject->oHomeX;
        gCurrentObject->oPosY = gCurrentObject->oHomeY;
        gCurrentObject->oPosZ = gCurrentObject->oHomeZ;
    }
}

void BehButterflyLoop(void)
{
    switch (gCurrentObject->oAction)
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

    SetObjectVisibility(gCurrentObject, 3000);
}

void BehHootInit(void)
{
    SetObjAnimation(0);

    gCurrentObject->oHomeX = gCurrentObject->oPosX + 800.0f;
    gCurrentObject->oHomeY = gCurrentObject->oPosY - 150.0f;
    gCurrentObject->oHomeZ = gCurrentObject->oPosZ + 300.0f;
    gCurrentObject->gfx.graphFlags |= 0x10; /* bit 4 */

    func_8029FE38();
}

//sp28 = arg0
//sp2c = arg1

f32 func_802E88EC(f32 **arg0, f32 arg1)
{
    f32 sp24 = arg1 * sins(gCurrentObject->oAngleYaw) + gCurrentObject->oPosX;
    UNUSED f32 sp20 = gCurrentObject->oPosY;
    f32 sp1c = arg1 * coss(gCurrentObject->oAngleYaw) + gCurrentObject->oPosZ;
    f32 floorY = func_803814B8(sp24, 10000.0f, sp1c, arg0);

    return floorY;
}