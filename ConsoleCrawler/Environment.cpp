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
}

void Environment::tick(const float& deltaTime)
{
	entityManager.tick(deltaTime);
}

void Environment::render(ScreenBuffer& buffer) const
{

}

EntityManager& Environment::getEntityManager()
{
	return entityManager;
}
