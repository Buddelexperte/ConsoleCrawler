#include "Menu.h"

MenuInterface::MenuInterface()
{
}

MenuInterface::~MenuInterface()
{
}

void MenuInterface::render(ScreenBuffer& buffer)
{
	for (const Element* elem : components)
	{
		if (!elem)
			continue;

		buffer.drawElem(elem);
	}
}
