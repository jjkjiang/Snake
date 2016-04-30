//
// Created by Jerry on 4/21/2016.
//

#include "GameOverState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/TileMapArr.h"

GameOverState::GameOverState(sf::Font& mainFont) {
    if (!gameOverBg.load(gameOverResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");

    sf::Vector2f playButtonLocation(screenResWidth / 2, screenResHeight / 2 - buttonSizeY / 2);
    sf::Vector2f exitButtonLocation(playButtonLocation);
    exitButtonLocation.x += buttonSizeY * 2;
    restartButton = Button("PLAY", playButtonLocation, mainFont);
    returnButton = Button("MENU", exitButtonLocation, mainFont);

    gameOver.setString("GAME OVER");
    gameOver.setFont(mainFont);
    gameOver.setCharacterSize(700);
    gameOver.setPosition(pixelSizeX, pixelSizeY);
}

int GameOverState::update(sf::Keyboard::Key& press) {


    return 0;
}

void GameOverState::drawState(sf::RenderWindow& window) {
    window.clear();
    window.draw(gameOverBg);
    window.draw(gameOver);
    restartButton.drawButton(window);
    returnButton.drawButton(window);
}