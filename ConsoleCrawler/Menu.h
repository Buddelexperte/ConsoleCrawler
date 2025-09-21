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

	virtual void construct() = 0;
	virtual void tick(const float& deltaTime) {};

	virtual void takeInput(const char key) {};

	void render(ScreenBuffer& buffer) override;
};