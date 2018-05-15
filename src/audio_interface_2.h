#ifndef _AUDIO_INTEFACE_2_H
#define _AUDIO_INTEFACE_2_H

#include "types.h"

struct Struct80333F00
{
    u8 filler0[0xA0];
    OSViMode viMode;
#if VERSION_US
    OSViMode unk500;
#endif
};

extern f32 D_803320E0[];
extern struct Struct80333F00 D_80333F00;
extern u8 D_80338750[];

// extern ? D_80360120;
// extern ? D_80331D44;
// extern ? D_80338F50;
// extern ? D_8032B800;
// extern ? D_801FF200;
// extern ? D_80331E34;
// extern ? D_80360128;
// extern ? D_80360C48;
// extern ? D_803320B0;
// extern ? D_803320A4;
// extern ? D_80331E30;
// extern ? D_80332110;
// extern ? D_8033212C;
// extern ? D_8033216C;
// extern ? D_8033217C;
// extern ? D_803320C8;
// extern ? D_80360C28;
// extern ? D_80360C38;
// extern ? D_80363808;
// extern ? D_8033209C;
// extern ? D_80331EB0;
// extern ? D_80331EAC;
// extern ? D_803320A0;
// extern ? D_80360928;
// extern ? D_80222A1A;
// extern ? D_80331F50;
// extern ? D_80363813;
// extern ? D_80363812;
// extern ? D_8033211C;
// extern ? D_803320BC;
// extern ? D_80363818;
// extern ? D_80332118;
// extern ? D_80332114;
// extern ? D_80332128;
// extern ? D_80332120;
// extern ? D_80332124;
// extern ? D_803320F8;
// extern ? D_8033210C;
// extern ? D_80332108;

// extern ? func_8031D630(?);
// extern ? func_8031D690(?);
// extern ? func_8031D6E4(?);
// extern ? func_8031D7B0(?);
// extern ? func_8031D838(?);
extern OSMesg *func_8031D924(void);
extern void SetSound(int, void *);
// extern ? func_8031DCA8(?);
// extern ? func_8031DF64(?);
// extern ? func_8031DFE8(?);
// extern ? func_8031E0E4(?);
// extern ? func_8031E16C(?);
// extern ? func_8031E97C(?);
// extern ? func_8031EB24(?);
// extern ? func_8031EC7C(?);
// extern ? func_8031ED70(?);
// extern ? func_8031EEC8(?);
extern void func_8031EED0(void);
// extern ? func_8031EEF8(?);
// extern ? SetMusic(?);
extern void func_8031F7CC();
// extern ? func_8031F810(?);
// extern ? func_8031F888(?);
// extern ? func_8031F96C(?);
// extern ? func_8031FA4C(?);
// extern ? Unknown8031FED0(?);
extern void func_8031FFB4();
extern void func_80320040();
// extern ? func_803200E4(?);
extern void func_80320248();
extern void func_803202A0(void);
// extern ? Unknown8032050C(?);
// extern ? func_803205E8(?);
extern void func_803206F8();
// extern ? func_803207DC(?);
extern void func_80320890(void);
extern void func_803208C0();
// extern ? func_8032091C(?);
extern void func_80320980();
// extern ? Unknown803209D8(?);
// extern ? func_80320A4C(?);
// extern ? func_80320A68(?);
extern void func_80320AE8(int, int, int);
extern void func_80320CE8();
extern void func_80320E20();
extern void func_80320E74(void);
extern u16 func_80320E98(void);
// extern ? func_80320ED8(?);
extern void func_80320F84();
extern void func_80321080();
extern void func_803210D4();
// extern ? func_803211B0(?);
// extern ? func_803211EC(?);
// extern ? func_80321228(?);
// extern ? func_80321264(?);
// extern ? func_803212A0(?);
// extern ? func_803212F0(?);
// extern ? func_8032132C(?);
extern void func_80321368();
extern void func_80321434();
// extern ? Unknown80321460(?);
// extern ? Unknown80321474(?);

#endif /* _AUDIO_INTEFACE_2_H */
