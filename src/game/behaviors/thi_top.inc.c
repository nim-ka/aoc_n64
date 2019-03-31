// thi_top.c.inc

struct SpawnParticlesInfo D_8032F134 = {0,30,164,0,40,0,20,40,252,30,20.0f,0.0f};

UNUSED u8 unused8032F134[] = {10,11,12};

void BehTHIHugeIslandTopLoop(void)
{
    if(D_8035FEE6 & 1)
    {
        if(o->oTimer == 0)
            gWaterRegions[18] = 3000;
        obj_hide();
    }
    else
        load_object_collision_model();
}

void BehTHITinyIslandTopLoop(void)
{
    if(!(D_8035FEE6 & 1)) // last bit not set
    {
        if(o->oAction == 0)
        {
            if(o->oDistanceToMario < 500.0f)
                if(gMarioStates->action == ACT_GROUND_POUND_LAND)
                {
                    o->oAction++;
                    obj_spawn_particles(&D_8032F134);
                    func_802AD82C(20,138,0.3f,3);
                    PlaySound2(0x30008081);
                    obj_hide();
                }
        }
        else
        {
            if(o->oTimer < 50)
            {
                gWaterRegions[18]--;
                PlaySound(0x41160001);
            }
            else
            {
                D_8035FEE6 |= 1; // set last bit
                func_80321228();
                o->oAction += 1;
            }
        }
    }
    else
    {
        if(o->oTimer == 0)
            gWaterRegions[18] = 700;
        obj_hide();
    }
}
