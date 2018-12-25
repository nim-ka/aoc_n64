
/**
 * Behavior for bCloud and bCloudPart.
 * bCloud includes both fwoosh and the cloud that lakitu rides (both nice and
 * evil).
 * bCloudPart is spawned by bCloud and is either a "chunk" of cloud, or fwoosh's
 * face. It is purely visual.
 * If spawned by a lakitu, its parent will be the lakitu.
 * Processing order is lakitu -> cloud -> its cloud parts.
 */


/**
 * The relative heights of each cloud part.
 */
static s8 sCloudPartHeights[] = { 11, 8, 12, 8, 9, 9 };


/**
 * Spawn the visual parts of the cloud, including fwoosh's face.
 */
static void cloud_act_spawn_parts(void)
{
    struct Object *cloudPart;
    s32 i;

    // Spawn the pieces of the cloud itself
    for (i = 0; i < 5; i++)
    {
        cloudPart = spawn_object_relative(
            i,
            0, 0, 0,
            o,
            MODEL_MIST,
            bCloudPart);

        if (cloudPart != NULL)
        {
            func_802A1230(cloudPart);
        }
    }

    if (o->oBehParams2ndByte == CLOUD_BP_FWOOSH)
    {
        // Spawn fwoosh's face
        spawn_object_relative(
            5,
            0, 0, 0,
            o,
            MODEL_FWOOSH,
            bCloudPart);

        obj_scale(3.0f);

        o->oCloudCenterX = o->oPosX;
        o->oCloudCenterY = o->oPosY;
    }

    o->oAction = CLOUD_ACT_MAIN;
}

/**
 * Wait for mario to approach, then unhide and enter the spawn parts action.
 */
static void cloud_act_fwoosh_hidden(void)
{
    if (o->oDistanceToMario < 2000.0f)
    {
        obj_unhide();
        o->oAction = CLOUD_ACT_SPAWN_PARTS;
    }
}

/**
 * Move in a circle. Unload if mario moves far away. If mario stays close for
 * long enough, blow wind at him.
 */
static void cloud_fwoosh_update(void)
{
    if (o->oDistanceToMario > 2500.0f)
    {
        o->oAction = CLOUD_ACT_UNLOAD;
    }
    else
    {
        if (o->oCloudBlowing)
        {
            o->header.gfx.scale[0] += o->oCloudGrowSpeed;

            if ((o->oCloudGrowSpeed -= 0.005f) < -0.16f)
            {
                // Stop blowing once we are shrinking faster than -0.16
                o->oCloudBlowing = o->oTimer = 0;
            }
            else if (o->oCloudGrowSpeed < -0.1f)
            {
                // Start blowing once we start shrinking faster than -0.1
                PlaySound(SOUND_CH6_UNKNOWN004_2);
                func_802C76E0(12, 3.0f, 0.0f, -50.0f, 120.0f);
            }
            else
            {
                PlaySound(SOUND_ENVIRONMENT_WIND1);
            }
        }
        else
        {
            // Return to normal size
            approach_f32_ptr(&o->header.gfx.scale[0], 3.0f, 0.012f);
            o->oCloudFwooshMovementRadius += 0xC8;

            // If mario stays nearby for 100 frames, begin blowing
            if (o->oDistanceToMario < 1000.0f)
            {
                if (o->oTimer > 100)
                {
                    o->oCloudBlowing = TRUE;
                    o->oCloudGrowSpeed = 0.14f;
                }
            }
            else
            {
                o->oTimer = 0;
            }

            o->oCloudCenterX = o->oHomeX + 100.0f * coss(o->oCloudFwooshMovementRadius);
            o->oPosZ = o->oHomeZ + 100.0f * sins(o->oCloudFwooshMovementRadius);
            o->oCloudCenterY = o->oHomeY;
        }

        obj_scale(o->header.gfx.scale[0]);
    }
}

/**
 * Main update function for bCloud. This controls the cloud's movement, when it
 * unloads, and when fwoosh blows wind.
 */
static void cloud_act_main(void)
{
    s16 localOffsetPhase;
    f32 localOffset;

    localOffsetPhase = 0x800 * gGlobalTimer;

    if (o->parentObj != o)
    {
        // Despawn if the parent lakitu does
        if (o->parentObj->activeFlags == ACTIVE_FLAGS_INACTIVE)
        {
            o->oAction = CLOUD_ACT_UNLOAD;
        }
        else
        {
            o->oCloudCenterX = o->parentObj->oPosX;
            o->oCloudCenterY = o->parentObj->oPosY;
            o->oPosZ = o->parentObj->oPosZ;

            o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw;
        }
    }
    else if (o->oBehParams2ndByte != CLOUD_BP_FWOOSH)
    {
        // This code should never run, since a lakitu cloud should always have
        // a parent
        if (o->oDistanceToMario > 1500.0f)
        {
            o->oAction = CLOUD_ACT_UNLOAD;
        }
    }
    else
    {
        cloud_fwoosh_update();
    }

    localOffset = 2.0f * coss(localOffsetPhase) * o->header.gfx.scale[0];

    o->oPosX = o->oCloudCenterX + localOffset;
    o->oPosY = o->oCloudCenterY + localOffset + 12.0f * o->header.gfx.scale[0];
}

/**
 * If fwoosh, return to home and hide. If lakitu cloud, despawn.
 * This action informs the cloud parts to despawn.
 */
static void cloud_act_unload(void)
{
    if (o->oBehParams2ndByte != CLOUD_BP_FWOOSH)
    {
        mark_object_for_deletion(o);
    }
    else
    {
        o->oAction = CLOUD_ACT_FWOOSH_HIDDEN;
        obj_hide();
        obj_set_pos_to_home();
    }
}

/**
 * Update function for bCloud.
 */
void bhv_cloud_update(void)
{
    switch (o->oAction)
    {
    case CLOUD_ACT_SPAWN_PARTS:   cloud_act_spawn_parts();   break;
    case CLOUD_ACT_MAIN:          cloud_act_main();          break;
    case CLOUD_ACT_UNLOAD:        cloud_act_unload();        break;
    case CLOUD_ACT_FWOOSH_HIDDEN: cloud_act_fwoosh_hidden(); break;
    }
}

/**
 * Update function for bCloudPart. Follow the parent cloud with some oscillation.
 */
void bhv_cloud_part_update(void)
{
    if (o->parentObj->oAction == CLOUD_ACT_UNLOAD)
    {
        mark_object_for_deletion(o);
    }
    else
    {
        f32 size = 2.0f / 3.0f * o->parentObj->header.gfx.scale[0];
        s16 angleFromCenter = o->parentObj->oFaceAngleYaw + 0x10000 / 5 * o->oBehParams2ndByte;

        // Takes 32 frames to cycle
        s16 localOffsetPhase = 0x800 * gGlobalTimer + 0x4000 * o->oBehParams2ndByte;
        f32 localOffset;

        f32 cloudRadius;

        obj_scale(size);

        // Cap fwoosh's face size
        if (o->oBehParams2ndByte == 5 && size > 2.0f)
        {
            size = o->header.gfx.scale[1] = 2.0f;
        }

        // Move back and forth along (1, 1, 1)
        localOffset = 2.0f * coss(localOffsetPhase) * size;

        cloudRadius = 25.0f * size;

        o->oPosX = o->parentObj->oCloudCenterX +
            cloudRadius * sins(angleFromCenter) +
            localOffset;

        o->oPosY = o->parentObj->oCloudCenterY +
            localOffset +
            size * sCloudPartHeights[o->oBehParams2ndByte];

        o->oPosZ = o->parentObj->oPosZ +
            cloudRadius * coss(angleFromCenter) +
            localOffset;

        o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw;
    }
}