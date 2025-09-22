#include "Menu.h"

void MenuInterface::addComponent(Renderable* obj)
{
    components.push_back(obj);
}

void MenuInterface::addComponent(Renderable& obj)
{
    addComponent(&obj);
}

MenuInterface::MenuInterface() = default;

MenuInterface::~MenuInterface() = default;

void MenuInterface::tick(const float& deltaTime)
{
    if (activeChild)
        return activeChild->tick(deltaTime);
}

EInputReturn MenuInterface::takeInput(const char key)
{
    // If default relaying already consumed input, cancel further usage
    if (activeChild)
    {
        return activeChild->takeInput(key);
    }

    return EInputReturn::NOT_USED;
}

bool MenuInterface::openChild(MenuInterface* child)
{
    if (!child) return false;

    if (child == activeChild) return false;

    // Prevent cyclic parenting
    if (!child->setParent(this))
        return false;

    activeChild = child;
    activeChild->construct();
    return true;
}

void MenuInterface::closeChild()
{
    if (activeChild)
    {
        activeChild->setParent(nullptr);
        activeChild = nullptr;
    }
}


void MenuInterface::closeChild(MenuInterface* specificChild)
{
    if (activeChild)
    {
        if (activeChild != specificChild) return;

        activeChild->setParent(nullptr);
        activeChild = nullptr;
    }
}

bool MenuInterface::hasActiveChild() const
{
    return activeChild != nullptr;
}

MenuInterface* MenuInterface::getActiveChild() const
{
    return activeChild;
}

bool MenuInterface::setParent(MenuInterface* newParent)
{
    for (const MenuInterface* ptr = newParent; ptr != nullptr; ptr = ptr->getParent())
    {
        if (ptr == this) return false; // cycle detected, return false
    }

    parent = newParent;
    return true;
}

const MenuInterface* MenuInterface::getParent() const
{
    return parent;
}

void MenuInterface::closeInParent()
{
    if (parent)
        parent->closeChild(this);
}

void MenuInterface::render(ScreenBuffer& buffer) const
{
    if (!isVisible) return;

    // Draw components
    for (const Renderable* component : components)
    {
        if (component)
            component->render(buffer);
    }

    // Active child is not included in components
    if (activeChild)
        activeChild->render(buffer);
}
