#include <ultra64.h>

#include "sm64.h"
#include "types.h"
#include "behavior_actions.h"
#include "game.h"
#include "main.h"
#include "mario.h"
#include "behavior_script.h"
#include "math_util.h"
#include "object_helpers.h"
#include "object_helpers2.h"
#include "behavior_data.h"
#include "obj_behaviors.h"
#include "surface_collision.h"
#include "surface_load.h"
#include "level_update.h"
#include "audio/interface_2.h"
#include "save_file.h"
#include "area.h"
#include "graph_node.h"
#include "camera.h"
#include "display.h"
#include "spawn_object.h"
#include "mario_actions_cutscene.h"
#include "object_list_processor.h"
#include "spawn_sound.h"
#include "debug.h"
#include "object_constants.h"
#include "mario_step.h"
#include "obj_behaviors_2.h"
#include "platform_displacement.h"
#include "interaction.h"
#include "ingame_menu.h"
#include "room.h"
#include "rendering_graph_node.h"

#define o gCurrentObject

// BSS
s16 D_8035FF10;

struct Struct8032F24A {
    s16 pad;
    s16 unk0;
    void* unk1;
    s16 unk2;
};

struct Struct8032F34C {
    s16 unk0;
    s16 unk1;
    s16 unk2;
    s16 unk3;
    void* unk4;
};

struct Struct8032FB4C {
    u8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s8* unk4;
};

struct Struct8032F698 {
    void* unk0;
    s16 unk1;
    s16 unk2;
    s16 unk3;
    s16 unk4;
};

struct Struct802C0DF0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    void* unk4;
};

struct Struct8032FE4C {
    s32 unk0;
    s32 unk1;
    f32 unk2;
    f32 unk3;
};

struct Struct8032F754 {
    s32 unk0;
    Vec3f unk1;
    f32 unk2;
};

struct Struct8032FCE8 {
    s16 unk0;
    s16 unk1;
    void* unk2;
};

extern void BehClimbDetectLoop();
extern s16 gDebugInfo[][8];
extern s8 D_8035FE68[][2];
extern s32 inside_castle_seg7_dl_0702A880;
extern u8 inside_castle_seg7_collision_ddd_warp_2[];
extern u8 inside_castle_seg7_collision_ddd_warp[];
extern s32 gDialogueResponse;
extern s32 D_8033B858;
extern u8 D_8032CFF4;
extern s8* D_8032F96C[];
extern u32 bowser_seg6_unkmoveshorts_060576FC[];
extern u32 blue_fish_seg3_anims_0301C2B0[];
extern u32 cyan_fish_seg6_anims_0600E264[];
extern u32 blue_fish_seg3_anims_0301C2B0[];

void func_802A8D18(f32,f32,s32);

s32 func_802BDAD4(void);
void func_802C49E0(void);

s32 D_8032F0C0[] = {SAVE_FLAG_HAVE_WING_CAP,SAVE_FLAG_HAVE_METAL_CAP,SAVE_FLAG_HAVE_VANISH_CAP};

s16 D_8032F0CC[] = {6047,5664,5292,4934,4587,4254,3933,3624,3329,3046,2775,2517,2271,2039,1818,1611,1416,1233,1063,906,761,629,509,402,308,226,157,100,56,25,4,0};

#include "behaviors/star_door.c.inc"
#include "behaviors/mr_i.c.inc"
#include "behaviors/pole.c.inc"
#include "behaviors/thi_top.c.inc"
#include "behaviors/capswitch.c.inc"
#include "behaviors/king_bobomb.c.inc"
#include "behaviors/beta_chest.c.inc"
#include "behaviors/water_objs.c.inc"
#include "behaviors/cannon.c.inc"
#include "behaviors/chuckya.c.inc"
#include "behaviors/breakable_wall.c.inc"
#include "behaviors/kickable_board.c.inc"
#include "behaviors/tower_door.c.inc"
#include "behaviors/rotating_platform.c.inc"
#include "behaviors/koopa_shell_underwater.c.inc"
#include "behaviors/warp.c.inc"
#include "behaviors/white_puff_explode.c.inc"



// not in behavior file
struct SpawnParticlesInfo D_8032F270 = {2,20,142,0,40,5,30,20,252,30,330.0f,10.0f};

void func_802AA618(s32 sp18,s32 sp1C,f32 sp20)
{
    D_8032F270.sizeBase = sp20;
    D_8032F270.sizeRange = sp20/20.0;
    D_8032F270.offsetY = sp1C;
    if(sp18 == 0)
        D_8032F270.count = 20;
    else if(sp18 > 20)
        D_8032F270.count = sp18;
    else
        D_8032F270.count = 4;
    obj_spawn_particles(&D_8032F270);
}

#include "behaviors/sparkle_spawn_star.c.inc"
#include "behaviors/coin.c.inc"
#include "behaviors/collide_particles.c.inc"
#include "behaviors/door.c.inc"
#include "behaviors/thwomp.c.inc"
#include "behaviors/tumbling_bridge.c.inc"
#include "behaviors/elevator.c.inc"
#include "behaviors/water_mist_particle.c.inc"
#include "behaviors/break_particles.c.inc"
#include "behaviors/water_mist.c.inc"
#include "behaviors/ground_particles.c.inc"
#include "behaviors/wind.c.inc"
#include "behaviors/piranha_particles.c.inc"
#include "behaviors/little_cage.c.inc"
#include "behaviors/falling_rising_platform.c.inc"
#include "behaviors/fishing_boo.c.inc"
#include "behaviors/flamethrower.c.inc"
#include "behaviors/bouncing_fireball.c.inc"
#include "behaviors/shock_wave.c.inc"
#include "behaviors/flame_mario.c.inc"
#include "behaviors/unused_1298.c.inc"
#include "behaviors/spindrift.c.inc"
#include "behaviors/tower_platform.c.inc"
#include "behaviors/tree_particles.c.inc"
#include "behaviors/square_platform_cycle.c.inc"
#include "behaviors/piranha_bubbles.c.inc"
#include "behaviors/purple_switch.c.inc"
#include "behaviors/metal_box.c.inc"
#include "behaviors/switch_hidden_objects.c.inc"
#include "behaviors/breakable_box.c.inc"

// not sure what this is doing here. not in a behavior file.
s32 Geo18_802B1BB0(s32 a0,UNUSED s32 a1, Mat4 a2)
{
    Mat4 sp20;
    struct Object* sp1C;
    if(a0 == 1)
    {
        sp1C = (struct Object*)D_8032CFA0;
        if(sp1C == gMarioObject && sp1C->prevObj != NULL)
        {
            func_8029D704(sp20,a2,D_8032CF9C->unk34);
            func_8029D558(sp20,sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

#include "behaviors/heave_ho.c.inc"
#include "behaviors/spawn_star_exit.c.inc"
#include "behaviors/pound_explode.c.inc"
#include "behaviors/beta_trampoline.c.inc"
#include "behaviors/jumping_box.c.inc"
#include "behaviors/boo_cage.c.inc"

// not in behavior file
void func_802B2328(s32 n,s32 a1,s32 a2,s32 r) // n is the number of objects to spawn, r if the rate of change of phase (frequency?)
{
    s32 i;
    s16 seperation = 0x10000/n; // Evenly spread around a circle
    for(i=0;i<n;i++)
        spawn_object_relative(0,
                                    sins(D_8035FF10+i*seperation)*a1,
                                    (i+1)*a2,
                                    coss(D_8035FF10+i*seperation)*a1,
                                    o,0,beh_powerup_sparkles2);

    D_8035FF10 += r*0x100;
}

#include "behaviors/beta_boo_key.c.inc"
#include "behaviors/grand_star.c.inc"
#include "behaviors/bowser_key.c.inc"
#include "behaviors/bullet_bill.c.inc"
#include "behaviors/bowser.c.inc"
#include "behaviors/blue_fish.c.inc"
#include "behaviors/checkerboard_platform.c.inc"
#include "behaviors/ddd_warp.c.inc"
#include "behaviors/water_pillar.c.inc"
#include "behaviors/moat_drainer.c.inc"
#include "behaviors/door_key.c.inc"
#include "behaviors/moat_grill.c.inc"
#include "behaviors/clock_arm.c.inc"
#include "behaviors/ukiki_cage.c.inc"
#include "behaviors/lll_octagonal_rotating_mesh.c.inc"
#include "behaviors/lll_sinking_rock_block.c.inc"
#include "behaviors/lll_rotating_hex_flame.c.inc"
#include "behaviors/lll_floating_wood_piece.c.inc"
#include "behaviors/lll_volcano_flames.c.inc"
#include "behaviors/lll_hexagonal_ring.c.inc"
#include "behaviors/lll_sinking_rectangle.c.inc"
#include "behaviors/lll_tilting_platform.c.inc"
#include "behaviors/koopa_shell.c.inc"
#include "behaviors/tox_box.c.inc"
#include "behaviors/piranha_plant.c.inc"
#include "behaviors/bowser_puzzle_piece.c.inc"
#include "behaviors/tuxie.c.inc"
#include "behaviors/fish.c.inc"
#include "behaviors/express_elevator.c.inc"
#include "behaviors/bub.c.inc"
#include "behaviors/exclamation_box.c.inc"
#include "behaviors/sound_spawner.c.inc"
#include "behaviors/ddd_sub.c.inc"
#include "behaviors/sushi.c.inc"
#include "behaviors/jrb_ship.c.inc"
#include "behaviors/white_puff.c.inc"
#include "behaviors/blue_coin.c.inc"
#include "behaviors/grill_door.c.inc"
#include "behaviors/wdw_water_level.c.inc"
#include "behaviors/tweester.c.inc"
#include "behaviors/boo.c.inc"
#include "behaviors/bbh_tilt_floor.c.inc"
#include "behaviors/bbh_tumbling_bookshelf.c.inc"
#include "behaviors/bbh_merry_go_round.c.inc"
#include "behaviors/static_checkered_platform.c.inc"
#include "behaviors/bait_coin.c.inc"
#ifdef VERSION_US
#include "behaviors/music_touch.c.inc"
#endif
#include "behaviors/castle_floor_trap.c.inc"

// not in behavior file
void BehClimbDetectLoop(void)
{
    if(o->oPosY - 10.0f < gMarioObject->oPosY && gMarioObject->oPosY < o->oPosY + o->hitboxHeight + 30.0f)
        if(o->oTimer > 10)
            if(!(gMarioStates->action & MARIO_PUNCHING))
                obj_push_mario_away(70.0f);
}

#include "behaviors/powerup_sparkles.c.inc"
#include "behaviors/scuttlebug.c.inc" // :scuttleeyes:
#include "behaviors/whomp.c.inc"
#include "behaviors/water_splash.c.inc"
#include "behaviors/wind_particle.c.inc"
#include "behaviors/snowman_wind.c.inc"
#include "behaviors/walking_penguin.c.inc"
