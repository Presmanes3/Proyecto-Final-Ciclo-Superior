#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

#include "State.h"

class StateMachine {
public:
  StateMachine(State *initialState);

  void changeState(State *newState);
  void updateCurrentState();

private:
  State currentState;
};

class State {
public:
  State(StateMachine *_parent);

  virtual void update() = 0;
  void changeState(State *newState);

private:
  StateMachine *parent;
};

#endif
