#ifndef _AREA_H
#define _AREA_H


struct WarpNode
{
    /*00*/ u8 id;
    /*01*/ u8 destLevel;
    /*02*/ u8 destArea;
    /*03*/ u8 destNode;
};

struct ObjectWarpNode
{
    /*0x00*/ struct WarpNode node;
    /*0x04*/ struct Object *object;
    /*0x08*/ struct ObjectWarpNode *next;
};

struct InstantWarp
{
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 area;
    /*0x02*/ Vec3s displacement;
};

struct SpawnInfo
{
    /*0x00*/ Vec3s startPos;
    /*0x06*/ Vec3s startAngle;
    /*0x0C*/ s8 areaIndex;
    /*0x0D*/ s8 unk0D;
    /*0x10*/ u32 behaviorArg;
    /*0x14*/ void *behaviorScript;
    /*0x18*/ struct GraphNode *unk18;
    /*0x1C*/ struct SpawnInfo *next;
};

// camera related
struct Struct80280550
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
    Vec3f unk4;
    Vec3f unk10;
    u8 filler1C[0x28-0x1C];
    float unk28;
    float unk2C;
    u8 unk30;
    u8 filler31[0x9];
    s16 unk3A;
    u8 filler3C[0x64-0x3C];
    s8 unk64;
    u8 filler65[3];
    float unk68;
};

struct UnknownArea28
{
    /*0x00*/ s16 unk00;
    /*0x02*/ s16 unk02;
    /*0x04*/ s16 unk04;
    /*0x06*/ s16 unk06;
    /*0x08*/ s16 unk08;
};

struct Whirlpool
{
    /*0x00*/ Vec3s pos;
    /*0x03*/ s16 strength;
};

struct Area
{
    /*0x00*/ s8 index;
    /*0x01*/ s8 unk01;
    /*0x02*/ u16 unk02;
    /*0x04*/ struct GraphNode *unk04;
    /*0x08*/ s16 *terrainData;
    /*0x0C*/ s8 *surfaceRooms;
    /*0x10*/ s16 *unk10;
    /*0x14*/ struct ObjectWarpNode *warpNodes;
    /*0x18*/ struct WarpNode *paintingWarpNodes;
    /*0x1C*/ struct InstantWarp *instantWarps;
    /*0x20*/ struct SpawnInfo *objectSpawnInfos;
    /*0x24*/ struct Struct80280550 *unk24;
    /*0x28*/ struct UnknownArea28 *unk28;
    /*0x2C*/ struct Whirlpool *whirlpools[2];
    /*0x34*/ u8 unk34[1];
    /*0x35*/ u8 unk35;
    /*0x36*/ u16 unk36;
    /*0x38*/ u16 unk38;
};


extern struct SpawnInfo gPlayerSpawnInfos[];
extern u8 D_8033A740;
extern struct SpawnInfo *gMarioSpawnInfo;

extern s16 gCurrCourseNum;
extern s16 D_8033A758;
extern s16 gCurrAreaIndex;
extern s16 D_8033A75C;
extern s16 D_8033A75E;

extern struct Area gAreaData[];
extern struct Area *gAreas;
extern struct Area *gCurrentArea;

extern s16 gCurrSaveFileNum;
extern s16 gCurrLevelNum;


void func_8027A220(Vp *a, Vp *b, u8 c, u8 d, u8 e);
void print_intro_text(void);
u32 get_mario_spawn_type(struct Object *o);
struct ObjectWarpNode *area_get_warp_node(u8 id);
void clear_areas(void);
void func_8027A7C4(void);
void load_area(s32 index);
void func_8027A998(void);
void load_mario_area(void);
void func_8027AA88(void);
void change_area(s32 index);
void area_update_objects(void);
void func_8027ABF0(s16 a, s16 b, u8 c, u8 d, u8 e);
void func_8027ADAC(s16 a, s16 b, u8 c, u8 d, u8 e, s16 f);
void render_game(void);


#endif
