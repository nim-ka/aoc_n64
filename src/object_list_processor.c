#include <ultra64.h>
#include "libultra.h"

#include "sm64.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "camera.h"
#include "graph_node.h"
#include "interaction.h"
#include "mario.h"
#include "debug.h"
#include "memory.h"
#include "object_helpers.h"
#include "area.h"
#include "level_update.h"
#include "object_collision.h"
#include "object_list_processor.h"
#include "platform_displacement.h"
#include "profiler.h"
#include "spawn_object.h"
#include "surface_collision.h"
#include "surface_load.h"
#include "object_list_processor.h"

#if VERSION_US
extern void func_u_802C8F28(void);
#endif

struct ParticleType
{
    u32 flag;
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u16 unkA;
    void *beh;
};

u32 gTimeStopState;
struct Object gObjectPool[OBJECT_ARRAY_SIZE];
struct Object D_8035FB18;
struct ObjectNode *gObjectLists;

extern struct ObjectNode D_8033B870;

static s8 sObjectListUpdateOrder[] = 
{ 
    OBJ_LIST_SPAWNER,
    OBJ_LIST_SURFACE,
    OBJ_LIST_POLELIKE,
    OBJ_LIST_PLAYER,
    OBJ_LIST_PUSHABLE,
    OBJ_LIST_GENACTOR,
    OBJ_LIST_DESTRUCTIVE,
    OBJ_LIST_LEVEL,
    OBJ_LIST_DEFAULT,
    OBJ_LIST_UNIMPORTANT,
    -1
};

static struct ParticleType sParticleTypes[] = {
    { PARTICLE_DUST,     0x00000001, 0x8E, 0x00, 0x0000, beh_mario_dust_generator              },
    { PARTICLE_1,        0x00040000, 0x00, 0x00, 0x0000, beh_wall_tiny_star_particle_spawn     },
    { PARTICLE_4,        0x00000010, 0x00, 0x00, 0x0000, beh_pound_tiny_star_particle_spawn    },
    { PARTICLE_SPARKLES, 0x00000008, 0x95, 0x00, 0x0000, beh_special_triple_jump_sparkles      },
    { PARTICLE_5,        0x00000020, 0xA8, 0x00, 0x0000, beh_bubble_mario                      },
    { PARTICLE_6,        0x00000040, 0xA7, 0x00, 0x0000, beh_water_splash                      },
    { PARTICLE_7,        0x00000080, 0xA6, 0x00, 0x0000, beh_surface_waves                     },
    { PARTICLE_9,        0x00000200, 0xA4, 0x00, 0x0000, beh_water_waves                       },
    { PARTICLE_10,       0x00000400, 0xA3, 0x00, 0x0000, beh_wave_trail_on_surface             },
    { PARTICLE_11,       0x00000800, 0x90, 0x00, 0x0000, beh_flame_mario                       },
    { PARTICLE_8,        0x00000100, 0x00, 0x00, 0x0000, beh_waves_generator                   },
    { PARTICLE_12,       0x00001000, 0x00, 0x00, 0x0000, beh_surface_wave_shrinking            },
    { PARTICLE_LEAVES,   0x00002000, 0x00, 0x00, 0x0000, beh_snow_leaf_particle_spawn          },
    { PARTICLE_14,       0x00010000, 0x00, 0x00, 0x0000, beh_ground_snow                       },
    { PARTICLE_17,       0x00020000, 0x00, 0x00, 0x0000, beh_water_mist_spawn                  },
    { PARTICLE_15,       0x00004000, 0x00, 0x00, 0x0000, beh_ground_sand                       },
    { PARTICLE_16,       0x00008000, 0x00, 0x00, 0x0000, beh_pound_white_puffs                 },
    { PARTICLE_18,       0x00080000, 0x00, 0x00, 0x0000, beh_punch_tiny_triangle_spawn         },
    { 0,                 0x00000000, 0x00, 0x00, 0x0000, NULL                                  },
};

void nop_change_course()
{
}

static void copy_mario_state_to_object(void)
{
    s32 i = 0;
    // L is real
    if (gCurrentObject != gMarioObject)
        i += 1;

    gCurrentObject->oVelX = gMarioStates[i].vel[0];
    gCurrentObject->oVelY = gMarioStates[i].vel[1];
    gCurrentObject->oVelZ = gMarioStates[i].vel[2];

    gCurrentObject->oPosX = gMarioStates[i].pos[0];
    gCurrentObject->oPosY = gMarioStates[i].pos[1];
    gCurrentObject->oPosZ = gMarioStates[i].pos[2];

    gCurrentObject->oAnglePitch = gCurrentObject->header.gfx.angle[0];
    gCurrentObject->oAngleYaw = gCurrentObject->header.gfx.angle[1];
    gCurrentObject->oAngleRoll = gCurrentObject->header.gfx.angle[2];

    gCurrentObject->oFaceAnglePitch = gCurrentObject->header.gfx.angle[0];
    gCurrentObject->oFaceAngleYaw = gCurrentObject->header.gfx.angle[1];
    gCurrentObject->oFaceAngleRoll = gCurrentObject->header.gfx.angle[2];

    gCurrentObject->oAngleVelPitch = gMarioStates[i].angleVel[0];
    gCurrentObject->oAngleVelYaw = gMarioStates[i].angleVel[1];
    gCurrentObject->oAngleVelRoll = gMarioStates[i].angleVel[2];
}

static void spawn_particle(u32 flags, s16 seg, void *script)
{
    if (!(gCurrentObject->oUnkE0 & flags))
    {
        struct Object *particle;
        gCurrentObject->oUnkE0 |= flags;
        particle = func_8029E5A4(gCurrentObject, 0, seg, script);
        CopyObjParams(particle, gCurrentObject);
    }
}

void BehMarioLoop2(void)
{
    u32 particleFlags = 0; 
    s32 i;

    particleFlags = func_80254604(gCurrentObject);
    gCurrentObject->oMarioParticleFlags = particleFlags;
    copy_mario_state_to_object();

    i = 0;
    while (sParticleTypes[i].flag != 0)
    {
        if (particleFlags & sParticleTypes[i].flag)
            spawn_particle(sParticleTypes[i].unk4, sParticleTypes[i].unk8, sParticleTypes[i].beh);

        i++;
    }
}

static s32 update_objects_starting_at(struct ObjectNode *listHead, struct ObjectNode *firstObj)
{
    s32 count = 0;
    
    while (listHead != firstObj)
    {
        gCurrentObject = (struct Object *) firstObj;

        gCurrentObject->header.gfx.node.flags |= 0x0020;
        cur_object_exec_behavior();

        firstObj = firstObj->next;
        count += 1;
    }

    return count;
}

static s32 update_objects_during_time_stop(struct ObjectNode *listHead, struct ObjectNode *firstObj)
{
    s32 count = 0;
    s32 unfrozen;

    while (listHead != firstObj)
    {
        gCurrentObject = (struct Object *) firstObj;

        unfrozen = FALSE;
        if (!(gTimeStopState & TIME_STOP_ALL_OBJECTS))
        { 
            if (gCurrentObject == gMarioObject &&
                !(gTimeStopState & TIME_STOP_MARIO_AND_DOORS))
            {
                unfrozen = TRUE;
            }
            
            if ((gCurrentObject->oInteractType & (INTERACT_DOOR | INTERACT_WARP_DOOR)) &&
                !(gTimeStopState & TIME_STOP_MARIO_AND_DOORS))
            {
                unfrozen = TRUE;
            }

            if (gCurrentObject->active & 0x30)
                unfrozen = TRUE;
        }

        if (unfrozen)
        {
            gCurrentObject->header.gfx.node.flags |= 0x20;
            cur_object_exec_behavior();
        }
        else
        {
            gCurrentObject->header.gfx.node.flags &= ~0x20;
        }

        firstObj = firstObj->next;
        count++;
    }

    return count;
}

static s32 update_objects_in_list(struct ObjectNode *objList)
{
    s32 count;
    struct ObjectNode *firstObj = objList->next;

    if (!(gTimeStopState & TIME_STOP_ACTIVE))
        count = update_objects_starting_at(objList, firstObj);
    else
        count = update_objects_during_time_stop(objList, firstObj);

    return count;
}

static s32 func_8029C618(struct ObjectNode *objList)
{
    struct ObjectNode *obj = objList->next;

    while (objList != obj)
    {
        gCurrentObject = (struct Object *) obj;
        
        obj = obj->next;

        if ((gCurrentObject->active & 0x01) != 1)
        {
            if ((gCurrentObject->oFlags & 0x4000) == 0)
                func_8029C6D8(gCurrentObject, 0xFF);

            unload_obj(gCurrentObject);
        }
    }

    return 0;
}

void func_8029C6D8(struct Object *a0, u8 a1)
{  
    s32 *spC;
    u16 *sp8;

    switch(a0->unk1F6)
    {
    case 1:
        spC = a0->unk25C;
        *spC |= a1 << 8; 
        break;
    
    case 2:
        sp8 = a0->unk25C;
        *sp8 |= a1 << 8; 
        break;
    }
}

void func_8029C75C(UNUSED s32 sp28, s32 sp2C)
{
    struct ObjectNode *sp24, *sp20, *sp1C;
    s32 sp18;
    gObjectLists = &D_8033B870;
    
    for (sp18 = 0; sp18 < 13; sp18++)
    {
        sp1C = gObjectLists + sp18;
        sp20 = sp1C->next;

        while (sp20 != sp1C)
        {
            sp24 = sp20;
            sp20 = sp20->next;
            if (sp24->gfx.unk19 == sp2C)
                unload_obj((struct Object *) sp24);
        }
    }
}

void spawn_objects_from_info(UNUSED s32 unusedArg, struct SpawnInfo *spawnInfo)
{
    gObjectLists = &D_8033B870;
    gTimeStopState = 0;

    D_8035FEF2 = 0;
    D_8035FEF4 = 0;

#if VERSION_US
    func_u_802C8F28();
#endif

    if (gCurrAreaIndex == 2) 
        D_8035FEEC |= 1;

    while (spawnInfo != NULL)
    {
        struct Object *object;
        UNUSED s32 unused;
        void *script;
        UNUSED s16 arg16;

        arg16 = (s16)(spawnInfo->behaviorArg & 0xFFFF);
        script = segmented_to_virtual(spawnInfo->behaviorScript);

        if ((spawnInfo->behaviorArg & 0xFF00) != 0xFF00)
        {
            object = create_object(script);
 
            object->oBehParamCopy = spawnInfo->behaviorArg;
            object->oBehParam = ((spawnInfo->behaviorArg) >> 16) & 0xff;
            object->behavior = script;
            object->unk1C8 = 0;
            object->unk1F6 = 1;
            object->unk25C = &spawnInfo->behaviorArg; 

            if (spawnInfo->behaviorArg & 0x01)
            {
                gMarioObject = object;
                func_8037C138((struct GraphNode *) object);
            }

            func_8037C51C((struct GraphNodeObject *) object, spawnInfo);
            
            object->oPosX = spawnInfo->startPos[0];
            object->oPosY = spawnInfo->startPos[1];
            object->oPosZ = spawnInfo->startPos[2];

            object->oFaceAnglePitch = spawnInfo->startAngle[0];
            object->oFaceAngleYaw = spawnInfo->startAngle[1];
            object->oFaceAngleRoll = spawnInfo->startAngle[2];
            
            object->oAnglePitch = spawnInfo->startAngle[0];
            object->oAngleYaw = spawnInfo->startAngle[1];
            object->oAngleRoll = spawnInfo->startAngle[2];

        }
        
        spawnInfo = spawnInfo->next;
    }
}

static void func_8029CA50()
{
}

void func_8029CA60(void)
{ 
    s32 i;

    D_8035FEE6 = 0;
    gTimeStopState = 0;
    gMarioObject = NULL;
    D_8035FEE0 = 0;

    for (i = 0; i < 60; i++)
    {
        D_8035FE68[i][0] = 0;
        D_8035FE68[i][1] = 0;
    }

    debug_unknown_level_select_check();
    init_free_obj_list();
    clear_object_lists(&D_8033B870);
    func_80385BF0();
    func_8029CA50();

    for (i = 0; i < OBJECT_ARRAY_SIZE; i++)
    {
        gObjectPool[i].active = 0;
        func_8037C3D0(&gObjectPool[i].header.gfx);
    }

    D_8035FE0C = mem_pool_init(0x800, MEMORY_POOL_LEFT);
    gObjectLists = &D_8033B870;
    clear_dynamic_surfaces();
}

static void update_terrain_objects(void)
{
    gUpdatedObjectCount = update_objects_in_list(&gObjectLists[OBJ_LIST_SPAWNER]);
    //! This was meant to be +=
    gUpdatedObjectCount = update_objects_in_list(&gObjectLists[OBJ_LIST_SURFACE]);
} 


static void update_non_terrain_objects(void)
{
    UNUSED s32 unused; 
    s32 listIndex;

    s32 i = 2;
    while ((listIndex = sObjectListUpdateOrder[i]) != -1)
    {
        gUpdatedObjectCount += update_objects_in_list(&gObjectLists[listIndex]);
        i += 1;
    }
}

static void func_8029CCA0(void)
{
    UNUSED s32 unused; 
    s32 listIndex;

    s32 i = 0;
    while ((listIndex = sObjectListUpdateOrder[i]) != -1)
    {
        func_8029C618(&gObjectLists[listIndex]);
        i += 1;
    }

    gTimeStopState &= ~TIME_STOP_UNKNOWN_0;
}

static u16 unused_get_elapsed_time(u64 *cycleCounts, s32 index)
{
    u16 time;
    f64 cycles;

    cycles = cycleCounts[index] - cycleCounts[index - 1];
    if (cycles < 0)
        cycles = 0;

    time = (u16) (((u64) cycles * 1000000 / osClockRate) / 16667.0 * 1000.0);
    if (time > 999)
        time = 999;
    
    return time;
}

void update_objects(UNUSED s32 sp108)
{
    s64 cycleCounts[30];

    cycleCounts[0] = get_current_clock();

    gTimeStopState &= ~TIME_STOP_UNKNOWN_5;

    D_8035FEEE = 0;
    D_8035FEF0 = 0;
    D_8035FE10 = 0;

    reset_debug_objectinfo();
    stub_802CA5D0();
    
    gObjectLists = &D_8033B870;
    
    cycleCounts[1] = get_clock_difference(cycleCounts[0]);
    clear_dynamic_surfaces();

    cycleCounts[2] = get_clock_difference(cycleCounts[0]);
    update_terrain_objects();
    
    apply_mario_platform_displacement();
    
    cycleCounts[3] = get_clock_difference(cycleCounts[0]);
    func_802C8C44();
    
    cycleCounts[4] = get_clock_difference(cycleCounts[0]);
    update_non_terrain_objects();
    
    cycleCounts[5] = get_clock_difference(cycleCounts[0]);
    func_8029CCA0();
    
    cycleCounts[6] = get_clock_difference(cycleCounts[0]);
    update_mario_platform();
    
    cycleCounts[7] = get_clock_difference(cycleCounts[0]);  

    cycleCounts[0] = 0;
    try_print_debug_mario_object_info();

    if (gTimeStopState & TIME_STOP_ENABLED)
        gTimeStopState |= TIME_STOP_ACTIVE;
    else 
        gTimeStopState &= ~TIME_STOP_ACTIVE;
    
    gPostUpdateObjCount = gUpdatedObjectCount;
}
