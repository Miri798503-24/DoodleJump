#pragma once
#include <SFML/Graphics.hpp>
#include "ResourseManager.h"

class GameStart
{
public:
	GameStart();
	~GameStart() = default;
	bool screenStart(sf::RenderWindow& window, const std::string& headLine);
	bool events(sf::RenderWindow& window);

	int clickButton(sf::RenderWindow& window, sf::Event event);

	void draw(sf::RenderWindow& window);
	void setHeadLine(const std::string& headLine);

private:

	sf::Sprite m_buttonStart;
	sf::Sprite m_buttonEnd;
	sf::Sprite m_backround;
	
	sf::Text m_headLine;

};