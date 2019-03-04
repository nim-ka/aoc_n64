// door.c.inc

void func_802AC070(s32 sp18)
{
    func_8029ED38(sp18);
    if(func_8029F788())
        o->oAction = 0;
}

void func_802AC0B8(void)
{
    if(segmented_to_virtual(beh_door) == o->behavior)
        D_8033B1B0->unk1C[1] = 6;
    else
        D_8033B1B0->unk1C[1] = 5;
    D_8033B1B0->unk20 = o;
}

void func_802AC130(void)
{
    s32 sp1C = obj_has_model(31);
    if(o->oTimer == 0)
    {
        PlaySound2(D_8032F328[sp1C]);
        gTimeStopState |= 0x20;
    }
    if(o->oTimer == 70)
    {
        PlaySound2(D_8032F330[sp1C]);
    }
}

void func_802AC1CC(void)
{
    s32 sp1C = obj_has_model(31);
    if(o->oTimer == 30)
        PlaySound2(D_8032F330[sp1C]);
}

void BehDoorLoop(void)
{
    s32 sp1C = 0;
    while(D_8032F300[sp1C][0] != -1)
    {
        if(obj_clear_interact_status_flag(D_8032F300[sp1C][0]))
        {
            func_802AC0B8();
            obj_change_action(D_8032F300[sp1C][1]);
        }
        sp1C++;
    }
    switch(o->oAction)
    {
    case 0: func_8029ED38(0); break;
    case 1: func_802AC070(1); func_802AC130(); break;
    case 2: func_802AC070(2); func_802AC130(); break;
    case 3: func_802AC070(3); func_802AC1CC(); break;
    case 4: func_802AC070(4); func_802AC1CC(); break;
    }
    if(o->oAction == 0)
        load_object_collision_model();
    BehStarDoorLoop2();
}

void BehDoorInit(void)
{
    f32 sp24 = o->oPosX;
    f32 sp20 = o->oPosZ;
    struct Surface* sp1C;
    find_floor(sp24,o->oPosY,sp20,&sp1C);
    if(sp1C != NULL)
        o->OBJECT_FIELD_S32(0x1C) = sp1C->room;
    sp24 = o->oPosX + sins(o->oMoveAngleYaw) * 200.0f;
    sp20 = o->oPosZ + coss(o->oMoveAngleYaw) * 200.0f;
    find_floor(sp24,o->oPosY,sp20,&sp1C);
    if(sp1C != NULL)
        o->OBJECT_FIELD_S32(0x1D) = sp1C->room;
    sp24 = o->oPosX + sins(o->oMoveAngleYaw) * -200.0f;
    sp20 = o->oPosZ + coss(o->oMoveAngleYaw) * -200.0f;
    find_floor(sp24,o->oPosY,sp20,&sp1C);
    if(sp1C != NULL)
        o->OBJECT_FIELD_S32(0x1E) = sp1C->room;
    if(o->OBJECT_FIELD_S32(0x1C) > 0 && o->OBJECT_FIELD_S32(0x1C) < 60)
    {
        D_8035FE68[o->OBJECT_FIELD_S32(0x1C)][0] = o->OBJECT_FIELD_S32(0x1D);
        D_8035FE68[o->OBJECT_FIELD_S32(0x1C)][1] = o->OBJECT_FIELD_S32(0x1E);
    }
}

void BehStarDoorLoop2(void)
{
    s32 sp4 = 0;
    if(gMarioCurrentRoom != 0)
    {
        if(o->OBJECT_FIELD_S32(0x1C) == gMarioCurrentRoom)
            sp4 = 1;
        else if(gMarioCurrentRoom == o->OBJECT_FIELD_S32(0x1D))
            sp4 = 1;
        else if(gMarioCurrentRoom == o->OBJECT_FIELD_S32(0x1E))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][0] == o->OBJECT_FIELD_S32(0x1D))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][0] == o->OBJECT_FIELD_S32(0x1E))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][1] == o->OBJECT_FIELD_S32(0x1D))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][1] == o->OBJECT_FIELD_S32(0x1E))
            sp4 = 1;
    }
    else
        sp4 = 1;
    if(sp4 == 1)
    {
        o->header.gfx.node.flags |= 1;
        D_8035FEE4++;
    }
    if(sp4 == 0)
    {
        o->header.gfx.node.flags &= ~1;
    }
    o->oUnk88 = sp4;
}
