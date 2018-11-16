
static void swoop_act_idle(void)
{
    func_8029ED38(1);

    if (approach_f32_2(&o->header.gfx.scale[0], 1.0f, 0.05f) &&
        o->oDistanceToMario < 1500.0f)
    {
        if (func_8029DE70(o->oAngleToMario, 0x320))
        {
            PlaySound2(0x90490081);
            o->oAction = SWOOP_ACT_MOVE;
            o->oVelY = -12.0f;
        }
    }

    o->oFaceAngleRoll = 0x8000;
}

static void swoop_act_move(void)
{
    func_8029ED98(0, 2.0f);

    if (func_8029F788())
    {
        PlaySound2(0x50310081);
    }

    if (o->oForwardVel == 0.0f)
    {
        if (face_roll_approach(0, 2500))
        {
            o->oForwardVel = 10.0f;
            o->oVelY = -10.0f;
        }
    }
    else if (func_802A37A0())
    {
        o->oAction = SWOOP_ACT_IDLE;
        obj_set_pos_to_home();
        o->header.gfx.scale[0] = o->oForwardVel = o->oVelY = 0.0f;
        o->oFaceAngleRoll = 0;
    }
    else
    {
        if (o->oSwoopTimeUntilTurn != 0)
        {
            o->oSwoopTimeUntilTurn -= 1;
        }
        else if (o->oVelY != 0.0f)
        {
            o->oSwoopTargetYaw = o->oAngleToMario;
            if (o->oPosY < gMarioObject->oPosY + 200.0f)
            {
                if (y_vel_approach(0.0f, 0.5f))
                {
                    o->oForwardVel *= 2.0f;
                }
            }
            else
            {
                y_vel_approach(-10.0f, 0.5f);
            }
        }
        else if (o->oMoveFlags & 0x00000200)
        {
            o->oSwoopTargetYaw = func_802A2AC0();
            o->oSwoopTimeUntilTurn = 30;
        }

        if ((o->oSwoopTargetPitch = func_802F86C0()) == 0)
        {
            o->oSwoopTargetPitch += o->oForwardVel * 500.0f;
        }

        func_802F95B0(o->oSwoopTargetPitch, 140);
        func_8029DE70(
            o->oSwoopTargetYaw + (s32)(3000.0f * coss(4000 * gGlobalTimer)),
            1200);

        func_802F9850(o->oSwoopTargetYaw, 0x3000, 500);

        o->oFaceAngleRoll += (s32)(1000.0f * coss(20000 * gGlobalTimer));
    }
}

void bhv_swoop_update(void)
{
    if (!(o->active & 0x0008))
    {
        o->oUnk1C4 = 0x5062B081;

        MoveRelated();

        switch (o->oAction)
        {
        case SWOOP_ACT_IDLE: swoop_act_idle(); break;
        case SWOOP_ACT_MOVE: swoop_act_move(); break;
        }

        ScaleObject(o->header.gfx.scale[0]);
        MoveObj(78);
        func_802FA888(&D_80331788, o->oAction);
    }
}
