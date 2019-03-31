#ifndef _CAMERA_H
#define _CAMERA_H

#include "types.h"
#include "area.h"
#include "engine/geo_layout.h"

#define ABS(x) ((x) > 0.f ? (x) : -(x))
#define ABS2(x) ((x) >= 0.f ? (x) : -(x))

// sorted

struct Struct8033B1B0
{
    /*0x00*/ u32 unk0;
    /*0x04*/ Vec3f unk4;
    /*0x10*/ Vec3s unk10;
    /*0x16*/ Vec3s unk16;
    /*0x1C*/ s16 unk1C[2];
    /*0x20*/ struct Object *unk20;
};

struct Struct8033B250
{
    /*0x00*/ s16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ f32 unk4;
    /*0x08*/ s16 unk8;
    /*0x0A*/ s16 unkA;
    /*0x0C*/ f32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ Vec3f unk14;
    /*0x20*/ u8 pad; // for the structs to align, there has to be an extra unused variable here. type is unknown.
};

struct Struct8033B2B8
{
    /*0x00*/ s8 unk0;
    union {
        /*0x08*/ Vec3s unk8;
        /*0x08*/ long long int force_structure_alignment;
    } myUnion;
}; // size = 0x10

// unsorted

struct Struct80287404
{
    u8 filler0[0x18];
    s32 unk18;
    Vec3f unk1C;
    Vec3f unk28;
    u8 filler34[0x3A-0x34];
    s16 unk3A;
};

typedef void (*CameraCommandProc)(struct LevelCamera *a);

struct Struct8032CA78
{
    s8 unk0;
    CameraCommandProc unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
};

struct CutsceneTableEntry
{
    CameraCommandProc unk0;
    s16 unk4;
};

struct Struct8033B230
{
    /*0x00*/ u8 unk0;
    /*0x04*/ f32 fieldOfView;
    /*0x08*/ f32 unk8;
    /*0x0C*/ u32 unkC;
    /*0x10*/ f32 unk10;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18;
};

struct Struct8032E040
{
    /*0x00*/ s8 unk0;
    /*0x01*/ u8 unk1;
    /*0x02*/ Vec3s unk2;
}; // size = 0x08

struct Struct8033B278
{
    struct Surface *unk0;
    f32 unk4;
    s16 unk8;
    struct Surface *unkC;
    s16 unk10;
    f32 unk14;
    struct Surface *unk18;
    f32 unk1C;
    s16 unk20;
    struct Surface *unk24;
    f32 unk28;
    s16 unk2C;
    f32 unk30;
};

struct Struct8033B418_sub
{
    Vec3f unk0;
    Vec3f unkC;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
};

struct Struct8033B418
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    struct Struct8033B418_sub unk8;
    struct Struct8033B418_sub unk28;
};

struct Struct8033B470
{
    s16 unk0;
    Vec3f unk4;
    f32 unk10;
    f32 unk14;
};

struct Struct8033B4B8
{
    /*0x00*/ Vec3f unk0;
    /*0x0C*/ Vec3f unkC;
    /*0x18*/ f32 unk18;
    /*0x1C*/ f32 unk1C;
};

struct Struct8033B6F0
{
    s32 unk0;
    Vec3f unk4;
    Vec3f unk10;
    Vec3s unk1C;
    s16 unk22;
};

struct Struct8033B328
{
    Vec3f unk0[4];
    u8 filler30[12]; // extra unused Vec3f?
    u8 unk3C;
    u8 unk3D;
    u8 filler3E[10];
    float unk48;
    s16 unk4C;
    s16 unk4E;
    u8 filler50[2];
    Vec3s unk52;
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    u8 filler5E[2];
    Vec3f unk60;
    Vec3s unk6C;
    u8 filler72[8];
    s16 unk7A;
    s16 unk7C;
    s16 unk7E;
    //u8 unk7A[0x80-0x7A];  // unknown type
    Vec3f unk80;
    Vec3f unk8C;
    s16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    float unkA4;
    float unkA8;
    float unkAC;
    float unkB0;
};

// bss order hack to not affect BSS order. if possible, remove me, but it will be hard to match otherwise
#ifndef INCLUDED_FROM_CAMERA_C
// BSS
extern struct Struct8033B1B0 D_8033B1B0[2];
extern s16 D_8033B314;
extern s16 D_8033B318;
extern s16 D_8033B31C;
extern u16 D_8033B31E;
extern struct Struct8033B328 D_8033B328;
extern s16 D_8033B4D8;
extern s32 D_8033B858;
extern struct LevelCamera *gCurrLevelCamera;
#endif

extern struct Object *D_8032CFC4;
extern struct Object *D_8032CFD0;

// TODO: sort all of this extremely messy shit out after the split
// TODO: bring in some externs from camera.c

extern Vec3f D_8032D00C;
extern u8 D_8032D0B8[];

extern void func_8027EFE0(s16);
extern void func_8027F308(s16);
extern void func_8027F440(s16, f32, f32, f32);
extern void func_802852F4(struct LevelCamera *); // static (ASM)
extern void func_80285A8C(UNUSED struct LevelCamera *, s16);
extern void func_80285BD8(struct LevelCamera *, s16, s16);
extern void func_80286348(struct LevelCamera *);
extern void func_802869B8(struct LevelCamera *);
extern void func_80286C9C(struct LevelCamera *);
extern void func_802875DC(void);
extern void dummy_802877D8(struct LevelCamera *);
extern void dummy_802877EC(struct LevelCamera *);
extern void vec3f_sub(Vec3f, Vec3f);
extern void object_pos_to_vec3f(Vec3f, struct Object *);
extern void vec3f_to_object_pos(struct Object *, Vec3f); // static (ASM)
extern s32 func_80287CFC(Vec3f, struct Struct8032E040[], s16 *, f32 *);
extern s32 func_8028803C(s32);
extern s32 func_80288130(s32);
extern void func_802882A0(u8);
extern void func_802883C8(Vec3f, Vec3f);
extern s32 func_802886FC(u16, u16, u16);
extern s32 update_camera_status(struct LevelCamera *);
extern s32 func_80288974(Vec3f, f32, f32);
extern s32 func_80288C2C(Vec3f a, Vec3f b, s16 c, s16 d);
extern s32 func_80288CF0(f32, f32, f32);
extern s32 func_80288D74(f32 *, f32, f32);
extern s32 approach_f32_exponential(f32 *, f32, f32);
extern f32 approach_f32_exponential_2(f32, f32, f32); // static (ASM)
extern s32 approach_s16_exponential(s16 *, s16, s16);
extern s32 approach_s16_exponential_2(s16, s16, s16); // static (ASM)
extern void approach_vec3f_exponential(Vec3f, Vec3f, f32, f32, f32); // static (ASM)




extern void func_8028909C(Vec3f, Vec3f, f32, f32, f32); // postdefined
// extern ? approach_vec3s_exponential(?);
extern s32 func_80289184(s16 *a, s16 b, s16 c);
// extern ? func_80289264(?);
extern s32 func_80289354(s16 *a, s16 b, s16 c); // postdefined
extern s32 func_802893E4(f32 *, f32, f32);
extern f32 func_80289524(f32, f32, f32);
void func_80289618(Vec3s a, s16 b, s16 c, s16 d); // postdefined
// extern ? func_80289738(?);
extern s32 func_802899A0(Vec3f, Vec3f, f32, f32, f32, f32);
// extern ? func_80289A98(?);
// extern ? func_80289B0C(?);
// extern ? func_80289F04(?);
extern s32 func_8028A0D4(Vec3f a, Vec3f b, struct Surface *c, s16 d, s16 e);
// extern ? func_8028A204(?);
extern void func_8028A24C(Vec3f, Vec3f, Vec3f, f32);
// extern ? func_8028A300(?);
extern s16 func_8028A440(Vec3f, Vec3f);
extern s16 func_8028A4F0(Vec3f, Vec3f);
extern void func_8028A578(Vec3f, Vec3f, s16 *, s16 *);
extern f32 func_8028A640(Vec3f, Vec3f);
extern f32 func_8028A6E4(Vec3f, Vec3f);
extern void func_8028A764(Vec3f, Vec3f, s16);
extern void func_8028A834(Vec3f, Vec3f, s16);
extern void func_8028A908(s16, s16, s16);
extern void func_8028A964(s16, s16, s16);
extern void func_8028AA24(s16, s16, s16);
extern void func_8028AA80(s16, s16, s16, f32, f32, f32, f32);
// extern ? Unknown8028AB34(?);
// extern ? func_8028ABE8(?);
extern void func_8028AC30(); // postdefined
extern void func_8028AD44(); // postdefined
extern void func_8028AE50(s16 *); // postdefined
extern s32 func_8028AF24(struct LevelCamera *a, s16 b);
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
extern s32 func_8028B3DC(struct LevelCamera *a, f32 b);
extern s32 StopMario(s32);
extern void func_8028B7A4(struct LevelCamera *);
// extern ? func_8028BA38(?);
extern void func_8028BB3C(struct LevelCamera *a, u8 b); // postdefined
// extern ? func_8028BB8C(?);
// extern ? func_8028BC6C(?);
extern u8 func_8028BCC8(); // postdefined
extern void func_8028C1A0(f32, f32, f32);
extern void func_8028C2F0(struct LevelCamera *, f32, f32);
// extern ? Unknown8028C3AC(?);
// extern ? func_8028C3CC(?);
// extern ? Unknown8028C508(?);
extern void func_8028C5F0(Vec3f, Vec3f, Vec3f, Vec3s);
// extern ? func_8028C794(?);
// extern ? func_8028C7EC(?);
s32 func_8028C824(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f, s16 g); // postdefined
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
extern s16 func_8028E88C(struct LevelCamera *); // postdefined
extern void func_8028F04C(Vec3f, Vec3f);
extern s32 func_8028F2F0(struct LevelCamera *, Vec3f, s16 *, s16);
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
// extern ? CutsceneIntroPeach0_2(?);
// extern ? CutsceneIntroPeach2_1(?);
// extern ? func_8028FEDC(?);
// extern ? func_8028FEFC(?);
// extern ? func_80290144(?);
// extern ? func_802901B4(?);
// extern ? func_80290224(?);
// extern ? func_802902A8(?);
// extern ? unused_vec3s_to_vec3f(?);
// extern ? unused_vec3f_to_vec3s(?);
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
// extern ? CutsceneFallCommon1(?);
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
// extern ? CutsceneExitSuccess1(?);
// extern ? CutsceneExitSuccess2(?);
// extern ? CutsceneExitSuccess4(?);
// extern ? CutsceneExitSuccess3(?);
// extern ? CutsceneExitBowserSuccess80296014(?);
// extern ? CutsceneExitSuccess5(?);
// extern ? CutsceneExitBowserSuccess0(?);
// extern ? CutsceneExitNonPainting1(?);
// extern ? CutsceneBBHExitSuccess02961D4(?);
// extern ? CutsceneBBHExitSuccess0(?);
// extern ? CutsceneNonPaintingDeath0_1(?);
// extern ? Cutscene1CTodo_0(?);
// extern ? CutsceneNonPaintingDeath0_2(?);
// extern ? CutsceneNonPaintingDeath0(?);
// extern ? CutsceneCapSwitchPress0_1(?);
// extern ? CutsceneCapSwitchPress0_4(?);
// extern ? CutsceneCapSwitchPress0_5(?);
// extern ? CutsceneCapSwitchPress0_2(?);
// extern ? CutsceneCapSwitchPress0_3(?);
// extern ? CutsceneCapSwitchPress0_6(?);
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
// extern ? CutsceneIntroPeach0_3(?);
// extern ? CutsceneIntroPeachCommon(?);
// extern ? CutsceneIntroPeach4(?);
// extern ? CutsceneIntroPeach3_2(?);
// extern ? CutsceneIntroPeach2_2(?);
// extern ? CutsceneIntroPeach0_1(?);
// extern ? CutsceneIntroPeach3_1(?);
// extern ? CutsceneIntroPeach3_3(?);
// extern ? CutsceneIntroPeach3_4(?);
// extern ? CutsceneIntroPeach2(?);
// extern ? CutsceneIntroPeach3(?);
// extern ? CutsceneIntroPeach1(?);
// extern ? CutsceneIntroPeach0(?);
// extern ? CutsceneEndWaving0_1(?);
// extern ? CutsceneEndWaving0(?);
// extern ? CutsceneCredits0_1(?);
// extern ? CutsceneCredits0(?);
// extern ? CutsceneSlidingDoorsOpen0_1(?);
// extern ? CutsceneSlidingDoorsOpen0_2(?);
// extern ? CutsceneSlidingDoorsOpen0_3(?);
// extern ? CutsceneSlidingDoorsOpen0_4(?);
// extern ? CutsceneSlidingDoorsOpen0_5(?);
// extern ? CutsceneSlidingDoorsOpen0(?);
// extern ? CutsceneDoubleDoorsOpen1(?);
// extern ? CutsceneEnterPainting0_1(?);
// extern ? CutsceneEnterPainting0(?);
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
extern void handle_cutscenes(struct LevelCamera *);
extern s32 call_cutscene_func_in_time_range(CameraCommandProc, struct LevelCamera *, s16, s16);
extern s32 func_80299C60(s32, s16);
extern void func_80299C98(s16, s16, s16);
// extern ? func_80299D00(?);

extern void func_8029A478(u8);
extern void func_8029A494(u8);
extern void func_8029A514(u8, f32, f32, f32);
// extern ? Unknown8029A664(?);
// extern ? Unknown8029A724(?);
extern void func_8029A7DC(struct Object *, Vec3f, s16, s16, s16, s16);
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
