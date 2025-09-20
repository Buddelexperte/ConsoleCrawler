#pragma once

#include "Renderable.h" // Base class
#include "MenuElement.h" // Components

class MenuInterface : public Renderable
{
protected:
	std::vector<Element*> components;

public:
	MenuInterface();
	~MenuInterface();

	virtual void take_input(const char key) = 0;

	void render(ScreenBuffer& buffer) override;
};