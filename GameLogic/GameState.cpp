#include "GameState.h"

void GameState::update() {

}

void GameState::draw(sf::RenderWindow window) {
    window.clear();
    window.draw(map);
    window.draw(square);
    window.display();
}