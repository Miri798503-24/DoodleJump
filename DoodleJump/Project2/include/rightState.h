#pragma once
#include "State.h"
#include "leftState.h"
#include "Player.h"

class rightState : public State {
public:
	rightState() = default;
	~rightState() = default;

	unique_ptr<State> handleInput();
	virtual void enter(Player& player);
};