 

set(TEST_SOURCES
	main.cpp
)

target_include_directories(CapybaraGL_Test PUBLIC /home/Angie/Documents/CppCode/CapybaraGL/include)


add_executable(CapybaraGL_Test ${TEST_SOURCES})

target_link_libraries(CapybaraGL_Test PRIVATE CapybaraGL)
