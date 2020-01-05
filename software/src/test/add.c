//#define MAKE_SURE_THIS_COMPILES

#include "add.h"

#ifdef MAKE_SURE_THIS_COMPILES
#error Yep, it compiles!
#endif

int add(int a, int b) {
	return a + b;
}
