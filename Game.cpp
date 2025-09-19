#include "Game.h"
#include "Player.h"

#include <thread>

void GameInstance::init_members()
{
	entityManager.spawnEntity<Player>();
	window.getRenderStack().addToStack(&environment, ERenderLayer::BACKGROUND);
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
	using clock = std::chrono::high_resolution_clock;
	auto lastFrame = clock::now();

	init_members();

	init_window();

	float deltaTime = 0.0f;
	static constexpr double targetFrameTime = 1.0 / TARGET_FPS; // 60 FPS
	while (true)
	{
		auto now = clock::now();
		std::chrono::duration<double> elapsed = now - lastFrame;
		lastFrame = now;

		double deltaTime = elapsed.count();

		tick(deltaTime);
		tick_render(deltaTime);

		// Frame limiting for aesthetic and performance
		auto frameEnd = clock::now();
		std::chrono::duration<double> frameDuration = frameEnd - now;

		if (frameDuration.count() < targetFrameTime)
		{
			auto sleepTime = std::chrono::duration<double>(targetFrameTime - frameDuration.count());
			std::this_thread::sleep_for(sleepTime);
		}
	}
}

void GameInstance::tick(const float& deltaTime)
{
	tick_gameplay(deltaTime);

	tick_render(deltaTime);
}
