#include "ultra64.h"
#include "sm64.h"
#include "types.h"
#include "memory.h"
#include "segment2.h"
#include "segment7.h"
#include "intro_geo.h"
#include "libultra.h"

#define INTRO_STEPS_ZOOM_IN    20
#define INTRO_STEPS_HOLD_1     75
#define INTRO_STEPS_ZOOM_OUT   91

struct SceneGraphNodeMore
{
    /*0x00*/ struct SceneGraphNode node;
    /*0x14*/ void *todo;
    /*0x18*/ u32 unk18;
};

// intro geo bss
extern s16 gIntroFrameCounter;
extern s32 gGeoFadeCounter;
extern int D_801B9850;
extern int D_801B9854;
// intro geo data
extern s8 *D_801A7BB4[];
extern s8 D_801A7BB8[];
extern s8 D_801A7BC4[];

Gfx *geo18_title_screen(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2)
{
   struct SceneGraphNode *sp4c;
   Gfx *displayList; // sp48
   Gfx *displayListIter; // sp44
   Mtx *scaleMat; // sp40
   float *scaleTable1; // sp3c
   float *scaleTable2; // sp38
   float scaleX; // sp34
   float scaleY; // sp30
   float scaleZ; // sp2c
   sp4c = a1;
   displayList = NULL;
   displayListIter = NULL;
   scaleTable1 = segmented_to_virtual(intro_table_0700C790);
   scaleTable2 = segmented_to_virtual(intro_table_0700C880);
   if (a0 != 1)
   {
      gIntroFrameCounter = 0;
   }
   else if (a0 == 1)
   {
      sp4c->unk02 = (sp4c->unk02 & 0xFF) | 0x100;
      scaleMat = alloc_display_list(sizeof(*scaleMat));
      displayList = alloc_display_list(4 * sizeof(*displayList));
      displayListIter = displayList;
      if (gIntroFrameCounter >= 0 && gIntroFrameCounter < INTRO_STEPS_ZOOM_IN)
      {
         scaleX = scaleTable1[gIntroFrameCounter * 3];
         scaleY = scaleTable1[gIntroFrameCounter * 3 + 1];
         scaleZ = scaleTable1[gIntroFrameCounter * 3 + 2];
      }
      else if (gIntroFrameCounter >= INTRO_STEPS_ZOOM_IN && gIntroFrameCounter < INTRO_STEPS_HOLD_1)
      {
         scaleX = 1.0f;
         scaleY = 1.0f;
         scaleZ = 1.0f;
      }
      else if (gIntroFrameCounter >= INTRO_STEPS_HOLD_1 && gIntroFrameCounter < INTRO_STEPS_ZOOM_OUT)
      {
         scaleX = scaleTable2[(gIntroFrameCounter - INTRO_STEPS_HOLD_1) * 3];
         scaleY = scaleTable2[(gIntroFrameCounter - INTRO_STEPS_HOLD_1) * 3 + 1];
         scaleZ = scaleTable2[(gIntroFrameCounter - INTRO_STEPS_HOLD_1) * 3 + 2];
      }
      else
      {
         scaleX = 0.0f;
         scaleY = 0.0f;
         scaleZ = 0.0f;
      }
      guScale(scaleMat, scaleX, scaleY, scaleZ);
      gSPMatrix(displayListIter++, scaleMat, G_MTX_PUSH);
      gSPDisplayList(displayListIter++, &intro_f3d_0700B3A0);
      gSPPopMatrix(displayListIter++, G_MTX_MODELVIEW);
      gSPEndDisplayList(displayListIter);
      gIntroFrameCounter++;
   }
   return displayList;
}

Gfx *geo18_fade_transition(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2)
{
   // sp40 = a0
   // sp44 = a1
   // sp48 = a2
   struct SceneGraphNode *sp3c = a1;
   Gfx *displayList = NULL; // sp38
   Gfx *displayListIter = NULL; // sp34
   if (a0 != 1)
   {
      gGeoFadeCounter = 0; // D_801B985C
   }
   else if (a0 == 1)
   {
      displayList = alloc_display_list(5 * sizeof(*displayList));
      displayListIter = displayList;
      gSPDisplayList(displayListIter++, seg2_f3d_014660);
      gDPSetEnvColor(displayListIter++, 0xFF, 0xFF, 0xFF, gGeoFadeCounter);
      if (gGeoFadeCounter == 0xFF)
      {
         if (0) {}
         sp3c->unk02 = (sp3c->unk02 & 0xFF) | 0x100;
         gDPSetRenderMode(displayListIter++, 0x00552048, 0); // TODO mode1 | mode2
      }
      else
      {
         sp3c->unk02 = (sp3c->unk02 & 0xFF) | 0x500;
         gDPSetRenderMode(displayListIter++, 0x005041C8 , 0); // TODO mode1 | mode2
         if (0) {}
      }
      gSPDisplayList(displayListIter++, &intro_f3d_0700C6A0);
      gSPEndDisplayList(displayListIter);
      if (gIntroFrameCounter >= 0x13)
      {
         gGeoFadeCounter += 0x1a;
         if (gGeoFadeCounter >= 0x100)
         {
            gGeoFadeCounter = 0xFF;
         }
      }
   }
   return displayList;
}

Gfx *intro_backdrop_one_image(u32 index, s8 *backdrop_table)
{
   // sp60 = a0 = index
   // sp64 = a1 = backdrop_table
   Mtx *mtx;
   Gfx *displayList;
   Gfx *displayListIter;
   u32 *sp50;
   int i; // sp4c
   mtx = alloc_display_list(sizeof(*mtx));
   displayList = alloc_display_list(36 * sizeof(*displayList));
   displayListIter = displayList;
   sp50 = segmented_to_virtual(D_801A7BA0[backdrop_table[index]]);
   func_80324758(mtx, D_801A7B40[index], D_801A7B70[index], 0);
   gSPMatrix(displayListIter++, mtx, G_MTX_LOAD | G_MTX_PUSH);
   gSPDisplayList(displayListIter++, &D_0A000118);
   for (i = 0; i < 4; ++i) {
      gDPSetTextureImage(displayListIter++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, sp50[i]);
      gDPSetTile(displayListIter++, 0, 2, 0, 0, 7, 0, 2, 6, 0, 2, 7, 0);
      gDPLoadSync(displayListIter++);
      gDPLoadBlock(displayListIter++, 7, 0, 0, 1599, 103);
      gDPPipeSync(displayListIter++);
      gDPSetTile(displayListIter++, 0, 2, 0x14, 0, 0, 0, 2, 6, 0, 2, 7, 0);
      gDPSetTileSize(displayListIter++, 0, 0, 0, 316, 76);
      gSPDisplayList(displayListIter++, D_801A7B30[i]);
   }
   gSPPopMatrix(displayListIter++, G_MTX_MODELVIEW);
   gSPEndDisplayList(displayListIter);
   return displayList;
}

Gfx *geo18_intro_backdrop(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2)
{
   // sp48 = a0
   // sp4c = a1
   // sp50 = a2
   struct SceneGraphNodeMore *sp44;
   int sp40;
   s8 *backdrop_table; // sp3c
   Gfx *displayList;
   Gfx *displayListIter;
   int i; // sp30
   sp44 = (struct SceneGraphNodeMore *)a1;
   sp40 = sp44->unk18 & 0xff; // TODO: word at offset 0x18 of struct SceneGraphNode
   backdrop_table = D_801A7BB4[sp40];
   displayList = NULL;
   displayListIter = NULL;
   if (a0 == 1) {
      displayList = alloc_display_list(16 * sizeof(*displayList));
      displayListIter = displayList;
      sp44->node.unk02 = (sp44->node.unk02 & 0xFF) | 0x100;
      gSPDisplayList(displayListIter++, &seg2_f3d_014660);
      gSPDisplayList(displayListIter++, &D_0A000100);
      for (i = 0; i < 12; ++i) {
         gSPDisplayList(displayListIter++, intro_backdrop_one_image(i, backdrop_table));
      }
      gSPDisplayList(displayListIter++, &D_0A000190);
      gSPEndDisplayList(displayListIter);
   }
   return displayList;
}

Gfx *geo18_backdrop_tile(u32 a0, struct SceneGraphNode *a1, UNUSED u32 a2)
{
   // sp40 = a0
   // sp44 = a1
   // sp48 = a2
   struct SceneGraphNode *sp3c;
   Gfx *displayList;
   Gfx *displayListIter;
   int j; // sp30
   int i; // sp2c
   sp3c = a1;
   displayList = NULL;
   displayListIter = NULL;
   if (a0 != 1) {
      D_801B9850 = 0;
      D_801B9854 = -2;
      for (i = 0; i < 12; ++i) {
         D_801A7BB8[i] = 1;
      }
   } else {
      displayList = alloc_display_list(16 * sizeof(*displayList));
      displayListIter = displayList;
      if (D_801B9854 == -2) {
         if (D_801B9850 == 180) {
            D_801B9854++;
            D_801B9850 = 0;
         }
      } else {
         if (D_801B9854 != 11 && !(D_801B9850 & 0x1)) {
            D_801B9854++;
            D_801A7BB8[D_801A7BC4[D_801B9854]] = 0;
         }
      }
      if (D_801B9854 != 11) {
         D_801B9850++;
      }
      sp3c->unk02 = (sp3c->unk02 & 0xFF) | 0x100;
      gSPDisplayList(displayListIter++, &seg2_f3d_014660);
      gSPDisplayList(displayListIter++, &D_0A000100);
      for (j = 0; j < 12; ++j) {
         gSPDisplayList(displayListIter++, intro_backdrop_one_image(j, D_801A7BB8));
      }
      gSPDisplayList(displayListIter++, &D_0A000190);
      gSPEndDisplayList(displayListIter);
   }
   return displayList;
}

