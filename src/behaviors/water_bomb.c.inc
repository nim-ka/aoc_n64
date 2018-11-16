
void bhv_water_bomb_spawner_update(void)
{
    f32 distToMario;
    f32 spawnerRadius;
    struct Object *waterBomb;
    f32 waterBombDistToMario;

    spawnerRadius = 50 * (u16)(o->oBehParams >> 16) + 200.0f;
    distToMario = DistanceFromObject(o, gMarioObject);
    
    if (o->oWaterBombSpawnerBombActive == FALSE &&
        distToMario < spawnerRadius &&
        gMarioObject->oPosY - o->oPosY < 1000.0f)
    {
        if (o->oWaterBombSpawnerTimeToSpawn != 0)
        {
            o->oWaterBombSpawnerTimeToSpawn -= 1;
        }
        else
        {
            waterBomb = spawn_obj_adv(0, 0, 2000, 0x0, o, 0x54, bWaterBomb);
            if (waterBomb != NULL)
            {
                waterBombDistToMario = 28.0f * gMarioStates[0].forwardVel + 100.0f;
                waterBomb->oAction = WATER_BOMB_ACT_INIT;
                
                waterBomb->oPosX = gMarioObject->oPosX + waterBombDistToMario * sins(gMarioObject->oAngleYaw);
                waterBomb->oPosZ = gMarioObject->oPosZ + waterBombDistToMario * coss(gMarioObject->oAngleYaw);
                
                SpawnObj(waterBomb, 0x55, bWaterBombShadow);
                
                o->oWaterBombSpawnerBombActive = TRUE;
                o->oWaterBombSpawnerTimeToSpawn = random_linear_offset(0, 50);
            }
        }
    }
}

static void func_803051C4(s8 arg0, s8 arg1, s8 arg2)
{
    D_80331938.unk3 = arg0;
    D_80331938.unk5 = arg1;
    D_80331938.unk6 = arg2;
    func_802A2B04(&D_80331938);
}

static void water_bomb_act_init(void)
{
    PlaySound2(0x50288081);
    o->oAction = WATER_BOMB_ACT_DROP;
    o->oMoveFlags = 0;
    o->oVelY = -40.0f;
}

static void water_bomb_act_drop(void)
{
    f32 stretch;

    func_802A2CFC(o, &D_80331928);

    if ((o->oInteractStatus & 0x00008000) || (o->oMoveFlags & 0x00000008))
    {
        create_sound_spawner(0x5029A081);
        func_8027F440(1, o->oPosX, o->oPosY, o->oPosZ);
        o->oAction = WATER_BOMB_ACT_DEACTIVATE;
    }
    else if (o->oMoveFlags & 0x00000003)
    {
        if (o->oWaterBombOnGround == FALSE)
        {
            o->oWaterBombOnGround = TRUE;

            if ((o->oWaterBombNumBounces += 1.0f) < 3.0f)
            {
                PlaySound2(0x502E8081);
            }
            else
            {
                create_sound_spawner(0x5029A081);
            }

            func_8027F440(1, o->oPosX, o->oPosY, o->oPosZ);
            o->oAngleYaw = o->oAngleToMario;
            o->oForwardVel = 10.0f;
            o->oWaterBombUnkFC = -40.0f;
        }

        o->oWaterBombUnkFC += 15.0f - o->oWaterBombNumBounces * 2.8f;

        o->oWaterBombVerticalStretch += o->oWaterBombUnkFC * 0.01f;
        if (o->oWaterBombVerticalStretch < -0.8f)
        {
            o->oAction = WATER_BOMB_ACT_DEACTIVATE;
        }
        else if (o->oWaterBombVerticalStretch > 0.1f)
        {
            o->oVelY = 1.8f * o->oWaterBombUnkFC;
        }
    }
    else
    {
        approach_f32_2(&o->oWaterBombVerticalStretch, 0.0f, 0.008f);
        o->oWaterBombOnGround = FALSE;
    }

    o->header.gfx.scale[1] = o->oWaterBombVerticalStretch + 1.0f;
    
    stretch = o->oWaterBombVerticalStretch;
    if (o->oWaterBombNumBounces == 3.0f)
    {
        stretch *= 4.0f;
    }
    o->header.gfx.scale[0] = o->header.gfx.scale[2] = 1.0f - stretch;

    MoveObj(78);
}

static void water_bomb_act_deactivate(void)
{
    func_803051C4(25, 60, 10);
    o->parentObj->oWaterBombSpawnerBombActive = FALSE;
    DeactivateObject(o);
}

static void func_803055F4(void)
{
    if (o->oTimer > 100)
    {
        DeactivateObject(o);
    }
    else
    {
        if (o->oTimer < 7)
        {
            if (o->oTimer == 1)
            {
                func_803051C4(-20, 10, 30);
            }
            func_802A2B04(&D_8033194C);
        }

        if (o->header.gfx.scale[1] > 1.2f)
        {
            o->header.gfx.scale[1] -= 0.1f;
        }

        o->header.gfx.scale[0] = o->header.gfx.scale[2] = 2.0f - o->header.gfx.scale[1];
        func_802A2A38();
    }
}

void bhv_water_bomb_update(void)
{
    if (o->oAction == WATER_BOMB_ACT_UNK0)
    {
        func_803055F4();
    }
    else
    {
        o->oGraphYOffset = 40.0f * o->header.gfx.scale[1];
        MoveRelated();

        switch (o->oAction)
        {
        case WATER_BOMB_ACT_INIT: water_bomb_act_init(); break;
        case WATER_BOMB_ACT_DROP: water_bomb_act_drop(); break;
        case WATER_BOMB_ACT_DEACTIVATE: water_bomb_act_deactivate(); break;
        }
    }
}

void bhv_water_bomb_shadow_update(void)
{
    f32 val04;

    if (o->parentObj->oAction == WATER_BOMB_ACT_DEACTIVATE)
    {
        DeactivateObject(o);
    }
    else
    {
        val04 = o->parentObj->oPosY - o->parentObj->oFloorHeight;
        if (val04 > 500.0f)
        {
            val04 = 500.0f;
        }

        CopyObjPosition(o, o->parentObj);
        o->oPosY = o->parentObj->oFloorHeight + val04;
        CopyObjScaling(o, o->parentObj);
    }
}
