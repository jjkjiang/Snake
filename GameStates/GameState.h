#ifndef gameStateH
#define gameStateH

#include "StateManager.h"
#include "State.h"
#include "../GameObjects/Fruit.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/TileMap.h"
#include "../Definitions/Logic.h"
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
    virtual void update(const sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow& window);
};

#endif
