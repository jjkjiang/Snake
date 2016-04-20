//
// Created by jerry on 2016/04/18.
//

#include "Snake.h"

Snake::Snake() {
    size = 5;
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

    playerMove = PlayerMove();
}

Snake::~Snake() {
    delete head;
}

void Snake::moveRight() {
    if (collision()) return;
    Vector2f nextPos = head->shape.getPosition();
    nextPos.x += pixelSizeX;
    SnakeBody* nextBody = new SnakeBody(nextPos);
    head->prev = nextBody;
    nextBody->next = head;
    head = nextBody;
    SnakeBody* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = 0;
}
void Snake::moveLeft() {
    if (collision()) return;
    Vector2f nextPos = head->shape.getPosition();
    nextPos.x -= pixelSizeX;
    SnakeBody* nextBody = new SnakeBody(nextPos);
    head->prev = nextBody;
    nextBody->next = head;
    head = nextBody;
    SnakeBody* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = 0;
}
void Snake::moveUp() {
    if (collision()) return;
    Vector2f nextPos = head->shape.getPosition();
    nextPos.y -= pixelSizeY;
    SnakeBody* nextBody = new SnakeBody(nextPos);
    head->prev = nextBody;
    nextBody->next = head;
    head = nextBody;
    SnakeBody* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = 0;
}
void Snake::moveDown() {
    if (collision()) return;
    Vector2f nextPos = head->shape.getPosition();
    nextPos.y += pixelSizeY;
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

    if (movementDir == sf::Keyboard::Up) {
        moveUp();
    }
    if (movementDir == sf::Keyboard::Down) {
        moveDown();
    }
    if (movementDir == sf::Keyboard::Left) {
        moveLeft();
    }
    if (movementDir == sf::Keyboard::Right) {
        moveRight();
    }
}

void Snake::displaySnake(sf::RenderWindow& window) {
    for (SnakeBody* i = head; i != 0; i = i->next) {
        window.draw(i->shape);
    }
}

bool Snake::collision() {
    return false;
}