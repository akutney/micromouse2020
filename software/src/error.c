#include <stdio.h>
#include <error.h>

static const char *error_strings[] = {
	"Success",
	#define E(mnemonic, desc) desc,
	#include <errors.h>
	#undef E
};

mm_error_t mm_errno = ESUCCESS;
const int mm_numerr = sizeof(error_strings) / sizeof(error_strings[0]);

static char *const invalid_error = "Invalid error XXXXXXXXXX";
static char *const invalid_error_num = invalid_error + 14;
static char *const invalid_error_num_end = invalid_error_num + 10;

const char *mm_strerror(mm_error_t errno) {
	if (errno < 0 || errno >= mm_numerr) {
		char *it = invalid_error_num_end;
		uint32_t err = (uint32_t) errno;
		while (err) {
			*it-- = '0' + (err % 10);
			err /= 10;
		}
		char *it2 = invalid_error_num;
		while (it < invalid_error_num_end) {
			*it2++ = *it++;
		}
		*it2 = 0;
		return invalid_error;
	}
	return error_strings[errno];
}
