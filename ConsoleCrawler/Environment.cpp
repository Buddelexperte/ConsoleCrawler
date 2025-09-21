#include "Environment.h"

#include "Player.h"

Environment::Environment()
{
}

Environment::~Environment()
{
}

void Environment::startRound()
{
	entityManager.spawnEntity<Player>();
}

void Environment::tick(const float& deltaTime)
{
	entityManager.tick(deltaTime);
}

void Environment::render(ScreenBuffer& buffer)
{

}
