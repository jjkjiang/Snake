//
// Created by jerry on 2016/04/21.
//

#include "Fruit.h"

sf::Vector2f Fruit::randomPos() {
    int posX = rand() % (borderRight - borderLeft) + pixelSizeX;
    int posY = rand() % (borderBottom - borderTop) + pixelSizeY;
    return sf::Vector2f(poxX, poxY);
}

Fruit::Fruit() {
    fruit.setSize(sf::Vector2f(pixelSizeX, pixelSizeY));
    fruit.setFillColor(sf::Color::Red);
    fruit.setPosition(randomPos());
}

sf::Vector2f Fruit::eatFruit() {
    sf::Vector2f currPos = fruit.getPosition();
    fruit.setPosition(randomPos());
    return currPos;
}

void Fruit::drawFruit(sf::RenderWindow window) {
    window.draw(fruit);
}

sf::Vector2f Fruit::getPos() {
    return fruit.getPosition();
}