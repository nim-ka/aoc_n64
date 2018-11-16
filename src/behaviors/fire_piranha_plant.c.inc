
void bhv_fire_piranha_plant_init(void)
{
    o->oFirePiranhaPlantNeutralScale = D_80331B5C[(u16)(o->oBehParams >> 16)];
    func_802A2CFC(o, &sFirePiranhaPlantHitbox);

    if ((u16)(o->oBehParams >> 16) != 0)
    {
        o->oFlags |= 0x00004000;
        o->oUnk184 = 1;

        if (o->oBehParams & 0x0000FF00)
        {
            o->oUnk198 = 0;
        }
        else
        {
            o->oUnk198 = 2;
        }
    }

    sNumKilledFirePiranhaPlants = 0;
    sNumActiveFirePiranhaPlants = 0;
}

static void fire_piranha_plant_act_hide(void)
{
    if (o->oFirePiranhaPlantDeathSpinTimer != 0)
    {
        o->oAngleYaw += (s32)o->oFirePiranhaPlantDeathSpinVel;
        approach_f32_2(&o->oFirePiranhaPlantDeathSpinVel, 0.0f, 200.0f);

        if (func_8029F788())
        {
            if (--o->oFirePiranhaPlantDeathSpinTimer == 0)
            {
                PlaySound2(0x50744081);
            }
        }
    }
    else if (approach_f32_2(
        &o->oFirePiranhaPlantScale,
        0.0f,
        0.04f * o->oFirePiranhaPlantNeutralScale))
    {
        func_8029FE38();
        if (o->oFirePiranhaPlantActive)
        {
            sNumActiveFirePiranhaPlants -= 1;
            o->oFirePiranhaPlantActive = FALSE;

            if ((u16)(o->oBehParams >> 16) != 0 && o->oUnk184 == 0)
            {
                if (++sNumKilledFirePiranhaPlants == 5)
                {
                    CreateStar(-6300.0f, -1850.0f, -6300.0f);
                }

                func_802FA078();
                func_8029C6D8(o, 1);
            }
        }
        else if (sNumActiveFirePiranhaPlants < 2 &&
            o->oTimer > 100 &&
            o->oDistanceToMario > 100.0f && o->oDistanceToMario < 800.0f)
        {
            PlaySound2(0x50542081);

            o->oFirePiranhaPlantActive = TRUE;
            sNumActiveFirePiranhaPlants += 1;
            
            func_8029EF18();
            o->oAction = FIRE_PIRANHA_PLANT_ACT_GROW;
            o->oAngleYaw = o->oAngleToMario;
        }
        else
        {
            UnHideObject();
        }
    }

    func_8029F728();
}

static void fire_piranha_plant_act_grow(void)
{
    func_802F927C(4);

    if (approach_f32_2(
        &o->oFirePiranhaPlantScale,
        o->oFirePiranhaPlantNeutralScale,
        0.04f * o->oFirePiranhaPlantNeutralScale))
    {
        if (o->oTimer > 80)
        {
            PlaySound2(0x50334081);
            o->oAction = FIRE_PIRANHA_PLANT_ACT_HIDE;
            func_8029ED38(0);
        }
        else if (o->oTimer < 50)
        {
            func_8029DE70(o->oAngleToMario, 0x400);
        }
        else
        { // TODO: Check if we can put these conditionals on same line
            if (func_802F8680())
            {
                if (check_anim_frame(56))
                {
                    PlaySound2(0x50558081);
                    obj_spit_fire(
                        0,
                        (s32)(30.0f * o->oFirePiranhaPlantNeutralScale),
                        (s32)(140.0f * o->oFirePiranhaPlantNeutralScale),
                        2.5f * o->oFirePiranhaPlantNeutralScale,
                        0xCB,
                        20.0f,
                        15.0f,
                        0x1000);
                }
            }
        }
    }
    else if (o->oFirePiranhaPlantScale > o->oFirePiranhaPlantNeutralScale / 2.0f)
    {
        func_8029FE58();
    }
}

void bhv_fire_piranha_plant_update(void)
{
    ScaleObject(o->oFirePiranhaPlantScale);

    switch (o->oAction)
    {
    case FIRE_PIRANHA_PLANT_ACT_HIDE: fire_piranha_plant_act_hide(); break;
    case FIRE_PIRANHA_PLANT_ACT_GROW: fire_piranha_plant_act_grow(); break;
    }

    if (func_802FA888(&sFirePiranhaPlantHitbox, o->oAction))
    {
        if (--o->oUnk184 < 0)
        {
            if (o->oFirePiranhaPlantActive)
            {
                sNumActiveFirePiranhaPlants -= 1;
            }
        }
        else
        {
            func_8029ED38(2);
        }

        o->oAction = FIRE_PIRANHA_PLANT_ACT_HIDE;
        o->oFirePiranhaPlantDeathSpinTimer = 10;
        o->oFirePiranhaPlantDeathSpinVel = 8000.0f;

        func_8029FE38();
    }
}
