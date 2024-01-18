#ifndef PKGPU_OGL4_SCREEN
#define PKGPU_OGL4_SCREEN

#include "../types.h"
#include "backend_state.h"

PKGPU_API void pkgpu_prepare_frame(pkgpu_backend_state* state);
PKGPU_API void pkgpu_finish_frame(pkgpu_backend_state* state);

PKGPU_API void pkgpu_set_clear_color(pkgpu_backend_state* state, float r, float g, float b, float a);
PKGPU_API void pkgpu_set_clear_color_t(pkgpu_backend_state* state, pkgpu_color color);
PKGPU_API pkgpu_color pkgpu_get_clear_color(pkgpu_backend_state* state);
PKGPU_API void pkgpu_clear_screen(pkgpu_backend_state* state);

#endif // PKGPU_OGL4_SCREEN
