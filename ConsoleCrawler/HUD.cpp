#include "HUD.h"

void W_HUD::openPause()
{
	inGame_indic.content[0] = "gameplay paused";
}

W_HUD::W_HUD()
{
	components.push_back(&inGame_indic);
}

W_HUD::~W_HUD()
{

}

void W_HUD::construct()
{
	inGame_indic = Element(1, 1, "in Game");
}

void W_HUD::takeInput(const char key)
{
	switch (key)
	{
	case VK_ESCAPE:
		openPause();
		break;
	default:
		break;
	}
}
