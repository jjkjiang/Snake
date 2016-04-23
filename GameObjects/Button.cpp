//
// Created by jerry on 2016/04/21.
//

#include "Button.h"
#include "../Definitions/ResolutionVariables.h"

Button::Button(const sf::String& text, sf::Vector2f location) {
    buttonBackground.setPosition(location);
    buttonBackground.setSize(sf::Vector2f(buttonSizeX , buttonSizeY));
    buttonBackground.setFillColor(sf::Color::Black);
    buttonBackground.setOutlineColor(sf::Color::White);
    buttonBackground.setOutlineThickness(pixelSizeX);

    location.x -= pixelSizeX;
    location.y -= pixelSizeY;
    buttonText.setString(text);
    buttonText.setPosition(location);
    buttonText.setColor(sf::Color::White);
}

bool Button::isActive() {
    return active;
}
void Button::activate() {
    buttonBackground.setOutlineColor(sf::Color::Green);
    buttonText.setColor(sf::Color::Green);
    active = true;
}
void Button::deactivate() {
    buttonBackground.setOutlineColor(sf::Color::White);
    buttonText.setColor(sf::Color::White);
    active = false;
}
void Button::drawButton(sf::RenderWindow& window) {
    window.draw(buttonBackground);
    window.draw(buttonText);
}

// for future use if we allow mouse
/*
bool Button::isInBoundary(const sf::Vector2f& location) {
    if (location.x < buttonBackground.getPosition().x ||
        location.x > buttonBackground.getPosition().x + buttonSizeX ||
        location.y < buttonBackground.getPosition().y ||
        location.y > buttonBackground.getPosition().x + buttonSizeY) {
        return false;
    }

    return true;
}
 */