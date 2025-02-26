#pragma once
#include "Monsters.h"
#include "factory.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class SmartMonster :public Monsters
{
public:
	SmartMonster(const sf::Vector2f& location, const sf::Texture& tex);
	SmartMonster() = default;
	~SmartMonster() = default;
	virtual void move();
private:

	Player m_player;
	static bool m_registerit;
};

inline bool SmartMonster::m_registerit = factory::registeritM("SmartMonster",
	[]() -> std::unique_ptr<Monsters> { return std::make_unique<SmartMonster>(); });