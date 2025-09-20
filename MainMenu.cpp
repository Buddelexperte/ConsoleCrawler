#include "MainMenu.h" // Header file

void W_MainMenu::option_down()
{
	option_incr(1);
}

void W_MainMenu::option_up()
{
	option_incr(-1);
}

void W_MainMenu::option_select(char option)
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

void W_MainMenu::option_incr(int incr = +1)
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

void W_MainMenu::exec_option(const char option)
{
}

W_MainMenu::W_MainMenu()
{
	components.push_back(&bg);
	components.push_back(&T_Title);
	components.push_back(&T_NewGame);
	components.push_back(&T_Quit);
}

W_MainMenu::~W_MainMenu()
{

}

void W_MainMenu::take_input(const char key)
{
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
	case '1': case '2':
		option_select(key);
		break;
	// Execute selected Option on 'Enter'
	case VK_RETURN:
		exec_option(selectedOption);
		break;
	default:
		break;
	}
}