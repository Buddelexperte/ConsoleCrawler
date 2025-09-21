#pragma once

#include "Menu.h"
#include "Window.h"

#include <vector>
#include <unordered_map>

class W_HUD : public MenuInterface
{
private:
	Element inGame_indic;

	void openPause();

public:
	W_HUD();
	~W_HUD();

	virtual void construct() override;

	virtual void takeInput(const char key) override;
};