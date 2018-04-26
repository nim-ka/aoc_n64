#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"
#include "save_file.h"

#define INTERACTION_UNKNOWN_0 (1 << 0) // 0x00000001
#define INTERACTION_UNKNOWN_1 (1 << 1) // 0x00000002
#define INTERACTION_UNKNOWN_2 (1 << 2) // 0x00000004
#define INTERACTION_UNKNOWN_3 (1 << 3) // 0x00000008
#define INTERACTION_UNKNOWN_4 (1 << 4) // 0x00000010
#define INTERACTION_UNKNOWN_5 (1 << 5) // 0x00000020
#define INTERACTION_UNKNOWN_6 (1 << 6) // 0x00000040
#define INTERACTION_UNKNOWN_7 (1 << 7) // 0x00000080

u32 func_8024BE50(struct Object *capObject)
{
    void *script = virtual_to_segmented(0x13, capObject->unk20C);

    if (script == D_13003DD8)
        return MARIO_UNKNOWN_00;
    else if (script == D_13003DB8)
        return MARIO_METAL_CAP;
    else if (script == D_13003D98)
        return MARIO_WING_CAP;
    else if (script == D_13003DFC)
        return MARIO_VANISH_CAP;

    return 0;
}

u32 func_8024BF18(struct MarioState *m, struct Object *o, s16 angleRange)
{
    f32 dx = m->pos[0] - o->pos[0];
    f32 dz = m->pos[2] - o->pos[2];

    s16 angleToMario = func_8037A9A8(dz, dx);
    s16 dAngle = angleToMario - o->angle[1];

    if (-angleRange <= dAngle && dAngle <= angleRange)
        return TRUE;
    
    return FALSE;
}

s16 func_8024BFCC(struct MarioState *m, struct Object *o)
{
    f32 dx = o->pos[0] - m->pos[0];
    f32 dz = o->pos[2] - m->pos[2];

    return func_8037A9A8(dz, dx);
}

s32 func_8024C038(struct MarioState *m, struct Object *o)
{
    u32 interaction = 0;
    u32 action = m->action;

    if (action & ACT_FLAG_UNKNOWN_23)
    {
        if (action == ACT_PUNCHING || action == ACT_MOVE_PUNCHING || action == ACT_JUMP_KICK)
        {
            s16 dYawToObject = func_8024BFCC(m, o) - m->faceAngle[1];

            if (m->flags & MARIO_UNKNOWN_20)
            {
                if (-0x2AAA <= dYawToObject && dYawToObject <= 0x2AAA)
                    interaction = INTERACTION_UNKNOWN_1;
            }
            if (m->flags & MARIO_UNKNOWN_21)
            {
                if (-0x2AAA <= dYawToObject && dYawToObject <= 0x2AAA)
                    interaction = INTERACTION_UNKNOWN_2;
            }
            if (m->flags & MARIO_UNKNOWN_22)
            {
                if (-0x4000 <= dYawToObject && dYawToObject <= 0x4000)
                    interaction = INTERACTION_UNKNOWN_3;
            }
        }
        else if (action == ACT_GROUND_POUND || action == ACT_TWIRLING)
        {
            if (m->vel[1] < 0.0f)
                interaction = INTERACTION_UNKNOWN_0;
        }
        else if (action == ACT_GROUND_POUND_LAND || action == ACT_TWIRL_LAND)
        {
            if (m->vel[1] < 0.0f && m->actionState == 0)
                interaction = INTERACTION_UNKNOWN_0;
        }
        else if (action == ACT_SLIDE_KICK || action == ACT_SLIDE_KICK_SLIDE)
        {
            interaction = INTERACTION_UNKNOWN_4;
        }
        else if (action & ACT_FLAG_RIDING_SHELL)
        {
            interaction = INTERACTION_UNKNOWN_5;
        }
        else if (m->forwardVel <= -26.0f || 26.0f <= m->forwardVel)
        {
            interaction = INTERACTION_UNKNOWN_5;
        }
    }

    if (interaction == 0 && (action & ACT_FLAG_AIR))
    {
        if (m->vel[1] < 0.0f)
        {
            if (m->pos[1] > o->pos[1])
                interaction = INTERACTION_UNKNOWN_6;
        }
        else
        {
            if (m->pos[1] < o->pos[1])
                interaction = INTERACTION_UNKNOWN_7;
        }
    }

    return interaction;
}

u32 func_8024C37C(struct Object *o, s32 interaction)
{
    u32 result = 0;
    
    switch (interaction)
    {
    case INTERACTION_UNKNOWN_0: result = 0x00000004; break;
    case INTERACTION_UNKNOWN_1: result = 0x00000001; break;
    case INTERACTION_UNKNOWN_2:
    case INTERACTION_UNKNOWN_3: result = 0x00000002; break;
    case INTERACTION_UNKNOWN_4:
    case INTERACTION_UNKNOWN_5: result = 0x00000005; break;
    case INTERACTION_UNKNOWN_6: result = 0x00000003; break;
    case INTERACTION_UNKNOWN_7: result = 0x00000006; break;
    }

    o->interactStatus = result + 0xC000;
    return result;
}

void func_8024C478(struct MarioState *m)
{
    if (m->riddenObj != NULL)
    {
        m->riddenObj->interactStatus = 0x00400000;
        func_8024931C();
        m->riddenObj = NULL;
    }
}

void func_8024C4CC(struct MarioState *m)
{
    if (m->heldObj == NULL)
    {
        m->heldObj = m->usedObj;
        func_8029DA34(m->heldObj, D_13003444);
    }
}

void func_8024C520(struct MarioState *m)
{
    if (m->heldObj != NULL)
    {
        if (m->heldObj->unk20C == segmented_to_virtual(D_13000708))
            func_8024931C();

        func_8029DA34(m->heldObj, D_1300344C);

        m->heldObj->pos[0] = m->unk98->unk18[0];
        m->heldObj->pos[1] = m->pos[1];
        m->heldObj->pos[2] = m->unk98->unk18[2];

        m->heldObj->angle[1] = m->faceAngle[1];

        m->heldObj = NULL;
    }
}

void func_8024C5E0(struct MarioState *m)
{
    if (m->heldObj != NULL)
    {
        if (m->heldObj->unk20C == segmented_to_virtual(D_13000708))
            func_8024931C();

        func_8029DA34(m->heldObj, D_13003454);

        m->heldObj->pos[0] = m->unk98->unk18[0] + 32.0f * sins(m->faceAngle[1]);
        m->heldObj->pos[1] = m->unk98->unk18[1];
        m->heldObj->pos[2] = m->unk98->unk18[2] + 32.0f * coss(m->faceAngle[1]);

        m->heldObj->angle[1] = m->faceAngle[1];

        m->heldObj = NULL;
    }
}

void func_8024C6F4(struct MarioState *m)
{
    func_8024C520(m);
    func_8024C478(m);

    if (m->action == ACT_RIDING_HOOT)
    {
        m->usedObj->interactStatus = 0;
        m->usedObj->unk110 = D_8032C694;
    }
}

u32 func_8024C75C(struct MarioState *m)
{
    return (m->flags & MARIO_CAP_FLAGS) == (MARIO_UNKNOWN_00 | MARIO_CAP_ON_HEAD);
}

void func_8024C788(struct MarioState *m, f32 capSpeed)
{
    struct Object *capObject;

    if (func_8024C75C(m))
    {
        save_file_set_cap_location(m->pos[0], m->pos[1], m->pos[2]);

        m->flags &= ~(MARIO_UNKNOWN_00 | MARIO_CAP_ON_HEAD);

        capObject = SpawnObj(m->marioObj, 136, D_13003DD8);

        capObject->pos[1] += (m->action & ACT_FLAG_UNKNOWN_15) ? 120.0f : 180.0f;
        capObject->forwardVel = capSpeed;
        capObject->angle[1] = (s16) (m->faceAngle[1] + 0x400);

        if (m->forwardVel < 0.0f)
            capObject->angle[1] = (s16) (capObject->angle[1] + 0x8000);
    }
}

u32 func_8024C8C8(u32 arg)
{
    u32 result = FALSE;
    if (func_8024C75C(gMarioState))
    {
        save_file_set_flags(arg == 1 ? FLAG_CAP_ON_KLEPTO : FLAG_CAP_ON_UKIKI);
        gMarioState->flags &= ~(MARIO_UNKNOWN_00 | MARIO_CAP_ON_HEAD);
        result = TRUE;
    }
    return result;
}

void func_8024C958(void)
{
    func_8024C520(gMarioState);
    save_file_clear_flags(FLAG_CAP_ON_KLEPTO | FLAG_CAP_ON_UKIKI);
    gMarioState->flags &= ~MARIO_CAP_ON_HEAD;
    gMarioState->flags |= MARIO_UNKNOWN_00 | MARIO_CAP_IN_HAND;
}

u32 func_8024C9B8(struct MarioState *m, UNUSED struct Object *o)
{
    u32 action = m->action;

    if (action == ACT_DIVE_SLIDE || action == ACT_DIVE)
    {
        if (!(o->unk190 & 0x00000004))
            return TRUE;
    }
    else if (action == ACT_PUNCHING || action == ACT_MOVE_PUNCHING)
    {
        if (m->actionArg < 2)
            return TRUE;
    }

    return FALSE;
}

struct Object *func_8024CA5C(struct MarioState *m, u32 interactType)
{
    s32 i;
    struct Object *object;

    for (i = 0; i < m->marioObj->numCollidedObjs; i++)
    {
        object = m->marioObj->collidedObjs[i];

        if (object->interactType == interactType)
            return object;
    }

    return NULL;
}

u32 func_8024CADC(struct MarioState *m)
{
    u32 result = FALSE;
    void *script;

    if (m->input & INPUT_INTERACT_OBJ_GRABBABLE)
    {
        script = virtual_to_segmented(0x13, m->interactObj->unk20C);

        if (script == D_13001850)
        {
            s16 facingDYaw = m->faceAngle[1] - m->interactObj->angle[1];
            if (facingDYaw >= -0x5555 && facingDYaw <= 0x5555)
            {
                m->faceAngle[1] = m->interactObj->angle[1];
                m->usedObj = m->interactObj;
                result = set_mario_action(m, ACT_UNKNOWN_190, 0);
            }
        }
        else
        {
            s16 facingDYaw = func_8024BFCC(m, m->interactObj) - m->faceAngle[1];
            if (facingDYaw >= -0x2AAA && facingDYaw <= 0x2AAA)
            {
                m->usedObj = m->interactObj;

                if (!(m->action & ACT_FLAG_AIR))
                {
                    set_mario_action(
                        m,
                        (m->action & ACT_FLAG_UNKNOWN_19) ? ACT_UNKNOWN_185 : ACT_UNKNOWN_183,
                        0);
                }
    
                result = TRUE;
            }
        }
    }

    return result;
}

u32 func_8024CC68(struct MarioState *mario)
{
    struct BullyCollisionData marioData;
    struct BullyCollisionData bullyData;
    s16 newMarioYaw;
    s16 newBullyYaw;
    s16 marioDYaw;
    UNUSED s16 bullyDYaw;
    u32 bonkAction;
    struct Object *bully;
    f32 bullyToMarioRatio;
    f32 marioToBullyRatio;

    bonkAction = 0;

    bully = mario->interactObj;

    //! Conversion ratios multiply to more than 1 (could allow unbounded speed
    // with bonk cancel - but this isn't important for regular bully battery)
    bullyToMarioRatio = bully->hitboxRadius * 3.0f / 53.0f;
    marioToBullyRatio = 53.0f / bully->hitboxRadius;

    init_bully_collision_data(
        &marioData,
        mario->pos[0],
        mario->pos[2],
        mario->forwardVel,
        mario->faceAngle[1],
        bullyToMarioRatio,
        52.0f);

    init_bully_collision_data(
        &bullyData,
        bully->pos[0],
        bully->pos[2],
        bully->forwardVel,
        bully->angle[1],
        marioToBullyRatio,
        bully->hitboxRadius + 2.0f);

    if (mario->forwardVel != 0.0f)
        transfer_bully_speed(&marioData, &bullyData);
    else
        transfer_bully_speed(&bullyData, &marioData);

    newMarioYaw = func_8037A9A8(marioData.velZ, marioData.velX);
    newBullyYaw = func_8037A9A8(bullyData.velZ, bullyData.velX);

    marioDYaw = newMarioYaw - mario->faceAngle[1];
    bullyDYaw = newBullyYaw - bully->angle[1];

    mario->faceAngle[1] = newMarioYaw;
    mario->forwardVel =
        sqrtf(marioData.velX * marioData.velX + marioData.velZ * marioData.velZ);
    mario->pos[0] = marioData.posX;
    mario->pos[2] = marioData.posZ;

    bully->angle[1] = newBullyYaw;
    bully->forwardVel =
        sqrtf(bullyData.velX * bullyData.velX + bullyData.velZ * bullyData.velZ);
    bully->pos[0] = bullyData.posX;
    bully->pos[2] = bullyData.posZ;

    if (marioDYaw < -0x4000 || marioDYaw > 0x4000)
    {
        mario->faceAngle[1] += 0x8000;
        mario->forwardVel *= -1.0f;

        if (mario->action & ACT_FLAG_AIR)
            bonkAction = ACT_BACKWARD_AIR_KB;
        else
            bonkAction = ACT_UNKNOWN_064;
    }
    else
    {
        if (mario->action & ACT_FLAG_AIR)
            bonkAction = ACT_FORWARD_AIR_KB;
        else
            bonkAction = ACT_UNKNOWN_065;
    }

    return bonkAction;
}

void func_8024CF14(struct MarioState *m, struct Object *o, f32 velY)
{
    m->pos[1] = o->pos[1] + o->hitboxHeight;
    m->vel[1] = velY;

    m->flags &= ~MARIO_UNKNOWN_08;

    SetSound(0x0459B081, &m->marioObj->gfx.unk54);
}
