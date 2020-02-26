#ifdef USE_VAR_1
#define COLS_1 4
#define ROWS_1 3
#elif defined(USE_VAR_2)
#define COLS_2 4
#define ROWS_2 3
#else
#define COLS_3 4
#define ROWS_3 3
#endif
#include "matrix-codegen.h"

#ifdef USE_VAR_1
#define COLS_1 2
#define ROWS_1 2
#elif defined(USE_VAR_2)
#define COLS_2 2
#define ROWS_2 2
#else
#define COLS_3 2
#define ROWS_3 2
#endif
#include "matrix-codegen.h"

#ifdef USE_VAR_1
#define COLS_1 2
#define ROWS_1 4
#elif defined(USE_VAR_2)
#define COLS_2 2
#define ROWS_2 4
#else
#define COLS_3 2
#define ROWS_3 4
#endif
#include "matrix-codegen.h"

#ifdef USE_VAR_1
#define COLS_1 3
#define ROWS_1 4
#elif defined(USE_VAR_2)
#define COLS_2 3
#define ROWS_2 4
#else
#define COLS_3 3
#define ROWS_3 4
#endif
#include "matrix-codegen.h"
