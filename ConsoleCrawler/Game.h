#pragma once
#include "Window.h"
#include "Clock.h"

#include "Environment.h"
#include "UserInterface.h"
#include "MenuCollection.h"

class GameInstance
{
private:
	static constexpr double TARGET_FPS = 12.0;

	void init_members();
	void init_window();

	void gameLoop();
	void endGame();
	bool bGameShouldEnd = false;

	void tick_gameplay(const float& deltaTime);
	void tick_menus(const float& deltaTime);
	void tick_render(const float& deltaTime);

	// Singleton private constructor and destructor
	GameInstance();
	~GameInstance();

	Window& window = Window::getInstance();
	Clock clock;

	UserInterface userInterface;
	Environment environment;

public:
	// Singleton getInstance method
	static GameInstance& getInstance()
	{
		static GameInstance instance;
		return instance;
	}

	void run();
	void tick(const float& deltaTime);

	void enterGameplay();
	void queueEndGame();

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

inline MenuInterface* currentMenu()
{
	return GameInstance::getInstance().getUserInterface().getCurrentMenu();
}