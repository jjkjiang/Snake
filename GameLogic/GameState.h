#ifndef gameStateH
#define  gameStateH

#include "State.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/TileMap.h"
#include <stdexcept>

class GameState : public State
{
private:
    Tilemap gameMap;
    Snake player1;
public:
    GameState();
    virtual void update();
    virtual void draw();
};

#endif
