#include <ultra64.h>

#include "sm64.h"
#include "playback.h"

union s8arr_u16 {
    u8 as_s8[2];
    u16 as_u16;
};

union s8ptr_u16 {
    s8 *as_s8ptr;
    u16 as_u16[2];
};

struct struct8031A17C {
    struct struct8031A17C *unk00;
    u32 unk04;
    union s8ptr_u16 unk08;
    union s8arr_u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
};

struct unknown2 {
    u32 pad0b : 2; 
    u32 unk0b30 : 1;
    s8 pad04[0x18 - 0x04];
    f32 unk18;
    s8 pad01C[0x24 - 0x1C];
    f32 unk24;
};

struct struct8031A478 { // Struct80222A18_2C
    struct {
        u16 b31 : 1;
    } unk00;
    u8 unk02;    
    struct struct8031A078 unk04;
    s8 pad14[0x18 - 0x14];
    s32 pad18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s8 pad38[0x40 - 0x38];
    struct unknown2 *unk40;
    struct struct8031A478 *unk44[3];
    struct struct8031A17C *unk50;
};

struct struct8031A418_2 { // Struct80222A18
    s8 pad00[0x2 - 0x0];
    u8 unk02;
    s8 pad03[0xE - 0x3];
    u16 unk0E;
    s8 pad10[0x18 - 0x10];
    f32 unk18;
    f32 unk1C;
    s8 pad20[0x2C - 0x20];
    struct struct8031A478 *unk2C[16];
    s8 pad6C[0x74 - 0x6C];
    struct struct8031A078 unk74;
    struct struct8031A17C unk84;
};

extern f32 D_80332684[];
extern s8 D_80332AA4;

#ifdef VERSION_JP
#define US_FLOAT(x) x
#else
#define US_FLOAT(x) x ## f
#endif

#ifdef VERSION_JP
#define US_FLOAT2(x) x ## .0
#else
#define US_FLOAT2(x) x
#endif

extern void func_8031AE24(void* arg0);

void func_80319E70(void) { }

void func_80319E78(struct struct8031A418_2 *a0) {
    s32 a3;

    if (a0->unk0E != 0) {
        a0->unk18 += a0->unk1C;
        
        if (a0->unk18 > US_FLOAT2(1)) a0->unk18 = US_FLOAT2(1);
        if (a0->unk18 < 0) a0->unk18 = 0;

        if (--a0->unk0E == 0) {
            switch (a0->unk02) {
                case 1:
                    func_8031AE24(a0);
                    return;

                case 2:
                case 3:
                    a0->unk02 = 0;
                    break;

                case 4:
                    break;
            } 
        }
    }

    for (a3 = 0; a3 < 16; a3++) {
        if (IS_SPECIAL(a0->unk2C[a3]) == 1) { 
            if (a0->unk2C[a3]->unk00.b31 == 1) {
                f32 f0;
                f32 f12;
                f32 f2;
                s32 v1;
                struct struct8031A478 *v0 = a0->unk2C[a3];

                f0 = v0->unk40->unk18 * (v0->unk20 * v0->unk1C);
                if (v0->unk40->unk0b30 && (v0->unk02 & 0x20) != 0)
                    f0 *= v0->unk40->unk24;

                f2 = v0->unk28 * v0->unk24;
                f12 = US_FLOAT(1.0) - v0->unk28;

                for (v1 = 0; v1 < 4; v1++) {
                    struct struct8031A478 *v0_2 = v0->unk44[v1];
                    if (v0_2 != NULL && v0_2->unk00.b31 
                        && v0_2->unk44[0] != 0) {
                        v0_2->unk34 = v0->unk2C * v0_2->unk20;
                        v0_2->unk2C = v0_2->unk24 * f0;
                        v0_2->unk30 = (v0_2->unk28 * f12) + f2;
                    }
                }
            }
        }
    }
}

f32 func_8031A078(struct struct8031A078 *a0) {
    u32 v0;
    f32 result;
    if (!a0->unk00)
        return 1.0f;

    a0->unk04 += a0->unk08;
    v0 = a0->unk04;

    if (v0 >= 127)
        v0 = 127;

    result = US_FLOAT(1.0) + (D_80332684[v0] - US_FLOAT(1.0)) * a0->unk0C;
    return result;
}

s8 func_8031A17C(struct struct8031A17C *a0) {
    s32 v1;
    a0->unk04 += a0->unk0E;

    v1 = (a0->unk04 >> 10) & 0x3F;

    switch (v1 & 0x30) {
        case 0x10:
            v1 = 31 - v1;
            
        case 0x00:
            return a0->unk08.as_s8ptr[v1];

        case 0x20:
            v1 -= 0x20;
            break;

        case 0x30:
            v1 = 63 - v1;
            break;
    }

    return -a0->unk08.as_s8ptr[v1];
}

f32 func_8031A204(struct struct8031A17C *a0) {
    s8 v0;
    f32 f2;
    f32 result;

    if (a0->unk16 != 0) {
        a0->unk16--;
        return 1;
    }

    if (a0->unk14) {
        if (a0->unk14 == 1) {
            a0->unk10 = a0->unk00->unk0E;
        }
        else {
            a0->unk10 += (a0->unk00->unk0E - a0->unk10) / a0->unk14;
        }

        a0->unk14--;
    } 
    else {
        if (a0->unk10 != a0->unk00->unk0E) {
            a0->unk14 = a0->unk00->unk12;
            if (a0->unk14 == 0)
                a0->unk10 = a0->unk00->unk0E;
        }
    }

    if (a0->unk12) {
        if (a0->unk12 == 1) {
            a0->unk0E = a0->unk00->unk0C.as_u16;
        }
        else {
            a0->unk0E = a0->unk0E + (a0->unk00->unk0C.as_u16 - a0->unk0E) / a0->unk12;
        }

        a0->unk12--;
    }
    else {
        if (a0->unk0E != a0->unk00->unk0C.as_u16) {
            a0->unk12 = a0->unk00->unk10;
            if (a0->unk12 == 0)
                a0->unk0E = a0->unk00->unk0C.as_u16;
        }
    }

    if (a0->unk10 == 0) {
        return 1.0f;
    }
    
    v0 = func_8031A17C(a0);
    f2 = (f32)a0->unk10 /  US_FLOAT(4096.0);

    result = f2 * (D_80332684[v0] - US_FLOAT(1.0)) + US_FLOAT(1.0);
    return result;
}

void func_8031A418(struct struct8031A418_2 *a0) {
    if (a0->unk84.unk0C.as_s8[0] != 0) {
        a0->unk18 = func_8031A078(&a0->unk74);
        if ((s32)a0->unk2C[0] != -1) {
            a0->unk1C = func_8031A204(&a0->unk84);
        }
    }
}

void func_8031A478(struct struct8031A418_2 *a0) {
    struct struct8031A17C *v0; 
    struct struct8031A17C *v1;  
    a0->unk1C = 1.0f;
    a0->unk18 = 1.0f;

    v0 = &a0->unk84;

    if (a0->unk2C[0]->unk50->unk08.as_u16[1] == 0
        && a0->unk2C[0]->unk50->unk0E == 0
        && a0->unk2C[0]->unk04.unk00 == 0 ) {
        a0->unk84.unk0C.as_s8[0] = 0;
        return;
    }


    v0->unk0C.as_s8[0] = 1;
    v0->unk04 = 0;
    v0->unk08.as_s8ptr = &D_80332AA4;
    v0->unk00 = a0->unk2C[0]->unk50;

    v1 = v0->unk00;

    v0->unk14 = v1->unk12;
    if (v0->unk14 == 0) {
        v0->unk10 = v1->unk0E;
    }
    else {
        v0->unk10 = v1->unk08.as_u16[1];
    }


    v0->unk12 = v1->unk10;
    if (v0->unk12 == 0) {
        v0->unk0E = v1->unk0C.as_u16;
    }
    else {
        v0->unk0E = v1->unk08.as_u16[0];
    }

    v0->unk16 = v1->unk14;
    a0->unk74 = a0->unk2C[0]->unk04;
}

void func_8031A564(struct SubStruct_func_8031A584 *a0, struct SubStructInstrumentSomething *a1, s16 *a2) {
    a0->unk00 = 0;
    a0->unk01 = 0;
    a0->unk02 = 0;
    a0->unk0A = 0;
    a0->unk10 = 0;
    a0->unk1C = a1;
    a0->unk18 = a2;
}

s32 func_8031A584(struct SubStruct_func_8031A584 *a0) {
    u8 flags = a0->unk00;
    switch (a0->unk01)
    {
        case 0:
            return 0;

        case 1: {
            a0->unk06 = a0->unk02;
            a0->unk04 = a0->unk02;
            if ((flags & 0x40) != 0) {
                a0->unk01 = 5;
                goto CONT;
            }
            // fallthrough
        }

        case 2:
            a0->unk08 = 0;
            a0->unk14 = a0->unk06 << 0x10;
            a0->unk01 = 3;
            // fallthrough

        case 3:
            a0->unk0A = a0->unk1C[a0->unk08].unk00;
            switch (a0->unk0A)
            {
                case 0:
                    a0->unk01 = 0;
                    break;
                case -1:
                    a0->unk01 = 5;
                    break;
                case -2:
                    a0->unk08 = a0->unk1C[a0->unk08].unk02;
                    break;
                case -3:
                    a0->unk01 = 1;
                    break;

                default:
                    a0->unk04 = a0->unk1C[a0->unk08].unk02;
                    a0->unk10 = ((a0->unk04 -a0->unk06) << 0x10) / a0->unk0A;
                    a0->unk01 = 4;
                    a0->unk08++;
                    break;
            }
            if (a0->unk01 != 4) {
                goto CONT;
            }

        case 4:
            a0->unk14 += a0->unk10;
            a0->unk06 = (a0->unk14) >> 0x10;
            if (--a0->unk0A <= 0) {
                a0->unk01 = 3;
            }

        case 5:
            goto CONT;

        case 6:
        case 7: {
            a0->unk06 -= a0->unk0E;
            if (a0->unk0C != 0) {
                if (a0->unk01 == 6) {
                    if (a0->unk06 < a0->unk0C) {
                        a0->unk06 = a0->unk0C;
                        a0->unk0A = a0->unk0C / 16;
                        a0->unk01 = 8;
                    }
                    goto CONT;
                }
            }

            if (a0->unk06 < 0x64) {
                a0->unk06 = 0;
                a0->unk01 = 0;
            }
            goto CONT;
        }

        case 8:
            a0->unk0A -= 1;
            if (a0->unk0A == 0) {
                a0->unk01 = 7;
            }
            goto CONT;
    }

CONT:

    if ((flags & 0x20)) {
        a0->unk01 = 6;
        a0->unk00 = flags & ~0x20;
    }

    if ((flags & 0x10)) {
        a0->unk01 = 7;
        a0->unk00 = flags & ~0x30;
    }

    *a0->unk18 = a0->unk06;
    return 0;
}
