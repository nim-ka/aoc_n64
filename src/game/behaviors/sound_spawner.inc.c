// sound_spawner.c.inc

void BehPlaySound(void)
{
    s32 sp1C = o->oSoundEffectUnkF4;
    SetSound(sp1C, &o->header.gfx.unk54);
}
