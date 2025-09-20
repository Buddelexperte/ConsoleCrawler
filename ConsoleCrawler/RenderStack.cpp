#include "RenderStack.h"
#include "ScreenBuffer.h"

 size_t RenderStack::renderCounter = 0;

void RenderStack::addToStack(Renderable* obj, const ERenderLayer layer, const bool bStackOnTop)
{
	const size_t currID = renderCounter++;

	obj->setRenderID(currID);
	obj->setRenderLayer(layer);

	int layerIndex = static_cast<int>(layer);
	if (bStackOnTop)
		renderLayers[layerIndex].emplace_back(currID, obj);
	else
		renderLayers[layerIndex].emplace(renderLayers[layerIndex].begin(), currID, obj);
}

void RenderStack::removeFromStack(Renderable* obj)
{
	for (int i = 0; i < NUM_LAYERS; i++)
	{
		auto& layer = renderLayers[i];
		size_t id = obj->getRenderID();
		auto it = std::find_if(layer.begin(), layer.end(),
			[id](const std::pair<size_t, Renderable*>& entry)
			{
				return entry.first == id;
			});

		if (it != layer.end())
		{
			layer.erase(it);
			return;
		}
	}
}

void RenderStack::render(ScreenBuffer& buffer)
{
	for (int i = 0; i < NUM_LAYERS; i++)
	{
		for (const auto& pair : renderLayers[i])
		{
			Renderable* renderObj = pair.second;

			if (!renderObj)
				continue;

			renderObj->render(buffer);
		}
	}
}