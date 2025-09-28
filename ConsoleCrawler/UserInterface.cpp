#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{
}

void UserInterface::displayMenu(MenuElement* menu)
{
	currentMenu = menu;
	currentMenu->construct();
}

void UserInterface::tick(const float& deltaTime)
{
	if (!currentMenu)
		return;

	currentMenu->tick(deltaTime);
}

void UserInterface::handleInput(const char key)
{
	if (!currentMenu)
		return;

	currentMenu->takeInput(key);
}

void UserInterface::render(ScreenBuffer& buffer) const
{
	if (currentMenu)
		currentMenu->render(buffer);

	windowBorder.render(buffer);
}
