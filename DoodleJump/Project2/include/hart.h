#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "factory.h"

class hart :public StaticObject
{
public:
	hart(const sf::Vector2f& location, const sf::Texture& tex)
		:StaticObject(location, tex){}
	hart() = default;
	~hart() = default;

private:
	static bool m_registerit;
};

inline bool hart::m_registerit = factory::registerit("hart",
	[]() -> std::unique_ptr<Objects> { return std::make_unique<hart>(); });