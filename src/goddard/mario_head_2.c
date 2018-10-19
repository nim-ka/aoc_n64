#include <ultra64.h>

#include "sm64.h"
#include "mario_head_1.h"
#include "mario_head_2.h"
#include "profiler_utils.h"
#include "matrix_fns.h"

#include "gd_types.h"

/* bss */
struct ObjWeight* sSkinNetCurWeight;
static Mat4 D_801B9EA8;               // TODO: rename to sHead2Mtx?
static struct ObjJoint* D_801B9EE8;

extern s32 sTargetWeightID;
extern struct ObjNet* gGdSkinNet;

/* @ 22FDB0 for 0x180 */
void Unknown801815E0(Mat4* mtx)
{
    struct MyVec3f scratchVec;

    scratchVec.x = (*mtx)[0][0];
    scratchVec.y = (*mtx)[0][1];
    scratchVec.z = (*mtx)[0][2];
    func_80194BF4(&scratchVec);
    (*mtx)[0][0] = scratchVec.x;
    (*mtx)[0][1] = scratchVec.y;
    (*mtx)[0][2] = scratchVec.z;

    scratchVec.x = (*mtx)[1][0];
    scratchVec.y = (*mtx)[1][1];
    scratchVec.z = (*mtx)[1][2];
    func_80194BF4(&scratchVec);
    (*mtx)[1][0] = scratchVec.x;
    (*mtx)[1][1] = scratchVec.y;
    (*mtx)[1][2] = scratchVec.z;

    scratchVec.x = (*mtx)[2][0];
    scratchVec.y = (*mtx)[2][1];
    scratchVec.z = (*mtx)[2][2];
    func_80194BF4(&scratchVec);
    (*mtx)[2][0] = scratchVec.x;
    (*mtx)[2][1] = scratchVec.y;
    (*mtx)[2][2] = scratchVec.z;
}

/* @ 22FF30 for 0xDC */
/* called with ObjNext->unk1A8 (variable obj ptr?) ->unk20 or ->unk24 ptr*/
// TODO: figure out the proper object type for a0
void func_80181760(struct ObjUnkFromNet1A8* a0)
{
    register f32 sp1C;
    register struct ObjUnkSub* subStruct;
    Mat4* mtx;
    
    for (subStruct = a0->ptr1C; subStruct != NULL; subStruct = subStruct->next)
    {
        mtx = subStruct->mat08;

        if ((sp1C = (*mtx)[3][3]) != 0.0f)
        {
            (*mtx)[2][0] = (*mtx)[1][1] * sp1C;
            (*mtx)[2][1] = (*mtx)[1][2] * sp1C;
            (*mtx)[2][2] = (*mtx)[1][3] * sp1C;
        } 
        else
            (*mtx)[2][0] = (*mtx)[2][1] = (*mtx)[2][2] = 0.0f;
    }
}

/* @ 23000C for 0x58; orig name: func8018183C*/
void move_skin(struct ObjNet* net)
{
    UNUSED u8 pad1C[8];

    if (net->unk1A8 != NULL)
        func_80181760(((struct ObjUnkFromNet1A8*)net->unk1A8)->unk24);
}

/* @ 230064 for 0x13C*/
void func_80181894(struct ObjJoint* joint)
{   
    register struct ObjGroup* weightGroup;  //baseGroup? weights Only?
    struct MyVec3f stackVec;
    register struct ObjWeight* curWeight;
    register struct ObjVertex* connectedVtx;
    register struct Links* link;
    register f32 scaleFactor;
    struct ObjHeader* linkedObj;

    weightGroup = joint->unk1F4;
    if (weightGroup != NULL)
    {
        for (link = weightGroup->link1C; link != NULL; link = link->next)
        {
            linkedObj = link->obj;
            curWeight = (struct ObjWeight*) linkedObj;

            if (curWeight->unk38 > 0.0) //! 0.0f
            {
                stackVec.x = curWeight->vec20.x;
                stackVec.y = curWeight->vec20.y;
                stackVec.z = curWeight->vec20.z;
                func_80196430(&stackVec, &joint->matE8);

                connectedVtx = curWeight->unk3C;
                scaleFactor = curWeight->unk38;

                connectedVtx->vec20.x += stackVec.x * scaleFactor;
                connectedVtx->vec20.y += stackVec.y * scaleFactor;
                connectedVtx->vec20.z += stackVec.z * scaleFactor;
            }
        }
    }
}

/* @ 2301A0 for 0x110 */
void Unknown801819D0(struct ObjVertex* vtx)
{
    struct MyVec3f localVec;
    UNUSED u8 pad24[0x10];

    if (sTargetWeightID++ == sSkinNetCurWeight->id)
    {
        sSkinNetCurWeight->unk3C = vtx;
        localVec.x = vtx->vec20.x;
        localVec.y = vtx->vec20.y;
        localVec.z = vtx->vec20.z;

        func_80196430(&localVec, &D_801B9EA8);
        sSkinNetCurWeight->vec20.x = localVec.x;
        sSkinNetCurWeight->vec20.y = localVec.y;
        sSkinNetCurWeight->vec20.z = localVec.z;

        vtx->unk3C -= sSkinNetCurWeight->unk38;
    }
}

/* @ 2302B0 for 0xA8; orig name: Unknown80181AE0 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
void reset_weight(struct ObjWeight* weight)
{
    u32 vtxCount;
    UNUSED u32 pad20;
    struct ObjGroup* skinGroup;

    sSkinNetCurWeight = weight;
    sTargetWeightID = 0;
    if ((skinGroup = gGdSkinNet->skinGrp) != NULL)
        vtxCount = apply_to_obj_types_in_group(
            OBJ_TYPE_VERTICES,
            &Unknown801819D0,
            skinGroup
        );
    else 
        myPrintf("reset_weight(): Skin net has no SkinGroup");
    
    if (weight->unk3C == NULL)
        myPrintf("reset_weight(): Skin vertex ID %d not found", weight->id);
}
#pragma GCC diagnostic pop

/* @ 230358 for 0x78; rename to reset_joint_weight? */
void Unknown80181B88(struct ObjJoint* joint)
{
    struct ObjGroup* group;

    func_80194E7C(&joint->matE8, &D_801B9EA8);
    D_801B9EE8 = joint;
    if ((group = joint->unk1F4) != NULL)
        apply_to_obj_types_in_group(
            OBJ_TYPE_WEIGHTS,
            &reset_weight,
            group
        );
}
