// purple_switch.c.inc

void BehFloorSwitchLoop(void)
{
    UNUSED s32 unused;
    switch(o->oAction)
    {
    case 0:
        obj_set_model(207);
        obj_scale(1.5f);
        if(gMarioObject->platform == o && !(gMarioStates->action & 0x2000))
            if(lateral_dist_between_objects(o,gMarioObject) < 127.5)
                o->oAction = 1;
        break;
    case 1:
        func_802A3398(2,3,1.5f,0.2f);
        if(o->oTimer == 3)
        {
            PlaySound2(0x803EC081);
            o->oAction = 2;
            ShakeScreen(1);
        }
        break;
    case 2:
        if(o->oBehParams2ndByte != 0)
        {
            if(o->oBehParams2ndByte == 1 && gMarioObject->platform != o)
                o->oAction++;
            else
            {
                if(o->oTimer < 360)
                    SetSound(0x8054F011,D_803320E0);
                else
                    SetSound(0x8055F011,D_803320E0);
                if(o->oTimer > 400)
                    o->oAction = 4;
            }
        }
        break;
    case 3:
        func_802A3398(2,3,0.2f,1.5f);
        if(o->oTimer == 3)
            o->oAction = 0;
        break;
    case 4:
        if(!obj_is_mario_on_platform())
            o->oAction = 3;
        break;
    }
}