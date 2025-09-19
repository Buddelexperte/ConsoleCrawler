#include "WindowBorder.h"

WindowBorder::WindowBorder()
{

}

WindowBorder::~WindowBorder()
{

}

void WindowBorder::render(ScreenBuffer& buffer)
{
	// Get current buffer size
	const int w = buffer.getWidth();
	const int h = buffer.getHeight();

	// Calc window Border coords
	int firstLine_y = 0;
	int lastLine_y = h - 1;
	int firstCol_x = 0;
	int lastCol_x = w - 1;

	// Standard char for left and right console edges
	static constexpr char HOR_BORDER_CHAR = char(186);
	static constexpr char VERT_BORDER_CHAR = char(205);
	static constexpr char TL_CORNER = char(201);
	static constexpr char TR_CORNER = char(187);
	static constexpr char BL_CORNER = char(200);
	static constexpr char BR_CORNER = char(188);

	std::string vertical_border = std::string(w - 2, VERT_BORDER_CHAR);

	std::string top_line = TL_CORNER + vertical_border + TR_CORNER;
	std::string bottom_line = BL_CORNER + vertical_border + BR_CORNER;

	buffer.drawString(0, firstLine_y, top_line);

	for (int i = firstLine_y + 1; i < lastLine_y; i++)
	{
		buffer.draw(firstCol_x, i, HOR_BORDER_CHAR);
		buffer.draw(lastCol_x, i, HOR_BORDER_CHAR);
	}

	buffer.drawString(0, lastLine_y, bottom_line);
}