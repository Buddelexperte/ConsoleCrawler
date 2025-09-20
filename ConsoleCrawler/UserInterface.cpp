#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{
}

void UserInterface::handleInput(const char key)
{
	if (!currentMenu)
		return;

	currentMenu->take_input(key);
}

void UserInterface::render(ScreenBuffer& buffer)
{
	if (currentMenu)
		currentMenu->render(buffer);

	windowBorder.render(buffer);
}
