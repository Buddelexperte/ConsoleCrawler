#include "HealthBar.h"

#include "Game.h"

HealthBar::HealthBar()
	: playerRef(getPlayer())
{
	addComponent(T_Bar);
	addComponent(T_Bar_bg);
}

HealthBar::~HealthBar()
{
}

void HealthBar::onHealthUpdate()
{
}

void HealthBar::construct()
{
}
