#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::init(const int newID)
{
	id = newID;
	onInit();
}

void Entity::tick(const float& deltaTime)
{
}

void Entity::render(ScreenBuffer& buffer) const
{

}