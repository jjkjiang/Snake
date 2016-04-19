#ifndef gameStateH
#define  gameStateH

#include "State.h"

class GameState : public State
{
public:
  virtual void update();
  virtual void draw();
};

#endif
