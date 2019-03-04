// piranha_plant.c.inc

void ActionPiranhaPlant20(void)
{
    obj_become_intangible();
    func_8029ED38(8);
#ifdef VERSION_US
    obj_scale(1);
#endif
    if(o->oDistanceToMario < 1200.0f)
        o->oAction = 1;
}

s32 func_802BD4A8(void)
{
    s32 i;
    s32 sp18 = 1;
    if(o->oInteractStatus & 0x8000)
    {
        func_80321080(50);
        if(o->oInteractStatus & 0x4000)
        {
            PlaySound2(0x90116081);
            for(i=0;i<20;i++)
                spawn_object(o,170,beh_giant_piranha_particle);
            o->oAction = 5;
        }
        else
            o->oAction = 3;
        o->oInteractStatus = 0;
    }
    else
        sp18 = 0;
    return sp18;
}

void ActionPiranhaPlant21(void)
{
    obj_become_tangible();
    o->oInteractType = 0x8000;
    func_8029ED38(8);
    obj_set_hitbox_radius_and_height(250.0f,200.0f);
    func_802A1274(150.0f,100.0f);
#ifdef VERSION_US
    o->oDamageOrCoinValue = 0;
#endif
    if(o->oDistanceToMario < 400.0f)
    {
        if(func_802BDAD4())
            o->oAction = 3;
    }
    else if(o->oDistanceToMario < 1000.0f)
    {
        func_80320F84(11,0,255,1000);
        o->oPiranhaPlant2UnkF4 = 0;
    }
    else if(o->oPiranhaPlant2UnkF4 == 0)
    {
        o->oPiranhaPlant2UnkF4++;
        func_80321080(0x32);
    }
    func_802BD4A8();
}

void ActionPiranhaPlant23(void)
{
#ifdef VERSION_US
    o->oDamageOrCoinValue = 3;
#endif
    if(o->oTimer == 0)
        func_80321080(50);
    if(func_802BD4A8() == 0)
        if(o->oTimer > 10)
            o->oAction = 2;
}

#ifdef VERSION_US
void func_u_802BE0B8(void)
{
    if(o->activeFlags & 2)
        o->oAction = 0;
}
#endif

void ActionPiranhaPlant25(void)
{
    obj_become_intangible();
    func_8029ED38(2);
    o->oInteractStatus = 0;
    if(func_8029F788())
        o->oAction = 6;
#ifdef VERSION_US
    func_u_802BE0B8();
#endif
}

void ActionPiranhaPlant26(void)
{
    if(o->oTimer == 0)
    {
        PlaySound2(0x50744081);
        o->oPiranhaPlant2UnkF8 = 1.0f;
    }
    if(o->oPiranhaPlant2UnkF8 > 0.0f)
        o->oPiranhaPlant2UnkF8 = o->oPiranhaPlant2UnkF8 - 0.04;
    else
    {
        o->oPiranhaPlant2UnkF8 = 0.0f;
        obj_spawn_loot_blue_coin();
        o->oAction = 7;
    }
    obj_scale(o->oPiranhaPlant2UnkF8);
#ifdef VERSION_US
    func_u_802BE0B8();
#endif
}

void ActionPiranhaPlant27(void)
{
    if(o->oDistanceToMario > 1200.0f)
        o->oAction = 8;
}

void ActionPiranhaPlant28(void)
{
    func_8029ED38(8);
    if(o->oTimer == 0)
        o->oPiranhaPlant2UnkF8 = 0.3f;
    if(o->oPiranhaPlant2UnkF8 < 1.0)
        o->oPiranhaPlant2UnkF8 += 0.02;
    else
    {
        o->oPiranhaPlant2UnkF8 = 1.0f;
        o->oAction = 0;
    }
    obj_scale(o->oPiranhaPlant2UnkF8);
}

void ActionPiranhaPlant22(void)
{

    s32 frame = o->header.gfx.unk38.animFrame;
    obj_become_tangible();
    o->oInteractType = 8;
    func_8029ED38(0);
    obj_set_hitbox_radius_and_height(150.0f,100.0f);
    func_802A1274(150.0f,100.0f);
    if(item_in_array(frame,D_8032F998))
        PlaySound2(0x90105081);
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
    if(o->oDistanceToMario > 500.0f)
        if(func_8029F788())
            o->oAction = 4;
    if(o->oInteractStatus & 0x8000)
        if(gMarioState->flags & 4)
            o->oAction = 5;
}
s32 func_802BDAD4(void)
{
    if(gMarioStates->vel[1] > 10.0f)
        return 1;
    if(gMarioStates->forwardVel > 10.0f)
        return 1;
    return 0;
}

void ActionPiranhaPlant24(void)
{
    obj_become_intangible();
    func_8029ED38(6);
    if(func_8029F788())
        o->oAction = 1;
    if(o->oDistanceToMario < 400.0f)
        if(func_802BDAD4())
            o->oAction = 2;
}

void (*TablePiranhaPlantActions[])(void) = {ActionPiranhaPlant20,ActionPiranhaPlant21,ActionPiranhaPlant22,ActionPiranhaPlant23,ActionPiranhaPlant24,ActionPiranhaPlant25,ActionPiranhaPlant26,ActionPiranhaPlant27,ActionPiranhaPlant28};
s8 D_8032F9C4[] = {2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,-1};
s8 D_8032F9E0[] = {2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,-1};
s8 D_8032F9FC[] = {2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,2,2,-1};
s8 D_8032FA18[] = {2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,-1};
s8 D_8032FA34[] = {2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,-1};
s8 D_8032FA50[] = {2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,-1};
s8 D_8032FA6C[] = {2,2,2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,2,2,-1};
s8 D_8032FA88[] = {2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,-1};
s8 D_8032FAA4[] = {2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FAC0[] = {2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FADC[] = {2,2,2,2,2,2,2,2,2,2,2,6,2,2,5,2,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FAF8[] = {2,2,2,2,2,2,2,2,2,2,2,2,3,4,2,2,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FB14[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FB30[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1};

struct Struct8032FB4C D_8032FB4C[] = {{67,251,241,1,D_8032F9C4},{68,5,241,0,D_8032F9E0},{69,241,251,0,D_8032FADC},{70,251,251,0,D_8032FAF8},{71,5,251,0,D_8032F9FC},{72,15,251,0,D_8032FA18},{73,241,5,0,D_8032FAC0},{74,251,5,0,D_8032FAA4},{75,5,5,0,D_8032FA50},{76,15,5,0,D_8032FA34},{77,241,15,0,D_8032FB14},{78,251,15,0,D_8032FA88},{79,5,15,0,D_8032FA6C},{80,15,15,0,D_8032FB30}};

void BehPiranhaPlant2Loop(void)
{
    obj_call_action_function(TablePiranhaPlantActions);
    if(gCurrLevelNum == LEVEL_WF)
    {
        if(gMarioObject->oPosY > 3400.0f)
            obj_hide();
        else
            obj_unhide();
    }
    o->oInteractStatus = 0;
}
