#include "backend/ogl4/screen.h"
#include "backend/ogl4/deps.h"

void pkgpu_prepare_frame(pkgpu_backend_state* state)
{
	// TODO: Batch rendering
}

void pkgpu_finish_frame(pkgpu_backend_state* state)
{
	// TODO: Flush batch renderer
	glFlush();
}

void pkgpu_set_clear_color(pkgpu_backend_state* state, float r, float g, float b, float a)
{
	state->clear_color = (pkgpu_color){r,g,b,a};
}

void pkgpu_set_clear_color_t(pkgpu_backend_state* state, pkgpu_color color)
{
	state->clear_color = color;
}

pkgpu_color pkgpu_get_clear_color(pkgpu_backend_state* state)
{
	return state->clear_color;
}

void pkgpu_clear_screen(pkgpu_backend_state* state)
{
	glClearColor(
		state->clear_color.r,
		state->clear_color.g,
		state->clear_color.b,
		state->clear_color.a
	);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
