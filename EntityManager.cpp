#include "EntityManager.h"

int EntityManager::entityCount = 0;

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::tick(const float& deltaTime)
{
	for (std::unique_ptr<Entity>& entity : entities)
	{
		entity->tick(deltaTime);
	}
}
