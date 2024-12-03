#ifndef _CUSTOM_H_
#define _CUSTOM_H_

typedef u16 FBColor;

struct FBGlyph {
	enum {
		FBGS_VALID,
		FBGS_INVALIDATED,
		FBGS_CLEAR
	} state;
	u32 *glyph;
};

#define FB_GLYPH_TABLE_WIDTH 45
#define FB_GLYPH_TABLE_HEIGHT 26

#define FB_GLYPH_X_OFFSET 3
#define FB_GLYPH_Y_OFFSET 2

#define FB_RGB(r, g, b) ((((r) / 8) << 11) | (((g) / 8) << 6) | (((b) / 8) << 1) | 0x0001)

FBColor fb_get_color(void);
void fb_set_color(FBColor color);

extern void fb_draw_pixel(u32 x, u32 y);
extern void fb_print_char(u32 x, u32 y, char ch);
extern void fb_print_str(u32 x, u32 y, const char *str);
extern void fb_print_byte_str(u32 x, u32 y, u8 *str, u32 len);

extern void fb_init(void);
extern void fb_invalidate(void);
extern void fb_invalidate_row(u32 y);
extern void fb_clear(void);
extern void fb_clear_row(u32 y);
extern void fb_display(void);

#endif
