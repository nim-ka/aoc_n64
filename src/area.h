#ifndef _AREA_H
#define _AREA_H

#include "types.h"

enum CourseNum
{
    COURSE_NONE,                       // (0)  Overworld (Castle Grounds, etc)
    COURSE_MIN,
    /* -------------- Main Courses -------------- */
    COURSE_STAGES_MIN = COURSE_MIN,
    COURSE_BOB = COURSE_STAGES_MIN,    // (1)  Bob Omb Battlefield
    COURSE_WF,                         // (2)  Whomp's Fortress
    COURSE_JRB,                        // (3)  Jolly Rodger's Bay
    COURSE_CCM,                        // (4)  Cool Cool Mountain
    COURSE_BBH,                        // (5)  Big Boo's Haunt
    COURSE_HMC,                        // (6)  Hazy Maze Cave
    COURSE_LLL,                        // (7)  Lethal Lava Land
    COURSE_SSL,                        // (8)  Shifting Sand Land
    COURSE_DDD,                        // (9)  Dire Dire Docks
    COURSE_SL,                         // (10) Snowman's Land
    COURSE_WDW,                        // (11) Wet Dry World
    COURSE_TTM,                        // (12) Tall Tall Mountain
    COURSE_THI,                        // (13) Tiny Huge Island
    COURSE_TTC,                        // (14) Tick Tock Clock
    COURSE_RR,                         // (15) Rainbow Ride
    COURSE_STAGES_MAX = COURSE_RR,
    /* -------------- Bonus Courses -------------- */
    COURSE_BITDW,                      // (16) Bowser in the Dark World
    COURSE_BITFS,                      // (17) Bowser in the Fire Sea
    COURSE_BITS,                       // (18) Bowser in the Sky
    COURSE_PSS,                        // (19) Princess's Secret Slide
    COURSE_CAP_COURSES,
    COURSE_COTMC = COURSE_CAP_COURSES, // (20) Cavern of the Metal Cap
    COURSE_TOTWC,                      // (21) Tower of the Wing Cap
    COURSE_VCUTM,                      // (22) Vanish Cap Under the Moat
    COURSE_WMOTR,                      // (23) Winged Mario over the Rainbow
    COURSE_SA,                         // (24) Secret Aquarium
    COURSE_CAKE_END,                   // (25) The End (Cake Scene)
    COURSE_MAX = COURSE_CAKE_END
};

enum LevelNum
{
    LEVEL_NONE,                  // not indexed
    LEVEL_MIN,
    LEVEL_UNKNOWN_1 = LEVEL_MIN, // (1)  ""
    LEVEL_UNKNOWN_2,             // (2)  ""
    LEVEL_UNKNOWN_3,             // (3)  ""
    LEVEL_BBH,                   // (4)  "TERESA OBAKE"   Big Boo's Haunt
    LEVEL_CCM,                   // (5)  "YYAMA1 % YSLD1" Cool Cool Mountain
    LEVEL_CASTLE,                // (6)  "SELECT ROOM"    Castle lobby
    LEVEL_HMC,                   // (7)  "HORROR DUNGEON" Hazy Maze Cave
    LEVEL_SSL,                   // (8)  "SABAKU % PYRMD" Shifting Sand Land
    LEVEL_BOB,                   // (9)  "BATTLE FIELD"   Bob Omb Battlefield
    LEVEL_SL,                    // (10) "YUKIYAMA2"      Snowman's Land
    LEVEL_WDW,                   // (11) "POOL KAI"       Wet Dry World
    LEVEL_JRB,                   // (12) "WTDG % TINBOTU" Jolly Rodger's Bay
    LEVEL_THI,                   // (13) "BIG WORLD"      Tiny Huge Island
    LEVEL_TTC,                   // (14) "CLOCK TOWER"    Tick Tock Clock
    LEVEL_RR,                    // (15) "RAINBOW CRUISE" Rainbow Ride
    LEVEL_CASTLE_GROUNDS,        // (16) "MAIN MAP"       Castle grounds (outside)
    LEVEL_BITDW,                 // (17) "EXT1 YOKO SCRL" Bowser in the Dark World
    LEVEL_VCUTM,                 // (18) "EXT7 HORI MINI" Vanish Cap under the Moat
    LEVEL_BITFS,                 // (19) "EXT2 TIKA LAVA" Bowser in the Fire Sea
    LEVEL_SA,                    // (20) "EXT9 SUISOU"    Secret Aquarium
    LEVEL_BITS,                  // (21) "EXT3 HEAVEN"    Bowser in the Sky
    LEVEL_LLL,                   // (22) "FIREB1 % INVLC" Lethal Lava Land
    LEVEL_DDD,                   // (23) "WATER LAND"     Dire Dire Docks
    LEVEL_WF,                    // (24) "MOUNTAIN"       Whomp's Fortress
    LEVEL_ENDING,                // (25) "ENDING"         (Ending Cutscene)
    LEVEL_CASTLE_COURTYARD,      // (26) "URANIWA"        Castle courtyard (BBH entrance)
    LEVEL_PSS,                   // (27) "EXT4 MINI SLID" Princess's Secret Slide
    LEVEL_COTMC,                 // (28) "IN THE FALL"    Cavern of the Metal Cap
    LEVEL_TOTWC,                 // (29) "EXT6 MARIO FLY" Tower of the Wing Cap
    LEVEL_BOWSER_1,              // (30) "KUPPA1"         Bowser in the Dark World (Boss)
    LEVEL_WMOTR,                 // (31) "EXT8 BLUE SKY"  Winged Mario over the Rainbow
    LEVEL_UNKNOWN_32,            // (32) ""
    LEVEL_BOWSER_2,              // (33) "KUPPA2"         Bowser in the Fire Sea (Boss)
    LEVEL_BOWSER_3,              // (34) "KUPPA3"         Bowser in the Sky (Final Boss)
    LEVEL_UNKNOWN_35,            // (35) ""
    LEVEL_TTM,                   // (36) "DONKEY % SLID2" Tall Tall Mountain
    LEVEL_UNKNOWN_37,            // (37) ""
    LEVEL_UNKNOWN_38,            // (38) ""
    LEVEL_MAX = LEVEL_UNKNOWN_38
};

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
    u8 unk64;
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
extern struct GraphNode *D_8033A160[];
extern struct Area gAreaData[];
extern u8 D_8033A740;
extern u8 D_8033A740;
extern u8 D_8033A741;
extern u8 D_8033A742;
extern u8 D_8033A743;
extern s8 D_8033A744;
extern s8 D_8033A745;
extern s8 D_8033A746;
extern s16 D_8033A748;
extern s16 D_8033A74A;
extern s16 D_8033A74C;
extern s16 D_8033A74E;
extern s16 D_8033A750;
extern s16 D_8033A752;
extern s16 D_8033A754;
extern s16 gCurrCourseNum;
extern s16 D_8033A758;
extern s16 gCurrAreaIndex;
extern s16 D_8033A75C;
extern s16 D_8033A75E;
extern s16 D_8033A760;

extern struct SpawnInfo *gMarioSpawnInfo;

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
