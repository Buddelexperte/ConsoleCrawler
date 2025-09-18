#pragma once
#include <windows.h>

class Window
{
private:
	static const int WIDTH = 800;
	static const int HEIGHT = 600;

	void SetConsoleSize(int width, int height);
	void LockConsoleSize();

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

	void clear();
	void render();
	const int getWidth() const { return WIDTH; }
	const int getHeight() const { return HEIGHT; }
};