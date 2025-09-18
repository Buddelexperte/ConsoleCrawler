#pragma once

#include "Window.h"
#include "Clock.h"

#include "EntityManager.h"

class GameInstance
{
private:
	void init_members();
	void tick_gameplay(const float& deltaTime);
	void tick_render(const float& deltaTime);

	// Singleton private constructor and destructor
	GameInstance();
	~GameInstance();

	Window& window = Window::getInstance();
	Clock clock;

	EntityManager& entityManager = EntityManager::getInstance();

public:
	// Singleton getInstance method
	static GameInstance& getInstance()
	{
		static GameInstance instance;
		return instance;
	}

	void run();
	void tick(const float& deltaTime);
};