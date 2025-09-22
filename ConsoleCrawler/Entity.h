#pragma once

#include "Renderable.h"

class Entity : public Renderable
{
private:
	int id = -1;

	virtual void onInit() = 0;

public:
	Entity();
	~Entity();

	const int getID() const { return id; }

	void init(const int newID);
	virtual void tick(const float& deltaTime) = 0;

	virtual void render(ScreenBuffer& buffer) const override;
};