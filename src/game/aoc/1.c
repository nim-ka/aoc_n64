#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"

const char *aoc_day1(const char *input, s32 isPart2) {
	s32 max1 = 0;
	s32 max2 = 0;
	s32 max3 = 0;

	while (*input) {
		s32 total = 0;

		while (*input && *input != '\n') {
			s32 curNum = 0;

			while (*input && *input != '\n') {
				curNum *= 10;
				curNum += *input - '0';
				input++;
			}

			total += curNum;
			curNum = 0;
			input++;
		}

		input++;

		if (max3 < total) {
			max3 = total;
		}

		if (max2 < max3) {
			s32 tmp = max2;
			max2 = max3;
			max3 = tmp;
		}

		if (max1 < max2) {
			s32 tmp = max1;
			max1 = max2;
			max2 = tmp;
		}
	}

	sprintf(gAocOutputBuf, "%d", isPart2 ? max1 + max2 + max3 : max1);
	return gAocOutputBuf;
}
