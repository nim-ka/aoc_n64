.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel bubble_geo # 0x17000000
   geo_switch_case 1, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x04, bubble_seg4_dl_0401DD60
   geo_close_node
   geo_end

glabel purple_marble_geo # 0x1700001C
   geo_switch_case 1, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x04, purple_marble_seg4_dl_0401DDE0
   geo_close_node
   geo_end

glabel smoke_geo # 0x17000038
   geo_switch_case 7, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x05, smoke_seg4_dl_04021718
      geo_display_list 0x05, smoke_seg4_dl_04021730
      geo_display_list 0x05, smoke_seg4_dl_04021748
      geo_display_list 0x05, smoke_seg4_dl_04021760
      geo_display_list 0x05, smoke_seg4_dl_04021778
      geo_display_list 0x05, smoke_seg4_dl_04021790
      geo_display_list 0x05, smoke_seg4_dl_040217A8
   geo_close_node
   geo_end

glabel dirt2_geo # 0x17000084
   geo_node_start
   geo_open_node
      geo_display_list 0x05, dirt2_seg4_dl_04022070
   geo_close_node
   geo_end

glabel spot_on_ground_geo # 0x1700009C
   geo_switch_case 6, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x05, spot_on_ground_seg4_dl_040251F8
      geo_display_list 0x05, spot_on_ground_seg4_dl_04025210
      geo_display_list 0x05, spot_on_ground_seg4_dl_04025228
      geo_display_list 0x05, spot_on_ground_seg4_dl_04025240
      geo_display_list 0x05, spot_on_ground_seg4_dl_04025258
      geo_display_list 0x05, spot_on_ground_seg4_dl_04025270
   geo_close_node
   geo_end

glabel mario_TODO_geo_0000E0 # 0x170000E0
   geo_switch_case 6, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x05, mario_TODO_seg4_dl_04025288
      geo_display_list 0x05, mario_TODO_seg4_dl_040252A0
      geo_display_list 0x05, mario_TODO_seg4_dl_040252B8
      geo_display_list 0x05, mario_TODO_seg4_dl_040252D0
      geo_display_list 0x05, mario_TODO_seg4_dl_040252E8
      geo_display_list 0x05, mario_TODO_seg4_dl_04025300
   geo_close_node
   geo_end

glabel water_waves2_geo # 0x17000124
   geo_switch_case 6, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x05, water_waves_seg4_dl_040273F0
      geo_display_list 0x05, water_waves_seg4_dl_04027408
      geo_display_list 0x05, water_waves_seg4_dl_04027420
      geo_display_list 0x05, water_waves_seg4_dl_04027438
      geo_display_list 0x05, water_waves_seg4_dl_04027420
      geo_display_list 0x05, water_waves_seg4_dl_04027408
   geo_close_node
   geo_end

glabel water_waves_geo # 0x17000168
   geo_switch_case 8, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x05, water_waves_seg4_dl_040273F0
      geo_display_list 0x05, water_waves_seg4_dl_04027408
      geo_display_list 0x05, water_waves_seg4_dl_04027420
      geo_display_list 0x05, water_waves_seg4_dl_04027438
      geo_display_list 0x05, water_waves_seg4_dl_04027438
      geo_display_list 0x05, water_waves_seg4_dl_04027438
      geo_display_list 0x05, water_waves_seg4_dl_04027438
      geo_display_list 0x05, water_waves_seg4_dl_04027438
   geo_close_node
   geo_end

glabel sparkles_geo # 0x170001BC
   geo_switch_case 12, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x04, sparkles_seg4_dl_0402A570
      geo_display_list 0x04, sparkles_seg4_dl_0402A570
      geo_display_list 0x04, sparkles_seg4_dl_0402A558
      geo_display_list 0x04, sparkles_seg4_dl_0402A558
      geo_display_list 0x04, sparkles_seg4_dl_0402A540
      geo_display_list 0x04, sparkles_seg4_dl_0402A540
      geo_display_list 0x04, sparkles_seg4_dl_0402A528
      geo_display_list 0x04, sparkles_seg4_dl_0402A528
      geo_display_list 0x04, sparkles_seg4_dl_0402A510
      geo_display_list 0x04, sparkles_seg4_dl_0402A510
      geo_display_list 0x04, sparkles_seg4_dl_0402A4F8
      geo_display_list 0x04, sparkles_seg4_dl_0402A4F8
   geo_close_node
   geo_end

glabel water_splash_geo # 0x17000230
   geo_switch_case 8, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x04, water_splash_seg4_dl_04032640
      geo_display_list 0x04, water_splash_seg4_dl_04032658
      geo_display_list 0x04, water_splash_seg4_dl_04032670
      geo_display_list 0x04, water_splash_seg4_dl_04032688
      geo_display_list 0x04, water_splash_seg4_dl_040326A0
      geo_display_list 0x04, water_splash_seg4_dl_040326B8
      geo_display_list 0x04, water_splash_seg4_dl_040326D0
      geo_display_list 0x04, water_splash_seg4_dl_040326E8
   geo_close_node
   geo_end

glabel sparkles_animation_geo # 0x17000284
   geo_switch_case 9, GeoSwitchCase8029DB48
   geo_open_node
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035300
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035318
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035330
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035348
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035360
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035348
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035330
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035318
      geo_display_list 0x05, sparkles_animation_seg4_dl_04035300
   geo_close_node
   geo_end

glabel mario_geo_0002E0 # 0x170002E0
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_040119A0
            geo_display_list 0x01, mario_seg4_dl_04011A90
            geo_display_list 0x01, mario_seg4_dl_04011B80
            geo_display_list 0x01, mario_seg4_dl_04011C70
            geo_display_list 0x01, mario_seg4_dl_04011D60
            geo_display_list 0x01, mario_seg4_dl_04011E50
            geo_display_list 0x01, mario_seg4_dl_04011F40
            geo_display_list 0x01, mario_seg4_dl_04012030
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_040139E8
            geo_display_list 0x01, mario_seg4_dl_04013AB8
            geo_display_list 0x01, mario_seg4_dl_04013B88
            geo_display_list 0x01, mario_seg4_dl_04013C58
            geo_display_list 0x01, mario_seg4_dl_04013D28
            geo_display_list 0x01, mario_seg4_dl_04013DF8
            geo_display_list 0x01, mario_seg4_dl_04013EC8
            geo_display_list 0x01, mario_seg4_dl_04013F98
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00041C # 0x1700041C
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_0400D8F0
         geo_close_node
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0400D8F0
   geo_close_node
   geo_return

glabel mario_geo_000494 # 0x17000494
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_0400E458
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00053C # 0x1700053C
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400CC98
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 68, 0, 0, mario_seg4_dl_04010370
            geo_open_node
               geo_dl_translated 0x01, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0002E0
               geo_close_node
               geo_dl_translated 0x01, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400D1D8
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_00041C
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400DDE8
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_000494
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400E7B0
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0, mario_seg4_dl_0400ECA0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400EFB8
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x01, mario_seg4_dl_0400F4E8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0006F8 # 0x170006F8
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04014DC0
         geo_close_node
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04014DC0
   geo_close_node
   geo_return

glabel mario_geo_000770 # 0x17000770
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_040154E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000818 # 0x17000818
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04014638
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 68, 0, 0, mario_seg4_dl_040168C8
            geo_open_node
               geo_dl_translated 0x01, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0002E0
               geo_close_node
               geo_dl_translated 0x01, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04014840
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_0006F8
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04014F40
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_branch 1, mario_geo_000770
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_040156B0
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0, mario_seg4_dl_04015B60
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04015D00
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x01, mario_seg4_dl_040160C8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0009D4 # 0x170009D4
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04018460
            geo_display_list 0x01, mario_seg4_dl_04018530
            geo_display_list 0x01, mario_seg4_dl_04018600
            geo_display_list 0x01, mario_seg4_dl_040186D0
            geo_display_list 0x01, mario_seg4_dl_040187A0
            geo_display_list 0x01, mario_seg4_dl_04018870
            geo_display_list 0x01, mario_seg4_dl_04018940
            geo_display_list 0x01, mario_seg4_dl_04018A10
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04018F90
            geo_display_list 0x01, mario_seg4_dl_04019040
            geo_display_list 0x01, mario_seg4_dl_040190F0
            geo_display_list 0x01, mario_seg4_dl_040191A0
            geo_display_list 0x01, mario_seg4_dl_04019250
            geo_display_list 0x01, mario_seg4_dl_04019300
            geo_display_list 0x01, mario_seg4_dl_040193B0
            geo_display_list 0x01, mario_seg4_dl_04019460
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000B10 # 0x17000B10
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04016E80
         geo_close_node
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04016E80
   geo_close_node
   geo_return

glabel mario_geo_000B88 # 0x17000B88
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_040171C0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000C30 # 0x17000C30
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04016AB8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 68, 0, 0, mario_seg4_dl_04017EA0
            geo_open_node
               geo_dl_translated 0x01, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0009D4
               geo_close_node
               geo_dl_translated 0x01, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04016C70
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_000B10
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04016FB0
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_000B88
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04017360
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0, mario_seg4_dl_040176A8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04017818
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x01, mario_seg4_dl_04017AD8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000DEC # 0x17000DEC
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_040119A0
            geo_display_list 0x05, mario_seg4_dl_04011A90
            geo_display_list 0x05, mario_seg4_dl_04011B80
            geo_display_list 0x05, mario_seg4_dl_04011C70
            geo_display_list 0x05, mario_seg4_dl_04011D60
            geo_display_list 0x05, mario_seg4_dl_04011E50
            geo_display_list 0x05, mario_seg4_dl_04011F40
            geo_display_list 0x05, mario_seg4_dl_04012030
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_040139E8
            geo_display_list 0x05, mario_seg4_dl_04013AB8
            geo_display_list 0x05, mario_seg4_dl_04013B88
            geo_display_list 0x05, mario_seg4_dl_04013C58
            geo_display_list 0x05, mario_seg4_dl_04013D28
            geo_display_list 0x05, mario_seg4_dl_04013DF8
            geo_display_list 0x05, mario_seg4_dl_04013EC8
            geo_display_list 0x05, mario_seg4_dl_04013F98
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000F28 # 0x17000F28
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0400D8F0
         geo_close_node
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0400D8F0
   geo_close_node
   geo_return

glabel mario_geo_000FA0 # 0x17000FA0
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0400E458
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001048 # 0x17001048
   geo_dl_translated 0x05, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400CC98
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 68, 0, 0, mario_seg4_dl_04010370
            geo_open_node
               geo_dl_translated 0x05, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_000DEC
               geo_close_node
               geo_dl_translated 0x05, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400D1D8
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_000F28
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400DDE8
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_000FA0
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400E7B0
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0, mario_seg4_dl_0400ECA0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400EFB8
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x05, mario_seg4_dl_0400F4E8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001204 # 0x17001204
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04014DC0
         geo_close_node
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04014DC0
   geo_close_node
   geo_return

glabel mario_geo_00127C # 0x1700127C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_040154E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001324 # 0x17001324
   geo_dl_translated 0x05, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04014638
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 68, 0, 0, mario_seg4_dl_040168C8
            geo_open_node
               geo_dl_translated 0x05, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_000DEC
               geo_close_node
               geo_dl_translated 0x05, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04014840
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_001204
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04014F40
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_branch 1, mario_geo_00127C
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_040156B0
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0, mario_seg4_dl_04015B60
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04015D00
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x05, mario_seg4_dl_040160C8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0014E0 # 0x170014E0
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04018460
            geo_display_list 0x05, mario_seg4_dl_04018530
            geo_display_list 0x05, mario_seg4_dl_04018600
            geo_display_list 0x05, mario_seg4_dl_040186D0
            geo_display_list 0x05, mario_seg4_dl_040187A0
            geo_display_list 0x05, mario_seg4_dl_04018870
            geo_display_list 0x05, mario_seg4_dl_04018940
            geo_display_list 0x05, mario_seg4_dl_04018A10
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04018F90
            geo_display_list 0x05, mario_seg4_dl_04019040
            geo_display_list 0x05, mario_seg4_dl_040190F0
            geo_display_list 0x05, mario_seg4_dl_040191A0
            geo_display_list 0x05, mario_seg4_dl_04019250
            geo_display_list 0x05, mario_seg4_dl_04019300
            geo_display_list 0x05, mario_seg4_dl_040193B0
            geo_display_list 0x05, mario_seg4_dl_04019460
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00161C # 0x1700161C
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04016E80
         geo_close_node
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04016E80
   geo_close_node
   geo_return

glabel mario_geo_001694 # 0x17001694
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_040171C0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00173C # 0x1700173C
   geo_dl_translated 0x05, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04016AB8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 68, 0, 0, mario_seg4_dl_04017EA0
            geo_open_node
               geo_dl_translated 0x05, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0014E0
               geo_close_node
               geo_dl_translated 0x05, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04016C70
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_00161C
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04016FB0
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_001694
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04017360
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0, mario_seg4_dl_040176A8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04017818
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x05, mario_seg4_dl_04017AD8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0018F8 # 0x170018F8
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list 0x01, mario_seg4_dl_04012120
         geo_display_list 0x01, mario_seg4_dl_04014068
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0019A4 # 0x170019A4
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_0400D758
         geo_close_node
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0400D758
   geo_close_node
   geo_return

glabel mario_geo_001A1C # 0x17001A1C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_0400E478
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001AC4 # 0x17001AC4
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400CCC8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 68, 0, 0, mario_seg4_dl_040103F0
            geo_open_node
               geo_dl_translated 0x01, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0018F8
               geo_close_node
               geo_dl_translated 0x01, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400D090
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_0019A4
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400DCA0
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_001A1C
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400E7E0
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0, mario_seg4_dl_0400EBB8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_0400EEB0
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x01, mario_seg4_dl_0400F528
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001C80 # 0x17001C80
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04014C90
         geo_close_node
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04014C90
   geo_close_node
   geo_return

glabel mario_geo_001CF8 # 0x17001CF8
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04015500
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001DA0 # 0x17001DA0
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04014668
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 68, 0, 0, mario_seg4_dl_04016948
            geo_open_node
               geo_dl_translated 0x01, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0018F8
               geo_close_node
               geo_dl_translated 0x01, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_040147D0
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_001C80
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04014ED0
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_branch 1, mario_geo_001CF8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_040156E0
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0, mario_seg4_dl_04015A98
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04015C70
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x01, mario_seg4_dl_04016108
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001F5C # 0x17001F5C
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list 0x01, mario_seg4_dl_04018AE0
         geo_display_list 0x01, mario_seg4_dl_04019510
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x04, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002008 # 0x17002008
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_04016E20
         geo_close_node
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_04016E20
   geo_close_node
   geo_return

glabel mario_geo_002080 # 0x17002080
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x01, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, mario_seg4_dl_040171E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated 0x01, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002128 # 0x17002128
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04016AE8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 68, 0, 0, mario_seg4_dl_04017F20
            geo_open_node
               geo_dl_translated 0x01, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_001F5C
               geo_close_node
               geo_dl_translated 0x01, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04016C20
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_002008
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04016F60
                  geo_open_node
                     geo_dl_translated 0x01, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_002080
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_04017390
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0, mario_seg4_dl_04017638
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, mario_seg4_dl_040177A8
            geo_open_node
               geo_dl_translated 0x01, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated 0x01, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x01, mario_seg4_dl_04017B18
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0022E4 # 0x170022E4
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list 0x05, mario_seg4_dl_04012120
         geo_display_list 0x05, mario_seg4_dl_04014068
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002390 # 0x17002390
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0400D758
         geo_close_node
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0400D758
   geo_close_node
   geo_return

glabel mario_geo_002408 # 0x17002408
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0400E478
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0024B0 # 0x170024B0
   geo_dl_translated 0x05, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400CCC8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 68, 0, 0, mario_seg4_dl_040103F0
            geo_open_node
               geo_dl_translated 0x05, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0022E4
               geo_close_node
               geo_dl_translated 0x05, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400D090
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_002390
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400DCA0
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_002408
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400E7E0
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0, mario_seg4_dl_0400EBB8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_0400EEB0
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x05, mario_seg4_dl_0400F528
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00266C # 0x1700266C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04014C90
         geo_close_node
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04014C90
   geo_close_node
   geo_return

glabel mario_geo_0026E4 # 0x170026E4
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04015500
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00278C # 0x1700278C
   geo_dl_translated 0x05, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04014668
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 68, 0, 0, mario_seg4_dl_04016948
            geo_open_node
               geo_dl_translated 0x05, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0022E4
               geo_close_node
               geo_dl_translated 0x05, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_040147D0
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_00266C
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04014ED0
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_switch_case 0, GeoSwitchCase802774F4
                        geo_open_node
                           geo_branch 1, mario_geo_0026E4
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_040156E0
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0, mario_seg4_dl_04015A98
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04015C70
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x05, mario_seg4_dl_04016108
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002958 # 0x17002958
   geo_asm 0, Geo18_802773A4
   geo_todo_12 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list 0x05, mario_seg4_dl_04018AE0
         geo_display_list 0x05, mario_seg4_dl_04019510
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002A04 # 0x17002A04
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_04016E20
         geo_close_node
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_04016E20
   geo_close_node
   geo_return

glabel mario_geo_002A7C # 0x17002A7C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated 0x05, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x05, mario_seg4_dl_040171E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated 0x05, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list 0x04, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002B24 # 0x17002B24
   geo_dl_translated 0x05, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04016AE8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_todo_12 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 68, 0, 0, mario_seg4_dl_04017F20
            geo_open_node
               geo_dl_translated 0x05, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_002958
               geo_close_node
               geo_dl_translated 0x05, 67, -10, 79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04016C20
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_002A04
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 68, -10, -79
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04016F60
                  geo_open_node
                     geo_dl_translated 0x05, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_002A7C
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, 42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_04017390
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0, mario_seg4_dl_04017638
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 13, -8, -42
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0, mario_seg4_dl_040177A8
            geo_open_node
               geo_dl_translated 0x05, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated 0x05, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list 0x05, mario_seg4_dl_04017B18
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002CE0 # 0x17002CE0
   geo_switch_case 0, GeoSwitchCase802776D8
   geo_open_node
      geo_branch 1, mario_geo_00053C
      geo_branch 1, mario_geo_001048
      geo_branch 1, mario_geo_001AC4
      geo_branch 1, mario_geo_0024B0
   geo_close_node
   geo_return

glabel mario_geo_002D14 # 0x17002D14
   geo_switch_case 0, GeoSwitchCase802776D8
   geo_open_node
      geo_branch 1, mario_geo_000818
      geo_branch 1, mario_geo_001324
      geo_branch 1, mario_geo_001DA0
      geo_branch 1, mario_geo_00278C
   geo_close_node
   geo_return

glabel mario_geo_002D48 # 0x17002D48
   geo_switch_case 0, GeoSwitchCase802776D8
   geo_open_node
      geo_branch 1, mario_geo_000C30
      geo_branch 1, mario_geo_00173C
      geo_branch 1, mario_geo_002128
      geo_branch 1, mario_geo_002B24
   geo_close_node
   geo_return

glabel mario_geo_002D7C # 0x17002D7C
   geo_node_start
   geo_open_node
      geo_render_range -2048, 600
      geo_open_node
         geo_branch 1, mario_geo_002CE0
      geo_close_node
      geo_render_range 600, 1600
      geo_open_node
         geo_branch 1, mario_geo_002D14
      geo_close_node
      geo_render_range 1600, 32767
      geo_open_node
         geo_branch 1, mario_geo_002D48
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo # 0x17002DD4
   geo_shadow SHADOW_CIRCLE_PLAYER, 0xB4, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 0, Geo18_80277D6C
         geo_asm 0, Geo18_802770A4
         geo_switch_case 0, GeoSwitchCase80277150
         geo_open_node
            geo_branch 1, mario_geo_002CE0
            geo_branch 1, mario_geo_002D7C
         geo_close_node
         geo_asm 1, Geo18_80277D6C
      geo_close_node
   geo_close_node
   geo_end
