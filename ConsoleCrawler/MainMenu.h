#pragma once

#include "Menu.h"
#include "Window.h"

#include <vector>
#include <unordered_map>

class W_MainMenu : public MenuInterface
{
private:
	Element bg;
	Element T_Title;
	Element T_NewGame;
	Element T_Quit;

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

	virtual void construct() override;

	virtual void takeInput(const char key) override;
};