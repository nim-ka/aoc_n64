
/**
 * Behavior for bKoopa. This includes normal, unshelled, tiny, and Koopa the
 * Quick.
 */


/**
 * Hitbox for koopa - this is used for every form except Koopa the Quick, which
 * uses a hardcoded soft hitbox.
 */
static struct ObjectHitbox sKoopaHitbox =
{
    /* interactType: */ INTERACT_KOOPA,
    /* downOffset:   */ 0,
    /* unk05:        */ 0,
    /* health:       */ 0,
    /* numLootCoins: */ -1,
    /* radius:       */ 60,
    /* height:       */ 40,
    /* unk0C:        */ 40,
    /* unk0E:        */ 30,
};

static u8 sKoopaUnshelledAttackHandlers[] =
{
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_UNK2,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_UNK2,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_UNK3,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_UNK3,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_UNK2,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_UNK2,
};

static u8 sKoopaShelledAttackHandlers[] =
{
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_UNK4,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_UNK4,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_UNK4,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_UNK4,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_UNK4,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_UNK4,
};

/**
 * Data to control the behavior of each instance of Koopa the Quick.
 */
struct KoopaTheQuickProperties
{
    s16 initText;
    s16 unk02;
    void *unk04;
    Vec3s starPos;
};

static struct KoopaTheQuickProperties sKoopaTheQuickProperties[] =
{
    { 5, 7, bob_seg7_trajectory_koopa, {3030, 4500, 60936} },
    { 9, 31, thi_seg7_trajectory_koopa, {7100, 64236, 59536} }
};


/**
 * Initialization function.
 */
void bhv_koopa_init(void)
{
    if ((o->oKoopaMovementType = o->oBehParams2ndByte) == KOOPA_BP_TINY)
    {
        // Tiny koopa in THI
        o->oKoopaMovementType = KOOPA_BP_NORMAL;
        o->oKoopaUnkF4 = 1.6f / 3.0f;
        o->oDrawingDistance = 1500.0f;
        obj_scale(0.8f);
        o->oGravity = -6.4f / 3.0f;
    }
    else if (o->oKoopaMovementType >= KOOPA_BP_KOOPA_THE_QUICK_BASE)
    {
        // Koopa the Quick. Race index is 0 for BoB and 1 for THI
        o->oKoopaTheQuickRaceIndex = o->oKoopaMovementType - KOOPA_BP_KOOPA_THE_QUICK_BASE;
        o->oKoopaUnkF4 = 4.0f;
        obj_scale(3.0f);
    }
    else
    {
        o->oKoopaUnkF4 = 1.0f;
    }
}

/**
 * Play the appropriate footstep sound on the two provided animation frames.
 */
static void koopa_play_footstep_sound(s8 animFrame1, s8 animFrame2)
{
    s32 sound;
    if (o->header.gfx.scale[0] > 1.5f)
        sound = SOUND_OBJECT_UNK50342081;
    else
        sound = SOUND_OBJECT_UNK50350081;

    func_802F9378(animFrame1, animFrame2, sound);
}

/**
 * If mario is close to koopa, and koopa is facing toward mario, then begin
 * running away.
 */
static s32 koopa_check_run_from_mario(void)
{
    if (o->oKoopaDistanceToMario < 300.0f &&
        abs_angle_diff(o->oKoopaAngleToMario, o->oMoveAngleYaw) < 0x3000)
    {
        o->oAction = KOOPA_SHELLED_ACT_RUNNING_FROM_MARIO;
        return TRUE;
    }

    return FALSE;
}

/**
 * Stay still for a while, then change target yaw by 45 degrees and begin
 * walking.
 */
static void koopa_shelled_act_stopped(void)
{
    o->oForwardVel = 0.0f;
    if (func_802F92B0(7))
    {
        o->oAction = KOOPA_SHELLED_ACT_WALKING;
        o->oKoopaTargetYaw = o->oMoveAngleYaw + 0x2000 * (s16)RandomSign();
    }
}

static void koopa_walk_accelerate(void)
{
    forward_vel_approach(3.0f * o->oKoopaUnkF4, 0.3f * o->oKoopaUnkF4);
    
    if (func_802F92B0(11))
    {
        o->oSubAction += 1;
        o->oKoopaCountdown = random_linear_offset(30, 100);
    }
}

static void koopa_walk_straight(void)
{
    func_8029ED38(9);
    koopa_play_footstep_sound(2, 17);

    if (o->oKoopaCountdown != 0)
    {
        o->oKoopaCountdown -= 1;
    }
    else if (func_8029F788())
    {
        o->oSubAction += 1;
    }
}

static void koopa_walk_decelerate(void)
{
    forward_vel_approach(0.0f, 1.0f * o->oKoopaUnkF4);
    if (func_802F92B0(10))
    {
        o->oAction = KOOPA_SHELLED_ACT_STOPPED;
    }
}

/**
 * Walk for a while, then come to a stop. During this time, turn toward the
 * target yaw.
 */
static void koopa_shelled_act_walking(void)
{
    if (o->oKoopaTurning)
    {
        o->oKoopaTurning =
            resolve_collisions_and_turn(o->oKoopaTargetYaw, 0x200);
    }
    else
    {
        // If far from home, then begin turning toward home
        if (o->oDistanceToMario >= 25000.0f)
        {
            o->oKoopaTargetYaw = o->oAngleToMario;
        }

        o->oKoopaTurning = func_802F9F6C(&o->oKoopaTargetYaw);
        obj_rotate_yaw_toward(o->oKoopaTargetYaw, 0x200);
    }

    switch (o->oSubAction)
    {
    case 0: koopa_walk_accelerate(); break;
    case 1: koopa_walk_straight(); break;
    case 2: koopa_walk_decelerate(); break;
    }

    koopa_check_run_from_mario();
}

/**
 * Run while turning away from mario. Come to a stop once mario is far enough
 * away.
 */
static void koopa_shelled_act_running_from_mario(void)
{
    func_8029ED38(1);
    koopa_play_footstep_sound(0, 11);

    // If far from home, run toward it
    if (o->oDistanceToMario >= 25000.0f)
    {
        o->oAngleToMario += 0x8000;
        o->oDistanceToMario = 0.0f;
    }

    if (o->oTimer > 30 && o->oDistanceToMario > 800.0f)
    {
        if (forward_vel_approach(0.0f, 1.0f))
        {
            o->oAction = KOOPA_SHELLED_ACT_STOPPED;
        }
    }
    else
    {
        obj_rotate_yaw_toward(o->oAngleToMario + 0x8000, 0x400);
        forward_vel_approach(17.0f, 1.0f);
    }
}

/**
 * If on the ground, decelerate. Generate dust if moving fast enough.
 */
static void koopa_lying_slide_on_ground(f32 decel)
{
    if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND)
    {
        forward_vel_approach(0.0f, decel);
        if (o->oForwardVel > 5.0f)
        {
            if (!(o->oTimer % 4))
                func_8029E73C(o, 150, beh_white_puff_smoke2, 1.0f);
        }
    }
}

/**
 * Slide on the ground and then come to a stop.
 */
static void koopa_shelled_act_lying(void)
{
    if (o->oForwardVel != 0.0f)
    {
        if (o->oMoveFlags & OBJ_MOVE_HIT_WALL)
        {
            o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
        }

        func_802F927C(5);
        koopa_lying_slide_on_ground(0.3f);
    }
    else if (o->oKoopaCountdown != 0)
    {
        o->oKoopaCountdown -= 1;
        func_8029F728();
    }
    else if (func_802F92B0(6))
    {
        o->oAction = KOOPA_SHELLED_ACT_STOPPED;
    }
}

void koopa_attacked(s32 attackType)
{
    if (o->header.gfx.scale[0] > 0.8f)
    {
        PlaySound2(0x503EA081);

        o->oKoopaMovementType = KOOPA_BP_UNSHELLED;
        o->oAction = KOOPA_UNSHELLED_ACT_LYING;
        o->oForwardVel = 20.0f;

        // If attacked from the side, get knocked away from mario
        if (attackType != ATTACK_FROM_ABOVE &&
            attackType != ATTACK_GROUND_POUND_OR_TWIRL)
        {
            o->oMoveAngleYaw = angle_to_object(gMarioObject, o);
        }

        obj_set_model(0xBF);
        SpawnObj(o, 0xBE, beh_koopa_shell);
        obj_become_intangible();
    }
    else
    {
        func_802FA078();
    }
}

static void koopa_shelled_update(void)
{
    obj_update_floor_and_walls();
    update_blinking(&o->oKoopaBlinkTimer, 20, 50, 4);

    switch (o->oAction)
    {
    case KOOPA_SHELLED_ACT_STOPPED:
        koopa_shelled_act_stopped();
        koopa_check_run_from_mario();
        break;

    case KOOPA_SHELLED_ACT_WALKING:
        koopa_shelled_act_walking();
        break;

    case KOOPA_SHELLED_ACT_RUNNING_FROM_MARIO:
        koopa_shelled_act_running_from_mario();
        break;

    case KOOPA_SHELLED_ACT_LYING:
        koopa_shelled_act_lying();
        break;
    }

    if (o->header.gfx.scale[0] > 0.8f)
    {
        func_802FA468(
            &sKoopaHitbox, o->oAction, sKoopaShelledAttackHandlers);
    }
    else
    {
        func_802FA468(
            &sKoopaHitbox, KOOPA_SHELLED_ACT_UNK4, sKoopaUnshelledAttackHandlers);
        if (o->oAction == KOOPA_SHELLED_ACT_UNK4)
        {
            func_802FA078();
        }
    }

    obj_move_standard(-78);
}

static void koopa_unshelled_act_running(void)
{
    f32 val0C = 99999.0f;
    struct Object *val08;

    func_8029ED38(3);
    koopa_play_footstep_sound(0, 6);

    if (o->oKoopaTurning)
    {
        o->oKoopaTurning =
            resolve_collisions_and_turn(o->oKoopaTargetYaw, 0x600);
    }
    else
    {
        if (o->oDistanceToMario >= 25000.0f)
            o->oKoopaTargetYaw = o->oAngleToMario;

        val08 = obj_find_nearest_object_with_behavior(beh_koopa_shell, &val0C);
        if (val08 != NULL)
        {
            o->oKoopaTargetYaw = angle_to_object(o, val08);
        }
        else if (!(o->oKoopaTurning = func_802F9F6C(&o->oKoopaTargetYaw)))
        {
            if (o->oKoopaUnk100 != 0)
                o->oKoopaUnk100 -= 1;
            else
                o->oKoopaTargetYaw = random_fixed_turn(0x2000);
        }

        if (o->oDistanceToMario > 800.0f ||
            (val08 != NULL &&
            abs_angle_diff(o->oKoopaTargetYaw, o->oAngleToMario + 0x8000) < 0x2000))
        {
            obj_rotate_yaw_toward(o->oKoopaTargetYaw, 0x600);
        }
        else
        {
            obj_rotate_yaw_toward(o->oAngleToMario + 0x8000, 0x600);
        }
    }

    if (forward_vel_approach(20.0f, 1.0f) &&
        val0C < 600.0f &&
        abs_angle_diff(o->oKoopaTargetYaw, o->oMoveAngleYaw) < 0xC00)
    {
        o->oMoveAngleYaw = o->oKoopaTargetYaw;
        o->oAction = KOOPA_UNSHELLED_ACT_DIVING;
        o->oForwardVel *= 1.2f;
        o->oVelY = val0C / 20.0f;
        o->oKoopaCountdown = 20;
    }
}

static void koopa_unshelled_act_diving(void)
{
    struct Object *val04;
    f32 val00;

    if (o->oTimer > 10)
    {
        obj_become_tangible();
    }

    if (o->oTimer > 10)
    {
        val04 = obj_find_nearest_object_with_behavior(beh_koopa_shell, &val00);

        if (val04 != NULL &&
            dist_between_objects(val04, gMarioObject) > 200.0f &&
            val00 < 50.0f)
        {
            o->oKoopaMovementType = KOOPA_BP_NORMAL;
            o->oAction = KOOPA_UNSHELLED_ACT_UNKNOWN_3;
            o->oForwardVel *= 0.5f;

            obj_set_model(0x68);
            DeactivateObject(val04);
            goto end;
        }
    }

    if (o->oForwardVel != 0.0f)
    {
        if (o->oAction == KOOPA_UNSHELLED_ACT_LYING)
        {
            o->oAnimState = 1;
            func_802F927C(2);
        }
        else
        {
            func_802F927C(5);
        }
        koopa_lying_slide_on_ground(0.5f);
    }
    else if (o->oKoopaCountdown != 0)
    {
        o->oKoopaCountdown -= 1;
        func_8029F728();
    }
    else if (func_802F92B0(6))
    {
        o->oAction = KOOPA_UNSHELLED_ACT_RUNNING;
    }

end:
    ;
}

static void func_802FBA44(void)
{
    func_802F927C(0);
}

static void koopa_unshelled_update(void)
{
    obj_update_floor_and_walls();
    update_blinking(&o->oKoopaBlinkTimer, 10, 15, 3);

    switch (o->oAction)
    {
    case KOOPA_UNSHELLED_ACT_RUNNING: koopa_unshelled_act_running(); break;
    case KOOPA_UNSHELLED_ACT_DIVING:
    case KOOPA_UNSHELLED_ACT_LYING: koopa_unshelled_act_diving(); break;
    case KOOPA_UNSHELLED_ACT_UNKNOWN_3: func_802FBA44(); break;
    }

    func_802FA468(&sKoopaHitbox, o->oAction, sKoopaUnshelledAttackHandlers);
    obj_move_standard(-78);
}

s32 obj_begin_race(s32 noTimer)
{
    if (o->oTimer == 50)
    {
        PlaySound2(0x314D4081);

        if (!noTimer)
        {
            func_80320AE8(0, 0x409, 0);
            level_control_timer(TIMER_CONTROL_SHOW);
            level_control_timer(TIMER_CONTROL_START);
            o->parentObj->oUnknownUnkF4_S32 = 1;
        }

        func_802573C8(0);
        disable_time_stop_including_mario();
    }
    else if (o->oTimer > 50)
    {
        return TRUE;
    }

    return FALSE;
}

static void koopa_the_quick_act_wait_before_race(void)
{
    koopa_shelled_act_stopped();

    if (o->oKoopaTheQuickInitTextboxCooldown != 0)
    {
        o->oKoopaTheQuickInitTextboxCooldown -= 1;
    }
    else if (obj_is_mario_in_cylinder_and_ready_to_speak(400.0f, 400.0f))
    {
        o->oAction = KOOPA_THE_QUICK_ACT_UNK2;
        o->oForwardVel = 0.0f;
        func_8029ED38(7);
    }
}

static void koopa_the_quick_act_show_init_text(void)
{
    s32 response = func_802F870C(sKoopaTheQuickProperties[o->oKoopaTheQuickRaceIndex].initText);
    UNUSED s32 unused;

    if (response == 1)
    {
        D_8035FEEA = 0;
        o->oAction = KOOPA_THE_QUICK_ACT_UNK3;
        o->oForwardVel = 0.0f;
        
        o->parentObj = obj_nearest_object_with_behavior(bKoopaRaceEndpoint);
        o->oPathedStartWaypoint = o->oPathedPrevWaypoint =
            segmented_to_virtual(sKoopaTheQuickProperties[o->oKoopaTheQuickRaceIndex].unk04);

        o->oKoopaTurning = FALSE;

        o->oFlags |= 0x00000080;;
    }
    else if (response == 2)
    {
        o->oAction = KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE;
        o->oKoopaTheQuickInitTextboxCooldown = 60;
    }
}

static s32 func_802FBDE4(void)
{
    struct Object *val0C;
    f32 val08;
    s16 val06;
    f32 val00;

    val0C = obj_find_nearest_object_with_behavior(beh_bowling_ball, &val08);

    if (val0C != NULL)
    {
        val06 = UnknownMove(o, val0C, 16, 0);
        val00 = val0C->oForwardVel * coss(val0C->oMoveAngleYaw - o->oMoveAngleYaw);

        if (abs_angle_diff(o->oMoveAngleYaw, val06) < 0x4000)
        {
            if (val08 < 400.0f)
            {
                if (val00 < o->oForwardVel * 0.7f)
                    return 1;
                else
                    o->oForwardVel -= 2.0f;
            }
        }
        else if (val08 < 300.0f && val00 > o->oForwardVel)
        {
            return -1;
        }
    }

    return 0;
}

static void func_802FBF64(void)
{
    func_8029ED98(9, o->oForwardVel * 0.09f);
    koopa_play_footstep_sound(2, 17);
}

static void func_802FBFB8(void)
{
    f32 val0C;
    s32 val08;

    if (obj_begin_race(FALSE))
    {
        obj_push_mario_away_from_cylinder(180.0f, 300.0f);
        if (obj_follow_path(0) == PATH_REACHED_END)
        {
            o->oAction = KOOPA_THE_QUICK_ACT_UNK4;
        }
        else
        {
            val0C = 1.0f + sins((s16)(f32)o->oPathedTargetPitch);
            obj_rotate_yaw_toward(o->oKoopaAngleToMario, (s32)(o->oKoopaUnkF4 * 150.0f));

            switch (o->oSubAction)
            {
            case 0:
                koopa_walk_accelerate();
                break;

            case 1:
                func_802FBF64();

                if (o->parentObj->oUnknownUnkFC_S32 != 0 &&
                    o->oDistanceToMario > 1500.0f &&
                    (o->oKoopaUnk104_2 & 0x000000FF) < 28)
                {
                    o->oKoopaUnkF4 = 8.0f;
                }
                else if (o->oKoopaTheQuickRaceIndex != 0)
                {
                    o->oKoopaUnkF4 = 6.0f;
                }
                else
                {
                    o->oKoopaUnkF4 = 4.0f;
                }

                forward_vel_approach(o->oKoopaUnkF4 * 6.0f * val0C, o->oKoopaUnkF4 * 0.1f);
                if (o->oMoveFlags & OBJ_MOVE_HIT_WALL)
                {
                    o->oVelY = 20.0f;
                }
                
                val08 = func_802FBDE4();
                if (val08 != 0 || (o->oMoveFlags & OBJ_MOVE_HIT_EDGE))
                {
                    if (val08 < 0)
                    {
                        o->oForwardVel = 0.0f;
                    }
                    
                    if (val08 != 0 || (o->oKoopaUnk104_2 & 0x000000FF) >= 8)
                    {
                        o->oVelY = 80.0f;
                    }
                    else
                    {
                        o->oVelY = 40.0f;
                    }

                    o->oGravity = -6.0f;
                    o->oSubAction = 2;
                    o->oMoveFlags = 0;
                    func_8029ED38(12);
                }
                break;

            case 2:
                if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND)
                {
                    if (func_802F92B0(13))
                        o->oSubAction -= 1;
                    
                    func_802FBDE4();
                }
            }
        }
    }
}

static void func_802FC334(void)
{
    forward_vel_approach(3.0f, 1.0f);
    func_8029ED98(9, 0.99f);

    if (func_8029F788())
    {
        o->oAction = KOOPA_THE_QUICK_ACT_UNK5;
        o->oForwardVel = 3.0f;
    }
}

static void func_802FC3B4(void)
{
    koopa_walk_decelerate();
    if (o->oAction == KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE)
        o->oAction = KOOPA_THE_QUICK_ACT_UNK6;
}

static void func_802FC400(void)
{
    s32 val04;

    func_8029ED38(7);

    if (o->parentObj->oUnknownUnk100_S32 == 0)
    {
        if (obj_is_mario_in_cylinder_and_ready_to_speak(400.0f, 400.0f))
        {
            func_80320CE8(0x409);

            if (o->parentObj->oUnknownUnkFC_S32 != 0)
            {
                if (o->parentObj->oUnknownUnkFC_S32 < 0)
                {
                    o->parentObj->oUnknownUnkFC_S32 = 0;
                    o->parentObj->oUnknownUnk100_S32 = 6;
                }
                else
                {
                    o->parentObj->oUnknownUnk100_S32 = sKoopaTheQuickProperties[o->oKoopaTheQuickRaceIndex].unk02;
                }
            }
            else
            {
                o->parentObj->oUnknownUnk100_S32 = 41;
            }

            o->oFlags &= ~0x00000080;
        }
    }
    else if (o->parentObj->oUnknownUnk100_S32 > 0)
    {
        val04 = obj_update_dialogue_unk2(2, 1, 162, o->parentObj->oUnknownUnk100_S32);
        if (val04 != 0)
        {
            o->parentObj->oUnknownUnk100_S32 = -1;
            o->oTimer = 0;
        }
    }
    else if (o->parentObj->oUnknownUnkFC_S32 != 0)
    {
        CreateStar(
            sKoopaTheQuickProperties[o->oKoopaTheQuickRaceIndex].starPos[0],
            sKoopaTheQuickProperties[o->oKoopaTheQuickRaceIndex].starPos[1],
            sKoopaTheQuickProperties[o->oKoopaTheQuickRaceIndex].starPos[2]);

        o->parentObj->oUnknownUnkFC_S32 = 0;
    }
}

static void koopa_the_quick_update(void)
{
    obj_update_floor_and_walls();
    update_blinking(&o->oKoopaBlinkTimer, 10, 15, 3);

    switch (o->oAction)
    {
    case KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE:
    case KOOPA_THE_QUICK_ACT_UNK1: koopa_the_quick_act_wait_before_race(); break;
    case KOOPA_THE_QUICK_ACT_UNK2: koopa_the_quick_act_show_init_text(); break;
    case KOOPA_THE_QUICK_ACT_UNK3: func_802FBFB8(); break;
    case KOOPA_THE_QUICK_ACT_UNK4: func_802FC334(); break;
    case KOOPA_THE_QUICK_ACT_UNK5: func_802FC3B4(); break;
    case KOOPA_THE_QUICK_ACT_UNK6: func_802FC400(); break;
    }

    if (o->parentObj != o)
    {
        if (dist_between_objects(o, o->parentObj) < 400.0f)
        {
            o->parentObj->oUnknownUnkF8_S32 = 1;
        }
    }
    
    obj_push_mario_away_from_cylinder(140.0f, 300.0f);
    obj_move_standard(-78);
}

void bhv_koopa_update(void)
{
    //! (For this and similar objects) If we kill the object before update is
    // called for the first time, will it make the wrong sound?
    o->oDeathSound = SOUND_OBJECT_KOOPADEATH;
    
    if (o->oKoopaMovementType >= KOOPA_BP_KOOPA_THE_QUICK_BASE)
    {
        koopa_the_quick_update();
    }
    else if (func_802FA7CC(o->oKoopaUnkF4 * 1.5f))
    {
        o->oKoopaDistanceToMario = o->oDistanceToMario;
        o->oKoopaAngleToMario = o->oAngleToMario;
        treat_far_home_as_mario(1000.0f);

        switch (o->oKoopaMovementType)
        {
        case KOOPA_BP_UNSHELLED:           koopa_unshelled_update(); break;
        case KOOPA_BP_NORMAL:              koopa_shelled_update();   break;
        case KOOPA_BP_KOOPA_THE_QUICK_BOB:
        case KOOPA_BP_KOOPA_THE_QUICK_THI: koopa_the_quick_update(); break;
        }
    }
    else
    {
        o->oAnimState = 1;
    }

    face_yaw_approach(o->oMoveAngleYaw, 0x600);
}

void bhv_koopa_race_endpoint_update(void)
{
    if (o->oKoopaRaceEndpointUnkF4 && o->oKoopaRaceEndpointUnk104 == 0)
    {
        if (o->oKoopaRaceEndpointUnkF8 != 0 || o->oDistanceToMario < 400.0f)
        {
            o->oKoopaRaceEndpointUnk104 = 1;
            level_control_timer(TIMER_CONTROL_STOP);

            if (o->oKoopaRaceEndpointUnkF8 == 0)
            {
                func_803212F0();
                if (D_8035FEEA != 0)
                {
                    o->oKoopaRaceEndpointUnkFC = -1;
                }
                else
                {
                    o->oKoopaRaceEndpointUnkFC = 1;
                }
            }
        }
    }
}
