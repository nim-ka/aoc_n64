#ifndef _MARIO_HEAD_5_H_
#define _MARIO_HEAD_5_H_

#include "types.h"
#include "goddard/gd_types.h"

// extern ? D_801B8160;
// extern ? D_801A82A0;
// extern ? D_801B8180;
// extern ? D_801B819C;
// extern ? D_801B81A0;
// extern ? D_801B81B8;
// extern ? D_801B81D4;
// extern ? D_801B81E0;
// extern ? D_801B81EC;
// extern ? D_801B81FC;
// extern ? D_801B8214;
// extern ? D_801B824C;
// extern ? D_801B8278;
// extern ? D_801A8280;
// extern ? D_801B82A4;
// extern ? D_801B82B0;
// extern ? D_801B82B4;
// extern ? D_801B82B8;
// extern ? D_801B82BC;
// extern ? D_801B82C0;
// extern ? D_801B82C4;
// extern ? D_801B82C8;
// extern ? D_801B82CC;
// extern ? D_801B82D0;
// extern ? D_801B82D4;
// extern ? D_801B82D8;
// extern ? D_801B82DC;
// extern ? D_801B82F8;
// extern ? D_801B8300;
// extern ? D_801A82A4;
// extern ? D_801A82A8;
// extern ? D_801B8328;
// extern ? D_801A82C0;
// extern ? D_801B8344;
// extern ? D_801B8350;
// extern ? D_801B836C;
// extern ? D_801B838C;
// extern ? D_801B83B4;
// extern ? D_801B83B8;
// extern ? D_801B8420;
// extern ? D_801B8460;
// extern ? D_801B8464;
// extern ? D_801A82D0;
// extern ? D_801A82D4;
// extern ? D_801B85B0;
// extern ? D_801B85BC;
// extern ? D_801B85C8;
// extern ? D_801B85D4;
// extern ? D_801B85E0;
// extern ? D_801B85F0;
// extern ? D_801B85FC;
// extern ? D_801B8608;
// extern ? D_801B8614;
// extern ? D_801B8620;
// extern ? D_801B8648;
// extern ? D_801B8654;
// extern ? D_801B8660;
// extern ? D_801B866C;
// extern ? D_801B8678;
// extern ? D_801B8680;
// extern ? D_801B8688;
// extern ? D_801B8690;
// extern ? D_801B8698;
// extern ? D_801B86A4;
// extern ? D_801B86B0;
// extern ? D_801B86C0;
// extern ? D_801B86D0;
// extern ? D_801B86D8;
// extern ? D_801B86E0;
// extern ? D_801B86EC;
// extern ? D_801B86FC;
// extern ? D_801B870C;
// extern ? D_801B871C;
// extern ? D_801B8724;
// extern ? D_801B8738;
// extern ? D_801B8748;
// extern ? D_801B8750;
// extern ? D_801B875C;
// extern ? D_801B876C;
// extern ? D_801B877C;
// extern ? D_801B878C;
// extern ? D_801B87E0;
// extern ? D_801B8800;
// extern ? D_801B888C;
// extern ? D_801B8890;
// extern ? D_801B8894;
// extern ? D_801B8898;

// extern ? func_8018C1B0(?);
// extern ? func_8018C264(?);
// extern ? func_8018C30C(?);
// extern ? Unknown8018C410(?);
extern void func_8018C458(const char*); /* printing function? */
// extern ? func_8018C5C4(?);
// extern ? func_8018C650(?);
extern void func_8018C674(void);
// extern ? func_8018C72C(?);
// extern ? func_8018C7E0(?);
// extern ? func_8018C7F8(?);
// extern ? func_8018C814(?);
// extern ? func_8018C948(?);
// extern ? func_8018C9F4(?);
// extern ? func_8018CAB4(?);
// extern ? get_timernum(?);
// extern ? func_8018CB80(?);
// extern ? Unknown8018CC5C(?);
// extern ? Unknown8018CCCC(?);
extern void start_timer(const char *);
extern void restart_timer(const char *);
extern void func_8018CEEC(const char *);
extern void func_8018CF48(const char *);
// extern ? func_8018D020(?);
// extern ? Unknown8018D1A8(?);
extern void myPrint1(const char *);
// extern ? func_8018D0E8(?);
extern void myPrintf(const char *, ...);
extern void func_8018D420(const char *);
extern void imout(void);
extern float func_8018D560(void);
extern s32 func_8018D6A8(char*); /* s32 gd_atoi(char*) */
extern f64 func_8018D808(char*, UNUSED u32*);   /* return (f64) gd_atoi(char*); lol */
// extern ? func_8018D848(?);
// extern ? func_8018D8A8(?);
// extern ? func_8018D9A4(?);
// extern ? func_8018D9F8(?);
extern void func_8018DC98(char *, char *);  /* gd_strcpy? */
// extern ? Unknown8018DCDC(?);
// extern ? func_8018DD5C(?);
// extern ? func_8018DDD8(?);
// extern ? func_8018DE2C(?);
extern s32 func_8018DEB0(char*, char*); /* gd_strcmp? */ 
extern s32 func_8018DF58(char*, char*); // gd_strstr?
extern s32 func_8018DFE8(struct GdFile*);  /* get GdFile->unk0C bit 3 (->0c & 0x4); file end reached? */
// extern ? func_8018E00C(?);
extern struct GdFile* gd_fopen(char*, char*);
extern s32 func_8018E23C(s8*, s32, s32, struct GdFile*); /* read_into(buf*, number, size, fd*)? */
extern void func_8018E368(struct GdFile*); /* gd_fclose? */
// extern ? func_8018E384(?);
// extern ? func_8018E3A0(?);
extern s32 func_8018E3D8(char*, u32, struct GdFile*);   /* gd_read_file? gd_fgets? */
// extern ? Proc8018E520(?);
extern void Proc8018EBE8(struct ObjJoint*);
// extern ? Unknown8018EE5C(?);
// extern ? func_8018EF78(?);
// extern ? make_joint(?);
extern struct ObjJoint* func_8018F248(void*, s32, f32, f32, f32);
// extern ? func_8018F328(?);
// extern ? Unknown8018F4CC(?);
// extern ? func_8018F520(?);
// extern ? func_8018F89C(?);
// extern ? Unknown8018FA68(?);
// extern ? func_8018FAC8(?);
// extern ? func_8018FB58(?);
// extern ? func_8018FCA4(?);
// extern ? make_bone(?);
// extern ? Unknown8018FF14(?);
// extern ? Unknown8018FF28(?);
// extern ? Unknown8018FF88(?);
// extern ? func_8018FFE8(?);
// extern ? func_80190168(?);
// extern ? func_801903E8(?);
// extern ? func_80190574(?);
// extern ? func_801909B4(?);
// extern ? Unknown80190A20(?);
// extern ? func_80190B54(?);
// extern ? Unknown80190E68(?);
// extern ? func_80190F3C(?);
// extern ? Unknown801911A8(?);
// extern ? Unknown80191220(?);
// extern ? Unknown801913C0(?);
// extern ? Unknown801913F0(?);
// extern ? Unknown801914F8(?);
// extern ? Unknown8019150C(?);
extern void func_80191604(struct ObjHeader*);   // maybe a ObjJoint
// extern ? Unknown80191824(?);
// extern ? Unknown801918F4(?);
// extern ? Unknown80191A1C(?);
// extern ? Unknown80191BF8(?);
// extern ? Unknown80191D60(?);
// extern ? Unknown80191E54(?);
// extern ? func_80191E88(?);
extern void func_80191EE8(void);
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
// extern ? func_80193B30(?);
// extern ? func_80193B68(?);
extern void func_8019415C(Mat4*, struct MyVec3f*);
extern void func_80194220(Mat4*, struct MyVec3f*);
extern void func_801942E4(Mat4*, struct MyVec3f*);
extern void func_80194358(Mat4*, struct MyVec3f*, float);
extern f32 func_80194728(f32, f32);     /* min(f1, +/-f2)? */
extern void func_80194770(struct MyVec3f*, f32);
extern void func_80194880(f32, f32*, f32*);
// extern ? Unknown8019498C(?);
extern void func_80194A54(Mat4*, s32, f32);
extern f32 func_80194B98(struct MyVec3f*);
extern s32 func_80194BF4();     //s32 func_80194BF4(struct MyVec3f*)
extern void func_80194D14(struct MyVec3f*, struct MyVec3f*, struct MyVec3f*);
extern float func_80194DB8(); //extern float func_80194DB8(struct MyVec3f *, struct MyVec3f *);
// extern ? Unknown80194DFC(?);
extern void func_80194E7C(Mat4*, Mat4*);
// extern ? func_80194F90(?);
// extern ? func_80195578(?);
// extern ? func_80195844(?);
// extern ? func_8019590C(?);
// extern ? Unknown80195950(?);
// extern ? Unknown801959E0(?);
// extern ? Unknown80195B04(?);
// extern ? func_80195C78(?);
// extern ? Unknown80195D98(?);
// extern ? func_80195FD4(?);
extern void func_8018C30C(const char*); /* some sort of print function */
extern void func_801961F4(Mat4*, struct MyVec3f*, f32);
extern void func_80196280(void *);      //Mat4*; something sort of matrix4x4_init?
extern void func_80196360(Mat4*, Mat4*);
extern void func_80196430(struct MyVec3f *, void *);    // (struct MyVec3f*, Mat4*)
extern void func_80196540(struct MyVec3f*, Mat4*);
extern void func_80196614(Mat4*, Mat4*, Mat4*);
extern void func_80196F8C(char*, struct MyVec3f*);
// extern ? func_80196FA8(?);
// extern ? func_80196FC4(?);
// extern ? Unknown80197068(?);
// extern ? Unknown801970F0(?);

#endif /* _MARIO_HEAD_5_H_ */
