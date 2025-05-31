#ifndef WINDOW_H
#define WINDOW_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<string>

class Window
{
	private:
		GLFWwindow* m_window;
		std::string m_name;
		unsigned int m_width;
		unsigned int m_height;

	public:
		Window();
		~Window();

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }
};

#endif
