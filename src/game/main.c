#include <ultra64.h>
#include <stdio.h>

#include "sm64.h"
#include "game_init.h"
#include "buffers/buffers.h"
#include "segments.h"
#include "main.h"

// Message IDs
#define MESG_SP_COMPLETE 100
#define MESG_DP_COMPLETE 101
#define MESG_VI_VBLANK 102
#define MESG_START_GFX_SPTASK 103
#define MESG_NMI_REQUEST 104

OSThread D_80339210; // unused?
OSThread gIdleThread;
OSThread gMainThread;
OSThread gGameLoopThread;
OSThread gSoundThread;
#ifdef VERSION_SH
OSThread gRumblePakThread;

s32 gRumblePakPfs; // Actually an OSPfs but we don't have that header yet
#endif

OSIoMesg gDmaIoMesg;
OSMesg D_80339BEC;
OSMesgQueue gDmaMesgQueue;
OSMesgQueue gSIEventMesgQueue;
OSMesgQueue gPIMesgQueue;
OSMesgQueue gIntrMesgQueue;
OSMesgQueue gSPTaskMesgQueue;
#ifdef VERSION_SH
OSMesgQueue gRumblePakSchedulerMesgQueue;
OSMesgQueue gRumbleThreadVIMesgQueue;
#endif
OSMesg gDmaMesgBuf[1];
OSMesg gPIMesgBuf[32];
OSMesg gSIEventMesgBuf[1];
OSMesg gIntrMesgBuf[16];
OSMesg gUnknownMesgBuf[16];
#ifdef VERSION_SH
OSMesg gRumblePakSchedulerMesgBuf[1];
OSMesg gRumbleThreadVIMesgBuf[1];

struct RumbleData gRumbleDataQueue[3];
struct StructSH8031D9B0 gCurrRumbleSettings;
#endif

struct VblankHandler *gVblankHandler1 = NULL;
struct VblankHandler *gVblankHandler2 = NULL;
struct SPTask *gActiveSPTask = NULL;
struct SPTask *sCurrentAudioSPTask = NULL;
struct SPTask *sCurrentDisplaySPTask = NULL;
struct SPTask *sNextAudioSPTask = NULL;
struct SPTask *sNextDisplaySPTask = NULL;
s8 sAudioEnabled = 1;
u32 sNumVblanks = 0;
s8 gResetTimer = 0;
s8 D_8032C648 = 0;
s8 gDebugLevelSelect = 0;
s8 D_8032C650 = 0;

s8 gShowDebugText = FALSE;

// unused
void unknown_main_func(void) {
    // uninitialized
    OSTime time;
    u32 b;

    osSetTime(time);
    osMapTLB(0, b, NULL, 0, 0, 0);
    osUnmapTLBAll();

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    sprintf(NULL, NULL);
#pragma GCC diagnostic pop
}

void stub_main_1(void) {
}

void stub_main_2(void) {
}

void stub_main_3(void) {
}

void setup_mesg_queues(void) {
    osCreateMesgQueue(&gDmaMesgQueue, gDmaMesgBuf, ARRAY_COUNT(gDmaMesgBuf));
    osCreateMesgQueue(&gSIEventMesgQueue, gSIEventMesgBuf, ARRAY_COUNT(gSIEventMesgBuf));
    osSetEventMesg(OS_EVENT_SI, &gSIEventMesgQueue, NULL);

    osCreateMesgQueue(&gSPTaskMesgQueue, gUnknownMesgBuf, ARRAY_COUNT(gUnknownMesgBuf));
    osCreateMesgQueue(&gIntrMesgQueue, gIntrMesgBuf, ARRAY_COUNT(gIntrMesgBuf));
    osViSetEvent(&gIntrMesgQueue, (OSMesg) MESG_VI_VBLANK, 1);

    osSetEventMesg(OS_EVENT_SP, &gIntrMesgQueue, (OSMesg) MESG_SP_COMPLETE);
    osSetEventMesg(OS_EVENT_DP, &gIntrMesgQueue, (OSMesg) MESG_DP_COMPLETE);
    osSetEventMesg(OS_EVENT_PRENMI, &gIntrMesgQueue, (OSMesg) MESG_NMI_REQUEST);
}

void create_thread(OSThread *thread, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {
    thread->next = NULL;
    thread->queue = NULL;
    osCreateThread(thread, id, entry, arg, sp, pri);
}

#ifdef VERSION_SH
extern void func_sh_802F69CC(void);
#endif

void handle_nmi_request(void) {
    gResetTimer = 1;
    D_8032C648 = 0;
}

void receive_new_tasks(void) {
    struct SPTask *spTask;

    while (osRecvMesg(&gSPTaskMesgQueue, (OSMesg *) &spTask, OS_MESG_NOBLOCK) != -1) {
        spTask->state = SPTASK_STATE_NOT_STARTED;
        switch (spTask->task.t.type) {
            case 2:
                sNextAudioSPTask = spTask;
                break;
            case 1:
                sNextDisplaySPTask = spTask;
                break;
        }
    }

    if (sCurrentAudioSPTask == NULL && sNextAudioSPTask != NULL) {
        sCurrentAudioSPTask = sNextAudioSPTask;
        sNextAudioSPTask = NULL;
    }

    if (sCurrentDisplaySPTask == NULL && sNextDisplaySPTask != NULL) {
        sCurrentDisplaySPTask = sNextDisplaySPTask;
        sNextDisplaySPTask = NULL;
    }
}

void start_sptask(s32 taskType) {
    UNUSED s32 pad; // needed to pad the stack

    if (taskType == M_AUDTASK) {
        gActiveSPTask = sCurrentAudioSPTask;
    } else {
        gActiveSPTask = sCurrentDisplaySPTask;
    }

    if (gActiveSPTask->task.t.ucode_boot_size == 0) {
        osSendMesg(&gIntrMesgQueue, (OSMesg) MESG_SP_COMPLETE, OS_MESG_NOBLOCK);
    } else {
        osSpTaskLoad(&gActiveSPTask->task);
        osSpTaskStartGo(&gActiveSPTask->task);
    }

    gActiveSPTask->state = SPTASK_STATE_RUNNING;
}

void interrupt_gfx_sptask(void) {
    if (gActiveSPTask->task.t.type == M_GFXTASK) {
        gActiveSPTask->state = SPTASK_STATE_INTERRUPTED;
        osSpTaskYield();
    }
}

void start_gfx_sptask(void) {
    if (gActiveSPTask == NULL && sCurrentDisplaySPTask != NULL
        && sCurrentDisplaySPTask->state == SPTASK_STATE_NOT_STARTED) {
        start_sptask(M_GFXTASK);
    }
}

void pretend_audio_sptask_done(void) {
    gActiveSPTask = sCurrentAudioSPTask;
    gActiveSPTask->state = SPTASK_STATE_RUNNING;
    osSendMesg(&gIntrMesgQueue, (OSMesg) MESG_SP_COMPLETE, OS_MESG_NOBLOCK);
}

void handle_vblank(void) {
    UNUSED s32 pad; // needed to pad the stack

    stub_main_3();
    sNumVblanks++;
#ifdef VERSION_SH
    if (gResetTimer > 0 && gResetTimer < 100) {
        gResetTimer++;
    }
#else
    if (gResetTimer > 0) {
        gResetTimer++;
    }
#endif

    receive_new_tasks();

    // First try to kick off an audio task. If the gfx task is currently
    // running, we need to asynchronously interrupt it -- handle_sp_complete
    // will pick up on what we're doing and start the audio task for us.
    // If there is already an audio task running, there is nothing to do.
    // If there is no audio task available, try a gfx task instead.
    if (sCurrentAudioSPTask != NULL) {
        if (gActiveSPTask != NULL) {
            interrupt_gfx_sptask();
        } else {
            if (sAudioEnabled != 0) {
                start_sptask(M_AUDTASK);
            } else {
                pretend_audio_sptask_done();
            }
        }
    } else {
        if (gActiveSPTask == NULL && sCurrentDisplaySPTask != NULL
            && sCurrentDisplaySPTask->state != SPTASK_STATE_FINISHED) {
            start_sptask(M_GFXTASK);
        }
    }
#ifdef VERSION_SH
    rumble_thread_update_vi();
#endif

    // Notify the game loop about the vblank.
    if (gVblankHandler1 != NULL) {
        osSendMesg(gVblankHandler1->queue, gVblankHandler1->msg, OS_MESG_NOBLOCK);
    }
    if (gVblankHandler2 != NULL) {
        osSendMesg(gVblankHandler2->queue, gVblankHandler2->msg, OS_MESG_NOBLOCK);
    }
}

void handle_sp_complete(void) {
    struct SPTask *curSPTask = gActiveSPTask;

    gActiveSPTask = NULL;

    if (curSPTask->state == SPTASK_STATE_INTERRUPTED) {
        // handle_vblank tried to start an audio task while there was already a
        // gfx task running, so it had to interrupt the gfx task. That interruption
        // just finished.
        if (osSpTaskYielded(&curSPTask->task) == 0) {
            // The gfx task completed before we had time to interrupt it.
            // Mark it finished, just like below.
            curSPTask->state = SPTASK_STATE_FINISHED;
        }

        // Start the audio task, as expected by handle_vblank.
        if (sAudioEnabled != 0) {
            start_sptask(M_AUDTASK);
        } else {
            pretend_audio_sptask_done();
        }
    } else {
        curSPTask->state = SPTASK_STATE_FINISHED;
        if (curSPTask->task.t.type == M_AUDTASK) {
            // After audio tasks come gfx tasks.
            if (sCurrentDisplaySPTask != NULL
                && sCurrentDisplaySPTask->state != SPTASK_STATE_FINISHED) {
                if (sCurrentDisplaySPTask->state != SPTASK_STATE_INTERRUPTED) {
                }
                start_sptask(M_GFXTASK);
            }
            sCurrentAudioSPTask = NULL;
            if (curSPTask->msgqueue != NULL) {
                osSendMesg(curSPTask->msgqueue, curSPTask->msg, OS_MESG_NOBLOCK);
            }
        } else {
            // The SP process is done, but there is still a Display Processor notification
            // that needs to arrive before we can consider the task completely finished and
            // null out sCurrentDisplaySPTask. That happens in handle_dp_complete.
        }
    }
}

void handle_dp_complete(void) {
    // Gfx SP task is completely done.
    if (sCurrentDisplaySPTask->msgqueue != NULL) {
        osSendMesg(sCurrentDisplaySPTask->msgqueue, sCurrentDisplaySPTask->msg, OS_MESG_NOBLOCK);
    }
    sCurrentDisplaySPTask->state = SPTASK_STATE_FINISHED_DP;
    sCurrentDisplaySPTask = NULL;
}

void dma_read(u8 *dest, u8 *srcStart, u8 *srcEnd) {
    u32 size = ((srcEnd - srcStart) + 0xF) & ~0xF;

    osInvalDCache(dest, size);
    while (size != 0) {
        u32 copySize = (size >= 0x1000) ? 0x1000 : size;

        osPiStartDma(&gDmaIoMesg, OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t) srcStart, dest, copySize,
                     &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, &D_80339BEC, OS_MESG_BLOCK);

        dest += copySize;
        srcStart += copySize;
        size -= copySize;
    }
}

extern u8 _customSegmentRomStart[];
extern u8 _customSegmentRomEnd[];

void load_custom_code_segment(void) {
    void *startAddr = (void *) SEG_CUSTOM;
    u32 totalSize = _customSegmentRomEnd - _customSegmentRomStart;

    bzero(startAddr, totalSize);
    osWritebackDCacheAll();
    dma_read(startAddr, _customSegmentRomStart, _customSegmentRomEnd);
    osInvalICache(startAddr, totalSize);
    osInvalDCache(startAddr, totalSize);
}

void thread3_main(UNUSED void *arg) {
    setup_mesg_queues();
    load_custom_code_segment();

    create_thread(&gGameLoopThread, 5, thread5_game_loop, NULL, gThread5Stack + 0x2000, 10);
    osStartThread(&gGameLoopThread);

    while (1) {
        OSMesg msg;

        osRecvMesg(&gIntrMesgQueue, &msg, OS_MESG_BLOCK);
        switch ((uintptr_t) msg) {
            case MESG_VI_VBLANK:
                handle_vblank();
                break;
            case MESG_SP_COMPLETE:
                handle_sp_complete();
                break;
            case MESG_DP_COMPLETE:
                handle_dp_complete();
                break;
            case MESG_START_GFX_SPTASK:
                start_gfx_sptask();
                break;
            case MESG_NMI_REQUEST:
                handle_nmi_request();
                break;
        }
        stub_main_2();
    }
}

void set_vblank_handler(s32 index, struct VblankHandler *handler, OSMesgQueue *queue, OSMesg *msg) {
    handler->queue = queue;
    handler->msg = msg;

    switch (index) {
        case 1:
            gVblankHandler1 = handler;
            break;
        case 2:
            gVblankHandler2 = handler;
            break;
    }
}

void send_sp_task_message(OSMesg *msg) {
    osWritebackDCacheAll();
    osSendMesg(&gSPTaskMesgQueue, msg, OS_MESG_NOBLOCK);
}

void dispatch_audio_sptask(struct SPTask *spTask) {
    if (sAudioEnabled != 0 && spTask != NULL) {
        osWritebackDCacheAll();
        osSendMesg(&gSPTaskMesgQueue, spTask, OS_MESG_NOBLOCK);
    }
}

void send_display_list(struct SPTask *spTask) {
    if (spTask != NULL) {
        osWritebackDCacheAll();
        spTask->state = SPTASK_STATE_NOT_STARTED;
        if (sCurrentDisplaySPTask == NULL) {
            sCurrentDisplaySPTask = spTask;
            sNextDisplaySPTask = NULL;
            osSendMesg(&gIntrMesgQueue, (OSMesg) MESG_START_GFX_SPTASK, OS_MESG_NOBLOCK);
        } else {
            sNextDisplaySPTask = spTask;
        }
    }
}

void turn_on_audio(void) {
    sAudioEnabled = 1;
}

void turn_off_audio(void) {
    sAudioEnabled = 0;
    while (sCurrentAudioSPTask != NULL) {
        ;
    }
}

/**
 * Initialize hardware, start main thread, then idle.
 */
void thread1_idle(UNUSED void *arg) {
#if defined(VERSION_US) || defined(VERSION_SH)
    s32 sp24 = osTvType;
#endif

    osCreateViManager(OS_PRIORITY_VIMGR);
#if defined(VERSION_US) || defined(VERSION_SH)
    if (sp24 == TV_TYPE_NTSC) {
        osViSetMode(&osViModeTable[OS_VI_NTSC_LAN1]);
    } else {
        osViSetMode(&osViModeTable[OS_VI_PAL_LAN1]);
    }
#elif defined(VERSION_JP)
    osViSetMode(&osViModeTable[OS_VI_NTSC_LAN1]);
#else // VERSION_EU
    osViSetMode(&osViModeTable[OS_VI_PAL_LAN1]);
#endif
    osViBlack(TRUE);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPIMesgQueue, gPIMesgBuf, ARRAY_COUNT(gPIMesgBuf));
    create_thread(&gMainThread, 3, thread3_main, NULL, gThread3Stack + 0x2000, 100);
    if (D_8032C650 == 0) {
        osStartThread(&gMainThread);
    }
    osSetThreadPri(NULL, 0);

    // halt
    while (1) {
        ;
    }
}

void main_func(void) {
    UNUSED u8 pad[64]; // needed to pad the stack

    osInitialize();
    stub_main_1();
    create_thread(&gIdleThread, 1, thread1_idle, NULL, gIdleThreadStack + 0x800, 100);
    osStartThread(&gIdleThread);
}
