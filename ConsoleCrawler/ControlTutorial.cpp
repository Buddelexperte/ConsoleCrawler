#include "ControlsHint.h"

#include "Game.h"

void W_ControlsHint::onEnter()
{
	ui().displayMenu(MenuCollection::MainMenu.get());
}

W_ControlsHint::W_ControlsHint()
	: promptBlinkTimer(BLINK_INTERVAL)
{
	components.push_back(&bg);
	components.push_back(&T_Title);
	components.push_back(&T_Text);
	components.push_back(&T_Prompt);
}

W_ControlsHint::~W_ControlsHint()
{
}

void W_ControlsHint::tick(const float& deltaTime)
{
	promptBlinkTimer.addValue(-deltaTime);

	if (promptBlinkTimer.isEmpty()) // Should blink
	{
		T_Prompt.isVisible = !T_Prompt.isVisible;
		promptBlinkTimer.fill_to_max();
	}
}

void W_ControlsHint::construct()
{
	bg = Element_FillScreen(' ');

	const int screenHalf_x = screenBuffer().getWidth() / 2;
	const int screenThird_y = screenBuffer().getHeight() / 3;

	static const std::string title = "CONTROLS";
	T_Title = Element(screenHalf_x, screenThird_y, title, EJustification::CENTER);

	static const std::vector<std::string> hints = 
	{
		"ARROW KEYS - Navigating around menus",
		"ENTER      - Submitting current choice, forwarding, etc",
		"ESC        - Pause Menu, canceling selection, etc",
		"OTHER KEYS - Selection of specific options"
	};

	T_Text = Element(screenHalf_x, screenThird_y + 2, hints, EJustification::CENTER);

	static const std::string prompt = "PRESS ENTER TO CONTINUE";
	int promptPos_y = screenThird_y + 2 + hints.size() + 2;
	T_Prompt = Element(screenHalf_x, promptPos_y, prompt, EJustification::CENTER);
}

void W_ControlsHint::takeInput(const char key)
{
	switch (key)
	{
	case VK_RETURN:
		onEnter();
		break;
	default:
		break;
	}

}
