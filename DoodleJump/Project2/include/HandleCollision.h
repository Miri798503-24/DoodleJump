#pragma once
#include <iostream>
#include <typeinfo>
#include "Player.h"
#include "money.h"
#include "Monsters.h"
#include "Objects.h"
#include "Shoot.h"

class HandleCollision
{
public:
	HandleCollision() = default;
	~HandleCollision() = default;
	

private:
};
void processCollision(Objects& object1, Objects& object2);