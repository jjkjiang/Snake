//
// Created by jerry on 2016/04/21.
//

#include "Fruit.h"
#include "../Definitions/ResolutionVariables.h"

// used to create random positions of the fruit for initialization and resetting
sf::Vector2f Fruit::randomPos() {
    srand(time(0));
    int posX = ((rand() % (xPixels - 2)) + 2) * pixelSizeX;
    int posY = ((rand() % (yPixels - 2)) + 2) * pixelSizeY;
    return sf::Vector2f(posX, posY);
}

// creates a red fruit
Fruit::Fruit() {
    fruit.setSize(sf::Vector2f(pixelSizeX, pixelSizeY));
    fruit.setFillColor(sf::Color::Red);
    fruit.setPosition(randomPos());
}

// resets the fruit to a random position
void Fruit::resetFruit() {
    fruit.setPosition(randomPos());
}

// draws the fruit
void Fruit::drawFruit(sf::RenderWindow& window) {
    window.draw(fruit);
}

// returns the position of the fruit
sf::Vector2f Fruit::getPos() {
    return fruit.getPosition();
}