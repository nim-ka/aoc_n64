#include <ultra64.h>

#include "sm64.h"

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
s8 gDebugResourceMeter = 0;
s8 gPrintDebugInfo = 0;
u16 D_8032C65C[] = {0x800, 0x800, 0x400, 0x400, 0x200, 0x100, 0x200, 0x100};
u16 D_8032C66C[] = {0x400, 0x400, 0x800, 0x800, 0x200, 0x100, 0x200, 0x100};
s16 D_8032C67C = 0;
s16 D_8032C680 = 0;

void Unknown80246050(void)
{
    if (gPlayer2Controller->buttonPressed != 0)
    {
        if (D_8032C65C[D_8032C67C++] == gPlayer2Controller->buttonPressed)
        {
            if (D_8032C67C == 8)
                D_8032C67C = 0, gDebugResourceMeter ^= 1;
        }
        else
        {
            D_8032C67C = 0;
        }

        if (D_8032C66C[D_8032C680++] == gPlayer2Controller->buttonPressed)
        {
            if (D_8032C680 == 8)
                D_8032C680 = 0, gPrintDebugInfo ^= 1;
        }
        else
        {
            D_8032C680 = 0;
        }
    }
}

void Unknown80246170(void)
{
    // uninitialized
    OSTime time;
    u32 b;

    osSetTime(time);
    osMapTLB(0, b, NULL, 0, 0, 0);
    osMapTLBRdb();
    proutSprintf(0, 0);
}

void Dummy802461CC(void)
{
}

void Dummy802461DC(void)
{
}

void Dummy802461EC(void)
{
}

void SetupMessageQueues(void)
{
    osCreateMesgQueue(&gDmaMesgQueue, &D_80339AC8, 1);
    osCreateMesgQueue(&D_80339C08, &D_80339B50, 1);
    osSetEventMesg(5, &D_80339C08, NULL);

    osCreateMesgQueue(&D_80339AB0, &D_80339B98, 16);
    osCreateMesgQueue(&D_80339A98, &D_80339B58, 16);
    osViSetEvent(&D_80339A98, (OSMesg)102, 1);

    osSetEventMesg(4, &D_80339A98, (OSMesg)100);
    osSetEventMesg(9, &D_80339A98, (OSMesg)101);
    osSetEventMesg(14, &D_80339A98, (OSMesg)104);
}

void AllocPool(void)
{
    void *var1 = (void *)0x8005C000;
    void *var2 = (void *)0x801C1000;

    InitMemPool(var1, var2);
    D_8033A124 = func_802785E8(16384, 0);
}

void CreateThread(OSThread *thread, OSId id, void (*entry)(void *), void *arg,
    void *sp, OSPri pri)
{
    thread->next = NULL;
    thread->queue = NULL;
    osCreateThread(thread, id, entry, arg, sp, pri);
}

void func_8024639C(void)
{
    gResetTimer = 1;
    D_8032C648 = 0;
    func_80320890();
    func_803208C0(2, 890);
    func_802491FC(90);
}

void func_802463EC(void)
{
    OSMesg msg;

    while (osRecvMesg(&D_80339AB0, &msg, 0) != -1)
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

void func_8024651C(int a)
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

void func_8024659C(void)
{
    if (D_8032C628->task.t.type == 1)
    {
        D_8032C628->unk48 = 2;
        osSpTaskYield();
    }
}

void KickTask(void)
{
    if (D_8032C628 == NULL && D_8032C630 != NULL && D_8032C630->unk48 == 0)
    {
        func_8027DF70(0);
        func_8024651C(1);
    }
}

void SendSPTaskDone(void)
{
    D_8032C628 = D_8032C62C;
    D_8032C628->unk48 = 1;
    osSendMesg(&D_80339A98, (OSMesg *)100, 0);
}

void func_8024669C(void)
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

void func_802467FC(void)
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
        if (sp1C->task.t.type == 2)
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

void func_8024694C(void)
{
    if (D_8032C630->msgqueue != NULL)
        osSendMesg(D_8032C630->msgqueue, D_8032C630->msg, 0);
    func_8027DF70(2);
    D_8032C630->unk48 = 4;
    D_8032C630 = NULL;
}

void Thread3_Main(UNUSED void *arg)
{
    SetupMessageQueues();
    AllocPool();
    CopyScriptInterpreter();

    CreateThread(&D_803398D0, 4, Thread4, NULL, D_80203200 + 0x2000, 20);
    osStartThread(&D_803398D0);

    CreateThread(&D_80339720, 5, Thread5_GameLoop, NULL, D_80205200 + 0x2000, 10);
    osStartThread(&D_80339720);

    while (1)
    {
        OSMesg msg;

        osRecvMesg(&D_80339A98, &msg, 1);
        switch ((u32)msg)
        {
        case 102:
            func_8024669C();
            break;
        case 100:
            func_802467FC();
            break;
        case 101:
            func_8024694C();
            break;
        case 103:
            KickTask();
            break;
        case 104:
            func_8024639C();
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

void SendMessage(OSMesg *msg)
{
    osWritebackDCacheAll();
    osSendMesg(&D_80339AB0, msg, 0);
}

void func_80246BB4(OSMesg *msg)
{
    if (D_8032C63C != 0 && msg != NULL)
    {
        osWritebackDCacheAll();
        osSendMesg(&D_80339AB0, msg, 0);
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
            osSendMesg(&D_80339A98, (OSMesg)103, 0);
        }
        else
        {
            D_8032C638 = (OSMesg)a;
        }
    }
}

void Unknown80246C9C(void)
{
    D_8032C63C = 1;
}

void Unknown80246CB8(void)
{
    D_8032C63C = 0;
    while (D_8032C62C != NULL)
        ;
}

void Thread1_Idle(UNUSED void *arg)
{
    osCreateViManager(254);
    osViSetMode(&D_80333F00.viMode);
    osViBlack(TRUE);
    osViSetSpecialFeatures(0x40);
    osViSetSpecialFeatures(2);
    osCreatePiManager(150, &D_80339A80, &D_80339AD0, 32);
    CreateThread(&D_80339570, 3, Thread3_Main, NULL, D_80201200 + 0x2000, 100);
    if (D_8032C650 == 0)
        osStartThread(&D_80339570);
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
    CreateThread(&D_803393C0, 1, Thread1_Idle, NULL, D_80200A00 + 0x800, 100);
    osStartThread(&D_803393C0);
}
