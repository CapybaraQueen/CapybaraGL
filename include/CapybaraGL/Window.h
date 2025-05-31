#ifndef WINDOW_H
#define WINDOW_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<string>
#include<optional>

class Window
{
	private:
		Window(std::string name, unsigned int width, unsigned int height);

		GLFWwindow* m_window;
		std::string m_name;
		unsigned int m_width;
		unsigned int m_height;

		bool initSuccess;

	public:
		static std::optional<Window> Create(std::string name, unsigned int width, unsigned int height);
		~Window();

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }
};

#endif
