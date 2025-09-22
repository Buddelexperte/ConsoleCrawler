#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	void onInit() override;
	
public:
	Player();
	~Player();

	void tick(const float& deltaTime) override;

	void render(ScreenBuffer& buffer) const override;
};