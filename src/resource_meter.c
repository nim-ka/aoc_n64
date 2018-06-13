#include <ultra64.h>

#include "sm64.h"
#include "libultra.h"
#include "resource_meter.h"
#include "game.h"

struct Struct8033B020 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 fill4[4];
    /* 0x08 */ OSTime unk8[8];
    /* 0x48 */ OSTime unk72[8];
    /* 0x88 */ OSTime unk136[8];
};

struct Struct8033B020 D_8033B020[2];

void func_8027DE30(int arg0)
{
    D_8033B020[D_8032CFB4].unk8[arg0] = osGetTime();

    if (arg0 == 4) {
        D_8032CFB4 ^= 1;
        D_8033B020[D_8032CFB4].unk0 = 0;
    }
}

void func_8027DEE0(void)
{
    struct Struct8033B020* pUnk = &D_8033B020[D_8032CFB4];

    if (pUnk->unk0 < 8) {
        pUnk->unk72[pUnk->unk0] = osGetTime();
        pUnk->unk0++;
    }
}

void func_8027DF70(int arg0)
{
    if (arg0 == 0) {
        D_8032CFB8 ^= 1;
        D_8033B020[D_8032CFB8].unk2 = 0;
    }

    D_8033B020[D_8032CFB8].unk8[arg0 + 4 + 1] = osGetTime();
}

void func_8027E01C(void)
{
    struct Struct8033B020* pUnk = &D_8033B020[D_8032CFB8];

    if (pUnk->unk2 < 8) {
        pUnk->unk136[pUnk->unk2] = osGetTime();
        pUnk->unk2++;
    }
}

void draw_meter_bar(s64 clock_base, s64 clock_start, s64 clock_end, s16 pos_y, u16 color)
{
    s64 unk0, unk1;
    s32 rect_x1, rect_x2;

    if ((unk0 = clock_start - clock_base) < 0) {
        unk0 = 0;
    }
    if ((unk1 = clock_end - clock_base) < 0) {
        unk1 = 0;
    }

    rect_x1 = ((((unk0 * 1000000) / osClockRate * 3) / 1000) + 30);
    rect_x2 = ((((unk1 * 1000000) / osClockRate * 3) / 1000) + 30);

    //! I believe this is supposed to cap rect_x1 to 320, but the code has a typo...
    if (rect_x1 >= 320) {
        clock_start = 319;
    }
    if (rect_x2 >= 320) {
        clock_end = 319;
    }

    if (rect_x1 < rect_x2) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, color << 16 | color);
        gDPFillRectangle(gDisplayListHead++, rect_x1, pos_y, rect_x2, pos_y + 2);
    }
}

void draw_reference_meter_bars(void)
{
    // Draws the reference "max" bars underneath the real thing.

    // Blue
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, GPACK_RGBA5551(40, 80, 255, 1) << 16 | GPACK_RGBA5551(40, 80, 255, 1));
    gDPFillRectangle(gDisplayListHead++, 30, 220, 79, 222);

    // Yellow
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, GPACK_RGBA5551(255, 255, 40, 1) << 16 | GPACK_RGBA5551(255, 255, 40, 1));
    gDPFillRectangle(gDisplayListHead++, 79, 220, 128, 222);

    // Orange
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, GPACK_RGBA5551(255, 120, 40, 1) << 16 | GPACK_RGBA5551(255, 120, 40, 1));
    gDPFillRectangle(gDisplayListHead++, 128, 220, 177, 222);

    // Red
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, GPACK_RGBA5551(255, 40, 40, 1) << 16 | GPACK_RGBA5551(255, 40, 40, 1));
    gDPFillRectangle(gDisplayListHead++, 177, 220, 226, 222);
}

void func_8027E61C(void)
{
    s32 i;
    struct Struct8033B020 *pUnk;
    u64 unk0;

    pUnk = &D_8033B020[D_8032CFB4 ^ 1];
    unk0 = pUnk->unk72[0] - (16433 * osClockRate / 1000000);

    draw_meter_bar(unk0, pUnk->unk8[0], pUnk->unk8[1], 212, GPACK_RGBA5551(255, 255, 40, 1));
    draw_meter_bar(unk0, pUnk->unk8[1], pUnk->unk8[2], 212, GPACK_RGBA5551(255, 120, 40, 1));
    draw_meter_bar(unk0, pUnk->unk8[2], pUnk->unk8[3], 212, GPACK_RGBA5551(40, 192, 230, 1));

    pUnk->unk0 &= 0xFFFE;
    for (i = 0; i < pUnk->unk0; i += 2) {
        draw_meter_bar(unk0, pUnk->unk72[i], pUnk->unk72[i+1], 212, GPACK_RGBA5551(255, 40, 40, 1));
    }

    draw_meter_bar(unk0, pUnk->unk8[5], pUnk->unk8[6], 216, GPACK_RGBA5551(255, 255, 40, 1));
    draw_meter_bar(unk0, pUnk->unk8[6], pUnk->unk8[7], 216, GPACK_RGBA5551(255, 120, 40, 1));

    pUnk->unk2 &= 0xFFFE;
    for (i = 0; i < pUnk->unk2; i += 2) {
        draw_meter_bar(unk0, pUnk->unk136[i], pUnk->unk136[i+1], 216, GPACK_RGBA5551(255, 40, 40, 1));
    }

    draw_reference_meter_bars();
}

void func_8027E8FC(void)
{
    s32 i;
    struct Struct8033B020* pUnk;

    u64 unk0;
    u64 unk1, unk2, unk3, unk4, unk5, unk6;
    u64 unk7;
    u64* pUnk2;
    u64* pUnk3;
    u64* pUnk4;
    u64* pUnk5;
    u64* pUnk6;
    u64* pUnk7;

    pUnk = &D_8033B020[D_8032CFB4 ^ 1];
    unk0 = pUnk->unk8[0] <= pUnk->unk72[0] ? pUnk->unk8[0] : pUnk->unk72[0];
    unk1 = pUnk->unk8[1] - unk0;
    unk2 = pUnk->unk8[2] - pUnk->unk8[1];
    unk3 = 0;
    unk4 = pUnk->unk8[6] - pUnk->unk8[5];
    unk5 = pUnk->unk8[7] - pUnk->unk8[5];
    unk6 = 0;

    pUnk->unk0 &= 0xFFFE;
    for (i = 0; i < pUnk->unk0; i += 2) {
        unk7 = pUnk->unk72[i + 1] - pUnk->unk72[i];
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"
        *pUnk2 = (*(pUnk2 = &unk3)) + unk7;
        if (pUnk->unk72[i] < pUnk->unk8[1]) {
            *pUnk3 = (*(pUnk3 = &unk1)) - unk7;
        } else if (pUnk->unk72[i] < pUnk->unk8[2]) {
            *pUnk4 = (*(pUnk4 = &unk2)) - unk7;
        }
#pragma GCC diagnostic pop
    }

    pUnk->unk0 &= 0xFFFE;

    for (i = 0; i < pUnk->unk0; i += 2) {
        (pUnk5 = &unk6), *pUnk5 = *pUnk5 + (pUnk->unk136[i + 1] - pUnk->unk136[i]);
    }

    // Draw top meters.
    unk0 = 0;
    draw_meter_bar(0, unk0, unk0 + unk3, 212, GPACK_RGBA5551(255, 40, 40, 1));
    pUnk6 = &unk0, *pUnk6 = *pUnk6 + unk3;
    draw_meter_bar(0, unk0, unk0 + unk1, 212, GPACK_RGBA5551(255, 255, 40, 1));
    pUnk7 = &unk0, *pUnk7 = *pUnk7 + unk1;
    draw_meter_bar(0, unk0, unk0 + unk2, 212, GPACK_RGBA5551(255, 120, 40, 1));

    // Draw bottom meters.
    draw_meter_bar(0, 0, unk5, 216, GPACK_RGBA5551(255, 120, 40, 1));
    draw_meter_bar(0, 0, unk4, 216, GPACK_RGBA5551(255, 255, 40, 1));
    draw_meter_bar(0, 0, unk6, 216, GPACK_RGBA5551(255, 40, 40, 1));
    draw_reference_meter_bars();
}

void draw_resource_meter(void)
{
    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        D_8032CFB0 ^= 1;
    }

    if (D_8032CFB0 == 0) {
        func_8027E8FC();
    } else {
        func_8027E61C();
    }
}
