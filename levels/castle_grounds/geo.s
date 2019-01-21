glabel castle_grounds_geo_000660 # 0x0E000660
   geo_start_distance 1000
   geo_open_node
      geo_scale 0x00, 24576
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, castle_grounds_seg7_dl_0700C768
            geo_open_node
               geo_dl_translated 0x01, 459, 0, 0, castle_grounds_seg7_dl_0700C728
               geo_open_node
                  geo_dl_translated 0x01, 460, 0, 0, castle_grounds_seg7_dl_0700C6E8
                  geo_open_node
                     geo_dl_translated 0x01, 345, 0, 0, castle_grounds_seg7_dl_0700C6A8
                     geo_open_node
                        geo_dl_translated 0x01, 287, 0, 0, castle_grounds_seg7_dl_0700C670
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel castle_grounds_geo_0006F4 # 0x0E0006F4
   geo_start_distance 2100
   geo_open_node
      geo_display_list 0x01, castle_grounds_seg7_dl_0700A290
   geo_close_node
   geo_end

glabel castle_grounds_geo_00070C # 0x0E00070C
   geo_start_distance 15000
   geo_open_node
      geo_display_list 0x04, castle_grounds_seg7_dl_0700BB80
   geo_close_node
   geo_end

glabel castle_grounds_geo_000724 # 0x0E000724
   geo_start_distance 15000
   geo_open_node
      geo_display_list 0x04, castle_grounds_seg7_dl_0700BC68
   geo_close_node
   geo_end

glabel castle_grounds_geo_00073C # 0x0E00073C
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 0, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 1500, 2500, 0, 1500, -12000, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, castle_grounds_seg7_dl_07006D70
               geo_display_list 0x01, castle_grounds_seg7_dl_070095F0
               geo_display_list 0x04, castle_grounds_seg7_dl_0700A860
               geo_display_list 0x06, castle_grounds_seg7_dl_0700B1D0
               geo_display_list 0x04, castle_grounds_seg7_dl_0700BA20
               geo_display_list 0x02, castle_grounds_seg7_dl_0700C430
               geo_display_list 0x01, castle_grounds_seg7_dl_0700C210
               geo_asm    0, Geo18_802D01E0
               geo_asm 5633, Geo18_802D1B70
               geo_asm 5633, Geo18_802D104C
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end
