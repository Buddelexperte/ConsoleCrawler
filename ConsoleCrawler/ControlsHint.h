#pragma once

#include "MenuElement.h"
#include "Window.h"

#include "ValueBar.h"

class W_ControlsHint : public MenuElement
{
private:
	FillScreenElement bg;
	SimpleElement T_Title;
	SimpleElement T_Text;
	SimpleElement T_Prompt;

	static constexpr float BLINK_INTERVAL = 1.0f;
	ValueBar promptBlinkTimer;

	void onEnter();

public:
	W_ControlsHint();
	~W_ControlsHint();

	void tick(const float& deltaTime) override;

	virtual void construct() override;

	EInputReturn takeInput(const char key) override;
};