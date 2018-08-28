.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel mist_geo # 0x16000000
   geo_node_start
   geo_open_node
      geo_asm 0, Geo18_8029D924
      geo_display_list 0x05, mist_seg3_dl_03000880
   geo_close_node
   geo_end

glabel white_puff_geo # 0x16000020
   geo_node_start
   geo_open_node
      geo_asm 0, Geo18_8029D924
      geo_display_list 0x05, white_puff_seg3_dl_03000920
   geo_close_node
   geo_end

glabel explosion_geo # 0x16000040
   geo_node_start
   geo_open_node
      geo_switch_case 9, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x05, explosion_seg3_dl_03004298
         geo_display_list 0x05, explosion_seg3_dl_03004298
         geo_display_list 0x05, explosion_seg3_dl_030042B0
         geo_display_list 0x05, explosion_seg3_dl_030042B0
         geo_display_list 0x05, explosion_seg3_dl_030042C8
         geo_display_list 0x05, explosion_seg3_dl_030042E0
         geo_display_list 0x05, explosion_seg3_dl_030042F8
         geo_display_list 0x05, explosion_seg3_dl_03004310
         geo_display_list 0x05, explosion_seg3_dl_03004328
      geo_close_node
   geo_close_node
   geo_end

glabel butterfly_geo # 0x160000A8
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 25
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x04, 0, 0, 0, butterfly_seg3_dl_03005408
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
            geo_close_node
         geo_close_node
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x04, 0, 0, 0, butterfly_seg3_dl_030054A0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel yellow_coin_geo # 0x1600013C
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 50
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, yellow_coin_seg3_dl_03007800
         geo_display_list 0x04, yellow_coin_seg3_dl_03007800
         geo_display_list 0x04, yellow_coin_seg3_dl_03007828
         geo_display_list 0x04, yellow_coin_seg3_dl_03007828
         geo_display_list 0x04, yellow_coin_seg3_dl_03007850
         geo_display_list 0x04, yellow_coin_seg3_dl_03007850
         geo_display_list 0x04, yellow_coin_seg3_dl_03007878
         geo_display_list 0x04, yellow_coin_seg3_dl_03007878
      geo_close_node
   geo_close_node
   geo_end

glabel yellow_coin_no_shadow_geo # 0x160001A0
   geo_node_start
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, yellow_coin_seg3_dl_03007800
         geo_display_list 0x04, yellow_coin_seg3_dl_03007800
         geo_display_list 0x04, yellow_coin_seg3_dl_03007828
         geo_display_list 0x04, yellow_coin_seg3_dl_03007828
         geo_display_list 0x04, yellow_coin_seg3_dl_03007850
         geo_display_list 0x04, yellow_coin_seg3_dl_03007850
         geo_display_list 0x04, yellow_coin_seg3_dl_03007878
         geo_display_list 0x04, yellow_coin_seg3_dl_03007878
      geo_close_node
   geo_close_node
   geo_end

glabel blue_coin_geo # 0x16000200
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 80
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, blue_coin_seg3_dl_030078A0
         geo_display_list 0x04, blue_coin_seg3_dl_030078A0
         geo_display_list 0x04, blue_coin_seg3_dl_030078C8
         geo_display_list 0x04, blue_coin_seg3_dl_030078C8
         geo_display_list 0x04, blue_coin_seg3_dl_030078F0
         geo_display_list 0x04, blue_coin_seg3_dl_030078F0
         geo_display_list 0x04, blue_coin_seg3_dl_03007918
         geo_display_list 0x04, blue_coin_seg3_dl_03007918
      geo_close_node
   geo_close_node
   geo_end

glabel blue_coin_no_shadow_geo # 0x16000264
   geo_node_start
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, blue_coin_seg3_dl_030078A0
         geo_display_list 0x04, blue_coin_seg3_dl_030078A0
         geo_display_list 0x04, blue_coin_seg3_dl_030078C8
         geo_display_list 0x04, blue_coin_seg3_dl_030078C8
         geo_display_list 0x04, blue_coin_seg3_dl_030078F0
         geo_display_list 0x04, blue_coin_seg3_dl_030078F0
         geo_display_list 0x04, blue_coin_seg3_dl_03007918
         geo_display_list 0x04, blue_coin_seg3_dl_03007918
      geo_close_node
   geo_close_node
   geo_end

glabel red_coin_geo # 0x160002C4
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 80
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, red_coin_seg3_dl_03007940
         geo_display_list 0x04, red_coin_seg3_dl_03007940
         geo_display_list 0x04, red_coin_seg3_dl_03007968
         geo_display_list 0x04, red_coin_seg3_dl_03007968
         geo_display_list 0x04, red_coin_seg3_dl_03007990
         geo_display_list 0x04, red_coin_seg3_dl_03007990
         geo_display_list 0x04, red_coin_seg3_dl_030079B8
         geo_display_list 0x04, red_coin_seg3_dl_030079B8
      geo_close_node
   geo_close_node
   geo_end

glabel red_coin_no_shadow_geo # 0x16000328
   geo_node_start
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, red_coin_seg3_dl_03007940
         geo_display_list 0x04, red_coin_seg3_dl_03007940
         geo_display_list 0x04, red_coin_seg3_dl_03007968
         geo_display_list 0x04, red_coin_seg3_dl_03007968
         geo_display_list 0x04, red_coin_seg3_dl_03007990
         geo_display_list 0x04, red_coin_seg3_dl_03007990
         geo_display_list 0x04, red_coin_seg3_dl_030079B8
         geo_display_list 0x04, red_coin_seg3_dl_030079B8
      geo_close_node
   geo_close_node
   geo_end

glabel warp_pipe_geo # 0x16000388
   geo_start_distance 350
   geo_open_node
      geo_display_list 0x01, warp_pipe_seg3_dl_03008F98
      geo_display_list 0x01, warp_pipe_seg3_dl_03009A50
   geo_close_node
   geo_end

glabel castle_door_geo # 0x160003A8
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03014100
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel cabin_door_geo # 0x1600043C
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, cabin_door_seg3_dl_03013EA8
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, cabin_door_seg3_dl_03014128
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel wooden_door_geo # 0x160004D0
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, wooden_door_seg3_dl_03014A80
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, wooden_door_seg3_dl_03014F98
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel wooden_door2_geo # 0x16000564
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, wooden_door2_seg3_dl_03014B30
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, wooden_door2_seg3_dl_03015008
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel metal_door_geo # 0x160005F8
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, metal_door_seg3_dl_03014BE0
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, metal_door_seg3_dl_03015078
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel hazy_maze_door_geo # 0x1600068C
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, hazy_maze_door_seg3_dl_03014C90
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, hazy_maze_door_seg3_dl_030150E8
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel haunted_door_geo # 0x16000720
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 3500
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, haunted_door_seg3_dl_03014D40
               geo_close_node
               geo_render_range 3500, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, haunted_door_seg3_dl_03015158
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel castle_door_0_star_geo # 0x160007B4
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 1000
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x05, castle_door_seg3_dl_03014250
                  geo_close_node
               geo_close_node
               geo_render_range 1000, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x06, castle_door_seg3_dl_03014280
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel castle_door_1_star_geo # 0x16000868
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 1000
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x05, castle_door_seg3_dl_030142B0
                  geo_close_node
               geo_close_node
               geo_render_range 1000, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x06, castle_door_seg3_dl_030142E0
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel castle_door_3_stars_geo # 0x1600091C
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 1000
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x05, castle_door_seg3_dl_03014310
                  geo_close_node
               geo_close_node
               geo_render_range 1000, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x06, castle_door_seg3_dl_03014340
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel locked_castle_door_geo # 0x160009D0
   geo_todo_11 0x00, 78, 0, 0
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -300, 0, 0
         geo_open_node
            geo_open_node
               geo_render_range -2048, 1000
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x01, castle_door_seg3_dl_03014540
                  geo_close_node
               geo_close_node
               geo_render_range 1000, 32767
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, castle_door_seg3_dl_03013E28
                  geo_open_node
                     geo_display_list 0x02, castle_door_seg3_dl_03014528
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_dl_translated 0x01, 0, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel bowser_key2_geo # 0x16000A84
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 300
   geo_open_node
      geo_scale 0x00, 65536
      geo_open_node
         geo_display_list 0x01, bowser_key_seg3_dl_030161F8
      geo_close_node
   geo_close_node
   geo_end

glabel bowser_key_geo # 0x16000AB0
   geo_scale 0x00, 16384
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_asm 0, Geo18_802BA2B0
            geo_scale 0x00, 65536
            geo_open_node
               geo_display_list 0x01, bowser_key_seg3_dl_030161F8
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel red_flame_shadow_geo # 0x16000B10
   geo_shadow SHADOW_CIRCLE_UNK1, 0x50, 20
   geo_open_node
      geo_branch_and_link red_flame_geo
   geo_close_node
   geo_end

glabel red_flame_geo # 0x16000B2C
   geo_node_start
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x05, red_flame_seg3_dl_0301B3B0
         geo_display_list 0x05, red_flame_seg3_dl_0301B3C8
         geo_display_list 0x05, red_flame_seg3_dl_0301B3E0
         geo_display_list 0x05, red_flame_seg3_dl_0301B3F8
         geo_display_list 0x05, red_flame_seg3_dl_0301B410
         geo_display_list 0x05, red_flame_seg3_dl_0301B428
         geo_display_list 0x05, red_flame_seg3_dl_0301B440
         geo_display_list 0x05, red_flame_seg3_dl_0301B458
      geo_close_node
   geo_close_node
   geo_end

glabel blue_flame_geo # 0x16000B8C
   geo_node_start
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x05, blue_flame_seg3_dl_0301B500
         geo_display_list 0x05, blue_flame_seg3_dl_0301B518
         geo_display_list 0x05, blue_flame_seg3_dl_0301B530
         geo_display_list 0x05, blue_flame_seg3_dl_0301B548
         geo_display_list 0x05, blue_flame_seg3_dl_0301B560
         geo_display_list 0x05, blue_flame_seg3_dl_0301B578
         geo_display_list 0x05, blue_flame_seg3_dl_0301B590
         geo_display_list 0x05, blue_flame_seg3_dl_0301B5A8
      geo_close_node
   geo_close_node
   geo_end

glabel fish2_geo # 0x16000BEC
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 50
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, -16, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, fish_seg3_dl_0301BFB8
            geo_open_node
               geo_dl_translated 0x01, 97, 0, 0, fish_seg3_dl_0301C150
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel fish_geo # 0x16000C44
   geo_scale 0x00, 16384
   geo_open_node
      geo_dl_translated 0x01, -16, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0, fish_seg3_dl_0301BFB8
         geo_open_node
            geo_dl_translated 0x01, 97, 0, 0, fish_seg3_dl_0301C150
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel leaves_geo # 0x16000C8C
   geo_node_start
   geo_open_node
      geo_display_list 0x04, leaves_seg3_dl_0301CDE0
   geo_close_node
   geo_end

glabel marios_cap_geo # 0x16000CA4
   geo_shadow SHADOW_CIRCLE_UNK0, 0xB4, 75
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 10, Geo18_8029D924
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_display_list 0x01, marios_cap_seg3_dl_03022F48
            geo_display_list 0x05, marios_cap_seg3_dl_03022F48
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel marios_metal_cap_geo # 0x16000CF0
   geo_shadow SHADOW_CIRCLE_UNK0, 0xB4, 75
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 10, Geo18_8029D924
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_display_list 0x01, marios_metal_cap_seg3_dl_03022FF8
            geo_display_list 0x05, marios_metal_cap_seg3_dl_03022FF8
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel marios_wing_cap_geo # 0x16000D3C
   geo_shadow SHADOW_CIRCLE_UNK0, 0xB4, 75
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 10, Geo18_8029D924
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_node_start
            geo_open_node
               geo_display_list 0x01, marios_cap_seg3_dl_03022F48
               geo_display_list 0x04, marios_wing_cap_seg3_dl_030230B0
            geo_close_node
            geo_node_start
            geo_open_node
               geo_display_list 0x05, marios_wing_cap_seg3_dl_03023160
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel marios_winged_metal_cap_geo # 0x16000DA8
   geo_shadow SHADOW_CIRCLE_UNK0, 0xB4, 75
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 10, Geo18_8029D924
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_node_start
            geo_open_node
               geo_display_list 0x01, marios_metal_cap_seg3_dl_03022FF8
               geo_display_list 0x04, marios_winged_metal_cap_seg3_dl_03023108
            geo_close_node
            geo_node_start
            geo_open_node
               geo_display_list 0x05, marios_winged_metal_cap_seg3_dl_03023298
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel number_geo # 0x16000E14
   geo_node_start
   geo_open_node
      geo_switch_case 10, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, seg2_dl_0200F078
         geo_display_list 0x04, seg2_dl_0200F0A8
         geo_display_list 0x04, seg2_dl_0200F0D8
         geo_display_list 0x04, seg2_dl_0200F108
         geo_display_list 0x04, seg2_dl_0200F138
         geo_display_list 0x04, seg2_dl_0200F168
         geo_display_list 0x04, seg2_dl_0200F198
         geo_display_list 0x04, seg2_dl_0200F1C8
         geo_display_list 0x04, seg2_dl_0200F1F8
         geo_display_list 0x04, seg2_dl_0200F228
      geo_close_node
   geo_close_node
   geo_end

glabel mushroom_1up_geo # 0x16000E84
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 80
   geo_open_node
      geo_display_list 0x04, mushroom_1up_seg3_dl_0302A660
   geo_close_node
   geo_end

glabel star_geo # 0x16000EA0
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_display_list 0x01, star_seg3_dl_0302B870
         geo_display_list 0x04, star_seg3_dl_0302BA18
      geo_close_node
   geo_close_node
   geo_end

glabel dirt_animation_geo # 0x16000ED4
   geo_start_distance 300
   geo_open_node
      geo_switch_case 6, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x01, dirt_animation_seg3_dl_0302C378
         geo_display_list 0x01, dirt_animation_seg3_dl_0302C3B0
         geo_display_list 0x01, dirt_animation_seg3_dl_0302C3E8
         geo_display_list 0x04, dirt_animation_seg3_dl_0302C028
         geo_display_list 0x01, dirt_animation_seg3_dl_0302C420
         geo_display_list 0x01, dirt_animation_seg3_dl_0302C458
      geo_close_node
   geo_close_node
   geo_end

glabel cartoon_star_geo # 0x16000F24
   geo_start_distance 300
   geo_open_node
      geo_switch_case 5, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x01, cartoon_star_seg3_dl_0302C298
         geo_display_list 0x01, cartoon_star_seg3_dl_0302C2B8
         geo_display_list 0x01, cartoon_star_seg3_dl_0302C2D8
         geo_display_list 0x01, cartoon_star_seg3_dl_0302C2F8
         geo_display_list 0x01, cartoon_star_seg3_dl_0302C318
      geo_close_node
   geo_close_node
   geo_end

glabel transparent_star_geo # 0x16000F6C
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_display_list 0x05, transparent_star_seg3_dl_0302C620
      geo_close_node
   geo_close_node
   geo_end

glabel snowman_snow_ball_geo # 0x16000F98
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 50
   geo_open_node
      geo_display_list 0x04, snow_ball_seg3_dl_0302C8A0
   geo_close_node
   geo_end

glabel wooden_signpost_geo # 0x16000FB4
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 60
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_display_list 0x01, wooden_signpost_seg3_dl_0302DA48
         geo_display_list 0x01, wooden_signpost_seg3_dl_0302DD08
      geo_close_node
   geo_close_node
   geo_end

glabel bubbly_tree_geo # 0x16000FE8
   geo_start_distance 800
   geo_open_node
      geo_display_list 0x04, bubbly_tree_seg3_dl_0302FEE8
   geo_close_node
   geo_end

glabel spiky_tree_geo # 0x16001000
   geo_start_distance 800
   geo_open_node
      geo_display_list 0x04, spiky_tree_seg3_dl_03030FA0
   geo_close_node
   geo_end

glabel snow_tree_geo # 0x16001018
   geo_start_distance 800
   geo_open_node
      geo_display_list 0x04, snow_tree_seg3_dl_03032088
   geo_close_node
   geo_end

glabel spiky_tree1_geo # 0x16001030
   geo_start_distance 800
   geo_open_node
      geo_display_list 0x04, spiky_tree2_seg3_dl_03032170
   geo_close_node
   geo_end

glabel palm_tree_geo # 0x16001048
   geo_start_distance 800
   geo_open_node
      geo_display_list 0x04, palm_tree_seg3_dl_03033258
   geo_close_node
   geo_end
