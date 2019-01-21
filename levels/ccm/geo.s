glabel ccm_geo_0003D0 # 0x0E0003D0
   geo_start_distance 500
   geo_open_node
      geo_display_list 0x04, ccm_seg7_dl_07010F28
      geo_display_list 0x01, ccm_seg7_dl_070118B0
   geo_close_node
   geo_end

glabel ccm_geo_0003F0 # 0x0E0003F0
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 400
   geo_open_node
      geo_display_list 0x01, ccm_seg7_dl_07012BD8
   geo_close_node
   geo_end

glabel ccm_geo_00040C # 0x0E00040C
   geo_start_distance 300
   geo_open_node
      geo_display_list 0x01, ccm_seg7_dl_070136D0
      geo_display_list 0x04, ccm_seg7_dl_07013870
   geo_close_node
   geo_end

glabel ccm_geo_00042C # 0x0E00042C
   geo_start_distance 800
   geo_open_node
      geo_render_range -1000, 4000
      geo_open_node
         geo_display_list 0x01, ccm_seg7_dl_0700E708
         geo_display_list 0x04, ccm_seg7_dl_0700E970
      geo_close_node
   geo_close_node
   geo_end

glabel ccm_geo_00045C # 0x0E00045C
   geo_start_distance 900
   geo_open_node
      geo_render_range -1000, 7000
      geo_open_node
         geo_display_list 0x01, ccm_seg7_dl_0700F440
         geo_display_list 0x04, ccm_seg7_dl_0700F650
         geo_display_list 0x05, ccm_seg7_dl_0700F780
      geo_close_node
   geo_close_node
   geo_end

glabel ccm_geo_000494 # 0x0E000494
   geo_start_distance 400
   geo_open_node
      geo_render_range -500, 7000
      geo_open_node
         geo_display_list 0x01, ccm_seg7_dl_0700FB00
      geo_close_node
   geo_close_node
   geo_end

glabel ccm_geo_0004BC # 0x0E0004BC
   geo_start_distance 800
   geo_open_node
      geo_render_range -1000, 7000
      geo_open_node
         geo_display_list 0x05, ccm_seg7_dl_0700FD08
      geo_close_node
   geo_close_node
   geo_end

glabel ccm_geo_0004E4 # 0x0E0004E4
   geo_start_distance 3500
   geo_open_node
      geo_render_range -3000, 6000
      geo_open_node
         geo_display_list 0x01, ccm_seg7_dl_07010660
         geo_display_list 0x04, ccm_seg7_dl_070109D0
         geo_display_list 0x05, ccm_seg7_dl_07010B50
      geo_close_node
   geo_close_node
   geo_end

glabel ccm_geo_00051C # 0x0E00051C
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 4, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, ccm_seg7_dl_0700B090
               geo_display_list 0x01, ccm_seg7_dl_0700B1D8
               geo_display_list 0x01, ccm_seg7_dl_0700C380
               geo_display_list 0x04, ccm_seg7_dl_0700D578
               geo_display_list 0x06, ccm_seg7_dl_0700DDF0
               geo_asm    0, Geo18_802D01E0
               geo_asm 1281, Geo18_802D104C
               geo_todo_17
               geo_asm    1, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end

glabel ccm_geo_0005E8 # 0x0E0005E8
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
            geo_todo_0F 9, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, ccm_seg7_dl_0701CE30
               geo_display_list 0x01, ccm_seg7_dl_0701E558
               geo_display_list 0x02, ccm_seg7_dl_0701E6B0
               geo_display_list 0x04, ccm_seg7_dl_0701FC78
               geo_display_list 0x04, ccm_seg7_dl_0701FD78
               geo_display_list 0x05, ccm_seg7_dl_0701FE60
               geo_display_list 0x05, ccm_seg7_dl_070207F0
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
