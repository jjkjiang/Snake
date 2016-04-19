#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObjects/TileMap.h"
#include "GameObjects/Snake.h"
#include "GameLogic/GameState.h"
#include "Definitions/Logic.h"
#include "Definitions/ResolutionVariables.h"

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenResWidth, screenResHeight), "Snake");

    // define the level with an array of tile indices

    // create the tilemap from the level definition

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
        gamestate->draw();
        // draw the map
    }

    return 0;
}
