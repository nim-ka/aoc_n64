// bowling_ball.c.inc

void BehBowlingBallInit(void)
{
    o->oGravity = 5.5f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
}

void func_802EDA14(void)
{
    set_object_hitbox(o, &sBowlingBallHitbox);
    
    if (o->oInteractStatus & 0x8000) o->oInteractStatus = 0;
}

void func_802EDA6C(void)
{
    switch (o->oBehParams2ndByte)
    {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oBowlingBallUnkFC = segmented_to_virtual(bob_seg7_metal_ball_path0);
            break;
            
        case BBALL_BP_STYPE_TTM:
            o->oBowlingBallUnkFC = segmented_to_virtual(ttm_seg7_trajectory_070170A0);
            break;
            
        case BBALL_BP_STYPE_BOB_LOWER:
            o->oBowlingBallUnkFC = segmented_to_virtual(bob_seg7_metal_ball_path1);
            break;
            
        case BBALL_BP_STYPE_THI_LARGE:
            o->oBowlingBallUnkFC = D_803315B4;
            break;
            
        case BBALL_BP_STYPE_THI_SMALL:
            o->oBowlingBallUnkFC = D_80331608;
            break;
    }
}

void BehBowlingBallRollLoop(void)
{
    s16 collisionFlags;
    s32 sp18;
    
    func_802EDA6C();
    collisionFlags = ObjectStep();
    
    //! Uninitialzed parameter, but the parameter is unused in the called function
    sp18 = obj_follow_path(sp18);
    
    //! oBowlingBallInitYaw is never explicitly initialized, so it is 0.
    o->oBowlingBallTargetYaw = o->oBowlingBallInitYaw;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oBowlingBallTargetYaw, 0x400);
    if (o->oForwardVel > 70.0)
    {
        o->oForwardVel = 70.0;
    }
    
    func_802EDA14();
    
    if (sp18 == -1)
    {
        if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 7000))
        {
            func_802A3004();
            func_802AA618(0, 0, 92.0f);
        }
        
        o->activeFlags = 0;
    }
    
    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) && (o->oVelY > 5.0f))
        PlaySound2(0x30400081);
}

void BehBowlingBallInitializeLoop(void)
{
    s32 sp1c;
    
    func_802EDA6C();
    
    //! Uninitialzed parameter, but the parameter is unused in the called function
    sp1c = obj_follow_path(sp1c);
    
    //! oBowlingBallInitYaw is never explicitly initialized, so it is 0.
    o->oMoveAngleYaw = o->oBowlingBallInitYaw;
    
    switch (o->oBehParams2ndByte)
    {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oForwardVel = 20.0f;
            break;
            
        case BBALL_BP_STYPE_TTM:
            o->oForwardVel = 10.0f;
            break;
            
        case BBALL_BP_STYPE_BOB_LOWER:
            o->oForwardVel = 20.0f;
            break;
            
        case BBALL_BP_STYPE_THI_LARGE:
            o->oForwardVel = 25.0f;
            break;
            
        case BBALL_BP_STYPE_THI_SMALL:
            o->oForwardVel = 10.0f;
            obj_scale(0.3f);
            o->oGraphYOffset = 39.0f;
            break;
    }
}

void BehBowlingBallLoop(void)
{
    switch (o->oAction)
    {
        case BBALL_ACT_INITIALIZE:
            o->oAction = BBALL_ACT_ROLL;
            BehBowlingBallInitializeLoop();
            break;
            
        case BBALL_ACT_ROLL:
            BehBowlingBallRollLoop();
            break;
    }
    
    if (o->oBehParams2ndByte != 4)
        func_8027F440(4, o->oPosX, o->oPosY, o->oPosZ);
    
    SetObjectVisibility(o, 4000);
}

void BehGenericBowlingBallSpawnerInit(void)
{
    switch (o->oBehParams2ndByte)
    {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oBBallSpwnrMaxSpawnDist = 7000.0f;
            o->oBBallSpwnrSpawnOdds = 2.0f;
            break;
            
        case BBALL_BP_STYPE_TTM:
            o->oBBallSpwnrMaxSpawnDist = 8000.0f;
            o->oBBallSpwnrSpawnOdds = 1.0f;
            break;
            
        case BBALL_BP_STYPE_BOB_LOWER:
            o->oBBallSpwnrMaxSpawnDist = 6000.0f;
            o->oBBallSpwnrSpawnOdds = 2.0f;
            break;
    }
}

void BehGenericBowlingBallSpawnerLoop(void)
{
    struct Object *bowlingBall;
    
    if (o->oTimer == 256)
        o->oTimer = 0;
    
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1000)
    ||  (o->oPosY < gMarioObject->header.gfx.pos[1]))
        return;
    
    if ((o->oTimer & o->oBBallSpwnrPeriodMinus1) == 0) /* Modulus */
    {
        if  (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, o->oBBallSpwnrMaxSpawnDist))
        {
            if  ((s32)(RandomFloat() * o->oBBallSpwnrSpawnOdds) == 0)
            {
                bowlingBall = spawn_object(o, 180, beh_bowling_ball);
                bowlingBall->oBehParams2ndByte = o->oBehParams2ndByte;
            }
        }
    }
}

void BehTHIBowlingBallSpawnerLoop(void)
{
    struct Object *bowlingBall;
    
    if (o->oTimer == 256)
        o->oTimer = 0;
    
    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 800)
    ||  (o->oPosY < gMarioObject->header.gfx.pos[1]))
        return;
        
    if ((o->oTimer % 64) == 0)
    {
        if  (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 12000))
        {
            if  ((s32)(RandomFloat() * 1.5) == 0)
            {
                bowlingBall = spawn_object(o, 180, beh_bowling_ball);
                bowlingBall->oBehParams2ndByte = o->oBehParams2ndByte;
            }
        }
    }
}

void BehBOBPitBowlingBallInit(void)
{
    o->oGravity = 12.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
}

void BehBOBPitBowlingBallLoop(void)
{
    f32 *sp1c;
    UNUSED s16 collisionFlags = ObjectStep();
    
    func_803814B8(o->oPosX, o->oPosY, o->oPosZ, &sp1c);
    if ((sp1c[4] == 0) && (sp1c[6] == 0))
        o->oForwardVel = 28.0f;
    
    func_802EDA14();
    func_8027F440(4, o->oPosX, o->oPosY, o->oPosZ);
    PlaySound(0x400A0001);
    SetObjectVisibility(o, 3000);
}

void BehFreeBowlingBallInit(void)
{
    o->oGravity = 5.5f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oForwardVel = 0;
    o->oMoveAngleYaw = 0;
}

void BehFreeBowlingBallRollLoop(void)
{
    s16 collisionFlags = ObjectStep();
    func_802EDA14();
    
    if (o->oForwardVel > 10.0f)
    {
        func_8027F440(4, o->oPosX, o->oPosY, o->oPosZ);
        PlaySound(0x400A0001);
    }
    
    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED)
    &&  !(collisionFlags & OBJ_COL_FLAGS_LANDED))
        PlaySound2(0x30400081);
        
    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 6000))
    {
        o->header.gfx.node.flags |= 0x10; /* bit 4 */
        obj_become_intangible();
        
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        BehFreeBowlingBallInit();
        o->oAction = FREE_BBALL_ACT_RESET;
    }
}

void BehFreeBowlingBallLoop(void)
{
    o->oGravity = 5.5f;
    
    switch (o->oAction)
    {
        case FREE_BBALL_ACT_IDLE:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 3000))
            {
                o->oAction = FREE_BBALL_ACT_ROLL;
                o->header.gfx.node.flags &= ~0x10; /* bit 4 */
                obj_become_tangible();
            }
            break;
            
        case FREE_BBALL_ACT_ROLL:
            BehFreeBowlingBallRollLoop();
            break;
            
        case FREE_BBALL_ACT_RESET:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 5000))
                o->oAction = FREE_BBALL_ACT_IDLE;
            break;
    }
}
