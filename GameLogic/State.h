#ifndef __STATE_H__
#define __STATE_H__

#include <SFML/Graphics/RenderWindow.hpp>

class State
{
public:
  virtual void update() = 0;
  virtual void drawState(sf::RenderWindow&) = 0;
};

#endif
