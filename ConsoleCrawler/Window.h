#pragma once
#include <string>
#include <windows.h>

#include "ScreenBuffer.h"
#include "RenderStack.h"

class Window
{
private:
	int WIDTH = 800;
	int HEIGHT = 600;
	std::string windowTitle = "Window";

	void SetConsoleTitle(const std::string& title);
	void SetConsoleSize(int width, int height);
	void LockConsoleSize();

	RenderStack renderStack;
	ScreenBuffer buffer;

	// Singleton private constructor and destructor
	Window();
	~Window();
public:
	// Singleton getInstance method
	static Window& getInstance()
	{
		static Window instance;
		return instance;
	}

	void init(const std::string& title, int w, int h);

	const int getWidth() const { return WIDTH; }
	const int getHeight() const { return HEIGHT; }

	RenderStack& getRenderStack() { return renderStack; }
	ScreenBuffer& getBuffer() { return buffer; }

	void update();
};

inline Window& window()
{
	return Window::getInstance();
}

inline ScreenBuffer& screenBuffer()
{
	return Window::getInstance().getBuffer();
}