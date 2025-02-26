#include "leftState.h"

unique_ptr<State> leftState::handleInput()
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// Other code...
			return std::make_unique<rightState>();
		}
		return NULL;        // Stay in this state.
}

void leftState::enter(Player& player)
{
	//positionPlayer.x -= 4;
	player.getSprite().setScale(1, 1);
	player.setDirection(-4);
	
}
