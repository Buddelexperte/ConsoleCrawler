#pragma once

class UserInput
{
private:
	// Singleton
	UserInput();
	~UserInput();

public:
	// Singleton getInstance method
	static UserInput& getInstance()
	{
		static UserInput instance;
		return instance;
	}

	static void tick_events();
	static bool isKeyDown(const char key);
};