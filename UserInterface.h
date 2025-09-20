#pragma once

#include "Renderable.h" // Base class

// Components
#include "WindowBorder.h"
#include "Menu.h"

class UserInterface : public Renderable
{
private:
	MenuInterface* currentMenu;
	WindowBorder windowBorder;

public:
	UserInterface();
	~UserInterface();

	void displayMenu(MenuInterface* menu) { currentMenu = menu; }
	void removeMenu() { currentMenu = nullptr; }
	MenuInterface* getCurrentMenu() const { return currentMenu; }

	void handleInput(const char key);

	void render(ScreenBuffer& buffer) override;
};