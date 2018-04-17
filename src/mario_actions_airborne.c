#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"

void func_80269AD0(struct MarioState *m, s16 arg1, s16 arg2, s16 arg3)
{
    s32 animFrame = m->marioObj->unk40;
    if (animFrame == arg1 || animFrame == arg2 || animFrame == arg3)
        SetSound(0x04378081, &m->marioObj->unk54);
}

void func_80269B50(struct MarioState *m)
{
    u32 action = m->action;
    if (!(action & ACT_FLAG_UNKNOWN_17) &&
        action != ACT_TWIRLING &&
        action != ACT_FLYING &&
        !(m->flags & MARIO_UNKNOWN_18))
    {
        if (m->peakHeight - m->pos[1] > D_80335A60)
        {
            SetSound(0x2410C081, &m->marioObj->unk54);
            m->flags |= MARIO_UNKNOWN_18;
        }
    }
}

u32 lava_boost_on_wall(struct MarioState *m)
{
    m->faceAngle[1] = func_8037A9A8(m->wall->normal[2], m->wall->normal[0]);

    if (m->forwardVel < 24.0f)
       m->forwardVel = 24.0f;

    if (!(m->flags & MARIO_METAL_CAP))
        m->hurtCounter += (m->flags & MARIO_CAP_ON_HEAD) ? 12 : 18;

    SetSound(0x2414A081, &m->marioObj->unk54);
    func_80251F74(m);
    return drop_and_set_mario_action(m, ACT_LAVA_BOOST, 1);
}

u32 check_fall_damage(struct MarioState *m, u32 hardFallAction)
{
    f32 fallHeight;
    f32 damageHeight;

    fallHeight = m->peakHeight - m->pos[1];

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"

    //! Compares action to animation
    if (m->unk18 == ACT_GROUND_POUND)
        damageHeight = 600.0f;
    else
        damageHeight = D_80335A64;

#pragma GCC diagnostic pop

    if (m->action != ACT_TWIRLING && m->floor->type != SURFACE_LAVA)
    {
        if (m->vel[1] < -55.0f)
        {
            if (fallHeight > D_80335A68)
            {
                m->hurtCounter += (m->flags & MARIO_CAP_ON_HEAD) ? 16 : 24;
                func_8027EFE0(9);
                SetSound(0x240AFF81, &m->marioObj->unk54);
                return drop_and_set_mario_action(m, hardFallAction, 4);
            }
            else if (fallHeight > damageHeight && !func_802519A8(m))
            {
                m->hurtCounter += (m->flags & MARIO_CAP_ON_HEAD) ? 8 : 12;
                m->squishTimer = 30;
                func_8027EFE0(9);
                SetSound(0x240AFF81, &m->marioObj->unk54);
            }
        }
    }

    return 0;
}

u32 check_kick_or_dive_in_air(struct MarioState *m)
{
    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, m->forwardVel > 28.0f ? ACT_DIVE : ACT_JUMP_KICK, 0);
    return 0;
}

u32 should_get_stuck_in_ground(struct MarioState *m)
{
    u32 val = m->area->v02 & 0x0007;
    struct Surface *floor = m->floor;
    s32 flags = floor->flags;
    s32 type = floor->type;

    if (floor != NULL &&
        (val == 2 || val == 3) &&
        type != SURFACE_LAVA &&
        type != SURFACE_0030 &&
        !(type >= SURFACE_0035 && type <= SURFACE_0037))
    {
        if (!(flags & 0x01) &&
            m->peakHeight - m->pos[1] > 1000.0f &&
            floor->normal[1] >= D_80335A6C)
        {
            return 1;
        }
    }

    return 0;
}

u32 check_fall_damage_or_get_stuck(struct MarioState *m, u32 hardFallAction)
{
    if (should_get_stuck_in_ground(m))
    {
        SetSound(0x240B8081, &m->marioObj->unk54);
        m->unk08 |= 0x00010000;
        drop_and_set_mario_action(m, ACT_FEET_STUCK_IN_GROUND, 0);
        return 1;
    }

    return check_fall_damage(m, hardFallAction);
}

u32 func_8026A120(struct MarioState *m)
{
    struct Surface *floor;
    f32 speed;
    s16 pushAngle;

    floor = m->floor;

    if (floor->type == SURFACE_002C)
    {
        pushAngle = floor->unk02 << 8;
        m->slideVelX += D_80335A70 * sins(pushAngle);
        m->slideVelZ += D_80335A74 * coss(pushAngle);

        speed = sqrtf(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);

        if (speed > 48.0f)
        {
            m->slideVelX = m->slideVelX * 48.0f / speed;
            m->slideVelZ = m->slideVelZ * 48.0f / speed;
            speed = 32.0f; //! This was meant to be 48?
        }
        else if (speed > 32.0f)
        {
            speed = 32.0f;
        }

        m->vel[0] = m->slideVelX;
        m->vel[2] = m->slideVelZ;
        m->slideYaw = func_8037A9A8(m->slideVelZ, m->slideVelX);
        m->forwardVel = coss(m->faceAngle[1] - m->slideYaw) * speed;

        SetSound(0x40108001, &m->marioObj->unk54);
        return 1;
    }

    return 0;
}

void update_air_with_turn(struct MarioState *m)
{
    f32 dragThreshold;
    s16 intendedDyaw;
    f32 intendedMag;

    if (!func_8026A120(m))
    {
        dragThreshold = m->action == ACT_LONG_JUMP ? 48.0f : 32.0f;
        m->forwardVel = func_8037A8B4(m->forwardVel, 0.0f, 0.35f, 0.35f);

        if (m->input & INPUT_NONZERO_ANALOG)
        {
            intendedDyaw = m->intendedYaw - m->faceAngle[1];
            intendedMag = m->intendedMag / 32.0f;

            m->forwardVel += 1.5f * coss(intendedDyaw) * intendedMag;
            m->faceAngle[1] += 512.0f * sins(intendedDyaw) * intendedMag;
        }

        //! Uncapped air speed. Net positive when moving forward.
        if (m->forwardVel > dragThreshold)
            m->forwardVel -= 1.0f;
        if (m->forwardVel < -16.0f)
            m->forwardVel += 2.0f;

        m->vel[0] = m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
        m->vel[2] = m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);
    }
}

void update_air_without_turn(struct MarioState *m)
{
    f32 sidewaysSpeed = 0.0f;
    f32 dragThreshold;
    s16 intendedDyaw;
    f32 intendedMag;

    if (!func_8026A120(m))
    {
        dragThreshold = m->action == ACT_LONG_JUMP ? 48.0f : 32.0f;
        m->forwardVel = func_8037A8B4(m->forwardVel, 0.0f, 0.35f, 0.35f);

        if (m->input & INPUT_NONZERO_ANALOG)
        {
            intendedDyaw = m->intendedYaw - m->faceAngle[1];
            intendedMag = m->intendedMag / 32.0f;

            m->forwardVel += intendedMag * coss(intendedDyaw) * 1.5f;
            sidewaysSpeed = intendedMag * sins(intendedDyaw) * 10.0f;
        }

        //! Uncapped air speed. Net positive when moving forward.
        if (m->forwardVel > dragThreshold)
            m->forwardVel -= 1.0f;
        if (m->forwardVel < -16.0f)
            m->forwardVel += 2.0f;

        m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
        m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);

        m->slideVelX += sidewaysSpeed * sins(m->faceAngle[1] + 0x4000);
        m->slideVelZ += sidewaysSpeed * coss(m->faceAngle[1] + 0x4000);

        m->vel[0] = m->slideVelX;
        m->vel[2] = m->slideVelZ;
    }
}

void update_lava_boost_or_twirling(struct MarioState *m)
{
    s16 intendedDyaw;
    f32 intendedMag;

    if (m->input & INPUT_NONZERO_ANALOG)
    {
        intendedDyaw = m->intendedYaw - m->faceAngle[1];
        intendedMag = m->intendedMag / 32.0f;

        m->forwardVel += coss(intendedDyaw) * intendedMag;
        m->faceAngle[1] += sins(intendedDyaw) * intendedMag * 1024.0f;

        if (m->forwardVel < 0.0f)
        {
            m->faceAngle[1] += 0x8000;
            m->forwardVel *= -1.0f;
        }

        if (m->forwardVel > 32.0f)
            m->forwardVel -= 2.0f;
    }

    m->vel[0] = m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
    m->vel[2] = m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);
}

void update_flying_yaw(struct MarioState *m)
{
    s16 targetYawVel;

    targetYawVel = -(s16) (m->controller->stickX * (m->forwardVel / 4.0f));

    if (targetYawVel > 0)
    {
        if (m->angleVel[1] < 0)
        {
            m->angleVel[1] += 0x40;
            if (m->angleVel[1] > 0x10)
                m->angleVel[1] = 0x10;
        }
        else
        {
            m->angleVel[1] = func_8037A860(m->angleVel[1], targetYawVel, 0x10, 0x20);
        }
    }
    else if (targetYawVel < 0)
    {
        if (m->angleVel[1] > 0)
        {
            m->angleVel[1] -= 0x40;
            if (m->angleVel[1] < -0x10)
                m->angleVel[1] = -0x10;
        }
        else
        {
            m->angleVel[1] = func_8037A860(m->angleVel[1], targetYawVel, 0x20, 0x10);
        }
    }
    else
    {
        m->angleVel[1] = func_8037A860(m->angleVel[1], 0, 0x40, 0x40);
    }

    m->faceAngle[1] += m->angleVel[1];
    m->faceAngle[2] = 20 * -m->angleVel[1];
}
