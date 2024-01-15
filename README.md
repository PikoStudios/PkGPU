# PkGPU
Low-level graphics abstraction layer for C. 

## Example
```c
#define PKGPU_USE_OPENGL4
#include <pkgpu/pkgpu.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800

int main(void)
{
	// Initialize Window here
	// end

	pkgpu_window_info window_info = (pkgpu_window_info){.width = 400, .height = 800};
	pkgpu_backend_state_result gpu_backend_result = pkgpu_initialize_backend(window_info);
  	pkgpu_backend_state gpu_backend = gpu_backend_result.result;
	unsigned char running = 1;
	
	if (gpu_backend_result.result_info.code != 0)
	{
		pkgpu_result_info_print(&gpu_backend_result.result_info);
		return;
	}
	
	pkgpu_shader_result default_vertex_shader_result = pkgpu_load_default_vertex_shader(&gpu_backend);
	pkgpu_shader_result default_fragment_shader_result = pkgpu_load_default_fragment_shader(&gpu_backend);
	pkgpu_shader default_vertex_shader = default_vertex_shader_result.result;
	pkgpu_shader default_fragment_shader = default_fragment_shader_result.result;

	if (default_vertex_shader_result.result_info.code != 0)
	{
		pkgpu_result_info_print(&default_vertex_shader_result.result_info);
		pkgpu_destroy_backend(&gpu_backend); // Certain resources will be destroyed here
		return -1;
	}
	
	if (default_fragment_shader_result.result_info.code != 0)
	{
		pkgpu_result_info_print(&default_fragment_shader_result.result_info);
		pkgpu_destroy_backend(&gpu_backend);
		return -1;
	}

	pkgpu_shader_program_result default_shader_program_result = pkgpu_initialize_shader_program(&default_vertex_shader, &default_fragment_shader);
	pkgpu_shader_program default_shader_program = default_shader_program.result;

	if (default_shader_program_result.result_info.code != 0)
	{
		pkgpu_result_info_print(&default_shader_program_result);
		pkgpu_destroy_backend(&gpu_backend);
		return -1;
	}

	pkgpu_destroy_all_shaders(&gpu_backend); // Shaders already compiled into a program, can destroy shaders.
	pkgpu_set_clear_color(&gpu_backend, 0.f, 0.f, 0.f, 0.f);
	
	while (running)
	{
		// Check for event to cause window close then set running = false
	
		pkgpu_clear(&gpu_backend);
		pkgpu_use_shader_program(&gpu_backend, default_shader_program);
		pkgpu_begin(&gpu_backend, PKGPU_TRIANGLE);

		pkgpu_set_color(&gpu_backend, 1.0f, 1.0f, 1.0f, 1.0f);
		pkgpu_vertex2f(&gpu_backend, SCREEN_WIDTH * 0.5, 50);
		pkgpu_vertex2f(&gpu_backend, SCREEN_WIDTH * 0.25, 600);
		pkgpu_vertex2f(&gpu_backend, SCREEN_WIDTH * 0.75, 600);
		
		pkgpu_end(&gpu_backend);
		pkgpu_use_shader_program(&gpu_backend, 0);
		pkgpu_finish_frame(&gpu_backend);
	}
	
	pkgpu_destroy_backend(&gpu_backend);
	return 0;
}
```
