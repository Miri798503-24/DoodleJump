#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "factory.h"

class brickBrown :public StaticObject
{
public:
	brickBrown(const sf::Vector2f& location, const sf::Texture& tex);
	brickBrown() = default;
	~brickBrown() = default;
private:
	static bool m_registerit;
};

inline bool brickBrown::m_registerit = factory::registerit("brickBrown",
	[]() -> std::unique_ptr<Objects> { return std::make_unique<brickBrown>(); });