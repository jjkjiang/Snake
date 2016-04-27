#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "StateManager.h"

#include "State.h"
#include "../GameObjects/TileMap.h"
#include "../GameObjects/Button.h"

class MenuState : public State {
private:
    TileMap menuBg;
    int arrSize;
    int activeIndex;
    Button buttonArr[2];
    Button playButton;
    Button exitButton;
public:
    MenuState();
    virtual void update(sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow& window);
};

#endif