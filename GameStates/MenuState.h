#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "StateManager.h"

#include "State.h"
#include "../GameObjects/TileMap.h"

class MenuState : public State {
private:
    TileMap menuBg;
    Button play;
public:
    MenuState();
    virtual void update(const sf::Keyboard::Key&);
    virtual void drawState(sf::RenderWindow& window);
};

#endif