
void bhv_ddd_pole_init(void)
{
    if (!(save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_2 | SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR)))
    {
        DeactivateObject(o);
    }
    else
    {
        o->hitboxDownOffset = 100.0f;
        o->oDDDPoleMaxOffset = 100.0f * o->oBehParams2ndByte;
    }
}

void bhv_ddd_pole_update(void)
{
    if (o->oTimer > 20)
    {
        o->oDDDPoleOffset += o->oDDDPoleVel;

        if (cap_f32(&o->oDDDPoleOffset, 0.0f, o->oDDDPoleMaxOffset))
        {
            o->oDDDPoleVel = -o->oDDDPoleVel;
            o->oTimer = 0;
        }
    }

    func_802F8770(o->oDDDPoleOffset);
}
