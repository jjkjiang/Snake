//
// Created by jerry on 2016/04/18.
//

#include "PlayerMove.h"

//
PlayerMove::PlayerMove() {
    currentDirection = Keyboard::Up;
}

// updates direction based on what the current press is
void PlayerMove::setDirection(const sf::Keyboard::Key& curr) {
    if (curr == Keyboard::Right && currentDirection != Keyboard::Left)
        currentDirection = Keyboard::Right;
    if (curr == Keyboard::Left && currentDirection != Keyboard::Right)
        currentDirection = Keyboard::Left;
    if (curr == Keyboard::Up && currentDirection != Keyboard::Down)
        currentDirection = Keyboard::Up;
    if (curr == Keyboard::Down && currentDirection != Keyboard::Up)
        currentDirection = Keyboard::Down;
}

Keyboard::Key PlayerMove::getDirection() {
    return currentDirection;
}