#pragma once
#include <SFML/Graphics.hpp>

class Player;
class Board;

class Objects {
public:
	Objects();
	Objects(const sf::Vector2f& location, const sf::Texture& tex);
	
	virtual void draw(sf::RenderWindow& window);
	virtual void setLocation(const sf::Vector2f& location);
	virtual void upData(const sf::Vector2f& location, const sf::Texture& tex);
	virtual void upData(const sf::Texture& tex);
	
	virtual sf::Vector2f getLocation();
	sf::Sprite& getSprite();
	sf::FloatRect objectGlobalBounds() const;
	sf::FloatRect getRect();

protected:
	sf::Sprite m_picture;
};