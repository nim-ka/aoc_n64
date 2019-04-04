glabel mario_geo_0002E0 # 0x170002E0
   geo_asm 0, Geo18_802773A4
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040119A0
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04011A90
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04011B80
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04011C70
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04011D60
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04011E50
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04011F40
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04012030
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040139E8
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013AB8
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013B88
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013C58
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013D28
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013DF8
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013EC8
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04013F98
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00041C # 0x1700041C
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_0400D8F0
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0400D8F0
   geo_close_node
   geo_return

glabel mario_geo_000494 # 0x17000494
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_0400E458
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00053C # 0x1700053C
   geo_dl_translated LAYER_OPAQUE, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400CC98
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 68, 0, 0, mario_seg4_dl_04010370
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0002E0
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400D1D8
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_00041C
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400DDE8
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_000494
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400E7B0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0, mario_seg4_dl_0400ECA0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400EFB8
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_OPAQUE, mario_seg4_dl_0400F4E8
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
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04014DC0
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04014DC0
   geo_close_node
   geo_return

glabel mario_geo_000770 # 0x17000770
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040154E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000818 # 0x17000818
   geo_dl_translated LAYER_OPAQUE, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04014638
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 68, 0, 0, mario_seg4_dl_040168C8
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0002E0
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04014840
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_0006F8
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04014F40
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_branch 1, mario_geo_000770
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_040156B0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0, mario_seg4_dl_04015B60
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04015D00
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_OPAQUE, mario_seg4_dl_040160C8
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018460
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018530
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018600
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040186D0
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040187A0
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018870
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018940
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018A10
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018F90
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04019040
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040190F0
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040191A0
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04019250
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04019300
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040193B0
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04019460
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CA00
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000B10 # 0x17000B10
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04016E80
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04016E80
   geo_close_node
   geo_return

glabel mario_geo_000B88 # 0x17000B88
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040171C0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000C30 # 0x17000C30
   geo_dl_translated LAYER_OPAQUE, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04016AB8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 68, 0, 0, mario_seg4_dl_04017EA0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0009D4
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04016C70
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_000B10
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04016FB0
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_000B88
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04017360
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0, mario_seg4_dl_040176A8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04017818
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_OPAQUE, mario_seg4_dl_04017AD8
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040119A0
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04011A90
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04011B80
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04011C70
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04011D60
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04011E50
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04011F40
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04012030
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040139E8
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013AB8
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013B88
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013C58
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013D28
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013DF8
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013EC8
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04013F98
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_000F28 # 0x17000F28
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0400D8F0
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0400D8F0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0400D8F0
   geo_close_node
   geo_return

glabel mario_geo_000FA0 # 0x17000FA0
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0400E458
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001048 # 0x17001048
   geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400CC98
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 68, 0, 0, mario_seg4_dl_04010370
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_000DEC
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400D1D8
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_000F28
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400DDE8
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_000FA0
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400E7B0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0, mario_seg4_dl_0400ECA0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400EFB8
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0400F4E8
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
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04014DC0
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04014DC0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04014DC0
   geo_close_node
   geo_return

glabel mario_geo_00127C # 0x1700127C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040154E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001324 # 0x17001324
   geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04014638
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 68, 0, 0, mario_seg4_dl_040168C8
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_000DEC
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04014840
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_001204
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04014F40
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_branch 1, mario_geo_00127C
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_040156B0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0, mario_seg4_dl_04015B60
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04015D00
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040160C8
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018460
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018530
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018600
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040186D0
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040187A0
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018870
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018940
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018A10
         geo_close_node
         geo_switch_case 0, GeoSwitchCase802771BC
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018F90
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04019040
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040190F0
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040191A0
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04019250
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04019300
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040193B0
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04019460
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CAB8
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00161C # 0x1700161C
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04016E80
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04019CA0
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04016E80
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04016E80
   geo_close_node
   geo_return

glabel mario_geo_001694 # 0x17001694
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040171C0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401A428
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401BF30
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B158
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B158
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B1D8
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00173C # 0x1700173C
   geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04016AB8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 68, 0, 0, mario_seg4_dl_04017EA0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0014E0
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04016C70
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_00161C
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04016FB0
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_001694
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04017360
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0, mario_seg4_dl_040176A8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04017818
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04017AD8
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list LAYER_OPAQUE, mario_seg4_dl_04012120
         geo_display_list LAYER_OPAQUE, mario_seg4_dl_04014068
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0019A4 # 0x170019A4
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_0400D758
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0400D758
   geo_close_node
   geo_return

glabel mario_geo_001A1C # 0x17001A1C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_0400E478
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001AC4 # 0x17001AC4
   geo_dl_translated LAYER_OPAQUE, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400CCC8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 68, 0, 0, mario_seg4_dl_040103F0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0018F8
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400D090
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_0019A4
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400DCA0
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_001A1C
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400E7E0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0, mario_seg4_dl_0400EBB8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_0400EEB0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_OPAQUE, mario_seg4_dl_0400F528
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
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04014C90
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04014C90
   geo_close_node
   geo_return

glabel mario_geo_001CF8 # 0x17001CF8
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04015500
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_001DA0 # 0x17001DA0
   geo_dl_translated LAYER_OPAQUE, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04014668
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 68, 0, 0, mario_seg4_dl_04016948
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0018F8
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_040147D0
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_001C80
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04014ED0
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04015050
                     geo_open_node
                        geo_branch 1, mario_geo_001CF8
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_040156E0
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0, mario_seg4_dl_04015A98
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04015C70
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_OPAQUE, mario_seg4_dl_04016108
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list LAYER_OPAQUE, mario_seg4_dl_04018AE0
         geo_display_list LAYER_OPAQUE, mario_seg4_dl_04019510
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_ALPHA, mario_seg4_dl_0401CB70
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002008 # 0x17002008
   geo_switch_case 1, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_04016E20
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_04016E20
   geo_close_node
   geo_return

glabel mario_geo_002080 # 0x17002080
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_OPAQUE, mario_seg4_dl_040171E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated LAYER_OPAQUE, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002128 # 0x17002128
   geo_dl_translated LAYER_OPAQUE, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04016AE8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 68, 0, 0, mario_seg4_dl_04017F20
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_001F5C
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04016C20
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_002008
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_OPAQUE, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04016F60
                  geo_open_node
                     geo_dl_translated LAYER_OPAQUE, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_002080
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_04017390
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0, mario_seg4_dl_04017638
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_OPAQUE, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_OPAQUE, 0, 0, 0, mario_seg4_dl_040177A8
            geo_open_node
               geo_dl_translated LAYER_OPAQUE, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated LAYER_OPAQUE, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_OPAQUE, mario_seg4_dl_04017B18
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04012120
         geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04014068
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002390 # 0x17002390
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0400D758
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0400D758
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0400D758
   geo_close_node
   geo_return

glabel mario_geo_002408 # 0x17002408
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0400E478
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_0024B0 # 0x170024B0
   geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400CCC8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 68, 0, 0, mario_seg4_dl_040103F0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0022E4
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400D090
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_0400D2F8
                     geo_open_node
                        geo_branch 1, mario_geo_002390
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400DCA0
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_0400DF08
                     geo_open_node
                        geo_branch 1, mario_geo_002408
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400E7E0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_0400E918
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0, mario_seg4_dl_0400EBB8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_0400EEB0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_0400F1D8
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0400F528
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
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04014C90
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04014C90
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04014C90
   geo_close_node
   geo_return

glabel mario_geo_0026E4 # 0x170026E4
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04015500
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_00278C # 0x1700278C
   geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04014668
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 68, 0, 0, mario_seg4_dl_04016948
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_0022E4
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_040147D0
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04014950
                     geo_open_node
                        geo_branch 1, mario_geo_00266C
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04014ED0
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04015050
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
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_040156E0
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_04015848
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0, mario_seg4_dl_04015A98
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04015C70
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_04015E10
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04016108
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
   geo_rotation_node 0x00, 0, 0, 0
   geo_open_node
      geo_switch_case 0, GeoSwitchCase80277740
      geo_open_node
         geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04018AE0
         geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04019510
      geo_close_node
      geo_translate_rotate 0, 142, -51, -126, 22, -40, -135
      geo_open_node
         geo_asm 0, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
      geo_translate_rotate 0, 142, -51, 126, -22, 40, -135
      geo_open_node
         geo_asm 1, Geo18_80277824
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_0401CC28
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002A04 # 0x17002A04
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 1, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04016E20
         geo_close_node
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04019A68
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04016E20
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_04016E20
   geo_close_node
   geo_return

glabel mario_geo_002A7C # 0x17002A7C
   geo_switch_case 0, GeoSwitchCase802774F4
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0
      geo_open_node
         geo_asm 0, Geo18_802775CC
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_040171E0
         geo_close_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401A448
      geo_open_node
         geo_todo_1C 0x00, 0, 0, 0, Geo1C_8027795C
      geo_close_node
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401BC80
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B230
      geo_dl_translated LAYER_TRANSPARENT, 60, 0, 0, mario_seg4_dl_0401B230
      geo_open_node
         geo_display_list LAYER_ALPHA, mario_seg4_dl_0401B278
      geo_close_node
   geo_close_node
   geo_return

glabel mario_geo_002B24 # 0x17002B24
   geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0
   geo_open_node
      geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04016AE8
      geo_open_node
         geo_asm 0, Geo18_802B1BB0
         geo_asm 0, Geo18_80277294
         geo_rotation_node 0x00, 0, 0, 0
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 68, 0, 0, mario_seg4_dl_04017F20
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 87, 0, 0
               geo_open_node
                  geo_branch 1, mario_geo_002958
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 67, -10, 79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04016C20
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04016D50
                     geo_open_node
                        geo_branch 1, mario_geo_002A04
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated LAYER_TRANSPARENT, 68, -10, -79
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04016F60
                  geo_open_node
                     geo_dl_translated LAYER_TRANSPARENT, 65, 0, 0, mario_seg4_dl_04017090
                     geo_open_node
                        geo_branch 1, mario_geo_002A7C
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, 42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_04017390
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_040174E8
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0, mario_seg4_dl_04017638
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated LAYER_TRANSPARENT, 13, -8, -42
         geo_open_node
            geo_dl_translated LAYER_TRANSPARENT, 0, 0, 0, mario_seg4_dl_040177A8
            geo_open_node
               geo_dl_translated LAYER_TRANSPARENT, 89, 0, 0, mario_seg4_dl_04017918
               geo_open_node
                  geo_dl_translated LAYER_TRANSPARENT, 67, 0, 0
                  geo_open_node
                     geo_asm 2, Geo18_802775CC
                     geo_scale 0x00, 65536
                     geo_open_node
                        geo_display_list LAYER_TRANSPARENT, mario_seg4_dl_04017B18
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
