#pragma once
#include <unordered_map>
#include <memory>

#include "Renderable.h"

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

public:
	Environment();
	~Environment();

	void render(ScreenBuffer& buffer) override;
};