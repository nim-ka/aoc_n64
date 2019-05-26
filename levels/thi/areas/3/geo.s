glabel thi_geo_00079C # 0x0E00079C
   geo_node_screen_area 10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2
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
               geo_display_list LAYER_TRANSPARENT, thi_seg7_dl_07007C20
               geo_display_list LAYER_OPAQUE, thi_seg7_dl_07009670
               geo_display_list LAYER_OPAQUE, thi_seg7_dl_07009D50
               geo_display_list LAYER_ALPHA, thi_seg7_dl_07009F58
               geo_render_obj
               geo_asm 0, geo_exec_level
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
