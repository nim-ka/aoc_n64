#include <ultra64.h>
#include <string.h>

#include "game_init.h"
#include "fb.h"

#define ARRAY_LEN(arr) (sizeof((arr)) / sizeof((arr)[0]))

struct Test {
	char *name;
	u8 (*exec)(int *reg, u8 *msg, int *msglen);
	u8 completed;
	int reg;
	u8 msg[32];
	int msglen;
};

extern u8 test_cache_l0(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_l1(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_lf(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_lg(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_u0(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_u1(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_uf(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_ug(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_m0(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_m1(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_mf(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_mg(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_v0(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_v1(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_vf(int *reg, u8 *msg, int *msglen);
extern u8 test_cache_vg(int *reg, u8 *msg, int *msglen);

extern u8 test_dma_d0(int *reg, u8 *msg, int *msglen);
extern u8 test_dma_d1(int *reg, u8 *msg, int *msglen);
extern u8 test_dma_e0(int *reg, u8 *msg, int *msglen);
extern u8 test_dma_e1(int *reg, u8 *msg, int *msglen);

extern u8 test_cpu_mulmul(int *reg, u8 *msg, int *msglen);
extern u8 test_cpu_mulnopmul(int *reg, u8 *msg, int *msglen);

#define MSG { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

struct Test sTestList1[] = {
	{ "L0", test_cache_l0, FALSE, 0, MSG, 0 },
	{ "L1", test_cache_l1, FALSE, 0, MSG, 0 },
	{ "LF", test_cache_lf, FALSE, 0, MSG, 0 },
	{ "LG", test_cache_lg, FALSE, 0, MSG, 0 },
	{ "U0", test_cache_u0, FALSE, 0, MSG, 0 },
	{ "U1", test_cache_u1, FALSE, 0, MSG, 0 },
	{ "UF", test_cache_uf, FALSE, 0, MSG, 0 },
	{ "UG", test_cache_ug, FALSE, 0, MSG, 0 },
	{ "M0", test_cache_m0, FALSE, 0, MSG, 0 },
	{ "M1", test_cache_m1, FALSE, 0, MSG, 0 },
	{ "MF", test_cache_mf, FALSE, 0, MSG, 0 },
	{ "MG", test_cache_mg, FALSE, 0, MSG, 0 },
	{ "V0", test_cache_v0, FALSE, 0, MSG, 0 },
	{ "V1", test_cache_v1, FALSE, 0, MSG, 0 },
	{ "VF", test_cache_vf, FALSE, 0, MSG, 0 },
	{ "VG", test_cache_vg, FALSE, 0, MSG, 0 },
	{ "D0", test_dma_d0, FALSE, 0, MSG, 0 },
	{ "D1", test_dma_d1, FALSE, 0, MSG, 0 },
	{ "E0", test_dma_e0, FALSE, 0, MSG, 0 },
	{ "E1", test_dma_e1, FALSE, 0, MSG, 0 },
};

struct Test sTestList2[] = {
	{ "MM", test_cpu_mulmul, FALSE, 0, MSG, 0 },
	{ "MN", test_cpu_mulnopmul, FALSE, 0, MSG, 0 }
};

struct TestList {
	const char *name;
	struct Test *tests;
	u32 len;
};

struct TestList sTestGroups[] = {
	{ "CACHE+DMA TESTING", sTestList1, ARRAY_LEN(sTestList1) },
	{ "CPU TESTING", sTestList2, ARRAY_LEN(sTestList2) },
	{ "", NULL, 0 }
};

struct TestList *sCurTestGroup = &sTestGroups[0];

u8 sTestsRunning = FALSE;
u8 sTestsDone = FALSE;

int sRunningTimer = 0;

void print_run_str(void) {
	char str[11];

	memcpy(str, "RUNNING...", 11);

	str[7 + ((sRunningTimer / 2) % 4)] = '\0';

	fb_clear_row(24);
	fb_print_str(5, 24, str);

	sRunningTimer++;
}

void print_test(struct Test *test, int y) {
	fb_clear_row(y);
	fb_print_str(5, y, test->name);
	fb_print_str(7, y, test->completed ? "1" : "0");
	fb_print_byte_str(8, y, test->msg, test->msglen);
}

void print_tests(void) {
	u32 i;

	fb_clear();

	fb_print_str(5, 1, sCurTestGroup->name);

	fb_print_str(30, 1, "PAGE ");
	fb_print_char(35, 1, sCurTestGroup - &sTestGroups[0] + 1 + '0');
	fb_print_str(36, 1, "/");
	fb_print_char(37, 1, ARRAY_LEN(sTestGroups) - 1 + '0');

	for (i = 0; i < sCurTestGroup->len; i++) {
		print_test(&sCurTestGroup->tests[i], i + 3);
	}

	print_run_str();
}

void run_tests(void) {
	u32 i;

	print_tests();

	if (!sTestsRunning && !sTestsDone) {
		fb_print_str(5, 24, "PRESS A TO BEGIN      L/R TO SKIP");

		if (gPlayer1Controller->buttonPressed & L_TRIG) {
			if (sCurTestGroup > &sTestGroups[0]) {
				sCurTestGroup--;
				sRunningTimer = 0;
			}
		}

		if (gPlayer1Controller->buttonPressed & R_TRIG) {
			if ((sCurTestGroup + 1)->tests != NULL) {
				sCurTestGroup++;
				sRunningTimer = 0;
			}
		}

		if (gPlayer1Controller->buttonPressed & A_BUTTON) {
			sTestsRunning = TRUE;
			sRunningTimer = 0;
			print_run_str();
		} else {
			return;
		}
	}

	for (i = 0; i < sCurTestGroup->len; i++) {
		struct Test *test = &sCurTestGroup->tests[i];

		test->completed = test->completed || test->exec(&test->reg, test->msg, &test->msglen);

		print_test(test, i + 3);

		if (!test->completed) {
			return;
		}
	}

	if ((sCurTestGroup + 1)->tests == NULL) {
		sTestsDone = TRUE;

		fb_clear_row(24);
		fb_print_str(5, 24, "HAVE A NICE DAY u");
	} else {
		fb_print_str(5, 24, "PRESS A TO CONTINUE...");

		if (gPlayer1Controller->buttonPressed & A_BUTTON) {
			sCurTestGroup++;
			sRunningTimer = 0;
		}
	}
}

#undef MSG
#undef ARRAY_LEN
