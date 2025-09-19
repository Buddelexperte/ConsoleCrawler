#pragma once

#include "ScreenBuffer.h"

enum class ERenderLayer
{
	NOT_RENDERED = -1,
	BACKGROUND = 0,
	MIDGROUND,
	FOREGROUND,
	UI,
	RENDER_LAYER_COUNT
};

class Renderable
{
private:
	size_t renderID = -1;
    ERenderLayer layer = ERenderLayer::NOT_RENDERED;

public:
	void setRenderID(const size_t id) { renderID = id; }
	const size_t getRenderID() const { return renderID; }
	const ERenderLayer getRenderLayer() const { return layer; }
	void setRenderLayer(ERenderLayer l) { layer = l; }
    virtual void render(ScreenBuffer& buffer) = 0;
};