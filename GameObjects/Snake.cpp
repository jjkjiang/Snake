//
// Created by jerry on 2016/04/18.
//

#include "Snake.h"

// constructs a snake of size 8 moving upwards to start
Snake::Snake() {
    size = 8;
    head = new SnakeBody(sf::Vector2f(20 * pixelSizeX, 12 * pixelSizeY), playerMove.getDirection());
    tail = head;
    for (unsigned i = 1; i < size; i++) {
        Vector2f nextPos = head->shape.getPosition();
        nextPos.y -= pixelSizeY;
        SnakeBody* nextBody = new SnakeBody(nextPos, playerMove.getDirection());
        head->prev = nextBody;
        nextBody->next = head;
        head = nextBody;
    }

    headShape.setRadius((pixelSizeX / 2) - 10);
    headShape.setFillColor(sf::Color::Black);
    headShape.setPosition(head->shape.getPosition());
    playerMove = PlayerMove();
}

// deconstructor
Snake::~Snake() {
    SnakeBody* curr = head;
    while (curr != 0) {
        SnakeBody* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = 0;
    tail = 0;
}

// moves the snake by adding a new head and deleting the tail
// this is more efficient than moving each part of the snake
void Snake::moveDir(const Vector2f& nextPos) {
    SnakeBody* nextBody = new SnakeBody(nextPos, playerMove.getDirection());
    head->prev = nextBody;
    nextBody->next = head;
    head = nextBody;
    SnakeBody* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = 0;
}

// moves the snake in accordance to eating a fruit by moving but not deleting
// and updating the tail
void Snake::eatFruit(const Vector2f& nextPos) {
    SnakeBody* nextBody = new SnakeBody(nextPos, playerMove.getDirection());
    head->prev = nextBody;
    nextBody->next = head;
    head = nextBody;
    size++;
}

// updates the snake by checking for changes in direction before getting the direction,
// and determines if the snake is colliding into something, moving or eating a fruit
int Snake::updateSnake(const sf::Keyboard::Key& dir, sf::Vector2f fruitPos) {
    playerMove.setDirection(dir);
    // what's worse, creating a new temporary movementDir everytime or calling getDirection 4x?
    sf::Keyboard::Key movementDir = playerMove.getDirection();

    if (collision()) {
        //do something idk yet
        return 2;
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

    if (nextPos == fruitPos) {
        eatFruit(nextPos);
        return 1;
    } else {
        moveDir(nextPos);
    }
    return 0;
}

// draws the whole snake
void Snake::displaySnake(sf::RenderWindow& window) {
    for (SnakeBody* i = head; i != 0; i = i->next) {
        window.draw(i->shape);
    }
    headShape.setPosition(head->shape.getPosition());
    window.draw(headShape);
}

// checks if the snake collides into itself or the borders
bool Snake::collision() {
    sf::Vector2f currPos = head->shape.getPosition();
    if (currPos.x >= borderRight ||
        currPos.x <= borderLeft ||
        currPos.y >= borderBottom ||
        currPos.y <= borderTop) {
        return true;
    }

    for (SnakeBody* i = head->next; i != 0; i = i->next) {
        if (currPos == i->shape.getPosition()) {
            return true;
        }
    }

    return false;
}