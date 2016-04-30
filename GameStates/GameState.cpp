#include "GameState.h"

// initalizes the tilemap for the game.
GameState::GameState(sf::Font& mainFont) {
    if (!gameMap.load(gameResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");
    updateTime = 0.5;

    scoreCounter.setPosition(borderRight + pixelSizeX + pixelSizeX / 2, pixelSizeY);
    scoreCounter.setCharacterSize(25);
    scoreCounter.setFont(mainFont);
    scoreCounter.setString("Score: 0");

    controlHeader.setPosition(borderRight + pixelSizeX + pixelSizeX / 2, 3 * pixelSizeY);
    controlHeader.setCharacterSize(25);
    controlHeader.setFont(mainFont);
    controlHeader.setString("Controls:");

    movementHeader.setPosition(borderRight + pixelSizeX + pixelSizeX / 2, 4 * pixelSizeY);
    movementHeader.setCharacterSize(25);
    movementHeader.setFont(mainFont);
    movementHeader.setString(" Movement");

    speedHeader.setPosition(borderRight + pixelSizeX + pixelSizeX / 2, 14 * pixelSizeY);
    speedHeader.setCharacterSize(25);
    speedHeader.setFont(mainFont);
    speedHeader.setString("  Speed");

    if (!controlsTexture.loadFromFile("res/controls.png"))
        throw std::runtime_error("Could not load controls.png");
    controls.setTexture(controlsTexture);
    controls.setPosition(borderRight + pixelSizeX, 4 * pixelSizeY);
}

// updates the game's status by moving forward the snake, detecting if the snake has hit the wall
// changes the speed of the snake based on 1, 2, 3.
int GameState::update(sf::Keyboard::Key& press, ScoreBoard* scoreBoard) {
    if (press == sf::Keyboard::Num1) {
        updateTime = 0.5;
    } else if (press == sf::Keyboard::Num2) {
        updateTime = 0.2;
    } else if (press == sf::Keyboard::Num3) {
        updateTime = 0.1;
    }

    if (gameClock.getElapsedTime().asSeconds() >= updateTime) {
        int result = player1.updateSnake(press, player1Fruit.getPos());
        if (result == 1) {
            scoreCounter.setString(player1.getScore());
            player1Fruit.resetFruit();
        } else if (result == 2) {
            // player crashed into something - game ends
            std::stringstream convert;
            convert.str(", ");
            convert << player1.getScore();
            scoreBoard->setLastScore(convert.str());
            return 3;
        }
        gameClock.restart();
    }

    return 0;
}

// clears the screen (so if the previous screen was a menu, that will be cleared), draws the background,
// draws the fruit and then draws the snake.
void GameState::drawState(sf::RenderWindow& window) {
    window.clear();
    window.draw(gameMap);
    window.draw(controls);
    window.draw(scoreCounter);
    window.draw(controlHeader);
    window.draw(speedHeader);
    window.draw(movementHeader);
    player1Fruit.drawFruit(window);
    player1.displaySnake(window);
    window.display();
}
