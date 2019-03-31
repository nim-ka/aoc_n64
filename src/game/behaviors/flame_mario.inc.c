// flame_mario.c.inc

void BehBlackSmokeUpwardLoop(void)
{
    spawn_object_with_scale(o,148,beh_black_smoke_bowser,o->header.gfx.scale[0]);
}

void BehBlackSmokeBowserLoop(void)
{
    if(o->oTimer == 0)
    {
        o->oForwardVel = RandomFloat() * 2.0f + 0.5;
        o->oMoveAngleYaw = RandomU16();
        o->oVelY = 8.0f;
        o->oBlackSmokeBowserUnkF4 = o->header.gfx.scale[0];
    }
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
}

void BehBlackSmokeMarioLoop(void)
{
    if(o->oTimer == 0)
    {
        obj_set_pos_relative(gMarioObject,0,0,-30.0f);
        o->oForwardVel = RandomFloat() * 2.0f + 0.5;
        o->oMoveAngleYaw = (gMarioObject->oMoveAngleYaw + 0x7000) + RandomFloat() * 8192.0f;
        o->oVelY = 8.0f;
    }
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
}

void BehFlameMarioLoop(void)
{
    obj_scale(2.0f);
    if(o->oTimer != 0)
        if(o->oTimer&1)
            spawn_object(o,148,beh_black_smoke_mario);
    gMarioObject->prevObj = o; // weird?
    set_object_parent_relative_pos(o,40,-120,0);
    if(!(gMarioObject->oMarioParticleFlags & 0x800))
    {
        o->parentObj->oUnkE0 &= ~0x800;
        mark_object_for_deletion(o);
        gMarioObject->prevObj = NULL;
    }
}
