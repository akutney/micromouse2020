//#define MAKE_SURE_THIS_COMPILES

#include <stdio.h>
#include <testing.h>
#include "add.h"

#ifdef MAKE_SURE_THIS_COMPILES
#error Yep, it compiles!
#endif

TEST(2 + 2, src/test/add.c) {
	if (add(2, 2) != 4) {
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

TEST(2 + 3, src/test/add.c) {
	if (add(2, 3) != 5) {
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}
