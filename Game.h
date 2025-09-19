#pragma once
#include "Window.h"
#include "Clock.h"

#include "EntityManager.h"
#include "Environment.h"

class GameInstance
{
private:
	static constexpr double TARGET_FPS = 1.0;

	void init_members();
	void init_window();
	void tick_gameplay(const float& deltaTime);
	void tick_render(const float& deltaTime);

	// Singleton private constructor and destructor
	GameInstance();
	~GameInstance();

	Window& window = Window::getInstance();
	Clock clock;

	Environment environment;

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

	Environment& getEnvironment() { return environment; }
};