#include "RandMonster.h"

RandMonster::RandMonster(const sf::Vector2f& location, const sf::Texture& tex)
	:Monsters(location, tex)
{
}

void RandMonster::move()
{
	sf::Vector2f loc = getLocation();
	if (m_numSteps == 0)
	{
		m_direction = rand() % 4 + 1;
		m_numSteps = rand() % 150 + 140;
	}

	switch (m_direction)
	{
	case 1:
		setLocation({ loc.x - 0.3f, loc.y });
		break;

	case 2:
		setLocation({ loc.x + 0.3f , loc.y });
		break;

	case 3:
		setLocation({ loc.x , loc.y - 0.3f });
		break;

	default:
		setLocation({ loc.x , loc.y + 0.3f });
		break;
	}
	m_numSteps--;
}

