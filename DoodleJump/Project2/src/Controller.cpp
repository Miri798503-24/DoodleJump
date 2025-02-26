#include "Controller.h"
#include "factory.h"
#include <stdlib.h>
#include <time.h> 

Controller::Controller()
	:m_window(sf::RenderWindow({ 500, 700 }, "Doodle jump")) , m_player({ 250, 151 }, ResourseManager::instance().getImage("doodle left"))
{
	m_window.setFramerateLimit(60);	
}

void Controller::run()
{
	srand(time(NULL));	
	newMonster();
	m_player.newHart();


			if (m_start.screenStart(m_window, "Welcome to the game"))
			{
				m_board.loadFromFile();
				while (m_window.isOpen())
				{
				while (!m_board.isFailure(m_player))
					{
						sf::Event e;
						if (m_window.pollEvent(e))
						{
							if (e.type == sf::Event::Closed)
								m_window.close();
						}						
						
						//m_music.play();
						m_window.clear(sf::Color::White);
						HandleCollision();
						move();
						
						draw();
						m_board.drawScore(m_window);
						m_window.display();
					}

				if (m_start.screenStart(m_window, m_board.getString()))
					run();	
				}
				
			}
			
}

void Controller::draw()
{
	m_board.draw(m_window);	
	m_player.drawLife(m_window);
	m_player.draw(m_window);
	m_monster->draw(m_window);
}

void Controller::move()
{
	m_player.move(m_board);
	
	m_board.MoveAndReset(m_player);

	for (int i = 0; i < m_board.getvecSize(); i++)
	m_player.isColid(m_board.getBrick(i));

	for (int i = 0; i < m_board.getSizeBrickB(); i++)
		if(m_player.isColid(m_board.getBrickB(i)))
			m_board.eraseB(i);

	m_player.changePosition();	
		m_monster->move();
}

void Controller::newMonster()
{	
	int r = rand() % 4 + 1;
	int x = rand() % (500 - 70);
	int y = rand() % 700 + 100;

	switch (r)
	{
	case 1:
	case 2:
		m_monster = factory::createM("RandMonster");
		m_monster->upData(sf::Vector2f(x, y), ResourseManager::instance().getImage("monster1"));	
		break;

	case 3:
		m_monster = factory::createM("LineMonster");
		m_monster->upData(sf::Vector2f(x, y), ResourseManager::instance().getImage("monster2"));
		break;

	default:
		 m_monster = factory::createM("SmartMonster");
		m_monster->upData(sf::Vector2f(x, y), ResourseManager::instance().getImage("monster3"));	
		break;
	}
}

void Controller::HandleCollision()
{	
		if (m_monster->objectGlobalBounds().contains(m_player.objectGlobal()))
		{
			m_player.erase();
			m_player.setLife();
			//processCollision(m_player, *m_monster);
			m_monster = nullptr;
			newMonster();
		}

	for (int i = 0; i < m_board.getMoneyVecSize(); i++)
		if (m_board.getMoney(i).objectGlobalBounds().contains(m_player.objectGlobal()))
		{
		  // processCollision(m_player, m_board.getMoney(i)); 
			m_board.erase(i);	
			m_player.setLife();
		}		
}
