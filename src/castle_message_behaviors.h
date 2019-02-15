#ifndef _CASTLE_MESSAGE_BEHAVIORS_H
#define _CASTLE_MESSAGE_BEHAVIORS_H

#include "types.h"

#define TOAD_STAR_1_REQUIREMENT 12
#define TOAD_STAR_2_REQUIREMENT 25
#define TOAD_STAR_3_REQUIREMENT 35

#define TOAD_STAR_1_DIALOG 82
#define TOAD_STAR_2_DIALOG 76
#define TOAD_STAR_3_DIALOG 83

#define TOAD_STAR_1_DIALOG_AFTER 154
#define TOAD_STAR_2_DIALOG_AFTER 155
#define TOAD_STAR_3_DIALOG_AFTER 156


enum ToadMessageStates {
    TOAD_MESSAGE_FADED,
    TOAD_MESSAGE_OPAQUE,
    TOAD_MESSAGE_OPACIFYING,
    TOAD_MESSAGE_FADING,
    TOAD_MESSAGE_TALKING
};

enum UnlockDoorStarStates {
    UNLOCK_DOOR_STAR_RISING,
    UNLOCK_DOOR_STAR_WAITING,
    UNLOCK_DOOR_STAR_SPAWNING_PARTICLES,
    UNLOCK_DOOR_STAR_DONE
};

struct Struct802761D0
{
    u16 unk0;
    s16 unk2;
    u8 filler4[0x18-0x4];
};

struct Struct802763D4
{
    u8 filler0[0x18];
    s32 unk18;
    s32 unk1C;
};

struct Struct802763D4_Unknown
{
    u8 filler0[0x1C];
    float unk1C;
};

struct Struct802769E0
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0x18-0x4];
    s32 unk18;
};

struct Struct80277150
{
    struct GraphNode node;
    u8 filler14[0x4];
    float unk18;
    s16 unk1C;
    s16 unk1E;
};

struct Struct80277294
{
    struct GraphNode node;
    u8 filler14[0x4];
    s32 unk18;
};

struct Struct80277294_2
{
    struct GraphNode node;
    u8 filler14[4];
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
};

struct Struct802773A4
{
    struct GraphNode node;
    u8 filler14[0x4];
    s32 unk18;
};

struct Struct802773A4_2
{
    struct GraphNode node;
    u8 filler14[0x4];
    Vec3s unk18;
};

struct Struct802775CC
{
    struct GraphNode node;
    u8 filler14[4];
    s32 unk18;
};

struct Struct80277824
{
    struct GraphNode node;
    u8 filler14[4];
    u32 unk18;
};

struct Struct80277824_2
{
    struct GraphNode node;
    u8 filler14[4];
    s16 unk18;
};

struct Struct8027795C
{
    struct GraphNode node;
    u8 filler14[4];
    s32 unk18;
    struct Object *unk1C;
    Vec3s unk20;
};

struct Struct80277D6C
{
    struct GraphNode node;
    u8 filler14[4];
    s32 unk18;
};

struct Struct8033A040
{
    u32 unk0;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    u8 fillerA[1];
    u8 unkB;
    Vec3s unkC;
    Vec3s unk12;
    u8 filler18[0x28-0x18];
};

extern struct GraphNodeObject D_80339FE0;
extern struct Struct8033A040 D_8033A040[2]; 

extern Gfx *Geo18_802761D0(int a, struct GraphNode *b, float c[4][4]);
extern Gfx *Geo19_802763D4(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo18_802764B0(int a, struct GraphNode *b, Mat4 *c);
extern void beh_toad_message_loop(void);
extern void beh_toad_message_init(void);
extern void beh_unlock_door_star_init(void);
extern void beh_unlock_door_star_loop(void);
extern Gfx *Geo18_802770A4(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *GeoSwitchCase80277150(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *GeoSwitchCase802771BC(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo18_80277294(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo18_802773A4(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *GeoSwitchCase802774F4(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo18_802775CC(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *GeoSwitchCase802776D8(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *GeoSwitchCase80277740(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo18_80277824(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo1C_8027795C(int a, struct GraphNode *b, Mat4 *c);
extern Gfx *Geo18_80277B14(int a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *Geo18_80277D6C(int a, struct GraphNode *b, UNUSED Mat4 *c);

#endif /* _CASTLE_MESSAGE_BEHAVIOR_H */
