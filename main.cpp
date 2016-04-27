#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include "GameObjects/Snake.h"
#include "GameObjects/Fruit.h"
#include "GameStates/StateManager.h"
#include "Definitions/Logic.h"
#include "Definitions/ResolutionVariables.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(screenResWidth, screenResHeight), "Snake");

    // initialize states and a variable to hold the last keyboard press by the user.
    sf::Keyboard::Key press;
    //GameState gameState;
    MenuState menuState;
    //StateManager state;
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
        menuState.update(press);
        menuState.drawState(window);

    //state.update(press);
    //tate.drawState(window);
    }


    return 0;
}
