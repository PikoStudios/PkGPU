#ifndef PKGPU_OGL4_BACKEND_STATE
#define PKGPU_OGL4_BACKEND_STATE

#include <stdint.h>
#include "../types.h"

/// @brief Backend State
typedef struct pkgpu_opengl4_backend_state
{
	uint32_t active_shader_program;
	pkgpu_color clear_color;
	int width;
	int height;
} pkgpu_backend_state;

/// @brief OpenGL 4 Specific Parameters
/// @field void* (*get_proc_address)(const char* name) - GLADloadproc function IE: When using GLFW3 you would set this field to glfwGetProcAddress \
/// if NULL, gladLoadGL will be ran instead.
typedef struct pkgpu_opengl4_backend_parameters
{
	void* (*get_proc_address)(const char* name);
} pkgpu_backend_parameters;

enum pkgpu_backend_state_result_code
{
	BACKEND_STATE_RESULT_GLAD_LOADGL_FAILED = 1,
};

typedef pkgpu_result(pkgpu_backend_state) pkgpu_backend_state_result;

/// @brief Initalize Backend State
/// @param int width - Width
/// @param int height - Height
/// @param pkgpu_backend_parameters specific_parameters - Backend-specific parameters IE: In the OpenGL 4 Backend, pkgpu_backend_parameters has a field named get_proc_address for function loading
/// @return pkgpu_backend_state_result - Result structure containing pkgpu_result_info and pkgpu_backend_state result
PKGPU_API pkgpu_backend_state_result pkgpu_initialize_backend(int width, int height, pkgpu_backend_parameters specific_parameters);

/// @brief Destroy Backend State
/// @param pkgpu_backend_state* state - Pointer to state
PKGPU_API void pkgpu_destroy_backend(pkgpu_backend_state* state);

#endif // PKGPU_OGL4_BACKEND_STATE
