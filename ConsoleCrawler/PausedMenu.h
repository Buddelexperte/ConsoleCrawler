#pragma once

#include "Menu.h"
#include "Window.h"

#include <vector>
#include <unordered_map>

class W_Paused : public MenuInterface
{
private:
	Element modalBorder;
	Element T_Title;

	Element T_Resume;
	Element T_Options;
	Element T_Quit;

	char selectedOption = '1';
	const std::vector<char> options = { '1', '2', '0' }; // 1 = New Game, 2 = Quit
	const std::unordered_map<char, Element*> optionsElems = {
		{ '1', &T_Resume },
		{ '2', &T_Options },
		{ '0', &T_Quit }
	};

	void option_down();
	void option_up();
	void option_select(char option);
	void option_incr(int incr);
	void exec_option(const char option);

public:
	W_Paused();
	~W_Paused();

	virtual void construct() override;

	virtual EInputReturn takeInput(const char key) override;
};