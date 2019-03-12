// bbh_merry_go_round.c.inc

void func_802C50F4(void)
{
    struct Surface* sp1C;
    u16 sp1A;
    if(o->oRotatingMerryGoRoundUnkF8 == 0)
    {
        if(gMarioCurrentRoom == 10)
        {
            func_80320F84(19,45,20,200);
            o->oRotatingMerryGoRoundUnkF8++;
        }
    }
    else
    {
        find_floor(gMarioObject->oPosX,gMarioObject->oPosY,gMarioObject->oPosZ,&sp1C);
        if(sp1C == NULL)
            sp1A = 0;
        else
            sp1A = sp1C->type;
        if(obj_is_mario_on_platform() || sp1A == SURFACE_001A)  //Surface 1A is floor of Merry-Go-Round
        {
            func_80320F84(19,0,78,50);
            D_8035FEF4 = 1;
        }
        else
        {
            func_80320F84(19,45,20,200);
            D_8035FEF4 = 0;
        }
        if(gMarioCurrentRoom != 0 && gMarioCurrentRoom != 10)
        {
            func_80321080(300);
            o->oRotatingMerryGoRoundUnkF8 = 0;
        }
        else
            PlaySound(0x400F4001);
    }
}

void BehRotatingMerryGoRoundLoop(void)
{
    if(o->oRotatingMerryGoRoundUnkFC == 0)
    {
        if(gMarioCurrentRoom == 13)
            o->oRotatingMerryGoRoundUnkFC++;
    }
    else
    {
        SetSound(0x60098001,D_803320E0);
        if(gMarioCurrentRoom != 13 && gMarioCurrentRoom != 0)
            o->oRotatingMerryGoRoundUnkFC = 0;
    }
    if(o->oUnk88 == 0)
    {
        o->oAngleVelYaw = 0x80;
        o->oMoveAngleYaw += o->oAngleVelYaw;
        o->oFaceAngleYaw += o->oAngleVelYaw;
        func_802C50F4();
    }
    else
    {
        o->oAngleVelYaw = 0;
        func_80321080(300);
    }
}