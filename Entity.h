#pragma once

class Entity
{
private:
	int id = -1;

public:
	Entity();
	~Entity();

	virtual void init(const int newID);
	virtual void tick(const float& deltaTime) = 0;
};