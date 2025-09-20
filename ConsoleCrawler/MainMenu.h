#pragma once

#include "Menu.h"
#include "Window.h"

#include <vector>
#include <unordered_map>

class W_MainMenu : public MenuInterface
{
private:
	Element bg =		Element_FillScreen(' ');
	Element T_Title =	Element(5, 3, "CONSOLE CRAWLER" );
	Element T_NewGame = Element(5, 6, "> (1) NEW GAME" );
	Element T_Quit =	Element(5, 8, "  (2) QUIT" );

	char selectedOption = '1';
	const std::vector<char> options = { '1', '2' }; // 1 = New Game, 2 = Quit
	const std::unordered_map<char, Element*> optionsElems = {
		{ '1', &T_NewGame },
		{ '2', &T_Quit }
	};

	void option_down();
	void option_up();
	void option_select(char option);
	void option_incr(int incr);
	void exec_option(const char option);

public:
	W_MainMenu();
	~W_MainMenu();

	void take_input(const char key) override;
};