
/**
 * Behavior for bEvilLakitu.
 * Lakitu comes before it spawned spinies in processing order.
 */


/**
 * Hitbox for evil lakitu.
 */
static struct ObjectHitbox sEvilLakituHitbox =
{
    /* interactType:      */ INTERACT_HIT_FROM_BELOW,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 5,
    /* radius:            */ 50,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 50,
};


/**
 * Wait for mario to approach, then spawn the cloud and become visible.
 */
static void evil_lakitu_act_uninitialized(void)
{
    if (o->oDistanceToMario < 2000.0f)
    {
        spawn_object_relative_with_scale(
            1,
            0, 0, 0,
            2.0f,
            o,
            MODEL_MIST,
            beh_fwoosh_blowing_wind);

        obj_unhide();
        o->oAction = EVIL_LAKITU_ACT_MAIN;
    }
}

/**
 * Accelerate toward mario vertically.
 */
static void evil_lakitu_update_vel_y(f32 offsetY)
{
    // In order to encourage oscillation, pass mario by a small margin before
    // accelerating the opposite direction
    f32 margin;
    if (o->oVelY < 0.0f)
    {
        margin = -3.0f;
    }
    else
    {
        margin = 3.0f;
    }

    if (o->oPosY < gMarioObject->oPosY + offsetY + margin)
    {
        obj_y_vel_approach(4.0f, 0.4f);
    }
    else
    {
        obj_y_vel_approach(-4.0f, 0.4f);
    }
}

/**
 * Control speed based on distance to mario, turn toward mario, and change move
 * angle toward mario.
 */
static void evil_lakitu_update_speed_and_angle(void)
{
    f32 minSpeed;
    s16 turnSpeed;

    f32 distToMario = o->oDistanceToMario;
    if (distToMario > 500.0f)
    {
        distToMario = 500.0f;
    }

    // Move faster the farther away mario is and the faster mario is moving
    if ((minSpeed = 1.2f * gMarioStates[0].forwardVel) < 8.0f)
    {
        minSpeed = 8.0f;
    }
    o->oForwardVel = distToMario * 0.04f;
    clamp_f32(&o->oForwardVel, minSpeed, 40.0f);

    // Accelerate toward mario vertically
    evil_lakitu_update_vel_y(300.0f);

    // Turn toward mario except right after throwing a spiny
    if (o->oEvilLakituFaceForwardCountdown != 0)
    {
        o->oEvilLakituFaceForwardCountdown -= 1;
    }
    else
    {
        obj_face_yaw_approach(o->oAngleToMario, 0x600);
    }

    // Change move angle toward mario faster when farther from mario
    turnSpeed = (s16)(distToMario * 2.0f);
    clamp_s16(&turnSpeed, 0xC8, 0xFA0);
    obj_rotate_yaw_toward(o->oAngleToMario, turnSpeed);
}

/**
 * When close enough to mario and facing roughly toward him, spawn a spiny and
 * hold it, then enter the hold spiny sub-action.
 */
static void evil_lakitu_sub_act_no_spiny(void)
{
    func_8029ED38(1);

    if (o->oEvilLakituSpinyCooldown != 0)
    {
        o->oEvilLakituSpinyCooldown -= 1;
    }
    else if (o->oEvilLakituNumSpinies < 3 &&
        o->oDistanceToMario < 800.0f &&
        abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) < 0x4000)
    {
        struct Object *spiny = spawn_object(o, MODEL_SPINY_BALL, bSpiny);
        if (spiny != NULL)
        {
            o->prevObj = spiny;
            spiny->oAction = SPINY_ACT_HELD_BY_LAKITU;

            func_8029EE20(spiny, spiny_egg_seg5_anims_050157E4, 0);

            o->oEvilLakituNumSpinies += 1;
            o->oSubAction = EVIL_LAKITU_SUB_ACT_HOLD_SPINY;
            o->oEvilLakituSpinyCooldown = 30;
        }
    }
}

/**
 * When close to mario and facing toward him or when mario gets far enough away,
 * enter the throw spiny sub-action.
 */
static void evil_lakitu_sub_act_hold_spiny(void)
{
    func_802F927C(3);

    if (o->oEvilLakituSpinyCooldown != 0)
    {
        o->oEvilLakituSpinyCooldown -= 1;
    }
    // TODO: Check if anything interesting happens if we bypass this with speed
    else if (o->oDistanceToMario > o->oDrawingDistance - 100.0f ||
        (o->oDistanceToMario < 500.0f &&
            abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) < 0x2000))
    {
        o->oSubAction = EVIL_LAKITU_SUB_ACT_THROW_SPINY;
        o->oEvilLakituFaceForwardCountdown = 20;
    }
}

/**
 * Throw the spiny, then enter the no spiny sub-action.
 */
static void evil_lakitu_sub_act_throw_spiny(void)
{
    if (func_802F92EC(2, 2))
    {
        PlaySound2(SOUND_OBJECT_EVILLAKITUTHROW);
        o->prevObj = NULL;
    }

    if (func_8029F788())
    {
        o->oSubAction = EVIL_LAKITU_SUB_ACT_NO_SPINY;
        o->oEvilLakituSpinyCooldown = random_linear_offset(100, 100);
    }
}

/**
 * Main update function.
 */
static void evil_lakitu_act_main(void)
{
    PlaySound(SOUND_CH6_UNKNOWN002);

    obj_update_floor_and_walls();

    evil_lakitu_update_speed_and_angle();
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL)
    {
        o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
    }

    obj_update_blinking(&o->oEvilLakituBlinkTimer, 20, 40, 4);

    switch (o->oSubAction)
    {
    case EVIL_LAKITU_SUB_ACT_NO_SPINY:    evil_lakitu_sub_act_no_spiny();    break;
    case EVIL_LAKITU_SUB_ACT_HOLD_SPINY:  evil_lakitu_sub_act_hold_spiny();  break;
    case EVIL_LAKITU_SUB_ACT_THROW_SPINY: evil_lakitu_sub_act_throw_spiny(); break;
    }

    obj_move_standard(78);

    // Die and drop held spiny when attacked by mario
    if (obj_check_mario_attacks(&sEvilLakituHitbox, o->oAction))
    {
        // The spiny uses this as a signal to get thrown
        o->prevObj = NULL;
    }
}

/**
 * Update function for bEvilLakitu.
 */
void bhv_evil_lakitu_update(void)
{
    //PARTIAL_UPDATE

    treat_far_home_as_mario(2000.0f);

    switch (o->oAction)
    {
    case EVIL_LAKITU_ACT_UNINITIALIZED: evil_lakitu_act_uninitialized(); break;
    case EVIL_LAKITU_ACT_MAIN:          evil_lakitu_act_main();          break;
    }
}
