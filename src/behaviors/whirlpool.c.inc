// whirlpool.c.inc

void BehWhirlpoolInit(void)
{
    o->oWhirlpoolInitFacePitch = o->oFaceAnglePitch;
    o->oWhirlpoolInitFaceRoll = o->oFaceAngleRoll;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
}

void func_802E70A8(void)
{
    set_object_hitbox(o, &sWhirlpoolHitbox);
}

void func_802E70DC(void)
{
    f32 cosPitch = coss(o->oFaceAnglePitch);
    f32 sinPitch = sins(o->oFaceAnglePitch);
    f32 cosRoll = coss(o->oFaceAngleRoll);
    f32 sinRoll = sins(o->oFaceAngleRoll);
    f32 normalX = sinRoll * cosPitch;
    f32 normalY = cosPitch * cosRoll;
    f32 normalZ = sinPitch;
    ObjOrientGraph(o, normalX, normalY, normalZ);
}

void BehWhirlpoolLoop(void)
{
    if (o->oDistanceToMario < 5000.0f)
    {
        o->header.gfx.node.flags &= ~0x10; /* bit 4 */

        //not sure if actually an array
        D_803600B0[7] = 60;
        D_803600B0[1] = o->oPosX;
        D_803600B0[3] = o->oPosZ;
        D_803600B0[4] = o->oPosX;
        D_803600B0[5] = o->oPosY;
        D_803600B0[6] = o->oPosZ;
        D_803600B0[2] = o->oPosY + 800.0f;
        D_803600B0[8] = o->oWhirlpoolInitFacePitch;
        D_803600B0[9] = o->oWhirlpoolInitFaceRoll;
        
        func_802E70DC();
        
        o->oFaceAngleYaw += 0x1F40;
    }
    else
    {
        o->header.gfx.node.flags |= 0x10; /* bit 4 */
        D_803600B0[7] = 0;
    }

    PlaySound(0x40090001);

    func_802E70A8();
}

void BehJetStreamLoop(void)
{
    if (o->oDistanceToMario < 5000.0f)
    {
        D_803600B0[7] = 60;
        D_803600B0[1] = o->oPosX;
        D_803600B0[2] = o->oPosY;
        D_803600B0[3] = o->oPosZ;
    }
    else D_803600B0[7] = 0;

    PlaySound(0x40090001);
}
