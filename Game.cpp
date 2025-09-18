#include "Game.h"
#include "Player.h"

void GameInstance::init_members()
{
	entityManager.spawnEntity<Player>();
}

void GameInstance::tick_gameplay(const float& deltaTime)
{
	entityManager.tick(deltaTime);
}

void GameInstance::tick_render(const float& deltaTime)
{

}

GameInstance::~GameInstance()
{
}

void GameInstance::run()
{
	init_members();


	clock.restart();
	while (true)
	{

		float deltaTime = clock.getElapsedTime();

		tick(deltaTime);

		clock.restart();
	}
}

void GameInstance::tick(const float& deltaTime)
{
	tick_gameplay(deltaTime);

	tick_render(deltaTime);
}
