#pragma once
#include <vector>

#include "Renderable.h"

enum class ERenderLayer
{
	BACKGROUND = 0,
	MIDGROUND,
	FOREGROUND,
	UI,
	RENDER_LAYER_COUNT
};

class RenderStack : public Renderable
{
private:
	static constexpr int NUM_LAYERS = static_cast<int>(ERenderLayer::RENDER_LAYER_COUNT);
	std::vector<Renderable*> renderLayers[NUM_LAYERS];

public:
	void addToStack(Renderable* obj, const ERenderLayer = ERenderLayer::UI, const bool bStackOnTop = true);
	void render() override;
};