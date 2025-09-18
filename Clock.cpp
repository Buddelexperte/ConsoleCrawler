#include "Clock.h"

Clock::Clock()
{
}

Clock::~Clock()
{
}

float Clock::getElapsedTime()
{
	const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> elapsedTime = now - startTime;
	return elapsedTime.count();
}

void Clock::restart()
{
	startTime = std::chrono::high_resolution_clock::now();
}
