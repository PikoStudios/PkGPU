#include "../deps/glfw/include/glfw/glfw3.h"
#define PKGPU_USE_OPENGL4
#include <pkgpu/pkgpu.h>
#include <stdio.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800

#define pkgpu_error_msg(R) printf("PkGPU Error %d: %s", R.code, R.reasoning)

int main(void)
{
	if (!glfwInit()) return -1;

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello, World!", NULL, NULL);
	if (!window)
	{
		printf("glfw failed to create window\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	pkgpu_backend_parameters params = { (pkgpu_opengl4_getprocaddress_fun)(glfwGetProcAddress) };
	pkgpu_backend_state_result gpu_backend_result = pkgpu_initialize_backend(SCREEN_WIDTH, SCREEN_HEIGHT, &params);
	pkgpu_backend_state gpu_backend = gpu_backend_result.result;

	if (gpu_backend_result.result_info.code != 0)
	{
		pkgpu_error_msg(gpu_backend_result.result_info);
		return -1;
	}

	pkgpu_set_clear_color(&gpu_backend, 0.451, 1.0, 1.0, 1.0);
	
	while (!glfwWindowShouldClose(window))
	{
		pkgpu_prepare_frame(&gpu_backend);
		pkgpu_clear_screen(&gpu_backend);
		pkgpu_finish_frame(&gpu_backend);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
