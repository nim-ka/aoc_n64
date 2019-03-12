// scuttlebug.c.inc

s32 func_802C5A64(s32* a0)
{
    if(o->oMoveFlags & 0x200)
    {
        *a0 = o->oWallAngle;
        return 1;
    }
    else if(o->oMoveFlags & 0x400)
    {
        *a0 = o->oMoveAngleYaw + 0x8000;
        return -1;
    }
    return 0;
}

void BehScuttlebugLoop(void)
{
    UNUSED s32 unused;
    f32 sp18;
    obj_update_floor_and_walls();
    if(o->oSubAction != 0 && obj_set_hitbox_and_die_if_attacked(&D_8032FD74,0x50244081,o->oScuttlebugUnkF4))
        o->oSubAction = 3;
    if(o->oSubAction != 1)
        o->oScuttlebugUnkF8 = 0;
    switch(o->oSubAction)
    {
    case 0:
        if(o->oMoveFlags & 1)
            PlaySound2(0x502F0081);
        if(o->oMoveFlags & 3)
        {
            o->oHomeX = o->oPosX;
            o->oHomeY = o->oPosY;
            o->oHomeZ = o->oPosZ;
            o->oSubAction++;
        }
        break;
    case 1:
        o->oForwardVel = 5.0f;
        if(obj_lateral_dist_from_mario_to_home() > 1000.0f)
            o->oAngleToMario = obj_angle_to_home();
        else
        {
            if(o->oScuttlebugUnkF8 == 0)
            {
                o->oScuttlebugUnkFC = 0;
                o->oAngleToMario = angle_to_object(o,gMarioObject);
                if(abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw) < 0x800)
                {
                    o->oScuttlebugUnkF8 = 1;
                    o->oVelY = 20.0f;
                    PlaySound2(0x90444081);
                }
            }
            else if(o->oScuttlebugUnkF8 == 1)
            {
                o->oForwardVel = 15.0f;
                o->oScuttlebugUnkFC++;
                if(o->oScuttlebugUnkFC > 50)
                    o->oScuttlebugUnkF8 = 0;
            }
        }
        if(func_802C5A64(&o->oAngleToMario))
            o->oSubAction = 2;
        obj_rotate_yaw_toward(o->oAngleToMario,0x200);
        break;
    case 2:
        o->oForwardVel = 5.0f;
        if((s16)o->oMoveAngleYaw == (s16)o->oAngleToMario)
            o->oSubAction = 1;
        if(o->oPosY - o->oHomeY < -200.0f)
            mark_object_for_deletion(o);
        obj_rotate_yaw_toward(o->oAngleToMario,0x400);
        break;
    case 3:
        o->oFlags &= ~8;
        o->oForwardVel = -10.0f;
        o->oVelY = 30.0f;
        PlaySound2(0x90444081);
        o->oSubAction++;
        break;
    case 4:
        o->oForwardVel = -10.0f;
        if(o->oMoveFlags & 1)
        {
            o->oSubAction++;
            o->oVelY = 0.0f;
            o->oScuttlebugUnkFC = 0;
            o->oFlags |= 8;
            o->oInteractStatus = 0;
        }
        break;
    case 5:
        o->oForwardVel = 2.0f;
        o->oScuttlebugUnkFC++;
        if(o->oScuttlebugUnkFC > 30)
            o->oSubAction = 0;
        break;
    }
    if(o->oForwardVel < 10.0f)
        sp18 = 1.0f;
    else
        sp18 = 3.0f;
    func_8029ED98(0,sp18);
    if(o->oMoveFlags & 3)
        func_802BE2E8(1,23,0x90434081);
    if(o->parentObj != o)
    {
        if(obj_is_hidden(o))
            mark_object_for_deletion(o);
        if(o->activeFlags == 0)
            o->parentObj->oUnk88 = 1;
    }
    obj_move_standard(-50);
}

void BehScuttlebugSpawnLoop(void)
{
    struct Object* scuttlebug;
    if(o->oAction == 0)
    {
        if(o->oTimer > 30 && 500.0f < o->oDistanceToMario && o->oDistanceToMario < 1500.0f)
        {
            PlaySound2(0x90444081);
            scuttlebug = spawn_object(o,101,beh_scuttlebug);
            scuttlebug->oScuttlebugUnkF4 = o->oScuttlebugSpawnerUnkF4;
            scuttlebug->oForwardVel = 30.0f;
            scuttlebug->oVelY = 80.0f;
            o->oAction++;
            o->oScuttlebugUnkF4 = 1;
        }
    }
    else if(o->oUnk88 != 0)
    {
        o->oUnk88 = 0;
        o->oAction = 0;
    }
}