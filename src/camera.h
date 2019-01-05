#ifndef _CAMERA_H
#define _CAMERA_H

#include "types.h"
#include "area.h"
#include "geo_layout.h"


struct Struct80287404
{
    u8 filler0[0x18];
    s32 unk18;
    Vec3f unk1C;
    Vec3f unk28;
    u8 filler34[0x3A-0x34];
    s16 unk3A;
};

typedef void (*CameraCommandProc)(struct Struct80280550 *a);

struct Struct8032CA78
{
    s8 unk0;
    s8 filler1[3];
    CameraCommandProc unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16; // unknown type
};

struct Struct8032D000
{
    u32 unk0;
    Vec3f unk4;
    Vec3s unk10;
    s16 unk16;
    s16 unk18;
    u8 filler1A[0x1E - 0x1A];
    s16 unk1E;
    u32 unk20;
};

struct Struct8032E040
{
    s8 unk0;
    u8 unk1;
    Vec3s unk2;
};

struct Struct8033B278
{
    struct Surface *unk0;
    f32 unk4;
    s16 unk8;
    u8 fillerA[2];
    struct Surface *unkC;
    s16 unk10;
    u8 filler12[2];
    f32 unk14;
    struct Surface *unk18;
    f32 unk1C;
    s16 unk20;
    u8 filler22[2];
    struct Surface *unk24;
    f32 unk28;
    s16 unk2C;
    u8 filler2E[2];
    f32 unk30;
};

struct Struct8033B418_sub
{
    Vec3f unk0;
    Vec3f unkC;
    float unk18;
    s16 unk1C;
    s16 unk1E;
};

struct Struct8033B418
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    struct Struct8033B418_sub unk8[2];  // unknown length
};

struct Struct8033B470
{
    s16 unk0;
    u8 filler2[2];
    Vec3f unk4;
    float unk10;
    float unk14;
};

struct Struct8033B4B8
{
    Vec3f unk0;
    Vec3f unkC;
    u32 filler2[2];
};

struct Struct8033B6F0
{
    s32 unk0;
    Vec3f unk4;
    Vec3f unk10;
    Vec3s unk1C;
    s16 unk22;
};

struct StructUnknown1
{
    s8 unk0;
    u8 unk1;
    Vec3s unk2;
};

// TODO: add all the externs from camera.c
// TODO: figure out which ones of these are static

extern struct Object *D_8032CFD0;
extern s16 D_8032CFD4;
extern s32 D_8032CFD8;
extern float D_8032CFEC;
extern struct Struct8032D000 *D_8032D000;
extern Vec3f D_8032D00C;
extern Vec3f D_8032D090;
extern struct Struct8032E040 D_8032E040;
extern struct Struct8032E040 D_8032E090;
extern struct Struct8032E040 D_8032E0E8;
extern struct Struct8032E040 D_8032E188;
extern struct Struct8032E040 D_8032E1D0;
extern struct Struct8032E040 D_8032E218;
extern struct Struct8032E040 D_8032E258;
extern struct Struct8033B1B0 D_8033B1B0;
extern struct Struct8033B278 D_8033B278;
extern s16 D_8033B2AC;
extern s16 D_8033B2AE;
extern s16 D_8033B2B0;
extern s16 D_8033B314;
extern s16 D_8033B318;
extern s16 D_8033B31C;
extern u16 D_8033B31E;
extern s16 D_8033B3EA;
extern s16 D_8033B3EC;
extern s16 D_8033B3EE;
extern s16 D_8033B3F0;
extern s16 D_8033B3F8;
extern s16 D_8033B3FA;
extern s16 D_8033B400;
extern s16 D_8033B402;
extern s16 D_8033B404;
extern s16 D_8033B406;
extern s16 D_8033B408;
extern float D_8033B40C;
extern struct Struct8033B418 D_8033B418;
extern s16 D_8033B43E;
extern Vec3f D_8033B460;
extern u32 D_8033B46C;
extern struct Struct8033B470 *D_8033B470;
extern Vec3f D_8033B478;
extern Vec3f D_8033B498[];
extern s16 D_8033B4D8;
extern s16 D_8033B4DA;
extern struct Struct8033B6F0 D_8033B6F0[];
extern u32 D_8033B858;



// TODO: make some of these functions static
// "static (ASM)" means they will be resolved after full decompilation
// "static (postdefined)" means that the function is used before its definition
// "postdefined" same as above but unconfirmed whether it is actually static

extern void func_8027EFE0(s16);
extern void func_8027F308(s16);
extern void func_8027F440(s16, f32, f32, f32);

extern int CameraChange01(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange0E(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange02(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange0C(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange0D(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange0B(struct Struct80280550 *, Vec3f, Vec3f);
extern void CameraChange05(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange03(struct Struct80280550 *, Vec3f, Vec3f);
extern void CameraChange08(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange040710(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange11(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange090F(struct Struct80280550 *, Vec3f, Vec3f);
extern int CameraChange06(struct Struct80280550 *, Vec3f, Vec3f);
extern void func_802852F4(struct Struct80280550 *); // static (ASM)
extern int CameraChange0A(struct Struct80280550 *, Vec3f, Vec3f);

extern void func_80285A8C(UNUSED struct Struct80280550 *, s16); // static (postdefined)
extern void func_80285BD8(struct Struct80280550 *, s16, s16);
extern void func_80286348(struct Struct80280550 *);
extern void func_802869B8(struct Struct80280550 *);
extern void func_80286C9C(struct Struct80280550 *); // static (postdefined)
extern void func_802875DC(void);
extern int Geo0F_80287D30(int, struct Struct80287404 *, struct AllocOnlyPool *);
extern void dummy_802877D8(struct Struct80280550 *); // static (postdefined)
extern void dummy_802877EC(struct Struct80280550 *); // static (postdefined)
extern void vec3f_sub(Vec3f, Vec3f); // static (postdefined)
extern void object_pos_to_vec3f(Vec3f, struct Object *); // static (postdefined)
extern void vec3f_to_object_pos(struct Object *, Vec3f); // static (ASM)
extern int func_80287CFC(Vec3f, struct Struct8032E040 *, s16 *, float *);
extern int func_8028803C(int);
extern int func_80288130(int); // static (postdefined)
extern void func_802882A0(u8); // static (postdefined)
extern void func_802883C8(Vec3f, Vec3f); // static (postdefined)
extern int func_802886FC(u16, u16, u16); // static (postdefined)
extern int update_camera_status(struct Struct80280550 *); // static (postdefined)
extern int func_80288974(Vec3f, float, float); // static (postdefined)
extern int func_80288C2C(Vec3f a, Vec3f b, s16 c, s16 d); // static (postdefined)
extern int func_80288CF0(float, float, float); // static (postdefined)
extern int func_80288D74(float *, float, float); // static (postdefined)
extern int func_80288E0C(float *, float, float); // static (postdefined)
extern float func_80288EA0(float, float, float); // static (ASM)
extern int func_80288ECC(s16 *, s16, s16); // static (postdefined)
extern int func_80288F84(s16, s16, s16); // static (ASM)
extern void func_80289028(Vec3f, Vec3f, float, float, float); // static (ASM)




extern void func_8028909C(Vec3f, Vec3f, float, float, float); // postdefined
// extern ? func_80289110(?);
extern int func_80289184(s16 *a, s16 b, s16 c);
// extern ? func_80289264(?);
extern int func_80289354(s16 *a, s16 b, s16 c); // postdefined
extern int func_802893E4(float *, float, float);
// extern ? func_80289524(?);
void func_80289618(Vec3s a, s16 b, s16 c, s16 d); // postdefined
// extern ? func_80289738(?);
extern int func_802899A0(Vec3f, Vec3f, float, float, float, float);
// extern ? func_80289A98(?);
// extern ? func_80289B0C(?);
// extern ? func_80289F04(?);
extern int func_8028A0D4(Vec3f a, Vec3f b, struct Surface *c, s16 d, s16 e);
// extern ? func_8028A204(?);
extern void func_8028A24C(Vec3f, Vec3f, Vec3f, float);
// extern ? func_8028A300(?);
extern int func_8028A440(Vec3f, Vec3f);
extern s16 func_8028A4F0(Vec3f, Vec3f);
extern void func_8028A578(Vec3f, Vec3f, s16 *, s16 *);
extern float func_8028A640(Vec3f, Vec3f);
extern float func_8028A6E4(Vec3f, Vec3f);
extern void func_8028A764(Vec3f, Vec3f, u16);
extern void func_8028A834(Vec3f, Vec3f, u16);
extern void func_8028A908(s16, s16, s16);
extern void func_8028A964(s16, s16, s16);
extern void func_8028AA24(s16, s16, s16);
extern void func_8028AA80(s16, s16, s16, float, float, float, float);
// extern ? Unknown8028AB34(?);
// extern ? func_8028ABE8(?);
extern void func_8028AC30(); // postdefined
extern void func_8028AD44(); // postdefined
extern void func_8028AE50(s16 *); // postdefined
extern int func_8028AF24(struct Struct80280550 *a, s16 b);
// extern ? func_8028B13C(?);
// extern ? func_8028B16C(?);
extern void func_8028B19C(void);
extern void func_8028B1DC(void);
extern void func_8028B21C(void);
extern void func_8028B268(void);
extern void func_8028B29C(void);
extern void func_8028B2D0(void);
extern void func_8028B304(void); // postdefined
extern void func_8028B338(void); // postdefined
extern void func_8028B36C(void); // postdefined
extern int func_8028B3DC(struct Struct80280550 *a, float b);
extern int StopMario(int);
extern void func_8028B7A4(struct Struct80280550 *);
// extern ? func_8028BA38(?);
extern void func_8028BB3C(struct Struct80280550 *a, u8 b); // postdefined
// extern ? func_8028BB8C(?);
// extern ? func_8028BC6C(?);
extern u8 func_8028BCC8(); // postdefined
extern void func_8028C1A0(f32, f32, f32);
extern void func_8028C2F0(struct Struct80280550 *, float, float);
// extern ? Unknown8028C3AC(?);
// extern ? func_8028C3CC(?);
// extern ? Unknown8028C508(?);
extern void func_8028C5F0(Vec3f, Vec3f, Vec3f, Vec3s);
// extern ? func_8028C794(?);
// extern ? func_8028C7EC(?);
int func_8028C824(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f, s16 g); // postdefined
// extern ? Unknown8028CE1C(?);
// extern ? func_8028CE4C(?);
// extern ? func_8028CFAC(?);
// extern ? func_8028CFFC(?);
// extern ? func_8028D058(?);
// extern ? func_8028D098(?);
// extern ? func_8028D19C(?);
extern void func_8028D288(); // postdefined
// extern ? func_8028D32C(?);
// extern ? CameraRR00(?);
// extern ? CameraRR04(?);
// extern ? CameraRR02(?);
// extern ? CameraRR0305(?);
// extern ? CameraRR01(?);
// extern ? CameraMetal00(?);
// extern ? CameraSL00(?);
// extern ? CameraSL01(?);
// extern ? CameraHMC00(?);
// extern ? CameraHMC02(?);
// extern ? CameraHMC03(?);
// extern ? CameraHMC04(?);
// extern ? CameraHMC05(?);
// extern ? CameraSSL00(?);
// extern ? CameraSSL0102(?);
// extern ? CameraSSL03(?);
// extern ? CameraTHI00(?);
// extern ? CameraTHI01(?);
// extern ? CameraRR07(?);
// extern ? CameraRR08(?);
// extern ? CameraHMC01(?);
// extern ? CameraInside20(?);
// extern ? CameraInside1E(?);
// extern ? CameraInside1F(?);
// extern ? CameraInside01(?);
// extern ? CameraInside1213(?);
// extern ? CameraUnused(?);
// extern ? CameraInside00(?);
// extern ? CameraInside0E(?);
// extern ? CameraInside0F(?);
// extern ? CameraBBH2B2C(?);
// extern ? CameraBBH24(?);
// extern ? CameraBBH2E2F(?);
// extern ? CameraBBH020C(?);
// extern ? CameraBBH01(?);
// extern ? CameraBBH0D0F(?);
// extern ? CameraBBH1011(?);
// extern ? CameraBBH12(?);
// extern ? CameraBBH1314(?);
// extern ? CameraBBH15(?);
// extern ? CameraBBH16(?);
// extern ? CameraBBH17(?);
// extern ? CameraBBH18(?);
// extern ? CameraBBH28(?);
// extern ? CameraBBH29(?);
// extern ? CameraBBH2A(?);
// extern ? CameraBBH3033(?);
// extern ? CameraBBH34(?);
// extern ? CameraBBH38(?);
// extern ? CameraBBH393A(?);
// extern ? CameraBBH00(?);
// extern ? CameraBBH1A1B(?);
// extern ? CameraBBH1C(?);
// extern ? CameraBBH1E(?);
// extern ? CameraBBH1D(?);
// extern ? CameraBBH1F20(?);
// extern ? CameraBBH21(?);
// extern ? CameraBBH22(?);
// extern ? CameraBBH23(?);
// extern ? CameraBBH3536(?);
// extern ? CameraCCM00(?);
// extern ? CameraCCM01(?);
// extern ? func_8028E634(?);
// extern ? func_8028E70C(?);
// extern ? func_8028E774(?);
extern s16 func_8028E88C(struct Struct80280550 *); // postdefined
extern void func_8028F04C(Vec3f, Vec3f);
extern s32 func_8028F2F0(struct Struct80280550 *, Vec3f, s16 *, s16);
extern void func_8028F678(struct Struct8033B278 *); // postdefined
// extern ? func_8028F800(?);
extern u8 func_8028F834(u8);
extern s16 func_8028F8E0(u8, struct Object *, s16);
extern s16 func_8028F9A4(u8, struct Object *);
extern s16 func_8028F9E8(u8, struct Object *);
// extern ? func_8028FA74(?);
// extern ? func_8028FABC(?);
// extern ? func_8028FAE0(?);
// extern ? func_8028FB44(?);
// extern ? func_8028FB80(?);
// extern ? func_8028FBD8(?);
// extern ? func_8028FD94(?);
// extern ? Unknown8028FDE8(?);
// extern ? Cutscene26Todo_0(?);
// extern ? Unknown8028FE50(?);
// extern ? CutsceneIntroPeach8028FE84(?);
// extern ? CutsceneIntroPeach8028FEB0(?);
// extern ? func_8028FEDC(?);
// extern ? func_8028FEFC(?);
// extern ? func_80290144(?);
// extern ? func_802901B4(?);
// extern ? func_80290224(?);
// extern ? func_802902A8(?);
// extern ? Unknown802902F8(?);
// extern ? Unknown80290344(?);
// extern ? func_80290390(?);
// extern ? CutsceneEnterSomething8029041C(?);
// extern ? Unknown80290450(?);
// extern ? func_8029047C(?);
// extern ? func_80290514(?);
// extern ? func_80290564(?);
// extern ? func_80290598(?);
// extern ? Unknown802905C8(?);
// extern ? Cutscene0FTodo_0(?);
// extern ? Cutscene0FTodo_1(?);
// extern ? CutscenePeachEnd80290604(?);
// extern ? CutscenePeachEnd8029065C(?);
// extern ? CutscenePeachEnd0(?);
// extern ? CutscenePeachEnd2(?);
// extern ? CutscenePeachEnd367_1(?);
// extern ? CutscenePeachEnd80290870(?);
// extern ? CutscenePeachEnd3(?);
// extern ? CutscenePeachEnd1(?);
// extern ? CutscenePeachEnd80290A34(?);
// extern ? CutscenePeachEnd4(?);
// extern ? CutscenePeachEnd80290B88(?);
// extern ? CutscenePeachEnd80290BC8(?);
// extern ? CutscenePeachEnd80290C3C(?);
// extern ? CutscenePeachEnd80290C78(?);
// extern ? CutscenePeachEnd5(?);
// extern ? CutscenePeachEnd6(?);
// extern ? CutscenePeachEnd80290E8C(?);
// extern ? CutscenePeachEnd7(?);
// extern ? CutscenePeachEnd8(?);
// extern ? CutscenePeachEnd80291014(?);
// extern ? CutscenePeachEnd80291078(?);
// extern ? CutscenePeachEnd9(?);
// extern ? CutscenePeachEnd802911A4(?);
// extern ? CutscenePeachEnd8029120C(?);
// extern ? CutscenePeachEndA(?);
// extern ? CutscenePeachEndB(?);
// extern ? CutsceneGrandStar80291324(?);
// extern ? CutsceneGrandStar8029139C(?);
// extern ? CutsceneGrandStar80291474(?);
// extern ? CutsceneGrandStar802914D8(?);
// extern ? CutsceneGrandStar80291528(?);
// extern ? CutsceneGrandStar802915B4(?);
// extern ? CutsceneGrandStar802915FC(?);
// extern ? CutsceneGrandStar0(?);
// extern ? CutsceneGrandStar80291770(?);
// extern ? CutsceneGrandStar80291844(?);
// extern ? CutsceneGrandStar802918D8(?);
// extern ? CutsceneGrandStar802919F8(?);
// extern ? CutsceneGrandStar1(?);
// extern ? func_80291BBC(?);
// extern ? CutsceneDance80291C4C(?);
// extern ? CutsceneStarDance80291CE4(?);
// extern ? CutsceneStarDance80291D30(?);
// extern ? CutsceneStarDance80291D78(?);
// extern ? Unknown80291DC0(?);
// extern ? CutsceneStarDance80291DD4(?);
// extern ? CutsceneStarDance80291E0C(?);
// extern ? CutsceneStarDance80291E44(?);
// extern ? CutsceneStarDance1(?);
// extern ? func_80291FE8(?);
// extern ? CutsceneStarDance8029209C(?);
// extern ? CutsceneStarDance80292190(?);
// extern ? CutsceneStarDance80292228(?);
// extern ? CutsceneStarDance80292334(?);
// extern ? CutsceneStarDance802923E0(?);
// extern ? CutsceneStarDance8029240C(?);
// extern ? CutsceneStarDance3(?);
// extern ? CutsceneStarDance802925C0(?);
// extern ? CutsceneStarDance80292740(?);
// extern ? CutsceneStarDance802927EC(?);
// extern ? func_80292884(?);
// extern ? CutsceneStarDance80292900(?);
// extern ? CutsceneStarDance80292958(?);
// extern ? CutsceneStarDance802929A4(?);
// extern ? CutsceneStarDance2(?);
// extern ? CutsceneKeyDance80292AB0(?);
// extern ? CutsceneKeyDance80292B24(?);
// extern ? CutsceneKeyDance80292B80(?);
// extern ? CutsceneKeyDance80292BE0(?);
// extern ? CutsceneKeyDance80292C4C(?);
// extern ? CutsceneKeyDance80292CB4(?);
// extern ? CutsceneKeyDance80292CE8(?);
// extern ? CutsceneKeyDance80292D14(?);
// extern ? CutsceneKeyDance(?);
// extern ? CutsceneEnterBowserPlatform80292E48(?);
// extern ? CutsceneEnterBowserPlatform80292E74(?);
// extern ? CutsceneEnterBowserPlatform80292E98(?);
// extern ? CutsceneEnterBowserPlatform80292F08(?);
// extern ? CutsceneEnterBowserPlatform80292FA0(?);
// extern ? CutsceneEnterBowserPlatform80292FE4(?);
// extern ? CutsceneEnterBowserPlatform8029305C(?);
// extern ? CutsceneEnterBowserPlatform8029309C(?);
// extern ? func_802930C8(?);
// extern ? CutsceneEnterBowserPlatform802930F4(?);
// extern ? CutsceneEnterBowserPlatform802931A8(?);
// extern ? CutsceneEnterBowserPlatform1(?);
// extern ? CutsceneEnterBowserPlatform2(?);
// extern ? CutsceneEnterBowserPlatform0(?);
// extern ? CutsceneStarSpawn8029347C(?);
// extern ? CutsceneStarSpawn802934A8(?);
// extern ? CutsceneStarSpawn80293530(?);
// extern ? CutsceneStarSpawn802935B4(?);
// extern ? CutsceneStarSpawn0(?);
// extern ? CutsceneStarSpawn1(?);
// extern ? CutsceneStarSpawn2(?);
// extern ? CutsceneExitWaterfall80293750(?);
// extern ? Cutscene80293794(?);
// extern ? CutsceneExitWaterfall0(?);
// extern ? CutsceneFallCommon(?);
// extern ? CutsceneFallToCastleGrounds802938EC(?);
// extern ? CutsceneFallToCastleGrounds0(?);
// extern ? CutsceneSpecialStarSpawn8029398C(?);
// extern ? CutsceneSpecialStarSpawn802939E4(?);
// extern ? CutsceneSpecialStarSpawn80293A48(?);
// extern ? CutsceneSpecialStarSpawn80293A8C(?);
// extern ? CutsceneSpecialStarSpawn80293ACC(?);
// extern ? CutsceneSpecialStarSpawn80293C8C(?);
// extern ? CutsceneSpecialStarSpawn0(?);
// extern ? CutsceneSpecialStarSpawn1(?);
// extern ? func_80293DE8(?);
// extern ? CutscenePrepareCannon802940D8(?);
// extern ? CutscenePrepareCannon80294164(?);
// extern ? func_802941CC(?);
// extern ? CutscenePrepareCannon80294260(?);
// extern ? CutscenePrepareCannon0(?);
// extern ? CutscenePrepareCannon1(?);
// extern ? func_802944A8(?);
// extern ? func_80294538(?);
// extern ? CutsceneDeath80294574(?);
// extern ? CutsceneDeath802945E8(?);
// extern ? CutsceneDeath1(?);
// extern ? CutsceneDeath80294684(?);
// extern ? CutsceneDeath80294708(?);
// extern ? Unknown80294748(?);
// extern ? CutsceneDeath2(?);
// extern ? CutsceneBBHDeath802947E4(?);
// extern ? CutsceneBBHDeath80294868(?);
// extern ? CutsceneBBHDeath(?);
// extern ? CutsceneQuicksandDeath80294918(?);
// extern ? CutsceneQuicksandDeath80294954(?);
// extern ? CutsceneQuicksandDeath0(?);
// extern ? Cutscene1ATodo80294A70(?);
// extern ? Cutscene1ATodo80294B00(?);
// extern ? Cutscene1ATodo80294BB0(?);
// extern ? Cutscene1ATodo(?);
// extern ? CutsceneEnterPool80294CD0(?);
// extern ? CutsceneEnterPool80294D9C(?);
// extern ? CutsceneEnterPool0(?);
// extern ? Cutscene26Todo80294E40(?);
// extern ? Cutscene26Todo80294EAC(?);
// extern ? Cutscene26Todo80294ED8(?);
// extern ? Cutscene26Todo80294F40(?);
// extern ? Cutscene26Todo80295030(?);
// extern ? Cutscene26Todo80295100(?);
// extern ? Cutscene26Todo8029512C(?);
// extern ? Cutscene26Todo_1(?);
// extern ? Cutscene26Todo_2(?);
// extern ? CutsceneEnterPyramidTop80295294(?);
// extern ? CutsceneEnterPyramidTop0(?);
// extern ? Unknown8029538C(?);
// extern ? CutsceneDialog80295418(?);
// extern ? CutsceneDialog80295568(?);
// extern ? CutsceneDialog8029579C(?);
// extern ? CutsceneDialog0(?);
// extern ? CutsceneDialog1(?);
// extern ? CutsceneDialog2(?);
// extern ? CutsceneReadMessage80295998(?);
// extern ? Unknown80295A28(?);
// extern ? CutsceneReadMessage0(?);
// extern ? CutsceneReadMessage1(?);
// extern ? CutsceneReadMessage2(?);
// extern ? CutsceneExitSuccess80295C90(?);
// extern ? CutsceneExitSuccess80295D30(?);
// extern ? CutsceneExitSuccess80295EA4(?);
// extern ? CutsceneExitSuccess80295FD4(?);
// extern ? CutsceneExitBowserSuccess80296014(?);
// extern ? CutsceneExitSuccess8029605C(?);
// extern ? CutsceneExitBowserSuccess0(?);
// extern ? CutsceneExitNonPainting1(?);
// extern ? CutsceneBBHExitSuccess02961D4(?);
// extern ? CutsceneBBHExitSuccess0(?);
// extern ? CutsceneNonPaintingDeath802962D4(?);
// extern ? Cutscene1CTodo_0(?);
// extern ? CutsceneNonPaintingDeath802963DC(?);
// extern ? CutsceneNonPaintingDeath0(?);
// extern ? CutsceneCapSwitchPress80296540(?);
// extern ? CutsceneCapSwitchPress802965C4(?);
// extern ? CutsceneCapSwitchPress802966D8(?);
// extern ? CutsceneCapSwitchPress80296720(?);
// extern ? CutsceneCapSwitchPress8029682C(?);
// extern ? CutsceneCapSwitchPress802968B0(?);
// extern ? Unknown802968E8(?);
// extern ? CutsceneCapSwitchPress(?);
// extern ? CutsceneUnlockKeyDoor80296AC0(?);
// extern ? CutsceneUnlockKeyDoor80296B84(?);
// extern ? CutsceneUnlockKeyDoor80296C08(?);
// extern ? CutsceneUnlockKeyDoor80296C64(?);
// extern ? CutsceneUnlockKeyDoor80296C78(?);
// extern ? CutsceneUnlockKeyDoor80296CFC(?);
// extern ? CutsceneUnlockKeyDoor0(?);
// extern ? func_80296DDC(?);
// extern ? CutsceneIntroPeach80296ED8(?);
// extern ? CutsceneIntroPeach80296F04(?);
// extern ? CutsceneIntroPeach4(?);
// extern ? CutsceneIntroPeach80296FFC(?);
// extern ? CutsceneIntroPeach80297068(?);
// extern ? CutsceneIntroPeach80297088(?);
// extern ? CutsceneIntroPeach802970C4(?);
// extern ? CutsceneIntroPeach80297108(?);
// extern ? CutsceneIntroPeach80297134(?);
// extern ? CutsceneIntroPeach2(?);
// extern ? CutsceneIntroPeach3(?);
// extern ? CutsceneIntroPeach1(?);
// extern ? CutsceneIntroPeach0(?);
// extern ? CutsceneEndWaving8029743C(?);
// extern ? CutsceneEndWaving(?);
// extern ? CutsceneCredits802974F8(?);
// extern ? CutsceneCredits(?);
// extern ? CutsceneSlidingDoorsOpen802979C0(?);
// extern ? CutsceneSlidingDoors80297A80(?);
// extern ? CutsceneSlidingDoors80297AFC(?);
// extern ? CutsceneSlidingDoors80297B38(?);
// extern ? CutsceneSlidingDoors80297B74(?);
// extern ? CutsceneSlidingDoorsOpen0(?);
// extern ? CutsceneSlidingDoubleDoorsOpen1(?);
// extern ? CutsceneEnterPainting80297D84(?);
// extern ? CutsceneEnterPainting(?);
// extern ? CutsceneExitPainting80298094(?);
// extern ? CutsceneExitPainting80298230(?);
// extern ? CutsceneExitPainting802982CC(?);
// extern ? CutsceneExitPainting0(?);
// extern ? Cutscene11Todo_0(?);
// extern ? Cutscene11Todo_1(?);
// extern ? CutsceneExitPainting1(?);
// extern ? CutsceneEnterCannon2(?);
// extern ? CutsceneEnterCannon1(?);
// extern ? CutsceneEnterCannon0(?);
// extern ? CutsceneDoor0(?);
// extern ? CutsceneDoor1(?);
// extern ? CutsceneDoorWarp1(?);
// extern ? CutsceneDoor2(?);
// extern ? CutsceneDoor3(?);
// extern ? CutsceneDoor4(?);
// extern ? CutsceneDoorAB_2(?);
extern void func_80298DCC(struct Struct80280550 *); // postdefined
extern void func_80299BDC(CameraCommandProc, struct Struct80280550 *, s32, s32);
extern void func_80299C60(s16, s16);
extern void func_80299C98();
// extern ? func_80299D00(?);
// extern ? func_80299DB4(?);
// extern ? Unknown80299EA0(?);
// extern ? func_80299ECC(?);
// extern ? func_80299EF0(?);
// extern ? func_80299F30(?);
// extern ? func_80299F54(?);
// extern ? func_80299F78(?);
// extern ? func_80299FD8(?);
// extern ? Unknown8029A100(?);
// extern ? func_8029A13C(?);
// extern ? func_8029A178(?);
// extern ? func_8029A1B4(?);
// extern ? func_8029A24C(?);
// extern ? func_8029A288(?);
// extern ? Geo0A_8029AA3C(?);
extern void func_8029A478();
extern void func_8029A494(u32);
extern void func_8029A514(int, float, float, float);
// extern ? Unknown8029A664(?);
// extern ? Unknown8029A724(?);
// extern ? func_8029A7DC(?);
// extern ? func_8029A87C(?);
// extern ? BehBeginningPeachLoop(?);
// extern ? func_8029AB70(?);
// extern ? func_8029AC3C(?);
// extern ? func_8029ACAC(?);
// extern ? BehBeginningLakituLoop(?);
// extern ? BehEndBirds1Loop(?);
// extern ? BehEndBirds2Loop(?);
// extern ? func_8029B964(?);
// extern ? BehIntroSceneLoop(?);

#endif /* _CAMERA_H */
