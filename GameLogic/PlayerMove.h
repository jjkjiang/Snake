//
// Created by jerry on 2016/04/18.
//

#ifndef SNAKE_PLAYERMOVE_H
#define SNAKE_PLAYERMOVE_H

#include <SFML/Window.hpp>
using namespace sf;

class PlayerMove {
private:
    Keyboard::Key currentDirection;
public:
    PlayerMove();
    void changeDirection();
    Keyboard::Key getDirection();
};

#endif //SNAKE_PLAYERMOVE_H
