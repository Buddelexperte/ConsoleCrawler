#pragma once

#include "Menu.h"
#include "Window.h"

#include "ValueBar.h"

class W_ControlsHint : public MenuInterface
{
private:
	Element_FillScreen bg;
	Element T_Title;
	Element T_Text;
	Element T_Prompt;

	static constexpr float BLINK_INTERVAL = 1.0f;
	ValueBar promptBlinkTimer;

	void onEnter();

public:
	W_ControlsHint();
	~W_ControlsHint();

	void tick(const float& deltaTime) override;

	virtual void construct() override;

	void takeInput(const char key) override;
};