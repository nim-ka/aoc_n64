// wdw_water_level.c.inc

// called when WDW is loaded.
void BehInitChangingWaterLevelLoop(void)
{
    if(gCurrentObject->oAction == 0)
    {
        if(gWaterRegions != NULL)
            gCurrentObject->oAction++;
    }
    else if(gCurrentObject->oTimer < 10)
        *gWaterLevels = gWaterRegions[6];
    else
    {
        gWaterRegions[6] = *gWaterLevels + sins(o->oWaterLevelTriggerUnkF4) * 20.0f;
        gCurrentObject->oWaterLevelTriggerUnkF4 += 0x200;
    }
}

void BehWaterLevelDiamondLoop(void)
{
    if(gWaterRegions != NULL)
    {
        switch(o->oAction)
        {
        case 0:
            o->oFaceAngleYaw = 0;
            o->oWaterLevelTriggerUnkF8 = (s32)o->oPosY;
            if(o->oTimer > 10)
                o->oAction++;
            break;
        case 1:
            if(are_objects_collided(o,gMarioObject))
            {
                if(D_8035FEF2 == 0)
                {
                    o->oAction++;
                    D_8035FEF2 = 1;
                }
            }
            break;
        case 2:
            o->oAngleVelYaw = 0;
            *gWaterLevels = (s32)approach_f32_symmetric((f32)*gWaterLevels,(f32)o->oWaterLevelTriggerUnkF8,10.0f);
            if(*gWaterLevels == o->oWaterLevelTriggerUnkF8)
            {
                if((s16)o->oFaceAngleYaw == 0)
                    o->oAction++;
                else
                    o->oAngleVelYaw = 0x800;
            }
            else
            {
                if(o->oTimer == 0)
                    PlaySound2(0x30668081);
                else
                {
                    if(*gWaterLevels > o->oWaterLevelTriggerUnkF8)
                        PlaySound(0x41160001);
                    else
                        PlaySound(0x41160001); // same as above
                }
                o->oAngleVelYaw = 0x800;
            }
            break;
        case 3:
            if(!are_objects_collided(o,gMarioObject))
            {
                D_8035FEF2 = 0;
                o->oAction = 1;
                o->oAngleVelYaw = 0;
            }
            break;
        }
        o->oFaceAngleYaw += o->oAngleVelYaw;
    }
}
