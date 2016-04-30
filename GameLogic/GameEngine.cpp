//
// Created by jerry on 2016/04/29.
//

#include "GameEngine.h"
#include "../GameStates/GameOverState.h"

GameEngine::GameEngine(sf::Font* mainFont) {
    std::string fileName = "highScores.db";
    scoreBoard = new ScoreBoard(fileName);
    this->mainFont = mainFont;
}

void GameEngine::init() {
    game.push(new MenuState(*mainFont));
}

void GameEngine::update(sf::Keyboard::Key& press) {
    int keyCode = game.top()->update(press, scoreBoard);

    if (keyCode == 1) { // keycode 1 is the signal to start a game
        game.push(new GameState(*mainFont));
    } else if (keyCode == 2) { // keycode 2 is the signal of restart the game from game over
        delete game.top();
        game.pop();
        delete game.top();
        game.pop();
        game.push(new GameState(*mainFont));
    } else if (keyCode == 3) { // keycode 3 is the signal of game over
        game.push(new GameOverState(*mainFont, scoreBoard));
    } else if (keyCode == 4) { // keycode 4 is the signal of return to menu from gameover
        delete game.top();
        game.pop();
        delete game.top();
        game.pop();
    } else if (keyCode == -1) { // keycode -1 is the signal to exit the game
        exit(0);
    }
}

void GameEngine::drawState(sf::RenderWindow& window) {
    game.top()->drawState(window);
}