#include "Window.h"
#include <iostream>

void Window::hideConsoleCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo); // Get current cursor info
    cursorInfo.bVisible = FALSE;                 // Hide cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo); // Apply
}


void Window::SetConsoleTitle(const std::string& title)
{
    SetConsoleTitleA(title.c_str());
}

void Window::SetConsoleSize(int width, int height)
{
    WIDTH = width;
    HEIGHT = height;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // First set buffer size
    COORD bufferSize = { static_cast<SHORT>(WIDTH), static_cast<SHORT>(HEIGHT) };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Then set window size (must be <= buffer size)
    SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(WIDTH - 1), static_cast<SHORT>(HEIGHT - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
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
    hideConsoleCursor();
    SetConsoleTitle(title);

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
