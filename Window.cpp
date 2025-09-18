#include "Window.h"

void Window::SetConsoleSize(int width, int height)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // 1. Fenstergröße anpassen
    SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    // 2. Puffergröße anpassen (muss >= Fenstergröße sein!)
    COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hOut, bufferSize);
}

void Window::LockConsoleSize()
{
    // Get the console window handle
    HWND consoleWindow = GetConsoleWindow();

    // Disable the maximize button
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style &= ~WS_MAXIMIZEBOX;    // remove maximize
    style &= ~WS_SIZEBOX;        // remove resizable border
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Apply the changes immediately
    SetWindowPos(consoleWindow, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

Window::Window()
{
    // Setting the console's size
    SetConsoleSize(WIDTH, HEIGHT);
}

Window::~Window()
{
}
