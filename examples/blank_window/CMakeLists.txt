cmake_minimum_required(VERSION 3.18)
project(BlankWindowExample)

set(CMAKE_BUILD_TYPE Debug)
set(PKGPU_ROOT "../../")
set(GLFW_ROOT "../deps/glfw")

include_directories(
	${PKGPU_ROOT}
	${PKGPU_ROOT}/include
	${PKGPU_ROOT}/include/pkgpu
)

link_directories(
	${GLFW_ROOT}/lib
	${PKGPU_ROOT}/build
)

add_executable(main main.c)

message(STATUS "Checking OS")
set(BASE_LIBS pkgpu)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	message(STATUS "Checking OS - found (Darwin/MacOS)")
	message(WARNING "Checking OS - warning (Darwin/MacOS support in this CMakeLists.txt is untested)")
	target_link_libraries(main ${BASE_LIBS} glfw CoreVideo OpenGL IOKit Cocoa Carbon)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	message(STATUS "Checking OS - found (Windows)")
	target_link_libraries(main ${BASE_LIBS} glfw3 opengl32)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	message(STATUS "Checking OS - found (Linux)")
	target_link_libraries(main ${BASE_LIBS} glfw GL m)
else()
	message(STATUS "Checking OS - not found")
	message(WARNING "No OS found, defaulting to Linux")
	target_link_libraries(main ${BASE_LIBS} glfw GL m)
endif()
