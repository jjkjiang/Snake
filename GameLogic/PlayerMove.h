//
// Created by jerry on 2016/04/18.
//

#ifndef SNAKE_PLAYERMOVE_H
#define SNAKE_PLAYERMOVE_H

#include <SFML/Window.hpp>
using namespace sf;

// this class stores a key direction so that the snake can be constantly updated based on the last direction and any
// inputs, this also limits movement so that the player cannot flip its movement into itself.
class PlayerMove {
private:
    Keyboard::Key currentDirection;
public:
    PlayerMove();
    void setDirection(const sf::Keyboard::Key&);
    Keyboard::Key getDirection();
};

#endif //SNAKE_PLAYERMOVE_H
