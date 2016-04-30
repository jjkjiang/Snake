#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include "StateManager.h"
#include "State.h"
#include "../GameObjects/Fruit.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/TileMap.h"
#include "../Definitions/TileMapArr.h"
#include "../Definitions/ResolutionVariables.h"
#include <stdexcept>

// this state will be primarily for the snake game itself
class GameState : public State
{
private:
    Fruit player1Fruit;
    TileMap gameMap;
    Snake player1;
    Clock gameClock;
    float updateTime;
public:
    GameState();
    virtual int update(sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow&);
};

#endif
