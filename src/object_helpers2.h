#ifndef OBJECT_HELPERS2_H
#define OBJECT_HELPERS2_H

#include "types.h"

#define WAYPOINT_FLAGS_END -1

struct GraphNode_802A45E4 {
    /*0x00*/ s8 filler0[0x18 - 0x00];
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C;
    /*0x1E*/ s16 unk1E;
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
};

struct Struct802A2CFC {
    s32 unk0;
    u8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
};

extern void func_802A2CFC(struct Object* obj, struct Struct802A2CFC *arg1);
// extern ? func_802A2E5C(?);
extern f32 func_802A2E8C(f32);
// extern ? func_802A2ECC(?);
// extern ? func_802A2EFC(?);
// extern ? IsMarioGroundPounding(?);
void func_802A3004(void);
// extern ? func_802A3034(?);
// extern ? func_802A3070(?);
// extern ? func_802A3164(?);
// extern ? BehDustSmokeLoop(?);
// extern ? func_802A32A4(?);
// extern ? func_802A32E0(?);
// extern ? Unknown802A3380(?);
// extern ? func_802A3398(?);
// extern ? func_802A3470(?);
// extern ? IsMarioStepping(?);
// extern ? Unknown802A3598(?);
// extern ? func_802A362C(?);
// extern ? func_802A3688(?);
// extern ? func_802A36D8(?);
// extern ? Unknown802A3750(?);
// extern ? func_802A377C(?);
// extern ? func_802A37A0(?);
// extern ? func_802A38A4(?);
// extern ? func_802A3910(?);
extern void BehCommonInit(void); // 802A3978
extern void func_802A3A68(void);
// extern ? func_802A3BB8(?);
// extern ? func_802A3C98(?);
// extern ? func_802A3D4C(?);
// extern ? func_802A3D84(?);
// extern ? func_802A3DBC(?);
// extern ? Geo18_802A45E4(?);
// extern ? Unknown802A3E84(?);
// extern ? func_802A3F24(?);
// extern ? func_802A3F5C(?);
// extern ? func_802A3F80(?);
void func_802A3FA8(s32);
void func_802A3FCC(s32);
// extern ? func_802A3FF8(?);
// extern ? func_802A4114(?);
// extern ? func_802A4154(?);
// extern ? func_802A41B8(?);
extern int CreateMessageBox();
// extern ? func_802A472C(?);
// extern ? func_802A4780(?);
// extern ? Unknown802A485C(?);
// extern ? ShakeScreen(?);
extern s32 func_802A4964(struct Object *obj);
// extern ? func_802A49D4(?);
// extern ? func_802A4A50(?);
// extern ? func_802A4A70(?);
// extern ? func_802A4AB0(?);
// extern ? func_802A4AEC(?);
// extern ? func_802A4B20(?);
// extern ? func_802A4B80(?);
// extern ? Unknown802A4C34(?);
// extern ? Unknown802A4C88(?);
// extern ? func_802A4CC0(?);
// extern ? func_802A4D00(?);
// extern ? func_802A4D4C(?);

#endif /* OBJECT_HELPERS2_H */
