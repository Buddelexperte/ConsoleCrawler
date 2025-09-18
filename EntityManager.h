#pragma once
#include <vector>
#include <memory>

#include "GenericPool.h"
#include "Entity.h"

class EntityManager
{
private:
	// Singleton private constructor and destructor
	EntityManager();
	~EntityManager();

	static int entityCount;
	std::vector<std::unique_ptr<Entity>> entities;

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

		// Set the enemy's index and add it to the activeEnemies vector
		const size_t entityKey = entityCount++;
		//std::cout << "Using new enemy with ID [" << enemyKey << "]" << std::endl;
		newEntity->init(entityKey);

		// Actually spawn the enemy properly and update it's attributes accordingly
		entities.emplace(entityKey, std::move(newEntity));
	}

	void tick(const float& deltaTime);
};