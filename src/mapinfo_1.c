#include <ultra64.h>

#include "sm64.h"
#include "behavior_script.h"
#include "object_helpers.h"
#include "audio_interface_2.h"

extern void *beh_plays_sound;

struct UnkMapInfoStruct
{
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s32 soundMagic;
};

void PlaySound2(s32);

void func_802C9560(struct UnkMapInfoStruct *unkInfoStructs)
{
    int sp2C = gCurrentObject->oUnk178; // objectSoundState?

    switch(unkInfoStructs[sp2C].unk0)
    {
        case 0:
            break;
        case 1:
        {
            int temp;

            if((temp = unkInfoStructs[sp2C].unk2) >= 0)
                if(func_8029F88C(temp))
                    PlaySound2(unkInfoStructs[sp2C].soundMagic);

            if((temp = unkInfoStructs[sp2C].unk3) >= 0)
                if(func_8029F88C(temp))
                    PlaySound2(unkInfoStructs[sp2C].soundMagic);
        }
        break;
    }
}

void func_802C9664(u32 arg)
{
    struct Object *obj = SpawnObj(gCurrentObject, 0, &beh_plays_sound);

    obj->oSoundEffectUnkF4 = arg;
}

void PlaySound(s32 soundMagic)
{
    if(gCurrentObject->header.gfx.node.flags & 0x0001)
        SetSound(soundMagic, &gCurrentObject->header.gfx.unk54);
}

// duplicate function
void PlaySound2(s32 soundMagic)
{
    if(gCurrentObject->header.gfx.node.flags & 0x0001)
        SetSound(soundMagic, &gCurrentObject->header.gfx.unk54);
}

int Unknown802C9750(float arg0)
{
    int sp4;

    if (arg0 < 500.0f)
        sp4 = 127;
    else if (1500.0f < arg0)
        sp4 = 0;
    else
        sp4 = (((arg0 - 500.0f) / 1000.0f) * 64.0f) + 60.0f;

    return sp4;
}

int Unknown802C97F4(float arg0)
{
    int sp4;

    if(arg0 < 1300.0f)
        sp4 = 127;
    else if (2300.0f < arg0)
        sp4 = 0;
    else
        sp4 = (((arg0 - 1000.0f) / 1000.0f) * 64.0f) + 60.0f;

    return sp4;
}
