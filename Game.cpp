#include "Game.h"
#include "Player.h"

void GameInstance::init_members()
{
	entityManager.spawnEntity<Player>();
}

void GameInstance::init_window()
{
	window.init("Game Window", 1080, 600);

}

void GameInstance::tick_gameplay(const float& deltaTime)
{
	entityManager.tick(deltaTime);
}

void GameInstance::tick_render(const float& deltaTime)
{
	window.update();
}

GameInstance::GameInstance()
{
}

GameInstance::~GameInstance()
{
}

void GameInstance::run()
{
	init_members();

	init_window();

	float deltaTime = 0.0f;
	while (true)
	{
		deltaTime = clock.getElapsedTime();
		clock.restart();

		tick(deltaTime);
		tick_render(deltaTime);
	}
}

void GameInstance::tick(const float& deltaTime)
{
	tick_gameplay(deltaTime);

	tick_render(deltaTime);
}
