#pragma once
#include <SFML/Graphics.hpp>
#include "MoveObject.h"
#include <vector>
#include <memory>
#include <cstdio>
#include "brickGreen.h"
#include "State.h"
#include "rightState.h"
#include "leftState.h"
#include <SFML\Audio.hpp>
#include "Board.h"
#include "StaticObject.h"
#include "hart.h"
#include "Objects.h"
#include "factory.h"

static const float GRAVITY = 0.2f;
class Board;
class Player : 
	public MoveObject 
{
public:
	Player(const sf::Vector2f& location, const sf::Texture& tex);
	Player() = default;
	~Player() = default;
	void setScore(Board& board);
	bool isColid(Objects brick);
	void move(Board& board);
	void Jump();
	void changePosition();
	float getdy() const;
	void setY(int num);
	int getY() const;
	int getX() const;
	virtual void handleInput();
	void setPosX(int num);
	void setDirection(int dir) { m_direction = dir; }
	int getDirection()const { return m_direction; }
	void screenColission();
	void setScore();
	void setLife();
	int getLife()const;
	int getScore()const;
	sf::Vector2f objectGlobal();
	void drawLife(sf::RenderWindow& window);
	void erase();
	void newHart();
	int getSize() const;
	void resetLife();

private:
	int m_direction=-4;
	float m_dy =0;
	int m_height = 150;
	int m_score = 0;
	int m_life = 4;
	bool m_jumpFlag = true;
	bool m_moveFlag = true;
	brickGreen m_brickG;
	unique_ptr<State> m_state;
	sf::Vector2f positionPlayer = {250, 151};
	std::vector<std::unique_ptr<Objects>> m_hart;
};