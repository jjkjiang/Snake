//
// Created by jerry on 2016/04/29.
//

#include "GameEngine.h"

void GameEngine::init(sf::Font& mainFont) {
    game.push(new MenuState(mainFont));
}

void GameEngine::update(sf::Keyboard::Key& press) {
    int keyCode = game.top()->update(press);
    if (keyCode == 1) { // keycode 1 is the signal to start a game
        game.push(new GameState());
    } else if (keyCode == 2) { // keycode 2 is the signal of game over
        game.pop();
    } else if (keyCode == -1) { // keycode -1 is the signal to exit the game
        exit(0);
    }
}
void GameEngine::drawState(sf::RenderWindow& window) {
    game.top()->drawState(window);
}