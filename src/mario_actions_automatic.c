#include <ultra64.h>

#include "sm64.h"
#include "mario_actions_automatic.h"
#include "audio_interface_2.h"
#include "level_update.h"
#include "mario.h"
#include "mario_step.h"
#include "math_util.h"
#include "memory.h"
#include "sound_init.h"
#include "save_file.h"
#include "surface_collision.h"

extern u8 beh_tree[];
extern u8 beh_giant_pole[];

static void add_tree_leaf_particles(struct MarioState *m)
{
    float leafHeight;

    if (segmented_to_virtual(beh_tree) == m->usedObj->behavior)
    {
        // make leaf effect spawn higher on the Shifting Sand Land palm tree
        if (gCurrLevelNum == LEVEL_SSL)
            leafHeight = 250.0f;
        else
            leafHeight = 100.0f;
        if (m->pos[1] - m->floorHeight > leafHeight)
            m->particleFlags |= PARTICLE_LEAVES;
    }
}

static void play_climbing_sounds(struct MarioState *m, int b)
{
    int isOnTree = (segmented_to_virtual(beh_tree) == m->usedObj->behavior);

    if (b == 1)
    {
        if (func_80250B68(m, 1) != 0)
            SetSound(isOnTree ? 0x043A8081 : 0x04418081, &m->marioObj->gfx.unk54);
    }
    else
    {
        SetSound(isOnTree ? 0x14128001 : 0x14110001, &m->marioObj->gfx.unk54);
    }
}

static int func_8025DB84(struct MarioState *m, float b)
{
    UNUSED int unused1;
    UNUSED int unused2;
    UNUSED int unused3;
    struct Surface *floor;
    struct Surface *ceil;
    float floorHeight;
    float ceilHeight;
    int collided;
    int sp34 = 0;
    float sp30 = m->usedObj->hitboxHeight - 100.0f;
    struct Object *marioObj = m->marioObj;

    if (*(float *)&marioObj->unk110 > sp30)
        *(float *)&marioObj->unk110 = sp30;

    m->pos[0] = m->usedObj->pos[0];
    m->pos[2] = m->usedObj->pos[2];
    m->pos[1] = m->usedObj->pos[1] + *(float *)&marioObj->unk110 + b;

    collided  = func_80380DE8(&m->pos[0], &m->pos[1], &m->pos[2], 60.0f, 50.0f);
    collided |= func_80380DE8(&m->pos[0], &m->pos[1], &m->pos[2], 30.0f, 24.0f);

    ceilHeight = func_802518D0(m->pos, m->pos[1], &ceil);
    if (m->pos[1] > ceilHeight - 160.0f)
    {
        m->pos[1] = ceilHeight - 160.0f;
        *(float *)&marioObj->unk110 = m->pos[1] - m->usedObj->pos[1];
    }

    floorHeight = func_80381900(m->pos[0], m->pos[1], m->pos[2], &floor);
    if (m->pos[1] < floorHeight)
    {
        m->pos[1] = floorHeight;
        set_mario_action(m, ACT_IDLE, 0);
        sp34 = 1;
    }
    else if (*(float *)&marioObj->unk110 < -m->usedObj->unk208)
    {
        m->pos[1] = m->usedObj->pos[1] - m->usedObj->unk208;
        set_mario_action(m, ACT_FREEFALL, 0);
        sp34 = 2;
    }
    else if (collided)
    {
        if (m->pos[1] > floorHeight + 20.0f)
        {
            m->forwardVel = -2.0f;
            set_mario_action(m, ACT_SOFT_BONK, 0);
            sp34 = 2;
        }
        else
        {
            set_mario_action(m, ACT_IDLE, 0);
            sp34 = 1;
        }
    }

    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
    vec3s_set(m->marioObj->gfx.unk1A, m->usedObj->angle[0], m->faceAngle[1], m->usedObj->angle[2]);

    return sp34;
}

static int act_holding_pole(struct MarioState *m)
{
    struct Object *marioObj = m->marioObj;

#if VERSION_US
    if ((m->input & INPUT_Z_PRESSED) || m->health < 0x100)
    {
        add_tree_leaf_particles(m);
        m->forwardVel = -2.0f;
        return set_mario_action(m, ACT_SOFT_BONK, 0);
    }

    if (m->input & INPUT_A_PRESSED)
    {
        add_tree_leaf_particles(m);
        m->faceAngle[1] += 0x8000;
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0);
    }
#else
    if (m->input & INPUT_A_PRESSED)
    {
        add_tree_leaf_particles(m);
        m->faceAngle[1] += 0x8000;
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0);
    }

    if (m->input & INPUT_Z_PRESSED)
    {
        add_tree_leaf_particles(m);
        m->forwardVel = -2.0f;
        return set_mario_action(m, ACT_SOFT_BONK, 0);
    }
#endif

    if (m->controller->stickY > 16.0f)
    {
        float sp20 = m->usedObj->hitboxHeight - 100.0f;
        void *poleBehavior = virtual_to_segmented(0x13, m->usedObj->behavior);

        if (*(float *)&marioObj->unk110 < sp20 - 0.4f)
            return set_mario_action(m, ACT_CLIMBING_POLE, 0);

        if (poleBehavior != beh_giant_pole && m->controller->stickY > 50.0f)
            return set_mario_action(m, ACT_TOP_OF_POLE_TRANSITION, 0);
    }

    if (m->controller->stickY < -16.0f)
    {
        marioObj->unk10C -= m->controller->stickY * 2.0f;
        if (marioObj->unk10C > 0x1000)
            marioObj->unk10C = 0x1000;
        m->faceAngle[1] += marioObj->unk10C;
        *(float *)&marioObj->unk110 -= marioObj->unk10C / 0x100;
        if (m->usedObj->behavior == segmented_to_virtual(beh_tree))
        {
            //! The Shifting Sand Land palm tree check is done climbing up in
            // add_tree_leaf_particles, but not here, when climbing down.
            if (m->pos[1] - m->floorHeight > 100.0f)
                m->particleFlags |= PARTICLE_LEAVES;
        }
        play_climbing_sounds(m, 2);
        func_80320A4C(1, marioObj->unk10C / 0x100 * 2);
    }
    else
    {
        marioObj->unk10C = 0;
        m->faceAngle[1] -= m->controller->stickX * 16.0f;
    }

    if (func_8025DB84(m, 0.0f) == 0)
        func_802507E8(m, 13);

    return FALSE;
}

static int act_climbing_pole(struct MarioState *m)
{
    int sp24;
    struct Object *marioObj = m->marioObj;
    s16 sp1E = m->area->unk24->unk02;

#if VERSION_US
    if (m->health < 0x100)
    {
        add_tree_leaf_particles(m);
        m->forwardVel = -2.0f;
        return set_mario_action(m, ACT_SOFT_BONK, 0);
    }
#endif

    if (m->input & INPUT_A_PRESSED)
    {
        add_tree_leaf_particles(m);
        m->faceAngle[1] += 0x8000;
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0);
    }

    if (m->controller->stickY < 8.0f)
        return set_mario_action(m, ACT_HOLDING_POLE, 0);

    *(float *)&marioObj->unk110 += m->controller->stickY / 8.0f;
    marioObj->unk10C = 0;
    m->faceAngle[1] = sp1E - approach_s32((s16)(sp1E - m->faceAngle[1]), 0, 0x400, 0x400);
    if (func_8025DB84(m, 0.0f) == 0)
    {
        sp24 = m->controller->stickY / 4.0f * 65536.0f;
        func_80250934(m, 5, sp24);
        add_tree_leaf_particles(m);
        play_climbing_sounds(m, 1);
    }
    return FALSE;
}

static int act_grab_pole_slow(struct MarioState *m)
{
    func_80250F50(m, 0x2408C081, 0x20000);
    if (func_8025DB84(m, 0.0f) == 0)
    {
        func_802507E8(m, 6);
        if (func_80250770(m) != 0)
            set_mario_action(m, ACT_HOLDING_POLE, 0);
        add_tree_leaf_particles(m);
    }
    return FALSE;
}

static int act_grab_pole_fast(struct MarioState *m)
{
    struct Object *marioObj = m->marioObj;

    func_80250F50(m, 0x2408C081, 0x20000);
    m->faceAngle[1] += marioObj->unk10C;
    marioObj->unk10C = marioObj->unk10C * 8 / 10;
    if (func_8025DB84(m, 0.0f) == 0)
    {
        if (marioObj->unk10C > 0x800)
        {
            func_802507E8(m, 7);
        }
        else
        {
            func_802507E8(m, 8);
            if (func_80250770(m) != 0)
            {
                marioObj->unk10C = 0;
                set_mario_action(m, ACT_HOLDING_POLE, 0);
            }
        }
        add_tree_leaf_particles(m);
    }
    return FALSE;
}

static int act_top_of_pole_transition(struct MarioState *m)
{
    struct Object *marioObj = m->marioObj;

    marioObj->unk10C = 0;
    if (m->actionArg == 0)
    {
        func_802507E8(m, 11);
        if (func_80250770(m) != 0)
            return set_mario_action(m, ACT_TOP_OF_POLE, 0);
    }
    else
    {
        func_802507E8(m, 12);
        if (m->marioObj->gfx.unk40 == 0)
            return set_mario_action(m, ACT_HOLDING_POLE, 0);
    }
    func_8025DB84(m, func_80250F0C(m));
    return FALSE;
}

static int act_top_of_pole(struct MarioState *m)
{
    UNUSED struct Object *marioObj = m->marioObj;

    if (m->input & INPUT_A_PRESSED)
        return set_mario_action(m, ACT_TOP_OF_POLE_JUMP, 0);
    if (m->controller->stickY < -16.0f)
        return set_mario_action(m, ACT_TOP_OF_POLE_TRANSITION, 1);
    m->faceAngle[1] -= m->controller->stickX * 16.0f;
    func_802507E8(m, 9);
    func_8025DB84(m, func_80250F0C(m));
    return FALSE;
}

static int func_8025E778(struct MarioState *m, Vec3f newPos)
{
    UNUSED int unused;
    struct Surface *ceil;
    struct Surface *floor;
    float ceilHeight;
    float floorHeight;
    float distFromCeil;

    m->wall = func_8025181C(newPos, 50.0f, 50.0f);
    floorHeight = func_80381900(newPos[0], newPos[1], newPos[2], &floor);
    ceilHeight = func_802518D0(newPos, floorHeight, &ceil);
    if (floor == NULL)
        return 1;
    if (ceil == NULL)
        return 2;
    if (ceilHeight - floorHeight <= 160.0f)
        return 1;
    if (ceil->type != 5)
        return 2;
    distFromCeil = ceilHeight - (newPos[1] + 160.0f);
    if (distFromCeil < -30.0f)
        return 1;
    if (distFromCeil > 30.0f)
        return 2;
    newPos[1] = m->ceilHeight - 160.0f;
    vec3f_copy(m->pos, newPos);
    m->floor = floor;
    m->floorHeight = floorHeight;
    m->ceil = ceil;
    m->ceilHeight = ceilHeight;
    return 0;
}

static int func_8025E924(struct MarioState *m)
{
    int sp2C;
    Vec3f sp20;
    float maxSpeed = 4.0f;

    m->forwardVel += 1.0f;
    if (m->forwardVel > maxSpeed)
        m->forwardVel = maxSpeed;

    m->faceAngle[1] = m->intendedYaw - approach_s32((s16)(m->intendedYaw - m->faceAngle[1]), 0, 0x800, 0x800);

    m->slideYaw = m->faceAngle[1];
    m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
    m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);

    m->vel[0] = m->slideVelX;
    m->vel[1] = 0.0f;
    m->vel[2] = m->slideVelZ;

    sp20[0] = m->pos[0] - m->ceil->normal[1] * m->vel[0];
    sp20[2] = m->pos[2] - m->ceil->normal[1] * m->vel[2];
    sp20[1] = m->pos[1];

    sp2C = func_8025E778(m, sp20);
    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
    vec3s_set(m->marioObj->gfx.unk1A, 0, m->faceAngle[1], 0);
    return sp2C;
}

static void func_8025EAF8(struct MarioState *m)
{
    m->forwardVel = 0.0f;
    m->slideVelX = 0.0f;
    m->slideVelZ = 0.0f;
    m->pos[1] = m->ceilHeight - 160.0f;
    vec3f_copy(m->vel, D_80385FD0);
    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
}

static int act_start_hanging(struct MarioState *m)
{
    m->actionTimer++;

    if ((m->input & INPUT_NONZERO_ANALOG) && m->actionTimer >= 31)
        return set_mario_action(m, ACT_HANGING, 0);

    if (!(m->input & INPUT_A_DOWN))
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    if (m->ceil->type != 5)
        return set_mario_action(m, ACT_FREEFALL, 0);

    func_802507E8(m, 53);
    func_80250F50(m, 0x042DA081, 0x10000);
    func_8025EAF8(m);

    if (func_80250770(m) != 0)
        set_mario_action(m, ACT_HANGING, 0);

    return FALSE;
}

static int act_hanging(struct MarioState *m)
{
    if (m->input & INPUT_NONZERO_ANALOG)
        return set_mario_action(m, ACT_HANG_MOVING, m->actionArg);

    if (!(m->input & INPUT_A_DOWN))
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    if (m->ceil->type != 5)
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->actionArg & 1)
        func_802507E8(m, 198);
    else
        func_802507E8(m, 199);

    func_8025EAF8(m);

    return FALSE;
}

static int act_hang_moving(struct MarioState *m)
{
    if (!(m->input & INPUT_A_DOWN))
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->input & INPUT_Z_PRESSED)
        return set_mario_action(m, ACT_GROUND_POUND, 0);

    if (m->ceil->type != 5)
        return set_mario_action(m, ACT_FREEFALL, 0);

    if (m->actionArg & 1)
        func_802507E8(m, 92);
    else
        func_802507E8(m, 93);

    if (m->marioObj->gfx.unk40 == 12)
        SetSound(0x042DA081, &m->marioObj->gfx.unk54);

    if (func_802507AC(m) != 0)
    {
        m->actionArg ^= 1;
        if (m->input & INPUT_UNKNOWN_5)
            return set_mario_action(m, ACT_HANGING, m->actionArg);
    }

    if (func_8025E924(m) == 2)
        set_mario_action(m, ACT_FREEFALL, 0);

    return FALSE;
}

static int let_go_of_edge(struct MarioState *m)
{
    float floorHeight;
    struct Surface *floor;

    m->vel[1] = 0.0f;
    m->forwardVel = -8.0f;
    m->pos[0] -= 60.0f * sins(m->faceAngle[1]);
    m->pos[2] -= 60.0f * coss(m->faceAngle[1]);

    floorHeight = func_80381900(m->pos[0], m->pos[1], m->pos[2], &floor);
    if (floorHeight < m->pos[1] - 100.0f)
        m->pos[1] -= 100.0f;
    else
        m->pos[1] = floorHeight;

    return set_mario_action(m, ACT_SOFT_BONK, 0);
}

static void func_8025F0DC(struct MarioState *m)
{
    func_802507E8(m, 195);
    m->pos[0] += 14.0f * sins(m->faceAngle[1]);
    m->pos[2] += 14.0f * coss(m->faceAngle[1]);
    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
}

static void func_8025F188(struct MarioState *m)
{
    float sp4;

    if (m->actionTimer < 14)
        sp4 = m->actionTimer;
    else
        sp4 = 14.0f;
    m->unk94->unk04[0] = m->pos[0] + sp4 * sins(m->faceAngle[1]);
    m->unk94->unk04[2] = m->pos[2] + sp4 * coss(m->faceAngle[1]);
    m->unk94->unk04[1] = m->pos[1];
    m->actionTimer++;
    m->flags |= MARIO_UNKNOWN_25;
}

static void func_8025F26C(struct MarioState *m, int b, int action)
{
    stop_and_set_height_to_floor(m);
    func_802507E8(m, b);
    if (func_80250770(m) != 0)
    {
        set_mario_action(m, action, 0);
        if (action == ACT_IDLE)
            func_8025F0DC(m);
    }
}

static int act_ledge_grab(struct MarioState *m)
{
    float sp2C;
    s16 intendedDYaw = m->intendedYaw - m->faceAngle[1];
    int hasSpaceForMario = (m->ceilHeight - m->floorHeight >= 160.0f);

    if (m->actionTimer < 10)
        m->actionTimer++;

    if (m->floor->normal[1] < 0.9063078f)
        return let_go_of_edge(m);

    if (m->input & (INPUT_Z_PRESSED | INPUT_OFF_FLOOR))
        return let_go_of_edge(m);

    if ((m->input & INPUT_A_PRESSED) && hasSpaceForMario)
        return set_mario_action(m, ACT_LEDGE_CLIMB_FAST, 0);

    if (m->input & INPUT_UNKNOWN_10)
    {
        if (m->marioObj->interactStatus & 2)
            m->hurtCounter += (m->flags & 0x10) ? 12 : 18;
        return let_go_of_edge(m);
    }
    if (m->actionTimer == 10 && (m->input & INPUT_NONZERO_ANALOG))
    {
        if (intendedDYaw >= -0x4000 && intendedDYaw <= 0x4000)
        {
            if (hasSpaceForMario)
                return set_mario_action(m, ACT_LEDGE_CLIMB_SLOW_1, 0);
        }
        else
        {
            return let_go_of_edge(m);
        }
    }

    // climb ledge if a platform is pushing Mario up?
    sp2C = m->pos[1] - func_80251CF8(m, -0x8000, 30.0f);
    if (hasSpaceForMario && sp2C < 100.0f)
        return set_mario_action(m, ACT_LEDGE_CLIMB_FAST, 0);

    if (m->actionArg == 0)
        func_80250F50(m, 0x2408C081, 0x20000);

    stop_and_set_height_to_floor(m);
    func_802507E8(m, 51);

    return FALSE;
}

static int act_ledge_climb_slow(struct MarioState *m)
{
    if (m->input & INPUT_OFF_FLOOR)
        return let_go_of_edge(m);

    if (m->actionTimer >= 28
     && (m->input & (INPUT_ABOVE_SLIDE | INPUT_OFF_FLOOR | INPUT_A_PRESSED | INPUT_NONZERO_ANALOG)))
    {
        func_8025F0DC(m);
        return func_80252FEC(m);
    }

    if (m->actionTimer == 10)
        func_80250F50(m, 0x24098081, 0x20000);

    func_8025F26C(m, 0, ACT_IDLE);
    func_8025F188(m);
    if (m->marioObj->gfx.unk40 == 17)
        m->action = ACT_LEDGE_CLIMB_SLOW_2;

    return FALSE;
}

static int act_ledge_climb_down(struct MarioState *m)
{
    if (m->input & INPUT_OFF_FLOOR)
        return let_go_of_edge(m);

    func_80250F50(m, 0x2408C081, 0x20000);
    func_8025F26C(m, 28, ACT_LEDGE_GRAB);
    m->actionArg = 1;

    return FALSE;
}

static int act_ledge_climb_fast(struct MarioState *m)
{
    if (m->input & INPUT_OFF_FLOOR)
        return let_go_of_edge(m);

    func_80250F50(m, 0x2413D081, 0x20000);
    func_8025F26C(m, 52, ACT_IDLE);
    if (m->marioObj->gfx.unk40 == 8)
        func_80251280(m, 0x04088081);
    func_8025F188(m);

    return FALSE;
}

static int act_unknown_170(struct MarioState *m)
{
    if (m->marioObj->interactStatus & 4)
    {
        int sp24 = (m->marioObj->interactStatus & 0x40) == 0;
        
        m->faceAngle[1] = m->usedObj->angle[1];
        vec3f_copy(m->pos, m->marioObj->gfx.unk20);
        return set_mario_action(m,
            (m->forwardVel >= 0.0f) ? ACT_THROWN : ACT_HEAVED, sp24);
    }
    func_802507E8(m, 88);

    return FALSE;
}

static int act_in_cannon(struct MarioState *m)
{
    struct Object *marioObj = m->marioObj;
    s16 facePitch = m->faceAngle[0];
    s16 faceYaw = m->faceAngle[1];

    switch (m->actionState)
    {
    case 0:
        m->marioObj->gfx.graphFlags &= ~1;
        m->usedObj->interactStatus = 0x8000;
        m->unk94->unk1E = 1;
        m->unk94->unk20 = m->usedObj;
        vec3f_set(m->vel, 0.0f, 0.0f, 0.0f);
        m->pos[0] = m->usedObj->pos[0];
        m->pos[1] = m->usedObj->pos[1] + 350.0f;
        m->pos[2] = m->usedObj->pos[2];
        m->forwardVel = 0.0f;
        m->actionState = 1;
        break;
    case 1:
        if (m->usedObj->action == 1)
        {
            m->faceAngle[0] = m->usedObj->angle[0];
            m->faceAngle[1] = m->usedObj->angle[1];
            marioObj->unk10C = m->usedObj->angle[1];
            marioObj->unk110 = 0;
            m->actionState = 2;
        }
        break;
    case 2:
        m->faceAngle[0] -= (s16)(m->controller->stickY * 10.0f);
        marioObj->unk110 -= (s16)(m->controller->stickX * 10.0f);

        if (m->faceAngle[0] > 0x38E3)
            m->faceAngle[0] = 0x38E3;
        if (m->faceAngle[0] < 0)
            m->faceAngle[0] = 0;

        if (marioObj->unk110 > 0x4000)
            marioObj->unk110 = 0x4000;
        if (marioObj->unk110 < -0x4000)
            marioObj->unk110 = -0x4000;

        m->faceAngle[1] = marioObj->unk110 + marioObj->unk10C;
        if (m->input & INPUT_A_PRESSED)
        {
            m->forwardVel = 100.0f * coss(m->faceAngle[0]);
            m->vel[1] = 100.0f * sins(m->faceAngle[0]);
            m->pos[0] += 120.0f * coss(m->faceAngle[0]) * sins(m->faceAngle[1]);
            m->pos[1] += 120.0f * sins(m->faceAngle[0]);
            m->pos[2] += 120.0f * coss(m->faceAngle[0]) * coss(m->faceAngle[1]);
            SetSound(0x04568081, &m->marioObj->gfx.unk54);
            SetSound(0x501A5081, &m->marioObj->gfx.unk54);
            m->marioObj->gfx.graphFlags |= 1;
            set_mario_action(m, ACT_SHOT_FROM_CANNON, 0);
            m->usedObj->action = 2;
            return FALSE;
        }
        else
        {
            if (m->faceAngle[0] != facePitch || m->faceAngle[1] != faceYaw)
                SetSound(0x1D192001, &m->marioObj->gfx.unk54);
        }
    }
    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
    vec3s_set(m->marioObj->gfx.unk1A, 0, m->faceAngle[1], 0);
    func_802507E8(m, 136);

    return FALSE;
}

static int act_tornado_twirling(struct MarioState *m)
{
    struct Surface *floor;
    Vec3f nextPos;
    float sp4C;
    float sp48;
    float floorHeight;
    struct Object *marioObj = m->marioObj;
    struct Object *usedObj = m->usedObj;
    s16 prevTwirlYaw = m->twirlYaw;
    float dx = (m->pos[0] - usedObj->pos[0]) * 0.95f;
    float dz = (m->pos[2] - usedObj->pos[2]) * 0.95f;

    if (m->vel[1] < 60.0f)
        m->vel[1] += 1.0f;
    if ((*(float *)&marioObj->unk110 += m->vel[1]) < 0.0f)
        *(float *)&marioObj->unk110 = 0.0f;
    if (*(float *)&marioObj->unk110 > usedObj->hitboxHeight)
    {
        if (m->vel[1] < 20.0f)
            m->vel[1] = 20.0f;
        return set_mario_action(m, ACT_TWIRLING, 1);
    }
    if (m->angleVel[1] < 0x3000)
        m->angleVel[1] += 0x100;
    if (marioObj->unk10C < 0x1000)
        marioObj->unk10C += 0x100;
    m->twirlYaw += m->angleVel[1];
    sp4C = sins(marioObj->unk10C);
    sp48 = coss(marioObj->unk10C);
    nextPos[0] = usedObj->pos[0] + dx * sp48 + dz * sp4C;
    nextPos[2] = usedObj->pos[2] - dx * sp4C + dz * sp48;
    nextPos[1] = usedObj->pos[1] + *(float *)&marioObj->unk110;
    func_80380DE8(&nextPos[0], &nextPos[1], &nextPos[2], 60.0f, 50.0f);
    floorHeight = func_80381900(nextPos[0], nextPos[1], nextPos[2], &floor);
    if (floor != NULL)
    {
        m->floor = floor;
        m->floorHeight = floorHeight;
        vec3f_copy(m->pos, nextPos);
    }
    else
    {
        if (nextPos[1] >= m->floorHeight)
            m->pos[1] = nextPos[1];
        else
            m->pos[1] = m->floorHeight;
    }
    m->actionTimer++;
    func_802507E8(m, (m->actionArg == 0) ? 149 : 148);
    if (func_802507AC(m) != 0)
        m->actionArg = 1;
    if (prevTwirlYaw > m->twirlYaw)
        SetSound(0x04388081, &m->marioObj->gfx.unk54);
    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
    vec3s_set(m->marioObj->gfx.unk1A, 0, m->faceAngle[1] + m->twirlYaw, 0);

    return FALSE;
}

static int func_80260190(struct MarioState *m)
{
    if (m->pos[1] < m->waterLevel - 100)
        return func_8025325C(m);

    return FALSE;
}

int execute_automatic_action(struct MarioState *m)
{
    int cancel;

    if (func_80260190(m) != 0)
        return 1;

    m->quicksandDepth = 0.0f;
    switch (m->action)
    {
    case ACT_HOLDING_POLE:           cancel = act_holding_pole(m);           break;
    case ACT_GRAB_POLE_SLOW:         cancel = act_grab_pole_slow(m);         break;
    case ACT_GRAB_POLE_FAST:         cancel = act_grab_pole_fast(m);         break;
    case ACT_CLIMBING_POLE:          cancel = act_climbing_pole(m);          break;
    case ACT_TOP_OF_POLE_TRANSITION: cancel = act_top_of_pole_transition(m); break;
    case ACT_TOP_OF_POLE:            cancel = act_top_of_pole(m);            break;
    case ACT_START_HANGING:          cancel = act_start_hanging(m);          break;
    case ACT_HANGING:                cancel = act_hanging(m);                break;
    case ACT_HANG_MOVING:            cancel = act_hang_moving(m);            break;
    case ACT_LEDGE_GRAB:             cancel = act_ledge_grab(m);             break;
    case ACT_LEDGE_CLIMB_SLOW_1:     cancel = act_ledge_climb_slow(m);       break;
    case ACT_LEDGE_CLIMB_SLOW_2:     cancel = act_ledge_climb_slow(m);       break;
    case ACT_LEDGE_CLIMB_DOWN:       cancel = act_ledge_climb_down(m);       break;
    case ACT_LEDGE_CLIMB_FAST:       cancel = act_ledge_climb_fast(m);       break;
    case ACT_UNKNOWN_170:            cancel = act_unknown_170(m);            break;
    case ACT_IN_CANNON:              cancel = act_in_cannon(m);              break;
    case ACT_TORNADO_TWIRLING:       cancel = act_tornado_twirling(m);       break;
    }

    return cancel;
}
