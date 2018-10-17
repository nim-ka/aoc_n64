#include <ultra64.h>
#include "stdarg.h"

#include "sm64.h"
#include "../libultra.h"
#include "data801A8050.h"
#include "gd_main.h"
#include "../game_over_1.h"
#include "game_over_2.h"
#include "mario_head_1.h"
#include "mario_head_3.h"
#include "mario_head_4.h"
#include "old_obj_fn.h"
#include "../mario_head_5.h"
#include "half_6.h"
#include "../mario_head_6.h"

#include "gd_types.h"

/****** Possible Structs ******/
struct Unk801B9E68 {
    /* 0x00 */ s32 count;   
    /* 0x04 */ u8  pad[0x14];
}; /* sizeof() = 0x18 */

struct Unk8017F3CC {
    /*0x00*/ u8  pad[0x20];
    /*0x20*/ struct MyVec3f unk20;
};

/* Exported globals */
struct GdPlaneF D_801B9DA0;
struct ObjCamera *D_801B9DB8;
struct ObjView *D_801B9DBC;
struct DebugCounters D_801B9DC0;
Mat4 D_801B9DC8;
struct MyVec3f D_801B9E08;
struct ObjGroup *D_801B9E14;
struct MyVec3f D_801B9E18;
struct MyVec3f D_801B9E28;
f32 D_801B9E34;
void *D_801B9E38;
struct ObjParticle *D_801B9E3C;
s32 D_801B9E40;
s32 D_801B9E44;
Mat4 *D_801B9E48;
struct ObjCamera *D_801B9E4C;
void *D_801B9E50;
struct ObjGroup *D_801B9E54;
s32 D_801B9E58;
s32 D_801B9E5C;
s32 D_801B9E60;
s32 D_801B9E64;
struct Unk801B9E68 D_801B9E68;
void *D_801B9E80;
void *D_801B9E84;
void *D_801B9E88;
struct ObjHeader *D_801B9E8C;
struct ObjGroup *D_801B9E90;

/* @ 22A480 for 0x70 */
void func_8017BCB0(void)
{   /* Initialize Plane? */
    D_801B9DA0.vec0.x = 10000000.0f;
    D_801B9DA0.vec0.y = 10000000.0f;
    D_801B9DA0.vec0.z = 10000000.0f;

    D_801B9DA0.vec1.x = -10000000.0f;
    D_801B9DA0.vec1.y = -10000000.0f;
    D_801B9DA0.vec1.z = -10000000.0f;
}

//TODO: fix first argument's type once type of set_cur_dynobj is known
// Should be an ObjVertex* 
/* @ 22A4F0 for 0x140 */
void func_8017BD20(void* a0)
{
    struct MyVec3f sp1c;

    set_cur_dynobj(a0);
    d_get_world_pos(&sp1c);

    if (sp1c.x < D_801B9DA0.vec0.x)
        D_801B9DA0.vec0.x = sp1c.x;
    
    if (sp1c.y < D_801B9DA0.vec0.y)
        D_801B9DA0.vec0.y = sp1c.y;
    
    if (sp1c.z < D_801B9DA0.vec0.z)
        D_801B9DA0.vec0.z = sp1c.z;
    
    if (sp1c.x > D_801B9DA0.vec1.x)
        D_801B9DA0.vec1.x = sp1c.x;
    
    if (sp1c.y > D_801B9DA0.vec1.y)
        D_801B9DA0.vec1.y = sp1c.y;
    
    if (sp1c.z > D_801B9DA0.vec1.z)
        D_801B9DA0.vec1.z = sp1c.z;
}

/* @ 22A630 for 0x70 */
void func_8017BE60(struct GdPlaneF* a0)
{
    a0->vec0.x = D_801B9DA0.vec0.x;
    a0->vec0.y = D_801B9DA0.vec0.y;
    a0->vec0.z = D_801B9DA0.vec0.z;

    a0->vec1.x = D_801B9DA0.vec1.x;
    a0->vec1.y = D_801B9DA0.vec1.y;
    a0->vec1.z = D_801B9DA0.vec1.z;
}

/* @ 22A6A0 for 0x24 */
void func_8017BED0(UNUSED struct ObjGroup *a0, UNUSED struct ObjHeader *a1)
{
    UNUSED u8 sp00[8];
    /* Debug stub? */
    return;
}

/* @ 22A6C4 for 0x2CC; orig. name: func_8017BEF4 */
const char* get_obj_name_str(enum ObjTypeFlag objFlag)
{
    /* sp04 */ const char* objName;
    switch (objFlag)
    {
        case OBJ_TYPE_JOINTS:    objName = "joints";    break;
        case OBJ_TYPE_BONES:     objName = "bones";     break;
        case OBJ_TYPE_GROUPS:    objName = "groups";    break;
        case OBJ_TYPE_PARTICLES: objName = "particles"; break;
        case OBJ_TYPE_SHAPES:    objName = "shapes";    break;
        case OBJ_TYPE_NETS:      objName = "nets";      break;
        case OBJ_TYPE_PLANES:    objName = "planes";    break;
        case OBJ_TYPE_VERTICES:  objName = "vertices";  break;
        case OBJ_TYPE_CAMERAS:   objName = "cameras";   break;
        case OBJ_TYPE_FACES:     objName = "faces";     break;
        case OBJ_TYPE_MATERIALS: objName = "materials"; break;
        case OBJ_TYPE_LIGHTS:    objName = "lights";    break;
        case OBJ_TYPE_WEIGHTS:   objName = "weights";   break;
        case OBJ_TYPE_GADGETS:   objName = "gadgets";   break;
        case OBJ_TYPE_VIEWS:     objName = "views";     break;
        case OBJ_TYPE_LABELS:    objName = "labels";    break;
        case OBJ_TYPE_ANIMATORS: objName = "animators"; break;
        case OBJ_TYPE_VALPTRS:   objName = "valptrs";   break;
        case OBJ_TYPE_ZONES:     objName = "zones";     break;
        default:                 objName = "unkown";    break;
    }
    return objName;
}

/* @ 22A990 for 0x510 */
struct ObjHeader* make_object(enum ObjTypeFlag objType)
{
    struct ObjHeader* newObj;
    struct ObjHeader* objListOldHead;
    s32 objSize;
    int i;
    void (*objDrawFn)(void *);
    const char* objNameStr;
    u8 * newObjBytes;
    s32 objAlignment = 0x10;
    // to erase the object types of the various draw function pointers
    typedef void (*DrawFn)(void*);

    func_8018D420("make_object");   //goddard_debug_log()?
    switch (objType)
    {
        case OBJ_TYPE_JOINTS:
            objSize = 0x22C;
            objDrawFn = (DrawFn) &Proc8017A6A4;
            break;
        case OBJ_TYPE_BONES:
            objSize = 0x124;
            objDrawFn = (DrawFn) &Proc8017A550;
            break;
        case OBJ_TYPE_GROUPS:
            objSize = 0x78;
            objDrawFn = (DrawFn) &draw_group;
            break;
        case OBJ_TYPE_PARTICLES:
            objSize = 0xC0;
            objDrawFn = (DrawFn) &Proc8017A30C;
            break;
        case OBJ_TYPE_SHAPES:
            objSize = 0x9C;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_UNK200000:
            objSize = 0x38;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_NETS:
            objSize = 0x220;
            objDrawFn = (DrawFn) &Proc80179628;
            break;
        case OBJ_TYPE_PLANES:
            objSize = 0x44;
            objDrawFn = (DrawFn) &Proc8017A818;
            break;
        case OBJ_TYPE_VERTICES:
            objSize = 0x48;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_CAMERAS:
            objSize = 0x190;
            objDrawFn = (DrawFn) &draw_camera;
            break;
        case OBJ_TYPE_FACES:
            objSize = 0x4C;
            objDrawFn = (DrawFn) &draw_face;
            objAlignment = 1;
            break;
        case OBJ_TYPE_MATERIALS:
            objSize = 0x60;
            objDrawFn = (DrawFn) &draw_material;
            break;
        case OBJ_TYPE_LIGHTS:
            objSize = 0xA0;
            objDrawFn = (DrawFn) &Proc80178900;
            break;
        case OBJ_TYPE_WEIGHTS:
            objSize = 0x40;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_GADGETS:
            objSize = 0x60;
            objDrawFn = (DrawFn) &Proc8017976C;
            break;
        case OBJ_TYPE_VIEWS:
            objSize = 0xA0;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_LABELS:
            objSize = 0x34;
            objDrawFn = (DrawFn) &Proc80179350;
            break;
        case OBJ_TYPE_ANIMATORS:
            objSize = 0x58;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_VALPTRS:
            objSize = 0x24;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        case OBJ_TYPE_ZONES:
            objSize = 0x38;
            objDrawFn = (DrawFn) &nop_obj_draw;
            break;
        default:
            myPrint1("make_object() : Unkown object!");
    }

    objNameStr = get_obj_name_str(objType);
    func_8018C30C(objNameStr);
    
    newObj = gd_malloc(objSize, objAlignment);
    //! As the function doesn't exit early from this check, it could NULL dereference below 
    if (newObj == NULL)
        myPrintf("Cant allocate object '%s' memory!", objNameStr);
    
    func_8018C458(objNameStr);

    newObjBytes = (u8*) newObj;
    for (i = 0; i < objSize; i++)
        newObjBytes[i] = 0;
    
    D_801B9E58++;
    objListOldHead = D_801B9E8C;
    D_801B9E8C = newObj;
    
    newObj->prev = NULL;
    if (objListOldHead != NULL)
    {
        newObj->next = objListOldHead;
        objListOldHead->prev = newObj;
    }
    newObj->number    = D_801B9E58;
    newObj->type      = objType;
    newObj->objDrawFn = objDrawFn;
    newObj->unk12     = 0;

    imout();
    return newObj;
}

/* @ 22AEA0 for 0xD0; orig name: Unknown8017C6D0 */
void make_zone(struct ObjGroup *a0, struct GdPlaneF *a1, struct ObjGroup *a2)
{
    struct ObjZone* newZone = (struct ObjZone*) make_object(OBJ_TYPE_ZONES);

    newZone->unk14.vec0.x = a1->vec0.x;
    newZone->unk14.vec0.y = a1->vec0.y;
    newZone->unk14.vec0.z = a1->vec0.z;
    newZone->unk14.vec1.x = a1->vec1.x;
    newZone->unk14.vec1.y = a1->vec1.y;
    newZone->unk14.vec1.z = a1->vec1.z;
    // pointers? prev, next?
    newZone->unk2C = a2;
    newZone->unk30 = a0;
}

/* @ 22AF70 for 0x60 */
struct ObjUnk200000* Unknown8017C7A0(struct ObjVertex *a0, struct ObjFace *a1)
{
    struct ObjUnk200000* sp1C = (struct ObjUnk200000*) make_object(OBJ_TYPE_UNK200000);

    sp1C->unk30 = a0;
    sp1C->unk34 = a1;

    return sp1C;
}

/* @ 22AFD0 for 0xC0; orig name: func_8017C800 */
struct Links* make_link_to_obj(struct Links* head, struct ObjHeader* a1)
{   
    struct Links* newLink;

    func_8018C30C("links");

    newLink = func_8019BC18(0x0C);
    //! Doesn't return early from NULL pointer. Dereferences later in function
    if (newLink == NULL)
        myPrint1("Cant allocate link memory!");
    
    func_8018C458("links");

    if (head != NULL)
        head->next = newLink;

    newLink->prev = head;
    newLink->next = NULL;
    newLink->obj = a1;

    return newLink;
}

/* @ 22B090 for 0xC4; orig name; func_8017C8C0*/
//TODO: correct call in game_over_2.c to fix the type of first argument
void* make_link_2(void* linkHead, struct ObjHeader* object)
{
    struct Links* newLink;

    newLink = func_8019BC18(0x0C);
    //! Doesn't return early from NULL pointer. Dereferences later in function
    if (newLink == NULL)
        myPrint1("Cant allocate link memory!");
    
    if (linkHead != NULL)
        ((struct Links*)linkHead)->next = newLink;

    newLink->prev = linkHead;
    newLink->next = NULL;
    newLink->obj = object;
    // WTF?
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
    if ( ((int) (newLink)) == 0x3F800000)
        myPrintf("bad3\n");
    #pragma GCC diagnostic pop
    return newLink;
}

/* @ 22B154 for 0x88; orig name: func8017C984 */
struct ObjValPtrs* make_valptrs(void* a0, s32 a1, s32 a2, s32 a3)
{
    struct ObjValPtrs* sp1C = (struct ObjValPtrs*) make_object(OBJ_TYPE_VALPTRS);

    sp1C->obj = a0;
    sp1C->unk20 = a1;
    sp1C->offset = a3;
    sp1C->datatype = a2;

    return sp1C;
}

/* @ 22B1DC for 0x430 */
void reset_plane(struct ObjPlane* plane)
{
    struct ObjFace* sp4C;
    f32 sp48;
    f32 sp44;
    UNUSED u32 sp40;
    UNUSED u32 sp3C;
    UNUSED u32 sp38;
    int i;
    s32 sp30;
    register f32 sp28;

    func_8018D420("reset_plane");

    sp4C = plane->unk40;
    calc_face_normal(sp4C);
    plane->unk1C = func_80194DB8(&sp4C->vertices[0]->vec20, &sp4C->vec24);
    sp48 = 0.0f;
    
    sp28 = sp4C->vec24.x < 0.0f ? -sp4C->vec24.x : sp4C->vec24.x;
    sp44 = sp28;
    if (sp44 > sp48)
    {
        sp30 = 0;
        sp48 = sp44;
    }

    sp28 = sp4C->vec24.y < 0.0f ? -sp4C->vec24.y : sp4C->vec24.y;
    sp44 = sp28;
    if (sp44 > sp48)
    {
        sp30 = 1;
        sp48 = sp44;
    }

    sp28 = sp4C->vec24.z < 0.0f ? -sp4C->vec24.z : sp4C->vec24.z;
    sp44 = sp28;
    if (sp44 > sp48)
        sp30 = 2;


    switch (sp30)
    {
        case 0:
            plane->unk20 = 1;
            plane->unk24 = 2;
            break;
        case 1:
            plane->unk20 = 0;
            plane->unk24 = 2;
            break;
        case 2:
            plane->unk20 = 0;
            plane->unk24 = 1;
            break;
    }

    func_8017BCB0();

    for (i = 0; i < sp4C->vtxCount; i++)
      func_8017BD20(sp4C->vertices[i]);      

    plane->plane28.vec0.x = D_801B9DA0.vec0.x;
    plane->plane28.vec0.y = D_801B9DA0.vec0.y;
    plane->plane28.vec0.z = D_801B9DA0.vec0.z;
    plane->plane28.vec1.x = D_801B9DA0.vec1.x;
    plane->plane28.vec1.y = D_801B9DA0.vec1.y;
    plane->plane28.vec1.z = D_801B9DA0.vec1.z;

    if (plane->plane28.vec1.x - plane->plane28.vec0.x < 100.0f)
    {
        plane->plane28.vec1.x += 50.0f;
        plane->plane28.vec0.x -= 50.0f;
    }

    plane->plane28.vec1.y += 200.0f;
    plane->plane28.vec0.y -= 200.0f;

    if (plane->plane28.vec1.z - plane->plane28.vec0.z < 100.0f)
    {
        plane->plane28.vec1.z += 50.0f;
        plane->plane28.vec0.z -= 50.0f;
    }
    imout();
}

/* @ 22B60C for 0x94; orig name: func_8017CE3C */
struct ObjPlane* make_plane(void* a0, struct ObjFace* a1)
{
    UNUSED u32 pad1C;
    struct ObjPlane* newPlane = (struct ObjPlane*) make_object(OBJ_TYPE_PLANES);

    D_801B9E60++;
    newPlane->id = D_801B9E60;
    newPlane->unk18 = a0;
    newPlane->unk40 = a1;
    reset_plane(newPlane);

    return newPlane;
}

/* @ 22B6A0 for 0x21C; orig name: func_8017CED0 */
struct ObjCamera* make_camera(s32 a0, struct ObjHeader* a1)
{
    struct ObjCamera* newCam;
    struct ObjCamera* oldCameraHead;

    newCam = (struct ObjCamera*) make_object(OBJ_TYPE_CAMERAS);

    D_801B9E64++;
    newCam->id = D_801B9E64;
    
    oldCameraHead = D_801B9E4C;
    D_801B9E4C = newCam;

    if (oldCameraHead != NULL)
    {
        newCam->next = oldCameraHead;
        oldCameraHead->prev = newCam;
    }

    newCam->unk2C = a0 | 0x10;
    newCam->unk30 = a1;
    set_identity_mat4(&newCam->unk64);
    set_identity_mat4(&newCam->unkA8);

    newCam->unk180.x = 1.0f;
    newCam->unk180.y = 0.1f;
    newCam->unk180.z = 1.0f;

    newCam->unk134.x = 4.0f;
    newCam->unk134.y = 4.0f;
    newCam->unk134.z = 4.0f;

    newCam->unk178 = 0.0f;
    newCam->unk17C = 0.25f;
    
    newCam->unk174 = 0;
    newCam->unk170 = -1;

    newCam->unkA4 = 0.0f;

    newCam->unk34.x = newCam->unk34.y = newCam->unk34.z = 0.0f;
    newCam->unk14.x = newCam->unk14.y = newCam->unk14.z = 0.0f;

    return newCam;
}

/* @ 22B8BC for 0xA8; orig. name: func_8017D0EC */
struct ObjMaterial* make_material(UNUSED s32 a0, char* name, s32 a2)
{
    struct ObjMaterial* newMtl;

    newMtl = (struct ObjMaterial*) make_object(OBJ_TYPE_MATERIALS);

    if (name != NULL)
        func_8018DC98(newMtl->name, name);
    else
        func_8018DC98(newMtl->name, "NoName");

    newMtl->unk1C = a2;
    newMtl->unk5C = 0;
    newMtl->unk28 = 16;

    return newMtl;
}

/* @ 22B964 for 0x114; orig name: func_8017D194 */
struct ObjLight* make_light(s32 a0, char* name, s32 a2)
{
    struct ObjLight* newLight;

    newLight = (struct ObjLight*) make_object(OBJ_TYPE_LIGHTS);

    if (name != NULL)
        func_8018DC98(newLight->name, name);
    else
        func_8018DC98(newLight->name, "NoName");

    newLight->unk1C = a2;
    newLight->unk30 = 1.0f;
    newLight->unk4C = 0;
    newLight->unk2C = a0 | 0x10;
    newLight->unk98 = 0;
    newLight->unk40 = 0;

    newLight->unk68.x = newLight->unk68.y = newLight->unk68.z = 0;

    return newLight;
}

/* @ 22BA78 for 0x294; orig name: func_8017D2A8*/
struct ObjView* make_view(char *a0, s32 a1, s32 a2, s32 a3, s32 sp38, s32 sp3C, s32 sp40, struct ObjGroup* sp44)
{
    struct ObjView* newView = (struct ObjView*) make_object(OBJ_TYPE_VIEWS);

    if (D_801B9E90 == NULL)
        D_801B9E90 = make_group(0);
    
    addto_group(D_801B9E90, &newView->header);

    newView->unk34 = a1 | 0x800 | 0x200000;     /* typeArg | OBJ_TYPE_MATERIALS | OBJ_TYPE_UNK200000 ?*/
    newView->unk20 = D_801B9E68.count++;
    
    if ((newView->unk28 = sp44) != NULL)
        func_801814F4(sp44);

    newView->unk78 = 0;
    newView->unk38 = a2;

    newView->unk60.x = 30.0f;
    newView->unk60.y = 5000.0f;
    newView->unk60.z = 45.0f;

    newView->unk3C.x = (f32) a3;
    newView->unk3C.y = (f32) sp38;

    newView->unk54.x = (f32) sp3C;
    newView->unk54.y = (f32) sp40;

    newView->unk48 = 1.0f;
    newView->unk4C = 1.0f;

    newView->unk7C.x = newView->unk20 * 0.1;    //! 0.1f, unless the extra precision was wanted for the tenth
    newView->unk7C.y = 0.06f;
    newView->unk7C.z = 1.0f;

    newView->unk98 = 0;
    newView->unk9C = 0;

    if (a0 != 0)
        newView->unk1C = func_801A3E5C(a0, newView, a3, sp38, sp3C, sp40);

    newView->unk6C = a0;
    newView->unk2C = NULL;

    return newView;
}

/* @ 22BD0C for 0x78; orig name: func_8017D53C */
struct ObjAnimator* make_animator(void)
{
    struct ObjAnimator* newAnim = (struct ObjAnimator*) make_object(OBJ_TYPE_ANIMATORS);
    newAnim->unk24 = 1.0f;
    newAnim->unk28 = 1.0f;

    newAnim->fn48 = NULL;
    newAnim->unk4C = 0;

    return newAnim;
}

/* @ 22BD84 for 0x78; orig name: func_8017D5B4 */
struct ObjWeight* make_weight(UNUSED s32 a0, s32 a1, struct ObjVertex* a2, f32 a3)
{
    struct ObjWeight* newWeight = (struct ObjWeight*) make_object(OBJ_TYPE_WEIGHTS);

    newWeight->id = a1;
    newWeight->unk38 = a3;
    newWeight->unk3C = a2;

    return newWeight;
}

/* @ 22BDFC for 0xCC; orig name: func_8017D62C */
struct ObjGroup* make_group_of_type(enum ObjTypeFlag type, struct ObjHeader* fromObj, struct ObjHeader* toObj)
{
    struct ObjGroup* newGroup;
    struct ObjHeader* curObj;

    newGroup = make_group(0);
    curObj = fromObj;

    while (curObj != NULL)
    {
        if (curObj->type & type)
            addto_group(newGroup, curObj);
        
        if (curObj == toObj)
            break;
        
        curObj = curObj->prev; 
    }

    return newGroup;
}

/* @ 22BEC8 for 0x1CC; orig name: func_8017D6F8 */
void sprint_obj_id(char* str, struct ObjHeader* obj)
{
    enum ObjTypeFlag type = obj->type;

    switch(type)
    {
        case OBJ_TYPE_BONES: 
            sprintf(str, "b%d ", ((struct ObjBone*) obj)->id);
            break;
        case OBJ_TYPE_JOINTS:
            sprintf(str, "j%d ", ((struct ObjJoint*) obj)->id);
            break;
        case OBJ_TYPE_GROUPS:
            sprintf(str, "g%d ", ((struct ObjGroup*) obj)->id);
            break;
        case OBJ_TYPE_PARTICLES:
            sprintf(str, "p%d ", ((struct ObjParticle*) obj)->id);
            break;
        case OBJ_TYPE_NETS:
            sprintf(str, "net(no id) ");
            break;
        case OBJ_TYPE_CAMERAS:
            sprintf(str, "c%d ", ((struct ObjCamera*) obj)->id);
            break;
        case OBJ_TYPE_VERTICES:
            sprintf(str, "v(no id) ");
            break;
        case OBJ_TYPE_PLANES:
            sprintf(str, "pl%d ", ((struct ObjPlane*) obj)->id);
            break;
        default:
            sprintf(str, "?%x ", type);
            break;
    }
}

/* Unused rodata string */
const char* sUnusedGroupFmtStr = "Made group no.%d\n";

/* @ 22C094 for 0x210 */
struct ObjGroup* make_group(int count, ...)
{
    va_list args;
    s32 i;
    UNUSED u32 sp5C;
    struct ObjHeader* curObj;
    UNUSED u32 sp54;
    UNUSED u32 sp50;
    UNUSED u32 sp4C;
    struct ObjGroup* newGroup;
    struct ObjGroup* oldGroupListHead;
    struct ObjHeader* vargObj;
    char idStrBuf[0x20];
    struct Links* curLink;

    newGroup = (struct ObjGroup*) make_object(OBJ_TYPE_GROUPS);
    newGroup->id = ++D_801B9E5C;
    newGroup->objCount = 0;
    newGroup->link1C = newGroup->link20 = NULL;

    oldGroupListHead = D_801B9E54;
    D_801B9E54 = newGroup;

    if (oldGroupListHead != NULL)
    {
        newGroup->next = oldGroupListHead;
        oldGroupListHead->prev = newGroup;
    }

    if (count == 0)
        return newGroup;

    va_start(args, count);
    curLink = NULL;

    for (i = 0; i < count; i++)
    {
        // get the next pointer in the struct.
        vargObj = va_arg(args, struct ObjHeader*);

        if (vargObj == NULL) // one of our pointers was NULL. raise an error.
            myPrintf("make_group() NULL group ptr");

        curObj = vargObj;
        newGroup->groupObjTypes |= curObj->type;
        addto_group(newGroup, vargObj);
    }
    va_end(argp);

    curLink = newGroup->link1C;
    while (curLink != NULL)
    {
        curObj = curLink->obj;
        sprint_obj_id(idStrBuf, curObj);
        curLink = curLink->next;
    }

    va_end(args);
    return newGroup;
}

/* More unused rodata strings */
const char* sUnusedGroupSplitFmtStr1 = "Made group no.%d from: ";
const char* sUnusedGroupSplitFmtStr2 = "%s";
const char* sUnusedGroupSplitFmtStr3 = "\n";

/* @ 22C2A4 for 0xEC */
void addto_group(struct ObjGroup* group, struct ObjHeader* obj)
{
    char strbuf[0x20];
    UNUSED u8 pad[0x8];

    func_8018D420("addto_group");

    if (group->link1C == NULL)
    {
        group->link1C = make_link_to_obj(NULL, obj);
        group->link20 = group->link1C;
    } else 
        group->link20 = make_link_to_obj(group->link20, obj);
    
    group->groupObjTypes |= obj->type;
    group->objCount++;

    sprint_obj_id(strbuf, obj);
    sprint_obj_id(strbuf, &group->header);
    imout();
}

/* More unused rodata strings */
const char* sUnusedAddedToGroupFmtStr1 = "Added ";
const char* sUnusedAddedToGroupFmtStr2 = "%s";
const char* sUnusedAddedToGroupFmtStr3 = " to ";
const char* sUnusedAddedToGroupFmtStr4 = "%s";
const char* sUnusedAddedToGroupFmtStr5 = "\n";

/* @ 22C390 for 0xFC; orig name: func_8017DBC0 */
void addto_groupfirst(struct ObjGroup* group, struct ObjHeader* obj)
{
    struct Links* newLink;

    func_8018D420("addto_groupfirst");

    if (group->link1C == NULL)
    {
        group->link1C = make_link_to_obj(NULL, obj);
        group->link20 = group->link1C;
    } 
    else
    {
        newLink = make_link_to_obj(NULL, obj);
        group->link1C->prev = newLink;
        newLink->next = group->link1C;
        group->link1C = newLink;
    }

    group->groupObjTypes |= obj->type;
    group->objCount++;
    imout();
}

/* @ 22C48C for 0x84; orig name: func_8017DCBC */
s32 group_contains_obj(struct ObjGroup* group, struct ObjHeader* obj)
{
    struct Links* objLink = group->link1C;

    while (objLink != NULL)
    {
        if (objLink->obj->number == obj->number)
            return 1;
        
        objLink = objLink->next;
    }

    return 0;
}

/* @ 22C510 for 0x4A8 */
/* this shows details about all objects in the main object linked list */
void show_details(enum ObjTypeFlag type)
{
    enum ObjTypeFlag curObjType;
    struct Links* curGroupLink;
    struct ObjGroup* curSubGroup;
    struct ObjHeader* curObj;
    char idStrBuf[0x24];
    s32 curGroupTypes;

    printf("\nDetails about: ");
    switch (type)
    {
        case OBJ_TYPE_GROUPS:    printf("Groups\n");      break;
        case OBJ_TYPE_BONES:     printf("Bones\n");       break;
        case OBJ_TYPE_JOINTS:    printf("Joints\n");      break;
        case OBJ_TYPE_PARTICLES: printf("Particles\n");   break;
        default:                 printf("Everything?\n"); break;
    }

    curObj = D_801B9E8C;
    while (curObj != NULL)
    {
        curObjType = curObj->type;
        if (curObjType == type)
        {
            sprint_obj_id(idStrBuf, curObj);
            switch (curObjType)
            {
                case OBJ_TYPE_GROUPS:
                    printf("Group %s: ", idStrBuf);
                    curGroupTypes = ((struct ObjGroup*) curObj)->groupObjTypes;

                    if (curGroupTypes & OBJ_TYPE_GROUPS)    printf("groups ");
                    if (curGroupTypes & OBJ_TYPE_BONES)     printf("bones ");
                    if (curGroupTypes & OBJ_TYPE_JOINTS)    printf("joints ");
                    if (curGroupTypes & OBJ_TYPE_PARTICLES) printf("particles ");
                    if (curGroupTypes & OBJ_TYPE_CAMERAS)   printf("cameras ");
                    if (curGroupTypes & OBJ_TYPE_NETS)      printf("nets ");
                    if (curGroupTypes & OBJ_TYPE_GADGETS)   printf("gadgets ");
                    if (curGroupTypes & OBJ_TYPE_LABELS)    printf("labels ");
                    if (curGroupTypes & OBJ_TYPE_FACES)     printf("face ");
                    if (curGroupTypes & OBJ_TYPE_VERTICES)  printf("vertex ");

                    curGroupLink = ((struct ObjGroup*) curObj)->link1C;
                    while (curGroupLink != NULL)
                    {
                        sprint_obj_id(idStrBuf, curGroupLink->obj);
                        printf("%s", idStrBuf);
                        curGroupLink = curGroupLink->next;
                    }
                    printf("\n");
                    break;
                case OBJ_TYPE_BONES:
                    printf("Bone %s: ", idStrBuf);
                    curSubGroup = ((struct ObjBone*) curObj)->unk10C;
                    curGroupLink = curSubGroup->link1C;
                    while (curGroupLink != NULL)
                    {
                        sprint_obj_id(idStrBuf, curGroupLink->obj);
                        printf("%s", idStrBuf);
                        curGroupLink = curGroupLink->next;
                    }
                    printf("\n");
                    break;
                case OBJ_TYPE_JOINTS:
                    printf("Joint %s: ", idStrBuf);
                    curSubGroup = ((struct ObjJoint*) curObj)->unk1C4;
                    curGroupLink = curSubGroup->link1C;
                    while (curGroupLink != NULL)
                    {
                        sprint_obj_id(idStrBuf, curGroupLink->obj);
                        printf("%s", idStrBuf);
                        curGroupLink = curGroupLink->next;
                    }
                    printf("\n");
                    break;
                default: ;
            }
        }
        curObj = curObj->next;
    }
}
/* @ 22C9B8 for 0x24 */
s32 Unknown8017E1E8(void)
{
    s32 sp4 = 0;
    return sp4;
}
/* @ 22C9DC for 0x24 */
s32 func_8017E20C(void)
{
    s32 sp4 = 0;
    return sp4;
}

/* @ 22CA00 for 0x88 */
void gd_loadtexture(struct ObjHeader* obj)
{
    struct ObjHeader* localObjPtr = obj;

    switch (obj->type)
    {
        case OBJ_TYPE_JOINTS:
            func_80191604(localObjPtr);
            break;
        case OBJ_TYPE_NETS:
            func_801920C4(localObjPtr);
            break;
        default: ;
    }
}

/* @ 22CA88 for 0x38 */
void func_8017E2B8(void)
{
    apply_to_obj_types_in_group(
        OBJ_TYPE_NETS, 
        &gd_loadtexture, 
        D_801B9E14
    );
}

/* @ 22CAC0 for 0xF0 */
struct ObjHeader* UnknownRecursive8017E2F0(struct ObjHeader* obj, enum ObjTypeFlag type)
{
    UNUSED u32 sp2C;
    enum ObjTypeFlag curObjType;
    struct Links* curGroupLink;

    curObjType = obj->type;

    switch (curObjType)
    {
        case OBJ_TYPE_GROUPS:
           curGroupLink = ((struct ObjGroup*) obj)->link1C;
           while (curGroupLink != NULL)
           {
               UnknownRecursive8017E2F0(curGroupLink->obj, type);
               curGroupLink = curGroupLink->next;
           }
           break;
        case OBJ_TYPE_BONES: break;
        default: ;
    }

    if (curObjType == type)
        return obj;
    //! return NULL;
}

/* @ 22CBB0 for 0x1A4; orig name: func8017E3E0 */
s32 apply_to_obj_types_in_group(s32 types, void (*fn)(void *), struct ObjGroup* group)
{
    struct Links* curLink;
    struct Links* nextLink;
    struct ObjHeader* linkedObj;
    enum ObjTypeFlag linkedObjType;
    void (*objFn)(void *);
    UNUSED u8 pad2C[0x20];
    s32 fnAppliedCount;

    fnAppliedCount = 0;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
    //! should be `return fnAppliedCount`;
    if (group == NULL) 
        return;
#pragma GCC diagnostic pop
    
    if ((group->unk30 & 1) != 0)
        return fnAppliedCount;
    
    if ( ((group->groupObjTypes & OBJ_TYPE_GROUPS) | (group->groupObjTypes & types)) == 0 )
        return fnAppliedCount;

    objFn = fn;
    curLink = group->link1C;

    while (curLink != NULL)
    {
        linkedObj = curLink->obj;
        linkedObjType = linkedObj->type;
        nextLink = curLink->next;

        if (linkedObjType == OBJ_TYPE_GROUPS)
            fnAppliedCount += apply_to_obj_types_in_group(types, fn, (struct ObjGroup*) linkedObj);
        
        if (linkedObjType & types)
        {
            (*objFn)(linkedObj);
            fnAppliedCount++;
        }

        curLink = nextLink;
    }
    return fnAppliedCount;
}

/* @ 22CD54 for 0x2B4 */
void func_8017E584(struct ObjJoint* a0, struct MyVec3f* a1, struct MyVec3f* a2)
{
    struct MyVec3f sp94;
    struct MyVec3f sp88;
    struct MyVec3f sp7C;
    struct MyVec3f sp70;
    UNUSED u8 pad30[0x40];  //unused MyMatrix4x4? f32[4][4]
    f32 sp2C;
    UNUSED u32 sp28;
    struct MyVec3f sp1C;

    sp70.x = a2->x;
    sp70.y = a2->y;
    sp70.z = a2->z;

    func_80194BF4(&sp70);

    sp7C.x = a1->x;
    sp7C.y = a1->y;
    sp7C.z = a1->z;

    sp1C.x = a0->unkB0.x;
    sp1C.y = a0->unkB0.y;
    sp1C.z = a0->unkB0.z;

    func_80196430(&sp1C, &a0->mat128);

    sp7C.x -= sp1C.x;
    sp7C.y -= sp1C.y;
    sp7C.z -= sp1C.z;

    if (func_80194BF4(&sp7C) == 0)
    {
        sp7C.x = -sp70.x;
        sp7C.y = -sp70.y;
        sp7C.z = -sp70.z;
    }

    func_80194D14(&sp70, a1, &sp94);
    sp2C = (f32) func_8019B35C((sp94.x * sp94.x) + (sp94.z * sp94.z));

    if (sp2C > 1000.0)  //! 1000.0f
        sp2C = 1000.0f;

    sp2C /= 1000.0;     //! 1000.0f
    sp2C = 1.0 - sp2C;  //! 1.0f - sp2C

    sp88.x = a2->x * sp2C;
    sp88.y = a2->y * sp2C;
    sp88.z = a2->z * sp2C;

    a0->unk74.x += sp88.x;
    a0->unk74.y += sp88.y;
    a0->unk74.z += sp88.z;
}

/* @ 22D008 for 0x1B4 */
void func_8017E838(struct ObjJoint* a0, struct MyVec3f* a1, struct MyVec3f* a2)
{
    UNUSED u32 sp84;
    UNUSED u32 sp80;
    UNUSED u32 sp7C;
    struct MyVec3f sp70;
    struct MyVec3f sp64;
    UNUSED u8 pad24[0x40];
    struct MyVec3f sp18;

    sp64.x = a1->x;
    sp64.y = a1->y;
    sp64.z = a1->z;

    sp18.x = a0->unkB0.x;
    sp18.y = a0->unkB0.y;
    sp18.z = a0->unkB0.z;

    func_80196430(&sp18, &a0->mat128);

    sp64.x -= sp18.x;
    sp64.y -= sp18.y;
    sp64.z -= sp18.z;

    sp64.x *= 0.01;    //! 0.01f;
    sp64.y *= 0.01;    //! 0.01f;
    sp64.z *= 0.01;    //! 0.01f;

    func_80194D14(a2, &sp64, &sp70);
    func_80194770(&sp70, 5.0f);

    a0->unk80.x += sp70.x;
    a0->unk80.y += sp70.y;
    a0->unk80.z += sp70.z;
}

/* @ 22D1BC for 0xA8 */
/* Note: a0 might not be ObjJoint*; have to decomp more files to see */
void func_8017E9EC(struct ObjJoint* a0)
{
    struct MyVec3f sp5C;
    Mat4 sp1C;
    f32 sp18;

    sp5C.x = a0->unkA4.x;
    sp5C.y = a0->unkA4.y;
    sp5C.z = a0->unkA4.z;

    func_80194BF4(&sp5C);
    sp18 = rss_vec3f(&a0->unkA4);
    func_801961F4(&sp1C, &sp5C, -sp18);
    func_80196614(&D_801B9DC8, &sp1C, &D_801B9DC8);
}

/* @ 22D264 for 0x90 */
s32 Unknown8017EA94(struct MyVec3f* vec, Mat4 matrix)
{
    if (vec->x >= matrix[2][2] && vec->x <= matrix[3][1] && vec->z >= matrix[3][0] && vec->z <= matrix[3][3])
        return 1;
    
    return 0;
}

/* @ 22D2F4 for 0x1DC */
s32 Unknown8017EB24(struct ObjHeader* a0, struct ObjHeader* a1)
{
    struct MyVec3f sp44;
    struct MyVec3f sp38;
    struct GdPlaneF* sp34;
    struct GdPlaneF* sp30;
    struct GdPlaneF sp18;

    set_cur_dynobj(a0);
    d_get_world_pos(&sp44);
    sp34 = d_get_plane();

    set_cur_dynobj(a1);
    d_get_world_pos(&sp38);
    sp30 = d_get_plane();

    sp18.vec0.x = sp34->vec0.x + sp30->vec0.x;
    sp18.vec0.y = sp34->vec0.y + sp30->vec0.y;
    sp18.vec0.z = sp34->vec0.z + sp30->vec0.z;
    sp18.vec1.x = sp34->vec1.x + sp30->vec1.x;
    sp18.vec1.y = sp34->vec1.y + sp30->vec1.y;
    sp18.vec1.z = sp34->vec1.z + sp30->vec1.z;

    D_801B9E08.x = sp38.x - sp44.x;
    D_801B9E08.y = sp38.y - sp44.y;
    D_801B9E08.z = sp38.z - sp44.z;

    if (D_801B9E08.x >= sp18.vec0.x)
    if (D_801B9E08.x <= sp18.vec1.x)
    if (D_801B9E08.z >= sp18.vec0.z)
    if (D_801B9E08.z <= sp18.vec1.z)
        return 1;
    
    return 0;
}

/* @ 22D4D0 for 0xCC */
s32 Unknown8017ED00(struct ObjHeader* a0, struct GdPlaneF* a1)
{
    struct MyVec3f sp1C;

    set_cur_dynobj(a0);
    d_get_world_pos(&sp1C);
    
    if (sp1C.x >= a1->vec0.x)
    if (sp1C.x <= a1->vec1.x)
    if (sp1C.z >= a1->vec0.z)
    if (sp1C.z <= a1->vec1.z)
        return 1;
    
    return 0;
}

/* @ 22D59C for 0x90 */
s32 Unknown8017EDCC(struct MyVec3f* a0, struct GdPlaneF* a1)
{
    if (a0->x >= a1->vec0.x)
    if (a0->x <= a1->vec1.x)
    if (a0->z >= a1->vec0.z)
    if (a0->z <= a1->vec1.z)
        return 1;
    
    return 0;
}

/* @ 22D62C for 0x1F8 */
s32 Unknown8017EE5C(struct GdPlaneF* a0, struct GdPlaneF* a1)
{
    if (a0->vec0.x >= a1->vec0.x)
    if (a0->vec0.x <= a1->vec1.x)
    if (a0->vec0.z >= a1->vec0.z)
    if (a0->vec0.z <= a1->vec1.z)
        return 1;
    
    if (a0->vec1.x >= a1->vec0.x)
    if (a0->vec1.x <= a1->vec1.x)
    if (a0->vec0.z >= a1->vec0.z)
    if (a0->vec0.z <= a1->vec1.z)
        return 1;
    
    if (a0->vec1.x >= a1->vec0.x)
    if (a0->vec1.x <= a1->vec1.x)
    if (a0->vec1.z >= a1->vec0.z)
    if (a0->vec1.z <= a1->vec1.z)
        return 1;
    
    if (a0->vec0.x >= a1->vec0.x)
    if (a0->vec0.x <= a1->vec1.x)
    if (a0->vec1.z >= a1->vec0.z)
    if (a0->vec1.z <= a1->vec1.z)
        return 1;
    
    return 0;
}

/* @ 22D824 for 0x1BC */
s32 func_8017F054(struct ObjHeader* a0, struct ObjHeader* a1)
{
    struct Links* curLink;
    struct ObjGroup* curGroup;
    UNUSED u32 sp54;
    Mat4* sp50;
    Mat4* sp4C;
    Mat4* sp48;
    Mat4* sp44;
    Mat4* sp40;
    UNUSED u8 pad20[0x18];
    struct MyVec3f sp1C;

    if (a1 != NULL)
    {
        set_cur_dynobj(a1);
        sp50 = d_get_matrix_ptr();
        sp44 = (Mat4*) d_get_rot_mtx_ptr();
        
        set_cur_dynobj(a0);
        sp4C = d_get_idn_mtx_ptr();
        sp40 = (Mat4*) d_get_rot_mtx_ptr();

        d_get_scale(&sp1C);
        sp48 = d_get_matrix_ptr();

        func_80196614(sp4C, sp50, sp48);
        func_80196614(sp4C, sp44, sp40);
        func_8019415C(sp40, &sp1C);
    } else {
        set_cur_dynobj(a0);
        sp48 = d_get_matrix_ptr();
        sp4C = d_get_idn_mtx_ptr();
        sp44 = (Mat4*) d_get_rot_mtx_ptr();

        d_get_scale(&sp1C);
        set_identity_mat4(*sp48);
        mat4_cpy(sp4C, sp44);
        func_8019415C(sp44, &sp1C);
    }

    set_cur_dynobj(a0);
    curGroup = d_get_att_objgroup();

    if (curGroup != NULL)
    {
        curLink = curGroup->link1C;
        while (curLink != NULL)
        {
            func_8017F054(curLink->obj, a0);
            curLink = curLink->next;
        }
    }
    return 0;
}

/* @ 22D9E0 for 0x1BC */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
s32 UnknownRecursive8017F210(struct ObjHeader* a0, struct ObjHeader* a1)
{
    struct Links* sp6C;
    struct ObjGroup* sp68;
    UNUSED u32 sp64;
    Mat4* sp60;
    Mat4* sp5C;
    Mat4* sp58;
    Mat4* sp54;
    Mat4* sp50;
    UNUSED u8 pad38[0x18];
    struct MyVec3f sp2C;
    s32 count = 0;
    
    count++;

    if (a1 != NULL)
    {
        set_cur_dynobj(a1);
        sp60 = d_get_matrix_ptr();
        sp54 = (Mat4*) d_get_rot_mtx_ptr();

        set_cur_dynobj(a0);
        sp5C = d_get_idn_mtx_ptr();
        sp50 = (Mat4*) d_get_rot_mtx_ptr();

        d_get_scale(&sp2C);
        func_80196614(sp5C, sp54, sp50);
        func_8019415C(sp50, &sp2C);
    } else {
        set_cur_dynobj(a0);
        sp58 = d_get_matrix_ptr();
        sp5C = d_get_idn_mtx_ptr();
        sp54 = (Mat4*) d_get_rot_mtx_ptr();
        
        d_get_scale(&sp2C);
        mat4_cpy(sp5C, sp54);
        func_8019415C(sp54, &sp2C);
    }

    set_cur_dynobj(a0);
    sp68 = d_get_att_objgroup();

    if (sp68 != NULL)
    {
        sp6C = sp68->link1C;
        while (sp6C != NULL)
        {
            count += UnknownRecursive8017F210(sp6C->obj, a0);
            sp6C = sp6C->next;
        }
    }
    return count;
}
#pragma GCC diagnostic pop

/* @ 22DB9C for 0x38; a0 might be ObjUnk200000* */
void Unknown8017F3CC(struct Unk8017F3CC* a0)
{
    func_80196430(&a0->unk20, *D_801B9E48);
}

/* @ 22DBD4 for 0x20 */
void func_8017F404(UNUSED f32 a0, UNUSED struct ObjHeader* a1, UNUSED struct ObjHeader* a2)
{ 
    UNUSED u8 pad[0x30];
}

/* @ 22DBF4 for 0x1A0 */
void func_8017F424(struct GdTriangleF* a0, struct GdTriangleF* a1, f32 a2)
{
    Mat4 sp40;
    struct GdTriangleF sp1C; 

    set_identity_mat4(sp40);

    if (a2 != 0.0f)
    {        
        sp1C.vec1.x = a0->vec1.x + (a1->vec1.x - a0->vec1.x) * a2;
        sp1C.vec1.y = a0->vec1.y + (a1->vec1.y - a0->vec1.y) * a2;
        sp1C.vec1.z = a0->vec1.z + (a1->vec1.z - a0->vec1.z) * a2;
        sp1C.vec2.x = a0->vec2.x + (a1->vec2.x - a0->vec2.x) * a2;
        sp1C.vec2.y = a0->vec2.y + (a1->vec2.y - a0->vec2.y) * a2;
        sp1C.vec2.z = a0->vec2.z + (a1->vec2.z - a0->vec2.z) * a2;

        func_8019415C(&sp40, &a0->vec0);
        func_80194220(&sp40, &sp1C.vec1);
        func_801942E4(&sp40, &sp1C.vec2);
    } else {    //L8017F568
        d_set_scale(a0->vec0.x, a0->vec0.y, a0->vec0.z);
        func_80194220(&sp40, &a0->vec1);
        func_801942E4(&sp40, &a0->vec2);
    } //L8017F5A4
    d_set_idn_mtx(&sp40);
}

/* @ 22DD94 for 0x1060; orig name: Unknown8017F5C4 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
void move_animator(struct ObjAnimator* animObj)
{
    struct AnimDataInfo* animData;  // array?
    Mat4* mtxArr;
    Mat4 localMtx;
    struct GdTriangleF* triPtr;  // Used as GdTriangleF[] or GdTriangleF* 
    struct GdTriangleF tri1;
    struct GdTriangleF tri2;
    s16 (*triHArr)[9];          // GdTriangleH[]?
    s16 (*vec3hArr)[3];         // MyVec3h[]?
    s16 (*planeHArr)[6];        // GdPlaneH[]?
    s16 (*camPlaneHArr)[6];     // camera GdPlaneH[]?
    struct ObjHeader* stubObj1 = NULL;  //used only for call to stubbed function
    struct ObjHeader* stubObj2 = NULL;  //used only for call to stubbed function
    UNUSED s32 sp50;
    UNUSED s32 sp4C;
    UNUSED s32 sp48;
    struct MyVec3f unusedVec;
    s32 sp38;
    s32 sp34;
    f32 sp30;
    f32 scale = 0.1f;
    struct AnimMtxVec* sp28;
    register struct Links* link;
    struct ObjHeader* linkedObj;

    if (animObj->fn48 != NULL)
        (*animObj->fn48)(animObj);
    
    if (animObj->unk14 == NULL)
        return;

    animData = (struct AnimDataInfo*) animObj->animdata->link1C->obj;

    if (animObj->unk44 != NULL)
    {
        animObj->unk28 = ((struct ObjAnimator *)animObj->unk44)->unk28 / ((struct ObjAnimator *)animObj->unk44)->unk24;
        animData += ((struct ObjAnimator *)animObj->unk44)->unk20;   //...why offset this pointer like this...
    }

    if (animData->type == 0)
        return;
    
    unusedVec.x = 4.0f;
    unusedVec.y = 1.0f;
    unusedVec.z = 1.0f;

    if (animObj->unk28 > (f32) animData->count)
        animObj->unk28 = 1.0f;
    else if (animObj->unk28 < 0.0f)
        animObj->unk28 = (f32) animData->count;

    sp38 = animObj->unk28;
    sp30 = animObj->unk28 - (f32) sp38;
    sp34 = sp38 + 1;

    if (sp34 > animData->count)   
        sp34 = 1;

    sp38--;
    sp34--;
    link = animObj->unk14->link1C;
    while (link != NULL)
    {
        linkedObj = link->obj;
        set_cur_dynobj(linkedObj);
        switch (animData->type)
        {
            case GD_ANIM_MATRIX:     // data = Mat4* (f32[4][4])
                mtxArr = (Mat4*) animData->data;
                /* This needs be be un-dereferenced pointer addition to make the registers match */
                d_set_idn_mtx(mtxArr + (s32)animObj->unk28);
                break;
            case GD_ANIM_3H_SCALED:     // data = s16(*)[3] or MyVec3h[]...
                vec3hArr = (s16(*)[3]) animData->data;

                d_get_scale(&tri1.vec0);
                tri2.vec0.x = tri1.vec0.x;
                tri2.vec0.y = tri1.vec0.y;
                tri2.vec0.z = tri1.vec0.z;

                d_get_init_pos(&tri1.vec2);
                tri2.vec2.x = tri1.vec2.x;
                tri2.vec2.y = tri1.vec2.y;
                tri2.vec2.z = tri1.vec2.z;

                tri1.vec1.x = (f32) vec3hArr[sp38][0] * scale;
                tri1.vec1.y = (f32) vec3hArr[sp38][1] * scale;
                tri1.vec1.z = (f32) vec3hArr[sp38][2] * scale;

                tri2.vec1.x = (f32) vec3hArr[sp34][0] * scale;
                tri2.vec1.y = (f32) vec3hArr[sp34][1] * scale;
                tri2.vec1.z = (f32) vec3hArr[sp34][2] * scale;

                func_8017F424(&tri1, &tri2, sp30);
                break;
            case GD_ANIM_3H:     // data = s16(*)[3] or MyVec3h[]...
                vec3hArr = (s16(*)[3]) animData->data;

                d_get_scale(&tri1.vec0);
                tri2.vec0.x = tri1.vec0.x;
                tri2.vec0.y = tri1.vec0.y;
                tri2.vec0.z = tri1.vec0.z;

                d_get_init_rot(&tri1.vec1);
                tri2.vec1.x = tri1.vec1.x;
                tri2.vec1.y = tri1.vec1.y;
                tri2.vec1.z = tri1.vec1.z;

                tri1.vec2.x = (f32) vec3hArr[sp38][0];
                tri1.vec2.y = (f32) vec3hArr[sp38][1];
                tri1.vec2.z = (f32) vec3hArr[sp38][2];

                tri2.vec2.x = (f32) vec3hArr[sp34][0];
                tri2.vec2.y = (f32) vec3hArr[sp34][1];
                tri2.vec2.z = (f32) vec3hArr[sp34][2];

                func_8017F424(&tri1, &tri2, sp30);
                break;
            case GD_ANIM_6H_SCALED:     // data = s16(*)[6] or GdPlaneH[]...
                planeHArr =(s16(*)[6]) animData->data;

                d_get_scale(&tri1.vec0);
                tri2.vec0.x = tri1.vec0.x;
                tri2.vec0.y = tri1.vec0.y;
                tri2.vec0.z = tri1.vec0.z;

                tri1.vec1.x = (f32) planeHArr[sp38][0] * scale;
                tri1.vec1.y = (f32) planeHArr[sp38][1] * scale;
                tri1.vec1.z = (f32) planeHArr[sp38][2] * scale;

                tri2.vec1.x = (f32) planeHArr[sp34][0] * scale;
                tri2.vec1.y = (f32) planeHArr[sp34][1] * scale;
                tri2.vec1.z = (f32) planeHArr[sp34][2] * scale;

                tri1.vec2.x = (f32) planeHArr[sp38][3];
                tri1.vec2.y = (f32) planeHArr[sp38][4];
                tri1.vec2.z = (f32) planeHArr[sp38][5];

                tri2.vec2.x = (f32) planeHArr[sp34][3];
                tri2.vec2.y = (f32) planeHArr[sp34][4];
                tri2.vec2.z = (f32) planeHArr[sp34][5];

                func_8017F424(&tri1, &tri2, sp30);
                break;
            case GD_ANIM_9H:     // data = s16(*)[9] or GdTriangleFH[]...
                triHArr = (s16(*)[9]) animData->data;

                tri1.vec0.x = (f32) triHArr[sp38][0] * scale;
                tri1.vec0.y = (f32) triHArr[sp38][1] * scale;
                tri1.vec0.z = (f32) triHArr[sp38][2] * scale;

                tri1.vec1.x = (f32) triHArr[sp38][3] * scale;
                tri1.vec1.y = (f32) triHArr[sp38][4] * scale;
                tri1.vec1.z = (f32) triHArr[sp38][5] * scale;

                tri1.vec2.x = (f32) triHArr[sp38][6];
                tri1.vec2.y = (f32) triHArr[sp38][7];
                tri1.vec2.z = (f32) triHArr[sp38][8];

                tri2.vec0.x = (f32) triHArr[sp34][0] * scale;
                tri2.vec0.y = (f32) triHArr[sp34][1] * scale;
                tri2.vec0.z = (f32) triHArr[sp34][2] * scale;

                tri2.vec1.x = (f32) triHArr[sp34][3] * scale;
                tri2.vec1.y = (f32) triHArr[sp34][4] * scale;
                tri2.vec1.z = (f32) triHArr[sp34][5] * scale;

                tri2.vec2.x = (f32) triHArr[sp34][6];
                tri2.vec2.y = (f32) triHArr[sp34][7];
                tri2.vec2.z = (f32) triHArr[sp34][8];

                func_8017F424(&tri1, &tri2, sp30);
                break;
            case GD_ANIM_CAMERA:    // s16(*)[6]?
                if (linkedObj->type == OBJ_TYPE_CAMERAS)
                {
                    camPlaneHArr = animData->data;

                    tri1.vec2.x = (f32) camPlaneHArr[sp38][0];
                    tri1.vec2.y = (f32) camPlaneHArr[sp38][1];
                    tri1.vec2.z = (f32) camPlaneHArr[sp38][2];

                    tri2.vec2.x = (f32) camPlaneHArr[sp38][3];
                    tri2.vec2.y = (f32) camPlaneHArr[sp38][4];
                    tri2.vec2.z = (f32) camPlaneHArr[sp38][5];

                    ((struct ObjCamera*)linkedObj)->unk14.x = tri1.vec2.x;
                    ((struct ObjCamera*)linkedObj)->unk14.y = tri1.vec2.y;
                    ((struct ObjCamera*)linkedObj)->unk14.z = tri1.vec2.z;

                    ((struct ObjCamera*)linkedObj)->unk34.x = tri2.vec2.x;
                    ((struct ObjCamera*)linkedObj)->unk34.y = tri2.vec2.y;
                    ((struct ObjCamera*)linkedObj)->unk34.z = tri2.vec2.z;
                }
                break;
            case GD_ANIM_TRI_F_2:     // GdTriangleF[]
                triPtr = (struct GdTriangleF*) animData->data;
                func_8017F424(&triPtr[sp38], &triPtr[sp34], sp30);
                break;
            case GD_ANIM_MTX_VEC:     // AnimMtxVec[]
                sp28 = &((struct AnimMtxVec*) animData->data)[sp38];
                d_set_idn_mtx(&sp28->matrix);
                d_set_scale(sp28->vec.x, sp28->vec.y, sp28->vec.z);
                break;
            case GD_ANIM_TRI_F_4:     // GdTriangleF* 
                triPtr = (struct GdTriangleF*) animData->data;
                set_identity_mat4(localMtx);
                func_8019415C(&localMtx, &triPtr->vec0);
                func_80194220(&localMtx, &triPtr->vec1);
                func_801942E4(&localMtx, &triPtr->vec2);
                d_set_idn_mtx(&localMtx);
                break;
            case GD_ANIM_STUB:
                if (stubObj1 == NULL)
                    stubObj1 = linkedObj;
                else 
                {
                    if (stubObj2 == NULL)
                    {
                        stubObj2 = linkedObj;
                        func_8017F404(animObj->unk28, stubObj1, stubObj2);
                    }
                    else
                        myPrintf("Too many objects to morph");
                }
                break;
            default:
                myPrintf("move_animator(): Unkown animation data type");
        }
        link = link->next;
    }
}
#pragma GCC diagnostic pop

/* @ 22EDF4 for 0x300 */
void Unknown80180624(struct ObjHeader* inputObj)
{
    UNUSED u32 spE4;
    UNUSED u32 spE0;
    UNUSED u32 spDC;
    struct MyVec3f spD0;
    struct MyVec3f spC4;
    struct GdMem801B9920* memState;
    Mat4 sp80;
    Mat4 sp40;
    UNUSED u32 pad34[3];
    struct ObjHeader* obj;
    UNUSED u32 pad2C;
    f32 sp28;

    memState = &D_801B9920;

    if (D_801A80F8 == NULL)
        return;

    sp28 = rss_vec3f(&D_801A80F8->unk40);
    sp28 /= 1000.0f;

    spD0.x = ((f32) (memState->unkD0 - memState->unkB8)) * sp28;
    spD0.y = ((f32) -(memState->unkD4 - memState->unkBC)) * sp28;
    spD0.z = 0.0f;

    func_80194E7C(&D_801A80F8->unkE8, &sp40);
    func_80196540(&spD0, &sp40);

    obj = inputObj;
    if ( (inputObj->unk12 & 0x0004) != 0 && (D_801B9920.unkD8 >> 31) != 0 )
    {
        func_80178114(8);
        /* abs() macro */
        if ( (memState->unkC0 < 0 ? -memState->unkC0 : memState->unkC0) + 
             (memState->unkC4 < 0 ? -memState->unkC4 : memState->unkC4) >= 11)
            func_80178114(16);
        
        switch(inputObj->type)
        {
            case OBJ_TYPE_JOINTS:
                ((struct ObjJoint*) obj)->mat128[3][0] += spD0.x;
                ((struct ObjJoint*) obj)->mat128[3][1] += spD0.y;
                ((struct ObjJoint*) obj)->mat128[3][2] += spD0.z;
                break;
            case OBJ_TYPE_GADGETS:
                break;
            case OBJ_TYPE_NETS:
                func_80194E7C(&((struct ObjNet*) obj)->mat128, &sp80);
                spC4.x = spD0.x;
                spC4.y = spD0.y;
                spC4.z = spD0.z;

                func_80196540(&spC4, &sp80);
                ((struct ObjNet*) obj)->matE8[3][0] += spD0.x;
                ((struct ObjNet*) obj)->matE8[3][1] += spD0.y;
                ((struct ObjNet*) obj)->matE8[3][2] += spD0.z;
                break;
            case OBJ_TYPE_PARTICLES:
                break;
            default: ;
        }
    }
}

/* @ 22F0F4 for 0x50; orig name: func_80180924*/
void move_animators(struct ObjGroup* group)
{
    restart_timer("move_animators");
    apply_to_obj_types_in_group(
        OBJ_TYPE_ANIMATORS,
        (void (*)(void*)) &move_animator,
        group
    );
    func_8018CEEC("move_animators");    //End timer? Print Timer?
}

/* @ 22F144 for 0x3C */
void func_80180974(struct ObjGroup* group)
{
    apply_to_obj_types_in_group(
        0x00FFFFFF,     // All Object types
        (void (*)(void*)) &Unknown80180624,
        group
    );
}

/* @ 22F180 for 0x624 */
void Unknown801809B0(struct ObjCamera* a0)
{
    struct ObjHeader* spEC;
    struct MyVec3f spE0;
    struct MyVec3f spD4;
    struct MyVec3f spC8;
    UNUSED u8 padBC[0xC8-0xBC];
    struct MyVec3f spB0;
    Mat4 sp70;
    UNUSED u8 pad30[0x70-0x30];
    Mat4* sp2C;
    struct GdMem801B9920* sp28;

    sp28 = &D_801B9920;
    if ((a0->unk2C & 0x10) == 0)
        return;
    
    spE0.x = spE0.y = spE0.z = 0.0f;
    spB0.x = spB0.y = spB0.z = 0.0f;

    if ((spEC = a0->unk30) != NULL)
    {
        set_cur_dynobj(spEC);
        d_get_world_pos(&spE0);
        d_get_matrix(&sp70);

        spC8.x = sp70[2][0] - a0->unk58;
        spC8.z = sp70[2][2] - a0->unk60;

        a0->unk58 += spC8.x * a0->unk180.y;
        a0->unk60 += spC8.z * a0->unk180.y;

        a0->unkA8[2][0] = a0->unk58;
        a0->unkA8[2][1] = 0.0f;
        a0->unkA8[2][2] = a0->unk60;

        a0->unkA8[0][0] = a0->unkA8[2][2];
        a0->unkA8[0][1] = 0.0f;
        a0->unkA8[0][2] = -a0->unkA8[2][0];

        a0->unkA8[1][0] = 0.0f;
        a0->unkA8[1][1] = 1.0f;
        a0->unkA8[1][2] = 0.0f;

        set_identity_mat4(&a0->unkA8);
    }
    else
        set_identity_mat4(&a0->unkA8);
    
    sp2C = &a0->unk64;
    if ((a0->unk2C & 0x4) != 0)
    {
        if (sp28->unk38 != NULL && sp28->unkF0->unk38 == NULL)
        {
            a0->unk174++;
            if (a0->unk174 > a0->unk170)
                a0->unk174 = 0;
            
            switch (a0->unk174)
            {
                case 0:
                    func_80178114(0x40);
                    break;
                case 1:
                case 2:
                    func_80178114(0x80);
                    break;
            }
        }
            
        if (sp28->unk18 != 0)
            a0->unk128.y += a0->unk134.y;
        
        if (sp28->unk1C != 0)
            a0->unk128.y -= a0->unk134.y;
        
        if (sp28->unk20 != 0)
            a0->unk128.x += a0->unk134.x;
        
        if (sp28->unk24 != 0)
            a0->unk128.x -= a0->unk134.x;
        
        a0->unk128.x = func_80194728(a0->unk128.x, 80.0f);
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
        #pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
        //! wtf; did he mean to multiply the unk140 vec float by un174...? Offset the wrong MyVec3f pointer?
        a0->unk4C.x = ((struct ObjCamera*) ((s32) a0 + a0->unk174 * 12))->unk140.x;
        a0->unk4C.y = ((struct ObjCamera*) ((s32) a0 + a0->unk174 * 12))->unk140.y;
        a0->unk4C.z = ((struct ObjCamera*) ((s32) a0 + a0->unk174 * 12))->unk140.z;
        #pragma GCC diagnostic pop

        func_80194880(a0->unk128.x, &a0->unk4C.y, &a0->unk4C.z);
        func_80194880(-a0->unk128.y, &a0->unk4C.x, &a0->unk4C.z);

        a0->unk40.x += (a0->unk4C.x - a0->unk40.x) * a0->unk17C;
        a0->unk40.y += (a0->unk4C.y - a0->unk40.y) * a0->unk17C;
        a0->unk40.z += (a0->unk4C.z - a0->unk40.z) * a0->unk17C;
    }
    else
        set_identity_mat4(sp2C);
    
    spD4.x = a0->unk40.x;
    spD4.y = a0->unk40.y;
    spD4.z = a0->unk40.z;

    spD4.x += spB0.x;
    spD4.y += spB0.y;
    spD4.z += spB0.z;

    func_80196614(sp2C, &a0->unkA8, &a0->unkA8);
    func_80196540(&spD4, &a0->unkA8);

    a0->unk14.x = spD4.x;
    a0->unk14.y = spD4.y;
    a0->unk14.z = spD4.z;

    a0->unk14.x += spE0.x;
    a0->unk14.y += spE0.y;
    a0->unk14.z += spE0.z;
}

/* @ 22F7A4 for 0x38 */
void func_80180FD4(struct ObjGroup* group)
{
    apply_to_obj_types_in_group(
        OBJ_TYPE_CAMERAS,
        (void (*)(void*)) &Unknown801809B0,
        group
    );
}

/* @ 22F7DC for 0x36C*/
void Unknown8018100C(struct ObjLight* light)
{
    Mat4 mtx;
    UNUSED u32 pad1C[3];

    if (light->unk40 == 3)
    {
        if (light->unk30 > 0.0) //! 0.0f
            light->unk30 -= 0.2; //! 0.2f
        
        if (light->unk30 < 0.0f)
            light->unk30 = 0.0f;
        
        if ((light->unk3C & 0x1) != 0)
            light->unk30 = 1.0f;
        
        light->unk3C &= ~1;
    }
    // if (1)?
    return;
    //! unreachable
    light->unk74.x += light->unk80.x;
    light->unk74.y += light->unk80.y;
    light->unk74.z += light->unk80.z;

    if (light->unk74.x > 500.0f || light->unk74.y < -500.0f)    //! unk74.x for second comparison?
        light->unk80.x = -light->unk80.x;
    
    if (light->unk74.y > 500.0f || light->unk74.y < -500.0f)
        light->unk80.y = -light->unk80.y;
    
    if (light->unk74.z > 500.0f || light->unk74.z < -500.0f)
        light->unk80.z = -light->unk80.z;
    
    return;
    //! more unreachable
    D_801A81C0 += 1.0;  //! 1.0f
    D_801A81C4 += 0.6;  //! 0.6f

    set_identity_mat4(&mtx);
    func_80194A54(&mtx, 1, light->unk68.y);
    func_80194A54(&mtx, 0, light->unk68.x);
    func_80194A54(&mtx, 2, light->unk68.z);
    func_80196540(&light->unk8C, &mtx);

    light->unk74.x = light->unk8C.x;
    light->unk74.y = light->unk8C.y;
    light->unk74.z = light->unk8C.z;
    return;
    //! more unreachable
    func_80196540(&light->unk80, &mtx);
    imout();
}

/* @ 22FB48 for 0x38 */
void func_80181378(struct ObjGroup* group)
{
    apply_to_obj_types_in_group(
        OBJ_TYPE_LIGHTS,
        (void (*)(void*)) &Unknown8018100C,
        group
    );
}

/* @ 22FB80 for 0xAC */
/* This function runs apply_fn functions to group in a static group pointer */
void func_801813B0(void)
{
    int i;

    if (D_801A8050 != 0)
    {
        reset_gadgets_in_grp(D_801B9E14);
        func_80181378(D_801B9E14);
        func_80183570(D_801B9E14);
        move_animators(D_801B9E14);
        
        for (i = 0; i <= 0; i++)
            func_801936C4(D_801B9E14);
        
        func_80180FD4(D_801B9E14);
    }
}

/* @ 22FC2C for 0x98 */
void func_8018145C(struct ObjView* a0)
{
    func_8018D420("movement");
    D_801B9DB8 = a0->unk24;
    D_801B9DBC = a0;
    if ((D_801B9E14 = a0->unk28) != NULL)
        func_801813B0();
    if ((D_801B9E14 = a0->unk2C) != NULL)
        func_801813B0();
    imout();
}

/* @ 22FCC4 for 0x44*/
void func_801814F4(struct ObjGroup* group)
{
    func_80193848(group);
    apply_to_obj_types_in_group(
        OBJ_TYPE_GADGETS,
        (void (*)(void*)) &reset_gadget,
        group
    );
}

/* @ 22FD08 for 0x9C; orig name: func_80181538*/
void null_obj_lists(void)
{
    D_801B9E44 = 0;
    D_801B9E58 = 0;
    D_801B9E5C = 0;
    D_801B9E60 = 0;
    D_801B9E64 = 0;
    D_801B9E68.count = 0;

    D_801B9E4C = NULL;
    D_801B9E50 = NULL;
    D_801B9E88 = NULL;
    D_801B9E84 = NULL;
    D_801B9E54 = NULL;
    D_801B9E80 = NULL;
    D_801B9E8C = NULL;
    D_801B9E90 = NULL;

    func_80193B10();
    func_80191EE8();
}
