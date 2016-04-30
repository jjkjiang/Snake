//
// Created by jerry on 2016/04/21.
//

#include "Button.h"
#include "../Definitions/ResolutionVariables.h"

Button::Button() {}

Button::Button(std::string text, sf::Vector2f location, sf::Font& mainFont) {
    buttonBackground.setPosition(location);
    buttonBackground.setSize(sf::Vector2f(buttonSizeX , buttonSizeY));
    buttonBackground.setFillColor(sf::Color::Black);
    buttonBackground.setOutlineColor(sf::Color::White);
    buttonBackground.setOutlineThickness(pixelSizeX);

    location.x += pixelSizeX * 2;
    //location.y += pixelSizeY;
    buttonText.setString(text);
    buttonText.setCharacterSize(yPixels * 4);
    buttonText.setPosition(location);
    buttonText.setFont(mainFont);
    buttonText.setColor(sf::Color::White);
    active = false;
}

bool Button::isActive() {
    return active;
}
void Button::activate() {
    buttonBackground.setOutlineColor(sf::Color(84, 191, 88));
    buttonText.setColor(sf::Color(84, 191, 88));
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