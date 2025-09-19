#include "Background.h"

Background::Background()
{

}

Background::~Background()
{

}

void Background::render(ScreenBuffer& buffer)
{
	int w = buffer.getWidth();
	int h = buffer.getHeight();

	std::string line = char(186) + std::string(w - 2, ' ') + char(186);
	std::string top_line = char(201) + std::string(w - 2, char(205)) + char(187);
	std::string bottom_line = char(200) + std::string(w - 2, char(205)) + char(188);

	std::vector<std::string> vec(h, line);
	vec.back() = bottom_line;
	vec.front() = top_line;

	buffer.drawLines(0, 0, vec);
}