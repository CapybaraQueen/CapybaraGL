#include "CapybaraGL/Window.h"
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
#include<stdexcept>

class WindowImpl
{
	private:
		GLFWwindow* m_window;
		std::string m_name;
		unsigned int m_width;
		unsigned int m_height;

		bool initSuccess;

		WindowImpl(std::string name, unsigned int width, unsigned int height)
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

			m_name = name;
			m_width = width;
			m_height = height;

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

	public:
		static std::unique_ptr<WindowImpl> Create(std::string name, unsigned int width, unsigned int height)
		{
			std::unique_ptr<WindowImpl> window(new WindowImpl(name, width, height));
			if (!window->initSuccess)
			{
				return nullptr;
			}
			
			return window;
		}
		~WindowImpl();

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }
};

Window::Window(std::string name, unsigned int width, unsigned int height)
{
	impl = WindowImpl::Create(name, width, height);
	if (!impl)
	{
		throw std::runtime_error("Failed to initialize window.\n");
	}
}

Window::~Window() = default;
