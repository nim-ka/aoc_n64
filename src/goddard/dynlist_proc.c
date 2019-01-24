#include <ultra64.h>

#include "sm64.h"
#include "gd_types.h"
#include "bad_declarations.h"
#include "gd_main.h"

#include "game_over_2.h"
#include "mario_head_1.h"
#include "mario_head_3.h"
#include "dynlist_proc.h"
#include "old_obj_fn.h"
#include "profiler_utils.h"
#include "joint_fns.h"
#include "skin_fns.h"
#include "matrix_fns.h"
#include "half_6.h"
#include "mario_head_6.h"

// types
struct DynObjInfo {
    char name[8];
    struct ObjHeader *obj;
    s32 id;
    s32 unk;
};
// "convenient" accessors for the DynList entry data 
#define Dyn1AsInt(dyn) ((dyn)->w1.word)
#define Dyn1AsPtr(dyn) ((dyn)->w1.ptr)
#define Dyn1AsStr(dyn) ((dyn)->w1.str)
#define Dyn1AsID(dyn)  ((DynId) ((dyn)->w1.ptr))

#define Dyn2AsInt(dyn) ((dyn)->w2.word)
#define Dyn2AsPtr(dyn) ((dyn)->w2.ptr)
#define Dyn2AsStr(dyn) ((dyn)->w2.str)
#define Dyn2AsID(dyn)  ((DynId) ((dyn)->w2.ptr))

#define DynVec(dyn)  (&(dyn)->vec)
#define DynVecX(dyn) ((dyn)->vec.x)
#define DynVecY(dyn) ((dyn)->vec.y)
#define DynVecZ(dyn) ((dyn)->vec.z)

// data
static struct DynObjInfo *sGdDynObjList = NULL; // @ 801A8250; info for all loaded/made dynobjs
static struct ObjHeader *sDynListCurObj = NULL; // @ 801A8254
static struct GdPlaneF sGdNullPlaneF = {        // @ 801A8258
    { 0.0, 0.0, 0.0 },
    { 0.0, 0.0, 0.0 }
};
static s32 sGdDynObjIdIsInt = FALSE;            // @ 801A8270; str (0) or int (1) for Dyn Obj ID

// bss
static char sIntDynIdBuffer[8];                // @ 801B9F00; Another DynObjId string buffer
static struct DynObjInfo sNullDynObjInfo;      // @ 801B9F08
static char sDynIdBuf[8];                      // @ 801B9F20; small buf for printing dynid to?
static s32 sUnnamedObjCount;                   // @ 801B9F28; used to print empty string ids (not NULL char *) to sDynIdBuf
static s32 sLoadedDynObjs;                     // @ 801B9F2C; total loaded dynobjs
static struct DynObjInfo *sDynListCurInfo;     // @ 801B9F30; info for most recently added object
static struct DynObjInfo *sSecondaryInfoStash; // @ 801B9F34; what is it's purpose?
static struct DynObjInfo *sStashedDynObjInfo;  // @ 801B9F38
static struct ObjHeader *sStashedDynObj;       // @ 801B9F3C
static s32 sDynNetCount;                       // @ 801B9F40
static char sDynNetIdBuf[0x20];                // @ 801B9F48
static char sBackBuf[0x100];                   // @ 801B9F68

// necessary foreward declarations
void d_add_net_with_subgroup(s32, DynId);
void d_end_net_subgroup(DynId);
void d_attach_net_to_joint(s32, DynId);
void d_addto_group(DynId);
void d_link_with(DynId);
void d_link_with_ptr(void *);
void d_set_normal(f32, f32, f32);
void d_make_vertex(struct MyVec3f *);
void d_set_rotation(f32, f32, f32);
void d_center_of_gravity(f32, f32, f32);
void d_set_shape_offset(f32, f32, f32);
void d_clear_flags(s32);
void d_attach(DynId);
void d_attach_to(s32, struct ObjHeader *);
void d_attachto_dynid(s32, DynId);
void d_set_att_offset(struct MyVec3f *);
void d_set_nodegroup(DynId);
void d_set_matgroup(DynId);
void d_set_skinshape(DynId);
void d_set_planegroup(DynId);
void d_set_shapeptr(DynId);
void d_friction(f32, f32, f32);
void d_set_spring(f32);
void d_set_ambient(f32, f32, f32);
void d_set_control_type(s32);
void d_set_skin_weight(s32, f32);
void d_set_id(s32);
void d_set_material(void *, s32);
void d_map_materials(DynId);
void d_map_vertices(DynId);
void d_set_texture_st(f32, f32);
void d_use_texture(void *);
void d_make_netfromshapeid(DynId);
void d_make_netfromshape_ptrptr(struct ObjShape **);
void add_to_dynobj_list(struct ObjHeader *, DynId);

/* 2320E0 -> 232110; orig name: func_80183910 */
void push_dynobj_stash(void)
{
    sStashedDynObjInfo = sDynListCurInfo;
    sStashedDynObj = sDynListCurObj;
}

/* 232110 -> 232140; orig name: func_80183940 */
void pop_dynobj_stash(void)
{
    sDynListCurObj = sStashedDynObj;
    sDynListCurInfo = sStashedDynObjInfo;
}

/* 232140 -> 2321B0; orig name: func_80183970 */
void reset_dynlist(void)
{
    sUnnamedObjCount = 0;
    sLoadedDynObjs = 0;
    sDynIdBuf[0] = '\0';
    sGdDynObjList = NULL;
    sDynListCurObj = NULL;
    sDynNetCount = 0;
    sGdDynObjIdIsInt = FALSE;
    gd_strcpy(sNullDynObjInfo.name, "NullObj");
}

/* 2321B0 -> 2329EC; orig name: func_801839E0 */
struct ObjHeader *proc_dynlist(struct DynList *dylist)
{
    UNUSED u32 pad[2];

    if (dylist++->cmd != 0xD1D4)
        fatal_printf("proc_dynlist() not a valid dyn list");
    
    while (dylist->cmd != 58)
    {
        switch (dylist->cmd)
        {
            case 43:
                d_copystr_to_idbuf(Dyn1AsStr(dylist)); break;
            case 15:
                d_makeobj(Dyn2AsInt(dylist), Dyn1AsID(dylist)); break;
            case 46:
                d_add_net_with_subgroup(Dyn2AsInt(dylist), Dyn1AsID(dylist)); break;
            case 48:
                d_end_net_subgroup(Dyn1AsID(dylist)); break;
            case 47:
                d_attach_net_to_joint(Dyn2AsInt(dylist), Dyn1AsID(dylist)); break;
            case 16:
                d_start_group(Dyn1AsID(dylist)); break;
            case 17:
                d_end_group(Dyn1AsID(dylist)); break;
            case 18:
                d_addto_group(Dyn1AsID(dylist)); break;
            case 30:
                d_use_obj(Dyn1AsID(dylist)); break;
            case 28:
                d_link_with(Dyn1AsID(dylist)); break;
            case 50:
                d_add_valptr(
                    Dyn1AsID(dylist),
                    (u32) DynVecY(dylist),
                    Dyn2AsInt(dylist),
                    (u32) DynVecX(dylist)
                );
                break;
            case 29:
                d_link_with_ptr(Dyn1AsPtr(dylist)); break;
            case 12:
                proc_dynlist(Dyn1AsPtr(dylist)); break;
            case 0:
                dynid_is_int(Dyn2AsInt(dylist)); break;
            case 1:
                d_set_init_pos(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 2:
                d_set_rel_pos(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 3:
                d_set_world_pos(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 4:
                d_set_normal(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 5:
                d_set_scale(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 49:
                d_make_vertex(DynVec(dylist)); break;
            case 6:
                d_set_rotation(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 27:
                d_center_of_gravity(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 26:
                d_set_shape_offset(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 44:
                d_set_parm_f(Dyn2AsInt(dylist), DynVecX(dylist)); break;
            case 45:
                d_set_parm_ptr(Dyn2AsInt(dylist), Dyn1AsPtr(dylist)); break;
            case 8:
                d_set_flags(Dyn2AsInt(dylist)); break;
            case 9:
                d_clear_flags(Dyn2AsInt(dylist)); break;
            case 7:
                d_set_objheader_flag(Dyn2AsInt(dylist)); break;
            case 39:
                d_attach(Dyn1AsID(dylist)); break;
            case 40:
                d_attachto_dynid(Dyn2AsInt(dylist), Dyn1AsID(dylist)); break;
            case 41:
                d_set_att_offset(DynVec(dylist)); break;
            case 21:
                d_set_nodegroup(Dyn1AsID(dylist)); break;
            case 20:
                d_set_matgroup(Dyn1AsID(dylist)); break;
            case 22:
                d_set_skinshape(Dyn1AsID(dylist)); break;
            case 23:
                d_set_planegroup(Dyn1AsID(dylist)); break;
            case 24:
                d_set_shapeptrptr(Dyn1AsPtr(dylist)); break;
            case 25:
                d_set_shapeptr(Dyn1AsID(dylist)); break;
            case 19:
                d_set_type(Dyn2AsInt(dylist)); break;
            case 13:
                d_set_colour_num(Dyn2AsInt(dylist)); break;
            case 10:
                d_friction(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 11:
                d_set_spring(DynVecX(dylist)); break;
            case 33:
                d_set_ambient(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 34:
                d_set_diffuse(DynVecX(dylist), DynVecY(dylist), DynVecZ(dylist)); break;
            case 31:
                d_set_control_type(Dyn2AsInt(dylist)); break;
            case 32:
                d_set_skin_weight(Dyn2AsInt(dylist), DynVecX(dylist)); break;
            case 35:
                d_set_id(Dyn2AsInt(dylist)); break;
            case 36:
                d_set_material(Dyn1AsPtr(dylist), Dyn2AsInt(dylist)); break;
            case 37:
                d_map_materials(Dyn1AsID(dylist)); break;
            case 38:
                d_map_vertices(Dyn1AsID(dylist)); break;
            case 53:
                d_set_texture_st(DynVecX(dylist), DynVecY(dylist)); break;
            case 52:
                d_use_texture(Dyn2AsPtr(dylist)); break;
            case 54:
                d_make_netfromshapeid(Dyn1AsID(dylist)); break;
            case 55:
                d_make_netfromshape_ptrptr(Dyn1AsPtr(dylist)); break;
            default:
                fatal_printf("proc_dynlist(): unkown command");
        }
        dylist++;
    }

    return sDynListCurObj;
}

/* 2329EC -> 232A90; orig name: func_8018421C */
void d_copystr_to_idbuf(char *str)
{
    if (str != NULL)
    {
        if (str[0] == '\0') { sprintf(sDynIdBuf, "__%d", ++sUnnamedObjCount); } 
        else { gd_strcpy(sDynIdBuf, str); }
    } else {
        sDynIdBuf[0] = '\0';
    }
}

/* 232A90 -> 232B38 */
void Unknown801842C0(char *str)
{
    char buf[0xff + 1];

    if (str != NULL)
    {
        if (str[0] == '\0') { sprintf(buf, "__%d", ++sUnnamedObjCount); } 
        else { gd_strcpy(buf, str); }
    } else { 
        buf[0] = '\0';
    }

    gd_strcat(sDynIdBuf, buf);
}

/* 232B38 -> 232B6C; orig name: func_80184368 */
void cpy_idbuf_to_backbuf(void)
{
    gd_strcpy(sBackBuf, sDynIdBuf);
}

/* 232B6C -> 232BA0; orig name: func_8018439C */
void cpy_backbuf_to_idbuf(void)
{
    gd_strcpy(sDynIdBuf, sBackBuf);
}

/* 232BA0 -> 232CC0; orig name: func_801843D0 */
struct DynObjInfo *get_dynobj_info(DynId id)
{
    struct DynObjInfo *foundDynobj;
    char buf[0xff + 1];
    s32 i;

    if (sLoadedDynObjs == 0) { return NULL; }

    if (sGdDynObjIdIsInt)
        sprintf(buf, "N%d", DynIdAsInt(id));
    else
        gd_strcpy(buf, DynIdAsStr(id)); //strcpy

    gd_strcat(buf, sDynIdBuf); //strcat
    foundDynobj = NULL;
    for (i = 0; i < sLoadedDynObjs; i++)
    {
        if (gd_str_not_equal(sGdDynObjList[i].name, buf) == 0)  //strcmp equal
        {
            foundDynobj = &sGdDynObjList[i];
            break; 
        } 
    }

    return foundDynobj;
}

/* 232CC0 -> 232D1C */
void Unknown801844F0(void)
{
    UNUSED int pad;

    if (sLoadedDynObjs == 0) { return; }

    gd_free(sGdDynObjList);    //free objlist?
    sLoadedDynObjs = 0;
    sGdDynObjList = NULL;
}

/* 232D1C -> 232DD0; orig name: func_8018454C */
void d_add_net_with_subgroup(UNUSED s32 a0, DynId id)
{
    /* This makes a ObjNet */
    d_makeobj(D_NET, id);
    d_set_objheader_flag(2);
    sprintf(sDynNetIdBuf, "c%d", ++sDynNetCount);
    d_set_type(4);
    cpy_idbuf_to_backbuf();
    d_copystr_to_idbuf(sDynNetIdBuf);
    d_start_group(id);
    cpy_backbuf_to_idbuf();
    d_use_obj(id);
    sSecondaryInfoStash = sDynListCurInfo;
}

/* 232DD0 -> 232E3C; orig name: func_80184600 */
void d_end_net_subgroup(DynId id)
{
    d_use_obj(id);
    cpy_idbuf_to_backbuf();
    d_copystr_to_idbuf(sDynNetIdBuf);
    d_end_group(id);
    d_set_nodegroup(id);
    cpy_backbuf_to_idbuf();
    sSecondaryInfoStash = NULL;
}

/* 232E3C -> 232EB8 */
void d_attach_net_to_joint(UNUSED s32 a0, DynId id)
{
    UNUSED struct DynObjInfo *sp24 = sDynListCurInfo;
    UNUSED u32 pad[2];

    d_makeobj(D_JOINT, id);
    d_set_type(3);
    d_set_shapeptrptr(NULL);
    d_attach_to(0xD, sSecondaryInfoStash->obj);
    sSecondaryInfoStash = sDynListCurInfo;
}

/* 232EB8 -> 232F30; orig name: func_801846E8 */
void d_make_netfromshapeid(DynId id)
{
    struct DynObjInfo *dyninfo = get_dynobj_info(id);
    struct ObjNet *net;

    if (dyninfo == NULL)
        fatal_printf("dMakeNetFromShape(\"%s\"): Undefined object", DynIdAsStr(id));
    
    net = make_netfromshape((struct ObjShape *)dyninfo->obj);
    add_to_dynobj_list(&net->header, NULL);
}

/* 232F30 -> 232F78; org name: func_80184760 */
void d_make_netfromshape_ptrptr(struct ObjShape **objptr)
{
    UNUSED u32 pad;
    struct ObjNet *net = make_netfromshape(*objptr);

    printf("dMakeNetFromShapePtrPtr\n");

    add_to_dynobj_list(&net->header, NULL);
}

/* 232F78 -> 233214; orig name: func_801847A8 */
#define DYNOBJ_LIST_SZ 3000
void add_to_dynobj_list(struct ObjHeader *newobj, DynId id)
{
    UNUSED u32 pad;
    char idbuf[0x100];

    start_memtracker("dynlist");

    if (sGdDynObjList == NULL)
    {
        sGdDynObjList = gd_malloc_temp(DYNOBJ_LIST_SZ * sizeof(struct DynObjInfo));
        if (sGdDynObjList == NULL)
            fatal_printf("dMakeObj(): Cant allocate dynlist memory");
    }

    stop_memtracker("dynlist");

    if (sGdDynObjIdIsInt)
    {
        sprintf(idbuf, "N%d", DynIdAsInt(id));
        id = NULL;
    } else {
        sprintf(idbuf, "U%d", ((u32) sLoadedDynObjs)+1);
    }

    if (DynIdAsStr(id) != NULL) {
        if (get_dynobj_info(id) != NULL) 
        {
            fatal_printf("dMakeObj(\"%s\"): Object with same name already exists", DynIdAsStr(id));
        }
        gd_strcpy(sGdDynObjList[sLoadedDynObjs].name, DynIdAsStr(id));
    } else {
        gd_strcpy(sGdDynObjList[sLoadedDynObjs].name, idbuf);
    }

    gd_strcat(sGdDynObjList[sLoadedDynObjs].name, sDynIdBuf);

    if (gd_strlen(sGdDynObjList[sLoadedDynObjs].name) > 7)   //strlen
    {
        fatal_printf("dyn list obj name too long '%s'", sGdDynObjList[sLoadedDynObjs].name);
    }

    sGdDynObjList[sLoadedDynObjs].id = sLoadedDynObjs;
    sDynListCurInfo = &sGdDynObjList[sLoadedDynObjs];
    sGdDynObjList[sLoadedDynObjs++].obj = newobj;

    //! A good place to bounds-check your array is
    //! after you finish writing a new member to it.
    if (sLoadedDynObjs >= DYNOBJ_LIST_SZ)
        fatal_printf("dMakeObj(): Too many dynlist objects");

    sDynListCurObj = newobj;
}
#undef DYNOBJ_LIST_SZ

/* 233214 -> 233288; orig name: func_80184A44 */
char *print_int_dynid(DynId id)
{
    if (id && sGdDynObjIdIsInt)
    {
        sprintf(sIntDynIdBuffer, "N%d", DynIdAsInt(id));
        return sIntDynIdBuffer;
    }

    return NULL;
}

/* 233288 -> 23358C */
struct ObjHeader *d_makeobj(enum DObjTypes type, DynId id)
{
    struct ObjHeader *dobj;
    UNUSED struct ObjGroup *dgroup;

    switch (type)
    {
        case D_CAR_DYNAMICS:
            fatal_printf("dmakeobj() Car dynamics are missing!");
            break;
        case D_JOINT:
            dobj = &make_joint(0, 0.0f, 0.0f, 0.0f)->header;
            break;
        case D_ANOTHER_JOINT:
            dobj = &make_joint(0, 0.0f, 0.0f, 0.0f)->header;
            break;
        case D_NET:
            dobj = &make_net(0, NULL, NULL, NULL, NULL)->header;
            break;
        case D_GROUP:
            dobj = &make_group(0)->header;
            dgroup = (struct ObjGroup *)dobj;
            break;
        case D_DATA_GRP:
            d_makeobj(D_GROUP, id);
            ((struct ObjGroup *)sDynListCurObj)->unk30 = 1;
            //! bad goddard. set the return of the d_makeobj call to `dobj` and return that. 
            //! Or, use a goto
            #pragma GCC diagnostic push
            #pragma GCC diagnostic ignored "-Wreturn-type"
            return;
            #pragma GCC diagnostic pop
        case D_CAMERA:
            dobj = &make_camera(0, NULL)->header;
            break;
        case D_BONE:
            dobj = &make_bone(0, NULL, NULL, 0)->header;
            break;
        case D_PARTICLE:
            dobj = &make_particle(0, 0, 0.0f, 0.0f, 0.0f)->header;
            break;
        case D_VERTEX:
            dobj = &gd_make_vertex(0.0f, 0.0f, 0.0f)->header;
            break;
        case D_FACE:
            dobj = &make_face_1(1.0, 1.0, 1.0)->header;
            break;
        case D_PLANE:
            dobj = &make_plane(FALSE, NULL)->header;
            break;
        case D_MATERIAL:
            dobj = &make_material(0, NULL, 0)->header;
            break;
        case D_SHAPE:
            dobj = &make_shape(0, print_int_dynid(id))->header;
            break;
        case D_GADGET:
            dobj = &make_gadget(0, 0)->header;
            break;
        case D_LABEL:
            //! the final 3 args should be floats, but...
            dobj = &make_label(NULL, NULL, 8, 0, 0, 0)->header;
            break;
        case D_VIEW:
            dobj = &make_view(NULL, 0xE6018, 2, 0, 0, 0, 0, NULL)->header;
            break;
        case D_ANIMATOR:
            dobj = &make_animator()->header;
            break;
        case D_LIGHT:
            dobj = &make_light(0, NULL, 0)->header;
            addto_group(sGdLightGroup, dobj);
            break;
        default:
            fatal_printf("dMakeObj(): Unkown object type");
    }

    add_to_dynobj_list(dobj, id);
    return dobj;
}

/* 23358C -> 233654 */
void d_attach(DynId id)
{
    struct DynObjInfo *info;
    
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dAttach(\"%s\"): Undefined object", DynIdAsStr(id));
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS: 
            break;
        default: 
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dAttach()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 233654 -> 2339FC */
void d_attach_to(s32 a0, struct ObjHeader *obj)
{
    UNUSED u32 pad4C;
    struct ObjGroup *attgrp;
    UNUSED u32 pad[2];
    UNUSED struct DynObjInfo *info = sDynListCurInfo;
    struct MyVec3f dynobjPos;   // transformed into attach offset
    struct MyVec3f objPos;

    push_dynobj_stash();

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");

    // find or generate attachment groups
    switch (obj->type)
    {
        case OBJ_TYPE_JOINTS:
            if ((attgrp = ((struct ObjJoint *)obj)->unk1F8) == NULL)
            {
                attgrp = ((struct ObjJoint *)obj)->unk1F8 = make_group(0);
            }
            break;
        case OBJ_TYPE_NETS:
            if ((attgrp = ((struct ObjNet *)obj)->unk1D4) == NULL)
            {
                attgrp = ((struct ObjNet *)obj)->unk1D4 = make_group(0);
            }
            break;
        case OBJ_TYPE_PARTICLES:
            if ((attgrp = ((struct ObjParticle *)obj)->unkB4) == NULL)
            {
                attgrp = ((struct ObjParticle *)obj)->unkB4 = make_group(0);
            }
            break;
        case OBJ_TYPE_ANIMATORS:
            if ((attgrp = ((struct ObjAnimator *)obj)->unk30) == NULL)
            {
                attgrp = ((struct ObjAnimator *)obj)->unk30 = make_group(0);
            }
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
               "dAttachTo()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }

    if (group_contains_obj(attgrp, sDynListCurObj)) { return; }

    addto_group(attgrp, sDynListCurObj);

    if (a0 & 9)
    {
        d_get_world_pos(&dynobjPos);
        set_cur_dynobj(obj);
        d_get_world_pos(&objPos);

        dynobjPos.x -= objPos.x;
        dynobjPos.y -= objPos.y;
        dynobjPos.z -= objPos.z;
    } 

    pop_dynobj_stash();
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unk1FC = a0;
            ((struct ObjJoint *)sDynListCurObj)->unk20C = obj;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk1E4 = a0;
            ((struct ObjNet *)sDynListCurObj)->unk1E8 = obj;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)sDynListCurObj)->unkB8 = a0;
            ((struct ObjParticle *)sDynListCurObj)->unkBC = obj;
            break;
        case OBJ_TYPE_ANIMATORS:
            ((struct ObjAnimator *)sDynListCurObj)->unk34 = a0;
            ((struct ObjAnimator *)sDynListCurObj)->unk44 = obj;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dAttachTo()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }

    if (a0 & 9) { d_set_att_offset(&dynobjPos); }
}

/* 2339FC -> 233AA0; orig name: func_8018522C */
void d_attachto_dynid(s32 a0, DynId id)
{
    struct DynObjInfo *info;

    if (id == NULL) { return; }
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dAttachTo(\"%s\"): Undefined object", DynIdAsStr(id));
    d_attach_to(a0, info->obj);
}

/* 233AA0 -> 233AEC; orig name: func_801852D0 */
void copy_bytes(u8 *src, u8 *dst, s32 num)
{
    if (num == 0) { return; }
    while ( num-- ) { *dst++ = *src++; }
}

/* 233AEC -> 2340A8; orig name: func_8018531C */
// TODO: create types for all animation datas...?
void alloc_animdata(struct ObjAnimator *a0)
{
    UNUSED u32 pad5C;
    // probably should be MyVec3f[3], not triangle...
    struct GdTriangleF tri;           //+58; temp float for converting half to f32?
    s16 (*halfarr)[9];                //+54; data to convert into a AnimMtxVec
    struct AnimDataInfo *curAnimSrc;  //+50; source animation data...
    struct AnimDataInfo *animDst;     //+4c; destination anim data II
    struct AnimDataInfo *animDataArr; //+48; start of allocated anim data memory
    struct ObjGroup *animgrp;         //+44
    s32 datasize;                     //+40; anim data allocation size?
    s32 dataIdx;                      //+3C; byte count?
    s32 animCnt;                      //+38; count of animdata "info" structs
    s32 i;                            //+34
    void *allocSpace;                 //+30; allocated animdata space
    f32 sp2C = 0.1f;
    struct AnimMtxVec *curMtxVec;     //+28
    UNUSED u32 pad20;

    start_memtracker("animdata");

    if ((animgrp = a0->animdata) == NULL)
        fatal_printf("no anim group");
    
    if ((curAnimSrc = (struct AnimDataInfo *)animgrp->link1C->obj) == NULL)
        fatal_printf("no animation data");

    // count number of array-ed animation data structs
    animDst = curAnimSrc;
    animCnt = 0;
    while (animDst++->count >= 0) { animCnt++; }
    
    animDst = gd_malloc_perm(animCnt * sizeof(struct AnimDataInfo));   //gd_alloc_perm
    if ((animDataArr = animDst) == NULL)
        fatal_printf("cant allocate animation data");

    for (i = 0; i < animCnt; i++)
    { 
        allocSpace = NULL;
        if (curAnimSrc->type != 0)
        {
            switch (curAnimSrc->type) 
            {
                case GD_ANIM_CAMERA    : datasize = sizeof(s16[6]); break;
                case GD_ANIM_3H_SCALED : datasize = sizeof(s16[3]); break;
                case GD_ANIM_3H        : datasize = sizeof(s16[3]); break;
                case GD_ANIM_6H_SCALED : datasize = sizeof(s16[6]); break;
                case GD_ANIM_TRI_F_2   : datasize = sizeof(f32[3][3]); break;
                /* This function will convert the s16[9] array into a struct AnimMtxVec */
                case GD_ANIM_9H        : datasize = sizeof(struct AnimMtxVec); break;
                case GD_ANIM_MATRIX    : datasize = sizeof(Mat4); break;
                default:
                    fatal_printf("unknown anim type for allocation");
                break;
            }
            
            allocSpace = gd_malloc_perm(curAnimSrc->count * datasize);  //gd_alloc_perm
            if (allocSpace == NULL)
                fatal_printf("cant allocate animation data");
            
            if (curAnimSrc->type == GD_ANIM_9H)
            {
                for (dataIdx = 0; dataIdx < curAnimSrc->count; dataIdx++)
                {   
                    halfarr = &((s16 (*)[9])curAnimSrc->data)[dataIdx];
                    curMtxVec = &((struct AnimMtxVec *)allocSpace)[dataIdx];

                    tri.vec0.x = (f32) (*halfarr)[0] * sp2C;
                    tri.vec0.y = (f32) (*halfarr)[1] * sp2C;
                    tri.vec0.z = (f32) (*halfarr)[2] * sp2C;
                    tri.vec1.x = (f32) (*halfarr)[3] * sp2C;
                    tri.vec1.y = (f32) (*halfarr)[4] * sp2C;
                    tri.vec1.z = (f32) (*halfarr)[5] * sp2C;
                    tri.vec2.x = (f32) (*halfarr)[6];
                    tri.vec2.y = (f32) (*halfarr)[7];
                    tri.vec2.z = (f32) (*halfarr)[8];

                    set_identity_mat4(&curMtxVec->matrix);
                    func_80194220(&curMtxVec->matrix, &tri.vec1);
                    func_801942E4(&curMtxVec->matrix, &tri.vec2);

                    ((struct AnimMtxVec *)allocSpace)[dataIdx].vec.x = tri.vec0.x;
                    ((struct AnimMtxVec *)allocSpace)[dataIdx].vec.y = tri.vec0.y;
                    ((struct AnimMtxVec *)allocSpace)[dataIdx].vec.z = tri.vec0.z;
   
                }
                curAnimSrc->type = GD_ANIM_MTX_VEC;
            } else {
                copy_bytes(curAnimSrc->data, allocSpace, curAnimSrc->count * datasize);
            } 
        } 
        
        animDst[i].type = curAnimSrc->type;
        animDst[i].count = curAnimSrc->count;
        animDst[i].data = allocSpace;

        curAnimSrc++; //next anim data struct
    }

    animgrp->link1C->obj = (void *)animDataArr;
    stop_memtracker("animdata");
}

/* 2340A8 -> 234840 */
#define VTX_BUF_SZ 3000
void chk_shapegen(struct ObjShape *a0)
{
    struct ObjFace *face;         // sp5C; made face
    struct ObjVertex *vtx;        // sp58; made gdvtx
    struct ObjVertex **vtxbuf;    // sp54; heap storage for made gd vtx
    struct ObjGroup *shapeMtls;   // sp50
    struct ObjGroup *shapeFaces;  // sp4C
    struct ObjGroup *shapeVtx;    // sp48
    UNUSED u32 pad44;
    struct ObjGroup *madeFaces;   // sp40
    struct ObjGroup *madeVtx;     // sp3C
    u32 i;                        // sp38
    struct GdVtxData *vtxdata;    // sp34
    struct GdFaceData *facedata;  // sp30
    struct ObjHeader *oldObjHead; // sp2C

    start_memtracker("chk_shapegen");
    add_to_stacktrace("chk_shapegen");
    shapeMtls = a0->mtlGroup;
    shapeFaces = a0->faceGroup;
    shapeVtx = a0->vtxGroup;

    if (shapeVtx != NULL && shapeFaces != NULL)
    if ((shapeVtx->unk30 & 1) && (shapeFaces->unk30 & 1)) //! needs the double if
    {
        // These Links point to special data structures
        vtxdata = (struct GdVtxData *)shapeVtx->link1C->obj;
        facedata = (struct GdFaceData *)shapeFaces->link1C->obj;
        if (facedata->type != 1)
            fatal_printf("unsupported poly type");

        if (vtxdata->type != 1)
            fatal_printf("unsupported vertex type");

        if (vtxdata->count >= VTX_BUF_SZ)
            fatal_printf("shapegen() too many vertices");

        vtxbuf = gd_malloc_temp(VTX_BUF_SZ * sizeof(struct ObjVertex *));
        oldObjHead = gGdObjectList;

        for (i = 0; i < vtxdata->count; i++)
        {
            vtx = gd_make_vertex(vtxdata->data[i][0], vtxdata->data[i][1], vtxdata->data[i][2]);
            vtx->vec2C.x = vtx->vec2C.y = vtx->vec2C.z = 0.0f;
            vtxbuf[i] = vtx;
        }
        
        madeVtx = make_group_of_type(OBJ_TYPE_VERTICES, oldObjHead, NULL);
        
        oldObjHead = gGdObjectList;
        for (i = 0; i < facedata->count; i++)
        {
            //! Bad call; include proper header to fix
            face = make_face_1(1.0, 1.0, 1.0);
            face->unk44 = (s32) facedata->data[i][0];
            add_3_vtx_to_face(
                face, 
                vtxbuf[facedata->data[i][1]],
                vtxbuf[facedata->data[i][2]],
                vtxbuf[facedata->data[i][3]]
            );
            vtxbuf[facedata->data[i][1]]->vec2C.x += face->vec24.x;
            vtxbuf[facedata->data[i][1]]->vec2C.y += face->vec24.y;
            vtxbuf[facedata->data[i][1]]->vec2C.z += face->vec24.z;

            vtxbuf[facedata->data[i][2]]->vec2C.x += face->vec24.x;
            vtxbuf[facedata->data[i][2]]->vec2C.y += face->vec24.y;
            vtxbuf[facedata->data[i][2]]->vec2C.z += face->vec24.z;

            vtxbuf[facedata->data[i][3]]->vec2C.x += face->vec24.x;
            vtxbuf[facedata->data[i][3]]->vec2C.y += face->vec24.y;
            vtxbuf[facedata->data[i][3]]->vec2C.z += face->vec24.z;
        }

        if (a0->unk44 & 0x10)
        {
            for (i = 0; i < vtxdata->count; i++)
            {
                vtxbuf[i]->vec2C.x = vtxbuf[i]->vec20.x;
                vtxbuf[i]->vec2C.y = vtxbuf[i]->vec20.y;
                vtxbuf[i]->vec2C.z = vtxbuf[i]->vec20.z;
                into_unit_vec3f(&vtxbuf[i]->vec2C);
            }
        } else { 
            for (i = 0; i < vtxdata->count; i++)
            { 
                into_unit_vec3f(&vtxbuf[i]->vec2C);
            }
        }
        
        gd_free(vtxbuf);    //gd_free
        madeFaces = make_group_of_type(OBJ_TYPE_FACES, oldObjHead, NULL);
        a0->faceGroup = madeFaces;
        a0->vtxGroup = madeVtx;
    } 

    if (shapeMtls != NULL)
    {
        if (a0->faceGroup)
        {
            func_8017B064(a0->faceGroup, shapeMtls);
        } else {
            fatal_printf("chk_shapegen() please set face group before mats");
        }
    }

    imout();
    stop_memtracker("chk_shapegen");
}
#undef VTX_BUF_SZ

/* 234840 -> 2349E0 */
void d_set_nodegroup(DynId id)
{
    struct DynObjInfo *info;    // sp2C
    UNUSED u32 pad[2];

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dSetNodeGroup(\"%s\"): Undefined group", DynIdAsStr(id));

    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk1C8 = (struct ObjGroup *)info->obj;
            ((struct ObjNet *)sDynListCurObj)->unk1D0 = (struct ObjGroup *)info->obj;
            break;
        case OBJ_TYPE_SHAPES:
            ((struct ObjShape *)sDynListCurObj)->vtxGroup = (struct ObjGroup *)info->obj;
            chk_shapegen((struct ObjShape *)sDynListCurObj);
            break;
        case OBJ_TYPE_GADGETS:
            ((struct ObjGadget *)sDynListCurObj)->unk54 = (struct ObjGroup *)info->obj;
            break;
        case OBJ_TYPE_ANIMATORS:
            ((struct ObjAnimator *)sDynListCurObj)->animdata = (struct ObjGroup *)info->obj;
            alloc_animdata((struct ObjAnimator *)sDynListCurObj);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.", 
                "dSetNodeGroup()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2349E0 -> 234AD0; orig name: func_80186210 */
void d_set_matgroup(DynId id)
{
    struct DynObjInfo *info;    // sp1C

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dSetMatGroup(\"%s\"): Undefined group", DynIdAsStr(id));
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_SHAPES:
            ((struct ObjShape *)sDynListCurObj)->mtlGroup = (struct ObjGroup *)info->obj;
            chk_shapegen((struct ObjShape *)sDynListCurObj);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetMatGroup()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 234AD0 -> 234B6C; orig name: func_80186300 */
void d_set_texture_st(UNUSED f32 s, UNUSED f32 t)
{
    UNUSED u32 pad[2];

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_VERTICES:
            break;  // ifdef-ed out?
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetTextureST()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 234B6C -> 234C18; orig name: func_8018639C */
void d_use_texture(void *texture)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_MATERIALS:
            ((struct ObjMaterial *)sDynListCurObj)->unk58 = texture;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dUseTexture()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 234C18 -> 234CFC; orig name: func_80186448 */
void d_set_skinshape(DynId id)
{
    struct DynObjInfo *info;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dSetSkinShape(\"%s\"): Undefined object", DynIdAsStr(id));
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->skinGrp = ((struct ObjShape *)info->obj)->vtxGroup;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetSkinShape()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 234CFC -> 234D88; orig name: func_8018652C */
void d_map_materials(DynId id)
{
    struct DynObjInfo *info;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dMapMaterials(\"%s\"): Undefined group", DynIdAsStr(id));
    //TODO: rename to map_materials ?
    func_8017B064((struct ObjGroup *)sDynListCurObj, (struct ObjGroup *)info->obj);
}

/* 234D88 -> 234E14 */
void d_map_vertices(DynId id)
{
    struct DynObjInfo *info;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dMapVertices(\"%s\"): Undefined group", DynIdAsStr(id));

    map_vertices((struct ObjGroup *)sDynListCurObj, (struct ObjGroup *)info->obj);
}

/* 234E14 -> 234F34; orig name: func_80186644 */
void d_set_planegroup(DynId id)
{
    struct DynObjInfo *info;    //sp2C
    UNUSED u32 pad[2];

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dSetPlaneGroup(\"%s\"): Undefined group", DynIdAsStr(id));
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk1CC = (struct ObjGroup *)info->obj;
            break;
        case OBJ_TYPE_SHAPES:
            ((struct ObjShape *)sDynListCurObj)->faceGroup = (struct ObjGroup *)info->obj;
            chk_shapegen((struct ObjShape *)sDynListCurObj);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetPlaneGroup()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 234F34 -> 2350F0; orig name: func_80186764 */
void d_set_shapeptrptr(struct ObjShape **shpPtrptr)
{
    struct ObjShape *defaultptr = NULL;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    if (shpPtrptr == NULL)
        shpPtrptr = &defaultptr;
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unk20 = *shpPtrptr;
            ((struct ObjJoint *)sDynListCurObj)->unk1C8 = 0;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk1A8 = *shpPtrptr;
            break;
        case OBJ_TYPE_BONES:
            ((struct ObjBone *)sDynListCurObj)->unkF0 = *shpPtrptr;
            break;
        case OBJ_TYPE_GADGETS:
            ((struct ObjGadget *)sDynListCurObj)->unk50 = *shpPtrptr;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)sDynListCurObj)->unk1C = *shpPtrptr;
            break;
        case OBJ_TYPE_LIGHTS:
            ((struct ObjLight *)sDynListCurObj)->unk9C = *shpPtrptr;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetShapePtrPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2350F0 -> 23528C; orig name: func_80186920 */
void d_set_shapeptr(DynId id)
{
    struct DynObjInfo *info;    // sp24
    if (id == NULL) { return; }

    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dSetShapePtr(\"%s\"): Undefined object", DynIdAsStr(id));
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unk20 = (struct ObjShape *)info->obj;
            ((struct ObjJoint *)sDynListCurObj)->unk1C8 = 0;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk1A8 = (struct ObjShape *)info->obj;
            break;
        case OBJ_TYPE_BONES:
            ((struct ObjBone *)sDynListCurObj)->unkF0 = (struct ObjShape *)info->obj;
            break;
        case OBJ_TYPE_GADGETS:
            ((struct ObjGadget *)sDynListCurObj)->unk50 = (struct ObjShape *)info->obj;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)sDynListCurObj)->unk1C = (struct ObjShape *)info->obj;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetShapePtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 23528C -> 235314 */
struct ObjHeader *d_use_obj(DynId id)
{
    struct DynObjInfo *info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dUseObj(\"%s\"): Undefined object", DynIdAsStr(id));
    
    sDynListCurObj = info->obj;
    sDynListCurInfo = info;

    return info->obj;
}

/* 235314 -> 23533C; orig name: func_80186B44 */
void set_cur_dynobj(struct ObjHeader *obj)
{
    sDynListCurObj = obj;
    sDynListCurInfo = &sNullDynObjInfo;
}

/* 23533C -> 23536C; orig name: func_80186B6C */
void d_start_group(DynId id)
{
    d_makeobj(D_GROUP, id);
}

/* 23536C -> 235470 */
/* Enclose all dynobj(s) created between the creation of the d_group `id` and now */
void d_end_group(DynId id)
{
    UNUSED u32 pad;
    struct DynObjInfo *info = get_dynobj_info(id);  // sp20;
    struct ObjGroup *dynGrp;    // sp1C
    int i;                      // sp18

    if (info == NULL)
        fatal_printf("dEndGroup(\"%s\"): Undefined group", DynIdAsStr(id));

    dynGrp = (struct ObjGroup *)info->obj;
    for (i = info->id + 1; i < sLoadedDynObjs; i++)
    {
        if (sGdDynObjList[i].obj->type != OBJ_TYPE_GROUPS)
        {
            addto_group(dynGrp, sGdDynObjList[i].obj);
        }
    }
}

/* 235470 -> 2354EC; orig name: func_80186CA0 */
void d_addto_group(DynId id)
{
    UNUSED u32 pad;
    struct DynObjInfo *info = get_dynobj_info(id);  // sp20
    struct ObjGroup *targetGrp;

    if (info == NULL)
        fatal_printf("dAddToGroup(\"%s\"): Undefined group", DynIdAsStr(id));
    
    targetGrp = (struct ObjGroup *)info->obj;
    addto_group(targetGrp, sDynListCurObj);
}

/* 2354EC -> 235504; orig name: func_80186D1C */
void dynid_is_int(s32 b)
{
    sGdDynObjIdIsInt = b;
}

/* 235504 -> 23579C */
void d_set_init_pos(f32 x, f32 y, f32 z)
{
    UNUSED u32 pad2c[3];
    struct ObjHeader *dynobj = sDynListCurObj;  // sp28
    UNUSED u32 pad[1];

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk14.x = x;
            ((struct ObjJoint *)dynobj)->unk14.y = y;
            ((struct ObjJoint *)dynobj)->unk14.z = z;

            ((struct ObjJoint *)dynobj)->unk3C.x = x;
            ((struct ObjJoint *)dynobj)->unk3C.y = y;
            ((struct ObjJoint *)dynobj)->unk3C.z = z;

            ((struct ObjJoint *)dynobj)->unk54.x = x;
            ((struct ObjJoint *)dynobj)->unk54.y = y;
            ((struct ObjJoint *)dynobj)->unk54.z = z;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->unk14.x = x;
            ((struct ObjNet *)dynobj)->unk14.y = y;
            ((struct ObjNet *)dynobj)->unk14.z = z;

            ((struct ObjNet *)dynobj)->unk20.x = x;
            ((struct ObjNet *)dynobj)->unk20.y = y;
            ((struct ObjNet *)dynobj)->unk20.z = z;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)dynobj)->unk20.x = x;
            ((struct ObjParticle *)dynobj)->unk20.y = y;
            ((struct ObjParticle *)dynobj)->unk20.z = z;
            break;
        case OBJ_TYPE_CAMERAS:
            ((struct ObjCamera *)dynobj)->unk14.x = x;
            ((struct ObjCamera *)dynobj)->unk14.y = y;
            ((struct ObjCamera *)dynobj)->unk14.z = z;
            break;
        case OBJ_TYPE_VERTICES:
            d_set_rel_pos(x, y, z);

            ((struct ObjVertex *)dynobj)->vec14.x = x;
            ((struct ObjVertex *)dynobj)->vec14.y = y;
            ((struct ObjVertex *)dynobj)->vec14.z = z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetInitPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 23579C -> 2358D4 ; not called */
void d_set_velocity(struct MyVec3f *vel)
{
    struct ObjHeader *dynobj = sDynListCurObj;
    
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk78.x = vel->x;
            ((struct ObjJoint *)dynobj)->unk78.y = vel->y;
            ((struct ObjJoint *)dynobj)->unk78.z = vel->z;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->unk50.x = vel->x;
            ((struct ObjNet *)dynobj)->unk50.y = vel->y;
            ((struct ObjNet *)dynobj)->unk50.z = vel->z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetVelocity()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2358D4 -> 235A2C; not called */
void d_get_velocity(struct MyVec3f *dst)
{
    struct ObjHeader *dynobj = sDynListCurObj;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)dynobj)->unk78.x;
            dst->y = ((struct ObjJoint *)dynobj)->unk78.y;
            dst->z = ((struct ObjJoint *)dynobj)->unk78.z;
            break;
        case OBJ_TYPE_NETS:
            dst->x = ((struct ObjNet *)dynobj)->unk50.x;
            dst->y = ((struct ObjNet *)dynobj)->unk50.y;
            dst->z = ((struct ObjNet *)dynobj)->unk50.z;
            break;
        default:
            dst->x = dst->y = dst->z = 0.0f;
            break;
    }
} 

/* 235A2C -> 235B10; not called */
void d_set_torque(struct MyVec3f *src)
{
    struct ObjHeader *dynobj = sDynListCurObj;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->unkA4.x = src->x;
            ((struct ObjNet *)dynobj)->unkA4.y = src->y;
            ((struct ObjNet *)dynobj)->unkA4.z = src->z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetTorque()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 235B10 -> 235C98; orig name: func_80187340 */
void d_get_init_pos(struct MyVec3f *dst)
{
    struct ObjHeader *dynobj = sDynListCurObj;
    
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");

    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)dynobj)->unk54.x;
            dst->y = ((struct ObjJoint *)dynobj)->unk54.y;
            dst->z = ((struct ObjJoint *)dynobj)->unk54.z;
            break;
        case OBJ_TYPE_NETS:
            dst->x = ((struct ObjNet *)dynobj)->unk20.x;
            dst->y = ((struct ObjNet *)dynobj)->unk20.y;
            dst->z = ((struct ObjNet *)dynobj)->unk20.z;
            break;
        case OBJ_TYPE_VERTICES:
            dst->x = ((struct ObjVertex *)dynobj)->vec14.x;
            dst->y = ((struct ObjVertex *)dynobj)->vec14.y;
            dst->z = ((struct ObjVertex *)dynobj)->vec14.z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetInitPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 235C98 -> 235E24; orig name: func_801874C8 */
void d_get_init_rot(struct MyVec3f *dst)
{
    struct ObjHeader *dynobj = sDynListCurObj;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)dynobj)->unk6C.x;
            dst->y = ((struct ObjJoint *)dynobj)->unk6C.y;
            dst->z = ((struct ObjJoint *)dynobj)->unk6C.z;
            break;
        case OBJ_TYPE_NETS:
            dst->x = ((struct ObjNet *)dynobj)->unk68.x;
            dst->y = ((struct ObjNet *)dynobj)->unk68.y;
            dst->z = ((struct ObjNet *)dynobj)->unk68.z;
            break;
        case OBJ_TYPE_LIGHTS:
            dst->x = dst->y = dst->z = 0.0f;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetInitRot()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 235E24 -> 236140 */
void d_set_rel_pos(f32 x, f32 y, f32 z)
{
    struct ObjHeader *dynobj = sDynListCurObj;  // sp34
    UNUSED struct MyVec3f unusedVec;            // sp28

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk3C.x = x;
            ((struct ObjJoint *)dynobj)->unk3C.y = y;
            ((struct ObjJoint *)dynobj)->unk3C.z = z;
            break;
        case OBJ_TYPE_CAMERAS:
            unusedVec.x = x;
            unusedVec.y = y;
            unusedVec.z = z;

            ((struct ObjCamera *)dynobj)->unk40.x = x;
            ((struct ObjCamera *)dynobj)->unk40.y = y;
            ((struct ObjCamera *)dynobj)->unk40.z = z;

            ((struct ObjCamera *)dynobj)->unk140.x = x;
            ((struct ObjCamera *)dynobj)->unk140.y = y;
            ((struct ObjCamera *)dynobj)->unk140.z = z;

            ((struct ObjCamera *)dynobj)->unk14C.x = x * 1.5;   //! 1.5f
            ((struct ObjCamera *)dynobj)->unk14C.y = y * 1.5;   //! 1.5f
            ((struct ObjCamera *)dynobj)->unk14C.z = z * 1.5;   //! 1.5f

            ((struct ObjCamera *)dynobj)->unk158.x = x * 2.0f;
            ((struct ObjCamera *)dynobj)->unk158.y = y * 2.0f;
            ((struct ObjCamera *)dynobj)->unk158.z = z * 2.0f;

            ((struct ObjCamera *)dynobj)->unk170 = 2;
            break;
        case OBJ_TYPE_VERTICES:
            ((struct ObjVertex *)dynobj)->vec20.x = x;
            ((struct ObjVertex *)dynobj)->vec20.y = y;
            ((struct ObjVertex *)dynobj)->vec20.z = z;
            break;
        case OBJ_TYPE_LABELS:
            ((struct ObjLabel *)dynobj)->vec14.x = x;
            ((struct ObjLabel *)dynobj)->vec14.y = y;
            ((struct ObjLabel *)dynobj)->vec14.z = z;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)dynobj)->unk20.x = x;
            ((struct ObjParticle *)dynobj)->unk20.y = y;
            ((struct ObjParticle *)dynobj)->unk20.z = z;
            break;
        case OBJ_TYPE_NETS:
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetRelPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 236140 -> 236310; not called */
void d_addto_rel_pos(struct MyVec3f *src)
{
    struct ObjHeader *dynobj = sDynListCurObj;  // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_VERTICES:
            ((struct ObjVertex *)dynobj)->vec20.x += src->x;
            ((struct ObjVertex *)dynobj)->vec20.y += src->y;
            ((struct ObjVertex *)dynobj)->vec20.z += src->z;
            break;
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk3C.x += src->x;
            ((struct ObjJoint *)dynobj)->unk3C.y += src->y;
            ((struct ObjJoint *)dynobj)->unk3C.z += src->z;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)dynobj)->unk20.x += src->x;
            ((struct ObjParticle *)dynobj)->unk20.y += src->y;
            ((struct ObjParticle *)dynobj)->unk20.z += src->z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dAddToRelPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 236310 -> 236508; orig name: func_80187B40 */
void d_get_rel_pos(struct MyVec3f *dst)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_VERTICES:
            dst->x = ((struct ObjVertex *)sDynListCurObj)->vec20.x;
            dst->y = ((struct ObjVertex *)sDynListCurObj)->vec20.y;
            dst->z = ((struct ObjVertex *)sDynListCurObj)->vec20.z;
            break;
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)sDynListCurObj)->unk3C.x;
            dst->y = ((struct ObjJoint *)sDynListCurObj)->unk3C.y;
            dst->z = ((struct ObjJoint *)sDynListCurObj)->unk3C.z;
            break;
        case OBJ_TYPE_CAMERAS:
            dst->x = ((struct ObjCamera *)sDynListCurObj)->unk40.x;
            dst->y = ((struct ObjCamera *)sDynListCurObj)->unk40.y;
            dst->z = ((struct ObjCamera *)sDynListCurObj)->unk40.z;
            break;
        case OBJ_TYPE_PARTICLES:
            dst->x = ((struct ObjParticle *)sDynListCurObj)->unk20.x;
            dst->y = ((struct ObjParticle *)sDynListCurObj)->unk20.y;
            dst->z = ((struct ObjParticle *)sDynListCurObj)->unk20.z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetRelPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 236508 -> 2365E4; orig name: func_80187D38 */
struct ObjGroup *d_get_att_objgroup(void)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            return ((struct ObjJoint *)sDynListCurObj)->unk1F8;
            break;  //! lol
        case OBJ_TYPE_NETS:
            return ((struct ObjNet *)sDynListCurObj)->unk1D4;
            break;  //! lol
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetAttObjGroup()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    //! No `return NULL;`
}

/* 2365E4 -> 2366C0; not called */
struct ObjHeader *d_get_att_to_obj(void)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            return ((struct ObjJoint *)sDynListCurObj)->unk20C;
            break;  //! lol
        case OBJ_TYPE_NETS:
            return ((struct ObjNet *)sDynListCurObj)->unk1E8;
            break;  //! lol
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetAttToObj()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    //! No `return NULL;`
}

/* 2366C0 -> 236848; orig name: func_80187EF0 */
void d_get_scale(struct MyVec3f *dst)
{
    struct ObjHeader *dynobj;   // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)dynobj)->unk9C.x;
            dst->y = ((struct ObjJoint *)dynobj)->unk9C.y;
            dst->z = ((struct ObjJoint *)dynobj)->unk9C.z;
            break;
        case OBJ_TYPE_NETS:
            dst->x = ((struct ObjNet *)dynobj)->unk1AC.x;
            dst->y = ((struct ObjNet *)dynobj)->unk1AC.y;
            dst->z = ((struct ObjNet *)dynobj)->unk1AC.z;
            break;
        case OBJ_TYPE_LIGHTS:
            dst->x = 1.0f;
            dst->y = 1.0f;
            dst->z = 1.0f;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetScale()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 236848 -> 236A0C; orig name: func_80188078 */
void d_set_att_offset(struct MyVec3f *off)
{
    struct ObjHeader *dynobj;   // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk200.x = off->x;
            ((struct ObjJoint *)dynobj)->unk200.y = off->y;
            ((struct ObjJoint *)dynobj)->unk200.z = off->z;

            ((struct ObjJoint *)dynobj)->unk54.x = off->x;
            ((struct ObjJoint *)dynobj)->unk54.y = off->y;
            ((struct ObjJoint *)dynobj)->unk54.z = off->z;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->unk1D8.x = off->x;
            ((struct ObjNet *)dynobj)->unk1D8.y = off->y;
            ((struct ObjNet *)dynobj)->unk1D8.z = off->z;

            ((struct ObjNet *)dynobj)->unk20.x = off->x;
            ((struct ObjNet *)dynobj)->unk20.y = off->y;
            ((struct ObjNet *)dynobj)->unk20.z = off->z;
            break;
        case OBJ_TYPE_PARTICLES:
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetAttOffset()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 236A0C -> 236B60; not called */
void d_set_att_to_offset(UNUSED u32 a)
{
    struct ObjHeader *dynobj;   // sp3c
    UNUSED u8 pad[24];

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    push_dynobj_stash();
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            set_cur_dynobj(((struct ObjJoint *)dynobj)->unk20C);
            break;
        case OBJ_TYPE_NETS:
            set_cur_dynobj(((struct ObjNet *)dynobj)->unk1E8);
            break;
        case OBJ_TYPE_PARTICLES:
            set_cur_dynobj(((struct ObjParticle *)dynobj)->unkBC);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetAttToOffset()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }

    if (sDynListCurObj == NULL)
    {
        fatal_printf("dSetAttOffset(): Object '%s' isnt attached to anything", 
            sStashedDynObjInfo->name
        );
    }
    d_set_att_to_offset(a);
    pop_dynobj_stash();
}

/* 236B60 -> 236CB4; not called */
void d_get_att_offset(struct MyVec3f *dst)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)sDynListCurObj)->unk200.x;
            dst->y = ((struct ObjJoint *)sDynListCurObj)->unk200.y;
            dst->z = ((struct ObjJoint *)sDynListCurObj)->unk200.z;
            break;
        case OBJ_TYPE_NETS:
            dst->x = ((struct ObjNet *)sDynListCurObj)->unk1D8.x;
            dst->y = ((struct ObjNet *)sDynListCurObj)->unk1D8.y;
            dst->z = ((struct ObjNet *)sDynListCurObj)->unk1D8.z;
            break;
        case OBJ_TYPE_PARTICLES:
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetAttOffset()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 236CB4 -> 236DC8; not called */
s32 d_get_att_flags(void)
{
    s32 attflag;    // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            attflag = ((struct ObjJoint *)sDynListCurObj)->unk1FC;
            break;
        case OBJ_TYPE_NETS:
            attflag = ((struct ObjNet *)sDynListCurObj)->unk1E4;
            break;
        case OBJ_TYPE_PARTICLES:
            attflag = ((struct ObjParticle *)sDynListCurObj)->unkB8;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetAttFlags()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }

    return attflag;
}

/* 236DC8 -> 237038 */
void d_set_world_pos(f32 x, f32 y, f32 z)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_CAMERAS:
            ((struct ObjCamera *)sDynListCurObj)->unk14.x = x;
            ((struct ObjCamera *)sDynListCurObj)->unk14.y = y;
            ((struct ObjCamera *)sDynListCurObj)->unk14.z = z;
            break;
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unk14.x = x;
            ((struct ObjJoint *)sDynListCurObj)->unk14.y = y;
            ((struct ObjJoint *)sDynListCurObj)->unk14.z = z;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk14.x = x;
            ((struct ObjNet *)sDynListCurObj)->unk14.y = y;
            ((struct ObjNet *)sDynListCurObj)->unk14.z = z;
            break;
        case OBJ_TYPE_GADGETS:
            ((struct ObjGadget *)sDynListCurObj)->unk14.x = x;
            ((struct ObjGadget *)sDynListCurObj)->unk14.y = y;
            ((struct ObjGadget *)sDynListCurObj)->unk14.z = z;
            break;
        case OBJ_TYPE_VIEWS:
            ((struct ObjView *)sDynListCurObj)->unk3C.x = x;
            ((struct ObjView *)sDynListCurObj)->unk3C.y = y;
            ((struct ObjView *)sDynListCurObj)->unk3C.z = z;
            break;
        case OBJ_TYPE_VERTICES:
            ((struct ObjVertex *)sDynListCurObj)->vec20.x = x;
            ((struct ObjVertex *)sDynListCurObj)->vec20.y = y;
            ((struct ObjVertex *)sDynListCurObj)->vec20.z = z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetWorldPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237038 -> 237140; orig name: func_80188868 */
void d_set_normal(f32 x, f32 y, f32 z)
{
    struct MyVec3f normal;  // sp1C

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    normal.x = x;
    normal.y = y;
    normal.z = z;
    into_unit_vec3f(&normal);

    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_VERTICES:
            ((struct ObjVertex *)sDynListCurObj)->vec2C.x = normal.x;
            ((struct ObjVertex *)sDynListCurObj)->vec2C.y = normal.y;
            ((struct ObjVertex *)sDynListCurObj)->vec2C.z = normal.z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetNormal()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237140 -> 23720C ; not called */
struct MyVec3f *d_get_world_pos_ptr(void)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_VERTICES:
            return &((struct ObjVertex *)sDynListCurObj)->vec20;
            break;
        case OBJ_TYPE_PARTICLES:
            return &((struct ObjParticle *)sDynListCurObj)->unk20;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetWorldPosPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    //! No `return NULL;` 
}

/* 23720C -> 237884; orig name: func_80188A3C */
void d_get_world_pos(struct MyVec3f *dst)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_VERTICES:
            dst->x = ((struct ObjVertex *)sDynListCurObj)->vec20.x;
            dst->y = ((struct ObjVertex *)sDynListCurObj)->vec20.y;
            dst->z = ((struct ObjVertex *)sDynListCurObj)->vec20.z;
            break;
        case OBJ_TYPE_JOINTS:
            dst->x = ((struct ObjJoint *)sDynListCurObj)->unk14.x;
            dst->y = ((struct ObjJoint *)sDynListCurObj)->unk14.y;
            dst->z = ((struct ObjJoint *)sDynListCurObj)->unk14.z;
            break;
        case OBJ_TYPE_NETS:
            dst->x = ((struct ObjNet *)sDynListCurObj)->unk14.x;
            dst->y = ((struct ObjNet *)sDynListCurObj)->unk14.y;
            dst->z = ((struct ObjNet *)sDynListCurObj)->unk14.z;
            break;
        case OBJ_TYPE_PARTICLES:
            dst->x = ((struct ObjParticle *)sDynListCurObj)->unk20.x;
            dst->y = ((struct ObjParticle *)sDynListCurObj)->unk20.y;
            dst->z = ((struct ObjParticle *)sDynListCurObj)->unk20.z;
            break;
        case OBJ_TYPE_CAMERAS:
            dst->x = ((struct ObjCamera *)sDynListCurObj)->unk14.x;
            dst->y = ((struct ObjCamera *)sDynListCurObj)->unk14.y;
            dst->z = ((struct ObjCamera *)sDynListCurObj)->unk14.z;
            break;
        case OBJ_TYPE_BONES:
            dst->x = ((struct ObjBone *)sDynListCurObj)->unk14.x;
            dst->y = ((struct ObjBone *)sDynListCurObj)->unk14.y;
            dst->z = ((struct ObjBone *)sDynListCurObj)->unk14.z;
            break;
        case OBJ_TYPE_SHAPES:
            dst->x = dst->y = dst->z = 0.0f;
            break;
        case OBJ_TYPE_LABELS:
            dst->x = dst->y = dst->z = 0.0f;
            break;
        case OBJ_TYPE_GADGETS:
            dst->x = ((struct ObjGadget *)sDynListCurObj)->unk14.x;
            dst->y = ((struct ObjGadget *)sDynListCurObj)->unk14.y;
            dst->z = ((struct ObjGadget *)sDynListCurObj)->unk14.z;
            break;
        case OBJ_TYPE_PLANES:
            dst->x = ((struct ObjPlane *)sDynListCurObj)->plane28.vec0.x;
            dst->y = ((struct ObjPlane *)sDynListCurObj)->plane28.vec0.y;
            dst->z = ((struct ObjPlane *)sDynListCurObj)->plane28.vec0.z;

            dst->x += ((struct ObjPlane *)sDynListCurObj)->plane28.vec1.x;
            dst->y += ((struct ObjPlane *)sDynListCurObj)->plane28.vec1.y;
            dst->z += ((struct ObjPlane *)sDynListCurObj)->plane28.vec1.z;

            dst->x *= 0.5;  //! 0.5f
            dst->y *= 0.5;  //! 0.5f
            dst->z *= 0.5;  //! 0.5f
            break;
        case OBJ_TYPE_ZONES:
            dst->x = ((struct ObjZone *)sDynListCurObj)->unk14.vec0.x;
            dst->y = ((struct ObjZone *)sDynListCurObj)->unk14.vec0.y;
            dst->z = ((struct ObjZone *)sDynListCurObj)->unk14.vec0.z;

            dst->x += ((struct ObjZone *)sDynListCurObj)->unk14.vec1.x;
            dst->y += ((struct ObjZone *)sDynListCurObj)->unk14.vec1.y;
            dst->z += ((struct ObjZone *)sDynListCurObj)->unk14.vec1.z;

            dst->x *= 0.5;  //! 0.5f
            dst->y *= 0.5;  //! 0.5f
            dst->z *= 0.5;  //! 0.5f
            break;
        case OBJ_TYPE_LIGHTS:
            dst->x = ((struct ObjLight *)sDynListCurObj)->unk74.x;
            dst->y = ((struct ObjLight *)sDynListCurObj)->unk74.y;
            dst->z = ((struct ObjLight *)sDynListCurObj)->unk74.z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetWorldPos()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237884 -> 2378D0; orig name: func_801890B4 */
void d_make_vertex(struct MyVec3f *pos)
{
    d_makeobj(D_VERTEX, AsDynId(NULL));
    d_set_init_pos(pos->x, pos->y, pos->z);
}

/* 2378D0 -> 237AEC */
void d_set_scale(f32 x, f32 y, f32 z)
{
    struct ObjHeader *initDynobj;    // sp24;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    initDynobj = sDynListCurObj;
    push_dynobj_stash();
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)initDynobj)->unk9C.x = x;
            ((struct ObjJoint *)initDynobj)->unk9C.y = y;
            ((struct ObjJoint *)initDynobj)->unk9C.z = z;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)initDynobj)->unk1AC.x = x;
            ((struct ObjNet *)initDynobj)->unk1AC.y = y;
            ((struct ObjNet *)initDynobj)->unk1AC.z = z;
            break;
        case OBJ_TYPE_VIEWS:
            ((struct ObjView *)initDynobj)->unk54.x = x;
            ((struct ObjView *)initDynobj)->unk54.y = y;
            ((struct ObjView *)initDynobj)->unk54.z = z;
            break;
        case OBJ_TYPE_PARTICLES:
            break;
        case OBJ_TYPE_GADGETS:
            if (((struct ObjGadget *)initDynobj)->unk50 != NULL)
            {
                func_8019834C(((struct ObjGadget *)initDynobj)->unk50, x, y, z);
            }
            ((struct ObjGadget *)initDynobj)->unk40.x = x;
            ((struct ObjGadget *)initDynobj)->unk40.y = y;
            ((struct ObjGadget *)initDynobj)->unk40.z = z;
            break;
        case OBJ_TYPE_LIGHTS:
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetScale()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    pop_dynobj_stash();
}

/* 237AEC -> 237C14; orig name: func_8018931C */
void d_set_rotation(f32 x, f32 y, f32 z)
{
    struct ObjHeader *dynobj;   // sp2C
    UNUSED u32 pad;

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk6C.x = x;
            ((struct ObjJoint *)dynobj)->unk6C.y = y;
            ((struct ObjJoint *)dynobj)->unk6C.z = z;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->unk68.x = x;
            ((struct ObjNet *)dynobj)->unk68.y = y;
            ((struct ObjNet *)dynobj)->unk68.z = z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetRotation()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237C14 -> 237CF0; orig name: func_80189444 */
void d_center_of_gravity(f32 x, f32 y, f32 z)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unkB0.x = x;
            ((struct ObjNet *)sDynListCurObj)->unkB0.y = y;
            ((struct ObjNet *)sDynListCurObj)->unkB0.z = z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dCofG()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237CF0 -> 237DCC; orig name: func_80189520 */
void d_set_shape_offset(f32 x, f32 y, f32 z)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unkC0.x = x;
            ((struct ObjJoint *)sDynListCurObj)->unkC0.y = y;
            ((struct ObjJoint *)sDynListCurObj)->unkC0.z = z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dShapeOffset()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237DCC -> 237F68 */
void d_add_valptr(DynId objId, u32 vflags, s32 type, u32 offset)
{
    struct ObjHeader *dynobj;   // sp2C
    struct ObjValPtrs *valptr;  // sp28
    struct DynObjInfo *info;    // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;

    if (vflags == 0x40000)
    {
        info = get_dynobj_info(objId);
        if (info == NULL)
            fatal_printf("dAddValPtr(\"%s\"): Undefined object", DynIdAsStr(objId));
        
        valptr = make_valptrs(info->obj, vflags, type, offset);
    } else {
        valptr = make_valptrs(objId, vflags, type, offset);
    }
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_GADGETS:
            if (((struct ObjGadget *)dynobj)->unk4C == NULL)
            {
                ((struct ObjGadget *)dynobj)->unk4C = make_group(0);
            }
            addto_group(((struct ObjGadget *)dynobj)->unk4C, &valptr->header);
            break;
        case OBJ_TYPE_LABELS:
            ((struct ObjLabel *)dynobj)->valptr = valptr;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dAddValPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 237F68 -> 238020; orig name: func_80189798 */
void d_add_valproc(valptrproc_t proc)
{
    struct ObjHeader *dynobj;   // sp1C

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_LABELS:
            ((struct ObjLabel *)dynobj)->valfn = proc;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dAddValProc()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 238020 -> 238368; orig name: func_80189850 */
void d_link_with_ptr(void *ptr)
{
    struct ObjHeader *dynobj;   // sp34
    struct ObjValPtrs *valptr;  // sp30
    struct Links *link;         // sp2C

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    add_to_stacktrace("dLinkWithPtr");
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_CAMERAS:
            ((struct ObjCamera *)dynobj)->unk30 = ptr;
            break;
        case OBJ_TYPE_GROUPS:
            link = make_link_to_obj(NULL, ptr);
            ((struct ObjGroup *)dynobj)->link1C = link;
            break;
        case OBJ_TYPE_BONES:
            add_joint2bone((struct ObjBone *)dynobj, ptr);
            break;
        case OBJ_TYPE_VIEWS:
            ((struct ObjView *)dynobj)->unk28 = ptr;
            ((struct ObjView *)dynobj)->unk1C = func_801A3E5C(
                ((struct ObjView *)dynobj)->unk6C,
                ((struct ObjView *)dynobj),
                (s32) ((struct ObjView *)dynobj)->unk3C.x,
                (s32) ((struct ObjView *)dynobj)->unk3C.y,
                (s32) ((struct ObjView *)dynobj)->unk54.x,
                (s32) ((struct ObjView *)dynobj)->unk54.y
            );
            reset_nets_and_gadgets(((struct ObjView *)dynobj)->unk28);
            break;
        case OBJ_TYPE_FACES:
            if (((struct ObjFace *)dynobj)->vtxCount >= 4)
                fatal_printf("too many points");
            
            ((struct ObjFace *)dynobj)->vertices[((struct ObjFace *)dynobj)->vtxCount] = ptr;
            ((struct ObjFace *)dynobj)->vtxCount++;

            if (((struct ObjFace *)dynobj)->vtxCount >= 3)
                calc_face_normal((struct ObjFace *)dynobj);
            
            break;
        case OBJ_TYPE_ANIMATORS:
            if (((struct ObjAnimator *)dynobj)->unk14 == NULL)
                ((struct ObjAnimator *)dynobj)->unk14 = make_group(0);

            addto_group(((struct ObjAnimator *)dynobj)->unk14, ptr);
            break;
        case OBJ_TYPE_LABELS:
            valptr = make_valptrs(ptr, OBJ_TYPE_ALL, 0, 0);
            ((struct ObjLabel *)dynobj)->valptr = valptr;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dLinkWithPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    imout();
}

/* 238368 -> 238438; orig name: func_80189B98 */
void d_link_with(DynId id)
{   
    struct DynObjInfo *info;                        // sp1C
    struct DynObjInfo *origInfo = sDynListCurInfo;  // sp18
    
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    if (id == NULL) { return; }

    info = get_dynobj_info(id);
    if (info == NULL)
        fatal_printf("dLinkWith(\"%s\"): Undefined object", DynIdAsStr(id));
    
    d_link_with_ptr(info->obj);
    set_cur_dynobj(origInfo->obj);
    sDynListCurInfo = origInfo;
}

/* 238438 -> 238644; orig name: func_80189C68 */
void d_set_flags(s32 flags)
{
    struct ObjHeader *dynobj;  // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk1BC |= flags;
            break;
        case OBJ_TYPE_BONES:
            ((struct ObjBone *)dynobj)->unk104 |= flags;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->unk34 |= flags;
            break;
        case OBJ_TYPE_CAMERAS:
            ((struct ObjCamera *)dynobj)->unk2C |= flags;
            break;
        case OBJ_TYPE_VIEWS:
            ((struct ObjView *)dynobj)->unk34 |= flags;
            break;
        case OBJ_TYPE_SHAPES:
            ((struct ObjShape *)dynobj)->unk44 |= flags;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)dynobj)->unk54 |= flags;
            break;
        case OBJ_TYPE_LIGHTS:
            ((struct ObjLight *)dynobj)->unk2C |= flags;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetFlags()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 238644 -> 2387BC; orig name: func_80189E74 */
void d_clear_flags(s32 flags)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unk1BC &= ~flags;
            break;
        case OBJ_TYPE_BONES:
            ((struct ObjBone *)sDynListCurObj)->unk104 &= ~flags;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk34 &= ~flags;
            break;
        case OBJ_TYPE_CAMERAS:
            ((struct ObjCamera *)sDynListCurObj)->unk2C &= ~flags;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)sDynListCurObj)->unk54 &= ~flags;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dClrFlags()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2387BC -> 2389E8; orig name: func_80189FEC*/
// TODO: enumerate the param types?
void d_set_parm_f(s32 param, f32 val)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
    case OBJ_TYPE_SHAPES:
        switch (param)
        {
        case 1:
            ((struct ObjShape *)sDynListCurObj)->unk58 = val;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetParmf() - unsupported parm.",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
        }
        break;
    case OBJ_TYPE_GADGETS:
        switch (param) 
        {
        case 2: // range left?
            ((struct ObjGadget *)sDynListCurObj)->unk38 = val;
            break;
        case 3: // range right?
            ((struct ObjGadget *)sDynListCurObj)->unk3C = val;
            break;
        case 6: // union type
            ((struct ObjGadget *)sDynListCurObj)->varval.f = val;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetParmf() - unsupported parm.",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
        }
        break;
    case OBJ_TYPE_VERTICES:
        switch (param)
        {
        case 1:
            ((struct ObjVertex *)sDynListCurObj)->unk40 = val;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetParmf() - unsupported parm.",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
        }
        break;
    default:
        fatal_printf("%s: Object '%s'(%x) does not support this function.",
            "dSetParmf()",
            sDynListCurInfo->name,
            sDynListCurObj->type
        );
    }
}

/* 2389E8 -> 238BC0 */
// TODO: rename "d_set_parm_ptr"
void d_set_parm_ptr(enum DParmPtr param, void *ptr)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");

    switch (sDynListCurObj->type)
    {
    case OBJ_TYPE_LABELS:
        switch (param)
        {
        case PARM_PTR_CHAR:
            ((struct ObjLabel *)sDynListCurObj)->fmtstr = ptr;
            break;
        default:
            fatal_printf("Bad parm");
        }
        break;
    case OBJ_TYPE_VIEWS:
        switch (param)
        {
        case PARM_PTR_CHAR:
            ((struct ObjView *)sDynListCurObj)->unk6C = ptr;
            break;
        default:
            fatal_printf("Bad parm");
        }
        break;
    case OBJ_TYPE_FACES:
        switch (param)
        {
        case PARM_PTR_OBJ_VTX:
            if ( ((struct ObjFace *)sDynListCurObj)->vtxCount > 3)
            {
                fatal_printf("dsetparmp() too many points");
            }
            ((struct ObjFace *)sDynListCurObj)->vertices[((struct ObjFace *)sDynListCurObj)->vtxCount++] = ptr;
            break;
        default:
            fatal_printf("Bad parm");
        }
        break;
    default:
        fatal_printf("%s: Object '%s'(%x) does not support this function.",
            "dSetParmp()",
            sDynListCurInfo->name,
            sDynListCurObj->type
        );
    }
}

/* 238BC0 -> 238C20; orig name: func_8018A3F0 */
void d_set_objheader_flag(s32 flag)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    sDynListCurObj->unk12 |= flag;
}

/* 238C20 -> 238D90 */
void d_set_type(s32 type)
{
    struct ObjHeader *dynobj = sDynListCurObj;  // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)dynobj)->netType = type;
            break;
        case OBJ_TYPE_GADGETS:
            ((struct ObjGadget *)dynobj)->unk24 = type;
            break;
        case OBJ_TYPE_GROUPS:
            ((struct ObjGroup *)dynobj)->debugPrint = type;
            break;
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->unk1CC = type;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)dynobj)->unk60 = type;
            break;
        case OBJ_TYPE_MATERIALS:
            ((struct ObjMaterial *)dynobj)->unk28 = type;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetType()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 238D90 -> 238EB8; orig name: func_8018A5C0 */
void d_set_id(s32 id)
{
    struct ObjHeader *dynobj = sDynListCurObj;  // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");

    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_MATERIALS:
            ((struct ObjMaterial *)dynobj)->unk1C = id;
            break;
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)dynobj)->id = id;
            break;
        case OBJ_TYPE_VERTICES:
            ((struct ObjVertex *)dynobj)->unk38 = id;
            break;
        case OBJ_TYPE_LIGHTS:
            ((struct ObjLight *)dynobj)->unk1C = id;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetID()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 238EB8 -> 23907C */
// TODO: enumerate colors?
void d_set_colour_num(s32 colornum)
{
    struct GdColour *rgbcolor;    // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unk1C8 = colornum;
            break;
        case OBJ_TYPE_PARTICLES:
            ((struct ObjParticle *)sDynListCurObj)->unk58 = colornum;
            break;
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk40 = colornum;
            break;
        case OBJ_TYPE_GADGETS:
            ((struct ObjGadget *)sDynListCurObj)->unk5C = colornum;
            break;
        case OBJ_TYPE_FACES:
            rgbcolor = gd_get_colour(colornum);  // get pointer to vec3 color
            if (rgbcolor != NULL)
            {
                ((struct ObjFace *)sDynListCurObj)->vec14.x = rgbcolor->r;
                ((struct ObjFace *)sDynListCurObj)->vec14.y = rgbcolor->g;
                ((struct ObjFace *)sDynListCurObj)->vec14.z = rgbcolor->b;
                ((struct ObjFace *)sDynListCurObj)->unk20 = colornum;
            } else {
                fatal_printf("dSetColNum: Unkown colour number");
            }
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dColourNum()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 23907C -> 23912C */
void d_set_material(UNUSED void *a0, s32 a1)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_FACES:
            ((struct ObjFace *)sDynListCurObj)->unk44 = a1;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetMaterial()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 23912C -> 239208; orig name: func_8018A95C */
void d_friction(f32 x, f32 y, f32 z)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            ((struct ObjJoint *)sDynListCurObj)->unkDC.x = x;
            ((struct ObjJoint *)sDynListCurObj)->unkDC.y = y;
            ((struct ObjJoint *)sDynListCurObj)->unkDC.z = z;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dFriction()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 239208 -> 2392B4; orig name: func_8018AA38 */
void d_set_spring(f32 spring)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_BONES:
            ((struct ObjBone *)sDynListCurObj)->unk110 = spring;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetSpring()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2392B4 -> 239390; orig name: func_8018AAE4 */
void d_set_ambient(f32 r, f32 b, f32 g)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_MATERIALS:
            ((struct ObjMaterial *)sDynListCurObj)->unk30.x = r;
            ((struct ObjMaterial *)sDynListCurObj)->unk30.y = b;
            ((struct ObjMaterial *)sDynListCurObj)->unk30.z = g;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetAmbient()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 239390 -> 2394C0; orig name: func_8018ABC0 */
void d_set_diffuse(f32 r, f32 g, f32 b)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_MATERIALS:
            ((struct ObjMaterial *)sDynListCurObj)->Kd.r = r;
            ((struct ObjMaterial *)sDynListCurObj)->Kd.g = g;
            ((struct ObjMaterial *)sDynListCurObj)->Kd.b = b;
            break;
        case OBJ_TYPE_LIGHTS:
            ((struct ObjLight *)sDynListCurObj)->unk50.r = r;
            ((struct ObjLight *)sDynListCurObj)->unk50.g = g;
            ((struct ObjLight *)sDynListCurObj)->unk50.b = b;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetDiffuse()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2394C0 -> 23956C; orig name: func_8018ACF0*/
void d_set_control_type(s32 ctrltype)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            ((struct ObjNet *)sDynListCurObj)->unk210 = ctrltype;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dControlType()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 23956C -> 239640; orig name: func_8018AD9C */
struct GdPlaneF *d_get_plane(void)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            return &((struct ObjNet *)sDynListCurObj)->unkBC;
            break;
        case OBJ_TYPE_PLANES:
            return &((struct ObjPlane *)sDynListCurObj)->plane28;
            break;
        case OBJ_TYPE_ZONES:
            return &((struct ObjZone *)sDynListCurObj)->unk14;
            break;
        default:
            return &sGdNullPlaneF;
    }
}

/* 239640 -> 23978C; orig name: func_8018AE70 */
void d_get_matrix(Mat4 *dst)
{
    struct ObjHeader *dynobj;   // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            cpy_mat4(&((struct ObjNet *)dynobj)->mat128, dst);
            break;
            break;  //! lol
        case OBJ_TYPE_JOINTS:
            cpy_mat4(&((struct ObjJoint *)dynobj)->matE8, dst);
            break;
        case OBJ_TYPE_CAMERAS:
            cpy_mat4(&((struct ObjCamera *)dynobj)->unkE8, dst);
            break;
        case OBJ_TYPE_PARTICLES:
            set_identity_mat4(dst);
            break;
        case OBJ_TYPE_SHAPES:
            set_identity_mat4(dst);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetMatrix()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );

    }
}

/* 23978C -> 2398A0; not called */
void d_set_matrix(Mat4 *src)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            cpy_mat4(src, &((struct ObjNet *)sDynListCurObj)->mat128);
            cpy_mat4(src, &((struct ObjNet *)sDynListCurObj)->mat128);    //! lol
            break;
        case OBJ_TYPE_JOINTS:
            cpy_mat4(src, &((struct ObjJoint *)sDynListCurObj)->matE8);
            break;
        case OBJ_TYPE_CAMERAS:
            cpy_mat4(src, &((struct ObjCamera *)sDynListCurObj)->unk64);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetMatrix()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 2398A0 -> 239978; not called */
void d_set_rot_mtx(Mat4 *src)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");

    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            cpy_mat4(src, &((struct ObjJoint *)sDynListCurObj)->mat128);
            break;
        case OBJ_TYPE_NETS:
            cpy_mat4(src, &((struct ObjJoint *)sDynListCurObj)->mat168);
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetRMatrix()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 239978 -> 239A34 */
Mat4 *d_get_rot_mtx_ptr(void)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            return &((struct ObjJoint *)sDynListCurObj)->mat128;
        case OBJ_TYPE_NETS:
            return &((struct ObjJoint *)sDynListCurObj)->mat168;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetRMatrixPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    //! no `return NULL;`
}

/* 239A34 -> 239B64 */
void d_set_idn_mtx(Mat4 *src)
{
    struct ObjHeader *dynobj;   // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");

    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            cpy_mat4(src, &((struct ObjNet *)dynobj)->matE8);
            break;
        case OBJ_TYPE_JOINTS:
            cpy_mat4(src, &((struct ObjNet *)dynobj)->mat168);
            break;
        case OBJ_TYPE_LIGHTS:
            ((struct ObjLight *)dynobj)->unk74.x = (*src)[3][0];
            ((struct ObjLight *)dynobj)->unk74.y = (*src)[3][1];
            ((struct ObjLight *)dynobj)->unk74.z = (*src)[3][2];
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetIMatrix()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}

/* 239B64 -> 239C78 */
Mat4 *d_get_matrix_ptr(void)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            return &((struct ObjNet *)sDynListCurObj)->mat128;
            break;
        case OBJ_TYPE_CAMERAS:
            return &((struct ObjCamera *)sDynListCurObj)->unk64;
            break;
        case OBJ_TYPE_BONES:
            return &((struct ObjBone *)sDynListCurObj)->mat70;
            break;
        case OBJ_TYPE_JOINTS:
            return &((struct ObjJoint *)sDynListCurObj)->matE8;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetMatrixPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    //! no `return NULL;`
}

/* 239C78 -> 239D4C */
Mat4 *d_get_idn_mtx_ptr(void)
{
    struct ObjHeader *dynobj;   // sp24

    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    dynobj = sDynListCurObj;
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_NETS:
            return &((struct ObjNet *)dynobj)->matE8;
            break;
        case OBJ_TYPE_JOINTS:
            return &((struct ObjJoint *)dynobj)->mat168;
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dGetIMatrixPtr()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
    //! no `return NULL;`
}

/* 239D4C -> 239DE8; orig name: func_8018B57C */
f32 d_calc_world_dist_btwn(struct ObjHeader *obj1, struct ObjHeader *obj2)
{
    struct MyVec3f obj1pos;     // sp34
    struct MyVec3f obj2pos;     // sp28
    struct MyVec3f posdiff;     // sp1C

    set_cur_dynobj(obj1);
    d_get_world_pos(&obj1pos);
    set_cur_dynobj(obj2);
    d_get_world_pos(&obj2pos);

    posdiff.x = obj2pos.x - obj1pos.x;
    posdiff.y = obj2pos.y - obj1pos.y;
    posdiff.z = obj2pos.z - obj1pos.z;

    return magnitude_vec3f(&posdiff);
}

/* 239DE8 -> 239EC0 */
void d_set_skin_weight(s32 a0, f32 a1)
{
    if (sDynListCurObj == NULL)
        fatal_printf("proc_dynlist(): No current object");
    
    switch (sDynListCurObj->type)
    {
        case OBJ_TYPE_JOINTS:
            set_skin_weight((struct ObjJoint *)sDynListCurObj, a0, NULL, a1 / 100.0); //! 100.0f
            break;
        default:
            fatal_printf("%s: Object '%s'(%x) does not support this function.",
                "dSetSkinWeight()",
                sDynListCurInfo->name,
                sDynListCurObj->type
            );
    }
}
