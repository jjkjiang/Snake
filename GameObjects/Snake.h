//
// Created by jerry on 2016/04/18.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include "../GameLogic/PlayerMove.h"
#include "../Definitions/ResolutionVariables.h"

// makes up the body of the snake, dir will be used to calculate the physics of pong balls later on.
struct SnakeBody {
public:
    sf::RectangleShape shape;
    sf::Keyboard::Key dir;
    SnakeBody* next;
    SnakeBody* prev;

    SnakeBody(const sf::Vector2f& position, const sf::Keyboard::Key dir) {
        shape = sf::RectangleShape(sf::Vector2f(pixelSizeX, pixelSizeY));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        next = 0;
        prev = 0;
        this->dir = dir;
    }
};

// snake class that represents the player in snake
class Snake {
private:
    unsigned size;
    SnakeBody* head;
    SnakeBody* tail;
    // use playermove class to get the direction for snake movement updates
    PlayerMove playerMove;
    sf::CircleShape headShape;

public:
    // creates a snake head with body of default size x.
    Snake();
    ~Snake();
    void moveDir(const Vector2f&);
    void eatFruit(const Vector2f&);
    // returns 1 if a fruit was encountered, 2 if you collide, 0 otherwise.
    int updateSnake(const sf::Keyboard::Key&, sf::Vector2f);
    void displaySnake(sf::RenderWindow&);
    // checks for collision with self and borders defined in Definitions/ResolutionVariables.h
    bool collision();
};

#endif //SNAKE_SNAKE_H
