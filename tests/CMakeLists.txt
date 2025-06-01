 

set(TEST_SOURCES
	main.cpp
)

add_executable(CapybaraGL_Test ${TEST_SOURCES})

target_link_libraries(CapybaraGL_Test PRIVATE CapybaraGL)
