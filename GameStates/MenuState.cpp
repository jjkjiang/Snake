#include "MenuState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/Logic.h"

/*
 * TileMap menuBg;
    sf::RectangleShape snakeLogo;
    sf::RectangleShape startSnakeButton;
    //sf::RectangleShape startSnakePongButton;
    //sf::RectangleShape optionsButton;
    sf::RectangleShape exitButton;
 */

MenuState::MenuState() {
    if (!menuBg.load(menuResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");
    //snakeLogo;

}
void MenuState::update(const sf::Keyboard::Key&) {
    return;
}
void MenuState::drawState(sf::RenderWindow& window) {
    return;
}