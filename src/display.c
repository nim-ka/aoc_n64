#include <ultra64.h>

#include "sm64.h"
#include "game.h"
#include "main.h"
#include "memory.h"
#include "profiler.h"
#include "audio/interface_2.h"
#include "display.h"

int unused8032C690 = 0;
u32 gGlobalTimer = 0;
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

static void CreateTaskStructure(void)
{
    int entries = gDisplayListHead - gGfxPool->buffer;

    gGfxSPTask->msgqueue = &D_80339CB8;
    gGfxSPTask->msg = (OSMesg *)2;
    gGfxSPTask->task.t.type = M_GFXTASK;
    gGfxSPTask->task.t.ucode_boot = rspF3DBootStart;
    gGfxSPTask->task.t.ucode_boot_size = ((u32)rspF3DBootEnd - (u32)rspF3DBootStart);
    gGfxSPTask->task.t.flags = 0;
    gGfxSPTask->task.t.ucode = rspF3DBootEnd;
    gGfxSPTask->task.t.ucode_data = rspF3DDataStart;
    gGfxSPTask->task.t.ucode_size = SP_UCODE_SIZE;
    gGfxSPTask->task.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    gGfxSPTask->task.t.dram_stack = (u64 *)gGfxSPTaskStack;
    gGfxSPTask->task.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    gGfxSPTask->task.t.output_buff = (u64 *)gGfxSPTaskOutputBuffer;
    gGfxSPTask->task.t.output_buff_size = (u64 *)(gGfxSPTaskOutputBuffer + 0x1F000);
    gGfxSPTask->task.t.data_ptr = (u64 *)&gGfxPool->buffer;
    gGfxSPTask->task.t.data_size = entries * sizeof(Gfx);
    gGfxSPTask->task.t.yield_data_ptr = (u64 *)gGfxSPTaskYieldBuffer;
    gGfxSPTask->task.t.yield_data_size = OS_YIELD_DATA_SIZE;
}

void func_80247C9C(void)
{
    move_segment_table_to_dmem();
    myRdpInit();
    myRspInit();
    ClearZBuffer();
    DisplayFrameBuffer();
}

void CleanupDisplayList(void)
{
    func_8024781C();
    if (gShowProfiler)
        draw_profiler();

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
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
}

void func_80247ED8(void)
{
    gGfxPool = &gGfxPools[0];
    set_segment_base_addr(1, gGfxPool->buffer);
    gGfxSPTask = &gGfxPool->spTask;
    gDisplayListHead = gGfxPool->buffer;
    gGfxPoolEnd = (u8 *)(gGfxPool->buffer + GFX_POOL_SIZE);
    func_80247C9C();
    ClearFrameBuffer(0);
    CleanupDisplayList();
    SendDisplayList(&gGfxPool->spTask);

    D_8032C69C++;
    gGlobalTimer++;
}

void func_80247FAC(void)
{
    gGfxPool = &gGfxPools[gGlobalTimer % 2];
    set_segment_base_addr(1, gGfxPool->buffer);
    gGfxSPTask = &gGfxPool->spTask;
    gDisplayListHead = gGfxPool->buffer;
    gGfxPoolEnd = (u8 *)(gGfxPool->buffer + GFX_POOL_SIZE);
}

void display_and_vsync(void)
{
    profiler_log_thread5_time(BEFORE_DISPLAY_LISTS);
    osRecvMesg(&D_80339CB8, &D_80339BEC, OS_MESG_BLOCK);
    if (D_8032C6A0 != NULL)
    {
        D_8032C6A0();
        D_8032C6A0 = NULL;
    }
    SendDisplayList(&gGfxPool->spTask);
    profiler_log_thread5_time(AFTER_DISPLAY_LISTS);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    osViSwapBuffer((void *)PHYSICAL_TO_VIRTUAL(gFrameBuffers[sCurrFBNum]));
    profiler_log_thread5_time(THREAD5_END);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    if (++sCurrFBNum == 3)
        sCurrFBNum = 0;
    if (++D_8032C69C == 3)
        D_8032C69C = 0;
    gGlobalTimer++;
}
