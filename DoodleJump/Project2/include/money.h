#pragma once
# include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "factory.h"


class money :public StaticObject
{
public:
	money(const sf::Vector2f& location, const sf::Texture& tex);
	money() = default;
	~money() = default;
	
private:
	static bool m_registerit;
};

inline bool money::m_registerit = factory::registerit("money",
	[]() -> std::unique_ptr<Objects> { return std::make_unique<money>(); });