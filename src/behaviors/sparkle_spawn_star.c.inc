// sparkle_spawn_star.c.inc

void BehUnused080CInit(void)
{
    s32 sp24;
    if(!(o->oUnk190 & 0x400))
        o->oBehParams = o->parentObj->oBehParams;
    sp24 =(o->oBehParams >> 24) & 0xFF;
    if(func_802A377C(sp24) & save_file_get_star_flags(gCurrSaveFileNum-1,gCurrCourseNum-1))
        obj_set_model(121);
    PlaySound2(0x8057FF91);
}

void func_802AA788(void)
{
    set_object_hitbox(o,&D_8032F284);
    if(o->oInteractStatus & 0x8000)
    {
        hide_object(o);
        o->oInteractStatus = 0;
    }
}

void func_802AA7EC(void)
{
    f32 sp1C;
    f32 sp18;
    o->oHomeX = gMarioObject->oPosX;
    o->oHomeZ = gMarioObject->oPosZ;
    o->oHomeY = gMarioObject->oPosY;
    o->oHomeY += 250.0f;
    o->oPosY = o->oHomeY;
    sp1C = o->oHomeX    - o->oPosX;
    sp18 = o->oHomeZ - o->oPosZ;
    o->oForwardVel = sqrtf(sp1C*sp1C+sp18*sp18)/23.0f;
}

void func_802AA8E4(void)
{
    o->oForwardVel = 0;
    o->oHomeY = o->oPosY;
}

void func_802AA918(void)
{
    if(o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x40;
}

void BehUnused080CLoop(void)
{
    if(o->oAction == 0)
    {
        if(o->oTimer == 0)
        {
            func_8028F9E8(173,o);
            set_time_stop_flag(10);
            o->activeFlags |= 0x20;
            o->oAngleVelYaw = 0x800;
            if(o->oBehParams2ndByte == 0)
                func_802AA7EC();
            else
                func_802AA8E4();
            o->oMoveAngleYaw = obj_angle_to_home();
            o->oVelY = 50.0f;
            o->oGravity = -4.0f;
            func_802A3004();
        }
        PlaySound(0x40140011);
        spawn_object(o,0,beh_powerup_sparkles2);
        if(o->oVelY < 0 && o->oPosY < o->oHomeY)
        {
            o->oAction++;
            o->oForwardVel = 0;
            o->oVelY = 20.0f;
            o->oGravity = -1.0f;
            if(o->oUnk190 & 0x400)
#ifndef VERSION_JP
                func_803212A0(1);
#else
                func_803212A0(0);
#endif
            else
                func_803212A0(1);
        }
    }
    else if(o->oAction == 1)
    {
        if(o->oVelY < -4.0f)
            o->oVelY = -4.0f;
        if(o->oVelY < 0 && o->oPosY < o->oHomeY)
        {
            D_8033B858 = 1;
            o->oVelY = 0;
            o->oGravity = 0;
            o->oAction++;
        }
        spawn_object(o,0,beh_powerup_sparkles2);
    }
    else if(o->oAction == 2)
    {
        if(gCurrLevelCamera->unk30 == 0 && D_8032CFF4 == 0)
        {
            clear_time_stop_flag(10);
            o->activeFlags &= ~0x20;
            o->oAction++;
        }
    }
    else
    {
        func_802AA788();
        func_802AA918();
    }
    obj_move_using_fvel_and_gravity();
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oInteractStatus = 0;
}

void BehSpawnStarObjects(u32 sp20)
{
    struct Object* sp1C = spawn_object(o,122,beh_unused_080C);
    sp1C->oBehParams = sp20 << 24;
    sp1C->oUnk190 = 0x400;
    set_object_angle(sp1C,0,0,0);
}
