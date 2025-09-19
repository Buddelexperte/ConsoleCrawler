#pragma once

#include "Renderable.h" // Base class

// Components
#include "WindowBorder.h"

class UserInterface : public Renderable
{
private:
	WindowBorder windowBorder;

public:
	UserInterface();
	~UserInterface();

	void render(ScreenBuffer& buffer) override;
};