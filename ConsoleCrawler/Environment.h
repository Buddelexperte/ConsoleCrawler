#pragma once
#include <unordered_map>
#include <memory>

#include "Renderable.h"
#include "EntityManager.h"

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
	EntityManager& entityManager = EntityManager::getInstance();

public:
	Environment();
	~Environment();

	void startRound();
	void tick(const float& deltaTime);

	void render(ScreenBuffer& buffer) const override;
};