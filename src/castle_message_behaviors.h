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

struct Struct8033B328
{
    Vec3f unk0[6];
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
    u8 filler7C[4];
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

extern struct Struct8033B328 D_8033B328;
// extern ? D_8032CE0C;
// extern ? D_80385FE4;
// extern ? D_80339FE0;
// extern ? D_80339FF4;
// extern ? D_80339FF8;
// extern ? D_8033A040;

// extern ? Geo18_802761D0(?);
// extern ? Geo19_802763D4(?);
// extern ? Geo18_802764B0(?);
// extern ? BehToadMessageFaded(?);
// extern ? BehToadMessageOpaque(?);
// extern ? BehToadMessageTalking(?);
// extern ? BehToadMessageOpacifying(?);
// extern ? BehToadMessageFading(?);
// extern ? BehToadMessageLoop(?);
// extern ? BehToadMessageInit(?);
// extern ? func_802764F0(?);
// extern ? BehSealedDoorStarInit(?);
// extern ? BehSealedDoorStarLoop(?);
// extern ? func_802769E0(?);
// extern ? Geo18_802770A4(?);
// extern ? GeoSwitchCase80277150(?);
// extern ? GeoSwitchCase802771BC(?);
// extern ? Geo18_80277294(?);
// extern ? Geo18_802773A4(?);
// extern ? GeoSwitchCase802774F4(?);
// extern ? Geo18_802775CC(?);
// extern ? GeoSwitchCase802776D8(?);
// extern ? GeoSwitchCase80277740(?);
// extern ? Geo18_80277824(?);
// extern ? Geo1C_8027795C(?);
// extern ? Geo18_80277B14(?);
// extern ? Geo18_80277D6C(?);

#endif /* _CASTLE_MESSAGE_BEHAVIOR_H */
