#include "CapybaraGL/Window.h"


Window::Window(std::string name, unsigned int width, unsigned int height)
{
	if (!glfwInit() )
	{
		fprintf(stderr, "Failed to initialized GLFW\n");
		getchar();
		glfwTerminate();
		initSuccess = false;
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), NULL, NULL);
	if (m_window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		getchar();
		glfwTerminate();
		initSuccess = false;
		return;
	}

	glfwMakeContextCurrent(m_window);

	glewExperimental = true;

	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialized GLEW.\n");
		getchar();
		glfwTerminate();
		initSuccess = false;
		return;
	}

	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
}

Window::~Window()
{
	if (m_window)
	{
		glfwDestroyWindow(m_window);
		m_window = nullptr;
	}
	
	// In the future, I need to only call glfwTerminate if I am deleting the last window instance. (if i have multiple windows)
	glfwTerminate();
}
