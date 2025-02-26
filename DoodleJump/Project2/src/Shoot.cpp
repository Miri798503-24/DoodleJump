#include "Shoot.h"

Shoot::Shoot(const sf::Vector2f& location, const sf::Texture& tex)
	:MoveObject(location, tex)
{
}

void Shoot::move()
{
	setLocation({ m_player.getLocation() });
	int x = getLocation().x + 20;

	//m_picture.setPosition(sf::Vector2f{ x, getLocation().y });
}
