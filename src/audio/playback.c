#include <ultra64.h>
#include <macros.h>

#include "memory.h"
#include "data.h"
#include "seqplayer.h"
#include "playback.h"
#include "synthesis.h"
#include "effects.h"

s32 func_80319660(struct Note *arg0, struct SequenceChannelLayer *arg1);

void func_80318870(struct Note *note)
{
    if (note->parentLayer->adsr.releaseRate == 0)
    {
        adsr_init(&note->adsr, note->parentLayer->seqChannel->adsr.envelope, &note->unk8);
    }
    else
    {
        adsr_init(&note->adsr, note->parentLayer->adsr.envelope, &note->unk8);
    }
    note->adsr.state = ADSR_STATE_INITIAL;
    note_init(note);
    func_80315D94(note);
}

void func_803188E8(struct Note *note)
{
    func_80315DE0(note);
}

void func_80318908(void)
{
    f32 f2;
    f32 frequency;
    u8 reverb;
    f32 velocity;
    f32 pan;
    f32 cap;
    struct Note *note;
    struct SequenceChannelLayer_2 *temp_v0;
    struct NoteListItem *it;
    s32 i;

    // Macro versions of func_80319564 and func_803195A4
    // (PREPEND does not actually need to be a macro, but it seems likely.)
#define PREPEND(item, head_arg) \
    ((it = (item), it->prev != NULL) ? it : ( \
        it->prev = (head_arg), \
        it->next = (head_arg)->next, \
        (head_arg)->next->prev = it, \
        (head_arg)->next = it, \
        (head_arg)->u.count++, \
        it->head = (head_arg)->head, \
        it))
#define POP(item) \
    ((it = (item), it->prev == NULL) ? it : ( \
        it->prev->next = it->next, \
        it->next->prev = it->prev, \
        it->prev = NULL, \
        it))

    for (i = 0; i < gNoteCount; i++)
    {
        note = &gNotes[i];
        if (note->unk4 != 0)
        {
            if (note->unk4 == 1 || note->unk0b10)
            {
                if (note->unk8 == 0 || note->unk0b10)
                {
                    if (note->unk30 != NO_LAYER)
                    {
                        func_803188E8(note);
                        if (note->unk30->seqChannel != 0)
                        {
                            if (func_80319660(note, note->unk30) == 1)
                            {
                                func_803188E8(note);
                                POP(&note->noteListItem);
                                PREPEND(&note->noteListItem, &D_80225EA8[0]);
                            }
                            else
                            {
                                note_vibrato_init(note);
                                note_list_item_add(&note->noteListItem.head[3], POP(&note->noteListItem));
                                note->unk30 = NO_LAYER;
                            }
                        }
                        else
                        {
                            func_803188E8(note);
                            note_list_item_add(&note->noteListItem.head[0], POP(&note->noteListItem));
                            note->unk30 = NO_LAYER;
                            continue;
                        }
                    }
                    else
                    {
                        func_803188E8(note);
                        note_list_item_add(&note->noteListItem.head[0], POP(&note->noteListItem));
                        continue;
                    }
                }
            }
            else
            {
                if (note->adsr.state == ADSR_STATE_DISABLED)
                {
                    func_803188E8(note);
                    note_list_item_add(&note->noteListItem.head[0], POP(&note->noteListItem));
                    continue;
                }
            }

            adsr_update(&note->adsr);
            note_vibrato_update(note);
            temp_v0 = &note->unk44;
            if (note->unk4 == 1)
            {
                frequency = temp_v0->freqScale;
                velocity = temp_v0->velocity;
                pan = temp_v0->pan;
                reverb = temp_v0->reverb;
            }
            else
            {
                frequency = note->parentLayer->noteFreqScale;
                velocity = note->parentLayer->noteVelocity;
                pan = note->parentLayer->notePan;
                reverb = note->parentLayer->seqChannel->reverb;
            }

            f2 = note->unk8;
            frequency *= note->vibratoFreqScale * note->portamentoFreqScale;
            cap = 3.99992f;
            if (gAiFrequency != 32006)
            {
                frequency *= US_FLOAT(32000.0) / (f32) gAiFrequency;
            }
            frequency = (frequency < cap ? frequency : cap);
            f2 *= 4.3498e-5f; // ~1 / 23000
            velocity = velocity * f2 * f2;
            note_set_frequency(note, frequency);
            func_803159EC(note, velocity, pan, reverb);
            continue;
        }
    }
#undef PREPEND
#undef POP
}

void seq_channel_layer_init(struct SequenceChannelLayer *seqLayer, s32 arg1)
{
    struct Note *note;
    struct SequenceChannelLayer_2 *sub;

    if (seqLayer == NO_LAYER || seqLayer->note == NULL)
    {
        return;
    }

    note = seqLayer->note;
    sub = &note->unk44;

    if (seqLayer->seqChannel != 0 && seqLayer->seqChannel->someMask == 0)
    {
        seqLayer->note = NULL;
    }

    if (note->unk30 == seqLayer)
    {
        note->unk30 = NO_LAYER;
    }

    if (note->parentLayer != seqLayer)
    {
        return;
    }

    seqLayer->unk1 = 0;
    if (note->adsr.state != ADSR_STATE_DECAY)
    {
        sub->freqScale = seqLayer->noteFreqScale;
        sub->velocity = seqLayer->noteVelocity;
        sub->pan = seqLayer->notePan;
        if (seqLayer->seqChannel != NULL)
        {
            sub->reverb = seqLayer->seqChannel->reverb;
        }
        note->unk4 = 1;
        note->unk28 = note->parentLayer;
        note->parentLayer = NO_LAYER;
        if (arg1 == 7)
        {
            note->adsr.fadeOutVel = 0x8000 / gAudioUpdatesPerFrame;
            note->adsr.action |= ADSR_ACTION_RELEASE;
        }
        else
        {
            note->adsr.action |= ADSR_ACTION_DECAY;
            if (seqLayer->adsr.releaseRate == 0)
            {
                note->adsr.fadeOutVel = seqLayer->seqChannel->adsr.releaseRate * 24;
            }
            else
            {
                note->adsr.fadeOutVel = seqLayer->adsr.releaseRate * 24;
            }
            note->adsr.sustain = (note->adsr.current * seqLayer->seqChannel->adsr.sustain) / 0x10000;
        }
    }

    if (arg1 == 6)
    {
        func_803195A4(&note->noteListItem);
        func_80319564(&note->noteListItem.head[1], &note->noteListItem);
    }
}

void seq_channel_layer_init_6(struct SequenceChannelLayer *seqLayer)
{
    seq_channel_layer_init(seqLayer, 6);
}

void seq_channel_layer_init_7(struct SequenceChannelLayer *seqLayer)
{
    seq_channel_layer_init(seqLayer, 7);
}

// wave synthesizer
void func_80318F04(struct Note *note, struct SequenceChannelLayer *seqLayer)
{
    s32 i;
    s32 j;
    s32 pos;
    s32 stepSize;
    s32 offset;
    u8 lim;
    u8 origSampleCount = note->sampleCount;

    if (seqLayer->freqScale < US_FLOAT(1.0))
    {
        note->sampleCount = 64;
        seqLayer->freqScale *= US_FLOAT(1.0465);
        stepSize = 1;
    }
    else if (seqLayer->freqScale < US_FLOAT(2.0))
    {
        note->sampleCount = 32;
        seqLayer->freqScale *= US_FLOAT(0.52325);
        stepSize = 2;
    }
    else if (seqLayer->freqScale < US_FLOAT(4.0))
    {
        note->sampleCount = 16;
        seqLayer->freqScale *= US_FLOAT(0.26263);
        stepSize = 4;
    }
    else
    {
        note->sampleCount = 8;
        seqLayer->freqScale *= US_FLOAT(0.13081);
        stepSize = 8;
    }

    if (note->sampleCount == origSampleCount && seqLayer->seqChannel->instOrWave == note->instOrWave)
    {
        return;
    }

    // Load wave sample
    note->instOrWave = (u8) seqLayer->seqChannel->instOrWave;
    for (i = -1, pos = 0; pos < 0x40; pos += stepSize)
    {
        i++;
        note->unk34->samples[i] = gWaveSamples[seqLayer->seqChannel->instOrWave - 0x80][pos];
    }

    // Repeat sample
    for (offset = note->sampleCount; offset < 0x40; offset += note->sampleCount)
    {
        lim = note->sampleCount;
        if (offset < 0 || offset > 0)
        {
            for (j = 0; j < lim; j++)
            {
                note->unk34->samples[offset + j] = note->unk34->samples[j];
            }
        }
        else
        {
            for (j = 0; j < lim; j++)
            {
                note->unk34->samples[offset + j] = note->unk34->samples[j];
            }
        }
    }

    osWritebackDCache(note->unk34->samples, sizeof(note->unk34->samples));
}

void func_80319164(struct Note *note, struct SequenceChannelLayer *seqLayer)
{
    s32 sampleCount = note->sampleCount;
    func_80318F04(note, seqLayer);
    if (sampleCount != 0)
    {
        note->unk14 *= note->sampleCount / sampleCount;
    }
    else
    {
        note->unk14 = 0;
    }
}

void note_list_create(struct NoteListItem *head)
{
    head->prev = head;
    head->next = head;
    head->u.count = 0;
}

void func_803191F8(struct NoteListItem *gNoteListHeads)
{
    note_list_create(&gNoteListHeads[0]);
    note_list_create(&gNoteListHeads[1]);
    note_list_create(&gNoteListHeads[2]);
    note_list_create(&gNoteListHeads[3]);
    gNoteListHeads[0].head = gNoteListHeads;
    gNoteListHeads[1].head = gNoteListHeads;
    gNoteListHeads[2].head = gNoteListHeads;
    gNoteListHeads[3].head = gNoteListHeads;
}

void func_80319248(void)
{
    s32 i;

    func_803191F8(D_80225EA8);
    for (i = 0; i < gNoteCount; i++)
    {
        gNotes[i].noteListItem.u.value = &gNotes[i];
        gNotes[i].noteListItem.prev = NULL;
        note_list_item_add(&D_80225EA8[0], &gNotes[i].noteListItem);
    }
}

void func_803192FC(struct NoteListItem *gNoteListHeads)
{
    struct NoteListItem *s0;
    struct NoteListItem *s2;
    s32 i;
    struct NoteListItem *s3;
    s32 j;

    for (i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            s2 = &gNoteListHeads[0];
            s3 = &D_80225EA8[0];
            break;

        case 1:
            s2 = &gNoteListHeads[1];
            s3 = &D_80225EA8[1];
            break;

        case 2:
            s2 = &gNoteListHeads[2];
            s3 = &D_80225EA8[2];
            break;

        case 3:
            s2 = &gNoteListHeads[3];
            s3 = &D_80225EA8[3];
            break;
        }

        j = 0;
        do
        {
            s0 = s2->next;
            if (s0 == s2)
                break;
            func_803195A4(s0);
            note_list_item_add(s3, s0);
            j++;
        } while (j <= gNoteCount);
    }
}

void func_80319428(struct NoteListItem *gNoteListHeads, s32 count)
{
    s32 i;
    s32 j;
    struct Note *ret;
    struct NoteListItem *s1;
    struct NoteListItem *s2;

    func_803192FC(gNoteListHeads);

    for (i = 0, j = 0; j < count; i++)
    {
        if (i == 4)
            return;

        switch (i)
        {
        case 0:
            s1 = &D_80225EA8[0];
            s2 = &gNoteListHeads[0];
            break;

        case 1:
            s1 = &D_80225EA8[1];
            s2 = &gNoteListHeads[1];
            break;

        case 2:
            s1 = &D_80225EA8[2];
            s2 = &gNoteListHeads[2];
            break;

        case 3:
            s1 = &D_80225EA8[3];
            s2 = &gNoteListHeads[3];
            break;
        }

        while (j < count)
        {
            ret = note_list_item_remove(s1);
            if (ret == 0)
                break;
            note_list_item_add(s2, &ret->noteListItem);
            j++;
        }
    }
}

void func_80319564(struct NoteListItem *head, struct NoteListItem *item)
{
    // add 'item' to the front of the list given by 'head', if it's not in any list
    if (item->prev == NULL)
    {
        item->prev = head;
        item->next = head->next;
        head->next->prev = item;
        head->next = item;
        head->u.count++;
        item->head = head->head;
    }
}

void func_803195A4(struct NoteListItem *item)
{
    // remove 'item' from the list it's in, if any
    if (item->prev != NULL)
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->prev = NULL;
    }
}

struct Note *func_803195D0(struct NoteListItem *head, s32 arg1)
{
    struct NoteListItem *cur = head->next;
    struct NoteListItem *best;

    if (cur == head)
    {
        return NULL;
    }

    best = cur;
    for (; cur != head; cur = cur->next)
    {
        if (best->u.value->unk4 >= cur->u.value->unk4)
        {
            best = cur;
        }
    }

    if (arg1 < best->u.value->unk4)
    {
        return NULL;
    }

    func_803195A4(best);
    return best->u.value;
}

s32 func_80319660(struct Note *note, struct SequenceChannelLayer *seqLayer)
{
    note->unk28 = NO_LAYER;
    note->parentLayer = seqLayer;
    note->unk4 = seqLayer->seqChannel->unk4;
    if (IS_BANK_LOAD_COMPLETE(seqLayer->seqChannel->bankId) == FALSE)
    {
        return TRUE;
    }

    note->bankId = seqLayer->seqChannel->bankId;
    note->soundModeSomething = seqLayer->seqChannel->soundModeSomething;
    note->sound = seqLayer->sound;
    seqLayer->unk1 = 3;
    seqLayer->note = note;
    seqLayer->seqChannel->unk34 = note;
    seqLayer->seqChannel->unk38 = seqLayer;
    if (note->sound == NULL)
    {
        func_80318F04(note, seqLayer);
    }
    func_80318870(note);
    return FALSE;
}

void func_80319728(struct Note *arg0, struct SequenceChannelLayer *seqLayer)
{
    seq_channel_layer_init_7(arg0->parentLayer);
    arg0->unk30 = seqLayer;
}

void func_8031975C(struct Note *arg0, struct SequenceChannelLayer *seqLayer)
{
    arg0->unk30 = seqLayer;
    arg0->unk4 = 1;
    arg0->adsr.fadeOutVel = 0x8000 / gAudioUpdatesPerFrame;
    arg0->adsr.action |= ADSR_ACTION_RELEASE;
}

struct Note *func_803197B4(struct NoteListItem *gNoteListHeads, struct SequenceChannelLayer *seqLayer)
{
    struct Note *a2 = note_list_item_remove(&gNoteListHeads[0]);
    if (a2 != NULL)
    {
        if (func_80319660(a2, seqLayer) == TRUE)
        {
            func_80319564(&D_80225EA8[0], &a2->noteListItem);
            return NULL;
        }

        func_80319564(&gNoteListHeads[3], &a2->noteListItem);
    }
    return a2;
}

struct Note *func_80319830(struct NoteListItem *gNoteListHeads, struct SequenceChannelLayer *seqLayer)
{
    struct Note *a2 = note_list_item_remove(&gNoteListHeads[1]);
    if (a2 != NULL)
    {
        func_8031975C(a2, seqLayer);
        note_list_item_add(&gNoteListHeads[2], &a2->noteListItem);
    }
    return a2;
}

struct Note *func_80319884(struct NoteListItem *gNoteListHeads, struct SequenceChannelLayer *seqLayer)
{
    struct Note *a2 = func_803195D0(&gNoteListHeads[3], seqLayer->seqChannel->unk4);
    if (a2 != 0)
    {
        func_80319728(a2, seqLayer);
        note_list_item_add(&gNoteListHeads[2], &a2->noteListItem);
    }
    return a2;
}

struct Note *func_803198E0(struct SequenceChannelLayer *seqLayer)
{
    struct Note *ret;
    u32 mask = seqLayer->seqChannel->someMask;

    if (mask & 1)
    {
        ret = seqLayer->note;
        if (ret != NULL && ret->unk28 == seqLayer)
        {
            func_8031975C(ret, seqLayer);
            func_803195A4(&ret->noteListItem);
            note_list_item_add(&D_80225EA8[2], &ret->noteListItem);
            return ret;
        }
    }

    if (mask & 2)
    {
        if (!(ret = func_803197B4(seqLayer->seqChannel->unk80, seqLayer)) &&
            !(ret = func_80319830(seqLayer->seqChannel->unk80, seqLayer)) &&
            !(ret = func_80319884(seqLayer->seqChannel->unk80, seqLayer)))
        {
            seqLayer->unk1 = 0;
            return 0;
        }
        return ret;
    }

    if (mask & 4)
    {
        if (!(ret = func_803197B4(seqLayer->seqChannel->unk80, seqLayer)) &&
            !(ret = func_803197B4(seqLayer->seqChannel->seqPlayer->unk90, seqLayer)) &&
            !(ret = func_80319830(seqLayer->seqChannel->unk80, seqLayer)) &&
            !(ret = func_80319830(seqLayer->seqChannel->seqPlayer->unk90, seqLayer)) &&
            !(ret = func_80319884(seqLayer->seqChannel->unk80, seqLayer)) &&
            !(ret = func_80319884(seqLayer->seqChannel->seqPlayer->unk90, seqLayer)))
        {
            seqLayer->unk1 = 0;
            return 0;
        }
        return ret;
    }

    if (mask & 8)
    {
        if (!(ret = func_803197B4(D_80225EA8, seqLayer)) &&
            !(ret = func_80319830(D_80225EA8, seqLayer)) &&
            !(ret = func_80319884(D_80225EA8, seqLayer)))
        {
            seqLayer->unk1 = 0;
            return 0;
        }
        return ret;
    }

    if (!(ret = func_803197B4(seqLayer->seqChannel->unk80, seqLayer)) &&
        !(ret = func_803197B4(seqLayer->seqChannel->seqPlayer->unk90, seqLayer)) &&
        !(ret = func_803197B4(D_80225EA8, seqLayer)) &&
        !(ret = func_80319830(seqLayer->seqChannel->unk80, seqLayer)) &&
        !(ret = func_80319830(seqLayer->seqChannel->seqPlayer->unk90, seqLayer)) &&
        !(ret = func_80319830(D_80225EA8, seqLayer)) &&
        !(ret = func_80319884(seqLayer->seqChannel->unk80, seqLayer)) &&
        !(ret = func_80319884(seqLayer->seqChannel->seqPlayer->unk90, seqLayer)) &&
        !(ret = func_80319884(D_80225EA8, seqLayer)))
    {
        seqLayer->unk1 = 0;
        return 0;
    }
    return ret;
}

void func_80319BC8(void)
{
    struct Note *s0;
    struct NoteListItem *item;
    s32 i;
    s32 cond;

    for (i = 0; i < gNoteCount; i++)
    {
        s0 = &gNotes[i];
        if (s0->parentLayer != NO_LAYER)
        {
            cond = FALSE;
            if (!s0->parentLayer->enabled && s0->unk4 >= 2)
            {
                cond = TRUE;
            }
            else
            {
                item = &s0->parentLayer->noteItem;
                if (s0->parentLayer->seqChannel == NULL)
                {
                    note_list_item_add(&gLayerFreeList, item);
                    seq_channel_layer_disable(s0->parentLayer);
                    s0->unk4 = 1;
                }
                else if (s0->parentLayer->seqChannel->seqPlayer == NULL)
                {
                    sequence_channel_disable(s0->parentLayer->seqChannel);
                    s0->unk4 = 1;
                }
                else if (s0->parentLayer->seqChannel->seqPlayer->muted)
                {
                    if (s0->parentLayer->seqChannel->muteBehavior & (MUTE_BEHAVIOR_80 | MUTE_BEHAVIOR_40))
                    {
                        cond = TRUE;
                    }
                }
                else
                {
                    cond = FALSE;
                }
            }

            if (cond)
            {
                seq_channel_layer_init_7(s0->parentLayer);
                func_803195A4(&s0->noteListItem);
                func_80319564(s0->noteListItem.head, &s0->noteListItem);
                s0->unk4 = 1;
            }
        }
    }
}

void note_init_all(void)
{
    struct Note *note;
    s32 i;

    for (i = 0; i < gNoteCount; i++)
    {
        note = &gNotes[i];
        note->enabled = FALSE;
        note->unk0b4 = FALSE;
        note->unk0b2 = FALSE;
        note->soundModeSomething = FALSE;
        note->unk4 = 0;
        note->parentLayer = NO_LAYER;
        note->unk30 = NO_LAYER;
        note->unk28 = NO_LAYER;
        note->reverb = 0;
        note->unk1 = 0;
        note->sampleCount = 0;
        note->instOrWave = 0;
        note->targetVolLeft = 0;
        note->targetVolRight = 0;
        note->frequency = 0.0f;
        note->unk41 = 0x3f;
        note->unk44.velocity = 0.0f;
        note->unk8 = 0;
        note->adsr.state = ADSR_STATE_DISABLED;
        note->adsr.action = 0;
        note->vibratoState.active = FALSE;
        note->portamento.cur = 0.0f;
        note->portamento.speed = 0.0f;
        note->unk34 = soundAlloc(&D_802212C8, 0x190);
    }
}
