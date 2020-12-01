#include <ultra64.h>

#include "lib/src/hardware.h"

#include "config.h"
#include "buffers/framebuffers.h"
#include "game_init.h"

u32 sGlyphs[][10] = {
#include "glyphs/glyphs.inc.c"
};

u32 sByteGlyphs[][10] = {
#include "glyphs/byteglyphs.inc.c"
};

struct FBGlyph {
	enum {
		FBGS_VALID,
		FBGS_INVALIDATED,
		FBGS_CLEAR
	} state;
	u32 *glyph;
};

#define GLYPH_TABLE_WIDTH 45
#define GLYPH_TABLE_HEIGHT 26

struct FBGlyph sFBGlyphTable[GLYPH_TABLE_HEIGHT][GLYPH_TABLE_WIDTH];

void fb_print_char(int x, int y, char ch) {
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

	if (ch == 'u') {
		glyph = sGlyphs[39];
	}

	if (glyph) {
		sFBGlyphTable[y][x].state = FBGS_VALID;
		sFBGlyphTable[y][x].glyph = glyph;
	}
}

void fb_print_str(int x, int y, const char *str) {
	int pos = 0;

	for (; *str; str++, pos++) {
		fb_print_char(x + pos, y, *str);
	}
}

void fb_print_byte_str(int x, int y, u8 *str, int len) {
	int pos;

	for (pos = 0; pos < len; pos++) {
		sFBGlyphTable[y][x + pos].state = FBGS_VALID;
		sFBGlyphTable[y][x + pos].glyph = sByteGlyphs[str[pos]];
	}
}

#define FB ((u16 *) ((u32) gFrameBuffer | 0xA0000000))

void fb_render_glyph(int x, int y, u32 *glyph) {
	int i, j;

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 10; j++) {
			u16 pixel = (glyph[j] & (0x1 << ((7 - i) * 4))) ? 0xFFFF : 0x0001;

			FB[(x + i - 1) + (y + j - 1) * SCREEN_WIDTH] = pixel;
		}
	}
}

void fb_init(void) {
	u32 x, y;

	for (x = 0; x < GLYPH_TABLE_WIDTH; x++) {
		for (y = 0; y < GLYPH_TABLE_HEIGHT; y++) {
			sFBGlyphTable[y][x].state = FBGS_CLEAR;
		}
	}

	for (x = 0; x < 320; x++) {
		for (y = 0; y < 240; y++) {
			gFrameBuffer[y * SCREEN_WIDTH + x] = 0x0001;
		}
	}
}

void fb_display(void) {
	u32 x, y;

	for (x = 0; x < GLYPH_TABLE_WIDTH; x++) {
		for (y = 0; y < GLYPH_TABLE_HEIGHT; y++) {
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

