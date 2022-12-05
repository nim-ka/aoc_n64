#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"
#include "utils.h"

const char *aoc_day3(const char *input, s32 isPart2) {
	s32 total = 0;

	while (*input) {
		char *str1 = (char *) gAocSharedMem;
		s32 str1Size = 0;

		char *str2 = NULL;
		s32 str2Size = 0;

		char *str3 = NULL;
		s32 str3Size = 0;

		char *ptr = str1;

		s32 priority = 0;
		char *i;
		char *j;

		while (*input && *input != '\n') {
			*(ptr++) = *(input++);

			if (str3) {
				str3Size++;
			} else if (str2) {
				str2Size++;
			} else {
				str1Size++;
			}

			if (isPart2 && !(*input && *input != '\n')) {
				if (!str2) {
					str2 = ptr;
					input++;
				} else if (!str3) {
					str3 = ptr;
					input++;
				}
			}
		}

		if (!isPart2) {
			str1Size /= 2;
			str2 = str1 + str1Size;
			str2Size = str1Size;
		}

		for (i = str1; i < str1 + str1Size; i++) {
			s32 found = FALSE;

			for (j = str2; j < str2 + str2Size; j++) {
				if (*i == *j) {
					found = TRUE;
					break;
				}
			}

			if (found && str3) {
				found = FALSE;

				for (j = str3; j < str3 + str3Size; j++) {
					if (*i == *j) {
						found = TRUE;
						break;
					}
				}
			}

			if (!found) {
				continue;
			}

			priority = *i >= 'a' ?
				*i - 'a' + 1 :
				*i - 'A' + 27;

			break;
		}

		total += priority;

		input++;
	}

	sprintf(gAocOutputBuf, "%d", total);
	return gAocOutputBuf;
}
