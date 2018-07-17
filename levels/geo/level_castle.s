.include "geo_commands.inc"

glabel castle_geo_000F00 # 0F00
   geo_start_distance 400
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0703BFA8
      geo_close_node
   geo_end

glabel castle_geo_000F18 # 0F18
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0703BCB8
      geo_close_node
   geo_end

glabel castle_geo_000F30 # 0F30
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm 0, Geo18_802D2360
      geo_close_node
   geo_return

glabel castle_geo_000F70 # 0F70
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0702E408
      geo_close_node
   geo_return

glabel castle_geo_000F88 # 0F88
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0702FD30
         geo_display_list 0x01, castle_seg7_dl_07023DB0
      geo_close_node
   geo_return

glabel castle_geo_000FA8 # 0FA8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07031588
         geo_display_list 0x04, castle_seg7_dl_07031720
         geo_display_list 0x04, castle_seg7_dl_07031830
      geo_close_node
   geo_return

glabel castle_geo_000FD0 # 0FD0
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07032FC0
         geo_display_list 0x04, castle_seg7_dl_07033158
         geo_asm   0, Geo18_802D5D0C
         geo_asm 256, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001000 # 1000
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07034D88
         geo_display_list 0x04, castle_seg7_dl_07035178
         geo_display_list 0x04, castle_seg7_dl_07035288
         geo_asm   0, Geo18_802D5D0C
         geo_asm 258, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001038 # 1038
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07036D88
         geo_display_list 0x01, castle_seg7_dl_07037988
         geo_display_list 0x01, castle_seg7_dl_07037BF8
         geo_display_list 0x05, castle_seg7_dl_07037DE8
         geo_display_list 0x05, castle_seg7_dl_07038240
         geo_display_list 0x04, castle_seg7_dl_07038350
         geo_asm   0, Geo18_802D5D0C
         geo_asm 259, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001088 # 1088
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0703A6C8
         geo_display_list 0x04, castle_seg7_dl_0703A808
         geo_display_list 0x01, castle_seg7_dl_070234C0
         geo_display_list 0x01, castle_seg7_dl_07023520
         geo_asm   0, Geo18_802D5D0C
         geo_asm 257, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_0010C8 # 10C8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm 0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_0703BA08
      geo_close_node
   geo_return

glabel castle_geo_001110 # 1110
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm 0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_0702E408
      geo_close_node
   geo_return

glabel castle_geo_001158 # 1158
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm 0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_0702FD30
         geo_display_list 0x01, castle_seg7_dl_07023DB0
      geo_close_node
   geo_return

glabel castle_geo_0011A8 # 11A8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm 0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_07031588
         geo_display_list 0x04, castle_seg7_dl_07031720
         geo_display_list 0x04, castle_seg7_dl_07031830
      geo_close_node
   geo_return

glabel castle_geo_001200 # 1200
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm   0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_07032FC0
         geo_display_list 0x04, castle_seg7_dl_07033158
         geo_asm   0, Geo18_802D5D0C
         geo_asm 256, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001260 # 1260
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm   0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_07034D88
         geo_display_list 0x04, castle_seg7_dl_07035178
         geo_display_list 0x04, castle_seg7_dl_07035288
         geo_asm   0, Geo18_802D5D0C
         geo_asm 258, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_0012C8 # 12C8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm   0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_07036D88
         geo_display_list 0x01, castle_seg7_dl_07037988
         geo_display_list 0x01, castle_seg7_dl_07037BF8
         geo_display_list 0x05, castle_seg7_dl_07037DE8
         geo_display_list 0x05, castle_seg7_dl_07038240
         geo_display_list 0x04, castle_seg7_dl_07038350
         geo_asm   0, Geo18_802D5D0C
         geo_asm 259, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001348 # 1348
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm   0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_0703A6C8
         geo_display_list 0x04, castle_seg7_dl_0703A808
         geo_display_list 0x01, castle_seg7_dl_070234C0
         geo_display_list 0x01, castle_seg7_dl_07023520
         geo_asm   0, Geo18_802D5D0C
         geo_asm 257, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_0013B8 # 13B8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07028FD0
         geo_display_list 0x04, castle_seg7_dl_07029578
         geo_display_list 0x01, castle_seg7_dl_0702A650
         geo_display_list 0x06, castle_seg7_dl_0702AA10
         geo_display_list 0x04, castle_seg7_dl_0702AB20
         geo_asm 0, Geo18_802D2360
         geo_display_list 0x01, castle_seg7_dl_0703BA08
      geo_close_node
   geo_return

glabel castle_geo_001400 # 1400
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 0x0001
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 64, 50, 7000, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 13, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_switch_case 17, GeoSwitchCaseBlinking
                  geo_open_node
                     geo_branch 1, castle_geo_000F30 # 0x0E000F30
                     geo_branch 1, castle_geo_000F70 # 0x0E000F70
                     geo_branch 1, castle_geo_000F88 # 0x0E000F88
                     geo_branch 1, castle_geo_000FA8 # 0x0E000FA8
                     geo_branch 1, castle_geo_000FD0 # 0x0E000FD0
                     geo_branch 1, castle_geo_001000 # 0x0E001000
                     geo_branch 1, castle_geo_001038 # 0x0E001038
                     geo_branch 1, castle_geo_001088 # 0x0E001088
                     geo_branch 1, castle_geo_0010C8 # 0x0E0010C8
                     geo_branch 1, castle_geo_001110 # 0x0E001110
                     geo_branch 1, castle_geo_001158 # 0x0E001158
                     geo_branch 1, castle_geo_0011A8 # 0x0E0011A8
                     geo_branch 1, castle_geo_001200 # 0x0E001200
                     geo_branch 1, castle_geo_001260 # 0x0E001260
                     geo_branch 1, castle_geo_0012C8 # 0x0E0012C8
                     geo_branch 1, castle_geo_001348 # 0x0E001348
                     geo_branch 1, castle_geo_0013B8 # 0x0E0013B8
                  geo_close_node
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel castle_geo_001518 # 1518
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_070512F8
      geo_close_node
   geo_end

glabel castle_geo_001530 # 1530
   geo_start_distance 300
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07058950
      geo_close_node
   geo_end

glabel castle_geo_001548 # 1548
   geo_start_distance 300
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07059190
      geo_close_node
   geo_end

glabel castle_geo_001560 # 1560
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0703E6F0
      geo_close_node
   geo_return

glabel castle_geo_001578 # 1578
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07043028
         geo_display_list 0x01, castle_seg7_dl_07043B48
         geo_display_list 0x04, castle_seg7_dl_07043CD8
         geo_asm   0, Geo18_802D5D0C
         geo_asm 264, Geo18_802D5B98
         geo_asm 266, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_0015B8 # 15B8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0704A0E8
         geo_display_list 0x05, castle_seg7_dl_0704A2E0
         geo_display_list 0x01, castle_seg7_dl_0704AA98
         geo_asm   0, Geo18_802D5D0C
         geo_asm 268, Geo18_802D5B98
         geo_asm   0, Geo18_80277B14
      geo_close_node
   geo_return

glabel castle_geo_0015F8 # 15F8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0704C7D8
         geo_asm   0, Geo18_802D5D0C
         geo_asm 265, Geo18_802D5B98
         geo_asm 269, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001628 # 1628
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07050938
         geo_display_list 0x04, castle_seg7_dl_07051678
         geo_display_list 0x05, castle_seg7_dl_070519C8
         geo_display_list 0x05, castle_seg7_dl_07051B60
         geo_asm   0, Geo18_802D5D0C
         geo_asm 267, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001668 # 1668
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_070558D0
         geo_display_list 0x01, castle_seg7_dl_070572A0
         geo_display_list 0x01, castle_seg7_dl_07057F00
      geo_close_node
   geo_return

glabel castle_geo_001690 # 1690
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0703E6F0
         geo_display_list 0x01, castle_seg7_dl_07043028
         geo_display_list 0x01, castle_seg7_dl_07043B48
         geo_display_list 0x04, castle_seg7_dl_07043CD8
         geo_asm   0, Geo18_802D5D0C
         geo_asm 264, Geo18_802D5B98
         geo_asm 266, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_0016D8 # 16D8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07043028
         geo_display_list 0x01, castle_seg7_dl_07043B48
         geo_display_list 0x04, castle_seg7_dl_07043CD8
         geo_display_list 0x01, castle_seg7_dl_0704A0E8
         geo_display_list 0x05, castle_seg7_dl_0704A2E0
         geo_display_list 0x01, castle_seg7_dl_0704AA98
         geo_asm   0, Geo18_802D5D0C
         geo_asm 264, Geo18_802D5B98
         geo_asm 266, Geo18_802D5B98
         geo_asm 268, Geo18_802D5B98
         geo_asm   0, Geo18_80277B14
      geo_close_node
   geo_return

glabel castle_geo_001740 # 1740
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07043028
         geo_display_list 0x01, castle_seg7_dl_07043B48
         geo_display_list 0x04, castle_seg7_dl_07043CD8
         geo_display_list 0x01, castle_seg7_dl_0704C7D8
         geo_asm   0, Geo18_802D5D0C
         geo_asm 264, Geo18_802D5B98
         geo_asm 265, Geo18_802D5B98
         geo_asm 266, Geo18_802D5B98
         geo_asm 269, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001798 # 1798
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07043028
         geo_display_list 0x01, castle_seg7_dl_07043B48
         geo_display_list 0x04, castle_seg7_dl_07043CD8
         geo_display_list 0x01, castle_seg7_dl_07050938
         geo_display_list 0x04, castle_seg7_dl_07051678
         geo_display_list 0x05, castle_seg7_dl_070519C8
         geo_display_list 0x05, castle_seg7_dl_07051B60
         geo_asm   0, Geo18_802D5D0C
         geo_asm 264, Geo18_802D5B98
         geo_asm 266, Geo18_802D5B98
         geo_asm 267, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001800 # 1800
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07050938
         geo_display_list 0x04, castle_seg7_dl_07051678
         geo_display_list 0x05, castle_seg7_dl_070519C8
         geo_display_list 0x05, castle_seg7_dl_07051B60
         geo_display_list 0x01, castle_seg7_dl_070558D0
         geo_display_list 0x01, castle_seg7_dl_070572A0
         geo_display_list 0x01, castle_seg7_dl_07057F00
         geo_asm   0, Geo18_802D5D0C
         geo_asm 267, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001858 # 1858
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 0x0001
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 64, 50, 8000, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 4, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_switch_case 11, GeoSwitchCaseBlinking
                  geo_open_node
                     geo_branch 1, castle_geo_001560 # 0x0E001560
                     geo_branch 1, castle_geo_001578 # 0x0E001578
                     geo_branch 1, castle_geo_0015B8 # 0x0E0015B8
                     geo_branch 1, castle_geo_0015F8 # 0x0E0015F8
                     geo_branch 1, castle_geo_001628 # 0x0E001628
                     geo_branch 1, castle_geo_001668 # 0x0E001668
                     geo_branch 1, castle_geo_001690 # 0x0E001690
                     geo_branch 1, castle_geo_0016D8 # 0x0E0016D8
                     geo_branch 1, castle_geo_001740 # 0x0E001740
                     geo_branch 1, castle_geo_001798 # 0x0E001798
                     geo_branch 1, castle_geo_001800 # 0x0E001800
                  geo_close_node
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel castle_geo_001940 # 1940
   geo_start_distance 550
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07068B10
      geo_close_node
   geo_end

glabel castle_geo_001958 # 1958
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0705E088
         geo_display_list 0x04, castle_seg7_dl_0705E2A0
         geo_display_list 0x05, castle_seg7_dl_0705E450
      geo_close_node
   geo_return

glabel castle_geo_001980 # 1980
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_070616E8
         geo_display_list 0x05, castle_seg7_dl_07061C20
         geo_asm    0, Geo18_802D5D0C
         geo_asm  260, Geo18_802D5B98
         geo_asm  261, Geo18_802D5B98
         geo_asm    0, Geo18_802D01E0
         geo_asm 1536, Geo18_802D104C
      geo_close_node
   geo_return

glabel castle_geo_0019C8 # 19C8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07064B78
         geo_display_list 0x04, castle_seg7_dl_07064D58
         geo_asm 0, Geo18_802D5D0C
         geo_asm 262, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_0019F8 # 19F8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07066CE0
         geo_display_list 0x05, castle_seg7_dl_07066E90
         geo_display_list 0x04, castle_seg7_dl_07066FA0
         geo_asm    0, Geo18_802D01E0
         geo_asm 1554, Geo18_802D104C
      geo_close_node
   geo_return

glabel castle_geo_001A30 # 1A30
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_07068850
         geo_asm   0, Geo18_802D5D0C
         geo_asm 263, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001A58 # 1A58
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0705E088
         geo_display_list 0x04, castle_seg7_dl_0705E2A0
         geo_display_list 0x05, castle_seg7_dl_0705E450
         geo_display_list 0x01, castle_seg7_dl_070616E8
         geo_display_list 0x05, castle_seg7_dl_07061C20
         geo_asm    0, Geo18_802D5D0C
         geo_asm  260, Geo18_802D5B98
         geo_asm  261, Geo18_802D5B98
         geo_asm    0, Geo18_802D01E0
         geo_asm 1536, Geo18_802D104C
      geo_close_node
   geo_return

glabel castle_geo_001AB8 # 1AB8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0705E088
         geo_display_list 0x04, castle_seg7_dl_0705E2A0
         geo_display_list 0x05, castle_seg7_dl_0705E450
         geo_display_list 0x01, castle_seg7_dl_07068850
         geo_asm   0, Geo18_802D5D0C
         geo_asm 263, Geo18_802D5B98
      geo_close_node
   geo_return

glabel castle_geo_001AF8 # 1AF8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_0705E088
         geo_display_list 0x04, castle_seg7_dl_0705E2A0
         geo_display_list 0x05, castle_seg7_dl_0705E450
         geo_display_list 0x01, castle_seg7_dl_07066CE0
         geo_display_list 0x05, castle_seg7_dl_07066E90
         geo_display_list 0x04, castle_seg7_dl_07066FA0
         geo_asm    0, Geo18_802D01E0
         geo_asm 1554, Geo18_802D104C
      geo_close_node
   geo_return

glabel castle_geo_001B48 # 1B48
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_070616E8
         geo_display_list 0x05, castle_seg7_dl_07061C20
         geo_display_list 0x01, castle_seg7_dl_07066CE0
         geo_display_list 0x05, castle_seg7_dl_07066E90
         geo_display_list 0x04, castle_seg7_dl_07066FA0
         geo_asm    0, Geo18_802D5D0C
         geo_asm  260, Geo18_802D5B98
         geo_asm  261, Geo18_802D5B98
         geo_asm    0, Geo18_802D01E0
         geo_asm 1536, Geo18_802D104C
         geo_asm 1554, Geo18_802D104C
      geo_close_node
   geo_return

glabel castle_geo_001BB0 # 1BB0
   geo_node_start
      geo_open_node
         geo_display_list 0x01, castle_seg7_dl_070616E8
         geo_display_list 0x05, castle_seg7_dl_07061C20
         geo_display_list 0x01, castle_seg7_dl_07064B78
         geo_display_list 0x04, castle_seg7_dl_07064D58
         geo_asm    0, Geo18_802D5D0C
         geo_asm  260, Geo18_802D5B98
         geo_asm  261, Geo18_802D5B98
         geo_asm  262, Geo18_802D5B98
         geo_asm    0, Geo18_802D01E0
         geo_asm 1536, Geo18_802D104C
      geo_close_node
   geo_return

glabel castle_geo_001C10 # 1C10
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 0x0001
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 64, 50, 6400, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 4, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_switch_case 10, GeoSwitchCaseBlinking
                  geo_open_node
                     geo_branch 1, castle_geo_001958 # 0x0E001958
                     geo_branch 1, castle_geo_001980 # 0x0E001980
                     geo_branch 1, castle_geo_0019C8 # 0x0E0019C8
                     geo_branch 1, castle_geo_0019F8 # 0x0E0019F8
                     geo_branch 1, castle_geo_001A30 # 0x0E001A30
                     geo_branch 1, castle_geo_001A58 # 0x0E001A58
                     geo_branch 1, castle_geo_001AB8 # 0x0E001AB8
                     geo_branch 1, castle_geo_001AF8 # 0x0E001AF8
                     geo_branch 1, castle_geo_001B48 # 0x0E001B48
                     geo_branch 1, castle_geo_001BB0 # 0x0E001BB0
                  geo_close_node
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end
