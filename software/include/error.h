#ifndef ERROR_H_
#define ERROR_H_

#include <stdio.h>

typedef enum {
	ESUCCESS = 0,
#ifdef E
#error Please do not define E
#endif
#define ERROR_H_CONCAT(a, b) a ## b
#define E(mnemonic, desc) ERROR_H_CONCAT(E, mnemonic),
#include "errors.h"
#undef E
#undef ERROR_H_CONCAT
} mm_error_t;

extern mm_error_t mm_errno;
extern const int mm_numerr;

const char *mm_strerror(mm_error_t errno);

#define ERROR_H_STR(x) # x

#define RETURN_ERROR (-1)
#define RETURN_SUCCESS (0)

#define TRACE_ERR() do { \
		puts("  at " __FILE__ ":" ERROR_H_STR(__LINE__)); \
	} while (0)
#define THROW_ERR(func, error) do { \
		mm_errno = error; \
		printf(func ": %s\r\n", mm_strerror(mm_errno)); \
		return RETURN_ERROR; \
	} while (0)
#define CHECK_ERR(code) do { \
		if (code < 0) { \
			TRACE_ERR(); \
			return RETURN_ERROR; \
		} \
	} while (0)
#define CHECK_ERR_JMP(code, label) do { \
		if (code < 0) { \
			TRACE_ERR(); \
			goto label; \
		} \
	} while (0)
#define CHECK_ERR_STOP(code, msg) do { \
  if (code < 0) { \
    TRACE_ERR(); \
    printf(msg); \
    printf("\nStopping...\n"); \
    while (1); \
  } \
} while (0)

#endif
