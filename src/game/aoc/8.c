#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

#define AOC_DAY8_WIDTH 99
#define AOC_DAY8_HEIGHT 99

#define AOC_DAY8_CELL(x, y) (&input[(x) + (y) * (AOC_DAY8_WIDTH + 1)])

const char *aoc_day8(const char *input, s32 isPart2) {
	s32 score = 0;
	s32 x;

	for (x = 0; x < AOC_DAY8_WIDTH; x++) {
		s32 y;

		for (y = 0; y < AOC_DAY8_HEIGHT; y++) {
			const char *cell = AOC_DAY8_CELL(x, y);

			const s32 dirChanges[4] = { -(AOC_DAY8_WIDTH + 1), AOC_DAY8_WIDTH + 1, -1, 1 };
			s32 cellScore = 1;
			s32 visFromEdge = FALSE;

			s32 i;

			for (i = 0; i < 4; i++) {
				const char *testCell = cell;
				s32 dist = 0;

				do {
					testCell += dirChanges[i];

					if (testCell < input || !*testCell || *testCell == '\n') {
						visFromEdge = TRUE;
						break;
					}

					dist++;

					if (*testCell >= *cell) {
						break;
					}
				} while (TRUE);

				cellScore *= dist;
			}

			if (!isPart2) {
				score += visFromEdge;
			} else {
				if (score < cellScore) {
					score = cellScore;
				}
			}
		}
	}

	sprintf(gAocOutputBuf, "%d", score);
	return gAocOutputBuf;
}
