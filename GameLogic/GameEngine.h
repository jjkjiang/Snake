//
// Created by jerry on 2016/04/29.
//

#ifndef SNAKE_GAMEENGINE_H
#define SNAKE_GAMEENGINE_H

#include <stack>
#include <cstdlib>
#include "../GameStates/State.h"
#include "../GameStates/MenuState.h"
#include "../GameStates/GameState.h"
#include "ScoreBoard.h"

class GameEngine {
private:
    sf::Font* mainFont;
    std::stack<State*> game;
    ScoreBoard* scoreBoard;
public:
    GameEngine(sf::Font*);
    void init();
    void update(sf::Keyboard::Key&);
    void drawState(sf::RenderWindow&);
};

#endif //SNAKE_GAMEENGINE_H
