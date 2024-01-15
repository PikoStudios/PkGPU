#ifndef PKGPU_H
#define PKGPU_H

#if defined(PKGPU_USE_OPENGL4)
	#include "backends/ogl4/impl.h"
#elif defined(PKGPU_USE_CUSTOM_BACKEND)
	// Do nothing... should of already been included by the user
#else
	#include "backends/ogl4/impl.h"
#endif

#endif // PKGPU_H
