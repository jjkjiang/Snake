#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObjects/Board.h"
#include "GameObjects/Snake.h"
#include "GameLogic/GameState.h"
#include "Definitions/Logic.h"
#include "Definitions/ResolutionVariables.h"

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenResWidth, screenResHeight), "Tilemap");
    sf::RectangleShape square(sf::Vector2f(32,32));
    square.setPosition(borderLeft, borderTop);
    square.setFillColor(sf::Color::Green);

    // define the level with an array of tile indices

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load(gameResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        GameState* gamestate = new GameState;
        //gamestate->draw();
        // draw the map
        window.clear();
        window.draw(map);
        window.draw(square);
        window.display();
    }

    return 0;
}