#pragma once

#include "Renderable.h" // Base class

// Components
#include "WindowBorder.h"
#include "MenuElement.h"

class UserInterface : public Renderable
{
private:
	MenuElement* currentMenu = nullptr;
	WindowBorder windowBorder;

public:
	UserInterface();
	~UserInterface();

	void displayMenu(MenuElement* menu);
	void removeMenu() { currentMenu = nullptr; }
	MenuElement* getCurrentMenu() const { return currentMenu; }

	void tick(const float& deltaTime);
	void handleInput(const char key);

	void render(ScreenBuffer& buffer) const override;
};