
void bhv_horizontal_grindel_init(void)
{
    o->oHorizontalGrindelTargetYaw = o->oAngleYaw;
}

void bhv_horizontal_grindel_update(void)
{
    if (o->oMoveFlags & 0x00000003)
    {
        if (!o->oHorizontalGrindelOnGround)
        {
            PlaySound2(0x500CA081);
            o->oHorizontalGrindelOnGround = TRUE;
            func_8027F440(1, o->oPosX, o->oPosY, o->oPosZ);

            o->oHorizontalGrindelDistToHome = obj_lateral_dist_to_home();
            o->oForwardVel = 0.0f;
            o->oTimer = 0;
        }

        if (func_8029DE70(o->oHorizontalGrindelTargetYaw, 0x400))
        {
            if (o->oTimer > 60)
            {
                if (o->oHorizontalGrindelDistToHome > 300.0f)
                {
                    o->oHorizontalGrindelTargetYaw += 0x8000;
                    o->oHorizontalGrindelDistToHome = 0.0f;
                }
                else
                {
                    PlaySound2(0x50468081);
                    o->oForwardVel = 11.0f;
                    o->oVelY = 70.0f;
                    o->oGravity = -4.0f;
                    o->oMoveFlags = 0;
                }
            }
        }
        else
        {
            o->oTimer = 0;
        }
    }
    else
    {
        o->oHorizontalGrindelOnGround = FALSE;
        if (o->oVelY < 0.0f)
        {
            o->oGravity = -16.0f;
        }
    }

    o->oFaceAngleYaw = o->oAngleYaw + 0x4000;
    MoveObj(78);
}
