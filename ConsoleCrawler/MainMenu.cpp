#include "MainMenu.h" // Header file

#include "Game.h"

W_MainMenu::W_MainMenu()
{
	addComponent(bg);
	addComponent(T_Title);
	addComponent(T_NewGame);
	addComponent(T_Quit);
}

W_MainMenu::~W_MainMenu()
{

}

void W_MainMenu::construct()
{
	bg = FillScreenElement(' ');
	T_Title = SimpleElement(5, 3, "CONSOLE CRAWLER");
	T_NewGame = SimpleElement(5, 6, "> (1) NEW GAME");
	T_Quit = SimpleElement(5, 8, "  (2) QUIT");
}

EInputReturn W_MainMenu::takeInput(const char key)
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
	case '1': case '2':
		option_select(key);
		break;
	// Execute selected Option on 'Enter'
	case VK_RETURN:
		exec_option(selectedOption);
		break;
	default:
		return EInputReturn::NOT_USED;
	}

	return EInputReturn::CONSUMED;
}

// Option selection

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
	switch (option)
	{
	case '1':
		gameInstance().enterGameplay();
		break;
	case '2':
		gameInstance().queueEndGame();
		break;
	default:
		break;
	}
}