#pragma once

#include "MenuElement.h"

class Player;

class HealthBar : MenuElement
{
private:
	float displayedHealth = 1.0f;
	float displayedMaxHealth = 1.0f;
	SimpleElement T_Bar_bg;
	SimpleElement T_Bar;

	Player* playerRef;

public:
	HealthBar();
	~HealthBar();
	
	void onHealthUpdate();

	virtual void construct() override;
};