#include <ultra64.h>

#include "sm64.h"
#include "main.h"
#include "input.h"

int unused8032C690 = 0;
u32 D_8032C694 = 0;
static u16 sCurrFBNum = 0;
u16 D_8032C69C = 0;

void myRdpInit(void)
{
    gDPPipeSync(gDisplayListHead++);
    gDPPipelineMode(gDisplayListHead++, G_PM_1PRIMITIVE);
    
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPSetCombine(gDisplayListHead++, 0xFFFFFF, 0xFFFE793C);

    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);

    gDPSetCombineKey(gDisplayListHead++, G_CK_NONE);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    gDPSetRenderMode(gDisplayListHead++, 0x0F0A4000, 0x0F0A4000);
    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPPipeSync(gDisplayListHead++);
}

void myRspInit(void)
{
    gSPClearGeometryMode(gDisplayListHead++,
        G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH | G_FOG | G_LIGHTING |
        G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD);

    gSPSetGeometryMode(gDisplayListHead++,
        G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LIGHTING);

    gSPNumLights(gDisplayListHead++, 1);
    gSPTexture(gDisplayListHead++, 0, 0, 0, 0, 0);
}

void ClearZBuffer(void)
{
    gDPPipeSync(gDisplayListHead++);

    gDPSetDepthSource(gDisplayListHead++, G_ZS_PIXEL);
    gDPSetDepthImage(gDisplayListHead++, D_80339CEC);

    gDPSetColorImage(gDisplayListHead++, G_IM_FMT_RGBA, 2, 320, D_80339CEC);
    gDPSetFillColor(gDisplayListHead++,
        GPACK_RGBA5551(255, 255, 240, 0) << 16 | GPACK_RGBA5551(255, 255, 240, 0));

    gDPFillRectangle(gDisplayListHead++, 0, 8, 319, 231);
}

void DisplayFrameBuffer(void)
{
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetColorImage(gDisplayListHead++, G_IM_FMT_RGBA, 2, 320, gFrameBuffers[D_8032C69C]);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
}

void ClearFrameBuffer(int a)
{
    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, 0x0F0A4000, 0x0F0A4000);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPSetFillColor(gDisplayListHead++, a);
    gDPFillRectangle(gDisplayListHead++, 0, 8, 319, 231);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

void DisplayInit(Vp *viewport, int b)
{
    s16 sp26 = (viewport->vp.vtrans[0] - viewport->vp.vscale[0]) / 4 + 1;
    s16 sp24 = (viewport->vp.vtrans[1] - viewport->vp.vscale[1]) / 4 + 1;
    s16 sp22 = (viewport->vp.vtrans[0] + viewport->vp.vscale[0]) / 4 - 2;
    s16 sp20 = (viewport->vp.vtrans[1] + viewport->vp.vscale[1]) / 4 - 2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, 0x0F0A4000, 0x0F0A4000);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPSetFillColor(gDisplayListHead++, b);
    gDPFillRectangle(gDisplayListHead++, sp26, sp24, sp22, sp20);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

void func_8024781C(void)
{
    gDPPipeSync(gDisplayListHead++);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPSetRenderMode(gDisplayListHead++, 0x0F0A4000, 0x0F0A4000);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPSetFillColor(gDisplayListHead++,
        GPACK_RGBA5551(0, 0, 0, 0) << 16 | GPACK_RGBA5551(0, 0, 0, 0));
    gDPFillRectangle(gDisplayListHead++, 0, 0, 319, 7);
    gDPFillRectangle(gDisplayListHead++, 0, 232, 319, 239);
}

void func_8024798C(Vp *viewport)
{
    s16 spE = (viewport->vp.vtrans[0] - viewport->vp.vscale[0]) / 4 + 1;
    s16 spC = (viewport->vp.vtrans[1] - viewport->vp.vscale[1]) / 4 + 1;
    s16 spA = (viewport->vp.vtrans[0] + viewport->vp.vscale[0]) / 4 - 1;
    s16 sp8 = (viewport->vp.vtrans[1] + viewport->vp.vscale[1]) / 4 - 1;

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, spE, spC, spA, sp8);
}

void CreateTaskStructure(void)
{
    int sp4 = (gDisplayListHead - D_80339D04);

    D_80339CF8->msgqueue = &D_80339CB8;
    D_80339CF8->msg = (OSMesg *)2;
    D_80339CF8->task.t.type = 1;
    D_80339CF8->task.t.ucode_boot = (u64 *)D_8032A320;
    D_80339CF8->task.t.ucode_boot_size = D_8032A3F0 - D_8032A320;
    D_80339CF8->task.t.flags = 0;
    D_80339CF8->task.t.ucode = (u64 *)D_8032A3F0;
    D_80339CF8->task.t.ucode_data = (u64 *)D_80338750;
    D_80339CF8->task.t.ucode_size = 4096;
    D_80339CF8->task.t.ucode_data_size = 2048;
    D_80339CF8->task.t.dram_stack = (u64 *)D_80207D00;
    D_80339CF8->task.t.dram_stack_size = 1024;
    D_80339CF8->task.t.output_buff = (u64 *)D_80227000;
    D_80339CF8->task.t.output_buff_size = (u64 *)(D_80227000 + 0x1F000);
    D_80339CF8->task.t.data_ptr = (u64 *)D_80339D04;
    D_80339CF8->task.t.data_size = sp4 * 8;
    D_80339CF8->task.t.yield_data_ptr = (u64 *)D_80207200;
    D_80339CF8->task.t.yield_data_size = 2304;
}

void func_80247C9C(void)
{
    MovePtrTbl2Dmem();
    myRdpInit();
    myRspInit();
    ClearZBuffer();
    DisplayFrameBuffer();
}

void CleanupDisplayList(void)
{
    func_8024781C();
    if (gShowResourceMeter)
        draw_resource_meter();

    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);

    CreateTaskStructure();
}

void func_80247D84(void)
{
    int sp24;
    int sp20;
    int fbNum;
    u64 *sp18;

    if (gResetTimer != 0 && D_8032C648 < 15)
    {
        if (sCurrFBNum == 0)
            fbNum = 2;
        else
            fbNum = sCurrFBNum - 1;

        sp18 = (u64 *)PHYSICAL_TO_VIRTUAL(gFrameBuffers[fbNum]);
        sp18 += D_8032C648++ * 80;

        for (sp24 = 0; sp24 < 16; sp24++)
        {
            for (sp20 = 0; sp20 < 80; sp20++)
            {
                *sp18 = 0;
                sp18++;
            }
            sp18 += 0x460;
        }
    }

    osWritebackDCacheAll();
    osRecvMesg(&D_80339CA0, &D_80339BEC, 1);
    osRecvMesg(&D_80339CA0, &D_80339BEC, 1);
}

// FIXME: find the correct types for these pointers to avoid unnecessary casting

void func_80247ED8(void)
{
    D_80339D04 = D_80208100;
    set_segment_base_addr(1, D_80339D04);
    D_80339CF8 = (struct Struct8032C630 *)((u8 *)D_80339D04 + 51200);
    gDisplayListHead = D_80339D04;
    gGfxPoolEnd = (u8 *)D_80339D04 + 51200;
    func_80247C9C();
    ClearFrameBuffer(0);
    CleanupDisplayList();
    SendDisplayList((u8 *)D_80339D04 + 51200);

    D_8032C69C++;
    D_8032C694++;
}

void func_80247FAC(void)
{
    D_80339D04 = (Gfx *)((u8 *)D_80208100 + (D_8032C694 % 2) * 51280);
    set_segment_base_addr(1, D_80339D04);
    D_80339CF8 = (struct Struct8032C630 *)((u8 *)D_80339D04 + 51200);
    gDisplayListHead = D_80339D04;
    gGfxPoolEnd = (u8 *)D_80339D04 + 51200;
}

void func_80248060(void)
{
    func_8027DE30(2);
    osRecvMesg(&D_80339CB8, &D_80339BEC, 1);
    if (D_8032C6A0 != NULL)
    {
        D_8032C6A0();
        D_8032C6A0 = NULL;
    }
    SendDisplayList((Gfx *)((u8 *)D_80339D04 + 51200));
    func_8027DE30(3);
    osRecvMesg(&D_80339CA0, &D_80339BEC, 1);
    osViSwapBuffer((void *)PHYSICAL_TO_VIRTUAL(gFrameBuffers[sCurrFBNum]));
    func_8027DE30(4);
    osRecvMesg(&D_80339CA0, &D_80339BEC, 1);
    if (++sCurrFBNum == 3)
        sCurrFBNum = 0;
    if (++D_8032C69C == 3)
        D_8032C69C = 0;
    D_8032C694++;
}
