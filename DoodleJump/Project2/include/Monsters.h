#pragma once
#include <SFML/Graphics.hpp>
#include "MoveObject.h"

class Monsters   :public MoveObject
{
public:
	Monsters(const sf::Vector2f& location, const sf::Texture& tex)
		:MoveObject(location, tex){}
	Monsters() = default;
	~Monsters() = default;
	virtual void move() = 0;

private:

};