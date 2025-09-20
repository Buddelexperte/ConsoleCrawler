#include "Game.h"

int main()
{
	GameInstance& game = GameInstance::getInstance();

	game.run();

	return 0;
}