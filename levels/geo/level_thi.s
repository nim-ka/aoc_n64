.include "geo_commands.inc"

glabel thi_geo_0005B0 # 0x0E0005B0
   geo_start_distance 300
   geo_open_node
      geo_display_list 0x01, thi_seg7_dl_07007648
   geo_close_node
   geo_end

glabel thi_geo_0005C8 # 0x0E0005C8
   geo_start_distance 300
   geo_open_node
      geo_scale 0x00, 19660
      geo_open_node
         geo_display_list 0x01, thi_seg7_dl_07007648
      geo_close_node
   geo_close_node
   geo_end

glabel thi_geo_0005F0 # 0x0E0005F0
   geo_start_distance 1200
   geo_open_node
      geo_display_list 0x01, thi_seg7_dl_07007930
   geo_close_node
   geo_end

glabel thi_geo_000608 # 0x0E000608
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
            geo_todo_0F 1, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, thi_seg7_dl_07005260
               geo_display_list 0x01, thi_seg7_dl_07006968
               geo_display_list 0x04, thi_seg7_dl_07007008
               geo_display_list 0x05, thi_seg7_dl_070072E8
               geo_display_list 0x06, thi_seg7_dl_070073C0
               geo_asm    0, Geo18_802D01E0
               geo_asm 4865, Geo18_802D104C
               geo_todo_17
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end

glabel thi_geo_0006D4 # 0x0E0006D4
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
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_scale 0x00, 19660
               geo_open_node
                  geo_display_list 0x01, thi_seg7_dl_07005260
                  geo_display_list 0x01, thi_seg7_dl_07006968
                  geo_display_list 0x04, thi_seg7_dl_07007008
                  geo_display_list 0x05, thi_seg7_dl_070072E8
               geo_close_node
               geo_display_list 0x06, thi_seg7_dl_07007538
               geo_asm    0, Geo18_802D01E0
               geo_asm 4866, Geo18_802D104C
               geo_todo_17
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel thi_geo_00079C # 0x0E00079C
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
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x05, thi_seg7_dl_07007C20
               geo_display_list 0x01, thi_seg7_dl_07009670
               geo_display_list 0x01, thi_seg7_dl_07009D50
               geo_display_list 0x04, thi_seg7_dl_07009F58
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
