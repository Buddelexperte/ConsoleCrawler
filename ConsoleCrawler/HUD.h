#pragma once

#include "Menu.h"
#include "Window.h"

#include "PausedMenu.h"
#include <vector>
#include <unordered_map>

class W_HUD : public MenuInterface
{
private:
	W_Paused pausedMenu;

	void openPause();
	void closePause();

public:
	W_HUD();
	~W_HUD();

	virtual void construct() override;

	virtual EInputReturn takeInput(const char key) override;
};