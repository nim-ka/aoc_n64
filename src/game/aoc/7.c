#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

#define AOC_DAY7_MAX_DEPTH 32

static s32 *sSizes;
static s32 sNumSizes;

static s32 sStack[AOC_DAY7_MAX_DEPTH];
static s32 sDepth;

static void aoc_day7_cd_out(void) {
	if (sDepth) {
		s32 size = sStack[sDepth--];
		sSizes[sNumSizes++] = size;
		sStack[sDepth] += size;
	}
}

const char *aoc_day7(const char *input, s32 isPart2) {
	s32 res = 0;

	sSizes = (s32 *) gAocSharedMem;
	sNumSizes = 0;

	sStack[0] = 0;
	sDepth = 0;

	while (*input) {
		if (*input == '$') {
			input += 2;

			if (*input == 'c') {
				input += 3;

				if (*input == '.') {
					aoc_day7_cd_out();
				} else if (*input == '/') {
					while (sDepth) {
						aoc_day7_cd_out();
					}
				} else {
					sStack[++sDepth] = 0;
				}
			}
		} else {
			sStack[sDepth] += read_nonneg_decimal_int(&input);
		}

		while (*input && *input != '\n') {
			input++;
		}

		input++;
	}

	while (sDepth) {
		aoc_day7_cd_out();
	}

	if (!isPart2) {
		s32 i;

		for (i = 0; i < sNumSizes; i++) {
			if (sSizes[i] <= 100000) {
				res += sSizes[i];
			}
		}
	} else {
		s32 threshold = sStack[0] - 40000000;
		s32 i;

		res = 70000000;

		for (i = 0; i < sNumSizes; i++) {
			if (res > sSizes[i] && sSizes[i] >= threshold) {
				res = sSizes[i];
			}
		}
	}

	sprintf(gAocOutputBuf, "%d", res);
	return gAocOutputBuf;
}
