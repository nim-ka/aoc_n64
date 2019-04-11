// capswitch.c.inc

void ActionActivateCapSwitch0(void)
{
    o->oAnimState = o->oBehParams2ndByte;
    obj_scale(0.5f);
    o->oPosY += 71.0f;
    spawn_object_relative_with_scale(0,0,-71,0,0.5f,o,86,beh_cap_switch_base);
    if(gCurrLevelNum != LEVEL_UNKNOWN_32)
    {
        if(save_file_get_flags() & D_8032F0C0[o->oBehParams2ndByte])
        {
            o->oAction = 3;
            o->header.gfx.scale[1] = 0.1f;
        }
        else
            o->oAction = 1;
    }
    else
        o->oAction = 1;
}

void ActionActivateCapSwitch1(void)
{
    if(obj_is_mario_on_platform())
    {
        save_file_set_flags(D_8032F0C0[o->oBehParams2ndByte]);
        o->oAction = 2;
        PlaySound2(SOUND_GENERAL_EXPLOSION);
    }
}

void ActionActivateCapSwitch2(void)
{
    s32 sp1C;
    if(o->oTimer < 5)
    {
        func_802A3398(2,4,0.5f,0.1f);
        if(o->oTimer == 4)
        {
            ShakeScreen(1);
            func_802A3004();
            func_802AD82C(60,139,0.3f,o->oBehParams2ndByte);
        }
    }
    else
    {
        sp1C = obj_update_dialogue_unk2(1,12,161,0);
        if(sp1C)
            o->oAction = 3;
    }
}

void ActionActivateCapSwitch3(){} // dead function

void (*TableCapSwitchActions[])(void) = {ActionActivateCapSwitch0,ActionActivateCapSwitch1,ActionActivateCapSwitch2,ActionActivateCapSwitch3};

void BehCapSwitchLoop(void)
{
    obj_call_action_function(TableCapSwitchActions);
}

int Geo18_802A719C(s32 arg0,UNUSED s32 arg1,Mat4 arg2)
{
    Mat4 sp20;
    struct Object* sp1C;
    if(arg0 == 1)
    {
        sp1C = (struct Object*)D_8032CFA0;
        if(sp1C->prevObj != NULL)
        {
            func_8029D704(sp20,arg2,D_8032CF9C->unk34);
            func_8029D558(sp20,sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}
