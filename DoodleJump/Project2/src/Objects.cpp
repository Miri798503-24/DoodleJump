#include "Objects.h"
#include "Player.h"
//#include "MonsterSmart.h"
//#include "MonsterRandomal.h"
//#include "MonsterDirection.h"
#include "Board.h"

Objects::Objects() {}

Objects::Objects(const sf::Vector2f& location,  const sf::Texture& tex)
{
    m_picture.setPosition(location);
    m_picture.setTexture(tex);
}

void Objects::draw(sf::RenderWindow& window)
{
    window.draw(m_picture);
}

void Objects::setLocation(const sf::Vector2f& location)
{
    m_picture.setPosition(location);
}

void Objects::upData(const sf::Vector2f& location, const sf::Texture& tex)
{
    m_picture.setPosition(location);
    m_picture.setTexture(tex);
  
}

void Objects::upData(const sf::Texture& tex)
{
    m_picture.setTexture(tex);
}

sf::Vector2f Objects::getLocation()
{
    return m_picture.getPosition();
}

sf::Sprite& Objects::getSprite()
{
    return m_picture;
}

sf::FloatRect Objects::objectGlobalBounds() const
{
    return  m_picture.getGlobalBounds();
}

sf::FloatRect Objects::getRect()
{
    return m_picture.getGlobalBounds();
}

