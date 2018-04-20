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
        if (m->peakHeight - m->pos[1] > 1150.0f)
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

    //! Never true
    if (m->actionState == ACT_GROUND_POUND)
        damageHeight = 600.0f;
    else
        damageHeight = 1150.0f;

#pragma GCC diagnostic pop

    if (m->action != ACT_TWIRLING && m->floor->type != SURFACE_LAVA)
    {
        if (m->vel[1] < -55.0f)
        {
            if (fallHeight > 3000.0f)
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
    u32 val = m->area->unk02 & 0x0007;
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
            floor->normal[1] >= 0.8660254f)
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

        m->slideVelX += 1.2f * sins(pushAngle);
        m->slideVelZ += 1.2f * coss(pushAngle);

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
    s16 targetYawVel = -(s16) (m->controller->stickX * (m->forwardVel / 4.0f));

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

void update_flying_pitch(struct MarioState *m)
{
    s16 targetPitchVel = -(s16) (m->controller->stickY * (m->forwardVel / 5.0f));

    if (targetPitchVel > 0)
    {
        if (m->angleVel[0] < 0)
        {
            m->angleVel[0] += 0x40;
            if (m->angleVel[0] > 0x20)
                m->angleVel[0] = 0x20;
        }
        else
        {
            m->angleVel[0] = func_8037A860(m->angleVel[0], targetPitchVel, 0x20, 0x40);
        }
    }
    else if (targetPitchVel < 0)
    {
        if (m->angleVel[0] > 0)
        {
            m->angleVel[0] -= 0x40;
            if (m->angleVel[0] < -0x20)
                m->angleVel[0] = -0x20;
        }
        else
        {
            m->angleVel[0] = func_8037A860(m->angleVel[0], targetPitchVel, 0x40, 0x20);
        }
    }
    else
    {
        m->angleVel[0] = func_8037A860(m->angleVel[0], 0, 0x40, 0x40);
    }
}

void update_flying(struct MarioState *m)
{
    UNUSED u32 unused;

    update_flying_pitch(m);
    update_flying_yaw(m);

    m->forwardVel -= 2.0f * ((f32) m->faceAngle[0] / 0x4000) + 0.1f;
    m->forwardVel -= 0.5f * (1.0f - coss(m->angleVel[1]));

    if (m->forwardVel < 0.0f)
        m->forwardVel = 0.0f;

    if (m->forwardVel > 16.0f)
        m->faceAngle[0] += (m->forwardVel - 32.0f) * 6.0f;
    else if (m->forwardVel > 4.0f)
        m->faceAngle[0] += (m->forwardVel - 32.0f) * 10.0f;
    else
        m->faceAngle[0] -= 0x400;

    m->faceAngle[0] += m->angleVel[0];

    if (m->faceAngle[0] > 0x2AAA)
        m->faceAngle[0] = 0x2AAA;
    if (m->faceAngle[0] < -0x2AAA)
        m->faceAngle[0] = -0x2AAA;

    m->vel[0] = m->forwardVel * coss(m->faceAngle[0]) * sins(m->faceAngle[1]);
    m->vel[1] = m->forwardVel * sins(m->faceAngle[0]);
    m->vel[2] = m->forwardVel * coss(m->faceAngle[0]) * coss(m->faceAngle[1]);

    m->slideVelX = m->vel[0];
    m->slideVelZ = m->vel[2];
}

u32 func_8026AF50(struct MarioState *m, u32 landAction, s32 animation, u32 stepArg)
{
    u32 stepResult;

    update_air_without_turn(m);

    stepResult = func_80256940(m, stepArg);
    switch (stepResult)
    {
    case AIR_STEP_NONE:
        func_802507E8(m, animation);
        break;

    case AIR_STEP_LANDED:
        if (!check_fall_damage_or_get_stuck(m, ACT_UNKNOWN_060))
            set_mario_action(m, landAction, 0);
        break;

    case AIR_STEP_HIT_WALL:
        func_802507E8(m, animation);

        if (m->forwardVel > 16.0f)
        {
            func_8025509C(m, 0);
            m->faceAngle[1] += 0x8000;

            if (m->wall != NULL)
            {
                set_mario_action(m, ACT_AIR_HIT_WALL, 0);
            }
            else
            {
                if (m->vel[1] > 0.0f)
                    m->vel[1] = 0.0f;

                if (m->forwardVel >= 38.0f)
                {
                    m->unk08 |= 0x00000002;
                    set_mario_action(m, ACT_UNKNOWN_0B0, 0);
                }
                else
                {
                    if (m->forwardVel > 8.0f)
                        func_802514DC(m, -8.0f);
                    return set_mario_action(m, ACT_UNKNOWN_0B6, 0);
                }
            }
        }
        else
        {
            func_802514DC(m, 0.0f);
        }
        break;

    case AIR_STEP_GRABBED_LEDGE:
        func_802507E8(m, 0x0033);
        drop_and_set_mario_action(m, ACT_LEDGE_GRAB, 0);
        break;

    case AIR_STEP_GRABBED_CEILING:
        set_mario_action(m, ACT_START_HANGING, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return stepResult;
}

u32 act_jump(struct MarioState *m)
{
    if (check_kick_or_dive_in_air(m))
        return 1;

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0);
    func_8026AF50(m, ACT_JUMP_LAND, 0x004D,
        AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG);
    return 0;
}

u32 act_double_jump(struct MarioState *m)
{
    s32 animation;

    if (m->vel[1] >= 0.0f)
        animation = 0x0050;
    else
        animation = 0x004C;

    if (check_kick_or_dive_in_air(m))
        return 1;

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0x24038081);
    func_8026AF50(m, ACT_DOUBLE_JUMP_LAND, animation,
        AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG);
    return 0;
}

u32 act_triple_jump(struct MarioState *m)
{
    if (D_8032CE34)
        return set_mario_action(m, ACT_SPECIAL_TRIPLE_JUMP, 0);

    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0x24048081);
    func_8026AF50(m, ACT_TRIPLE_JUMP_LAND, 0x00C1, 0);
    func_80269AD0(m, 2, 8, 20);
    return 0;
}

u32 act_backflip(struct MarioState *m)
{
    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0x24008081);
    func_8026AF50(m, ACT_BACKFLIP_LAND, 0x0004, 0);
    func_80269AD0(m, 2, 3, 17);
    return 0;
}

u32 act_freefall(struct MarioState *m)
{
    s32 animation;

    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    switch (m->actionArg)
    {
    case 0: animation = 0x0056; break;
    case 1: animation = 0x0090; break;
    case 2: animation = 0x0053; break;
    }

    func_8026AF50(m, ACT_FREEFALL_LAND, animation, AIR_STEP_CHECK_LEDGE_GRAB);
    return 0;
}

u32 func_8026B5C8(struct MarioState *m)
{
    if (m->marioObj->interactStatus & 0x00000008)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if ((m->input & INPUT_B_PRESSED) && !(m->heldObj->unk190 & 0x00000010))
        return set_mario_action(m, ACT_UNKNOWN_0AB, 0);

    if (m->input & INPUT_Z_PRESSED)
        return drop_and_set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0);
    func_8026AF50(m, ACT_UNKNOWN_074, 0x0041, AIR_STEP_CHECK_LEDGE_GRAB);
    return 0;
}

u32 func_8026B6C4(struct MarioState *m)
{
    s32 animation;
    if (m->actionArg == 0)
        animation = 0x0043;
    else
        animation = 0x0044;

    if (m->marioObj->interactStatus & 0x00000008)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if ((m->input & INPUT_B_PRESSED) && !(m->heldObj->unk190 & 0x00000010))
        return set_mario_action(m, ACT_UNKNOWN_0AB, 0);

    if (m->input & INPUT_Z_PRESSED)
        return drop_and_set_mario_action(m, ACT_GROUND_POUND, 0);

    func_8026AF50(m, ACT_UNKNOWN_075, animation, AIR_STEP_CHECK_LEDGE_GRAB);
    return 0;
}

u32 func_8026B7D0(struct MarioState *m)
{
    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0);

    if (func_8026AF50(m, ACT_SIDE_FLIP_LAND, 0x00BF, AIR_STEP_CHECK_LEDGE_GRAB) !=
        AIR_STEP_GRABBED_LEDGE)
    {
        m->marioObj->unk1A[1] += 0x8000;
    }

    if (m->marioObj->unk40 == 6)
        SetSound(0x045A8081, &m->marioObj->unk54);
    return 0;
}

u32 func_8026B8DC(struct MarioState *m)
{
    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80250FBC(m);
    func_8026AF50(m, ACT_JUMP_LAND, 0x00CB, AIR_STEP_CHECK_LEDGE_GRAB);
    return 0;
}

u32 func_8026B988(struct MarioState *m)
{
    s32 animation;
    if (m->marioObj->unk110 == 0)
        animation = 0x0013;
    else
        animation = 0x0014;

    func_80251410(m, 0x04008081, 0x24048081);

    if (m->floor->type == SURFACE_0038 && m->actionState == 0)
    {
        SetSound(0x240C8081, &m->marioObj->unk54);
        m->actionState = 1;
    }

    func_8026AF50(m, ACT_LONG_JUMP_LAND, animation, AIR_STEP_CHECK_LEDGE_GRAB);
    return 0;
}

u32 func_8026BA50(struct MarioState *m)
{
    func_80251410(m, 0x04008081, 0);
    func_802507E8(m, 0x004A);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_RIDING_SHELL_GROUND, 1);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 0.0f);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    m->marioObj->unk20[1] += 42.0f;
    return 0;
}

u32 func_8026BB44(struct MarioState *m)
{
    s16 startTwirlYaw = m->twirlYaw;
    s16 yawVelTarget;

    if (m->input & INPUT_A_DOWN)
        yawVelTarget = 0x2000;
    else
        yawVelTarget = 0x1800;

    m->angleVel[1] = func_8037A860(m->angleVel[1], yawVelTarget, 0x200, 0x200);
    m->twirlYaw += m->angleVel[1];

    func_802507E8(m, m->actionArg == 0 ? 0x0095 : 0x0094);
    if (func_802507AC(m))
        m->actionArg = 1;

    if (startTwirlYaw > m->twirlYaw)
        SetSound(0x04388081, &m->marioObj->unk54);

    update_lava_boost_or_twirling(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_TWIRL_LAND, 0);
        break;

    case AIR_STEP_HIT_WALL:
        func_8025509C(m, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    m->marioObj->unk1A[1] += m->twirlYaw;
    return 0;
}

u32 func_8026BCF0(struct MarioState *m)
{
    if (m->actionArg == 0)
        func_80251410(m, 0x04358081, 0x24038081);
    else
        func_80251410(m, 0x04008081, 0);

    func_802507E8(m, 0x0088);
    if (func_8024CADC(m))
    {
        func_8024C4CC(m);
        m->unk98->unk0A = 1;
        if (m->action != ACT_DIVE)
            return 1;
    }

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_NONE:
        if (m->vel[1] < 0.0f && m->faceAngle[0] > -0x2AAA)
        {
            m->faceAngle[0] -= 0x200;
            if (m->faceAngle[0] < -0x2AAA)
                m->faceAngle[0] = -0x2AAA;
        }
        m->marioObj->unk1A[0] = -m->faceAngle[0];
        break;

    case AIR_STEP_LANDED:
        if (should_get_stuck_in_ground(m) && m->faceAngle[0] == -0x2AAA)
        {
            SetSound(0x240B8081, &m->marioObj->unk54);
            m->unk08 |= 0x00010000;
            drop_and_set_mario_action(m, ACT_HEAD_STUCK_IN_GROUND, 0);
        }
        else if (!check_fall_damage(m, ACT_UNKNOWN_061))
        {
            if (m->heldObj == NULL)
                set_mario_action(m, ACT_DIVE_SLIDE, 0);
            else
                set_mario_action(m, ACT_UNKNOWN_185, 0);
        }
        m->faceAngle[0] = 0;
        break;

    case AIR_STEP_HIT_WALL:
        func_8025509C(m, 1);
        m->faceAngle[0] = 0;

        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        m->unk08 |= 0x00000002;
        drop_and_set_mario_action(m, ACT_UNKNOWN_0B0, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return 0;
}

u32 func_8026BFC8(struct MarioState *m)
{
    if (++m->actionTimer == 4)
        func_8024C5E0(m);

    func_80250F50(m, 0x24078081, MARIO_UNKNOWN_17);
    func_802507E8(m, 0x0052);
    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (!check_fall_damage_or_get_stuck(m, ACT_UNKNOWN_060))
            m->action = ACT_UNKNOWN_036;
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 0.0f);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return 0;
}

u32 func_8026C0E0(struct MarioState *m)
{
    if (m->forwardVel < 15.0f)
        func_802514DC(m, 15.0f);

    func_80251410(m, 0x04328081, 0);
    func_802507E8(m, 0x004D);

    switch (func_80256940(m, AIR_STEP_CHECK_LEDGE_GRAB))
    {
    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_JUMP_LAND, 0);
        func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 15.0f);
        break;

    case AIR_STEP_GRABBED_LEDGE:
        set_mario_action(m, ACT_LEDGE_GRAB, 0);
        func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return 0;
}

u32 func_8026C23C(struct MarioState *m)
{
    if (m->marioObj->interactStatus & 0x00000008)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (m->forwardVel < 15.0f)
        func_802514DC(m, 15.0f);

    func_80251410(m, 0x04328081, 0);
    func_802507E8(m, 0x0041);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_UNKNOWN_074, 0);
        func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 15.0f);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return 0;
}

u32 func_8026C384(struct MarioState *m)
{
    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    func_80251410(m, 0x04008081, 0);
    func_802514DC(m, 0.98f * m->forwardVel);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (!check_fall_damage_or_get_stuck(m, ACT_UNKNOWN_060))
        {
            m->faceAngle[0] = 0;
            set_mario_action(m, m->forwardVel < 0.0f ? ACT_BEGIN_SLIDING : ACT_JUMP_LAND, 0);
        }
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 0.0f);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    func_802507E8(m, 0x004D);
    m->marioObj->unk1A[1] = m->marioObj->unk110;
    return 0;
}

u32 func_8026C500(struct MarioState *m)
{
    u32 stepResult;
    f32 yOffset;

    func_80250F50(m, 0x04358081, MARIO_UNKNOWN_16);

    if (m->actionState == 0)
    {
        if (m->actionTimer < 10)
        {
            yOffset = 20 - 2 * m->actionTimer;
            if (m->pos[1] + yOffset + 160.0f < m->ceilHeight)
            {
                m->pos[1] += yOffset;
                m->peakHeight = m->pos[1];
                Vec3f_Copy(m->marioObj->unk20, m->pos);
            }
        }

        m->vel[1] = -50.0f;
        func_802514DC(m, 0.0f);

        func_802507E8(m, m->actionArg == 0 ? 0x003C : 0x003B);
        if (m->actionTimer == 0)
            SetSound(0x04378081, &m->marioObj->unk54);

        m->actionTimer += 1;
        if (m->actionTimer >= m->marioObj->unk3C->unk08 + 4)
        {
            SetSound(0x24228081, &m->marioObj->unk54);
            m->actionState = 1;
        }
    }
    else
    {
        func_802507E8(m, 0x003D);

        stepResult = func_80256940(m, 0);
        if (stepResult == AIR_STEP_LANDED)
        {
            if (should_get_stuck_in_ground(m))
            {
                SetSound(0x240B8081, &m->marioObj->unk54);
                m->unk08 |= 0x00010000;
                set_mario_action(m, ACT_BUTT_STUCK_IN_GROUND, 0);
            }
            else
            {
                func_80251348(m, 0x04608081);
                if (!check_fall_damage(m, ACT_UNKNOWN_060))
                {
                    m->unk08 |= 0x00010010;
                    set_mario_action(m, ACT_GROUND_POUND_LAND, 0);
                }
            }
            func_8027EFE0(2);
        }
        else if (stepResult == AIR_STEP_HIT_WALL)
        {
            func_802514DC(m, -16.0f);
            if (m->vel[1] > 0.0f)
                m->vel[1] = 0.0f;

            m->unk08 |= 0x00000002;
            set_mario_action(m, ACT_UNKNOWN_0B0, 0);
        }
    }

    return 0;
}

u32 func_8026C810(struct MarioState *m)
{
    func_80251410(m, 0x04008081, m->actionArg == 0 ? 0 : -1);
    func_802514DC(m, m->forwardVel);

    if (func_80256940(m, 0) == AIR_STEP_LANDED)
    {
        func_80251280(m, 0x04088081);
        set_mario_action(m, ACT_BURNING_GROUND, 0);
    }

    func_802507E8(m, m->actionArg == 0 ? 0x004D : 0x0029);
    m->unk08 |= 0x00000800;
    SetSound(0x14100001, &m->marioObj->unk54);

    m->marioObj->unk110 += 3;

    m->health -= 10;
    if (m->health < 0x100)
        m->health = 0xFF;
    return 0;
}

u32 func_8026C954(struct MarioState *m)
{
    func_802514DC(m, m->forwardVel);

    if (func_80256940(m, 0) == AIR_STEP_LANDED)
    {
        func_80251280(m, 0x04088081);
        set_mario_action(m, ACT_BURNING_GROUND, 0);
    }

    func_802507E8(m, 0x0056);
    m->unk08 |= 0x00000800;
    m->marioObj->unk110 += 3;

    m->health -= 10;
    if (m->health < 0x100)
        m->health = 0xFF;
    return 0;
}

u32 func_8026CA2C(struct MarioState *m)
{
    f32 minSpeed;

    if (m->actionTimer == 0)
    {
        switch (m->actionArg)
        {
        case 0:
            m->vel[1] = 45.0f;
            minSpeed = 32.0f;
            break;

        case 1:
            m->vel[1] = 60.0f;
            minSpeed = 36.0f;
            break;

        case 2:
            m->vel[1] = 100.0f;
            minSpeed = 48.0f;
            break;
        }

        SetSound(minSpeed < 40.0f ? 0x306C4081 : 0x306D4081, &m->marioObj->unk54);

        if (m->forwardVel < minSpeed)
            func_802514DC(m, minSpeed);

        m->actionTimer = 1;
    }

    func_80251410(m, 0x04008081, 0);
    func_802507E8(m, 0x0088);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (m->actionArg < 2)
        {
            set_mario_action(m, ACT_UNKNOWN_0AE, m->actionArg + 1);
        }
        else
        {
            m->heldObj->interactStatus = 0x00400000;
            m->heldObj = NULL;
            set_mario_action(m, ACT_STOMACH_SLIDE, 0);
        }
        m->unk08 |= 0x00010000;
        break;

    case AIR_STEP_HIT_WALL:
        func_8025509C(m, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    m->marioObj->unk1A[0] = func_8037A9A8(m->forwardVel, -m->vel[1]);
    return 0;
}

u32 func_8026CCB4(struct MarioState *m, u32 landAction, u32 hardFallAction, s32 animation, f32 speed)
{
    u32 stepResult;

    func_802514DC(m, speed);

    stepResult = func_80256940(m, 0);
    switch (stepResult)
    {
    case AIR_STEP_NONE:
        func_802507E8(m, animation);
        break;

    case AIR_STEP_LANDED:
        if (!check_fall_damage_or_get_stuck(m, hardFallAction))
            set_mario_action(m, landAction, m->actionArg);
        break;

    case AIR_STEP_HIT_WALL:
        func_802507E8(m, 0x0002);
        func_8025509C(m, 0);

        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        func_802514DC(m, -speed);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return stepResult;
}

u32 func_8026CDFC(struct MarioState *m)
{
    if ((m->input & INPUT_A_PRESSED) && m->wallKickTimer != 0 && m->prevAction == ACT_AIR_HIT_WALL)
    {
        m->faceAngle[1] += 0x8000;
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0);
    }

    return 0;
}

u32 func_8026CE88(struct MarioState *m)
{
    if (func_8026CDFC(m))
        return 1;

    func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);
    func_8026CCB4(m, ACT_UNKNOWN_062, ACT_UNKNOWN_060, 0x0002, -16.0f);
    return 0;
}

u32 func_8026CF08(struct MarioState *m)
{
    if (func_8026CDFC(m))
        return 1;

    func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);
    func_8026CCB4(m, ACT_UNKNOWN_063, ACT_UNKNOWN_061, 0x002D, 16.0f);
    return 0;
}

u32 func_8026CF88(struct MarioState *m)
{
    func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);
    func_8026CCB4(m, ACT_UNKNOWN_060, ACT_UNKNOWN_060, 0x0002, -16.0f);
    return 0;
}

u32 func_8026CFEC(struct MarioState *m)
{
    func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);
    func_8026CCB4(m, ACT_UNKNOWN_061, ACT_UNKNOWN_061, 0x002D, 16.0f);
    return 0;
}

u32 func_8026D050(struct MarioState *m)
{
    u32 landAction;
    if (m->actionArg != 0)
        landAction = ACT_UNKNOWN_060;
    else
        landAction = ACT_UNKNOWN_062;

    func_80250F50(m, 0x2410C081, MARIO_UNKNOWN_17);
    
    func_8026CCB4(m, landAction, ACT_UNKNOWN_060, 0x0002, m->forwardVel);
    m->forwardVel *= 0.98f;
    return 0;
}

u32 func_8026D0F8(struct MarioState *m)
{
    s16 pitch;

    u32 landAction;
    if (m->actionArg != 0)
        landAction = ACT_UNKNOWN_061;
    else
        landAction = ACT_UNKNOWN_063;

    func_80250F50(m, 0x2410C081, MARIO_UNKNOWN_17);
    
    if (func_8026CCB4(m, landAction, ACT_UNKNOWN_061, 0x002D, m->forwardVel) == AIR_STEP_NONE)
    {
        pitch = func_8037A9A8(m->forwardVel, -m->vel[1]);
        if (pitch > 0x1800)
            pitch = 0x1800;

        m->marioObj->unk1A[0] = pitch + 0x1800;
    }
    
    m->forwardVel *= 0.98f;
    return 0;
}

u32 func_8026D1EC(struct MarioState *m)
{
    if (func_8026CDFC(m))
        return 1;

    func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);

    func_8026CCB4(m, ACT_FREEFALL_LAND, ACT_UNKNOWN_060, 0x0056, m->forwardVel);
    return 0;
}

u32 func_8026D26C(struct MarioState *m)
{
    if (m->actionState == 0)
    {
        if (m->forwardVel > -60.0f)
            m->forwardVel -= 6.0f;
        else
            m->actionState = 1;
    }
    else
    {
        if (m->forwardVel < -16.0f)
            m->forwardVel += 0.8f;

        if (m->vel[1] < 0.0f && m->unkC4 < 4.0f)
            m->unkC4 += 0.05f;
    }

    if (++m->actionTimer == 20)
        func_8024C788(m, 50.0f);

    func_802514DC(m, m->forwardVel);
    func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);
    func_802507E8(m, 0x0002);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_KNOCKED_ONTO_BACK, 0);
        break;

    case AIR_STEP_HIT_WALL:
        func_802507E8(m, 0x002D);
        func_8025509C(m, 0);

        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        func_802514DC(m, -m->forwardVel);
        break;
    }

    return 0;
}

u32 func_8026D498(struct MarioState *m)
{
    if (m->heldObj != NULL)
        func_8024C520(m);

    if (++m->actionTimer <= 2)
    {
        if (m->input & INPUT_A_PRESSED)
        {
            m->vel[1] = 52.0f;
            m->faceAngle[1] += 0x8000;
            return set_mario_action(m, ACT_WALL_KICK_AIR, 0);
        }
    }
    else if (m->forwardVel >= 38.0f)
    {
        m->wallKickTimer = 5;
        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        m->unk08 |= 0x00000002;
        return set_mario_action(m, ACT_UNKNOWN_0B0, 0);
    }
    else
    {
        m->wallKickTimer = 5;
        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        if (m->forwardVel > 8.0f)
            func_802514DC(m, -8.0f);
        return set_mario_action(m, ACT_UNKNOWN_0B6, 0);
    }

    func_802507E8(m, 0x00CC);
}

u32 func_8026D664(struct MarioState *m)
{
    if (m->actionState == 0)
    {
        m->vel[1] = 30.0f;
        m->actionState = 1;
    }

    func_80251410(m, 0x04008081, 0);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_NONE:
        if (m->actionState == 1)
        {
            if (func_802507E8(m, 0x006F) == 4)
                SetSound(0x04378081, &m->marioObj->unk54);
        }
        else
        {
            func_802507E8(m, 0x0056);
        }
        break;

    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_FREEFALL_LAND_STOP, 0);
        func_80251280(m, 0x04088081);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 0.0f);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    if (m->actionState == 1 && func_802507AC(m))
        m->actionState = 2;
    return 0;
}

u32 func_8026D804(struct MarioState *m)
{
    if (m->actionState == 0)
    {
        m->vel[1] = 30.0f;
        m->actionState = 1;
    }

    func_80251410(m, 0x04008081, 0);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_NONE:
        if (m->actionState == 1)
        {
            if (func_802507E8(m, 0x0070) == 4)
                SetSound(0x04378081, &m->marioObj->unk54);
        }
        else
        {
            func_802507E8(m, 0x0056);
        }
        break;

    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_FREEFALL_LAND_STOP, 0);
        func_80251280(m, 0x04088081);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 0.0f);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    if (m->actionState == 1 && m->marioObj->unk40 == 2)
        m->actionState = 2;
    return 0;
}

u32 func_8026D9A8(struct MarioState *m)
{
    if (++m->actionTimer > 30 && m->pos[1] - m->floorHeight > 500.0f)
        return set_mario_action(m, ACT_FREEFALL, 1);

    update_air_with_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (m->actionState == 0 && m->vel[1] < 0.0f && m->floor->normal[1] >= 0.9848077f)
        {
            m->vel[1] = -m->vel[1] / 2.0f;
            m->actionState = 1;
        }
        else
        {
            set_mario_action(m, ACT_BUTT_SLIDE, 0);
        }
        func_80251280(m, 0x04088081);
        break;

    case AIR_STEP_HIT_WALL:
        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;
        m->unk08 |= 0x00000002;
        set_mario_action(m, ACT_UNKNOWN_0B0, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    func_802507E8(m, 0x0091);
    return 0;
}

u32 func_8026DB98(struct MarioState *m)
{
    if (m->marioObj->interactStatus & 0x00000008)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_0A1, 1);

    if (++m->actionTimer > 30 && m->pos[1] - m->floorHeight > 500.0f)
        return set_mario_action(m, ACT_UNKNOWN_0A1, 1);

    update_air_with_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (m->actionState == 0 && m->vel[1] < 0.0f && m->floor->normal[1] >= 0.9848077f)
        {
            m->vel[1] = -m->vel[1] / 2.0f;
            m->actionState = 1;
        }
        else
        {
            set_mario_action(m, ACT_UNKNOWN_054, 0);
        }
        func_80251280(m, 0x04088081);
        break;

    case AIR_STEP_HIT_WALL:
        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        func_8024C520(m);
        m->unk08 |= 0x00000002;
        set_mario_action(m, ACT_UNKNOWN_0B0, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    func_802507E8(m, 0x0045);
    return 0;
}

u32 func_8026DDC4(struct MarioState *m)
{
    func_80250F50(m, 0x2414A081, MARIO_UNKNOWN_17);

    if (!(m->input & INPUT_NONZERO_ANALOG))
        m->forwardVel = func_8037A8B4(m->forwardVel, 0.0f, 0.35f, 0.35f);

    update_lava_boost_or_twirling(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (m->floor->type == SURFACE_LAVA)
        {
            m->actionState = 0;
            if (!(m->flags & MARIO_METAL_CAP))
                m->hurtCounter += (m->flags & MARIO_CAP_ON_HEAD) ? 12 : 18;
            m->vel[1] = 84.0f;
            SetSound(0x2414A081, &m->marioObj->unk54);
        }
        else
        {
            func_80251348(m, 0x04188081);
            if (m->actionState < 2 && m->vel[1] < 0.0f)
            {
                m->vel[1] = -m->vel[1] * 0.4f;
                func_802514DC(m, m->forwardVel * 0.5f);
                m->actionState += 1;
            }
            else
            {
                set_mario_action(m, ACT_LAVA_BOOST_LAND, 0);
            }
        }
        break;

    case AIR_STEP_HIT_WALL:
        func_8025509C(m, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    func_802507E8(m, 0x0029);
    if ((m->area->unk02 & 0x0007) != 2 && !(m->flags & MARIO_METAL_CAP) && m->vel[1] > 0.0f)
    {
        m->unk08 |= 0x00000800;
        if (m->actionState == 0)
            SetSound(0x14100001, &m->marioObj->unk54);
    }

    if (m->health < 0x100)
        func_8024A860(m, 0x12);

    m->unk98->unk05 = 8;
    return 0;
}

u32 func_8026E0AC(struct MarioState *m)
{
    if (m->actionState == 0 && m->actionTimer == 0)
    {
        func_80251410(m, 0x04008081, 0x24038081);
        func_802507E8(m, 0x008C);
    }

    if (++m->actionTimer > 30 && m->pos[1] - m->floorHeight > 500.0f)
        return set_mario_action(m, ACT_FREEFALL, 2);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_NONE:
        if (m->actionState == 0)
        {
            m->marioObj->unk1A[0] = func_8037A9A8(m->forwardVel, -m->vel[1]);
            if (m->marioObj->unk1A[0] > 0x1800)
                m->marioObj->unk1A[0] = 0x1800;
        }
        break;

    case AIR_STEP_LANDED:
        if (m->actionState == 0 && m->vel[1] < 0.0f)
        {
            m->vel[1] = -m->vel[1] / 2.0f;
            m->actionState = 1;
            m->actionTimer = 0;
        }
        else
        {
            set_mario_action(m, ACT_SLIDE_KICK_SLIDE, 0);
        }
        func_80251280(m, 0x04088081);
        break;

    case AIR_STEP_HIT_WALL:
        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        m->unk08 |= 0x00000002;

        set_mario_action(m, ACT_UNKNOWN_0B0, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return 0;
}

u32 func_8026E320(struct MarioState *m)
{
    s32 animFrame;

    if (m->actionState == 0)
    {
        func_80250F50(m, 0x241F8081, MARIO_UNKNOWN_16);
        m->marioObj->unk38 = -1;
        func_802507E8(m, 0x004F);
        m->actionState = 1;
    }

    animFrame = m->marioObj->unk40;
    if (animFrame == 0)
        m->unk98->unk0B = 0x86;
    if (animFrame >= 0 && animFrame < 8)
        m->flags |= MARIO_UNKNOWN_21;

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (!check_fall_damage_or_get_stuck(m, ACT_UNKNOWN_060))
            set_mario_action(m, ACT_FREEFALL_LAND, 0);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, 0.0f);
        break;
    }

    return 0;
}

u32 func_8026E478(struct MarioState *m)
{
    if (m->area->unk24[0] != 3)
        m->unk94->unk1E = 2;

    func_802514DC(m, m->forwardVel);

    func_80250F50(m, 0x24048081, MARIO_UNKNOWN_17);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_NONE:
        func_802507E8(m, 0x0015);
        m->faceAngle[0] = func_8037A9A8(m->forwardVel, m->vel[1]);
        m->marioObj->unk1A[0] = -m->faceAngle[0];
        break;

    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_DIVE_SLIDE, 0);
        m->faceAngle[0] = 0;
        func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, -16.0f);

        m->faceAngle[0] = 0;
        if (m->vel[1] > 0.0f)
            m->vel[1] = 0.0f;

        m->unk08 |= 0x00000002;
        set_mario_action(m, ACT_UNKNOWN_0B0, 0);
        func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    if ((m->flags & MARIO_WING_CAP) && m->vel[1] < 0.0f)
        set_mario_action(m, ACT_FLYING, 0);
    
    if ((m->forwardVel -= 0.05) < 10.0f)
        func_802514DC(m, 10.0f);

    if (m->vel[1] > 0.0f)
        m->unk08 |= 0x00000001;
    return 0;
}

u32 func_8026E710(struct MarioState *m)
{
    s16 startPitch = m->faceAngle[0];

    if (m->input & INPUT_Z_PRESSED)
    {
        if (m->area->unk24[0] == 3)
            func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        return set_mario_action(m, ACT_GROUND_POUND, 1);
    }

    if (!(m->flags & MARIO_WING_CAP))
    {
        if (m->area->unk24[0] == 3)
            func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->area->unk24[0] != 3)
        func_80285BD8(m->area->unk24, 3, 1);

    if (m->actionState == 0)
    {
        if (m->actionArg == 0)
        {
            func_802507E8(m, 0x005B);
        }
        else
        {
            func_802507E8(m, 0x00CF);
            if (m->marioObj->unk40 == 1)
                SetSound(0x04378081, &m->marioObj->unk54);
        }

        if (func_80250770(m))
        {
            if (m->actionArg == 2)
            {
                func_8024980C(0);
                m->actionArg = 1;
            }

            func_802507E8(m, 0x002A);
            m->actionState = 1;
        }
    }

    update_flying(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_NONE:
        m->marioObj->unk1A[0] = -m->faceAngle[0];
        m->marioObj->unk1A[2] = m->faceAngle[2];
        m->actionTimer = 0;
        break;

    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_DIVE_SLIDE, 0);

        func_802507E8(m, 0x0088);
        func_80250AAC(m, 7);

        m->faceAngle[0] = 0;
        func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        break;

    case AIR_STEP_HIT_WALL:
        if (m->wall != NULL)
        {
            func_802514DC(m, -16.0f);
            m->faceAngle[0] = 0;

            if (m->vel[1] > 0.0f)
                m->vel[1] = 0.0f;

            SetSound((m->flags & MARIO_METAL_CAP) ? 0x04428081 : 0x0445A081, &m->marioObj->unk54);

            m->unk08 |= 0x00000002;
            set_mario_action(m, ACT_UNKNOWN_0B0, 0);
            func_80285BD8(m->area->unk24, m->area->unk24[1], 1);
        }
        else {
            if (m->actionTimer++ == 0)
                SetSound(0x0444C081, &m->marioObj->unk54);

            if (m->actionTimer == 30)
                m->actionTimer = 0;

            m->faceAngle[0] -= 0x200;
            if (m->faceAngle[0] < -0x2AAA)
                m->faceAngle[0] = -0x2AAA;

            m->marioObj->unk1A[0] = -m->faceAngle[0];
            m->marioObj->unk1A[2] = m->faceAngle[2];
        }
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    if (m->faceAngle[0] > 0x800 && m->forwardVel >= 48.0f)
        m->unk08 |= 0x00000001;

    if (startPitch <= 0 && m->faceAngle[0] > 0 && m->forwardVel >= 48.0f)
        SetSound(0x04568081, &m->marioObj->unk54);

    SetSound(0x14170001, &m->marioObj->unk54);
    func_80251048(m);
    return 0;
}

u32 func_8026EC2C(struct MarioState *m)
{
    if (!(m->input & INPUT_A_DOWN) || (m->marioObj->interactStatus & 0x00000080))
    {
        m->usedObj->interactStatus = 0;
        m->usedObj->unk110 = D_8032C694;

        func_80250F50(m, 0x24058081, MARIO_UNKNOWN_17);
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    m->pos[0] = m->usedObj->pos[0];
    m->pos[1] = m->usedObj->pos[1] - 92.5f;
    m->pos[2] = m->usedObj->pos[2];

    m->faceAngle[1] = 0x4000 - m->usedObj->angle[1];

    if (m->actionState == 0)
    {
        func_802507E8(m, 0x0035);
        if (func_80250770(m))
        {
            func_802507E8(m, 0x002B);
            m->actionState = 1;
        }
    }

    Vec3f_Set(m->vel, 0.0f, 0.0f, 0.0f);
    Vec3f_Set(m->marioObj->unk20, m->pos[0], m->pos[1], m->pos[2]);
    Vec3s_Set(m->marioObj->unk1A, 0, 0x4000 - m->faceAngle[1], 0);
    return 0;
}

u32 func_8026EDC0(struct MarioState *m)
{
    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0x24048081);
    if (m->actionState == 0)
    {
        func_802507E8(m, 0x00D0);

        if (m->marioObj->unk40 == 7)
            SetSound(0x04378081, &m->marioObj->unk54);
    
        if (func_802507AC(m))
        {
            func_802507E8(m, 0x006F);
            m->actionState = 1;
        }
    }

    if (m->actionState == 1 && m->marioObj->unk40 == 1)
        SetSound(0x04378081, &m->marioObj->unk54);

    if (m->vel[1] < 4.0f)
    {
        if (m->area->unk24[0] != 3)
            func_80285BD8(m->area->unk24, 3, 1);
        
        if (m->forwardVel < 32.0f)
            func_802514DC(m, 32.0f);
        
        set_mario_action(m, ACT_FLYING, 1);
    }

    if (m->actionTimer++ == 10 && m->area->unk24[0] != 3)
        func_80285BD8(m->area->unk24, 3, 1);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (!check_fall_damage_or_get_stuck(m, ACT_UNKNOWN_060))
            set_mario_action(m, ACT_DOUBLE_JUMP_LAND, 0);
        break;

    case AIR_STEP_HIT_WALL:
        func_8025509C(m, 0);
        break;

    case AIR_STEP_HIT_LAVA_WALL:
        lava_boost_on_wall(m);
        break;
    }

    return 0;
}

u32 func_8026F0A8(struct MarioState *m)
{
    func_80250FBC(m);
    func_8026AF50(m, ACT_FREEFALL_LAND, 0x000A, AIR_STEP_CHECK_LEDGE_GRAB);
    return 0;
}

/** 8026F0F4(J) */
u32 func_8026F0F4(struct MarioState *m)
{
    s16 intendedDyaw = m->intendedYaw - m->faceAngle[1];
    f32 intendedMag = m->intendedMag / 32.0f;

    func_80250F50(m, 0x240C8081, MARIO_UNKNOWN_17);
    if (m->actionState == 0)
    {
        func_802507E8(m, 0x00CF);
        if (m->marioObj->unk40 == 1)
            SetSound(0x04378081, &m->marioObj->unk54);

        if (func_802507AC(m))
            m->actionState = 1;
    }
    else
    {
        func_802507E8(m, 0x0015);
    }

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        set_mario_action(m, ACT_DIVE_SLIDE, 0);
        break;

    case AIR_STEP_HIT_WALL:
        func_802514DC(m, -16.0f);
        break;
    }

    m->marioObj->unk1A[0] = (s16) (6144.0f * intendedMag * coss(intendedDyaw));
    m->marioObj->unk1A[2] = (s16) (-4096.0f * intendedMag * sins(intendedDyaw));
    return 0;
}

u32 func_8026F2D4(struct MarioState *m)
{
    if (m->input & INPUT_B_PRESSED)
        return set_mario_action(m, ACT_DIVE, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    func_80251410(m, 0x04008081, 0x24048081);

    update_air_without_turn(m);

    switch (func_80256940(m, 0))
    {
    case AIR_STEP_LANDED:
        if (m->actionState++ == 0)
            m->vel[1] = 42.0f;
        else
            set_mario_action(m, ACT_FREEFALL_LAND_STOP, 0);
        func_80251280(m, 0x04088081);
        break;

    case AIR_STEP_HIT_WALL:
        func_8025509C(m, 1);
        break;
    }

    if (m->actionState == 0 || m->vel[1] > 0.0f)
    {
        if (func_802507E8(m, 0x006F) == 0)
            SetSound(0x04378081, &m->marioObj->unk54);
    }
    else
    {
        func_802507E8(m, 0x0056);
    }

    m->unk08 |= 0x00000008;
    return 0;
}

u32 func_8026F4AC(struct MarioState *m)
{
    if (m->pos[1] < m->waterLevel - 100)
        return func_8025325C(m);

    if (m->input & INPUT_SQUISHED)
        return drop_and_set_mario_action(m, ACT_SQUISHED, 0);

    if (m->floor->type == SURFACE_0038 && (m->action & ACT_FLAG_UNKNOWN_24))
        return drop_and_set_mario_action(m, ACT_VERTICAL_WIND, 0);

    m->quicksandDepth = 0.0f;
    return 0;
}

u32 func_8026F598(struct MarioState *m)
{
    u32 cancel;

    if (func_8026F4AC(m))
        return 1;

    func_80269B50(m);

    switch (m->action)
    {
    case ACT_JUMP:                     cancel = act_jump(m);              break;
    case ACT_DOUBLE_JUMP:              cancel = act_double_jump(m);       break;
    case ACT_FREEFALL:                 cancel = act_freefall(m);          break;
    case ACT_UNKNOWN_0A0:              cancel = func_8026B5C8(m);         break;
    case ACT_UNKNOWN_0A1:              cancel = func_8026B6C4(m);         break;
    case ACT_SIDE_FLIP:                cancel = func_8026B7D0(m);         break;
    case ACT_WALL_KICK_AIR:            cancel = func_8026B8DC(m);         break;
    case ACT_TWIRLING:                 cancel = func_8026BB44(m);         break;
    case ACT_WATER_JUMP:               cancel = func_8026C0E0(m);         break;
    case ACT_UNKNOWN_0A3:              cancel = func_8026C23C(m);         break;
    case ACT_STEEP_JUMP:               cancel = func_8026C384(m);         break;
    case ACT_BURNING_JUMP:             cancel = func_8026C810(m);         break;
    case ACT_BURNING_FALL:             cancel = func_8026C954(m);         break;
    case ACT_TRIPLE_JUMP:              cancel = act_triple_jump(m);       break;
    case ACT_BACKFLIP:                 cancel = act_backflip(m);          break;
    case ACT_LONG_JUMP:                cancel = func_8026B988(m);         break;
    case ACT_RIDING_SHELL_JUMP:
    case ACT_RIDING_SHELL_FALL:        cancel = func_8026BA50(m);         break;
    case ACT_DIVE:                     cancel = func_8026BCF0(m);         break;
    case ACT_UNKNOWN_0AB:              cancel = func_8026BFC8(m);         break;
    case ACT_UNKNOWN_0B0:              cancel = func_8026CE88(m);         break;
    case ACT_UNKNOWN_0B1:              cancel = func_8026CF08(m);         break;
    case ACT_UNKNOWN_0B2:              cancel = func_8026CFEC(m);         break;
    case ACT_KNOCKED_ONTO_BACK:        cancel = func_8026CF88(m);         break;
    case ACT_UNKNOWN_0B6:              cancel = func_8026D1EC(m);         break;
    case ACT_AIR_HIT_WALL:             cancel = func_8026D498(m);         break;
    case ACT_FORWARD_ROLLOUT:          cancel = func_8026D664(m);         break;
    case ACT_SHOT_FROM_CANNON:         cancel = func_8026E478(m);         break;
    case ACT_BUTT_SLIDE_AIR:           cancel = func_8026D9A8(m);         break;
    case ACT_UNKNOWN_0A2:              cancel = func_8026DB98(m);         break;
    case ACT_LAVA_BOOST:               cancel = func_8026DDC4(m);         break;
    case ACT_GETTING_BLOWN:            cancel = func_8026D26C(m);         break;
    case ACT_BACKWARD_ROLLOUT:         cancel = func_8026D804(m);         break;
    case ACT_UNKNOWN_0AE:              cancel = func_8026CA2C(m);         break;
    case ACT_SPECIAL_TRIPLE_JUMP:      cancel = func_8026F2D4(m);         break;
    case ACT_GROUND_POUND:             cancel = func_8026C500(m);         break;
    case ACT_THROWN:                   cancel = func_8026D0F8(m);         break;
    case ACT_HEAVED:                   cancel = func_8026D050(m);         break;
    case ACT_FLYING_TRIPLE_JUMP:       cancel = func_8026EDC0(m);         break;
    case ACT_SLIDE_KICK:               cancel = func_8026E0AC(m);         break;
    case ACT_JUMP_KICK:                cancel = func_8026E320(m);         break;
    case ACT_FLYING:                   cancel = func_8026E710(m);         break;
    case ACT_RIDING_HOOT:              cancel = func_8026EC2C(m);         break;
    case ACT_TOP_OF_POLE_JUMP:         cancel = func_8026F0A8(m);         break;
    case ACT_VERTICAL_WIND:            cancel = func_8026F0F4(m);         break;
    }

    return cancel;
}
