
void bhv_donut_platform_spawner_update(void)
{
    s32 i;
    s32 platformFlag;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 marioSqDist;

    for (i = 0, platformFlag = 1; i < 31; i++, platformFlag = platformFlag << 1)
    {
        if (!(o->oDonutPlatformSpawnerSpawnedPlatforms & platformFlag))
        {
            dx = gMarioObject->oPosX - sDonutPlatformPositions[i][0];
            dy = gMarioObject->oPosY - sDonutPlatformPositions[i][1];
            dz = gMarioObject->oPosZ - sDonutPlatformPositions[i][2];
            marioSqDist = dx*dx + dy*dy + dz*dz;

            // dist > 1000 and dist < 2000
            if (marioSqDist > 1000000.0f && marioSqDist < 4000000.0f)
            {
                if (spawn_obj_adv(
                    i,
                    sDonutPlatformPositions[i][0],
                    sDonutPlatformPositions[i][1],
                    sDonutPlatformPositions[i][2],
                    o,
                    0x3F,
                    bDonutPlatform) != NULL)
                {
                    o->oDonutPlatformSpawnerSpawnedPlatforms |= platformFlag;
                }
            }
        }
    }
}

void bhv_donut_platform_update(void)
{
    if (o->oTimer != 0 &&
        ((o->oMoveFlags & 0x00000003) || o->oDistanceToMario > 2500.0f))
    {
        o->parentObj->oDonutPlatformSpawnerSpawnedPlatforms =
            o->parentObj->oDonutPlatformSpawnerSpawnedPlatforms &
                ((1 << o->oBehParams2ndByte) ^ 0xFFFFFFFF);

        if (o->oDistanceToMario > 2500.0f)
        {
            DeactivateObject(o);
        }
        else
        {
            func_802A3C98(150.0f, 1);
            create_sound_spawner(0x302E2081);
        }
    }
    else
    {
        if (o->oGravity == 0.0f)
        {
            if (gMarioObject->platform == o)
            {
                func_802A1160(4.0f);
                if (o->oTimer > 15)
                {
                    o->oGravity = -0.1f;
                }
            }
            else
            {
                obj_set_pos_to_home();
                o->oTimer = 0;
            }
        }
        else
        {
            MoveRelated();
            MoveObj(78);
        }

        load_object_collision_model();
    }
}
