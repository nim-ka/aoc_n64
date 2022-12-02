#include <stdio.h>
#include <ultra64.h>

#include "aoc.h"

// ourPlay = instruction + opponentPlay + 2, mod 3

const char *aoc_day2(const char *input, s32 isPart2) {
	s32 totalScore = 0;

	while (*input) {
		s32 ourPlay;
		s32 score;

		s32 opponentPlay = *input - 'A';
		s32 instruction = *(input + 2) - 'X';

		if (!isPart2) {
			ourPlay = instruction;
			score = 3 * ((ourPlay - opponentPlay + 4) % 3);
		} else {
			ourPlay = (instruction + opponentPlay + 2) % 3;
			score = 3 * instruction;
		}

		totalScore += score + ourPlay + 1;
		input += 4;
	}

	sprintf(gAocOutputBuf, "%d", totalScore);
	return gAocOutputBuf;
}
