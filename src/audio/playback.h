#ifndef _AUDIO_PLAYBACK_H
#define _AUDIO_PLAYBACK_H

#include "internal.h"

void func_80318908(void);
void seq_channel_layer_init_6(struct SequenceChannelLayer *arg0);
void seq_channel_layer_init_7(struct SequenceChannelLayer *arg0);
void func_80319164(struct Note *arg0, struct SequenceChannelLayer *arg1);
void func_803191F8(struct NoteListItem *gNoteListHeads);
void func_80319248(void);
void func_803192FC(struct NoteListItem *gNoteListHeads);
void func_80319428(struct NoteListItem *gNoteListHeads, s32 count);
void func_80319564(struct NoteListItem *head, struct NoteListItem *item);
void func_803195A4(struct NoteListItem *item);
struct Note *func_803198E0(struct SequenceChannelLayer *arg0);
void func_80319BC8(void);
void note_init_all(void);


#endif /* _AUDIO_PLAYBACK_H */
