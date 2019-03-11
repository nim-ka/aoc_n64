#ifndef _SPECIAL_PRESETS_H
#define _SPECIAL_PRESETS_H

#include "special_preset_names.h"
#include "behavior_data.h"
#include "model_ids.h"

struct SpecialPreset
{
    /*00*/ u8  preset_id;
    /*01*/ u8  param1;
    /*02*/ u8  param2;
    /*03*/ u8  model;
    /*04*/ u32 (*beh)[];
};

// Some Models ID's are missing their names because they are probably unused

static struct SpecialPreset SpecialObjectPresets[] = 
{
    {0x00, 0x01, 0x00, MODEL_NONE, NULL},                            
    {0x01, 0x00, 0x00, MODEL_YELLOW_COIN, &beh_yellow_coin},
    {0x02, 0x00, 0x00, MODEL_YELLOW_COIN, &beh_yellow_coin},           
    {0x03, 0x00, 0x00, 0xB8, &beh_static_object},
    {0x04, 0x00, 0x00, MODEL_BOO, &beh_boo_group},                  
    {0x05, 0x00, 0x00, 0xAC, &beh_castle_floor_trap},
    {0x06, 0x00, 0x00, MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, &beh_lll_moving_octagonal_mesh_platform},        
    {0x07, 0x00, 0x00, MODEL_CCM_SNOWMAN_HEAD, &beh_snow_ball},
    {0x08, 0x01, 0x00, MODEL_LLL_DRAWBRIDGE_PART, &beh_lll_drawbridge_spawner},             
    {0x09, 0x00, 0x00, MODEL_NONE, &beh_static_object},
    {0x0A, 0x00, 0x00, MODEL_LLL_ROTATING_BLOCK_FIRE_BARS, &beh_lll_rotating_block_with_fire_bars}, 
    {0x0B, 0x00, 0x00, MODEL_NONE, &beh_lll_floating_wood_bridge},
    {0x0C, 0x00, 0x00, MODEL_NONE, &beh_tumbling_platform},          
    {0x0D, 0x00, 0x00, MODEL_LLL_ROTATING_HEXAGONAL_RING , &beh_lll_rotating_hexagonal_ring},
    {0x0E, 0x01, 0x00, MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, &beh_lll_sinking_rectangular_platform},  
    {0x0F, 0x00, 0x00, MODEL_LLL_SINKING_SQUARE_PLATFORMS, &beh_lll_sinking_square_platforms},
    {0x10, 0x00, 0x00, MODEL_LLL_TILTING_SQUARE_PLATFORM, &beh_lll_tilting_square_platform},  
    {0x11, 0x00, 0x00, MODEL_NONE, &beh_lll_bowser_puzzle},
    {0x12, 0x00, 0x00, MODEL_NONE, &beh_mr_i},                       
    {0x13, 0x00, 0x00, MODEL_BULLY, &beh_small_bully},
    {0x14, 0x00, 0x00, MODEL_BULLY_BOSS, &beh_big_bully},                  
    {0x15, 0x00, 0x00, MODEL_NONE, &beh_static_object},
    {0x16, 0x00, 0x00, MODEL_NONE, &beh_static_object},              
    {0x17, 0x00, 0x00, MODEL_NONE, &beh_static_object},
    {0x18, 0x00, 0x00, MODEL_NONE, &beh_static_object},              
    {0x19, 0x00, 0x00, MODEL_NONE, &beh_static_object},
    {0x1A, 0x00, 0x00, MODEL_YELLOW_COIN, &beh_moving_blue_coin},     // ??   
    {0x1B, 0x00, 0x00, MODEL_TREASURE_CHEST_BASE, &beh_beta_chest},
    {0x1C, 0x00, 0x00, MODEL_WATER_RING, &beh_jet_stream_ring_spawner},    
    {0x1D, 0x00, 0x00, MODEL_WATER_MINE, &beh_bowser_bomb},
    {0x1E, 0x03, 0x00, MODEL_NONE, &beh_static_object},              
    {0x1F, 0x00, 0x00, MODEL_NONE, &beh_static_object},
    {0x20, 0x00, 0x00, MODEL_BUTTERFLY, &beh_butterfly},                  
    {0x21, 0x00, 0x00, MODEL_COMMON13_64, &beh_bowser},
    {0x22, 0x00, 0x00, MODEL_WF_ROTATING_WOODEN_PLATFORM, &beh_wf_rotating_wooden_platform},         
    {0x23, 0x01, 0x00, MODEL_WF_SMALL_BOMP, &beh_small_bomp},
    {0x24, 0x01, 0x00, MODEL_WF_SLIDING_PLATFORM, &beh_wf_sliding_platform},   
    {0x25, 0x00, 0x00, MODEL_NONE, &beh_tower_platform_group},
    {0x26, 0x00, 0x00, MODEL_NONE, &beh_rotating_counter_clockwise}, 
    {0x27, 0x00, 0x00, MODEL_WF_TUMBLING_BRIDGE_PART, &beh_wf_tumbling_bridge},
    {0x28, 0x00, 0x00, MODEL_WF_LARGE_BOMP, &beh_large_bomp},            
    {0x65, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_03, &beh_static_object},
    {0x66, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_04, &beh_static_object},              
    {0x67, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_05, &beh_static_object},
    {0x68, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_06, &beh_static_object},              
    {0x69, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_07, &beh_static_object},
    {0x6A, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_08, &beh_static_object},              
    {0x6B, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_09, &beh_static_object},
    {0x6C, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_0A, &beh_static_object},              
    {0x6D, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_0B, &beh_static_object},
    {0x6E, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_0C, &beh_static_object},              
    {0x6F, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_0D, &beh_static_object},
    {0x70, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_0E, &beh_static_object},              
    {0x71, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_0F, &beh_static_object},
    {0x72, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_10, &beh_static_object},              
    {0x73, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_11, &beh_static_object},
    {0x74, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_12, &beh_static_object},              
    {0x75, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_13, &beh_static_object},
    {0x76, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_14, &beh_static_object},              
    {0x77, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_15, &beh_static_object},
    {0x78, 0x01, 0x00, MODEL_LEVEL_GEOMETRY_16, &beh_static_object},              
    {0x79, 0x00, 0x00, MODEL_BOB_BUBBLY_TREE, &beh_tree},
    {0x7A, 0x00, 0x00, MODEL_COURTYARD_SPIKY_TREE, &beh_tree},                       
    {0x7B, 0x00, 0x00, MODEL_CCM_SNOW_TREE, &beh_tree},
    {0x7C, 0x00, 0x00, 0x1A, &beh_tree},                       
    {0x7D, 0x00, 0x00, MODEL_SSL_PALM_TREE, &beh_tree},
    {0x89, 0x01, 0x00, MODEL_CASTLE_CASTLE_DOOR, &beh_door},                       
    {0x7E, 0x01, 0x00, MODEL_CASTLE_WOODEN_DOOR, &beh_door},
    {0x7F, 0x01, 0x00, 0x1E, &beh_door},                       
    {0x80, 0x01, 0x00, MODEL_HMC_METAL_DOOR, &beh_door},
    {0x81, 0x01, 0x00, MODEL_HMC_HAZY_MAZE_DOOR, &beh_door},                       
    {0x82, 0x01, 0x00, 0x21, &beh_door},
    {0x8A, 0x04, 0x00, MODEL_CASTLE_DOOR_0_STARS, &beh_door},                       
    {0x8B, 0x04, 0x01, MODEL_CASTLE_DOOR_1_STAR, &beh_door},
    {0x8C, 0x04, 0x03, MODEL_CASTLE_DOOR_3_STARS, &beh_door},                       
    {0x8D, 0x04, 0x00, MODEL_CASTLE_KEY_DOOR, &beh_door},
    {0x88, 0x02, 0x00, MODEL_CASTLE_26, &beh_door_warp},                  
    {0x83, 0x02, 0x00, MODEL_CASTLE_27, &beh_door_warp},
    {0x84, 0x02, 0x00, 0x28, &beh_door_warp},                  
    {0x85, 0x02, 0x00, MODEL_CASTLE_METAL_DOOR, &beh_door_warp},
    {0x86, 0x02, 0x00, 0x2A, &beh_door_warp},                  
    {0x87, 0x02, 0x00, 0x2B, &beh_door_warp},
    {0xFF, 0x00, 0x00, MODEL_NONE, NULL}
};

#endif // _SPECIAL_PRESETS_H
