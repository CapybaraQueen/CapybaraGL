cmake_minimum_required(VERSION 3.10)
project(MyOpenGLLibrary LANGUAGES C CXX)

cmake_policy(SET CMP0074 NEW)

# Set C++ and C standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

# Include directories
include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    include
)

# Link directories (in case needed)
link_directories(
    ${GLEW_LIBRARY_DIRS}
    ${GLFW_LIBRARY_DIRS}
)

# Source files (no globbing)
set(LIBRARY_SOURCES
    src/renderer.c
    src/utils.cpp
    include/renderer.h
    include/utils.hpp
)

# Build as a static or shared library (you can switch STATIC <-> SHARED)
add_library(MyOpenGLLibrary STATIC ${LIBRARY_SOURCES})

# Link necessary system libraries
target_link_libraries(MyOpenGLLibrary
    ${OPENGL_gl_LIBRARY}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
)

# Optionally expose headers for users of the library
target_include_directories(MyOpenGLLibrary PUBLIC include)

