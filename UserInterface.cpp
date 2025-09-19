#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{
}

void UserInterface::render(ScreenBuffer& buffer)
{
	windowBorder.render(buffer);
}
