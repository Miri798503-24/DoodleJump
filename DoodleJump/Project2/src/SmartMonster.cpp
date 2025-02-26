#include "SmartMonster.h"

SmartMonster::SmartMonster(const sf::Vector2f& location, const sf::Texture& tex)
	:Monsters(location, tex)
{
}

void SmartMonster::move()
{
	if (m_player.getY() > m_picture.getPosition().y)	
		setLocation({ m_picture.getPosition().x, m_picture.getPosition().y + 0.15f });

	if (m_player.getX() > m_picture.getPosition().x)
		setLocation({m_picture.getPosition().x + 0.15f, m_picture.getPosition().y });

	if (m_player.getY() < m_picture.getPosition().y)
		setLocation({ m_picture.getPosition().x, m_picture.getPosition().y - 0.15f });
	

	if (m_player.getX() < m_picture.getPosition().x)
		setLocation({ m_picture.getPosition().x - 0.15f, m_picture.getPosition().y });
}
