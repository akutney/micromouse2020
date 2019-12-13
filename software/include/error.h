#ifndef ERROR_H_
#define ERROR_H_

#include <stdio.h>

typedef enum {
	ESUCCESS = 0,
#ifdef E
#error Please don't define E
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
void mm_perror(const char *func);
void mm_trace(const char *file, int line);

#define RETURN_ERROR (-1)
#define RETURN_SUCCESS (0)

#define THROW_ERR(func, error) do { \
		mm_errno = error; \
		puts(); \
		mm_perror(func); \
		return RETURN_ERROR; \
	} while (0)
#define CHECK_ERR(code) do { \
		if (code < 0) { \
			mm_trace(__FILE__, __LINE__); \
			return RETURN_ERROR; \
		} \
	} while (0)
#define CHECK_ERR_JMP(code, label) do { \
		if (code < 0) { \
			mm_trace(__FILE__, __LINE__); \
			goto label; \
		} \
	} while (0)

#endif
