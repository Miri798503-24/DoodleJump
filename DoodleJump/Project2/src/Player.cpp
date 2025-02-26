#include "Player.h"
#include "Board.h"

Player::Player(const sf::Vector2f& location, const sf::Texture& tex)
    :MoveObject(location,  tex), m_dy(0.f), m_jumpFlag(true), m_state(std::make_unique<leftState>())
{
	m_picture.setOrigin(m_picture.getGlobalBounds().width /2, m_picture.getGlobalBounds().height/2);
}

void Player::setScore(Board& board)
{

	if (positionPlayer.y == m_height && m_dy < (1.62))
	{
		m_score += 1;
		board.setScoreT(m_score);
	}

}

bool Player::isColid(Objects brick)
{
	if (m_picture.getGlobalBounds().intersects(brick.getRect()) && m_dy>0)
	{
		Jump();		
		return true;
	}
	return false;	
}

void Player::move(Board& board)
{
	handleInput();
		setPosX(getX() + getDirection());

	screenColission();
	changePosition();
	setScore(board);
}

void Player::Jump()
{
	m_jumpFlag = false;
	m_dy = -10;
	setLocation({ positionPlayer.x, positionPlayer.y += static_cast<int>(m_dy) });
}

void Player::changePosition()
{
	setLocation(positionPlayer);
}

float Player::getdy() const
{
	return m_dy;
}

void Player::setY(int num)
{
	positionPlayer.y = num;
}

int Player::getY() const
{
	return positionPlayer.y;
}

int Player::getX() const
{
	return positionPlayer.x;
}

void Player::handleInput()
{		
	unique_ptr<State> state_ = m_state->handleInput();
	if (state_)
	{
		m_state = std::move(state_);
		m_state->enter(*this);
	}
	else
		m_moveFlag = false;
}

void Player::setPosX(int num)
{
	positionPlayer.x = num;
}

void Player::screenColission()
{
	if (positionPlayer.x > 500)
		positionPlayer.x = 0;
	if (positionPlayer.x < -40)
		positionPlayer.x = 500 - 68;

	m_jumpFlag = true;
	m_dy += GRAVITY;
	positionPlayer.y += static_cast<int>(m_dy);

	if (positionPlayer.y > 700 - 68)
	{
		m_jumpFlag = false;
		m_life = 0;
	}
}

void Player::setScore()
{
	m_score += 1;
}

void Player::setLife()
{
	m_life -= 1;
}

int Player::getLife() const
{
	return m_life;
}

int Player::getScore() const
{
	return m_score;
}

sf::Vector2f Player::objectGlobal()
{
	return m_picture.getPosition();
}

void Player::drawLife(sf::RenderWindow& window)
{
	for (int i = 0; i < m_hart.size(); i++)
		m_hart[i]->draw(window);
}

void Player::erase(/*int i*/)
{
	static int i=0 ;
	if(m_hart.size()>=i)
	m_hart.erase(m_hart.begin() + i);

	i++;
}

void Player::newHart()

{
	for (int i = 0; i < 3; i++)
	{
		m_hart.push_back(factory::create("hart"));
		m_hart[m_hart.size() - 1]->upData(sf::Vector2f(350 + 40 * i, 0), ResourseManager::instance().getImage("hart"));
	}
}

int Player::getSize() const
{
	return m_hart.size();
}

void Player::resetLife()
{
	m_life = 4;
	newHart();
}
