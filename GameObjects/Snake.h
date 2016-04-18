//
// Created by jerry on 2016/04/18.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>

struct SnakeBody {
public:
    sf::RectangleShape shape;
    SnakeBody* next;

    SnakeBody() {
        shape = sf::RectangleShape(sf::Vector2f(32, 32));
        next = 0;
    }
};

struct SnakeHead {
public:
    //shape of the head, i'm deciding on this later.
    SnakeBody* next;

    SnakeHead() {
        //shape of head;
        next = 0;
    }
};

class Snake {
private:
    unsigned size;
    SnakeHead* head;
public:
    // creates a snake head with body of size x.
    Snake();
    ~Snake();

};

#endif //SNAKE_SNAKE_H
