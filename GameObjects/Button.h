//
// Created by jerry on 2016/04/21.
//

#ifndef SNAKE_BUTTON_H
#define SNAKE_BUTTON_H

#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

// button class that creates a button of resolution variable defined sizes.
// work in progress
class Button {
private:
    sf::RectangleShape buttonBackground;
    sf::Text buttonText;
    bool active;
public:
    Button(const sf::String&, sf::Vector2f);
    bool isActive();
    void activate();
    void deactivate();
    void drawButton(sf::RenderWindow&);
    //bool isInBoundary(const sf::Vector2f&);
};

#endif //SNAKE_BUTTON_H
