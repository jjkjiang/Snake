//
// Created by jerry on 2016/04/21.
//

#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

class Fruit {
private:
    sf::RectangleShape fruit;
public:
    // creates a red "fruit" with random position
    Fruit();
    // changes the current fruit position to a random new position, returns the old location.
    sf::Vector2f eatFruit();
    // draws the current fruit on the window
    void drawFruit(sf::RenderWindow&);
    // returns the position of the fruit
    sf::Vector2f getPos();

private:
    sf::Vector2f randomPos();
};

#endif //SNAKE_FRUIT_H
