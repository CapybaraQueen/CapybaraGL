#include "CapybaraDebug.h"
#include <GL/glew.h>
#include <iostream>

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLCheckError(const char* function, const char* file, int line) {
    bool success = true;
    while (GLenum error = glGetError()) {
        success = false;
        std::cerr << "[OpenGL Error] (" << error << "): ";

        switch (error) {
            case GL_INVALID_ENUM:
                std::cerr << "GL_INVALID_ENUM: Invalid enum value.";
                break;
            case GL_INVALID_VALUE:
                std::cerr << "GL_INVALID_VALUE: Numeric value out of range.";
                break;
            case GL_INVALID_OPERATION:
                std::cerr << "GL_INVALID_OPERATION: Invalid operation.";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cerr << "GL_INVALID_FRAMEBUFFER_OPERATION: Incomplete framebuffer.";
                break;
            case GL_OUT_OF_MEMORY:
                std::cerr << "GL_OUT_OF_MEMORY: Out of memory.";
                break;
            case GL_STACK_UNDERFLOW:
                std::cerr << "GL_STACK_UNDERFLOW: Stack underflow.";
                break;
            case GL_STACK_OVERFLOW:
                std::cerr << "GL_STACK_OVERFLOW: Stack overflow.";
                break;
            default:
                std::cerr << "Unknown error code: " << error;
        }

        std::cerr << " in " << function << " (" << file << ":" << line << ")" << std::endl;
    }
    return success;
}

