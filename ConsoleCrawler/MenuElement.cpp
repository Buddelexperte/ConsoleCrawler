#include "MenuElement.h" // Header file

#include "Window.h"

FillScreenElement::FillScreenElement(const char c)
	: SimpleElement(0, 0, screenBuffer().getWidth(), screenBuffer().getHeight(), c)
{}

FillScreenElement::FillScreenElement()
	: FillScreenElement(' ')
{
}

void SimpleElement::render(ScreenBuffer& buffer) const
{
	if (isVisible)
		buffer.drawElem(this);
}
