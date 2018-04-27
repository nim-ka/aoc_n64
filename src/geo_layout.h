#ifndef _GEO_LAYOUT_H_
#define _GEO_LAYOUT_H_

#define cur_geo_cmd_u8(offset) \
    (gGeoLayoutCommand[offset])

#define cur_geo_cmd_s16(offset) \
    (*(s16 *) &gGeoLayoutCommand[offset])

#define cur_geo_cmd_s32(offset) \
    (*(s32 *) &gGeoLayoutCommand[offset])

#define cur_geo_cmd_u32(offset) \
    (*(u32 *) &gGeoLayoutCommand[offset])

typedef void (*GeoLayoutCommandProc)(void);
extern GeoLayoutCommandProc GeoLayoutJumpTable[];

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
