#include "EntityManager.h"

#include "Player.h"

int EntityManager::entityCount = 0;

EntityManager::EntityManager()
{
	spawnPlayer();
}

EntityManager::~EntityManager()
{
}

void EntityManager::spawnPlayer()
{
	player = std::make_unique<Player>();
	const size_t entityKey = entityCount++; // Player is ID = 0
	player->init(entityKey);
	renderer.addToStack(player.get(), ERenderLayer::ENTITIES);
}

void EntityManager::tick(const float& deltaTime)
{
	player->tick(deltaTime);

	for (const auto& pair : entities)
	{
		const std::unique_ptr<Entity>& entity = pair.second;

		if (!entity)
			continue;

		entity->tick(deltaTime);
	}
}

Player* EntityManager::getPlayer()
{
	return player.get();
}
