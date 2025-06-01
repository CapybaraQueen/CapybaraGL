cmake_minimum_required(VERSION 3.10)
project(CapybaraGL LANGUAGES C CXX)

cmake_policy(SET CMP0072 NEW)
cmake_policy(SET CMP0074 NEW)

# Set C++ and C standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

# Link directories (in case needed)
link_directories(
    ${GLEW_LIBRARY_DIRS}
    ${GLFW_LIBRARY_DIRS}
)

# Source files (no globbing)
set(LIBRARY_SOURCES
	src/Window.cpp
	src/Renderer.cpp
	src/Shader.cpp
	src/VertexBuffer.cpp
	src/VertexArray.cpp
	src/IndexBuffer.cpp
	src/CapybaraDebug.cpp
	res/shaders/Basic.glsl
	res/shaders/Circle.glsl
)

# Build as a static or shared library (you can switch STATIC <-> SHARED)
add_library(CapybaraGL STATIC ${LIBRARY_SOURCES})

# Link necessary system libraries
target_link_libraries(CapybaraGL PRIVATE
    ${OPENGL_gl_LIBRARY}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
)

# Optionally expose headers for users of the library
target_include_directories(CapybaraGL
	PUBLIC
		${CMAKE_SOURCE_DIR}/include
	PRIVATE
		${CMAKE_SOURCE_DIR}/internal
	)

