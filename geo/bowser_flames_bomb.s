.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel bowser_flames_geo # 0x0D000000
   geo_node_start
   geo_open_node
      geo_switch_case 14, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C108
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C1A8
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C248
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C2E8
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C388
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C428
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C4C8
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C568
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C608
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C6A8
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C748
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C7E8
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C888
         geo_display_list 0x05, bowser_flames_seg6_dl_0601C928
      geo_close_node
   geo_close_node
   geo_end

glabel invisible_bowser_accessory_geo # 0x0D000090
   geo_start_distance 10000
   geo_open_node
      geo_asm 20, Geo18_8029D924
      geo_display_list 0x06, invisible_bowser_accessory_seg6_dl_0601EAC0
   geo_close_node
   geo_end

glabel bowser_1_yellow_sphere_geo # 0x0D0000B0
   geo_node_start
   geo_open_node
      geo_billboard
      geo_open_node
         geo_display_list 0x04, bowser_1_yellow_sphere_seg6_dl_0601F3C0
      geo_close_node
   geo_close_node
   geo_end

glabel bowser_geo_0000D8 # 0x0D0000D8
   geo_shadow SHADOW_CIRCLE_UNK0, 0x9B, 400
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06040210
      geo_open_node
         geo_dl_translated 0x01, -89, -2, -18
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 69, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 85, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603D200
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603E6B8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 0, -32, -112
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06043698
               geo_asm 0, Geo18_802B798C
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 118, 67, 105
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 65, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 49, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603B208
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_060399D8
               geo_close_node
               geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_060392E0
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 0, 136, 130
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 61, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, -13, 258, 0, bowser_seg6_dl_060431F0
               geo_close_node
               geo_switch_case 9, GeoSwitchCase802B7C64
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06042348
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_060423A0
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_060423F8
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06042450
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_060424A8
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06042500
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06042558
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_060425B0
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_06042608
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, -118, 67, 105
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 65, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 49, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603DFB0
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603C6D0
               geo_close_node
               geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603BFC8
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 89, -2, -18
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 69, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 85, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603A4E8
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, bowser_seg6_dl_0603B8D0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
         geo_dl_translated 0x01, 0, 0, 0
      geo_close_node
   geo_close_node
   geo_return

glabel bowser_geo_000424 # 0x0D000424
   geo_shadow SHADOW_CIRCLE_UNK0, 0x9B, 400
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06040210
      geo_open_node
         geo_dl_translated 0x05, -89, -2, -18
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 69, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 85, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603D200
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603E6B8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 0, -32, -112
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06043698
               geo_asm 0, Geo18_802B798C
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 118, 67, 105
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 65, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 49, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603B208
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060399D8
               geo_close_node
               geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060392E0
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 0, 136, 130
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 61, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, -13, 258, 0, bowser_seg6_dl_060431F0
               geo_close_node
               geo_switch_case 9, GeoSwitchCase802B7C64
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042348
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060423A0
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060423F8
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042450
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060424A8
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042500
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042558
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060425B0
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042608
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, -118, 67, 105
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 65, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 49, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603DFB0
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603C6D0
               geo_close_node
               geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603BFC8
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 89, -2, -18
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 69, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 85, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603A4E8
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603B8D0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
      geo_close_node
   geo_close_node
   geo_return

glabel bowser_geo_000770 # 0x0D000770
   geo_node_start
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06040210
      geo_open_node
         geo_dl_translated 0x05, -89, -2, -18
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 69, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 85, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603D200
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603E6B8
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 0, -32, -112
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06043698
               geo_asm 0, Geo18_802B798C
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 118, 67, 105
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 65, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 49, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603B208
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060399D8
               geo_close_node
               geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060392E0
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 0, 136, 130
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 61, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, -13, 258, 0, bowser_seg6_dl_060431F0
               geo_close_node
               geo_switch_case 9, GeoSwitchCase802B7C64
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042348
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060423A0
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060423F8
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042450
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060424A8
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042500
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042558
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_060425B0
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_06042608
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, -118, 67, 105
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 65, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 49, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603DFB0
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603C6D0
               geo_close_node
               geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603BFC8
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 89, -2, -18
         geo_open_node
            geo_dl_translated 0x05, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 69, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 85, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603A4E8
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, bowser_seg6_dl_0603B8D0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
         geo_dl_translated 0x05, 0, 0, 0
      geo_close_node
   geo_close_node
   geo_return

.ifdef VERSION_US
glabel bowser_shadow_geo # 0x0D000AB8
   geo_shadow 0x00, 0x9B, 400
   geo_return
.endif

glabel bowser_geo # 0x0D000AB8 / 0AC4
   geo_node_start
   geo_open_node
      geo_asm 0, Geo18_8029D924
.ifdef VERSION_JP
      geo_switch_case 2, GeoSwitchCase8029DB48
.endif
.ifdef VERSION_US
      geo_switch_case 3, GeoSwitchCase8029DB48
.endif
      geo_open_node
         geo_node_start
         geo_open_node
            geo_asm 0, Geo18_802B7D44
            geo_branch 1, bowser_geo_0000D8
         geo_close_node

         geo_node_start
         geo_open_node
            geo_asm 0, Geo18_802B7D44
            geo_branch 1, bowser_geo_000424
         geo_close_node

.ifdef VERSION_US
         geo_node_start
         geo_open_node
            geo_asm 0, Geo18_802B7D44
            geo_branch 1, bowser_shadow_geo
         geo_close_node
.endif
      geo_close_node

   geo_close_node
   geo_end

glabel bowser2_geo # 0x0D000B18 / 0B40
   geo_node_start
   geo_open_node
      geo_asm 0, Geo18_8029D924

.ifdef VERSION_JP
      geo_switch_case 2, GeoSwitchCase8029DB48
.endif
.ifdef VERSION_US
      geo_switch_case 3, GeoSwitchCase8029DB48
.endif
      geo_open_node

         geo_node_start
         geo_open_node
            geo_asm 0, Geo18_802B7D44
            geo_branch 1, bowser_geo_0000D8
         geo_close_node

         geo_node_start
         geo_open_node
            geo_asm 0, Geo18_802B7D44
            geo_branch 1, bowser_geo_000770
         geo_close_node

.ifdef VERSION_US
         geo_node_start
         geo_open_node
            geo_asm 0, Geo18_802B7D44
            geo_branch 1, bowser_shadow_geo
         geo_close_node
.endif
      geo_close_node

   geo_close_node
   geo_end

glabel bowser_bomb_geo # 0x0D000B78 / 0BBC
   geo_start_distance 1000
   geo_open_node
      geo_scale 0x00, 196608
      geo_open_node
         geo_display_list 0x01, bomb_seg6_dl_0605A9C0
         geo_billboard
         geo_open_node
            geo_display_list 0x04, bomb_seg6_dl_0605A830
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel bowser_clouds_geo # 0x0D000BB8 / 0BFC
   geo_node_start
   geo_open_node
      geo_asm 0, Geo18_8029D924
      geo_switch_case 5, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x05, bowser_clouds_seg6_dl_06062B38
         geo_display_list 0x05, bowser_clouds_seg6_dl_06062BD8
         geo_display_list 0x05, bowser_clouds_seg6_dl_06062C78
         geo_display_list 0x05, bowser_clouds_seg6_dl_06062D18
         geo_display_list 0x05, bowser_clouds_seg6_dl_06062BD8
      geo_close_node
   geo_close_node
   geo_end

.word 0x0
.word 0x0
