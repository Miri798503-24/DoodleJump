#pragma once
#include <SFML/Graphics.hpp>
#include "Monsters.h"
#include "factory.h"

class RandMonster :public Monsters
{
public:
	RandMonster(const sf::Vector2f& location, const sf::Texture& tex);
	RandMonster() = default;
	~RandMonster() = default;
	virtual void move();
private:

	static bool m_registerit;
	int m_direction = 0; 
	int m_numSteps = 0;

};

inline bool RandMonster::m_registerit = factory::registeritM("RandMonster",
	[]() -> std::unique_ptr<Monsters> { return std::make_unique<RandMonster>(); });
