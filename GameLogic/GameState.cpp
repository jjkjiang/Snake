#include "GameState.h"

GameState::GameState() {
    if (!gameMap.load(gameResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw runtime_error("Failed to load the tilemap probably because file was not found.");
    snake = Snake();
}

void GameState::update() {

}

void GameState::draw(sf::RenderWindow window) {
    sf::RectangleShape square(sf::Vector2f(pixelSizeX,pixelSizeY));
    square.setPosition(borderLeft, borderTop);
    square.setFillColor(sf::Color::Green);

    window.clear();
    window.draw(map);
    window.draw(square);
    window.display();
}