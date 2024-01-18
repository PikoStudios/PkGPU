#ifdef CLEAN_UP_MACROS
	#undef pkgpu_result
	#undef PKGPU_API
#endif

#ifndef PKGPU_TYPES_H
#define PKGPU_TYPES_H

#ifdef _WIN32
	#ifdef BUILD_LIBTYPE_SHARED
		#define PKGPU_API __declspec(dllexport)
	#else
		#ifdef USE_LIBTYPE_SHARED
			#define PKGPU_API __declspec(dllimport)
		#endif
	#endif
#endif

#ifndef PKGPU_API
	#define PKGPU_API
#endif

#include <stdint.h>

typedef struct pkgpu_result_info
{
	uint8_t code;
	const char* reasoning;
} pkgpu_result_info;

typedef struct pkgpu_color
{
	float r;
	float g;
	float b;
	float a;
} pkgpu_color;

/// @param T - type
#define pkgpu_result(T) struct { pkgpu_result_info result_info; T result; }

/// @param T - type
/// @param R - result
#define pkgpu_result_ok(T,R) (T##_result){ .result_info = (pkgpu_result_info){.code = 0, .reasoning = NULL}, .result = R }

/// @param T - type
/// @param C - code
/// @param R - reasoning
/// @param F - fallback
#define pkgpu_result_err(T,C,R,F) (T##_result){ .result_info = (pkgpu_result_info){.code = C, .reasoning = R}, .result = F }

#endif // PKGPU_TYPES_H
