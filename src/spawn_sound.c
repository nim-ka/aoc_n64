#include <ultra64.h>

#include "sm64.h"
#include "behavior_script.h"
#include "object_helpers.h"
#include "audio/interface_2.h"
#include "spawn_sound.h"

extern void *beh_sound_spawner;

struct SoundState
{
    s16 playSound; // if this is 1, the info below will
                   // be used to determine the sound behavior
                   // for the object. if 0, this is skipped.
    s8 animFrame1; // the sound state provides 2 anim frames for
                   // when the provided sound can be played.
                   // these 2 variables probably coorespond to
                   // left/right foot.
    s8 animFrame2;
    s32 soundMagic;
};

/*
 * execute an object's current sound state with a provided array
 * of sound states. Used for the stepping sounds of various
 * objects. (King Bobomb, Bowser, King Whomp)
 */
void exec_anim_sound_state(struct SoundState *soundStates)
{
    int stateIdx = gCurrentObject->oSoundStateID;

    switch(soundStates[stateIdx].playSound)
    {
        // since we have an array of sound states cooresponding to
        // various behaviors, not all entries intend to play sounds. the
        // boolean being 0 for unused entries skips these states.
        case FALSE:
            break;
        case TRUE:
        {
            int animFrame;

            // in the sound state information, -1 (0xFF) is for empty
            // animFrame entries. These checks skips them.
            if((animFrame = soundStates[stateIdx].animFrame1) >= 0)
                if(check_anim_frame(animFrame))
                    PlaySound2(soundStates[stateIdx].soundMagic);

            if((animFrame = soundStates[stateIdx].animFrame2) >= 0)
                if(check_anim_frame(animFrame))
                    PlaySound2(soundStates[stateIdx].soundMagic);
        }
        break;
    }
}

/*
 * Create a sound spawner for objects that need a sound play once.
 * (Breakable walls, King Bobomb exploding, etc)
 */
void create_sound_spawner(s32 soundMagic)
{
    struct Object *obj = SpawnObj(gCurrentObject, 0, &beh_sound_spawner);

    obj->oSoundEffectUnkF4 = soundMagic;
}

/*
 * The following 2 functions are relevent to the sound state function
 * above. While only PlaySound2 is used, they may have been intended as
 * seperate left/right leg functions that went unused.
 */
void PlaySound(s32 soundMagic)
{
    if(gCurrentObject->header.gfx.node.flags & 0x0001)
        SetSound(soundMagic, &gCurrentObject->header.gfx.unk54);
}

// duplicate function, but its the used one
void PlaySound2(s32 soundMagic)
{
    if(gCurrentObject->header.gfx.node.flags & 0x0001)
        SetSound(soundMagic, &gCurrentObject->header.gfx.unk54);
}

/*
 * These 2 functions below are completely unreferenced in all versions
 * of Super Mario 64. They are likely functions which facilitated
 * calculation of distance of an object to volume, since these are
 * common implementations of such a concept, and the fact they are
 * adjacent to other sound functions. The fact there are 2 functions
 * might show that the developers were testing several ranges, or certain
 * objects had different ranges, or had these for other unknown purposes.
 * Technically, these functions are only educated guesses. Trust these
 * interpretations at your own discrection.
 */
int calc_dist_to_volume_range_1(float distance) // range from 60-124
{
    int volume;

    if (distance < 500.0f)
        volume = 127;
    else if (1500.0f < distance)
        volume = 0;
    else
        volume = (((distance - 500.0f) / 1000.0f) * 64.0f) + 60.0f;

    return volume;
}

int calc_dist_to_volume_range_2(float distance) // range from 79.2-143.2
{
    int volume;

    if (distance < 1300.0f)
        volume = 127;
    else if (2300.0f < distance)
        volume = 0;
    else
        volume = (((distance - 1000.0f) / 1000.0f) * 64.0f) + 60.0f;

    return volume;
}
