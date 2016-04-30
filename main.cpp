#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include "Definitions/TileMapArr.h"
#include "Definitions/ResolutionVariables.h"
#include "GameLogic/GameEngine.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(screenResWidth, screenResHeight), "Snake");
    sf::Font* mainFont = new sf::Font;
    if (!mainFont->loadFromFile("VTSR.ttf")) {
        throw std::runtime_error("Can't load mainfont");
    }

    // press is a variable that holds the current "button" pressed used for updates
    sf::Keyboard::Key press;
    GameEngine gameEngine;
    gameEngine.init(mainFont);

    while (window.isOpen()) {
        sf::Event event;
        // event loop
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                press = event.key.code;
            }
        }
        gameEngine.update(press);
        gameEngine.drawState(window);
    }


    return 0;
}
