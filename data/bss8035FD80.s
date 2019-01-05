.include "macros.inc"

.section .bss

glabel gFreeObjectList 
    .space 0x68
glabel gMarioObject
    .space 0x4
glabel gLuigiObject
    .space 0x4
glabel gCurrentObject
    .space 0x4
glabel gBehCommand 
    .space 0x4
glabel gPostUpdateObjCount
    .space 0x4
glabel gSurfaceNodesAllocated 
    .space 0x4
glabel gSurfacesAllocated
    .space 0x4
glabel gNumStaticSurfaceNodes
    .space 0x4
glabel gNumStaticSurfaces
    .space 0x4
glabel D_8035FE0C 
    .space 0x4 
