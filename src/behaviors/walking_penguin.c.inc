// walking_penguin.c.inc

s32 func_802C7AD0(void)
{
    o->oForwardVel = 0.0f;
    func_8029ED98(0,1.0f);
    o->oAngleVelYaw = 0x400;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    if(o->oTimer == 31)
        return 1;
    else
        return 0;
}

void BehWalkingPenguinLoop(void)
{
    f32 sp2C;
    f32 sp28;
    f32 sp24 = 100.0f;
    o->oAngleVelYaw = 0;
    obj_update_floor_and_walls();
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0)
        {
            o->oWalkingPenguinUnk10C = 0;
            o->oWalkingPenguinUnk110 = 0;
        }
        if(o->oWalkingPenguinUnk110 < D_8032FE4C[o->oWalkingPenguinUnk10C].unk0)
            o->oWalkingPenguinUnk110++;
        else
        {
            o->oWalkingPenguinUnk110 = 0;
            o->oWalkingPenguinUnk10C++;
            if(D_8032FE4C[o->oWalkingPenguinUnk10C].unk0 < 0)
                o->oWalkingPenguinUnk10C = 0;
        }
        if(o->oPosX < 300.0f)
            o->oAction++;
        else
        {
            o->oForwardVel = D_8032FE4C[o->oWalkingPenguinUnk10C].unk2;
            func_8029ED98(D_8032FE4C[o->oWalkingPenguinUnk10C].unk1,D_8032FE4C[o->oWalkingPenguinUnk10C].unk3);
        }
        break;
    case 1:
        if(func_802C7AD0())
            o->oAction++;
        break;
    case 2:
        o->oForwardVel = 12.0f;
        func_8029ED98(0,2.0f);
        if(o->oPosX > 1700.0f)
            o->oAction++;
        break;
    case 3:
        if(func_802C7AD0())
            o->oAction = 0;
        break;
    }
    obj_move_standard(-78);
    if(!obj_hide_if_mario_far_away_y(1000.0f))
        func_802BE3B4(1);
    sp2C = o->oPosX + sins(0xDBB0) * 60.0f;
    sp28 = o->oPosZ + coss(0xDBB0) * 60.0f;
    sp2C += sp24 * sins(0x1BB0);
    sp28 += sp24 * coss(0x1BB0);
    o->oWalkingPenguinUnk100 = sp2C;
    o->oWalkingPenguinUnk104 = sp28;
    print_debug_bottom_up("x %d",o->oPosX);
    print_debug_bottom_up("z %d",o->oPosZ);
}