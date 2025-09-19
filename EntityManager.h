#pragma once
#include <memory>
#include <unordered_map>

#include "GenericPool.h"
#include "Entity.h"
#include "Window.h"

class EntityManager
{
private:
	// Singleton private constructor and destructor
	EntityManager();
	~EntityManager();

	static int entityCount;
	std::unordered_map<size_t, std::unique_ptr<Entity>> entities;

	RenderStack& renderer = Window::getInstance().getRenderStack();

public:
	// Singleton getInstance method
	static EntityManager& getInstance()
	{
		static EntityManager instance;
		return instance;
	}


	template<typename T>
	void spawnEntity()
	{
		static_assert(std::is_base_of_v<Entity, T>, "T must be derived from Entity");

		// Retrieve an enemy instance from the pool
		std::unique_ptr<Entity> newEntity = GenericPool<T>::instance().get();

		// Set the enemy's index by using entityCounter
		const size_t entityKey = entityCount++;
		newEntity->init(entityKey);
		renderer.addToStack(newEntity.get(), ERenderLayer::MIDGROUND);

		// Actually add the enemy properly inside aliveEntity vector
		entities.emplace(entityKey, std::move(newEntity));
	}

	void tick(const float& deltaTime);
};