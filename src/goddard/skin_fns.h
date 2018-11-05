#ifndef _SKIN_FUNCTIONS_H_
#define _SKIN_FUNCTIONS_H_

#include <types.h>
#include "gd_types.h"

// bss
extern struct ObjNet* gGdSkinNet;   // @ 801BAAF0

// extern ? func_80191F10(?);
extern void func_801920C4(struct ObjHeader*);   // maybe a ObjNet
// extern ? Unknown80192294(?);
// extern ? Unknown801922FC(?);
extern struct ObjNet* make_net(s32, struct ObjShape*, void* , struct ObjGroup*, struct ObjGroup*);
// extern ? func_80192528(?);
// extern ? func_801926A4(?);
// extern ? Unknown80192AD0(?);
// extern ? func_80192C5C(?);
// extern ? func_80192CCC(?);
// extern ? func_80192F98(?);
// extern ? func_801932E4(?);
// extern ? Proc801933FC(?);
// extern ? func_801934D0(?);
// extern ? Unknown8019359C(?);
extern void func_801936C4(struct ObjGroup*);
// extern ? Unknown8019373C(?);
extern void func_80193848(struct ObjGroup*);
// extern ? Unknown801938BC(?);
extern void func_80193B10(void);

#endif /* _SKIN_FUNCTIONS_H_ */
