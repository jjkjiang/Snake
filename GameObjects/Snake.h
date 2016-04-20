//
// Created by jerry on 2016/04/18.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include "../GameLogic/PlayerMove.h"
#include "../Definitions/ResolutionVariables.h"

struct SnakeBody {
public:
    sf::RectangleShape shape;
    //sf::Keyboard::Key dir;
    SnakeBody* next;

    SnakeBody(const sf::Vector2f& position) {
        shape = sf::RectangleShape(sf::Vector2f(pixelSizeX, pixelSizeY));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        next = 0;
    }
};

struct SnakeHead {
public:
    sf::RectangleShape shape;
    //sf::Keyboard::Key dir;
    SnakeBody* next;

    SnakeHead(const sf::Vector2f& position) {
        shape = sf::RectangleShape(sf::Vector2f(pixelSizeX, pixelSizeY));
        shape.setFillColor(sf::Color::Green);
        //shape.setPosition(position);
        next = 0;
    }
};

class Snake {
private:
    unsigned size;
    SnakeHead* head;
    // use playermove class to get the direction for snake movement updates

public:
    // creates a snake head with body of default size x.
    Snake();
    ~Snake();
    // will likely contain a case for
    void updateSnake(const sf::Keyboard::Key&);
    void displaySnake(sf::RenderWindow&);
    // checks for collision with self and borders defined in Definitions/ResolutionVariables.h
    void checkCollision();
};

#endif //SNAKE_SNAKE_H
