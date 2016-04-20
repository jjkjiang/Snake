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
    SnakeBody* prev;

    SnakeBody(const sf::Vector2f& position) {
        shape = sf::RectangleShape(sf::Vector2f(pixelSizeX, pixelSizeY));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        next = 0;
        prev = 0;
    }
};

class Snake {
private:
    unsigned size;
    SnakeBody* head;
    SnakeBody* tail;
    // use playermove class to get the direction for snake movement updates
    PlayerMove playerMove;

public:
    // creates a snake head with body of default size x.
    Snake();
    ~Snake();
    // will likely contain a case for
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void updateSnake(const sf::Keyboard::Key&);
    void displaySnake(sf::RenderWindow&);
    // checks for collision with self and borders defined in Definitions/ResolutionVariables.h
    bool collision();
};

#endif //SNAKE_SNAKE_H
