#include "MenuState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/TileMapArr.h"

MenuState::MenuState(sf::Font& mainFont) {
    if (!menuBg.load(menuResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");

    sf::Vector2f playButtonLocation(screenResWidth / 2 - buttonSizeX / 2, screenResHeight / 2 - buttonSizeY / 2);
    sf::Vector2f exitButtonLocation(playButtonLocation);
    exitButtonLocation.y += buttonSizeY * 2;
    playButton = Button("PLAY", playButtonLocation, mainFont);
    exitButton = Button("EXIT", exitButtonLocation, mainFont);
    playButton.activate();

    introText.setString("SNAKE!");
    introText.setColor(sf::Color(84, 191, 88));
    introText.setPosition(screenResWidth / 2 - buttonSizeX + pixelSizeX, screenResHeight / 2 - 3 * buttonSizeY);
    introText.setCharacterSize(210);
    introText.setFont(mainFont);
    //buttonArr[0] = playButton;
    //buttonArr[1] = exitButton;
    //arrSize = 2;
    //activeIndex = 0;
    //snakeLogo;
}
void MenuState::update(sf::Keyboard::Key& press) {
    if (press == sf::Keyboard::Down) {
        if (playButton.isActive()) {
            playButton.deactivate();
            exitButton.activate();
        } else if (exitButton.isActive()) {
            exitButton.deactivate();
            playButton.activate();
        }
        press = sf::Keyboard::Left;
    }
    if (press == sf::Keyboard::Up) {
        if (playButton.isActive()) {
            playButton.deactivate();
            exitButton.activate();
        } else if (exitButton.isActive()) {
            exitButton.deactivate();
            playButton.activate();
        }
        press = sf::Keyboard::Left;
    }
    if (press == sf::Keyboard::Return) {
        if (activeIndex == 0); //play game
        if (activeIndex == 1); //exit game
    }
}

void MenuState::drawState(sf::RenderWindow& window) {
    window.clear();
    window.draw(menuBg);
    playButton.drawButton(window);
    exitButton.drawButton(window);
    window.draw(introText);
    window.display();
}