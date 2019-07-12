#ifndef _AUDIO_SEQPLAYER_H
#define _AUDIO_SEQPLAYER_H

#include "types.h"
#include "playback.h"

extern void seq_channel_layer_disable(struct SequenceChannelLayer *arg0);
void sequence_channel_disable(struct SequenceChannel *arg0);
extern void sequence_player_disable(struct SequencePlayer* arg0);
extern void note_list_item_add(struct NoteListItem *head, struct NoteListItem *item);
extern void *note_list_item_remove(struct NoteListItem *head);
extern void process_sequences(s32 iterationsRemaining);
extern void init_sequence_player(u32 arg0);
extern void func_8031D4B8(void);

#endif /* _AUDIO_SEQPLAYER_H */
