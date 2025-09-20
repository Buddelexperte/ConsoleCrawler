#pragma once
#include <vector>
#include <windows.h>
#include <iostream>

#include "Renderable.h"

class RenderStack : public Renderable
{
private:
	static size_t renderCounter;

	static constexpr int NUM_LAYERS = static_cast<int>(ERenderLayer::RENDER_LAYER_COUNT);
	std::vector<std::pair<size_t, Renderable*>> renderLayers[NUM_LAYERS];

public:
	void addToStack(Renderable* obj, const ERenderLayer = ERenderLayer::UI, const bool bStackOnTop = true);
	void removeFromStack(Renderable* obj);
	void render(ScreenBuffer& buffer) override;
};

