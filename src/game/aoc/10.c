#include <stdio.h>
#include <ultra64.h>

#include "game/fb.h"

#include "aoc.h"
#include "utils.h"

#define AOC_DAY10_CRT_WIDTH 40
#define AOC_DAY10_CRT_HEIGHT 6

#define AOC_DAY10_DISP_X_OFFSET 10
#define AOC_DAY10_DISP_Y_OFFSET 10

static s32 sCycle;
static s32 sX;

static s32 aoc_day10_cycle(s32 draw) {
	s32 res = 0;

	if (draw) {
		s32 crtX = sCycle % AOC_DAY10_CRT_WIDTH;
		s32 crtY = sCycle / AOC_DAY10_CRT_WIDTH;

		s32 pixel = crtX == sX - 1 || crtX == sX || crtX == sX + 1;

		fb_set_color(pixel ? FB_RGB(255, 255, 255) : FB_RGB(0, 0, 0));
		fb_draw_pixel(crtX + AOC_DAY10_DISP_X_OFFSET, crtY + AOC_DAY10_DISP_Y_OFFSET);
	}

	sCycle++;

	if (sCycle % AOC_DAY10_CRT_WIDTH == 20) {
		res = sCycle * sX;
	}

	return res;
}

const char *aoc_day10(const char *input, s32 isPart2) {
	s32 score = 0;

	sCycle = 0;
	sX = 1;

	while (*input) {
		char instr = *input;

		score += aoc_day10_cycle(isPart2);

		input += 5;

		if (instr != 'n') {
			s32 num = read_decimal_int(&input);
			input++;

			score += aoc_day10_cycle(isPart2);

			sX += num;
		}
	}

	if (!isPart2) {
		sprintf(gAocOutputBuf, "%d", score);
		return gAocOutputBuf;
	} else {
		return NULL;
	}
}
