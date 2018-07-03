#include <ultra64.h>

#include "sm64.h"
#include "mario_actions_object.h"
#include "types.h"
#include "mario_step.h"
#include "mario.h"
#include "audio_interface_2.h"
#include "interaction.h"
#include "audio_defines.h"
#include "math_util.h"

/**
 * Function declarations.
 */
void func_80274940(struct MarioState *, s32, u32);
s32  func_802749A0(struct MarioState *);
s32  act_punching(struct MarioState *);
s32  func_80274EFC(struct MarioState *);
s32  func_8027508C(struct MarioState *);
s32  func_80275158(struct MarioState *);
s32  act_throwing(struct MarioState *);
s32  func_80275350(struct MarioState *);
s32  func_80275444(struct MarioState *);
s32  func_80275510(struct MarioState *);
s32  act_holding_bowser(struct MarioState *);
s32  act_releasing_bowser(struct MarioState *);
s32  func_8027595C(struct MarioState *);
s32  func_80275A30(struct MarioState *);

/**
 * Used by act_punching() to determine Mario's forward velocity during each
 * animation frame.
 */
static s8 sPunchingForwardVelocities[8] = {0, 1, 1, 2, 3, 5, 7, 10};


void func_80274940(struct MarioState *m, s32 animation, u32 action)
{
    stationary_ground_step(m);
    func_802507E8(m, animation);
    if (func_80250770(m))
        set_mario_action(m, action, 0);
}

// This handles the punch-punch-kick sequence.
s32 func_802749A0(struct MarioState *m)
{
    u32 sp24, sp20;
    s32 sp1c;  // probably animation frame?

    if (m->action & ACT_FLAG_UNKNOWN_10)
        sp24 = ACT_WALKING, sp20 = ACT_CROUCH_SLIDE;
    else
        sp24 = ACT_IDLE,    sp20 = ACT_CROUCHING;

    switch (m->actionArg)
    {
        case 0:
            SetSound(SOUND_MARIO_YAH2, &m->marioObj->header.gfx.unk54);
            // Fall-through:
        case 1:
            func_802507E8(m, 103);
            if (func_802507AC(m))
                m->actionArg = 2;
            else
                m->actionArg = 1;

            if (m->marioObj->header.gfx.unk38.animFrame >= 2)
            {
                if (mario_check_object_grab(m))
                    return 1;
                m->flags |= MARIO_UNKNOWN_20;
            }
            if (m->actionArg == 2)
                m->unk98->unk0B = 4;

            break;
        case 2:
            func_802507E8(m, 105);

            if (m->marioObj->header.gfx.unk38.animFrame <= 0)
                m->flags |= MARIO_UNKNOWN_20;

            if (m->input & INPUT_B_PRESSED)
                m->actionArg = 3;

            if (func_80250770(m))
                set_mario_action(m, sp24, 0);

            break;
        case 3:
            SetSound(SOUND_MARIO_WAH4, &m->marioObj->header.gfx.unk54);
            // Fall-through:
        case 4:
            func_802507E8(m, 104);
            if (func_802507AC(m))
                m->actionArg = 5;
            else
                m->actionArg = 4;

            if (m->marioObj->header.gfx.unk38.animFrame > 0)
                m->flags |= MARIO_UNKNOWN_20;

            if (m->actionArg == 5)
                m->unk98->unk0B = 68;

            break;
        case 5:
            func_802507E8(m, 106);
            if (m->marioObj->header.gfx.unk38.animFrame <= 0)
                m->flags |= MARIO_UNKNOWN_20;

            if (m->input & INPUT_B_PRESSED)
                m->actionArg = 6;

            if (func_80250770(m))
                set_mario_action(m, sp24, 0);

            break;
        case 6:
            func_80251218(m, SOUND_MARIO_HOO6, 1);
            sp1c = func_802507E8(m, 102);
            if (sp1c == 0)
                m->unk98->unk0B = 134;

            if (sp1c >= 0 && sp1c < 8)
                m->flags |= MARIO_UNKNOWN_21;

            if (func_80250770(m))
                set_mario_action(m, sp24, 0);

            break;
        case 9:
            func_80251218(m, SOUND_MARIO_HOO6, 1);
            func_802507E8(m, 113);
            sp1c = m->marioObj->header.gfx.unk38.animFrame;
            if (sp1c >= 2 && sp1c < 8)
                m->flags |= MARIO_UNKNOWN_22;

            if (func_80250770(m))
                set_mario_action(m, sp20, 0);

            break;
    }
    return 0;
}

s32 act_punching(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED |
                    INPUT_OFF_FLOOR      | INPUT_ABOVE_SLIDE))
        return func_80252FEC(m);

    if (m->actionState == 0 && m->input & INPUT_A_DOWN)
        return set_mario_action(m, ACT_JUMP_KICK, 0);

    m->actionState = 1;
    if (m->actionArg == 0)
        m->actionTimer = 7;

    mario_set_forward_vel(m, sPunchingForwardVelocities[m->actionTimer]);
    if (m->actionTimer > 0)
        m->actionTimer--;

    func_802749A0(m);
    perform_ground_step(m);
    return 0;
}

s32 func_80274EFC(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (m->actionState == 0 && func_80250770(m))
    {
        mario_grab_used_object(m);
        func_80250F50(m, SOUND_MARIO_HRMM, MARIO_UNKNOWN_17);
        m->actionState = 1;
    }
    if (m->actionState == 1)
    {
        if (m->heldObj->oUnk190 & 0x4)
        {
            m->unk98->unk0A = 2;
            func_802507E8(m, 89);
            if (func_80250770(m))
                set_mario_action(m, ACT_UNKNOWN_008, 0);
        }
        else
        {
            m->unk98->unk0A = 1;
            func_802507E8(m, 107);
            if (func_80250770(m))
                set_mario_action(m, ACT_UNKNOWN_007, 0);
        }
    }
    stationary_ground_step(m);
    return 0;
}

s32 func_8027508C(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_ABOVE_SLIDE)
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);

    func_80274940(m, 139, ACT_UNKNOWN_007);
    return 0;
}

s32 func_80275158(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (++m->actionTimer == 8)   // increment occurs before comparison
        mario_drop_held_object(m);

    func_80274940(m, 110, ACT_IDLE);
    return 0;
}

s32 act_throwing(struct MarioState *m)
{
    if (m->heldObj && m->heldObj->oUnk190 & 0x10)
        return set_mario_action(m, ACT_UNKNOWN_187, 0);

    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (++m->actionTimer == 7)   // increment occurs before comparison
    {
        mario_throw_held_object(m);
        func_80250F50(m, SOUND_MARIO_WAH2, MARIO_UNKNOWN_17);
        func_80250F50(m, SOUND_ACTION_UNKNOWN435, MARIO_UNKNOWN_16);
    }
    func_80274940(m, 101, ACT_IDLE);
    return 0;
}

s32 func_80275350(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (++m->actionTimer == 13)   // increment occurs before comparison
    {
        mario_drop_held_object(m);
        func_80250F50(m, SOUND_MARIO_WAH2, MARIO_UNKNOWN_17);
        func_80250F50(m, SOUND_ACTION_UNKNOWN435, MARIO_UNKNOWN_16);
    }
    func_80274940(m, 185, ACT_IDLE);
    return 0;
}

s32 func_80275444(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_ABOVE_SLIDE)
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);

    func_80274940(m, 90, ACT_IDLE);
    return 0;
}

s32 func_80275510(struct MarioState *m)
{
    if (m->actionState == 0)
    {
        m->actionState = 1;
        m->angleVel[1] = 0;
        m->unk98->unk0A = 3;
        mario_grab_used_object(m);
        SetSound(SOUND_MARIO_HRMM, &m->marioObj->header.gfx.unk54);
    }
    func_802507E8(m, 181);
    if (func_80250770(m))
        set_mario_action(m, ACT_HOLDING_BOWSER, 0);

    stationary_ground_step(m);
    return 0;
}

s32 act_holding_bowser(struct MarioState *m)
{
    s16 sp26;

    if (m->input & INPUT_B_PRESSED)
    {
        SetSound(SOUND_MARIO_HEREWEGO, &m->marioObj->header.gfx.unk54);
        return set_mario_action(m, ACT_RELEASING_BOWSER, 0);
    }
    if (m->angleVel[1] == 0)
    {
        if (120 < m->actionTimer++)   // increment occurs after comparison
            return set_mario_action(m, ACT_RELEASING_BOWSER, 1);

        func_802507E8(m, 184);
    }
    else
    {
        m->actionTimer = 0;
        func_802507E8(m, 182);
    }
    if (m->intendedMag > 20.0f)
    {
        if (m->actionArg == 0)
        {
            m->actionArg = 1;
            m->twirlYaw = m->intendedYaw;
        }
        else
        {
            sp26 = ((s16) (m->intendedYaw - m->twirlYaw)) / 128;
            if (sp26 < -128)
                sp26 = -128;
            if (sp26 >= 129)
                sp26 = 128;

            m->twirlYaw = m->intendedYaw;
            m->angleVel[1] += sp26;
            if (m->angleVel[1] >= 4097)
                m->angleVel[1] = 4096;
            if (m->angleVel[1] < -4096)
                m->angleVel[1] = -4096;
        }
    }
    else
    {
        m->actionArg = 0;
        m->angleVel[1] = approach_s32(m->angleVel[1], 0, 64, 64);
    }
    sp26 = m->faceAngle[1];
    m->faceAngle[1] += m->angleVel[1];
    if (m->angleVel[1] < -255 && sp26 < m->faceAngle[1])
        SetSound(SOUND_OBJECT_BOWSERSPINNING, &m->marioObj->header.gfx.unk54);

    if (m->angleVel[1] >= 256 && sp26 > m->faceAngle[1])
        SetSound(SOUND_OBJECT_BOWSERSPINNING, &m->marioObj->header.gfx.unk54);

    stationary_ground_step(m);
    if (m->angleVel[1] >= 0)
        m->marioObj->header.gfx.angle[0] = -m->angleVel[1];
    else
        m->marioObj->header.gfx.angle[0] = m->angleVel[1];

    return 0;
}

s32 act_releasing_bowser(struct MarioState *m)
{
    if (++m->actionTimer == 1)  // increment occurs before comparison
    {
        if (m->actionArg == 0)
            mario_throw_held_object(m);
        else
            mario_drop_held_object(m);
    }
    m->angleVel[1] = 0;
    func_80274940(m, 183, ACT_IDLE);
    return 0;
}

s32 func_8027595C(struct MarioState *m)
{
    f32 waterSurface = m->waterLevel - 100;
    if (m->pos[1] < waterSurface)
        return func_8025325C(m);

    if (m->input & INPUT_SQUISHED)
        return drop_and_set_mario_action(m, ACT_SQUISHED, 0);

    if (m->health < 0x100)
        return drop_and_set_mario_action(m, ACT_STANDING_DEATH, 0);

    return 0;
}

s32 func_80275A30(struct MarioState *m)
{
    s32 ret;
    if (func_8027595C(m))
        return 1;

    if (mario_update_quicksand(m, 0.5f))
        return 1;

    switch (m->action)
    {
        case ACT_PUNCHING:
            ret = act_punching(m);
            break;
        case ACT_UNKNOWN_183:
            ret = func_80274EFC(m);
            break;
        case ACT_UNKNOWN_185:
            ret = func_8027508C(m);
            break;
        case ACT_UNKNOWN_186:
            ret = func_80275444(m);
            break;
        case ACT_UNKNOWN_187:
            ret = func_80275158(m);
            break;
        case ACT_THROWING:
            ret = act_throwing(m);
            break;
        case ACT_UNKNOWN_189:
            ret = func_80275350(m);
            break;
        case ACT_UNKNOWN_190:
            ret = func_80275510(m);
            break;
        case ACT_HOLDING_BOWSER:
            ret = act_holding_bowser(m);
            break;
        case ACT_RELEASING_BOWSER:
            ret = act_releasing_bowser(m);
            break;
    }

    if (ret == 0 && (m->input & INPUT_IN_WATER))
        m->particleFlags |= PARTICLE_7;

    return ret;
}
