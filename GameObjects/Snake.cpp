//
// Created by jerry on 2016/04/18.
//

#include "Snake.h"

Snake::Snake() {
    size = 10;
    head = new SnakeBody(sf::Vector2f(20 * pixelSizeX, 12 * pixelSizeY));
    tail = head;
    for (unsigned i = 1; i < size; i++) {
        Vector2f nextPos = head->shape.getPosition();
        nextPos.y -= pixelSizeY;
        SnakeBody* nextBody = new SnakeBody(nextPos);
        head->prev = nextBody;
        nextBody->next = head;
        head = nextBody;
    }

    headShape.setRadius((pixelSizeX / 2) - 10);
    headShape.setFillColor(sf::Color::Black);
    headShape.setPosition(head->shape.getPosition());
    playerMove = PlayerMove();
}

Snake::~Snake() {
    delete head;
}

void Snake::moveDir(const Vector2f& nextPos) {
    SnakeBody* nextBody = new SnakeBody(nextPos);
    head->prev = nextBody;
    nextBody->next = head;
    head = nextBody;
    SnakeBody* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = 0;
}

void Snake::updateSnake(const sf::Keyboard::Key& dir) {
    playerMove.setDirection(dir);
    // what's worse, creating a new movementDir everytime or calling getDirection 4x?
    sf::Keyboard::Key movementDir = playerMove.getDirection();

    if (collision()) {
        //do something idk yet
        return;
    }
    Vector2f nextPos = head->shape.getPosition();
    if (movementDir == sf::Keyboard::Up) {
        nextPos.y -= pixelSizeY;
    }
    if (movementDir == sf::Keyboard::Down) {
        nextPos.y += pixelSizeY;
    }
    if (movementDir == sf::Keyboard::Left) {
        nextPos.x -= pixelSizeX;
    }
    if (movementDir == sf::Keyboard::Right) {
        nextPos.x += pixelSizeX;
    }

    moveDir(nextPos);
}

void Snake::displaySnake(sf::RenderWindow& window) {
    for (SnakeBody* i = head; i != 0; i = i->next) {
        window.draw(i->shape);
    }
    headShape.setPosition(head->shape.getPosition());
    window.draw(headShape);
}

bool Snake::collision() {
    return false;
}