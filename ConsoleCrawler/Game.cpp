#include "Game.h"
#include "Player.h"

#include <thread>

#include "Input.h"
#include "MenuCollection.h"

void GameInstance::init_members()
{
	window.getRenderStack().addToStack(&environment, ERenderLayer::BACKGROUND);
	window.getRenderStack().addToStack(&userInterface, ERenderLayer::UI);

	userInterface.displayMenu(MenuCollection::ControlsHint.get());
}

void GameInstance::init_window()
{
	window.init("Game Window", 1080, 600);

}

void GameInstance::gameLoop()
{
	using clock = std::chrono::high_resolution_clock;
	auto lastFrame = clock::now();

	float deltaTime = 0.0f;
	static constexpr double targetFrameTime = 1.0 / TARGET_FPS;
	while (!bGameShouldEnd)
	{
		auto now = clock::now();
		std::chrono::duration<double> elapsed = now - lastFrame;
		lastFrame = now;

		double deltaTime = elapsed.count();

		tick(deltaTime);

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

void GameInstance::endGame()
{
	// Display EndScreen before ending game Loop
	userInterface.displayMenu(MenuCollection::EndScreen.get());
}

void GameInstance::tick_gameplay(const float& deltaTime)
{
	environment.tick(deltaTime);
}

void GameInstance::tick_menus(const float& deltaTime)
{
	userInterface.tick(deltaTime);
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

	gameLoop();
}

void GameInstance::tick(const float& deltaTime)
{
	UserInput::tick_events();

	tick_gameplay(deltaTime);

	tick_menus(deltaTime);

	if (bGameShouldEnd) endGame();

	tick_render(deltaTime);
}

void GameInstance::enterGameplay()
{
	environment.startRound();
	userInterface.displayMenu(MenuCollection::HUD.get());
}

void GameInstance::queueEndGame()
{
	bGameShouldEnd = true;
}