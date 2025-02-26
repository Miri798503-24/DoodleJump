#include "MoveObject.h"

MoveObject::MoveObject(const sf::Vector2f& location, const sf::Texture& tex) :Objects(location, tex) {}

MoveObject::~MoveObject()
{
}

sf::FloatRect MoveObject::objectGlobalBounds() const
{
    return  m_picture.getGlobalBounds();
}
