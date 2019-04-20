#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

#include "State.h"

class StateMachine {
public:
  StateMachine(State *initialState);

  void changeState(State *newState);
  void update();

private:
  State currentState;
};
#endif
