#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include <random>
#include <iostream>
#include <ctime>
#include "factory.h"

class brickGreen  :public StaticObject
{
  public:
	brickGreen(const sf::Vector2f& location, const sf::Texture& tex);
	brickGreen() = default;
	~brickGreen() = default;
  private:
	  static bool m_registerit;
};

inline bool brickGreen::m_registerit = factory::registerit("brickGreen",
	[]() -> std::unique_ptr<Objects> { return std::make_unique<brickGreen>(); });







//class GiftMoney : 
//	public Present {
//
//public:
//	bool handleCollision(Objects& object, Board& board);
//	bool handleCollision(Player& object, Board& board);
//	bool handleCollision(MonsterSmart& object, Board& board);
//	bool handleCollision(MonsterRandomal& object, Board& board);
//	bool handleCollision(Wall& object, Board& board);
//	bool handleCollision(Mot& object, Board& board);
//	bool handleCollision(Money& object, Board& board);
//	bool handleCollision(Ladder& object, Board& board);
//	bool handleCollision(MonsterDirection& object, Board& board);
//private:
//};