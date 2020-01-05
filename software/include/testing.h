#ifndef TESTING_H_
#define TESTING_H_

#ifndef MICROMOUSE_TEST_PREFIX
#error Please do not compile test files in Atmel Studio!
#endif

#define TESTING_H_CONCAT_(a, b) a ## b
#define TESTING_H_CONCAT(a, b) TESTING_H_CONCAT_(a, b)

#ifdef MICROMOUSE_TEST_DETECT
#define TEST(name, ...) @MICROMOUSESTART@TESTING_H_CONCAT(MICROMOUSE_TEST_PREFIX, __LINE__):__VA_ARGS__:name@MICROMOUSEEND@
#else
#define TEST(name, ...) int TESTING_H_CONCAT(MICROMOUSE_TEST_PREFIX, __LINE__)(void)
#endif

#define TEST_SUCCESS 0
#define TEST_FAIL 1

#endif
