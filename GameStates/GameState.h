#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

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
    sf::Text scoreCounter;
    sf::Text controlHeader;
    sf::Text movementHeader;
    sf::Text speedHeader;
    sf::Texture controlsTexture;
    sf::Sprite controls;
public:
    GameState(sf::Font&);
    virtual int update(sf::Keyboard::Key&, ScoreBoard*);
    virtual void drawState(sf::RenderWindow&);
};

#endif
