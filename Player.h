#pragma once

class Player
{
private:
	float health = 1.0f;
	char inventory[9] = {}; // 9 slots

public:
	Player();
	~Player();


};