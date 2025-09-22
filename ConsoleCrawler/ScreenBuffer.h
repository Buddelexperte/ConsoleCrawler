#pragma once
#include <vector>
#include <string>

// Standard char for left and right console edges
static inline constexpr char VERT_LINE_CHAR = char(186);
static inline constexpr char HOR_LINE_CHAR = char(205);
static inline constexpr char TL_CORNER_CHAR = char(201);
static inline constexpr char TR_CORNER_CHAR = char(187);
static inline constexpr char BL_CORNER_CHAR = char(200);
static inline constexpr char BR_CORNER_CHAR = char(188);

struct Element;

class ScreenBuffer
{
private:
	int width, height;
	std::vector<char> buffer;

public:
	ScreenBuffer(int w, int h) : width(w), height(h), buffer(w * h, ' ') {} // Fills buffer with empty chars (width * height)

	const int getWidth() const { return width; }
	const int getHeight() const { return height; }

	void clear() { std::fill(buffer.begin(), buffer.end(), ' '); }

	void draw(int x, int y, char c);
	void drawString(int x, int y, const std::string& str);
	void drawLines(int x, int y, const std::vector<std::string>& lines);
	void drawElem(const Element* elem);

	void flush();
};