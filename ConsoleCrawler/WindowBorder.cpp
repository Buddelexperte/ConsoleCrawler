#include "WindowBorder.h"

WindowBorder::WindowBorder()
{

}

WindowBorder::~WindowBorder()
{

}

void WindowBorder::render(ScreenBuffer& buffer) const
{
	// Get current buffer size
	const int w = buffer.getWidth();
	const int h = buffer.getHeight();

	// Calc window Border coords
	int firstLine_y = 0;
	int lastLine_y = h - 1;
	int firstCol_x = 0;
	int lastCol_x = w - 1;

	std::string vertical_border = std::string(w - 2, HOR_LINE_CHAR);

	std::string top_line = TL_CORNER_CHAR + vertical_border + TR_CORNER_CHAR;
	std::string bottom_line = BL_CORNER_CHAR + vertical_border + BR_CORNER_CHAR;

	buffer.drawString(0, firstLine_y, top_line);

	for (int i = firstLine_y + 1; i < lastLine_y; i++)
	{
		buffer.draw(firstCol_x, i, VERT_LINE_CHAR);
		buffer.draw(lastCol_x, i, VERT_LINE_CHAR);
	}

	buffer.drawString(0, lastLine_y, bottom_line);
}