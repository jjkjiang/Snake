#ifndef gameStateH
#define gameStateH

#include "State.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/TileMap.h"
#include <stdexcept>

class GameState : public State
{
private:
    TileMap gameMap;
    Snake player1;
    int iterations;
public:
    GameState();
    virtual void update(const sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow& window);
};

#endif
