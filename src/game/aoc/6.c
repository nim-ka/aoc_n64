#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

const char *aoc_day6(const char *input, s32 isPart2) {
	s32 markerLength = isPart2 ? 14 : 4;
	s32 duplicate = TRUE;
	s32 i;

	for (i = markerLength - 1; duplicate; i++) {
		s32 j;

		duplicate = FALSE;

		for (j = 0; j < markerLength; j++) {
			s32 k;

			for (k = j + 1; k < markerLength; k++) {
				if (input[i - j] == input[i - k]) {
					duplicate = TRUE;
					break;
				}
			}

			if (duplicate) {
				break;
			}
		}
	}

	sprintf(gAocOutputBuf, "%d", i);
	return gAocOutputBuf;
}
