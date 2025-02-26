#include "GameStart.h"

GameStart::GameStart()
{
	m_buttonStart.setPosition({ 220, 220 });
	m_buttonStart.setTexture(ResourseManager::instance().getImage("play butoon"));

	m_buttonEnd.setPosition({ 220, 350 });
	m_buttonEnd.setTexture(ResourseManager::instance().getImage("cancel-button"));

	m_headLine.setPosition({ 70 , 120 });
	m_headLine.setFont(ResourseManager::instance().getFont());
	m_headLine.setCharacterSize(50);
	m_headLine.setColor(sf::Color::Red);

	m_backround.setTexture(ResourseManager::instance().getImage("doodle"));

}

bool GameStart::screenStart(sf::RenderWindow& window, const std::string& headLine)
{
	setHeadLine(headLine);
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		if (events(window))
			return true;

		draw(window);
		window.display();
	}
	return false;
}

bool GameStart::events(sf::RenderWindow& window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(EXIT_SUCCESS);
			break;

		case sf::Event::MouseButtonPressed:
			if (clickButton(window, event) == 0)
			{
				window.close();
				exit(EXIT_SUCCESS);
				return false;
			}

			if (clickButton(window, event) == 1)
				return true;
			break;
		}
	}
	return false;
}

int GameStart::clickButton(sf::RenderWindow& window, sf::Event event)
{
	if (m_buttonStart.getGlobalBounds().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
		return 1;

	if (m_buttonEnd.getGlobalBounds().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
		return 0;

	return 2;
}

void GameStart::draw(sf::RenderWindow& window)
{
	window.draw(m_backround);
	window.draw(m_headLine);
	window.draw(m_buttonStart);
	window.draw(m_buttonEnd);
}

void GameStart::setHeadLine(const std::string& headLine)
{
	m_headLine.setString(headLine);
}
