#pragma once
#include "MoveObject.h"
#include "Player.h"

class Shoot :public MoveObject
{
public:
	Shoot(const sf::Vector2f& location, const sf::Texture& tex);
	Shoot() = default;
	~Shoot() = default;
	void move();

private:
	Player m_player;
};

