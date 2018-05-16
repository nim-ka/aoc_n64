#ifndef _GEO_LAYOUT_H_
#define _GEO_LAYOUT_H_

#include "graph_node.h"

#define cur_geo_cmd_u8(offset) \
    (gGeoLayoutCommand[offset])

#define cur_geo_cmd_s16(offset) \
    (*(s16 *) &gGeoLayoutCommand[offset])

#define cur_geo_cmd_s32(offset) \
    (*(s32 *) &gGeoLayoutCommand[offset])

#define cur_geo_cmd_u32(offset) \
    (*(u32 *) &gGeoLayoutCommand[offset])

extern struct Struct80278464 *D_8038BCA0;
extern struct SceneGraphNode *D_8038BCA4;
extern struct SceneGraphNode **D_8038BCAC;
extern u16 D_8038BCB0;
extern s16 D_8038BD78;
extern u32 gGeoLayoutStack[];
//extern struct SceneGraphNode *D_8038BCF4[];
extern struct SceneGraphNode *D_8038BCF8[];
extern s16 gGeoLayoutStackIndex;
extern s16 D_8038BD7E;
extern u8 *gGeoLayoutCommand;
extern u8 D_8038BD88[];

extern u32 D_8038B8A0;
extern u16 D_8038B8A4;
extern u16 D_8038B8A8;
extern s16 D_8038B8AC;

void GeoLayout00(void);
void GeoLayout01(void);
void GeoLayout02(void);
void GeoLayout03(void);
void GeoLayout04(void);
void GeoLayout05(void);
void GeoLayout06(void);
void GeoLayout07(void);
void GeoLayout08(void);
void GeoLayout09(void);
void GeoLayout0A(void);
void GeoLayout0B(void);
void GeoLayout1F(void);
void GeoLayout0C(void);
void GeoLayout0D(void);
void GeoLayout0E(void);
void GeoLayout0F(void);
void GeoLayout10(void);
void GeoLayout11(void);
void GeoLayout12(void);
void GeoLayout1D(void);
void GeoLayout1E(void);
void GeoLayout13(void);
void GeoLayout14(void);
void GeoLayout15(void);
void GeoLayout16(void);
void GeoLayout17(void);
void GeoLayout18(void);
void GeoLayout19(void);
void GeoLayout1A(void);
void GeoLayout1B(void);
void GeoLayout1C(void);
void GeoLayout20(void);

struct SceneGraphNode *ProcessGeoLayout(struct Struct80278464 *a0, void *segptr);

#endif /* _GEO_LAYOUT_H_ */
