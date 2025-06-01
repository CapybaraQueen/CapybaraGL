#ifndef CAPYBARA_DEBUG_H
#define CAPYBARA_DEBUG_H

#include<stdint.h>
#include<cassert>

#define ASSERT(x) if (!(x)) assert(false)
#define INT2VOIDP(i) reinterpret_cast<void*>(static_cast<uintptr_t>(i))

#ifdef CAPYBARA_DEBUG

void GLClearError();

bool GLCheckError(const char* function, const char* file, int line);

#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLCheckError(#x, __FILE__, __LINE__))
#else
#define GLCall(x) x
#endif

#endif
