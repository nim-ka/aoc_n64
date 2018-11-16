#include <ultra64.h>

#include "sm64.h"
#include "behavior_actions.h"
#include "behavior_script.h"
#include "camera.h"
#include "display.h"
#include "math_util.h"
#include "object_helpers.h"
#include "mario_actions_cutscene.h"
#include "behavior_data.h"
#include "mario.h"
#include "surface_collision.h"
#include "obj_behaviors_2.h"
#include "audio/interface_2.h"
#include "level_update.h"
#include "memory.h"
#include "obj_behaviors.h"
#include "object_constants.h"
#include "interaction.h"
#include "save_file.h"
#include "platform_displacement.h"
#include "graph_node.h"
#include "object_list_processor.h"
#include "surface_load.h"
#include "spawn_sound.h"

extern u32 wiggler_seg5_anims_0500C874[];
extern u32 spiny_egg_seg5_anims_050157E4[];
extern f32 D_8033B328[];
extern struct ObjectNode *gObjectLists;
extern s16 gTTCSpeedSetting;
extern u8 ttc_seg7_arr_07016840[];
extern u8 ttc_seg7_arr_07016904[];
extern u8 jrb_seg7_trajectory_unagi_1[];
extern u8 jrb_seg7_trajectory_unagi_2[];
extern u8 dorrie_seg6_collision_0600FBB8[];
extern u8 dorrie_seg6_collision_0600F644[];
extern u8 ssl_seg7_collision_070284B0[];
extern u8 ssl_seg7_collision_07028274[];
extern u8 ssl_seg7_collision_07028370[];
extern u8 ssl_seg7_collision_070282F8[];
extern u8 ccm_seg7_trajectory_penguin_race[];
extern u8 bob_seg7_trajectory_koopa[];
extern u8 thi_seg7_trajectory_koopa[];
extern u8 rr_seg7_collision_07029038[];
extern u8 ccm_seg7_collision_070163F8[];
extern u8 D_0800D710[];
extern u8 bitfs_seg7_collision_070157E0[];
extern u8 rr_seg7_trajectory_0702EC3C[];
extern u8 rr_seg7_trajectory_0702ECC0[];
extern u8 ccm_seg7_trajectory_0701669C[];
extern u8 bitfs_seg7_trajectory_070159AC[];
extern u8 hmc_seg7_arr_702B86C[];
extern u8 lll_seg7_trajectory_0702856C[];
extern u8 lll_seg7_trajectory_07028660[];
extern u8 rr_seg7_trajectory_0702ED9C[];
extern u8 rr_seg7_trajectory_0702EEE0[];
extern u8 bitdw_seg7_collision_0700F70C[];
extern u8 bits_seg7_collision_0701ADD8[];
extern u8 bits_seg7_collision_0701AE5C[];
extern u8 bob_seg7_collision_bridge[];
extern u8 bitfs_seg7_collision_07015928[];
extern u8 rr_seg7_collision_07029750[];
extern u8 rr_seg7_collision_07029858[];
extern u8 vcutm_seg7_collision_0700AC44[];
extern u8 bits_seg7_collision_0701ACAC[];
extern u8 bits_seg7_collision_0701AC28[];
extern u8 bitdw_seg7_collision_0700F7F0[];
extern u8 bitdw_seg7_collision_0700F898[];
extern u8 ttc_seg7_collision_07014F70[];
extern u8 ttc_seg7_collision_07015008[];
extern u8 ttc_seg7_collision_070152B4[];
extern u8 ttc_seg7_collision_070153E0[];
extern u8 ttc_seg7_collision_07015584[];
extern u8 ttc_seg7_collision_07015650[];
extern u8 ttc_seg7_collision_07015754[];
extern u8 ttc_seg7_collision_070157D8[];
extern u8 bits_seg7_collision_0701A9A0[];
extern u8 bits_seg7_collision_0701AA0C[];
extern u8 bitfs_seg7_collision_07015714[];
extern u8 bitfs_seg7_collision_07015768[];
extern u8 rr_seg7_collision_070295F8[];
extern u8 rr_seg7_collision_0702967C[];
extern u8 bitdw_seg7_collision_0700F688[];
extern u8 bits_seg7_collision_0701AA84[];
extern u8 rr_seg7_collision_07029508[];
extern u8 bits_seg7_collision_0701B734[];
extern u8 bits_seg7_collision_0701B59C[];
extern u8 bits_seg7_collision_0701B404[];
extern u8 bits_seg7_collision_0701B26C[];
extern u8 bits_seg7_collision_0701B0D4[];
extern u8 bitdw_seg7_collision_0700FD9C[];
extern u8 bitdw_seg7_collision_0700FC7C[];
extern u8 bitdw_seg7_collision_0700FB5C[];
extern u8 bitdw_seg7_collision_0700FA3C[];
extern u8 bitdw_seg7_collision_0700F91C[];
extern u8 rr_seg7_collision_0702A6B4[];
extern u8 rr_seg7_collision_0702A32C[];
extern u8 rr_seg7_collision_07029FA4[];
extern u8 rr_seg7_collision_07029C1C[];
extern u8 rr_seg7_collision_07029924[];
extern u8 bits_seg7_collision_0701AD54[];
extern u8 bitfs_seg7_collision_070157E0[];
extern u8 bitfs_seg7_collision_07015124[];
extern u32 spiny_seg5_anims_05016EAC[];

#define TTC_SPEED_SLOW    0
#define TTC_SPEED_FAST    1
#define TTC_SPEED_RANDOM  2
#define TTC_SPEED_STOPPED 3


#define o gCurrentObject


void wiggler_jumped_on(void);
void goomba_soft_attacked(void);


struct KoopaTheQuickData
{
    /*0x00*/ s16 initText;
    /*0x02*/ s16 unk02;
    /*0x04*/ void *unk04;
    /*0x08*/ Vec3s starPos;
};

struct GoombaProperties
{
    f32 baseSpeed;
    s32 unk04;
    s16 drawDistance;
    s8 unk0A;
};

struct Struct80331910
{
    void *unk00;
    void *unk04;
    s16 unk08;
};

struct TTCPitBlockProps
{
    s16 speed;
    s16 waitTime;
};

struct Struct80331A54
{
    void *unk00;
    s16 unk04;
};

struct Struct80331B30
{
    s16 unk00;
    s16 unk02;
};

struct RacingPenguinData
{
    s16 text;
    f32 radius;
    f32 height;
};

struct Struct80331C00
{
    s16 unk00;
    s16 unk02;
};

struct Struct80331C38
{
    s16 unk00;
    s16 unk02;
};

struct Struct80331C48
{
    s16 unk00;
    s16 unk02;
    s16 unk04;
};

struct TripletButterflyActivationData
{
    s32 model;
    void *behavior;
    f32 scale;
};

struct Struct80331874
{
    s8 unk01;
    s8 unk03;
    s8 unk04;
    s8 unk05;
    s8 unk06;
    s8 unk0C;
    u8 filler00[0x14-0x00];
};


extern s16 D_8035FEEA;

extern f32 D_803600F8;
extern f32 D_803600FC;
extern f32 D_80360100;


struct ObjectHitbox D_80331730 =
{
    INTERACT_KOOPA,
    0,
    0,
    0,
    -1,
    60,
    40,
    40,
    30,
};

u8 D_80331740[] = { 2, 2, 3, 3, 2, 2 };
u8 D_80331748[] = { 4, 4, 4, 4, 4, 4 };

static struct KoopaTheQuickData sKoopaTheQuickData[] =
{
    { 5, 7, bob_seg7_trajectory_koopa, {3030, 4500, 60936} },
    { 9, 31, thi_seg7_trajectory_koopa, {7100, 64236, 59536} }
};

struct ObjectHitbox D_80331770 =
{
    INTERACT_BOUNCE_TOP,
    10,
    2,
    0,
    0,
    40,
    20,
    20,
    20,
};

u8 D_80331780[] = { 2, 2, 3, 3, 2, 2 };

struct ObjectHitbox D_80331788 =
{
    INTERACT_HIT_FROM_BELOW,
    0,
    1,
    0,
    1,
    100,
    80,
    70,
    70,
};

struct ObjectHitbox sFlyGuyHitbox =
{
    INTERACT_BOUNCE_TOP,
    0,
    2,
    0,
    2,
    70,
    60,
    40,
    50,
};

s16 D_803317A8[] = { 0x1000, 0xE000, 0x2000 };

struct ObjectHitbox sGoombaHitbox =
{
    INTERACT_BOUNCE_TOP,
    0,
    1,
    0,
    1,
    72,
    50,
    42,
    40,
};

struct GoombaProperties sGoombaProperties[] =
{
    { 1.5f, 0x5060B081, 4000, 1 },
    { 3.5f, 0x5061B081, 4000, 2 },
    { 0.5f, 0x5060B081, 1500, 0 },
};

u8 sGoombaAttackHandlers[][6] =
{
    { 2, 2, 3, 3, 2, 2 },
    { 7, 7, 3, 8, 7, 7 },
};

struct ObjectHitbox D_803317F0 =
{
    INTERACT_MR_BLIZZARD,
    0,
    3,
    1,
    0,
    80,
    160,
    80,
    160,
};

struct ObjectHitbox sWigglerBodyPartHitbox =
{
    INTERACT_BOUNCE_TOP,
    0,
    3,
    99,
    0,
    20,
    20,
    20,
    10,
};

struct ObjectHitbox sWigglerHitbox =
{
    INTERACT_BOUNCE_TOP,
    0,
    3,
    4,
    0,
    60,
    50,
    30,
    40,
};

u8 D_80331820[] = { 2, 2, 6, 6, 2, 2 };

f32 sWigglerSpeeds[] = { 2.0f, 40.0f, 30.0f, 16.0f };

// FILE: wiggler



s32 func_802F8680(void)
{
    if (o->header.gfx.node.flags & 0x0001)
        return TRUE;
    else
        return FALSE;
}

s16 func_802F86C0(void)
{
    return -atan2s(o->oForwardVel, o->oVelY);
}

s32 func_802F870C(s16 arg0)
{
    s32 val04 = CreateMessageBox(0x02, 0x11, 0xA3, arg0);
    if (val04 == 2)
    {
        func_802573C8(0);
        func_802A4CC0();
    }
    return val04;
}

void func_802F8770(f32 arg0)
{
    o->oPosX = o->oHomeX + arg0 * coss(o->oAngleYaw);
    o->oPosZ = o->oHomeZ + arg0 * sins(o->oAngleYaw);
}

s32 func_802F87E0(f32 arg0, s16 arg1)
{
    if (o->oDistanceToMario < arg0 &&
        abs_angle_diff(o->oAngleYaw, o->oAngleToMario) < arg1)
    {
        return TRUE;
    }
    return FALSE;
}

void func_802F8854(s32 arg0)
{
    switch (arg0)
    {
    case 0:
        D_803600F8 = o->oPosX;
        D_803600FC = o->oPosY;
        D_80360100 = o->oPosZ;
        break;

    case 1:
        o->oVelX = o->oPosX - D_803600F8;
        o->oVelY = o->oPosY - D_803600FC;
        o->oVelZ = o->oPosZ - D_80360100;
        break;

    case 2:
        o->oPosX = D_803600F8;
        o->oPosY = D_803600FC;
        o->oPosZ = D_80360100;
        break;
    }
}

void func_802F8978(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Object *trackBall;
    s16 *val28;
    s16 *val24;
    s16 *val20;
    UNUSED s32 unused;
    f32 val18;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 val08;

    if (arg0 == 0 || ((u16)(o->oBehParams >> 16) & 0x0080))
    {
        val28 = o->oPlatformOnTrackUnk100;
        val24 = val28;
        
        if (arg0 != 0)
        {
            val18 = 300.0f * arg0;
        }
        else
        {
            func_802F8854(0);
            o->oPlatformOnTrackUnk104 = 0;
            val18 = o->oForwardVel;
        }

        do
        {
            val20 = val24;
            val24 += 4;

            if (val24[0] == -1)
            {
                if (arg0 == 0)
                    o->oPlatformOnTrackUnk104 = -1;
                
                if (((u16)(o->oBehParams >> 16) & 0x0100))
                    val24 = o->oPlatformOnTrackUnkFC;
                else
                    return;
            }

            dx = val24[1] - arg1;
            dy = val24[2] - arg2;
            dz = val24[3] - arg3;
            
            val08 = sqrtf(dx*dx + dy*dy + dz*dz);
            
            val18 -= val08;
            arg1 += dx;
            arg2 += dy;
            arg3 += dz;
        }
        while (val18 > 0.0f);
            
        val08 = val18 / val08;
        arg1 += dx * val08;
        arg2 += dy * val08;
        arg3 += dz * val08;

        if (arg0 != 0)
        {
            trackBall = spawn_obj_adv(
                o->oUnk88 + arg0,
                0, 0, 0,
                o,
                225,
                beh_metal_balls_for_elevators);

            if (trackBall != NULL)
            {
                trackBall->oPosX = arg1;
                trackBall->oPosY = arg2;
                trackBall->oPosZ = arg3;
            }
        }
        else
        {
            if (val20 != val28)
            {
                if (o->oPlatformOnTrackUnk104 == 0)
                    o->oPlatformOnTrackUnk104 = val28[0];
                o->oPlatformOnTrackUnk100 = val20;
            }

            o->oPosX = arg1;
            o->oPosY = arg2;
            o->oPosZ = arg3;
            
            func_802F8854(1);

            o->oPlatformOnTrackPitch = atan2s(
                sqrtf(o->oVelX * o->oVelX + o->oVelZ * o->oVelZ), -o->oVelY);
            o->oPlatformOnTrackYaw = atan2s(o->oVelZ, o->oVelX);
        }
    }
}

void func_802F8D78(f32 arg0, f32 arg1)
{
    f32 val24;
    f32 val20;
    f32 val1C;
    f32 val18;
    f32 val14;
    f32 val10;
    f32 val0C;
    f32 val08;
    f32 val04;
    f32 val00;

    if (o->oForwardVel == 0.0f)
    {
        val24 = val20 = val1C = 0.0f;

        if (o->oMoveFlags & 0x00000080)
        {
            val20 = 50.0f;
        }
        else
        {
            if (o->oFaceAnglePitch < 0)
                val1C = -arg0;
            else if (o->oFaceAnglePitch > 0)
                val1C = arg0;

            if (o->oFaceAngleRoll < 0)
                val24 = -arg1;
            else if (o->oFaceAngleRoll > 0)
                val24 = arg1;
        }
        
        val18 = coss(o->oFaceAnglePitch);
        val14 = sins(o->oFaceAnglePitch);
        val08 = val1C * val18 + val20 * val14;
        val0C = val20 * val18 - val1C * val14;

        val18 = coss(o->oFaceAngleRoll);
        val14 = sins(o->oFaceAngleRoll);
        val04 = val24 * val18 + val0C * val14;
        val0C = val0C * val18 - val24 * val14;

        val18 = coss(o->oFaceAngleYaw);
        val14 = sins(o->oFaceAngleYaw);
        val10 = val04 * val18 - val08 * val14;
        val08 = val08 * val18 + val04 * val14;

        val04 = val24 * val18 - val1C * val14;
        val00 = val1C * val18 + val24 * val14;

        o->oPosX = o->oHomeX - val04 + val10;
        o->oGraphYOffset = val20 - val0C;
        o->oPosZ = o->oHomeZ + val00 - val08;
    }
}

void func_802F90A8(s16 arg0, s16 arg1)
{
    if (o->oMoveFlags & 0x00000200)
        arg0 = func_802A2AC0();
    func_8029DE70(arg0, arg1);
}

s16 func_802F9100(f32 arg0)
{
    return atan2s(arg0, o->oPosY - o->oHomeY);
}

void func_802F9148(f32 arg0)
{
    o->oForwardVel = arg0 * coss(o->oAnglePitch);
    o->oVelY = arg0 * -sins(o->oAnglePitch);
}

s32 func_802F91AC(s16 *arg0, s16 arg1, s16 arg2)
{
    if (*arg0 <= arg1)
    {
        *arg0 = arg1;
    }
    else if (*arg0 >= arg2)
    {
        *arg0 = arg2;
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

static s32 cap_f32(f32 *value, f32 minimum, f32 maximum)
{
    if (*value <= minimum)
    {
        *value = minimum;
    }
    else if (*value >= maximum)
    {
        *value = maximum;
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

void func_802F927C(s32 arg0)
{
    func_8029ED38(arg0);
    func_8029F728();
}

s32 func_802F92B0(s32 arg0)
{
    func_8029ED38(arg0);
    return func_8029F788();
}

s32 func_802F92EC(s32 arg0, s32 arg1)
{
    func_8029ED38(arg0);
    return check_anim_frame(arg1);
}

s32 func_802F932C(s32 arg0)
{
    if (func_8029F828())
    {
        func_8029ED38(arg0);
        return TRUE;
    }
    return FALSE;
}

s32 func_802F9378(s8 arg0, s8 arg1, u32 arg2)
{
    s32 val04;

    if ((val04 = o->header.gfx.unk38.animAccel / 0x10000) <= 0)
        val04 = 1;

    if (func_8029F8D4(arg0, val04) || func_8029F8D4(arg1, val04))
    {
        PlaySound2(arg2);
        return TRUE;
    }

    return FALSE;
}

s16 func_802F9414(f32 arg0, s16 arg1)
{
    s16 val06;

    o->oPosY -= arg0;
    val06 = UnknownMove(o, gMarioObject, 15, arg1);
    o->oPosY += arg0;

    return val06;
}

s32 approach_f32_2(f32 *px, f32 target, f32 delta)
{
    if (*px > target)
        delta = -delta;

    *px += delta;

    if ((*px - target) * delta >= 0)
    {
        *px = target;
        return TRUE;
    }
    return FALSE;
}

s32 forward_vel_approach(f32 target, f32 delta)
{
    return approach_f32_2(&o->oForwardVel, target, delta);
}

s32 y_vel_approach(f32 target, f32 delta)
{
    return approach_f32_2(&o->oVelY, target, delta);
}

s32 func_802F95B0(s16 target, s16 delta)
{
    o->oAnglePitch = approach_target_angle(o->oAnglePitch, target, delta);

    if ((s16)o->oAnglePitch == target)
        return TRUE;
    
    return FALSE;
}

s32 face_pitch_approach(s16 targetPitch, s16 deltaPitch)
{
    o->oFaceAnglePitch =
        approach_target_angle(o->oFaceAnglePitch, targetPitch, deltaPitch);

    if ((s16)o->oFaceAnglePitch == targetPitch)
        return TRUE;

    return FALSE;
}

s32 face_yaw_approach(s16 targetYaw, s16 deltaYaw)
{
    o->oFaceAngleYaw =
        approach_target_angle(o->oFaceAngleYaw, targetYaw, deltaYaw);

    if ((s16)o->oFaceAngleYaw == targetYaw)
        return TRUE;

    return FALSE;
}

s32 face_roll_approach(s16 targetRoll, s16 deltaRoll)
{
    o->oFaceAngleRoll =
        approach_target_angle(o->oFaceAngleRoll, targetRoll, deltaRoll);

    if ((s16)o->oFaceAngleRoll == targetRoll)
        return TRUE;

    return FALSE;
}

s32 func_802F9780(s16 *arg0, s32 *arg1, s16 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6)
{
    s16 val06;
    s16 val04 = (s16)(*arg1);

    *arg0 = approach_target_angle(*arg0, (arg2 - val04) * arg3, arg4);
    val06 = func_802A2ECC(*arg0);

    func_802F91AC(&val06, arg5, arg6);
    *arg1 = approach_target_angle(*arg1, arg2, val06);

    return (s16)(*arg1) == arg2;
}

void func_802F9850(s16 arg0, s16 arg1, s16 arg2)
{
    s16 val06 = o->oAngleYaw - arg0;
    func_802F91AC(&val06, -arg1, arg1);
    face_roll_approach(val06, arg2);
}

s16 random_linear_offset(s16 base, s16 range)
{
    return base + (s16)(range * RandomFloat());
}

s16 random_mod_offset(s16 base, s16 step, s16 mod)
{
    return base + step * (RandomU16() % mod);
}

s16 random_fixed_turn(s16 delta)
{
    return o->oAngleYaw + (s16)RandomSign() * delta;
}

/**
 * Begin by increasing the object's scale by *scaleVel, and slowly decreasing
 * scaleVel. Once the object starts to shrink, wait a bit, and then begin to
 * scale the object toward endScale. The first time it reaches below
 * shootFireScale during this time, return 1.
 * Return -1 once it's reached endScale.
 */
s32 grow_then_shrink(f32 *scaleVel, f32 shootFireScale, f32 endScale)
{
    if (o->oTimer < 2)
    {
        o->header.gfx.scale[0] += *scaleVel;

        if ((*scaleVel -= 0.01f) > -0.03f)
            o->oTimer = 0;
    }
    else if (o->oTimer > 10)
    {
        if (approach_f32_2(&o->header.gfx.scale[0], endScale, 0.05f))
        {
            return -1;
        }
        else if (*scaleVel != 0.0f && o->header.gfx.scale[0] < shootFireScale)
        {
            *scaleVel = 0.0f;
            return 1;
        }
    }

    return 0;
}

s32 func_802F9B68(s32 *arg0, f32 *arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    s32 val04 = *arg0;

    *arg0 += (s32)*arg1;
    if (*arg0 == arg2 || ((*arg0 - arg2) * (val04 - arg2) < 0 && *arg1 > -arg3 && *arg1 < arg3))
    {
        *arg0 = arg2;
        *arg1 = 0.0f;
        return TRUE;
    }
    else
    {
        if (*arg0 >= arg2)
            arg4 = -arg4;
        if (*arg1 * arg4 < 0.0f)
            arg4 *= arg5;

        *arg1 += arg4;
    }
    
    return FALSE;
}

static void update_blinking(
    s32 *blinkTimer, s16 baseCycleLength, s16 cycleLengthRange, s16 blinkLength)
{
    if (*blinkTimer != 0)
        *blinkTimer -= 1;
    else
        *blinkTimer = random_linear_offset(baseCycleLength, cycleLengthRange);

    if (*blinkTimer > blinkLength)
        o->oAnimState = 0;
    else
        o->oAnimState = 1;
}

s32 resolve_obj_collisions(s32 *arg0)
{
    struct Object *otherObject;
    f32 dx;
    f32 dz;
    s16 angle;
    f32 radius;
    f32 otherRadius;
    f32 relativeRadius;
    f32 newCenterX;
    f32 newCenterZ;

    if (o->numCollidedObjs != 0)
    {
        otherObject = o->collidedObjs[0];
        if (otherObject != gMarioObject)
        {
            //! If one object moves after collisions are detected and this code
            // runs, the objects can move toward each other (transport cloning).

            dx = otherObject->oPosX - o->oPosX;
            dz = otherObject->oPosZ - o->oPosZ;
            angle = atan2s(dx, dz); //! Shouldn't this be atan2s(dz, dx)?

            radius = o->hitboxRadius;
            otherRadius = otherObject->hitboxRadius;
            relativeRadius = radius / (radius + otherRadius);

            newCenterX = o->oPosX + dx * relativeRadius;
            newCenterZ = o->oPosZ + dz * relativeRadius;

            o->oPosX = newCenterX - radius * coss(angle);
            o->oPosZ = newCenterZ - radius * sins(angle);

            otherObject->oPosX = newCenterX + otherRadius * coss(angle);
            otherObject->oPosZ = newCenterZ + otherRadius * sins(angle);
            
            if (arg0 != NULL && abs_angle_diff(o->oAngleYaw, angle) < 0x4000)
            {
                *arg0 = (s16)(angle - o->oAngleYaw + angle + 0x8000);
                return TRUE;
            }
        }
    }

    return FALSE;
}

s32 func_802F9F6C(s32 *arg0)
{
    if (o->oMoveFlags & 0x00000200)
    {
        *arg0 = func_802A2AC0();
    }
    else if (o->oMoveFlags & 0x00000400)
    {
        *arg0 = (s16)(o->oAngleYaw + 0x8000);
    }
    else if (!resolve_obj_collisions(arg0))
    {
        return FALSE;
    }

    return TRUE;
}

s32 resolve_collisions_and_turn(s16 targetYaw, s16 deltaYaw)
{
    resolve_obj_collisions(NULL);
    
    if (func_8029DE70(targetYaw, deltaYaw))
        return FALSE;
    else
        return TRUE;
}

void func_802FA078(void)
{
    if (o->oUnk184 <= 0)
    {
        if (o->oUnk1C4 == 0)
            func_802A3034(0x502C8081);
        else if (o->oUnk1C4 > 0)
            func_802A3034(o->oUnk1C4);
        else
            func_802A3004();

        if (o->oUnk198 < 0)
            SpawnObj(o, 0x0076, beh_mr_i_blue_coin);
        else
            func_802A1410(o, o->oUnk198, 20.0f);

        func_802A1410(o, o->oUnk198, 20.0f);

        if (o->oUnk184 < 0)
        {
            UnHideObject();
            func_8029FE38();
        }
        else
        {
            DeactivateObject(o);
        }
    }
}

void Unknown802FA1A4(void)
{
    o->oUnk184 = 0;
    func_802FA078();
}

void func_802FA1D8(s32 arg0)
{
    switch (arg0)
    {
    case 2:
    case 5:
        o->oAction = 101;
        o->oForwardVel = 20.0f;
        o->oVelY = 50.0f;
        break;

    default:
        o->oAction = 100;
        o->oForwardVel = 50.0f;
        o->oVelY = 30.0f;
        break;
    }

    o->oFlags &= ~0x00000008;
    o->oAngleYaw = func_8029DF18(gMarioObject, o);
}

void func_802FA2F0(void)
{
    PlaySound2(0x50308081);
    o->oAction = 102;
}

s32 func_802FA32C(void)
{
    if (o->oMoveFlags & 0x00000040)
    {
        if (o->oGravity + o->oBuoyancy > 0.0f ||
            find_water_level(o->oPosX, o->oPosZ) - o->oPosY < 150.0f)
        {
            return FALSE;
        }
    }
    else if (!(o->oMoveFlags & 0x00000800))
    {
        if (o->oMoveFlags & 0x00000008)
        {
            if (o->oUnk128 < 200.0f)
                PlaySound2(0x50324081);
            else
                PlaySound2(0x5029A081);
        }
        return FALSE;
    }

    func_802FA078();
    return TRUE;
}

s32 func_802FA468(struct ObjectHitbox *hitbox, s32 arg1, u8 *attackHandlers)
{
    s32 attackType;

    func_802A2CFC(o, hitbox);

    if (func_802FA32C())
    {
        return 1;
    }
    else if (o->oInteractStatus & 0x00008000)
    {
        if (o->oInteractStatus & 0x00002000)
        {
            if (o->oAction != arg1)
            {
                o->oAction = arg1;
                o->oTimer = 0;
            }
        }
        else
        {
            attackType = o->oInteractStatus & 0x000000FF;

            switch (attackHandlers[attackType - 1])
            {
            case 0:
                break;

            case 1:
                func_802FA078();
                break;

            case 2:
                func_802FA1D8(attackType);
                break;

            case 3:
                func_802FA2F0();
                break;

            case 4:
                func_802FB364(attackType);
                break;

            case 5:
                obj_set_speed_to_zero();
                break;

            case 6:
                wiggler_jumped_on();
                break;

            case 7:
                goomba_soft_attacked();
                break;

            case 8:
                o->oUnk198 = -1;
                func_802FA2F0();
                break;
            }

            o->oInteractStatus = 0;
            return attackType;
        }
    }

    o->oInteractStatus = 0;
    return 0;
}

void func_802FA638(UNUSED f32 arg0)
{
    MoveRelated();

    if (o->header.gfx.unk38.curAnim != NULL)
    {
        func_8029F728();
    }

    if ((o->oMoveFlags & 0x00000A7B) || (o->oAction == 101 && o->oTimer >= 9))
    {
        func_802FA078();
    }

    MoveObj(-78);
}

void func_802FA6C8(f32 arg0)
{
    f32 val04 = arg0 * 0.3f;

    MoveRelated();
    
    if (o->header.gfx.unk38.curAnim != NULL)
        func_8029F728();

    if (approach_f32_2(&o->header.gfx.scale[1], val04, arg0 * 0.14f))
    {
        o->header.gfx.scale[0] = o->header.gfx.scale[2] =
            arg0 * 2.0f - o->header.gfx.scale[1];

        if (o->oTimer >= 16)
            func_802FA078();
    }

    o->oForwardVel = 0.0f;
    MoveObj(-78);
}

s32 func_802FA7CC(f32 arg0)
{
    if (o->oAction < 100)
    {
        return 1;
    }
    else
    {
        func_8029FE38();

        switch (o->oAction)
        {
        case 100:
        case 101: func_802FA638(arg0); break;
        case 102: func_802FA6C8(arg0); break;
        }

        return 0;
    }
}

s32 func_802FA888(struct ObjectHitbox *arg0, s32 arg1)
{
    s32 attackType;

    func_802A2CFC(o, arg0);

    if (func_802FA32C())
    {
        return 1;
    }
    else if (o->oInteractStatus & 0x00008000)
    {
        if (o->oInteractStatus & 0x00002000)
        {
            if (o->oAction != arg1)
            {
                o->oAction = arg1;
                o->oTimer = 0;
            }
        }
        else
        {
            attackType = o->oInteractStatus & 0x000000FF;
            func_802FA078();
            o->oInteractStatus = 0;
            return attackType;
        }
    }

    o->oInteractStatus = 0;
    return 0;
}

s32 func_802FA990(s32 arg0)
{
    MoveRelated();
    func_8029F728();

    if (o->oTimer > 30)
    {
        o->oAction = arg0;
        return TRUE;
    }

    MoveObj(-78);
    return FALSE;
}

/**
 * If we are far from home (> threshold away), then set oAngleToMario to the
 * angle to home. Then set oDistanceToMario to one of:
 *  - 25000, if we are far from home
 *  - 20000, if we are close to home, but Mario is far from us (> threshold away)
 *  - original value, if we are close to home and Mario is close to us
 */
void treat_far_home_as_mario(f32 threshold)
{
    f32 dx = o->oHomeX - o->oPosX;
    f32 dy = o->oHomeY - o->oPosY;
    f32 dz = o->oHomeZ - o->oPosZ;
    f32 distance = sqrtf(dx*dx + dy*dy + dz*dz);

    if (distance > threshold)
    {
        o->oAngleToMario = atan2s(dz, dx);
        o->oDistanceToMario = 25000.0f;
    }
    else
    {
        dx = o->oHomeX - gMarioObject->oPosX;
        dy = o->oHomeY - gMarioObject->oPosY;
        dz = o->oHomeZ - gMarioObject->oPosZ;
        distance = sqrtf(dx*dx + dy*dy + dz*dz);

        if (distance > threshold)
            o->oDistanceToMario = 20000.0f;
    }
}

// TODO: Finish
#include "behaviors/koopa.c.inc"
// TODO: Finish
#include "behaviors/pokey.c.inc"
#include "behaviors/swoop.c.inc"
#include "behaviors/fly_guy.c.inc"
#include "behaviors/goomba.c.inc"
// TODO: Finish
#include "behaviors/chain_chomp.c.inc"
// TODO: Finish
#include "behaviors/wiggler.c.inc"




struct ObjectHitbox D_80331844 =
{
    INTERACT_MR_BLIZZARD,
    0,
    2,
    0,
    0,
    80,
    50,
    40,
    40,
};

u8 D_80331854[] = { 2, 2, 0, 0, 2, 2 };

struct ObjectHitbox D_8033185C =
{
    INTERACT_HIT_FROM_BELOW,
    0,
    2,
    0,
    5,
    50,
    50,
    40,
    50,
};

s8 D_8033186C[] = { 11, 8, 12, 8, 9, 9 };

struct Struct802A2B04 D_80331874 =
{
    0,
    3,
    159,
    0,
    4,
    4,
    10,
    15,
    0xFC,
    0,
    10.0f,
    7.0f,
};

struct ObjectHitbox D_80331888 =
{
    INTERACT_BOUNCE_TOP,
    0,
    2,
    -1,
    0,
    70,
    50,
    30,
    40,
};

struct ObjectHitbox D_80331898 =
{
    INTERACT_MR_BLIZZARD,
    15,
    1,
    99,
    0,
    30,
    15,
    30,
    15,
};

struct Struct802A2B04 D_803318A8 =
{
    0,
    2,
    161,
    10,
    4,
    4,
    10,
    15,
    0xFC,
    0,
    8.0f,
    4.0f,
};

void *sPlatformOnTrackCollisionModels[] =
{
    rr_seg7_collision_07029038,
    ccm_seg7_collision_070163F8,
    D_0800D710,
    bitfs_seg7_collision_070157E0,
};

void *D_803318CC[] =
{
    rr_seg7_trajectory_0702EC3C,
    rr_seg7_trajectory_0702ECC0,
    ccm_seg7_trajectory_0701669C,
    bitfs_seg7_trajectory_070159AC,
    hmc_seg7_arr_702B86C,
    lll_seg7_trajectory_0702856C,
    lll_seg7_trajectory_07028660,
    rr_seg7_trajectory_0702ED9C,
    rr_seg7_trajectory_0702EEE0,
};

void *D_803318F0[] =
{
    bitdw_seg7_collision_0700F70C,
    bits_seg7_collision_0701ADD8,
    bits_seg7_collision_0701AE5C,
    bob_seg7_collision_bridge,
    bitfs_seg7_collision_07015928,
    rr_seg7_collision_07029750,
    rr_seg7_collision_07029858,
    vcutm_seg7_collision_0700AC44,
};

struct Struct80331910 D_80331910[] =
{
    { bits_seg7_collision_0701ACAC, bits_seg7_collision_0701AC28, 60 },
    { bitdw_seg7_collision_0700F7F0, bitdw_seg7_collision_0700F898, 58 },
};

struct ObjectHitbox D_80331928 =
{
    INTERACT_MR_BLIZZARD,
    25,
    1,
    99,
    0,
    80,
    50,
    60,
    50,
};

struct Struct802A2B04 D_80331938 =
{
    0,
    5,
    168,
    20,
    20,
    60,
    10,
    10,
    0xFE,
    0,
    35.0f,
    10.0f,
};

struct Struct802A2B04 D_8033194C =
{
    0,
    1,
    168,
    236,
    20,
    5,
    0,
    0,
    0xFE,
    0,
    20.0f,
    5.0f,
};

void *sTTCRotatingSolidCollisionModels[] =
{
    ttc_seg7_collision_07014F70,
    ttc_seg7_collision_07015008,
};

u8 sTTCRotatingSolidRotationTimes[] = { 120, 40, 0, 0 };

f32 sTTCPendulumAngleAccels[] = { 13.0f, 22.0f, 13.0f, 0.0f };

void *D_8033197C[] =
{
    ttc_seg7_collision_070152B4,
    ttc_seg7_collision_070153E0,
};

s16 sTTCTreadmillSpeeds[] = { 50, 100, 0, 0 };

s16 sTTCMovingBarWaitTimes[] = { 55, 30, 55, 0 };

s8 sTTCMovingBarRandomWaitTimes[] = { 1, 12, 55, 100 };

void *sTTCCogCollisionModels[] =
{
    ttc_seg7_collision_07015584,
    ttc_seg7_collision_07015650,
};

s8 sTTCCogDirections[] = { 1, -1, 0, 0 };

s16 sTTCCogNormalSpeeds[] = { 200, 400 };

void *D_803319A8[] =
{
    ttc_seg7_collision_07015754,
    ttc_seg7_collision_070157D8,
};

struct TTCPitBlockProps sTTCPitBlockProps[][2] =
{
    {{ 11, 20 }, { -9, 30 }},
    {{ 18, 15 }, { -11, 15 }},
    {{ 11, 20 }, { -9, -1 }},
    {{ 0, 0 }, {0, 0}},
};

s8 sTTCElevatorSpeeds[] = { 6, 10, 6, 0 };

s16 D_803319D4[] = { -0x444, -0xCCC };

s16 D_803319D8[][4] =
{
    { 40, 10, 10, 0 },
    { 20, 5, 5, 0 },
};

s16 sTTCSpinnerSpeeds[] = { 200, 600, 200, 0 };

struct ObjectHitbox D_803319F0 =
{
    INTERACT_MR_BLIZZARD,
    24,
    2,
    99,
    3,
    65,
    170,
    65,
    170,
};

struct Struct802A2B04 D_80331A00 =
{
    0,
    6,
    160,
    0,
    5,
    5,
    10,
    10,
    0xFD,
    0,
    3.0f,
    5.0f,
};

struct ObjectHitbox D_80331A14 =
{
    INTERACT_MR_BLIZZARD,
    12,
    1,
    99,
    0,
    30,
    30,
    25,
    25,
};

void *D_80331A24[] =
{
    bits_seg7_collision_0701A9A0,
    bits_seg7_collision_0701AA0C,
    bitfs_seg7_collision_07015714,
    bitfs_seg7_collision_07015768,
    rr_seg7_collision_070295F8,
    rr_seg7_collision_0702967C,
    NULL,
    bitdw_seg7_collision_0700F688,
};

void *D_80331A44[] =
{
    bits_seg7_collision_0701AA84,
    rr_seg7_collision_07029508,
};

s16 D_80331A4C[] = { 300, -300, 600, -600 };

struct Struct80331A54 D_80331A54[][5] =
{
    {
        { bits_seg7_collision_0701B734, 0x0045 },
        { bits_seg7_collision_0701B59C, 0x0044 },
        { bits_seg7_collision_0701B404, 0x0043 },
        { bits_seg7_collision_0701B26C, 0x0042 },
        { bits_seg7_collision_0701B0D4, 0x0041 },
    },
    {
        { bitdw_seg7_collision_0700FD9C, 0x003F },
        { bitdw_seg7_collision_0700FC7C, 0x003E },
        { bitdw_seg7_collision_0700FB5C, 0x003D },
        { bitdw_seg7_collision_0700FA3C, 0x003C },
        { bitdw_seg7_collision_0700F91C, 0x003B },
    },
    {
        { rr_seg7_collision_0702A6B4, 0x0045 },
        { rr_seg7_collision_0702A32C, 0x0044 },
        { rr_seg7_collision_07029FA4, 0x0043 },
        { rr_seg7_collision_07029C1C, 0x0042 },
        { rr_seg7_collision_07029924, 0x0041 },
    },
};

s16 D_80331ACC[] = { 250, 200, 200 };

void *D_80331AD4[] =
{
    bits_seg7_collision_0701AD54,
    bitfs_seg7_collision_070157E0,
    bitfs_seg7_collision_07015124,
};

struct ObjectHitbox D_80331AE0 =
{
    0,
    0,
    0,
    0,
    0,
    50,
    50,
    50,
    50,
};

struct ObjectHitbox D_80331AF0 =
{
    INTERACT_CLAM_OR_BUBBA,
    50,
    3,
    99,
    0,
    150,
    150,
    150,
    150,
};

struct ObjectHitbox D_80331B00 =
{
    INTERACT_MR_BLIZZARD,
    0,
    2,
    0,
    0,
    50,
    50,
    50,
    50,
};

static struct ObjectHitbox sMadPianoHitbox =
{
    INTERACT_MR_BLIZZARD,
    0,
    3,
    99,
    0,
    200,
    150,
    200,
    150,
};

struct ObjectHitbox D_80331B20 =
{
    INTERACT_HIT_FROM_BELOW,
    0,
    2,
    0,
    -1,
    60,
    30,
    40,
    30,
};

struct Struct80331B30 D_80331B30[] =
{
    { 52, 150 },
    { 135, 3 },
    { -75, 78 },
};

struct ObjectHitbox D_80331B3C =
{
    INTERACT_BREAKABLE,
    0,
    0,
    99,
    0,
    20,
    30,
    20,
    30,
};

struct ObjectHitbox sFirePiranhaPlantHitbox =
{
    INTERACT_BOUNCE_TOP,
    0,
    2,
    0,
    1,
    80,
    160,
    50,
    150,
};

f32 D_80331B5C[] =
{
    0.5f,
    2.0f,
};

struct ObjectHitbox D_80331B64 =
{
    INTERACT_FLAME,
    10,
    0,
    0,
    0,
    10,
    20,
    10,
    20,
};

struct ObjectHitbox D_80331B74 =
{
    INTERACT_HIT_FROM_BELOW,
    0,
    2,
    0,
    2,
    100,
    60,
    70,
    50,
};

struct ObjectHitbox D_80331B84 =
{
    INTERACT_SNUFIT_BULLET,
    50,
    1,
    0,
    0,
    100,
    50,
    100,
    50,
};

struct ObjectHitbox D_80331B94 =
{
    INTERACT_BOUNCE_TOP,
    0,
    0,
    4,
    0,
    150,
    100,
    1,
    1,
};

s8 D_80331BA4[] = { 0, 1, 3, 2, 1, 0 };

static struct ObjectHitbox sKleptoHitbox =
{
    INTERACT_HIT_FROM_BELOW,
    0,
    0,
    1,
    0,
    160,
    250,
    80,
    200,
};

static Vec3f sKleptoTargetPositions[] =
{
    { 2200.0f, 1250.0f, -2820.0f },
    { -6200.0f, 1250.0f, -2800.0f },
    { -6200.0f, 1250.0f, 1150.0f },
};

static u8 sKleptoAttackHandlers[] = { 2, 2, 5, 5, 2, 2 };

static struct RacingPenguinData sRacingPenguinData[] =
{
    { 55, 200.0f, 200.0f },
    { 164, 350.0f, 250.0f },
};

struct Struct80331C00 D_80331C00[] =
{
    { 0x019C, 0xFF6A },
    { 0x02FA, 0xFF6A },
    { 0x0458, 0xFF6A },
    { 0x019C, 0x0096 },
    { 0x02FA, 0x0096 },
    { 0x0458, 0x0096 },
};

struct ObjectHitbox D_80331C18 =
{
    INTERACT_CLAM_OR_BUBBA,
    0,
    2,
    99,
    0,
    150,
    80,
    150,
    80,
};

struct ObjectHitbox D_80331C28 =
{
    INTERACT_BOUNCE_TOP,
    20,
    2,
    0,
    3,
    180,
    100,
    150,
    90,
};

struct Struct80331C38 D_80331C38[] =
{
    { 0xFF7E, 0xFF42 },
    { 0x0082, 0xFF42 },
    { 0xFF4C, 0x0082 },
    { 0x00B4, 0x0082 },
};

static Vec3s sDonutPlatformPositions[] =
{
    { 0x0B4C, 0xF7D7, 0x19A4 },
    { 0xF794, 0x08A3, 0xFFA9 },
    { 0x069C, 0x09D8, 0xFFE0 },
    { 0x05CF, 0x09D8, 0xFFE0 },
    { 0x0502, 0x09D8, 0xFFE0 },
    { 0x054C, 0xF7D7, 0x19A4 },
    { 0x0A7F, 0xF7D7, 0x19A4 },
    { 0x09B2, 0xF7D7, 0x19A4 },
    { 0x06E6, 0xF7D7, 0x19A4 },
    { 0x0619, 0xF7D7, 0x19A4 },
    { 0xEFB5, 0xF7D7, 0x19A4 },
    { 0x00E6, 0xF7D7, 0x19A4 },
    { 0x0019, 0xF7D7, 0x19A4 },
    { 0xFF4D, 0xF7D7, 0x19A4 },
    { 0xF081, 0xF7D7, 0x19A4 },
    { 0xE34F, 0xF671, 0x197A },
    { 0xEEE8, 0xF7D7, 0x19A4 },
    { 0xE74F, 0xF7D7, 0x197A },
    { 0xE683, 0xF7D7, 0x197A },
    { 0xE5B6, 0xF7D7, 0x197A },
    { 0xEE83, 0xF4A4, 0x19A4 },
    { 0xE41C, 0xF671, 0x197A },
    { 0xE4E9, 0xF671, 0x197A },
    { 0xECE9, 0xF4A4, 0x19A4 },
    { 0xEDB6, 0xF4A4, 0x19A4 },
    { 0xFC3F, 0x0A66, 0xFF45 },
    { 0x00EF, 0x04CD, 0xFF53 },
    { 0x0022, 0x04CD, 0xFF53 },
    { 0xFF57, 0x04CD, 0xFF53 },
    { 0xFB73, 0x0A66, 0xFF45 },
    { 0xFD0C, 0x0A66, 0xFF45 },
};

static struct ObjectHitbox sTripletButterflyExplodeHitbox =
{
    INTERACT_MR_BLIZZARD,
    50,
    2,
    1,
    0,
    100,
    50,
    100,
    50,
};

static struct TripletButterflyActivationData sTripletButterflyActivationData[] =
{
    { 0xB4, NULL, 0.5f },
    { 0xD4, beh_1up_walking, 1.0f },
};

struct ObjectHitbox D_80331D2C =
{
    INTERACT_CLAM_OR_BUBBA,
    0,
    1,
    99,
    0,
    300,
    200,
    300,
    200,
};


extern struct Object *D_80360104;
extern s32 D_80360108;
extern f32 D_8036010C;
extern f32 D_80360110;
extern f32 D_80360114;
extern struct Object *sMasterTreadmill;
extern s32 sNumActiveFirePiranhaPlants;
extern s32 sNumKilledFirePiranhaPlants;



#include "behaviors/spiny.c.inc"


void func_80301908(void)
{
    if (o->oDistanceToMario < 2000.0f)
    {
        func_8029E880(1, 0, 0, 0, 2.0f, o, 0x8E, beh_fwoosh_blowing_wind);
        func_8029EF18();
        o->oAction = 1;
    }
}

void func_803019A4(f32 arg0)
{
    f32 val04;

    if (o->oVelY < 0.0f)
    {
        val04 = -3.0f;
    }
    else
    {
        val04 = 3.0f;
    }

    if (o->oPosY < gMarioObject->oPosY + arg0 + val04)
    {
        y_vel_approach(4.0f, 0.4f);
    }
    else
    {
        y_vel_approach(-4.0f, 0.4f);
    }
}

void func_80301A70(void)
{
    f32 val0C;
    s16 val0A;

    f32 val04 = o->oDistanceToMario;
    if (val04 > 500.0f)
    {
        val04 = 500.0f;
    }

    if ((val0C = 1.2f * gMarioStates[0].forwardVel) < 8.0f)
    {
        val0C = 8.0f;
    }

    o->oForwardVel = val04 * 0.04f;
    cap_f32(&o->oForwardVel, val0C, 40.0f);
    func_803019A4(300.0f);

    if (o->oEvilLakituUnk100 != 0)
    {
        o->oEvilLakituUnk100 -= 1;
    }
    else
    {
        face_yaw_approach(o->oAngleToMario, 0x600);
    }

    val0A = (s16)(val04 * 2.0f);
    func_802F91AC(&val0A, 200, 4000);
    func_8029DE70(o->oAngleToMario, val0A);
}

void func_80301BD4(void)
{
    struct Object *val04;

    func_8029ED38(1);

    if (o->oEvilLakituUnkFC != 0)
    {
        o->oEvilLakituUnkFC -= 1;
    }
    else if (o->oEvilLakituNumSpinies < 3 &&
        o->oDistanceToMario < 800.0f &&
        abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) < 0x4000)
    {
        val04 = SpawnObj(o, 0x55, bSpiny);
        if (val04 != NULL)
        {
            o->prevObj = val04;
            val04->oAction = SPINY_ACT_HELD_BY_LAKITU;
            func_8029EE20(val04, spiny_egg_seg5_anims_050157E4, 0);
            o->oEvilLakituNumSpinies += 1;
            o->oUnk150 = 1;
            o->oEvilLakituUnkFC = 30;
        }
    }
}

void func_80301D00(void)
{
    func_802F927C(3);

    if (o->oEvilLakituUnkFC != 0)
    {
        o->oEvilLakituUnkFC -= 1;
    }
    else if (o->oDistanceToMario > o->oDrawingDistance - 100.0f ||
        (o->oDistanceToMario < 500.0f &&
            abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) < 0x2000))
    {
        o->oUnk150 = 2;
        o->oEvilLakituUnk100 = 20;
    }
}

void func_80301DD4(void)
{
    if (func_802F92EC(2, 2))
    {
        PlaySound2(0x50222081);
        o->prevObj = NULL;
    }

    if (func_8029F788())
    {
        o->oUnk150 = 0;
        o->oEvilLakituUnkFC = random_linear_offset(100, 100);
    }
}

void func_80301E54(void)
{
    PlaySound(0x60028001);
    MoveRelated();

    func_80301A70();
    if (o->oMoveFlags & 0x00000200)
    {
        o->oAngleYaw = func_802A2AC0();
    }

    update_blinking(&o->oEvilLakituBlinkTimer, 20, 40, 4);

    switch (o->oUnk150)
    {
    case 0: func_80301BD4(); break;
    case 1: func_80301D00(); break;
    case 2: func_80301DD4(); break;
    }

    MoveObj(78);
    if (func_802FA888(&D_8033185C, o->oAction))
    {
        o->prevObj = NULL;
    }
}

void BehEvilLakituLoop(void)
{
    treat_far_home_as_mario(2000.0f);

    switch (o->oAction)
    {
    case 0: func_80301908(); break;
    case 1: func_80301E54(); break;
    }
}

void func_80301FF8(void)
{
    struct Object *val04;
    s32 val00;

    for (val00 = 0; val00 < 5; val00++)
    {
        val04 = spawn_obj_adv(val00, 0, 0, 0, o, 0x8E, beh_fwoosh_face);
        if (val04 != NULL)
        {
            func_802A1230(val04);
        }
    }

    if (o->oBehParams2ndByte == 0)
    {
        spawn_obj_adv(5, 0, 0, 0, o, 0x57, beh_fwoosh_face);
        ScaleObject(3.0f);

        o->oFwooshSpawnerUnkF4 = o->oPosX;
        o->oFwooshSpawnerUnkF8 = o->oPosY;
    }

    o->oAction = 1;
}

void func_80302104(void)
{
    if (o->oDistanceToMario < 2000.0f)
    {
        func_8029EF18();
        o->oAction = 0;
    }
}

void func_8030215C(void)
{
    if (o->oDistanceToMario > 2500.0f)
    {
        o->oAction = 2;
    }
    else
    {
        if (o->oFwooshSpawnerUnkFC != 0)
        {
            o->header.gfx.scale[0] += o->oFwooshSpawnerUnk100;
            
            if ((o->oFwooshSpawnerUnk100 -= 0.005f) < -0.16f)
            {
                o->oFwooshSpawnerUnkFC = o->oTimer = 0;
            }
            else if (o->oFwooshSpawnerUnk100 < -0.1f)
            {
                PlaySound(0x60044001);
                func_802C76E0(12, 3.0f, 0.0f, -50.0f, 120.0f);
            }
            else
            {
                PlaySound(0x40050001);
            }
        }
        else
        {
            approach_f32_2(&o->header.gfx.scale[0], 3.0f, 0.012f);
            o->oFwooshSpawnerUnk1AC += 200;

            if (o->oDistanceToMario < 1000.0f)
            {
                if (o->oTimer > 100)
                {
                    o->oFwooshSpawnerUnkFC = 1;
                    o->oFwooshSpawnerUnk100 = 0.14f;
                }
            }
            else
            {
                o->oTimer = 0;
            }

            o->oFwooshSpawnerUnkF4 = o->oHomeX + 100.0f * coss(o->oFwooshSpawnerUnk1AC);
            o->oPosZ = o->oHomeZ + 100.0f * sins(o->oFwooshSpawnerUnk1AC);
            o->oFwooshSpawnerUnkF8 = o->oHomeY;
        }

        ScaleObject(o->header.gfx.scale[0]);
    }
}

void func_803023E8(void)
{
    s16 val06;
    f32 val00;

    val06 = 0x800 * gGlobalTimer;

    if (o->parentObj != o)
    {
        if (o->parentObj->active == 0)
        {
            o->oAction = 2;
        }
        else
        {
            o->oFwooshSpawnerUnkF4 = o->parentObj->oPosX;
            o->oFwooshSpawnerUnkF8 = o->parentObj->oPosY;
            o->oPosZ = o->parentObj->oPosZ;
            o->oAngleYaw = o->parentObj->oFaceAngleYaw;
        }
    }
    else
    {
        if (o->oBehParams2ndByte != 0)
        {
            if (o->oDistanceToMario > 1500.0f)
            {
                o->oAction = 2;
            }
        }
        else
        {
            func_8030215C();
        }
    }

    val00 = 2.0f * coss(val06) * o->header.gfx.scale[0];

    o->oPosX = o->oFwooshSpawnerUnkF4 + val00;
    o->oPosY = o->oFwooshSpawnerUnkF8 + val00 + 12.0f * o->header.gfx.scale[0];
}

void func_80302584(void)
{
    if (o->oBehParams2ndByte != 0)
    {
        DeactivateObject(o);
    }
    else
    {
        o->oAction = 3;
        UnHideObject();
        obj_set_pos_to_home();
    }
}

void BehFwooshBlowingWindLoop(void)
{
    switch (o->oAction)
    {
    case 0: func_80301FF8(); break;
    case 1: func_803023E8(); break;
    case 2: func_80302584(); break;
    case 3: func_80302104(); break;
    }
}

void BehFwooshFaceLoop(void)
{
    f32 val0C;
    s16 val0A;
    s16 val08;
    f32 val04;
    f32 val00;

    if (o->parentObj->oAction == 2)
    {
        DeactivateObject(o);
    }
    else
    {
        val0C = 2.0f / 3.0f * o->parentObj->header.gfx.scale[0];
        val0A = o->parentObj->oFaceAngleYaw + 0x3333 * o->oBehParams2ndByte;
        val08 = 0x800 * gGlobalTimer + 0x4000 * o->oBehParams2ndByte;

        ScaleObject(val0C);

        if (o->oBehParams2ndByte == 5 && val0C > 2.0f)
        {
            val0C = o->header.gfx.scale[1] = 2.0f;
        }

        val04 = 2.0f * coss(val08) * val0C;
        val00 = 25.0f * val0C;

        o->oPosX = o->parentObj->oFwooshSpawnerUnkF4 + val00 * sins(val0A) + val04;
        o->oPosY = o->parentObj->oFwooshSpawnerUnkF8 + val04 + val0C * D_8033186C[o->oBehParams2ndByte];
        o->oPosZ = o->parentObj->oPosZ + val00 * coss(val0A) + val04;
        o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw;
    }
}

void BehLakituInit(void)
{
    if (o->oBehParams2ndByte != 0)
    {
        if (D_80339EFE != 1)
        {
            DeactivateObject(o);
        }
    }
    else
    {
        func_8029E880(1, 0, 0, 0, 2.0f, o, 0x8E, beh_fwoosh_blowing_wind);
    }
}

void func_80302970(void)
{
    if (gMarioObject->oPosX > -544.0f && gMarioObject->oPosX < 545.0f &&
        gMarioObject->oPosY > 800.0f &&
        gMarioObject->oPosZ > -2000.0f && gMarioObject->oPosZ < -177.0f &&
        gMarioObject->oPosZ < -177.0f) // good programmers always check for cosmic rays
    {
        if (func_802573C8(2) == 1)
        {
            o->oAction = 1;
        }
    }
}

void func_80302A58(void)
{
    if (func_802573C8(2) == 2)
    {
        o->oAction = 2;

        o->oPosX = 1800.0f;
        o->oPosY = 2400.0f;
        o->oPosZ = -2400.0f;

        o->oAnglePitch = 0x4000;
        o->oNiceLakituUnkF8 = 60.0f;
        o->oNiceLakituUnkFC = 1000.0f;

        func_8029E880(1, 0, 0, 0, 2.0f, o, 0x8E, beh_fwoosh_blowing_wind);
    }
}

void func_80302B64(void)
{
    s16 val06;
    s16 val04;
    s16 val02;

    PlaySound(0x60028001);

    o->oFaceAnglePitch = func_802F9414(120.0f, 0);
    o->oFaceAngleYaw = o->oAngleToMario;

    if (o->oNiceLakituUnk100 != 0)
    {
        approach_f32_2(&o->oNiceLakituUnkF8, 60.0f, 3.0f);
        if (o->oDistanceToMario > 6000.0f)
        {
            DeactivateObject(o);
        }

        val06 = -0x3000;
        val04 = -0x6000;
    }
    else
    {
        if (o->oNiceLakituUnkF8 != 0.0f)
        {
            if (o->oDistanceToMario > 5000.0f)
            {
                val06 = o->oAnglePitch;
                val04 = o->oAngleToMario;
            }
            else
            {
                val02 = 0x4000 -
                    atan2s(o->oNiceLakituUnkFC, o->oDistanceToMario - o->oNiceLakituUnkFC);
                if ((s16)(o->oAngleYaw - o->oAngleToMario) < 0)
                {
                    val02 = -val02;
                }

                val04 = o->oAngleToMario + val02;
                val06 = o->oFaceAnglePitch;

                approach_f32_2(&o->oNiceLakituUnkFC, 200.0f, 50.0f);
                if (o->oDistanceToMario < 1000.0f)
                {
#ifndef VERSION_JP
                    if (o->oNiceLakituUnk104 == 0)
                    {
                        func_80320AE8(0, 3874, 0);
                        o->oNiceLakituUnk104 = 1;
                    }
#endif

                    approach_f32_2(&o->oNiceLakituUnkF8, 20.0f, 1.0f);
                    if (o->oDistanceToMario < 500.0f &&
                        abs_angle_diff(gMarioObject->oFaceAngleYaw, o->oFaceAngleYaw) > 0x7000)
                    {
                        approach_f32_2(&o->oNiceLakituUnkF8, 0.0f, 5.0f);
                    }
                }
            }
        }
        else if (CreateMessageBox(2, 1, 0xA2, 0x22) != 0)
        {
            o->oNiceLakituUnk100 = 1;
        }
    }

    o->oNiceLakituUnk1AC = approach_target_angle(o->oNiceLakituUnk1AC, 2000, 400);
    func_802F95B0(val06, o->oNiceLakituUnk1AC);
    o->oNiceLakituUnk1AE = approach_target_angle(o->oNiceLakituUnk1AE, 2000, 100);
    func_8029DE70(val04, o->oNiceLakituUnk1AE);
    func_802F9148(o->oNiceLakituUnkF8);
    MoveObj2();
}

void BehLakituLoop(void)
{
    f32 val0C;

    if (!(o->active & 0x00000008))
    {
        update_blinking(&o->oNiceLakituBlinkTimer, 20, 40, 4);
        if (o->oBehParams2ndByte != 0)
        {
            switch (o->oAction) {
            case 0: func_80302970(); break;
            case 1: func_80302A58(); break;
            case 2: func_80302B64(); break;
            }
        }
        else
        {
            val0C = (f32)0x875C3D / 0x800 - D_8033B328[3];
            if (D_8033B328[3] < 1700.0f || val0C < 0.0f)
            {
                UnHideObject();
            }
            else
            {
                func_8029EF18();

                o->oPosX = D_8033B328[3];
                o->oPosY = D_8033B328[4];
                o->oPosZ = D_8033B328[5];

                o->oHomeX = D_8033B328[0];
                o->oHomeZ = D_8033B328[2];

                o->oFaceAngleYaw = -obj_angle_to_home();
                o->oFaceAnglePitch = atan2s(obj_lateral_dist_to_home(), o->oPosY - D_8033B328[1]);

                o->oPosX = (f32)0x875C3D / 0x800 + val0C;
            }
        }
    }
}

struct Object *func_803030BC(void *arg0)
{
    void *val0C;
    struct Object *val08;
    struct Object *val04;
    struct ObjectNode *val00;

    val0C = segmented_to_virtual(arg0);
    val04 = NULL;

    val00 = &gObjectLists[func_8029F198(val0C)];
    
    val08 = (struct Object *)val00->next;
    while (val08 != (struct Object *)val00)
    {
        if (val08->behavior == val0C && val08->active != 0)
        {
            val08->parentObj = val04;
            val04 = val08;
        }
        
        val08 = (struct Object *)val08->header.next;
    }

    return val04;
}

struct Object *func_80303190(f32 arg0)
{
    struct Object *val0C;
    s32 val08;
    s32 val04;

    val0C = D_80360104;
    val08 = 0;

    while (val0C != NULL)
    {
        if (val0C->oMontyMoleHoleUnkF4 == 0)
        {
            if (val0C->oDistanceToMario < 1500.0f && val0C->oDistanceToMario > arg0)
            {
                val08++;
            }
        }

        val0C = val0C->parentObj;
    }

    if (val08 != 0)
    {
        val04 = (s32)(RandomFloat() * val08);
        val0C = D_80360104;
        val08 = 0;

        while (val0C != NULL)
        {
            if (val0C->oMontyMoleHoleUnkF4 == 0)
            {
                if (val0C->oDistanceToMario < 1500.0f && val0C->oDistanceToMario > arg0)
                {
                    if (val08 == val04)
                    {
                        return val0C;
                    }

                    val08++;
                }
            }

            val0C = val0C->parentObj;
        }
    }

    return NULL;
}

void BehMontyMoleInHoleLoop(void)
{
    if (o->parentObj == o)
    {
        D_80360104 = func_803030BC(beh_monty_mole_in_hole);
        D_80360108 = 0;
    }
    else if (o->oMontyMoleHoleUnkF4 > 0)
    {
        o->oMontyMoleHoleUnkF4 -= 1;
    }
}

void func_80303390(s8 arg0, s8 arg1)
{
    D_80331874.unk3 = arg0;
    D_80331874.unk6 = arg1;
    func_802A2B04(&D_80331874);
}

void BehMontyMoleInit(void)
{
    o->oMontyMoleUnkF4 = NULL;
}

void func_803033F8(void)
{
    f32 val0C;

    if (o->oBehParams2ndByte != 0)
    {
        val0C = 200.0f;
    }
    else if (gMarioStates[0].forwardVel < 8.0f)
    {
        val0C = 100.0f;
    }
    else
    {
        val0C = 500.0f;
    }

    if ((o->oMontyMoleUnkF4 = func_80303190(val0C)) != 0)
    {
        PlaySound2(0x90678081);
        o->oMontyMoleUnkF4->oMontyMoleHoleUnkF4 = -1;
        
        o->oPosX = o->oMontyMoleUnkF4->oPosX;
        o->oPosY = o->oFloorHeight = o->oMontyMoleUnkF4->oPosY;
        o->oPosZ = o->oMontyMoleUnkF4->oPosZ;

        o->oFaceAnglePitch = 0;
        o->oAngleYaw = o->oMontyMoleUnkF4->oAngleToMario;

        if (o->oDistanceToMario > 500.0f || val0C > 100.0f || RandomSign() < 0)
        {
            o->oAction = 1;
            o->oVelY = 3.0f;
            o->oGravity = 0.0f;
            func_80303390(0, 10);
        }
        else
        {
            o->oAction = 7;
            o->oVelY = 50.0f;
            o->oGravity = -4.0f;
            func_80303390(0, 20);
        }

        func_8029EF18();
        func_8029FE58();
    }
}

void func_8030362C(void)
{
    func_8029ED38(1);
    if (o->oMontyMoleUnkF8 >= 49.0f)
    {
        o->oPosY = o->oFloorHeight + 50.0f;
        o->oVelY = 0.0f;

        if (func_8029F788())
        {
            o->oAction = 2;
        }
    }
}

void func_803036C8(void)
{
    struct Object *val04;

    if (func_802F92B0(2))
    {
        if (o->oBehParams2ndByte != 0 &&
            abs_angle_diff(o->oAngleToMario, o->oAngleYaw) < 0x4000 &&
            (val04 = SpawnObj(o, 0xA1, beh_monty_mole_rock)) != NULL)
        {
            o->prevObj = val04;
            o->oAction = 4;
        }
        else
        {
            o->oAction = 3;
        }
    }
}

void func_80303780(void)
{
    if (func_802F92B0(3) || func_802F87E0(1000.0f, 0x4000))
    {
        o->oAction = 5;
        o->oVelY = 40.0f;
        o->oGravity = -6.0f;
    }
}

void func_80303808(void)
{
    if (func_802F92EC(8, 10))
    {
        PlaySound2(0x50220081);
        o->prevObj = NULL;
    }

    if (func_8029F788())
    {
        o->oAction = 3;
    }
}

void func_80303874(void)
{
    func_802F927C(0);
    o->oFaceAnglePitch = -atan2s(o->oVelY, -4.0f);
    
    if (o->oVelY < 0.0f && o->oMontyMoleUnkF8 < 120.0f)
    {
        o->oAction = 6;
        o->oGravity = 0.0f;
        func_80303390(-80, 15);
    }
}

void func_80303930(void)
{
    o->oMontyMoleUnkF4->oMontyMoleHoleUnkF4 = 30;
    o->oAction = 0;
    o->oVelY = 0.0f;
    func_8029FE38();
}

void func_8030398C(void)
{
    func_8029ED38(1);
    if (o->oMoveFlags & 0x00000003)
    {
        UnHideObject();
        func_80303930();
    }
    else
    {
        approach_f32_2(&o->oVelY, -4.0f, 0.5f);
    }
}

void func_803039FC(void)
{
    if (o->oVelY > 0.0f)
    {
        func_8029ED38(9);
    }
    else
    {
        func_802F927C(4);
        if (o->oMontyMoleUnkF8 < 50.0f)
        {
            o->oPosY = o->oFloorHeight + 50.0f;
            o->oAction = 3;
            o->oVelY = o->oGravity = 0.0f;
        }
    }
}

void BehMontyMoleLoop(void)
{
    f32 val0C;
    f32 val08;
    f32 val04;
    f32 val00;

    o->oUnk1C4 = 0x50244081;
    MoveRelated();

    o->oMontyMoleUnkF8 = o->oPosY - o->oFloorHeight;

    switch (o->oAction)
    {
    case 0: func_803033F8(); break;
    case 1: func_8030362C(); break;
    case 2: func_803036C8(); break;
    case 3: func_80303780(); break;
    case 4: func_80303808(); break;
    case 5: func_80303874(); break;
    case 6: func_8030398C(); break;
    case 7: func_803039FC(); break;
    }

    if (func_802FA888(&D_80331888, o->oAction))
    {
        if (D_80360108 != 0)
        {
            val0C = o->oPosX - D_8036010C;
            val08 = o->oPosY - D_80360110;
            val04 = o->oPosZ - D_80360114;

            val00 = sqrtf(val0C*val0C + val08*val08 + val04*val04);
            if (val00 < 1500.0f)
            {
                if (D_80360108 == 7)
                {
                    func_80321228();
                    SpawnObj(o, 0xD4, beh_1up_walking);
                }
            }
            else
            {
                D_80360108 = 0;
            }
        }

        D_80360108 += 1;
        D_8036010C = o->oPosX;
        D_80360110 = o->oPosY;
        D_80360114 = o->oPosZ;
        func_80303930();
        o->prevObj = NULL;
    }

    MoveObj(78);
}

void func_80303D44(void)
{
    f32 val04;

    o->oParentRelX = 80.0f;
    o->oParentRelY = -50.0f;
    o->oParentRelZ = 0.0f;

    if (o->parentObj->prevObj == NULL)
    {
        val04 = o->oDistanceToMario;
        if (val04 > 600.0f)
        {
            val04 = 600.0f;
        }

        o->oAction = 1;
        o->oAngleYaw = (s32)(o->parentObj->oAngleYaw + 500 - val04 * 0.1f);

        o->oForwardVel = 40.0f;
        o->oVelY = val04 * 0.08f + 8.0f;

        o->oMoveFlags = 0;
    }
}

void func_80303E90(void)
{
    MoveRelated();
    if (o->oMoveFlags & 0x0000000B)
    {
        func_802A2B04(&D_803318A8);
        DeactivateObject(o);
    }
    MoveObj(78);
}

void BehMontyMoleRockLoop(void)
{
    func_802FA888(&D_80331898, o->oAction);
    switch (o->oAction)
    {
    case 0: func_80303D44(); break;
    case 1: func_80303E90(); break;
    }
}

// TODO: Finish
#include "behaviors/platform_on_track.c.inc"
#include "behaviors/seesaw_platform.c.inc"

void BehFourRotatingPlatformsInit(void)
{
    struct Object *val04;
    s32 val00;

    o->collisionData = segmented_to_virtual(D_80331910[o->oBehParams2ndByte].unk00);

    for (val00 = 0; val00 < 4; val00++)
    {
        val04 = spawn_obj_adv(val00, 0, 0, 0, o, D_80331910[o->oBehParams2ndByte].unk08, beh_ferris_wheel_platform);
        if (val04 != NULL)
        {
            val04->collisionData = segmented_to_virtual(D_80331910[o->oBehParams2ndByte].unk04);
        }
    }
}

void BehFerrisWheelPlatformLoop(void)
{
    f32 sp1C;
    s16 sp1A;

    func_802F8854(0);
    sp1A = o->parentObj->oFaceAngleRoll + o->oBehParams2ndByte * 0x4000;
    sp1C = 400.0f * coss(sp1A);
    
    o->oPosX = o->parentObj->oPosX + sp1C * sins(o->parentObj->oAngleYaw) + 300.0f * coss(o->parentObj->oAngleYaw);
    o->oPosY = o->parentObj->oPosY + 400.0f * sins(sp1A);
    o->oPosZ = o->parentObj->oPosZ + sp1C * coss(o->parentObj->oAngleYaw) + 300.0f * sins(o->parentObj->oAngleYaw);

    func_802F8854(1);
}

#include "behaviors/water_bomb.c.inc"
#include "behaviors/ttc_rotating_solid.c.inc"
#include "behaviors/ttc_pendulum.c.inc"
#include "behaviors/ttc_treadmill.c.inc"
#include "behaviors/ttc_moving_bar.c.inc"
#include "behaviors/ttc_cog.c.inc"
#include "behaviors/ttc_pit_block.c.inc"
#include "behaviors/ttc_elevator.c.inc"
#include "behaviors/ttc_2d_rotator.c.inc"
#include "behaviors/ttc_spinner.c.inc"
// TODO: Finish
#include "behaviors/mr_blizzard.c.inc"

void BehSlidingPlatform2Init(void)
{
    s32 val04;

    val04 = ((u16)(o->oBehParams >> 16) & 0x0380) >> 7;
    o->collisionData = segmented_to_virtual(D_80331A24[val04]);
    o->oBackAndForthPlatformUnkF8 = 50.0f * ((u16)(o->oBehParams >> 16) & 0x003F);

    if (val04 < 5 || val04 > 6)
    {
        o->oBackAndForthPlatformUnk100 = 15.0f;
        if ((u16)(o->oBehParams >> 16) & 0x0040)
        {
            o->oAngleYaw += 0x8000;
        }
    }
    else
    {
        o->oBackAndForthPlatformUnk100 = 10.0f;
        if ((u16)(o->oBehParams >> 16) & 0x0040)
        {
            o->oBackAndForthPlatformUnkF4 = -1.0f;
        }
        else
        {
            o->oBackAndForthPlatformUnkF4 = 1.0f;
        }
    }
}

void BehSlidingPlatform2Loop(void)
{
    if (o->oTimer > 10)
    {
        o->oBackAndForthPlatformUnkFC += o->oBackAndForthPlatformUnk100;
        if (cap_f32(&o->oBackAndForthPlatformUnkFC, -o->oBackAndForthPlatformUnkF8, 0.0f))
        {
            o->oBackAndForthPlatformUnk100 = -o->oBackAndForthPlatformUnk100;
            o->oTimer = 0;
        }
    }

    func_802F8854(0);

    if (o->oBackAndForthPlatformUnkF4 != 0.0f)
    {
        o->oPosY = o->oHomeY + o->oBackAndForthPlatformUnkFC * o->oBackAndForthPlatformUnkF4;
    }
    else
    {
        func_802F8770(o->oBackAndForthPlatformUnkFC);
    }

    func_802F8854(1);
}

void BehOctagonalPlatformRotatingInit(void)
{
    o->collisionData = segmented_to_virtual(D_80331A44[(u8)(o->oBehParams >> 16)]);
    o->oAngleVelYaw = D_80331A4C[(u8)(o->oBehParams >> 24)];
}

void BehOctagonalPlatformRotatingLoop(void)
{
    o->oFaceAngleYaw += o->oAngleVelYaw;
}

void BehFloorSwitchPressAnimationInit(void)
{
    o->parentObj = func_8029F1E0(beh_purple_switch_staircase);
}

void BehFloorSwitchPressAnimationLoop(void)
{
    if (o->oFloorSwitchPressAnimationUnk100 != 0)
    {
        if (o->parentObj->oAction != 2)
        {
            o->oFloorSwitchPressAnimationUnk100 = 0;
        }

        if (o->oFloorSwitchPressAnimationUnkFC != 0)
        {
            o->oFloorSwitchPressAnimationUnkF4 = D_80331ACC[o->oBehParams2ndByte];
        }
        else
        {
            o->oFloorSwitchPressAnimationUnkF4 = 0;
        }
    }
    else if (o->parentObj->oAction == 2)
    {
        o->oFloorSwitchPressAnimationUnkFC ^= 1;
        o->oFloorSwitchPressAnimationUnk100 = 1;
    }

    if (o->oFloorSwitchPressAnimationUnkF4 != 0)
    {
        if (o->oFloorSwitchPressAnimationUnkF4 < 60)
        {
            PlaySound(0x8055F011);
        }
        else
        {
            PlaySound(0x8054F011);
        }

        if (--o->oFloorSwitchPressAnimationUnkF4 == 0)
        {
            o->oFloorSwitchPressAnimationUnkFC = 0;
        }

        if (o->oFloorSwitchPressAnimationUnkF8 < 9)
        {
            o->oFloorSwitchPressAnimationUnkF8 += 1;
        }
    }
    else if ((o->oFloorSwitchPressAnimationUnkF8 -= 2) < 0)
    {
        o->oFloorSwitchPressAnimationUnkF8 = 0;
        o->oFloorSwitchPressAnimationUnkFC = 1;
    }

    o->collisionData =
        segmented_to_virtual(D_80331A54[o->oBehParams2ndByte][o->oFloorSwitchPressAnimationUnkF8 / 2].unk00);

    SetModel(D_80331A54[o->oBehParams2ndByte][o->oFloorSwitchPressAnimationUnkF8 / 2].unk04);
}

#include "behaviors/activated_bf_plat.c.inc"
#include "behaviors/spinning_heart.c.inc"

void BehCannonBarrelBubblesLoop(void)
{
    struct Object *val04;

    if (o->parentObj->oAction == 2)
    {
        DeactivateObject(o);
    }
    else
    {
        o->oAngleYaw = o->parentObj->oFaceAngleYaw;
        o->oAnglePitch = o->parentObj->oAnglePitch + 0x4000;
        o->oFaceAnglePitch = o->parentObj->oAnglePitch;

        if ((o->oCannonBarrelBubblesUnkF4 += o->oForwardVel) > 0.0f)
        {
            func_802A2A38();
            forward_vel_approach(-5.0f, 18.0f);
        }
        else
        {
            o->oCannonBarrelBubblesUnkF4 = 0.0f;
            CopyObjPosition(o, o->parentObj);

            // check this
            if (o->parentObj->oCannonUnkF4 != 0)
            {
                if (o->oForwardVel == 0.0f)
                {
                    o->oForwardVel = 35.0f;

                    val04 = SpawnObj(o, 0x54, bWaterBomb);
                    if (val04 != NULL)
                    {
                        val04->oForwardVel = -100.0f;
                        val04->header.gfx.scale[1] = 1.7f;
                    }

                    func_8027F440(2, o->oPosX, o->oPosY, o->oPosZ);
                }
            }
            else
            {
                o->oForwardVel = 0.0f;
            }
        }
    }
}

void func_80308DF0(void)
{
    if (o->oDistanceToMario < 2000.0f)
    {
        SpawnObj(o, 0x7F, beh_cannon_barrel_bubbles);
        func_8029EF18();

        o->oAction = 1;
        o->oAnglePitch = o->oCannonUnkFC = 0x1C00;
    }
}

void func_80308E84(void)
{
    if (o->oDistanceToMario > 2500.0f)
    {
        o->oAction = 2;
    }
    else if (o->oBehParams2ndByte == 0)
    {
        if (o->oCannonUnkF4 != 0)
        {
            o->oCannonUnkF4 -= 1;
        }
        else
        {
            func_802F95B0(o->oCannonUnkFC, 0x80);
            face_yaw_approach(o->oCannonUnk100, 0x100);

            if ((s16)o->oFaceAngleYaw == (s16)o->oCannonUnk100)
            {
                if (o->oCannonUnkF8 != 0)
                {
                    o->oCannonUnkF8 -= 1;
                }
                else
                {
                    PlaySound2(0x50254081);
                    o->oCannonUnkF4 = 70;
                    o->oCannonUnkFC = 0x1000 + 0x400 * (RandomU16() & 0x3);
                    o->oCannonUnk100 = -0x2000 + o->oAngleYaw + 0x1000 * (RandomU16() % 5);
                    o->oCannonUnkF8 = 60;
                }
            }
        }
    }
}

void func_80309004(void)
{
    UnHideObject();
    o->oAction = 0;
}

void BehCannonLoop(void)
{
    func_802A3164(220.0f, 300.0f);

    switch (o->oAction)
    {
    case 0: func_80308DF0(); break;
    case 1: func_80308E84(); break;
    case 2: func_80309004(); break;
    }
}

void BehUnagiInit(void)
{
    if (o->oBehParams2ndByte != 1)
    {
        o->oUnagiUnkFC = segmented_to_virtual(jrb_seg7_trajectory_unagi_1);
        if (o->oBehParams2ndByte == 0)
        {
            o->oFaceAnglePitch = -7600;
        }
        else
        {
            o->oAction = 1;
        }
    }
    else
    {
        o->oUnagiUnkFC = segmented_to_virtual(jrb_seg7_trajectory_unagi_2);
        o->oAction = 3;
        o->oAnimState = 1;

        o->oUnagiUnk1B0 = o->oAngleYaw;
    }

    o->oUnagiUnk100 = o->oUnagiUnkFC;
}

void func_803091C4(void)
{
    if (o->oDistanceToMario > 4500.0f && o->oUnk150 != 0)
    {
        o->oAction = 1;
        o->oPosX = o->oUnagiUnkFC[1];
        o->oPosY = o->oUnagiUnkFC[2];
        o->oPosZ = o->oUnagiUnkFC[3];
    }
    else if (o->oUnagiUnk1AC < 700.0f)
    {
        o->oUnk150 = 1;
    }
}

void func_803092AC(s32 arg0)
{
    if (o->oSoundStateID == 3)
    {
        if (check_anim_frame(30))
        {
            o->oForwardVel = 40.0f;
        }
    }
    else
    {
        if (func_8029F828())
        {
            if (o->oAction != arg0 && (o->oUnagiUnk104 & 0xFF) >= 7)
            {
                func_8029ED38(3);
            }
            else
            {
                func_8029ED38(2);
            }
        }
    }

    if (check_anim_frame(6))
    {
        PlaySound2(0x30090081);
    }

    if (func_802A24B4(0) == -1)
    {
        o->oAction = arg0;
    }

    o->oAnglePitch = o->oFaceAnglePitch =
        approach_target_angle(o->oAnglePitch, o->oUnagiUnk108, 50);

    func_8029DE70(o->oUnagiUnk10C, 120);
    func_802F9850(o->oUnagiUnk10C, 0x2000, 100);

    forward_vel_approach(10.0f, 0.2f);
    func_802A2A38();
}

void func_80309430(void)
{
    o->oUnagiUnk100 = o->oUnagiUnkFC;
    o->oUnagiUnk104 = 0;

    obj_set_pos_to_home();

    o->oAnglePitch = o->oFaceAnglePitch = 0;
    o->oAngleYaw = o->oFaceAngleYaw = o->oUnagiUnk1B0;
    o->oFaceAngleRoll = 0;

    o->oForwardVel = o->oVelX = o->oVelZ = o->oUnagiUnkF8 = 0.0f;

    o->oUnagiUnkF4 = -800.0f;

    o->oAction = 3;
}

void func_80309530(void)
{
    if (o->oUnagiUnkF4 < 0.0f)
    {
        func_8029ED38(6);
        
        if ((o->oUnagiUnkF4 += 10.0f) > 0.0f)
        {
            o->oUnagiUnkF4 = 0.0f;
        }
    }
    else
    {
        if (o->oUnagiUnkF4 == 0.0f)
        {
            func_8029ED38(6);

            if (o->oTimer > 60 && o->oUnagiUnk1AC < 1000.0f)
            {
                PlaySound2(0x524A0081);
                o->oUnagiUnkF8 = o->oUnagiUnk110 = 30.0f;
            }
            else
            {
                o->oUnagiUnk110 = 0.0f;
            }
        }
        else if (o->oUnagiUnk110 > 0.0f)
        {
            if (func_802F92B0(5))
            {
                o->oUnagiUnk110 = 0.0f;
            }
        }
        else if (o->oUnagiUnk110 == 0.0f)
        {
            func_8029ED38(0);
            if (func_8029F828())
            {
                if (o->oUnagiUnk1AC < 1000.0f)
                {
                    o->oAction = 4;
                    o->oForwardVel = o->oUnagiUnkF8;
                    func_8029ED38(1);
                }
                else
                {
                    o->oUnagiUnk110 = -50.0f;
                    func_8029ED38(4);
                }
            }
        }
        
        approach_f32_2(&o->oUnagiUnkF8, o->oUnagiUnk110, 4.0f);

        if ((o->oUnagiUnkF4 += o->oUnagiUnkF8) < 0.0f)
        {
            o->oUnagiUnkF4 = o->oUnagiUnkF8 = 0.0f;
            o->oTimer = 0;
        }
    }

    o->oPosX = o->oHomeX + o->oUnagiUnkF4 * sins(o->oAngleYaw);
    o->oPosZ = o->oHomeZ + o->oUnagiUnkF4 * coss(o->oAngleYaw);
}

void BehUnagiLoop(void)
{
    s32 val04;

    if (o->oUnagiUnk1B2 == 0)
    {
        o->oUnagiUnk1AC = 99999.0f;
        if (o->oDistanceToMario < 3000.0f)
        {
            for (val04 = -4; val04 < 4; val04++)
            {
                spawn_obj_adv(val04, 0, 0, 0, o, 0, beh_unagi_subobject);
            }
            o->oUnagiUnk1B2 = 1;
        }
    }
    else if (o->oDistanceToMario > 4000.0f)
    {
        o->oUnagiUnk1B2 = 0;
    }

    switch (o->oAction)
    {
    case 0: func_803091C4(); break;
    case 1: func_803092AC(o->oAction); break;
    case 2: func_80309430();
    case 3: func_80309530(); break;
    case 4: func_803092AC(2); break;
    }
}

void BehUnagiSubobjectLoop(void)
{
    f32 val04;

    if (o->parentObj->oUnagiUnk1B2 == 0)
    {
        DeactivateObject(o);
    }
    else
    {
        val04 = 300.0f * o->oBehParams2ndByte;

        o->oPosY = o->parentObj->oPosY - val04 * sins(o->parentObj->oFaceAnglePitch) * 1.13f;

        val04 = coss(o->parentObj->oFaceAnglePitch / 2) * val04;

        o->oPosX = o->parentObj->oPosX + val04 * sins(o->parentObj->oFaceAngleYaw);
        o->oPosZ = o->parentObj->oPosZ + val04 * coss(o->parentObj->oFaceAngleYaw);

        if (o->oBehParams2ndByte == -4)
        {
            if (o->parentObj->oAnimState != 0 && o->oDistanceToMario < 150.0f)
            {
                o->oBehParams = o->parentObj->oBehParams;
                CreateStar(6833.0f, -3654.0f, 2230.0f);
                o->parentObj->oAnimState = 0;
            }
        }
        else
        {
            func_802FA888(&D_80331AF0, o->oAction);
            if (o->oBehParams2ndByte == 3)
            {
                o->parentObj->oUnagiUnk1AC = o->oDistanceToMario;
            }
        }
    }
}

#include "behaviors/dorrie.c.inc"

void BehHauntedChairInit(void)
{
    struct Object *val04;
    f32 val00;

    val04 = func_8029F270(bMadPiano, &val00);
    if (val04 != NULL && val00 < 300.0f)
    {
        o->parentObj = val04;
    }
    else
    {
        o->oHauntedChairUnkF4 = 1;
    }
}

void func_8030A5D8(void)
{
    s16 val0E;
    f32 val08;

    if (o->parentObj != o)
    {
        if (o->oHauntedChairUnk104 == 0)
        {
            if (DistanceFromObject(o, o->parentObj) < 250.0f)
            {
                val0E = func_8029DF18(o, o->parentObj) - o->oFaceAngleYaw + 0x2000;
                if (val0E & 0x4000)
                {
                    o->oHauntedChairUnk100 = &o->oFaceAngleRoll;
                    if (val0E > 0)
                    {
                        o->oHauntedChairUnk104 = 0x4000;
                    }
                    else
                    {
                        o->oHauntedChairUnk104 = -0x4000;
                    }
                }
                else
                {
                    o->oHauntedChairUnk100 = &o->oFaceAnglePitch;
                    if (val0E < 0)
                    {
                        o->oHauntedChairUnk104 = 0x5000;
                    }
                    else
                    {
                        o->oHauntedChairUnk104 = -0x4000;
                    }
                }

                if (o->oHauntedChairUnk104 < 0)
                {
                    o->oHauntedChairUnkF8 = -1500.0f;
                }
                else
                {
                    o->oHauntedChairUnkF8 = 1500.0f;
                }
            }
        }
        else
        {
            func_802F9B68(o->oHauntedChairUnk100, &o->oHauntedChairUnkF8, o->oHauntedChairUnk104, 4000.0f, 20.0f, 2.0f);
        }
    }
    else if (o->oHauntedChairUnkF4 != 0)
    {
        if (o->oDistanceToMario < 500.0f)
        {
            o->oHauntedChairUnkF4 -= 1;
        }
        o->oTimer = 0.0f;
    }
    else
    {
        if ((o->oTimer & 0x8) != 0)
        {
            if (o->oFaceAnglePitch < 0)
            {
                PlaySound2(0x305F0081);
                val08 = 4.0f;
            }
            else
            {
                val08 = -4.0f;
            }

            o->oHomeX -= val08;
            o->oHomeZ -= val08;

            o->oFaceAnglePitch = o->oFaceAngleRoll = (s32)(50.0f * val08);;
        }
        else
        {
            o->oFaceAnglePitch = o->oFaceAngleRoll = 0;
        }

        if (o->oTimer > 30)
        {
            o->oAction = 1;
            o->oHauntedChairUnkF8 = 0.0f;
            o->oHauntedChairUnkFC = 200.0f;
            o->oHauntedChairUnkF4 = 40;
        }
    }

    func_802A3164(80.0f, 120.0f);
}

void func_8030A968(void)
{
    MoveRelated();

    if (o->oTimer < 70)
    {
        if (o->oTimer < 50)
        {
            o->oVelY = 6.0f;
        }
        else
        {
            o->oVelY = 0.0f;
        }

        o->oGravity = 0.0f;
        func_802F9B68(&o->oFaceAnglePitch, &o->oHauntedChairUnkF8, -4000, 200.0f, 20.0f, 2.0f);
        func_802F9B68(&o->oFaceAngleRoll, &o->oHauntedChairUnkFC, 0, 0.0f, 20.0f, 1.0f);
    }
    else
    {
        if (o->oHauntedChairUnkF4 != 0)
        {
            if (--o->oHauntedChairUnkF4 == 0)
            {
                PlaySound2(0x305D0081);
                o->oAnglePitch = func_802F9414(120.0f, 0);
                o->oAngleYaw = o->oAngleToMario;
                func_802F9148(50.0f);
            }
            else if (o->oHauntedChairUnkF4 > 20)
            {
                if (gGlobalTimer % 4 == 0)
                {
                    PlaySound2(0x315C0081);
                }
                o->oFaceAngleYaw += 0x2710;
            }
        }
        else if (o->oMoveFlags & 0x00000203)
        {
            func_802FA078();
        }
    }

    func_802FA888(&D_80331B00, o->oAction);
    MoveObj(78);
}

void BehHauntedChairLoop(void)
{
    if (!(o->active & 0x0008))
    {
        switch (o->oAction)
        {
        case 0: func_8030A5D8(); break;
        case 1: func_8030A968(); break;
        }
        func_802F8D78(30.0f, 30.0f);
    }
}

#include "behaviors/mad_piano.c.inc"

void func_8030AF6C(void)
{
    if (func_802F87E0(400.0f, 0x3000))
    {
        PlaySound2(0x502C8081);
        o->oAction = 1;
        o->oBookendUnkF4 = o->oFaceAnglePitch + 0x7FFF;
        o->oBookendUnkF8 = o->oFaceAngleRoll - 0x7FFF;
        SetModel(0x58);
    }
}

void func_8030AFF0(void)
{
    if (forward_vel_approach(3.0f, 1.0f))
    {
        if (func_802F92B0(2))
        {
            o->oAction = 2;
            o->oForwardVel = 0.0f;
        }
        else
        {
            o->oForwardVel = 3.0f;
            if (o->oTimer > 5)
            {
                face_pitch_approach(o->oBookendUnkF4, 2000);
                if (o->oTimer >= 10)
                {
                    face_roll_approach(o->oBookendUnkF8, 2000);
                    if (o->oTimer >= 20)
                    {
                        approach_f32_2(&o->header.gfx.scale[0], 3.0f, 0.2f);
                    }
                }
            }
        }
    }

    MoveObj2();
}

void func_8030B110(void)
{
    func_8029ED38(1);
    MoveRelated();

    if (o->oForwardVel == 0.0f)
    {
        func_802F9414(120.0f, 1000);
        o->oFaceAnglePitch = o->oAnglePitch + 0x7FFF;
        func_8029DE70(o->oAngleToMario, 1000);

        if (o->oTimer > 30)
        {
            func_802F9148(50.0f);
        }
    }

    MoveObj(78);
}

void func_8030B1C8(void)
{
    o->oUnk180 = 1;
    o->oUnk198 = 0;

    if (o->oTimer >= 4)
    {
        o->oAction = 2;
        o->oForwardVel = 50.0f;
    }

    forward_vel_approach(50.0f, 2.0f);
    MoveObj2();
}

void BehFlyingBookendLoop(void)
{
    if (!(o->active & 0x0008))
    {
        o->oUnk1C4 = 0x50155081;
        ScaleObject(o->header.gfx.scale[0]);

        switch (o->oAction)
        {
        case 0: func_8030AF6C(); break;
        case 1: func_8030AFF0(); break;
        case 2: func_8030B110(); break;
        case 3: func_8030B1C8(); break;
        }

        func_802FA888(&D_80331B20, -1);
        if (o->oAction == -1 || (o->oMoveFlags & 0x00000203))
        {
            o->oUnk198 = 0;
            func_802FA078();
        }

        o->oGraphYOffset = 30.0f * o->header.gfx.scale[0];
    }
}

void BehBookendSpawnLoop(void)
{
    struct Object *sp1C;

    if (!(o->active & 0x0008))
    {
        if (o->oTimer > 40 && func_802F87E0(600.0f, 0x2000))
        {
            sp1C = SpawnObj(o, 0x59, beh_flying_bookend);
            if (sp1C != NULL)
            {
                sp1C->oAction = 3;
                PlaySound2(0x502C8081);
            }
            o->oTimer = 0;
        }
    }
}

void func_8030B464(void)
{
    s32 val04;

    if (!(o->active & 0x0008))
    {
        for (val04 = 0; val04 < 3; val04++)
        {
            spawn_obj_adv(val04, D_80331B30[val04].unk00, D_80331B30[val04].unk02, 0, o, 0x59, beh_book_switch);
        }

        o->oAction = 1;
    }
}

void func_8030B50C(void)
{
    if (o->oBookSwitchManagerUnkF8 == 0)
    {
        if (func_802F87E0(500.0f, 0x3000))
        {
            o->oBookSwitchManagerUnkF8 = 1;
        }
    }
    else if (o->oTimer > 60)
    {
        o->oAction = 2;
        o->oBookSwitchManagerUnkF8 = 0;
    }
}

void func_8030B5A4(void)
{
    if (!(o->active & 0x0008))
    {
        if (o->oBookSwitchManagerUnkF4 < 0)
        {
            if (o->oTimer > 30)
            {
                o->oBookSwitchManagerUnkF4 = o->oBookSwitchManagerUnkF8 = 0;
            }
            else if (o->oTimer > 10)
            {
                o->oBookSwitchManagerUnkF8 = 1;
            }
        }
        else
        {
            if (o->oBookSwitchManagerUnkF4 >= 3)
            {
                if (o->oTimer > 100)
                {
                    o->parentObj = func_8029F1E0(beh_tumbling_bookshelf);
                    o->parentObj->oAction = 1;
                    o->oPosX = o->parentObj->oPosX;
                    o->oAction = 3;
                }
                else if (o->oTimer == 30)
                {
                    func_80321228();
                }
            }
            else
            {
                o->oTimer = 0;
            }
        }
    }
    else
    {
        o->oAction = 4;
    }
}

void func_8030B728(void)
{
    if (o->oTimer > 85)
    {
        o->oAction = 4;
    }
    else
    {
        o->oForwardVel = o->parentObj->oPosX - o->oPosX;
        o->oPosX = o->parentObj->oPosX;
    }
}

void func_8030B794(void)
{
    if (o->oBookSwitchManagerUnkF4 >= 3)
    {
        DeactivateObject(o);
    }
    else
    {
        o->oAction = 0;
    }
}

void BehBookshelfThingLoop(void)
{
    switch (o->oAction)
    {
    case 0: func_8030B464(); break;
    case 2: func_8030B5A4(); break;
    case 1: func_8030B50C(); break;
    case 3: func_8030B728(); break;
    case 4: func_8030B794(); break;
    }
}

void BehBookSwitchLoop(void)
{
    s32 sp3C;
    struct Object *sp38;
    s16 sp36;
    s16 sp34;

    o->header.gfx.scale[0] = 2.0f;
    o->header.gfx.scale[1] = 0.9f;

    if (o->parentObj->oAction == 4)
    {
        DeactivateObject(o);
    }
    else
    {
        sp3C = func_802FA888(&D_80331B3C, o->oAction);
        if (o->parentObj->oBookSwitchManagerUnkF8 != 0 || o->oAction == 1)
        {
            if (o->oDistanceToMario < 100.0f)
            {
                func_8029FE58();
            }
            else
            {
                func_8029FE38();
            }

            o->oAction = 1;
            if (o->oBookSwitchUnkF4 == 0.0f)
            {
                PlaySound2(0x502C8081);
            }

            if (approach_f32_2(&o->oBookSwitchUnkF4, 50.0f, 20.0f))
            {
                if (o->parentObj->oBookSwitchManagerUnkF4 >= 0 && o->oTimer > 60)
                {
                    if (sp3C == 1 || sp3C == 2 || sp3C == 6)
                    {
                        o->oAction = 2;
                    }
                }
            }
            else
            {
                o->oTimer = 0;
            }
        }
        else
        {
            func_8029FE38();
            if (approach_f32_2(&o->oBookSwitchUnkF4, 0.0f, 20.0f))
            {
                if (o->oAction != 0)
                {
                    if (o->parentObj->oBookSwitchManagerUnkF4 == o->oBehParams2ndByte)
                    {
                        SetSound(0x806AA081, &D_803320E0);
                        o->parentObj->oBookSwitchManagerUnkF4 += 1;
                    }
                    else
                    {
                        sp36 = RandomU16() & 0x1;
                        sp34 = gMarioObject->oPosZ + 1.5f * gMarioStates[0].vel[2];

                        SetSound(0x700E0081, &D_803320E0);
                        if (sp34 > 0)
                        {
                            sp34 = 0;
                        }

                        sp38 = func_8029E230(
                            o,
                            0,
                            0x59,
                            beh_flying_bookend,
                            0x1FC * sp36 - 0x8CA,
                            890,
                            sp34,
                            0,
                            0x8000 * sp36 + 0x4000,
                            0);
                        
                        if (sp38 != NULL)
                        {
                            sp38->oAction = 3;
                        }

                        o->parentObj->oBookSwitchManagerUnkF4 = -1;
                    }

                    o->oAction = 0;
                }
            }
        }

        o->oPosX += o->parentObj->oForwardVel;
        o->oPosZ = o->oHomeZ - o->oBookSwitchUnkF4;
        func_802A3164(70.0f, 70.0f);
    }
}

void obj_spit_fire(s16 arg0, s16 arg1, s16 arg2, f32 arg3, s32 arg4, f32 arg5, f32 arg6, s16 arg7)
{
    struct Object *sp2C;

    sp2C = func_8029E880(1, arg0, arg1, arg2, arg3, o, arg4, beh_small_piranha_flame);
    if (sp2C != NULL)
    {
        sp2C->oSmallPiranhaFlameUnkF4 = arg5;
        sp2C->oSmallPiranhaFlameUnkF8 = arg6;
        sp2C->oSmallPiranhaFlameUnkFC = arg4;
        sp2C->oAnglePitch = arg7;
    }
}

#include "behaviors/fire_piranha_plant.c.inc"
#include "behaviors/fire_spitter.c.inc"

void BehSmallPiranhaFlameLoop(void)
{
    f32 sp2C;

    if ((u16)(o->oBehParams >> 16) == 0)
    {
        if (o->oTimer > 0)
        {
            DeactivateObject(o);
        }
        else
        {
            sp2C = RandomFloat() - 0.5f;
            o->header.gfx.scale[1] = o->header.gfx.scale[2] * (1.0f + 0.7f * sp2C);
            o->header.gfx.scale[0] = o->header.gfx.scale[2] * (0.9f - 0.5f * sp2C);

            o->oAnimState = RandomU16();
        }
    }
    else
    {
        MoveRelated();
        if (approach_f32_2(&o->oSmallPiranhaFlameUnkF4, o->oSmallPiranhaFlameUnkF8, 0.6f))
        {
            func_8029DE70(o->oAngleToMario, 0x200);
        }

        func_802F9148(o->oSmallPiranhaFlameUnkF4);
        MoveObj(-78);
        func_8029E73C(o, o->oSmallPiranhaFlameUnkFC, beh_small_piranha_flame, 0.4f * o->header.gfx.scale[0]);

        if (o->oTimer > o->oSmallPiranhaFlameUnk100)
        {
            func_8029E880(1, 0, o->oGraphYOffset, 0, o->header.gfx.scale[0], o, o->oSmallPiranhaFlameUnkFC, beh_flyguy_flame);
            o->oSmallPiranhaFlameUnk100 = random_linear_offset(8, 15);
            o->oTimer = 0;
        }

        func_802FA888(&D_80331B64, o->oAction);
        o->oSmallPiranhaFlameUnk104 += o->oSmallPiranhaFlameUnkF4;

        if (o->oSmallPiranhaFlameUnk104 > 1500.0f || (o->oMoveFlags & 0x00000278))
        {
            func_802FA078();
        }
    }

    o->oGraphYOffset = 15.0f * o->header.gfx.scale[1];
}

void BehFlyGuyFlameLoop(void)
{
    MoveObj2();

    if (approach_f32_2(&o->header.gfx.scale[0], 0.0f, 0.6f))
    {
        DeactivateObject(o);
    }

    ScaleObject(o->header.gfx.scale[0]);
}

s32 Geo18_8030D93C(s32 arg0, struct GraphNode *arg1, UNUSED void *arg2)
{
    struct Object *sp4;
    struct GraphNodeTranslationRotationOptionalDisplayList *sp0;

    if (arg0 == 1)
    {
        sp4 = (struct Object *)D_8032CFA0;
        sp0 = (struct GraphNodeTranslationRotationOptionalDisplayList *)arg1->next;

        sp0->translation[0] = sp4->OBJECT_FIELD_S16(0x49, 0);
        sp0->translation[1] = sp4->OBJECT_FIELD_S16(0x49, 1);
        sp0->translation[2] = sp4->OBJECT_FIELD_S16(0x4A, 0);
    }

    return 0;
}

s32 Geo18_8030D9AC(s32 arg0, struct GraphNode *arg1, UNUSED void *arg2)
{
    struct Object *sp4;
    struct GraphNodeScaleOptionalDisplayList *sp0;

    if (arg0 == 1)
    {
        sp4 = (struct Object *)D_8032CFA0;
        sp0 = (struct GraphNodeScaleOptionalDisplayList *)arg1->next;

        sp0->scale = sp4->OBJECT_FIELD_S16(0x4A, 1) / 1000.0f;
    }

    return 0;
}

void func_8030C914(void)
{
    s32 sp1C;

    sp1C = (s32)(o->oDistanceToMario / 10.0f);
    if (o->oTimer > sp1C && o->oDistanceToMario < 800.0f)
    {
        o->oSnufitUnk104 = approach_target_angle(o->oSnufitUnk104, 0, 1500);
        o->oSnufitUnk108 = approach_target_angle(o->oSnufitUnk108, 600, 15);

        if ((s16)o->oSnufitUnk104 == 0 && o->oSnufitUnk108 == 600)
        {
            o->oAction = 1;
            o->oSnufitUnk10C = 0;
        }
    }
    else
    {
        o->oSnufitUnk100 += 400;
    }
}

void func_8030CA38(void)
{
    o->oSnufitUnk104 = approach_target_angle(o->oSnufitUnk104, -0x8000, 3000);
    o->oSnufitUnk108 = approach_target_angle(o->oSnufitUnk108, 0xA7, 20);

    if ((u16)o->oSnufitUnk104 == 0x8000 && o->oSnufitUnk108 == 0xA7)
    {
        o->oAction = 0;
    }
    else if (o->oSnufitUnk10C < 3 && o->oTimer >= 3)
    {
        o->oSnufitUnk10C += 1;
        PlaySound2(0x504D0081);
        spawn_obj_adv(0, 0, -20, 40, o, 0xB4, beh_snufit_balls);
        o->oSnufitUnkF4 = -30;
        o->oTimer = 0;
    }
}

void BehSnufitLoop(void)
{
    if (!(o->active & 0x0008))
    {
        o->oUnk1C4 = 0x5072C081;
        if (o->oDistanceToMario < 800.0f)
        {
            func_802F9414(120.0f, 2000);

            if ((s16)o->oAnglePitch > 0x2000)
            {
                o->oAnglePitch = 0x2000;
            }
            else if ((s16)o->oAnglePitch < -0x2000)
            {
                o->oAnglePitch = -0x2000;
            }

            func_8029DE70(o->oAngleToMario, 2000);
        }
        else
        {
            func_802F95B0(0, 0x200);
            o->oAngleYaw += 200;
        }

        o->oFaceAnglePitch = o->oAnglePitch;

        switch (o->oAction)
        {
        case 0: func_8030C914(); break;
        case 1: func_8030CA38(); break;
        }

        o->oPosX = o->oHomeX + 100.0f * coss(o->oSnufitUnk100);
        o->oPosY = o->oHomeY + 8.0f * coss(4000 * gGlobalTimer);
        o->oPosZ = o->oHomeZ + 100.0f * sins(o->oSnufitUnk100);

        o->oSnufitUnk1AE = -0x20;
        o->oSnufitUnk1B0 = o->oSnufitUnkF4 + 180;
        o->oSnufitUnk1B2 = (s16)(o->oSnufitUnk108 + 666 + o->oSnufitUnk108 * coss(o->oSnufitUnk104));

        if (o->oSnufitUnk1B2 > 1000)
        {
            o->oSnufitUnkF8 = (o->oSnufitUnk1B2 - 1000) / 1000.0f + 1.0f;
            o->oSnufitUnk1B2 = 1000;
        }
        else
        {
            o->oSnufitUnkF8 = 1.0f;
        }

        ScaleObject(o->oSnufitUnkF8);
        func_802FA888(&D_80331B74, o->oAction);
    }
}

void BehSnufitBallsLoop(void)
{
    if ((o->active & 0x0008) || (o->oTimer != 0 && o->oDistanceToMario > 1500.0f))
    {
        DeactivateObject(o);
    }

    if (o->oGravity == 0.0f)
    {
        MoveRelated();

        func_802F9148(40.0f);
        if (func_802FA888(&D_80331B84, 1))
        {
            o->oAngleYaw += 0x8000;
            o->oForwardVel *= 0.05f;
            o->oVelY = 30.0f;
            o->oGravity = -4.0f;

            func_8029FE38();
        }
        else if (o->oAction == 1 || (o->oMoveFlags & 0x00000203))
        {
            o->oUnk1C4 = -1;
            func_802FA078();
        }

        MoveObj(78);
    }
    else
    {
        MoveObj2();
    }
}

#include "behaviors/horizontal_grindel.c.inc"
#include "behaviors/eyerok.c.inc"
#include "behaviors/klepto.c.inc"
#include "behaviors/bird.c.inc"
#include "behaviors/racing_penguin.c.inc"

void BehHauntedRoomCheckLoop(void)
{
    struct Object *val0C;
    s32 val08;
    s16 val06;

    if (o->oAction == 0)
    {
        if (!(o->active & 0x0008))
        {
            for (val08 = 0; val08 < 6; val08++)
            {
                val06 = D_80331C00[val08].unk02;

                val0C = spawn_obj_adv(val08 & 0x00000001, D_80331C00[val08].unk00, 0, val06, o, 60, beh_haunted_room_check_subobject);
                if (val0C != NULL)
                {
                    if (val06 > 0)
                    {
                        val0C->oFaceAngleYaw = 0x8000;
                    }
                }
            }

            o->oAction += 1;
        }
    }
    else if (o->active & 0x0008)
    {
        o->oAction = 0;
    }
}

void func_80311264(void)
{
    f32 val14;
    f32 val10;
    f32 val0C;
    f32 val08;
    f32 val04;
    f32 val00;

    if (o->oBehParams2ndByte != 0)
    {
        if (o->oFaceAnglePitch != 0)
        {
            o->oAngleVelPitch = approach_target_angle(o->oAngleVelPitch, -2000, 200);

            if (face_pitch_approach(0, -o->oAngleVelPitch))
            {
                PlaySound2(0x315B0081);
                func_802F8854(0);
                o->oAngleYaw = o->oFaceAngleYaw - 0x4000;

                func_802F8770(200.0f);
                func_802ADA94();
                func_802F8854(2);
            }

            o->oTimer = 0;
        }
        else
        {
            val14 = coss(o->oFaceAngleYaw);
            val10 = sins(o->oFaceAngleYaw);

            val0C = gMarioObject->oPosX - o->oPosX;
            val08 = gMarioObject->oPosZ - o->oPosZ;

            val04 = val0C * val14 + val08 * val10;
            val00 = val08 * val14 - val0C * val10;

            if (o->oTimer > 60 && (o->oDistanceToMario > 100.0f || gMarioState->action == ACT_SQUISHED))
            {
                if (gMarioObject->oPosY - o->oPosY < 200.0f &&
                    func_802A2E8C(val04) < 140.0f)
                {
                    if (val00 < 150.0f && val00 > -450.0f)
                    {
                        PlaySound2(0x315A0081);
                        o->oAction = 1;
                    }
                }
            }

            o->oAngleVelPitch = 0;
        }
    }
}

void func_80311520(void)
{
    if (o->oFaceAnglePitch != 0x4000)
    {
        o->oAngleVelPitch = approach_target_angle(o->oAngleVelPitch, 1000, 200);
        face_pitch_approach(0x4000, o->oAngleVelPitch);
    }
    else
    {
        if (o->oTimer > 60)
        {
            o->oAction = 0;
            o->oFaceAngleRoll = 0;
        }
        else if (o->oTimer > 30)
        {
            if (gGlobalTimer % 4 == 0)
            {
                PlaySound2(0x315B0081);
            }
            o->oFaceAngleRoll = 400 * (gGlobalTimer % 2) - 200;
        }

        o->oAngleVelPitch = 0;
    }
}

void BehHauntedRoomCheckSubobjectLoop(void)
{
    if (o->parentObj->oAction == 0)
    {
        DeactivateObject(o);
    }
    else
    {
        o->header.gfx.scale[1] = 1.1f;

        switch (o->oAction)
        {
        case 0: func_80311264(); break;
        case 1: func_80311520(); break;
        }

        load_object_collision_model();
    }
}

void func_803116F8(void)
{
    if (func_802F92EC(0, 25))
    {
        PlaySound2(0x30274081);
        func_802ADA94();
        func_8029FE58();

        o->oClamUnkF4 = 10;
        o->oTimer = 0;
    }
    else if (o->oTimer > 150 && o->oDistanceToMario < 500.0f)
    {
        PlaySound2(0x30264081);
        o->oAction = 1;
    }
    else if (o->oClamUnkF4 != 0)
    {
        o->oClamUnkF4 -= 1;
        func_802A1160(3.0f);
    }
}

void func_803117F4(void)
{
    s16 val06;
    s16 val04;
    s16 val02;

    if (o->oTimer > 150)
    {
        o->oAction = 0;
    }
    else if (func_802F8680() &&func_802F92EC(1, 8))
    {
        for (val06 = -0x2000; val06 < 0x2000; val06 += 0x555)
        {
            val04 = (s16)(100.0f * sins(val06));
            val02 = (s16)(100.0f * coss(val06));

            spawn_obj_adv(0, val04, 30, val02, o, 0xA8, beh_bubble_maybe);
        }
    }
    else if (check_anim_frame(30))
    {
        func_8029FE38();
    }
}

void BehClamShellLoop(void)
{
    o->header.gfx.scale[1] = 1.5f;

    switch (o->oAction)
    {
    case 0: func_803116F8(); break;
    case 1: func_803117F4(); break;
    }

    func_802FA888(&D_80331C18, o->oAction);
}

#include "behaviors/skeeter.c.inc"
#include "behaviors/swing_platform.c.inc"
#include "behaviors/donut_platform.c.inc"
#include "behaviors/ddd_pole.c.inc"
#include "behaviors/reds_star_marker.c.inc"
#include "behaviors/triplet_butterfly.c.inc"

void func_80312F8C(void)
{
    f32 sp24;

    sp24 = obj_lateral_dist_to_home();
    treat_far_home_as_mario(2000.0f);
    o->oAnimState = 0;

    o->oBubbaUnk1AC = func_802F9100(sp24);

    approach_f32_2(&o->oBubbaUnkF4, 5.0f, 0.5f);

    if (o->oBubbaUnkFC != 0)
    {
        if (abs_angle_diff(o->oAngleYaw, o->oBubbaUnk1AE) < 800)
        {
            o->oBubbaUnkFC = 0;
        }
    }
    else
    {
        if (o->oDistanceToMario >= 25000.0f)
        {
            o->oBubbaUnk1AE = o->oAngleToMario;
            o->oBubbaUnkF8 = random_linear_offset(20, 30);
        }

        if ((o->oBubbaUnkFC = o->oMoveFlags & 0x00000200) != 0)
        {
            o->oBubbaUnk1AE = func_802A2AC0();
        }
        else if (o->oTimer > 30 && o->oDistanceToMario < 2000.0f)
        {
            o->oAction = 1;
        }
        else if (o->oBubbaUnkF8 != 0)
        {
            o->oBubbaUnkF8 -= 1;
        }
        else
        {
            o->oBubbaUnk1AE = random_fixed_turn(0x2000);
            o->oBubbaUnkF8 = random_linear_offset(100, 100);
        }
    }
}

void func_80313170(void)
{
    s16 val06;
    s16 val04;

    treat_far_home_as_mario(2500.0f);
    if (o->oDistanceToMario > 2500.0f)
    {
        o->oAction = 0;
    }
    else if (o->oBubbaUnk100 != 0)
    {
        if (--o->oBubbaUnk100 == 0)
        {
            PlaySound2(0x50734081);
            o->oAction = 0;
        }
        else if (o->oBubbaUnk100 < 15)
        {
            o->oAnimState = 1;
        }
        else if (o->oBubbaUnk100 == 20)
        {
            val06 = 10000 - (s16)(20.0f * (find_water_level(o->oPosX, o->oPosZ) - o->oPosY));
            o->oBubbaUnk1AC -= val06;
            o->oAnglePitch = o->oBubbaUnk1AC;
            o->oBubbaUnkF4 = 40.0f;
            func_802F9148(o->oBubbaUnkF4);
            o->oAnimState = 0;;
        }
        else
        {
            o->oBubbaUnk1AE = o->oAngleToMario;
            o->oBubbaUnk1AC = o->oBubbaUnk104;

            func_8029DE70(o->oBubbaUnk1AE, 400);
            func_802F95B0(o->oBubbaUnk1AC, 400);
        }
    }
    else
    {
        if (abs_angle_diff(gMarioObject->oFaceAngleYaw, o->oAngleToMario) < 0x3000)
        {
            val04 = 0x4000 - atan2s(800.0f, o->oDistanceToMario - 800.0f);
            if ((s16)(o->oAngleYaw - o->oAngleToMario) < 0)
            {
                val04 = -val04;
            }

            o->oBubbaUnk1AE = o->oAngleToMario + val04;;
        }
        else
        {
            o->oBubbaUnk1AE = o->oAngleToMario;
        }

        o->oBubbaUnk1AC = o->oBubbaUnk104;

        if (func_802F87E0(500.0f, 3000) &&
            abs_angle_diff(o->oBubbaUnk1AC, o->oAnglePitch) < 3000)
        {
            o->oBubbaUnk100 = 30;
            o->oBubbaUnkF4 = 0;
            o->oAnimState = 1;
        }
        else
        {
            approach_f32_2(&o->oBubbaUnkF4, 20.0f, 0.5f);
        }
    }
}

void BehBubbaLoop(void)
{
    UNUSED s32 unused;
    struct Object *sp38;
    s16 sp36;

    o->oUnk190 &= ~0x00002000;
    o->oBubbaUnk104 = func_802F9414(120.0f, 0);

    if (abs_angle_diff(o->oAngleToMario, o->oAngleYaw) < 0x1000 &&
        abs_angle_diff(o->oBubbaUnk104 + 0x800, o->oAnglePitch) < 0x2000)
    {
        if (o->oAnimState != 0 && o->oDistanceToMario < 250.0f)
        {
            o->oUnk190 |= 0x00002000;
        }

        o->unk200 = 100.0f;
    }
    else
    {
        o->unk200 = 150.0f;
    }

    MoveRelated();

    switch (o->oAction)
    {
    case 0: func_80312F8C(); break;
    case 1: func_80313170(); break;
    }

    if (o->oMoveFlags & 0x00000078)
    {
        if (o->oMoveFlags & 0x00000008)
        {
            sp38 = SpawnObj(o, 0xA7, beh_water_splash);
            if (sp38 != NULL)
            {
                func_8029EC88(sp38, 3.0f);
            }

            o->oBubbaUnk108 = o->oVelY;
            o->oBubbaUnk10C = 0.0f;;
        }
        else
        {
            approach_f32_2(&o->oBubbaUnk108, 0.0f, 4.0f);
            if ((o->oBubbaUnk10C -= o->oBubbaUnk108) > 1.0f)
            {
                sp36 = RandomU16();
                o->oBubbaUnk10C -= 1.0f;
                spawn_obj_adv(0, 150.0f * coss(sp36), 0x64, 150.0f * sins(sp36), o, 0xA4, beh_small_particle_snow);
            }
        }

        func_802F9780(&o->oBubbaUnk1B0, &o->oAnglePitch, o->oBubbaUnk1AC, 0.05f, 10, 50, 2000);
        func_802F9780(&o->oBubbaUnk1B2, &o->oAngleYaw, o->oBubbaUnk1AE, 0.05f, 10, 50, 2000);
        func_802F9148(o->oBubbaUnkF4);
    }
    else
    {
        o->oBubbaUnkF4 = sqrtf(o->oForwardVel * o->oForwardVel + o->oVelY * o->oVelY);
        o->oAnglePitch = func_802F86C0();
        face_pitch_approach(o->oAnglePitch, 400);
        o->oBubbaUnk1B0 = 0;
    }

    face_pitch_approach(o->oAnglePitch, 400);
    func_802FA888(&D_80331D2C, o->oAction);

    MoveObj(78);

    o->oFloorHeight += 150.0f;
    if (o->oPosY < o->oFloorHeight)
    {
        o->oPosY = o->oFloorHeight;
    }
}
