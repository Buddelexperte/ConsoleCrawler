#include "Environment.h"

Environment::Environment()
{
}

Environment::~Environment()
{
}

void Environment::render(ScreenBuffer& buffer)
{
	background.render(buffer);
}
