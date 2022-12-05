#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

#define AOC_DAY5_NUM_STACKS 9
#define AOC_DAY5_NUM_CRATES_PER_STACK 8
#define AOC_DAY5_MAX_CRATES (AOC_DAY5_NUM_STACKS * AOC_DAY5_NUM_CRATES_PER_STACK + 1)

const char *aoc_day5(const char *input, s32 isPart2) {
	// char stacks[AOC_DAY5_NUM_STACKS][AOC_DAY5_MAX_CRATES]
	char (*stacks)[AOC_DAY5_MAX_CRATES] = (char (*)[AOC_DAY5_MAX_CRATES]) gAocSharedMem;
	s32 i;

	input++;

	for (i = AOC_DAY5_NUM_CRATES_PER_STACK - 1; i >= 0; i--) {
		s32 j;

		for (j = 0; j < AOC_DAY5_NUM_STACKS; j++) {
			char ch = *input;
			stacks[j][i] = ch == ' ' ? '\0' : ch;
			input += 4;
		}
	}

	while (*input != 'm') {
		input++;
	}

	while (*input) {
		s32 amount;
		char *src;
		char *srcEnd;
		char *dest;
		char *destEnd;

		input += 5;
		amount = read_nonneg_decimal_int(&input);
		input += 6;
		src = stacks[read_nonneg_decimal_int(&input) - 1];
		input += 4;
		dest = stacks[read_nonneg_decimal_int(&input) - 1];
		input++;

		srcEnd = src;

		while (*srcEnd) {
			srcEnd++;
		}

		destEnd = dest;

		while (*destEnd) {
			destEnd++;
		}

		if (!isPart2) {
			for (; amount > 0; amount--) {
				*(destEnd++) = *(--srcEnd);
				*srcEnd = '\0';
			}
		} else {
			srcEnd -= amount;

			for (; amount > 0; amount--) {
				*(destEnd++) = *(srcEnd++);
				*(srcEnd - 1) = '\0';
			}
		}
	}

	for (i = 0; i < AOC_DAY5_NUM_STACKS; i++) {
		char *end = stacks[i];

		while (*end) {
			end++;
		}

		gAocOutputBuf[i] = *(end - 1);
	}

	gAocOutputBuf[i] = '\0';
	return gAocOutputBuf;
}
