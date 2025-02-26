#include "staticObject.h"

StaticObject::StaticObject(const sf::Vector2f& location, const sf::Texture& tex) 
	:Objects(location, tex) {}

StaticObject::StaticObject()
{
}
