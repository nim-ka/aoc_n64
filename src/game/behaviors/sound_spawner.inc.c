// sound_spawner.c.inc

void BehPlaySound(void)
{
    s32 sp1C = o->oUnknownUnkF4_S32; // sound spawner
    SetSound(sp1C,&o->header.gfx.unk54);
}
