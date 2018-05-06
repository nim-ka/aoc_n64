#include <ultra64.h>

#include "sm64.h"

struct Unknown80177DF4
{
    u32 unk00; // 0x00
    u32 unk04; // 0x04
    u8 unk08; // 0x08
    u8 unk09; // 0x09
    u8 unk0A; // 0x0A
    u8 unk0B; // 0x0B
    u32 unk0C; // 0x0C
};

extern char D_801B540C[];
extern char D_801B5424[];
extern char D_801B5420[];
extern u32 D_801B9B10;
extern char D_801B5438[];
extern char D_801B546C[];
extern char D_801B5468[];
extern char D_801B5454[];
extern char D_801B5450[];
extern char D_801B543C[];
extern u32 D_801B9B18;
extern u32 D_801B9B10;
extern u32* D_801B9B14;
extern u32 D_801B9B18;
extern f32 D_801B5364;
extern f32 D_801B99A8;
extern f32 D_801B99C0;
extern char D_801A8058[];
extern char D_801A8050[];
extern char D_801B5330[];
extern u32 D_801B5338;
extern float D_801B99CC;
extern u32 D_801B9920;
extern u32 D_801B9974;
extern u32* D_801B9A10;
extern u32 D_801B9A18;
extern u32 D_801B5340;
extern u32 D_801B5354;
extern u32 D_801B535C;

void osSyncPrintf(const char* format, ...);
extern void func_80177DF4(u32 a0, u32 a1, u32 a2);
u32* MakeMemBlock(u32 a0, u8 a1);
void func_8018D420(u32 a0);
void gd_init();
void imout();
void _InitControllers();
void func_8018C674();
void start_timer(u32* a0);
void func_8018CF48(u32* a0);
void MemStats();
void func_801A520C();

u32 __main___()
{
    osSyncPrintf(D_801B5330, D_801A8058, D_801A8050);

    func_8018D420((u32)&D_801B5338);

    gd_init();

    D_801B99A8 = D_801B5364;

    D_801B99C0 = -34;

    D_801B99CC = 34;

    D_801B9920 = 2;

    D_801B9974 = 0;

    D_801B9A10 = &D_801B9A18;

    func_8018D420((u32)&D_801B5340);

    imout();

    _InitControllers();

    func_8018C674();

    start_timer(&D_801B5354);

    func_8018CF48(&D_801B535C);

    MemStats();

    while (1)
    {
        func_801A520C();
    }

    imout();

    return 0;
}

u32* func_80177D3C_(u32 a0, u32 a1, u8 a2)
{
    u32* var1;

    a0 = (a0 - 8) & -8;
    a1 = (a1 - 8) & -8;

    var1 = MakeMemBlock(a2, 1);
    var1[0] = a1;
    var1[1] = a0;

    return var1;
}

void func_80177DCC_()
{
    D_801B9B10 = 0;
    D_801B9B14 = 0;
    D_801B9B18 = 0;
}

void func_801777E4_(UNUSED struct Unknown80177DF4* a0)
{

}

// WIP
void MemStats_()
{
    u32* var1;

    osSyncPrintf(D_801B540C);

    var1 = D_801B9B14;
    
    func_80177DF4((u32)var1, 0, 240);

    osSyncPrintf(D_801B5420);

    osSyncPrintf(D_801B5424);

    var1 = (u32*)D_801B9B10;

    func_80177DF4((u32)var1, 0, 240);

    osSyncPrintf(D_801B5438);

    osSyncPrintf(D_801B543C);

    var1 = D_801B9B14;

    func_80177DF4((u32)var1, 0, 15);

    osSyncPrintf(D_801B5450);

    osSyncPrintf(D_801B5454);

    func_80177DF4(D_801B9B10, 0, 15);

    osSyncPrintf(D_801B5468);

    osSyncPrintf(D_801B546C);

    var1 = (u32*)D_801B9B18;

    // This line needs to use $t0 for var1 instead of $t9...
    func_80177DF4((u32)var1, 0, 255); 
}
