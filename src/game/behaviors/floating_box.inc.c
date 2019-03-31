// floating_box.c.inc

void BehJrbFloatingBoxLoop(void) {
    o->oPosY = o->oHomeY + sins(o->oTimer * 0x400) * 10.0f;
}
