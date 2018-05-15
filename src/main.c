#include <ultra64.h>

#include "sm64.h"
#include "audio_interface_2.h"
#include "libultra.h"
#include "main.h"
#include "memory.h"
#include "sound_init.h"
#include "resource_meter.h"
#include "game.h"

// Message IDs
#define MESG_SP_COMPLETE 100
#define MESG_DP_COMPLETE 101
#define MESG_VI_VBLANK   102
#define MESG_UNKNOWN_103 103
#define MESG_NMI_REQUEST 104

OSThread D_80339210;  // unused?
OSThread gIdleThread;
OSThread gMainThread;
OSThread gGameLoopThread;
OSThread gSoundThread;
OSMesgQueue gPIMesgQueue;
OSMesgQueue gIntrMesgQueue;
OSMesgQueue gUnknownMesgQueue;
OSMesg gDmaMesgBuf[1];
OSMesg gPIMesgBuf[32];
OSMesg gSIEventMesgBuf[1];
OSMesg gIntrMesgBuf[16];
OSMesg gUnknownMesgBuf[16];
OSIoMesg gDmaIoMesg;
// FIXME: This overlaps with gDmaIoMesg.
//OSMesg D_80339BEC;
OSMesgQueue gDmaMesgQueue;
OSMesgQueue gSIEventMesgQueue;

struct Struct8032C620 *D_8032C620 = NULL;
struct Struct8032C620 *D_8032C624 = NULL;
struct Struct8032C630 *D_8032C628 = NULL;
struct Struct8032C630 *D_8032C62C = NULL;
struct Struct8032C630 *D_8032C630 = NULL;
OSMesg D_8032C634 = NULL;
OSMesg D_8032C638 = NULL;
s8 D_8032C63C = 1;
u32 D_8032C640 = 0;
s8 gResetTimer = 0;
s8 D_8032C648 = 0;
s8 gDebugLevelSelect = 0;
s8 D_8032C650 = 0;

s8 gShowResourceMeter = FALSE;
s8 gShowDebugText = FALSE;
static u16 sResourceMeterKeySequence[] = {U_JPAD, U_JPAD, D_JPAD, D_JPAD, L_JPAD, R_JPAD, L_JPAD, R_JPAD};
static u16 sDebugTextKeySequence[]     = {D_JPAD, D_JPAD, U_JPAD, U_JPAD, L_JPAD, R_JPAD, L_JPAD, R_JPAD};
static s16 sResourceMeterKey = 0;
static s16 sDebugTextKey = 0;

// unused
void handle_debug_key_sequences(void)
{
    if (gPlayer2Controller->buttonPressed != 0)
    {
        if (sResourceMeterKeySequence[sResourceMeterKey++] == gPlayer2Controller->buttonPressed)
        {
            if (sResourceMeterKey == ARRAY_COUNT(sResourceMeterKeySequence))
                sResourceMeterKey = 0, gShowResourceMeter ^= 1;
        }
        else
        {
            sResourceMeterKey = 0;
        }

        if (sDebugTextKeySequence[sDebugTextKey++] == gPlayer2Controller->buttonPressed)
        {
            if (sDebugTextKey == ARRAY_COUNT(sDebugTextKeySequence))
                sDebugTextKey = 0, gShowDebugText ^= 1;
        }
        else
        {
            sDebugTextKey = 0;
        }
    }
}

static void Unknown80246170(void)
{
    // uninitialized
    OSTime time;
    u32 b;

    osSetTime(time);
    osMapTLB(0, b, NULL, 0, 0, 0);
    osMapTLBRdb();
    proutSprintf(0, 0);
}

static void Dummy802461CC(void)
{
}

static void Dummy802461DC(void)
{
}

static void Dummy802461EC(void)
{
}

static void setup_mesg_queues(void)
{
    osCreateMesgQueue(&gDmaMesgQueue, gDmaMesgBuf, ARRAY_COUNT(gDmaMesgBuf));
    osCreateMesgQueue(&gSIEventMesgQueue, gSIEventMesgBuf, ARRAY_COUNT(gSIEventMesgBuf));
    osSetEventMesg(OS_EVENT_SI, &gSIEventMesgQueue, NULL);

    osCreateMesgQueue(&gUnknownMesgQueue, gUnknownMesgBuf, ARRAY_COUNT(gUnknownMesgBuf));
    osCreateMesgQueue(&gIntrMesgQueue, gIntrMesgBuf, ARRAY_COUNT(gIntrMesgBuf));
    osViSetEvent(&gIntrMesgQueue, (OSMesg)MESG_VI_VBLANK, 1);

    osSetEventMesg(OS_EVENT_SP, &gIntrMesgQueue, (OSMesg)MESG_SP_COMPLETE);
    osSetEventMesg(OS_EVENT_DP, &gIntrMesgQueue, (OSMesg)MESG_DP_COMPLETE);
    osSetEventMesg(OS_EVENT_PRENMI, &gIntrMesgQueue, (OSMesg)MESG_NMI_REQUEST);
}

// wtf? Nintendo defined these via the assembler and NOT the linker
// script. Most likely it is via an include and not a symbol in the
// linker script. Using the linker symbol(s) causes the asm to not
// match due to lw over an or to load the addresses.
#define SEG_POOL_START 0x8005C000
#define SEG_POOL_END   0x801C1000

extern char __segPoolStart[];
extern char __segPoolEnd[];

// if one were sane, you'd use the linker symbols for these defs, not
// header defines. But Nintendo was not sane when writing this.
void AllocPool(void)
{
    u32 start = SEG_POOL_START;
    u32 end   = SEG_POOL_END;

    InitMemPool(start, end);
    D_8033A124 = func_802785E8(16384, 0);
}

void create_thread(OSThread *thread, OSId id, void (*entry)(void *), void *arg,
    void *sp, OSPri pri)
{
    thread->next = NULL;
    thread->queue = NULL;
    osCreateThread(thread, id, entry, arg, sp, pri);
}

void handle_nmi_request(void)
{
    gResetTimer = 1;
    D_8032C648 = 0;
    func_80320890();
    func_803208C0(2, 890);
    func_802491FC(90);
}

static void func_802463EC(void)
{
    OSMesg msg;

    while (osRecvMesg(&gUnknownMesgQueue, &msg, 0) != -1)
    {
        // FIXME: What type is this? I think it might be OSTask.
        ((u32 *)msg)[18] = 0;
        switch (*(u32 *)msg)
        {
        case 2:
            D_8032C634 = msg;
            break;
        case 1:
            D_8032C638 = msg;
            break;
        }
    }

    if (D_8032C62C == NULL && D_8032C634 != NULL)
    {
        D_8032C62C = D_8032C634;
        D_8032C634 = NULL;
    }

    if (D_8032C630 == NULL && D_8032C638 != NULL)
    {
        D_8032C630 = D_8032C638;
        D_8032C638 = NULL;
    }
}

static void func_8024651C(int a)
{
    UNUSED int pad;  // needed to pad the stack

    if (a == 2)
        D_8032C628 = D_8032C62C;
    else
        D_8032C628 = D_8032C630;

    osSpTaskLoad(&D_8032C628->task);
    osSpTaskStartGo(&D_8032C628->task);
    D_8032C628->unk48 = 1;
}

static void func_8024659C(void)
{
    if (D_8032C628->task.t.type == M_GFXTASK)
    {
        D_8032C628->unk48 = 2;
        osSpTaskYield();
    }
}

static void KickTask(void)
{
    if (D_8032C628 == NULL && D_8032C630 != NULL && D_8032C630->unk48 == 0)
    {
        func_8027DF70(0);
        func_8024651C(1);
    }
}

static void SendSPTaskDone(void)
{
    D_8032C628 = D_8032C62C;
    D_8032C628->unk48 = 1;
    osSendMesg(&gIntrMesgQueue, (OSMesg)MESG_SP_COMPLETE, 0);
}

static void handle_vblank(void)
{
    UNUSED int pad;  // needed to pad the stack

    Dummy802461EC();
    D_8032C640++;
    if (gResetTimer > 0)
        gResetTimer++;
    func_802463EC();
    if (D_8032C62C != NULL)
    {
        if (D_8032C628 != NULL)
        {
            func_8024659C();
        }
        else
        {
            func_8027E01C();
            if (D_8032C63C != 0)
                func_8024651C(2);
            else
                SendSPTaskDone();
        }
    }
    else
    {
        if (D_8032C628 == NULL && D_8032C630 != NULL && D_8032C630->unk48 != 3)
        {
            func_8027DF70(0);
            func_8024651C(1);
        }
    }

    if (D_8032C620 != NULL)
        osSendMesg(D_8032C620->queue, D_8032C620->msg, 0);
    if (D_8032C624 != NULL)
        osSendMesg(D_8032C624->queue, D_8032C624->msg, 0);
}

static void handle_sp_complete(void)
{
    struct Struct8032C630 *sp1C = D_8032C628;

    D_8032C628 = 0;

    if (sp1C->unk48 == 2)
    {
        if (func_80321E40(sp1C) == 0)
        {
            sp1C->unk48 = 3;
            func_8027DF70(1);
        }
        func_8027E01C();
        if (D_8032C63C != 0)
            func_8024651C(2);
        else
            SendSPTaskDone();
    }
    else
    {
        sp1C->unk48 = 3;
        if (sp1C->task.t.type == M_AUDTASK)
        {
            func_8027E01C();
            if (D_8032C630 != NULL && D_8032C630->unk48 != 3)
            {
                if (D_8032C630->unk48 != 2)
                    func_8027DF70(0);
                func_8024651C(1);
            }
            D_8032C62C = NULL;
            if (sp1C->msgqueue != NULL)
                osSendMesg(sp1C->msgqueue, sp1C->msg, 0);
        }
        else
        {
            func_8027DF70(1);
        }
    }
}

static void handle_dp_complete(void)
{
    if (D_8032C630->msgqueue != NULL)
        osSendMesg(D_8032C630->msgqueue, D_8032C630->msg, 0);
    func_8027DF70(2);
    D_8032C630->unk48 = 4;
    D_8032C630 = NULL;
}

static void thread3_main(UNUSED void *arg)
{
    setup_mesg_queues();
    AllocPool();
    CopyScriptInterpreter();

    create_thread(&gSoundThread, 4, thread4_sound, NULL, D_80203200 + 0x2000, 20);
    osStartThread(&gSoundThread);

    create_thread(&gGameLoopThread, 5, thread5_game_loop, NULL, D_80205200 + 0x2000, 10);
    osStartThread(&gGameLoopThread);

    while (1)
    {
        OSMesg msg;

        osRecvMesg(&gIntrMesgQueue, &msg, 1);
        switch ((u32)msg)
        {
        case MESG_VI_VBLANK:
            handle_vblank();
            break;
        case MESG_SP_COMPLETE:
            handle_sp_complete();
            break;
        case MESG_DP_COMPLETE:
            handle_dp_complete();
            break;
        case MESG_UNKNOWN_103:
            KickTask();
            break;
        case MESG_NMI_REQUEST:
            handle_nmi_request();
            break;
        }
        Dummy802461DC();
    }
}

void func_80246B14(int a, struct Struct8032C620 *b, OSMesgQueue *queue, OSMesg *msg)
{
    b->queue = queue;
    b->msg = msg;

    switch (a)
    {
    case 1:
        D_8032C620 = b;
        break;
    case 2:
        D_8032C624 = b;
        break;
    }
}

static void SendMessage(OSMesg *msg)
{
    osWritebackDCacheAll();
    osSendMesg(&gUnknownMesgQueue, msg, 0);
}

void func_80246BB4(OSMesg *msg)
{
    if (D_8032C63C != 0 && msg != NULL)
    {
        osWritebackDCacheAll();
        osSendMesg(&gUnknownMesgQueue, msg, 0);
    }
}

void SendDisplayList(struct Struct8032C630 *a)
{
    if (a != NULL)
    {
        osWritebackDCacheAll();
        a->unk48 = 0;
        if (D_8032C630 == NULL)
        {
            D_8032C630 = a;
            D_8032C638 = NULL;
            osSendMesg(&gIntrMesgQueue, (OSMesg)MESG_UNKNOWN_103, 0);
        }
        else
        {
            D_8032C638 = (OSMesg)a;
        }
    }
}

static void Unknown80246C9C(void)
{
    D_8032C63C = 1;
}

static void Unknown80246CB8(void)
{
    D_8032C63C = 0;
    while (D_8032C62C != NULL)
        ;
}

/**
 * Initialize hardware, start main thread, then idle.
 */
static void thread1_idle(UNUSED void *arg)
{
#if VERSION_US
    int sp24 = D_U_80000300;
#endif

    osCreateViManager(OS_PRIORITY_VIMGR);
#if VERSION_US
    if (sp24 == 1)
        osViSetMode(&D_80333F00.viMode);
    else
        osViSetMode(&D_80333F00.unk500);
#else
    osViSetMode(&D_80333F00.viMode);
#endif
    osViBlack(TRUE);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPIMesgQueue, gPIMesgBuf, ARRAY_COUNT(gPIMesgBuf));
    create_thread(&gMainThread, 3, thread3_main, NULL, D_80201200 + 0x2000, 100);
    if (D_8032C650 == 0)
        osStartThread(&gMainThread);
    osSetThreadPri(NULL, 0);

    // halt
    while (1)
        ;
}

void Main(void)
{
    UNUSED u8 pad[64];  // needed to pad the stack

    osInitialize();
    Dummy802461CC();
    create_thread(&gIdleThread, 1, thread1_idle, NULL, D_80200A00 + 0x800, 100);
    osStartThread(&gIdleThread);
}
