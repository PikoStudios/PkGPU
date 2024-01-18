#include "backend/ogl4/backend_state.h"
#include "backend/ogl4/deps.h"

pkgpu_backend_state_result pkgpu_initialize_backend(int width, int height, pkgpu_backend_parameters specific_parameters)
{
	pkgpu_backend_state state;
	state.active_shader_program = 0;
	state.width = width;
	state.height = height;

	if (specific_parameters.get_proc_address == NULL)
	{
		if (!gladLoadGL())
		{
			return pkgpu_result_err(pkgpu_backend_state, BACKEND_STATE_RESULT_GLAD_LOADGL_FAILED, "gladLoadGL() failed", (pkgpu_backend_state){0});
		}
	}

	else
	{
		if (!gladLoadGLLoader((GLADloadproc)(specific_parameters.get_proc_address)))
		{
			return pkgpu_result_err(pkgpu_backend_state, BACKEND_STATE_RESULT_GLAD_LOADGL_FAILED, "gladLoadGL() failed", (pkgpu_backend_state){0});
		}
	}

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	return pkgpu_result_ok(pkgpu_backend_state, state);
}

void pkgpu_destroy_backend(pkgpu_backend_state* state)
{
	// TODO: Destroy Resources
}
