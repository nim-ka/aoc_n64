#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

static s32 sKnots[10][2];

const char *aoc_day9(const char *input, s32 isPart2) {
	const s32 numKnots = isPart2 ? 10 : 2;
	s32 i;
	s32 *const tail = sKnots[numKnots - 1];

	s32 (*tailPoses)[2] = (s32 (*)[2]) gAocSharedMem;
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

			for (i = numTailPoses - 1; i >= 0; i--) {
				if (tailPoses[i][0] == tail[0] && tailPoses[i][1] == tail[1]) {
					break;
				}
			}

			if (i < 0) {
				tailPoses[numTailPoses][0] = tail[0];
				tailPoses[numTailPoses][1] = tail[1];
				numTailPoses++;
			}
		}

		input++;
	}

	sprintf(gAocOutputBuf, "%d", numTailPoses);
	return gAocOutputBuf;
}
