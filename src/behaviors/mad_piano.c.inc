
static void mad_piano_act_wait(void)
{
    func_8029ED38(0);

    if (o->oDistanceToMario < 500.0f)
    {
        if (o->oTimer > 20)
        {
            if (gMarioStates[0].forwardVel > 10.0f)
            {
                o->oAction = MAD_PIANO_ACT_ATTACK;
                func_8029FE58();
            }
        }
    }
    else
    {
        o->oTimer = 0;
    }

    func_802A3164(280.0f, 150.0f);
}

static void mad_piano_act_attack(void)
{
    MoveRelated();
    func_8029ED38(1);
    func_802F9378(0, 0, 0x52564081);
    
    if (o->oDistanceToMario < 500.0f)
    {
        o->oTimer = 0;
    }
    
    if (o->oTimer > 80 && func_8029F788())
    {
        o->oAction = MAD_PIANO_ACT_WAIT;
        o->oForwardVel = 0.0f;
        func_8029FE38();
    }
    else
    {
        f32 dx = o->oPosX - o->oHomeX;
        f32 dz = o->oPosZ - o->oHomeZ;
        f32 distToHome = sqrtf(dx*dx + dz*dz);

        if (distToHome > 400.0f)
        {
            distToHome = 400.0f / distToHome;
            o->oPosX = o->oHomeX + dx * distToHome;
            o->oPosZ = o->oHomeZ + dz * distToHome;
        }

        func_8029DE70(o->oAngleToMario, 400);
        o->oForwardVel = 5.0f;
    }

    func_802FA888(&sMadPianoHitbox, o->oAction);
    MoveObj(78);
}

void bhv_mad_piano_update(void)
{
    if (!(o->active & 0x0008))
    {
        o->oFaceAngleYaw = o->oAngleYaw - 0x4000;

        switch (o->oAction)
        {
        case MAD_PIANO_ACT_WAIT:   mad_piano_act_wait();   break;
        case MAD_PIANO_ACT_ATTACK: mad_piano_act_attack(); break;
        }
    }
}
