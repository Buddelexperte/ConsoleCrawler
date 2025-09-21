#pragma once

#include "Menu.h"
#include "Window.h"

class W_EndScreen : public MenuInterface
{
private:
	Element_FillScreen bg;
	Element T_Title;

public:
	W_EndScreen();
	~W_EndScreen();

	virtual void construct() override;
};