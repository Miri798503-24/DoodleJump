#pragma once
#include <SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
#include "Board.h"
#include "Player.h"
#include "GameStart.h"
#include "Monsters.h"
#include "HandleCollision.h"
#include "Objects.h"

class Controller
{
public:
    Controller();
    ~Controller() = default;
    
    void run();
    void draw();
    void move();
    void newMonster();
    void HandleCollision();

private:
  
    Board m_board;
    Player m_player;
    GameStart m_start;
    sf::RenderWindow m_window;
    std::unique_ptr<Monsters> m_monster;
};
