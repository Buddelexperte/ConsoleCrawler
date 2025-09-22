#include "HUD.h"

void W_HUD::openPause()
{
	openChild(&pausedMenu);
}

void W_HUD::closePause()
{
	closeChild(&pausedMenu);
}

W_HUD::W_HUD()
{

}

W_HUD::~W_HUD()
{

}

void W_HUD::construct()
{

}

EInputReturn W_HUD::takeInput(const char key)
{
	EInputReturn childInput = MenuInterface::takeInput(key);
	if (childInput != EInputReturn::NOT_USED)
		return childInput;

	switch (key)
	{
	case VK_ESCAPE:
		openPause();
		break;
	default:
		return EInputReturn::NOT_USED;
	}

	return EInputReturn::CONSUMED;
}
