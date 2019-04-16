// music_touch.c.inc

void BehPlayMusicTrackWhenTouchedLoop(void)
{
    if(o->oAction == 0)
    {
        if(o->oDistanceToMario < 200.0f)
        {
            play_puzzle_jingle();
            o->oAction++;
        }
    }
}
