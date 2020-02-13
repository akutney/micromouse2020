/*
 * guidance.test.c
 *
 */ 


#include <testing.h>
#include <error.h>

#include "guidance.h"

TEST(guidance compiles, src/algorithms/guidance.c, src/error.c) {
	//printf("works\n");
	return TEST_SUCCESS;
}