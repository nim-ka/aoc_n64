#ifndef _GEO_LAYOUT_H_
#define _GEO_LAYOUT_H_

#include "graph_node.h"

struct AllocOnlyPool;

#define GEO_CMD_FLAGS_RESET 0
#define GEO_CMD_FLAGS_SET   1
#define GEO_CMD_FLAGS_CLEAR 2

#define cur_geo_cmd_u8(offset) \
    (gGeoLayoutCommand[offset])

#define cur_geo_cmd_s16(offset) \
    (*(s16 *) &gGeoLayoutCommand[offset])

#define cur_geo_cmd_s32(offset) \
    (*(s32 *) &gGeoLayoutCommand[offset])

#define cur_geo_cmd_u32(offset) \
    (*(u32 *) &gGeoLayoutCommand[offset])

extern struct AllocOnlyPool *D_8038BCA0;
extern struct GraphNode *D_8038BCA4;
extern struct GraphNode **D_8038BCAC;
extern u16 D_8038BCB0;
extern s16 D_8038BD78;
extern u32 gGeoLayoutStack[];
extern struct GraphNode *D_8038BCF8[];
extern s16 gGeoLayoutStackIndex;
extern s16 D_8038BD7E;
extern u8 *gGeoLayoutCommand;

extern u32 D_8038B8A0;
extern u16 D_8038B8A4;
extern u16 D_8038B8A8;
extern s16 D_8038B8AC;

extern struct AllocOnlyPool *gGraphNodePool;

void geo_layout_cmd_00(void);
void geo_layout_cmd_01(void);
void geo_layout_cmd_02(void);
void geo_layout_cmd_03(void);
void geo_layout_cmd_04(void);
void geo_layout_cmd_05(void);
void geo_layout_cmd_06(void);
void geo_layout_cmd_07(void);
void geo_layout_cmd_08(void);
void geo_layout_cmd_09(void);
void geo_layout_cmd_0A(void);
void geo_layout_cmd_0B(void);
void geo_layout_cmd_1F(void);
void geo_layout_cmd_0C(void);
void geo_layout_cmd_0D(void);
void geo_layout_cmd_0E(void);
void geo_layout_cmd_0F(void);
void geo_layout_cmd_10(void);
void geo_layout_cmd_11(void);
void geo_layout_cmd_12(void);
void geo_layout_cmd_1D(void);
void geo_layout_cmd_1E(void);
void geo_layout_cmd_13(void);
void geo_layout_cmd_14(void);
void geo_layout_cmd_15(void);
void geo_layout_cmd_16(void);
void geo_layout_cmd_17(void);
void geo_layout_cmd_18(void);
void geo_layout_cmd_19(void);
void geo_layout_cmd_1A(void);
void geo_layout_cmd_1B(void);
void geo_layout_cmd_1C(void);
void geo_layout_cmd_20(void);

struct GraphNode *process_geo_layout(struct AllocOnlyPool *a0, void *segptr);

#endif /* _GEO_LAYOUT_H_ */
