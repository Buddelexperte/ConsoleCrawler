#include "Window.h"
#include <iostream>

void Window::SetConsoleTitle(const std::string& title)
{
    SetConsoleTitleA(title.c_str());
}

void Window::SetConsoleSize(int width, int height)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // First set buffer size
    COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hOut, bufferSize);

    // Then set window size (must be <= buffer size)
    SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);
}


void Window::LockConsoleSize()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    style &= ~WS_MAXIMIZEBOX; // disable maximize button
    style &= ~WS_SIZEBOX;     // disable resize border

    SetWindowLong(consoleWindow, GWL_STYLE, style);
    SetWindowPos(consoleWindow, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}


Window::Window()
    : buffer(120, 29)
{

}

Window::~Window()
{
}

void Window::init(const std::string& title, int w, int h)
{
    SetConsoleTitle(title);

    // WIP
    SetConsoleSize(w, h);
    LockConsoleSize();

    // Clear view
    update();
}

void Window::update()
{
    buffer.clear();
    renderStack.render(buffer);
    buffer.flush();
}
