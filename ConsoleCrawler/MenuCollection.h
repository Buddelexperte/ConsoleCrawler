#pragma once
#include <memory>

#include "AllMenus.h"

class MenuCollection
{
public:
	inline static std::unique_ptr<W_MainMenu> MainMenu = std::make_unique<W_MainMenu>();
	inline static std::unique_ptr<W_EndScreen> EndScreen = std::make_unique<W_EndScreen>();
	inline static std::unique_ptr<W_ControlsHint> ControlsHint = std::make_unique<W_ControlsHint>();
	inline static std::unique_ptr<W_HUD> HUD = std::make_unique<W_HUD>();

	MenuCollection();
	~MenuCollection();
};