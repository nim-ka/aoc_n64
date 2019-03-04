// collide_particles.c.inc

void BehPunchTinyTriangleLoop(void)
{
    s16 sp1E;
    if(o->oTimer == 0)
    {
        sp1E = o->oMoveAngleYaw;
        o->OBJECT_FIELD_F32(0x1B) = 1.28f;
        obj_set_pos_relative(gMarioObject,0.0f,60.0f,100.0f);
        o->oMoveAngleYaw = sp1E; // does obj_set_pos_relative modify currentObject?
    }
    obj_move_using_fvel_and_gravity();
    o->oAnimState = 5;
    obj_scale(o->OBJECT_FIELD_F32(0x1B));
    o->OBJECT_FIELD_F32(0x1B) -= 0.2f;
    if(gDebugInfo[4][0] + 6 < o->oTimer)
        mark_object_for_deletion(o);
}

void BehPunchTinyTriangleInit(void)
{
    s32 i;
    UNUSED s32 unused;
    struct Object* triangle;
    for(i=0;i<6;i++)
    {
        triangle = spawn_object(o,138,beh_punch_tiny_triangle);
        triangle->oMoveAngleYaw = gMarioObject->oMoveAngleYaw + D_8032F2CC[2*i] + 0x8000;
        triangle->oVelY = sins(D_8032F2CC[2*i+1]) * 25.0f;
        triangle->oForwardVel = coss(D_8032F2CC[2*i+1]) * 25.0f;
    }
}

void BehWallTinyStarParticleLoop(void)
{
    s16 sp1E;
    if(o->oTimer == 0)
    {
        sp1E = o->oMoveAngleYaw;
        o->OBJECT_FIELD_F32(0x1B) = 0.28f;
        obj_set_pos_relative(gMarioObject,0.0f,30.0f,110.0f);
        o->oMoveAngleYaw = sp1E;
    }
    obj_move_using_fvel_and_gravity();
    o->oAnimState = 4;
    obj_scale(o->OBJECT_FIELD_F32(0x1B));
    o->OBJECT_FIELD_F32(0x1B) -= 0.015f;
}

void BehTinyStarParticlesInit(void)
{
    s32 i;
    UNUSED s32 unused;
    struct Object* particle;
    for(i=0;i<7;i++)
    {
        particle = spawn_object(o,139,beh_wall_tiny_star_particle);
        particle->oMoveAngleYaw = gMarioObject->oMoveAngleYaw + D_8032F2E4[2*i] + 0x8000;
        particle->oVelY = sins(D_8032F2E4[2*i+1]) * 25.0f;
        particle->oForwardVel = coss(D_8032F2E4[2*i+1]) * 25.0f;
    }
}

void BehPoundTinyStarParticleLoop(void)
{
    if(o->oTimer == 0)
    {
        o->OBJECT_FIELD_F32(0x1B) = 0.28f;
        o->oForwardVel = 25.0f;
        o->oPosY -= 20.0f;
        o->oVelY = 14.0f;
    }
    obj_move_using_fvel_and_gravity();
    o->oAnimState = 4;
    obj_scale(o->OBJECT_FIELD_F32(0x1B));
    o->OBJECT_FIELD_F32(0x1B) -= 0.015f;
}

void BehPoundTinyStarParticleInit(void)
{
    s32 sp24;
    s32 sp20 = 8;
    struct Object* particle;
    for(sp24=0;sp24<sp20;sp24++)
    {
        particle = spawn_object(o,139,beh_pound_tiny_star_particle);
        particle->oMoveAngleYaw = (sp24 << 16)/sp20;
    }
}
