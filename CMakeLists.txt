cmake_minimum_required(VERSION 3.18)
project(PkGPU)

option(SUPPLY_CUSTOM_GLAD "Supply custom GLAD Headers" OFF)
option(GLAD_HEADER_FILE "Header file to GLAD" OFF)
set(GLAD_SOURCE_FILE deps/ogl4/glad/src/glad.c CACHE STRING "Source file to GLAD")

if (SUPPLY_CUSTOM_GLAD)
	add_compile_definitions(PKGPU_OGL4_SUPPLY_GLAD)

	if (NOT GLAD_HEADER_FILE)
			message(WARNING "GLAD_HEADER_FILE not defined... build will continue however this is likely not intended. If intended, ignore this warning.")
	endif()
endif()

set(SOURCE_FILES
	src/ogl4/screen.c
	src/ogl4/backend_state.c
	${GLAD_SOURCE_FILE}
)

include_directories(
	include/pkgpu
	${CMAKE_CURRENT_LIST_DIR}
)

if (NOT GLAD_HEADER_FILE)
	add_library(pkgpu STATIC ${SOURCE_FILES})
else()
	add_library(pkgpu STATIC ${SOURCE_FILES} ${GLAD_HEADER_FILE})
endif()
