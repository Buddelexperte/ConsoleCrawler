#pragma once

#include "SimpleElement.h" // Base class
#include "Types.h"

class MenuElement : public SimpleElement
{
private:
    MenuElement* parent = nullptr; // If self is child, this represents call relaying menu
    MenuElement* activeChild = nullptr; // Child to relay tick, input and draw calls to
    std::vector<Renderable*> components; // Components for render calls

protected:
    void addComponent(Renderable* obj);
    void addComponent(Renderable& obj);

public:
    MenuElement();
    ~MenuElement();

    virtual void construct() = 0;
    virtual void tick(const float& deltaTime);
    virtual EInputReturn takeInput(const char key);

    // Manage active child
    bool openChild(MenuElement* child);
    void closeChild();
    void closeChild(MenuElement* specificChild);
    bool hasActiveChild() const;
    MenuElement* getActiveChild() const;

    // Ownership chain
    bool setParent(MenuElement* newParent);
    const MenuElement* getParent() const;
    void closeInParent();

    virtual void render(ScreenBuffer& buffer) const override;
};
