// water_objs.c.inc
// TODO: Better name, please

void BehWaterAirBubbleInit(void)
{
    obj_scale(4.0f);
}

// Fields 0xF4 & 0xF8 seem to be angles for bubble and cannon

void BehWaterAirBubbleLoop(void)
{
    s32 i;
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.5 + 4.0;
    o->header.gfx.scale[1] = -sins(o->OBJECT_FIELD_S32(0x1B)) * 0.5 + 4.0;
    o->OBJECT_FIELD_S32(0x1B) += 0x400;
    if(o->oTimer < 30)
    {
        obj_become_intangible();
        o->oPosY += 3.0f;
    }
    else
    {
        obj_become_tangible();
        obj_obj_forward_vel_approach_upward(2.0f,10.0f);
        o->oMoveAngleYaw = angle_to_object(o,gMarioObject);
        obj_move_using_fvel_and_gravity();
    }
    o->oPosX += RandomFloat() * 4.0f - 2.0f;
    o->oPosZ += RandomFloat() * 4.0f - 2.0f;
    if(o->oInteractStatus & 0x8000 || o->oTimer > 200)
    {
        PlaySound2(SOUND_GENERAL_QUIETBUBBLE);
        mark_object_for_deletion(o);
        for(i=0;i<30;i++)
            spawn_object(o,168,beh_bubble_maybe);
    }
    if(find_water_level(o->oPosX,o->oPosZ) < o->oPosY)
        mark_object_for_deletion(o);
    o->oInteractStatus = 0;
}

void BehBubbleWaveInit(void)
{
    o->OBJECT_FIELD_S32(0x1D) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    o->OBJECT_FIELD_S32(0x1E) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    PlaySound2(SOUND_GENERAL_QUIETBUBBLE);
}

void Unknown802A7E48(void)
{
    obj_scale(RandomFloat() + 1.0);
}

void BehBubbleMaybeLoop(void)
{
    o->oPosY += RandomFloat() * 3.0f    + 6.0f;
    o->oPosX += RandomFloat() * 10.0f - 5.0f;
    o->oPosZ += RandomFloat() * 10.0f - 5.0f;
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1B) += o->OBJECT_FIELD_S32(0x1D);
    o->header.gfx.scale[1] = sins(o->OBJECT_FIELD_S32(0x1C)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1C) += o->OBJECT_FIELD_S32(0x1E);
}

void BehSmallWaterWaveLoop(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1B) += o->OBJECT_FIELD_S32(0x1D);
    o->header.gfx.scale[1] = sins(o->OBJECT_FIELD_S32(0x1C)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1C) += o->OBJECT_FIELD_S32(0x1E);
    if(o->oPosY > sp1C)
    {
        o->activeFlags = 0;
        o->oPosY += 5.0f;
        if(gFreeObjectList.next != NULL)
            spawn_object(o,165,beh_water_surface_white_wave_2);
    }
    if(o->oInteractStatus & 0x8000)
        mark_object_for_deletion(o);
}

void func_802A81C4(void)
{
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.5 + 2.0;
    o->OBJECT_FIELD_S32(0x1B) += o->OBJECT_FIELD_S32(0x1D);
    o->header.gfx.scale[1] = sins(o->OBJECT_FIELD_S32(0x1C)) * 0.5 + 2.0;
    o->OBJECT_FIELD_S32(0x1C) += o->OBJECT_FIELD_S32(0x1E);
}

void BehParticleInit(void)
{
    scale_object_xyz(o,2.0f,2.0f,1.0f);
    o->OBJECT_FIELD_S32(0x1D) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    o->OBJECT_FIELD_S32(0x1E) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    translate_object_xyz_random(o,100.0f);
}

void BehParticleLoop() {
    f32 sp24 = find_water_level(o->oPosX,o->oPosZ);
    o->oPosY += 5.0f;
    translate_object_xz_random(o,4.0f);
    func_802A81C4();
    if(o->oPosY > sp24 && o->oTimer)
    {
        mark_object_for_deletion(o);
        try_to_spawn_object(5,0,o,165,beh_water_surface_white_wave_2);
    }
}

void BehSmallBubblesLoop(void)
{
    o->oPosY += 5.0f;
    translate_object_xz_random(o,4.0f);
    func_802A81C4();
}

void BehFishGroupLoop(void)
{
    if(gMarioCurrentRoom == 15 || gMarioCurrentRoom == 7)
        if(gGlobalTimer & 1)
            spawn_object(o,164,beh_small_particle_bubbles);
}

void BehWaterWavesInit(void)
{
    s32 sp1C;
    for(sp1C=0;sp1C<3;sp1C++)
        spawn_object(o,164,beh_small_particle);

}
