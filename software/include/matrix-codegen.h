#ifndef CONCAT
#   ifndef _CONCAT
#       define _CONCAT(a, b) a ## b
#   endif
#   define CONCAT(a, b) _CONCAT(a, b)
#endif
#ifndef matrix_element_t
#   define matrix_element_t double
#endif

#ifdef MATRIX_C_SOURCE
#   ifdef USE_VAR_1

#       define SIZE_1 CONCAT(CONCAT(COLS_1, _), ROWS_1)
#       define SIZE_3 CONCAT(CONCAT(COLS_3, _), ROWS_3)
#       define matrix1_t CONCAT(matrix, SIZE_1)
#       define matrix3_t CONCAT(matrix, SIZE_3)

#       if ROWS_3 == COLS_1

#           define USE_VAR_2
#           undef USE_VAR_1
#           include "matrices.h"
#           define USE_VAR_1
#           undef USE_VAR_2

#       endif

#       undef matrix3_t
#       undef matrix1_t
#       undef SIZE_3
#       undef SIZE_1

#       undef ROWS_1
#       undef COLS_1
#   elif defined(USE_VAR_2)

#       if COLS_3 == COLS_2 && ROWS_1 == ROWS_2

void CONCAT(CONCAT(mult, SIZE_3), CONCAT(_, ROWS_1))(matrix3_t a, matrix1_t b, CONCAT(CONCAT(matrix, COLS_3), CONCAT(_, ROWS_1)) *prod) {
    for (int i = COLS_3; i > 0; --i) {
        for (int j = ROWS_1; j > 0; --j) {
            prod->e[i][j] = 0;
            for (int k = ROWS_3; k > 0; --k) {
                prod->e[i][j] += a.e[i][k] * b.e[k][j];
            }
        }
    }
}

#       endif

#       undef COLS_2
#       undef ROWS_2
#   else
#       define SIZE CONCAT(CONCAT(COLS_3, _), ROWS_3)
#       define matrix_t CONCAT(matrix, SIZE)
#       ifdef MATRIX_FUNCS

void CONCAT(add, SIZE)(matrix_t a, matrix_t b, matrix_t *sum) {
    for (int i = COLS_3; i > 0; --i) {
        for (int j = ROWS_3; j > 0; --j) {
            sum->e[i][j] = a.e[i][j] + b.e[i][j];
        }
    }
}

void CONCAT(sub, SIZE)(matrix_t a, matrix_t b, matrix_t *diff) {
    for (int i = COLS_3; i > 0; --i) {
        for (int j = ROWS_3; j > 0; --j) {
            diff->e[i][j] = a.e[i][j] - b.e[i][j];
        }
    }
}

void CONCAT(element_mult, SIZE)(matrix_t a, matrix_t b, matrix_t *prod) {
    for (int i = COLS_3; i > 0; --i) {
        for (int j = ROWS_3; j > 0; --j) {
            prod->e[i][j] = a.e[i][j] * b.e[i][j];
        }
    }
}

void CONCAT(zero, SIZE)(matrix_t *m) {
    for (int i = COLS_3; i > 0; --i) {
        for (int j = ROWS_3; j > 0; --j) {
            m->e[i][j] = 0;
        }
    }
}

#           if COLS_3 == ROWS_3

void CONCAT(inverse, SIZE)(matrix_t in, matrix_t *out) {
    // TODO
}

void CONCAT(ident, SIZE)(matrix_t *m) {
    for (int i = COLS_3; i > 0; --i) {
        for (int j = ROWS_3; j > 0; --j) {
            m->e[i][j] = i == j ? 1 : 0;
        }
    }
}

#           endif

#           define USE_VAR_1
#           include "matrices.h"
#           undef USE_VAR_1

#       else

//typedef double[COLS_3][ROWS_3] matrix_t;

#       endif
#       undef matrix_t
#       undef SIZE
#       undef ROWS_3
#       undef COLS_3
#   endif
#else
#   ifdef USE_VAR_1

#       define SIZE_1 CONCAT(CONCAT(COLS_1, _), ROWS_1)
#       define SIZE_3 CONCAT(CONCAT(COLS_3, _), ROWS_3)
#       define matrix1_t CONCAT(matrix, SIZE_1)
#       define matrix3_t CONCAT(matrix, SIZE_3)

#       if ROWS_3 == COLS_1

#           define USE_VAR_2
#           undef USE_VAR_1
#           include "matrices.h"
#           define USE_VAR_1
#           undef USE_VAR_2

#       endif

#       undef matrix3_t
#       undef matrix1_t
#       undef SIZE_3
#       undef SIZE_1

#       undef ROWS_1
#       undef COLS_1
#   elif defined(USE_VAR_2)

#       if COLS_3 == COLS_2 && ROWS_1 == ROWS_2

void CONCAT(CONCAT(mult, SIZE_3), CONCAT(_, ROWS_1))(matrix3_t a, matrix1_t b, CONCAT(CONCAT(matrix, COLS_3), CONCAT(_, ROWS_1)) *prod);

#       endif

#       undef COLS_2
#       undef ROWS_2
#   else
#       define SIZE CONCAT(CONCAT(COLS_3, _), ROWS_3)
#       define matrix_t CONCAT(matrix, SIZE)
#       ifdef MATRIX_FUNCS

void CONCAT(add, SIZE)(matrix_t a, matrix_t b, matrix_t *sum);
void CONCAT(sub, SIZE)(matrix_t a, matrix_t b, matrix_t *diff);
void CONCAT(element_mult, SIZE)(matrix_t a, matrix_t b, matrix_t *prod);
void CONCAT(zero, SIZE)(matrix_t *m);

#           if COLS_3 == ROWS_3

void CONCAT(inverse, SIZE)(matrix_t in, matrix_t *out);
void CONCAT(ident, SIZE)(matrix_t *m);

#           endif

#           define USE_VAR_1
#           include "matrices.h"
#           undef USE_VAR_1

#       else

typedef struct {
    matrix_element_t e[COLS_3][ROWS_3];
} matrix_t;

#       endif
#       undef matrix_t
#       undef SIZE
#       undef ROWS_3
#       undef COLS_3
#   endif
#endif
