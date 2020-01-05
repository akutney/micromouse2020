#include <stdio.h>
#include <stdlib.h>
#include <testing.h>

#define RUN_TEST(func, desc) \
int func(void);
#include "tests.h"
#undef RUN_TEST

int main(int argc, const char **argv) {
    int res;
    int ret = EXIT_SUCCESS;
#define RUN_TEST(func, desc) \
    do { \
        printf("\r[\0337\033[33mTEST\033[0m] " desc "\t"); \
        res = func(); \
        printf("\0338"); \
        if (res == TEST_SUCCESS) { \
            printf("\033[32mPASS"); \
        } else { \
            printf("\033[31mFAIL"); \
            ret = EXIT_FAILURE; \
        } \
        printf("\033[0m\n"); \
    } while (0);
#include "tests.h"
    return ret;
}
