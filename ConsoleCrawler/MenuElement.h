#pragma once
#include <string>
#include <vector>

struct Element
{
	int x = 0; // X-Position in the buffer
	int y = 0; // Y-Position in the buffer

	int width = 0; // Max length of vector elements
	int height = 0; // Num of vector elements
	std::vector<std::string> content; // Content to render

	Element()
		: x(0), y(0), width(0), height(0), content(std::vector<std::string>()) {}

	Element(int x, int y, const std::string& content)
		: x(x), y(y), width(content.size()), height(1), content({ content }) {}

	Element(int x, int y, int width, const std::vector<std::string>& content)
		: x(x), y(y), width(width), height(content.size()), content(content) {}

	Element(int x, int y, int width, int height, const char c)
		: x(x), y(y), width(width), height(height), content(std::vector<std::string>(height, std::string(width, c))) {}
};

struct Element_FillScreen : public Element
{
	Element_FillScreen(const char c);
};