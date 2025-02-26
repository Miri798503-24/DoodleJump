#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML\Audio.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "ResourseManager.h"
#include "StaticObject.h"
#include "MoveObject.h"
#include "Player.h"
#include "ResourseManager.h"
#include "brickGreen.h"
#include "brickBrown.h"
#include "money.h"
#include "Objects.h"

class Board {
public:
	Board();
	~Board() {}
	
	void draw(sf::RenderWindow& window);
	void newMoney();
	void setScoreT(int score);
	void loadFromFile();
	Objects getBrick(int index) const;
	Objects getBrickB(int index) const;
	void MoveAndReset(Player& player);
	int getvecSize() const;
	int getSizeBrickB() const;
	void updateLoc(int i);
	void drawScore(sf::RenderWindow& window);
	bool isFailure(Player& m_player);
	string getString()const;
	void changeLevel();
	int getMoneyVecSize() const;
	Objects getMoney(int index);
	void erase(int i);
	void eraseB(int i);
	void resetBoard();

private:
	std::vector<sf::Vector2f> m_posBrick;

	sf::Vector2f m_posBrown;
	sf::Text m_scoreText;
	sf::Sprite m_background;
	std::vector<std::unique_ptr<Objects>> m_brickGreen;
	std::vector<std::unique_ptr<Objects>> m_brickBrown;
	std::vector<std::unique_ptr<Objects>> m_vecMoney;
	std::string m_massege;
	int m_numLevel = 1;
};