#pragma once
#include <chrono>

using namespace std::chrono;

class Clock
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

public:
	Clock();
	~Clock();

	float getElapsedTime(); // Time elapsed since last reset in seconds
	void restart(); // Elapsed time is reset to zero
};