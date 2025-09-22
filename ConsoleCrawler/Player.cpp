#include "Player.h"
#include <iostream>

void Player::onInit()
{

}

Player::Player()
{

}

Player::~Player()
{

}

void Player::tick(const float& deltaTime)
{

}

void Player::render(ScreenBuffer& buffer) const
{
	buffer.drawString(57, 10, "Player");
}
