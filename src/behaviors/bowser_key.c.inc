// bowser_key.c.inc

void BehBowserKey2Loop(void)
{
    obj_scale(0.5f);
    if(o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAngleRoll = -0x4000;
    o->oGraphYOffset = 165.0f;
    if(o->oAction == 0)
    {
        if(o->oTimer == 0)
            o->oVelY = 70.0f;
        func_802B2328(3,200,80,-60);
        spawn_object(o,0,beh_powerup_sparkles2);
        obj_update_floor_and_walls();
        obj_move_standard(78);
        if(o->oMoveFlags & 2)
            o->oAction++;
        else if(o->oMoveFlags & 1)
#ifndef VERSION_JP
            PlaySound2(0x38378081);
#else
            PlaySound2(0x30370081);	
#endif
    }
    else
    {
        set_object_hitbox(o,&D_8032F4CC);
        if(o->oInteractStatus & 0x8000)
        {
            hide_object(o);
            o->oInteractStatus = 0;
        }
    }
}
