#include "PausedMenu.h"

#include "Game.h"

W_Paused::W_Paused()
{
	addComponent(modalBorder);
	addComponent(T_Title);
	addComponent(T_Resume);
	addComponent(T_Options);
	addComponent(T_Quit);
}

W_Paused::~W_Paused()
{

}

void W_Paused::construct()
{
	const int screenHalf_x = screenBuffer().getWidth() / 2;
	const int screenThird_y = screenBuffer().getHeight() / 3;

	static const std::vector<std::string> borderText = {
		TL_CORNER_CHAR + std::string(50, HOR_LINE_CHAR) + TR_CORNER_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		VERT_LINE_CHAR + std::string(50, ' ') + VERT_LINE_CHAR,
		BL_CORNER_CHAR + std::string(50, HOR_LINE_CHAR) + BR_CORNER_CHAR
	};
	modalBorder = SimpleElement(screenHalf_x, screenThird_y - 3, borderText, EJustification::CENTER);


	static const std::string title = "(PAUSED)";
	T_Title = SimpleElement(screenHalf_x, screenThird_y, title, EJustification::CENTER);

	static const std::string resume = "> (1) Resume";
	T_Resume = SimpleElement(screenHalf_x - 10, screenThird_y + 3, resume, EJustification::LEFT);

	static const std::string options = "  (2) Options";
	T_Options = SimpleElement(screenHalf_x - 10, screenThird_y + 4, options, EJustification::LEFT);

	static const std::string quit = "  (0) Quit";
	T_Quit = SimpleElement(screenHalf_x - 10, screenThird_y + 6, quit, EJustification::LEFT);
}

EInputReturn W_Paused::takeInput(const char key)
{
	const EInputReturn childInput = MenuElement::takeInput(key);
	if (childInput != EInputReturn::NOT_USED)
		return childInput;

	switch (key)
	{
	// Up and down "scrolling" using arrow keys
	case VK_DOWN:
		option_down();
		break;
	case VK_UP:
		option_up();
		break;
	// Allow specific selection without having to tip through all options
	case '1': case '2': case '0':
		option_select(key);
		break;
	// Execute selected Option on 'Enter'
	case VK_RETURN:
		exec_option(selectedOption);
		break;
	// Close pauseMenu in HUD
	case VK_ESCAPE:
		closeInParent();
		break;
	default:
		return EInputReturn::NOT_USED;
	}

	return EInputReturn::CONSUMED;
}

// Option selection

void W_Paused::option_down()
{
	option_incr(1);
}

void W_Paused::option_up()
{
	option_incr(-1);
}

void W_Paused::option_select(char option)
{
	auto unselectedPair = optionsElems.find(selectedOption);
	if (unselectedPair != optionsElems.end())
		unselectedPair->second->content[0][0] = ' ';
	else
		std::cerr << "Warning: no element bound to key " << selectedOption << "\n";

	selectedOption = option;

	auto selectedPair = optionsElems.find(selectedOption);
	if (selectedPair != optionsElems.end())
		selectedPair->second->content[0][0] = '>';
	else
		std::cerr << "Warning: no element bound to key " << selectedOption << "\n";
}

void W_Paused::option_incr(int incr = +1)
{
	auto it = std::find(options.begin(), options.end(), selectedOption);
	if (it != options.end())
	{
		const size_t NUM_OPTIONS = options.size();
		size_t index = std::distance(options.begin(), it);
		index = (index + incr + NUM_OPTIONS) % NUM_OPTIONS;

		char newOption = options[index];
		option_select(newOption);
	}
	else
		std::cerr << "Warning: selectedOption not in options list\n";
}

void W_Paused::exec_option(const char option)
{
	switch (option)
	{
	case '0':
		gameInstance().queueEndGame();
		break;
	case '1':
		closeInParent();
		break;
	case '2':
		// open options
		break;
	default:
		break;
	}
}