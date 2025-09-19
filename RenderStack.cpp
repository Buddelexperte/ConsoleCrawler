#include "RenderStack.h"

void RenderStack::addToStack(Renderable* obj, const ERenderLayer layer, const bool bStackOnTop)
{
	int layerIndex = static_cast<int>(layer);
	if (bStackOnTop)
		renderLayers[layerIndex].push_back(obj);
	else
		renderLayers[layerIndex].insert(renderLayers[layerIndex].begin(), obj);
}

void RenderStack::render()
{
	for (int i = 0; i < NUM_LAYERS; i++)
	{
		for (Renderable* obj : renderLayers[i])
		{
			obj->render();
		}
	}
}
