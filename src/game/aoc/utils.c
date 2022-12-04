#include <ultra64.h>

#include "aoc.h"

s32 read_nonneg_decimal_int(char **input) {
	s32 num = 0;

	while ('0' <= **input && **input <= '9') {
		num *= 10;
		num += *((*input)++) - '0';
	}

	return num;
}
