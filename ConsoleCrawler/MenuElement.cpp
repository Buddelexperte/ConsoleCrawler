#include "MenuElement.h" // Header file

#include "Window.h"

Element_FillScreen::Element_FillScreen(const char c)
	: Element(0, 0, screenBuffer().getWidth(), screenBuffer().getHeight(), c)
{}
