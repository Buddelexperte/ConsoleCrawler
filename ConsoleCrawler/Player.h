#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	float health = 1.0f;
	char inventory[9] = {}; // 9 slots

	void onInit() override;
	
public:
	Player();
	~Player();

	void tick(const float& deltaTime) override;

	void render(ScreenBuffer& buffer) override;
};