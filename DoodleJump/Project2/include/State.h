#pragma once
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
class Player;

enum Input
{
	PRESS_LEFT,
	PRESS_RIGHT
};

class State
{
public:
	State() = default;
	virtual ~State() { }
	//virtual unique_ptr<State>handleInput(Input input) = 0;
	virtual void enter(Player& player) = 0;
	virtual unique_ptr<State>handleInput() = 0;
private:

};
