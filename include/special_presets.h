#ifndef _SPECIAL_PRESETS_H
#define _SPECIAL_PRESETS_H

#include "special_preset_names.h"
#include "behavior_data.h"
#include "model_ids.h"

// Special Preset types
#define SPTYPE_NO_YROT_OR_PARAMS  0 // object is 8-bytes long, no y-rotation or any behavior params
#define SPTYPE_YROT_NO_PARAMS     1 // object is 10-bytes long, has y-rotation but no params
#define SPTYPE_PARAMS_AND_YROT    2 // object is 12-bytes long, has y-rotation and params
#define SPTYPE_UNKNOWN            3 // object is 14-bytes long, has 3 extra shorts that get converted to floats.
#define SPTYPE_DEF_PARAM_AND_YROT 4 // object is 10-bytes long, has y-rotation and uses the default param

struct SpecialPreset
{
    /*00*/ u8  preset_id;
    /*01*/ u8  type;      // Determines whether object is 8, 10, 12 or 14 bytes long.
    /*02*/ u8  defParam;  // Default parameter, only used when type is SPTYPE_DEF_PARAM_AND_YROT
    /*03*/ u8  model;     
    /*04*/ u32 *behavior;
};

// Some Models ID's are missing their names because they are probably unused

static struct SpecialPreset SpecialObjectPresets[] = 
{
    {0x00, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_NONE, NULL},
    {0x01, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_YELLOW_COIN, beh_yellow_coin},
    {0x02, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_YELLOW_COIN, beh_yellow_coin},
    {0x03, SPTYPE_NO_YROT_OR_PARAMS , 0x00, 0xB8, beh_static_object},
    {0x04, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_BOO, beh_boo_group},
    {0x05, SPTYPE_NO_YROT_OR_PARAMS , 0x00, 0xAC, beh_castle_floor_trap},
    {0x06, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, beh_lll_moving_octagonal_mesh_platform},
    {0x07, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_CCM_SNOWMAN_HEAD, beh_snow_ball},
    {0x08, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LLL_DRAWBRIDGE_PART, beh_lll_drawbridge_spawner},
    {0x09, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x0A, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_LLL_ROTATING_BLOCK_FIRE_BARS, beh_lll_rotating_block_with_fire_bars},
    {0x0B, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_lll_floating_wood_bridge},
    {0x0C, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_tumbling_platform},
    {0x0D, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_LLL_ROTATING_HEXAGONAL_RING , beh_lll_rotating_hexagonal_ring},
    {0x0E, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, beh_lll_sinking_rectangular_platform},
    {0x0F, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_LLL_SINKING_SQUARE_PLATFORMS, beh_lll_sinking_square_platforms},
    {0x10, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_LLL_TILTING_SQUARE_PLATFORM, beh_lll_tilting_square_platform},
    {0x11, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_lll_bowser_puzzle},
    {0x12, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_mr_i},
    {0x13, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_BULLY, beh_small_bully},
    {0x14, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_BULLY_BOSS, beh_big_bully},
    {0x15, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x16, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x17, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x18, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x19, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x1A, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_YELLOW_COIN, beh_moving_blue_coin},     // ??   
    {0x1B, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_TREASURE_CHEST_BASE, beh_beta_chest},
    {0x1C, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_WATER_RING, beh_jet_stream_ring_spawner},
    {0x1D, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_WATER_MINE, beh_bowser_bomb},
    {0x1E, SPTYPE_UNKNOWN           , 0x00, MODEL_NONE, beh_static_object},
    {0x1F, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_static_object},
    {0x20, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_BUTTERFLY, beh_butterfly},
    {0x21, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_COMMON13_64, beh_bowser},
    {0x22, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_WF_ROTATING_WOODEN_PLATFORM, beh_wf_rotating_wooden_platform},
    {0x23, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_WF_SMALL_BOMP, beh_small_bomp},
    {0x24, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_WF_SLIDING_PLATFORM, beh_wf_sliding_platform},
    {0x25, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_tower_platform_group},
    {0x26, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, beh_rotating_counter_clockwise},
    {0x27, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_WF_TUMBLING_BRIDGE_PART, beh_wf_tumbling_bridge},
    {0x28, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_WF_LARGE_BOMP, beh_large_bomp},
    {0x65, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_03, beh_static_object},
    {0x66, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_04, beh_static_object},
    {0x67, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_05, beh_static_object},
    {0x68, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_06, beh_static_object},
    {0x69, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_07, beh_static_object},
    {0x6A, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_08, beh_static_object},
    {0x6B, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_09, beh_static_object},
    {0x6C, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_0A, beh_static_object},
    {0x6D, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_0B, beh_static_object},
    {0x6E, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_0C, beh_static_object},
    {0x6F, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_0D, beh_static_object},
    {0x70, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_0E, beh_static_object},
    {0x71, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_0F, beh_static_object},
    {0x72, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_10, beh_static_object},
    {0x73, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_11, beh_static_object},
    {0x74, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_12, beh_static_object},
    {0x75, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_13, beh_static_object},
    {0x76, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_14, beh_static_object},
    {0x77, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_15, beh_static_object},
    {0x78, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_LEVEL_GEOMETRY_16, beh_static_object},
    {0x79, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_BOB_BUBBLY_TREE, beh_tree},
    {0x7A, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_COURTYARD_SPIKY_TREE, beh_tree},
    {0x7B, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_CCM_SNOW_TREE, beh_tree},
    {0x7C, SPTYPE_NO_YROT_OR_PARAMS , 0x00, 0x1A, beh_tree},
    {0x7D, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_SSL_PALM_TREE, beh_tree},
    {0x89, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_CASTLE_CASTLE_DOOR, beh_door},
    {0x7E, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_CASTLE_WOODEN_DOOR, beh_door},
    {0x7F, SPTYPE_YROT_NO_PARAMS    , 0x00, 0x1E, beh_door},
    {0x80, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_HMC_METAL_DOOR, beh_door},
    {0x81, SPTYPE_YROT_NO_PARAMS    , 0x00, MODEL_HMC_HAZY_MAZE_DOOR, beh_door},
    {0x82, SPTYPE_YROT_NO_PARAMS    , 0x00, 0x21, beh_door},
    {0x8A, SPTYPE_DEF_PARAM_AND_YROT, 0x00, MODEL_CASTLE_DOOR_0_STARS, beh_door},
    {0x8B, SPTYPE_DEF_PARAM_AND_YROT, 0x01, MODEL_CASTLE_DOOR_1_STAR, beh_door},
    {0x8C, SPTYPE_DEF_PARAM_AND_YROT, 0x03, MODEL_CASTLE_DOOR_3_STARS, beh_door},
    {0x8D, SPTYPE_DEF_PARAM_AND_YROT, 0x00, MODEL_CASTLE_KEY_DOOR, beh_door},
    {0x88, SPTYPE_PARAMS_AND_YROT   , 0x00, MODEL_CASTLE_26, beh_door_warp},
    {0x83, SPTYPE_PARAMS_AND_YROT   , 0x00, MODEL_CASTLE_27, beh_door_warp},
    {0x84, SPTYPE_PARAMS_AND_YROT   , 0x00, 0x28, beh_door_warp},
    {0x85, SPTYPE_PARAMS_AND_YROT   , 0x00, MODEL_CASTLE_METAL_DOOR, beh_door_warp},
    {0x86, SPTYPE_PARAMS_AND_YROT   , 0x00, 0x2A, beh_door_warp},
    {0x87, SPTYPE_PARAMS_AND_YROT   , 0x00, 0x2B, beh_door_warp},
    {0xFF, SPTYPE_NO_YROT_OR_PARAMS , 0x00, MODEL_NONE, NULL}
};

#endif // _SPECIAL_PRESETS_H
