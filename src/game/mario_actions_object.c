#include <ultra64.h>

#include "sm64.h"
#include "mario_actions_object.h"
#include "types.h"
#include "mario_step.h"
#include "mario.h"
#include "audio/interface_2.h"
#include "interaction.h"
#include "audio_defines.h"
#include "engine/math_util.h"

/**
 * Used by act_punching() to determine Mario's forward velocity during each
 * animation frame.
 */
static s8 sPunchingForwardVelocities[8] = {0, 1, 1, 2, 3, 5, 7, 10};


static void animated_stationary_ground_step(struct MarioState *m, s32 animation, u32 endAction)
{
    stationary_ground_step(m);
    func_802507E8(m, animation);
    if (func_80250770(m))
        set_mario_action(m, endAction, 0);
}

s32 mario_update_punch_sequence(struct MarioState *m)
{
    u32 endAction, crouchEndAction;
    s32 animFrame;

    if (m->action & ACT_FLAG_MOVING)
        endAction = ACT_WALKING, crouchEndAction = ACT_CROUCH_SLIDE;
    else
        endAction = ACT_IDLE,    crouchEndAction = ACT_CROUCHING;

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
                return TRUE;

            m->flags |= MARIO_PUNCHING;
        }

        if (m->actionArg == 2)
            m->unk98->unk0B = 4;
        break;

    case 2:
        func_802507E8(m, 105);

        if (m->marioObj->header.gfx.unk38.animFrame <= 0)
            m->flags |= MARIO_PUNCHING;

        if (m->input & INPUT_B_PRESSED)
            m->actionArg = 3;

        if (func_80250770(m))
            set_mario_action(m, endAction, 0);
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
            m->flags |= MARIO_PUNCHING;

        if (m->actionArg == 5)
            m->unk98->unk0B = 68;
        break;

    case 5:
        func_802507E8(m, 106);
        if (m->marioObj->header.gfx.unk38.animFrame <= 0)
            m->flags |= MARIO_PUNCHING;

        if (m->input & INPUT_B_PRESSED)
            m->actionArg = 6;

        if (func_80250770(m))
            set_mario_action(m, endAction, 0);
        break;

    case 6:
        func_80251218(m, SOUND_MARIO_HOO6, 1);
        animFrame = func_802507E8(m, 102);
        if (animFrame == 0)
            m->unk98->unk0B = 134;

        if (animFrame >= 0 && animFrame < 8)
            m->flags |= MARIO_KICKING;

        if (func_80250770(m))
            set_mario_action(m, endAction, 0);
        break;

    case 9:
        func_80251218(m, SOUND_MARIO_HOO6, 1);
        func_802507E8(m, 113);
        animFrame = m->marioObj->header.gfx.unk38.animFrame;

        if (animFrame >= 2 && animFrame < 8)
            m->flags |= MARIO_TRIPPING;

        if (func_80250770(m))
            set_mario_action(m, crouchEndAction, 0);
        break;
    }

    return FALSE;
}

static s32 act_punching(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED |
                    INPUT_OFF_FLOOR      | INPUT_ABOVE_SLIDE))
        return func_80252FEC(m);

    if (m->actionState == 0 && (m->input & INPUT_A_DOWN))
        return set_mario_action(m, ACT_JUMP_KICK, 0);

    m->actionState = 1;
    if (m->actionArg == 0)
        m->actionTimer = 7;

    mario_set_forward_vel(m, sPunchingForwardVelocities[m->actionTimer]);
    if (m->actionTimer > 0)
        m->actionTimer--;

    mario_update_punch_sequence(m);
    perform_ground_step(m);
    return FALSE;
}

static s32 act_picking_up(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (m->actionState == 0 && func_80250770(m))
    {
        //! While the animation is playing, it is possible for the used object
        // to unload. This allows you to pick up a vacant or newly loaded object
        // slot (cloning via fake object).
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
    return FALSE;
}

static s32 act_dive_picking_up(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_ABOVE_SLIDE)
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);

    animated_stationary_ground_step(m, 139, ACT_UNKNOWN_007);
    return FALSE;
}

static s32 act_placing_down(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (++m->actionTimer == 8)
        mario_drop_held_object(m);

    animated_stationary_ground_step(m, 110, ACT_IDLE);
    return FALSE;
}

static s32 act_throwing(struct MarioState *m)
{
    if (m->heldObj && (m->heldObj->oUnk190 & 0x10))
        return set_mario_action(m, ACT_PLACING_DOWN, 0);

    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (++m->actionTimer == 7)
    {
        mario_throw_held_object(m);
        func_80250F50(m, SOUND_MARIO_WAH2, MARIO_UNKNOWN_17);
        func_80250F50(m, SOUND_ACTION_UNKNOWN435, MARIO_UNKNOWN_16);
    }

    animated_stationary_ground_step(m, 101, ACT_IDLE);
    return FALSE;
}

static s32 act_heavy_throw(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);

    if (++m->actionTimer == 13)
    {
        mario_drop_held_object(m);
        func_80250F50(m, SOUND_MARIO_WAH2, MARIO_UNKNOWN_17);
        func_80250F50(m, SOUND_ACTION_UNKNOWN435, MARIO_UNKNOWN_16);
    }

    animated_stationary_ground_step(m, 185, ACT_IDLE);
    return FALSE;
}

static s32 act_stomach_slide_stop(struct MarioState *m)
{
    if (m->input & INPUT_UNKNOWN_10)
        return set_mario_action(m, ACT_UNKNOWN_026, 0);

    if (m->input & INPUT_OFF_FLOOR)
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_ABOVE_SLIDE)
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);

    animated_stationary_ground_step(m, 90, ACT_IDLE);
    return FALSE;
}

static s32 act_picking_up_bowser(struct MarioState *m)
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
    return FALSE;
}

static s32 act_holding_bowser(struct MarioState *m)
{
    s16 spin;

    if (m->input & INPUT_B_PRESSED)
    {
#if VERSION_US
        if (m->angleVel[1] <= -0xE00 || m->angleVel[1] >= 0xE00)
            SetSound(SOUND_MARIO_SOLONGABOWSER, &m->marioObj->header.gfx.unk54);
        else
            SetSound(SOUND_MARIO_HEREWEGO, &m->marioObj->header.gfx.unk54);
#else
        SetSound(SOUND_MARIO_HEREWEGO, &m->marioObj->header.gfx.unk54);
#endif
        return set_mario_action(m, ACT_RELEASING_BOWSER, 0);
    }

    if (m->angleVel[1] == 0)
    {
        if (m->actionTimer++ > 120)
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
            // spin = acceleration
            spin = (s16) (m->intendedYaw - m->twirlYaw) / 0x80;

            if (spin < -0x80)
                spin = -0x80;
            if (spin > 0x80)
                spin = 0x80;

            m->twirlYaw = m->intendedYaw;
            m->angleVel[1] += spin;

            if (m->angleVel[1] > 0x1000)
                m->angleVel[1] = 0x1000;
            if (m->angleVel[1] < -0x1000)
                m->angleVel[1] = -0x1000;
        }
    }
    else
    {
        m->actionArg = 0;
        m->angleVel[1] = approach_s32(m->angleVel[1], 0, 64, 64);
    }

    // spin = starting yaw
    spin = m->faceAngle[1];
    m->faceAngle[1] += m->angleVel[1];

    // play sound on overflow
    if (m->angleVel[1] <= -0x100 && spin < m->faceAngle[1])
        SetSound(SOUND_OBJECT_BOWSERSPINNING, &m->marioObj->header.gfx.unk54);
    if (m->angleVel[1] >= 0x100 && spin > m->faceAngle[1])
        SetSound(SOUND_OBJECT_BOWSERSPINNING, &m->marioObj->header.gfx.unk54);

    stationary_ground_step(m);
    if (m->angleVel[1] >= 0)
        m->marioObj->header.gfx.angle[0] = -m->angleVel[1];
    else
        m->marioObj->header.gfx.angle[0] = m->angleVel[1];

    return FALSE;
}

static s32 act_releasing_bowser(struct MarioState *m)
{
    if (++m->actionTimer == 1)
    {
        if (m->actionArg == 0)
            mario_throw_held_object(m);
        else
            mario_drop_held_object(m);
    }

    m->angleVel[1] = 0;
    animated_stationary_ground_step(m, 183, ACT_IDLE);
    return FALSE;
}

static s32 check_common_object_cancels(struct MarioState *m)
{
    f32 waterSurface = m->waterLevel - 100;
    if (m->pos[1] < waterSurface)
        return func_8025325C(m);

    if (m->input & INPUT_SQUISHED)
        return drop_and_set_mario_action(m, ACT_SQUISHED, 0);

    if (m->health < 0x100)
        return drop_and_set_mario_action(m, ACT_STANDING_DEATH, 0);

    return FALSE;
}

s32 mario_execute_object_action(struct MarioState *m)
{
    s32 cancel;
    
    if (check_common_object_cancels(m))
        return TRUE;

    if (mario_update_quicksand(m, 0.5f))
        return TRUE;

    switch (m->action)
    {
    case ACT_PUNCHING:           cancel = act_punching(m);           break;
    case ACT_PICKING_UP:         cancel = act_picking_up(m);         break;
    case ACT_DIVE_PICKING_UP:    cancel = act_dive_picking_up(m);    break;
    case ACT_STOMACH_SLIDE_STOP: cancel = act_stomach_slide_stop(m); break;
    case ACT_PLACING_DOWN:       cancel = act_placing_down(m);       break;
    case ACT_THROWING:           cancel = act_throwing(m);           break;
    case ACT_HEAVY_THROW:        cancel = act_heavy_throw(m);        break;
    case ACT_PICKING_UP_BOWSER:  cancel = act_picking_up_bowser(m);  break;
    case ACT_HOLDING_BOWSER:     cancel = act_holding_bowser(m);     break;
    case ACT_RELEASING_BOWSER:   cancel = act_releasing_bowser(m);   break;
    }

    if (!cancel && (m->input & INPUT_IN_WATER))
        m->particleFlags |= PARTICLE_7;

    return cancel;
}
