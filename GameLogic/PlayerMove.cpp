//
// Created by jerry on 2016/04/18.
//

#include "PlayerMove.h"


PlayerMove::PlayerMove() {
    currentDirection = Keyboard::Up;
}

void PlayerMove::checkChangeDirection() {
    if (Keyboard::isKeyPressed(Keyboard::Right) && currentDirection != Keyboard::Left)
        currentDirection = Keyboard::Right;
    if (Keyboard::isKeyPressed(Keyboard::Left) && currentDirection != Keyboard::Right)
        currentDirection = Keyboard::Left;
    if (Keyboard::isKeyPressed(Keyboard::Up) && currentDirection != Keyboard::Down)
        currentDirection = Keyboard::Up;
    if (Keyboard::isKeyPressed(Keyboard::Down) && currentDirection != Keyboard::Up)
        currentDirection = Keyboard::Down;
}

Keyboard::Key PlayerMove::getDirection() {
    return currentDirection;
}