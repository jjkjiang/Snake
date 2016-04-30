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
    // initialize states and a variable to hold the last keyboard press by the user.
    sf::Keyboard::Key press;
    //GameState gameState;
    //MenuState menuState(mainFont);
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
        // // //draws objects then updates
        //gameState.update(press);
        //gameState.drawState(window);
        gameEngine.update(press);
        gameEngine.drawState(window);

    //state.update(press);
    //tate.drawState(window);
    }


    return 0;
}
