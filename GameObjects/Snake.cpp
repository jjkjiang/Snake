//
// Created by jerry on 2016/04/18.
//

#include "Snake.h"

Snake::Snake() {
    size = 1;
    head = new SnakeHead(sf::Vector2f(20 * pixelSizeX, 8 * pixelSizeY));
    playerMove;
}

Snake::~Snake() {
    delete head;
}

void Snake::updateSnake() {
    playerMove.checkChangeDirection();
    sf::Keyboard::Key dir = playerMove.getDirection();
    if (dir == sf::Keyboard::Up) (head->shape).move(0, pixelSizeY);
    if (dir == sf::Keyboard::Down) (head->shape).move(0, -pixelSizeY);
    if (dir == sf::Keyboard::Left) (head->shape).move(-pixelSizeX, 0);
    if (dir == sf::Keyboard::Right) (head->shape).move(pixelSizeX, 0);
}
void Snake::displaySnake(sf::RenderWindow& window) {
    sf::RectangleShape curr = head->shape;
    window.draw(curr);
}