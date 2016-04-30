#ifndef __STATE_H__
#define __STATE_H__

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

// abstract base class
class State
{
public:
    // all updates will take in the last pressed key from the event loop
  virtual int update(sf::Keyboard::Key&) = 0;
    // all the draws will take in the main window to draw with
  virtual void drawState(sf::RenderWindow&) = 0;
};

#endif
