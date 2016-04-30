//
// Created by Jerry on 4/21/2016.
//

#ifndef SNAKE_GAMEOVERSTATE_H
#define SNAKE_GAMEOVERSTATE_H

#include <stdexcept>
#include "State.h"
#include "../GameObjects/TileMap.h"
#include "../GameObjects/Button.h"

class GameOverState : public State {
private:
    TileMap gameOverBg;
    sf::Text gameOver;
    Button restartButton;
    Button returnButton;
public:
    GameOverState(sf::Font&);
    virtual int update(sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow&);
};

#endif //SNAKE_GAMEOVERSTATE_H
