// moat_drainer.c.inc

void BehInvisibleObjUnderBridge(void)
{
    if(save_file_get_flags() & SAVE_FLAG_MOAT_DRAINED)
    {
        gWaterRegions[6]    = -800;
        gWaterRegions[12] = -800;
    }
}
