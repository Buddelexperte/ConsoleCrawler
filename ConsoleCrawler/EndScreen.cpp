#include "EndScreen.h"

W_EndScreen::W_EndScreen()
{
	components.push_back(&bg);
	components.push_back(&T_Title);
}

W_EndScreen::~W_EndScreen()
{
	
}

void W_EndScreen::construct()
{
	bg = Element_FillScreen(' ');

	static const std::string title = "GAME QUIT";
	static const int textHalfLen = std::ceil(title.size() / 2.0f);
	int screenHalf_x = screenBuffer().getWidth() / 2;
	int screenThird_y = screenBuffer().getHeight() / 3;
	T_Title = Element(screenHalf_x - textHalfLen, screenThird_y, title);
}
