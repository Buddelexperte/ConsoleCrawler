#pragma once
#include <vector>
#include <string>

class ScreenBuffer
{
private:
	int width, height;
	std::vector<char> buffer;

public:
	ScreenBuffer(int w, int h) : width(w), height(h), buffer(w * h, ' ') {} // Fills buffer with empty chars (width * height)

	void clear() { std::fill(buffer.begin(), buffer.end(), ' '); }

	void draw(int x, int y, char c);
	void drawString(int x, int y, const std::string& str);
	void drawText(int x, int y, const std::vector<std::string>& lines);

	void flush();
};