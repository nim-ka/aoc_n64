#include <ultra64.h>

#include "lib/src/hardware.h"

#include "config.h"
#include "buffers/framebuffers.h"
#include "game_init.h"
#include "fb.h"

const FBColor gFBBlack;

FBColor sFBWriteVal = 0xFFFF;

u32 sGlyphs[][10] = {
#include "glyphs/glyphs.inc.c"
};

u32 sByteGlyphs[][10] = {
#include "glyphs/byteglyphs.inc.c"
};

struct FBGlyph sFBGlyphTable[FB_GLYPH_TABLE_HEIGHT][FB_GLYPH_TABLE_WIDTH];

#define FB ((u16 *) ((u32) gFrameBuffer | 0xA0000000))

FBColor fb_get_color(void) {
	return sFBWriteVal;
}

void fb_set_color(FBColor color) {
	sFBWriteVal = color;
}

void fb_draw_pixel(u32 x, u32 y) {
	FB[x + y * SCREEN_WIDTH] = sFBWriteVal;
}

void fb_print_char(u32 x, u32 y, char ch) {
	u32 *glyph = NULL;

	if (ch == ' ') {
		glyph = sGlyphs[0];
	}

	if (ch >= '0' && ch <= '9') {
		glyph = sGlyphs[ch - '0' + 1];
	}

	if (ch >= 'A' && ch <= 'Z') {
		glyph = sGlyphs[ch - 'A' + 11];
	}

	if (ch == '/') {
		glyph = sGlyphs[37];
	}

	if (ch == '.') {
		glyph = sGlyphs[38];
	}

	if (ch == '+') {
		glyph = sGlyphs[39];
	}

	if (ch == 'u') {
		glyph = sGlyphs[40];
	}

	if (glyph != NULL) {
		sFBGlyphTable[y][x].state = FBGS_VALID;
		sFBGlyphTable[y][x].glyph = glyph;
	}
}

void fb_print_str(u32 x, u32 y, const char *str) {
	u32 pos = 0;

	for (; *str; str++, pos++) {
		fb_print_char(x + pos, y, *str);
	}
}

void fb_print_byte_str(u32 x, u32 y, u8 *str, u32 len) {
	u32 pos;

	for (pos = 0; pos < len; pos++) {
		sFBGlyphTable[y][x + pos].state = FBGS_VALID;
		sFBGlyphTable[y][x + pos].glyph = sByteGlyphs[str[pos]];
	}
}

void fb_render_glyph(u32 x, u32 y, u32 *glyph) {
	u32 i, j;

	FBColor color = fb_get_color();

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 10; j++) {
			fb_set_color((glyph[j] & (0x1 << ((7 - i) * 4))) ? color : FB_RGB(0, 0, 0));
			fb_draw_pixel(x + i + FB_GLYPH_X_OFFSET, y + j + FB_GLYPH_Y_OFFSET);
		}
	}

	fb_set_color(color);
}

void fb_init(void) {
	u32 x, y;

	fb_clear();

	for (x = 0; x < 320; x++) {
		for (y = 0; y < 240; y++) {
			FB[y * SCREEN_WIDTH + x] = 0x0001;
		}
	}
}

void fb_clear(void) {
	u32 y;

	for (y = 0; y < FB_GLYPH_TABLE_HEIGHT; y++) {
		fb_clear_row(y);
	}
}

void fb_clear_row(u32 y) {
	u32 x;

	for (x = 0; x < FB_GLYPH_TABLE_WIDTH; x++) {
		sFBGlyphTable[y][x].state = FBGS_INVALIDATED;
	}
}

void fb_display(void) {
	u32 x, y;

	for (x = 0; x < FB_GLYPH_TABLE_WIDTH; x++) {
		for (y = 0; y < FB_GLYPH_TABLE_HEIGHT; y++) {
			struct FBGlyph *fbGlyph = &sFBGlyphTable[y][x];

			if (fbGlyph->state == FBGS_VALID) {
				fb_render_glyph(x * 7, y * 9, fbGlyph->glyph);
				fbGlyph->state = FBGS_INVALIDATED;
			} else if (fbGlyph->state == FBGS_INVALIDATED) {
				fb_render_glyph(x * 7, y * 9, sGlyphs[0]);
				fbGlyph->state = FBGS_CLEAR;
			}
		}
	}
}

#undef FB

