#ifndef _INTRO_GEO_H
#define _INTRO_GEO_H

extern u8 D_0A000118[];
extern Gfx D_0A000100[];
extern Gfx D_0A000190[];
extern u32   D_801A7B30[];
extern float D_801A7B40[];
extern float D_801A7B70[];
extern Gfx  *D_801A7BA0[];

Gfx *geo18_title_screen(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2);
Gfx *geo18_fade_transition(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2);
Gfx *intro_backdrop_one_image(u32 index, s8 *backdrop_table);
Gfx *geo18_intro_backdrop(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2);
Gfx *geo18_backdrop_tile(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2);

#endif /* _INTRO_GEO_H */
