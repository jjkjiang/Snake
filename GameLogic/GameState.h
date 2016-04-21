#ifndef gameStateH
#define gameStateH

#include "State.h"
#include "../GameObjects/Fruit.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/TileMap.h"
#include "../Definitions/Logic.h"
#include "../Definitions/ResolutionVariables.h"
#include <stdexcept>

class GameState : public State
{
private:
    Fruit player1Fruit;
    TileMap gameMap;
    Snake player1;
    Clock gameClock;
public:
    GameState();
    virtual void update(const sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow& window);
};

#endif
