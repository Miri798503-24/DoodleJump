#include "Board.h"

Board::Board() 
{  
	ResourseManager::instance();
}

void Board::loadFromFile()
{
	int m_x, m_y;
	   
	changeLevel();

	m_scoreText.setFont(ResourseManager::instance().getFont());
	m_scoreText.setCharacterSize(45);
	m_scoreText.setFillColor(sf::Color::Red);

		std::uniform_int_distribution<unsigned> x(0, 500 - 68);
		std::uniform_int_distribution<unsigned> y(100, 700);
		std::default_random_engine e(time(0));
		for (int i = 0; i < 10; i++)
		{
			m_x = x(e);
			m_y = y(e);
			m_posBrick.push_back(sf::Vector2f(m_x, m_y));
			m_brickGreen.push_back(factory::create("brickGreen"));
			m_brickGreen[m_brickGreen.size() - 1]->upData(sf::Vector2f(x(e), y(e)), ResourseManager::instance().getImage("brickGreen"));		
		}	

		for (int i = 0; i < 2; i++)
		{
			m_brickBrown.push_back(factory::create("brickBrown"));
			m_brickBrown[m_brickBrown.size()-1]->upData(sf::Vector2f(x(e), y(e)), ResourseManager::instance().getImage("brickBrown"));
		}
		newMoney();
}

Objects Board::getBrick(int index) const
{
	return *m_brickGreen[index].get();
}

Objects Board::getBrickB(int index) const
{
	return *m_brickBrown[index].get();
}

void Board::MoveAndReset(Player& player)
{
	int m_x, m_y;
	static const int limit = 700 ;

	std::uniform_int_distribution<unsigned> x(0, 500 -68);
	std::uniform_int_distribution<unsigned> y(100, 700);
	std::default_random_engine e(time(0));
	 
	if (player.getY() < 150)
	{
		for (int i = 0; i < m_brickGreen.size(); i++)
		{
			player.setY(150);
			m_posBrick[i].y -= static_cast<int>(player.getdy());

			if (i < m_brickBrown.size())
			{
				m_brickBrown[i]->setLocation(sf::Vector2f{ m_brickBrown[i]->getLocation().x ,m_brickBrown[i]->getLocation().y - static_cast<int>(player.getdy()) });

				if (m_brickBrown[i]->getLocation().y > 700)
				{
					m_posBrown.x = x(e);
					m_posBrown.y = 0;
					m_brickBrown[i]->setLocation(m_posBrown);
				}
			}
			updateLoc(i);

			 if(m_posBrick[i].y > 700)
			{
				m_posBrick[i].x = x(e);
				m_posBrick[i].y = 0;
				updateLoc(i);
			}			 
		}
	}
}

int Board::getvecSize() const
{
	return m_brickGreen.size();
}

int Board::getSizeBrickB() const
{
	return m_brickBrown.size();
}

void Board::updateLoc(int i)
{
	m_brickGreen[i]->setLocation(m_posBrick[i]);
}

void Board::drawScore(sf::RenderWindow& window)
{
	window.draw(m_scoreText);
}

bool Board::isFailure(Player& m_player)
{
	if (m_player.getScore() >= 200* m_numLevel)
	{
		m_numLevel = m_numLevel +1;

		if ( m_numLevel == 4)
		{
			m_massege = "Congratulations :)";
			m_player.resetLife();
			resetBoard();
			return true;
		}
		changeLevel();
		return false;
	}

	if (m_player.getLife() <= 0)
	{
		m_massege = "Game Over :(";
		resetBoard();
		return true;
	}
	return false;
}

string Board::getString() const
{
	return m_massege;
}

void Board::changeLevel()
{
	if(m_numLevel == 1)
	   m_background.setTexture(ResourseManager::instance().getImage("level1"));

	else if (m_numLevel == 2)
		m_background.setTexture(ResourseManager::instance().getImage("level2"));
	else
	m_background.setTexture(ResourseManager::instance().getImage("level3"));
}

int Board::getMoneyVecSize() const
{
	return m_vecMoney.size();
}

Objects Board::getMoney(int index)
{
	return *m_vecMoney[index].get();
}

void Board::erase(int i)
{
	m_vecMoney.erase(m_vecMoney.begin() +i);
}

void Board::eraseB(int i)
{
	m_brickBrown.erase(m_brickBrown.begin() + i);
}

void Board::resetBoard()
{
	 m_brickGreen.clear();
	 m_brickBrown.clear();
	 m_vecMoney.clear();

	
	m_numLevel = 1;
	setScoreT(0);
}

void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	//window.draw(m_scoreText);
	for (int i = 0; i < m_brickGreen.size(); ++i)
	{
		m_brickGreen[i]->setLocation(m_posBrick[i]);
		m_brickGreen[i]->draw(window);
	}

	for (int i = 0; i < m_brickBrown.size(); i++)
		m_brickBrown[i]->draw(window);

	for (int i = 0; i < m_vecMoney.size(); ++i)
		m_vecMoney[i]->draw(window);

	/*for (int i = 0; i < m_brickGreen.size(); ++i)
		m_brickGreen[i]->draw(window);*/
}

void Board::newMoney()
{
	std::uniform_int_distribution<unsigned> x(0, 500 - 68);
	std::uniform_int_distribution<unsigned> y(120, 700);
	std::default_random_engine e(time(0));
	
	for (int i = 0; i <3; i++)
	{
		m_vecMoney.push_back(factory::create("money"));
		m_vecMoney[m_vecMoney.size() - 1]->upData(sf::Vector2f(x(e), y(e)), ResourseManager::instance().getImage("pear"));
	}
}

void Board::setScoreT(int score)
{
	m_scoreText.setString("Score: " + std::to_string(score));
}