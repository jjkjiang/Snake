//
// Created by Jerry on 4/21/2016.
//

#include "GameOverState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/TileMapArr.h"

/*
sf::Text yourScore;
sf::Text highScore;
sf::Text letterOne;
sf::Text letterTwo;
sf::Text letterThree;
*/

GameOverState::GameOverState(sf::Font& mainFont) {
    if (!gameOverBg.load(gameOverResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");

    sf::Vector2f restartButtonLocation(screenResWidth / 8, screenResHeight / 2 + buttonSizeY / 2);
    sf::Vector2f returnButtonLocation(restartButtonLocation);
    returnButtonLocation.x += buttonSizeX * 2;
    restartButton = Button("REDO", restartButtonLocation, mainFont);
    returnButton = Button("MENU", returnButtonLocation, mainFont);
    restartButton.activate();

    enteredFirst = false;
    enteredSecond = false;
    enteredThird = false;

    yourScore.setString("100");
    yourScore.setFont(mainFont);
    yourScore.setCharacterSize(pixelSizeX * 2);
    yourScore.setPosition(restartButtonLocation);

    highScore.setString("ABC, 100");
    highScore.setFont(mainFont);
    highScore.setCharacterSize(pixelSizeX * 2);
    highScore.setPosition(returnButtonLocation);

    restartButtonLocation.x += pixelSizeX * 2;
    letterOne.setString("A");
    letterOne.setCharacterSize(pixelSizeX * 2);
    letterOne.setFont(mainFont);
    letterOne.setColor(sf::Color(84, 191, 88));
    letterOne.setPosition(restartButtonLocation);

    restartButtonLocation.x += pixelSizeX * 2;
    letterTwo.setString("A");
    letterTwo.setCharacterSize(pixelSizeX * 2);
    letterTwo.setFont(mainFont);
    letterTwo.setPosition(restartButtonLocation);

    restartButtonLocation.x += pixelSizeX * 2;
    letterThree.setString("A");
    letterThree.setCharacterSize(pixelSizeX * 2);
    letterThree.setFont(mainFont);
    letterThree.setPosition(restartButtonLocation);

    gameOver.setString("GAME OVER");
    gameOver.setFont(mainFont);
    gameOver.setCharacterSize(275);
    gameOver.setPosition(pixelSizeX, pixelSizeY);
}

int GameOverState::update(sf::Keyboard::Key& press) {
    if (!enteredThird) {
        if (press == sf::Keyboard::Up) {
            if (!enteredFirst) {
                convert.str(letterOne.getString());
                char temp = convert.get();
                temp++;
                if (temp > 'Z') temp = 'A';
                convert << temp;
                letterOne.setString(convert.str());
            } else if (!enteredSecond) {
                convert.str(letterTwo.getString());
                char temp = convert.get();
                temp++;
                if (temp > 'Z') temp = 'A';
                convert << temp;
                letterTwo.setString(convert.str());
            } else {
                convert.str(letterThree.getString());
                char temp = convert.get();
                temp++;
                if (temp > 'Z') temp = 'A';
                convert << temp;
                letterThree.setString(convert.str());
            }
            press = sf::Keyboard::Unknown;
        }
        if (press == sf::Keyboard::Down) {
            if (!enteredFirst) {
                convert.str(letterOne.getString());
                char temp = convert.get();
                temp--;
                if (temp < 'A') temp = 'Z';
                convert << temp;
                letterOne.setString(convert.str());
            } else if (!enteredSecond) {
                convert.str(letterTwo.getString());
                char temp = convert.get();
                temp--;
                if (temp < 'A') temp = 'Z';
                convert << temp;
                letterTwo.setString(convert.str());
            } else {
                convert.str(letterThree.getString());
                char temp = convert.get();
                temp--;
                if (temp < 'A') temp = 'Z';
                convert << temp;
                letterThree.setString(convert.str());
            }
        }
        if (press == sf::Keyboard::Return) {
            if (!enteredFirst) {
                enteredFirst = true;
                letterOne.setColor(sf::Color::White);
                letterTwo.setColor(sf::Color(84, 191, 88));
            } else if (!enteredSecond) {
                enteredSecond = true;
                letterTwo.setColor(sf::Color::White);
                letterThree.setColor(sf::Color(84, 191, 88));
            } else {
                enteredThird = true;
                letterThree.setColor(sf::Color::White);
            }
        }
        press = sf::Keyboard::Unknown;
        return 0;
    }


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
    if (!enteredThird) {
        window.draw(letterOne);
        window.draw(letterTwo);
        window.draw(letterThree);
    } else {
        restartButton.drawButton(window);
        returnButton.drawButton(window);
    }
    window.display();
}