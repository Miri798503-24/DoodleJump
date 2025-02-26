#include"rightState.h"

unique_ptr<State> rightState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// Other code...
		return make_unique<leftState>();
	}
	return NULL;
}

void rightState::enter(Player& player)
{
	//positionPlayer.x += 4;
	player.getSprite().setScale(-1, 1);
	player.setDirection(4);
	
}
