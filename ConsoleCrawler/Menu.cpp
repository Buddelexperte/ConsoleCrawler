#include "MenuElement.h"

void MenuElement::addComponent(Renderable* obj)
{
    components.push_back(obj);
}

void MenuElement::addComponent(Renderable& obj)
{
    addComponent(&obj);
}

MenuElement::MenuElement() = default;

MenuElement::~MenuElement() = default;

void MenuElement::tick(const float& deltaTime)
{
    if (activeChild)
        return activeChild->tick(deltaTime);
}

EInputReturn MenuElement::takeInput(const char key)
{
    // If default relaying already consumed input, cancel further usage
    if (activeChild)
    {
        return activeChild->takeInput(key);
    }

    return EInputReturn::NOT_USED;
}

bool MenuElement::openChild(MenuElement* child)
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

void MenuElement::closeChild()
{
    if (activeChild)
    {
        activeChild->setParent(nullptr);
        activeChild = nullptr;
    }
}


void MenuElement::closeChild(MenuElement* specificChild)
{
    if (activeChild)
    {
        if (activeChild != specificChild) return;

        activeChild->setParent(nullptr);
        activeChild = nullptr;
    }
}

bool MenuElement::hasActiveChild() const
{
    return activeChild != nullptr;
}

MenuElement* MenuElement::getActiveChild() const
{
    return activeChild;
}

bool MenuElement::setParent(MenuElement* newParent)
{
    for (const MenuElement* ptr = newParent; ptr != nullptr; ptr = ptr->getParent())
    {
        if (ptr == this) return false; // cycle detected, return false
    }

    parent = newParent;
    return true;
}

const MenuElement* MenuElement::getParent() const
{
    return parent;
}

void MenuElement::closeInParent()
{
    if (parent)
        parent->closeChild(this);
}

void MenuElement::render(ScreenBuffer& buffer) const
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
