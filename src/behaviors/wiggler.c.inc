
// TODO: Fix textbox array

void bhv_wiggler_body_part_update(void)
{
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dxz;
    struct ChainSegment *segment = &o->parentObj->oWigglerSegments[o->oBehParams2ndByte];
    f32 posOffset;

    obj_scale(o->parentObj->header.gfx.scale[0]);

    o->oFaceAnglePitch = segment->pitch;
    o->oFaceAngleYaw = segment->yaw;

    posOffset = -37.5f * o->header.gfx.scale[0];

    dy = posOffset * coss(o->oFaceAnglePitch) - posOffset;
    dxz = posOffset * sins(o->oFaceAnglePitch);
    dx = dxz * sins(o->oFaceAngleYaw);
    dz = dxz * coss(o->oFaceAngleYaw);

    o->oPosX = segment->posX + dx;
    o->oPosY = segment->posY + dy;
    o->oPosZ = segment->posZ + dz;

    if (o->oPosY < o->parentObj->oWigglerUnkF4)
    {
        o->oPosY += -30.0f;
        obj_update_floor_height();
        if (o->oFloorHeight > o->oPosY)
        {
            o->oPosY = o->oFloorHeight;
        }
    }

    segment->posY = o->oPosY;

    func_8029ED98(0, o->parentObj->oWigglerUnkFC);
    if (o->parentObj->oWigglerUnkFC == 0.0f)
    {
        func_8029F6F0();
    }

    if (o->parentObj->oAction == WIGGLER_ACT_SHRINK)
    {
        obj_become_intangible();
    }
    else
    {
        func_802FA888(&sWigglerBodyPartHitbox, o->oAction);
    }
}

static void wiggler_init_segments(void)
{
    s32 i;
    struct ChainSegment *segments;
    struct Object *bodyPart;

    segments = mem_pool_alloc(D_8035FE0C, 4 * sizeof(struct ChainSegment));
    if (segments != NULL)
    {
        o->oWigglerSegments = segments;
        for (i = 0; i < 4; i++)
        {
            chain_segment_init(&segments[i]);

            segments[i].posX = o->oPosX;
            segments[i].posY = o->oPosY;
            segments[i].posZ = o->oPosZ;

            segments[i].pitch = o->oFaceAnglePitch;
            segments[i].yaw = o->oFaceAngleYaw;
        }

        o->header.gfx.unk38.animFrame = -1;

        for (i = 1; i < 4; i++)
        {
            bodyPart = spawn_obj_adv(i, 0, 0, 0, o, 0x58, bWigglerBodyPart);
            if (bodyPart != NULL)
            {
                func_8029EE20(bodyPart, wiggler_seg5_anims_0500C874, 0);
                bodyPart->header.gfx.unk38.animFrame = (23 * i) % 26 - 1;
            }
        }

        o->oAction = WIGGLER_ACT_WALK;
        obj_unhide();
    }
}

static void wiggler_update_segments(void)
{
    struct ChainSegment *prevBodyPart;
    struct ChainSegment *bodyPart;
    f32 dx;
    f32 dy;
    f32 dz;
    s16 dpitch;
    s16 dyaw;
    f32 dxz;
    s32 i;
    f32 segmentLength;

    segmentLength = 35.0f * o->header.gfx.scale[0];

    for (i = 1; i < 4; i++)
    {
        prevBodyPart = &o->oWigglerSegments[i - 1];
        bodyPart = &o->oWigglerSegments[i];

        dx = bodyPart->posX - prevBodyPart->posX;
        dy = bodyPart->posY - prevBodyPart->posY;
        dz = bodyPart->posZ - prevBodyPart->posZ;

        dyaw = atan2s(-dz, -dx) - prevBodyPart->yaw;
        func_802F91AC(&dyaw, -0x2000, 0x2000);
        bodyPart->yaw = prevBodyPart->yaw + dyaw;

        dxz = sqrtf(dx*dx + dz*dz);

        dpitch = atan2s(dxz, dy) - prevBodyPart->pitch;
        func_802F91AC(&dpitch, -0x2000, 0x2000);
        bodyPart->pitch = prevBodyPart->pitch + dpitch;

        bodyPart->posY = segmentLength * sins(bodyPart->pitch) + prevBodyPart->posY;
        dxz = segmentLength * coss(bodyPart->pitch);
        bodyPart->posX = prevBodyPart->posX - dxz * sins(bodyPart->yaw);
        bodyPart->posZ = prevBodyPart->posZ - dxz * coss(bodyPart->yaw);
    }
}

static void wiggler_act_walk(void)
{
    s16 yawTurnSpeed;

    o->oWigglerUnkFC = 0.06f * o->oForwardVel;

    if (o->oWigglerUnk1AE < 2)
    {
        if (o->oWigglerUnk1AE == 0)
        {
            func_8031FFB4(0, 60, 40);
            o->oWigglerUnk1AE = 1;
        }

        // If Mario is positioned below the wiggler, assume he entered through
        // lower cave entrance, so don't display text.
        if (gMarioObject->oPosY < o->oPosY || obj_update_dialogue_unk2(2, 0, 0xA2, 0x96))
        {
            o->oWigglerUnk1AE = 2;
        }
    }
    else
    {
        forward_vel_approach(sWigglerSpeeds[o->oHealth - 1], 1.0f);
        
        if (o->oWigglerWalkStraightTimer != 0)
        {
            o->oWigglerWalkStraightTimer -= 1;
        }
        else
        {
            if (o->oDistanceToMario >= 25000.0f)
            {
                // If >1200 away from home, turn to home
                o->oWigglerTargetYaw = o->oAngleToMario;
            }

            if (func_802F9F6C(&o->oWigglerTargetYaw))
            {
                // TODO: Can this ever happen? Maybe on self-intersection?
                //! (Marking because if this does happen on self-intersction, it
                // could save an A press)
                o->oWigglerWalkStraightTimer = random_linear_offset(30, 30);
            }
            else
            {
                if (o->oHealth < 4)
                {
                    o->oWigglerTargetYaw = o->oAngleToMario;
                }
                else if (o->oWigglerTimeUntilRandomTurn != 0)
                {
                    o->oWigglerTimeUntilRandomTurn -= 1;
                }
                else
                {
                    o->oWigglerTargetYaw = o->oMoveAngleYaw + 0x4000 * (s16)RandomSign();
                    o->oWigglerTimeUntilRandomTurn = random_linear_offset(30, 50);
                }
            }
        }

        yawTurnSpeed = (s16)(30.0f * o->oForwardVel);
        obj_rotate_yaw_toward(o->oWigglerTargetYaw, yawTurnSpeed);
        face_yaw_approach(o->oMoveAngleYaw, 2 * yawTurnSpeed);

        face_pitch_approach(0, 800);
        
        if (o->oTimer < 60)
        {
            func_802FA888(&sWigglerHitbox, o->oAction);
        }
        else if (func_802FA468(&sWigglerHitbox, o->oAction, D_80331820))
        {
            if (o->oAction != WIGGLER_ACT_JUMPED_ON)
            {
                o->oAction = WIGGLER_ACT_KNOCKBACK;
            }
            
            o->oWigglerWalkStraightTimer = 0;
            o->oWigglerUnkFC = 0.0f;
        }
    }
}

static void wiggler_act_jumped_on(void)
{
    s32 textbox[3] = { 152, 168, 151 };

    if (approach_f32_2(&o->oWigglerSquishSpeed, 0.0f, 0.05f))
    {
        approach_f32_2(&o->header.gfx.scale[1], 4.0f, 0.2f);
    }
    else
    {
        o->header.gfx.scale[1] -= o->oWigglerSquishSpeed;
    }

    if (o->header.gfx.scale[1] >= 4.0f)
    {
        if (o->oTimer > 30)
        {
            if (obj_update_dialogue_unk2(2, 0, 0xA2, textbox[o->oHealth - 2]) != 0)
            {
                if (--o->oHealth == 1)
                {
                    o->oAction = WIGGLER_ACT_SHRINK;
                    obj_become_intangible();
                }
                else
                {
                    o->oAction = WIGGLER_ACT_WALK;
                    o->oMoveAngleYaw = o->oFaceAngleYaw;
                    
                    if (o->oHealth == 2)
                    {
                        PlaySound2(0x502F6081);
                        o->oForwardVel = 10.0f;
                        o->oVelY = 70.0f;
                    }
                }
            }
        }
    }
    else
    {
        o->oTimer = 0;
    }

    func_802FA888(&sWigglerHitbox, o->oAction);
}

static void wiggler_act_knockback(void)
{
    if (o->oVelY > 0.0f)
    {
        o->oFaceAnglePitch -= o->oVelY * 30.0f;
    }
    else
    {
        face_pitch_approach(0, 0x190);
    }

    if (forward_vel_approach(0.0f, 1.0f) && o->oFaceAnglePitch == 0)
    {
        o->oAction = WIGGLER_ACT_WALK;
        o->oMoveAngleYaw = o->oFaceAngleYaw;
    }

    func_802FA888(&sWigglerHitbox, o->oAction);
}

static void wiggler_act_shrink(void)
{
    if (o->oTimer >= 20)
    {
        if (o->oTimer == 20)
        {
            PlaySound2(0x50744081);
        }

        if (approach_f32_2(&o->header.gfx.scale[0], 1.0f, 0.1f))
        {
            CreateStar(0.0f, 2048.0f, 0.0f);
            o->oAction = WIGGLER_ACT_FALL_THROUGH_FLOOR;
        }

        obj_scale(o->header.gfx.scale[0]);
    }
}

static void wiggler_act_fall_through_floor(void)
{
    if (o->oTimer == 60)
    {
        func_80320CE8(0x416);
        o->oWigglerUnkF4 = 1700.0f;
    }
    else if (o->oTimer > 60)
    {
        if (o->oPosY < o->oWigglerUnkF4)
        {
            o->oAction = WIGGLER_ACT_WALK;
        }
        else
        {
            o->oFaceAnglePitch = func_802F86C0();
        }

        obj_move_xz_using_fvel_and_gravity();
    }
}

void wiggler_jumped_on(void)
{
    PlaySound2(0x50706081);
    o->oAction = WIGGLER_ACT_JUMPED_ON;
    o->oForwardVel = o->oVelY = 0.0f;
    o->oWigglerSquishSpeed = 0.4f;
}

void bhv_wiggler_update(void)
{
    if (o->oAction == WIGGLER_ACT_UNINITIALIZED)
    {
        wiggler_init_segments();
    }
    else
    {
        if (o->oAction == WIGGLER_ACT_FALL_THROUGH_FLOOR)
        {
            wiggler_act_fall_through_floor();
        }
        else
        {
            treat_far_home_as_mario(1200.0f);

            func_8029ED98(0, o->oWigglerUnkFC);
            if (o->oWigglerUnkFC != 0.0f)
            {
                func_802F9378(0, 13, o->oHealth >= 4 ? 0x50712081 : 0x505C4081);
            }
            else
            {
                func_8029F6F0();
            }

            obj_update_floor_and_walls();
            switch (o->oAction)
            {
            case WIGGLER_ACT_WALK:               wiggler_act_walk();               break;
            case WIGGLER_ACT_KNOCKBACK:          wiggler_act_knockback();          break;
            case WIGGLER_ACT_JUMPED_ON:          wiggler_act_jumped_on();          break;
            case WIGGLER_ACT_SHRINK:             wiggler_act_shrink();             break;
            case WIGGLER_ACT_FALL_THROUGH_FLOOR: wiggler_act_fall_through_floor(); break;
            }

            obj_move_standard(-78);
        }

        o->oWigglerSegments[0].posX = o->oPosX;
        o->oWigglerSegments[0].posY = o->oPosY;
        o->oWigglerSegments[0].posZ = o->oPosZ;
        o->oWigglerSegments[0].pitch = o->oFaceAnglePitch;
        o->oWigglerSegments[0].yaw = o->oFaceAngleYaw;

        wiggler_update_segments();
    }
}
