#pragma once
#include "Monsters.h"
#include "factory.h"
#include <SFML/Graphics.hpp>

class LineMonster :public Monsters
{
public:
	LineMonster(const sf::Vector2f& location, const sf::Texture& tex);
	LineMonster() = default;
	~LineMonster() = default;
	virtual void move();
private:

	//Player m_player;
	static bool m_registerit;
};

inline bool LineMonster::m_registerit = factory::registeritM("LineMonster",
	[]() -> std::unique_ptr<Monsters> { return std::make_unique<LineMonster>(); });