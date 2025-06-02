cmake_minimum_required(VERSION 3.16)
project(CapybaraGL_Test)

set(TEST_SOURCES
	main.cpp
)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

add_executable(CapybaraGL_Test ${TEST_SOURCES})

target_include_directories(CapybaraGL_Test PRIVATE /home/Angie/Documents/CppCode/CapybaraGL/include)

target_link_libraries(CapybaraGL_Test PRIVATE
	/home/Angie/Documents/CppCode/CapybaraGL/build/libCapybaraGL.a
	${OPENGL_gl_LIBRARY}
	${GLEW_LIBRARIES}
	${GLFW_LIBRARIES}
)
