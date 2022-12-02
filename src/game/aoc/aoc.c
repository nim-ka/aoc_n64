#include <stdio.h>
#include <ultra64.h>

#include "game/game_init.h"
#include "game/fb.h"

#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"
#include "7.h"
#include "8.h"
#include "9.h"
#include "10.h"
#include "11.h"
#include "12.h"
#include "13.h"
#include "14.h"
#include "15.h"
#include "16.h"
#include "17.h"
#include "18.h"
#include "19.h"
#include "20.h"
#include "21.h"
#include "22.h"
#include "23.h"
#include "24.h"
#include "25.h"

#include "aoc.h"

char gAocOutputBuf[256];

static const char *(*sAocFuncs[])(const char *input, s32 isPart2) = {
	NULL,
	aoc_day1,
	aoc_day2,
	aoc_day3,
	aoc_day4,
	aoc_day5,
	aoc_day6,
	aoc_day7,
	aoc_day8,
	aoc_day9,
	aoc_day10,
	aoc_day11,
	aoc_day12,
	aoc_day13,
	aoc_day14,
	aoc_day15,
	aoc_day16,
	aoc_day17,
	aoc_day18,
	aoc_day19,
	aoc_day20,
	aoc_day21,
	aoc_day22,
	aoc_day23,
	aoc_day24,
	aoc_day25
};

static const char *sAocInputs[] = {
	NULL,
	aoc_input_day1,
	aoc_input_day2,
	aoc_input_day3,
	aoc_input_day4,
	aoc_input_day5,
	aoc_input_day6,
	aoc_input_day7,
	aoc_input_day8,
	aoc_input_day9,
	aoc_input_day10,
	aoc_input_day11,
	aoc_input_day12,
	aoc_input_day13,
	aoc_input_day14,
	aoc_input_day15,
	aoc_input_day16,
	aoc_input_day17,
	aoc_input_day18,
	aoc_input_day19,
	aoc_input_day20,
	aoc_input_day21,
	aoc_input_day22,
	aoc_input_day23,
	aoc_input_day24,
	aoc_input_day25
};

static s32 sAocDay = 1;
static s32 sAocIsPart2 = FALSE;

static s32 sAocExecuted = FALSE;

static const char *sAocResult = NULL;
static char sAocTimeStr[256];
static char sAocMemStr[256];

void aoc_main(void) {
	if (gPlayer1Controller->buttonPressed & Z_TRIG) {
		sAocIsPart2 ^= 1;
		sAocExecuted = FALSE;
	}

	if (gPlayer1Controller->buttonPressed & L_TRIG) {
		sAocDay = (sAocDay + 23) % 25 + 1;
		sAocIsPart2 = FALSE;
		sAocExecuted = FALSE;
	}

	if (gPlayer1Controller->buttonPressed & R_TRIG) {
		sAocDay = (sAocDay % 25) + 1;
		sAocIsPart2 = FALSE;
		sAocExecuted = FALSE;
	}

	if (!sAocExecuted) {
		const char *(*func)(const char *input, s32 isPart2) = sAocFuncs[sAocDay];
		const char *input = sAocInputs[sAocDay];

		OSTime start;
		OSTime end;

		start = osGetTime();
		sAocResult = func(input, sAocIsPart2);
		end = osGetTime();

		sAocExecuted = TRUE;

		sprintf(sAocTimeStr, "DAY %2d PART %d COMPLETED IN %.3fMS u",
			sAocDay,
			sAocIsPart2 ? 2 : 1,
			(s32)(end - start) / 46875.0f);

		sprintf(sAocMemStr, "INPUT LOCATED AT RAM %08X", (u32) input);
	}

	if (sAocResult != NULL) {
		fb_set_color(FB_RGB(255, 255, 255));
		fb_print_str(0, 0, sAocResult);
		fb_print_str(0, 24, sAocTimeStr);
		fb_print_str(0, 25, sAocMemStr);
	}
}
