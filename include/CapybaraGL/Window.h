#ifndef WINDOW_H
#define WINDOW_H

#include<memory>

class WindowImpl;

class Window
{
	public:
		Window(std::string name, unsigned int width, unsigned int height);
		~Window();

		void* GetWindowHandle() const;

		unsigned int GetWidth() const;
		unsigned int GetHeight() const;

		void SetDimensions();

	private:
		std::unique_ptr<WindowImpl> impl;
};

#endif
