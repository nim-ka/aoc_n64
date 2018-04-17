#include <ultra64.h>

#include "sm64.h"

void myRdpInit(void)
{
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001701;
        g->words.w1 = 0x800000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xED000000;
        g->words.w1 = 0x005003C0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xFCFFFFFF;
        g->words.w1 = 0xFFFE793C;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001001;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA000E02;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001102;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001301;
        g->words.w1 = 0x80000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA000C02;
        g->words.w1 = 8192;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA000903;
        g->words.w1 = 3072;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA000801;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB9000002;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB900031D;
        g->words.w1 = 0x0F0A4000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA000602;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0x300000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }
}

void myRspInit(void)
{
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB6000000;
        g->words.w1 = 0x001F3204;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB7000000;
        g->words.w1 = 0x00022204;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBC000002;
        g->words.w1 = 0x80000040;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBB000000;
        g->words.w1 = 0;
    }
}

void ClearZBuffer(void)
{
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB9000201;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xFE000000;
        g->words.w1 = D_80339CEC;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xFF10013F;
        g->words.w1 = D_80339CEC;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF7000000;
        g->words.w1 = 0xFFFCFFFC;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF64FC39C;
        g->words.w1 = 32;
    }
}

void DisplayFrameBuffer(void)
{
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xFF10013F;
        g->words.w1 = D_80339CE0[D_8032C69C];
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xED000020;
        g->words.w1 = 0x005003A0;
    }
}

void ClearFrameBuffer(int a)
{
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB900031D;
        g->words.w1 = 0x0F0A4000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0x00300000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF7000000;
        g->words.w1 = a;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF64FC39C;
        g->words.w1 = 32;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0;
    }
}

void DisplayInit(s16 *a, int b)
{
    s16 sp26 = (a[4] - a[0]) / 4 + 1;
    s16 sp24 = (a[5] - a[1]) / 4 + 1;
    s16 sp22 = (a[4] + a[0]) / 4 - 2;
    s16 sp20 = (a[5] + a[1]) / 4 - 2;

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB900031D;
        g->words.w1 = 0x0F0A4000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0x300000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF7000000;
        g->words.w1 = b;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF6000000 | ((sp22 & 0x3FF) << 14) | ((sp20 & 0x3FF) << 2);
        g->words.w1 = ((sp26 & 0x3FF) << 14) | ((sp24 & 0x3FF) << 2);
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0;
    }
}

void func_8024781C(void)
{
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xED000000;
        g->words.w1 = 0x005003C0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB900031D;
        g->words.w1 = 0x0F0A4000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xBA001402;
        g->words.w1 = 0x300000;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF7000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF64FC01C;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xF64FC3BC;
        g->words.w1 = 928;
    }
}

void func_8024798C(s16 *a)
{
    s16 spE = (a[4] - a[0]) / 4 + 1;
    s16 spC = (a[5] - a[1]) / 4 + 1;
    s16 spA = (a[4] + a[0]) / 4 - 1;
    s16 sp8 = (a[5] + a[1]) / 4 - 1;

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xED000000 | (((int)(spE * 4.0f) & 0xFFF) << 12) | ((int)(spC * 4.0f) & 0xFFF);
        g->words.w1 = (((int)(spA * 4.0f) & 0xFFF) << 12) | ((int)(sp8 * 4.0f) & 0xFFF);
    }
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
    if (D_8032C654 != 0)
        func_8027EEB0();

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE9000000;
        g->words.w1 = 0;
    }

    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB8000000;
        g->words.w1 = 0;
    }

    CreateTaskStructure();
}

void func_80247D84(void)
{
    int sp24;
    int sp20;
    int sp1C;
    u64 *sp18;

    if (gResetTimer != 0 && D_8032C648 < 15)
    {
        if (D_8032C698 == 0)
            sp1C = 2;
        else
            sp1C = D_8032C698 - 1;

        sp18 = (u64 *)(D_80339CE0[sp1C] | 0x80000000);
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
    SetSegmentBase(1, D_80339D04);
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
    SetSegmentBase(1, D_80339D04);
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
    osViSwapBuffer((void *)(D_80339CE0[D_8032C698] | 0x80000000));
    func_8027DE30(4);
    osRecvMesg(&D_80339CA0, &D_80339BEC, 1);
    if (++D_8032C698 == 3)
        D_8032C698 = 0;
    if (++D_8032C69C == 3)
        D_8032C69C = 0;
    D_8032C694++;
}
