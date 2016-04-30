//
// Created by Jerry on 4/21/2016.
//

#include "GameOverState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/TileMapArr.h"

GameOverState::GameOverState(sf::Font& mainFont) {
    if (!gameOverBg.load(gameOverResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");

    sf::Vector2f restartButtonLocation(screenResWidth / 8, screenResHeight / 2 + buttonSizeY / 2);
    sf::Vector2f returnButtonLocation(restartButtonLocation);
    returnButtonLocation.x += buttonSizeX * 2;
    restartButton = Button("REDO", restartButtonLocation, mainFont);
    returnButton = Button("MENU", returnButtonLocation, mainFont);
    restartButton.activate();

    gameOver.setString("GAME OVER");
    gameOver.setFont(mainFont);
    gameOver.setCharacterSize(275);

    gameOver.setPosition(pixelSizeX, pixelSizeY);
}

int GameOverState::update(sf::Keyboard::Key& press) {
    if (press == sf::Keyboard::Left) {
        if (restartButton.isActive()) {
            restartButton.deactivate();
            returnButton.activate();
        } else if (returnButton.isActive()) {
            returnButton.deactivate();
            restartButton.activate();
        }
        press = sf::Keyboard::Unknown;
    }
    if (press == sf::Keyboard::Right) {
        if (restartButton.isActive()) {
            restartButton.deactivate();
            returnButton.activate();
        } else if (returnButton.isActive()) {
            returnButton.deactivate();
            restartButton.activate();
        }
        press = sf::Keyboard::Unknown;
    }
    if (press == sf::Keyboard::Return) {
        press = sf::Keyboard::Unknown;
        if (restartButton.isActive()) return 2;
        if (returnButton.isActive()) return 4;
    }
    return 0;
}

void GameOverState::drawState(sf::RenderWindow& window) {
    window.clear();
    window.draw(gameOverBg);
    window.draw(gameOver);
    restartButton.drawButton(window);
    returnButton.drawButton(window);
    window.display();
}