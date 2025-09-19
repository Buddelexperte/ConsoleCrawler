#include "ScreenBuffer.h"
#include "windows.h"

#include <iostream>

void ScreenBuffer::draw(int x, int y, char c)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		buffer[y * width + x] = c;
}

void ScreenBuffer::drawString(int x, int y, const std::string& str)
{
	for (int i = 0; i < str.size(); i++)
		draw(x + (int)i, y, str[i]);
}

void ScreenBuffer::drawText(int x, int y, const std::vector< std::string>& lines)
{
	for (int i = 0; i < lines.size(); i++)
		drawString(x, y + i, lines[i]);
}

void ScreenBuffer::flush()
{
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
			std::cout << buffer[y * width + x];
		std::cout << "\n";
	} 
	std::cout << std::flush;
}