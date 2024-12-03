#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

#define AOC_DAY9_WIDTH 500
#define AOC_DAY9_HEIGHT 500

static s32 sKnots[10][2];

const char *aoc_day9(const char *input, s32 isPart2) {
	const s32 numKnots = isPart2 ? 10 : 2;
	s32 i;
	s32 *const tail = sKnots[numKnots - 1];

	s32 *tailPoses = (s32 *) gAocSharedMem;
	s32 numTailPoses = 0;

	for (i = 0; i < numKnots; i++) {
		sKnots[i][0] = 0;
		sKnots[i][1] = 0;
	}

	while (*input) {
		char headDirX;
		char headDirY;
		s32 num;

		switch (*input) {
			case 'U':
				headDirX = 0;
				headDirY = -1;
				break;

			case 'L':
				headDirX = -1;
				headDirY = 0;
				break;

			case 'R':
				headDirX = 1;
				headDirY = 0;
				break;

			default:
				headDirX = 0;
				headDirY = 1;
				break;
		}

		input += 2;

		num = read_nonneg_decimal_int(&input);

		for (; num > 0; num--) {
			s32 dirX = headDirX;
			s32 dirY = headDirY;

			s32 lastX;
			s32 lastY;

			s32 enc;

			for (i = 0; i < numKnots; i++) {
				s32 curX = sKnots[i][0];
				s32 curY = sKnots[i][1];

				if (i > 0) {
					s32 diffX = lastX - curX;
					s32 diffY = lastY - curY;

					if (-1 <= diffX && diffX <= 1 && -1 <= diffY && diffY <= 1) {
						break;
					}

					dirX = diffX < 0 ? -1 : diffX > 0 ? 1 : 0;
					dirY = diffY < 0 ? -1 : diffY > 0 ? 1 : 0;
				}

				lastX = sKnots[i][0] += dirX;
				lastY = sKnots[i][1] += dirY;
			}

			enc = (tail[0] + AOC_DAY9_WIDTH / 2) + (tail[1] + AOC_DAY9_HEIGHT / 2) * AOC_DAY9_WIDTH;

			if (!tailPoses[enc]) {
				numTailPoses++;
				tailPoses[enc] = 1;
			}
		}

		input++;
	}

	sprintf(gAocOutputBuf, "%d", numTailPoses);
	return gAocOutputBuf;
}
