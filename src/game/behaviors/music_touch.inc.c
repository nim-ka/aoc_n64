// music_touch.c.inc

void BehPlayMusicTrackWhenTouchedLoop(void)
{
    if(o->oAction == 0)
    {
        if(o->oDistanceToMario < 200.0f)
        {
            func_80321228();
            o->oAction++;
        }
    }
}
