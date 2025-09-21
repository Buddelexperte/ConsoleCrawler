#pragma once

#include "Renderable.h" // Base class

// Components
#include "WindowBorder.h"
#include "Menu.h"

class UserInterface : public Renderable
{
private:
	MenuInterface* currentMenu = nullptr;
	WindowBorder windowBorder;

public:
	UserInterface();
	~UserInterface();

	void displayMenu(MenuInterface* menu);
	void removeMenu() { currentMenu = nullptr; }
	MenuInterface* getCurrentMenu() const { return currentMenu; }

	void tick(const float& deltaTime);
	void handleInput(const char key);

	void render(ScreenBuffer& buffer) override;
};