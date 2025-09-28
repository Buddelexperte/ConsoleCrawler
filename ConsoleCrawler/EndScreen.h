#pragma once

#include "MenuElement.h"
#include "Window.h"

class W_EndScreen : public MenuElement
{
private:
	FillScreenElement bg;
	SimpleElement T_Title;

public:
	W_EndScreen();
	~W_EndScreen();

	virtual void construct() override;
};