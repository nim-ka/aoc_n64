#include <ultra64.h>

#include "sm64.h"
#include "gfx_dimensions.h"
#include "buffers/buffers.h"
#include "buffers/gfx_output_buffer.h"
#include "buffers/framebuffers.h"
#include "game_init.h"
#include "main.h"
#include "custom.h"
#include <prevent_bss_reordering.h>

// FIXME: I'm not sure all of these variables belong in this file, but I don't
// know of a good way to split them
struct Controller gControllers[3];
struct SPTask *gGfxSPTask;
Gfx *gDisplayListHead;
u8 *gGfxPoolEnd;
struct GfxPool *gGfxPool;
OSContStatus gControllerStatuses[4];
OSContPad gControllerPads[4];
u8 gControllerBits;
s8 gEepromProbe;
OSMesgQueue gGameVblankQueue;
OSMesgQueue D_80339CB8;
OSMesg D_80339CD0;
OSMesg D_80339CD4;
struct VblankHandler gGameVblankHandler;
void *D_80339CF0;
void *D_80339CF4;
struct MarioAnimation D_80339D10;
struct MarioAnimation gDemo;
UNUSED u8 filler80339D30[0x90];

int unused8032C690 = 0;
u32 gGlobalTimer = 0;

void (*D_8032C6A0)(void) = NULL;
struct Controller *gPlayer1Controller = &gControllers[0];
struct Controller *gPlayer2Controller = &gControllers[1];
// probably debug only, see note below
struct Controller *gPlayer3Controller = &gControllers[2];
struct DemoInput *gCurrDemoInput = NULL; // demo input sequence
u16 gDemoInputListID = 0;
struct DemoInput gRecordedDemoInput = { 0 }; // possibly removed in EU. TODO: Check

/**
 * Initializes the Reality Display Processor (RDP).
 * This function initializes settings such as texture filtering mode,
 * scissoring, and render mode (although keep in mind that this render
 * mode is not used in-game, where it is set in render_graph_node.c).
 */
void my_rdp_init(void) {
    gDPPipeSync(gDisplayListHead++);
    gDPPipelineMode(gDisplayListHead++, G_PM_1PRIMITIVE);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);

    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);

    gDPSetCombineKey(gDisplayListHead++, G_CK_NONE);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

#ifdef VERSION_SH
    gDPSetAlphaDither(gDisplayListHead++, G_AD_PATTERN);
#endif
    gDPPipeSync(gDisplayListHead++);
}

/**
 * Initializes the RSP's built-in geometry and lighting engines.
 * Most of these (with the notable exception of gSPNumLights), are
 * almost immediately overwritten.
 */
void my_rsp_init(void) {
    gSPClearGeometryMode(gDisplayListHead++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH | G_FOG
                        | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD);

    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LIGHTING);

    gSPNumLights(gDisplayListHead++, NUMLIGHTS_1);
    gSPTexture(gDisplayListHead++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

    // @bug Nintendo did not explicitly define the clipping ratio.
    // For Fast3DEX2, this causes the dreaded warped vertices issue
    // unless the clipping ratio is changed back to the intended value,
    // as Fast3DEX2 uses a different initial value than Fast3D(EX).
#ifdef F3DEX_GBI_2
    gSPClipRatio(gDisplayListHead++, FRUSTRATIO_1);
#endif
}

/**
 * Loads the F3D microcodes.
 * Refer to this function if you would like to load
 * other microcodes (i.e. S2DEX).
 */
void create_task_structure(void) {
    s32 entries = gDisplayListHead - gGfxPool->buffer;

    gGfxSPTask->msgqueue = &D_80339CB8;
    gGfxSPTask->msg = (OSMesg) 2;
    gGfxSPTask->task.t.type = M_GFXTASK;
    gGfxSPTask->task.t.ucode_boot = rspF3DBootStart;
    gGfxSPTask->task.t.ucode_boot_size = ((u8 *) rspF3DBootEnd - (u8 *) rspF3DBootStart);
    gGfxSPTask->task.t.flags = 0;
    gGfxSPTask->task.t.ucode = rspF3DStart;
    gGfxSPTask->task.t.ucode_data = rspF3DDataStart;
    gGfxSPTask->task.t.ucode_size = SP_UCODE_SIZE; // (this size is ignored)
    gGfxSPTask->task.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    gGfxSPTask->task.t.dram_stack = (u64 *) gGfxSPTaskStack;
    gGfxSPTask->task.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    gGfxSPTask->task.t.output_buff = gGfxSPTaskOutputBuffer;
    gGfxSPTask->task.t.output_buff_size =
        (u64 *)((u8 *) gGfxSPTaskOutputBuffer + sizeof(gGfxSPTaskOutputBuffer));
    gGfxSPTask->task.t.data_ptr = (u64 *) &gGfxPool->buffer;
    gGfxSPTask->task.t.data_size = entries * sizeof(Gfx);
    gGfxSPTask->task.t.yield_data_ptr = (u64 *) gGfxSPTaskYieldBuffer;
    gGfxSPTask->task.t.yield_data_size = OS_YIELD_DATA_SIZE;
}

/** Starts rendering the scene. */
void init_render_image(void) {
    my_rdp_init();
    my_rsp_init();
}

/** Ends the master display list. */
void end_master_display_list(void) {
    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);

    create_task_structure();
}

void rendering_init(void) {
    gGfxPool = &gGfxPools[0];
    gGfxSPTask = &gGfxPool->spTask;
    gDisplayListHead = gGfxPool->buffer;
    gGfxPoolEnd = (u8 *) (gGfxPool->buffer + GFX_POOL_SIZE);
    init_render_image();
    end_master_display_list();
    send_display_list(&gGfxPool->spTask);

    gGlobalTimer++;
}

void config_gfx_pool(void) {
    gGfxPool = &gGfxPools[gGlobalTimer % 2];
    gGfxSPTask = &gGfxPool->spTask;
    gDisplayListHead = gGfxPool->buffer;
    gGfxPoolEnd = (u8 *) (gGfxPool->buffer + GFX_POOL_SIZE);
}

extern void custom_entry(void);

/** Handles vsync. */
void display_and_vsync(void) {
    osRecvMesg(&D_80339CB8, &D_80339BEC, OS_MESG_BLOCK);
    if (D_8032C6A0 != NULL) {
        D_8032C6A0();
        D_8032C6A0 = NULL;
    }
    send_display_list(&gGfxPool->spTask);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    osViSwapBuffer(gFrameBuffer);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    gGlobalTimer++;
}

void setup_game_memory(void) {
    UNUSED u8 pad[8];

    osCreateMesgQueue(&D_80339CB8, &D_80339CD4, 1);
    osCreateMesgQueue(&gGameVblankQueue, &D_80339CD0, 1);
}

// main game loop thread. runs forever as long as the game
// continues.
void thread5_game_loop(UNUSED void *arg) {
    setup_game_memory();

    set_vblank_handler(2, &gGameVblankHandler, &gGameVblankQueue, (OSMesg) 1);

    rendering_init();
    fb_init();

    while (1) {
        config_gfx_pool();
        init_render_image();
        end_master_display_list();
        custom_entry();
        fb_display();
        display_and_vsync();
        osViBlack(FALSE);
    }
}
