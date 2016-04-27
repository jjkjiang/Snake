#include "MenuState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/Logic.h"

MenuState::MenuState() : playButton("PLAY", sf::Vector2f(pixelSizeX * (screenResWidth / 2), pixelSizeY * (screenResHeight/2))),
                         exitButton("EXIT", sf::Vector2f(pixelSizeX * (screenResWidth / 2), pixelSizeY * (screenResHeight/2) + (pixelSizeY * 6))) {
    if (!menuBg.load(menuResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");

    playButton.activate();
    buttonArr[0] = playButton;
    buttonArr[1] = exitButton;
    arrSize = 2;
    activeIndex = 0;
    //snakeLogo;
}
void MenuState::update(sf::Keyboard::Key& press) {
    if (press == sf::Keyboard::Down) {
        buttonArr[activeIndex].deactivate();
        activeIndex = (activeIndex + 1) % arrSize;
        buttonArr[activeIndex].activate();
        press = sf::Keyboard::Left;
    }
    if (press == sf::Keyboard::Down) {
        buttonArr[activeIndex].deactivate();
        activeIndex = (activeIndex + 1) % arrSize;
        buttonArr[activeIndex].activate();
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
    window.display();
}