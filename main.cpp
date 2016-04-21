#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include "GameObjects/Snake.h"
#include "GameObjects/Fruit.h"
#include "GameLogic/GameState.h"
#include "Definitions/Logic.h"
#include "Definitions/ResolutionVariables.h"

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenResWidth, screenResHeight), "Snake");

    // define the level with an array of tile indices
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(pixelSizeX, pixelSizeY));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100,100);

    // create the tilemap from the level definition

    sf::Keyboard::Key press = sf::Keyboard::Up;
    // run the main loop
    GameState gameState;
    while (window.isOpen())
    {

        // handle events
        sf::Event event;

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                press = event.key.code;
            }
        }
        //window.display();
        gameState.drawState(window);
        window.draw(shape);
        gameState.update(press);
        // draw the map
    }

    return 0;
}
