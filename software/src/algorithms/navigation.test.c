/*
 * navigation.test.c
 */ 


#include <testing.h>
#include <error.h>

#include "navigation.h"

TEST(navigation compiles, src/algorithms/navigation.c, src/error.c) {
  return TEST_SUCCESS;
}