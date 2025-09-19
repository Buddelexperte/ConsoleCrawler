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
	for (const auto& pair : entities)
	{
		const std::unique_ptr<Entity>& entity = pair.second;

		if (!entity)
			continue;

		entity->tick(deltaTime);
	}
}