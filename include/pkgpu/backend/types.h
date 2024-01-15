#ifdef CLEAN_UP_MACROS
	#undef pkgpu_result
#endif

#ifndef PKGPU_TYPES_H
#define PKGPU_TYPES_H

#include <stdint.h>

typedef struct pkgpu_result_info
{
	uint8_t code;
	const char* reasoning;
} pkgpu_result_info;

#define pkgpu_result(T) struct { pkgpu_result_info result_info; T result; }

#endif // PKGPU_TYPES_H
