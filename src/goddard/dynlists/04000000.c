#include <ultra64.h>

#include "sm64.h"
#include "macros.h"
#include "dynlists.h"
#include "../mario_head_4.h"
// maybe move types into the dynlists.h file?

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wint-conversion"
struct DynList dynlist_04000000[67] = { 
    StartList(), 
    StartGroup("ico1vg"), 
    MakeVertex(-2.0, 0.0, -2.0), 
    MakeVertex(-2.0, 0.0, 2.0), 
    MakeVertex(2.0, 0.0, 2.0), 
    MakeVertex(2.0, 0.0, -2.0), 
    MakeVertex(0.0, 3.0, 0.0), 
    MakeVertex(0.0, -3.0, 0.0), 
    EndGroup("ico1vg"), 
    StartGroup("ico1pg"), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 1), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 2), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 2), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 3), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 4), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 2), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 3), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 1), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 2), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 4), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 1), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 4), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 0), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 3), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 4), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 5), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 3), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 2), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 1), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 5), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 2), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 1), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 5), 
    MakeDynObj(D_FACE, NULL), 
    SetMaterial(NULL, 0), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 3), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 5), 
    SetParamPtr(PARM_PTR_OBJ_VTX, 0), 
    EndGroup("ico1pg"), 
    UseObj("ico1pg"), 
    MapVertices("ico1vg"), 
    MakeDynObj(D_SHAPE, "ico1_sh"), 
    SetNodeGroup("ico1vg"), 
    SetPlaneGroup("ico1pg"), 
    StopList(), 
};

#pragma GCC diagnostic pop