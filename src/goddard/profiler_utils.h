#ifndef _GD_PROFILERS_H_
#define _GD_PROFILERS_H_

#include <types.h>
#include "gd_types.h"

// extern ? func_8018C1B0(?);
// extern ? func_8018C264(?);
// extern ? func_8018C30C(?);
// extern ? Unknown8018C410(?);
extern void func_8018C458(const char*); /* printing function? */
// extern ? func_8018C5C4(?);
// extern ? func_8018C650(?);
extern void func_8018C674(void);
// extern ? func_8018C72C(?);
// extern ? func_8018C7E0(?);
// extern ? func_8018C7F8(?);
// extern ? func_8018C814(?);
// extern ? func_8018C948(?);
// extern ? func_8018C9F4(?);
// extern ? func_8018CAB4(?);
// extern ? get_timernum(?);
// extern ? func_8018CB80(?);
// extern ? Unknown8018CC5C(?);
// extern ? Unknown8018CCCC(?);
extern void start_timer(const char *);
extern void restart_timer(const char *);
extern void func_8018CEEC(const char *);
extern void func_8018CF48(const char *);
// extern ? func_8018D020(?);
// extern ? Unknown8018D1A8(?);
extern void myPrint1(const char *);
// extern ? func_8018D0E8(?);
extern void myPrintf(const char *, ...);
extern void func_8018D420(const char *);
extern void imout(void);
extern float func_8018D560(void);
extern s32 func_8018D6A8(char*); /* s32 gd_atoi(char*) */
extern f64 func_8018D808(char*, UNUSED u32*);   /* return (f64) gd_atoi(char*); lol */
// extern ? func_8018D848(?);
// extern ? func_8018D8A8(?);
// extern ? func_8018D9A4(?);
// extern ? func_8018D9F8(?);
extern void func_8018DC98(char *, char *);  /* gd_strcpy? */
// extern ? Unknown8018DCDC(?);
// extern ? func_8018DD5C(?);
extern u32 func_8018DDD8(char *);   /* gd_strlen ? */
extern char *func_8018DE2C(char *, char *); /* gd_strcat ?? */
extern s32 func_8018DEB0(char*, char*); /* gd_strcmp? */ 
extern s32 func_8018DF58(char*, char*); // gd_strstr?
extern s32 func_8018DFE8(struct GdFile*);  /* get GdFile->unk0C bit 3 (->0c & 0x4); file end reached? */
// extern ? func_8018E00C(?);
extern struct GdFile* gd_fopen(char*, char*);
extern s32 func_8018E23C(s8*, s32, s32, struct GdFile*); /* read_into(buf*, number, size, fd*)? */
extern void func_8018E368(struct GdFile*); /* gd_fclose? */
// extern ? func_8018E384(?);

#endif /* _GD_PROFILERS_H_ */
