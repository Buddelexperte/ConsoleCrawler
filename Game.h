#pragma once
#include "Window.h"
#include "Clock.h"

#include "EntityManager.h"
#include "Environment.h"
#include "UserInterface.h"

class GameInstance
{
private:
	static constexpr double TARGET_FPS = 12.0;

	void init_members();
	void init_window();
	void tick_gameplay(const float& deltaTime);
	void tick_render(const float& deltaTime);

	// Singleton private constructor and destructor
	GameInstance();
	~GameInstance();

	Window& window = Window::getInstance();
	Clock clock;

	UserInterface userInterface;
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

	UserInterface& getUserInterface() { return userInterface; }
	Environment& getEnvironment() { return environment; }
};

inline GameInstance& gameInstance()
{
	return GameInstance::getInstance();
}

inline UserInterface& ui()
{
	return GameInstance::getInstance().getUserInterface();
}

inline Environment& gameEnvironment()
{
	return GameInstance::getInstance().getEnvironment();
}