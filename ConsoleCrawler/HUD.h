#pragma once

#include "MenuElement.h"
#include "Window.h"

#include "PausedMenu.h"
#include "HealthBar.h"
#include <vector>
#include <unordered_map>

class W_HUD : public MenuElement
{
private:
	HealthBar healthBar;
	W_Paused pausedMenu;

	void openPause();
	void closePause();

public:
	W_HUD();
	~W_HUD();

	virtual void construct() override;

	virtual EInputReturn takeInput(const char key) override;
};