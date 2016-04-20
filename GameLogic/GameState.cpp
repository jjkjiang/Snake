#include "GameState.h"
#include "../Definitions/Logic.h"
#include "../Definitions/ResolutionVariables.h"

GameState::GameState() {
    if (!gameMap.load(gameResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");
    //snake = Snake();
    iterations = 0;
}

void GameState::update(const sf::Keyboard::Key& press) {
    if (iterations == 5000) {
        player1.updateSnake(press);
        iterations = 0;
    }
    iterations++;
}

void GameState::drawState(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(pixelSizeX,pixelSizeY));
    square.setPosition(borderLeft, borderTop);
    square.setFillColor(sf::Color::Green);

    window.clear();
    window.draw(gameMap);
    window.draw(square);
    player1.displaySnake(window);
    //window.display();
}
