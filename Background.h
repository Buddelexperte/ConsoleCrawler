#pragma once

#include "Renderable.h"

class Background : public Renderable
{
private:

public:
	Background();
	~Background();

	void render(ScreenBuffer& buffer) override;
};