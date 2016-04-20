//
// Created by jerry on 2016/04/18.
//

#include "Snake.h"

Snake::Snake() {
    size = 1;
    head = new SnakeHead(sf::Vector2f(20 * pixelSizeX, 12 * pixelSizeY));
}

Snake::~Snake() {
    delete head;
}

void Snake::updateSnake(const sf::Keyboard::Key& dir) {
    if (dir == sf::Keyboard::Up)
        (head->shape).move(0, pixelSizeY);
    if (dir == sf::Keyboard::Down)
        (head->shape).move(0, -pixelSizeY);
    if (dir == sf::Keyboard::Left)
        (head->shape).move(-pixelSizeX, 0);
    if (dir == sf::Keyboard::Right)
        (head->shape).move(pixelSizeX, 0);

    (head->shape).move(5,5);
}
void Snake::displaySnake(sf::RenderWindow& window) {
    window.draw(head->shape);
}