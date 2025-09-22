#pragma once

#include "MenuElement.h" // Base class
#include "Types.h"

class MenuInterface : public Element
{
private:
    MenuInterface* parent = nullptr; // If self is child, this represents call relaying menu
    MenuInterface* activeChild = nullptr; // Child to relay tick, input and draw calls to
    std::vector<Renderable*> components; // Components for render calls

protected:
    void addComponent(Renderable* obj);
    void addComponent(Renderable& obj);

public:
    MenuInterface();
    ~MenuInterface();

    virtual void construct() = 0;
    virtual void tick(const float& deltaTime);
    virtual EInputReturn takeInput(const char key);

    // Manage active child
    bool openChild(MenuInterface* child);
    void closeChild();
    void closeChild(MenuInterface* specificChild);
    bool hasActiveChild() const;
    MenuInterface* getActiveChild() const;

    // Ownership chain
    bool setParent(MenuInterface* newParent);
    const MenuInterface* getParent() const;
    void closeInParent();

    virtual void render(ScreenBuffer& buffer) const override;
};
