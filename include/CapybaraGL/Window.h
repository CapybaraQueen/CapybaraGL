#ifndef WINDOW_H
#define WINDOW_H

#include<memory>
#include<stdbool.h>

class WindowImpl;

class Window
{
	public:
		Window(std::string name, unsigned int width, unsigned int height);
		~Window();

		bool WindowExists() const;

		unsigned int GetWidth() const;
		unsigned int GetHeight() const;

		void SetDimensions();

		void PollEvents();

		void LoopTest() const;

	private:
		std::unique_ptr<WindowImpl> impl;
};

#endif
