#pragma once

#include "Renderable.h"

class WindowBorder : public Renderable
{
private:

public:
	WindowBorder();
	~WindowBorder();

	void render(ScreenBuffer& buffer) const override;
};