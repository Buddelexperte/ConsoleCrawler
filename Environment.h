#pragma once
#include <unordered_map>
#include <memory>

#include "Background.h"

enum class EBackgroundSprite
{
	NONE = 0,
	BLANK,
	STONE_WALL,
	NUM_BACKGROUNDS
};

class Environment : public Renderable
{
private:
	Background background;

public:
	Environment();
	~Environment();

	void render(ScreenBuffer& buffer) override;
};