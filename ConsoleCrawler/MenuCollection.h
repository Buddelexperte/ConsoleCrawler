#pragma once
#include <memory>

#include "AllMenus.h"

class MenuCollection
{
public:
	static std::unique_ptr<W_MainMenu> MainMenu;

	MenuCollection();
	~MenuCollection();
};