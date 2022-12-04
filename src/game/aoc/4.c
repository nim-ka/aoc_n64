#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"

const char *aoc_day4(const char *input, s32 isPart2) {
	s32 count = 0;

	while (*input) {
		s32 start1;
		s32 end1;
		s32 start2;
		s32 end2;

		start1 = read_nonneg_decimal_int(&input);
		input++;
		end1 = read_nonneg_decimal_int(&input);
		input++;
		start2 = read_nonneg_decimal_int(&input);
		input++;
		end2 = read_nonneg_decimal_int(&input);
		input++;

		count += (start2 <= start1 && (isPart2 ? start1 : end1) <= end2) ||
			(start1 <= start2 && (isPart2 ? start2 : end2) <= end1);
	}

	sprintf(gAocOutputBuf, "%d", count);
	return gAocOutputBuf;
}
