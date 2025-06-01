#ifndef WINDOW_H
#define WINDOW_H

#include<memory>

class WindowImpl;

class Window
{
	public:
		Window(std::string name, unsigned int width, unsigned int height);
		~Window();

	private:
		std::unique_ptr<WindowImpl> impl;
};

#endif
