#pragma once
#include <SFML/Graphics.hpp>
#include "Objects.h"

class MoveObject :
	public Objects
{
public:
	MoveObject(const sf::Vector2f& location, const sf::Texture& tex);
	MoveObject() = default;
	~MoveObject();
	sf::FloatRect objectGlobalBounds() const;
//	virtual void movement() = 0;
};