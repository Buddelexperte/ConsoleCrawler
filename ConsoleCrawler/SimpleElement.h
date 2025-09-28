#pragma once
#include <string>
#include <vector>

#include <ranges>
#include <algorithm>

#include "Renderable.h"

enum class EJustification {
    LEFT = 0,
    RIGHT,
    CENTER,
    COUNT
};

struct SimpleElement : public Renderable
{
public:
    bool isVisible = true;

    int x = 0; // X-Position in the buffer
    int y = 0; // Y-Position in the buffer

    int width = 0;  // Max length of vector elements
    int height = 0; // Num of vector elements
    std::vector<std::string> content; // Content to render

    // Default constructor
    SimpleElement(EJustification justification = EJustification::LEFT)
        : x(0), y(0), width(0), height(0), content() 
    {
        applyJustification(justification);
    }

    // Constructor: single string
    SimpleElement(int x, int y, const std::string& content,
        EJustification justification = EJustification::LEFT)
        : x(x), y(y), width(content.size()), height(1), content({ content }) 
    {
        applyJustification(justification);
    }

    // Constructor: vector of strings
    SimpleElement(int x, int y, const std::vector<std::string>& content,
        EJustification justification = EJustification::LEFT)
        : x(x), y(y), width(0), height(content.size()), content(content)
    {
        if (!content.empty()) {
            auto it = std::ranges::max_element(
                content,
                {},
                &std::string::size
            );
            width = it->size();
        }

        applyJustification(justification);
    }

    // Constructor: specified width + vector
    SimpleElement(int x, int y, int width, const std::vector<std::string>& content,
        EJustification justification = EJustification::LEFT)
        : x(x), y(y), width(width), height(content.size()), content(content) 
    {
        applyJustification(justification);
    }

    // Constructor: fill with char
    SimpleElement(int x, int y, int width, int height, const char c,
        EJustification justification = EJustification::LEFT)
        : x(x), y(y), width(width), height(height),
        content(std::vector<std::string>(height, std::string(width, c)))
    {
        applyJustification(justification);
    }

    virtual void render(ScreenBuffer& buffer) const override;

private:
    void applyJustification(const EJustification justification)
    {
        switch (justification)
        {
        case EJustification::RIGHT:
            x -= width;
            break;
        case EJustification::CENTER:
            x -= width / 2;
            break;
        // No changes here
        case EJustification::LEFT:
        case EJustification::COUNT:
        default:
            break;
        }
    }

};



struct FillScreenElement : public SimpleElement
{
	FillScreenElement(const char c);
	FillScreenElement();
};