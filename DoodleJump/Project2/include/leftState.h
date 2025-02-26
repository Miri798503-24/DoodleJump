#pragma once
#include "State.h"
#include "rightState.h"
#include "Player.h"

class leftState : public State {
public:
	leftState() = default;
	~leftState() = default;

	unique_ptr<State> handleInput();
	
	virtual void enter(Player& player);
};