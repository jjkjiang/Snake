//
// Created by Jerry on 4/21/2016.
//

#ifndef SNAKE_GAMEOVERSTATE_H
#define SNAKE_GAMEOVERSTATE_H

#include <stdexcept>
#include <sstream>
#include "State.h"
#include "../GameObjects/TileMap.h"
#include "../GameObjects/Button.h"

class GameOverState : public State {
private:
    //databasething* database
    std::stringstream convert;
    std::stringstream name;
    TileMap gameOverBg;
    sf::Text gameOver;
    sf::Text yourScore;
    sf::Text highScore;
    sf::Text letterOne;
    sf::Text letterTwo;
    sf::Text letterThree;
    Button restartButton;
    Button returnButton;
    bool enteredFirst;
    bool enteredSecond;
    bool enteredThird;
public:
    GameOverState(sf::Font&, ScoreBoard*);
    int updateNameEntry(sf::Keyboard::Key&, ScoreBoard*);
    virtual int update(sf::Keyboard::Key&, ScoreBoard*);
    virtual void drawState(sf::RenderWindow&);
};

#endif //SNAKE_GAMEOVERSTATE_H
