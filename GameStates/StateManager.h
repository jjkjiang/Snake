#ifndef STATEMAN_H
#define STATEMAN_H


#include "MenuState.h"
#include "GameState.h"

class StateManager
{
private:
  GameState game;
  MenuState menu;

public:
  StateManager();
  void update(const sf::Keyboard::Key&);
  void drawState(sf::RenderWindow&);
};
#endif
