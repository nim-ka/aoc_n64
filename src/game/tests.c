#include <ultra64.h>

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
};

struct TestList {
	struct Test *tests;
	u32 len;
};

struct TestList sTestGroups[] = {
	{ sTestList1, ARRAY_LEN(sTestList1) },
	{ sTestList1, ARRAY_LEN(sTestList1) },
	{ NULL, 0 }
};

struct TestList *sCurTestGroup = &sTestGroups[0];

void run_tests(void) {
	u32 i;

	fb_print_str(30, 1, "PAGE ");
	fb_print_char(35, 1, sCurTestGroup - &sTestGroups[0] + '0');
	fb_print_str(36, 1, "/");
	fb_print_char(37, 1, ARRAY_LEN(sTestGroups) - 1 + '0');

	for (i = 0; i < sCurTestGroup->len; i++) {
		struct Test *test = &sCurTestGroup->tests[i];

		fb_print_str(5, i + 3, test->name);
		fb_print_str(7, i + 3, test->completed ? "1" : "0");
		fb_print_byte_str(8, i + 3, test->msg, test->msglen);
	}

	fb_print_str(5, 25, "RUNNING...");

	for (i = 0; i < sCurTestGroup->len; i++) {
		struct Test *test = &sCurTestGroup->tests[i];

		if (!test->completed) {
			test->completed = test->exec(&test->reg, test->msg, &test->msglen);
			return;
		}
	}

	if ((sCurTestGroup + 1)->tests == NULL) {
		fb_print_str(5, 25, "HAVE A NICE DAY u");
	} else {
		fb_print_str(5, 25, "PRESS A TO CONTINUE...");

		if (gPlayer1Controller->buttonPressed & A_BUTTON) {
			sCurTestGroup++;
		}
	}
}

#undef MSG
#undef ARRAY_LEN
