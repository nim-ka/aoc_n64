// celebration_star.c.inc

void BehCelebrationStarInit(void)
{
    o->oHomeX = gMarioObject->header.gfx.pos[0];
    o->oPosY = gMarioObject->header.gfx.pos[1] + 30.0f;
    o->oHomeZ = gMarioObject->header.gfx.pos[2];
    o->oMoveAngleYaw = gMarioObject->header.gfx.angle[1] + 0x8000;
    o->oCelebStarDiameterOfRotation = 100;
#ifdef VERSION_JP
    o->header.gfx.asGraphNode = gLoadedGraphNodes[122];
    obj_scale(0.4f);
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
#else
    if (gCurrLevelNum == LEVEL_BOWSER_1 || gCurrLevelNum == LEVEL_BOWSER_2)
    {
        o->header.gfx.asGraphNode = gLoadedGraphNodes[204];
        o->oFaceAnglePitch = 0;
        o->oFaceAngleRoll = 49152;
        obj_scale(0.1f);
        o->oUnknownUnkF4_S32 = 1;
    }
    else
    {
        o->header.gfx.asGraphNode = gLoadedGraphNodes[122];
        o->oFaceAnglePitch = 0;
        o->oFaceAngleRoll = 0;
        obj_scale(0.4f);
        o->oUnknownUnkF4_S32 = 0;
    }
#endif
}

void CelebrationStarSpinAroundMarioLoop(void)
{
    o->oPosX = o->oHomeX + sins(o->oMoveAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosZ = o->oHomeZ + coss(o->oMoveAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosY += 5.0f;
    o->oFaceAngleYaw += 0x1000;
    o->oMoveAngleYaw += 0x2000;
    
    if (o-> oTimer == 40) o->oAction = CELEB_STAR_ACT_FACE_CAMERA;
    if (o-> oTimer < 35)
    {
        spawn_object(o, 149, beh_celebration_star_sparkle);
        o->oCelebStarDiameterOfRotation++;
    }
    else o->oCelebStarDiameterOfRotation -= 20;
}

void CelebrationStarFaceCameraLoop(void)
{

    if (o->oTimer < 10)
    {
#ifdef VERSION_JP
        obj_scale((f32)o->oTimer / 10.0);
#else
        if(o->oUnknownUnkF4_S32 == 0)
        {
            obj_scale((f32)o->oTimer / 10.0);
        }
        else
        {
            obj_scale((f32)o->oTimer / 30.0);
        }
#endif
        o->oFaceAngleYaw += 0x1000;
    }
    else
    {
        o->oFaceAngleYaw = gMarioObject->header.gfx.angle[1];
    }
    
    if (o->oTimer == 59) o->activeFlags = 0;
}

void BehCelebrationStarLoop(void)
{
    switch (o->oAction)
    {
        case CELEB_STAR_ACT_SPIN_AROUND_MARIO:
            CelebrationStarSpinAroundMarioLoop();
            break;
            
        case CELEB_STAR_ACT_FACE_CAMERA:
            CelebrationStarFaceCameraLoop();
            break;
    }
}

void BehCelebrationStarSparkleLoop(void)
{
    o->oPosY -= 15.0f;
    
    if (o->oTimer == 12) o->activeFlags = 0;
}

void BehStarKeyCollectionPuffSpawnerLoop(void)
{
    func_802AA618(0, 10, 30.0f);
    o->activeFlags = 0;
}
